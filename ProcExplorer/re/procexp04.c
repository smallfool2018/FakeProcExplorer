
//----- (00C118A0) --------------------------------------------------------
int __stdcall sub_C118A0(int a1, FILETIME *lpFileTime)
{
  _bstr_t *v2; // esi
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  _bstr_t *v5; // esi
  Data_t_bstr_t *v6; // eax
  Data_t_bstr_t *v7; // esi
  LONG (__stdcall *v8)(volatile LONG *); // ecx
  Data_t_bstr_t *v9; // esi
  Data_t_bstr_t *v10; // esi
  Data_t_bstr_t *v11; // esi
  Data_t_bstr_t *v12; // esi
  struct _FILETIME LocalFileTime; // [esp+14h] [ebp-140h]
  int v15; // [esp+1Ch] [ebp-138h]
  _bstr_t bstrRet; // [esp+20h] [ebp-134h]
  _bstr_t a3; // [esp+24h] [ebp-130h]
  _bstr_t v18; // [esp+28h] [ebp-12Ch]
  _bstr_t v19; // [esp+2Ch] [ebp-128h]
  _bstr_t v20; // [esp+30h] [ebp-124h]
  struct _SYSTEMTIME SystemTime; // [esp+34h] [ebp-120h]
  WCHAR TimeStr; // [esp+44h] [ebp-110h]
  WCHAR DateStr; // [esp+C4h] [ebp-90h]
  int v24; // [esp+150h] [ebp-4h]

  *(_DWORD *)a1 = 0;
  v24 = 0;
  v15 = 1;
  FileTimeToLocalFileTime(lpFileTime, &LocalFileTime);
  FileTimeToSystemTime(&LocalFileTime, &SystemTime);
  GetDateFormatW(0x400u, 0, &SystemTime, L"yyyy-MM-dd", &DateStr, 64);
  GetTimeFormatW(0x400u, 8u, &SystemTime, L"hh:mm:ss", &TimeStr, 64);
  _bstr_t::_bstr_t((tagEventSetItem *)&a3, L" ");
  v24 = 1;
  v2 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v20, &TimeStr);
  LOBYTE(v24) = 2;
  v3 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v18, &DateStr);
  LOBYTE(v24) = 3;
  v4 = _bstr_t::operator+(v3, &bstrRet, &a3);
  LOBYTE(v24) = 4;
  v5 = _bstr_t::operator+(v4, &v19, v2);
  if ( (_bstr_t *)a1 != v5 )
  {
    _bstr_t::_Free((_bstr_t *)a1);
    v6 = v5->m_Data;
    *(_bstr_t *)a1 = (_bstr_t)v5->m_Data;
    if ( v6 )
      InterlockedIncrement(&v6->m_RefCount);
  }
  v7 = v19.m_Data;
  v8 = InterlockedDecrement;
  if ( v19.m_Data )
  {
    if ( !InterlockedDecrement(&v19.m_Data->m_RefCount) && v7 )
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
    v8 = InterlockedDecrement;
    v19.m_Data = 0;
  }
  v9 = bstrRet.m_Data;
  if ( bstrRet.m_Data )
  {
    if ( !v8(&bstrRet.m_Data->m_RefCount) && v9 )
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
    bstrRet.m_Data = 0;
  }
  v10 = v18.m_Data;
  if ( v18.m_Data )
  {
    if ( !InterlockedDecrement(&v18.m_Data->m_RefCount) && v10 )
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
    v18.m_Data = 0;
  }
  v11 = v20.m_Data;
  if ( v20.m_Data )
  {
    if ( !InterlockedDecrement(&v20.m_Data->m_RefCount) && v11 )
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
    v20.m_Data = 0;
  }
  v12 = a3.m_Data;
  if ( a3.m_Data && !InterlockedDecrement(&a3.m_Data->m_RefCount) )
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
  return a1;
}

//----- (00C11BC0) --------------------------------------------------------
int __stdcall sub_C11BC0(int a2, OLECHAR *psz)
{
  OLECHAR *v2; // edi
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  BSTR v6; // eax
  Data_t_bstr_t *v7; // eax
  BSTR *v8; // eax
  int v9; // edi
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // esi
  BSTR v12; // eax
  Data_t_bstr_t *v13; // eax
  BSTR *v14; // eax
  int v15; // edi
  Data_t_bstr_t *v16; // edi
  Data_t_bstr_t *v17; // eax
  Data_t_bstr_t *v18; // esi
  BSTR v19; // eax
  Data_t_bstr_t *v20; // eax
  BSTR *v21; // eax
  int v22; // edi
  _bstr_t v24; // [esp+10h] [ebp-18h]
  _bstr_t a3; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+24h] [ebp-4h]
  OLECHAR *psza; // [esp+34h] [ebp+Ch]
  OLECHAR *pszb; // [esp+34h] [ebp+Ch]
  OLECHAR *pszc; // [esp+34h] [ebp+Ch]

  *(_DWORD *)a2 = 0;
  v2 = psz;
  v27 = 0;
  v26 = 1;
  if ( psz )
  {
    while ( 1 )
    {
      v3 = (Data_t_bstr_t *)wcschr(v2, 0x5Cu);
      v24.m_Data = v3;
      if ( !v3 )
        break;
      LOWORD(v3->m_wstr) = 0;
      v4 = (Data_t_bstr_t *)operator new(0xCu);
      v5 = v4;
      v27 = 1;
      if ( v4 )
      {
        v4->m_str = 0;
        v4->m_RefCount = 1;
        v6 = SysAllocString(v2);
        v5->m_wstr = v6;
        if ( !v6 && v2 )
          goto LABEL_56;
      }
      else
      {
        v5 = 0;
      }
      LOBYTE(v27) = 0;
      a3.m_Data = v5;
      if ( !v5 )
        goto LABEL_56;
      v27 = 2;
      v7 = (Data_t_bstr_t *)operator new(0xCu);
      LOBYTE(v27) = 3;
      v8 = v7 ? _bstr_t::Data_t::Data_t(v7, (_bstr_t *)a2, &a3) : 0;
      psza = (OLECHAR *)v8;
      LOBYTE(v27) = 2;
      if ( !v8 )
        goto LABEL_56;
      v9 = *(_DWORD *)a2;
      if ( *(_DWORD *)a2 )
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
        v8 = (BSTR *)psza;
        *(_DWORD *)a2 = 0;
      }
      *(_DWORD *)a2 = v8;
      LOBYTE(v27) = 0;
      if ( !InterlockedDecrement(&v5->m_RefCount) )
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
      v10 = (Data_t_bstr_t *)operator new(0xCu);
      v11 = v10;
      v27 = 4;
      if ( v10 )
      {
        v10->m_str = 0;
        v10->m_RefCount = 1;
        v12 = SysAllocString(L"\\\\");
        v11->m_wstr = v12;
        if ( !v12 )
          goto LABEL_56;
      }
      else
      {
        v11 = 0;
      }
      LOBYTE(v27) = 0;
      a3.m_Data = v11;
      if ( !v11 )
        goto LABEL_56;
      v27 = 5;
      v13 = (Data_t_bstr_t *)operator new(0xCu);
      LOBYTE(v27) = 6;
      v14 = v13 ? _bstr_t::Data_t::Data_t(v13, (_bstr_t *)a2, &a3) : 0;
      pszb = (OLECHAR *)v14;
      LOBYTE(v27) = 5;
      if ( !v14 )
        goto LABEL_56;
      v15 = *(_DWORD *)a2;
      if ( *(_DWORD *)a2 )
      {
        if ( !InterlockedDecrement((volatile LONG *)(v15 + 8)) && v15 )
        {
          if ( *(_DWORD *)v15 )
          {
            SysFreeString(*(BSTR *)v15);
            *(_DWORD *)v15 = 0;
          }
          if ( *(_DWORD *)(v15 + 4) )
          {
            operator delete[](*(void **)(v15 + 4));
            *(_DWORD *)(v15 + 4) = 0;
          }
          operator delete((void *)v15);
        }
        v14 = (BSTR *)pszb;
        *(_DWORD *)a2 = 0;
      }
      *(_DWORD *)a2 = v14;
      LOBYTE(v27) = 0;
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
      v16 = v24.m_Data;
      LOWORD(v24.m_Data->m_wstr) = 92;
      v2 = (OLECHAR *)((char *)&v16->m_wstr + 2);
    }
    v17 = (Data_t_bstr_t *)operator new(0xCu);
    v18 = v17;
    v27 = 7;
    if ( v17 )
    {
      v17->m_str = 0;
      v17->m_RefCount = 1;
      v19 = SysAllocString(v2);
      v18->m_wstr = v19;
      if ( !v19 && v2 )
        goto LABEL_56;
    }
    else
    {
      v18 = 0;
    }
    LOBYTE(v27) = 0;
    v24.m_Data = v18;
    if ( !v18
      || ((v27 = 8, v20 = (Data_t_bstr_t *)operator new(0xCu), LOBYTE(v27) = 9, !v20) ? (v21 = 0) : (v21 = _bstr_t::Data_t::Data_t(v20, (_bstr_t *)a2, &v24)),
          pszc = (OLECHAR *)v21,
          LOBYTE(v27) = 8,
          !v21) )
    {
LABEL_56:
      _com_issue_error(-2147024882);
    }
    v22 = *(_DWORD *)a2;
    if ( *(_DWORD *)a2 )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v22 + 8)) && v22 )
      {
        if ( *(_DWORD *)v22 )
        {
          SysFreeString(*(BSTR *)v22);
          *(_DWORD *)v22 = 0;
        }
        if ( *(_DWORD *)(v22 + 4) )
        {
          operator delete[](*(void **)(v22 + 4));
          *(_DWORD *)(v22 + 4) = 0;
        }
        operator delete((void *)v22);
      }
      v21 = (BSTR *)pszc;
      *(_DWORD *)a2 = 0;
    }
    *(_DWORD *)a2 = v21;
    if ( !InterlockedDecrement(&v18->m_RefCount) )
    {
      if ( v18->m_wstr )
      {
        SysFreeString(v18->m_wstr);
        v18->m_wstr = 0;
      }
      if ( v18->m_str )
      {
        operator delete[](v18->m_str);
        v18->m_str = 0;
      }
      operator delete(v18);
    }
  }
  return a2;
}

//----- (00C11FC0) --------------------------------------------------------
DWORD __thiscall sub_C11FC0(_DWORD *this)
{
  _DWORD *v1; // ebx
  CSystemProcessInfoMapNode *v2; // eax
  bool v3; // zf
  DWORD v4; // edi
  std__list_node **v5; // eax
  void (__stdcall *v6)(BSTR); // ebx
  Data_t_bstr_t *v7; // esi
  std__list_node *v8; // edi
  volatile LONG *v9; // eax
  volatile LONG *v10; // ebx
  Data_t_bstr_t *v11; // eax
  _DWORD *v12; // eax
  DWORD v13; // ebx
  Data_t_bstr_t *v14; // eax
  Data_t_bstr_t *v15; // eax
  Data_t_bstr_t *v16; // eax
  Data_t_bstr_t *v17; // esi
  OLECHAR *v18; // eax
  _bstr_t *v19; // eax
  _bstr_t *v20; // eax
  _bstr_t *v21; // ebx
  Data_t_bstr_t *v22; // eax
  BSTR *v23; // eax
  Data_t_bstr_t *v24; // ebx
  Data_t_bstr_t *v25; // ebx
  Data_t_bstr_t *v26; // ebx
  void *v27; // ebx
  Data_t_bstr_t *v28; // eax
  Data_t_bstr_t *v29; // esi
  char *v30; // eax
  OLECHAR *v31; // eax
  _bstr_t *v32; // eax
  _bstr_t *v33; // eax
  _bstr_t *v34; // ebx
  Data_t_bstr_t *v35; // eax
  BSTR *v36; // eax
  DWORD v37; // ebx
  Data_t_bstr_t *v38; // ebx
  Data_t_bstr_t *v39; // ebx
  void *v40; // ebx
  volatile LONG *v41; // eax
  volatile LONG *v42; // ebx
  Data_t_bstr_t *v43; // esi
  _bstr_t *v44; // eax
  Data_t_bstr_t *v45; // eax
  BSTR *v46; // eax
  Data_t_bstr_t *v47; // eax
  Data_t_bstr_t *v48; // eax
  Data_t_bstr_t *v49; // eax
  volatile LONG *v50; // eax
  volatile LONG *v51; // esi
  BSTR v52; // eax
  OLECHAR *v53; // eax
  _bstr_t *v54; // eax
  _bstr_t *v55; // eax
  _bstr_t *v56; // ebx
  Data_t_bstr_t *v57; // eax
  Data_t_bstr_t *v58; // ebx
  void **v59; // eax
  Data_t_bstr_t *v60; // ebx
  Data_t_bstr_t *v61; // ebx
  Data_t_bstr_t *v62; // ebx
  volatile LONG *v63; // eax
  volatile LONG *v64; // esi
  _bstr_t *v65; // eax
  _bstr_t *v66; // eax
  _bstr_t *v67; // ebx
  Data_t_bstr_t *v68; // eax
  Data_t_bstr_t *v69; // ebx
  Data_t_bstr_t *v70; // eax
  Data_t_bstr_t *v71; // ebx
  Data_t_bstr_t *v72; // ebx
  Data_t_bstr_t *v73; // ebx
  volatile LONG *v74; // eax
  volatile LONG *v75; // ebx
  Data_t_bstr_t *v76; // eax
  Data_t_bstr_t *v77; // eax
  volatile LONG *v78; // eax
  volatile LONG *v79; // edi
  Data_t_bstr_t *v80; // eax
  Data_t_bstr_t *v81; // eax
  Data_t_bstr_t *v82; // esi
  void *v83; // ecx
  volatile LONG *v84; // eax
  volatile LONG *v85; // esi
  _bstr_t *v86; // eax
  CHAR *v87; // ecx
  DWORD v88; // eax
  Data_t_bstr_t *v89; // edi
  DWORD v90; // edi
  Data_t_bstr_t *v91; // ebx
  tagHttpInfo *v92; // edi
  CHAR *v93; // ecx
  const wchar_t *v94; // eax
  CHAR *v95; // ecx
  const wchar_t *v96; // eax
  const wchar_t *v97; // eax
  std__list_node *v98; // eax
  std__list_node *v99; // esi
  tagHttpInfo *v100; // ebx
  BSTR **v101; // edi
  Data_t_bstr_t *v102; // eax
  Data_t_bstr_t *v103; // edi
  OLECHAR *v104; // eax
  CSystemProcessInfoMapNode *v105; // ecx
  Data_t_bstr_t *v106; // eax
  const wchar_t *v107; // eax
  CHAR *v108; // ecx
  Data_t_bstr_t *v109; // eax
  BSTR *v110; // edi
  BSTR v111; // eax
  CHAR *v112; // ecx
  Data_t_bstr_t *v113; // eax
  BSTR *v114; // edi
  BSTR v115; // eax
  int v116; // edi
  std__list_node **v117; // eax
  std__list_node *v118; // esi
  int v119; // edi
  OLECHAR **v120; // eax
  OLECHAR *v121; // eax
  Data_t_bstr_t *v122; // esi
  _bstr_t *v123; // ecx
  std__list_node *v124; // eax
  std__list_node *v125; // edi
  tagHttpInfo *v126; // ebx
  volatile LONG **v127; // eax
  int v128; // esi
  Data_t_bstr_t *v129; // esi
  Data_t_bstr_t *v130; // esi
  _bstr_t *v131; // edi
  std__list_node *v132; // eax
  std__list_node *v133; // edi
  tagHttpInfo *v134; // ebx
  _bstr_t *v135; // eax
  tagHttpInfo *v136; // edx
  std__list_node *v137; // eax
  std__list_node *v138; // ecx
  tagHttpInfo *v139; // ebx
  std__list_node *v140; // esi
  CHAR *v142; // [esp-10h] [ebp-9Ch]
  void *v143; // [esp-Ch] [ebp-98h]
  CSystemProcessInfoMapNode *v144; // [esp-8h] [ebp-94h]
  CHAR *v145; // [esp-4h] [ebp-90h]
  void *v146; // [esp+10h] [ebp-7Ch]
  int v147; // [esp+14h] [ebp-78h]
  void *v148; // [esp+18h] [ebp-74h]
  OLECHAR psz[2]; // [esp+1Ch] [ebp-70h]
  _bstr_t a3; // [esp+20h] [ebp-6Ch]
  _bstr_t v151; // [esp+24h] [ebp-68h]
  _bstr_t v152; // [esp+28h] [ebp-64h]
  _bstr_t v153; // [esp+2Ch] [ebp-60h]
  _bstr_t v154; // [esp+30h] [ebp-5Ch]
  _bstr_t v155; // [esp+34h] [ebp-58h]
  _bstr_t v156; // [esp+38h] [ebp-54h]
  _bstr_t v157; // [esp+3Ch] [ebp-50h]
  _bstr_t v158; // [esp+40h] [ebp-4Ch]
  void *v159; // [esp+44h] [ebp-48h]
  _bstr_t v160; // [esp+48h] [ebp-44h]
  _bstr_t v161; // [esp+4Ch] [ebp-40h]
  void *v162; // [esp+50h] [ebp-3Ch]
  _bstr_t a1; // [esp+54h] [ebp-38h]
  _bstr_t bstrRet; // [esp+58h] [ebp-34h]
  char *v165; // [esp+5Ch] [ebp-30h]
  _bstr_t v166; // [esp+60h] [ebp-2Ch]
  _bstr_t v167; // [esp+64h] [ebp-28h]
  OLECHAR v168[2]; // [esp+68h] [ebp-24h]
  DWORD dwMessageId; // [esp+6Ch] [ebp-20h]
  _bstr_t v170; // [esp+70h] [ebp-1Ch]
  tagHttpInfo *v171; // [esp+74h] [ebp-18h]
  _bstr_t a2; // [esp+78h] [ebp-14h]
  bool v173; // [esp+7Fh] [ebp-Dh]
  int v174; // [esp+88h] [ebp-4h]

  v1 = this;
  v171 = (tagHttpInfo *)this;
  v147 = 0;
  v2 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  v146 = v2;
  v3 = v1[3] == 0;
  v174 = 0;
  v165 = 0;
  if ( v3 )
  {
    v4 = 0;
    goto LABEL_475;
  }
  _bstr_t::_bstr_t(&a2, L"[");
  v5 = (std__list_node **)v1[2];
  v6 = SysFreeString;
  v7 = a2.m_Data;
  LOBYTE(v174) = 1;
  v8 = *v5;
  if ( *v5 != (std__list_node *)v5 )
  {
    do
    {
      v166.m_Data = (Data_t_bstr_t *)v8->_Myval;
      _bstr_t::operator=((EventItem *)&v166.m_Data[2], (OLECHAR *)&gszNullString);
      if ( v165 )
      {
        v9 = (volatile LONG *)operator new(0xCu);
        v10 = v9;
        *(_DWORD *)psz = v9;
        LOBYTE(v174) = 2;
        if ( v9 )
        {
          v145 = ",";
          *((_DWORD *)v9 + 1) = 0;
          *((_DWORD *)v9 + 2) = 1;
          *v9 = (volatile LONG)_com_util::ConvertStringToBSTR(v145);
        }
        else
        {
          v10 = 0;
        }
        LOBYTE(v174) = 1;
        *(_DWORD *)v168 = v10;
        if ( !v10 )
          goto LABEL_311;
        LOBYTE(v174) = 3;
        v11 = (Data_t_bstr_t *)operator new(0xCu);
        *(_DWORD *)psz = v11;
        LOBYTE(v174) = 4;
        v7 = (Data_t_bstr_t *)(v11 ? _bstr_t::Data_t::Data_t(v11, &a2, (_bstr_t *)v168) : 0);
        LOBYTE(v174) = 3;
        if ( !v7 )
          goto LABEL_311;
        _bstr_t::_Free(&a2);
        a2.m_Data = v7;
        LOBYTE(v174) = 1;
        if ( !InterlockedDecrement(v10 + 2) )
        {
          if ( *v10 )
          {
            SysFreeString(*(BSTR *)v10);
            *v10 = 0;
          }
          if ( *((_DWORD *)v10 + 1) )
          {
            operator delete[](*((void **)v10 + 1));
            *((_DWORD *)v10 + 1) = 0;
          }
          operator delete((void *)v10);
        }
      }
      v12 = operator new(0xCu);
      v13 = (DWORD)v12;
      *(_DWORD *)psz = v12;
      LOBYTE(v174) = 5;
      if ( v12 )
      {
        v145 = L"{";
        v12[1] = 0;
        v12[2] = 1;
        *v12 = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v13 = 0;
      }
      LOBYTE(v174) = 1;
      dwMessageId = v13;
      if ( !v13 )
        goto LABEL_311;
      LOBYTE(v174) = 6;
      v14 = (Data_t_bstr_t *)operator new(0xCu);
      *(_DWORD *)psz = v14;
      LOBYTE(v174) = 7;
      v15 = (Data_t_bstr_t *)(v14 ? _bstr_t::Data_t::Data_t(v14, &a2, (_bstr_t *)&dwMessageId) : 0);
      *(_DWORD *)v168 = v15;
      LOBYTE(v174) = 6;
      if ( !v15 )
        goto LABEL_311;
      if ( v7 )
      {
        if ( !InterlockedDecrement(&v7->m_RefCount) )
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
        v15 = *(Data_t_bstr_t **)v168;
      }
      a2.m_Data = v15;
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement((volatile LONG *)(v13 + 8)) )
      {
        if ( *(_DWORD *)v13 )
        {
          SysFreeString(*(BSTR *)v13);
          *(_DWORD *)v13 = 0;
        }
        if ( *(_DWORD *)(v13 + 4) )
        {
          operator delete[](*(void **)(v13 + 4));
          *(_DWORD *)(v13 + 4) = 0;
        }
        operator delete((void *)v13);
      }
      v16 = (Data_t_bstr_t *)operator new(0xCu);
      v17 = v16;
      *(_DWORD *)psz = v16;
      LOBYTE(v174) = 8;
      if ( v16 )
      {
        v145 = "\", ";
        v16->m_str = 0;
        v16->m_RefCount = 1;
        v16->m_wstr = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v17 = 0;
      }
      LOBYTE(v174) = 1;
      a3.m_Data = v17;
      if ( !v17 )
        goto LABEL_311;
      LOBYTE(v174) = 9;
      v18 = (OLECHAR *)(v166.m_Data->m_wstr ? *(_DWORD *)v166.m_Data->m_wstr : 0);
      v19 = (_bstr_t *)sub_C11BC0((int)&v162, v18);
      LOBYTE(v174) = 10;
      v20 = sub_C114F0(&a1, "\"autostart_location\": \"", v19);
      LOBYTE(v174) = 11;
      v21 = _bstr_t::operator+(v20, &bstrRet, &a3);
      LOBYTE(v174) = 12;
      v22 = (Data_t_bstr_t *)operator new(0xCu);
      *(_DWORD *)psz = v22;
      LOBYTE(v174) = 13;
      v23 = v22 ? _bstr_t::Data_t::Data_t(v22, &a2, v21) : 0;
      dwMessageId = (DWORD)v23;
      LOBYTE(v174) = 12;
      if ( !v23 )
        goto LABEL_311;
      v24 = *(Data_t_bstr_t **)v168;
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v168 + 8)) )
      {
        if ( v24->m_wstr )
        {
          SysFreeString(v24->m_wstr);
          v24->m_wstr = 0;
        }
        if ( v24->m_str )
        {
          operator delete[](v24->m_str);
          v24->m_str = 0;
        }
        operator delete(v24);
      }
      v25 = bstrRet.m_Data;
      a2.m_Data = (Data_t_bstr_t *)dwMessageId;
      if ( bstrRet.m_Data )
      {
        if ( !InterlockedDecrement(&bstrRet.m_Data->m_RefCount) && v25 )
        {
          if ( v25->m_wstr )
          {
            SysFreeString(v25->m_wstr);
            v25->m_wstr = 0;
          }
          if ( v25->m_str )
          {
            operator delete[](v25->m_str);
            v25->m_str = 0;
          }
          operator delete(v25);
        }
        bstrRet.m_Data = 0;
      }
      v26 = a1.m_Data;
      if ( a1.m_Data )
      {
        if ( !InterlockedDecrement(&a1.m_Data->m_RefCount) && v26 )
        {
          if ( v26->m_wstr )
          {
            SysFreeString(v26->m_wstr);
            v26->m_wstr = 0;
          }
          if ( v26->m_str )
          {
            operator delete[](v26->m_str);
            v26->m_str = 0;
          }
          operator delete(v26);
        }
        a1.m_Data = 0;
      }
      v27 = v162;
      if ( v162 )
      {
        if ( !InterlockedDecrement((volatile LONG *)v162 + 2) && v27 )
        {
          if ( *(_DWORD *)v27 )
          {
            SysFreeString(*(BSTR *)v27);
            *(_DWORD *)v27 = 0;
          }
          if ( *((_DWORD *)v27 + 1) )
          {
            operator delete[](*((void **)v27 + 1));
            *((_DWORD *)v27 + 1) = 0;
          }
          operator delete(v27);
        }
        v162 = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(&v17->m_RefCount) )
      {
        if ( v17->m_wstr )
        {
          SysFreeString(v17->m_wstr);
          v17->m_wstr = 0;
        }
        if ( v17->m_str )
        {
          operator delete[](v17->m_str);
          v17->m_str = 0;
        }
        operator delete(v17);
      }
      v28 = (Data_t_bstr_t *)operator new(0xCu);
      v29 = v28;
      *(_DWORD *)psz = v28;
      LOBYTE(v174) = 14;
      if ( v28 )
      {
        v145 = "\", ";
        v28->m_str = 0;
        v28->m_RefCount = 1;
        v28->m_wstr = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v29 = 0;
      }
      LOBYTE(v174) = 1;
      a3.m_Data = v29;
      if ( !v29 )
        goto LABEL_311;
      LOBYTE(v174) = 15;
      v30 = v166.m_Data->m_str;
      v31 = (OLECHAR *)(v30 ? *(_DWORD *)v30 : 0);
      v32 = (_bstr_t *)sub_C11BC0((int)&v159, v31);
      LOBYTE(v174) = 16;
      v33 = sub_C114F0(&v160, "\"autostart_entry\": \"", v32);
      LOBYTE(v174) = 17;
      v34 = _bstr_t::operator+(v33, &v161, &a3);
      LOBYTE(v174) = 18;
      v35 = (Data_t_bstr_t *)operator new(0xCu);
      *(_DWORD *)psz = v35;
      LOBYTE(v174) = 19;
      v36 = v35 ? _bstr_t::Data_t::Data_t(v35, &a2, v34) : 0;
      *(_DWORD *)v168 = v36;
      LOBYTE(v174) = 18;
      if ( !v36 )
        goto LABEL_311;
      v37 = dwMessageId;
      if ( !InterlockedDecrement((volatile LONG *)(dwMessageId + 8)) )
      {
        if ( *(_DWORD *)v37 )
        {
          SysFreeString(*(BSTR *)v37);
          *(_DWORD *)v37 = 0;
        }
        if ( *(_DWORD *)(v37 + 4) )
        {
          operator delete[](*(void **)(v37 + 4));
          *(_DWORD *)(v37 + 4) = 0;
        }
        operator delete((void *)v37);
      }
      v38 = v161.m_Data;
      a2.m_Data = *(Data_t_bstr_t **)v168;
      if ( v161.m_Data )
      {
        if ( !InterlockedDecrement(&v161.m_Data->m_RefCount) && v38 )
        {
          if ( v38->m_wstr )
          {
            SysFreeString(v38->m_wstr);
            v38->m_wstr = 0;
          }
          if ( v38->m_str )
          {
            operator delete[](v38->m_str);
            v38->m_str = 0;
          }
          operator delete(v38);
        }
        v161.m_Data = 0;
      }
      v39 = v160.m_Data;
      if ( v160.m_Data )
      {
        if ( !InterlockedDecrement(&v160.m_Data->m_RefCount) && v39 )
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
        v160.m_Data = 0;
      }
      v40 = v159;
      if ( v159 )
      {
        if ( !InterlockedDecrement((volatile LONG *)v159 + 2) && v40 )
        {
          if ( *(_DWORD *)v40 )
          {
            SysFreeString(*(BSTR *)v40);
            *(_DWORD *)v40 = 0;
          }
          if ( *((_DWORD *)v40 + 1) )
          {
            operator delete[](*((void **)v40 + 1));
            *((_DWORD *)v40 + 1) = 0;
          }
          operator delete(v40);
        }
        v159 = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(&v29->m_RefCount) )
      {
        if ( v29->m_wstr )
        {
          SysFreeString(v29->m_wstr);
          v29->m_wstr = 0;
        }
        if ( v29->m_str )
        {
          operator delete[](v29->m_str);
          v29->m_str = 0;
        }
        operator delete(v29);
      }
      v41 = (volatile LONG *)operator new(0xCu);
      v42 = v41;
      *(_DWORD *)psz = v41;
      LOBYTE(v174) = 20;
      if ( v41 )
      {
        v145 = "\", ";
        *((_DWORD *)v41 + 1) = 0;
        *((_DWORD *)v41 + 2) = 1;
        *v41 = (volatile LONG)_com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v42 = 0;
      }
      LOBYTE(v174) = 1;
      *(_DWORD *)psz = v42;
      if ( !v42 )
        goto LABEL_311;
      v43 = (Data_t_bstr_t *)v166.m_Data->m_RefCount;
      a3.m_Data = v43;
      if ( v43 )
        InterlockedIncrement(&v43->m_RefCount);
      LOBYTE(v174) = 22;
      v44 = sub_C114F0(&v157, "\"hash\": \"", &a3);
      LOBYTE(v174) = 23;
      dwMessageId = (DWORD)_bstr_t::operator+(v44, &v158, (_bstr_t *)psz);
      LOBYTE(v174) = 24;
      v45 = (Data_t_bstr_t *)operator new(0xCu);
      v148 = v45;
      LOBYTE(v174) = 25;
      v46 = v45 ? _bstr_t::Data_t::Data_t(v45, &a2, (_bstr_t *)dwMessageId) : 0;
      dwMessageId = (DWORD)v46;
      LOBYTE(v174) = 24;
      if ( !v46 )
        goto LABEL_311;
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v168 + 8)) )
      {
        v47 = *(Data_t_bstr_t **)v168;
        if ( **(_DWORD **)v168 )
        {
          SysFreeString(**(BSTR **)v168);
          v47 = *(Data_t_bstr_t **)v168;
          **(_DWORD **)v168 = 0;
        }
        if ( v47->m_str )
        {
          operator delete[](v47->m_str);
          v47 = *(Data_t_bstr_t **)v168;
          *(_DWORD *)(*(_DWORD *)v168 + 4) = 0;
        }
        operator delete(v47);
      }
      a2.m_Data = (Data_t_bstr_t *)dwMessageId;
      *(_bstr_t *)v168 = v158;
      if ( v158.m_Data )
      {
        if ( !InterlockedDecrement(&v158.m_Data->m_RefCount) )
        {
          v48 = *(Data_t_bstr_t **)v168;
          if ( *(_DWORD *)v168 )
          {
            if ( **(_DWORD **)v168 )
            {
              SysFreeString(**(BSTR **)v168);
              v48 = *(Data_t_bstr_t **)v168;
              **(_DWORD **)v168 = 0;
            }
            if ( v48->m_str )
            {
              operator delete[](v48->m_str);
              v48 = *(Data_t_bstr_t **)v168;
              *(_DWORD *)(*(_DWORD *)v168 + 4) = 0;
            }
            operator delete(v48);
          }
        }
        v158.m_Data = 0;
      }
      *(_bstr_t *)v168 = v157;
      if ( v157.m_Data )
      {
        if ( !InterlockedDecrement(&v157.m_Data->m_RefCount) )
        {
          v49 = *(Data_t_bstr_t **)v168;
          if ( *(_DWORD *)v168 )
          {
            if ( **(_DWORD **)v168 )
            {
              SysFreeString(**(BSTR **)v168);
              v49 = *(Data_t_bstr_t **)v168;
              **(_DWORD **)v168 = 0;
            }
            if ( v49->m_str )
            {
              operator delete[](v49->m_str);
              v49 = *(Data_t_bstr_t **)v168;
              *(_DWORD *)(*(_DWORD *)v168 + 4) = 0;
            }
            operator delete(v49);
          }
        }
        v157.m_Data = 0;
      }
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
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v42 + 2) )
      {
        if ( *v42 )
        {
          SysFreeString(*(BSTR *)v42);
          *v42 = 0;
        }
        if ( *((_DWORD *)v42 + 1) )
        {
          operator delete[](*((void **)v42 + 1));
          *((_DWORD *)v42 + 1) = 0;
        }
        operator delete((void *)v42);
      }
      v50 = (volatile LONG *)operator new(0xCu);
      v51 = v50;
      v148 = (void *)v50;
      LOBYTE(v174) = 26;
      if ( v50 )
      {
        v145 = "\", ";
        *((_DWORD *)v50 + 1) = 0;
        *((_DWORD *)v50 + 2) = 1;
        *v50 = (volatile LONG)_com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v51 = 0;
      }
      LOBYTE(v174) = 1;
      *(_DWORD *)psz = v51;
      if ( !v51 )
        goto LABEL_311;
      LOBYTE(v174) = 27;
      v52 = v166.m_Data[1].m_wstr;
      v53 = (OLECHAR *)(v52 ? *(_DWORD *)v52 : 0);
      v54 = (_bstr_t *)sub_C11BC0((int)&v154, v53);
      LOBYTE(v174) = 28;
      v55 = sub_C114F0(&v155, "\"image_path\": \"", v54);
      LOBYTE(v174) = 29;
      v56 = _bstr_t::operator+(v55, &v156, (_bstr_t *)psz);
      LOBYTE(v174) = 30;
      v57 = (Data_t_bstr_t *)operator new(0xCu);
      v148 = v57;
      LOBYTE(v174) = 31;
      if ( v57 )
      {
        v58 = (Data_t_bstr_t *)_bstr_t::Data_t::Data_t(v57, &a2, v56);
        *(_DWORD *)v168 = v58;
      }
      else
      {
        v58 = 0;
        *(_DWORD *)v168 = 0;
      }
      LOBYTE(v174) = 30;
      if ( !v58 )
        goto LABEL_311;
      if ( !InterlockedDecrement((volatile LONG *)(dwMessageId + 8)) )
      {
        v59 = (void **)dwMessageId;
        if ( *(_DWORD *)dwMessageId )
        {
          SysFreeString(*(BSTR *)dwMessageId);
          v59 = (void **)dwMessageId;
          *(_DWORD *)dwMessageId = 0;
        }
        if ( v59[1] )
        {
          operator delete[](v59[1]);
          v59 = (void **)dwMessageId;
          *(_DWORD *)(dwMessageId + 4) = 0;
        }
        operator delete(v59);
      }
      a2.m_Data = v58;
      v60 = v156.m_Data;
      if ( v156.m_Data )
      {
        if ( !InterlockedDecrement(&v156.m_Data->m_RefCount) && v60 )
        {
          if ( v60->m_wstr )
          {
            SysFreeString(v60->m_wstr);
            v60->m_wstr = 0;
          }
          if ( v60->m_str )
          {
            operator delete[](v60->m_str);
            v60->m_str = 0;
          }
          operator delete(v60);
        }
        v156.m_Data = 0;
      }
      v61 = v155.m_Data;
      if ( v155.m_Data )
      {
        if ( !InterlockedDecrement(&v155.m_Data->m_RefCount) && v61 )
        {
          if ( v61->m_wstr )
          {
            SysFreeString(v61->m_wstr);
            v61->m_wstr = 0;
          }
          if ( v61->m_str )
          {
            operator delete[](v61->m_str);
            v61->m_str = 0;
          }
          operator delete(v61);
        }
        v155.m_Data = 0;
      }
      v62 = v154.m_Data;
      if ( v154.m_Data )
      {
        if ( !InterlockedDecrement(&v154.m_Data->m_RefCount) && v62 )
        {
          if ( v62->m_wstr )
          {
            SysFreeString(v62->m_wstr);
            v62->m_wstr = 0;
          }
          if ( v62->m_str )
          {
            operator delete[](v62->m_str);
            v62->m_str = 0;
          }
          operator delete(v62);
        }
        v154.m_Data = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v51 + 2) )
      {
        if ( *v51 )
        {
          SysFreeString(*(BSTR *)v51);
          *v51 = 0;
        }
        if ( *((_DWORD *)v51 + 1) )
        {
          operator delete[](*((void **)v51 + 1));
          *((_DWORD *)v51 + 1) = 0;
        }
        operator delete((void *)v51);
      }
      v63 = (volatile LONG *)operator new(0xCu);
      v64 = v63;
      v148 = (void *)v63;
      LOBYTE(v174) = 32;
      if ( v63 )
      {
        v145 = "\"";
        *((_DWORD *)v63 + 1) = 0;
        *((_DWORD *)v63 + 2) = 1;
        *v63 = (volatile LONG)_com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v64 = 0;
      }
      LOBYTE(v174) = 1;
      *(_DWORD *)psz = v64;
      if ( !v64 )
        goto LABEL_311;
      LOBYTE(v174) = 33;
      v65 = (_bstr_t *)sub_C118A0((int)&v151, (FILETIME *)&v166.m_Data[1].m_str);
      LOBYTE(v174) = 34;
      v66 = sub_C114F0(&v152, "\"creation_datetime\": \"", v65);
      LOBYTE(v174) = 35;
      v67 = _bstr_t::operator+(v66, &v153, (_bstr_t *)psz);
      LOBYTE(v174) = 36;
      v68 = (Data_t_bstr_t *)operator new(0xCu);
      v148 = v68;
      LOBYTE(v174) = 37;
      if ( v68 )
      {
        v69 = (Data_t_bstr_t *)_bstr_t::Data_t::Data_t(v68, &a2, v67);
        v166.m_Data = v69;
      }
      else
      {
        v69 = 0;
        v166.m_Data = 0;
      }
      LOBYTE(v174) = 36;
      if ( !v69 )
        goto LABEL_311;
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v168 + 8)) )
      {
        v70 = *(Data_t_bstr_t **)v168;
        if ( **(_DWORD **)v168 )
        {
          SysFreeString(**(BSTR **)v168);
          v70 = *(Data_t_bstr_t **)v168;
          **(_DWORD **)v168 = 0;
        }
        if ( v70->m_str )
        {
          operator delete[](v70->m_str);
          v70 = *(Data_t_bstr_t **)v168;
          *(_DWORD *)(*(_DWORD *)v168 + 4) = 0;
        }
        operator delete(v70);
      }
      a2.m_Data = v69;
      v71 = v153.m_Data;
      if ( v153.m_Data )
      {
        if ( !InterlockedDecrement(&v153.m_Data->m_RefCount) && v71 )
        {
          if ( v71->m_wstr )
          {
            SysFreeString(v71->m_wstr);
            v71->m_wstr = 0;
          }
          if ( v71->m_str )
          {
            operator delete[](v71->m_str);
            v71->m_str = 0;
          }
          operator delete(v71);
        }
        v153.m_Data = 0;
      }
      v72 = v152.m_Data;
      if ( v152.m_Data )
      {
        if ( !InterlockedDecrement(&v152.m_Data->m_RefCount) && v72 )
        {
          if ( v72->m_wstr )
          {
            SysFreeString(v72->m_wstr);
            v72->m_wstr = 0;
          }
          if ( v72->m_str )
          {
            operator delete[](v72->m_str);
            v72->m_str = 0;
          }
          operator delete(v72);
        }
        v152.m_Data = 0;
      }
      v73 = v151.m_Data;
      if ( v151.m_Data )
      {
        if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v73 )
        {
          if ( v73->m_wstr )
          {
            SysFreeString(v73->m_wstr);
            v73->m_wstr = 0;
          }
          if ( v73->m_str )
          {
            operator delete[](v73->m_str);
            v73->m_str = 0;
          }
          operator delete(v73);
        }
        v151.m_Data = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v64 + 2) )
      {
        if ( *v64 )
        {
          SysFreeString(*(BSTR *)v64);
          *v64 = 0;
        }
        if ( *((_DWORD *)v64 + 1) )
        {
          operator delete[](*((void **)v64 + 1));
          *((_DWORD *)v64 + 1) = 0;
        }
        operator delete((void *)v64);
      }
      v74 = (volatile LONG *)operator new(0xCu);
      v75 = v74;
      v148 = (void *)v74;
      LOBYTE(v174) = 38;
      if ( v74 )
      {
        v145 = "}";
        *((_DWORD *)v74 + 1) = 0;
        *((_DWORD *)v74 + 2) = 1;
        *v74 = (volatile LONG)_com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v75 = 0;
      }
      LOBYTE(v174) = 1;
      *(_DWORD *)psz = v75;
      if ( !v75 )
        goto LABEL_311;
      LOBYTE(v174) = 39;
      v76 = (Data_t_bstr_t *)operator new(0xCu);
      v148 = v76;
      LOBYTE(v174) = 40;
      v7 = (Data_t_bstr_t *)(v76 ? _bstr_t::Data_t::Data_t(v76, &a2, (_bstr_t *)psz) : 0);
      LOBYTE(v174) = 39;
      if ( !v7 )
        goto LABEL_311;
      if ( !InterlockedDecrement(&v166.m_Data->m_RefCount) )
      {
        v77 = v166.m_Data;
        if ( v166.m_Data->m_wstr )
        {
          SysFreeString(v166.m_Data->m_wstr);
          v77 = v166.m_Data;
          v166.m_Data->m_wstr = 0;
        }
        if ( v77->m_str )
        {
          operator delete[](v77->m_str);
          v77 = v166.m_Data;
          v166.m_Data->m_str = 0;
        }
        operator delete(v77);
      }
      a2.m_Data = v7;
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v75 + 2) )
      {
        if ( *v75 )
        {
          SysFreeString(*(BSTR *)v75);
          *v75 = 0;
        }
        if ( *((_DWORD *)v75 + 1) )
        {
          operator delete[](*((void **)v75 + 1));
          *((_DWORD *)v75 + 1) = 0;
        }
        operator delete((void *)v75);
      }
      ++v165;
      v8 = v8->_Next;
    }
    while ( v8 != v171->m_List._Mypair._Myval2._Myhead );
    v6 = SysFreeString;
  }
  v78 = (volatile LONG *)operator new(0xCu);
  v79 = v78;
  v148 = (void *)v78;
  LOBYTE(v174) = 41;
  if ( v78 )
  {
    v145 = "]";
    *((_DWORD *)v78 + 1) = 0;
    *((_DWORD *)v78 + 2) = 1;
    *v78 = (volatile LONG)_com_util::ConvertStringToBSTR(v145);
  }
  else
  {
    v79 = 0;
  }
  LOBYTE(v174) = 1;
  *(_DWORD *)psz = v79;
  if ( !v79 )
LABEL_311:
    _com_issue_error(-2147024882);
  LOBYTE(v174) = 42;
  v80 = (Data_t_bstr_t *)operator new(0xCu);
  v148 = v80;
  LOBYTE(v174) = 43;
  if ( v80 )
    v81 = (Data_t_bstr_t *)_bstr_t::Data_t::Data_t(v80, &a2, (_bstr_t *)psz);
  else
    v81 = 0;
  v151.m_Data = v81;
  LOBYTE(v174) = 42;
  if ( !v81 )
    _com_issue_error(-2147024882);
  if ( v7 && !InterlockedDecrement(&v7->m_RefCount) )
  {
    if ( v7->m_wstr )
    {
      v6(v7->m_wstr);
      v7->m_wstr = 0;
    }
    if ( v7->m_str )
    {
      operator delete[](v7->m_str);
      v7->m_str = 0;
    }
    operator delete(v7);
  }
  v82 = v151.m_Data;
  a2.m_Data = v151.m_Data;
  if ( !InterlockedDecrement(v79 + 2) )
  {
    if ( *v79 )
    {
      v6(*(BSTR *)v79);
      *v79 = 0;
    }
    if ( *((_DWORD *)v79 + 1) )
    {
      operator delete[](*((void **)v79 + 1));
      *((_DWORD *)v79 + 1) = 0;
    }
    operator delete((void *)v79);
  }
  *(_DWORD *)v168 = 0;
  v145 = (CHAR *)v168;
  v148 = &v144;
  v144 = (CSystemProcessInfoMapNode *)v82;
  InterlockedIncrement(&v82->m_RefCount);
  v143 = v83;
  a3.m_Data = (Data_t_bstr_t *)&v143;
  LOBYTE(v174) = 45;
  _bstr_t::_bstr_t((tagEventSetItem *)&v143, L"Content-Type: application/json\r\n");
  LOBYTE(v174) = 46;
  v84 = (volatile LONG *)operator new(0xCu);
  v85 = v84;
  *(_DWORD *)psz = v84;
  LOBYTE(v174) = 47;
  if ( v84 )
  {
    v142 = "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c";
    *((_DWORD *)v84 + 1) = 0;
    *((_DWORD *)v84 + 2) = 1;
    *v84 = (volatile LONG)_com_util::ConvertStringToBSTR(v142);
  }
  else
  {
    v85 = 0;
  }
  LOBYTE(v174) = 46;
  *(_DWORD *)psz = v85;
  if ( !v85 )
    _com_issue_error(-2147024882);
  LOBYTE(v174) = 48;
  v86 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v151, L"/partners/sysinternals/file-reports?apikey=");
  v142 = v87;
  LOBYTE(v174) = 49;
  _bstr_t::operator+(v86, (_bstr_t *)&v142, (_bstr_t *)psz);
  LOBYTE(v174) = 51;
  v88 = sub_C14F00((HINTERNET *)v171, v142, v143, v144, (int)v145);
  v89 = v151.m_Data;
  dwMessageId = v88;
  if ( v151.m_Data )
  {
    if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v89 )
    {
      if ( v89->m_wstr )
      {
        v6(v89->m_wstr);
        v89->m_wstr = 0;
      }
      if ( v89->m_str )
      {
        operator delete[](v89->m_str);
        v89->m_str = 0;
      }
      operator delete(v89);
    }
    v151.m_Data = 0;
  }
  LOBYTE(v174) = 44;
  if ( !InterlockedDecrement(v85 + 2) )
  {
    if ( *v85 )
    {
      v6(*(BSTR *)v85);
      *v85 = 0;
    }
    if ( *((_DWORD *)v85 + 1) )
    {
      operator delete[](*((void **)v85 + 1));
      *((_DWORD *)v85 + 1) = 0;
    }
    operator delete((void *)v85);
  }
  v90 = dwMessageId;
  v91 = *(Data_t_bstr_t **)v168;
  if ( dwMessageId || !*(_DWORD *)v168 || !**(_DWORD **)v168 || (v145 = **(CHAR ***)v168, !SysStringLen((BSTR)v145)) )
  {
    v130 = 0;
    v170.m_Data = 0;
    LOBYTE(v174) = 56;
    if ( v90 )
    {
      if ( v90 != 232 )
      {
        v131 = (_bstr_t *)sub_C14320((int)psz, v90);
        if ( &v170 != v131 )
        {
          _bstr_t::_Free(&v170);
          v130 = v131->m_Data;
          v170.m_Data = v130;
          if ( v130 )
            InterlockedIncrement(&v130->m_RefCount);
        }
        _bstr_t::_Free((_bstr_t *)psz);
        goto LABEL_455;
      }
      v145 = (CHAR *)L"Throttled request. Try again later.";
    }
    else
    {
      v145 = (CHAR *)L"Unable to connect to VT";
    }
    _bstr_t::operator=((EventItem *)&v170, (OLECHAR *)v145);
    v130 = v170.m_Data;
LABEL_455:
    v132 = v171->m_List._Mypair._Myval2._Myhead;
    v133 = v132->_Next;
    if ( v132->_Next != v132 )
    {
      v134 = v171;
      do
      {
        v135 = (_bstr_t *)((char *)v133->_Myval + 24);
        *(_DWORD *)psz = v135;
        if ( v135 != &v170 )
        {
          _bstr_t::_Free(v135);
          **(_DWORD **)psz = v130;
          if ( v130 )
            InterlockedIncrement(&v130->m_RefCount);
        }
        v133 = v133->_Next;
      }
      while ( v133 != v134->m_List._Mypair._Myval2._Myhead );
      v91 = *(Data_t_bstr_t **)v168;
    }
    v4 = 13;
    v123 = &v170;
    goto LABEL_463;
  }
  v92 = v171;
  *(_DWORD *)psz = v91->m_wstr;
  sub_C14530(v171, (int)&v167, (unsigned int)psz, (int)&v146);
  v145 = v93;
  LOBYTE(v174) = 52;
  _bstr_t::_bstr_t((_bstr_t *)&v145, "result");
  sub_C14950((int)&v166, (int)&v146, v145);
  LOBYTE(v174) = 53;
  if ( v166.m_Data )
    v94 = v166.m_Data->m_wstr;
  else
    v94 = 0;
  if ( _wcsicmp(v94, L"-1") )
  {
    v96 = v166.m_Data ? v166.m_Data->m_wstr : 0;
    if ( _wcsicmp(v96, L"0") )
    {
      v145 = v95;
      _bstr_t::_bstr_t((_bstr_t *)&v145, "data");
      sub_C14950((int)&v152, (int)&v146, v145);
      LOBYTE(v174) = 54;
      if ( v152.m_Data )
        v97 = v152.m_Data->m_wstr;
      else
        v97 = 0;
      *(_DWORD *)psz = wcschr(v97, 0x5Bu) + 1;
      v98 = v92->m_List._Mypair._Myval2._Myhead;
      v99 = v98->_Next;
      if ( v98->_Next == v98 )
      {
LABEL_397:
        v117 = &v92->m_List._Mypair._Myval2._Myhead->_Next;
        v118 = *v117;
        if ( *v117 != (std__list_node *)v117 )
        {
          do
          {
            v119 = (int)v118->_Myval;
            v120 = *(OLECHAR ***)(v119 + 28);
            if ( !v120 || (v121 = *v120) == 0 || !SysStringLen(v121) )
            {
              if ( v171->field_18 )
                dwMessageId = sub_C155A0(v171, v119, (unsigned int)v168);
              else
                _bstr_t::operator=((EventItem *)(v119 + 32), L"Unknown");
            }
            v118 = v118->_Next;
          }
          while ( v118 != v171->m_List._Mypair._Myval2._Myhead );
          v91 = *(Data_t_bstr_t **)v168;
        }
        v122 = v152.m_Data;
        if ( v152.m_Data && !InterlockedDecrement(&v152.m_Data->m_RefCount) && v122 )
        {
          if ( v122->m_wstr )
          {
            SysFreeString(v122->m_wstr);
            v122->m_wstr = 0;
          }
          if ( v122->m_str )
          {
            operator delete[](v122->m_str);
            v122->m_str = 0;
          }
          operator delete(v122);
        }
        v4 = dwMessageId;
        _bstr_t::_Free(&v166);
        v123 = &v167;
        goto LABEL_463;
      }
      v100 = v171;
      while ( 1 )
      {
        v165 = (char *)v99->_Myval;
        v101 = sub_C14530(v100, (int)&v151, (unsigned int)psz, (int)&v146);
        if ( &v167 == (_bstr_t *)v101 )
          goto LABEL_370;
        _bstr_t::_Free(&v167);
        v102 = (Data_t_bstr_t *)*v101;
        v167.m_Data = v102;
        if ( v102 )
          break;
LABEL_371:
        v103 = v151.m_Data;
        if ( v151.m_Data )
        {
          if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v103 )
          {
            if ( v103->m_wstr )
            {
              SysFreeString(v103->m_wstr);
              v103->m_wstr = 0;
            }
            if ( v103->m_str )
            {
              operator delete[](v103->m_str);
              v103->m_str = 0;
            }
            operator delete(v103);
          }
          v102 = v167.m_Data;
          v151.m_Data = 0;
        }
        if ( v102 )
        {
          v104 = v102->m_wstr;
          if ( v104 )
          {
            if ( SysStringLen(v104) )
            {
              v145 = (CHAR *)L"true";
              v144 = v105;
              _bstr_t::_bstr_t((tagEventSetItem *)&v144, L"found");
              v106 = sub_C14950((int)&a3, (int)&v146, v144)->m_Data;
              v107 = v106 ? v106->m_wstr : 0;
              v173 = _wcsicmp(v107, (const wchar_t *)v145) == 0;
              _bstr_t::_Free(&a3);
              if ( v173 )
              {
                v145 = v108;
                _bstr_t::_bstr_t((tagEventSetItem *)&v145, L"detection_ratio");
                v109 = (Data_t_bstr_t *)sub_C14950((int)&v154, (int)&v146, v145);
                v110 = (BSTR *)(v165 + 32);
                v153.m_Data = v109;
                if ( v165 + 32 != (char *)v109 )
                {
                  _bstr_t::_Free((_bstr_t *)v165 + 8);
                  v111 = v153.m_Data->m_wstr;
                  *v110 = v153.m_Data->m_wstr;
                  if ( v111 )
                    InterlockedIncrement((volatile LONG *)v111 + 2);
                }
                _bstr_t::_Free(&v154);
                v145 = v112;
                _bstr_t::_bstr_t((tagEventSetItem *)&v145, L"Permalink");
                v113 = (Data_t_bstr_t *)sub_C14950((int)&v155, (int)&v146, v145);
                v114 = (BSTR *)(v165 + 28);
                v153.m_Data = v113;
                if ( v165 + 28 != (char *)v113 )
                {
                  _bstr_t::_Free((_bstr_t *)v165 + 7);
                  v115 = v153.m_Data->m_wstr;
                  *v114 = v153.m_Data->m_wstr;
                  if ( v115 )
                    InterlockedIncrement((volatile LONG *)v115 + 2);
                }
                _bstr_t::_Free(&v155);
              }
              else
              {
                v116 = (int)v165;
                _bstr_t::operator=((EventItem *)(v165 + 32), (OLECHAR *)&gszNullString);
                _bstr_t::operator=((EventItem *)(v116 + 28), (OLECHAR *)&gszNullString);
              }
              v99 = v99->_Next;
              if ( v99 != v100->m_List._Mypair._Myval2._Myhead )
                continue;
            }
          }
        }
        v91 = *(Data_t_bstr_t **)v168;
        v92 = v171;
        goto LABEL_397;
      }
      InterlockedIncrement(&v102->m_RefCount);
LABEL_370:
      v102 = v167.m_Data;
      goto LABEL_371;
    }
  }
  v145 = v95;
  _bstr_t::_bstr_t((tagEventSetItem *)&v145, L"message");
  sub_C14950((int)&v153, (int)&v146, v145);
  LOBYTE(v174) = 55;
  if ( !v153.m_Data || !v153.m_Data->m_wstr || (v145 = (CHAR *)v153.m_Data->m_wstr, !SysStringLen((BSTR)v145)) )
  {
    v4 = 0;
    goto LABEL_444;
  }
  v124 = v92->m_List._Mypair._Myval2._Myhead;
  v125 = v124->_Next;
  if ( v124->_Next == v124 )
    goto LABEL_443;
  v126 = v171;
  do
  {
    v151.m_Data = (Data_t_bstr_t *)v125->_Myval;
    v127 = (volatile LONG **)_bstr_t::_bstr_t(&v152, "message");
    v128 = *(_DWORD *)(*sub_C72F90((int *)&v146, (int *)&v148, v127) + 20);
    if ( v128 )
      InterlockedIncrement((volatile LONG *)(v128 + 8));
    if ( (OLECHAR *)&v151.m_Data[2] != psz )
    {
      _bstr_t::_Free((_bstr_t *)&v151.m_Data[2]);
      v151.m_Data[2].m_wstr = (BSTR)v128;
      if ( !v128 )
        goto LABEL_432;
      InterlockedIncrement((volatile LONG *)(v128 + 8));
    }
    if ( v128 && !InterlockedDecrement((volatile LONG *)(v128 + 8)) )
    {
      if ( *(_DWORD *)v128 )
      {
        SysFreeString(*(BSTR *)v128);
        *(_DWORD *)v128 = 0;
      }
      if ( *(_DWORD *)(v128 + 4) )
      {
        operator delete[](*(void **)(v128 + 4));
        *(_DWORD *)(v128 + 4) = 0;
      }
      operator delete((void *)v128);
    }
LABEL_432:
    v129 = v152.m_Data;
    if ( v152.m_Data )
    {
      if ( !InterlockedDecrement(&v152.m_Data->m_RefCount) && v129 )
      {
        if ( v129->m_wstr )
        {
          SysFreeString(v129->m_wstr);
          v129->m_wstr = 0;
        }
        if ( v129->m_str )
        {
          operator delete[](v129->m_str);
          v129->m_str = 0;
        }
        operator delete(v129);
      }
      v152.m_Data = 0;
    }
    v125 = v125->_Next;
  }
  while ( v125 != v126->m_List._Mypair._Myval2._Myhead );
  v91 = *(Data_t_bstr_t **)v168;
LABEL_443:
  v4 = dwMessageId;
LABEL_444:
  _bstr_t::_Free(&v153);
  _bstr_t::_Free(&v166);
  v123 = &v167;
LABEL_463:
  _bstr_t::_Free(v123);
  v136 = v171;
  v137 = v171->m_List._Mypair._Myval2._Myhead;
  v138 = v137->_Next;
  v137->_Next = v137;
  v136->m_List._Mypair._Myval2._Myhead->_Prev = v136->m_List._Mypair._Myval2._Myhead;
  v136->m_List._Mypair._Myval2._Mysize = 0;
  if ( v138 != v136->m_List._Mypair._Myval2._Myhead )
  {
    v139 = v136;
    do
    {
      v140 = v138->_Next;
      operator delete(v138);
      v138 = v140;
    }
    while ( v140 != v139->m_List._Mypair._Myval2._Myhead );
    v91 = *(Data_t_bstr_t **)v168;
  }
  if ( v91 && !InterlockedDecrement(&v91->m_RefCount) )
  {
    if ( v91->m_wstr )
    {
      SysFreeString(v91->m_wstr);
      v91->m_wstr = 0;
    }
    if ( v91->m_str )
    {
      operator delete[](v91->m_str);
      v91->m_str = 0;
    }
    operator delete(v91);
  }
  _bstr_t::_Free(&a2);
  v2 = (CSystemProcessInfoMapNode *)v146;
LABEL_475:
  v145 = (CHAR *)v2;
  v144 = v2->baseclass._Left;
  v174 = -1;
  sub_C16540((CSystemProcessInfoMap *)&v146, (CSystemProcessInfoMapNode **)&v148, v144, v2);
  operator delete(v146);
  return v4;
}
// CA4790: using guessed type wchar_t aThrottledReque[36];

//----- (00C137E0) --------------------------------------------------------
Data_t_bstr_t *__thiscall sub_C137E0(_DWORD *this)
{
  _DWORD *v1; // ebx
  CSystemProcessInfoMapNode *v2; // eax
  char *v3; // esi
  Data_t_bstr_t *v4; // esi
  _bstr_t *v5; // eax
  _bstr_t *v6; // eax
  _DWORD *v7; // eax
  LONG (__stdcall *v8)(volatile LONG *); // ebx
  _DWORD *v9; // edi
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // esi
  Data_t_bstr_t *v12; // eax
  Data_t_bstr_t *v13; // eax
  Data_t_bstr_t *v14; // esi
  Data_t_bstr_t *v15; // eax
  Data_t_bstr_t *v16; // ebx
  Data_t_bstr_t *v17; // ebx
  CSystemProcessInfoMapNode **v18; // ecx
  void *v19; // ecx
  _DWORD *v20; // edi
  Data_t_bstr_t *v21; // ebx
  const wchar_t **v22; // esi
  const wchar_t *v23; // esi
  Data_t_bstr_t *v24; // edi
  void *v25; // ecx
  wchar_t **v26; // eax
  wchar_t *v27; // ebx
  _bstr_t *v28; // esi
  void *v29; // esi
  CSystemProcessInfoMapNode *v30; // ecx
  OLECHAR *v31; // eax
  OLECHAR *v32; // esi
  BSTR v33; // eax
  Data_t_bstr_t *v34; // eax
  const wchar_t *v35; // eax
  int v36; // eax
  wchar_t *v37; // ecx
  void *v38; // esi
  char v39; // al
  wchar_t *v40; // ecx
  _bstr_t *v41; // eax
  Data_t_bstr_t *v42; // eax
  int v43; // edx
  Data_t_bstr_t *v44; // ecx
  int *v45; // eax
  int v46; // esi
  BSTR v47; // eax
  Data_t_bstr_t *v48; // esi
  Data_t_bstr_t *v49; // esi
  Data_t_bstr_t *v50; // esi
  Data_t_bstr_t *v51; // ecx
  int *v52; // eax
  int v53; // esi
  BSTR v54; // eax
  Data_t_bstr_t *v55; // esi
  wchar_t *v56; // eax
  Data_t_bstr_t *v57; // esi
  Data_t_bstr_t *v58; // esi
  LONG (__stdcall *v59)(volatile LONG *); // edi
  void *v60; // ebx
  Data_t_bstr_t *v61; // esi
  Data_t_bstr_t *v63; // esi
  _bstr_t *v64; // edi
  _DWORD *v65; // eax
  _DWORD *v66; // edi
  Data_t_bstr_t *v67; // eax
  BSTR v68; // ebx
  void *v69; // [esp-10h] [ebp-80h]
  OLECHAR *v70; // [esp-Ch] [ebp-7Ch]
  CSystemProcessInfoMapNode *v71; // [esp-8h] [ebp-78h]
  wchar_t *v72; // [esp-4h] [ebp-74h]
  void *v73; // [esp+10h] [ebp-60h]
  int v74; // [esp+14h] [ebp-5Ch]
  void *v75; // [esp+18h] [ebp-58h]
  _bstr_t v76; // [esp+1Ch] [ebp-54h]
  _bstr_t a1; // [esp+20h] [ebp-50h]
  _bstr_t bstr; // [esp+24h] [ebp-4Ch]
  _bstr_t a3; // [esp+28h] [ebp-48h]
  void *v80; // [esp+2Ch] [ebp-44h]
  void *v81; // [esp+30h] [ebp-40h]
  OLECHAR psz[2]; // [esp+34h] [ebp-3Ch]
  _bstr_t bstrResource; // [esp+38h] [ebp-38h]
  void *v84; // [esp+3Ch] [ebp-34h]
  _bstr_t v85; // [esp+40h] [ebp-30h]
  _bstr_t v86; // [esp+44h] [ebp-2Ch]
  _bstr_t v87; // [esp+48h] [ebp-28h]
  _bstr_t v88; // [esp+4Ch] [ebp-24h]
  int v89; // [esp+50h] [ebp-20h]
  _bstr_t v90; // [esp+54h] [ebp-1Ch]
  _bstr_t a2; // [esp+58h] [ebp-18h]
  _DWORD *v92; // [esp+5Ch] [ebp-14h]
  char v93; // [esp+63h] [ebp-Dh]
  int v94; // [esp+6Ch] [ebp-4h]

  v1 = this;
  v92 = this;
  v74 = 0;
  v2 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  v73 = v2;
  v3 = 0;
  v94 = 0;
  v84 = 0;
  if ( !v1[5] )
  {
    v4 = (Data_t_bstr_t *)232;
    goto LABEL_188;
  }
  _bstr_t::_bstr_t(&bstrResource, "&resource=");
  LOBYTE(v94) = 1;
  v5 = _bstr_t::_bstr_t(&bstr, "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c");
  LOBYTE(v94) = 2;
  v6 = sub_C114F0(&a1, "apikey=", v5);
  LOBYTE(v94) = 3;
  _bstr_t::operator+(v6, &a2, &bstrResource);
  _bstr_t::_Free(&a1);
  _bstr_t::_Free(&bstr);
  LOBYTE(v94) = 7;
  _bstr_t::_Free(&bstrResource);
  v7 = (_DWORD *)v1[4];
  v8 = InterlockedDecrement;
  v9 = (_DWORD *)*v7;
  if ( (_DWORD *)*v7 != v7 )
  {
    do
    {
      v80 = (void *)v9[2];
      _bstr_t::operator=((EventItem *)((char *)v80 + 24), (OLECHAR *)&gszNullString);
      if ( v3 )
      {
        v10 = (Data_t_bstr_t *)operator new(0xCu);
        v11 = v10;
        v76.m_Data = v10;
        LOBYTE(v94) = 8;
        if ( v10 )
        {
          v72 = (wchar_t *)",";
          v10->m_str = 0;
          v10->m_RefCount = 1;
          v10->m_wstr = _com_util::ConvertStringToBSTR((LPCSTR)v72);
        }
        else
        {
          v11 = 0;
        }
        LOBYTE(v94) = 7;
        a3.m_Data = v11;
        if ( !v11 )
          goto LABEL_74;
        LOBYTE(v94) = 9;
        v12 = (Data_t_bstr_t *)operator new(0xCu);
        v76.m_Data = v12;
        LOBYTE(v94) = 10;
        v13 = (Data_t_bstr_t *)(v12 ? _bstr_t::Data_t::Data_t(v12, &a2, &a3) : 0);
        bstrResource.m_Data = v13;
        LOBYTE(v94) = 9;
        if ( !v13 )
          goto LABEL_74;
        _bstr_t::_Free(&a2);
        a2.m_Data = bstrResource.m_Data;
        if ( !v8(&v11->m_RefCount) )
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
      }
      v14 = (Data_t_bstr_t *)*((_DWORD *)v80 + 2);
      a3.m_Data = v14;
      if ( v14 )
        InterlockedIncrement(&v14->m_RefCount);
      LOBYTE(v94) = 11;
      v15 = (Data_t_bstr_t *)operator new(0xCu);
      v76.m_Data = v15;
      LOBYTE(v94) = 12;
      if ( v15 )
      {
        v16 = (Data_t_bstr_t *)_bstr_t::Data_t::Data_t(v15, &a2, &a3);
        bstrResource.m_Data = v16;
      }
      else
      {
        v16 = 0;
        bstrResource.m_Data = 0;
      }
      LOBYTE(v94) = 11;
      if ( !v16 )
LABEL_74:
        _com_issue_error(-2147024882);
      v17 = a2.m_Data;
      if ( a2.m_Data && !InterlockedDecrement(&a2.m_Data->m_RefCount) && v17 )
      {
        if ( v17->m_wstr )
        {
          SysFreeString(v17->m_wstr);
          v17->m_wstr = 0;
        }
        if ( v17->m_str )
        {
          operator delete[](v17->m_str);
          v17->m_str = 0;
        }
        operator delete(v17);
      }
      v8 = InterlockedDecrement;
      a2.m_Data = bstrResource.m_Data;
      LOBYTE(v94) = 7;
      if ( v14 && !InterlockedDecrement(&v14->m_RefCount) )
      {
        if ( v14->m_wstr )
        {
          SysFreeString(v14->m_wstr);
          v14->m_wstr = 0;
        }
        if ( v14->m_str )
        {
          operator delete[](v14->m_str);
          v14->m_str = 0;
        }
        operator delete(v14);
      }
      v9 = (_DWORD *)*v9;
      v3 = (char *)v84 + 1;
      v84 = (char *)v84 + 1;
    }
    while ( v9 != (_DWORD *)v92[4] );
  }
  v84 = 0;
  v72 = (wchar_t *)&v84;
  v76.m_Data = (Data_t_bstr_t *)&v71;
  v18 = &v71;
  v71 = (CSystemProcessInfoMapNode *)a2.m_Data;
  if ( a2.m_Data )
    InterlockedIncrement(&a2.m_Data->m_RefCount);
  v70 = (OLECHAR *)v18;
  a1.m_Data = (Data_t_bstr_t *)&v70;
  LOBYTE(v94) = 14;
  _bstr_t::_bstr_t((tagEventSetItem *)&v70, L"Content-Type: application/x-www-form-urlencoded\r\n");
  v69 = v19;
  LOBYTE(v94) = 15;
  _bstr_t::_bstr_t((tagEventSetItem *)&v69, L"vtapi/v2/file/report");
  v20 = v92;
  LOBYTE(v94) = 13;
  v21 = (Data_t_bstr_t *)sub_C14F00((HINTERNET *)v92, v69, v70, v71, (int)v72);
  bstrResource.m_Data = v21;
  if ( !v21 )
  {
    v22 = (const wchar_t **)v84;
    if ( v84 )
    {
      if ( *(_DWORD *)v84 )
      {
        v72 = *(wchar_t **)v84;
        if ( SysStringLen(v72) )
        {
          v23 = *v22;
          *(_DWORD *)psz = v23;
          if ( wcschr(v23, 0x5Bu) )
            *(_DWORD *)psz = wcschr(v23, 0x5Bu) + 1;
          v24 = 0;
          v85.m_Data = 0;
          v25 = v92;
          LOBYTE(v94) = 16;
          v26 = (wchar_t **)v92[4];
          v27 = *v26;
          if ( *v26 != (wchar_t *)v26 )
          {
            do
            {
              v89 = *((_DWORD *)v27 + 2);
              v28 = (_bstr_t *)sub_C14530(v25, (int)&v81, (unsigned int)psz, (int)&v73);
              if ( &v85 != v28 )
              {
                if ( v24 && !InterlockedDecrement(&v24->m_RefCount) )
                {
                  if ( v24->m_wstr )
                  {
                    SysFreeString(v24->m_wstr);
                    v24->m_wstr = 0;
                  }
                  if ( v24->m_str )
                  {
                    operator delete[](v24->m_str);
                    v24->m_str = 0;
                  }
                  operator delete(v24);
                }
                v24 = v28->m_Data;
                v85.m_Data = v24;
                if ( v24 )
                  InterlockedIncrement(&v24->m_RefCount);
              }
              v29 = v81;
              if ( v81 )
              {
                if ( !InterlockedDecrement((volatile LONG *)v81 + 2) && v29 )
                {
                  if ( *(_DWORD *)v29 )
                  {
                    SysFreeString(*(BSTR *)v29);
                    *(_DWORD *)v29 = 0;
                  }
                  if ( *((_DWORD *)v29 + 1) )
                  {
                    operator delete[](*((void **)v29 + 1));
                    *((_DWORD *)v29 + 1) = 0;
                  }
                  operator delete(v29);
                }
                v81 = 0;
              }
              if ( !v24 )
                break;
              if ( !v24->m_wstr )
                break;
              v72 = v24->m_wstr;
              if ( !SysStringLen(v72) )
                break;
              v72 = L"1";
              v71 = v30;
              v76.m_Data = (Data_t_bstr_t *)&v71;
              v31 = (OLECHAR *)operator new(0xCu);
              v32 = v31;
              v75 = v31;
              LOBYTE(v94) = 17;
              if ( v31 )
              {
                v70 = L"response_code";
                *((_DWORD *)v31 + 1) = 0;
                *((_DWORD *)v31 + 2) = 1;
                v33 = SysAllocString(v70);
                *(_DWORD *)v32 = v33;
                if ( !v33 )
                  goto LABEL_74;
              }
              else
              {
                v32 = 0;
              }
              LOBYTE(v94) = 16;
              v76.m_Data->m_wstr = v32;
              if ( !v32 )
                goto LABEL_74;
              v34 = sub_C14950((int)&v80, (int)&v73, v71)->m_Data;
              if ( v34 )
                v35 = v34->m_wstr;
              else
                v35 = 0;
              v36 = _wcsicmp(v35, v72);
              v38 = v80;
              v39 = v36 == 0;
              v93 = v39;
              if ( v80 )
              {
                if ( !InterlockedDecrement((volatile LONG *)v80 + 2) && v38 )
                {
                  if ( *(_DWORD *)v38 )
                  {
                    SysFreeString(*(BSTR *)v38);
                    *(_DWORD *)v38 = 0;
                  }
                  if ( *((_DWORD *)v38 + 1) )
                  {
                    operator delete[](*((void **)v38 + 1));
                    *((_DWORD *)v38 + 1) = 0;
                  }
                  operator delete(v38);
                }
                v39 = v93;
                v80 = 0;
              }
              if ( v39 )
              {
                v72 = v37;
                _bstr_t::_bstr_t((tagEventSetItem *)&v72, L"positives");
                sub_C14950((int)&v86, (int)&v73, v72);
                v72 = v40;
                LOBYTE(v94) = 18;
                _bstr_t::_bstr_t((tagEventSetItem *)&v72, L"total");
                sub_C14950((int)&v87, (int)&v73, v72);
                LOBYTE(v94) = 19;
                _bstr_t::_bstr_t((tagEventSetItem *)&v88, L"/");
                LOBYTE(v94) = 20;
                v41 = _bstr_t::operator+(&v86, &bstr, &v88);
                LOBYTE(v94) = 21;
                v42 = (Data_t_bstr_t *)_bstr_t::operator+(v41, &a3, &v87);
                v43 = v89;
                v44 = v42;
                v76.m_Data = v42;
                v45 = (int *)(v89 + 32);
                if ( (Data_t_bstr_t *)(v89 + 32) != v76.m_Data )
                {
                  v46 = *v45;
                  if ( *v45 )
                  {
                    if ( !InterlockedDecrement((volatile LONG *)(v46 + 8)) && v46 )
                    {
                      if ( *(_DWORD *)v46 )
                      {
                        SysFreeString(*(BSTR *)v46);
                        *(_DWORD *)v46 = 0;
                      }
                      if ( *(_DWORD *)(v46 + 4) )
                      {
                        operator delete[](*(void **)(v46 + 4));
                        *(_DWORD *)(v46 + 4) = 0;
                      }
                      operator delete((void *)v46);
                    }
                    v43 = v89;
                    v44 = v76.m_Data;
                    *(_DWORD *)(v89 + 32) = 0;
                  }
                  v47 = v44->m_wstr;
                  *(_DWORD *)(v43 + 32) = v44->m_wstr;
                  if ( v47 )
                    InterlockedIncrement((volatile LONG *)v47 + 2);
                }
                v48 = a3.m_Data;
                if ( a3.m_Data )
                {
                  if ( !InterlockedDecrement(&a3.m_Data->m_RefCount) && v48 )
                  {
                    if ( v48->m_wstr )
                    {
                      SysFreeString(v48->m_wstr);
                      v48->m_wstr = 0;
                    }
                    if ( v48->m_str )
                    {
                      operator delete[](v48->m_str);
                      v48->m_str = 0;
                    }
                    operator delete(v48);
                  }
                  a3.m_Data = 0;
                }
                v49 = bstr.m_Data;
                if ( bstr.m_Data )
                {
                  if ( !InterlockedDecrement(&bstr.m_Data->m_RefCount) && v49 )
                  {
                    if ( v49->m_wstr )
                    {
                      SysFreeString(v49->m_wstr);
                      v49->m_wstr = 0;
                    }
                    if ( v49->m_str )
                    {
                      operator delete[](v49->m_str);
                      v49->m_str = 0;
                    }
                    operator delete(v49);
                  }
                  bstr.m_Data = 0;
                }
                v50 = v88.m_Data;
                LOBYTE(v94) = 19;
                if ( v88.m_Data )
                {
                  if ( !InterlockedDecrement(&v88.m_Data->m_RefCount) )
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
                  v88.m_Data = 0;
                }
                v72 = (wchar_t *)v44;
                _bstr_t::_bstr_t((tagEventSetItem *)&v72, L"Permalink");
                v51 = (Data_t_bstr_t *)sub_C14950((int)&a1, (int)&v73, v72);
                v52 = (int *)(v89 + 28);
                v76.m_Data = v51;
                if ( (Data_t_bstr_t *)(v89 + 28) != v51 )
                {
                  v53 = *v52;
                  if ( *v52 )
                  {
                    if ( !InterlockedDecrement((volatile LONG *)(v53 + 8)) && v53 )
                    {
                      if ( *(_DWORD *)v53 )
                      {
                        SysFreeString(*(BSTR *)v53);
                        *(_DWORD *)v53 = 0;
                      }
                      if ( *(_DWORD *)(v53 + 4) )
                      {
                        operator delete[](*(void **)(v53 + 4));
                        *(_DWORD *)(v53 + 4) = 0;
                      }
                      operator delete((void *)v53);
                    }
                    v51 = v76.m_Data;
                    *(_DWORD *)(v89 + 28) = 0;
                  }
                  v54 = v51->m_wstr;
                  *(_DWORD *)(v89 + 28) = v51->m_wstr;
                  if ( v54 )
                    InterlockedIncrement((volatile LONG *)v54 + 2);
                }
                v55 = a1.m_Data;
                if ( a1.m_Data )
                {
                  if ( !InterlockedDecrement(&a1.m_Data->m_RefCount) && v55 )
                  {
                    if ( v55->m_wstr )
                    {
                      SysFreeString(v55->m_wstr);
                      v55->m_wstr = 0;
                    }
                    if ( v55->m_str )
                    {
                      operator delete[](v55->m_str);
                      v55->m_str = 0;
                    }
                    operator delete(v55);
                  }
                  a1.m_Data = 0;
                }
                v56 = v27;
                v27 = *(wchar_t **)v27;
                v72 = v56;
                **((_DWORD **)v56 + 1) = *(_DWORD *)v56;
                *(_DWORD *)(*(_DWORD *)v56 + 4) = *((_DWORD *)v56 + 1);
                --v92[5];
                operator delete(v72);
                v57 = v87.m_Data;
                if ( v87.m_Data )
                {
                  if ( !InterlockedDecrement(&v87.m_Data->m_RefCount) && v57 )
                  {
                    if ( v57->m_wstr )
                    {
                      SysFreeString(v57->m_wstr);
                      v57->m_wstr = 0;
                    }
                    if ( v57->m_str )
                    {
                      operator delete[](v57->m_str);
                      v57->m_str = 0;
                    }
                    operator delete(v57);
                  }
                  v87.m_Data = 0;
                }
                v58 = v86.m_Data;
                LOBYTE(v94) = 16;
                if ( v86.m_Data )
                {
                  if ( !InterlockedDecrement(&v86.m_Data->m_RefCount) && v58 )
                  {
                    if ( v58->m_wstr )
                    {
                      SysFreeString(v58->m_wstr);
                      v58->m_wstr = 0;
                    }
                    if ( v58->m_str )
                    {
                      operator delete[](v58->m_str);
                      v58->m_str = 0;
                    }
                    operator delete(v58);
                  }
                  v86.m_Data = 0;
                }
              }
              else
              {
                v27 = *(wchar_t **)v27;
              }
              v25 = v92;
            }
            while ( v27 != (wchar_t *)v92[4] );
          }
          _bstr_t::_Free(&v85);
          goto LABEL_170;
        }
      }
    }
  }
  v63 = 0;
  v90.m_Data = 0;
  LOBYTE(v94) = 22;
  if ( !v21 )
  {
    v72 = L"Unable to connect to VT";
    goto LABEL_197;
  }
  if ( v21 == (Data_t_bstr_t *)232 )
  {
    v72 = L"Throttled request. Try again later.";
LABEL_197:
    _bstr_t::operator=((EventItem *)&v90, v72);
    v63 = v90.m_Data;
    goto LABEL_198;
  }
  v64 = (_bstr_t *)sub_C14320((int)&v76, (DWORD)v21);
  if ( &v90 != v64 )
  {
    _bstr_t::_Free(&v90);
    v63 = v64->m_Data;
    if ( v64->m_Data )
      InterlockedIncrement(&v63->m_RefCount);
  }
  _bstr_t::_Free(&v76);
  v20 = v92;
LABEL_198:
  v65 = (_DWORD *)v20[4];
  v66 = (_DWORD *)*v65;
  if ( (_DWORD *)*v65 != v65 )
  {
    do
    {
      v67 = (Data_t_bstr_t *)(v66[2] + 24);
      v76.m_Data = v67;
      if ( v67 != (Data_t_bstr_t *)&v90 )
      {
        v68 = v67->m_wstr;
        if ( v67->m_wstr )
        {
          if ( !InterlockedDecrement((volatile LONG *)v68 + 2) && v68 )
          {
            if ( *(_DWORD *)v68 )
            {
              SysFreeString(*(BSTR *)v68);
              *(_DWORD *)v68 = 0;
            }
            if ( *((_DWORD *)v68 + 1) )
            {
              operator delete[](*((void **)v68 + 1));
              *((_DWORD *)v68 + 1) = 0;
            }
            operator delete(v68);
          }
          v67 = v76.m_Data;
          v76.m_Data->m_wstr = 0;
        }
        v67->m_wstr = (BSTR)v63;
        if ( v63 )
          InterlockedIncrement(&v63->m_RefCount);
      }
      v66 = (_DWORD *)*v66;
    }
    while ( v66 != (_DWORD *)v92[4] );
  }
  bstrResource.m_Data = (Data_t_bstr_t *)13;
  if ( v63 )
  {
    v59 = InterlockedDecrement;
    if ( !InterlockedDecrement(&v63->m_RefCount) )
    {
      if ( v63->m_wstr )
      {
        SysFreeString(v63->m_wstr);
        v63->m_wstr = 0;
      }
      if ( v63->m_str )
      {
        operator delete[](v63->m_str);
        v63->m_str = 0;
      }
      operator delete(v63);
    }
    goto LABEL_171;
  }
LABEL_170:
  v59 = InterlockedDecrement;
LABEL_171:
  v60 = v84;
  if ( v84 && !v59((volatile LONG *)v84 + 2) )
  {
    if ( *(_DWORD *)v60 )
    {
      SysFreeString(*(BSTR *)v60);
      *(_DWORD *)v60 = 0;
    }
    if ( *((_DWORD *)v60 + 1) )
    {
      operator delete[](*((void **)v60 + 1));
      *((_DWORD *)v60 + 1) = 0;
    }
    operator delete(v60);
  }
  v61 = a2.m_Data;
  if ( a2.m_Data )
  {
    if ( !v59(&a2.m_Data->m_RefCount) && v61 )
    {
      if ( v61->m_wstr )
      {
        SysFreeString(v61->m_wstr);
        v61->m_wstr = 0;
      }
      if ( v61->m_str )
      {
        operator delete[](v61->m_str);
        v61->m_str = 0;
      }
      operator delete(v61);
    }
    a2.m_Data = 0;
  }
  v4 = bstrResource.m_Data;
  v2 = (CSystemProcessInfoMapNode *)v73;
LABEL_188:
  v72 = (wchar_t *)v2;
  v71 = v2->baseclass._Left;
  v94 = -1;
  sub_C16540((CSystemProcessInfoMap *)&v73, (CSystemProcessInfoMapNode **)&v75, v71, v2);
  operator delete(v73);
  return v4;
}
// CA4790: using guessed type wchar_t aThrottledReque[36];

//----- (00C14320) --------------------------------------------------------
int __stdcall sub_C14320(int a1, DWORD dwMessageId)
{
  HMODULE v2; // eax
  wchar_t *i; // esi
  int v4; // eax
  WCHAR Buffer; // [esp+Ch] [ebp-804h]

  Buffer = 0;
  if ( !FormatMessageW(0x1200u, 0, dwMessageId, 0, &Buffer, 0x400u, 0) )
  {
    v2 = GetModuleHandleW(L"winhttp.dll");
    FormatMessageW(0xA00u, v2, dwMessageId, 0, &Buffer, 0x400u, 0);
  }
  if ( Buffer )
  {
    for ( i = wcschr(&Buffer, 0); i > &Buffer; *i = 0 )
    {
      v4 = *(i - 1);
      --i;
      if ( !isspace(v4) )
        break;
    }
  }
  else
  {
    _swprintf(&Buffer, L"Error %d (0x%0x)", dwMessageId, dwMessageId);
  }
  _bstr_t::_bstr_t((tagEventSetItem *)a1, &Buffer);
  return a1;
}

//----- (00C14420) --------------------------------------------------------
DWORD __stdcall sub_C14420(void *a1, int a2, int a3)
{
  const WCHAR *v3; // eax
  HANDLE v4; // esi
  DWORD v5; // edi
  DWORD v6; // edi
  void *v7; // ebx
  LARGE_INTEGER FileSize; // [esp+0h] [ebp-Ch]
  DWORD NumberOfBytesRead; // [esp+8h] [ebp-4h]

  if ( a1 )
    v3 = *(const WCHAR **)a1;
  else
    v3 = 0;
  v4 = CreateFileW(v3, 0x80000000, 7u, 0, 3u, 0, 0);
  if ( v4 == (HANDLE)-1 )
  {
    v5 = GetLastError();
  }
  else
  {
    GetFileSizeEx(v4, &FileSize);
    v6 = FileSize.LowPart;
    if ( FileSize.QuadPart <= 0x2000000 )
    {
      v7 = malloc(FileSize.LowPart);
      if ( ReadFile(v4, v7, v6, &NumberOfBytesRead, 0) )
      {
        CloseHandle(v4);
        v5 = 0;
        *(_DWORD *)a2 = v7;
        *(_DWORD *)a3 = FileSize.LowPart;
      }
      else
      {
        free(v7);
        CloseHandle(v4);
        v5 = GetLastError();
      }
    }
    else
    {
      v5 = 223;
    }
  }
  if ( a1 && !InterlockedDecrement((volatile LONG *)a1 + 2) && a1 )
  {
    if ( *(_DWORD *)a1 )
    {
      SysFreeString(*(BSTR *)a1);
      *(_DWORD *)a1 = 0;
    }
    if ( *((_DWORD *)a1 + 1) )
    {
      operator delete[](*((void **)a1 + 1));
      *((_DWORD *)a1 + 1) = 0;
    }
    operator delete(a1);
  }
  return v5;
}

//----- (00C14530) --------------------------------------------------------
BSTR **__thiscall sub_C14530(void *this, int a2, OLECHAR psz, int a4)
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
  *(_DWORD *)a2 = 0;
  v4 = (std__tree *)a4;
  v5 = 1;
  v26 = 0;
  v22 = 1;
  v6 = 0;
  sub_C16500(*(void **)(*(_DWORD *)a4 + 4));
  v4->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v4->_Mypair._Myval2._Myhead;
  v4->_Mypair._Myval2._Myhead->_Left = (std_Tree_node_for_tagKeyName *)v4->_Mypair._Myval2._Myhead;
  v4->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v4->_Mypair._Myval2._Myhead;
  v7 = (const wchar_t **)psz;
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
      v12 = (BSTR **)a2;
      _bstr_t::operator=((EventItem *)a2, v9);
      *(_DWORD *)psz = i;
      v4 = (std__tree *)a4;
    }
    else
    {
      v12 = (BSTR **)a2;
      *i = 0;
      _bstr_t::operator=((EventItem *)a2, v9);
      *i = 125;
      *(_DWORD *)psz = i;
      v4 = (std__tree *)a4;
    }
  }
  else
  {
    v12 = (BSTR **)a2;
  }
  if ( !*v12 || !**v12 || !SysStringLen(**v12) )
    return v12;
  v13 = *v12 ? **v12 : 0;
  v14 = *v13 == 0;
  *(_DWORD *)&psz = v13;
  if ( v14 )
    return v12;
  do
  {
    sub_C14810((int)&v24, &psz, 58);
    v26 = 1;
    sub_C14810((int)&v25, &psz, 44);
    a2a = (int)v24;
    if ( v24 )
      InterlockedIncrement((volatile LONG *)v24 + 2);
    v21 = v25;
    if ( v25 )
      InterlockedIncrement((volatile LONG *)v25 + 2);
    LOBYTE(v26) = 3;
    v15 = sub_C111F0(v4, (std__List *)&a2a);
    sub_C11240((int *)v4, (int)&v19, 0, (int)&v15->_Keyvalue, v15);
    sub_C11430((std__List *)&a2a);
    v16 = v25;
    if ( v25 )
    {
      if ( !InterlockedDecrement((volatile LONG *)v25 + 2) && v16 )
      {
        if ( *(_DWORD *)v16 )
        {
          SysFreeString(*(BSTR *)v16);
          *(_DWORD *)v16 = 0;
        }
        if ( *((_DWORD *)v16 + 1) )
        {
          operator delete[](*((void **)v16 + 1));
          *((_DWORD *)v16 + 1) = 0;
        }
        operator delete(v16);
      }
      v25 = 0;
    }
    v17 = v24;
    LOBYTE(v26) = 0;
    if ( v24 )
    {
      if ( !InterlockedDecrement((volatile LONG *)v24 + 2) && v17 )
      {
        if ( *(_DWORD *)v17 )
        {
          SysFreeString(*(BSTR *)v17);
          *(_DWORD *)v17 = 0;
        }
        if ( *((_DWORD *)v17 + 1) )
        {
          operator delete[](*((void **)v17 + 1));
          *((_DWORD *)v17 + 1) = 0;
        }
        operator delete(v17);
      }
      v24 = 0;
    }
    v4 = (std__tree *)a4;
  }
  while ( *(_WORD *)psz );
  return (BSTR **)a2;
}

//----- (00C14810) --------------------------------------------------------
int __stdcall sub_C14810(int a1, OLECHAR *psz, __int16 a3)
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
  *(_DWORD *)a1 = 0;
  v5 = psz;
  if ( **(_WORD **)psz )
  {
    do
    {
      if ( **(_WORD **)psz != 32 )
        break;
      v6 = (_WORD *)(*(_DWORD *)psz + 2);
      *(_DWORD *)psz = v6;
    }
    while ( *v6 );
  }
  if ( **(_WORD **)psz == 34 )
  {
    v3 = 1;
    v12 = 1;
    *(_DWORD *)psz += 2;
  }
  v7 = *(_DWORD *)psz;
  psza = *(OLECHAR **)psz;
  if ( **(_WORD **)v5 )
  {
    while ( v4 || v3 || **(_WORD **)v5 != a3 )
    {
      v8 = **(unsigned __int16 **)v5;
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
        else if ( v8 == 92 && **((_WORD **)v5 + 1) == 34 )
        {
          *(_DWORD *)v5 += 2;
        }
        v3 = v12;
      }
      *(_DWORD *)v5 += 2;
      if ( !**(_WORD **)v5 )
        break;
    }
  }
  if ( v7 )
  {
    v9 = **(_WORD **)v5;
    **(_WORD **)v5 = 0;
    _bstr_t::operator=((EventItem *)a1, psza);
    **(_WORD **)v5 = v9;
  }
  if ( **(_WORD **)v5 )
  {
    do
    {
      if ( **(_WORD **)v5 == a3 )
        break;
      v10 = (_WORD *)(*(_DWORD *)v5 + 2);
      *(_DWORD *)v5 = v10;
    }
    while ( *v10 );
  }
  result = a1;
  if ( **(_WORD **)v5 == a3 )
    *(_DWORD *)v5 += 2;
  return result;
}

//----- (00C14950) --------------------------------------------------------
_bstr_t *__stdcall sub_C14950(int a1, int a2, void *a3)
{
  _bstr_t *v3; // ebx
  void *v4; // edi
  int v5; // esi
  char v6; // al
  int v7; // esi
  void *v8; // esi
  char v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v3 = (_bstr_t *)a1;
  v4 = a3;
  v11 = 0;
  *(_DWORD *)a1 = 0;
  a1 = (int)v4;
  if ( v4 )
    InterlockedIncrement((volatile LONG *)v4 + 2);
  v5 = *(_DWORD *)a2;
  v6 = *sub_C72F90((int *)a2, (int *)&v10, (volatile LONG **)&a1) != v5;
  HIBYTE(a1) = v6;
  if ( v4 )
  {
    if ( !InterlockedDecrement((volatile LONG *)v4 + 2) )
    {
      if ( *(_DWORD *)v4 )
      {
        SysFreeString(*(BSTR *)v4);
        *(_DWORD *)v4 = 0;
      }
      if ( *((_DWORD *)v4 + 1) )
      {
        operator delete[](*((void **)v4 + 1));
        *((_DWORD *)v4 + 1) = 0;
      }
      operator delete(v4);
    }
    v6 = HIBYTE(a1);
  }
  if ( v6 )
  {
    a1 = (int)a3;
    if ( a3 )
      InterlockedIncrement((volatile LONG *)a3 + 2);
    v7 = *(_DWORD *)(*sub_C72F90((int *)a2, (int *)&v10, (volatile LONG **)&a1) + 20);
    a2 = v7;
    if ( v7 )
      InterlockedIncrement((volatile LONG *)(v7 + 8));
    if ( v3 != (_bstr_t *)&a2 )
    {
      _bstr_t::_Free(v3);
      v3->m_Data = (Data_t_bstr_t *)v7;
      if ( v7 )
        InterlockedIncrement((volatile LONG *)(v7 + 8));
    }
    _bstr_t::_Free((_bstr_t *)&a2);
    _bstr_t::_Free((_bstr_t *)&a1);
  }
  v8 = a3;
  if ( a3 && !InterlockedDecrement((volatile LONG *)a3 + 2) && v8 )
  {
    if ( *(_DWORD *)v8 )
    {
      SysFreeString(*(BSTR *)v8);
      *(_DWORD *)v8 = 0;
    }
    if ( *((_DWORD *)v8 + 1) )
    {
      operator delete[](*((void **)v8 + 1));
      *((_DWORD *)v8 + 1) = 0;
    }
    operator delete(v8);
  }
  return v3;
}

//----- (00C14AA0) --------------------------------------------------------
DWORD __stdcall sub_C14AA0(tagHttpInfo *hRequest, int a2)
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
  v3 = sub_C14CA0(hRequest, (int)L"StatusCode", 0x13u, (int)&v16);
  v4 = v16;
  if ( v3 >= 0 )
  {
    if ( v16 )
      v5 = *(const unsigned __int16 **)v16;
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
        v7 = (CHAR *)operator new[](dwNumberOfBytesAvailable + 1);
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
          _bstr_t::operator+=((_bstr_t *)a2, &a2a);
          LOBYTE(v18) = 0;
          _bstr_t::_Free(&a2a);
        }
        else
        {
          v2 = GetLastError();
        }
        operator delete[](v8);
        if ( !dwNumberOfBytesAvailable )
          goto LABEL_28;
      }
      v9 = GetLastError();
      goto LABEL_27;
    }
  }
  if ( v16 )
    v10 = *(const unsigned __int16 **)v16;
  else
    v10 = 0;
  v11 = wcscmp(v10, L"204");
  if ( v11 )
    v11 = -(v11 < 0) | 1;
  if ( v11 )
  {
    v13 = v16;
    if ( v16 )
      InterlockedIncrement((volatile LONG *)v16 + 2);
    v9 = sub_C14D50(v13);
LABEL_27:
    v2 = v9;
    goto LABEL_28;
  }
  v2 = 232;
LABEL_28:
  if ( v4 && !InterlockedDecrement((volatile LONG *)v4 + 2) )
  {
    if ( *(_DWORD *)v4 )
    {
      SysFreeString(*(BSTR *)v4);
      *(_DWORD *)v4 = 0;
    }
    if ( *((_DWORD *)v4 + 1) )
    {
      operator delete[](*((void **)v4 + 1));
      *((_DWORD *)v4 + 1) = 0;
    }
    operator delete(v4);
  }
  return v2;
}
// CA45DC: using guessed type wchar_t a200[4];
// CA45EC: using guessed type wchar_t a204[4];
// CA45F4: using guessed type wchar_t aStatuscode[11];

//----- (00C14CA0) --------------------------------------------------------
int __stdcall sub_C14CA0(HINTERNET hRequest, int a2, DWORD dwInfoLevel, int a4)
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
    v6 = (OLECHAR *)malloc(dwBufferLength);
    if ( WinHttpQueryHeaders(hRequest, dwInfoLevel, 0, v6, &dwBufferLength, 0) )
    {
      _bstr_t::operator=((EventItem *)a4, v6);
    }
    else
    {
      v7 = GetLastError();
      v4 = v7;
      if ( v7 > 0 )
      {
        v8 = (unsigned __int16)v7 | 0x80070000;
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
      result = (unsigned __int16)result | 0x80070000;
  }
  return result;
}

//----- (00C14D50) --------------------------------------------------------
int __stdcall sub_C14D50(void *a1)
{
  const unsigned __int16 *v1; // eax
  int v2; // eax
  signed int v3; // edi
  const unsigned __int16 *v4; // eax
  int v5; // eax
  const unsigned __int16 *v6; // eax
  int v7; // eax

  if ( a1 )
    v1 = *(const unsigned __int16 **)a1;
  else
    v1 = 0;
  v2 = wcscmp(v1, L"200");
  if ( v2 )
    v2 = -(v2 < 0) | 1;
  if ( v2 )
  {
    if ( a1 )
      v4 = *(const unsigned __int16 **)a1;
    else
      v4 = 0;
    v5 = wcscmp(v4, L"403");
    if ( v5 )
      v5 = -(v5 < 0) | 1;
    if ( v5 )
    {
      if ( a1 )
        v6 = *(const unsigned __int16 **)a1;
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
  if ( a1 && !InterlockedDecrement((volatile LONG *)a1 + 2) && a1 )
  {
    if ( *(_DWORD *)a1 )
    {
      SysFreeString(*(BSTR *)a1);
      *(_DWORD *)a1 = 0;
    }
    if ( *((_DWORD *)a1 + 1) )
    {
      operator delete[](*((void **)a1 + 1));
      *((_DWORD *)a1 + 1) = 0;
    }
    operator delete(a1);
  }
  return v3;
}
// CA45DC: using guessed type wchar_t a200[4];
// CA45E4: using guessed type wchar_t a403[4];
// CA45EC: using guessed type wchar_t a204[4];

//----- (00C14E80) --------------------------------------------------------
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
  v6->m_hSession = (int)v8;
  if ( !v8 )
    return GetLastError();
  v9 = WinHttpConnect(v8, L"www.virustotal.com", 0x1BBu, 0);
  v6->m_hConnect = (int)v9;
  if ( !v9 )
  {
    WinHttpCloseHandle((HINTERNET)v6->m_hSession);
    v6->m_hSession = 0;
    return GetLastError();
  }
  return 0;
}

//----- (00C14F00) --------------------------------------------------------
DWORD __thiscall sub_C14F00(HINTERNET *this, void *a2, void *a3, void *a4, int a5)
{
  HINTERNET *v5; // esi
  const WCHAR *v6; // eax
  tagHttpInfo *v7; // ebx
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
    v6 = *(const WCHAR **)a2;
  else
    v6 = 0;
  v7 = (tagHttpInfo *)WinHttpOpenRequest(this[1], L"POST", v6, 0, 0, 0, 0x800000u);
  pAutoProxyOptions.dwFlags = 1;
  pAutoProxyOptions.dwAutoDetectFlags = 3;
  pAutoProxyOptions.fAutoLogonIfChallenged = 1;
  if ( WinHttpGetProxyForUrl(*v5, L"https://www.virustotal.com", &pAutoProxyOptions, &pProxyInfo) )
    WinHttpSetOption(v7, 0x26u, &pProxyInfo, 0xCu);
  v8 = (BSTR *)a4;
  if ( !a4 )
  {
    v12 = 0;
    v10 = 0;
LABEL_21:
    v11 = 0;
    goto LABEL_22;
  }
  if ( *(_DWORD *)a4 )
  {
    v8 = (BSTR *)a4;
    dwTotalLength = SysStringLen(*(BSTR *)a4);
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
    v8 = (BSTR *)a4;
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
    v8[1] = (BSTR)_com_util::ConvertBSTRToString(*v8);
  v11 = v8[1];
  v12 = dwTotalLength;
LABEL_22:
  if ( a3 )
    v13 = *(const WCHAR **)a3;
  else
    v13 = 0;
  if ( WinHttpSendRequest(v7, v13, 0, v11, v10, v12, 0) && WinHttpReceiveResponse(v7, 0) )
    v14 = sub_C14AA0(v7, a5);
  else
    v14 = GetLastError();
  v15 = v14;
  WinHttpCloseHandle(v7);
  v16 = InterlockedDecrement;
  if ( a2 )
  {
    if ( !InterlockedDecrement((volatile LONG *)a2 + 2) && a2 )
    {
      if ( *(_DWORD *)a2 )
      {
        SysFreeString(*(BSTR *)a2);
        *(_DWORD *)a2 = 0;
      }
      if ( *((_DWORD *)a2 + 1) )
      {
        operator delete[](*((void **)a2 + 1));
        *((_DWORD *)a2 + 1) = 0;
      }
      operator delete(a2);
    }
    v16 = InterlockedDecrement;
  }
  if ( a3 && !v16((volatile LONG *)a3 + 2) && a3 )
  {
    if ( *(_DWORD *)a3 )
    {
      SysFreeString(*(BSTR *)a3);
      *(_DWORD *)a3 = 0;
    }
    if ( *((_DWORD *)a3 + 1) )
    {
      operator delete[](*((void **)a3 + 1));
      *((_DWORD *)a3 + 1) = 0;
    }
    operator delete(a3);
  }
  if ( a4 && !InterlockedDecrement((volatile LONG *)a4 + 2) && a4 )
  {
    if ( *(_DWORD *)a4 )
    {
      SysFreeString(*(BSTR *)a4);
      *(_DWORD *)a4 = 0;
    }
    if ( *((_DWORD *)a4 + 1) )
    {
      operator delete[](*((void **)a4 + 1));
      *((_DWORD *)a4 + 1) = 0;
    }
    operator delete(a4);
  }
  return v15;
}

//----- (00C15160) --------------------------------------------------------
std__list_node *__thiscall sub_C15160(tagHttpInfo *this, char a2)
{
  std__list_node *v2; // edi
  std__List *v3; // esi
  std__list_node *v4; // edx
  unsigned int v5; // eax
  std__list_node *result; // eax

  v2 = this->m_List._Mypair._Myval2._Myhead;
  v3 = &this->m_List;
  v4 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
         (EventList *)this->m_List._Mypair._Myval2._Myhead,
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

//----- (00C151B0) --------------------------------------------------------
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
  if ( RegOpenKeyExW(HKEY_CURRENT_USER, (LPCWSTR)this->szKeyName, 0, KEY_READ, &this->hKey) )
    return 0;
  if ( pConfigItem->Name )
  {
    RegQueryValueExW = ::RegQueryValueExW;
    pBuffer = (PUCHAR)&pConfigItem->dbValue;
    do
    {
      switch ( *((_DWORD *)pBuffer - 3) )       // pConfigItem->RegType
      {
        case KT_None:                           // REG_NONE
          cbData = (unsigned int)*(double *)pBuffer;// cbData = pConfigItem->dwValue1
          pItem = (tagConfigItem *)*((_DWORD *)pBuffer - 4);// pItem=pConfigItem->Name
          FileTime.dwLowDateTime = *((_DWORD *)pBuffer - 1);// Buffer[0]=pConfigItem->Address
          v7 = *phKey;
          pConfigItem = (tagConfigItem *)4;
          if ( ::RegQueryValueExW(v7, (LPCWSTR)pItem, 0, 0, (LPBYTE)FileTime.dwHighDateTime, (LPDWORD)&pConfigItem) )
            *(_DWORD *)FileTime.dwHighDateTime = cbData;
          goto __Next;
        case KT_Bool:                           // REG_SZ
          Address = (_BYTE *)*((_DWORD *)pBuffer - 1);// pConfigItem->Address
          dbValue = (signed int)*(double *)pBuffer;
          cbData = 4;
          pConfigItem = (tagConfigItem *)(unsigned __int8)*Address;
          // RegQueryValueExW(pThis->hKey,pConfigItem->Name,NULL,NULL,&pConfigItem->Address,&cbData);
          lRet = RegQueryValueExW(pThis->hKey, *((LPCWSTR *)pBuffer - 4), 0, 0, (LPBYTE)&pConfigItem, &cbData);
          v11 = (char)pConfigItem;
          v12 = dbValue;
          phKey = hKey;
          if ( lRet )
            v11 = v12;
          *Address = v11;
          pRegKeyInfo = pThis;
          goto __Next;
        case KT_Double:                         // REG_EXPAND_SZ
          v13 = (BYTE *)*((_DWORD *)pBuffer - 1);// pConfigItem->Address
          Name = (const WCHAR *)*((_DWORD *)pBuffer - 4);// pConfigItem->Name
          FileTime = *(FILETIME *)pBuffer;
          hKey_ = *phKey;
          cbData = (DWORD)v13;
          pConfigItem = (tagConfigItem *)8;
          v16 = RegQueryValueExW(hKey_, Name, 0, 0, v13, (LPDWORD)&pConfigItem);
          RegQueryValueExW = ::RegQueryValueExW;
          if ( v16 )
            *(FILETIME *)cbData = FileTime;
          break;
        case KT_Short:                          // REG_BINARY
          RegKeyInfo_LoadWord(
            pRegKeyInfo,
            *((LPCWSTR *)pBuffer - 4),
            *((WORD **)pBuffer - 1),
            (unsigned __int16)(signed int)*(double *)pBuffer);
          goto __Next;                          // REG_DWORD
        case KT_String:
          v17 = *(double *)pBuffer;             //  pConfigItem->dwValue1
          pConfigItem = (tagConfigItem *)*((_DWORD *)pBuffer - 2);// pConfigItem->StructSize
          cbData = (unsigned int)v17;
          pszName = (const WCHAR *)*((_DWORD *)pBuffer - 4);// pConfigItem->Name
          FileTime.dwHighDateTime = *((_DWORD *)pBuffer - 1);// pConfigItem->Address
          if ( ::RegQueryValueExW(*phKey, pszName, 0, 0, (LPBYTE)FileTime.dwHighDateTime, (LPDWORD)&pConfigItem)
            && cbData )
          {
            wcscpy_s((wchar_t *)FileTime.dwHighDateTime, (rsize_t)pConfigItem, (const wchar_t *)cbData);
          }
          goto __Next;
        case KT_LongArray:                      // REG_DWORD_BIG_ENDIAN
          RegKeyInfo_LoadDwordArray(
            pRegKeyInfo,
            *((LPCWSTR *)pBuffer - 4),
            *((_DWORD *)pBuffer - 2) >> 2,
            *((PVOID *)pBuffer - 1));
          goto __Next;
        case KT_ShortArray:                     // REG_LINK
          RegKeyInfo_LoadShortArray(
            pRegKeyInfo,
            *((LPCWSTR *)pBuffer - 4),
            *((_DWORD *)pBuffer - 2) >> 1,
            *((PVOID *)pBuffer - 1));
          goto __Next;
        case KT_Structure:                      // REG_MULTI_SZ
          pConfigItem = (tagConfigItem *)*((_DWORD *)pBuffer - 2);
          // RegQueryValueExW(*hKey,pConfigItem->Name, NULL, NULL, pConfigItem->Address,&pConfigItem->StructSize)
          RegQueryValueExW(*phKey, *((LPCWSTR *)pBuffer - 4), 0, 0, *((LPBYTE *)pBuffer - 1), (LPDWORD)&pConfigItem);
__Next:
          RegQueryValueExW = ::RegQueryValueExW;
          break;
        default:
          break;
      }
      pBuffer += sizeof(tagConfigItem);
    }
    while ( *((_DWORD *)pBuffer - 4) );         // pConfigItem->Name
  }
  RegCloseKey(*phKey);
  return 1;
}
// C1538B: CONTAINING_RECORD: no field 'PUCHAR' in struct 'tagConfigItem' at 24

//----- (00C153E0) --------------------------------------------------------
LSTATUS __thiscall RegKeyInfo_LoadDwordArray(tagRegKeyInfo *pThis, LPCWSTR lpValueName, DWORD cbSize, PVOID pMap)
{
  BYTE *pdwValue; // edi
  LSTATUS lresult; // eax
  DWORD Index; // esi
  DWORD cbData; // [esp+4h] [ebp-2Ch]
  HKEY hSubKey; // [esp+8h] [ebp-28h]
  __int16 ValueName[16]; // [esp+Ch] [ebp-24h]

  pdwValue = (BYTE *)pMap;
  lresult = RegOpenKeyExW(pThis->hKey, lpValueName, 0, KEY_READ, &hSubKey);
  if ( !lresult )
  {
    Index = 0;
    if ( cbSize )
    {
      do
      {
        cbData = 4;
        sub_C113E0((wchar_t *)ValueName, L"%d", Index);
        RegQueryValueExW(hSubKey, (LPCWSTR)ValueName, 0, 0, pdwValue, &cbData);
        ++Index;
        pdwValue += 4;
      }
      while ( Index < cbSize );
    }
    lresult = RegCloseKey(hSubKey);
  }
  return lresult;
}

//----- (00C15480) --------------------------------------------------------
int __thiscall RegKeyInfo_LoadWord(tagRegKeyInfo *this, LPCWSTR lpValueName, WORD *dwValue, DWORD dwDefValue)
{
  WORD *pwValueIn; // esi
  LSTATUS v5; // eax
  signed __int16 v6; // dx
  int result; // eax
  DWORD cbData; // [esp+4h] [ebp-4h]

  pwValueIn = dwValue;
  cbData = 4;
  dwValue = (WORD *)(signed __int16)*dwValue;
  v5 = RegQueryValueExW(this->hKey, lpValueName, 0, 0, (LPBYTE)&dwValue, &cbData);
  v6 = (signed __int16)dwValue;
  if ( v5 )
    v6 = dwDefValue;
  *pwValueIn = v6;
  result = MulDiv(v6, gLogPixelSize.x, 96);
  *pwValueIn = result;
  return result;
}

//----- (00C154E0) --------------------------------------------------------
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
        sub_C113E0(&ValueName, L"%d", v5);
        if ( !RegQueryValueExW(hSubKey, &ValueName, 0, 0, (LPBYTE)Data, &cbData) )
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

//----- (00C155A0) --------------------------------------------------------
DWORD __thiscall sub_C155A0(tagHttpInfo *this, int a2, OLECHAR psz)
{
  tagHttpInfo *v3; // ebx
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
  tagHttpInfo *v83; // edi
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
  _bstr_t bstrRet; // [esp+50h] [ebp-44h]
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
  _bstr_t::operator=((EventItem *)psz, (OLECHAR *)&gszNullString);
  v4 = a2;
  v102 = &dwMessageId;
  v111.m_Data = (Data_t_bstr_t *)(a2 + 12);
  v5 = *(volatile LONG **)(a2 + 12);
  v101 = v5;
  if ( v5 )
    InterlockedIncrement(v5 + 2);
  v6 = sub_C14420((void *)v101, (int)&lpBuffer, (int)v102);
  v7 = v6;
  if ( v6 )
  {
    sub_C14320((int)&v124, v6);
    v8 = (_bstr_t *)(v4 + 24);
    if ( v8 != (_bstr_t *)&v124 )
    {
      _bstr_t::_Free(v8);
      v9 = v124;
      v8->m_Data = (Data_t_bstr_t *)v124;
      if ( v9 )
        InterlockedIncrement((volatile LONG *)(v9 + 8));
    }
    v10 = (_bstr_t *)&v124;
  }
  else
  {
    v125.m_Data = 0;
    LOBYTE(v126) = 1;
    v11 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a1, L"\r\n");
    LOBYTE(v126) = 2;
    v12 = (_bstr_t *)_bstr_t::_bstr_t(
                       (tagEventSetItem *)&dwNumberOfBytesToWrite,
                       L"---------------------------41184676334");
    LOBYTE(v126) = 3;
    v13 = _bstr_t::operator+((_bstr_t *)&hRequest, L"--", v12);
    LOBYTE(v126) = 4;
    v14 = _bstr_t::operator+(v13, &a2a, v11);
    LOBYTE(v126) = 5;
    _bstr_t::operator+=(&v125, v14);
    _bstr_t::_Free(&a2a);
    _bstr_t::_Free((_bstr_t *)&hRequest);
    _bstr_t::_Free((_bstr_t *)&dwNumberOfBytesToWrite);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a1);
    _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"Content-Disposition: form-data; name=\"apikey\"\r\n");
    LOBYTE(v126) = 6;
    _bstr_t::operator+=(&v125, &a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a2a);
    v15 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&bstrRet, L"\r\n");
    LOBYTE(v126) = 7;
    v16 = _bstr_t::_bstr_t(
            (_bstr_t *)&dwNumberOfBytesToWrite,
            "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c");
    LOBYTE(v126) = 8;
    v17 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"\r\n");
    LOBYTE(v126) = 9;
    v18 = _bstr_t::operator+(v17, &a2a, v16);
    LOBYTE(v126) = 10;
    v19 = _bstr_t::operator+(v18, &a1, v15);
    LOBYTE(v126) = 11;
    _bstr_t::operator+=(&v125, v19);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    _bstr_t::_Free((_bstr_t *)&hRequest);
    _bstr_t::_Free((_bstr_t *)&dwNumberOfBytesToWrite);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&bstrRet);
    v20 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"\r\n");
    LOBYTE(v126) = 12;
    v21 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"---------------------------41184676334");
    LOBYTE(v126) = 13;
    v22 = _bstr_t::operator+(&a1, L"--", v21);
    LOBYTE(v126) = 14;
    v23 = _bstr_t::operator+(v22, &bstrRet, v20);
    LOBYTE(v126) = 15;
    _bstr_t::operator+=(&v125, v23);
    _bstr_t::_Free(&bstrRet);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free((_bstr_t *)&hRequest);
    _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"Content-Disposition: form-data; name=\"creation_datetime\"\r\n");
    LOBYTE(v126) = 16;
    _bstr_t::operator+=(&v125, &a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a2a);
    v24 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&dwNumberOfBytesToWrite, L"\r\n");
    LOBYTE(v126) = 17;
    v25 = (_bstr_t *)sub_C118A0((int)&hRequest, (FILETIME *)(a2 + 16));
    LOBYTE(v126) = 18;
    v26 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"\r\n");
    LOBYTE(v126) = 19;
    v27 = _bstr_t::operator+(v26, &a1, v25);
    LOBYTE(v126) = 20;
    v28 = _bstr_t::operator+(v27, &bstrRet, v24);
    LOBYTE(v126) = 21;
    _bstr_t::operator+=(&v125, v28);
    _bstr_t::_Free(&bstrRet);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    _bstr_t::_Free((_bstr_t *)&hRequest);
    LOBYTE(v126) = 1;
    _bstr_t::_Free((_bstr_t *)&dwNumberOfBytesToWrite);
    v29 = (_bstr_t *)a2;
    v30 = SysStringLen;
    if ( *(_DWORD *)a2 && **(_DWORD **)a2 )
    {
      if ( SysStringLen(**(BSTR **)a2) )
      {
        v31 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"\r\n");
        LOBYTE(v126) = 22;
        v32 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"---------------------------41184676334");
        LOBYTE(v126) = 23;
        v33 = _bstr_t::operator+(&a1, L"--", v32);
        LOBYTE(v126) = 24;
        v34 = _bstr_t::operator+(v33, &bstrRet, v31);
        LOBYTE(v126) = 25;
        _bstr_t::operator+=(&v125, v34);
        _bstr_t::_Free(&bstrRet);
        _bstr_t::_Free(&a1);
        _bstr_t::_Free(&a2a);
        LOBYTE(v126) = 1;
        _bstr_t::_Free((_bstr_t *)&hRequest);
        _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"Content-Disposition: form-data; name=\"autostart_location\"\r\n");
        LOBYTE(v126) = 26;
        _bstr_t::operator+=(&v125, &a2a);
        LOBYTE(v126) = 1;
        _bstr_t::_Free(&a2a);
        v35 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"\r\n");
        LOBYTE(v126) = 27;
        v36 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"\r\n");
        LOBYTE(v126) = 28;
        v37 = _bstr_t::operator+(v36, &a1, v29);
        LOBYTE(v126) = 29;
        v38 = _bstr_t::operator+(v37, &bstrRet, v35);
        LOBYTE(v126) = 30;
        _bstr_t::operator+=(&v125, v38);
        _bstr_t::_Free(&bstrRet);
        _bstr_t::_Free(&a1);
        _bstr_t::_Free(&a2a);
        LOBYTE(v126) = 1;
        _bstr_t::_Free((_bstr_t *)&hRequest);
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
          v42 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"\r\n");
          LOBYTE(v126) = 31;
          v43 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"---------------------------41184676334");
          LOBYTE(v126) = 32;
          v44 = _bstr_t::operator+(&a1, L"--", v43);
          LOBYTE(v126) = 33;
          v45 = _bstr_t::operator+(v44, &bstrRet, v42);
          LOBYTE(v126) = 34;
          _bstr_t::operator+=(&v125, v45);
          _bstr_t::_Free(&bstrRet);
          _bstr_t::_Free(&a1);
          _bstr_t::_Free(&a2a);
          LOBYTE(v126) = 1;
          _bstr_t::_Free((_bstr_t *)&hRequest);
          _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"Content-Disposition: form-data; name=\"autostart_entry\"\r\n");
          LOBYTE(v126) = 35;
          _bstr_t::operator+=(&v125, &a2a);
          LOBYTE(v126) = 1;
          _bstr_t::_Free(&a2a);
          v46 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"\r\n");
          LOBYTE(v126) = 36;
          v47 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"\r\n");
          LOBYTE(v126) = 37;
          v48 = _bstr_t::operator+(v47, &a1, v40);
          LOBYTE(v126) = 38;
          v49 = _bstr_t::operator+(v48, &bstrRet, v46);
          LOBYTE(v126) = 39;
          _bstr_t::operator+=(&v125, v49);
          _bstr_t::_Free(&bstrRet);
          _bstr_t::_Free(&a1);
          _bstr_t::_Free(&a2a);
          LOBYTE(v126) = 1;
          _bstr_t::_Free((_bstr_t *)&hRequest);
        }
      }
    }
    v50 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"\r\n");
    LOBYTE(v126) = 40;
    v51 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"---------------------------41184676334");
    LOBYTE(v126) = 41;
    v52 = _bstr_t::operator+(&a1, L"--", v51);
    LOBYTE(v126) = 42;
    v53 = _bstr_t::operator+(v52, &bstrRet, v50);
    LOBYTE(v126) = 43;
    _bstr_t::operator+=(&v125, v53);
    _bstr_t::_Free(&bstrRet);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free((_bstr_t *)&hRequest);
    _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"\"");
    LOBYTE(v126) = 44;
    v54 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&dwNumberOfBytesToWrite, L"\r\n");
    LOBYTE(v126) = 45;
    v55 = _bstr_t::operator+(
            (_bstr_t *)&hRequest,
            L"Content-Disposition: form-data; name=\"file\"; filename=\"",
            (_bstr_t *)v111.m_Data);
    LOBYTE(v126) = 46;
    v56 = _bstr_t::operator+(v55, &a1, &a2a);
    LOBYTE(v126) = 47;
    v57 = _bstr_t::operator+(v56, &bstrRet, v54);
    LOBYTE(v126) = 48;
    _bstr_t::operator+=(&v125, v57);
    _bstr_t::_Free(&bstrRet);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free((_bstr_t *)&hRequest);
    _bstr_t::_Free((_bstr_t *)&dwNumberOfBytesToWrite);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a2a);
    v58 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&bstrRet, L"\r\n");
    LOBYTE(v126) = 49;
    v59 = _bstr_t::operator+(&v111, L"Content-Type: application/octet-stream\r\n", v58);
    LOBYTE(v126) = 50;
    _bstr_t::operator+=(&v125, v59);
    _bstr_t::_Free(&v111);
    _bstr_t::_Free(&bstrRet);
    a2a.m_Data = 0;
    LOBYTE(v126) = 51;
    _bstr_t::_bstr_t((tagEventSetItem *)&dwNumberOfBytesToWrite, L"--");
    LOBYTE(v126) = 52;
    _bstr_t::_bstr_t((tagEventSetItem *)&hRequest, L"--");
    LOBYTE(v126) = 53;
    v60 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v107, L"\r\n");
    LOBYTE(v126) = 54;
    v61 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v108, L"---------------------------41184676334");
    LOBYTE(v126) = 55;
    v62 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v109, L"\r\n");
    LOBYTE(v126) = 56;
    v63 = _bstr_t::operator+(v62, &v110, (_bstr_t *)&hRequest);
    LOBYTE(v126) = 57;
    v64 = _bstr_t::operator+(v63, &a1, v61);
    LOBYTE(v126) = 58;
    v65 = _bstr_t::operator+(v64, &bstrRet, (_bstr_t *)&dwNumberOfBytesToWrite);
    LOBYTE(v126) = 59;
    v66 = _bstr_t::operator+(v65, &v111, v60);
    LOBYTE(v126) = 60;
    _bstr_t::operator+=(&a2a, v66);
    _bstr_t::_Free(&v111);
    _bstr_t::_Free(&bstrRet);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&v110);
    _bstr_t::_Free(&v109);
    _bstr_t::_Free(&v108);
    _bstr_t::_Free(&v107);
    _bstr_t::_Free((_bstr_t *)&hRequest);
    LOBYTE(v126) = 51;
    _bstr_t::_Free((_bstr_t *)&dwNumberOfBytesToWrite);
    v102 = (void *)0x800000;
    v67 = WinHttpOpenRequest((HINTERNET)v3->m_hConnect, L"POST", L"vtapi/v2/file/scan", 0, 0, 0, 0x800000u);
    pAutoProxyOptions.dwFlags = 1;
    hRequest = v67;
    v102 = &pProxyInfo;
    pAutoProxyOptions.dwAutoDetectFlags = 3;
    v68 = (void *)v3->m_hSession;
    pAutoProxyOptions.fAutoLogonIfChallenged = 1;
    if ( WinHttpGetProxyForUrl(v68, L"https://www.virustotal.com", &pAutoProxyOptions, &pProxyInfo) )
      WinHttpSetOption(v67, 0x26u, &pProxyInfo, 0xCu);
    v69 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v110, L"\r\n");
    LOBYTE(v126) = 61;
    v70 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v109, L"---------------------------41184676334");
    LOBYTE(v126) = 62;
    v71 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v108, L"Content-Type: multipart/form-data; boundary=");
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
          v73->m_str = _com_util::ConvertBSTRToString(v73->m_wstr);
        v81 = v73->m_str;
        v82 = dwNumberOfBytesToWrite;
      }
      else
      {
        v82 = 0;
        v81 = 0;
      }
      v83 = (tagHttpInfo *)hRequest;
      WinHttpWriteData(hRequest, v81, v82, &dwNumberOfBytesWritten);
      WinHttpWriteData(v83, lpBuffer, dwMessageId, &dwNumberOfBytesWritten);
      if ( v74 )
      {
        if ( v74->m_wstr )
          dwMessageId = SysStringLen(v74->m_wstr);
        else
          dwMessageId = 0;
        if ( !v74->m_str )
          v74->m_str = _com_util::ConvertBSTRToString(v74->m_wstr);
        v84 = v74->m_str;
        v85 = dwMessageId;
      }
      else
      {
        v85 = 0;
        v84 = 0;
      }
      WinHttpWriteData(v83, v84, v85, &dwNumberOfBytesWritten);
      free((void *)lpBuffer);
      if ( WinHttpReceiveResponse(v83, 0) )
      {
        v89 = (_DWORD **)psz;
        dwMessageId = sub_C14AA0(v83, psz);
        WinHttpCloseHandle(v83);
        v7 = dwMessageId;
        if ( dwMessageId )
        {
          sub_C14320((int)&v118, dwMessageId);
          v98 = (_bstr_t *)(a2 + 24);
          if ( (_bstr_t *)(a2 + 24) != &v118 )
          {
            _bstr_t::_Free((_bstr_t *)(a2 + 24));
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
            *(_DWORD *)&psz = **v89;
          else
            *(_DWORD *)&psz = 0;
          sub_C14530(v3, (int)&lpBuffer, (unsigned int)&psz, (int)&v105);
          LOBYTE(v126) = 70;
          if ( lpBuffer && *(_DWORD *)lpBuffer && SysStringLen(*(BSTR *)lpBuffer) )
          {
            v102 = v90;
            _bstr_t::_bstr_t((tagEventSetItem *)&v102, L"permalink");
            v91 = sub_C14950((int)&psz, (int)&v105, v102);
            v92 = a2;
            _bstr_t::operator=((_bstr_t *)(a2 + 28), v91);
            _bstr_t::_Free((_bstr_t *)&psz);
            if ( _bstr_t::length((tagEventItem *)(v92 + 28)) )
            {
              _bstr_t::operator=((EventItem *)(v92 + 32), L"Submitted");
            }
            else
            {
              v102 = v93;
              _bstr_t::_bstr_t((tagEventSetItem *)&v102, L"verbose_msg");
              v94 = sub_C14950((int)&v107, (int)&v105, v102);
              LOBYTE(v126) = 71;
              v95 = _bstr_t::operator+((_bstr_t *)&psz, L"Submission error: ", v94);
              _bstr_t::operator=((_bstr_t *)(v92 + 24), v95);
              _bstr_t::_Free((_bstr_t *)&psz);
              LOBYTE(v126) = 70;
              _bstr_t::_Free(&v107);
            }
            v102 = v96;
            _bstr_t::_bstr_t((tagEventSetItem *)&v102, L"scan_id");
            v97 = sub_C14950((int)&psz, (int)&v105, v102);
            _bstr_t::operator=((_bstr_t *)(v92 + 8), v97);
            _bstr_t::_Free((_bstr_t *)&psz);
            std::list<tagEventItem *,std::allocator<tagEventItem *>>::push_back(&v3->m_List2, (int)&a2);
            v7 = dwMessageId;
          }
          v80 = (_bstr_t *)&lpBuffer;
        }
      }
      else
      {
        v86 = GetLastError();
        sub_C14320((int)&v119, v86);
        v87 = (int *)(a2 + 24);
        if ( (int *)(a2 + 24) != &v119 )
        {
          _bstr_t::_Free((_bstr_t *)(a2 + 24));
          v88 = v119;
          *v87 = v119;
          if ( v88 )
            InterlockedIncrement((volatile LONG *)(v88 + 8));
        }
        WinHttpCloseHandle(v83);
        v7 = GetLastError();
        v80 = (_bstr_t *)&v119;
      }
    }
    else
    {
      v77 = (void *)lpBuffer;
      free((void *)lpBuffer);
      sub_C14320((int)&v122, 0);
      v78 = (int *)(a2 + 24);
      if ( (int *)(a2 + 24) != &v122 )
      {
        _bstr_t::_Free((_bstr_t *)(a2 + 24));
        v79 = v122;
        *v78 = v122;
        if ( v79 )
          InterlockedIncrement((volatile LONG *)(v79 + 8));
      }
      WinHttpCloseHandle(hRequest);
      free(v77);
      v7 = GetLastError();
      v80 = (_bstr_t *)&v122;
    }
    _bstr_t::_Free(v80);
    _bstr_t::_Free(&v114);
    _bstr_t::_Free(&a2a);
    v10 = &v125;
  }
  _bstr_t::_Free(v10);
  v102 = v105;
  v126 = -1;
  sub_C16540(
    (CSystemProcessInfoMap *)&v105,
    (CSystemProcessInfoMapNode **)&a2,
    *(CSystemProcessInfoMapNode **)v105,
    (CSystemProcessInfoMapNode *)v105);
  operator delete(v105);
  return v7;
}

//----- (00C16210) --------------------------------------------------------
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
  result = RegCreateKeyExW(HKEY_CURRENT_USER, (LPCWSTR)pThis->szKeyName, 0, 0, 0, KEY_WRITE, 0, &pThis->hKey, 0);
  if ( !result )
  {
    if ( pConfigItem->Name )
    {
      RegSetValueExW = (void (__stdcall *)(HKEY, LPCWSTR, DWORD, DWORD, const BYTE *, DWORD))::RegSetValueExW;
      pAddrBuf = (PUCHAR)&pConfigItem->Address;
      do
      {
        switch ( *((_DWORD *)pAddrBuf - 2) )
        {
          case KT_None:
            pConfigItem = **(tagConfigItem ***)pAddrBuf;
            RegSetValueExW(*phKey, *((LPCWSTR *)pAddrBuf - 3), 0, REG_DWORD, (const BYTE *)&pConfigItem, 4u);
            goto __Next;
          case KT_Bool:
            v15 = **(unsigned __int8 **)pAddrBuf;
            RegSetValueExW(*phKey, *((LPCWSTR *)pAddrBuf - 3), 0, REG_DWORD, (const BYTE *)&v15, 4u);
            goto __Next;
          case KT_Double:
            v11 = 8;
            v12 = *(_QWORD *)*(_DWORD *)pAddrBuf;
            v10 = (tagConfigItem **)&v12;
            goto __WriteKey;
          case KT_Short:
            v7 = (const WCHAR *)*((_DWORD *)pAddrBuf - 3);
            *(_DWORD *)Data = MulDiv(**(signed __int16 **)pAddrBuf, 96, gLogPixelSize.x);
            ::RegSetValueExW(*phKey, v7, 0, REG_DWORD, Data, 4u);
            this = pRegKeyInfo;
            goto __Next;
          case KT_String:
            v8 = *(tagConfigItem ***)pAddrBuf;
            v15 = *(_DWORD *)pAddrBuf + 2;
            do
            {
              v9 = *(_WORD *)v8;
              v8 = (tagConfigItem **)((char *)v8 + 2);
            }
            while ( v9 );
            RegSetValueExW(
              *phKey,
              *((LPCWSTR *)pAddrBuf - 3),
              0,
              REG_SZ,
              *(const BYTE **)pAddrBuf,
              2 * (((signed int)v8 - v15) >> 1) + 2);
            goto __Next;
          case KT_LongArray:
            RegKeyInfo_SaveLongArray(
              (HKEY *)this,
              *((LPCWSTR *)pAddrBuf - 3),
              *((_DWORD *)pAddrBuf - 1) >> 2,
              *(BYTE **)pAddrBuf);
            goto __Next;
          case KT_ShortArray:
            RegKeyInfo_SaveShortArray(
              this,
              *((LPCWSTR *)pAddrBuf - 3),
              *((_DWORD *)pAddrBuf - 1) >> 1,
              *(PVOID *)pAddrBuf);
            goto __Next;
          case KT_Structure:
            v11 = *((_DWORD *)pAddrBuf - 1);
            v10 = *(tagConfigItem ***)pAddrBuf;
__WriteKey:
            RegSetValueExW(*phKey, *((LPCWSTR *)pAddrBuf - 3), 0, REG_BINARY, (const BYTE *)v10, v11);
__Next:
            RegSetValueExW = (void (__stdcall *)(HKEY, LPCWSTR, DWORD, DWORD, const BYTE *, DWORD))::RegSetValueExW;
            break;
          default:
            break;
        }
        pAddrBuf += sizeof(tagConfigItem);
      }
      while ( *((_DWORD *)pAddrBuf - 3) );
    }
    result = RegCloseKey(*phKey);
  }
  return result;
}
// C1634D: CONTAINING_RECORD: no field 'PUCHAR' in struct 'tagConfigItem' at 24

//----- (00C16390) --------------------------------------------------------
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
        sub_C113E0(&ValueName, L"%d", v6);
        if ( *(_DWORD *)v4 )
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

//----- (00C16430) --------------------------------------------------------
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
        sub_C113E0(&ValueName, L"%d", v5);
        Data = MulDiv((unsigned __int16)v7[v5], 96, gLogPixelSize.x);
        if ( v7[v5] )
          RegSetValueExW(phkResult, &ValueName, 0, 4u, (const BYTE *)&Data, 4u);
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

//----- (00C16500) --------------------------------------------------------
void __stdcall sub_C16500(void *a1)
{
  std__List *v1; // edi
  std__List *v2; // esi

  v1 = (std__List *)a1;
  v2 = (std__List *)a1;
  if ( !*((_BYTE *)a1 + 13) )
  {
    do
    {
      sub_C16500(v2[1]._Mypair._Myval2._Myhead);
      v2 = (std__List *)v2->_Mypair._Myval2._Myhead;
      sub_C11430(v1 + 2);
      operator delete(v1);
      v1 = v2;
    }
    while ( !BYTE1(v2[1]._Mypair._Myval2._Mysize) );
  }
}

//----- (00C16540) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_C16540(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3, CSystemProcessInfoMapNode *a4)
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
  v6 = (CSystemProcessInfoMapNode *)this->_Header;
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
      sub_C16600(v5, (CSystemProcessInfoMapNode **)&v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_C16500(v6->baseclass._Parent);
    v5->_Header->_Parent = (std_Tree_node_for_tagKeyName *)v5->_Header;
    v5->_Header->_Left = (std_Tree_node_for_tagKeyName *)v5->_Header;
    v5->_Header->_Right = (std__Tree_node_For__bstr_t *)v5->_Header;
    v7 = (CSystemProcessInfoMapNode **)v5->_Header;
    v5->_Size = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00C16600) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_C16600(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3)
{
  std__tree *v3; // ebx
  CSystemProcessInfoMapNode *v4; // ecx
  CSystemProcessInfoMapNode *v5; // edi
  CSystemProcessInfoMapNode *v6; // edx
  std__Tree_node *v7; // esi
  std__Tree_node *v8; // eax
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

  v3 = (std__tree *)this;
  v19 = a3;
  sub_C04CE0((std__tree *)&a3);
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
        v7 = (std__Tree_node *)v6;
      }
      else
      {
        v7 = (std__Tree_node *)v6->baseclass._Parent;
        if ( !v5->baseclass._isnil )
          v5->baseclass._Parent = (CSystemProcessInfoMapNode *)v7;
        v7->_Left = (std_Tree_node_for_tagKeyName *)v5;
        v6->baseclass._Right = v19->baseclass._Right;
        v19->baseclass._Right->baseclass._Parent = v6;
      }
      if ( (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent == v19 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v6;
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
  v7 = (std__Tree_node *)v19->baseclass._Parent;
  if ( !v5->baseclass._isnil )
    v5->baseclass._Parent = (CSystemProcessInfoMapNode *)v7;
  if ( (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent == v19 )
  {
    v3->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v5;
  }
  else if ( (CSystemProcessInfoMapNode *)v7->_Left == v19 )
  {
    v7->_Left = (std_Tree_node_for_tagKeyName *)v5;
  }
  else
  {
    v7->_Right = (std__Tree_node_For__bstr_t *)v5;
  }
  v8 = v3->_Mypair._Myval2._Myhead;
  if ( v3->_Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v9 = (std_Tree_node_for_tagKeyName *)v7;
    }
    else
    {
      v10 = v5->baseclass._Left;
      v9 = (std_Tree_node_for_tagKeyName *)v5;
      if ( !v5->baseclass._Left->baseclass._isnil )
      {
        do
        {
          v9 = (std_Tree_node_for_tagKeyName *)v10;
          v10 = v10->baseclass._Left;
        }
        while ( !v10->baseclass._isnil );
      }
      v8 = v3->_Mypair._Myval2._Myhead;
    }
    v8->_Left = v9;
  }
  if ( (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Right == v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v3->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v7;
    }
    else
    {
      v11 = v5->baseclass._Right;
      for ( i = v5; !v11->baseclass._isnil; v11 = v11->baseclass._Right )
        i = v11;
      v3->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)i;
    }
  }
LABEL_37:
  if ( v4->baseclass._Color != 1 )
    goto LABEL_62;
  if ( v5 == (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->baseclass._Color == 1 )
  {
    v15 = (std__Tree_node *)v7->_Left;
    if ( v5 == (CSystemProcessInfoMapNode *)v7->_Left )
    {
      v15 = (std__Tree_node *)v7->_Right;
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_C654B0(v3, v7);
        v15 = (std__Tree_node *)v7->_Right;
      }
      if ( v15->_IsNil )
        goto LABEL_55;
      if ( v15->_Left->_Color != 1 || v15->_Right->_Color != 1 )
      {
        if ( v15->_Right->_Color == 1 )
        {
          v15->_Left->_Color = 1;
          v15->_Color = 0;
          sub_C72BB0(v3, v15);
          v15 = (std__Tree_node *)v7->_Right;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Right->_Color = 1;
        sub_C654B0(v3, v7);
        break;
      }
    }
    else
    {
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_C72BB0(v3, v7);
        v15 = (std__Tree_node *)v7->_Left;
      }
      if ( v15->_IsNil )
        goto LABEL_55;
      if ( v15->_Right->_Color != 1 || v15->_Left->_Color != 1 )
      {
        if ( v15->_Left->_Color == 1 )
        {
          v15->_Right->_Color = 1;
          v15->_Color = 0;
          sub_C654B0(v3, v15);
          v15 = (std__Tree_node *)v7->_Left;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Left->_Color = 1;
        sub_C72BB0(v3, v7);
        break;
      }
    }
    v15->_Color = 0;
LABEL_55:
    v5 = (CSystemProcessInfoMapNode *)v7;
    v7 = (std__Tree_node *)v7->_Parent;
    if ( v5 == (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent )
      break;
  }
  v4 = v19;
LABEL_61:
  v5->baseclass._Color = 1;
LABEL_62:
  sub_C11430((std__List *)&v4->_Keyvalue);
  operator delete(v19);
  v16 = v3->_Mypair._Myval2._Mysize;
  v17 = a3;
  if ( v16 )
    v3->_Mypair._Myval2._Mysize = v16 - 1;
  result = a2;
  *a2 = v17;
  return result;
}

//----- (00C16870) --------------------------------------------------------
unsigned int __cdecl sub_C16870(int a1, const unsigned __int16 *a2)
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
    *(const unsigned __int16 *)((char *)v2 + a1 - (_DWORD)a2 - 2) = v4;
  }
  while ( v4 );
  return result;
}

//----- (00C168C0) --------------------------------------------------------
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
    v6 = sub_C16A40();
    v10 = 0;
    v12 = v6;
    lParam = (LPARAM)&v12;
    v11 = sub_C17910;
    _swprintf(&String, L"%s License Agreement", a4);
    SetWindowTextW(hDlg, &String);
    v7 = GetDlgItem(hDlg, 500);
    SendMessageW(v7, 0x435u, 0, 0x100000);
    v8 = GetDlgItem(v13, 500);
    SendMessageW(v8, 0x449u, 2u, (LPARAM)&lParam);
    free(v6);
  }
  else
  {
    if ( a2 != 273 )
    {
      if ( a2 == 312 && (HWND)a4 == GetDlgItem(hDlg, 500) )
        return GetSysColorBrush(5);
      return 0;
    }
    switch ( (unsigned __int16)a3 )
    {
      case 1u:
        EndDialog(hDlg, 1);
        break;
      case 2u:
        EndDialog(hDlg, 0);
        break;
      case 0x1F5u:
        v5 = GetDlgItem(hDlg, 500);
        sub_C16D40(v5);
        break;
      default:
        return 0;
    }
  }
  return (HBRUSH)1;
}

//----- (00C16A40) --------------------------------------------------------
_BYTE *sub_C16A40()
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

  v0 = off_CCC4C8[0];
  v1 = 0;
  v2 = 1;
  if ( off_CCC4C8[0] )
  {
    v3 = off_CCC4C8[0];
    do
    {
      ++v1;
      v2 += strlen(v3);
      v3 = off_CCC4C8[v1];
    }
    while ( v3 );
  }
  v4 = malloc(v2);
  v5 = 0;
  v10 = 0;
  for ( i = v4; v0; v0 = off_CCC4C8[v10] )
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
// CCC4C8: using guessed type char *off_CCC4C8[48];

//----- (00C16AE0) --------------------------------------------------------
BOOL __cdecl License_IsEulaAccepted(HKEY hKey, LPCWSTR lpSubKey)
{
  LSTATUS v2; // esi
  BOOL result; // eax
  DWORD cbData; // [esp+0h] [ebp-Ch]
  BYTE Data[4]; // [esp+4h] [ebp-8h]
  HKEY hSubKey; // [esp+8h] [ebp-4h]

  hSubKey = 0;
  *(_DWORD *)Data = 0;
  result = 0;
  if ( !RegOpenKeyExW(hKey, lpSubKey, 0, 0x101u, &hSubKey) )
  {
    cbData = 4;
    v2 = RegQueryValueExW(hSubKey, L"EulaAccepted", 0, 0, Data, &cbData);
    RegCloseKey(hSubKey);
    if ( !v2 )
    {
      if ( *(_DWORD *)Data )
        result = 1;
    }
  }
  return result;
}

//----- (00C16B60) --------------------------------------------------------
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

//----- (00C16C00) --------------------------------------------------------
signed int sub_C16C00()
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
    if ( !RegQueryValueExW(phkResult, L"ProductName", 0, &Type, (LPBYTE)Data, &cbData) && !_wcsicmp(L"iotuap", Data) )
      v0 = 1;
    RegCloseKey(phkResult);
  }
  return v0;
}

//----- (00C16CC0) --------------------------------------------------------
signed int sub_C16CC0()
{
  signed int v0; // esi
  DWORD cbData; // [esp+4h] [ebp-10h]
  BYTE Data[4]; // [esp+8h] [ebp-Ch]
  DWORD Type; // [esp+Ch] [ebp-8h]
  HKEY phkResult; // [esp+10h] [ebp-4h]

  phkResult = 0;
  v0 = 0;
  *(_DWORD *)Data = 0;
  cbData = 4;
  Type = 0;
  if ( !RegOpenKeyW(
          HKEY_LOCAL_MACHINE,
          L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Server\\ServerLevels",
          &phkResult) )
  {
    if ( !RegQueryValueExW(phkResult, L"NanoServer", 0, &Type, Data, &cbData) && Type == 4 && *(_DWORD *)Data == 1 )
      v0 = 1;
    RegCloseKey(phkResult);
  }
  return v0;
}

//----- (00C16D40) --------------------------------------------------------
BOOL __cdecl sub_C16D40(HWND a1)
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
    v2 = LoadCursorW(0, (LPCWSTR)0x7F02);
    hCursor = SetCursor(v2);
    v12 = GetDeviceCaps(pPD.hDC, 8);
    v3 = GetDeviceCaps(pPD.hDC, 10);
    v4 = GetDeviceCaps(pPD.hDC, 88);
    v5 = GetDeviceCaps(pPD.hDC, 90);
    lParam = 0;
    memset(&v14, 0, 0x2Cu);
    _mm_storeu_si128((__m128i *)&v8.lpszDocName, (__m128i)0i64);
    SetMapMode(pPD.hDC, 1);
    lParam = (LPARAM)pPD.hDC;
    v14 = pPD.hDC;
    *(_QWORD *)&v16 = 0i64;
    HIDWORD(v16) = 1440 * (v3 / v5);
    DWORD2(v16) = 1440 * (v12 / v4);
    _mm_storeu_si128((__m128i *)&rc, _mm_loadu_si128((const __m128i *)&v16));
    InflateRect(&rc, -1440, -1440);
    v17 = 0;
    v18 = -1;
    v8.cbSize = 20;
    v8.lpszDocName = L"Sysinternals License";
    StartDocW(pPD.hDC, &v8);
    v6 = hWnd;
    v12 = SendMessageW(hWnd, 0xEu, 0, 0);
    StartPage(pPD.hDC);
    v7 = SendMessageW(v6, 0x439u, 1u, (LPARAM)&lParam);
    EndPage(pPD.hDC);
    while ( v7 < v12 )
    {
      v17 = v7;
      v18 = -1;
      StartPage(pPD.hDC);
      v7 = SendMessageW(v6, 0x439u, 1u, (LPARAM)&lParam);
      EndPage(pPD.hDC);
    }
    SendMessageW(v6, 0x439u, 0, 0);
    EndDoc(pPD.hDC);
    SetCursor(hCursor);
    result = 1;
  }
  return result;
}
// CAACE4: using guessed type wchar_t aSysinternalsLi[21];

//----- (00C16F60) --------------------------------------------------------
BOOL __cdecl LicenseCheck(WCHAR *lpszText, int a2, int a3)
{
  int v3; // esi
  signed int ret; // ebx
  signed int Data; // [esp+8h] [ebp-4h]

  Data = 0;
  if ( !a2 || !a3 )
    return sub_C17390((LPARAM)lpszText, 0, 0);
  v3 = 0;
  if ( *(_DWORD *)a2 > 0 )
  {
    Data = 0;
    while ( _wcsicmp(*(const wchar_t **)(a3 + 4 * v3), L"/accepteula")
         && _wcsicmp(*(const wchar_t **)(a3 + 4 * v3), L"-accepteula") )
    {
      if ( ++v3 >= *(_DWORD *)a2 )
        goto LABEL_12;
    }
    for ( Data = 1; v3 < *(_DWORD *)a2 - 1; ++v3 )
      *(_DWORD *)(a3 + 4 * v3) = *(_DWORD *)(a3 + 4 * v3 + 4);
    --*(_DWORD *)a2;
  }
LABEL_12:
  ret = Data;
  if ( LicensePropSheet(lpszText, Data) )
    ret = 1;
  return ret != 0;
}

//----- (00C17020) --------------------------------------------------------
signed int sub_C17020()
{
  signed int v0; // esi
  char v1; // bh
  char v2; // bl

  v0 = 0;
  v1 = 0;
  wprintf(off_CCC58C);
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

//----- (00C17080) --------------------------------------------------------
void __noreturn sub_C17080()
{
  wprintf_s(L"%ls", off_CCC58C);
  wprintf_s(L"This is the first run of this program. You must accept EULA to continue.\n");
  wprintf_s(L"Use -accepteula to accept EULA.\n\n");
  exit(1);
}

//----- (00C170B0) --------------------------------------------------------
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
  *(_DWORD *)&Data = License_CheckEulaAccepted(lpszText);
  if ( Data )
    goto __quit;
  if ( sub_C16C00() )
  {
    *(_DWORD *)&Data = sub_C17020();
  }
  else
  {
    if ( sub_C16CC0() || (hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE), GetFileType(hOutputHandle) == FILE_TYPE_PIPE) )
      sub_C17080();
    v3 = (char *)LocalAlloc(LMEM_ZEROINIT, 1000u);
    LoadLibraryW(L"Riched32.dll");
    *(_DWORD *)v3 = 0x80C808D0;
    *(_DWORD *)(v3 + 10) = 0;
    *(_DWORD *)(v3 + 14) = 0xB40138;
    *((_WORD *)v3 + 4) = 0;
    *(_DWORD *)(v3 + 18) = 0;
    v4 = &v3[2 * sub_C16870((int)(v3 + 22), L"License Agreement") + 22];
    *(_WORD *)v4 = 8;
    v5 = (unsigned int)&v4[2 * sub_C16870((int)(v4 + 2), L"MS Shell Dlg") + 5] & 0xFFFFFFFC;
    *(_DWORD *)(v5 + 8) = 0x30007;
    *(_DWORD *)(v5 + 12) = 0xE012A;
    *(_DWORD *)(v5 + 16) = 0xFFFF01F6;
    *(_DWORD *)v5 = 0x50000000;
    *(_WORD *)(v5 + 20) = 130;
    v5 += 22;
    v6 = sub_C16870(v5, L"You can also use the /accepteula command-line switch to accept the EULA.");
    *(_WORD *)(v5 + 2 * v6) = 0;
    ++*((_WORD *)v3 + 4);
    v7 = (v5 + 2 * v6 + 5) & 0xFFFFFFFC;
    *(_DWORD *)(v7 + 8) = 0x9F00C9;
    *(_DWORD *)(v7 + 12) = 0xE0032;
    *(_DWORD *)(v7 + 16) = 0xFFFF0001;
    *(_DWORD *)v7 = 0x50010000;
    *(_WORD *)(v7 + 20) = 128;
    v7 += 22;
    v8 = sub_C16870(v7, L"&Agree");
    *(_WORD *)(v7 + 2 * v8) = 0;
    ++*((_WORD *)v3 + 4);
    v9 = (v7 + 2 * v8 + 5) & 0xFFFFFFFC;
    *(_DWORD *)(v9 + 8) = 0x9F00FF;
    *(_DWORD *)(v9 + 12) = 0xE0032;
    *(_DWORD *)(v9 + 16) = 0xFFFF0002;
    *(_DWORD *)v9 = 0x50010000;
    *(_WORD *)(v9 + 20) = 128;
    v9 += 22;
    v10 = sub_C16870(v9, L"&Decline");
    *(_WORD *)(v9 + 2 * v10) = 0;
    ++*((_WORD *)v3 + 4);
    v11 = (v9 + 2 * v10 + 5) & 0xFFFFFFFC;
    *(_DWORD *)(v11 + 8) = 0x9F0007;
    *(_DWORD *)(v11 + 12) = 0xE0032;
    *(_DWORD *)(v11 + 16) = 0xFFFF01F5;
    *(_DWORD *)v11 = 0x50010000;
    *(_WORD *)(v11 + 20) = 128;
    v11 += 22;
    v12 = sub_C16870(v11, L"&Print");
    *(_WORD *)(v11 + 2 * v12) = 0;
    ++*((_WORD *)v3 + 4);
    v13 = (v11 + 2 * v12 + 5) & 0xFFFFFFFC;
    *(_DWORD *)(v13 + 8) = 0xE0007;
    *(_DWORD *)(v13 + 12) = 0x8C012A;
    *(_WORD *)(v13 + 16) = 500;
    *(_DWORD *)v13 = 0x50A11844;
    v14 = v13 + 18 + 2 * sub_C16870(v13 + 18, L"RICHEDIT");
    *(_WORD *)(v14 + 2 * sub_C16870(v14, L"&Decline")) = 0;
    ++*((_WORD *)v3 + 4);
    *(_DWORD *)&Data = DialogBoxIndirectParamW(0, (LPCDLGTEMPLATEW)v3, 0, (DLGPROC)DlgLicenseInfo, (LPARAM)lpszText);
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
// CAAD8C: using guessed type wchar_t aLicenseAgreeme[18];
// CAADB0: using guessed type wchar_t aMsShellDlg[13];
// CAADD0: using guessed type wchar_t aYouCanAlsoUseT[73];
// CAAE64: using guessed type wchar_t aAgree[7];
// CAAE74: using guessed type wchar_t aDecline[9];
// CAAE88: using guessed type wchar_t aPrint[7];
// CAAE98: using guessed type wchar_t aRichedit[9];

//----- (00C17390) --------------------------------------------------------
BOOL __cdecl sub_C17390(LPARAM a1, int *a2, int a3)
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
  *(_DWORD *)v59 = 0;
  if ( !a2 || !a3 )
  {
    v5 = LoadLibraryW(L"Shell32.dll");
    v6 = GetProcAddress(v5, "CommandLineToArgvW");
    if ( !v6 )
      goto LABEL_14;
    v4 = &dword_CD4DB4;
    v7 = GetCommandLineW();
    v3 = ((int (__stdcall *)(LPWSTR, int *))v6)(v7, &dword_CD4DB4);
  }
  v8 = 0;
  if ( *v4 > 0 )
  {
    *(_DWORD *)v59 = 0;
    while ( _wcsicmp(*(const wchar_t **)(v3 + 4 * v8), L"/accepteula")
         && _wcsicmp(*(const wchar_t **)(v3 + 4 * v8), L"-accepteula") )
    {
      if ( ++v8 >= *v4 )
        goto LABEL_14;
    }
    v9 = *v4 - 1;
    *(_DWORD *)v59 = 1;
    if ( v8 < v9 )
    {
      do
      {
        *(_DWORD *)(v3 + 4 * v8) = *(_DWORD *)(v3 + 4 * v8 + 4);
        ++v8;
      }
      while ( v8 < *v4 - 1 );
    }
    --*v4;
  }
LABEL_14:
  v10 = *(_DWORD *)v59;
  v56 = 0;
  _swprintf(&SubKey, L"Software\\Sysinternals\\%s", dwInitParam);
  if ( *(_DWORD *)v59 )
    goto LABEL_25;
  _swprintf(&Dest, L"%s\\%s", L"Software\\Sysinternals", dwInitParam);
  phkResult = 0;
  *(_DWORD *)Data = 0;
  v11 = RegQueryValueExW;
  if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Sysinternals", 0, 0x101u, &phkResult) )
  {
    cbData = 4;
    v12 = RegQueryValueExW(phkResult, L"EulaAccepted", 0, 0, Data, &cbData);
    RegCloseKey(phkResult);
    if ( !v12 && *(_DWORD *)Data )
      goto LABEL_22;
    v11 = RegQueryValueExW;
  }
  hKey = 0;
  *(_DWORD *)v55 = 0;
  if ( RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Sysinternals", 0, 0x101u, &hKey)
    || (v52 = 4, v13 = v11(hKey, L"EulaAccepted", 0, 0, v55, &v52), RegCloseKey(hKey), v13)
    || !*(_DWORD *)v55 )
  {
    if ( !License_IsEulaAccepted(HKEY_CURRENT_USER, &Dest) )
    {
      v14 = 0;
      goto LABEL_31;
    }
    *(_DWORD *)v59 = 1;
LABEL_25:
    if ( !RegCreateKeyW(HKEY_CURRENT_USER, &SubKey, &v56) )
    {
      RegSetValueExW(v56, L"EulaAccepted", 0, 4u, v59, 4u);
      RegCloseKey(v56);
    }
    if ( *(_DWORD *)v59 )
      v10 = 1;
    return v10 != 0;
  }
LABEL_22:
  v14 = 1;
LABEL_31:
  *(_DWORD *)v59 = v14;
  if ( v14 )
    goto LABEL_25;
  if ( sub_C16C00() )
  {
    v16 = sub_C17020();
    *(_DWORD *)v59 = v16;
  }
  else
  {
    if ( sub_C16CC0() || (v17 = GetStdHandle(0xFFFFFFF5), GetFileType(v17) == 3) )
      sub_C17080();
    v18 = (char *)LocalAlloc(0x40u, 0x3E8u);
    LoadLibraryW(L"Riched32.dll");
    *(_DWORD *)v18 = -2134374192;
    v19 = L"License Agreement";
    *(_DWORD *)(v18 + 10) = 0;
    *(_DWORD *)(v18 + 14) = 11796792;
    *((_WORD *)v18 + 4) = 0;
    *(_DWORD *)(v18 + 18) = 0;
    do
    {
      v20 = *v19;
      ++v19;
      *(const wchar_t *)((char *)v19 + v18 + 22 - (char *)L"License Agreement" - 2) = v20;
    }
    while ( v20 );
    v21 = L"MS Shell Dlg";
    *((_WORD *)v18 + 29) = 8;
    do
    {
      v22 = *v21;
      ++v21;
      *(const wchar_t *)((char *)v21 + v18 + 60 - (char *)L"MS Shell Dlg" - 2) = v22;
    }
    while ( v22 );
    v23 = (unsigned int)(v18 + 89) & 0xFFFFFFFC;
    v24 = v23 + 18;
    *(_WORD *)(v23 + 16) = 502;
    v25 = L"You can also use the /accepteula command-line switch to accept the EULA.";
    *(_DWORD *)(v23 + 8) = 196615;
    v26 = v23 + 22 - (_DWORD)L"You can also use the /accepteula command-line switch to accept the EULA.";
    *(_DWORD *)(v23 + 12) = 917802;
    *(_DWORD *)v23 = 1342177280;
    *(_DWORD *)(v23 + 18) = 8585215;
    do
    {
      v27 = *v25;
      ++v25;
      *(const wchar_t *)((char *)v25 + v26 - 2) = v27;
    }
    while ( v27 );
    *(_WORD *)(v24 + 150) = 0;
    ++*((_WORD *)v18 + 4);
    v28 = (v24 + 155) & 0xFFFFFFFC;
    v29 = v28 + 18;
    *(_WORD *)(v28 + 16) = 1;
    v30 = L"&Agree";
    *(_DWORD *)(v28 + 8) = 10420425;
    v31 = v28 + 22 - (_DWORD)L"&Agree";
    *(_DWORD *)(v28 + 12) = 917554;
    *(_DWORD *)v28 = 1342242816;
    *(_DWORD *)(v28 + 18) = 8454143;
    do
    {
      v32 = *v30;
      ++v30;
      *(const wchar_t *)((char *)v30 + v31 - 2) = v32;
    }
    while ( v32 );
    *(_WORD *)(v29 + 18) = 0;
    ++*((_WORD *)v18 + 4);
    v33 = (v29 + 23) & 0xFFFFFFFC;
    v34 = v33 + 18;
    *(_WORD *)(v33 + 16) = 2;
    v35 = L"&Decline";
    *(_DWORD *)(v33 + 8) = 10420479;
    v36 = v33 + 22 - (_DWORD)L"&Decline";
    *(_DWORD *)(v33 + 12) = 917554;
    *(_DWORD *)v33 = 1342242816;
    *(_DWORD *)(v33 + 18) = 8454143;
    do
    {
      v37 = *v35;
      ++v35;
      *(const wchar_t *)((char *)v35 + v36 - 2) = v37;
    }
    while ( v37 );
    *(_WORD *)(v34 + 22) = 0;
    ++*((_WORD *)v18 + 4);
    v38 = (v34 + 27) & 0xFFFFFFFC;
    v39 = v38 + 18;
    *(_WORD *)(v38 + 16) = 501;
    v40 = L"&Print";
    *(_DWORD *)(v38 + 8) = 10420231;
    v41 = v38 + 22 - (_DWORD)L"&Print";
    *(_DWORD *)(v38 + 12) = 917554;
    *(_DWORD *)v38 = 1342242816;
    *(_DWORD *)(v38 + 18) = 8454143;
    do
    {
      v42 = *v40;
      ++v40;
      *(const wchar_t *)((char *)v40 + v41 - 2) = v42;
    }
    while ( v42 );
    *(_WORD *)(v39 + 18) = 0;
    ++*((_WORD *)v18 + 4);
    v43 = (v39 + 23) & 0xFFFFFFFC;
    v44 = v43 + 18;
    *(_WORD *)(v43 + 16) = 500;
    v45 = L"RICHEDIT";
    *(_DWORD *)(v43 + 8) = 917511;
    *(_DWORD *)(v43 + 12) = 9175338;
    *(_DWORD *)v43 = 1352734788;
    v46 = v43 + 18 - (_DWORD)L"RICHEDIT";
    do
    {
      v47 = *v45;
      ++v45;
      *(const wchar_t *)((char *)v45 + v46 - 2) = v47;
    }
    while ( v47 );
    v48 = L"&Decline";
    do
    {
      v49 = *v48;
      ++v48;
      *(const wchar_t *)((char *)v48 + v44 + 18 - (_DWORD)L"&Decline" - 2) = v49;
    }
    while ( v49 );
    v50 = dwInitParam;
    *(_WORD *)(v44 + 36) = 0;
    ++*((_WORD *)v18 + 4);
    *(_DWORD *)v59 = DialogBoxIndirectParamW(0, (LPCDLGTEMPLATEW)v18, 0, (DLGPROC)DlgLicenseInfo, v50);
    LocalFree(v18);
    v16 = *(_DWORD *)v59;
  }
  if ( v16 )
    goto LABEL_25;
  return v10 != 0;
}
// CAAD8C: using guessed type wchar_t aLicenseAgreeme[18];
// CAADB0: using guessed type wchar_t aMsShellDlg[13];
// CAADD0: using guessed type wchar_t aYouCanAlsoUseT[73];
// CAAE64: using guessed type wchar_t aAgree[7];
// CAAE74: using guessed type wchar_t aDecline[9];
// CAAE88: using guessed type wchar_t aPrint[7];
// CAAE98: using guessed type wchar_t aRichedit[9];
// CD4DB4: using guessed type int dword_CD4DB4;

//----- (00C17910) --------------------------------------------------------
int __stdcall sub_C17910(int a1, void *a2, int a3, int a4)
{
  int v4; // eax
  int v5; // esi

  *(_DWORD *)a1;
  v4 = strlen(*(const char **)a1);
  v5 = a3;
  if ( a3 > v4 )
    v5 = v4;
  memmove_0(a2, *(const void **)a1, v5);
  *(_DWORD *)a4 = v5;
  *(_DWORD *)a1 += v5;
  return 0;
}

//----- (00C17950) --------------------------------------------------------
signed int CMainWnd::HandleTVSN7D2()
{
  return 1;
}

//----- (00C17960) --------------------------------------------------------
LRESULT __cdecl CAboutWnd::HandleCommand(HWND hWnd, int a2, WPARAM wParam, LPARAM lParam)
{
  return HandleCmdHandler((int)&CAboutDlg::gCmdHandler, hWnd, wParam, lParam);
}
// CCC5BC: using guessed type struct tagMSGHANDLER CAboutDlg::gCmdHandler;

//----- (00C17980) --------------------------------------------------------
int __cdecl Command_OkOrCancel(HWND hDlg)
{
  EndDialog(hDlg, 1);
  return 1;
}

//----- (00C179A0) --------------------------------------------------------
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
      ghDefaultGuiFont = (int)GetStockObject(DEFAULT_GUI_FONT);
      GetObjectW((HANDLE)ghDefaultGuiFont, 92, &LogFont);
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
        v7 = (const WCHAR *)PE_QueryFileVersionBlock(pVersionInfo, L"FileVersion");
        SetDlgItemTextW(hDlg, IDD_ABOUT_STATIC_VERSION, v7);
        v8 = (const WCHAR *)PE_QueryFileVersionBlock(pVersionInfo, L"LegalCopyright");
        SetDlgItemTextW(hDlg, IDD_ABOUT_STATIC_COPYRIGHT, v8);
        free(pVersionInfo);
      }
      else
      {
        ghWndAddressInAbout = GetDlgItem(hDlg, 0x51B);
      }
      ghHandArrow = LoadCursorW(ghInstance, L"HAND");
      ghCursorArrow = LoadCursorW(0, (LPCWSTR)IDC_ARROW);
      return (HBRUSH)1;
    case WM_CTLCOLORSTATIC:
      if ( (HWND)lParam != ghWndAddressInAbout )
        return (HBRUSH)HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
      SetBkMode((HDC)hdc, 1);
      if ( GetSysColorBrush(COLOR_HOTLIGHT) )
      {
        v10 = GetSysColor(COLOR_HOTLIGHT);
        SetTextColor((HDC)hdc, v10);
      }
      else
      {
        SetTextColor((HDC)hdc, 0xFF0000u);
      }
      v11 = (HGDIOBJ)ghDefaultGuiFont;
      if ( gbIndirectFontCreated )
        v11 = ghIndirectFontCreated;
      SelectObject((HDC)hdc, v11);
      return GetSysColorBrush(COLOR_BTNFACE);
    case WM_MOUSEFIRST:
      pt.y = (unsigned int)lParam >> 16;
      pt.x = (unsigned __int16)lParam;
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
      return (HBRUSH)HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
    case WM_LBUTTONUP:
      pt_1.y = (unsigned int)lParam >> 16;
      pt_1.x = (unsigned __int16)lParam;
      if ( ChildWindowFromPoint(hDlg, pt_1) == ghWndAddressInAbout )
      {
        if ( GetDlgItem(hDlg, IDD_ABOUT_STATIC_ADDRESS) )
          ShellExecuteW(hDlg, L"open", L"http://www.sysinternals.com", 0, 0, 1);
        else
          ShellExecuteW(hDlg, L"open", L"http://www.microsoft.com/whdc/devtools/debugging/default.mspx", 0, 0, 1);
      }
      break;
    default:
      return (HBRUSH)HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
  }
  return (HBRUSH)HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
}
// CAB118: using guessed type wchar_t aHttpWwwSysinte[28];
// CD4DBC: using guessed type int gbIndirectFontCreated;
// CD4DC0: using guessed type int ghDefaultGuiFont;

//----- (00C17DC0) --------------------------------------------------------
int __cdecl Command_About(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"AboutBox", hWndParent, (DLGPROC)DlgAbout, 0);
  return 0;
}

//----- (00C17DF0) --------------------------------------------------------
int *__cdecl sub_C17DF0(int *a1, const unsigned __int16 *a2)
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
  v5 = *(_DWORD *)(*a1 + 4);
  v6 = *(int *)((char *)a1 + v5 + 36);
  v7 = *(int *)((char *)a1 + v5 + 32);
  if ( v6 >= 0 && (v6 > 0 || v7 && v6 >= 0 && (v6 > 0 || v7 > v3)) )
  {
    v8 = (__PAIR__(v6, v7) - (unsigned __int64)v3) >> 32;
    v9 = v7 - v3;
  }
  else
  {
    v44 = 0i64;
    v8 = 0;
    v9 = 0;
  }
  v10 = *(int *)((char *)a1 + v5 + 56);
  LODWORD(v44) = a1;
  if ( v10 )
  {
    (*(void (**)(void))(*(_DWORD *)v10 + 4))();
    v4 = a1;
  }
  v11 = *v4;
  v49 = 0;
  v12 = *(_DWORD *)(v11 + 4);
  if ( !*(int *)((char *)v4 + v12 + 12) )
  {
    v13 = *(char **)((char *)v4 + v12 + 60);
    if ( v13 )
    {
      if ( v13 != (char *)v4 )
      {
        sub_C19D10(v13);
        v4 = a1;
      }
    }
  }
  v14 = *(_DWORD *)(*v4 + 4);
  BYTE4(v44) = *(int *)((char *)v4 + v14 + 12) == 0;
  v49 = 1;
  if ( BYTE4(v44) )
  {
    v15 = *(int *)((char *)v4 + v14 + 20) & 0x1C0;
    LOBYTE(v49) = 2;
    if ( v15 == 64 )
      goto LABEL_66;
    while ( v8 >= 0 && (v8 > 0 || v9) )
    {
      v16 = *(_DWORD *)(*v4 + 4);
      v46 = *(unsigned __int16 *)((char *)v4 + v16 + 64);
      v17 = *(_DWORD **)((char *)v4 + v16 + 56);
      if ( *(_DWORD *)v17[8] && (v18 = (_DWORD *)v17[12], *v18 > 0) )
      {
        --*v18;
        v19 = (_WORD **)v17[8];
        v20 = *v19;
        ++*v19;
        v21 = v46;
        *v20 = v46;
      }
      else
      {
        v21 = (*(int (__stdcall **)(int))(*v17 + 12))(v46);
      }
      v4 = a1;
      if ( v21 == -1 )
      {
        v2 = 4;
        v45 = 4;
        break;
      }
      v8 = (__PAIR__((unsigned int)v8, v9--) - 1) >> 32;
    }
    if ( !v2 )
    {
LABEL_66:
      v22 = (*(int (__stdcall **)(const unsigned __int16 *, unsigned int, _DWORD))(**(_DWORD **)((char *)v4
                                                                                               + *(_DWORD *)(*v4 + 4)
                                                                                               + 56)
                                                                                 + 36))(
              a2,
              v47,
              0);
      if ( v22 != v47 || v23 )
      {
        v2 = 4;
      }
      else
      {
        while ( v8 >= 0 && (v8 > 0 || v9) )
        {
          v24 = *(_DWORD *)(*a1 + 4);
          v25 = *(unsigned __int16 *)((char *)a1 + v24 + 64);
          v26 = *(int *)((char *)a1 + v24 + 56);
          v46 = *(unsigned __int16 *)((char *)a1 + v24 + 64);
          if ( **(_DWORD **)(v26 + 32) && (v27 = **(_DWORD **)(v26 + 48), v27 > 0) )
          {
            **(_DWORD **)(v26 + 48) = v27 - 1;
            v28 = *(_WORD ***)(v26 + 32);
            v29 = *v28;
            ++*v28;
            v30 = v46;
            *v29 = v46;
          }
          else
          {
            v30 = (*(int (__stdcall **)(int))(*(_DWORD *)v26 + 12))(v25);
          }
          if ( v30 == -1 )
          {
            v2 |= 4u;
            break;
          }
          v8 = (__PAIR__((unsigned int)v8, v9--) - 1) >> 32;
        }
      }
      v4 = a1;
    }
    v31 = *(_DWORD *)(*v4 + 4);
    *(int *)((char *)v4 + v31 + 32) = 0;
    *(int *)((char *)v4 + v31 + 36) = 0;
    v49 = 1;
  }
  else
  {
    v2 = 4;
  }
  v32 = (int *)((char *)v4 + *(_DWORD *)(*v4 + 4));
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
        sub_C18630((std::exception *)&v43, 1, (int)off_CCAA40, "ios_base::badbit set");
        v43 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v43, &_TI5_AVfailure_ios_base_std__);
      }
      if ( v35 & 2 )
      {
        sub_C18630((std::exception *)&v42, 1, (int)off_CCAA40, "ios_base::failbit set");
        v42 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v42, &_TI5_AVfailure_ios_base_std__);
      }
      sub_C18630((std::exception *)&v41, 1, (int)off_CCAA40, "ios_base::eofbit set");
      v41 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v41, &_TI5_AVfailure_ios_base_std__);
    }
  }
  v49 = -1;
  v36 = __uncaught_exception();
  v37 = v44;
  if ( !v36 )
    sub_C192D0((_DWORD *)v44);
  v38 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v37 + 4) + v37 + 56);
  if ( v38 )
    (*(void (**)(void))(*(_DWORD *)v38 + 8))();
  return a1;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CABEB8: using guessed type void *std::ios_base::failure::`vftable';
// CC4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// CCAA40: using guessed type int (__thiscall **off_CCAA40[2])(void *, char);

//----- (00C18150) --------------------------------------------------------
struct std::_Facet_base *__cdecl sub_C18150(int *a1)
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

  std::_Lockit::_Lockit((std::_Lockit *)&v8, 0);
  v1 = dword_CF5868;
  v2 = dword_CD4DD0;
  v11 = 0;
  v10 = (struct std::_Facet_base *)dword_CD4DD0;
  if ( !dword_CF5868 )
  {
    std::_Lockit::_Lockit((std::_Lockit *)&v9, dword_CF5868);
    if ( dword_CF5868 == v1 )
      dword_CF5868 = ++dword_CF5840;
    std::_Lockit::~_Lockit((std::_Lockit *)&v9);
    v1 = dword_CF5868;
  }
  v3 = *a1;
  if ( v1 >= *(_DWORD *)(*a1 + 12) )
  {
    v4 = 0;
  }
  else
  {
    v4 = *(struct std::_Facet_base **)(*(_DWORD *)(v3 + 8) + 4 * v1);
    if ( v4 )
      goto LABEL_19;
  }
  if ( !*(_BYTE *)(v3 + 20) )
    goto LABEL_12;
  v5 = sub_C74C4A();
  if ( v1 < *(_DWORD *)(v5 + 12) )
  {
    v4 = *(struct std::_Facet_base **)(*(_DWORD *)(v5 + 8) + 4 * v1);
LABEL_12:
    if ( v4 )
      goto LABEL_19;
  }
  if ( v2 )
  {
    v4 = (struct std::_Facet_base *)v2;
  }
  else
  {
    if ( sub_C19090((char **)&v10, a1) == -1 )
    {
      sub_C79D12((std::exception *)&v7, "bad cast");
      _CxxThrowException(&v7, &_TI2_AVbad_cast_std__);
    }
    v4 = v10;
    dword_CD4DD0 = (int)v10;
    (*(void (__thiscall **)(struct std::_Facet_base *))(*(_DWORD *)v10 + 4))(v10);
    std::_Facet_Register(v4);
  }
LABEL_19:
  std::_Lockit::~_Lockit((std::_Lockit *)&v8);
  return v4;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CC45C4: using guessed type int _TI2_AVbad_cast_std__;
// CD4DD0: using guessed type int dword_CD4DD0;
// CF5840: using guessed type int dword_CF5840;

//----- (00C18270) --------------------------------------------------------
_DWORD *__thiscall sub_C18270(_DWORD *this)
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
  *(_DWORD *)v1[8] = 0;
  *(_DWORD *)v1[12] = 0;
  *(_DWORD *)v1[3] = 0;
  *(_DWORD *)v1[7] = 0;
  *(_DWORD *)v1[11] = 0;
  return v1;
}
// CABF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00C18300) --------------------------------------------------------
char *__thiscall sub_C18300(char *this, int a2, int a3)
{
  char *v3; // esi
  _Cvtvec v4; // rax
  char v6; // [esp+30h] [ebp-10h]

  v3 = this;
  *((_DWORD *)this + 1) = a3;
  *(_DWORD *)this = &std::ctype<unsigned short>::`vftable';
  _mm_storeu_si128((__m128i *)(this + 8), _mm_loadu_si128((const __m128i *)_Getctype((_Ctypevec *)&v6)));
  v4 = _Getcvt();
  _mm_storeu_si128((__m128i *)(v3 + 24), _mm_loadu_si128((const __m128i *)v4._Hand));
  _mm_storeu_si128((__m128i *)(v3 + 40), _mm_loadu_si128((const __m128i *)(v4._Hand + 16)));
  _mm_storel_epi64((__m128i *)(v3 + 56), _mm_loadl_epi64((const __m128i *)(v4._Hand + 32)));
  *((_DWORD *)v3 + 16) = *(_DWORD *)(v4._Hand + 40);
  return v3;
}
// CABE5C: using guessed type void *std::ctype<unsigned short>::`vftable';

//----- (00C18360) --------------------------------------------------------
struct std::_Locinfo *__thiscall sub_C18360(struct std::_Locinfo *this, char *a2)
{
  struct std::_Locinfo *v2; // esi
  void **v4; // [esp+8h] [ebp-1Ch]
  struct std::_Locinfo *v5; // [esp+14h] [ebp-10h]
  int v6; // [esp+20h] [ebp-4h]

  v2 = this;
  v5 = this;
  std::_Lockit::_Lockit(this, 0);
  v6 = 0;
  *((_DWORD *)v2 + 1) = 0;
  *((_BYTE *)v2 + 8) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_BYTE *)v2 + 16) = 0;
  *((_DWORD *)v2 + 5) = 0;
  *((_WORD *)v2 + 12) = 0;
  *((_DWORD *)v2 + 7) = 0;
  *((_WORD *)v2 + 16) = 0;
  *((_DWORD *)v2 + 9) = 0;
  *((_BYTE *)v2 + 40) = 0;
  *((_DWORD *)v2 + 11) = 0;
  *((_BYTE *)v2 + 48) = 0;
  LOBYTE(v6) = 6;
  if ( !a2 )
  {
    a2 = "bad locale name";
    std::exception::exception((std::exception *)&v4, (const char *const *)&a2);
    v4 = &std::runtime_error::`vftable';
    _CxxThrowException(&v4, &_TI2_AVruntime_error_std__);
  }
  std::_Locinfo::_Locinfo_ctor(v2, a2);
  return v2;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CABE30: using guessed type void *std::runtime_error::`vftable';
// CC44F4: using guessed type int _TI2_AVruntime_error_std__;

//----- (00C18420) --------------------------------------------------------
std::exception *__thiscall sub_C18420(std::exception *this, int a2, int a3, int a4)
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
  sub_C06F00((string *)&v8, a4, 0, 0xFFFFFFFF);
  v5 = (char *)sub_C191F0(&v15, a2, a3, v8, v9, v10, v11, v12, v13);
  v6 = *((_DWORD *)v5 + 5) < 0x10u;
  v17 = 0;
  if ( !v6 )
    v5 = *(char **)v5;
  v14 = v5;
  std::exception::exception(v4, (const char *const *)&v14);
  v6 = v16 < 0x10;
  *(_DWORD *)v4 = &std::runtime_error::`vftable';
  if ( !v6 )
    operator delete(v15);
  result = v4;
  *((_DWORD *)v4 + 3) = a2;
  *(_DWORD *)v4 = &std::_System_error::`vftable';
  *((_DWORD *)v4 + 4) = a3;
  return result;
}
// CABE30: using guessed type void *std::runtime_error::`vftable';
// CABE9C: using guessed type void *std::_System_error::`vftable';

//----- (00C184F0) --------------------------------------------------------
std::exception *__thiscall sub_C184F0(std::exception *this, struct exception *a2)
{
  std::exception *v2; // edi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::_System_error::`vftable';
  *((_DWORD *)v2 + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)v2 + 4) = *((_DWORD *)a2 + 4);
  return v2;
}
// CABE9C: using guessed type void *std::_System_error::`vftable';

//----- (00C18520) --------------------------------------------------------
std::exception *__thiscall sub_C18520(std::exception *this, struct exception *a2)
{
  std::exception *v2; // edi
  std::exception *result; // eax

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::_System_error::`vftable';
  *((_DWORD *)v2 + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)v2 + 4) = *((_DWORD *)a2 + 4);
  result = v2;
  *(_DWORD *)v2 = &std::ios_base::failure::`vftable';
  return result;
}
// CABE9C: using guessed type void *std::_System_error::`vftable';
// CABEB8: using guessed type void *std::ios_base::failure::`vftable';

//----- (00C18550) --------------------------------------------------------
std::exception *__thiscall sub_C18550(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::runtime_error::`vftable';
  return v2;
}
// CABE30: using guessed type void *std::runtime_error::`vftable';

//----- (00C18570) --------------------------------------------------------
_DWORD *__thiscall sub_C18570(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  int v3; // ecx
  int v4; // eax
  char *v5; // ecx

  v2 = this;
  *this = a2;
  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) + a2 + 56);
  if ( v3 )
    (*(void (**)(void))(*(_DWORD *)v3 + 4))();
  v4 = *(_DWORD *)(*(_DWORD *)a2 + 4);
  if ( !*(_DWORD *)(v4 + a2 + 12) )
  {
    v5 = *(char **)(v4 + a2 + 60);
    if ( v5 )
    {
      if ( v5 != (char *)a2 )
        sub_C19D10(v5);
    }
  }
  *((_BYTE *)v2 + 4) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) + a2 + 12) == 0;
  return v2;
}

//----- (00C18600) --------------------------------------------------------
std::exception *__thiscall sub_C18600(std::exception *this, struct exception *a2)
{
  std::exception *v2; // edi
  std::exception *result; // eax

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::_System_error::`vftable';
  *((_DWORD *)v2 + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)v2 + 4) = *((_DWORD *)a2 + 4);
  result = v2;
  *(_DWORD *)v2 = &std::system_error::`vftable';
  return result;
}
// CABE9C: using guessed type void *std::_System_error::`vftable';
// CABEAC: using guessed type void *std::system_error::`vftable';

//----- (00C18630) --------------------------------------------------------
std::exception *__thiscall sub_C18630(std::exception *this, int a2, int a3, void *a4)
{
  std::exception *v4; // esi
  size_t v5; // ecx
  std::exception *result; // eax
  string v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+30h] [ebp-4h]

  v4 = this;
  v7._Myval2._Myres = 15;
  v7._Myval2._Mysize = 0;
  v7._Myval2._Bx._Alias[0] = 0;
  if ( *(_BYTE *)a4 )
    v5 = strlen((const char *)a4);
  else
    v5 = 0;
  sub_C07030(&v7, a4, v5);
  v8 = 0;
  sub_C18420(v4, a2, a3, (int)&v7);
  if ( v7._Myval2._Myres >= 0x10 )
    operator delete(v7._Myval2._Bx._Ptr);
  result = v4;
  *(_DWORD *)v4 = &std::system_error::`vftable';
  return result;
}
// CABEAC: using guessed type void *std::system_error::`vftable';

//----- (00C187D0) --------------------------------------------------------
int __thiscall sub_C187D0(_DWORD *this)
{
  _DWORD *v1; // edi
  void *v2; // esi
  void (__thiscall ***v3)(_DWORD, signed int); // eax
  int v4; // ecx
  int result; // eax

  v1 = this;
  *(_DWORD *)((char *)this + *(_DWORD *)(*(this - 26) + 4) - 104) = &std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(v1 - 26) + 4) - 108) = *(_DWORD *)(*(v1 - 26) + 4) - 104;
  *(this - 20) = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
  sub_C19420((int)(this - 20));
  v2 = (void *)*(v1 - 7);
  *(v1 - 20) = &std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
  if ( v2 )
  {
    if ( *(_DWORD *)v2 )
    {
      v3 = (void (__thiscall ***)(_DWORD, signed int))(*(int (**)(void))(**(_DWORD **)v2 + 8))();
      if ( v3 )
        (**v3)(v3, 1);
    }
    operator delete(v2);
  }
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(v1 - 26) + 4) - 104) = &std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(v1 - 26) + 4) - 108) = *(_DWORD *)(*(v1 - 26) + 4) - 32;
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(v1 - 22) + 4) - 88) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(v1 - 22) + 4) - 92) = *(_DWORD *)(*(v1 - 22) + 4) - 8;
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(v1 - 26) + 4) - 104) = &std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  v4 = *(_DWORD *)(*(v1 - 26) + 4);
  result = v4 - 24;
  *(_DWORD *)((char *)v1 + v4 - 108) = v4 - 24;
  return result;
}
// CABF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// CABFAC: using guessed type void *std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';

//----- (00C18880) --------------------------------------------------------
int __thiscall sub_C18880(std::_Lockit *this)
{
  void **v1; // esi

  v1 = (void **)this;
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
  return std::_Lockit::~_Lockit((std::_Lockit *)v1);
}

//----- (00C18990) --------------------------------------------------------
void __thiscall sub_C18990(_DWORD *this)
{
  _DWORD *v1; // edx

  v1 = this + 8;
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*this + 4) - 32) = &std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*this + 4) - 36) = *(_DWORD *)(*this + 4) - 32;
  *(_DWORD *)((char *)v1 + *(_DWORD *)(this[4] + 4) - 16) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(this[4] + 4) - 20) = *(_DWORD *)(this[4] + 4) - 8;
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*this + 4) - 32) = &std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*this + 4) - 36) = *(_DWORD *)(*this + 4) - 24;
  *v1 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor((struct std::ios_base *)(this + 8));
}
// CABEC4: using guessed type void *std::ios_base::`vftable';
// CABF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00C18A1C) --------------------------------------------------------
void __fastcall sub_C18A1C(unsigned int a1, int a2, int a3)
{
  bool v3; // cf

  v3 = a1 < *(_DWORD *)(a1 - 4);
  JUMPOUT(&loc_C18A40);
}

//----- (00C18A24) --------------------------------------------------------
void __fastcall sub_C18A24(unsigned int a1, int a2, int a3)
{
  bool v3; // cf

  v3 = a1 < *(_DWORD *)(a1 - 4);
  JUMPOUT(&loc_C18A70);
}

//----- (00C18A2C) --------------------------------------------------------
char *__thiscall sub_C18A2C(_DWORD *this, char a2)
{
  struct std::ios_base *v2; // ecx
  char *v3; // esi

  v2 = (struct std::ios_base *)((char *)this - *(this - 1));
  v3 = (char *)v2 - 8;
  *(_DWORD *)((char *)v2 + *(_DWORD *)(*((_DWORD *)v2 - 2) + 4) - 8) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(_DWORD *)((char *)v2 + *(_DWORD *)(*((_DWORD *)v2 - 2) + 4) - 12) = *(_DWORD *)(*((_DWORD *)v2 - 2) + 4) - 8;
  *(_DWORD *)v2 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(v2);
  if ( a2 & 1 )
    operator delete(v3);
  return v3;
}
// CABEC4: using guessed type void *std::ios_base::`vftable';
// CABF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00C18B10) --------------------------------------------------------
void *__thiscall sub_C18B10(void *this, char a2)
{
  void *v2; // esi
  void *v3; // edi
  void (__thiscall ***v4)(_DWORD, signed int); // eax

  v2 = this;
  v3 = (void *)*((_DWORD *)this + 13);
  *(_DWORD *)this = &std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
  if ( v3 )
  {
    if ( *(_DWORD *)v3 )
    {
      v4 = (void (__thiscall ***)(_DWORD, signed int))(*(int (**)(void))(**(_DWORD **)v3 + 8))();
      if ( v4 )
        (**v4)(v4, 1);
    }
    operator delete(v3);
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CABF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00C18B60) --------------------------------------------------------
_DWORD *__thiscall sub_C18B60(void *this, char a2)
{
  _DWORD *v2; // esi
  void *v3; // edi
  void (__thiscall ***v4)(_DWORD, signed int); // eax

  v2 = this;
  *(_DWORD *)this = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
  sub_C19420((int)this);
  v3 = (void *)v2[13];
  *v2 = &std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
  if ( v3 )
  {
    if ( *(_DWORD *)v3 )
    {
      v4 = (void (__thiscall ***)(_DWORD, signed int))(*(int (**)(void))(**(_DWORD **)v3 + 8))();
      if ( v4 )
        (**v4)(v4, 1);
    }
    operator delete(v3);
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CABF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';

//----- (00C18BC0) --------------------------------------------------------
_DWORD *__thiscall sub_C18BC0(struct std::ios_base *this, char a2)
{
  char *v2; // edi
  struct std::ios_base *v3; // esi

  v2 = (char *)this - 104;
  v3 = this;
  sub_C187D0(this);
  *(_DWORD *)v3 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CABEC4: using guessed type void *std::ios_base::`vftable';

//----- (00C18C00) --------------------------------------------------------
void **__thiscall sub_C18C00(void *this, char a2)
{
  void **v2; // esi
  bool v3; // zf

  v2 = (void **)this;
  v3 = *((_DWORD *)this + 4) == 0;
  *(_DWORD *)this = &std::ctype<unsigned short>::`vftable';
  if ( !v3 )
    free(*((void **)this + 3));
  free(v2[5]);
  *v2 = &std::_Facet_base::`vftable';
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CABE4C: using guessed type void *std::_Facet_base::`vftable';
// CABE5C: using guessed type void *std::ctype<unsigned short>::`vftable';

//----- (00C18C50) --------------------------------------------------------
void *__thiscall sub_C18C50(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *(_DWORD *)this = &std::_Facet_base::`vftable';
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// CABE4C: using guessed type void *std::_Facet_base::`vftable';

//----- (00C18C80) --------------------------------------------------------
struct std::ios_base *__thiscall sub_C18C80(struct std::ios_base *this, char a2)
{
  struct std::ios_base *v2; // esi

  v2 = this;
  *(_DWORD *)this = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this);
  if ( a2 & 1 )
    operator delete((void *)v2);
  return v2;
}
// CABEC4: using guessed type void *std::ios_base::`vftable';

//----- (00C18CB0) --------------------------------------------------------
void *__thiscall sub_C18CB0(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  std::_system_error::~_system_error((std::exception *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00C18CE0) --------------------------------------------------------
void __cdecl sub_C18CE0(int a1, int a2, wchar_t *a3)
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
    v17 = &unk_CABFB0;
    v19 = dword_CABFB8;
    v30 = 0;
    v25 = 1;
    v24 = &std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    v23 = 80;
    v18 = 0i64;
    sub_C19E70((struct std::ios_base *)&v24, (int)&v20, 0);
    *(_DWORD **)((char *)&v19 + dword_CABFB8[1]) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    *(_DWORD *)((char *)&v18 + v19[1] + 4) = v19[1] - 8;
    *(_DWORD **)((char *)&v17 + v17[1]) = &std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    *(int *)((char *)&v16 + v17[1]) = v17[1] - 32;
    v30 = 5;
    *(_DWORD **)((char *)&v17 + v17[1]) = &std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
    *(int *)((char *)&v16 + v17[1]) = v17[1] - 104;
    sub_C18270(&v20);
    v20 = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
    v21 = 0;
    v22 = 0;
    v30 = 7;
    sub_C19000((int)&v17, a1, (int)&dword_CCC5C8, 8);
    v26 = 1;
    v6 = 0;
    do
    {
      v7 = wcscmp((const unsigned __int16 *)a2, (&off_CCCB90)[v6]);
      if ( v7 )
        v7 = -(v7 < 0) | 1;
      if ( v7 )
      {
        v8 = v26;
      }
      else
      {
        sub_C19000((int)&v17, a1, *(int *)((char *)&off_CCCB88 + v6 * 4), dword_CCCB8C[v6]);
        v8 = 0;
        v26 = 0;
      }
      v6 += 3;
    }
    while ( v6 < 39 );
    if ( v8 )
    {
      if ( (_WORD)a1 )
        sub_C17DF0((int *)&v19, L"<Unknown>");
      else
        sub_C17DF0((int *)&v19, L"<None>");
      v9 = (wchar_t *)sub_C1A6E0(&v17, &v27);
      v10 = v9;
      if ( *((_DWORD *)v9 + 5) >= 8u )
        v10 = *(wchar_t **)v9;
      do
      {
        v11 = *v10;
        ++v10;
        *v3 = v11;
        ++v3;
      }
      while ( v11 );
      if ( v29 >= 8 )
        operator delete(v27);
      v29 = 7;
      v28 = 0;
      LOWORD(v27) = 0;
    }
    else
    {
      sub_C1A6E0(&v17, &v27);
      if ( v28 )
      {
        v12 = &v27;
        if ( v29 >= 8 )
          v12 = v27;
        v12[v28 - 3] = 0;
        v13 = (const wchar_t *)&v27;
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
          *(const wchar_t *)((char *)v14 + (char *)a3 - (char *)L"<Unknown>" - 2) = v15;
        }
        while ( v15 );
      }
      if ( v29 >= 8 )
        operator delete(v27);
    }
    v30 = -1;
    sub_C187D0(&v24);
    v24 = &std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor((struct std::ios_base *)&v24);
  }
  else
  {
    v4 = L"<None>";
    do
    {
      v5 = *v4;
      ++v4;
      *(const wchar_t *)((char *)v4 + (char *)a3 - (char *)L"<None>" - 2) = v5;
    }
    while ( v5 );
  }
}
// CABEC4: using guessed type void *std::ios_base::`vftable';
// CABF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// CABF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// CABFAC: using guessed type void *std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// CABFD8: using guessed type wchar_t aUnknown_0[10];
// CCC5C8: using guessed type int dword_CCC5C8;
// CCCB88: using guessed type void *off_CCCB88;
// CCCB8C: using guessed type int dword_CCCB8C[];
// CCCB90: using guessed type wchar_t *off_CCCB90;

//----- (00C19000) --------------------------------------------------------
int __cdecl sub_C19000(int a1, int a2, int a3, int a4)
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
      if ( (a2 & *(_DWORD *)v5) == *(_DWORD *)v5 )
      {
        if ( a1 )
          v6 = (int *)(a1 + 16);
        else
          v6 = 0;
        v7 = sub_C17DF0(v6, *(const unsigned __int16 **)(v5 + 4));
        sub_C17DF0(v7, L" | ");
        v8 = *(_DWORD *)(v5 + 8);
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
// CABFC0: using guessed type wchar_t asc_CABFC0[4];

//----- (00C19070) --------------------------------------------------------
volatile signed __int32 *__thiscall sub_C19070(volatile signed __int32 *this)
{
  volatile signed __int32 *result; // eax

  result = 0;
  if ( !_InterlockedExchangeAdd(this + 1, 0xFFFFFFFF) )
    result = this;
  return result;
}

//----- (00C19090) --------------------------------------------------------
signed int __cdecl sub_C19090(char **a1, int *a2)
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
    v3 = (char *)operator new(0x44u);
    v11 = 0;
    if ( v3 )
    {
      v4 = *a2;
      if ( *a2 )
      {
        v5 = *(char **)(v4 + 24);
        if ( !v5 )
          v5 = (char *)(v4 + 28);
      }
      else
      {
        v5 = gszStatusBarText;
      }
      v6 = sub_C18360((struct std::_Locinfo *)&v9, v5);
      v2 = 1;
      v7 = sub_C18300(v3, (int)v6, 0);
    }
    else
    {
      v7 = 0;
    }
    *a1 = v7;
    if ( v2 & 1 )
      sub_C18880((std::_Lockit *)&v9);
  }
  return 2;
}

//----- (00C19140) --------------------------------------------------------
__int64 __thiscall sub_C19140(_DWORD **this)
{
  __int64 result; // rax

  if ( *this[7] )
    result = (signed int)*this[11];
  else
    result = 0i64;
  return result;
}

//----- (00C19160) --------------------------------------------------------
signed __int32 __thiscall sub_C19160(volatile signed __int32 *this)
{
  return _InterlockedExchangeAdd(this + 1, 1u);
}

//----- (00C19170) --------------------------------------------------------
struct std::locale::_Locimp *__thiscall sub_C19170(_DWORD *this)
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
  sub_C19860(this, 0);
  result = (struct std::locale::_Locimp *)operator new(4u);
  v3 = result;
  if ( result )
  {
    result = std::locale::_Init(1);
    *(_DWORD *)v3 = result;
    v1[12] = v3;
  }
  else
  {
    v1[12] = 0;
  }
  return result;
}

//----- (00C191F0) --------------------------------------------------------
void *__cdecl sub_C191F0(void *a1, char a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // eax
  int v10; // edx
  void *result; // eax
  void *v12; // [esp+Ch] [ebp-28h]
  unsigned int v13; // [esp+20h] [ebp-14h]
  int v14; // [esp+30h] [ebp-4h]

  v14 = 0;
  if ( a8 )
    sub_C19550(&a4, &unk_CABEA4, 2u);
  v9 = sub_C19F90((_DWORD **)&a2, (int)&v12);
  LOBYTE(v14) = 1;
  sub_C19490(&a4, v9, 0, -1);
  if ( v13 >= 0x10 )
    operator delete(v12);
  *((_DWORD *)a1 + 5) = 15;
  *((_DWORD *)a1 + 4) = 0;
  *(_BYTE *)a1 = 0;
  v10 = a9;
  if ( (unsigned int)a9 >= 0x10 )
  {
    *(_DWORD *)a1 = a4;
  }
  else if ( a8 != -1 )
  {
    memmove(a1, &a4, a8 + 1);
    v10 = a9;
  }
  result = a1;
  *((_DWORD *)a1 + 4) = a8;
  *((_DWORD *)a1 + 5) = v10;
  return result;
}

//----- (00C192D0) --------------------------------------------------------
int __thiscall sub_C192D0(_DWORD *this)
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
  result = *(_DWORD *)(v2 + 4);
  if ( !*(_DWORD *)((char *)this + result + 12) )
  {
    if ( *((_BYTE *)this + result + 20) & 2 )
    {
      result = (*(int (**)(void))(**(_DWORD **)((char *)this + result + 56) + 52))();
      if ( result == -1 )
      {
        v4 = *(_DWORD *)(*v1 + 4);
        v5 = *(_DWORD *)((char *)v1 + v4 + 12);
        v6 = (_DWORD *)((char *)v1 + v4);
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
            sub_C18630((std::exception *)&v12, 1, (int)off_CCAA40, "ios_base::badbit set");
            v12 = &std::ios_base::failure::`vftable';
            _CxxThrowException(&v12, &_TI5_AVfailure_ios_base_std__);
          }
          if ( v8 & 2 )
          {
            sub_C18630((std::exception *)&v11, 1, (int)off_CCAA40, "ios_base::failbit set");
            v11 = &std::ios_base::failure::`vftable';
            _CxxThrowException(&v11, &_TI5_AVfailure_ios_base_std__);
          }
          sub_C18630((std::exception *)&v10, 1, (int)off_CCAA40, "ios_base::eofbit set");
          v10 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
        }
      }
    }
  }
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CABEB8: using guessed type void *std::ios_base::failure::`vftable';
// CC4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// CCAA40: using guessed type int (__thiscall **off_CCAA40[2])(void *, char);

//----- (00C19400) --------------------------------------------------------
__int64 __thiscall sub_C19400(_DWORD **this)
{
  __int64 result; // rax

  if ( *this[8] )
    result = (signed int)*this[12];
  else
    result = 0i64;
  return result;
}

//----- (00C19420) --------------------------------------------------------
_DWORD *__thiscall sub_C19420(int this)
{
  int v1; // esi
  _DWORD *result; // eax

  v1 = this;
  if ( *(_BYTE *)(this + 60) & 1 )
    operator delete(**(void ***)(this + 12));
  **(_DWORD **)(v1 + 12) = 0;
  **(_DWORD **)(v1 + 28) = 0;
  **(_DWORD **)(v1 + 44) = 0;
  **(_DWORD **)(v1 + 16) = 0;
  **(_DWORD **)(v1 + 32) = 0;
  result = *(_DWORD **)(v1 + 48);
  *result = 0;
  *(_DWORD *)(v1 + 60) &= 0xFFFFFFFE;
  *(_DWORD *)(v1 + 56) = 0;
  return result;
}

//----- (00C19490) --------------------------------------------------------
_DWORD *__thiscall sub_C19490(void *this, int a2, int a3, int a4)
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

  v4 = (_DWORD *)a2;
  v5 = this;
  v6 = *(_DWORD *)(a2 + 16);
  if ( v6 < a3 )
    std::_Xout_of_range("invalid string position");
  v7 = a4;
  v8 = v6 - a3;
  v9 = *((_DWORD *)this + 4);
  v14 = v5[4];
  if ( v8 < a4 )
    v7 = v8;
  if ( -1 - v9 <= v7 )
    std::_Xlength_error("string too long");
  if ( v7 && (unsigned __int8)sub_C06E00(v5, v9 + v7, 0) )
  {
    if ( v4[5] >= 0x10u )
      v4 = (_DWORD *)*v4;
    if ( v5[5] < 0x10u )
      v10 = v5;
    else
      v10 = (_DWORD *)*v5;
    if ( v7 )
      memmove_0((char *)v10 + v5[4], (char *)v4 + a3, v7);
    v11 = v7 + v14;
    v12 = v5[5] < 0x10u;
    v5[4] = v7 + v14;
    if ( !v12 )
    {
      *(_BYTE *)(*v5 + v11) = 0;
      return v5;
    }
    *((_BYTE *)v5 + v11) = 0;
  }
  return v5;
}

//----- (00C19550) --------------------------------------------------------
_DWORD *__thiscall sub_C19550(void *this, void *a2, size_t a3)
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
    && ((v5 = *((_DWORD *)this + 5), v5 < 0x10) ? (v6 = (unsigned int)v4) : (v6 = *v4),
        (unsigned int)a2 >= v6 && (v5 < 0x10 ? (v7 = v4) : (v7 = (_DWORD *)*v4), (char *)v7 + v4[4] > a2)) )
  {
    if ( v5 < 0x10 )
      result = sub_C19490(v4, (int)v4, (_BYTE *)a2 - (_BYTE *)v4, a3);
    else
      result = sub_C19490(v4, (int)v4, (int)a2 - *v4, a3);
  }
  else
  {
    v9 = (char *)v4[4];
    v13 = v9;
    if ( -1 - (signed int)v9 <= a3 )
      std::_Xlength_error("string too long");
    if ( a3 && (unsigned __int8)sub_C06E00(v4, (size_t)&v9[a3], 0) )
    {
      if ( v4[5] < 0x10u )
        v10 = v4;
      else
        v10 = (_DWORD *)*v4;
      if ( a3 )
        memmove_0((char *)v10 + v4[4], v3, a3);
      v11 = (size_t)&v13[a3];
      v12 = v4[5] < 0x10u;
      v4[4] = &v13[a3];
      if ( !v12 )
      {
        *(_BYTE *)(*v4 + v11) = 0;
        return v4;
      }
      *((_BYTE *)v4 + v11) = 0;
    }
    result = v4;
  }
  return result;
}

//----- (00C19640) --------------------------------------------------------
int *__thiscall sub_C19640(int *this, int *a2, unsigned int a3, unsigned int a4)
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
          *(_WORD *)v5 = 0;
        }
        else
        {
          *(_WORD *)*v5 = 0;
          result = v5;
        }
        return result;
      }
    }
    else
    {
      sub_BEF9D0((string *)v5, v8, v5[4]);
      v6 = a3;
      if ( !v8 )
        return v5;
    }
    if ( (unsigned int)a2[5] >= 8 )
      v4 = (int *)*a2;
    if ( (unsigned int)v5[5] < 8 )
      v14 = v5;
    else
      v14 = (int *)*v5;
    if ( v8 )
      memmove_0(v14, (char *)v4 + 2 * v6, 2 * v8);
    v10 = (unsigned int)v5[5] < 8;
    v5[4] = v8;
    if ( !v10 )
    {
      *(_WORD *)(*v5 + 2 * v8) = 0;
      return v5;
    }
    *((_WORD *)v5 + v8) = 0;
    return v5;
  }
  v9 = v8 + a3;
  if ( v5[4] < v8 + a3 )
    std::_Xout_of_range("invalid string position");
  v10 = (unsigned int)v5[5] < 8;
  v5[4] = v9;
  if ( v10 )
    v11 = (int)v5;
  else
    v11 = *v5;
  *(_WORD *)(v11 + 2 * v9) = 0;
  sub_C19C60(v5, 0, a3);
  return v5;
}

//----- (00C19760) --------------------------------------------------------
int *__thiscall sub_C19760(int *this, void *a2, int a3)
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
    || ((v4 = this[5], v4 < 8) ? (v5 = (unsigned int)v3) : (v5 = *v3),
        (unsigned int)a2 < v5 || (v4 < 8 ? (v6 = (int)v3) : (v6 = *v3), v6 + 2 * v3[4] <= (unsigned int)a2)) )
  {
    if ( (unsigned int)a3 > 0x7FFFFFFE )
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
          *(_WORD *)v3 = 0;
        }
        else
        {
          *(_WORD *)*v3 = 0;
          result = v3;
        }
        return result;
      }
    }
    else
    {
      sub_BEF9D0((string *)v3, a3, v3[4]);
      if ( !a3 )
        return v3;
    }
    if ( (unsigned int)v3[5] < 8 )
      v10 = v3;
    else
      v10 = (int *)*v3;
    if ( a3 )
      memmove_0(v10, a2, 2 * a3);
    v11 = (unsigned int)v3[5] < 8;
    v3[4] = a3;
    if ( !v11 )
    {
      *(_WORD *)(*v3 + 2 * a3) = 0;
      return v3;
    }
    *((_WORD *)v3 + a3) = 0;
    return v3;
  }
  if ( v4 < 8 )
    v7 = (int)v3;
  else
    v7 = *v3;
  return sub_C19640(v3, v3, (_DWORD)((_DWORD)a2 - v7) >> 1, a3);
}

//----- (00C19860) --------------------------------------------------------
int __thiscall sub_C19860(_DWORD *this, char a2)
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
        sub_C18630((std::exception *)&v4, 1, (int)off_CCAA40, "ios_base::failbit set");
      else
        sub_C18630((std::exception *)&v4, 1, (int)off_CCAA40, "ios_base::eofbit set");
      v4 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v4, &_TI5_AVfailure_ios_base_std__);
    }
    sub_C18630((std::exception *)&v4, 1, (int)off_CCAA40, "ios_base::badbit set");
    v4 = &std::ios_base::failure::`vftable';
    _CxxThrowException(&v4, &_TI5_AVfailure_ios_base_std__);
  }
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CABEB8: using guessed type void *std::ios_base::failure::`vftable';
// CC4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// CCAA40: using guessed type int (__thiscall **off_CCAA40[2])(void *, char);

//----- (00C19900) --------------------------------------------------------
BOOL __stdcall sub_C19900(__int16 a1, WCHAR SrcStr)
{
  return ((unsigned __int16)_Getwctype(SrcStr) & (unsigned __int16)a1) != 0;
}

//----- (00C19930) --------------------------------------------------------
char __thiscall sub_C19930(const _Cvtvec *this, wchar_t a2, int a3)
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

//----- (00C19980) --------------------------------------------------------
wchar_t *__thiscall sub_C19980(const _Cvtvec *this, wchar_t *a2, unsigned int a3, char a4, int a5)
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
  v7 = (a3 - (unsigned int)a2 + 1) >> 1;
  if ( (unsigned int)a2 > a3 )
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
      *(_BYTE *)(v5 - 1) = v11;
      ++v6;
      v16 = v12;
    }
    while ( v12 != v7 );
  }
  return v6;
}

//----- (00C19A20) --------------------------------------------------------
unsigned __int16 *__thiscall sub_C19A20(void *this, int a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // esi
  void *i; // ebx

  v4 = a3;
  for ( i = this; v4 != a4; ++v4 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)i + 16))(i, a2, *v4) )
      break;
  }
  return v4;
}

//----- (00C19A60) --------------------------------------------------------
unsigned __int16 *__thiscall sub_C19A60(void *this, int a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // esi
  void *i; // ebx

  v4 = a3;
  for ( i = this; v4 != a4; ++v4 )
  {
    if ( !(*(unsigned __int8 (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)i + 16))(i, a2, *v4) )
      break;
  }
  return v4;
}

//----- (00C19AA0) --------------------------------------------------------
int __thiscall sub_C19AA0(void *this, wchar_t Src)
{
  return _Towlower(Src, (int)this + 8);
}

//----- (00C19AC0) --------------------------------------------------------
wchar_t *__thiscall sub_C19AC0(char *this, wchar_t *a2, unsigned int a3)
{
  wchar_t *v3; // esi
  unsigned int v4; // ebx
  int v5; // edi
  char *v6; // eax
  char *v8; // [esp+18h] [ebp+Ch]

  v3 = a2;
  v4 = (a3 - (unsigned int)a2 + 1) >> 1;
  v5 = 0;
  if ( (unsigned int)a2 > a3 )
    v4 = 0;
  if ( v4 )
  {
    v6 = this + 8;
    v8 = this + 8;
    do
    {
      *v3 = _Towlower(*v3, (int)v6);
      ++v5;
      v6 = v8;
      ++v3;
    }
    while ( v5 != v4 );
  }
  return v3;
}

//----- (00C19B10) --------------------------------------------------------
int __thiscall sub_C19B10(void *this, wchar_t Src)
{
  return _Towupper(Src, (int)this + 8);
}

//----- (00C19B30) --------------------------------------------------------
wchar_t *__thiscall sub_C19B30(char *this, wchar_t *a2, unsigned int a3)
{
  wchar_t *v3; // esi
  unsigned int v4; // ebx
  int v5; // edi
  char *v6; // eax
  char *v8; // [esp+18h] [ebp+Ch]

  v3 = a2;
  v4 = (a3 - (unsigned int)a2 + 1) >> 1;
  v5 = 0;
  if ( (unsigned int)a2 > a3 )
    v4 = 0;
  if ( v4 )
  {
    v6 = this + 8;
    v8 = this + 8;
    do
    {
      *v3 = _Towupper(*v3, (int)v6);
      ++v5;
      v6 = v8;
      ++v3;
    }
    while ( v5 != v4 );
  }
  return v3;
}

//----- (00C19B80) --------------------------------------------------------
wchar_t __thiscall sub_C19B80(const _Cvtvec *this, char a2)
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

//----- (00C19BD0) --------------------------------------------------------
char *__thiscall sub_C19BD0(const _Cvtvec *this, wchar_t a2, char a3, mbstate_t a4)
{
  char *v4; // esi
  int v5; // edi
  const _Cvtvec *v6; // ecx
  mbstate_t v7; // ebx
  int v8; // eax
  wchar_t v9; // cx
  const _Cvtvec *v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]

  v4 = (char *)a2;
  v5 = a3 - a2;
  v12 = 0;
  if ( a2 > (unsigned int)a3 )
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
      *(_WORD *)(v7 - 2) = v9;
      v6 = v11;
      ++v4;
      ++v12;
    }
    while ( v12 != v5 );
  }
  return v4;
}

//----- (00C19C60) --------------------------------------------------------
_DWORD *__thiscall sub_C19C60(_DWORD *this, unsigned int a2, unsigned int a3)
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
        v7 = (_DWORD *)*this;
      v8 = v4 - a3;
      if ( v8 != a2 )
        memmove((char *)v7 + 2 * a2, (char *)v7 + 2 * a2 + 2 * a3, 2 * (v8 - a2));
      v5 = v3[5] < 8u;
      v3[4] = v8;
      if ( !v5 )
      {
        *(_WORD *)(*v3 + 2 * v8) = 0;
        return v3;
      }
      *((_WORD *)v3 + v8) = 0;
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
      *((_WORD *)this + a2) = 0;
    }
    else
    {
      *(_WORD *)(*this + 2 * a2) = 0;
      result = this;
    }
  }
  return result;
}

//----- (00C19D10) --------------------------------------------------------
char *__thiscall sub_C19D10(char *this)
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
  if ( *(_DWORD *)&this[*(_DWORD *)(*(_DWORD *)this + 4) + 56] )
  {
    sub_C18570(&v11, (int)this);
    v13 = 0;
    if ( v12 && (*(int (**)(void))(**(_DWORD **)&v1[*(_DWORD *)(*(_DWORD *)v1 + 4) + 56] + 52))() == -1 )
    {
      v2 = *(_DWORD *)(*(_DWORD *)v1 + 4);
      v3 = *(_DWORD *)&v1[v2 + 12];
      v4 = &v1[v2];
      v5 = v3 | 4;
      if ( !*((_DWORD *)v4 + 14) )
        v5 |= 4u;
      v6 = v5 & 0x17;
      *((_DWORD *)v4 + 3) = v6;
      v7 = v6 & *((_DWORD *)v4 + 4);
      if ( v7 )
      {
        if ( v7 & 4 )
        {
          sub_C18630((std::exception *)&v10, 1, (int)off_CCAA40, "ios_base::badbit set");
          v10 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
        }
        if ( v7 & 2 )
          sub_C18630((std::exception *)&v10, 1, (int)off_CCAA40, "ios_base::failbit set");
        else
          sub_C18630((std::exception *)&v10, 1, (int)off_CCAA40, "ios_base::eofbit set");
        v10 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
      }
    }
    v13 = -1;
    if ( !__uncaught_exception() )
      sub_C192D0(v11);
    v8 = *(_DWORD *)((char *)v11 + *(_DWORD *)(*v11 + 4) + 56);
    if ( v8 )
      (*(void (**)(void))(*(_DWORD *)v8 + 8))();
  }
  return v1;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CABEB8: using guessed type void *std::ios_base::failure::`vftable';
// CC4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// CCAA40: using guessed type int (__thiscall **off_CCAA40[2])(void *, char);

//----- (00C19E40) --------------------------------------------------------
int *__thiscall sub_C19E40(_DWORD *this, int *a2)
{
  int *v2; // eax
  int v3; // ecx

  v2 = (int *)this[12];
  v3 = *v2;
  *a2 = *v2;
  (*(void (**)(void))(*(_DWORD *)v3 + 4))();
  return a2;
}

//----- (00C19E70) --------------------------------------------------------
void __thiscall sub_C19E70(struct std::ios_base *this, int a2, char a3)
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
  sub_C19170(this);
  *((_DWORD *)v3 + 14) = a2;
  *((_DWORD *)v3 + 15) = 0;
  v4 = sub_C19E40(v3, &a2);
  v14 = -1;
  v5 = sub_C18150(v4);
  if ( a2 )
  {
    v6 = (void (__thiscall ***)(_DWORD, signed int))(*(int (**)(void))(*(_DWORD *)a2 + 8))();
    if ( v6 )
      (**v6)(v6, 1);
  }
  v7 = (*(int (__thiscall **)(struct std::_Facet_base *, signed int))(*(_DWORD *)v5 + 48))(v5, 32);
  v8 = *((_DWORD *)v3 + 14) == 0;
  *((_WORD *)v3 + 32) = v7;
  if ( v8 )
  {
    v9 = *((_DWORD *)v3 + 4);
    v10 = ((unsigned __int8)*((_DWORD *)v3 + 3) | 4) & 0x17;
    *((_DWORD *)v3 + 3) = v10;
    v11 = v10 & v9;
    if ( v11 )
    {
      if ( v11 & 4 )
      {
        sub_C18630((std::exception *)&v13, 1, (int)off_CCAA40, "ios_base::badbit set");
      }
      else
      {
        if ( !(v11 & 2) )
        {
          sub_C18630((std::exception *)&v12, 1, (int)off_CCAA40, "ios_base::eofbit set");
          v12 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v12, &_TI5_AVfailure_ios_base_std__);
        }
        sub_C18630((std::exception *)&v13, 1, (int)off_CCAA40, "ios_base::failbit set");
      }
      v13 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v13, &_TI5_AVfailure_ios_base_std__);
    }
  }
  if ( a3 )
    std::ios_base::_Addstd(v3);
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CABEB8: using guessed type void *std::ios_base::failure::`vftable';
// CC4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// CCAA40: using guessed type int (__thiscall **off_CCAA40[2])(void *, char);

//----- (00C19F90) --------------------------------------------------------
int __thiscall sub_C19F90(_DWORD **this, int a2)
{
  (*(void (__stdcall **)(int, _DWORD *, _DWORD))(*this[1] + 8))(a2, *this, 0);
  return a2;
}

//----- (00C19FC0) --------------------------------------------------------
__int16 __thiscall sub_C19FC0(_DWORD *this, __int16 a2)
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
    v5 = (unsigned int *)this[8];
    v6 = *v5;
    if ( *v5 )
    {
      v7 = v2[14];
      if ( v6 < v7 )
      {
        v8 = *(_DWORD *)v2[12];
        *v5 = v7;
        *(_DWORD *)v2[12] = (signed int)(v6 + 2 * v8 - v7) >> 1;
      }
    }
  }
  v9 = *(_DWORD *)v2[8];
  if ( !v9 )
    goto LABEL_35;
  v10 = (_DWORD *)v2[12];
  if ( v9 < v9 + 2 * *v10 )
  {
    result = a2;
    --*v10;
    v11 = (__int16 **)v2[8];
    v12 = *v11;
    ++*v11;
    *v12 = a2;
    return result;
  }
  if ( v9 )
    v13 = (signed int)(v9 + 2 * *(_DWORD *)v2[12] - *(_DWORD *)v2[3]) >> 1;
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
  v15 = sub_BEFFE0(v14 + v13);
  v16 = (const void **)v2[3];
  v17 = (signed int)v15;
  v30 = (void *)*v16;
  if ( v13 && (memmove_0(v15, *v16, 2 * v13), v13) )
  {
    v22 = (_DWORD *)v2[4];
    v19 = v30;
    v2[14] = v17 + 2 * ((v2[14] - (signed int)v30) >> 1);
    v23 = v17 + 2 * ((*(_DWORD *)v2[8] - (signed int)v30) >> 1);
    *v22 = v17 + 2 * ((*v22 - (signed int)v30) >> 1);
    *(_DWORD *)v2[8] = v23;
    *(_DWORD *)v2[12] = (v17 + 2 * v29 - v23) >> 1;
    if ( v2[15] & 4 )
    {
      *(_DWORD *)v2[3] = v17;
      *(_DWORD *)v2[7] = 0;
      *(_DWORD *)v2[11] = v17 >> 1;
    }
    else
    {
      v24 = v17 + 2 * ((*(_DWORD *)v2[7] - (signed int)v30) >> 1);
      v25 = (*(_DWORD *)v2[8] - v24 + 2) >> 1;
      *(_DWORD *)v2[3] = v17;
      *(_DWORD *)v2[7] = v24;
      *(_DWORD *)v2[11] = v25;
    }
  }
  else
  {
    v18 = (signed int *)v2[4];
    v19 = v30;
    v2[14] = v17;
    *v18 = v17;
    *(_DWORD *)v2[8] = v17;
    *(_DWORD *)v2[12] = 2 * v29 >> 1;
    v20 = (v2[15] & 4) == 0;
    *(_DWORD *)v2[3] = v17;
    v21 = (signed int *)v2[7];
    if ( v20 )
    {
      *v21 = v17;
      *(_DWORD *)v2[11] = 1;
    }
    else
    {
      *v21 = 0;
      *(_DWORD *)v2[11] = v17 >> 1;
    }
  }
  if ( v2[15] & 1 )
    operator delete(v19);
  v26 = (_DWORD *)v2[12];
  v2[15] |= 1u;
  --*v26;
  v27 = (__int16 **)v2[8];
  v28 = *v27;
  ++*v27;
  result = a2;
  *v28 = a2;
  return result;
}

//----- (00C1A1E0) --------------------------------------------------------
signed int __stdcall sub_C1A1E0(int a1)
{
  return 0xFFFF;
}

//----- (00C1A1F0) --------------------------------------------------------
signed __int16 __thiscall sub_C1A1F0(int this, __int16 a2)
{
  unsigned int v2; // esi

  v2 = **(_DWORD **)(this + 28);
  if ( !v2 || v2 <= **(_DWORD **)(this + 12) || -1 != a2 && a2 != *(_WORD *)(v2 - 2) && *(_BYTE *)(this + 60) & 2 )
    return -1;
  ++**(_DWORD **)(this + 44);
  **(_DWORD **)(this + 28) -= 2;
  if ( -1 == a2 )
    return 0;
  ***(_WORD ***)(this + 28) = a2;
  return a2;
}

//----- (00C1A260) --------------------------------------------------------
_DWORD *__stdcall sub_C1A260(_DWORD *a1, int a2, int a3, int a4, int a5)
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

//----- (00C1A290) --------------------------------------------------------
signed int *__thiscall sub_C1A290(int this, signed int *a2, __int64 a3, int a4, char a5)
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
  v6 = *(unsigned int **)(this + 32);
  v7 = *v6;
  if ( *v6 && *(_DWORD *)(this + 56) < v7 )
    *(_DWORD *)(this + 56) = v7;
  if ( !(a5 & 1) || (v8 = **(_DWORD **)(this + 28), (v18 = v8) == 0) )
  {
    if ( a5 & 2 && (v15 = *v6) != 0 )
    {
      if ( a4 == 2 )
      {
        v9 = (unsigned __int64)(((*(_DWORD *)(this + 56) - **(_DWORD **)(this + 12)) >> 1) + a3) >> 32;
        v10 = ((*(_DWORD *)(this + 56) - **(_DWORD **)(this + 12)) >> 1) + a3;
      }
      else if ( a4 == 1 )
      {
        v9 = (unsigned __int64)(((signed int)(v15 - **(_DWORD **)(this + 12)) >> 1) + a3) >> 32;
        v10 = ((signed int)(v15 - **(_DWORD **)(this + 12)) >> 1) + a3;
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
        v16 = **(_DWORD **)(this + 12);
        if ( __PAIR__(v9, v10) <= (*(_DWORD *)(v5 + 56) - v16) >> 1 )
        {
          v20 = v10 + ((signed int)(v16 - v15) >> 1);
          **(_DWORD **)(v5 + 48) -= v20;
          **(_DWORD **)(v5 + 32) += 2 * v20;
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
        v9 = (unsigned __int64)(((v8 - **(_DWORD **)(this + 12)) >> 1) + a3) >> 32;
        v10 = ((v8 - **(_DWORD **)(this + 12)) >> 1) + a3;
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
  v9 = (unsigned __int64)(((*(_DWORD *)(this + 56) - **(_DWORD **)(this + 12)) >> 1) + a3) >> 32;
  v10 = ((*(_DWORD *)(this + 56) - **(_DWORD **)(this + 12)) >> 1) + a3;
LABEL_14:
  if ( v9 < 0 )
    goto LABEL_32;
  v11 = **(_DWORD **)(this + 12);
  if ( __PAIR__(v9, v10) > (*(_DWORD *)(v5 + 56) - v11) >> 1 )
    goto LABEL_32;
  v19 = v10 + ((v11 - v18) >> 1);
  **(_DWORD **)(v5 + 44) -= v19;
  **(_DWORD **)(v5 + 28) += 2 * v19;
  if ( a5 & 2 )
  {
    v12 = *(_DWORD **)(v5 + 32);
    if ( *v12 )
    {
      v13 = **(_DWORD **)(v5 + 28);
      v14 = (*v12 + 2 * **(_DWORD **)(v5 + 48) - v13) >> 1;
      **(_DWORD **)(v5 + 32) = v13;
      **(_DWORD **)(v5 + 48) = v14;
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

//----- (00C1A480) --------------------------------------------------------
_DWORD *__stdcall sub_C1A480(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
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

//----- (00C1A4B0) --------------------------------------------------------
signed int *__thiscall sub_C1A4B0(int this, signed int *a2, __int64 a3, __int64 a4, int a5, int a6, char a7)
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

  v7 = (unsigned __int64)(a3 + a4) >> 32;
  v8 = a3 + a4;
  v9 = this;
  v10 = *(unsigned int **)(this + 32);
  v11 = *v10;
  if ( *v10 && *(_DWORD *)(this + 56) < v11 )
    *(_DWORD *)(this + 56) = v11;
  if ( v8 != -1 || v7 != -1 )
  {
    if ( a7 & 1 && (v19 = **(_DWORD **)(this + 28)) != 0 )
    {
      if ( v7 >= 0 )
      {
        v12 = **(_DWORD **)(this + 12);
        if ( __PAIR__(v7, v8) <= (*(_DWORD *)(v9 + 56) - v12) >> 1 )
        {
          v13 = v8 + ((v12 - v19) >> 1);
          **(_DWORD **)(v9 + 44) -= v13;
          **(_DWORD **)(v9 + 28) += 2 * v13;
          if ( a7 & 2 )
          {
            v14 = *(_DWORD **)(v9 + 32);
            if ( *v14 )
            {
              v15 = **(_DWORD **)(v9 + 28);
              v16 = (*v14 + 2 * **(_DWORD **)(v9 + 48) - v15) >> 1;
              **(_DWORD **)(v9 + 32) = v15;
              **(_DWORD **)(v9 + 48) = v16;
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
        v17 = **(_DWORD **)(this + 12);
        if ( __PAIR__(v7, v8) <= (*(_DWORD *)(v9 + 56) - v17) >> 1 )
        {
          v21 = v8 + ((signed int)(v17 - v20) >> 1);
          **(_DWORD **)(v9 + 48) -= v21;
          **(_DWORD **)(v9 + 32) += 2 * v21;
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

//----- (00C1A600) --------------------------------------------------------
void *__thiscall sub_C1A600(void *this, int a2, int a3, int a4)
{
  return this;
}

//----- (00C1A610) --------------------------------------------------------
__int64 sub_C1A610()
{
  return 0i64;
}

//----- (00C1A620) --------------------------------------------------------
void *__thiscall sub_C1A620(_DWORD *this, void *a2)
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
    v4 = *(_DWORD *)v2[8];
    if ( v4 )
    {
      v5 = v2[14];
      if ( v5 < v4 )
        v5 = *(_DWORD *)v2[8];
      v6 = (void **)v2[4];
      goto LABEL_6;
    }
  }
  if ( !(v3 & 4) )
  {
    v8 = (_DWORD *)v2[7];
    if ( *v8 )
    {
      v5 = *v8 + 2 * *(_DWORD *)v2[11];
      v6 = (void **)v2[3];
LABEL_6:
      v7 = *v6;
      v12 = 7;
      v11 = 0;
      LOWORD(v10) = 0;
      sub_C19760((int *)&v10, v7, (signed int)(v5 - (_DWORD)v7) >> 1);
      goto LABEL_11;
    }
  }
  v12 = 7;
  v11 = 0;
  LOWORD(v10) = 0;
LABEL_11:
  sub_BE3530(a2, &v10);
  if ( v12 >= 8 )
    operator delete(v10);
  return a2;
}

//----- (00C1A6E0) --------------------------------------------------------
void *__thiscall sub_C1A6E0(_DWORD *this, void *a2)
{
  sub_C1A620(this + 6, a2);
  return a2;
}

//----- (00C1A700) --------------------------------------------------------
signed int __thiscall sub_C1A700(_DWORD **this)
{
  _DWORD **v1; // esi
  unsigned __int16 **v3; // ecx
  unsigned __int16 *v4; // edx

  v1 = this;
  if ( ((unsigned __int16 (*)(void))(*this)[6])() == -1 )
    return 0xFFFF;
  --*v1[11];
  v3 = (unsigned __int16 **)v1[7];
  v4 = *v3;
  ++*v3;
  return *v4;
}

//----- (00C1A730) --------------------------------------------------------
signed int sub_C1A730()
{
  return 0xFFFF;
}

//----- (00C1A740) --------------------------------------------------------
signed __int16 __thiscall sub_C1A740(int this)
{
  unsigned int *v1; // edi
  unsigned int v2; // esi
  int *v4; // ebx
  unsigned int v5; // eax

  v1 = *(unsigned int **)(this + 28);
  v2 = *v1;
  if ( !*v1 )
    return -1;
  v4 = *(int **)(this + 44);
  if ( v2 < v2 + 2 * *v4 )
    return *(_WORD *)v2;
  if ( *(_BYTE *)(this + 60) & 4 )
    return -1;
  v5 = **(_DWORD **)(this + 32);
  if ( !v5 || v5 <= v2 && *(_DWORD *)(this + 56) <= v2 )
    return -1;
  if ( *(_DWORD *)(this + 56) < v5 )
    *(_DWORD *)(this + 56) = v5;
  *v4 = (signed int)(*(_DWORD *)(this + 56) - *v1) >> 1;
  return ***(_WORD ***)(this + 28);
}

//----- (00C1A7B0) --------------------------------------------------------
unsigned int __thiscall sub_C1A7B0(_DWORD **this, void *a2, int a3, int a4)
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
    v7 = sub_C19140(v5);
    v12 = HIDWORD(v7);
    v8 = v7;
    if ( v7 >= 0 && (SHIDWORD(v7) > 0 || (_DWORD)v7) )
    {
      if ( __PAIR__(v4, v6) < v7 )
      {
        v8 = v6;
        v12 = v4;
      }
      if ( v8 )
        memmove_0(a2, (const void *)*v13[7], 2 * v8);
      a2 = (char *)a2 + 2 * v8;
      v9 = __CFADD__(v8, v14);
      v14 += v8;
      v5 = v13;
      v15 += v12 + v9;
      v4 = (__PAIR__(v4, v6) - __PAIR__((unsigned int)v12, v8)) >> 32;
      v6 -= v8;
      *v13[11] -= v8;
      *v13[7] += 2 * v8;
    }
    else
    {
      v10 = ((int (*)(void))(*v13)[7])();
      if ( v10 == -1 )
        return v14;
      *(_WORD *)a2 = v10;
      a2 = (char *)a2 + 2;
      v15 = (__PAIR__((unsigned int)v15, v14++) + 1) >> 32;
      v9 = v6-- != 0;
      v5 = v13;
      v4 = v9 + v4 - 1;
    }
  }
  while ( v4 > 0 || v4 >= 0 && v6 );
  return v14;
}

//----- (00C1A8C0) --------------------------------------------------------
unsigned int __thiscall sub_C1A8C0(_DWORD **this, void *a2, int a3, int a4)
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
    v7 = sub_C19400(v5);
    v11 = HIDWORD(v7);
    v8 = v7;
    if ( v7 >= 0 && (SHIDWORD(v7) > 0 || (_DWORD)v7) )
    {
      if ( __PAIR__(v4, v6) < v7 )
      {
        v8 = v6;
        v11 = v4;
      }
      if ( v8 )
        memmove_0((void *)*v12[8], a2, 2 * v8);
      a2 = (char *)a2 + 2 * v8;
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
      if ( ((unsigned __int16 (__stdcall *)(_DWORD))(*v12)[3])(*(unsigned __int16 *)a2) == -1 )
        return v13;
      v5 = v12;
      a2 = (char *)a2 + 2;
      v14 = (__PAIR__((unsigned int)v14, v13++) + 1) >> 32;
      v4 = (__PAIR__((unsigned int)v4, v6--) - 1) >> 32;
    }
  }
  while ( v4 > 0 || v4 >= 0 && v6 );
  return v13;
}

//----- (00C1A9D0) --------------------------------------------------------
void *__thiscall CObjSecurity::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi
  HLOCAL *v3; // edi

  v2 = this;
  v3 = (HLOCAL *)((char *)this + 12);
  *(_DWORD *)this = &CObjSecurity::`vftable';
  if ( this != (void *)-12 )
  {
    if ( *v3 )
      LocalFree(*v3);
    *v3 = 0;
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CAC4C4: using guessed type void *CObjSecurity::`vftable';

//----- (00C1AA10) --------------------------------------------------------
int __cdecl CObjSecurity::~CObjSecurity(int a1)
{
  return (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 8))(a1);
}

//----- (00C1AA20) --------------------------------------------------------
int __cdecl CObjSecurity::Create(tagHANDLELISTITEMPARAM *pItem, LPCWSTR lpszText, CObjSecurity **ppv, int nType, BOOL fObjSecurity)
{
  CObjSecurity *v5; // eax
  CObjSecurity *v6; // esi
  CObjSecurityVTbl *v7; // ecx
  int result; // eax
  int v9; // ebx

  *ppv = 0;
  v5 = (CObjSecurity *)operator new(0x1Cu);
  v6 = v5;
  if ( !v5 )
    return -2147024882;
  v5->vtptr = (CObjSecurityVTbl *)&CObjSecurity::`vftable';
  v7 = v5->vtptr;
  v5->m_nRefCount = 1;
  result = ((int (__stdcall *)(CObjSecurity *, signed int, tagHANDLELISTITEMPARAM *, LPCWSTR, const WCHAR **, int, BOOL))v7->Init)(
             v5,
             0x213,
             pItem,
             lpszText,
             &gszNullString,
             nType,
             fObjSecurity);
  v9 = result;
  if ( result < 0 )
  {
    ((void (__thiscall *)(CObjSecurity *, signed int))v6->vtptr->Destroy)(v6, 1);
    result = v9;
  }
  else
  {
    *ppv = v6;
  }
  return result;
}
// CAC4C4: using guessed type void *CObjSecurity::`vftable';

//----- (00C1AA90) --------------------------------------------------------
int __stdcall CObjSecurity::AddRef(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 4) + 1;
  *(_DWORD *)(a1 + 4) = result;
  return result;
}

//----- (00C1AAB0) --------------------------------------------------------
int __stdcall CObjSecurity::GetAccessRights(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int result; // eax

  switch ( *(_DWORD *)(a1 + 20) )
  {
    case 0:
      *a4 = &off_CCD008;
      *a5 = 9;
      *a6 = 0;
      result = 0;
      break;
    case 2:
      *a4 = &off_CCD098;
      *a5 = 5;
      *a6 = 0;
      result = 0;
      break;
    case 3:
      *a4 = &off_CCCCD8;
      *a5 = 19;
      *a6 = 0;
      result = 0;
      break;
    case 4:
      *a4 = &off_CCCF18;
      *a5 = 15;
      *a6 = 0;
      result = 0;
      break;
    case 5:
      *a4 = &off_CCCE08;
      *a5 = 17;
      *a6 = 0;
      result = 0;
      break;
    default:
      *a4 = &off_CCCC68;
      *a5 = 7;
      *a6 = 0;
      result = 0;
      break;
  }
  return result;
}
// CCCC68: using guessed type GUID *off_CCCC68;
// CCCCD8: using guessed type GUID *off_CCCCD8;
// CCCE08: using guessed type GUID *off_CCCE08;
// CCCF18: using guessed type GUID *off_CCCF18;
// CCD008: using guessed type GUID *off_CCD008;
// CCD098: using guessed type GUID *off_CCD098;

//----- (00C1ABB0) --------------------------------------------------------
int __stdcall CObjSecurity::GetInheritTypes(int a1, _DWORD *a2, _DWORD *a3)
{
  *a2 = &off_CCD0E8;
  *a3 = 1;
  return 0;
}
// CCD0E8: using guessed type GUID *off_CCD0E8;

//----- (00C1ABD0) --------------------------------------------------------
int __stdcall CObjSecurity::GetObjectInformation(_DWORD *a1, _DWORD *a2)
{
  *a2 = a1[2];
  a2[1] = ghMainInstance;
  a2[2] = a1[3];
  a2[3] = a1[4];
  return 0;
}

//----- (00C1AC00) --------------------------------------------------------
signed int __stdcall CObjSecurity::GetSecurity(CObjSecurity *a1, SECURITY_INFORMATION dwSecurityInformation, PSECURITY_DESCRIPTOR lpSecurityDescriptor, int a4)
{
  bool v4; // zf
  void **ppv; // esi
  signed int result; // eax
  HLOCAL pSecurityInfo; // eax

  v4 = a4 == 0;
  ppv = (void **)lpSecurityDescriptor;
  *(_DWORD *)lpSecurityDescriptor = 0;
  if ( !v4 )
    return E_NOTIMPL;
  if ( a1->m_nRightType == 4 )
  {
    QueryServiceObjectSecurity(
      (SC_HANDLE)a1->m_ServerInfo->hService,
      dwSecurityInformation,
      ppv,
      0,
      (LPDWORD)&lpSecurityDescriptor);
    if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
    {
      pSecurityInfo = LocalAlloc(0, (SIZE_T)lpSecurityDescriptor);
      *ppv = pSecurityInfo;
      if ( QueryServiceObjectSecurity(
             (SC_HANDLE)a1->m_ServerInfo->hService,
             dwSecurityInformation,
             pSecurityInfo,
             (DWORD)lpSecurityDescriptor,
             (LPDWORD)&lpSecurityDescriptor) )
      {
        return 0;
      }
    }
    result = GetLastError();
  }
  else
  {
    result = PE_QueryProcessKernelSecurity(a1->m_ServerInfo, dwSecurityInformation, ppv);
  }
  if ( result > 0 )
    result = (unsigned __int16)result | 0x80070000;
  return result;
}

//----- (00C1ACB0) --------------------------------------------------------
int __stdcall CObjSecurity::Init(CObjSecurity *a1, int a2, int a3, int a4, wchar_t *Src, int a6, int a7)
{
  int result; // eax

  a1->m_dwFlags = a2;
  if ( a7 )
    a1->m_dwFlags = a2 | 4;
  result = CopyServerName((int)&a1->m_pszServerName, Src);
  a1->m_nRightType = a6;
  a1->m_pszObjectName = (WCHAR *)a4;
  a1->m_ServerInfo = (SERVERINFO *)a3;
  return result;
}

//----- (00C1ACF0) --------------------------------------------------------
int __cdecl CopyServerName(int a1, wchar_t *Src)
{
  unsigned int v2; // kr00_4
  wchar_t *v3; // eax

  if ( !a1 || !Src )
    return -2147024809;
  v2 = wcslen(Src);
  v3 = (wchar_t *)LocalAlloc(0x40u, 2 * (v2 + 1));
  *(_DWORD *)a1 = v3;
  if ( !v3 )
    return -2147024882;
  wcscpy_s(v3, v2 + 1, Src);
  return 0;
}

//----- (00C1AD60) --------------------------------------------------------
int __stdcall CObjSecurity::MapGeneric(int a1, int a2, int a3, PDWORD AccessMask)
{
  int result; // eax

  if ( *(_DWORD *)(a1 + 20) == 3 )
  {
    MapGenericMask(AccessMask, &stru_CCCC38);
    result = 0;
  }
  else if ( *(_DWORD *)(a1 + 20) == 4 )
  {
    MapGenericMask(AccessMask, &stru_CCCC58);
    result = 0;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 20) == 5 )
      MapGenericMask(AccessMask, &stru_CCCC48);
    else
      MapGenericMask(AccessMask, &GenericMapping);
    result = 0;
  }
  return result;
}

//----- (00C1ADD0) --------------------------------------------------------
int __stdcall CObjSecurity::PropertySheetPageCallback(int a1, int a2, int a3, int a4)
{
  return 0;
}

//----- (00C1ADE0) --------------------------------------------------------
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
    v5 = (GUID *)((char *)v5 + 4);
    v7 = v6 < 4;
    v6 -= 4;
    if ( v7 )
    {
      *a3 = a1;
      ++*(_DWORD *)(a1 + 4);
      return 0;
    }
  }
  v9 = &CLSID_IObjectSecurity;
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
      ++*(_DWORD *)(a1 + 4);
      return 0;
    }
  }
  *a3 = 0;
  return -2147467262;
}
// CAC4B0: using guessed type GUID CLSID_IObjectSecurity;
// CB7BBC: using guessed type GUID CLSID_IUnknown;

//----- (00C1AE60) --------------------------------------------------------
int __stdcall CObjSecurity::Release(_DWORD *a1)
{
  bool v1; // zf
  int result; // eax

  v1 = a1[1]-- == 1;
  result = a1[1];
  if ( v1 )
  {
    (*(void (__stdcall **)(signed int))(*a1 + 40))(1);
    result = 0;
  }
  return result;
}

//----- (00C1AE80) --------------------------------------------------------
int __stdcall CObjSecurity::SetSecurity(CObjSecurity *a1, SECURITY_INFORMATION dwSecurityInformation, PSECURITY_DESCRIPTOR lpSecurityDescriptor)
{
  int result; // eax

  if ( a1->m_nRightType == 4 )
  {
    if ( SetServiceObjectSecurity((SC_HANDLE)a1->m_ServerInfo->hService, dwSecurityInformation, lpSecurityDescriptor) )
      return 0;
    result = GetLastError();
  }
  else
  {
    result = PE_SetServiceObjectSecurity(a1->m_ServerInfo, dwSecurityInformation, lpSecurityDescriptor, 0, 0);
  }
  if ( result > 0 )
    result = (unsigned __int16)result | 0x80070000;
  return result;
}

//----- (00C1AEE0) --------------------------------------------------------
int __thiscall sub_C1AEE0(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
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
    sub_C11430((std__List *)a6 + 2);
    operator delete(a6);
    std::_Xlength_error("map/set<T> too long");
  }
  this[1] = v7 + 1;
  *((_DWORD *)a6 + 1) = a4;
  if ( a4 == *this )
  {
    *(_DWORD *)(*this + 4) = a6;
    *(_DWORD *)*this = a6;
    *(_DWORD *)(*this + 8) = a6;
  }
  else if ( a3 )
  {
    *(_DWORD *)a4 = a6;
    if ( a4 == *(_DWORD *)*this )
      *(_DWORD *)*this = a6;
  }
  else
  {
    *(_DWORD *)(a4 + 8) = a6;
    if ( a4 == *(_DWORD *)(*this + 8) )
      *(_DWORD *)(*this + 8) = a6;
  }
  v8 = a6;
  if ( !*(_BYTE *)(*((_DWORD *)a6 + 1) + 12) )
  {
    do
    {
      v9 = (int *)v8[1];
      v10 = (int *)v9[1];
      v11 = (int *)*v10;
      if ( v9 == (int *)*v10 )
      {
        v11 = (int *)v10[2];
        if ( *((_BYTE *)v11 + 12) )
        {
          if ( v8 == (_DWORD *)v9[2] )
          {
            v8 = (_DWORD *)v8[1];
            v12 = (_DWORD *)v9[2];
            v9[2] = *v12;
            if ( !*(_BYTE *)(*v12 + 13) )
              *(_DWORD *)(*v12 + 4) = v9;
            v12[1] = v9[1];
            if ( v9 == *(int **)(*v6 + 4) )
            {
              *(_DWORD *)(*v6 + 4) = v12;
            }
            else
            {
              v13 = (void **)v9[1];
              if ( v8 == *v13 )
                *v13 = v12;
              else
                v13[2] = v12;
            }
            *v12 = v8;
            v8[1] = v12;
          }
          *(_BYTE *)(v8[1] + 12) = 1;
          *(_BYTE *)(*(_DWORD *)(v8[1] + 4) + 12) = 0;
          v14 = *(_DWORD **)(v8[1] + 4);
          v15 = (_DWORD *)*v14;
          *v14 = *(_DWORD *)(*v14 + 8);
          v16 = v15[2];
          if ( !*(_BYTE *)(v16 + 13) )
            *(_DWORD *)(v16 + 4) = v14;
          v15[1] = v14[1];
          if ( v14 == *(_DWORD **)(*v6 + 4) )
          {
            *(_DWORD *)(*v6 + 4) = v15;
            v15[2] = v14;
          }
          else
          {
            v17 = (_DWORD *)v14[1];
            if ( v14 == (_DWORD *)v17[2] )
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
      else if ( *((_BYTE *)v11 + 12) )
      {
        if ( v8 == (_DWORD *)*v9 )
        {
          v8 = (_DWORD *)v8[1];
          v18 = *v9;
          *v9 = *(_DWORD *)(*v9 + 8);
          v19 = *(_DWORD *)(v18 + 8);
          if ( !*(_BYTE *)(v19 + 13) )
            *(_DWORD *)(v19 + 4) = v8;
          *(_DWORD *)(v18 + 4) = v8[1];
          if ( v8 == *(_DWORD **)(*v6 + 4) )
          {
            *(_DWORD *)(*v6 + 4) = v18;
          }
          else
          {
            v20 = (_DWORD *)v8[1];
            if ( v8 == (_DWORD *)v20[2] )
              v20[2] = v18;
            else
              *v20 = v18;
          }
          *(_DWORD *)(v18 + 8) = v8;
          v8[1] = v18;
        }
        *(_BYTE *)(v8[1] + 12) = 1;
        *(_BYTE *)(*(_DWORD *)(v8[1] + 4) + 12) = 0;
        v14 = *(_DWORD **)(v8[1] + 4);
        v15 = (_DWORD *)v14[2];
        v14[2] = *v15;
        if ( !*(_BYTE *)(*v15 + 13) )
          *(_DWORD *)(*v15 + 4) = v14;
        v15[1] = v14[1];
        if ( v14 == *(_DWORD **)(*v6 + 4) )
        {
          *(_DWORD *)(*v6 + 4) = v15;
        }
        else
        {
          v21 = (_DWORD *)v14[1];
          if ( v14 == (_DWORD *)*v21 )
            *v21 = v15;
          else
            v21[2] = v15;
        }
        *v15 = v14;
        goto LABEL_48;
      }
      *((_BYTE *)v9 + 12) = 1;
      *((_BYTE *)v11 + 12) = 1;
      *(_BYTE *)(*(_DWORD *)(v8[1] + 4) + 12) = 0;
      v8 = *(_DWORD **)(v8[1] + 4);
    }
    while ( !*(_BYTE *)(v8[1] + 12) );
  }
  *(_BYTE *)(*(_DWORD *)(*v6 + 4) + 12) = 1;
  result = a2;
  *(_DWORD *)a2 = a6;
  return result;
}

//----- (00C1B100) --------------------------------------------------------
int __thiscall sub_C1B100(std__tree *this, int a2, int a3, int a4, void *a5)
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
  _bstr_t *v15; // esi
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
  v5 = (std_Tree_node_for_tagKeyName *)this->_Mypair._Myval2._Myhead;
  v6 = 1;
  v25 = 0;
  LOBYTE(v23) = 1;
  v7 = v5->_Parent;
  if ( !v7->_IsNil )
  {
    while ( 1 )
    {
      v5 = v7;
      if ( !(_BYTE)a3 )
      {
        v11 = *(Data_t_bstr_t **)a4;
        v12 = (OLECHAR **)v7->_Myval.first;
        if ( *(OLECHAR ***)a4 == v12 )
          goto LABEL_16;
        if ( v11 )
        {
          if ( v12 )
          {
            v13 = _bstr_t::Data_t::Compare(v11, (Data_t_bstr_t *)v7->_Myval.first);
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
      v8 = (Data_t_bstr_t *)v7->_Myval.first;
      v9 = *(Data_t_bstr_t **)a4;
      if ( v8 != *(Data_t_bstr_t **)a4 )
      {
        if ( v8 )
        {
          if ( v9 )
          {
            v6 = _bstr_t::Data_t::Compare(v8, v9) >= 0;
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
  v15 = (_bstr_t *)v5;
  a3 = (int)v5;
  if ( v6 )
  {
    if ( v5 == this->_Mypair._Myval2._Myhead->_Left )
    {
      v16 = (int *)sub_C1AEE0(this, (int)&a3, 1, (int)v5, a4, a5);
LABEL_36:
      v17 = *v16;
      result = a2;
      *(_DWORD *)a2 = v17;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&a3);
    v15 = (_bstr_t *)a3;
  }
  v19 = a4;
  if ( (unsigned __int8)_bstr_t::operator!=(v15 + 4, (_bstr_t *)a4) )
  {
    v16 = (int *)sub_C1AEE0(v22, (int)&a3, v23, (int)v5, v19, a5);
    goto LABEL_36;
  }
  v20 = a5;
  sub_C11430((std__List *)a5 + 2);
  operator delete(v20);
  result = a2;
  *(_DWORD *)a2 = v15;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C1B2D0) --------------------------------------------------------
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
  v2->pszData = (CHAR *)(((int (*)(void))v3->vtptr->GetNilData)() + 16);
  if ( !nID )
  {
    v5 = 0;
    goto LABEL_9;
  }
  if ( nID & 0xFFFF0000 )
  {
    v5 = wcslen((const unsigned __int16 *)nID);
LABEL_9:
    ATL::CSimpleStringT<wchar_t,0>::SetString(v2, (void *)nID, v5);
    return v2;
  }
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance((unsigned __int16)nID, 0);
  if ( v4 )
    ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::LoadStringW(
      v2,
      (HMODULE)v4,
      (unsigned __int16)nID);
  return v2;
}

//----- (00C1B3A0) --------------------------------------------------------
CString *__thiscall ATL::CSimpleStringT<wchar_t,0>::CSimpleStringT<wchar_t,0>(CString *this)
{
  CString *v1; // esi
  IAtlStringMgr *v2; // ecx

  v1 = this;
  v2 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v2 )
    ATL::AtlThrowImpl(E_FAIL);
  v1->pszData = (CHAR *)(((int (*)(void))v2->vtptr->GetNilData)() + 16);
  return v1;
}

//----- (00C1B3D0) --------------------------------------------------------
ATL::CAtlStringMgr *__thiscall ATL::CAtlStringMgr::Clone(ATL::CAtlStringMgr *this)
{
  return this;
}

//----- (00C1B3E0) --------------------------------------------------------
volatile signed __int32 *__thiscall ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(CString *this)
{
  CStringData *v1; // edx
  volatile signed __int32 *result; // eax

  v1 = (CStringData *)(this->pszData - 16);
  result = &v1->nRefs;
  if ( _InterlockedDecrement(&v1->nRefs) <= 0 )
    result = (volatile signed __int32 *)((int (__stdcall *)(CStringData *))v1->pStringMgr->vtptr->Free)(v1);
  return result;
}

//----- (00C1B460) --------------------------------------------------------
// CString::operator+(const CString& str1,LPCWSTR lpszText)
CString *__cdecl ATL::CSimpleStringT<wchar_t,0>::Append(CString *str1, CString *str2, WCHAR *lpszSource2)
{
  CStringData *v3; // ecx
  IAtlStringMgr *v4; // edx
  IAtlStringMgr *v5; // eax
  int v6; // edx

  v3 = (CStringData *)*((_DWORD *)str2->pszData - 4);
  if ( !v3 || (v4 = (IAtlStringMgr *)((int (*)(void))v3->pStringMgr[4].vtptr)()) == 0 )
  {
    v5 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
    v4 = (IAtlStringMgr *)((int (__thiscall *)(IAtlStringMgr *))v5->vtptr->Clone)(v5);
  }
  if ( !v4 )
    ATL::AtlThrowImpl(E_FAIL);
  str1->pszData = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v4->vtptr->GetNilData)(v4) + 16);
  if ( lpszSource2 )
    v6 = wcslen(lpszSource2);
  else
    v6 = 0;
  ATL::CSimpleStringT<wchar_t,0>::Concatenate(
    str1,
    (WCHAR *)str2->pszData,
    *((_DWORD *)str2->pszData - 3),
    lpszSource2,
    v6);
  return str1;
}

//----- (00C1B540) --------------------------------------------------------
void *__thiscall ATL::CAtlStringMgr::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *(_DWORD *)this = &ATL::CAtlStringMgr::`vftable';
  byte_CD4DF4 = 0;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// CAC510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// CD4DF4: using guessed type char byte_CD4DF4;

//----- (00C1B570) --------------------------------------------------------
void *__thiscall ATL::CWin32Heap::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi
  bool v3; // zf

  v2 = this;
  v3 = *((_BYTE *)this + 8) == 0;
  *(_DWORD *)this = &ATL::CWin32Heap::`vftable';
  if ( !v3 && *((_DWORD *)this + 1) )
    HeapDestroy(*((HANDLE *)this + 1));
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CAC4F8: using guessed type void *ATL::CWin32Heap::`vftable';

//----- (00C1B5B0) --------------------------------------------------------
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
  v7 = (***((int (__stdcall ****)(int))this + 1))(v6 + 16);
  if ( !v7 )
    return 0;
  *(_DWORD *)v7 = v3;
  *(_DWORD *)(v7 + 8) = v5 - 1;
  result = (ATL::CAtlStringMgr **)v7;
  *(_DWORD *)(v7 + 12) = 1;
  *(_DWORD *)(v7 + 4) = 0;
  return result;
}

//----- (00C1B630) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Allocate(HANDLE *this, SIZE_T dwBytes)
{
  return HeapAlloc(this[1], 0, dwBytes);
}

//----- (00C1B650) --------------------------------------------------------
int __cdecl sub_C1B650(int a1)
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

//----- (00C1B6F0) --------------------------------------------------------
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
  v4 = (unsigned int)a1 >> 4;
  while ( 1 )
  {
    v5 = FindResourceExW((HMODULE)v2, (LPCWSTR)6, (LPCWSTR)(unsigned __int16)(v4 + 1), wLanguage);
    if ( v5 )
    {
      if ( ATL::AtlGetStringResourceImage((HMODULE)v2, v5, a1) )
        break;
    }
    v2 = ATL::CAtlBaseModule::GetHInstanceAt(&ATL::_AtlBaseModule, v3++);
    if ( !v2 )
      return 0;
  }
  return v2;
}

//----- (00C1B760) --------------------------------------------------------
void __cdecl __noreturn ATL::AtlThrowImpl(int a1)
{
  _CxxThrowException(&a1, &_TI1_AVCAtlException_ATL__);
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CC4740: using guessed type int _TI1_AVCAtlException_ATL__;

//----- (00C1B780) --------------------------------------------------------
void __cdecl PE_LaunchExe(HWND hWnd, CCmdString *lpCommandLine)
{
  CCmdString *lpCommandLine_1; // esi
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

  lpCommandLine_1 = lpCommandLine;
  if ( LOWORD(lpCommandLine->m_String) == 'H' )
  {
    PE_LaunchRegedit(hWnd, (LPCWSTR)lpCommandLine);
  }
  else
  {
    StartupInfo.cb = 68;
    StartupInfo.lpReserved = 0;
    memset(&StartupInfo.lpDesktop, 0, 0x3Cu);
    _mm_storeu_si128((__m128i *)&ProcessInformation, (__m128i)0i64);
    v3 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(
           &v15,
           (UINT)L"explorer /select,");
    index = 0;
    ATL::CSimpleStringT<wchar_t,0>::Append((CString *)&lpCommandLine, v3, (WCHAR *)lpCommandLine_1);
    v4 = (CStringData *)(v15.pszData - 16);
    LOBYTE(index) = 2;
    if ( _InterlockedDecrement((volatile signed __int32 *)v15.pszData - 1) <= 0 )
      ((void (__stdcall *)(CStringData *))v4->pStringMgr->vtptr->Free)(v4);
    if ( CreateProcessW(0, (LPWSTR)lpCommandLine, 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation) )
    {
      CloseHandle(ProcessInformation.hThread);
      CloseHandle(ProcessInformation.hProcess);
    }
    else
    {
      v5 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(
             &v13,
             (UINT)L"Explorer could not open ");
      LOBYTE(index) = 3;
      v6 = ATL::CSimpleStringT<wchar_t,0>::Append(&str1, v5, (WCHAR *)lpCommandLine_1);
      LOBYTE(index) = 4;
      ATL::CSimpleStringT<wchar_t,0>::Append(&lpText, v6, ".");
      v7 = (CStringData *)(str1.pszData - 16);
      LOBYTE(index) = 3;
      if ( _InterlockedDecrement((volatile signed __int32 *)str1.pszData - 1) <= 0 )
        ((void (__stdcall *)(CStringData *))v7->pStringMgr->vtptr->Free)(v7);
      v8 = (CStringData *)(v13.pszData - 16);
      LOBYTE(index) = 2;
      if ( _InterlockedDecrement((volatile signed __int32 *)v13.pszData - 1) <= 0 )
        ((void (__stdcall *)(CStringData *))v8->pStringMgr->vtptr->Free)(v8);
      MessageBoxW(hWnd, (LPCWSTR)lpText.pszData, L"Process Explorer", MB_ICONEXCLAMATION);
      v9 = (CStringData *)(lpText.pszData - 16);
      if ( _InterlockedDecrement((volatile signed __int32 *)lpText.pszData - 1) <= 0 )
        ((void (__stdcall *)(CStringData *))v9->pStringMgr->vtptr->Free)(v9);
    }
    v10 = (CStringData *)&lpCommandLine[-4];
    index = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)&lpCommandLine[-1]) <= 0 )
      ((void (__stdcall *)(CStringData *))v10->pStringMgr->vtptr->Free)(v10);
  }
}
// CAC528: using guessed type wchar_t aExplorerSelect[18];
// CAC54C: using guessed type wchar_t aExplorerCouldN[25];

//----- (00C1B950) --------------------------------------------------------
HANDLE StartBackendThread()
{
  InitializeCriticalSection(&gBstrListLock);
  return _beginthread((int)BackendThreadProc, 0, 0);
}

//----- (00C1B970) --------------------------------------------------------
CStringData *__cdecl sub_C1B970(CStringData *a1)
{
  IAtlStringMgr *pStringMgr; // eax
  volatile signed __int32 *v2; // edx
  CStringData *result; // eax
  CStringData *pNewData; // eax
  CStringData *v5; // edi

  pStringMgr = (IAtlStringMgr *)((int (*)(void))a1->pStringMgr->vtptr->Clone)();
  v2 = &a1->nRefs;
  if ( a1->nRefs < 0 || pStringMgr != a1->pStringMgr )
  {
    pNewData = (CStringData *)((int (__fastcall *)(IAtlStringMgr *, volatile signed __int32 *, int, signed int))pStringMgr->vtptr->Allocate)(
                                pStringMgr,
                                v2,
                                a1->nDataLength,
                                2);
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

//----- (00C1B9E0) --------------------------------------------------------
CHAR *__cdecl ATL::CSimpleStringT<wchar_t,0>::Concatenate(CString *this, WCHAR *lpszSource, int nLength, void *lpszSource2, int nLength2)
{
  int v5; // ebx
  CHAR *pszData; // edi
  CHAR *result; // eax

  v5 = nLength2 + nLength;
  if ( nLength2 + nLength < 0 )
    goto LABEL_9;
  if ( ((*((_DWORD *)this->pszData - 2) - v5) | (1 - *((_DWORD *)this->pszData - 1))) < 0 )
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(this, nLength2 + nLength);
  pszData = this->pszData;
  memcpy_s(this->pszData, 2 * nLength, lpszSource, 2 * nLength);
  memcpy_s(&pszData[2 * nLength], 2 * nLength2, lpszSource2, 2 * nLength2);
  if ( v5 > *((_DWORD *)this->pszData - 2) )
LABEL_9:
    ATL::AtlThrowImpl(E_INVALIDARG);
  *((_DWORD *)this->pszData - 3) = v5;
  result = this->pszData;
  *(_WORD *)&this->pszData[2 * v5] = 0;
  return result;
}

//----- (00C1BA60) --------------------------------------------------------
CStringData *__thiscall ATL::CSimpleStringT<wchar_t,0>::Empty(CString *this)
{
  CString *v1; // esi
  CStringData *result; // eax
  CStringData *v3; // edx
  IAtlStringMgr *v4; // edi

  v1 = this;
  result = (CStringData *)this->pszData;
  v3 = (CStringData *)(this->pszData - 16);
  v4 = v3->pStringMgr;
  if ( *((_DWORD *)this->pszData - 3) )
  {
    if ( v3->nRefs >= 0 )
    {
      if ( _InterlockedDecrement(&v3->nRefs) <= 0 )
        ((void (__stdcall *)(CStringData *))v3->pStringMgr->vtptr->Free)(v3);
      result = (CStringData *)(((int (__thiscall *)(IAtlStringMgr *))v4->vtptr->GetNilData)(v4) + 16);
      v1->pszData = (CHAR *)result;
    }
    else
    {
      if ( result[-1].nAllocLength < 0 )
        ATL::AtlThrowImpl(E_INVALIDARG);
      result[-1].nDataLength = 0;
      result = (CStringData *)this->pszData;
      *(_WORD *)this->pszData = 0;
    }
  }
  return result;
}

//----- (00C1BAC0) --------------------------------------------------------
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
  pOldData = (CStringData *)(this->pszData - 16);
  nOldLength = pOldData->nDataLength;
  v4 = (IAtlStringMgr *)((int (*)(void))pOldData->pStringMgr->vtptr->Clone)();
  nLength_1 = nLength;
  pNewData = (CStringData *)((int (__thiscall *)(IAtlStringMgr *, int, signed int))v4->vtptr->Allocate)(v4, nLength, 2);
  pNewData_1 = pNewData;
  if ( !pNewData )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  if ( nOldLength < nLength_1 )
    nLength_1 = nOldLength;
  nCharsToCopy = 2 * (nLength_1 + 1);
  pszData = (CHAR *)&pNewData[1];
  memcpy_s(&pNewData[1], nCharsToCopy, &pOldData[1], nCharsToCopy);
  pNewData_1->nDataLength = nOldLength;
  result = &pOldData->nRefs;
  if ( _InterlockedDecrement(&pOldData->nRefs) <= 0 )
    result = (volatile signed __int32 *)((int (__stdcall *)(CStringData *))pOldData->pStringMgr->vtptr->Free)(pOldData);
  pThis->pszData = pszData;
  return result;
}

//----- (00C1BB40) --------------------------------------------------------
int __thiscall ATL::CAtlStringMgr::Free(ATL::CAtlStringMgr *this, struct CStringData *a2)
{
  return (*(int (**)(void))(**((_DWORD **)this + 1) + 4))();
}

//----- (00C1BB50) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Free(HANDLE *this, LPVOID lpMem)
{
  LPVOID result; // eax

  result = lpMem;
  if ( lpMem )
    result = (LPVOID)HeapFree(this[1], 0, lpMem);
  return result;
}

//----- (00C1BB70) --------------------------------------------------------
wchar_t *__cdecl sub_C1BB70(wchar_t *a1, wchar_t *a2)
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
  _wcsupr((wchar_t *)v3);
  EnterCriticalSection(&gBstrListLock);
  v4 = *gBstrList;
  if ( (int *)*gBstrList == gBstrList )
    goto LABEL_27;
  while ( 1 )
  {
    v5 = **(const wchar_t ****)(v4 + 8);
    if ( v5 )
      v6 = *v5;
    else
      v6 = 0;
    if ( _wcsicmp(v6, L"System") )
    {
      v7 = **(_DWORD ***)(v4 + 8);
      v8 = (const wchar_t *)(v7 ? *v7 : 0);
      if ( _wcsicmp(v8, a1) )
        goto LABEL_25;
    }
    v9 = *(_DWORD *)(v4 + 8);
    _bstr_t::_bstr_t((tagEventSetItem *)&a2, (OLECHAR *)v3);
    v10 = (int *)(v9 + 4);
    v11 = sub_C1C770((tagPEStringStruct *)(v9 + 4), (_bstr_t *)&a2);
    if ( v11 == (tagPEStringStruct *)*v10
      || (unsigned __int8)_bstr_t::operator!=((_bstr_t *)&a2, (_bstr_t *)&v11->strValue[4]) )
    {
      v18 = *v10;
      v12 = &v18;
    }
    else
    {
      v19 = v11;
      v12 = (int *)&v19;
    }
    v13 = a2;
    v14 = *v12;
    v17 = v14;
    if ( a2 )
    {
      if ( !InterlockedDecrement((volatile LONG *)a2 + 2) )
      {
        if ( *(_DWORD *)v13 )
        {
          SysFreeString(*(BSTR *)v13);
          *(_DWORD *)v13 = 0;
        }
        if ( *((_DWORD *)v13 + 1) )
        {
          operator delete[](*((void **)v13 + 1));
          *((_DWORD *)v13 + 1) = 0;
        }
        operator delete(v13);
      }
      v14 = v17;
      a2 = 0;
    }
    if ( v14 != *v10 )
      break;
    v3 = v20;
LABEL_25:
    v4 = *(_DWORD *)v4;
    if ( (int *)v4 == gBstrList )
      goto LABEL_26;
  }
  v16 = *(const wchar_t ***)(v14 + 20);
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

//----- (00C1BCE0) --------------------------------------------------------
IAtlStringMgr *__stdcall ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager()
{
  int v0; // eax
  HANDLE v1; // eax

  v0 = ATL::CAtlStringMgr::sbInited;
  if ( !(ATL::CAtlStringMgr::sbInited & 1) )
  {
    ATL::CAtlStringMgr::sbInited |= 1u;
    v1 = GetProcessHeap();
    strHeap.baseclass.vtptr = (IAtlMemMgrVTable *)&ATL::CWin32Heap::`vftable';
    strHeap.m_hHeap = v1;
    strHeap.m_bOwnHeap = 0;
    atexit(sub_C9A7F0);
    v0 = ATL::CAtlStringMgr::sbInited;
  }
  if ( !(v0 & 2) )
  {
    strMgr.baseclass.vtptr = (IAtlStringMgrVTable *)&ATL::CAtlStringMgr::`vftable';
    ATL::CAtlStringMgr::sbInited = v0 | 2;
    strMgr.m_pMemMgr = (IAtlMemMgr *)&strHeap;
    strMgr.m_nil.baseclass.nRefs = 2;
    strMgr.m_nil.baseclass.nDataLength = 0;
    strMgr.m_nil.baseclass.nAllocLength = 0;
    *(_DWORD *)strMgr.m_nil.achNil = 0;
    strMgr.m_nil.baseclass.pStringMgr = (IAtlStringMgr *)&strMgr;
    atexit(sub_C9A820);
  }
  return (IAtlStringMgr *)&strMgr;
}
// CAC4F8: using guessed type void *ATL::CWin32Heap::`vftable';
// CAC510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// CD4E04: using guessed type int ATL::CAtlStringMgr::sbInited;

//----- (00C1BD90) --------------------------------------------------------
char *__thiscall ATL::CAtlStringMgr::GetNilString(ATL::CAtlStringMgr *this)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)this + 5, 1u);
  return (char *)this + 8;
}

//----- (00C1BDA0) --------------------------------------------------------
SIZE_T __thiscall ATL::CWin32Heap::GetSize(HANDLE *this, LPCVOID lpMem)
{
  return HeapSize(this[1], 0, lpMem);
}

//----- (00C1BDC0) --------------------------------------------------------
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
  v4 = FindResourceW(hModule, (LPCWSTR)(unsigned __int16)(((unsigned int)nID >> 4) + 1), (LPCWSTR)6);
  if ( !v4 )
    return 0;
  pImage = (ATLSTRINGRESOURCEIMAGE *)ATL::AtlGetStringResourceImage(hModule, v4, nID);
  v6 = pImage;
  if ( !pImage )
    return 0;
  nDestLength = pImage->nLength;
  if ( ((*((_DWORD *)pThis->pszData - 2) - nDestLength) | (1 - *((_DWORD *)pThis->pszData - 1))) < 0 )
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
  sub_C1B650(v11);
  if ( nDestLength > *((_DWORD *)pThis->pszData - 2) )
    ATL::AtlThrowImpl(E_INVALIDARG);
  *((_DWORD *)pThis->pszData - 3) = nDestLength;
  result = 1;
  *(_WORD *)&pThis->pszData[2 * nDestLength] = 0;
  return result;
}

//----- (00C1BE90) --------------------------------------------------------
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
  v4 = (CStringData *)this->pszData;
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
      result = (volatile signed __int32 *)ATL::CSimpleStringT<wchar_t,0>::Reallocate(this_1, v8);
    }
    else
    {
      // 1024 * 1024
      v7 = nAllocLength + 0x100000;
      if ( v7 < nLength )
        v7 = nLength;
      result = (volatile signed __int32 *)ATL::CSimpleStringT<wchar_t,0>::Reallocate(this_1, v7);
    }
  }
  return result;
}

//----- (00C1BF00) --------------------------------------------------------
volatile signed __int32 *__cdecl PE_UpdateKey(OLECHAR *lpszText1, OLECHAR *lpszText2, OLECHAR *lpszText3)
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
  std__list_node *v13; // eax
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
  _Node = (std__list_node_for_BSTR *)*gBstrList;
  if ( (int *)*gBstrList == gBstrList )
    goto LABEL_9;
  while ( 1 )
  {
    v4 = (Data_t_bstr_t *)_Node->__MyVal.pStringItem->strValue[0];
    v5 = v4 ? v4->m_wstr : 0;
    if ( !_wcsicmp(v5, lpszText1) )
      break;
    _Node = (std__list_node_for_BSTR *)_Node->_Next;
    if ( _Node == (std__list_node_for_BSTR *)gBstrList )
      goto LABEL_9;
  }
  pStringItem = (Data_t_bstr_t *)_Node->__MyVal.pStringItem;
  if ( !pStringItem )
  {
LABEL_9:
    pItem = (Data_t_bstr_t *)operator new(0xCu);
    pStringItem = pItem;
    pItem_2 = pItem;
    v49 = 0;
    if ( pItem )
    {
      pItem->m_wstr = 0;
      LOBYTE(v49) = 1;
      pItem->m_str = 0;
      pItem->m_RefCount = 0;
      pItem->m_str = (char *)std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
    }
    else
    {
      pStringItem = 0;
    }
    theTmpMap = pStringItem;
    v8 = (Data_t_bstr_t *)operator new(0xCu);
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
    if ( pStringItem != (Data_t_bstr_t *)&pItem_2 )
    {
      v11 = (Data_t_bstr_t *)pStringItem->m_wstr;
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
            operator delete[](v11->m_str);
            v11->m_str = 0;
          }
          operator delete(v11);
        }
        pStringItem->m_wstr = 0;
      }
      pStringItem->m_wstr = (BSTR)v9;
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
        operator delete[](v9->m_str);
        v9->m_str = 0;
      }
      operator delete(v9);
    }
    v12 = gBstrList;
    v13 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
            (EventList *)gBstrList,
            (_DWORD *)gBstrList[1],
            &theTmpMap);
    if ( (unsigned int)(357913940 - (_DWORD)*(&gBstrList + 1)) < 1 )
      std::_Xlength_error("list<T> too long");
    *(&gBstrList + 1) = (int *)((char *)*(&gBstrList + 1) + 1);
    v12[1] = (int)v13;
    v13->_Prev->_Next = v13;
  }
  _wcsupr(lpszText2);
  v14 = (Data_t_bstr_t *)operator new(0xCu);
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
  v17 = (Data_t_bstr_t *)((char *)pStringItem + 4);
  theTmpMap = v17;
  v18 = sub_C1C770((tagPEStringStruct *)v17, (_bstr_t *)&pItem_2);
  v19 = v18;
  if ( v18 != (tagPEStringStruct *)v17->m_wstr )
  {
    v20 = (Data_t_bstr_t *)v18->strValue[4];
    if ( v15 == v20 )
      goto LABEL_52;
    if ( !v20 )
    {
      if ( v15->m_wstr )
      {
        SysStringLen(v15->m_wstr);
        pItem_2 = (Data_t_bstr_t *)v19;
        goto LABEL_54;
      }
      goto LABEL_52;
    }
    if ( _bstr_t::Data_t::Compare(v15, (Data_t_bstr_t *)v19->strValue[4]) >= 0 )
    {
LABEL_52:
      pItem_2 = (Data_t_bstr_t *)v19;
      goto LABEL_54;
    }
  }
  pItem_2 = (Data_t_bstr_t *)v17->m_wstr;
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
      operator delete[](v15->m_str);
      v15->m_str = 0;
    }
    operator delete(v15);
  }
  v22 = v21 == (Data_t_bstr_t *)v17->m_wstr;
  v23 = lpszText3;
  if ( v22 )
  {
    v24 = (Data_t_bstr_t *)operator new(0xCu);
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
    v27 = (Data_t_bstr_t *)operator new(0xCu);
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
    theTmpList._Mypair._Myval2._Myhead = (std__list_node *)v28;
    InterlockedIncrement(&v28->m_RefCount);
    theTmpList._Mypair._Myval2._Mysize = (unsigned int)v25;
    InterlockedIncrement(&v25->m_RefCount);
    LOBYTE(v49) = 8;
    v30 = sub_C111F0((std__tree *)theTmpMap, &theTmpList);
    sub_C1B100((std__tree *)theTmpMap, (int)&a2, 0, (int)&v30->_Keyvalue, v30);
    sub_C11430(&theTmpList);
    if ( !InterlockedDecrement(&v28->m_RefCount) )
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
        operator delete[](v25->m_str);
        v25->m_str = 0;
      }
      operator delete(v25);
    }
    v23 = lpszText3;
  }
  LeaveCriticalSection(&gBstrListLock);
  v31 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v31 )
    ATL::AtlThrowImpl(E_FAIL);
  lParam = ((int (__thiscall *)(IAtlStringMgr *))v31->vtptr->GetNilData)(v31) + 16;
  v32 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v32 )
    ATL::AtlThrowImpl(-2147467259);
  v42.pszData = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v32->vtptr->GetNilData)(v32) + 16);
  v33 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v33 )
    ATL::AtlThrowImpl(-2147467259);
  v43.pszData = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v33->vtptr->GetNilData)(v33) + 16);
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
  ATL::CSimpleStringT<wchar_t,0>::SetString((CString *)&lParam, lpszText1, v35);
  if ( v23 )
    v36 = wcslen(v23);
  else
    v36 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(&v43, v23, v36);
  SendMessageW(ghMainWnd, WM_MSG_7F8, 0, (LPARAM)&lParam);
  v37 = v43.pszData - 16;
  v49 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)v43.pszData - 1) <= 0 )
    (*(void (__stdcall **)(CHAR *))(**(_DWORD **)v37 + 4))(v37);
  v38 = v42.pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v42.pszData - 1) <= 0 )
    (*(void (__stdcall **)(CHAR *))(**(_DWORD **)v38 + 4))(v38);
  v39 = lParam - 16;
  result = (volatile signed __int32 *)(lParam - 16 + 12);
  if ( _InterlockedDecrement(result) <= 0 )
    result = (volatile signed __int32 *)(*(int (__stdcall **)(int))(**(_DWORD **)v39 + 4))(v39);
  return result;
}

//----- (00C1C530) --------------------------------------------------------
CStringData *__thiscall ATL::CSimpleStringT<wchar_t,0>::Reallocate(CString *this, int nLength)
{
  CString *v2; // edi
  CStringData *v3; // edx
  CStringData *pNewData; // eax
  CStringData *result; // eax

  v2 = this;
  v3 = (CStringData *)(this->pszData - 16);
  if ( v3->nAllocLength >= nLength
    || nLength <= 0
    || (pNewData = (CStringData *)((int (__stdcall *)(CStringData *, int, signed int))v3->pStringMgr->vtptr->Reallocate)(
                                    v3,
                                    nLength,
                                    2)) == 0 )
  {
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  }
  result = pNewData + 1;
  v2->pszData = (CHAR *)result;
  return result;
}

//----- (00C1C570) --------------------------------------------------------
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
  result = (*(int (__stdcall **)(struct CStringData *, unsigned int))(**((_DWORD **)this + 1) + 8))(a2, v6 + 16);
  if ( !result )
    return 0;
  *(_DWORD *)(result + 8) = v5 - 1;
  return result;
}

//----- (00C1C5E0) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Reallocate(HANDLE *this, LPVOID lpMem, SIZE_T dwBytes)
{
  if ( !lpMem )
    return (LPVOID)(*(int (__stdcall **)(SIZE_T))*this)(dwBytes);
  if ( dwBytes )
    return HeapReAlloc(this[1], 0, lpMem, dwBytes);
  (*((void (__stdcall **)(LPVOID))*this + 1))(lpMem);
  return 0;
}

//----- (00C1C620) --------------------------------------------------------
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
  v7 = (signed int)((signed int)Src - (unsigned int)this->pszData) >> 1;
  nLength_1 = *((_DWORD *)this->pszData - 3);
  if ( v3 < 0 )
    ATL::AtlThrowImpl(E_INVALIDARG);
  if ( ((*((_DWORD *)this->pszData - 2) - v3) | (1 - *((_DWORD *)this->pszData - 1))) < 0 )
  {
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(this, v3);
    v6 = Src;
  }
  v8 = (CStringData *)pThis->pszData;
  if ( v7 > nLength_1 )
  {
    v9 = 2 * v3;
    memcpy_s(v8, 2 * v8[-1].nAllocLength, v6, 2 * v3);
  }
  else
  {
    memmove_s(v8, 2 * v8[-1].nAllocLength, (char *)v8 + 2 * v7, 2 * v3);
    v9 = 2 * v3;
  }
  if ( v3 > *((_DWORD *)pThis->pszData - 2) )
LABEL_16:
    ATL::AtlThrowImpl(E_INVALIDARG);
  *((_DWORD *)pThis->pszData - 3) = v3;
  result = (CStringData *)pThis->pszData;
  *(_WORD *)&pThis->pszData[v9] = 0;
  return result;
}

//----- (00C1C6E0) --------------------------------------------------------
HGLOBAL __cdecl ATL::AtlGetStringResourceImage(HMODULE hModule, HRSRC hResInfo, int id)
{
  HGLOBAL result; // eax
  ATLSTRINGRESOURCEIMAGE *pImage; // esi
  ATLSTRINGRESOURCEIMAGE *v5; // edx
  int iIndex; // ecx

  result = LoadResource(hModule, hResInfo);
  if ( result )
  {
    pImage = (ATLSTRINGRESOURCEIMAGE *)LockResource(result);
    if ( !pImage )
      return 0;
    v5 = (ATLSTRINGRESOURCEIMAGE *)((char *)pImage + SizeofResource(hModule, hResInfo));
    iIndex = id & 0xF;
    if ( id & 0xF )
    {
      while ( pImage < v5 )
      {
        // pImage = (const ATLSTRINGRESOURCEIMAGE*)(LPBYTE( pImage )+(sizeof( ATLSTRINGRESOURCEIMAGE )+(pImage->nLength*sizeof( WCHAR ))));
        pImage = (ATLSTRINGRESOURCEIMAGE *)((char *)pImage + 2 * pImage->nLength + 2);
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

//----- (00C1C750) --------------------------------------------------------
void __stdcall sub_C1C750(void *a1)
{
  sub_C11430((std__List *)a1 + 2);
  operator delete(a1);
}
