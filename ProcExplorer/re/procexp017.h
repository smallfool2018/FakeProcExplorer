//----- (0103DD60) --------------------------------------------------------
void __cdecl sub_103DD60(char a1, unsigned int a2, int a3, unsigned int a4, int a5, int a6, int a7, unsigned int *a8)
{
  int v8; // esi
  unsigned int v9; // edx
  wchar_t *v10; // edi
  int v11; // ebx
  signed int v12; // eax
  const CHAR *v13; // ecx
  unsigned int v14; // ebx
  int v15; // esi
  int v16; // eax
  const CHAR *v17; // ebx
  const wchar_t **v18; // eax
  wchar_t *v19; // eax
  volatile signed __int32 *v20; // edx
  CString *v21; // eax
  HANDLE v22; // esi
  int v23; // ebx
  LPCSTR v24; // ebx
  CHAR *v25; // ecx
  int v26; // eax
  void *v27; // ebx
  int v28; // edx
  unsigned int v29; // ebx
  int v30; // esi
  char *v31; // eax
  LPCSTR v32; // eax
  int v33; // eax
  HANDLE v34; // esi
  const wchar_t **v35; // eax
  bool v36; // bl
  bool v37; // zf
  int v38; // ebx
  CString *v39; // eax
  const wchar_t **v40; // eax
  const wchar_t **v41; // eax
  wchar_t *v42; // eax
  DWORD v43; // ST28_4
  int v44; // eax
  int v45; // esi
  __int16 *v46; // ecx
  __int16 v47; // ax
  int v48; // ecx
  wchar_t v49; // ax
  __int16 v50; // ax
  int v51; // ecx
  wchar_t v52; // ax
  BOOL (__stdcall *v53)(HANDLE, PCWSTR, PVOID); // [esp+0h] [ebp-1288h]
  struct _MODLOAD_DATA *v54; // [esp+0h] [ebp-1288h]
  void *v55; // [esp+4h] [ebp-1284h]
  DWORD v56; // [esp+4h] [ebp-1284h]
  BOOL (__stdcall *v57)(HANDLE, PCWSTR, PVOID); // [esp+8h] [ebp-1280h]
  void *v58; // [esp+Ch] [ebp-127Ch]
  CString v59; // [esp+10h] [ebp-1278h]
  unsigned __int64 Displacement; // [esp+14h] [ebp-1274h]
  CString v61; // [esp+1Ch] [ebp-126Ch]
  CString v62; // [esp+20h] [ebp-1268h]
  int v63; // [esp+24h] [ebp-1264h]
  int v64; // [esp+28h] [ebp-1260h]
  int v65; // [esp+2Ch] [ebp-125Ch]
  CString v66; // [esp+30h] [ebp-1258h]
  int v67; // [esp+34h] [ebp-1254h]
  int v68; // [esp+38h] [ebp-1250h]
  unsigned int *v69; // [esp+3Ch] [ebp-124Ch]
  int v70; // [esp+40h] [ebp-1248h]
  int v71; // [esp+44h] [ebp-1244h]
  LPCSTR lpMultiByteStr; // [esp+48h] [ebp-1240h]
  unsigned int *v73; // [esp+4Ch] [ebp-123Ch]
  DWORD64 Address; // [esp+50h] [ebp-1238h]
  wchar_t v75; // [esp+58h] [ebp-1230h]
  struct _SYMBOL_INFOW Symbol; // [esp+858h] [ebp-A30h]
  WCHAR Buffer; // [esp+C58h] [ebp-630h]
  WCHAR Src; // [esp+E60h] [ebp-428h]
  WCHAR Dst; // [esp+106Ch] [ebp-21Ch]
  int v80; // [esp+1284h] [ebp-4h]

  HIDWORD(Displacement) = a6;
  Address = __PAIR__(a4, a2);
  v71 = a3;
  v64 = a5;
  v63 = a7;
  v69 = a8;
  if ( !a2 )
  {
    v8 = sub_103E420(*(a3 + 44));
    if ( !v8 )
      v8 = a5;
    LODWORD(Address) = v8;
  }
  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  GetSystemDirectoryW(&Buffer, 0x104u);
  v9 = Address;
  v10 = (a3 + 52);
  while ( 1 )
  {
    v11 = v63;
    v12 = -1;
    v73 = -1;
    *v10 = 0;
    if ( !v11 )
      goto LABEL_74;
    v70 = -1;
    v13 = *(v11 + 48);
    v14 = 0;
    lpMultiByteStr = v13;
    if ( !*v13 )
      goto LABEL_74;
    v15 = (v13 + 12);
    do
    {
      if ( v9 > *v15 )
      {
        if ( v9 >= *v15 + *(v15 + 4) )
        {
          v12 = v73;
        }
        else
        {
          v16 = *(v15 + 18) + 20;
          v70 = *v15;
          swprintf(v10, L"%S", v15 + v16);
          v9 = Address;
          v12 = v14;
          v73 = v14;
        }
      }
      ++v14;
      v15 += 284;
    }
    while ( v14 < *lpMultiByteStr );
    if ( v12 == -1 )
    {
LABEL_74:
      v29 = 0;
      v70 = -1;
      if ( !*v69 )
        goto LABEL_52;
      v30 = (v69 + 3);
      do
      {
        if ( v9 > *v30 )
        {
          if ( v9 >= *v30 + *(v30 + 4) )
          {
            v12 = v73;
          }
          else
          {
            v70 = *v30;
            lpMultiByteStr = (v30 + 20);
            v31 = strrchr((v30 + 20), 92);
            if ( v31 )
              v32 = v31 + 1;
            else
              v32 = lpMultiByteStr;
            swprintf(v10, L"%S", v32);
            v9 = Address;
            v12 = v29;
            v73 = v29;
          }
        }
        ++v29;
        v30 += 284;
      }
      while ( v29 < *v69 );
      if ( v12 == -1 )
      {
LABEL_52:
        v27 = HIDWORD(Address);
        goto LABEL_53;
      }
      v33 = 71 * v12;
      v34 = 0;
      v73 = &v69[v33];
      lpMultiByteStr = &v69[v33 + 8];
      v35 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
              &v61,
              lpMultiByteStr);
      v36 = _wcsnicmp(*v35, L"\\SystemRoot\\", 0xCu) == 0;
      ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v61);
      v37 = v36 == 0;
      v38 = v73;
      if ( v37 )
      {
        if ( *(v73 + 33) == 58 )
        {
          v40 = sub_1014BD0(&v66, lpMultiByteStr);
          wcscpy_s(&Dst, 0x105u, *v40);
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v66);
        }
        else
        {
          if ( *(v73 + 37) != 58 )
          {
            sub_1039D60(&Dst, L"%s\\drivers\\%s", &Buffer, v10);
            v34 = FindExecutableImageExW_0(&Dst, &Buffer, &Src, v53, v55);
            if ( v34 )
            {
              if ( !_wcsicmp(&Src, &Dst) )
                goto LABEL_46;
              CloseHandle(v34);
            }
            sub_1039D60(&Src, L"%s\\drivers\\%s", &Buffer, v10);
            v34 = FindExecutableImageExW_0(&Src, &Buffer, &Dst, v57, v58);
            goto LABEL_46;
          }
          v41 = sub_1014BD0(&v62, v73 + 36);
          wcscpy_s(&Dst, 0x105u, *v41);
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v62);
        }
      }
      else
      {
        v39 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                &v59,
                v73 + 44);
        sub_1039D60(&Src, L"%%SystemRoot%%\\%s", v39->pszData);
        ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v59);
        ExpandEnvironmentStringsW(&Src, &Dst, 0x105u);
      }
LABEL_46:
      v42 = _wcsdup(&Dst);
      *(v71 + 572) = v42;
      if ( SymLoadModuleExW_1 && a1 )
      {
        v43 = *(v38 + 16);
        v44 = *(v38 + 12);
        v27 = HIDWORD(Address);
        SymLoadModuleExW_1(HIDWORD(Address), v34, &Dst, 0, v44, v43, v59.pszData, Displacement);
      }
      else
      {
        v27 = HIDWORD(Address);
      }
      if ( v34 )
        CloseHandle(v34);
      goto LABEL_53;
    }
    if ( !a1 )
      goto LABEL_52;
    lpMultiByteStr += 284 * v12;
    v17 = lpMultiByteStr + 32;
    v18 = sub_1014BD0(&v67, lpMultiByteStr + 32);
    v19 = _wcsdup(*v18);
    v20 = (v67 - 16);
    *(v71 + 572) = v19;
    if ( _InterlockedDecrement(v20 + 3) <= 0 )
      (*(**v20 + 4))(v20);
    if ( !SymLoadModuleExW_1 )
      goto LABEL_52;
    v21 = sub_1014BD0(&v65, v17);
    v80 = 0;
    v22 = FindExecutableImageExW_0(v21->pszData, 0, &Dst, v53, v55);
    v23 = v65 - 16;
    v80 = -1;
    if ( _InterlockedDecrement((v65 - 16 + 12)) <= 0 )
      (*(**v23 + 4))(v23);
    v24 = lpMultiByteStr;
    v25 = sub_1014BD0(&v68, lpMultiByteStr + 32)->pszData;
    v26 = *(v24 + 3);
    v27 = HIDWORD(Address);
    v80 = 1;
    SymLoadModuleExW_1(HIDWORD(Address), v22, v25, 0, v26, 0, v54, v56);
    v28 = v68 - 16;
    v80 = -1;
    if ( _InterlockedDecrement((v68 - 16 + 12)) <= 0 )
      (*(**v28 + 4))(v28);
    if ( v22 )
      CloseHandle(v22);
LABEL_53:
    v45 = Address;
    Symbol.SizeOfStruct = 88;
    Symbol.MaxNameLen = 469;
    if ( a1 )
    {
      if ( *SymFromAddrW && SymFromAddrW(v27, Address, &Displacement, &Symbol) )
        break;
    }
    if ( *v10 )
    {
      wsprintfW(&v75, L"+0x%x", v45 - v70);
      goto LABEL_70;
    }
    if ( v45 == v64 )
    {
      wsprintfW(&v75, L"0x%x", v45);
LABEL_70:
      wcscat_s(v10, 0x104u, &v75);
      goto LABEL_71;
    }
    v9 = v64;
    LODWORD(Address) = v64;
  }
  v46 = (a3 + 52);
  LOBYTE(Symbol.Name[Symbol.NameLen]) = 0;
  if ( Displacement )
  {
    do
    {
      v47 = *v46;
      ++v46;
    }
    while ( v47 );
    v48 = (v46 - a3 - 54) >> 1;
    do
    {
      v49 = *v10;
      ++v10;
    }
    while ( v49 );
    _snwprintf_s((v71 + 2 * ((v10 - a3 - 54) >> 1) + 52), 260 - v48, 0xFFFFFFFF, L"!%s+0x%x", Symbol.Name, Displacement);
  }
  else
  {
    do
    {
      v50 = *v46;
      ++v46;
    }
    while ( v50 );
    v51 = (v46 - a3 - 54) >> 1;
    do
    {
      v52 = *v10;
      ++v10;
    }
    while ( v52 );
    _snwprintf_s((v71 + 2 * ((v10 - a3 - 54) >> 1) + 52), 260 - v51, 0xFFFFFFFF, L"!%s", Symbol.Name);
  }
LABEL_71:
  LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
}
// 10A2BE0: using guessed type wchar_t a0xX_0[5];

//----- (0103E420) --------------------------------------------------------
int __cdecl sub_103E420(HANDLE hObject)
{
  HANDLE v1; // esi
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+0h] [ebp-28h]
  struct _CLIENT_ID ClientId; // [esp+18h] [ebp-10h]
  ULONG ReturnLength; // [esp+20h] [ebp-8h]
  int ThreadInformation; // [esp+24h] [ebp-4h]

  ClientId.UniqueThread = hObject;
  ThreadInformation = 0;
  ClientId.UniqueProcess = 0;
  ObjectAttributes.Length = 24;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 0;
  ObjectAttributes.ObjectName = 0;
  ObjectAttributes.SecurityDescriptor = 0;
  ObjectAttributes.SecurityQualityOfService = 0;
  if ( NtOpenThread(&hObject, 0x40u, &ObjectAttributes, &ClientId) )
    return ThreadInformation;
  v1 = hObject;
  if ( hObject )
  {
    NtQueryInformationThread(hObject, ThreadQuerySetWin32StartAddress, &ThreadInformation, 4u, &ReturnLength);
    CloseHandle(v1);
  }
  return ThreadInformation;
}

//----- (0103E4B0) --------------------------------------------------------
int __cdecl sub_103E4B0(CSystemProcessInfoMap *theMap, SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo, SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pProcessorIdleCycleTimeInfo, unsigned int dwProcessorIdleCycleTimeInfoLen)
{
  unsigned __int64 ThisMap; // rcx
  SYSTEM_PROCESS_INFORMATION *SystemProcessInfo; // esi
  unsigned int v6; // edx
  DWORD dwNumberOfProcessors; // edi
  DWORD dwIndex; // edx
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  char *v11; // eax
  __m128i v12; // xmm0
  __m128i v13; // xmm1
  __m128i v14; // xmm1
  unsigned __int64 v15; // kr08_8
  unsigned int v16; // eax
  unsigned int v17; // edi
  int v18; // kr18_4
  unsigned __int8 v19; // cf
  unsigned __int64 v20; // kr28_8
  DWORD v21; // kr04_4
  int v22; // ebx
  int v23; // ecx
  HANDLE v24; // edx
  int v25; // eax
  int *v26; // eax
  _DWORD *v27; // eax
  int v28; // edx
  CSystemProcessInfoMap *theMap_2; // esi
  std__Tree_node *_Node; // eax
  _DWORD *v31; // edi
  std_Tree_node_for_tagKeyName *v32; // edx
  Data_t_bstr_t *v33; // ecx
  std__Tree_node_For__bstr_t *_Node_1; // ecx
  std__Tree_node *_Node_2; // ecx
  std_Tree_node_for_tagKeyName *_Node_3; // ecx
  unsigned int dwIndex_1; // edx
  __m128i v38; // xmm1
  __m128i v39; // xmm2
  SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pProcessorIdleCycleTimeInfo2; // eax
  __m128i v41; // xmm0
  __m128i v42; // xmm1
  __m128i v43; // xmm1
  unsigned __int64 v44; // kr20_8
  unsigned __int64 v45; // rcx
  int v46; // eax
  unsigned int v47; // edi
  unsigned int v48; // eax
  ULONGLONG v49; // kr40_8
  ULONGLONG v50; // kr48_8
  unsigned int v51; // edi
  unsigned __int64 v52; // rax
  ULONG Buffer; // [esp+0h] [ebp-83Ch]
  int v55; // [esp+4h] [ebp-838h]
  int v56; // [esp+8h] [ebp-834h]
  DWORD v57; // [esp+Ch] [ebp-830h]
  _DWORD a2[2]; // [esp+10h] [ebp-82Ch]
  unsigned int dwProcessorIdleCycleTimeInfoLength; // [esp+18h] [ebp-824h]
  __int64 v60; // [esp+1Ch] [ebp-820h]
  __int64 v61; // [esp+24h] [ebp-818h]
  CSystemProcessInfoMap *theMap_1; // [esp+2Ch] [ebp-810h]
  unsigned int v63; // [esp+30h] [ebp-80Ch]
  unsigned int v64; // [esp+34h] [ebp-808h]
  ULONG64 ProcessorIdleCycleTime; // [esp+38h] [ebp-804h]
  int v66; // [esp+40h] [ebp-7FCh]
  int v67; // [esp+44h] [ebp-7F8h]
  char v68; // [esp+48h] [ebp-7F4h]

  ThisMap = theMap;
  SystemProcessInfo = pSystemProcessInfo;
  v60 = 0i64;
  v6 = 0;
  dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
  theMap_1 = theMap;
  dwProcessorIdleCycleTimeInfoLength = dwProcessorIdleCycleTimeInfoLen;
  v63 = 0;
  v64 = 0;
  while ( 1 )
  {
    if ( !SystemProcessInfo->UniqueProcessId && !SystemProcessInfo->SpareLi3.QuadPart )
    {
      Buffer = 8 * dwNumberOfProcessors;
      QueryIdleProcessorCycleTime(&Buffer, &ProcessorIdleCycleTime);
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
      dwIndex = 0;
      if ( gSystemInfo.dwNumberOfProcessors && gSystemInfo.dwNumberOfProcessors >= 4 )
      {
        v9 = 0i64;
        v10 = 0i64;
        v11 = &v68;
        do
        {
          v12 = _mm_loadu_si128(v11 - 1);
          dwIndex += 4;
          v11 += 32;
          v9 = _mm_add_epi64(v9, v12);
          v10 = _mm_add_epi64(v10, _mm_loadu_si128(v11 - 2));
        }
        while ( dwIndex < gSystemInfo.dwNumberOfProcessors - (gSystemInfo.dwNumberOfProcessors & 3) );
        v13 = _mm_add_epi64(v9, v10);
        v14 = _mm_add_epi64(v13, _mm_srli_si128(v13, 8));
        LODWORD(ThisMap) = _mm_cvtsi128_si32(v14);
        v15 = ThisMap + __PAIR__(_mm_cvtsi128_si32(_mm_srli_si128(v14, 4)), v64);
        HIDWORD(ThisMap) = HIDWORD(v15);
        v63 = v15 >> 32;
        v64 = v15;
      }
      v60 = 0i64;
      v61 = 0i64;
      if ( dwIndex >= gSystemInfo.dwNumberOfProcessors )
      {
        v6 = v64;
      }
      else
      {
        ThisMap = __PAIR__(HIDWORD(v61), v60);
        if ( gSystemInfo.dwNumberOfProcessors - dwIndex < 2 )
        {
          HIDWORD(v61) = v61;
          v16 = HIDWORD(v60);
        }
        else
        {
          v57 = gSystemInfo.dwNumberOfProcessors - 1;
          HIDWORD(v61) = v61;
          v16 = HIDWORD(v60);
          v17 = v61;
          do
          {
            v16 = (__PAIR__(*(&ProcessorIdleCycleTime + 2 * dwIndex + 1), *(&ProcessorIdleCycleTime + 2 * dwIndex))
                 + __PAIR__(v16, ThisMap)) >> 32;
            LODWORD(ThisMap) = *(&ProcessorIdleCycleTime + 2 * dwIndex) + ThisMap;
            v18 = *(&v66 + 2 * dwIndex) + v17;
            HIDWORD(ThisMap) = (__PAIR__(*(&v67 + 2 * dwIndex), *(&v66 + 2 * dwIndex)) + __PAIR__(HIDWORD(ThisMap), v17)) >> 32;
            v17 += *(&v66 + 2 * dwIndex);
            dwIndex += 2;
          }
          while ( dwIndex < v57 );
          HIDWORD(v61) = v18;
          dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
        }
        if ( dwIndex < dwNumberOfProcessors )
        {
          v19 = __CFADD__(*(&ProcessorIdleCycleTime + 2 * dwIndex), v64);
          v64 += *(&ProcessorIdleCycleTime + 2 * dwIndex);
          v63 += *(&ProcessorIdleCycleTime + 2 * dwIndex + 1) + v19;
          dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
        }
        v20 = __PAIR__(v16, HIDWORD(v61)) + ThisMap + __PAIR__(v63, v64);
        HIDWORD(ThisMap) = HIDWORD(v20);
        v6 = v20;
      }
      LODWORD(ThisMap) = theMap_1;
    }
    v21 = SystemProcessInfo->SpareLi3.LowPart;
    v64 = SystemProcessInfo->SpareLi3.LowPart + v6;
    HIDWORD(ThisMap) = (__PAIR__(HIDWORD(ThisMap), v21) + __PAIR__(SystemProcessInfo->SpareLi3.HighPart, v6)) >> 32;
    v6 += v21;
    v63 = HIDWORD(ThisMap);
    if ( ThisMap )
    {
      v22 = *ThisMap;
      v23 = v22;
      v24 = SystemProcessInfo->UniqueProcessId;
      v25 = *(v22 + 4);
      while ( !*(v25 + 13) )
      {
        if ( *(v25 + 16) >= v24 )
        {
          v23 = v25;
          v25 = *v25;
        }
        else
        {
          v25 = *(v25 + 8);
        }
      }
      if ( v23 == v22 || v24 < *(v23 + 16) )
      {
        v56 = v22;
        v26 = &v56;
      }
      else
      {
        v55 = v23;
        v26 = &v55;
      }
      v27 = *v26;
      if ( v27 != v22 )
      {
        v28 = v27[5];
        if ( *(v28 + 32) == SystemProcessInfo->CreateTime.LowPart )
        {
          LODWORD(ThisMap) = theMap_1;
          if ( *(v28 + 36) != SystemProcessInfo->CreateTime.HighPart )
          {
LABEL_35:
            v6 = v64;
            HIDWORD(ThisMap) = v63;
            goto LABEL_36;
          }
          sub_10555B0(theMap_1, &a2[1], v27);
          dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
        }
      }
      LODWORD(ThisMap) = theMap_1;
      goto LABEL_35;
    }
LABEL_36:
    if ( !SystemProcessInfo->NextEntryOffset )
      break;
    SystemProcessInfo = (SystemProcessInfo + SystemProcessInfo->NextEntryOffset);
  }
  theMap_2 = theMap_1;
  if ( theMap_1 )
  {
    _Node = theMap_1->_Header->_Left;
    if ( _Node != theMap_1->_Header )
    {
      v31 = dwProcessorIdleCycleTimeInfoLength;
      do
      {
        v32 = _Node[1]._Parent;
        v33 = v32->_Myval.second.bstrText2.m_Data;
        v19 = __CFADD__(v33, *v31);
        *v31 += v33;
        v31[1] += v32->_Myval.second.dwValue + v19;
        if ( !_Node->_IsNil )
        {
          _Node_1 = _Node->_Right;
          if ( _Node_1->_IsNil )
          {
            for ( _Node_3 = _Node->_Parent; !_Node_3->_IsNil; _Node_3 = _Node_3->_Parent )
            {
              if ( _Node != _Node_3->_Right )
                break;
              _Node = _Node_3;
            }
            _Node = _Node_3;
          }
          else
          {
            _Node = _Node->_Right;
            for ( _Node_2 = _Node_1->_Left; !_Node_2->_IsNil; _Node_2 = _Node_2->_Left )
              _Node = _Node_2;
          }
        }
      }
      while ( _Node != theMap_2->_Header );
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    }
  }
  dwIndex_1 = 0;
  if ( dwNumberOfProcessors && dwNumberOfProcessors >= 4 )
  {
    v38 = 0i64;
    v39 = 0i64;
    pProcessorIdleCycleTimeInfo2 = pProcessorIdleCycleTimeInfo + 2;
    do
    {
      *v41.m128i_i8 = pProcessorIdleCycleTimeInfo2[-2];
      pProcessorIdleCycleTimeInfo2 += 4;
      v41.m128i_i64[1] = pProcessorIdleCycleTimeInfo2[-5].CycleTime;
      dwIndex_1 += 4;
      v38 = _mm_add_epi64(v38, v41);
      *v41.m128i_i8 = pProcessorIdleCycleTimeInfo2[-4];
      v41.m128i_i64[1] = pProcessorIdleCycleTimeInfo2[-3].CycleTime;
      v39 = _mm_add_epi64(v39, v41);
    }
    while ( dwIndex_1 < dwNumberOfProcessors - (dwNumberOfProcessors & 3) );
    v42 = _mm_add_epi64(v38, v39);
    v43 = _mm_add_epi64(v42, _mm_srli_si128(v42, 8));
    LODWORD(ThisMap) = _mm_cvtsi128_si32(v43);
    v44 = ThisMap + __PAIR__(_mm_cvtsi128_si32(_mm_srli_si128(v43, 4)), v64);
    v63 = v44 >> 32;
    v64 = v44;
  }
  *a2 = 0i64;
  v60 = 0i64;
  if ( dwIndex_1 >= dwNumberOfProcessors )
  {
    LODWORD(v52) = v64;
  }
  else
  {
    v45 = __PAIR__(HIDWORD(v60), a2[0]);
    if ( dwNumberOfProcessors - dwIndex_1 < 2 )
    {
      HIDWORD(v61) = v60;
      v48 = a2[1];
    }
    else
    {
      v46 = dwNumberOfProcessors - 1;
      v47 = v60;
      dwProcessorIdleCycleTimeInfoLength = v46;
      v48 = a2[1];
      do
      {
        v49 = pProcessorIdleCycleTimeInfo[dwIndex_1].CycleTime + __PAIR__(v48, v45);
        v48 = HIDWORD(v49);
        LODWORD(v45) = v49;
        v50 = pProcessorIdleCycleTimeInfo[dwIndex_1 + 1].CycleTime + __PAIR__(HIDWORD(v45), v47);
        HIDWORD(v45) = HIDWORD(v50);
        v47 = v50;
        dwIndex_1 += 2;
      }
      while ( dwIndex_1 < dwProcessorIdleCycleTimeInfoLength );
      HIDWORD(v61) = v50;
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    }
    if ( dwIndex_1 >= dwNumberOfProcessors )
    {
      v51 = v63;
    }
    else
    {
      v51 = (pProcessorIdleCycleTimeInfo[dwIndex_1].CycleTime + __PAIR__(v63, v64)) >> 32;
      v64 += LODWORD(pProcessorIdleCycleTimeInfo[dwIndex_1].CycleTime);
    }
    v52 = __PAIR__(v48, HIDWORD(v61)) + v45 + __PAIR__(v51, v64);
  }
  return v52;
}

//----- (0103E920) --------------------------------------------------------
signed int sub_103E920()
{
  HANDLE v0; // edi
  SYSTEM_HANDLE_INFORMATION *v1; // eax
  ULONG v2; // esi
  int v3; // esi
  signed int result; // eax
  SYSTEM_HANDLE_INFORMATION *v5; // eax
  ULONG v6; // esi
  int v7; // esi
  _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *pEntry; // [esp+4h] [ebp-808h]
  wchar_t Dst; // [esp+8h] [ebp-804h]

  if ( *CreateJobObjectW )
  {
    v0 = CreateJobObjectW(0, 0);
    if ( v0 )
    {
      GetSystemProcessInfo(&gpSystemProcessInfo, &gnSystemProcessInfoLength);
      QuerySystemHandleInfo(0);
      v1 = gpSystemHandleInfo2;
      if ( gpSystemHandleInfo2 )
        v2 = gpSystemHandleInfo2->NumberOfHandles;
      else
        v2 = 0;
      v3 = v2 - 1;
      if ( v3 >= 0 )
      {
        while ( 1 )
        {
          GetHandleTableEntry(v1, v3, &pEntry);
          if ( pEntry->UniqueProcessId == GetCurrentProcessId() && pEntry->HandleValue == v0 )
            break;
          if ( --v3 < 0 )
            goto LABEL_12;
          v1 = gpSystemHandleInfo2;
        }
        Dst = 0;
        PE_QueryObject(&gpszObjectTypeNames[0x40 * pEntry->ObjectTypeIndex], pEntry, &Dst, 0x400u, 0);
      }
LABEL_12:
      CloseHandle(v0);
    }
    result = 1;
  }
  else
  {
    GetSystemProcessInfo(&gpSystemProcessInfo, &gnSystemProcessInfoLength);
    QuerySystemHandleInfo(0);
    v5 = gpSystemHandleInfo2;
    if ( gpSystemHandleInfo2 )
      v6 = gpSystemHandleInfo2->NumberOfHandles;
    else
      v6 = 0;
    v7 = v6 - 1;
    if ( v7 >= 0 )
    {
      while ( 1 )
      {
        GetHandleTableEntry(v5, v7, &pEntry);
        if ( !gpszObjectTypeNames[64 * pEntry->ObjectTypeIndex] )
        {
          Dst = 0;
          PE_QueryObject(&gpszObjectTypeNames[64 * pEntry->ObjectTypeIndex], pEntry, &Dst, 0x400u, 0);
        }
        if ( --v7 < 0 )
          break;
        v5 = gpSystemHandleInfo2;
      }
    }
    result = 1;
  }
  return result;
}

//----- (0103EAA0) --------------------------------------------------------
LPVOID __cdecl PE_QueryFileVersionBlock(LPCVOID pBlock, LPCWSTR lpszBlockName)
{
  LPVOID result; // eax
  unsigned int puLen; // [esp+8h] [ebp-Ch]
  __int16 v4; // [esp+Ch] [ebp-8h]
  DWORD *lpBuffer; // [esp+10h] [ebp-4h]

  v4 = 1024;
  lpBuffer = &v4;
  VerQueryValueW(pBlock, L"\\VarFileInfo\\Translation", &lpBuffer, &puLen);
  result = PE_QueryVersionInfo(pBlock, *lpBuffer, *(lpBuffer + 1), lpszBlockName);
  if ( !result )
  {
    result = PE_QueryVersionInfo(pBlock, *lpBuffer, 1252u, lpszBlockName);
    if ( !result )
      result = PE_QueryVersionInfo(pBlock, 1033, 1252u, lpszBlockName);
  }
  return result;
}

//----- (0103EB20) --------------------------------------------------------
DWORD __cdecl sub_103EB20(void *a1, PVOID *a2, DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, DWORD *a7)
{
  DWORD result; // eax
  unsigned int v8; // ecx
  int v9; // eax

  *a4 = 0;
  *a5 = 0;
  *a6 = 0;
  *a7 = 0;
  while ( 1 )
  {
    if ( QueryWorkingSet(a1, *a2, *a3) )
    {
      if ( !*a2 )
        goto LABEL_7;
      if ( *a3 >= 4 * **a2 )
        break;
    }
    if ( *a2 )
      free(*a2);
LABEL_7:
    result = GetLastError();
    if ( result != 24 )
    {
      *a2 = 0;
      *a3 = 0;
      return result;
    }
    *a3 += 0x4000;
    *a2 = malloc(*a3);
  }
  v8 = 0;
  if ( **a2 )
  {
    do
    {
      v9 = *(*a2 + v8 + 1);
      ++*a4;
      if ( v9 & 0x100 )
      {
        ++*a6;
        if ( (v9 & 0xE0u) > 0x20 )
          ++*a7;
      }
      else
      {
        ++*a5;
      }
      ++v8;
    }
    while ( v8 < **a2 );
  }
  *a4 *= gSystemInfo.dwPageSize;
  *a5 *= gSystemInfo.dwPageSize;
  *a6 *= gSystemInfo.dwPageSize;
  result = gSystemInfo.dwPageSize * *a7;
  *a7 = result;
  return result;
}

//----- (0103EC30) --------------------------------------------------------
BOOL __stdcall DlgSystemInfoGPUNodes(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int v4; // ebx
  int v5; // esi
  HWND v6; // eax
  int v7; // ST24_4
  int v8; // ST20_4
  int v9; // ST1C_4
  HWND v10; // eax
  HICON v11; // eax
  HWND v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  signed int v16; // esi
  HWND v17; // eax
  CGraphData *v18; // eax
  int v19; // esi
  unsigned int v20; // edx
  int v21; // ecx
  LONG v22; // eax
  LONG v23; // ecx
  int v24; // ebx
  int v25; // esi
  HWND v26; // esi
  CResizer *v27; // eax
  CResizer *v28; // esi
  char *v29; // eax
  HWND v30; // eax
  struct tagResizerItem *v31; // eax
  HMENU v32; // ST2C_4
  HWND v33; // eax
  double v34; // xmm0_8
  double *v35; // eax
  DWORD v37; // ecx
  int v38; // esi
  int v39; // ebx
  int v40; // esi
  int v41; // ebx
  HWND v42; // eax
  HWND v43; // eax
  int v44; // ebx
  int v45; // esi
  HWND v46; // eax
  double v47; // [esp+10h] [ebp-94h]
  LRESULT wParama; // [esp+14h] [ebp-90h]
  double v49; // [esp+18h] [ebp-8Ch]
  int v50; // [esp+1Ch] [ebp-88h]
  double v51; // [esp+20h] [ebp-84h]
  int v52; // [esp+24h] [ebp-80h]
  double v53; // [esp+28h] [ebp-7Ch]
  double v54; // [esp+28h] [ebp-7Ch]
  int v55; // [esp+2Ch] [ebp-78h]
  int v56; // [esp+30h] [ebp-74h]
  int nWidth; // [esp+34h] [ebp-70h]
  int v58; // [esp+38h] [ebp-6Ch]
  double v59; // [esp+3Ch] [ebp-68h]
  signed int ArgList; // [esp+40h] [ebp-64h]
  LONG ArgLista; // [esp+40h] [ebp-64h]
  struct tagPOINT Point; // [esp+44h] [ebp-60h]
  int v63; // [esp+4Ch] [ebp-58h]
  HMENU hMenu; // [esp+50h] [ebp-54h]
  struct tagRECT v65; // [esp+54h] [ebp-50h]
  struct tagRECT Rect; // [esp+64h] [ebp-40h]
  WCHAR String; // [esp+74h] [ebp-30h]
  int v68; // [esp+A0h] [ebp-4h]

  if ( msg > 0x113 )
  {
    if ( msg > 0x138 )
    {
      if ( msg == 1124 )
      {
        v43 = GetDlgItem(hDlg, 2501);
        ShowWindow(v43, 0);
        v44 = 1;
        if ( gdwAdapterRuntingTime + 1 > 1 )
        {
          v45 = 2503;
          do
          {
            v46 = GetDlgItem(hDlg, v45);
            ShowWindow(v46, 5);
            ++v44;
            v45 += 2;
          }
          while ( v44 < gdwAdapterRuntingTime + 1 );
        }
      }
    }
    else if ( msg == 312 || msg == 307 || msg == 310 )
    {
      return PE_FillControl(hDlg, wParam);
    }
    return 0;
  }
  if ( msg == 275 )
  {
    v40 = 0;
    if ( gdwAdapterRuntingTime > 0 )
    {
      v41 = 2502;
      do
      {
        v42 = GetDlgItem(hDlg, v41);
        SendMessageW(v42, 0x400u, 0, 0);
        ++v40;
        v41 += 2;
      }
      while ( v40 < gdwAdapterRuntingTime );
    }
    return 0;
  }
  if ( msg > 0x110 )
  {
    if ( msg == 273 )
    {
      if ( wParam == 1 )
      {
        v37 = 0;
        v38 = 0;
        hMenu = 0;
        if ( gdwAdapterRuntingTime > 0 )
        {
          v39 = 2503;
          do
          {
            if ( IsDlgButtonChecked(hDlg, v39) == 1 )
            {
              v37 = (1 << v38) | hMenu;
              hMenu = ((1 << v38) | hMenu);
            }
            else
            {
              v37 = hMenu;
            }
            ++v38;
            v39 += 2;
          }
          while ( v38 < gdwAdapterRuntingTime );
        }
        if ( v37 != gConfig.dwGpuNodeUsageMask )
        {
          gConfig.dwGpuNodeUsageMask = v37;
          gpGraphInfoOfGPU->field_888 = 0;
          gpGraphInfoOfGPU->field_88C = 0;
        }
        EndDialog(hDlg, 0);
      }
      else if ( wParam == 2 )
      {
        EndDialog(hDlg, 0);
      }
    }
    return 0;
  }
  if ( msg != 272 )
  {
    if ( msg == 5 )
    {
      v4 = 0;
      if ( gdwAdapterRuntingTime > 0 )
      {
        v5 = 2503;
        do
        {
          v6 = GetDlgItem(hDlg, v5 - 1);
          GetWindowRect(v6, &Rect);
          Point.x = Rect.left;
          Point.y = Rect.bottom + 2;
          ScreenToClient(hDlg, &Point);
          v7 = Rect.right - Rect.left;
          v8 = Point.y;
          v9 = Point.x;
          v10 = GetDlgItem(hDlg, v5);
          SetWindowPos(v10, 0, v9, v8, v7, 14, 0);
          ++v4;
          v5 += 2;
        }
        while ( v4 < gdwAdapterRuntingTime );
      }
    }
    else if ( msg == 36 )
    {
      *(lParam + 8) = 2 * gdwVirtualScreenWidth;
    }
    return 0;
  }
  v11 = LoadIconW(ghInstance, 0x65);
  SendMessageW(hDlg, 0x80u, 0, v11);
  v12 = GetDlgItem(hDlg, 2501);
  GetWindowRect(v12, &v65);
  v13 = gdwAdapterRuntingTime;
  v56 = gdwAdapterRuntingTime;
  if ( gdwAdapterRuntingTime > 8 )
  {
    v13 = 8 * (gdwAdapterRuntingTime / 8 > 16) + 8;
    v56 = 8 * (gdwAdapterRuntingTime / 8 > 16) + 8;
  }
  v14 = (v13 + gdwAdapterRuntingTime - 1) / v13;
  v58 = v14;
  v15 = v13 * v14 - gdwAdapterRuntingTime;
  if ( v15 )
  {
    v13 += v15 / -2;
    v56 = v13;
    v58 = (v13 + gdwAdapterRuntingTime - 1) / v13;
  }
  v16 = 4;
  if ( gdwAdapterRuntingTime > 16 )
    v16 = 3;
  ArgList = v16;
  if ( gdwAdapterRuntingTime > 32 )
    ArgList = --v16;
  nWidth = (v65.right - v16 * (v13 - 1) - v65.left) / v13;
  v52 = (v65.bottom - v16 * (v58 - 1) - v65.top) / v58;
  v17 = GetDlgItem(hDlg, 2501);
  GetWindowRect(v17, &v65);
  MapWindowPoints(0, hDlg, &v65, 2u);
  if ( !dword_10DBA1C )
  {
    v18 = InitGraphData(gdwAdapterRuntingTime, 1, 0);
    v19 = 0;
    dword_10DBA1C = v18;
    if ( gdwAdapterRuntingTime > 0 )
    {
      v20 = 0;
      while ( 1 )
      {
        v18[v20 / 0x898].m_ProcessorID = v19;
        *(v20 + dword_10DBA1C + 28) = 1;
        *(v20 + dword_10DBA1C + 32) = 4;
        *(v20 + dword_10DBA1C + 48) = 8421631;
        *(v20 + dword_10DBA1C + 40) = db_onehundred;
        *(v20 + dword_10DBA1C + 2172) = gpGraphInfoOfGPU;
        if ( v19 )
        {
          v21 = dword_10DBA1C;
          *(v20 + dword_10DBA1C + 2148) = *(dword_10DBA1C + 2148);
          *(v20 + dword_10DBA1C + 2152) = *(v21 + 2152);
        }
        ++v19;
        v20 += 2200;
        if ( v19 >= gdwAdapterRuntingTime )
          break;
        v18 = dword_10DBA1C;
      }
    }
    v16 = ArgList;
  }
  Rect.bottom = v65.left;
  wParama = SendMessageW(hDlg, 0x31u, 0, 0);
  v22 = 0;
  ArgLista = 0;
  if ( gdwAdapterRuntingTime > 0 )
  {
    v63 = 0;
    v50 = v16 + nWidth;
    v23 = v65.left;
    hMenu = 2503;
    do
    {
      v24 = 0;
      Point.y = v22 + 1;
      v55 = (v22 + 1) % v56;
      if ( !v55 )
        v24 = v65.right - v23 - nWidth;
      v25 = MulDiv(14, gLogPixelSize.y, 96);
      CreateWindowExW(
        0,
        L"Static",
        0,
        0x40000000u,
        v65.left,
        v65.top,
        v24 + nWidth,
        v52 - v25 - 1,
        hDlg,
        (hMenu - 1),
        ghInstance,
        0);
      CreateGraphWindow(hDlg, hMenu - 1, (v63 + dword_10DBA1C));
      v26 = CreateWindowExW(
              0,
              L"Button",
              0,
              0x40010003u,
              v65.left,
              v52 + v65.top - v25,
              nWidth,
              v25,
              hDlg,
              hMenu,
              ghInstance,
              0);
      sub_10013E0(&String, L"Engine %d", ArgLista);
      SetWindowTextW(v26, &String);
      SendMessageW(v26, 0x30u, wParama, 1);
      EnableWindow(v26, 1);
      ShowWindow(v26, 5);
      if ( (1 << ArgLista) & gConfig.dwGpuNodeUsageMask )
        CheckDlgButton(hDlg, hMenu, 1u);
      v23 = v50 + v65.left;
      v65.left += v50;
      if ( !v55 )
      {
        v23 = Rect.bottom;
        v65.left = Rect.bottom;
        v65.top += v52 + 2;
      }
      v22 = Point.y;
      v63 += 2200;
      ArgLista = Point.y;
      hMenu = (hMenu + 2);
    }
    while ( Point.y < gdwAdapterRuntingTime );
    v13 = v56;
  }
  v27 = operator new(0x40u);
  v28 = v27;
  Point.y = v27;
  v68 = 0;
  if ( v27 )
  {
    v27->baseclass.m_hThemeHandle = 0;
    LOBYTE(v68) = 1;
    v27->baseclass.vtptr = &CResizer::`vftable';
    v27->m_OldWndProc = 0;
    v27->m_nXRatio = 50;
    v27->m_nYRatio = 67;
    v27->m_pItem = 0;
    v27->m_dwItemCount = 0;
    v27->m_FixedBorder = 1;
    if ( hDlg )
      CResizer::InitWnd(v27, hDlg);
  }
  else
  {
    v28 = 0;
  }
  v68 = -1;
  *&Point = 0.0;
  *&Rect.right = 0i64;
  v63 = 0;
  if ( gdwAdapterRuntingTime > 0 )
  {
    v29 = 2502;
    hMenu = 2502;
    v47 = 1.0 / v13;
    v49 = 1.0 / v58;
    do
    {
      v30 = GetDlgItem(hDlg, v29);
      v59 = v49 + *&Rect.right;
      v53 = v49 + *&Rect.right;
      if ( v49 + *&Rect.right >= 0.99999 )
        v53 = db_one;
      v31 = CResizer::AddItem(v28, v30, 1);
      v32 = hMenu;
      *&v31->m_rect2.left = *&Rect.right;
      *&v31->m_rect2.right = v53;
      v33 = GetDlgItem(hDlg, v32);
      v34 = v47 + *&Point;
      v51 = v47 + *&Point;
      v54 = v47 + *&Point;
      if ( v47 + *&Point >= 0.99999 )
        v54 = db_one;
      if ( v33 )
      {
        v35 = CResizer::AddItem(v28, v33, 1);
        *v35 = *&Point;
        v35[1] = v54;
        v34 = v51;
      }
      *&Point = v34;
      if ( !(++v63 % v13) )
      {
        *&Point = 0.0;
        *&Rect.right = v59;
      }
      v29 = hMenu + 2;
      hMenu = (hMenu + 2);
    }
    while ( v63 < gdwAdapterRuntingTime );
  }
  SendMessageW(hDlg, 0x464u, 0, 0);
  SetTimer(hDlg, 0, 0x3E8u, 0);
  return 1;
}
// 109C888: using guessed type void *CResizer::`vftable';
// 109CDC0: using guessed type double db_onehundred;
// 10C4E28: using guessed type int gdwVirtualScreenWidth;
// 10DBA1C: using guessed type int dword_10DBA1C;

//----- (0103F3E0) --------------------------------------------------------
signed int __cdecl sub_103F3E0(int ThreadId, int a2, int a3)
{
  void *v3; // esi
  signed int result; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v5 = ThreadId;
  v6 = a2;
  v7 = a3;
  v3 = _beginthreadex(0, 0, sub_103C090, &v5, 0, &ThreadId);
  if ( WaitForSingleObject(v3, 0x1388u) == 258 )
  {
    TerminateThread(v3, 1u);
    CloseHandle(v3);
    result = 32;
  }
  else
  {
    CloseHandle(v3);
    result = v8;
  }
  return result;
}

//----- (0103F460) --------------------------------------------------------
char __cdecl PE_QueryObjectInfo(int pObjectInfo)
{
  SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *v1; // ecx
  SYSTEM_HANDLE_INFORMATION *v2; // eax
  unsigned int i; // esi
  SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *pEntry; // [esp+0h] [ebp-4h]

  pEntry = v1;
  v2 = gpSystemHandleInfo2;
  if ( !gpSystemHandleInfo2 )
    return 0;
  for ( i = 0; v2 && i < v2->NumberOfHandles; ++i )
  {
    GetHandleTableEntry(v2, i, &pEntry);
    if ( pEntry->UniqueProcessId == *(pObjectInfo + 0x24)
      && pEntry->HandleValue == *(pObjectInfo + 0x2C)
      && pEntry->Object == *(pObjectInfo + 0x28) )
    {
      return 1;
    }
    v2 = gpSystemHandleInfo2;
  }
  return 0;
}

//----- (0103F4D0) --------------------------------------------------------
int __cdecl sub_103F4D0(int a1, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR SecurityDescriptor, PSECURITY_DESCRIPTOR pSecurityDescriptor, int a5)
{
  SECURITY_INFORMATION v5; // esi
  DWORD v6; // eax
  void *v7; // eax
  void *v8; // ebx
  signed int v10; // edi
  int v11; // esi
  bool v12; // al

  v5 = SecurityInformation;
  switch ( SecurityInformation )
  {
    case 1u:
      v6 = 0x80000;
      break;
    case 4u:
      v6 = 0x40000;
      break;
    case 8u:
      v6 = 0x1000000;
      break;
    default:
      v6 = SecurityInformation;
      break;
  }
  v7 = PE_DuplicateProcessHandle(*(a1 + 36), *(a1 + 44), v6);
  v8 = v7;
  if ( !v7 || !SetKernelObjectSecurity(v7, v5, SecurityDescriptor) )
    return 5;
  v10 = 5;
  if ( pSecurityDescriptor )
  {
    v11 = v5 | 3;
    if ( v11 == 1 )
      v11 = 5;
    v12 = GetKernelObjectSecurity(v8, v11, pSecurityDescriptor, 0x2000u, &SecurityInformation);
    *a5 = v12;
  }
  CloseHandle(v8);
  if ( !a5 )
    return 0;
  if ( *a5 )
    v10 = 0;
  return v10;
}

//----- (0103F580) --------------------------------------------------------
int __stdcall Fake_GetProcessDEPPolicy(HANDLE hProcess, LPDWORD lpFlags, PBOOL lpPermanent)
{
  int (__stdcall *v3)(HANDLE, LPDWORD, PBOOL); // eax
  HMODULE v4; // eax

  v3 = GetProcessDEPPolicy;
  if ( GetProcessDEPPolicy )
    return v3(hProcess, lpFlags, lpPermanent);
  v4 = GetModuleHandleW(L"KERNEL32.DLL");
  v3 = GetProcAddress(v4, "GetProcessDEPPolicy");
  GetProcessDEPPolicy = v3;
  if ( v3 )
    return v3(hProcess, lpFlags, lpPermanent);
  SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
  return 0;
}

//----- (0103F5C0) --------------------------------------------------------
int __stdcall sub_103F5C0(int a1, int a2, int a3, int a4)
{
  int (__stdcall *v4)(int, int, int, int); // eax
  HMODULE v5; // eax

  v4 = GetProcessMitigationPolicy;
  if ( GetProcessMitigationPolicy )
    return v4(a1, a2, a3, a4);
  v5 = GetModuleHandleW(L"KERNEL32.DLL");
  v4 = GetProcAddress(v5, "GetProcessMitigationPolicy");
  GetProcessMitigationPolicy = v4;
  if ( v4 )
    return v4(a1, a2, a3, a4);
  SetLastError(0x78u);
  return 0;
}

//----- (0103F600) --------------------------------------------------------
char __cdecl sub_103F600(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // eax
  int v5; // ecx

  v4 = a1;
  if ( !a1 )
    return 0;
  while ( 1 )
  {
    if ( v4[10] == a2 && v4[146] == a4 )
    {
      v5 = v4[11];
      if ( v5 == a3 || v5 == 16777343 && !a3 )
        break;
      if ( !v5 && a3 == 16777343 )
        break;
    }
    v4 = v4[547];
    if ( !v4 )
      return 0;
  }
  return 1;
}

//----- (0103F660) --------------------------------------------------------
int __thiscall sub_103F660(int *this, HMODULE hModule, int a3)
{
  int *v3; // edi
  HRSRC v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // ebx
  int v7; // eax
  int v8; // esi
  int result; // eax

  v3 = this;
  v4 = FindResourceW(hModule, ((a3 >> 4) + 1), 6);
  if ( !v4 )
    return 0;
  v5 = ATL::AtlGetStringResourceImage(hModule, v4, a3);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = WideCharToMultiByte(3u, 0, v5 + 1, *v5, 0, 0, 0, 0);
  v8 = v7;
  if ( v7 < 0 )
    goto LABEL_12;
  if ( ((*(*v3 - 8) - v7) | (1 - *(*v3 - 4))) < 0 )
    sub_1042330(v3, v7);
  WideCharToMultiByte(3u, 0, v6 + 1, *v6, *v3, v8, 0, 0);
  if ( v8 > *(*v3 - 8) )
LABEL_12:
    ATL::AtlThrowImpl(-2147024809);
  *(*v3 - 12) = v8;
  result = 1;
  *(v8 + *v3) = 0;
  return result;
}

//----- (0103F720) --------------------------------------------------------
char LoadSystemApis()
{
  HMODULE v0; // eax
  HMODULE v2; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  HMODULE v8; // eax
  HMODULE v9; // eax
  HMODULE v10; // eax
  HMODULE v11; // eax
  HMODULE v12; // eax
  HMODULE v13; // eax
  HMODULE v14; // eax
  HMODULE v15; // eax
  HMODULE v16; // eax
  HMODULE v17; // eax
  HMODULE v18; // eax
  HMODULE v19; // eax
  HMODULE v20; // eax
  HMODULE v21; // eax
  HMODULE v22; // eax
  HMODULE v23; // eax
  HMODULE v24; // eax
  HMODULE v25; // eax
  HMODULE v26; // eax
  HMODULE v27; // eax
  HMODULE v28; // eax
  HMODULE v29; // eax
  HMODULE v30; // eax
  HMODULE v31; // eax
  HMODULE v32; // eax
  HMODULE v33; // eax
  HMODULE v34; // eax
  HMODULE v35; // eax
  HMODULE v36; // eax
  HMODULE v37; // eax
  HMODULE v38; // eax
  HMODULE v39; // eax
  HMODULE v40; // eax
  HMODULE v41; // eax
  HMODULE v42; // eax
  HMODULE v43; // eax
  HMODULE v44; // eax
  HMODULE v45; // eax
  HMODULE v46; // eax
  HMODULE v47; // eax
  HMODULE v48; // eax
  HMODULE v49; // eax
  HMODULE v50; // eax
  HMODULE v51; // eax
  HMODULE v52; // eax
  HMODULE v53; // eax
  HMODULE v54; // eax
  HMODULE v55; // eax
  HMODULE v56; // eax
  HMODULE hModule_1; // eax
  HMODULE v58; // eax
  HMODULE v59; // eax
  int (__stdcall *FindExecutableImage)(PCSTR, PCSTR, PSTR); // eax
  int (__stdcall *v61)(LPCWSTR, LPCWSTR, int); // ecx
  HMODULE v62; // eax
  HMODULE v63; // eax
  HMODULE v64; // eax
  HMODULE v65; // eax
  HMODULE v66; // eax
  HMODULE v67; // eax
  HMODULE v68; // eax
  HMODULE v69; // eax
  HMODULE v70; // eax
  HMODULE v71; // eax
  HMODULE v72; // eax
  HMODULE v73; // eax
  HMODULE v74; // eax
  HMODULE v75; // eax
  HKEY hKey; // [esp+8h] [ebp-218h]
  DWORD cbLength; // [esp+Ch] [ebp-214h]
  HMODULE hModule; // [esp+10h] [ebp-210h]
  WCHAR Text; // [esp+14h] [ebp-20Ch]

  InitTlhlpApis();
  v0 = GetModuleHandleW(L"ntdll.dll");
  NtQuerySystemInformation = GetProcAddress(v0, "NtQuerySystemInformation");
  if ( !NtQuerySystemInformation )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQuerySystemInformation");
LABEL_3:
    MessageBoxW(0, &Text, L"Process Explorer", 0x10u);
    return 0;
  }
  v2 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtQuerySymbolicLinkObject = GetProcAddress(v2, "NtQuerySymbolicLinkObject");
  if ( !gpfn_NtQuerySymbolicLinkObject )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQuerySymbolicLinkObject");
    goto LABEL_3;
  }
  v3 = GetModuleHandleW(L"ntdll.dll");
  NtQueryDirectoryObject = GetProcAddress(v3, "NtQueryDirectoryObject");
  if ( !NtQueryDirectoryObject )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQueryDirectoryObject");
    goto LABEL_3;
  }
  v4 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtOpenSymbolicLinkObject = GetProcAddress(v4, "NtOpenSymbolicLinkObject");
  if ( !gpfn_NtOpenSymbolicLinkObject )
    return ReportMsg(L"Ntdll!NtOpenSymbolicLinkObject");
  v5 = GetModuleHandleW(L"ntdll.dll");
  NtOpenDirectoryObject = GetProcAddress(v5, "NtOpenDirectoryObject");
  if ( !NtOpenDirectoryObject )
    return ReportMsg(L"Ntdll!NtOpenDirectoryObject");
  v6 = GetModuleHandleW(L"ntdll.dll");
  NtQueryObject = GetProcAddress(v6, "NtQueryObject");
  if ( !NtQueryObject )
    return ReportMsg(L"Ntdll!NtQueryObject");
  v7 = GetModuleHandleW(L"ntdll.dll");
  NtQueryInformationProcess = GetProcAddress(v7, "NtQueryInformationProcess");
  if ( !NtQueryInformationProcess )
    return ReportMsg(L"Ntdll!NtQueryInformationProcess");
  v8 = GetModuleHandleW(L"ntdll.dll");
  NtSetInformationProcess = GetProcAddress(v8, "NtSetInformationProcess");
  if ( !NtSetInformationProcess )
    return ReportMsg(L"Ntdll!NtSetInformationProcess");
  v9 = GetModuleHandleW(L"ntdll.dll");
  NtSetInformationProcess_0 = GetProcAddress(v9, "NtQuerySemaphore");
  if ( !NtSetInformationProcess_0 )
    return ReportMsg(L"Ntdll!NtQuerySemaphore");
  v10 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtOpenSymbolicLinkObject = GetProcAddress(v10, "NtOpenSymbolicLinkObject");
  if ( !gpfn_NtOpenSymbolicLinkObject )
    return ReportMsg(L"Ntdll!NtOpenSymbolicLinkObject");
  v11 = GetModuleHandleW(L"ntdll.dll");
  NtQuerySection = GetProcAddress(v11, "NtQuerySection");
  if ( !NtQuerySection )
    return ReportMsg(L"Ntdll!NtQuerySection");
  v12 = GetModuleHandleW(L"ntdll.dll");
  NtQueryEvent = GetProcAddress(v12, "NtQueryEvent");
  if ( !NtQueryEvent )
    return ReportMsg(L"Ntdll!NtQueryEvent");
  v13 = GetModuleHandleW(L"ntdll.dll");
  NtQueryMutant = GetProcAddress(v13, "NtQueryMutant");
  if ( !NtQueryMutant )
    return ReportMsg(L"Ntdll!NtQueryMutant");
  v14 = GetModuleHandleW(L"ntdll.dll");
  NtResumeThread = GetProcAddress(v14, "NtResumeThread");
  if ( !NtResumeThread )
    return ReportMsg(L"Ntdll!NtResumeThread");
  v15 = GetModuleHandleW(L"ntdll.dll");
  NtSuspendThread = GetProcAddress(v15, "NtSuspendThread");
  if ( !NtSuspendThread )
    return ReportMsg(L"Ntdll!NtSuspendThread");
  v16 = GetModuleHandleW(L"ntdll.dll");
  NtOpenThread = GetProcAddress(v16, "NtOpenThread");
  if ( !NtOpenThread )
    return ReportMsg(L"Ntdll!NtOpenThread");
  v17 = GetModuleHandleW(L"ntdll.dll");
  NtQueryInformationThread = GetProcAddress(v17, "NtQueryInformationThread");
  if ( !NtQueryInformationThread )
    return ReportMsg(L"Ntdll!NtQueryInformationThread");
  v18 = GetModuleHandleW(L"ntdll.dll");
  NtQueryVirtualMemory = GetProcAddress(v18, "NtQueryVirtualMemory");
  if ( !NtQueryVirtualMemory )
    return ReportMsg(L"Ntdll!NtQueryVirtualMemory");
  v19 = GetModuleHandleW(L"ntdll.dll");
  RtlCreateQueryDebugBuffer = GetProcAddress(v19, "RtlCreateQueryDebugBuffer");
  if ( !RtlCreateQueryDebugBuffer )
    return ReportMsg(L"Ntdll!RtlCreateQueryDebugBuffer");
  v20 = GetModuleHandleW(L"ntdll.dll");
  RtlQueryProcessDebugInformation = GetProcAddress(v20, "RtlQueryProcessDebugInformation");
  if ( !RtlQueryProcessDebugInformation )
    return ReportMsg(L"Ntdll!RtlQueryProcessDebugInformation");
  v21 = GetModuleHandleW(L"ntdll.dll");
  RtlDestroyQueryDebugBuffer = GetProcAddress(v21, "RtlDestroyQueryDebugBuffer");
  if ( !RtlDestroyQueryDebugBuffer )
    return ReportMsg(L"Ntdll!RtlDestroyQueryDebugBuffer");
  v22 = GetModuleHandleW(L"ntdll.dll");
  RtlTimeToTimeFields = GetProcAddress(v22, "RtlTimeToTimeFields");
  if ( !RtlTimeToTimeFields )
    return ReportMsg(L"Ntdll!RtlTimeToTimeFields");
  v23 = LoadLibraryW(L"aclui.dll");
  *CreateSecurityPage = GetProcAddress(v23, "CreateSecurityPage");
  if ( *CreateSecurityPage )
    goto LABEL_70;
  v24 = LoadLibraryW(L"acledit.dll");
  SedDiscretionaryAclEditor = GetProcAddress(v24, "SedDiscretionaryAclEditor");
  if ( !SedDiscretionaryAclEditor )
    return ReportMsg(L"Acledit!SedDiscretionaryAclEditor");
  v25 = GetModuleHandleW(L"acledit.dll");
  SedSystemAclEditor = GetProcAddress(v25, "SedSystemAclEditor");
  if ( !SedSystemAclEditor )
    return ReportMsg(L"Acledit!SedSystemAclEditor");
  v26 = GetModuleHandleW(L"acledit.dll");
  SedTakeOwnership = GetProcAddress(v26, "SedTakeOwnership");
  if ( !SedTakeOwnership )
    return ReportMsg(L"Acledit!SedTakeOwnership");
LABEL_70:
  v27 = LoadLibraryW(L"shcore.dll");
  GetProcessDpiAwareness = GetProcAddress(v27, "GetProcessDpiAwareness");
  v28 = LoadLibraryW(L"iphlpapi.dll");
  *GetTcpTable = GetProcAddress(v28, "GetTcpTable");
  v29 = LoadLibraryW(L"iphlpapi.dll");
  *GetUdpTable = GetProcAddress(v29, "GetUdpTable");
  v30 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetTcpExTableFromStack = GetProcAddress(v30, "AllocateAndGetTcpExTableFromStack");
  v31 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetUdpExTableFromStack = GetProcAddress(v31, "AllocateAndGetUdpExTableFromStack");
  v32 = LoadLibraryW(L"iphlpapi.dll");
  *GetExtendedTcpTable = GetProcAddress(v32, "GetExtendedTcpTable");
  v33 = LoadLibraryW(L"iphlpapi.dll");
  *GetExtendedUdpTable = GetProcAddress(v33, "GetExtendedUdpTable");
  v34 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetTcpExTable2FromStack = GetProcAddress(v34, "AllocateAndGetTcpExTable2FromStack");
  v35 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetUdpExTable2FromStack = GetProcAddress(v35, "AllocateAndGetUdpExTable2FromStack");
  v36 = LoadLibraryW(L"user32.dll");
  *GetGuiResources = GetProcAddress(v36, "GetGuiResources");
  v37 = LoadLibraryW(L"psapi.dll");
  *QueryWorkingSet = GetProcAddress(v37, "QueryWorkingSet");
  v38 = LoadLibraryW(L"psapi.dll");
  *GetMappedFileNameW = GetProcAddress(v38, "GetMappedFileNameW");
  v39 = LoadLibraryW(L"psapi.dll");
  *EnumProcessModulesEx = GetProcAddress(v39, "EnumProcessModulesEx");
  v40 = LoadLibraryW(L"kernel32.dll");
  GlobalMemoryStatusEx = GetProcAddress(v40, "GlobalMemoryStatusEx");
  v41 = LoadLibraryW(L"user32.dll");
  IsHungAppWindow = GetProcAddress(v41, "IsHungAppWindow");
  v42 = LoadLibraryW(L"user32.dll");
  HungWindowFromGhostWindow = GetProcAddress(v42, "HungWindowFromGhostWindow");
  v43 = LoadLibraryW(L"kernel32.dll");
  *GetLogicalProcessorInformation = GetProcAddress(v43, "GetLogicalProcessorInformation");
  v44 = LoadLibraryW(L"kernel32.dll");
  GetLogicalProcessorInformationEx = GetProcAddress(v44, "GetLogicalProcessorInformationEx");
  v45 = LoadLibraryW(L"kernel32.dll");
  SetThreadGroupAffinity = GetProcAddress(v45, "SetThreadGroupAffinity");
  v46 = LoadLibraryW(L"wtsapi32.dll");
  WTSEnumerateSessionsW = GetProcAddress(v46, "WTSEnumerateSessionsW");
  v47 = LoadLibraryW(L"wtsapi32.dll");
  WTSDisconnectSession = GetProcAddress(v47, "WTSDisconnectSession");
  v48 = LoadLibraryW(L"winsta.dll");
  WinStationConnectW = GetProcAddress(v48, "WinStationConnectW");
  v49 = LoadLibraryW(L"winsta.dll");
  WinStationShadow = GetProcAddress(v49, "WinStationShadow");
  v50 = LoadLibraryW(L"wtsapi32.dll");
  WTSLogoffSessio = GetProcAddress(v50, "WTSLogoffSession");
  v51 = LoadLibraryW(L"wtsapi32.dll");
  WTSSendMessageW = GetProcAddress(v51, "WTSSendMessageW");
  v52 = LoadLibraryW(L"wtsapi32.dll");
  WTSFreeMemory = GetProcAddress(v52, "WTSFreeMemory");
  v53 = LoadLibraryW(L"wtsapi32.dll");
  WTSQuerySessionInformationW = GetProcAddress(v53, "WTSQuerySessionInformationW");
  v54 = LoadLibraryW(L"kernel32.dll");
  *WTSGetActiveConsoleSessionId = GetProcAddress(v54, "WTSGetActiveConsoleSessionId");
  v55 = LoadLibraryW(L"user32.dll");
  *SetMenuInfo = GetProcAddress(v55, "SetMenuInfo");
  v56 = LoadLibraryW(L"user32.dll");
  *GetMenuInfo = GetProcAddress(v56, "GetMenuInfo");
  hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
  hModule = hModule_1;
  if ( !hModule_1 )
  {
    if ( RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\DebuggingTools", &hKey) )
      goto __directLoad;
    cbLength = 520;
    RegQueryValueExW(hKey, L"Windbg", 0, 0, gConfig.strDbgHelpModuleName, &cbLength);
    wcscat_s(gConfig.strDbgHelpModuleName, MAX_PATH, L"DbgHelp.dll");
    hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
    hModule = hModule_1;
    if ( !hModule_1 )
    {
      wcscpy_s(gConfig.strDbgHelpModuleName, MAX_PATH, L"C:\\Debuggers\\dbghelp.dll");
      hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
      hModule = hModule_1;
      if ( !hModule_1 )
      {
        ExpandEnvironmentStringsW(
          L"%ProgramFiles%\\Debugging Tools for Windows (x86)\\dbghelp.dll",
          gConfig.strDbgHelpModuleName,
          MAX_PATH);
        hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
        hModule = hModule_1;
        if ( !hModule_1 )
        {
          GetCurrentDirectoryW(MAX_PATH, gConfig.strDbgHelpModuleName);
          wcscat_s(gConfig.strDbgHelpModuleName, MAX_PATH, L"\\dbghelp.dll");
          hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
          hModule = hModule_1;
          if ( !hModule_1 )
          {
__directLoad:
            hModule_1 = LoadLibraryW(L"dbghelp.dll");
            hModule = hModule_1;
            if ( !hModule_1 )
            {
              hModule_1 = LoadLibraryW(L"imagehlp.dll");
              hModule = hModule_1;
            }
          }
        }
      }
    }
  }
  GetModuleFileNameW(hModule_1, gConfig.strDbgHelpModuleName, MAX_PATH);
  LoadDbgHelp(gConfig.strDbgHelpModuleName);
  if ( !*ImageNtHeader )
  {
    v58 = LoadLibraryW(L"imagehlp.dll");
    *ImageNtHeader = GetProcAddress(v58, "ImageNtHeader");
  }
  *FindExecutableImageExW = GetProcAddress(hModule, "FindExecutableImageExW");
  if ( *FindExecutableImageExW )
  {
    *FindExecutableImageExW_0 = FindExecutableImageExW_1;
  }
  else
  {
    v59 = LoadLibraryW(L"imagehlp.dll");
    FindExecutableImage = GetProcAddress(v59, "FindExecutableImage");
    v61 = 0;
    ::FindExecutableImage = FindExecutableImage;
    if ( FindExecutableImage )
      v61 = sub_103BC50;
    *FindExecutableImageExW_0 = v61;
  }
  v62 = GetModuleHandleW(L"ntdll.dll");
  NtSuspendProcess = GetProcAddress(v62, "NtSuspendProcess");
  v63 = GetModuleHandleW(L"ntdll.dll");
  NtResumeProcess = GetProcAddress(v63, "NtResumeProcess");
  v64 = GetModuleHandleW(L"kernel32.dll");
  QueryProcessCycleTime = GetProcAddress(v64, "QueryProcessCycleTime");
  v65 = GetModuleHandleW(L"kernel32.dll");
  QueryIdleProcessorCycleTime = GetProcAddress(v65, "QueryIdleProcessorCycleTime");
  v66 = GetModuleHandleW(L"kernel32.dll");
  QueryThreadCycleTime = GetProcAddress(v66, "QueryThreadCycleTime");
  v67 = GetModuleHandleW(L"Shell32.dll");
  SHGetStockIconInfo = GetProcAddress(v67, "SHGetStockIconInfo");
  v68 = GetModuleHandleW(L"kernel32.dll");
  *CreateJobObjectW = GetProcAddress(v68, "CreateJobObjectW");
  v69 = GetModuleHandleW(L"user32.dll");
  ChangeWindowMessageFilter = GetProcAddress(v69, "ChangeWindowMessageFilter");
  v70 = LoadLibraryW(L"advapi32.dll");
  I_QueryTagInformation = GetProcAddress(v70, "I_QueryTagInformation");
  v71 = LoadLibraryW(L"wow64cpu");
  CpuGetContext = GetProcAddress(v71, "CpuGetContext");
  v72 = LoadLibraryW(L"kernel32.dll");
  GetProcessorSystemCycleTime = GetProcAddress(v72, "GetProcessorSystemCycleTime");
  v73 = LoadLibraryW(L"kernel32.dll");
  GetThreadIdealProcessorEx = GetProcAddress(v73, "GetThreadIdealProcessorEx");
  v74 = LoadLibraryW(L"user32.dll");
  IsImmersiveProcess = GetProcAddress(v74, "IsImmersiveProcess");
  v75 = LoadLibraryW(L"kernel32.dll");
  GetPackageFullName = GetProcAddress(v75, "GetPackageFullName");
  return 1;
}
// 10A3420: using guessed type wchar_t aNtdllNtquerysy[31];
// 10A3480: using guessed type wchar_t aNtdllNtquerysy_0[32];
// 10A34D8: using guessed type wchar_t aNtdllNtquerydi[29];
// 10A3530: using guessed type wchar_t aNtdllNtopensym[31];
// 10A3588: using guessed type wchar_t aNtdllNtopendir[28];
// 10A35D0: using guessed type wchar_t aNtdllNtqueryob[20];
// 10A3618: using guessed type wchar_t aNtdllNtqueryin[32];
// 10A3670: using guessed type wchar_t aNtdllNtsetinfo[30];
// 10A36C0: using guessed type wchar_t aNtdllNtqueryse[23];
// 10A3700: using guessed type wchar_t aNtdllNtqueryse_0[21];
// 10A373C: using guessed type wchar_t aNtdllNtqueryev[19];
// 10A3774: using guessed type wchar_t aNtdllNtquerymu[20];
// 10A37AC: using guessed type wchar_t aNtdllNtresumet[21];
// 10A37E8: using guessed type wchar_t aNtdllNtsuspend[22];
// 10A3824: using guessed type wchar_t aNtdllNtopenthr[19];
// 10A3868: using guessed type wchar_t aNtdllNtqueryin_0[31];
// 10A38C0: using guessed type wchar_t aNtdllNtqueryvi[27];
// 10A3918: using guessed type wchar_t aNtdllRtlcreate[32];
// 10A3978: using guessed type wchar_t aNtdllRtlqueryp[38];
// 10A39E0: using guessed type wchar_t aNtdllRtldestro[33];
// 10A3A38: using guessed type wchar_t aNtdllRtltimeto[26];
// 10A3AC8: using guessed type wchar_t aAcleditSeddisc[34];
// 10A3B20: using guessed type wchar_t aAcleditSedsyst[27];
// 10A3B6C: using guessed type wchar_t aAcleditSedtake[25];
// 10CB1C8: using guessed type int (__stdcall *NtSetInformationProcess)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10CF220: using guessed type int RtlTimeToTimeFields;
// 10CF224: using guessed type int NtQueryDirectoryObject;
// 10CF228: using guessed type int (__stdcall *NtSetInformationProcess_0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10CF260: using guessed type int (__stdcall *RtlQueryProcessDebugInformation)(_DWORD, _DWORD, _DWORD);
// 10CF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 10CF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);
// 10CF2F4: using guessed type int GetProcessorSystemCycleTime;
// 10CF32C: using guessed type int SetThreadGroupAffinity;
// 10CF334: using guessed type int (__stdcall *WTSDisconnectSession)(_DWORD, _DWORD, _DWORD);
// 10CF338: using guessed type int (__stdcall *WinStationConnectW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10CF33C: using guessed type int (__stdcall *WinStationShadow)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10CF34C: using guessed type int (__stdcall *WTSLogoffSessio)(_DWORD, _DWORD, _DWORD);
// 10CF350: using guessed type int (__stdcall *WTSSendMessageW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10CF360: using guessed type int (__stdcall *ChangeWindowMessageFilter)(_DWORD, _DWORD);
// 10CF364: using guessed type int CpuGetContext;
// 10CF36C: using guessed type int (__stdcall *GetProcessDpiAwareness)(_DWORD, _DWORD);
// 10DBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);
// 10DBA50: using guessed type int (__stdcall *SHGetStockIconInfo)(_DWORD, _DWORD, _DWORD);

//----- (010401B0) --------------------------------------------------------
char InitTlhlpApis()
{
  HMODULE v0; // eax
  HMODULE v2; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  HMODULE v8; // eax
  HMODULE v9; // eax
  HMODULE v10; // eax

  v0 = GetModuleHandleW(L"kernel32.dll");
  *CreateToolhelp32Snapshot_0 = GetProcAddress(v0, "CreateToolhelp32Snapshot");
  if ( !*CreateToolhelp32Snapshot_0 )
    return 0;
  v2 = GetModuleHandleW(L"kernel32.dll");
  *Process32FirstW_0 = GetProcAddress(v2, "Process32FirstW");
  if ( !*Process32FirstW_0 )
    return 0;
  v3 = GetModuleHandleW(L"kernel32.dll");
  *Process32NextW_0 = GetProcAddress(v3, "Process32NextW");
  if ( !*Process32NextW_0 )
    return 0;
  v4 = GetModuleHandleW(L"kernel32.dll");
  *Thread32First_0 = GetProcAddress(v4, "Thread32First");
  if ( !*Thread32First_0 )
    return 0;
  v5 = GetModuleHandleW(L"kernel32.dll");
  *Thread32Next_0 = GetProcAddress(v5, "Thread32Next");
  if ( !*Thread32Next_0 )
    return 0;
  v6 = GetModuleHandleW(L"kernel32.dll");
  *Module32FirstW_0 = GetProcAddress(v6, "Module32FirstW");
  if ( !*Module32FirstW_0 )
    return 0;
  v7 = GetModuleHandleW(L"kernel32.dll");
  *Module32NextW_0 = GetProcAddress(v7, "Module32NextW");
  if ( !*Module32NextW_0 )
    return 0;
  v8 = LoadLibraryW(L"dbghelp.dll");
  *ImageNtHeader = GetProcAddress(v8, "ImageNtHeader");
  if ( !*ImageNtHeader )
  {
    v9 = LoadLibraryW(L"imagehlp.dll");
    *ImageNtHeader = GetProcAddress(v9, "ImageNtHeader");
  }
  v10 = LoadLibraryW(L"user32.dll");
  IsHungThread = GetProcAddress(v10, "IsHungThread");
  return 1;
}
// 10CF320: using guessed type int IsHungThread;

//----- (010402C0) --------------------------------------------------------
void __cdecl QueryProcessArguments(HANDLE hProcess, ULONG_PTR dwProcessId, WCHAR **ppszCommandLine, WCHAR **ppszCurrentDirectory, WCHAR **ppszEnvBlock, PDWORD pbFlagsInExtendedProcessBasicInfo)
{
  PDWORD pdwValue6In; // eax
  WCHAR **ppszCommandLineIn; // edi
  WCHAR **ppszCurrentDirectoryIn; // esi
  WCHAR **ppszEnvBlockIn; // ebx
  WCHAR *v10; // eax
  _PROCESS_EXTENDED_BASIC_INFORMATION ProcessInformation; // [esp+0h] [ebp-20h]

  pdwValue6In = pbFlagsInExtendedProcessBasicInfo;
  ProcessInformation.Size = 0;
  *&ProcessInformation.BasicInfo.UniqueProcessId = 0i64;
  ProcessInformation.Flags = 0;
  _mm_storeu_si128(&ProcessInformation.BasicInfo, 0i64);
  if ( pdwValue6In )
    *pdwValue6In = 0;
  ppszCommandLineIn = ppszCommandLine;
  if ( ppszCommandLine )
    *ppszCommandLine = 0;
  ppszCurrentDirectoryIn = ppszCurrentDirectory;
  if ( ppszCurrentDirectory )
    *ppszCurrentDirectory = 0;
  ppszEnvBlockIn = ppszEnvBlock;
  if ( ppszEnvBlock )
    *ppszEnvBlock = 0;
  if ( hProcess )
  {
    ProcessInformation.Size = 0x20;
    if ( !NtQueryInformationProcess(
            hProcess,
            ProcessBasicInformation,
            &ProcessInformation,
            sizeof(_PROCESS_EXTENDED_BASIC_INFORMATION),
            &ppszCommandLine)
      || !NtQueryInformationProcess(
            hProcess,
            ProcessBasicInformation,
            &ProcessInformation.BasicInfo,
            sizeof(PROCESS_BASIC_INFORMATION),
            &ppszCommandLine) )
    {
      if ( pbFlagsInExtendedProcessBasicInfo )
        *pbFlagsInExtendedProcessBasicInfo = ProcessInformation.Flags & 1;
      if ( ProcessInformation.BasicInfo.PebBaseAddress )
        QueryProcessCommandLineArgs(
          hProcess,
          ProcessInformation.BasicInfo.PebBaseAddress,
          ppszCommandLineIn,
          ppszCurrentDirectoryIn,
          ppszEnvBlockIn);
      if ( ppszCurrentDirectoryIn )
      {
        if ( *ppszCurrentDirectoryIn )
          PE_GetFullPathName(ppszCurrentDirectoryIn);
        else
          *ppszCurrentDirectoryIn = _wcsdup(&gszNullString);
      }
      if ( ppszCommandLineIn && !*ppszCommandLineIn )
        *ppszCommandLineIn = _wcsdup(&gszNullString);
      if ( ppszEnvBlockIn )
      {
        if ( !*ppszEnvBlockIn )
        {
          v10 = _wcsdup(L" ");
          *ppszEnvBlockIn = v10;
          *v10 = 0;
        }
      }
    }
  }
}

//----- (010403E0) --------------------------------------------------------
char __cdecl sub_10403E0(HANDLE hProcess, DWORD dwPid, LPCWSTR lpszProcessName, LPVOID *ppBufer, PDWORD pdwSize)
{
  HANDLE v5; // ebx
  HANDLE v6; // ebx
  const wchar_t *v7; // eax
  WCHAR *v8; // edi
  DWORD v9; // eax
  DWORD v10; // ebx
  SIZE_T v12; // edi
  WCHAR *v13; // esi
  void *v14; // edi
  int v15; // ebx
  IAtlStringMgr *v16; // eax
  volatile signed __int32 *v17; // edi
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+10h] [ebp-474h]
  WCHAR *v19; // [esp+2Ch] [ebp-458h]
  PDWORD v20; // [esp+30h] [ebp-454h]
  WCHAR *v21; // [esp+34h] [ebp-450h]
  wchar_t *v22; // [esp+38h] [ebp-44Ch]
  LPVOID *v23; // [esp+3Ch] [ebp-448h]
  wchar_t *v24; // [esp+40h] [ebp-444h]
  size_t SizeInWords; // [esp+44h] [ebp-440h]
  HANDLE v26; // [esp+48h] [ebp-43Ch]
  MODULEENTRY32W me; // [esp+4Ch] [ebp-438h]
  int v28; // [esp+480h] [ebp-4h]

  v5 = hProcess;
  v22 = lpszProcessName;
  v23 = ppBufer;
  v20 = pdwSize;
  v26 = hProcess;
  v24 = dwPid;
  if ( *CreateToolhelp32Snapshot_0 )
  {
    v6 = CreateToolhelp32Snapshot_0(8u, dwPid);
    v26 = v6;
    if ( v6 != -1 )
    {
      me.dwSize = 1064;
      if ( Module32FirstW_0(v6, &me) )
      {
        do
        {
          v28 = 0;
          if ( !wcsncmp(me.szExePath, L"\\??\\", 4u) )
          {
            v7 = &me.szExePath[4];
          }
          else
          {
            if ( !_wcsnicmp(me.szExePath, L"\\Systemroot\\", 0xCu) )
            {
              SizeInWords = ExpandEnvironmentStringsW(L"%SystemRoot%", 0, 0) + 1 + wcslen(me.szExePath);
              v8 = malloc(2 * SizeInWords);
              v21 = v8;
              ExpandEnvironmentStringsW(L"%SystemRoot%", v8, SizeInWords);
              wcscat_s(v8, SizeInWords, &me.szExePath[11]);
              goto LABEL_10;
            }
            v7 = me.szExePath;
          }
          v8 = _wcsdup(v7);
          v21 = v8;
LABEL_10:
          if ( *GetLongPathNameW )
          {
            v9 = GetLongPathNameW(v8, 0, 0);
            v10 = v9;
            if ( v9 )
            {
              v19 = malloc(2 * v9 + 2);
              LOBYTE(v28) = 1;
              GetLongPathNameW(v8, v19, v10 + 1);
              free(v8);
              v8 = v19;
              LOBYTE(v28) = 0;
              j__free(0);
            }
            v6 = v26;
          }
          if ( me.th32ProcessID == v24 && !_wcsicmp(v22, v8) )
          {
            *v23 = me.modBaseAddr;
            *v20 = me.modBaseSize;
            j__free(v8);
            return 1;
          }
          v28 = -1;
          j__free(v8);
        }
        while ( Module32NextW_0(v6, &me) );
      }
      CloseHandle(v6);
    }
    return 0;
  }
  Buffer.BaseAddress = 0;
  if ( !VirtualQueryEx(hProcess, 0, &Buffer, 0x1Cu) )
    return 0;
  while ( 1 )
  {
    if ( Buffer.Type != 0x40000
      || NtQueryVirtualMemory(v5, Buffer.BaseAddress, MemoryMappedFilenameInformation, 0, 0, &SizeInWords) != STATUS_INFO_LENGTH_MISMATCH )
    {
      goto LABEL_30;
    }
    v12 = SizeInWords;
    v13 = malloc(SizeInWords);
    v19 = v13;
    v28 = 2;
    if ( !NtQueryVirtualMemory(v5, Buffer.BaseAddress, MemoryMappedFilenameInformation, v13, v12, &SizeInWords) )
      break;
LABEL_29:
    v28 = -1;
    j__free(v13);
LABEL_30:
    Buffer.BaseAddress = Buffer.BaseAddress + Buffer.RegionSize;
    if ( !VirtualQueryEx(v5, Buffer.BaseAddress, &Buffer, 0x1Cu) )
      return 0;
  }
  v14 = *(v13 + 1);
  v15 = *v13 >> 1;
  v16 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  sub_100CF80(&v24, v14, v15, v16);
  v17 = (v24 - 8);
  if ( _wcsicmp(v24, v22) )
  {
    if ( _InterlockedDecrement(v17 + 3) <= 0 )
      (*(**v17 + 4))(v17);
    v5 = v26;
    goto LABEL_29;
  }
  *v23 = Buffer.BaseAddress;
  *v20 = Buffer.RegionSize;
  if ( _InterlockedDecrement(v17 + 3) <= 0 )
    (*(**v17 + 4))(v17);
  j__free(v13);
  return 1;
}

//----- (010407B0) --------------------------------------------------------
DWORD __cdecl LoadSystemModulesSymbolAddress(LPCWSTR lpszName)
{
  RTL_PROCESS_MODULES *ProcessModules; // edi
  ULONG v2; // esi
  ULONG Index; // esi
  const CHAR *v4; // ebx
  const wchar_t **v5; // eax
  CStringData *v6; // eax
  int BaseOfDll_1; // ebx
  HANDLE hFile; // edi
  HANDLE v9; // eax
  DWORD result; // eax
  HANDLE hProcess; // eax
  __int64 v12; // rax
  HANDLE v13; // eax
  const CHAR *Name_1; // ST1C_4
  HANDLE hProcess_1; // eax
  int v16; // eax
  HANDLE v17; // eax
  struct _MODLOAD_DATA *Data; // [esp-Ch] [ebp-740h]
  DWORD Flags; // [esp-8h] [ebp-73Ch]
  CStringData *v20; // [esp+0h] [ebp-734h]
  CString strFullPathName; // [esp+4h] [ebp-730h]
  PCSTR Name; // [esp+8h] [ebp-72Ch]
  DWORD64 BaseOfDll; // [esp+Ch] [ebp-728h]
  WCHAR szDir[260]; // [esp+14h] [ebp-720h]
  WCHAR FileName[260]; // [esp+21Ch] [ebp-518h]
  wchar_t ImageName[260]; // [esp+424h] [ebp-310h]
  IMAGEHLP_SYMBOL Symbol; // [esp+62Ch] [ebp-108h]

  Name = lpszName;
  if ( !SymCleanup || !SymInitialize || !SymLoadModuleExW_1 || !SymGetSymFromName )
    return 0;
  HIDWORD(BaseOfDll) = 1000;
  ProcessModules = malloc(0x3E8u);
  if ( NtQuerySystemInformation(SystemModuleInformation, ProcessModules, 0x3E8u, &BaseOfDll + 1) )
  {
    do
    {
      HIDWORD(BaseOfDll) += 1000;
      free(ProcessModules);
      v2 = HIDWORD(BaseOfDll);
      ProcessModules = malloc(HIDWORD(BaseOfDll));
    }
    while ( NtQuerySystemInformation(SystemModuleInformation, ProcessModules, v2, &BaseOfDll + 1) );
  }
  if ( IsPAEEnabled() )
    wcscpy_s(ImageName, MAX_PATH, L"ntkrnlpa.exe");
  else
    wcscpy_s(ImageName, MAX_PATH, L"ntoskrnl.exe");
  Index = 0;
  if ( ProcessModules->NumberOfModules )
  {
    v4 = ProcessModules->Modules[0].FullPathName;
    while ( 1 )
    {
      v5 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
             &strFullPathName,
             v4);
      LODWORD(BaseOfDll) = wcsstr(*v5, ImageName);
      v6 = (strFullPathName.pszData - 16);
      v20 = (strFullPathName.pszData - 16);
      if ( _InterlockedDecrement(strFullPathName.pszData - 1) <= 0 )
        (v6->pStringMgr->vtptr->Free)(v20);
      if ( BaseOfDll )
        break;
      ++Index;
      v4 += sizeof(RTL_PROCESS_MODULE_INFORMATION);
      if ( Index >= ProcessModules->NumberOfModules )
        goto LABEL_16;
    }
    BaseOfDll_1 = ProcessModules->Modules[Index].ImageBase;
  }
  else
  {
LABEL_16:
    BaseOfDll_1 = BaseOfDll;
  }
  free(ProcessModules);
  GetSystemDirectoryW(szDir, MAX_PATH);
  swprintf(FileName, L"%s\\%s", szDir, ImageName);
  hFile = CreateFileW(FileName, GENERIC_READ, 3u, 0, OPEN_EXISTING, 0, 0);
  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  v9 = GetCurrentThread();
  if ( SymInitialize(v9, 0, 0) )
  {
    hProcess = GetCurrentThread();
    LODWORD(v12) = SymLoadModuleExW_1(hProcess, hFile, ImageName, 0, BaseOfDll_1, 0, Data, Flags);
    if ( v12 )
    {
      Symbol.SizeOfStruct = sizeof(IMAGEHLP_SYMBOL);
      Name_1 = Name;
      Symbol.MaxNameLength = 237;
      hProcess_1 = GetCurrentThread();
      v16 = SymGetSymFromName(hProcess_1, Name_1, &Symbol);
      Symbol.Address &= -(v16 != 0);
      CloseHandle(hFile);
      v17 = GetCurrentThread();
      SymCleanup(v17);
      LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
      result = Symbol.Address;
    }
    else
    {
      CloseHandle(hFile);
      v13 = GetCurrentThread();
      SymCleanup(v13);
      LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
      result = 0;
    }
  }
  else
  {
    LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    CloseHandle(hFile);
    result = 0;
  }
  return result;
}
// 10A56FC: using guessed type wchar_t aNtkrnlpaExe[13];
// 10409BE: user specified stroff has not been processed: RTL_PROCESS_MODULE_INFORMATION offset 284

//----- (01040A90) --------------------------------------------------------
char __cdecl sub_1040A90(HANDLE hProcess, DWORD dwProcessId, LPWSTR *ppszFileName, tagTREEVIEWLISTITEMPARAM *pItem)
{
  DWORD dwIndex; // eax
  WCHAR **v5; // ecx
  SC_HANDLE hService; // ebx
  DWORD v8; // esi
  wchar_t *pstr; // eax
  LPWSTR v10; // eax
  LPWSTR v11; // ecx
  int v12; // edx
  WCHAR v13; // ax
  rsize_t v14; // edi
  wchar_t *v15; // eax
  const wchar_t **v16; // esi
  DWORD v17; // eax
  DWORD v18; // edi
  WCHAR *v19; // eax
  DWORD v20; // eax
  DWORD v21; // esi
  WCHAR *v22; // eax
  LPWSTR v23; // ecx
  WCHAR v24; // ax
  struct _QUERY_SERVICE_CONFIGW *pServiceConfig; // [esp+Ch] [ebp-21Ch]
  LPWSTR *ppszFileNameIn; // [esp+14h] [ebp-214h]
  DWORD dwRet; // [esp+18h] [ebp-210h]
  __int16 Src[260]; // [esp+1Ch] [ebp-20Ch]

  ppszFileNameIn = ppszFileName;
  *ppszFileName = 0;
  if ( !hProcess )
  {
    if ( pItem->dwStyle & TVLS_SHOWSERVICE )
    {
      dwIndex = 0;
      if ( gdwServiceReturned )
      {
        v5 = gpszServiceNames + 9;
        while ( *v5 != dwProcessId )
        {
          ++dwIndex;
          v5 += 11;
          if ( dwIndex >= gdwServiceReturned )
            return 0;
        }
        hService = OpenServiceW(ghSCManagerHandle, gpszServiceNames[11 * dwIndex], 5u);
        QueryServiceConfigW(hService, 0, 0, &dwRet);
        v8 = dwRet;
        pServiceConfig = malloc(dwRet);
        QueryServiceConfigW(hService, pServiceConfig, v8, &dwRet);
        if ( pServiceConfig->lpBinaryPathName )
        {
          if ( !pItem->pszCommandLine )
            pItem->pszCommandLine = _wcsdup(pServiceConfig->lpBinaryPathName);
          pstr = wcsstr(pServiceConfig->lpBinaryPathName, L".exe");
          if ( pstr && pstr[4] )
            pstr[4] = 0;
          v10 = pServiceConfig->lpBinaryPathName;
          if ( *v10 == '"' )
            pServiceConfig->lpBinaryPathName = v10 + 1;
          v11 = pServiceConfig->lpBinaryPathName;
          v12 = (v11 + 1);
          do
          {
            v13 = *v11;
            ++v11;
          }
          while ( v13 );
          v14 = ((v11 - v12) >> 1) + 5;
          v15 = malloc(2 * v14);
          v16 = ppszFileNameIn;
          *ppszFileNameIn = v15;
          wcscpy_s(v15, v14, pServiceConfig->lpBinaryPathName);
          free(pServiceConfig);
          if ( GetFileAttributesW(*v16) == -1 )
          {
            if ( **v16 != 34 && wcschr(*v16, ' ') )
              *wcschr(*v16, ' ') = 0;
            if ( GetFileAttributesW(*v16) == -1 )
              wcscat_s(*v16, v14, L".exe");
          }
          return 1;
        }
        free(pServiceConfig);
      }
    }
    return 0;
  }
  if ( !sub_103CF30(hProcess, ppszFileName) )
  {
    v17 = GetModuleFileNameExW(hProcess, 0, &ppszFileNameIn, 2u);
    v18 = v17;
    if ( !v17 )
      return 0;
    v19 = malloc(2 * v17 + 2);
    *ppszFileName = v19;
    if ( !GetModuleFileNameExW(hProcess, 0, v19, v18) )
      return 0;
  }
  if ( !_wcsnicmp(*ppszFileName, L"\\SystemRoot\\", 0xCu) )
  {
    swprintf(Src, L"%%SystemRoot%%\\%s", *ppszFileName + 12);
    v20 = ExpandEnvironmentStringsW(Src, 0, 0);
    v21 = v20;
    v22 = malloc(2 * v20);
    *ppszFileName = v22;
    ExpandEnvironmentStringsW(Src, v22, v21);
    return 1;
  }
  if ( !wcsncmp(*ppszFileName, L"\\??\\", 4u) )
  {
    v23 = *ppszFileName;
    do
    {
      v24 = *v23;
      ++v23;
    }
    while ( v24 );
    wcscpy_s(*ppszFileName, v23 - (*ppszFileName + 1), *ppszFileName + 4);
  }
  return 1;
}

//----- (01040D70) --------------------------------------------------------
PE_ImageItemVerified *__cdecl PE_ImageItemVerified_Find(wchar_t *pszText)
{
  PE_ImageItemVerified *v1; // esi
  PE_ImageItemVerified *result; // eax

  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  v1 = gpPE_ImageItemVerified;
  if ( gpPE_ImageItemVerified )
  {
    while ( _wcsicmp(v1->pszText1, pszText) )
    {
      v1 = v1->pNext;
      if ( !v1 )
        goto LABEL_4;
    }
    LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    result = v1;
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    result = 0;
  }
  return result;
}

//----- (01040DD0) --------------------------------------------------------
void __cdecl sub_1040DD0(wchar_t *a1)
{
  int v1; // edi
  wchar_t *v2; // ebx
  WCHAR *v3; // ecx
  size_t v4; // esi
  int v5; // edx
  unsigned int v6; // ecx
  WCHAR *v7; // esi
  WCHAR v8; // ax
  int v9; // esi
  WCHAR *v10; // edx
  int v11; // esi
  int v12; // edi
  WCHAR v13; // ax

  v1 = 0;
  if ( gszDriverLinkName[0] )
  {
    v2 = a1;
    v3 = gszDriverLinkName;
    while ( 1 )
    {
      v4 = wcslen(v3);
      if ( !_wcsnicmp(v3, v2, v4) && v2[v4] == 92 )
        break;
      v3 = &gszDriverLinkName[257 * ++v1];
      if ( !gszDriverLinkName[257 * v1] )
        return;
    }
    v5 = 257 * v1;
    *v2 = gszDriverName[0][257 * v1];
    v2[1] = 58;
    v6 = wcslen(v2);
    v7 = &gszDriverLinkName[257 * v1 + 1];
    do
    {
      v8 = *v7;
      ++v7;
    }
    while ( v8 );
    v9 = v7 - &gszDriverLinkName[v5 + 2];
    v10 = &gszDriverLinkName[v5];
    v11 = v9 >> 1;
    v12 = (v10 + 1);
    do
    {
      v13 = *v10;
      ++v10;
    }
    while ( v13 );
    memmove_0(v2 + 2, &v2[(v10 - v12) >> 1], 2 * (v6 - v11));
    sub_103C270(&a1, 0x104u);
  }
}

//----- (01040EE0) --------------------------------------------------------
int __cdecl sub_1040EE0(wchar_t *pszBuffer)
{
  int nIndex; // ebx
  size_t *pszPosition; // esi
  int v3; // ebx
  RegItem *v4; // esi
  int result; // eax
  int ret; // eax
  char found; // cl
  wchar_t *pszText; // esi
  wchar_t i; // ax
  const wchar_t *v10; // esi
  char found_1; // [esp+Ch] [ebp-Ch]

  nIndex = 0;
  pszPosition = &stru_10C0320[0].field_240;
  do
  {
    if ( !_wcsnicmp(pszBuffer, pszPosition - 288, *pszPosition)
      && !_wcsnicmp(&pszBuffer[*pszPosition], gpszCurAuthInfo, wcslen(gpszCurAuthInfo)) )
    {
      ret = _wcsnicmp(&pszBuffer[wcslen(gpszCurAuthInfo) + stru_10C0320[nIndex].field_240], L"_Classes", 8u);
      found = 0;
      if ( !ret )
        found = 1;
      found_1 = found;
      pszText = &pszBuffer[stru_10C0320[nIndex].field_240];
      for ( i = *pszText; i; ++pszText )
      {
        if ( i == '\\' )
          break;
        i = pszText[1];
      }
      wcscpy_s(pszBuffer, pszText - pszBuffer, &stru_10C0320[nIndex].gap4[508]);
      if ( found_1 )
        wcscat_s(pszBuffer, pszText - pszBuffer, L"\\Software\\Classes");
      return wcscat_s(pszBuffer, 1024u, pszText);
    }
    pszPosition += 145;
    ++nIndex;
  }
  while ( pszPosition < &stru_10C0320[2].field_240 );
  v3 = 0;
  v4 = &stru_10C0320[2];
  while ( 1 )
  {
    result = _wcsnicmp(pszBuffer, v4, v4->field_240);
    if ( !result )
      break;
    ++v4;
    ++v3;
    if ( v4 >= gdwValue_4F10B8 )
      return result;
  }
  v10 = &pszBuffer[stru_10C0320[v3 + 2].field_240];
  wcscpy_s(pszBuffer, 2 * stru_10C0320[v3 + 2].field_240 >> 1, &stru_10C0320[v3 + 2].gap4[508]);
  return wcscat_s(pszBuffer, 1024u, v10);
}
// 10C0320: using guessed type RegItem stru_10C0320[4];
// 10C10B8: using guessed type int gdwValue_4F10B8[3];

//----- (01041080) --------------------------------------------------------
char __cdecl ReportMsg(int ArgList)
{
  WCHAR Text; // [esp+0h] [ebp-20Ch]

  swprintf(&Text, L"Not able to run on this version of Windows:\nMissing function: %s", ArgList);
  MessageBoxW(0, &Text, L"Process Explorer", 0x10u);
  return 0;
}

//----- (010410E0) --------------------------------------------------------
signed int __userpurge PropHandleInfo@<eax>(char a1@<bl>, HWND hWnd, unsigned int a2, unsigned __int16 a3, int a4)
{
  HWND v6; // eax
  POINT v7; // ST18_8
  DWORD v8; // esi
  const WCHAR *v9; // ebx
  bool v10; // cl
  const WCHAR *v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  const wchar_t *v16; // eax
  const wchar_t *v17; // eax
  int v18; // eax
  void (__stdcall *v19)(HANDLE); // ebx
  const wchar_t *v20; // eax
  int v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  char v25; // [esp-4h] [ebp-6D4h]
  char v26; // [esp-4h] [ebp-6D4h]
  int ThreadInformation; // [esp+8h] [ebp-6C8h]
  DWORD dwProcessId; // [esp+10h] [ebp-6C0h]
  int InformationBuffer; // [esp+24h] [ebp-6ACh]
  int v30; // [esp+28h] [ebp-6A8h]
  char v31[4]; // [esp+2Ch] [ebp-6A4h]
  ULONG ResultLength; // [esp+34h] [ebp-69Ch]
  struct _FILETIME LocalFileTime; // [esp+38h] [ebp-698h]
  FILETIME FileTime; // [esp+40h] [ebp-690h]
  int EventInformation; // [esp+48h] [ebp-688h]
  int v36; // [esp+4Ch] [ebp-684h]
  int MutantInformation; // [esp+50h] [ebp-680h]
  char v38; // [esp+55h] [ebp-67Bh]
  struct tagPOINT Point; // [esp+58h] [ebp-678h]
  char v40[4]; // [esp+60h] [ebp-670h]
  char v41[4]; // [esp+64h] [ebp-66Ch]
  ULONG ReturnLength; // [esp+68h] [ebp-668h]
  struct _UNICODE_STRING LinkTarget; // [esp+6Ch] [ebp-664h]
  void *OutBuffer; // [esp+74h] [ebp-65Ch]
  DWORD BytesReturned; // [esp+78h] [ebp-658h]
  ULONG ReturnedLength; // [esp+7Ch] [ebp-654h]
  void *InBuffer; // [esp+80h] [ebp-650h]
  int ObjectInformation; // [esp+84h] [ebp-64Ch]
  int v49; // [esp+8Ch] [ebp-644h]
  int v50; // [esp+90h] [ebp-640h]
  char ArgList[4]; // [esp+94h] [ebp-63Ch]
  char v52[4]; // [esp+98h] [ebp-638h]
  FILETIME v53; // [esp+B4h] [ebp-61Ch]
  struct _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-614h]
  char v55; // [esp+CCh] [ebp-604h]
  wchar_t Dst; // [esp+2CCh] [ebp-404h]
  WCHAR String; // [esp+4CCh] [ebp-204h]

  if ( a2 == 16 )
    goto LABEL_5;
  if ( a2 == 272 )
  {
    v25 = a1;
    GetCursorPos(&Point);
    v6 = GetParent(hWnd);
    sub_103BDA0(v6);
    v7.y = Point.y - 430;
    v7.x = Point.x - 375;
    PE_SetWindowPlacement(hWnd, v7);
    PostMessageW(hWnd, 0x46Bu, 0, 0);
    v8 = *(a4 + 28);
    BytesReturned = v8;
    v9 = (v8 + 56);
    v10 = !_wcsicmp((v8 + 56), L"Mutant")
       || !_wcsicmp((v8 + 56), L"Section")
       || !_wcsicmp((v8 + 56), L"Event")
       || !_wcsicmp((v8 + 56), L"Semaphore");
    InBuffer = PE_DuplicateProcessHandle(*(v8 + 36), *(v8 + 44), v10 != 0);
    if ( !InBuffer )
    {
      if ( *(v8 + 16) == 1 )
        MessageBoxW(ghMainWnd, L"Object does not exist.", L"Object Properties Error", 0x10u);
      else
        MessageBoxW(ghMainWnd, L"Unable to query the object", L"Object Properties Error", 0x10u);
      v23 = GetParent(hWnd);
      EndDialog(v23, 0);
      v24 = GetParent(hWnd);
      PostMessageW(v24, 0x471u, 5u, 0);
      return 0;
    }
    v11 = (v8 + 2232);
    wsprintf(&String, L"%s Properties", v11);
    SetWindowTextW(hWnd, &String);
    SetDlgItemTextW(hWnd, 1005, v11);
    SetDlgItemTextW(hWnd, 1006, v9);
    if ( _wcsicmp(v9, L"file") )
    {
      if ( _wcsicmp(v9, L"directory") )
      {
        if ( _wcsicmp(v9, L"symboliclink") )
        {
          if ( _wcsicmp(v9, L"key") )
          {
            if ( _wcsicmp(v9, L"process") )
            {
              v12 = wcscmp(v9, L"thread");
              if ( v12 )
                v12 = -(v12 < 0) | 1;
              if ( v12 )
              {
                if ( _wcsicmp(v9, L"iocompletion") )
                {
                  if ( _wcsicmp(v9, L"mutant") )
                  {
                    if ( _wcsicmp(v9, L"event") && _wcsicmp(v9, L"semaphore") )
                    {
                      if ( _wcsicmp(v9, L"windowstation") )
                      {
                        if ( _wcsicmp(v9, L"desktop") )
                        {
                          if ( _wcsicmp(v9, L"port") && _wcsicmp(v9, L"waitableport") )
                          {
                            if ( _wcsicmp(v9, L"section") )
                            {
                              if ( _wcsicmp(v9, L"token") )
                              {
                                if ( !_wcsicmp(v9, L"timer") )
                                  SetDlgItemTextW(hWnd, 1050, L"A time-based synchronization object.");
                              }
                              else
                              {
                                SetDlgItemTextW(hWnd, 1050, L"Identifies a security context.");
                              }
                            }
                            else
                            {
                              SetDlgItemTextW(hWnd, 1050, L"A memory mapped file or paging-file backed memory region.");
                            }
                          }
                          else
                          {
                            SetDlgItemTextW(hWnd, 1050, L"An interprocess communications endpoint.");
                          }
                        }
                        else
                        {
                          SetDlgItemTextW(hWnd, 1050, L"Contains application windows.");
                        }
                      }
                      else
                      {
                        SetDlgItemTextW(hWnd, 1050, L"Contains one or more desktops with windows.");
                      }
                    }
                    else
                    {
                      SetDlgItemTextW(hWnd, 1050, L"A synchronization object.");
                    }
                  }
                  else
                  {
                    SetDlgItemTextW(hWnd, 1050, L"A synchronization object (a Win32 mutex).");
                  }
                }
                else
                {
                  SetDlgItemTextW(hWnd, 1050, L"An asynchronous I/O notification object.");
                }
              }
              else
              {
                SetDlgItemTextW(hWnd, 1050, L"An object that executes program code.");
              }
            }
            else
            {
              SetDlgItemTextW(hWnd, 1050, L"Contains threads, an address space, and handles.");
            }
          }
          else
          {
            SetDlgItemTextW(hWnd, 1050, L"A Registry key.");
          }
        }
        else
        {
          SetDlgItemTextW(hWnd, 1050, L"An Object Manager namespace link.");
        }
      }
      else
      {
        SetDlgItemTextW(hWnd, 1050, L"An Object Manager namespace directory.");
      }
    }
    else
    {
      SetDlgItemTextW(hWnd, 1050, L"A disk file, communications endpoint, or driver interface.");
    }
    wsprintf(&String, L"0x%X", *(BytesReturned + 40));
    SetDlgItemTextW(hWnd, 1051, &String);
    NtQueryObject(InBuffer, 0, &ObjectInformation, 0x38u, &ReturnLength);
    wsprintf(&String, L"%d", v49 - 1);
    SetDlgItemTextW(hWnd, 1008, &String);
    wsprintf(&String, L"%d", v50 - 2);
    SetDlgItemTextW(hWnd, 1019, &String);
    wsprintf(&String, L"%d", ArgList[0]);
    SetDlgItemTextW(hWnd, 1010, &String);
    wsprintf(&String, L"%d", v52[0]);
    SetDlgItemTextW(hWnd, 1013, &String);
    v13 = wcscmp(v9, L"SymbolicLink");
    if ( v13 )
      v13 = -(v13 < 0) | 1;
    if ( !v13 )
    {
      SetDlgItemTextW(hWnd, 1025, L"Symbolic Link Info");
      SetDlgItemTextW(hWnd, 1024, L"Creation Time:");
      FileTime = v53;
      FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
      FileTimeToSystemTime(&LocalFileTime, &SystemTime);
      wsprintf(&String, L"%d:%02d:%02d, %d/%d/%d", SystemTime.wHour);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Link:");
      LinkTarget.MaximumLength = 256;
      LinkTarget.Buffer = &v55;
      if ( gpfn_NtQuerySymbolicLinkObject(InBuffer, &LinkTarget, &ReturnedLength) )
        wcscpy_s(&String, 0x100u, L"<Error Querying Link>");
      else
        wsprintf(&String, L"%s", LinkTarget.Buffer);
      SetDlgItemTextW(hWnd, 1027, &String);
      goto LABEL_94;
    }
    v14 = wcscmp(v9, L"Semaphore");
    if ( v14 )
      v14 = -(v14 < 0) | 1;
    if ( v14 )
    {
      v15 = wcscmp(v9, L"Event");
      if ( v15 )
        v15 = -(v15 < 0) | 1;
      if ( v15 )
      {
        v18 = wcscmp(v9, L"Mutant");
        if ( v18 )
          v18 = -(v18 < 0) | 1;
        if ( !v18 )
        {
          SetDlgItemTextW(hWnd, 1025, L"Mutant Info");
          SetDlgItemTextW(hWnd, 1024, L"Held:");
          NtQueryMutant(InBuffer, 0, &MutantInformation, 8u, &ReturnedLength);
          wsprintf(&String, L"FALSE", v25);
          if ( MutantInformation <= 0
            && (wsprintf(&String, L"TRUE", v26),
                DeviceIoControl(ghDriverHandle, 0x8335002C, &InBuffer, 4u, &OutBuffer, 4u, &BytesReturned, 0))
            && OutBuffer )
          {
            if ( !NtQueryInformationThread(OutBuffer, 0, &ThreadInformation, 0x1Cu, &ReturnLength) )
            {
              SystemProcessInfo_GetSystemProcessName(dwProcessId, 0, &Dst, 0x100u);
              wsprintf(&String, L"%s(%d): %d", &Dst);
            }
            v19 = CloseHandle;
            CloseHandle(OutBuffer);
          }
          else
          {
            v19 = CloseHandle;
          }
          SetDlgItemTextW(hWnd, 1022, &String);
          SetDlgItemTextW(hWnd, 1028, L"Abandoned:");
          v20 = L"TRUE";
          if ( !v38 )
            v20 = L"FALSE";
          wsprintf(&String, L"%s", v20);
          SetDlgItemTextW(hWnd, 1027, &String);
          v19(InBuffer);
          return 1;
        }
        v21 = wcscmp(v9, L"Section");
        if ( v21 )
          v21 = -(v21 < 0) | 1;
        if ( v21 )
        {
          v22 = GetDlgItem(hWnd, 1025);
          ShowWindow(v22, 0);
        }
        else
        {
          SetDlgItemTextW(hWnd, 1025, L"Section Info");
          NtQuerySection(InBuffer, 0, &InformationBuffer, 0x10u, &ResultLength);
          if ( v30 & 0x1000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"IMAGE");
          }
          else if ( v30 & 0x800000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"FILE");
          }
          else if ( v30 & 0x4000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"RESERVED");
          }
          else if ( v30 & 0x8000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"COMMITED");
          }
          SetDlgItemTextW(hWnd, 1022, &String);
          SetDlgItemTextW(hWnd, 1028, L"Size:");
          wsprintf(&String, L"0x%08x", v31[0]);
          SetDlgItemTextW(hWnd, 1027, &String);
        }
LABEL_94:
        CloseHandle(InBuffer);
        return 1;
      }
      SetDlgItemTextW(hWnd, 1025, L"Event Info");
      SetDlgItemTextW(hWnd, 1024, L"Type:");
      NtQueryEvent(InBuffer, 0, &EventInformation, 8u, &ReturnedLength);
      v16 = L"Notification";
      if ( EventInformation )
        v16 = L"Synchronization";
      wsprintf(&String, L"%s", v16);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Signaled:");
      v17 = L"TRUE";
      if ( !v36 )
        v17 = L"FALSE";
      wsprintf(&String, L"%s", v17);
    }
    else
    {
      SetDlgItemTextW(hWnd, 1025, L"Semaphore Info");
      SetDlgItemTextW(hWnd, 1024, L"Count:");
      NtSetInformationProcess_0(InBuffer, 0, v40, 8, &ReturnedLength);
      wsprintf(&String, L"%d", v40[0]);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Limit:");
      wsprintf(&String, L"%d", v41[0]);
    }
    SetDlgItemTextW(hWnd, 1027, &String);
    goto LABEL_94;
  }
  if ( a2 == 273 && a3 - 1 <= 1 )
  {
LABEL_5:
    DestroyWindow(hWnd);
    return 1;
  }
  return 0;
}
// 10410E0: could not find valid save-restore pair for ebx
// 10A48C0: using guessed type wchar_t aADiskFileCommu[59];
// 10A4950: using guessed type wchar_t aAnObjectManage[39];
// 10A49C0: using guessed type wchar_t aAnObjectManage_0[34];
// 10A4A0C: using guessed type wchar_t aARegistryKey[16];
// 10A4A30: using guessed type wchar_t aContainsThread[49];
// 10A4A98: using guessed type wchar_t aAnObjectThatEx[38];
// 10A4B00: using guessed type wchar_t aAnAsynchronous[41];
// 10A4B68: using guessed type wchar_t aASynchronizati[42];
// 10A4C30: using guessed type wchar_t aContainsOneOrM[44];
// 10A4C98: using guessed type wchar_t aContainsApplic[30];
// 10A4D00: using guessed type wchar_t aAnInterprocess[41];
// 10A4D68: using guessed type wchar_t aAMemoryMappedF[58];
// 10A4DDC: using guessed type wchar_t aIdentifiesASec[31];
// 10A4E28: using guessed type wchar_t aATimeBasedSync[37];
// 10A4E74: using guessed type wchar_t aSymboliclink_0[13];
// 10A4FA4: using guessed type wchar_t aNotification[13];
// 10A4FC0: using guessed type wchar_t aSynchronizatio[16];
// 10A504C: using guessed type wchar_t aImage_0[6];
// 10A5058: using guessed type wchar_t aFile_2[5];
// 10A5064: using guessed type wchar_t aReserved[9];
// 10A50D8: using guessed type wchar_t aObjectDoesNotE[23];
// 10CF228: using guessed type int (__stdcall *NtSetInformationProcess_0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (01041C00) --------------------------------------------------------
int __stdcall PropSecurity(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int result; // eax
  HWND v5; // edi
  HWND v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  char v11; // al
  void *v12; // esi
  HWND v13; // eax
  unsigned int v14; // edx
  const unsigned __int16 *v15; // ebx
  __int16 *v16; // ecx
  __int16 v17; // ax
  WCHAR *v18; // esi
  WCHAR v19; // ax
  unsigned int v20; // edx
  HWND hWnda; // [esp+8h] [ebp+8h]

  if ( msg == WM_INITDIALOG )
  {
    v5 = hDlg;
    PostMessageW(hDlg, 0x46Bu, 0, 0);
    dword_10DC038 = *(lParam + 0x1C);
    hWnda = PE_DuplicateProcessHandle(*(dword_10DC038 + 36), *(dword_10DC038 + 44), 0x80000000);
    if ( hWnda )
    {
      byte_10DC083 = 0;
      byte_10DC084 = 0;
      byte_10DC085 = 0;
      byte_10DC082 = 0;
      v7 = wcscmp((dword_10DC038 + 0x38), L"Directory");
      if ( v7 )
        v7 = -(v7 < 0) | 1;
      if ( v7 )
      {
        v8 = wcscmp((dword_10DC038 + 0x38), L"Device");
        if ( v8 )
          v8 = -(v8 < 0) | 1;
        if ( v8 )
        {
          v9 = wcscmp((dword_10DC038 + 0x38), L"Process");
          if ( v9 )
            v9 = -(v9 < 0) | 1;
          if ( v9 )
          {
            v10 = wcscmp((dword_10DC038 + 0x38), L"Key");
            if ( v10 )
              v10 = -(v10 < 0) | 1;
            v11 = byte_10DC084;
            if ( !v10 )
              v11 = 1;
            byte_10DC084 = v11;
          }
          else
          {
            byte_10DC082 = 1;
          }
        }
        else
        {
          byte_10DC085 = 1;
        }
      }
      else
      {
        byte_10DC083 = 1;
      }
      wParam = 23;
      byte_10DC080 = GetUserObjectSecurity(hWnda, &wParam, pSID, 0x2000u, &msg) != 0;
      CloseHandle(hWnda);
    }
    else
    {
      byte_10DC080 = 0;
      v6 = GetDlgItem(v5, 127);
      EnableWindow(v6, 0);
    }
    v12 = PE_DuplicateProcessHandle(*(dword_10DC038 + 36), *(dword_10DC038 + 44), 0x81000000);
    if ( v12 || (v12 = PE_DuplicateProcessHandle(*(dword_10DC038 + 36), *(dword_10DC038 + 44), 0x1000000u)) != 0 )
    {
      wParam = 9;
      byte_10DC081 = GetUserObjectSecurity(v12, &wParam, ObjectSecurity, 0x2000u, &msg) != 0;
      CloseHandle(v12);
    }
    else
    {
      byte_10DC081 = 0;
      v13 = GetDlgItem(v5, 128);
      EnableWindow(v13, 0);
    }
    v14 = 0;
    v15 = (dword_10DC038 + 184);
    v16 = (dword_10DC038 + 184);
    do
    {
      v17 = *v16;
      ++v16;
    }
    while ( v17 );
    if ( (v16 - dword_10DC038 - 186) >> 1 )
    {
      v18 = (dword_10DC038 + 184);
      do
      {
        v19 = *v18;
        ++v18;
        gObjectName[v14++] = v19;
      }
      while ( v14 < wcslen(v15) );
    }
    v20 = v14;
    if ( v20 >= 1024 )
    {
      __report_rangecheckfailure();
      JUMPOUT(*algn_104224B);
    }
    gAclDlgControl.Version = 257;
    gObjectName[v20] = 0;
    if ( byte_10DC084 )
    {
      gAclDlgControl.GenericAccessMap = RegistryAccessMasks;
      gAclDlgControl.SpecificAccessMap = RegistryAccessMasks;
    }
    else
    {
      gAclDlgControl.GenericAccessMap = AccessMasks;
      gAclDlgControl.SpecificAccessMap = AccessMasks;
    }
    gAclDlgControl.Reserved = 0;
    gAclDlgControl.SubReplaceTitle = 0;
    gAclDlgControl.SubReplaceConfirmation = 0;
    result = 1;
    gAclDlgControl.DialogTitle = aObject_0;
    gAclDlgControl.HelpInfo = &HelpInfo;
    gAclDlgControl.SpecialAccess = aSpecialAccess;
    return result;
  }
  if ( msg != 273 )
    return 0;
  if ( wParam != 127 )
  {
    if ( wParam == 128 )
    {
      if ( !byte_10DC081 )
      {
        MessageBoxW(0, L"You do not have permission to view the Audit Information for\nthis object.", L"WinObj", 0x10u);
        return 0;
      }
      gAclEditControl.NumberOfEntries = 7;
      gAclEditControl.Entries = aclEditEntryFile;
      dword_10DC040 = *(dword_10DC038 + 44);
      dword_10DC03C = *(dword_10DC038 + 36);
      dword_10DC044 = 1;
      dword_10DC048 = dword_10DBC38;
      dword_10DC04C = ObjectSecurity;
      dword_10DC050 = &byte_10DC081;
      if ( SedSystemAclEditor(
             0,
             0,
             0,
             &gAclDlgControl,
             &gAclEditControl,
             gObjectName,
             pfnAclChangeCallback,
             &dword_10DC03C,
             ObjectSecurity,
             0,
             &msg,
             0) )
      {
        MessageBoxW(0, L"The SACL Editor does not understand the Security Information.", L"WinObj", 0x10u);
        return 0;
      }
      return 0;
    }
    if ( wParam == 129 )
    {
      if ( byte_10DC080 )
      {
        dword_10DC040 = *(dword_10DC038 + 44);
        dword_10DC03C = *(dword_10DC038 + 36);
        dword_10DC044 = 2;
        dword_10DC048 = dword_10DBC38;
        dword_10DC04C = pSID;
        dword_10DC050 = &byte_10DC080;
        wcscpy_s(&gObjectType, 0x400u, L"&Object");
        if ( SedTakeOwnership(
               0,
               0,
               0,
               &gObjectType,
               gObjectName,
               1u,
               pfnAclChangeCallback,
               &dword_10DC03C,
               pSID,
               0,
               0,
               &msg,
               &HelpInfo,
               0) )
        {
          if ( IsValidSecurityDescriptor(pSID) )
          {
            MessageBoxW(0, L"The Ownership Editor does not understand the Security Information.", L"WinObj", 0x10u);
            return 0;
          }
          goto LABEL_10;
        }
        return 0;
      }
      goto LABEL_29;
    }
    return 0;
  }
  if ( !byte_10DC080 )
  {
LABEL_29:
    MessageBoxW(0, L"You do not have permission to view the Security Information for\nthis object.", L"WinObj", 0x10u);
    return 0;
  }
  if ( !byte_10DC083 )
  {
    if ( byte_10DC084 )
    {
      gAclEditControl.Entries = stru_10C01C0;
    }
    else
    {
      if ( byte_10DC085 )
      {
        gAclEditControl.NumberOfEntries = 11;
        gAclEditControl.Entries = stru_10C0110;
        goto LABEL_26;
      }
      if ( byte_10DC082 )
      {
        gAclEditControl.NumberOfEntries = 14;
        gAclEditControl.Entries = &dword_10BFED0;
        goto LABEL_26;
      }
      gAclEditControl.Entries = &HelpInfo.Reserved1;
    }
    gAclEditControl.NumberOfEntries = 12;
    goto LABEL_26;
  }
  gAclEditControl.NumberOfEntries = 22;
  gAclEditControl.Entries = stru_10BFFB0;
LABEL_26:
  dword_10DC040 = *(dword_10DC038 + 44);
  dword_10DC03C = *(dword_10DC038 + 36);
  dword_10DC044 = 0;
  dword_10DC048 = dword_10DBC38;
  dword_10DC04C = pSID;
  dword_10DC050 = &byte_10DC080;
  if ( !SedDiscretionaryAclEditor(
          0,
          0,
          0,
          &gAclDlgControl,
          &gAclEditControl,
          gObjectName,
          pfnAclChangeCallback,
          &dword_10DC03C,
          pSID,
          0,
          0,
          &msg,
          0) )
    return 0;
  if ( !IsValidSecurityDescriptor(pSID) )
  {
LABEL_10:
    MessageBoxW(0, L"The Security Information is invalid.", L"WinObj", 0x10u);
    return 0;
  }
  MessageBoxW(0, L"The ACL Editor does not understand the Security Information.", L"WinObj", 0x10u);
  return 0;
}
// 10667E8: using guessed type int __report_rangecheckfailure(void);
// 10BFCB8: using guessed type wchar_t aObject_0[7];
// 10BFCE0: using guessed type wchar_t aSpecialAccess[18];
// 10BFED0: using guessed type int dword_10BFED0;
// 10BFFB0: using guessed type _ACLEDITENTRY stru_10BFFB0[22];
// 10C0110: using guessed type _ACLEDITENTRY stru_10C0110[11];
// 10C01C0: using guessed type _ACLEDITENTRY stru_10C01C0[12];
// 10C0280: using guessed type _ACLEDITENTRY aclEditEntryFile[7];
// 10C02F0: using guessed type int AccessMasks[4];
// 10C0300: using guessed type int RegistryAccessMasks[4];
// 10DBC38: using guessed type int dword_10DBC38[256];
// 10DC038: using guessed type int dword_10DC038;
// 10DC03C: using guessed type int dword_10DC03C;
// 10DC040: using guessed type int dword_10DC040;
// 10DC044: using guessed type int dword_10DC044;
// 10DC048: using guessed type int dword_10DC048;
// 10DC04C: using guessed type int dword_10DC04C;
// 10DC050: using guessed type int dword_10DC050;
// 10DC080: using guessed type char byte_10DC080;
// 10DC081: using guessed type char byte_10DC081;
// 10DC082: using guessed type char byte_10DC082;
// 10DC083: using guessed type char byte_10DC083;
// 10DC084: using guessed type char byte_10DC084;
// 10DC085: using guessed type char byte_10DC085;

//----- (01042250) --------------------------------------------------------
int __cdecl PE_DuplicateProcessHandle(DWORD dwProcessId, HANDLE hSourceHandle, DWORD dwDesiredAccess)
{
  DWORD dwPid; // edi
  HANDLE ProcessHandle; // esi
  DWORD v5; // ST14_4
  HANDLE v6; // ST0C_4
  HANDLE SourceHandle; // edi
  DWORD DesiredAccess; // ST14_4
  HANDLE TargetHandle; // ST0C_4
  int InBuf[4]; // [esp+8h] [ebp-20h]
  DWORD v12; // [esp+18h] [ebp-10h]
  DWORD BytesReturned; // [esp+1Ch] [ebp-Ch]
  DWORD InBuffer; // [esp+20h] [ebp-8h]
  int pTargetHandle; // [esp+24h] [ebp-4h]

  dwPid = dwProcessId;
  pTargetHandle = 0;
  InBuffer = dwProcessId;
  ProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, 0, dwProcessId);
  dwProcessId = ProcessHandle;
  if ( ProcessHandle )
    goto LABEL_14;
  if ( GetLastError() == ERROR_ACCESS_DENIED )
    DeviceIoControl(ghDriverHandle, CTRLCODE_QUERY_PROCESS_HANDLE, &InBuffer, 4u, &dwProcessId, 4u, &BytesReturned, 0);
  ProcessHandle = dwProcessId;
  if ( dwProcessId )
  {
LABEL_14:
    if ( dwPid <= 8 )
    {
      InBuf[0] = dwPid;
      SourceHandle = hSourceHandle;
      InBuf[3] = hSourceHandle;
      if ( ghDriverHandle == -1
        || !DeviceIoControl(ghDriverHandle, 0x83350014, InBuf, 0x10u, &pTargetHandle, 4u, &v12, 0) )
      {
        DesiredAccess = dwDesiredAccess;
        TargetHandle = GetCurrentProcess();
        DuplicateHandle(ProcessHandle, SourceHandle, TargetHandle, &pTargetHandle, DesiredAccess, 0, 0);
      }
    }
    else
    {
      v5 = dwDesiredAccess;
      v6 = GetCurrentProcess();
      DuplicateHandle(ProcessHandle, hSourceHandle, v6, &pTargetHandle, v5, 0, 0);
    }
    CloseHandle(ProcessHandle);
  }
  return pTargetHandle;
}

//----- (01042330) --------------------------------------------------------
int *__thiscall sub_1042330(int *this, int a2)
{
  int v2; // esi
  int *v3; // edi
  int v4; // ecx
  int *result; // eax
  signed int v6; // ecx
  int v7; // ecx
  int v8; // ecx

  v2 = a2;
  v3 = this;
  v4 = *this;
  if ( *(v4 - 12) > a2 )
    v2 = *(v4 - 12);
  if ( *(v4 - 4) > 1 )
    return sub_103BDF0(v3, v2);
  v6 = *(v4 - 8);
  if ( v6 < v2 )
  {
    if ( v6 <= 0x40000000 )
    {
      v8 = v6 / 2 + v6;
      if ( v8 < v2 )
        v8 = v2;
      result = sub_104DE20(v3, v8);
    }
    else
    {
      v7 = v6 + 0x100000;
      if ( v7 < v2 )
        v7 = v2;
      result = sub_104DE20(v3, v7);
    }
  }
  return result;
}

//----- (010423A0) --------------------------------------------------------
int __stdcall PageProcCPU(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  HWND v4; // eax
  int result; // eax
  CResizer *v6; // eax
  LONG v7; // eax
  HWND (__stdcall *v8)(HWND, int); // esi
  HWND v9; // edi
  HWND v10; // esi
  HWND v11; // edi
  HWND v12; // esi
  HWND v13; // edi
  HWND v14; // esi
  CResizer *v15; // edi
  HWND v16; // eax
  HWND v17; // ST2C_4
  HWND v18; // eax
  HWND v19; // ST2C_4
  HWND v20; // eax
  HWND v21; // ST2C_4
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  WPARAM v31; // [esp-8h] [ebp-38h]
  CResizer *v32; // [esp+10h] [ebp-20h]
  HWND v33; // [esp+14h] [ebp-1Ch]
  HWND v34; // [esp+18h] [ebp-18h]
  HWND v35; // [esp+1Ch] [ebp-14h]
  int v36; // [esp+2Ch] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  if ( a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  if ( a2 == 275 || a2 == 5 )
  {
    if ( IsWindowVisible(hWnd) )
    {
      v25 = GetDlgItem(hWnd, 1158);
      SendMessageW(v25, 0x400u, 0, 0);
      v26 = GetDlgItem(hWnd, 2000);
      SendMessageW(v26, 0x400u, 0, 0);
      v27 = GetDlgItem(hWnd, 1161);
      SendMessageW(v27, 0x400u, 0, 0);
      v28 = GetDlgItem(hWnd, 1159);
      SendMessageW(v28, 0x400u, 0, 0);
      v29 = GetDlgItem(hWnd, 1332);
      SendMessageW(v29, 0x400u, 0, 0);
      v30 = GetDlgItem(hWnd, 1330);
      SendMessageW(v30, 0x400u, 0, 0);
      return 0;
    }
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 273 )
    {
      switch ( wParam )
      {
        case 0x9C41u:
          v31 = 40014;
          goto LABEL_8;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          result = 0;
          break;
        case 0x9C9Cu:
        case 0x9C9Du:
          v31 = wParam;
LABEL_8:
          v4 = GetParent(hWnd);
          PostMessageW(v4, 0x111u, v31, 0);
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    }
    return 0;
  }
  v6 = operator new(0x40u);
  v36 = 0;
  if ( v6 )
    v32 = CResizer::CResizer(v6, hWnd);
  else
    v32 = 0;
  v36 = -1;
  v7 = GetWindowLongW(hWnd, -16);
  SetWindowLongW(hWnd, -16, v7 | 0x2000000);
  SetWindowLongW(hWnd, -21, dwNewLong);
  CreateGraphWindow(hWnd, 1158, *(dwNewLong + 1372));
  CreateGraphWindow(hWnd, 2000, *(dwNewLong + 1372));
  CreateGraphWindow(hWnd, 1161, *(dwNewLong + 908));
  CreateGraphWindow(hWnd, 1159, *(dwNewLong + 908));
  if ( *(dwNewLong + 1064) )
  {
    CreateGraphWindow(hWnd, 1332, *(dwNewLong + 1064));
    CreateGraphWindow(hWnd, 1330, *(dwNewLong + 1064));
  }
  v8 = GetDlgItem;
  if ( *(dwNewLong + 1064) )
  {
    v9 = GetDlgItem(hWnd, 1331);
    v10 = GetDlgItem(hWnd, 1160);
    v33 = GetDlgItem(hWnd, 1157);
    v34 = v10;
    v35 = v9;
    sub_1050550(v32, 3, &v33);
    v11 = GetDlgItem(hWnd, 1332);
    v12 = GetDlgItem(hWnd, 1161);
    v33 = GetDlgItem(hWnd, 1158);
    v34 = v12;
    v35 = v11;
    sub_1050550(v32, 3, &v33);
    v13 = GetDlgItem(hWnd, 1330);
    v14 = GetDlgItem(hWnd, 1159);
    v33 = GetDlgItem(hWnd, 2000);
    v35 = v13;
    v15 = v32;
    v34 = v14;
    sub_1050550(v32, 3, &v33);
    v8 = GetDlgItem;
    v16 = GetDlgItem(hWnd, 1331);
    *&CResizer::AddItem(v32, v16, 1)->m_rect2.right = db_four;
  }
  else
  {
    v17 = GetDlgItem(hWnd, 1160);
    v18 = GetDlgItem(hWnd, 1157);
    v15 = v32;
    sub_10504E0(v32, v18, v17);
    v19 = GetDlgItem(hWnd, 1161);
    v20 = GetDlgItem(hWnd, 1158);
    sub_10504E0(v32, v20, v19);
    v21 = GetDlgItem(hWnd, 1159);
    v22 = GetDlgItem(hWnd, 2000);
    sub_10504E0(v32, v22, v21);
  }
  v23 = v8(hWnd, 1157);
  *&CResizer::AddItem(v15, v23, 1)->m_rect2.right = db_four;
  v24 = v8(hWnd, 1160);
  *&CResizer::AddItem(v15, v24, 1)->m_rect2.right = db_four;
  PropSheet_UpdateTab(hWnd);
  SendMessageW(hWnd, 0x113u, 0, 0);
  return 1;
}
// 109CB38: using guessed type double db_four;

//----- (01042810) --------------------------------------------------------
int __stdcall PageProcEnv(HWND hWnd, int a2, WPARAM wParam, int a4)
{
  HWND v4; // ebx
  CResizer *v5; // eax
  LONG v6; // eax
  void (__stdcall *v7)(HWND, UINT, WPARAM, LPARAM); // edi
  HWND v8; // eax
  __int16 *v9; // esi
  __int16 *v10; // ecx
  int v11; // edi
  __int16 i; // ax
  LRESULT v13; // edx
  char *v14; // ecx
  __int16 v15; // ax
  HWND v17; // eax
  LRESULT v18; // esi
  WPARAM v19; // [esp-8h] [ebp-2ACh]
  LPARAM v20; // [esp+10h] [ebp-294h]
  int v21; // [esp+1Ch] [ebp-288h]
  int v22; // [esp+20h] [ebp-284h]
  void *v23; // [esp+44h] [ebp-260h]
  LPARAM lParam; // [esp+48h] [ebp-25Ch]
  LRESULT v25; // [esp+4Ch] [ebp-258h]
  int v26; // [esp+50h] [ebp-254h]
  int v27; // [esp+54h] [ebp-250h]
  int v28; // [esp+58h] [ebp-24Ch]
  __int16 *v29; // [esp+5Ch] [ebp-248h]
  int v30; // [esp+64h] [ebp-240h]
  int v31; // [esp+68h] [ebp-23Ch]
  UINT pnIDs; // [esp+7Ch] [ebp-228h]
  int v33; // [esp+80h] [ebp-224h]
  WORD pnWidths[2]; // [esp+84h] [ebp-220h]
  LPMEASUREITEMSTRUCT lpmis; // [esp+88h] [ebp-21Ch]
  __int16 v36; // [esp+8Ch] [ebp-218h]
  int v37; // [esp+2A0h] [ebp-4h]

  lpmis = a4;
  GetWindowLongW(hWnd, -21);
  lParam = 0;
  memset(&v25, 0, 0x30u);
  v4 = GetDlgItem(hWnd, 1055);
  pnIDs = 1057;
  v33 = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  switch ( a2 )
  {
    case 273:
      if ( wParam <= 40093 )
      {
        if ( wParam >= 40092 )
        {
          v19 = wParam;
        }
        else
        {
          if ( wParam != 40001 )
            return 0;
          v19 = 40014;
        }
        v17 = GetParent(hWnd);
        PostMessageW(v17, 0x111u, v19, 0);
        return 0;
      }
      if ( wParam == 40631 )
      {
        v18 = 0;
        if ( SendMessageW(v4, 0x1004u, 0, 0) > 0 )
        {
          do
          {
            v22 = 2;
            v21 = 2;
            SendMessageW(v4, 0x102Bu, v18++, &v20);
          }
          while ( v18 < SendMessageW(v4, 0x1004u, 0, 0) );
          return 0;
        }
      }
      return 0;
    case 43:
      CMainWnd::DrawList(lpmis);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, lpmis);
  }
  if ( a2 != 272 )
    return 0;
  v5 = operator new(0x40u);
  v23 = v5;
  v37 = 0;
  if ( v5 )
    CResizer::CResizer(v5, hWnd);
  PropSheet_UpdateTab(hWnd);
  v6 = GetWindowLongW(v4, -16);
  SetWindowLongW(v4, -16, v6 & 0xFFFFFFFD | 1);
  v7 = SendMessageW;
  SendMessageW(v4, 0x1036u, 0x4020u, 16416);
  v8 = SendMessageW(v4, 0x104Eu, 0, 0);
  CTreeList::InitToolTips(v8);
  SetWindowLongW(v4, -4, Proxy_ListCtrlWndProc);
  SendMessageW(v4, 0x30u, ghConfigFont, 0);
  InitListHeader(v4, &pnIDs, pnWidths, 2);
  v9 = lpmis[33].itemHeight;
  if ( v9 )
  {
    while ( *v9 )
    {
      v10 = &v36;
      v36 = 0;
      v11 = 0;
      for ( i = *v9; i; ++v9 )
      {
        if ( !v11 )
        {
          if ( i == 61 )
          {
            v11 = (v9 + 1);
            *v10 = 0;
          }
          else
          {
            *v10 = i;
            ++v10;
          }
        }
        i = v9[1];
      }
      lParam = 5;
      v29 = &v36;
      v25 = 0x7FFFFFFF;
      v26 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
      v31 = 1;
      v13 = SendMessageW(v4, 0x104Du, 0, &lParam);
      if ( v13 == -1 )
        return 0;
      if ( v11 )
      {
        v14 = v11;
        lpmis = (v11 + 2);
        do
        {
          v15 = *v14;
          v14 += 2;
        }
        while ( v15 );
        if ( ((v14 - lpmis) >> 1) > 0x1FFF )
          *(v11 + 16382) = 0;
        v29 = v11;
        v7 = SendMessageW;
        lParam = 1;
        v25 = v13;
        v26 = 1;
        SendMessageW(v4, 0x104Cu, 0, &lParam);
      }
      else
      {
        v7 = SendMessageW;
      }
      ++v9;
      if ( !v9 )
        break;
    }
  }
  v7(v4, 0x101Eu, 0, 0xFFFF);
  v7(v4, 0x101Eu, 1u, 0xFFFF);
  return 1;
}

//----- (01042C20) --------------------------------------------------------
HBRUSH __stdcall PageProcInfo(HWND hWnd, UINT a2, WPARAM a3, TreeViewParamInfo *dwNewLong)
{
  HWND v4; // ebx
  LONG v5; // edx
  Data_t_bstr_t *v6; // esi
  CResizer *v7; // eax
  CResizer *v8; // eax
  HWND v9; // eax
  struct tagResizerItem *v10; // eax
  HWND v11; // eax
  struct tagResizerItem *v12; // eax
  bool v13; // zf
  void *v14; // ST08_4
  void *v15; // ST04_4
  void *v16; // ST00_4
  const WCHAR *v17; // edi
  const WCHAR *v18; // eax
  BOOL v19; // ST2C_4
  HWND v20; // eax
  LPARAM v21; // edi
  BOOL v22; // ST2C_4
  HWND v23; // eax
  HWND v24; // eax
  int v25; // ebx
  HWND v26; // eax
  HWND v27; // eax
  char v28; // al
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  OLECHAR *v32; // ST2C_4
  _bstr_t *v33; // edi
  _bstr_t *v34; // eax
  _bstr_t *v35; // eax
  _bstr_t *v36; // eax
  const WCHAR *v37; // eax
  WCHAR *v38; // eax
  HWND v39; // eax
  _WORD *v40; // eax
  int v41; // ST2C_4
  HWND v42; // eax
  HWND v43; // eax
  _WORD *v44; // eax
  HWND v45; // eax
  DWORD v46; // edi
  void *v47; // edi
  wchar_t *v48; // eax
  HICON v49; // eax
  LPARAM v50; // ST2C_4
  HWND v51; // eax
  HICON v52; // eax
  LPARAM v53; // ST2C_4
  HWND v54; // eax
  HICON v55; // eax
  LPARAM v56; // ST2C_4
  HWND v57; // eax
  int v58; // eax
  int v59; // ST2C_4
  HWND v60; // eax
  HBRUSH v61; // edi
  const unsigned __int16 *v62; // eax
  int v63; // eax
  HWND v64; // eax
  int v65; // ST2C_4
  HWND v66; // eax
  WCHAR *v67; // eax
  HWND v68; // eax
  WCHAR *v69; // edi
  char v70; // cl
  int v71; // eax
  int v72; // ST2C_4
  HWND v73; // eax
  HWND v75; // eax
  int v76; // [esp-8h] [ebp-1664h]
  struct _FILETIME LocalFileTime; // [esp+10h] [ebp-164Ch]
  DWORD dwHandle; // [esp+18h] [ebp-1644h]
  _bstr_t v79; // [esp+1Ch] [ebp-1640h]
  _bstr_t v80; // [esp+20h] [ebp-163Ch]
  _bstr_t v81; // [esp+24h] [ebp-1638h]
  _bstr_t v82; // [esp+28h] [ebp-1634h]
  DWORD pdwValue5; // [esp+2Ch] [ebp-1630h]
  char v84[5]; // [esp+33h] [ebp-1629h]
  LPARAM lParam; // [esp+38h] [ebp-1624h]
  HANDLE hObject; // [esp+3Ch] [ebp-1620h]
  LPCWSTR lpString; // [esp+40h] [ebp-161Ch]
  EventItem v88; // [esp+44h] [ebp-1618h]
  WCHAR DateStr; // [esp+860h] [ebp-DFCh]
  WCHAR v90; // [esp+A60h] [ebp-BFCh]
  WCHAR Dest; // [esp+C4Ch] [ebp-A10h]
  WCHAR String; // [esp+E4Ch] [ebp-810h]
  int v93; // [esp+1658h] [ebp-4h]

  v4 = hWnd;
  *&v84[1] = hWnd;
  v88.field_4 = a3;
  lParam = dwNewLong;
  v5 = GetWindowLongW(hWnd, -21);
  v6 = 0;
  lpString = v5;
  v88.strEventTrace.m_Data = 0;
  v93 = 0;
  switch ( a2 )
  {
    case 0x110u:
      v7 = operator new(0x40u);
      pdwValue5 = v7;
      LOBYTE(v93) = 1;
      if ( v7 )
        v8 = CResizer::CResizer(v7, hWnd);
      else
        v8 = 0;
      v88.field_4 = v8;
      LOBYTE(v93) = 0;
      v8->m_nXRatio = 85;
      v8->m_nYRatio = 100;
      v9 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_PATH);
      if ( v9 )
      {
        v10 = CResizer::AddItem(v88.field_4, v9, 1);
        *&v10->m_rect1.left = 0i64;
        *&v10->m_rect1.right = db_one;
      }
      v11 = GetDlgItem(hWnd, 1656);
      if ( v11 )
      {
        v12 = CResizer::AddItem(v88.field_4, v11, 1);
        *&v12->m_rect1.left = 0i64;
        *&v12->m_rect1.right = db_one;
      }
      SetWindowLongW(hWnd, -21, dwNewLong);
      wsprintfW(&String, L"%s(%08X) (netsvcs) Properties", dwNewLong[1].field_14, dwNewLong[1].field_1C);
      SetWindowTextW(hWnd, &String);
      v13 = (dwNewLong[1].field_0 & 0x100) == 0;
      lpString = dwNewLong[19].field_20;
      if ( !v13 )
        SetDlgItemTextW(hWnd, 106, L"Path (Image is probably packed):");
      hObject = PE_OpenProcess(0x2000000u, 0, dwNewLong[1].field_1C);
      QueryProcessArguments(hObject, dwNewLong[1].field_1C, &v88.guid, &v88.field_4, &pdwValue5, v84);
      v14 = dwNewLong[20].field_0;
      dwNewLong[20].field_0 = v88.guid.Data1;
      free(v14);
      v15 = dwNewLong[20].field_4;
      dwNewLong[20].field_4 = v88.field_4;
      free(v15);
      v16 = dwNewLong[20].field_8;
      dwNewLong[20].field_8 = pdwValue5;
      free(v16);
      SetDlgItemTextW(hWnd, 1032, dwNewLong[20].field_0);
      SetDlgItemTextW(hWnd, 1035, dwNewLong[20].field_4);
      v17 = L"n/a";
      v18 = L"n/a";
      if ( lpString )
        v18 = lpString;
      SetDlgItemTextW(hWnd, 1015, v18);
      SetDlgItemTextW(hWnd, 1190, *(lParam + 796));
      if ( *(lParam + 828) )
        v17 = *(lParam + 828);
      SetDlgItemTextW(hWnd, 1656, v17);
      v19 = lpString != 0;
      v20 = GetDlgItem(hWnd, 1307);
      EnableWindow(v20, v19);
      v21 = lParam;
      v22 = *(lParam + 828) != 0;
      v23 = GetDlgItem(hWnd, 1306);
      EnableWindow(v23, v22);
      v24 = GetDlgItem(hWnd, 1195);
      ShowWindow(v24, 0);
      if ( gbIsProcessDEPEnabled )
      {
        Fake_GetProcessMitigationPolicy(v21, hObject);
        v25 = *(v21 + 636);
        if ( v25 == -1 )
        {
          wcscpy_s(&String, 0x400u, L"n/a");
        }
        else
        {
          if ( v25 & 1 )
            wcscpy_s(&String, 0x400u, L"Enabled");
          else
            wcscpy_s(&String, 0x400u, L"Disabled");
          if ( v25 & 8 )
            wcscat_s(&String, 0x400u, L" (permanent)");
        }
        v4 = *&v84[1];
        SetDlgItemTextW(*&v84[1], 1202, &String);
      }
      else
      {
        v26 = GetDlgItem(hWnd, 1203);
        ShowWindow(v26, 0);
        v27 = GetDlgItem(hWnd, 1202);
        ShowWindow(v27, 0);
      }
      if ( gdwVersion >= 3 && hObject )
      {
        if ( sub_103F5C0(hObject, 1, &v88.field_4, 4) )
        {
          _bstr_t::operator=(&v88, &gszNullString);
          v28 = v88.field_4;
          if ( v88.field_4 & 8 )
          {
            _bstr_t::_bstr_t(&v88.guid, L"Disallow-Stripped");
            LOBYTE(v93) = 2;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
            v28 = v88.field_4;
          }
          if ( v28 & 4 )
          {
            if ( sub_FE0440(&v88) )
            {
              _bstr_t::_bstr_t(&v88.guid, L", ");
              LOBYTE(v93) = 3;
              _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
              LOBYTE(v93) = 0;
              _bstr_t::_Free(&v88.guid);
            }
            _bstr_t::_bstr_t(&v88.guid, L"High-Entropy");
            LOBYTE(v93) = 4;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
            v28 = v88.field_4;
          }
          if ( v28 & 1 )
          {
            if ( sub_FE0440(&v88) )
            {
              _bstr_t::_bstr_t(&v88.guid, L", ");
              LOBYTE(v93) = 5;
              _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
              LOBYTE(v93) = 0;
              _bstr_t::_Free(&v88.guid);
            }
            _bstr_t::_bstr_t(&v88.guid, L"Bottom-Up");
            LOBYTE(v93) = 6;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
            v28 = v88.field_4;
          }
          if ( v28 & 2 )
          {
            if ( sub_FE0440(&v88) )
            {
              _bstr_t::_bstr_t(&v88.guid, L", ");
              LOBYTE(v93) = 7;
              _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
              LOBYTE(v93) = 0;
              _bstr_t::_Free(&v88.guid);
            }
            _bstr_t::_bstr_t(&v88.guid, L"Force-Relocate");
            LOBYTE(v93) = 8;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
          }
          if ( sub_FE0440(&v88) )
          {
            v6 = v88.strEventTrace.m_Data;
            if ( v88.strEventTrace.m_Data )
              wcscpy_s(&String, 0x400u, v88.strEventTrace.m_Data->m_wstr);
            else
              wcscpy_s(&String, 0x400u, 0);
          }
          else
          {
            wcscat_s(&String, 0x400u, L"Disabled");
            v6 = v88.strEventTrace.m_Data;
          }
        }
        else
        {
          GetErrorMsg(&String, 0x400u);
        }
      }
      else
      {
        if ( gdwVersion < 1 )
        {
          v29 = GetDlgItem(v4, 1204);
          ShowWindow(v29, 0);
          v30 = GetDlgItem(v4, 1205);
          ShowWindow(v30, 0);
          goto LABEL_56;
        }
        if ( *(v21 + 650) & 0x40 )
        {
          wcscpy_s(&String, 0x400u, L"Enabled");
        }
        else if ( *(v21 + 648) )
        {
          wcscpy_s(&String, 0x400u, L"Disabled");
        }
        else
        {
          wcscpy_s(&String, 0x400u, L"n/a");
        }
      }
      SetDlgItemTextW(v4, 1205, &String);
LABEL_56:
      if ( gdwVersion < 4 )
      {
        v31 = GetDlgItem(v4, 1666);
        ShowWindow(v31, 0);
      }
      else
      {
        if ( *(v21 + 650) & 0x4000 )
        {
          wcscpy_s(&String, 0x400u, L"Enabled");
        }
        else if ( *(v21 + 648) && *(v21 + 650) )
        {
          wcscpy_s(&String, 0x400u, L"Disabled");
        }
        else
        {
          wcscpy_s(&String, 0x400u, L"n/a");
        }
        SetDlgItemTextW(v4, 1666, &String);
      }
      if ( hObject )
        CloseHandle(hObject);
      if ( *(v21 + 784) )
      {
        _bstr_t::_bstr_t(&hObject, *(v21 + 784));
        v13 = *(v21 + 824) == 0;
        LOBYTE(v93) = 9;
        if ( !v13 )
        {
          _bstr_t::_bstr_t(&v88.guid, L")");
          v32 = *(v21 + 824);
          LOBYTE(v93) = 10;
          v33 = _bstr_t::_bstr_t(&v81, v32);
          LOBYTE(v93) = 11;
          v34 = _bstr_t::_bstr_t(&v79, L" (");
          LOBYTE(v93) = 12;
          v35 = _bstr_t::operator+(v34, &v82, v33);
          LOBYTE(v93) = 13;
          v36 = _bstr_t::operator+(v35, &v80, &v88.guid);
          LOBYTE(v93) = 14;
          _bstr_t::operator+=(&hObject, v36);
          _bstr_t::_Free(&v80);
          _bstr_t::_Free(&v82);
          _bstr_t::_Free(&v79);
          _bstr_t::_Free(&v81);
          _bstr_t::_Free(&v88.guid);
          v21 = lParam;
        }
        if ( hObject )
          v37 = *hObject;
        else
          v37 = 0;
        SetDlgItemTextW(v4, 1183, v37);
        LOBYTE(v93) = 0;
        _bstr_t::_Free(&hObject);
      }
      v38 = VerifyImage(v21, gConfig.bVerifySignatures);
      SetDlgItemTextW(v4, 3, v38);
      v39 = GetDlgItem(v4, 1672);
      SetWindowSubclass(v39, EditVTClassCallback, 0, 0);
      sub_1061A50(*(v21 + 844), &String);
      SetDlgItemTextW(v4, 1672, &String);
      v40 = *(v21 + 792);
      if ( v40 && *v40 != 91 )
      {
        v41 = sub_1061C10(*(v21 + 844));
        v42 = GetDlgItem(v4, 1671);
        EnableWindow(v42, v41);
      }
      if ( gbWintrustInited )
      {
        if ( *(v21 + 832) || (v44 = *(v21 + 792)) == 0 || *v44 == 91 )
        {
          v45 = GetDlgItem(v4, 1005);
          EnableWindow(v45, 0);
        }
      }
      else
      {
        v43 = GetDlgItem(v4, 1005);
        ShowWindow(v43, 0);
      }
      wsprintfW(&String, L"n/a");
      if ( lpString )
      {
        v84[1] = unknown_libname_2(255);
        v46 = GetFileVersionInfoSizeW(lpString, &dwHandle);
        v88.guid.Data1 = malloc(v46);
        if ( GetFileVersionInfoW(lpString, 0, v46, v88.guid.Data1) )
        {
          v47 = v88.guid.Data1;
          sub_1039660(*(v88.guid.Data1 + 52), *(v88.guid.Data1 + 48), &String);
        }
        else
        {
          wsprintfW(&String, L"n/a");
          v47 = v88.guid.Data1;
        }
        free(v47);
        unknown_libname_2(v84[1]);
        v21 = lParam;
      }
      SetDlgItemTextW(v4, 25, &String);
      if ( *(v21 + 640) )
        v48 = _wctime32((v21 + 640));
      else
        v48 = L"n/a";
      SetDlgItemTextW(v4, 30, v48);
      v49 = *(v21 + 56);
      if ( !v49 )
        v49 = LoadIconW(0, 0x7F00);
      v50 = v49;
      v51 = GetDlgItem(v4, 1033);
      SendMessageW(v51, 0x172u, 1u, v50);
      v52 = *(v21 + 56);
      if ( !v52 )
        v52 = LoadIconW(0, 0x7F00);
      v53 = v52;
      v54 = GetParent(v4);
      SendMessageW(v54, 0x80u, 1u, v53);
      if ( *(v21 + 56) )
        v55 = *(v21 + 52);
      else
        v55 = LoadIconW(0, 0x7F00);
      v56 = v55;
      v57 = GetParent(v4);
      SendMessageW(v57, 0x80u, 0, v56);
      SetDlgItemTextW(v4, 35, *(v21 + 72));
      wsprintfW(&String, L"%d K", *(v21 + 900) >> 10);
      SetDlgItemTextW(v4, 1008, &String);
      wsprintfW(&String, L"%d K", *(v21 + 888) >> 10);
      SetDlgItemTextW(v4, 1009, &String);
      if ( *(v21 + 624) )
      {
        FileTimeToLocalFileTime((v21 + 624), &LocalFileTime);
        FileTimeToSystemTime(&LocalFileTime, &v88.guid.Data2);
        GetTimeFormatW(0x400u, 0, &v88.guid.Data2, 0, &String, 512);
        GetDateFormatW(0x400u, 0, &v88.guid.Data2, 0, &DateStr, 128);
        wcscat_s(&String, 0x400u, L"   ");
        wcscat_s(&String, 0x400u, &DateStr);
      }
      else
      {
        wcscpy_s(&String, 0x400u, L"n/a");
      }
      SetDlgItemTextW(v4, 1007, &String);
      SetDlgItemTextW(v4, 19, *(v21 + 88));
      PropSheet_UpdateTab(v4);
      ShowWindow(v4, 1);
      goto LABEL_141;
    case 0x111u:
      if ( LOWORD(v88.field_4) > 1306 )
      {
        if ( LOWORD(v88.field_4) > 40001 )
        {
          if ( LOWORD(v88.field_4) == 40002 )
          {
            SetEvent(ghRefreshEventHandle);
            return 0;
          }
          if ( LOWORD(v88.field_4) - 40092 > 1 )
            return 0;
          v76 = v88.field_4;
        }
        else
        {
          if ( LOWORD(v88.field_4) != 40001 )
          {
            if ( LOWORD(v88.field_4) == 1307 )
            {
              sub_100B780(hWnd, *(v5 + 792));
              goto LABEL_141;
            }
            if ( LOWORD(v88.field_4) != 1671 )
              return 0;
            if ( SubmitExeToVirusTotalDotCom() )
            {
              v69 = lpString;
              v70 = 0;
              v71 = *(lpString + 211);
              if ( v71 )
              {
                v70 = 1;
                *(v71 + 4) = 6;
              }
              sub_1061C30(v69, 1, v70 != 0);
              v72 = sub_1061C10(*(v69 + 211));
              v73 = GetDlgItem(hWnd, 1671);
              EnableWindow(v73, v72);
              sub_1061A50(*(v69 + 211), &Dest);
              SetDlgItemTextW(hWnd, 1672, &Dest);
              PostMessageW(ghMainWnd, 0x7F9u, 0, *(v69 + 211));
            }
            goto LABEL_141;
          }
          v76 = 40014;
        }
        v75 = GetParent(hWnd);
        PostMessageW(v75, 0x111u, v76, 0);
        return 0;
      }
      if ( LOWORD(v88.field_4) == 1306 )
      {
        sub_100B780(hWnd, *(v5 + 828));
        goto LABEL_141;
      }
      if ( LOWORD(v88.field_4) > 1004 )
      {
        if ( LOWORD(v88.field_4) == 1005 )
        {
          v67 = VerifyImage(v5, 1);
          SetDlgItemTextW(hWnd, 3, v67);
          v68 = GetDlgItem(hWnd, 1005);
          EnableWindow(v68, 0);
          goto LABEL_141;
        }
        if ( LOWORD(v88.field_4) == 1160 )
        {
          v65 = *(v5 + 68);
          v66 = GetParent(hWnd);
          sub_1026B90(v66, 40084, v65);
          RefreshMenuWithTreeViewItemStatus(lpString);
          goto LABEL_141;
        }
        return 0;
      }
      switch ( LOWORD(v88.field_4) )
      {
        case 0x3ECu:
          if ( sub_1058030(*(v5 + 60), *(v5 + 68)) )
          {
            v64 = GetParent(hWnd);
            PostMessageW(v64, 0x471u, 5u, 0);
          }
          break;
        case 1u:
          GetDlgItemTextW(hWnd, 1190, &v88.List._Mysize, 1024);
          v62 = *(lpString + 199);
          if ( !v62 )
            goto LABEL_159;
          v63 = wcscmp(&v88.List._Mysize, v62);
          if ( v63 )
            v63 = -(v63 < 0) | 1;
          if ( v63 )
LABEL_159:
            sub_10262A0(lpString, &v88.List._Mysize);
          break;
        case 2u:
          break;
        default:
          return 0;
      }
LABEL_141:
      v61 = 1;
LABEL_142:
      if ( v6 && !InterlockedDecrement(&v6->m_RefCount) )
      {
        if ( v6->m_wstr )
        {
          SysFreeString(v6->m_wstr);
          v6->m_wstr = 0;
        }
        if ( v6->m_str )
        {
          j_j__free(v6->m_str);
          v6->m_str = 0;
        }
        j__free(v6);
      }
      return v61;
    case 0x113u:
      GetDlgItemTextW(hWnd, 1672, &v90, 245);
      sub_1061A50(*(lpString + 211), &Dest);
      v58 = wcscmp(&v90, &Dest);
      if ( v58 )
        v58 = -(v58 < 0) | 1;
      if ( v58 )
      {
        SetDlgItemTextW(hWnd, 1672, &Dest);
        v59 = sub_1061C10(*(lpString + 211));
        v60 = GetDlgItem(hWnd, 1671);
        EnableWindow(v60, v59);
      }
      goto LABEL_141;
    case 0x133u:
    case 0x136u:
      goto LABEL_112;
    case 0x138u:
      if ( dwNewLong == GetDlgItem(hWnd, 1672) && sub_1061820(*(lpString + 211)) )
      {
        if ( sub_1062910(*(lpString + 211)) )
          SetTextColor(v88.field_4, 0xFFu);
        else
          SetTextColor(v88.field_4, 0xFF0000u);
        SelectObject(v88.field_4, ghDefaultUnderlineFontHandle);
        v61 = GetSysColorBrush(20);
      }
      else
      {
LABEL_112:
        v61 = PE_FillControl(hWnd, v88.field_4);
      }
      goto LABEL_142;
    default:
      return 0;
  }
}
// 1025410: using guessed type _DWORD __cdecl unknown_libname_2(char);
// 10C4E54: using guessed type int gdwVersion;
// 10CA390: using guessed type char gbIsProcessDEPEnabled;
// 10CA391: using guessed type char gbWintrustInited;

//----- (01043C50) --------------------------------------------------------
int __stdcall PageProcJob(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  CResizer *v4; // eax
  void (__stdcall *v5)(HANDLE); // edi
  HWND v6; // edi
  LONG v7; // eax
  LRESULT (__stdcall *v8)(HWND, UINT, WPARAM, LPARAM); // esi
  DWORD *v9; // edi
  DWORD v10; // esi
  DWORD *v11; // eax
  HWND v12; // eax
  LRESULT v13; // eax
  HWND v14; // eax
  HWND v15; // ebx
  LONG v16; // eax
  HWND v17; // eax
  __int16 v18; // ax
  HANDLE v19; // esi
  char v20; // al
  void *v21; // edi
  DWORD v22; // esi
  int result; // eax
  HWND v24; // eax
  WPARAM v25; // [esp-8h] [ebp-1174h]
  LPARAM v26; // [esp+10h] [ebp-115Ch]
  int v27; // [esp+1Ch] [ebp-1150h]
  int v28; // [esp+20h] [ebp-114Ch]
  LPARAM lParam; // [esp+44h] [ebp-1128h]
  LRESULT v30; // [esp+48h] [ebp-1124h]
  int v31; // [esp+4Ch] [ebp-1120h]
  int v32; // [esp+50h] [ebp-111Ch]
  int v33; // [esp+54h] [ebp-1118h]
  wchar_t *v34; // [esp+58h] [ebp-1114h]
  int v35; // [esp+60h] [ebp-110Ch]
  HWND v36; // [esp+64h] [ebp-1108h]
  UINT v37; // [esp+78h] [ebp-10F4h]
  int v38; // [esp+7Ch] [ebp-10F0h]
  UINT pnIDs; // [esp+80h] [ebp-10ECh]
  int v40; // [esp+84h] [ebp-10E8h]
  DWORD dwValue4; // [esp+88h] [ebp-10E4h]
  HANDLE v42; // [esp+8Ch] [ebp-10E0h]
  WORD pnWidths[2]; // [esp+90h] [ebp-10DCh]
  _DWORD *v44; // [esp+94h] [ebp-10D8h]
  HANDLE hObject; // [esp+98h] [ebp-10D4h]
  HWND v46; // [esp+9Ch] [ebp-10D0h]
  HWND v47; // [esp+A0h] [ebp-10CCh]
  size_t ReturnLength; // [esp+A4h] [ebp-10C8h]
  int v49; // [esp+A8h] [ebp-10C4h]
  __int64 JobObjectInformation; // [esp+ACh] [ebp-10C0h]
  __int64 v51; // [esp+B4h] [ebp-10B8h]
  int v52; // [esp+BCh] [ebp-10B0h]
  unsigned int v53; // [esp+C0h] [ebp-10ACh]
  unsigned int v54; // [esp+C4h] [ebp-10A8h]
  char ArgList[4]; // [esp+C8h] [ebp-10A4h]
  char v56[4]; // [esp+CCh] [ebp-10A0h]
  char v57[4]; // [esp+D0h] [ebp-109Ch]
  char v58[4]; // [esp+D4h] [ebp-1098h]
  unsigned int v59; // [esp+10Ch] [ebp-1060h]
  unsigned int v60; // [esp+110h] [ebp-105Ch]
  wchar_t pszText; // [esp+11Ch] [ebp-1050h]
  wchar_t Dst; // [esp+91Ch] [ebp-850h]
  wchar_t v63; // [esp+111Ch] [ebp-50h]
  int v64; // [esp+1168h] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  lParam = 0;
  memset(&v30, 0, 0x30u);
  pnIDs = 3;
  v40 = 4;
  v37 = 1075;
  v38 = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  switch ( a2 )
  {
    case 273:
      switch ( wParam )
      {
        case 0x9C41u:
          v25 = 40014;
          goto LABEL_90;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          result = 0;
          break;
        case 0x9C9Cu:
        case 0x9C9Du:
          v25 = wParam;
LABEL_90:
          v24 = GetParent(hWnd);
          PostMessageW(v24, 0x111u, v25, 0);
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    case 43:
      CMainWnd::DrawList(dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, dwNewLong);
  }
  if ( a2 != 272 )
    return 0;
  v4 = operator new(0x40u);
  v42 = v4;
  v64 = 0;
  if ( v4 )
    CResizer::CResizer(v4, hWnd);
  v64 = -1;
  PropSheet_UpdateTab(hWnd);
  SetWindowLongW(hWnd, -21, dwNewLong);
  QuerySystemHandleInfo(1u);
  v42 = PE_OpenProcess(0x2000000u, 0, *(dwNewLong + 68));
  v5 = CloseHandle;
  if ( PE_IsProcessInJob(v42, *(dwNewLong + 68), &hObject, &dwValue4) )
  {
    if ( *dwValue4 )
      SetDlgItemTextW(hWnd, 1075, dwValue4);
    else
      SetDlgItemTextW(hWnd, 1075, L"<Unnamed Job>");
    v6 = GetDlgItem(hWnd, 1076);
    v46 = v6;
    v7 = GetWindowLongW(v6, -16);
    SetWindowLongW(v6, -16, v7 & 0xFFFFFFFD | 1);
    v8 = SendMessageW;
    SendMessageW(v6, 0x1036u, 0x4020u, 16416);
    gOldListWndProc = SetWindowLongW(v6, -4, Proxy_ListCtrlWndProc);
    SendMessageW(v6, 0x30u, ghConfigFont, 0);
    InitListHeader(v6, &pnIDs, pnWidths, 2);
    ReturnLength = 1200;
    v9 = malloc(0x4B0u);
    if ( !QueryInformationJobObject(hObject, JobObjectBasicProcessIdList, v9, 0x4B0u, &ReturnLength) )
    {
      do
      {
        if ( GetLastError() != 24 )
          break;
        free(v9);
        v10 = ReturnLength;
        v9 = malloc(ReturnLength);
      }
      while ( !QueryInformationJobObject(hObject, JobObjectBasicProcessIdList, v9, v10, &ReturnLength) );
      v8 = SendMessageW;
    }
    if ( v9 )
    {
      v47 = 0;
      if ( v9[1] )
      {
        v11 = v9 + 2;
        v44 = v9 + 2;
        do
        {
          SystemProcessInfo_GetSystemProcessName(*v11, 0, &pszText, 0x400u);
          wsprintf_s(&v63, L"%d", *v44);
          lParam = 5;
          v34 = &pszText;
          v12 = (v47 + 1);
          v30 = 0x7FFFFFFF;
          v47 = v12;
          v36 = v12;
          v31 = 0;
          v33 = 0;
          v32 = 0;
          v35 = 0;
          v13 = v8(v46, 0x104Du, 0, &lParam);
          if ( v13 == -1 )
            return 0;
          v30 = v13;
          v34 = &v63;
          lParam = 1;
          v31 = 1;
          v8(v46, 0x104Cu, 0, &lParam);
          v11 = v44 + 1;
          ++v44;
        }
        while ( v47 < v9[1] );
      }
      v8(v46, 0x101Eu, 0, 0xFFFF);
      v8(v46, 0x101Eu, 1u, 65534);
      v28 = 3;
      v27 = 3;
      v8(v46, 0x102Bu, 0, &v26);
      SetFocus(v46);
      free(v9);
    }
    v14 = GetDlgItem(hWnd, 1077);
    v15 = v14;
    v47 = v14;
    v16 = GetWindowLongW(v14, -16);
    SetWindowLongW(v15, -16, v16 & 0xFFFFFFFD | 1);
    v8(v15, 0x1036u, 0x4020u, 16416);
    v17 = v8(v15, 0x104Eu, 0, 0);
    CTreeList::InitToolTips(v17);
    gOldListWndProc = SetWindowLongW(v15, -4, Proxy_ListCtrlWndProc);
    v8(v15, 0x30u, ghConfigFont, 0);
    InitListHeader(v15, &v37, pnWidths, 2);
    QueryInformationJobObject(
      hObject,
      MaxJobObjectInfoClass|JobObjectBasicAccountingInformation,
      &JobObjectInformation,
      0x70u,
      &ReturnLength);
    v18 = v52;
    if ( v52 & 0x2000 )
    {
      sub_1057F90(v15, L"Kill on Job Close", L"True");
      v18 = v52;
    }
    if ( v18 & 0x400 )
    {
      sub_1057F90(v15, L"Die on Unhandled Exception", L"True");
      v18 = v52;
    }
    if ( v18 & 0x800 )
    {
      sub_1057F90(v15, L"Breakaway OK", L"True");
      v18 = v52;
    }
    if ( v18 & 0x1000 )
    {
      sub_1057F90(v15, L"Silent Breakaway OK", L"True");
      v18 = v52;
    }
    if ( v18 & 0x40 )
    {
      sub_1057F90(v15, L"Preserve Job Time", L"True");
      v18 = v52;
    }
    if ( v18 & 0x4000 )
    {
      sub_1057F90(v15, L"Subset Affinity Allowed", L"True");
      v18 = v52;
    }
    if ( v18 & 2 )
    {
      wsprintfW(&Dst, L"%I64d s", JobObjectInformation / 10000000);
      sub_1057F90(v15, L"Process CPU Limit", &Dst);
      v18 = v52;
    }
    if ( v18 & 4 )
    {
      wsprintfW(&Dst, L"%I64d s", v51 / 10000000);
      sub_1057F90(v15, L"User CPU Limit", &Dst);
      v18 = v52;
    }
    if ( v18 & 1 )
    {
      wsprintfW(&Dst, L"%d", v53 >> 10);
      PE_GetNumberFormat(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_1057F90(v15, L"Min Working Set", &Dst);
      v18 = v52;
      if ( v52 & 1 )
      {
        wsprintfW(&Dst, L"%d", v54 >> 10);
        PE_GetNumberFormat(&Dst, 0x400u);
        wcscat_s(&Dst, 0x400u, L" KB");
        sub_1057F90(v15, L"Max Working Set", &Dst);
        v18 = v52;
      }
    }
    if ( v18 & 0x100 )
    {
      wsprintfW(&Dst, L"%d", v59 >> 10);
      PE_GetNumberFormat(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_1057F90(v15, L"Process Memory Limit", &Dst);
      v18 = v52;
    }
    if ( v18 & 0x200 )
    {
      wsprintfW(&Dst, L"%d", v60 >> 10);
      PE_GetNumberFormat(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_1057F90(v15, L"Job Memory Limit", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 8 )
    {
      wsprintfW(&Dst, L"%d", *ArgList);
      sub_1057F90(v15, L"Active Processes", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 0x10 )
    {
      wsprintfW(&Dst, L"%x", *v56);
      sub_1057F90(v15, L"Affinity", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 0x20 )
    {
      wsprintfW(&Dst, L"%d", *v57);
      sub_1057F90(v15, L"Priority Class", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( (v18 & 0x80u) != 0 )
    {
      wsprintfW(&Dst, L"%d", *v58);
      sub_1057F90(v15, L"Scheduling Class", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 4 )
    {
      wsprintfW(
        &Dst,
        L"%I64d:%02I64d:%02I64d.%03I64d",
        v51 / 0x861C46800ui64,
        v51 / 0x23C34600ui64 % 0x3C,
        v51 / 10000000 % 60,
        v51 % 10000000 / 10000);
      v15 = v47;
      sub_1057F90(v47, L"Job Time", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 2 )
    {
      wsprintfW(
        &Dst,
        L"%I64d:%02I64d:%02I64d.%03I64d",
        JobObjectInformation / 0x861C46800ui64,
        JobObjectInformation / 0x23C34600ui64 % 0x3C,
        JobObjectInformation / 10000000 % 60,
        JobObjectInformation % 10000000 / 10000);
      v15 = v47;
      sub_1057F90(v47, L"Process Time", &Dst);
    }
    v19 = hObject;
    QueryInformationJobObject(hObject, JobObjectBasicUIRestrictions, &v49, 4u, &ReturnLength);
    v20 = v49;
    if ( v49 & 0x40 )
    {
      sub_1057F90(v15, L"Desktop", L"Limited");
      v20 = v49;
    }
    if ( v20 & 0x10 )
    {
      sub_1057F90(v15, L"Display Settings", L"Limited");
      v20 = v49;
    }
    if ( v20 < 0 )
    {
      sub_1057F90(v15, L"Exit Windows", L"Limited");
      v20 = v49;
    }
    if ( v20 & 0x20 )
    {
      sub_1057F90(v15, L"Global Atoms", L"Limited");
      v20 = v49;
    }
    if ( v20 & 1 )
    {
      sub_1057F90(v15, L"USER Handles", L"Limited");
      v20 = v49;
    }
    if ( v20 & 2 )
    {
      sub_1057F90(v15, L"Read Clipboard", L"Limited");
      v20 = v49;
    }
    if ( v20 & 8 )
    {
      sub_1057F90(v15, L"System Parameters", L"Limited");
      v20 = v49;
    }
    if ( v20 & 4 )
      sub_1057F90(v15, L"Write Clipboard", L"Limited");
    ReturnLength = 2000;
    v21 = malloc(0x7D0u);
    if ( !QueryInformationJobObject(v19, JobObjectSecurityLimitInformation, v21, 0x7D0u, &ReturnLength) )
    {
      do
      {
        if ( GetLastError() != 24 )
          break;
        free(v21);
        v22 = ReturnLength;
        v21 = malloc(ReturnLength);
      }
      while ( !QueryInformationJobObject(hObject, JobObjectSecurityLimitInformation, v21, v22, &ReturnLength) );
    }
    if ( v49 & 1 )
      sub_1057F90(v15, L"Administrator Access", L"Limited");
    free(v21);
    if ( SendMessageW(v15, 0x1004u, 0, 0) )
    {
      SendMessageW(v15, 0x101Eu, 0, 0xFFFF);
      SendMessageW(v15, 0x101Eu, 1u, 65534);
      v28 = 3;
      v27 = 3;
      SendMessageW(v15, 0x102Bu, 0, &v26);
    }
    v5 = CloseHandle;
    CloseHandle(hObject);
    free(dwValue4);
  }
  else
  {
    SetDlgItemTextW(hWnd, 1075, L"<Access denied>");
  }
  if ( v42 )
    v5(v42);
  return 1;
}
// 109BDE8: using guessed type wchar_t aDesktop_0[8];
// 10A5C9C: using guessed type wchar_t aTrue_1[5];
// 10A5CA8: using guessed type wchar_t aKillOnJobClose[18];
// 10A5CCC: using guessed type wchar_t aDieOnUnhandled[27];
// 10A5D04: using guessed type wchar_t aBreakawayOk[13];
// 10A5D20: using guessed type wchar_t aSilentBreakawa[20];
// 10A5D48: using guessed type wchar_t aPreserveJobTim[18];
// 10A5D6C: using guessed type wchar_t aSubsetAffinity[24];
// 10A5DAC: using guessed type wchar_t aProcessCpuLimi[18];
// 10A5DD0: using guessed type wchar_t aUserCpuLimit[15];
// 10A5DF0: using guessed type wchar_t aMinWorkingSet[16];
// 10A5E10: using guessed type wchar_t aMaxWorkingSet[16];
// 10A5E30: using guessed type wchar_t aProcessMemoryL[21];
// 10A5E5C: using guessed type wchar_t aJobMemoryLimit[17];
// 10A5E80: using guessed type wchar_t aActiveProcesse[17];
// 10A5EAC: using guessed type wchar_t aAffinity[9];
// 10A5EC0: using guessed type wchar_t aPriorityClass[15];
// 10A5EE0: using guessed type wchar_t aSchedulingClas[17];
// 10A5F04: using guessed type wchar_t aJobTime[9];
// 10A5F18: using guessed type wchar_t aProcessTime[13];
// 10A5F34: using guessed type wchar_t aLimited[8];
// 10A5F44: using guessed type wchar_t aDisplaySetting[17];
// 10A5F68: using guessed type wchar_t aExitWindows[13];
// 10A5F84: using guessed type wchar_t aGlobalAtoms[13];
// 10A5FA0: using guessed type wchar_t aUserHandles[13];
// 10A5FBC: using guessed type wchar_t aReadClipboard[15];
// 10A5FDC: using guessed type wchar_t aSystemParamete[18];
// 10A6000: using guessed type wchar_t aWriteClipboard[16];
// 10A6020: using guessed type wchar_t aAdministratorA[21];

//----- (01044990) --------------------------------------------------------
int __stdcall PageProcGPU(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  HWND v4; // eax
  int result; // eax
  CResizer *v6; // eax
  LONG v7; // eax
  HWND v8; // ebx
  HWND v9; // edi
  HWND v10; // esi
  HWND v11; // ebx
  HWND v12; // edi
  HWND v13; // esi
  HWND v14; // ebx
  HWND v15; // edi
  HWND v16; // esi
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  HWND v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  WPARAM v29; // [esp-8h] [ebp-40h]
  CResizer *v30; // [esp+10h] [ebp-28h]
  HWND v31; // [esp+18h] [ebp-20h]
  HWND v32; // [esp+1Ch] [ebp-1Ch]
  HWND v33; // [esp+20h] [ebp-18h]
  HWND v34; // [esp+24h] [ebp-14h]
  int v35; // [esp+34h] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  if ( a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  if ( a2 == 275 || a2 == 5 )
  {
    if ( IsWindowVisible(hWnd) )
    {
      v21 = GetDlgItem(hWnd, 1158);
      SendMessageW(v21, 0x400u, 0, 0);
      v22 = GetDlgItem(hWnd, 2000);
      SendMessageW(v22, 0x400u, 0, 0);
      v23 = GetDlgItem(hWnd, 1160);
      SendMessageW(v23, 0x400u, 0, 0);
      v24 = GetDlgItem(hWnd, 2601);
      SendMessageW(v24, 0x400u, 0, 0);
      v25 = GetDlgItem(hWnd, 1162);
      SendMessageW(v25, 0x400u, 0, 0);
      v26 = GetDlgItem(hWnd, 2602);
      SendMessageW(v26, 0x400u, 0, 0);
      v27 = GetDlgItem(hWnd, 1164);
      SendMessageW(v27, 0x400u, 0, 0);
      v28 = GetDlgItem(hWnd, 2603);
      SendMessageW(v28, 0x400u, 0, 0);
      return 0;
    }
    return 0;
  }
  if ( a2 == 272 )
  {
    v6 = operator new(0x40u);
    v35 = 0;
    if ( v6 )
      v30 = CResizer::CResizer(v6, hWnd);
    else
      v30 = 0;
    v35 = -1;
    v7 = GetWindowLongW(hWnd, -16);
    SetWindowLongW(hWnd, -16, v7 | 0x2000000);
    SetWindowLongW(hWnd, -21, dwNewLong);
    CreateGraphWindow(hWnd, 1158, *(dwNewLong + 1392));
    CreateGraphWindow(hWnd, 2000, *(dwNewLong + 1392));
    CreateGraphWindow(hWnd, 1160, *(dwNewLong + 1432));
    CreateGraphWindow(hWnd, 2601, *(dwNewLong + 1432));
    CreateGraphWindow(hWnd, 1162, *(dwNewLong + 1416));
    CreateGraphWindow(hWnd, 2602, *(dwNewLong + 1416));
    CreateGraphWindow(hWnd, 1164, *(dwNewLong + 1448));
    CreateGraphWindow(hWnd, 2603, *(dwNewLong + 1448));
    v8 = GetDlgItem(hWnd, 1659);
    v9 = GetDlgItem(hWnd, 1161);
    v10 = GetDlgItem(hWnd, 1159);
    v31 = GetDlgItem(hWnd, 1157);
    v32 = v10;
    v33 = v9;
    v34 = v8;
    sub_1050550(v30, 4, &v31);
    v11 = GetDlgItem(hWnd, 1164);
    v12 = GetDlgItem(hWnd, 1162);
    v13 = GetDlgItem(hWnd, 1160);
    v31 = GetDlgItem(hWnd, 1158);
    v32 = v13;
    v33 = v12;
    v34 = v11;
    sub_1050550(v30, 4, &v31);
    v14 = GetDlgItem(hWnd, 2603);
    v15 = GetDlgItem(hWnd, 2602);
    v16 = GetDlgItem(hWnd, 2601);
    v31 = GetDlgItem(hWnd, 2000);
    v33 = v15;
    v32 = v16;
    v34 = v14;
    sub_1050550(v30, 4, &v31);
    v17 = GetDlgItem(hWnd, 1157);
    *&CResizer::AddItem(v30, v17, 1)->m_rect2.right = db_four;
    v18 = GetDlgItem(hWnd, 1159);
    *&CResizer::AddItem(v30, v18, 1)->m_rect2.right = db_four;
    v19 = GetDlgItem(hWnd, 1161);
    *&CResizer::AddItem(v30, v19, 1)->m_rect2.right = db_four;
    v20 = GetDlgItem(hWnd, 1659);
    *&CResizer::AddItem(v30, v20, 1)->m_rect2.right = db_four;
    PropSheet_UpdateTab(hWnd);
    SendMessageW(hWnd, 0x113u, 0, 0);
    return 1;
  }
  if ( a2 != 273 )
    return 0;
  switch ( wParam )
  {
    case 0x9C41u:
      v29 = 40014;
      goto LABEL_8;
    case 0x9C42u:
      SetEvent(ghRefreshEventHandle);
      result = 0;
      break;
    case 0x9C9Cu:
    case 0x9C9Du:
      v29 = wParam;
LABEL_8:
      v4 = GetParent(hWnd);
      PostMessageW(v4, 0x111u, v29, 0);
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}
// 109CB38: using guessed type double db_four;

//----- (01044E40) --------------------------------------------------------
signed int __stdcall PageProcPerf(HWND hWnd, unsigned int a2, HDC hdc, int a4)
{
  HWND v4; // ebx
  char *v5; // esi
  HICON v6; // ST50_4
  HWND v7; // eax
  char *v8; // esi
  HANDLE v9; // edi
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  signed int result; // eax
  HWND v14; // eax
  HANDLE v15; // edi
  void (__stdcall *v16)(HWND, int, LPCWSTR); // esi
  const WCHAR *v17; // eax
  const WCHAR *v18; // eax
  const WCHAR *v19; // eax
  const WCHAR *v20; // eax
  const WCHAR *v21; // eax
  const WCHAR *v22; // eax
  __m128i *v23; // eax
  const WCHAR *v24; // eax
  int v25; // ecx
  const WCHAR *v26; // ST50_4
  const WCHAR *v27; // eax
  const WCHAR *v28; // ST50_4
  char v29; // al
  const WCHAR *v30; // eax
  char v31; // al
  const WCHAR *v32; // eax
  signed __int64 v33; // [esp+4Ch] [ebp-500h]
  char v34; // [esp+54h] [ebp-4F8h]
  int v35; // [esp+60h] [ebp-4ECh]
  char ArgList[4]; // [esp+6Ch] [ebp-4E0h]
  struct _FILETIME LocalFileTime; // [esp+78h] [ebp-4D4h]
  char v38; // [esp+80h] [ebp-4CCh]
  _DWORD v39[2]; // [esp+84h] [ebp-4C8h]
  char v40[4]; // [esp+8Ch] [ebp-4C0h]
  char ProcessInformation[4]; // [esp+90h] [ebp-4BCh]
  char v42[4]; // [esp+94h] [ebp-4B8h]
  char v43[4]; // [esp+98h] [ebp-4B4h]
  int v44; // [esp+9Ch] [ebp-4B0h]
  unsigned int v45; // [esp+A0h] [ebp-4ACh]
  unsigned int v46; // [esp+A4h] [ebp-4A8h]
  HANDLE v47; // [esp+A8h] [ebp-4A4h]
  void *v48; // [esp+ACh] [ebp-4A0h]
  HWND hDlg; // [esp+B0h] [ebp-49Ch]
  ULONG ReturnLength; // [esp+B4h] [ebp-498h]
  char *v51; // [esp+B8h] [ebp-494h]
  struct _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-490h]
  char v53[16]; // [esp+CCh] [ebp-480h]
  __int128 v54; // [esp+DCh] [ebp-470h]
  int v55; // [esp+ECh] [ebp-460h]
  unsigned int v56; // [esp+F0h] [ebp-45Ch]
  unsigned int v57; // [esp+F4h] [ebp-458h]
  char v58[16]; // [esp+F8h] [ebp-454h]
  char v59[16]; // [esp+108h] [ebp-444h]
  __int128 v60; // [esp+118h] [ebp-434h]
  FILETIME FileTime; // [esp+128h] [ebp-424h]
  unsigned __int64 v62; // [esp+138h] [ebp-414h]
  unsigned __int64 v63; // [esp+140h] [ebp-40Ch]
  WCHAR DateStr; // [esp+148h] [ebp-404h]
  WCHAR String; // [esp+348h] [ebp-204h]

  v4 = hWnd;
  hDlg = hWnd;
  v5 = GetWindowLongW(hWnd, -21);
  v48 = 0;
  v51 = v5;
  if ( a2 <= 0x133 )
  {
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 0x100u:
          if ( hdc != 116 )
            return 0;
          PostMessageW(hWnd, 0x113u, 1u, 0);
          result = 0;
          break;
        case 0x110u:
          PropSheet_UpdateTab(hWnd);
          v6 = LoadIconW(ghInstance, 0x6E);
          v7 = GetDlgItem(hWnd, 1119);
          SendMessageW(v7, 0x172u, 1u, v6);
          v8 = malloc(0x60u);
          v48 = v8;
          *v8 = a4;
          v9 = OpenProcess(0x400u, 0, *(a4 + 68));
          if ( v9 || (v9 = OpenProcess(0x1000u, 0, *(*v8 + 68))) != 0 )
          {
            NtQueryInformationProcess(v9, ProcessVmCounters, v8 + 4, 0x2Cu, &ReturnLength);
            NtQueryInformationProcess(v9, ProcessIoCounters, v8 + 48, 0x30u, &ReturnLength);
            if ( NtQueryInformationProcess(v9, ProcessHandleCount, ProcessInformation, 8u, &ReturnLength) )
            {
              v10 = GetDlgItem(hWnd, 1609);
              EnableWindow(v10, 0);
              v11 = GetDlgItem(hWnd, 1052);
              EnableWindow(v11, 0);
              v8 = v48;
            }
            CloseHandle(v9);
          }
          if ( !QueryProcessCycleTime )
          {
            v12 = GetDlgItem(hWnd, 1324);
            SetWindowTextW(v12, L"Context Switch Delta");
          }
          SetWindowLongW(hWnd, -21, v8);
          SendMessageW(hWnd, 0x113u, 0, 0);
          result = 0;
          break;
        case 0x111u:
          switch ( hdc )
          {
            case 0x9C41u:
              v33 = 40014i64;
              goto LABEL_18;
            case 0x9C42u:
              SetEvent(ghRefreshEventHandle);
              result = 0;
              break;
            case 0x9C9Cu:
            case 0x9C9Du:
              v33 = hdc;
LABEL_18:
              v14 = GetParent(hWnd);
              PostMessageW(v14, 0x111u, v33, SHIDWORD(v33));
              result = 0;
              break;
            default:
              return 0;
          }
          break;
        case 0x113u:
          v15 = OpenProcess(0x400u, 0, *(*v5 + 68));
          v47 = v15;
          if ( v15 || (v15 = OpenProcess(0x1000u, 0, *(*v5 + 68)), (v47 = v15) != 0) )
          {
            v16 = SetDlgItemTextW;
            if ( !NtQueryInformationProcess(v15, 0, &v35, 0x18u, &ReturnLength) )
            {
              wsprintf(&String, L"%d", ArgList[0]);
              SetDlgItemTextW(hWnd, 1042, &String);
            }
            if ( !NtQueryInformationProcess(v15, ProcessTimes, &FileTime, 0x20u, &ReturnLength) )
            {
              if ( FileTime )
              {
                FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
                FileTimeToSystemTime(&LocalFileTime, &SystemTime);
                GetTimeFormatW(0x400u, 0, &SystemTime, 0, &String, 128);
                GetDateFormatW(0x400u, 0, &SystemTime, 0, &DateStr, 128);
                wcscat_s(&String, 0x100u, L"   ");
                wcscat_s(&String, 0x100u, &DateStr);
              }
              else
              {
                wcscpy_s(&String, 0x100u, L"n/a");
              }
              SetDlgItemTextW(hWnd, 1007, &String);
              wsprintf(&String, L"%I64d:%02I64d:%02I64d.%03I64d", v62 / 0x861C46800i64);
              SetDlgItemTextW(hDlg, 1012, &String);
              wsprintf(&String, L"%I64d:%02I64d:%02I64d.%03I64d", v63 / 0x861C46800i64);
              SetDlgItemTextW(hDlg, 1013, &String);
              v46 = v62 + v63;
              wsprintf(&String, L"%I64d:%02I64d:%02I64d.%03I64d", (v62 + v63) / 0x861C46800i64);
              v4 = hDlg;
              v16 = SetDlgItemTextW;
              SetDlgItemTextW(hDlg, 1014, &String);
              v15 = v47;
            }
            if ( NtQueryInformationProcess(v15, ProcessIoCounters, v58, 0x30u, &ReturnLength) )
            {
              v23 = v51;
            }
            else
            {
              wsprintf(&String, L"%I64d", v58[0]);
              v17 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1041, v17);
              wsprintf(&String, L"%I64d", v58[0] - v51[48]);
              v18 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1044, v18);
              wsprintf(&String, L"%I64d", v58[8]);
              v19 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1043, v19);
              wsprintf(&String, L"%I64d", v58[8] - v51[56]);
              v20 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1050, v20);
              wsprintf(&String, L"%I64d", v59[0]);
              v21 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1045, v21);
              wsprintf(&String, L"%I64d", v59[0] - v51[64]);
              v22 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1049, v22);
              PE_FormatDouble(0, &String, 0x100u, (v60 - *(v51 + 10)), 0.0, COERCE_DOUBLE(0i64 >> 63));
              v16(v4, 1334, &String);
              PE_FormatDouble(0, &String, 0x100u, (*&v59[8] - *(v51 + 9)), 0.0, COERCE_DOUBLE(0i64 >> 63));
              v16(v4, 1333, &String);
              PE_FormatDouble(0, &String, 0x100u, (*(&v60 + 1) - *(v51 + 11)), 0.0, COERCE_DOUBLE(0i64 >> 63));
              v16(v4, 1051, &String);
              v23 = v51;
              _mm_storeu_si128(v51 + 3, _mm_loadu_si128(v58));
              _mm_storeu_si128(v23 + 4, _mm_loadu_si128(v59));
              _mm_storeu_si128(v23 + 5, _mm_loadu_si128(&v60));
            }
            if ( QueryProcessCycleTime )
            {
              QueryProcessCycleTime(QueryProcessCycleTime, v15);
              wsprintf(&String, L"%I64u", v39[0]);
            }
            else
            {
              wsprintf(&String, L"%I64d", *(v23->m128i_i32[0] + 1336));
            }
            v24 = PE_GetNumberFormat(&String, 0x100u);
            v16(v4, 1195, v24);
            if ( NtQueryInformationProcess(v15, ProcessPagePriority, v43, 4u, &ReturnLength) )
              wsprintf(&String, L"n/a", v34);
            else
              wsprintf(&String, L"%d", v43[0]);
            v16(v4, 1339, &String);
            if ( NtQueryInformationProcess(v15, ProcessIoPriority, &v44, 4u, &ReturnLength) )
              wsprintf(&String, L"n/a", v34);
            else
              sub_1057790(v44, &String, 0x100u);
            v16(v4, 1340, &String);
            v47 = 0;
            sub_103EB20(v15, &v48, &v47, &v38, &v46, &v45, &hDlg);
            free(v48);
            wsprintf(&String, L"%ld", v46 >> 10);
            PE_GetNumberFormat(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1067, &String);
            wsprintf(&String, L"%ld", hDlg >> 10);
            PE_GetNumberFormat(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1069, &String);
            wsprintf(&String, L"%ld", v45 >> 10);
            PE_GetNumberFormat(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1068, &String);
            if ( !NtQueryInformationProcess(v15, ProcessVmCounters, v53, 0x2Cu, &ReturnLength) )
            {
              wsprintf(&String, L"%ld", v54 >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1008, &String);
              wsprintf(&String, L"%ld", *&v53[12] >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1064, &String);
              wsprintf(&String, L"%ld", v56 >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1009, &String);
              wsprintf(&String, L"%ld", v57 >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1010, &String);
              wsprintf(&String, L"%I64u", *&v53[4] >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1060, &String);
              wsprintf(&String, L"%ld", v53[8]);
              PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1065, &String);
              wsprintf(&String, L"%d", v53[8] - v51[12]);
              PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1066, &String);
              v25 = v51;
              _mm_storeu_si128((v51 + 4), _mm_loadu_si128(v53));
              _mm_storeu_si128((v25 + 20), _mm_loadu_si128(&v54));
              _mm_storel_epi64((v25 + 36), _mm_loadl_epi64(&v55));
              *(v25 + 44) = v57;
            }
            if ( NtQueryInformationProcess(v15, ProcessHandleCount, ProcessInformation, 8u, &ReturnLength) )
            {
              if ( !NtQueryInformationProcess(v15, ProcessHandleCount, v40, 4u, &ReturnLength) )
              {
                wsprintf(&String, L"%d", v40[0]);
                v26 = PE_GetNumberFormat(&String, 0x100u);
                v16(v4, 1048, v26);
              }
            }
            else
            {
              wsprintf(&String, L"%d", ProcessInformation[0]);
              v27 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1048, v27);
              wsprintf(&String, L"%d", v42[0]);
              v28 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1052, v28);
            }
            if ( *GetGuiResources )
            {
              v29 = GetGuiResources(v15, 0);
              wsprintf(&String, L"%d", v29);
              v30 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1046, v30);
              v31 = GetGuiResources(v15, 1u);
              wsprintf(&String, L"%d", v31);
              v32 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1047, v32);
            }
            CloseHandle(v15);
          }
          result = 1;
          break;
        default:
          return 0;
      }
      return result;
    }
    return PE_FillControl(hWnd, hdc);
  }
  if ( a2 == 310 || a2 == 312 )
    return PE_FillControl(hWnd, hdc);
  if ( a2 == 2033 )
  {
    free(v5);
    DestroyWindow(hWnd);
  }
  return 0;
}
