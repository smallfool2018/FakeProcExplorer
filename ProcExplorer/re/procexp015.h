
//----- (0102DB50) --------------------------------------------------------
void __cdecl sub_102DB50(EVENT_TRACE *EventTrace, EventList *a2)
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
          sub_102DCE0(EventTrace, a2);
      }
      else
      {
        sub_102E310(EventTrace, a2);
      }
    }
    else
    {
      sub_102D510(EventTrace, a2);
    }
  }
}
// 10A0730: using guessed type wchar_t aDiskio[7];
// 10A0740: using guessed type wchar_t aTcpip[6];
// 10A074C: using guessed type wchar_t aUdpip[6];
// 10A0758: using guessed type wchar_t aMsntTcpipinfor[22];

//----- (0102DCE0) --------------------------------------------------------
void __cdecl sub_102DCE0(EVENT_TRACE *EventTrace, EventList *a2)
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
              v38 = &sub_102CC70(v15, v13->MofData + v13->MofLength, v17, &psz, 0x400u)[v15];
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
    sub_1055310(&v43);
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

//----- (0102E310) --------------------------------------------------------
int **__cdecl sub_102E310(int a1, int a2)
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
      sub_102E560(&gThreadProcessMap, &a2a, &v22);
      result = sub_1055510(&gThreadProcessMap, &a2, a2a, a4);
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
                 byte_10CA100);
    }
  }
  return result;
}
// 10A06F4: using guessed type wchar_t aEnd[4];
// 10CA100: using guessed type char byte_10CA100;

//----- (0102E4E0) --------------------------------------------------------
int __cdecl sub_102E4E0(int a1, PSID Sid)
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

//----- (0102E560) --------------------------------------------------------
_DWORD *__thiscall sub_102E560(int *this, _DWORD *a2, unsigned int *a3)
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

//----- (0102E5E0) --------------------------------------------------------
void __stdcall sub_102E5E0(CSystemProcessInfoMapNode *a1)
{
  CSystemProcessInfoMapNode *v1; // edi
  CSystemProcessInfoMapNode *i; // esi

  v1 = a1;
  for ( i = a1; !i->baseclass._isnil; v1 = i )
  {
    sub_102E5E0(i->baseclass._Right);
    i = i->baseclass._Left;
    j__free(v1);
  }
}

//----- (0102E620) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_102E620(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // edi
  std_Tree_node_for_tagKeyName *v2; // ebx
  std_Tree_node_for_tagKeyName *i; // esi
  CSystemProcessInfoMapNode *result; // eax

  v1 = this;
  v2 = this->_Header->_Parent;
  for ( i = v2; !i->_IsNil; v2 = i )
  {
    sub_102E5E0(i->_Right);
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

//----- (0102E670) --------------------------------------------------------
_DWORD *__thiscall sub_102E670(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  *this = a2;
  this[3] = a3;
  this[1] = a4;
  this[4] = a5;
  this[6] = a6;
  return this;
}

//----- (0102E6A0) --------------------------------------------------------
wchar_t **__thiscall sub_102E6A0(int **this, wchar_t *a2)
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
  if ( *v4 && ((v8 = sub_1012D20(this[4], v4[1]), !v2[6]) ? (v5 = **v2) : (v5 = 0), (v6 = operator new(0x10u)) != 0) )
    result = sub_102EC40(v6, v8, v4[7], *v2 + v4[9] + v5, v4[8]);
  else
LABEL_13:
    result = 0;
  return result;
}

//----- (0102E760) --------------------------------------------------------
wchar_t **__thiscall sub_102E760(PerformanceInfo **this, LPCWSTR lpsz)
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
  lpsza = sub_1012D20(v2[4], v5->m_LastCounterOfLastHelp);
  v7 = v2[6] ? 0 : (*v2)->m_dwLastCounterOfLastHelp;
  v8 = operator new(0x10u);
  if ( v8 )
    result = sub_102EC40(
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

//----- (0102E830) --------------------------------------------------------
wchar_t **__thiscall sub_102E830(int this)
{
  *(this + 8) = 0;
  return sub_102E6A0(this, 0);
}

//----- (0102E840) --------------------------------------------------------
wchar_t **__thiscall sub_102E840(int this)
{
  return sub_102E6A0(this, ++*(this + 8));
}

//----- (0102E850) --------------------------------------------------------
int __thiscall sub_102E850(int *this, wchar_t *Dst, rsize_t SizeInWords)
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

//----- (0102E8B0) --------------------------------------------------------
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
  pszText = sub_102EFA0(v2->m_PerfInfoInMemory);
  v4 = 0;
  if ( !sub_102EF90(v2->m_PerfInfoInMemory) )
    goto LABEL_5;
  while ( *(pszText + 3) != index )
  {
    ++v4;
    pszText = (pszText + *pszText);
    if ( v4 >= sub_102EF90(v2->m_PerfInfoInMemory) )
      goto LABEL_5;
  }
  pItem = operator new(0x10u);
  if ( pItem )
    result = sub_102ED40(pItem, pszText, v2->m_PerfInfo);
  else
LABEL_5:
    result = 0;
  return result;
}

//----- (0102E970) --------------------------------------------------------
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
  *lpBaseAddress = 0;
  *pTimeDateStamp = 0;
  bRet = 0;
  *pbRet = 0;
  hFile = CreateFileW(lpFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0x80u, 0);
  FileHandle = hFile;
  hFileHandle = hFile;
  if ( hFile == -1 )
    return 0;
  hMapping = CreateFileMappingW(hFile, 0, PAGE_READONLY, 0, 0, 0);
  hObjecta = hMapping;
  if ( !hMapping )
  {
    CloseHandle(FileHandle);
    return 0;
  }
  pImageBase = MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);
  lpBaseAddressa = pImageBase;
  if ( !pImageBase )
  {
    CloseHandle(hObjecta);
    CloseHandle(hFileHandle);
    return 0;
  }
  if ( pImageBase->e_magic == 0x5A4D )
  {
    pImageNtHeaders = (pImageBase + pImageBase->e_lfanew);
    if ( pImageNtHeaders->FileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE
      && (Machine = pImageNtHeaders->FileHeader.Machine, Machine != IMAGE_FILE_MACHINE_AMD64)
      && Machine != IMAGE_FILE_MACHINE_IA64 )
    {
      *pnRet = 1;
    }
    else
    {
      *pnRet = 2;
    }
    *pTimeDateStamp = pImageNtHeaders->FileHeader.TimeDateStamp;
    *pDllCharacteristics = pImageNtHeaders->OptionalHeader.DllCharacteristics | IMAGE_FILE_RELOCS_STRIPPED;
    if ( *pnRet == 2 )
    {
      pImageNtHeaders2 = (lpBaseAddressa + lpBaseAddressa->e_lfanew);
      if ( IsBadReadPtr(lpBaseAddressa + lpBaseAddressa->e_lfanew, 0x108u) )
        goto __quit;
      if ( pImageNtHeaders2->Signature != 0x4550 )
        goto __quit;
      // &(pImageSectionHeaders)->SizeOfRawData
      pItem = &pImageNtHeaders2[1].FileHeader.NumberOfSymbols;
      dwSectionIndex = 1;
      NumberOfSections = pImageNtHeaders2->FileHeader.NumberOfSections;
      if ( NumberOfSections < 1 )
        goto __quit;
      while ( 1 )
      {
        if ( !*&pItem->NumberOfRelocations
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
        pItem = (pItem + sizeof(_IMAGE_SECTION_HEADER));
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
      pSectionHeader = &pImageNtHeaders[1];
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
        if ( *pSectionHeader->Name == 'xet.' && *&pSectionHeader->Name[4] == 't' )
        {
          PhysicalAddress_1 = pSectionHeader->Misc.PhysicalAddress;
          if ( PhysicalAddress_1 > 4096 && pSectionHeader->SizeOfRawData < PhysicalAddress_1 - 4096 )
            break;
        }
        if ( !pSectionHeader->Name[0] && pSectionHeader->SizeOfRawData < pSectionHeader->Misc.PhysicalAddress
          || !pSectionHeader->SizeOfRawData
          && pSectionHeader->Misc.PhysicalAddress >= 4096
          && (*pSectionHeader->Name != 0x7865742E || *&pSectionHeader->Name[4] != 0x73736274)
          && (*pSectionHeader->Name != 0x736C742E || *&pSectionHeader->Name[4])
          && (*pSectionHeader->Name != 0x7373622E || *&pSectionHeader->Name[4])
          && (*pSectionHeader->Name != 0x7461642E || *&pSectionHeader->Name[4] != 0x61)
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
// 102EB17: CONTAINING_RECORD: no field 'FAKE_IMAGE_SECTION_HEADER_ITEM *' in struct '_IMAGE_SECTION_HEADER' at 40

//----- (0102EC40) --------------------------------------------------------
wchar_t **__thiscall sub_102EC40(wchar_t **this, wchar_t *a2, int a3, void *a4, unsigned int a5)
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

//----- (0102EC80) --------------------------------------------------------
void __thiscall sub_102EC80(void **this)
{
  void **v1; // esi

  v1 = this;
  free(*this);
  j_j__free(v1[2]);
}

//----- (0102ECA0) --------------------------------------------------------
signed int __thiscall sub_102ECA0(int this, _DWORD *a2, int a3)
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

//----- (0102ED40) --------------------------------------------------------
PE_PerfInfo_Item *__thiscall sub_102ED40(PE_PerfInfo_Item *this, int a2, PerformanceInfo *a3)
{
  this->m_Text = a2;
  this->m_PerfInfo = a3;
  return this;
}

//----- (0102ED60) --------------------------------------------------------
_DWORD *__thiscall sub_102ED60(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // ecx
  _DWORD *v3; // edi
  _DWORD *result; // eax

  v1 = this;
  v2 = *this;
  v1[1] = 0;
  if ( *(v2 + 40) && (v1[2] = v2 + *(v2 + 4), (v3 = operator new(0x1Cu)) != 0) )
    result = sub_102E670(v3, v1[2], *v1 + *(*v1 + 8), *(*v1 + 32), v1[3], *(*v1 + 40) == -1);
  else
    result = 0;
  return result;
}

//----- (0102EE00) --------------------------------------------------------
_DWORD *__thiscall sub_102EE00(_DWORD *this)
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
    result = sub_102E670(v4, v1[2], *v1 + *(*v1 + 8), *(*v1 + 32), v1[3], 0);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0102EEA0) --------------------------------------------------------
PerformanceInfoInMemory *__thiscall PE_PerfInfo::PE_PerfInfo(PerformanceInfoInMemory *this, PerformanceInfo *a2)
{
  PerformanceInfoInMemory *result; // eax

  this->m_PerfInfo = a2;
  result = this;
  this->m_pBuffer = 0;
  return result;
}

//----- (0102EEC0) --------------------------------------------------------
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
// 10A0800: using guessed type wchar_t aU_0[4];

//----- (0102EF90) --------------------------------------------------------
int __thiscall sub_102EF90(PerformanceInfoInMemory *this)
{
  int result; // eax

  if ( this->m_pBuffer )
    result = *(this->m_pBuffer + 7);
  else
    result = 0;
  return result;
}

//----- (0102EFA0) --------------------------------------------------------
WCHAR *__thiscall sub_102EFA0(PerformanceInfoInMemory *this)
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

//----- (0102EFB0) --------------------------------------------------------
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

//----- (0102F110) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7FD(int _8, int a2, int a3, void *a1)
{
  TreeViewListItemParam_Release(a1);
  return 0;
}

//----- (0102F130) --------------------------------------------------------
int __cdecl CMainWnd::HandleDeviceChange(HWND a1, unsigned int a2, unsigned int wParam, _DEV_BROADCAST_HDR *lParam)
{
  if ( wParam == DBT_DEVICEARRIVAL && lParam->dbch_devicetype == DBT_DEVTYP_VOLUME )
    GetDriverNameAndLinkInfo();
  return 0;
}

//----- (0102F150) --------------------------------------------------------
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
          sub_101FAA0(0x65);
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
              sub_101FAA0(0x68);
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
      sub_101FAA0(0x65);
    }
    else if ( IsColumnIDValid(ghWndTreeListView, 0x686u) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
    if ( IsWindowVisible(ghWndDllsListCtrl) )
    {
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
      sub_101FAA0(0x68);
    }
  }
  return 0;
}

//----- (0102F350) --------------------------------------------------------
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
// 10A2088: using guessed type wchar_t aErrorOpeningPr[22];
// 10A20E4: using guessed type wchar_t aDmp_0[6];
// 10A20F0: using guessed type wchar_t aDumpFileDmp[18];
// 10A2140: using guessed type wchar_t aErrorCreatingD[25];
// 10A2174: using guessed type wchar_t aErrorWritingDu[24];

//----- (0102F670) --------------------------------------------------------
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
  if ( !sub_1058030(*(v2 + 60), *(v2 + 68)) )
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
// 10A2394: using guessed type wchar_t aErrorRestartin[25];

//----- (0102F820) --------------------------------------------------------
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
      sub_1058140(*(v8 + 60), *(v8 + 68));
      SetEvent(ghRefreshEventHandle);
      v4 = 2;
      v3 = 2;
      SendMessageW(ghWndTreeListView, 0x102Bu, 0, &v2);
      return 0;
    }
  }
  return 0;
}

//----- (0102F8F0) --------------------------------------------------------
int __cdecl Command_Exit(HWND hWnd)
{
  DestroyWindow(hWnd);
  return 0;
}

//----- (0102F900) --------------------------------------------------------
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
// 10CA389: using guessed type char gbMainWndMinimized;
// 10CA393: using guessed type char gbMainWndMinimized1;

//----- (0102F980) --------------------------------------------------------
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
              wcscpy_s(&Dst, 0x800u, lvitem_1.lParam->szProcessName2);
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

//----- (0102FBD0) --------------------------------------------------------
int Command_RefreshNow()
{
  SetEvent(ghTimerRefreshEvent);
  return 0;
}

//----- (0102FBE0) --------------------------------------------------------
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
// 10A1188: using guessed type wchar_t aProccolumns[12];
// 10A11A0: using guessed type wchar_t aProcessImage[14];
// 10A11BC: using guessed type wchar_t aProcperfcolumn[16];
// 10A11DC: using guessed type wchar_t aProcessPerform[20];
// 10A1204: using guessed type wchar_t aProciocolumns[14];
// 10A1220: using guessed type wchar_t aProcessIO[12];
// 10A1238: using guessed type wchar_t aProcnetworkcol[19];
// 10A1260: using guessed type wchar_t aProcessNetwork[16];
// 10A1280: using guessed type wchar_t aProcdiskcolumn[16];
// 10A12A0: using guessed type wchar_t aProcessDisk[13];
// 10A12BC: using guessed type wchar_t aProcmemcolumns[15];
// 10A12DC: using guessed type wchar_t aProcessMemory[15];
// 10A12FC: using guessed type wchar_t aProcgpucolumns[15];
// 10A131C: using guessed type wchar_t aProcessGpu[12];
// 10A1334: using guessed type wchar_t aHandlecolumns_0[14];
// 10A1350: using guessed type wchar_t aHandle[7];
// 10A1360: using guessed type wchar_t aDllcolumns_0[11];
// 10A1380: using guessed type wchar_t aNetcolumns[11];
// 10A1398: using guessed type wchar_t aNet[5];
// 10A13A4: using guessed type wchar_t aStatusbarcolum_0[17];
// 10A13C8: using guessed type wchar_t aStatusBar[11];
// 10CA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 1030037: user specified stroff has not been processed: PROPSHEETHEADERW offset 52

//----- (01030150) --------------------------------------------------------
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
  CheckMenuItem(v1, 0x9C4Bu, 8u);
  v2 = 0;
  if ( !gConfig.bShowDllView )
    v2 = 8;
  v3 = v2;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C46u, v3);
  v5 = 1;
  if ( gConfig.bShowDllView )
    v5 = 4;
  PostMessageW(ghWndToolbar, 0x42Bu, 0x9C5Eu, v5);
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
  v11 = SendMessageW(ghWndDllsListCtrl, 0x100Cu, 0xFFFFFFFF, 2);
  UpdateMenuStatus(v11 != -1, 5);
  DrawMenuBar(ghMainWnd);
  if ( !gConfig.bShowLowerPane )
    Command_ShowLowerPane(ghMainWnd);
  return 0;
}

//----- (010302B0) --------------------------------------------------------
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
  CheckMenuItem(v1, 0x9C4Bu, 0);
  v2 = 0;
  if ( !gConfig.bShowDllView )
    v2 = 8;
  v3 = v2;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C46u, v3);
  v5 = 1;
  if ( gConfig.bShowDllView )
    v5 = 4;
  PostMessageW(ghWndToolbar, 0x42Bu, 0x9C5Eu, v5);
  PostMessageW(ghWndToolbar, 0x401u, 0x9C47u, gConfig.bShowDllView == 0);
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
  v9 = ghHandleMenuPopup;
  v10 = GetMenu(ghMainWnd);
  InsertMenuW(v10, 5u, 0x410u, v9, L"H&andle");
  v11 = SendMessageW(ghWndHandlesListCtrl, 0x100Cu, 0xFFFFFFFF, 2);
  UpdateMenuStatus(v11 != -1, 5);
  DrawMenuBar(ghMainWnd);
  if ( !gConfig.bShowLowerPane )
LABEL_17:
    Command_ShowLowerPane(ghMainWnd);
  return 0;
}

//----- (01030430) --------------------------------------------------------
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

//----- (01030480) --------------------------------------------------------
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

//----- (01030500) --------------------------------------------------------
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

//----- (01030550) --------------------------------------------------------
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

//----- (010305A0) --------------------------------------------------------
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
  if ( !Fake_HtmlHelp(a1, &Filename, 0, 0) )
  {
    SetLastError(0);
    ReportMsg(L"Unable to open help file", ghMainWnd);
  }
  return 0;
}
// 10A1864: using guessed type wchar_t aUnableToOpenHe[25];

//----- (01030660) --------------------------------------------------------
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
    if ( SendMessageW(v2, 0x104Bu, 0, &lParam) )
    {
      if ( v2 == ghWndTreeListView )
      {
        v5 = *(v11 + 60);
      }
      else
      {
        v6 = v11;
        if ( *(v11 + 44) & 8 )
        {
          MessageBoxW(
            ghWndTreeListView,
            L"Search not supported on pagefile-backed sections",
            L"Process Explorer Error",
            0x10u);
          return 0;
        }
        if ( wcsrchr(*(v11 + 344), 0x5Cu) )
          v5 = wcsrchr(*(v6 + 344), 0x5Cu) + 1;
        else
          v5 = *(v6 + 344);
      }
      LaunchWebBrowser(hWnd, 1, v5);
    }
  }
  return 0;
}

//----- (01030770) --------------------------------------------------------
int __cdecl Command_FindInProcess(HWND a1, __int16 nID)
{
  byte_10BE104 = nID == 40062;
  if ( ghFindDlg )
  {
    ShowWindow(ghFindDlg, 5);
    SetFocus(ghFindDlg);
  }
  else
  {
    ghFindDlg = CreateDialogParamW(ghInstance, L"FINDDIALOG", ghMainWnd, DlgFind, ghFindDlg);
  }
  return 0;
}
// 10BE104: using guessed type char byte_10BE104;

//----- (010307D0) --------------------------------------------------------
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
// 10CA38B: using guessed type char gbWindowFinding;

//----- (01030830) --------------------------------------------------------
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
  v3 = malloc(4u);
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

//----- (010308C0) --------------------------------------------------------
int __cdecl Command_Font(HWND hWnd)
{
  PE_SelectFont(hWnd);
  return 0;
}

//----- (010308E0) --------------------------------------------------------
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
    if ( SendMessageW(v0, LVM_GETITEMW, 0, &ItemInfo) )
    {
      InterlockedIncrement(&ItemInfo.lParam->field_0);
      ItemInfo.lParam->dwProcessId = gdwProcessIdSelected;
      _beginthread(PropertiesThreadProc, 0, ItemInfo.lParam);
    }
  }
  return 0;
}

//----- (01030970) --------------------------------------------------------
int __cdecl sub_1030970(int a1, __int16 a2)
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
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &ItemInfo) )
    {
      v2 = ItemInfo.lParam;
      if ( a2 == 40087 )
      {
        if ( ItemInfo.lParam->dwStyle & 4 )
        {
          ItemInfo2.stateMask = 3;
          ++ItemInfo.iItem;
          ItemInfo2.state = 3;
          SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, ItemInfo.iItem, &ItemInfo2);
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
          FindInfo.lParam = FindInfoParam;
          FindInfo.flags = 1;
          ItemInfo.iItem = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
          ItemInfo2.stateMask = 3;
          ItemInfo2.state = 3;
          SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, ItemInfo.iItem, &ItemInfo2);
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
      sub_1018DA0(v2);
      goto LABEL_20;
    }
  }
  return 0;
}

//----- (01030B10) --------------------------------------------------------
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

//----- (01030B60) --------------------------------------------------------
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

//----- (01030BC0) --------------------------------------------------------
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
  if ( !SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &ItemInfo) )
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
  gpHiddenProcesses = realloc(gpHiddenProcesses, 4 * v5 + 8);
  gpHiddenProcesses[v5] = _wcsdup(i->szProcessName2);
  gpHiddenProcesses[v5 + 1] = 0;
  SetEvent(ghTimerRefreshEvent);
  v6 = GetMenu(ghMainWnd);
  EnableMenuItem(v6, IDM_VIEW_SHOW_HIDDEN_PROCESSES, 0);
  SaveHiddenProcessesToRegistry();
  return 0;
}

//----- (01030D80) --------------------------------------------------------
int __cdecl Command_DifferenceHiliteDuration(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"DIFFDURATION", hWndParent, DialogFunc, 0);
  return 0;
}

//----- (01030DB0) --------------------------------------------------------
int Command_Save()
{
  sub_105E3B0(0);
  return 0;
}

//----- (01030DC0) --------------------------------------------------------
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
    if ( SendMessageW(v1, 0x104Bu, 0, &lParam) )
    {
      if ( v1 == ghWndTreeListView )
      {
        v3 = OpenProcess(0x600u, 0, *(v9 + 68));
        v4 = v3;
        if ( !v3 )
        {
          ReportMsg(L"Unable to set process affinity", ghMainWnd);
          return 0;
        }
        DialogBoxParamW(ghInstance, L"CPUAFFINITY", hWndParent, sub_105EDC0, v3);
        CloseHandle(v4);
      }
    }
  }
  return 0;
}
// 10A141C: using guessed type wchar_t aUnableToSetPro[31];

//----- (01030E90) --------------------------------------------------------
int Command_SaveAs()
{
  sub_105E3B0(1);
  return 0;
}

//----- (01030EA0) --------------------------------------------------------
int Command_CloseHandle()
{
  HWND v0; // esi
  LRESULT v1; // eax
  _DWORD *v2; // esi
  LPARAM v4; // [esp+8h] [ebp-78h]
  int v5; // [esp+14h] [ebp-6Ch]
  int v6; // [esp+18h] [ebp-68h]
  LPARAM lParam; // [esp+3Ch] [ebp-44h]
  LRESULT v8; // [esp+40h] [ebp-40h]
  int v9; // [esp+44h] [ebp-3Ch]
  _DWORD *v10; // [esp+5Ch] [ebp-24h]
  int InBuffer; // [esp+70h] [ebp-10h]
  int v12; // [esp+74h] [ebp-Ch]
  int v13; // [esp+7Ch] [ebp-4h]

  lParam = 0;
  memset(&v8, 0, 0x30u);
  v0 = GetFocus();
  if ( v0 == ghWndDllsListCtrl )
    v0 = ghWndTreeListView;
  v1 = SendMessageW(v0, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v1 == -1 )
  {
    if ( v0 == ghWndTreeListView )
    {
      MessageBoxW(ghWndTreeListView, L"No process selected", L"Process Explorer Error", 0x10u);
      return 0;
    }
    if ( v0 == ghWndHandlesListCtrl )
    {
      MessageBoxW(ghWndTreeListView, L"No handle selected", L"Process Explorer Error", 0x10u);
      return 0;
    }
    MessageBoxW(ghWndTreeListView, L"No handle or process selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  v8 = v1;
  v9 = 0;
  lParam = 4;
  if ( !SendMessageW(v0, 0x104Bu, 0, &lParam) )
    return 0;
  if ( v0 == ghWndTreeListView || v0 == ghWndDllsListCtrl )
  {
    if ( sub_1058030(v10[15], v10[17]) )
    {
      SetEvent(ghRefreshEventHandle);
      v6 = 3;
      v5 = 3;
      SendMessageW(ghWndTreeListView, 0x102Bu, v8 - 1, &v4);
      return 0;
    }
    return 0;
  }
  if ( v0 != ghWndHandlesListCtrl )
    return 0;
  v2 = v10;
  if ( !IsBuiltinAdministrative() )
  {
    MessageBoxW(
      ghWndHandlesListCtrl,
      L"Closing handles requires administrative rights.",
      L"Process Explorer Error",
      0x10u);
    return 0;
  }
  if ( !v2[9] )
  {
    MessageBoxW(
      ghWndHandlesListCtrl,
      L"Handles in the Idle process cannot be closed.",
      L"Process Explorer Error",
      0x10u);
    return 0;
  }
  if ( gConfig.bConfirmKill
    && MessageBoxW(
         ghWndHandlesListCtrl,
         L"Forcing a handle closed can lead to an application crash and system instability.\nContinue with close?",
         L"Process Explorer Warning",
         0x34u) != 6 )
  {
    return 0;
  }
  v13 = v2[11];
  InBuffer = v2[9];
  v12 = v2[10];
  if ( CDriver::Control(0x83350004, &InBuffer, 0x10u, 0, 0) )
  {
    SetEvent(ghRefreshEventHandle);
    v6 = 3;
    v5 = 3;
    SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, v8 - 1, &v4);
    SetFocus(ghWndHandlesListCtrl);
  }
  else
  {
    ReportMsg(L"Error opening process", ghMainWnd);
  }
  return 0;
}
// 10A2088: using guessed type wchar_t aErrorOpeningPr[22];

//----- (010310F0) --------------------------------------------------------
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
    && (Item.iItem = nItem, Item.iSubItem = 0, Item.mask = 4, SendMessageW(hWndTreeListView, LVM_GETITEMW, 0, &Item))
    && (pItemParam = Item.lParam, SetFocus(ghWndTreeListView), pItemParam) )
  {
    if ( PE_SuspendProcess(~(pItemParam->dwStyle >> 7) & 1, pItemParam->dwProcessId, &bRet) )
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
// 109E398: using guessed type wchar_t aREsume[8];
// 10A2024: using guessed type wchar_t aUnableToSuspen[30];

//----- (01031230) --------------------------------------------------------
int __cdecl Command_ShowLowerPane(HWND a1)
{
  HMENU v1; // ebx
  UINT v2; // ecx
  bool v3; // zf
  HMENU v4; // eax
  HWND v6; // edi
  LRESULT v7; // eax
  const WCHAR *v8; // eax
  UINT_PTR v9; // eax
  LRESULT v10; // eax
  const WCHAR *v11; // [esp-4h] [ebp-24h]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v1 = GetMenu(ghMainWnd);
  v2 = 0;
  v3 = gConfig.bShowLowerPane != 0;
  gConfig.bShowLowerPane = gConfig.bShowLowerPane == 0;
  if ( !v3 )
    v2 = 8;
  CheckMenuItem(v1, 0x9C6Eu, v2);
  SendMessageW(ghWndToolbar, 0x42Bu, 0x9C6Eu, (gConfig.bShowLowerPane != 0) + 9);
  InvalidateRect(ghWndToolbar, 0, 1);
  GetClientRect(ghMainWnd, &Rect);
  if ( gConfig.bShowLowerPane )
  {
    gConfig.dbDivider = gConfig.dbSavedDivider;
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
    v6 = ghWndHandlesListCtrl;
    if ( gConfig.bShowDllView )
      v6 = ghWndDllsListCtrl;
    v7 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
    SendMessageW(ghWndTreeListView, 0x1013u, v7, 0);
    ShowWindow(v6, 5);
    if ( a1 )
      SetEvent(ghRefreshEventHandle);
    v8 = L"&DLL";
    if ( !gConfig.bShowDllView )
      v8 = L"H&andle";
    v11 = v8;
    v9 = ghHandleMenuPopup;
    if ( gConfig.bShowDllView )
      v9 = ghDllMenuPopup;
    InsertMenuW(v1, 5u, 0x410u, v9, v11);
    DrawMenuBar(ghMainWnd);
    v10 = SendMessageW(v6, 0x100Cu, 0xFFFFFFFF, 2);
    UpdateMenuStatus(v10 != -1, 5);
  }
  else if ( IsWindowVisible(ghWndHandlesListCtrl) || IsWindowVisible(ghWndDllsListCtrl) )
  {
    ShowWindow(ghWndHandlesListCtrl, 0);
    ShowWindow(ghWndDllsListCtrl, 0);
    v4 = GetMenu(ghMainWnd);
    RemoveMenu(v4, 5u, 0x400u);
    DrawMenuBar(ghMainWnd);
    gConfig.dbSavedDivider = gConfig.dbDivider;
    gConfig.dbDivider = db_one;
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
    return 0;
  }
  return 0;
}

//----- (01031490) --------------------------------------------------------
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
  if ( !SendMessageW(hWnd, LVM_GETITEMW, 0, &ItemInfo) )
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
    if ( *&ItemInfo.lParam->gap154[4] )
    {
      InterlockedIncrement(&ItemInfo.lParam->field_0);
      v4->dwStyle = gdwProcessIdSelected;
      _beginthread(PropertiesThreadProc, 0, v4);
      return 0;
    }
    return 0;
  }
  if ( hWnd == ghWndHandlesListCtrl )
    FillHandleListParam(hWnd, ItemInfo.lParam);
  else
    CTreeList::FillTreeViewParam(ItemInfo.lParam);
  return 0;
}

//----- (01031620) --------------------------------------------------------
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
    if ( gConfig.dwRefreshRate > 2000 )
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
  if ( a2 == -25518 && !gConfig.dwRefreshRate )
  {
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, &gszNullString);
    v4 = gdwRefreshMenuIDLast;
    if ( gdwRefreshMenuIDLast == -1 )
      v4 = 1000;
    v3 = v4;
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
  v3 = v3;
  switch ( v3 )
  {
    case 0x9C52u:
      gConfig.dwRefreshRate = 0;
      SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, L"Paused");
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
  if ( a2 != -25518 )
  {
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, &gszNullString);
    SetEvent(ghRefreshEventHandle);
    gdwRefreshMenuIDLast = v3;
  }
  return 0;
}
// 10A0D80: using guessed type wchar_t aPaused[7];
// 10BE10C: using guessed type int gdwRefreshMenuIDLast;
// 10E5720: using guessed type int gnStatusBarItemCount;

//----- (01031850) --------------------------------------------------------
int OnProcessProperties()
{
  tagHwndID hWndTreeListView[4]; // [esp+0h] [ebp-2Ch]
  __int64 v2; // [esp+24h] [ebp-8h]

  hWndTreeListView[0].hWnd = ghWndTreeListView;
  _mm_storeu_si128(&hWndTreeListView[0].nID, 0i64);
  gConfig.bShowProcessTree = 0;
  gConfig.bProcessSortDirection = 0;
  _mm_storeu_si128(&hWndTreeListView[2].nID, 0i64);
  hWndTreeListView[0].nID = IDC_TREEVIEW_LIST;
  v2 = 0i64;
  hWndTreeListView[2].hWnd = 0;
  PE_ShowProcessTree(101u, hWndTreeListView);
  return 0;
}

//----- (010318A0) --------------------------------------------------------
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
  if ( !SendMessageW(v3, 0x104Bu, 0, &lParam) || v3 != ghWndTreeListView )
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
  v8 = OpenProcess(0x200u, 0, *(v18 + 68));
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
      *(v18 + 1368) = v5;
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
// 10318A0: could not find valid save-restore pair for edi
// 10CB1C8: using guessed type int (__stdcall *NtSetInformationProcess)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (01031AD0) --------------------------------------------------------
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

//----- (01031B20) --------------------------------------------------------
int __cdecl Command_Run(HWND hWndParent, int a2)
{
  HMODULE v2; // eax
  FARPROC v3; // eax

  v2 = LoadLibraryW(L"shell32.dll");
  v3 = GetProcAddress(v2, 0x3D);
  dword_10CA8D8 = v3;
  if ( v3 )
    (v3)(hWndParent, 0, 0, 0, 0, 0);
  else
    DialogBoxParamW(ghInstance, L"RUNDLG", hWndParent, sub_1037F60, a2);
  return 0;
}
// 10CA8D8: using guessed type int dword_10CA8D8;

//----- (01031B80) --------------------------------------------------------
int __cdecl Command_RunAs(HWND hWndParent, int a2)
{
  DialogBoxParamW(ghInstance, L"RUNDLG", hWndParent, sub_1037F60, a2);
  return 0;
}

//----- (01031BB0) --------------------------------------------------------
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

//----- (01031C40) --------------------------------------------------------
int __cdecl OpacityOptions_Update(HWND hWnd, int a2)
{
  UINT v2; // ST08_4
  HMENU v3; // eax
  LONG v4; // eax
  UINT v5; // ST08_4
  HMENU v6; // eax

  v2 = (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 2) + (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 31) + 40093;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, v2, 0);
  gConfig.dwOpacity = 10 * (a2 - 40093);
  v4 = GetWindowLongW(ghMainWnd, -20);
  if ( gConfig.dwOpacity == 100 )
  {
    SetWindowLongW(ghMainWnd, -20, v4 & 0xFFF7FFFF);
  }
  else
  {
    SetWindowLongW(ghMainWnd, -20, v4 | 0x80000);
    SetLayeredWindowAttributes(ghMainWnd, 0, (255 * gConfig.dwOpacity) / 100, 2u);
  }
  RedrawWindow(ghMainWnd, 0, 0, 0x485u);
  v5 = (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 2) + (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 31) + 40093;
  v6 = GetMenu(hWnd);
  CheckMenuItem(v6, v5, 8u);
  return 0;
}

//----- (01031D40) --------------------------------------------------------
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
        if ( ExitWindowsEx(8u, 0) )
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
// 10A1C74: using guessed type wchar_t aShutdown[9];
// 10A1C88: using guessed type wchar_t aRestart[8];
// 10A1C98: using guessed type wchar_t aLogoff[7];
// 10A1CA8: using guessed type wchar_t aHibernate[10];
// 10A1CBC: using guessed type wchar_t aStandBy[9];

//----- (01031F10) --------------------------------------------------------
int __cdecl Command_ReplaceTaskManager(HWND hWnd)
{
  HKEY v1; // ecx
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( gdwVersion < 1 || IsBuiltinAdministrative() )
  {
    if ( CanReplaceTaskManager() )
      sub_1025E40(v1);
    else
      ReplaceTaskManager(hWnd, 1);
  }
  else
  {
    sub_1026180(L"/rt", 5, 1);
  }
  v2 = CanReplaceTaskManager() != 0 ? 8 : 0;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, 0x9C7Bu, v2);
  return 0;
}
// 10A16AC: using guessed type wchar_t aRt_0[4];
// 10C4E54: using guessed type int gdwVersion;

//----- (01031F80) --------------------------------------------------------
int __cdecl Command_ConfigSymbols(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"SYMBOLCONFIG", hWndParent, DlgSymbolConfig, 0);
  return 0;
}

//----- (01031FB0) --------------------------------------------------------
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
    v1 = LoadCursorW(0, IDC_WAIT);
    v2 = SetCursor(v1);
    _beginthread(BackendSysInfoPropSheetThreadProc, 0, 0);
    WaitForSingleObject(ghSystemInfoSheetThreadEvent, 0xFFFFFFFF);
    SetCursor(v2);
  }
  return 0;
}

//----- (01032020) --------------------------------------------------------
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

//----- (01032070) --------------------------------------------------------
int __cdecl Command_ConfigColors(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"CHOOSECOLORS", hWndParent, DlgSelectColor, 0);
  return 0;
}

//----- (010320A0) --------------------------------------------------------
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
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &Item) )
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
// 10A25B8: using guessed type wchar_t aUnableToTrimPr[35];

//----- (01032190) --------------------------------------------------------
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
    if ( SendMessageW(v2, 0x104Bu, 0, &lParam) )
    {
      v4 = pItem;
      sub_1026B90(0, a2, pItem->dwProcessId);
      RefreshMenuWithTreeViewItemStatus(v4);
    }
  }
  return 0;
}

//----- (01032210) --------------------------------------------------------
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

//----- (01032260) --------------------------------------------------------
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
    &gConfig.dwProcessColumnCount);
  CTreeList_InsertVerifyColumn(
    ghWndDllsListCtrl,
    IDS_VERIFIED_SIGNER,
    gConfig.dwDllColumnMap,
    &gConfig.dwDllColumnCount);
  v5 = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
  ItemInfo.iItem = 0;
  if ( v5 <= 0 )
    return 0;
  do
  {
    ItemInfo.iSubItem = 0;
    ItemInfo.mask = LVIF_PARAM;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &ItemInfo) )
    {
      v6 = ItemInfo.lParam;
      InterlockedIncrement(&ItemInfo.lParam->nRefCount);
      _beginthread(VerifyImageThreadProc, 0, v6);
    }
    ++ItemInfo.iItem;
  }
  while ( ItemInfo.iItem < v5 );
  return 0;
}

//----- (01032390) --------------------------------------------------------
int __cdecl Command_CheckVirusTotalDotCom(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST0C_4
  HMENU v3; // eax
  BOOL v4; // ST0C_4
  HMENU v5; // eax
  DLLLISTITEMPARAM *v6; // esi
  DLLLISTITEMPARAM *v7; // edi
  int v8; // eax
  DLLLISTITEMPARAM *i; // esi
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
    v6 = gpTreeViewListItemParam;
    v7 = 0;
    CTreeList_InsertVerifyColumn(ghWndTreeListView, 0x686u, gConfig.dwProcessColumnMap, &gConfig.dwProcessColumnCount);
    for ( ; v6; v6 = v6[3].field_118 )
    {
      v8 = v6[2].field_3C;
      if ( v6->field_44 == gdwProcessIdSelected )
        v7 = v6;
      if ( v8 && *(v8 + 4) == 1 )
        *(v8 + 4) = 6;
      if ( v6[2].field_8 )
        sub_1061C30(v6, 1, 0);
    }
    InvalidateRect(ghWndTreeListView, 0, 0);
    CTreeList_InsertVerifyColumn(ghWndDllsListCtrl, 0x686u, gConfig.dwDllColumnMap, &gConfig.dwDllColumnCount);
    if ( v7 && IsWindowVisible(ghWndDllsListCtrl) )
    {
      for ( i = gpDllListItemParamHeader; i; i = i->m_Prev )
      {
        v10 = i->m_HashData;
        if ( v10 && *(v10 + 4) == 1 )
          *(v10 + 4) = 6;
        if ( i->m_strPath.pszData )
          sub_1061C30(i, ~(i->field_2C >> 1) & 1, 0);
      }
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
    }
  }
  return 0;
}

//----- (01032520) --------------------------------------------------------
int __cdecl Command_SubmitUnkownExecutables(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST10_4
  HMENU v4; // eax
  DLLLISTITEMPARAM *v5; // esi
  DLLLISTITEMPARAM *v6; // edi
  int v7; // eax
  DLLLISTITEMPARAM *i; // esi
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
  v5 = gpTreeViewListItemParam;
  v6 = 0;
  if ( gpTreeViewListItemParam )
  {
    do
    {
      v7 = v5[2].field_3C;
      if ( v5->field_44 == gdwProcessIdSelected )
        v6 = v5;
      if ( v7 && *(v7 + 4) == 6 && *v7 )
        sub_1061C30(v5, 1, 1);
      v5 = v5[3].field_118;
    }
    while ( v5 );
  }
  InvalidateRect(ghWndTreeListView, 0, 0);
  if ( v6 && IsWindowVisible(ghWndDllsListCtrl) )
  {
    for ( i = gpDllListItemParamHeader; i; i = i->m_Prev )
    {
      v9 = i->m_HashData;
      if ( v9 && *(v9 + 4) == 6 )
      {
        v10 = i->field_2C >> 1;
        if ( !(v10 & 1) )
          sub_1061C30(i, ~v10 & 1, 1);
      }
    }
    InvalidateRect(ghWndDllsListCtrl, 0, 0);
  }
  return 0;
}

//----- (01032640) --------------------------------------------------------
int Command_CheckVirusTotalDotCom()
{
  HWND v0; // esi
  char v1; // bl
  LRESULT v2; // eax
  DLLLISTITEMPARAM *v3; // esi
  int v4; // eax
  LPARAM lParam; // [esp+8h] [ebp-34h]
  LRESULT v7; // [esp+Ch] [ebp-30h]
  int v8; // [esp+10h] [ebp-2Ch]
  DLLLISTITEMPARAM *pItemParam; // [esp+28h] [ebp-14h]

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
    if ( SendMessageW(v0, 0x104Bu, 0, &lParam) )
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
            &gConfig.dwProcessColumnCount);
          v4 = v3[2].field_3C;
          if ( v4 )
          {
            if ( *(v4 + 4) == 6 )
            {
              v1 = 1;
            }
            else if ( v4 && *(v4 + 4) == 1 )
            {
              *(v4 + 4) = 6;
            }
          }
          sub_1061C30(v3, 1, v1 != 0);
          InvalidateRect(ghWndTreeListView, 0, 0);
        }
      }
    }
  }
  return 0;
}

//----- (01032740) --------------------------------------------------------
int Command_Check_VirusTotalDotCom()
{
  HWND v0; // esi
  char v1; // bl
  LRESULT v2; // eax
  DLLLISTITEMPARAM *v3; // esi
  int v4; // eax
  LPARAM lParam; // [esp+8h] [ebp-34h]
  LRESULT v7; // [esp+Ch] [ebp-30h]
  int v8; // [esp+10h] [ebp-2Ch]
  DLLLISTITEMPARAM *pItemParam; // [esp+28h] [ebp-14h]

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
    if ( SendMessageW(v0, 0x104Bu, 0, &lParam) )
    {
      v3 = pItemParam;
      SetFocus(ghWndTreeListView);
      if ( v3 )
      {
        if ( SubmitExeToVirusTotalDotCom() )
        {
          CTreeList_InsertVerifyColumn(ghWndDllsListCtrl, 0x686u, gConfig.dwDllColumnMap, &gConfig.dwDllColumnCount);
          v4 = v3->m_HashData;
          if ( v4 )
          {
            if ( *(v4 + 4) == 6 )
            {
              v1 = 1;
            }
            else if ( v4 && *(v4 + 4) == 1 )
            {
              *(v4 + 4) = 6;
            }
          }
          sub_1061C30(v3, 1, v1 != 0);
          InvalidateRect(ghWndDllsListCtrl, 0, 0);
        }
      }
    }
  }
  return 0;
}

//----- (01032840) --------------------------------------------------------
int Command_ShowDetailsForAllProcesses()
{
  DWORD v0; // eax

  UpdateWindowPlacement(ghMainWnd, 1);
  CreateEventW(0, 0, 1, L"ProcessExplorerElevating");
  v0 = sub_1026180(gszCmdLine, 5, 0);
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
// 10A1D84: using guessed type wchar_t aErrorElevating[16];
// 10CA38C: using guessed type int gszCmdLine;

//----- (010328B0) --------------------------------------------------------
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
      SetWindowPos(ghWndSysinfoPropSheet, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
  }
  return 0;
}

//----- (01032960) --------------------------------------------------------
int __cdecl Command_ViewCpuHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_10379E0(gConfig.bTrayCPUHistory == 0) )
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

//----- (010329C0) --------------------------------------------------------
int __cdecl Command_ViewIoHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_10379E0(gConfig.bShowIoTray == 0) )
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

//----- (01032A20) --------------------------------------------------------
int __cdecl Command_CommitNetworkHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_10379E0(gConfig.bShowNetTray == 0) )
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

//----- (01032A80) --------------------------------------------------------
int __cdecl Command_CommitDiskHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_10379E0(gConfig.bShowDiskTray == 0) )
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

//----- (01032AE0) --------------------------------------------------------
int __cdecl Command_CommitGPUHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_10379E0(gConfig.bShowGpuHistory == 0) )
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

//----- (01032B40) --------------------------------------------------------
int __usercall Command_RunAtLogon@<eax>(_DWORD *a1@<edi>, HWND hWnd)
{
  bool v2; // al
  UINT v3; // ST08_4
  HMENU v4; // eax
  int savedregs; // [esp+0h] [ebp+0h]

  v2 = IsProcessExplorerRunAtStartup(&savedregs, a1);
  sub_10237F0(v2 == 0);
  v3 = IsProcessExplorerRunAtStartup(&savedregs, a1) != 0 ? 8 : 0;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9F30u, v3);
  return 0;
}

//----- (01032B90) --------------------------------------------------------
int __cdecl Command_ViewCommitHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_10379E0(gConfig.bShowCommitTray == 0) )
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

//----- (01032BF0) --------------------------------------------------------
int __cdecl Command_ViewPhysicalMemoryHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_10379E0(gConfig.bShowPhysTray == 0) )
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

//----- (01032C50) --------------------------------------------------------
signed int __usercall Command_SetColumn@<eax>(double a1@<st0>, double a2@<st1>, HWND hWnd, unsigned __int16 uID)
{
  __int32 index; // esi
  BOOL v6; // ST2C_4
  HMENU v7; // eax
  LRESULT v8; // eax
  char v9; // [esp+0h] [ebp-A0h]
  char v10; // [esp+8h] [ebp-98h]
  int pThis; // [esp+10h] [ebp-90h]
  __int128 v12; // [esp+14h] [ebp-8Ch]
  __int128 v13; // [esp+24h] [ebp-7Ch]
  __int64 v14; // [esp+34h] [ebp-6Ch]
  char v15; // [esp+3Ch] [ebp-64h]
  struct tagRECT Rect; // [esp+8Ch] [ebp-14h]

  index = uID - IDM_PROCESS_PRIORITY_BASE;
  pThis = 0;
  _mm_storeu_si128(&v12, 0i64);
  _mm_storeu_si128(&v13, 0i64);
  v14 = 0i64;
  if ( index >= gConfig.dwNumColumnsets )
    return 1;
  SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  SendMessageW(ghWndHandlesListCtrl, WM_SETREDRAW, 0, 0);
  SendMessageW(ghWndDllsListCtrl, WM_SETREDRAW, 0, 0);
  qmemcpy(gConfig.szColumnSetName, &gConfig.strMenuCulumnSet[index], 0x5F4u);
  sub_1037930(gConfig.szColumnSetName);
  InitListHeader(ghWndTreeListView, gConfig.dwProcessColumnMap, gConfig.dwProcessColumns, gConfig.dwProcessColumnCount);
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
    gConfig.dwHandleSortColumn,
    gConfig.bHandleSortDirection);
  CTreeList::InitHeaderColumn(ghWndDllsListCtrl, 0xFFFFFFFF, gConfig.dwDllSortColumn, gConfig.bDllSortDirection);
  LODWORD(v12) = 101;
  pThis = ghWndTreeListView;
  if ( gConfig.bShowProcessTree )
  {
    gConfig.bShowProcessTree = 0;
    gConfig.bProcessSortDirection = 0;
    HIDWORD(v12) = 0;
  }
  else
  {
    gConfig.bProcessSortDirection = gConfig.bProcessSortDirection == 0;
    HIDWORD(v12) = gConfig.dwProcessSortColumn;
  }
  PE_ShowProcessTree(0x65u, &pThis);
  SendMessageW(ghWndToolbar, 0x401u, 0x9C67u, gConfig.bShowProcessTree == 0);
  v6 = gConfig.bShowProcessTree != 0;
  v7 = GetMenu(ghMainWnd);
  EnableMenuItem(v7, 0x9C67u, v6);
  memset(&v15, 0, 0x50u);
  sub_1060410(a1, a2, 0, &v15, &v9, &v10);
  CMainWnd::InitStatusBar(ghWndStatusBar);
  sub_101FAA0(0x66);
  sub_101FAA0(0x68);
  SendMessageW(ghWndTreeListView, 0xBu, 1u, 0);
  SendMessageW(ghWndHandlesListCtrl, 0xBu, 1u, 0);
  SendMessageW(ghWndDllsListCtrl, 0xBu, 1u, 0);
  v8 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  SendMessageW(ghWndTreeListView, 0x1013u, v8, 0);
  return 0;
}

//----- (01032F00) --------------------------------------------------------
int sub_1032F00()
{
  gConfig.bUseGoogle = 1;
  return 0;
}

//----- (01032F10) --------------------------------------------------------
int sub_1032F10()
{
  gConfig.bUseGoogle = 0;
  return 0;
}

//----- (01032F20) --------------------------------------------------------
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
    if ( SendMessageW(v2, 0x104Bu, 0, &lParam) )
    {
      if ( v2 == ghWndDllsListCtrl )
      {
        if ( *(v11 + 44) & 8 )
        {
          MessageBoxW(
            ghWndTreeListView,
            L"Depends not supported on pagefile-backed sections",
            L"Process Explorer Error",
            0x10u);
          return 0;
        }
        v3 = *(v11 + 344);
        SetFocus(ghWndDllsListCtrl);
      }
      else
      {
        v3 = *(v11 + 792);
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
    sub_10368E0(&CommandLine, L"depends \"%s\"", v3);
    memset(&StartupInfo, 0, 0x44u);
    StartupInfo.dwFlags = 1;
    StartupInfo.cb = 68;
    StartupInfo.wShowWindow = 5;
    _mm_storeu_si128(&ProcessInformation, 0i64);
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
// 10A1F14: using guessed type wchar_t aViewDependenci[18];

//----- (010331A0) --------------------------------------------------------
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
    && (v6 = v2, v7 = 0, lParam = 4, SendMessageW(v0, 0x104Bu, 0, &lParam))
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
  MakeHandlePropSheetCaption(&CommandLine, L"\"%s\" -p %d", gszAeDebuggerPath, *(v1 + 68));
  memset(&StartupInfo, 0, 0x44u);
  StartupInfo.dwFlags = 1;
  StartupInfo.cb = 68;
  StartupInfo.wShowWindow = 5;
  _mm_storeu_si128(&ProcessInformation, 0i64);
  if ( CreateProcessW(0, &CommandLine, 0, 0, 0, 0x200u, 0, 0, &StartupInfo, &ProcessInformation) )
  {
    CloseHandle(ProcessInformation.hThread);
    CloseHandle(ProcessInformation.hProcess);
  }
  return 0;
}

//----- (01033330) --------------------------------------------------------
int __cdecl Command_ShowProcessesForAllUsers(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST0C_4
  HMENU v4; // eax
  tagTREEVIEWLISTITEMPARAM *i; // eax
  int v6; // ecx
  LRESULT v7; // ebx
  void *v8; // edi
  int v9; // esi
  LRESULT k; // edi
  int v11; // esi
  int v12; // eax
  LPARAM lParam; // [esp+Ch] [ebp-38h]
  int v15; // [esp+10h] [ebp-34h]
  int v16; // [esp+14h] [ebp-30h]
  int v17; // [esp+2Ch] [ebp-18h]
  void *j; // [esp+40h] [ebp-4h]

  SendMessageW(ghWndTreeListView, 0xBu, 0, 0);
  v1 = 0;
  v2 = gConfig.bShowAllUsers != 0;
  gConfig.bShowAllUsers = gConfig.bShowAllUsers == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C77u, v3);
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
  {
    if ( gConfig.bShowAllUsers || (v6 = i->dwStyle, v6 & 0x40) )
      i->dwStyle |= 2u;
    else
      i->dwStyle = v6 & 0xFFFFFFFD;
  }
  v7 = SendMessageW(ghWndTreeListView, 0x1004u, 0, 0);
  v8 = operator new[](4 * v7);
  v9 = 0;
  for ( j = v8; v9 < v7; ++v9 )
  {
    v15 = v9;
    v16 = 0;
    lParam = 4;
    SendMessageW(ghWndTreeListView, 0x104Bu, 0, &lParam);
    *(v8 + v9) = v17;
  }
  SendMessageW(ghWndTreeListView, 0x1009u, 0, 0);
  for ( k = 0; k < v7; *(v11 + 1464) = v12 )
  {
    v11 = *(j + k);
    v12 = sub_1017F20(ghWndTreeListView, *(j + k++));
  }
  j_j__free(j);
  byte_10C53B5 = 1;
  SetEvent(ghTimerRefreshEvent);
  return 0;
}
// 10C53B5: using guessed type char byte_10C53B5;

//----- (01033490) --------------------------------------------------------
int __cdecl Command_SaveColumnSet(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"COLUMNSETSAVE", hWndParent, DlgColumnSetSave, 0);
  return 0;
}

//----- (010334C0) --------------------------------------------------------
int __cdecl Command_OrganizeColumnSets(HWND hWnd)
{
  if ( gConfig.dwNumColumnsets )
    DialogBoxParamW(ghInstance, L"COLUMNSETS", hWnd, DlgColumnSets, 0);
  else
    MessageBoxW(
      hWnd,
      L"There are no column sets defined. Use View->Save Column Set to save a column set.",
      L"Process Explorer",
      0x30u);
  return 0;
}

//----- (01033510) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleCommand(HWND hWnd, int a2, WPARAM wParam, LPARAM lParam)
{
  return HandleCmdHandler(&CMainWnd::gCmdHandler, hWnd, wParam, lParam);
}
// 10BE11C: using guessed type struct tagMSGHANDLER CMainWnd::gCmdHandler;

//----- (01033530) --------------------------------------------------------
int __cdecl CMainWnd::HandlePaint(HWND hWnd)
{
  HDC v1; // eax
  struct tagPAINTSTRUCT Paint; // [esp+4h] [ebp-44h]

  v1 = BeginPaint(hWnd, &Paint);
  if ( gConfig.bShowLowerPane )
    DrawEdge(v1, &gRectPane, 5u, 0x80Au);
  EndPaint(hWnd, &Paint);
  return 0;
}

//----- (01033590) --------------------------------------------------------
int __cdecl CMainWnd::HandleSize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int nHeight; // edi
  HWND hWndRebar; // eax
  LONG top; // ebx
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
    nHeight = rcStatusBar.bottom - rcStatusBar.top;
    hWndRebar = GetParent(ghWndCPUGraph);
    GetWindowRect(hWndRebar, &rcReBar);
    GetClientRect(hWnd, &gRectWindow);
    top = (lParam >> 16) - (rcReBar.bottom - rcReBar.top + gRectWindow.top);
    gRectWindow.top += rcReBar.bottom - rcReBar.top;
    gRectWindow.right = lParam;
    gRectWindow.bottom = top;
    InvalidateRect(hWnd, &gRectPane, 0);
    gRectPane.right = lParam;
    gRectPane.top = ((gRectWindow.top + gRectWindow.bottom - nHeight) * gConfig.dbDivider);
    gRectPane.bottom = gRectPane.top + 7;
    MoveWindow(ghWndTreeListView, 0, gRectWindow.top, lParam, gRectPane.top - gRectWindow.top, 1);
    MoveWindow(
      ghWndHandlesListCtrl,
      0,
      gRectPane.bottom - 1,
      lParam,
      gRectWindow.bottom - gRectPane.bottom - nHeight + gRectWindow.top + 1,
      TRUE);
    MoveWindow(
      ghWndDllsListCtrl,
      0,
      gRectPane.bottom - 1,
      lParam,
      gRectWindow.bottom - gRectPane.bottom - nHeight + gRectWindow.top + 1,
      TRUE);
    MoveWindow(ghWndStatusBar, 0, gRectWindow.top + gRectWindow.bottom - nHeight, lParam, nHeight, 1);
    v8 = gnToolbarHeight;
    v9 = gRectWindow.right;
    v10 = GetDlgItem(hWnd, IDC_MAINTOOLBAR);
    MoveWindow(v10, 0, 0, v9, v8, TRUE);
    InvalidateRgn(ghWndStatusBar, 0, FALSE);
    MoveWindow(ghWndReBar, 0, 0, gRectWindow.right - gRectWindow.left, 0, TRUE);
  }
  return 0;
}

//----- (01033780) --------------------------------------------------------
int __cdecl CMainWnd::HandleGetMinmaxInfo(HWND a1, unsigned int a2, unsigned int a3, MINMAXINFO *a4)
{
  a4->ptMinTrackSize.x = 200;
  a4->ptMinTrackSize.y = 200;
  return 0;
}

//----- (010337A0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLBtnDown(HWND hWnd, int a2, int a3, int a4)
{
  POINT v4; // ST04_8

  v4.y = a4 >> 16;
  v4.x = a4;
  if ( PtInRect(&gRectPane, v4) )
  {
    SetCursor(ghResizeCursor);
    SetCapture(hWnd);
    DrawLine(hWnd, (a4 >> 16) - 6);
    gyMouseDown = (a4 >> 16) - 6;
  }
  return 0;
}

//----- (010337F0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLBtnUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  signed int v4; // esi
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v4 = lParam >> 16;
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
    gRectPane.top = v4 - 3;
    gRectPane.bottom = gRectPane.top + 7;
    gConfig.dbDivider = (v4 - 3) / (gRectWindow.top + gRectWindow.bottom);
    GetClientRect(ghMainWnd, &Rect);
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
    InvalidateRect(hWnd, &gRectPane, 0);
  }
  return 0;
}
// 10CA38B: using guessed type char gbWindowFinding;

//----- (01033940) --------------------------------------------------------
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

  y = lParam >> 16;
  if ( gbWindowFinding )
  {
    Point.x = lParam;
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
            v7 = LoadCursorW(ghInstance, 10);
            SetCursor(v7);
            return 0;
          }
          break;
        }
      }
      ghWndHungWindow = 0;
    }
    v9 = LoadCursorW(ghInstance, 0xA);
    SetCursor(v9);
    result = 0;
  }
  else if ( GetCapture() )
  {
    if ( y > gRectWindow.bottom - 5 )
      LOWORD(y) = LOWORD(gRectWindow.bottom) - 5;
    if ( y < gRectWindow.top + 40 )
      LOWORD(y) = LOWORD(gRectWindow.top) + 40;
    DrawLine(hWnd, gyMouseDown);
    v10 = (y - 3);
    DrawLine(hWnd, v10);
    gyMouseDown = v10;
    result = 0;
  }
  else
  {
    v11.y = lParam >> 16;
    v11.x = lParam;
    if ( PtInRect(&gRectPane, v11) )
      SetCursor(ghResizeCursor);
    result = 0;
  }
  return result;
}
// 10CA38B: using guessed type char gbWindowFinding;

//----- (01033AA0) --------------------------------------------------------
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

//----- (01033B70) --------------------------------------------------------
int __cdecl CMainWnd::HandleNotify(HWND hWnd, UINT msg, WPARAM wParam, NMHDR *lParam)
{
  UINT code; // eax
  int v5; // eax
  struct tagPOINT Point; // [esp+4h] [ebp-1Ch]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  code = lParam->code;
  if ( code > LVN_GETDISPINFOW )
  {
    switch ( code )
    {
      case 0xFFFFFF51:
        // LVN_DELETEITEM
        return 1;
      case 0xFFFFFF65:
        return sub_101F490(wParam, lParam);
      case 0xFFFFFF94:
        return PE_ShowProcessTree(wParam, lParam);
      case 0xFFFFFF99:
        return sub_101D4B0(wParam, lParam);
      case 0xFFFFFF9B:
        return sub_101F4D0(wParam);
      case 0xFFFFFFEA:
        if ( wParam == 103 )
          GetButtonSize();
        return 0;
      case 0xFFFFFFFB:
        GetCursorPos(&Point);
        return UpdateListViewContextMenu(wParam, lParam, &Point);
      case 0xFFFFFFFD:
        return FillList(wParam);
      case 0xFFFFFFFE:
        return sub_101CDD0(wParam, lParam);
      default:
        return 0;
    }
  }
  else
  {
    if ( code == LVN_GETDISPINFOW )
      return sub_101D7B0(wParam, lParam);
    if ( code > 0xFFFFFCC1 )
    {
      switch ( code )
      {
        case 0xFFFFFD43:
          if ( lParam[1].hwndFrom == IDM_FIND_PROCESS_BY_WINDOW )
          {
            SearchWindow(hWnd);
            return 0;
          }
          break;
        case 0xFFFFFDEE:
          return GetStringByMenuID(wParam, lParam);
        case 0xFFFFFF4D:
          return sub_101D7A0(wParam);
      }
    }
    else
    {
      if ( code == 0xFFFFFCC1 )
      {
        GetClientRect(ghMainWnd, &Rect);
        CMainWnd::HandleSize(
          ghMainWnd,
          0,
          0,
          (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
        InvalidateRect(ghWndTreeListView, 0, 0);
        return 0;
      }
      if ( code > 0x7D4 )
      {
        if ( code == 2005 )
          return sub_1021C50(wParam, lParam);
        if ( code == -839 )
        {
          InvalidateRect(lParam->hwndFrom, 0, 0);
          return 0;
        }
      }
      else
      {
        if ( code == 2004 )
          return sub_1021B70(wParam, &lParam->hwndFrom);
        v5 = code - 2001;
        if ( !v5 )
          return sub_107F550();
        if ( v5 == 1 )
          return CAboutWnd::HandleInitDialog();
      }
    }
  }
  return 0;
}

//----- (01033F40) --------------------------------------------------------
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
  struct _IMAGELIST *v98; // eax
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
  int (__stdcall *v127)(HWND, RECT *, DWORD, DWORD); // eax
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
  RECT rcTreeList; // [esp+290h] [ebp-A4Ch]
  struct tagRECT rcToolbar; // [esp+2A0h] [ebp-A3Ch]
  wchar_t szUserName[260]; // [esp+2B0h] [ebp-A2Ch]
  wchar_t szMenuItemName[260]; // [esp+4B8h] [ebp-824h]
  __int16 szDomainName[260]; // [esp+6C0h] [ebp-61Ch]
  WCHAR szMainName[260]; // [esp+8C8h] [ebp-414h]
  WCHAR szPathName[260]; // [esp+AD0h] [ebp-20Ch]
  int savedregs; // [esp+CDCh] [ebp+0h]

  hWnd_1 = hWnd;
  _mm_storeu_si128(&rcToolbar, 0i64);
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
  gpfnCreateRestrictedToken = GetProcAddress(v1, "CreateRestrictedToken");
  gbWintrustInited = LoadWintrust();
  v2 = GetProcessDEPStatus();
  ghMainWnd = hWnd;
  gbIsProcessDEPEnabled = v2;
  hMainMenuHandle = ::GetMenu(hWnd);
  v4 = LoadCursorW(0, IDC_WAIT);
  hCursor_____ = SetCursor(v4);
  ghArrowCursor = LoadCursorW(0, IDC_ARROW);
  ghFindCursor = LoadCursorW(ghInstance, 10);
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
  for ( i = 0; i < gConfig.dwNumColumnsets; ++i )
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
  InsertMenuW(hMainMenuHandle, IDM_VIEW_SHOW_LOWER_PANE, MF_POPUP, hOpacityPopupMenuHandle, L"Opacity");
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
  if ( Init3DStatistics(&dwMinSegments, &dwNbSegments) )
  {
    gpGraphInfoOfGPU = InitGraphData(1, 1, 1);
    gpGraphInfoOfGPU->m_nItemID = 4;
    gpGraphInfoOfGPU->m_Color = 0x8080FF;
    gpGraphInfoOfGPU->m_dbMemorySize = db_onehundred;
    gpGraphInfoOfSystemMemory = InitGraphData(1, 1, 0);
    gpGraphInfoOfSystemMemory->m_nItemID = 5;
    gpGraphInfoOfSystemMemory->m_Color = 0xAAAA;
    if ( dwMinSegments )
    {
      v46 = dwMinSegments;
      v47 = v46;
    }
    else
    {
      v47 = db_one;
    }
    gpGraphInfoOfSystemMemory->m_dbMemorySize = v47;
    gpGraphInfoOfDedicatedMemory = InitGraphData(1, 1, 0);
    gpGraphInfoOfDedicatedMemory->m_nItemID = 6;
    gpGraphInfoOfDedicatedMemory->m_Color = 0x4080FF;
    if ( dwNbSegments )
    {
      v48 = dwNbSegments;
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
  v50 = CanReplaceTaskManager() != 0 ? MF_CHECKED : 0;
  v51 = GetMenu(hWnd_1);
  CheckMenuItem(v51, IDM_OPTIONS_REPLACE_TASK_MANAGER, v50);
  if ( gdwVersion >= 1 && !IsBuiltinAdministrative() )
    ReplaceMenuIconFromStockIcon(hMainMenuHandle, IDM_OPTIONS_REPLACE_TASK_MANAGER);
  if ( CanReplaceTaskManager() )
    ReplaceTaskManager(hWnd_1, 0);
  v52 = IsProcessExplorerRunAtStartup(&savedregs, hMainMenuHandle) != 0 ? MF_CHECKED : 0;
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
    && *SetMenuInfo
    && WTSEnumerateSessionsW(0, 0, 1u, &pSessionInfo, &nSessionCount)
    && nSessionCount )
  {
    Item.cchTextMax = sizeof(MENUINFO);
    Item.iImage = 0x80000010;
    Item.lParam = MNS_NOTIFYBYPOS;
    SetMenuInfo(hMainMenuHandle, &Item.cchTextMax);
    ghUserPopupMenuHandle = CreateMenu();
    InsertMenuW(hMainMenuHandle, 5u, 0x410u, ghUserPopupMenuHandle, L"&Users");
    WTSFreeMemory(pSessionInfo);
  }
  dwProcessId = GetCurrentProcessId();
  hProcessHandle = GetCurrentProcess();
  QueryProcessUsers(hProcessHandle, dwProcessId, 0, szUserName, MAX_PATH, szDomainName, MAX_PATH, 0, 0, 0, 0);
  if ( !szDomainName[0] || (psz_1 = L"\\", !szUserName[0]) )
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
    if ( *GetLogicalProcessorInformation )
    {
      cbData = 0;
      GetLogicalProcessorInformation(0, &cbData);
      if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
      {
        gpLogicalProcessorInfo = malloc(cbData);
        GetLogicalProcessorInformation(gpLogicalProcessorInfo, &cbData);
        gdwLogicalProcessorInfoItemCount = cbData / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
      }
    }
    else
    {
      gpLogicalProcessorInfo = Fake_GetLogicalProcessorInformation(&gdwLogicalProcessorInfoItemCount);
    }
    gppGraphInfo = malloc(4 * gSystemInfo.dwNumberOfProcessors);
    NumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    for ( index = 0; index < gSystemInfo.dwNumberOfProcessors; ++index )
    {
      gppGraphInfo[index] = InitGraphData(NumberOfProcessors, 2, 0);
      gppGraphInfo[index]->m_ProcessorID = index;
      sub_1023E70(
        gpLogicalProcessorInfo,
        gdwLogicalProcessorInfoItemCount,
        index,
        &gppGraphInfo[index]->field_874,
        &gppGraphInfo[index]->field_870);
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
  *SetSuspendState = GetProcAddress(v64, "SetSuspendState");
  if ( *SetSuspendState )
  {
    v65 = LoadLibraryW(L"Powrprof.dll");
    *IsPwrHibernateAllowed = GetProcAddress(v65, "IsPwrHibernateAllowed");
    if ( IsPwrHibernateAllowed() )
      InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_HIBERNATE, L"&Hibernate");
    v66 = LoadLibraryW(L"Powrprof.dll");
    *IsPwrSuspendAllowed = GetProcAddress(v66, "IsPwrSuspendAllowed");
    if ( IsPwrSuspendAllowed() )
      InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_STANDBY, L"Stand &By");
  }
  v67 = LoadLibraryW(L"User32.dll");
  *LockWorkStation = GetProcAddress(v67, "LockWorkStation");
  if ( *LockWorkStation )
    InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_THREADSTACK_BUTTON_COPY, L"Loc&k");
  v68 = LoadLibraryW(L"User32.dll");
  *GetMonitorInfoA = GetProcAddress(v68, "GetMonitorInfoA");
  v69 = LoadLibraryW(L"User32.dll");
  *MonitorFromPoint = GetProcAddress(v69, "MonitorFromPoint");
  v70 = LoadMenuW(ghInstance, L"DLLMENU");
  v71 = 0;
  ghDllMenuPopup = v70;
  if ( gConfig.bHighlightRelocatedDlls )
    v71 = 8;
  CheckMenuItem(v70, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, v71);
  ghHandleMenuPopup = LoadMenuW(ghInstance, L"HANDLEMENU");
  v72 = 0;
  if ( gConfig.bShowUnnamedHandles )
    v72 = 8;
  v73 = v72;
  v74 = GetMenu(hWnd_1);
  CheckMenuItem(v74, IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS, v73);
  RegCloseKey = ::RegCloseKey;
  if ( RegOpenKeyW(HKEY_CLASSES_ROOT, L"exefile\\shell\\View Dependencies", &hSubKey) )
  {
    gstrApplicationName = 0;
    dwRet = GetEnvironmentVariableW(L"PATH", 0, 0);
    dwSize = dwRet;
    if ( dwRet )
    {
      pszPath = malloc(2 * dwRet + 2);
      GetEnvironmentVariableW(L"PATH", pszPath, dwSize);
      dwSize_1 = dwSize;
      pszPath_1 = pszPath;
      if ( MakeApplicationName(L"depends.exe", pszPath, dwSize_1, &gstrApplicationName) )
      {
        InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
        InsertMenuW(
          ghDllMenuPopup,
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
    RegCloseKey = ::RegCloseKey;
  }
  else
  {
    gbLaunchDepends = 1;
    InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
    InsertMenuW(ghDllMenuPopup, IDM_DLLMENU_BASE_ITEM, MF_BYCOMMAND, IDM_DLLMENU_LAUNCH_DEPENDS, L"&Launch Depends...");
    gstrApplicationName = 0;
    ::RegCloseKey(hSubKey);
  }
  if ( !RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\AeDebug", &hSubKey) )
  {
    cbData = 520;
    if ( !RegQueryValueExW(hSubKey, L"Debugger", 0, &Type, szPathName, &cbData) )
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
  ghWndToolbar = InitToolbar(hWnd_1, IDC_MAINTOOLBAR);
  if ( !ghWndToolbar )
    return -1;
  UpdateMenuStatus(0, 3);
  GetWindowRect(ghWndToolbar, &rcToolbar);
  gnToolbarHeight = rcToolbar.bottom - rcToolbar.top + 2;
  hInst = ghInstance;
  _mm_storeu_si128(&rcTreeList, 0i64);
  hWndTreeListView = CTreeList::Init(hWnd_2, hInst, IDC_TREEVIEW_LIST, 0x40810200, &rcTreeList);
  ghWndTreeListView = hWndTreeListView;
  if ( !hWndTreeListView )
    return -1;
  CTreeList::InitListCtrl(hWndTreeListView, ghConfigFont);
  pTreeList = CTreeList::GetTreeList(ghWndTreeListView);
  pTreeList_1 = pTreeList;
  pszPath = pTreeList;
  pTreeList->m_pfnDrawBack = CMainWnd::Draw;
  CTreeList::UpdateSB(pTreeList, 0);
  pTreeList_1->m_pfnGetChildCursor = CMainWnd::GetDynamicCursor;
  v87 = LoadCursorW(ghInstance, 0x6A);
  CTreeList::SetSplitterCursor(pTreeList_1, v87);
  sub_FFBDA0(pTreeList_1, 1);
  sub_FFF210(pTreeList_1, 0);
  sub_FFF230(pTreeList_1, 0);
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
  if ( !InitListHeader(ghWndTreeListView, gConfig.dwProcessColumnMap, gConfig.dwProcessColumns, dwProcessColumnCount) )
    return -1;
  v93 = GetSystemMetrics(SM_CYSMICON);
  v94 = GetSystemMetrics(SM_CXSMICON);
  hImgList = ImageList_Create(v94, v93, 0x21u, 256, 256);
  pTreeList_2 = pszPath;
  CTreeList::ResetImageList(pszPath, hImgList, 0);
  v97 = LoadIconW(0, IDC_ARROW);
  v98 = CTreeList::GetImageList(pTreeList_2);
  ImageList_ReplaceIcon(v98, -1, v97);
  v99 = InitSortableImageList();
  CTreeList::SetSortFlagsImageList(pTreeList_2, v99, 1, 0);
  if ( !gConfig.bShowProcessTree )
    CTreeList::InitHeaderColumn(
      ghWndTreeListView,
      0xFFFFFFFF,
      gConfig.dwProcessSortColumn,
      gConfig.bProcessSortDirection);
  v100 = hWnd_1;
  v101 = CreateListCtrl(
           hWnd_1,
           0x40810605u,
           gConfig.dwIdsOfHandleColumnMap,
           gConfig.dwHandleColumns,
           gConfig.dwHandleColumnCount,
           IDC_LISTCTRL_HANDLES);
  ghWndHandlesListCtrl = v101;
  if ( !v101 )
    return -1;
  CTreeList::InitHeaderColumn(v101, 0xFFFFFFFF, gConfig.dwHandleSortColumn, gConfig.bHandleSortDirection);
  v102 = CreateListCtrl(
           v100,
           0x40810605u,
           gConfig.dwDllColumnMap,
           gConfig.dwDllColumns,
           gConfig.dwDllColumnCount,
           IDC_LISTCTRL_DLLS);
  ghWndDllsListCtrl = v102;
  if ( !v102 )
    return -1;
  CTreeList::InitHeaderColumn(v102, 0xFFFFFFFF, gConfig.dwDllSortColumn, gConfig.bDllSortDirection);
  ghWndStatusBar = CreateStatusWindowW(0x50000000, &gszNullString, v100, 0x6Au);
  CMainWnd::InitStatusBar(ghWndStatusBar);
  ghResizeCursor = LoadCursorW(ghInstance, 0x69);
  if ( !ghResizeCursor )
    ghResizeCursor = LoadCursorW(0, 0x7F00);
  ghSplitterCursor = LoadCursorW(ghInstance, 0x6A);
  if ( !ghSplitterCursor )
    ghSplitterCursor = LoadCursorW(0, 0x7F00);
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
  gRectPane.left = 0;
  gRectWindow.top = gRectWindow.top - 1 + gnToolbarHeight;
  gRectWindow.bottom -= gRectWindow.top;
  gRectPane.top = gRectWindow.top + ((gRectWindow.bottom - gRectWindow.top) * gConfig.dbDivider);
  gRectPane.bottom = gRectPane.top + 7;
  gRectPane.right = gRectWindow.right;
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
  SendMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, gConfig.bShowProcessTree);
  SetFocus(ghWndTreeListView);
  lvItem.iItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  lvItem.iSubItem = 0;
  lvItem.mask = 4;
  SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &lvItem);
  RefreshVirusTotalMenuItem(lvItem.lParam);
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(ghWndDllsListCtrl, LVM_SETITEMSTATE, 0, &Item);
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, 0, &Item);
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
  ghBackupRefreshThreadHandle = _beginthreadex(0, 0, CMainWnd::BackendRefreshThreadProc, 0, 0, 0);
  if ( gConfig.dwRefreshRate > 2000 )
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
      SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, L"Paused");
    }
  }
LABEL_167:
  InvalidateRect(ghWndToolbar, 0, 1);
  SetCursor(hCursor_____);
  if ( !gIOGraphInfo.pGraphData )
    DeleteMenu(hMainMenuHandle, IDM_OPTIONS_TRAYICON_IO_HISTORY, 0);
  HandleTaskbarCreated();
  v125 = GetModuleHandleW(L"Shlwapi.dll");
  gpfnSHAutoComplete = GetProcAddress(v125, "SHAutoComplete");
  v126 = LoadLibraryW(L"user32.dll");
  v127 = GetProcAddress(v126, "SetLayeredWindowAttributes");
  dwOpacity = gConfig.dwOpacity;
  SetLayeredWindowAttributes = v127;
  if ( gConfig.dwOpacity != 100 )
  {
    v129 = GetWindowLongW(ghMainWnd, GWL_EXSTYLE);
    SetWindowLongW(ghMainWnd, -20, v129 | WS_EX_LAYERED);
    SetLayeredWindowAttributes(ghMainWnd, 0, (255 * gConfig.dwOpacity) / 100, LWA_ALPHA);
    RedrawWindow(ghMainWnd, 0, 0, 0x485u);
    dwOpacity = gConfig.dwOpacity;
  }
  uId = (((0x66666667i64 * dwOpacity) >> 32) >> 2) + (((0x66666667i64 * dwOpacity) >> 32) >> 31) + 40093;
  v131 = ::GetMenu(v119);
  CheckMenuItem(v131, uId, 8u);
  if ( gbHide )
    CMainWnd::Hide(ghMainWnd);
  return 0;
}
// FF9F40: using guessed type bool __cdecl LoadWintrust();
// 1056620: using guessed type bool __cdecl GetProcessDEPStatus();
// 109CDC0: using guessed type double db_onehundred;
// 10A08AC: using guessed type wchar_t aRUnAsAdministr[25];
// 10A0D80: using guessed type wchar_t aPaused[7];
// 10C4E54: using guessed type int gdwVersion;
// 10CA118: using guessed type int (__stdcall *gpfnCreateRestrictedToken)(void *, unsigned int, unsigned int, struct _SID_AND_ATTRIBUTES *, unsigned int, struct _LUID_AND_ATTRIBUTES *, unsigned int, struct _SID_AND_ATTRIBUTES *, void **);
// 10CA32C: using guessed type int gdwComdlg_FindReplaceMessageID;
// 10CA388: using guessed type char gbHide;
// 10CA390: using guessed type char gbIsProcessDEPEnabled;
// 10CA391: using guessed type char gbWintrustInited;
// 10CA392: using guessed type char gbLaunchDepends;
// 10CA884: using guessed type int gShellIconMsg;
// 10CA8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);
// 10CA908: using guessed type int ghSplitterCursor;
// 10CF360: using guessed type int (__stdcall *ChangeWindowMessageFilter)(_DWORD, _DWORD);
// 10E5720: using guessed type int gnStatusBarItemCount;
