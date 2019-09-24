
//----- (00C6AD00) --------------------------------------------------------
char __usercall CTreeList::InitTreeList@<al>(HWND hWndListCtrl, char flags)
{
  int v2; // ebp
  double v3; // st1
  double v4; // st2
  double v5; // st3
  double v6; // st4
  double v7; // st5
  double v8; // st6
  double v9; // st7
  void *v10; // esp
  signed int v11; // ecx
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfoLast; // ecx
  int nSystemProcessInfoLengthLast; // edx
  std__Tree_node *Tree_node_8; // esi
  int v15; // edi
  FILETIME TimeRet; // rax
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_11; // eax
  unsigned int v18; // ecx
  DWORD dwNumberOfProcessors; // edx
  signed int nProcessorIndex; // esi
  int nIndex; // edi
  DWORD v22; // ecx
  DWORD v23; // edx
  LONG v24; // edx
  unsigned __int64 v25; // kr20_8
  float v26; // xmm0_4
  float v27; // xmm0_4
  double v28; // xmm1_8
  float v29; // xmm0_4
  CGraphData *v30; // eax
  float v31; // xmm0_4
  float v32; // xmm0_4
  double v33; // xmm1_8
  float v34; // xmm0_4
  CGraphData *v35; // eax
  unsigned __int64 v36; // rax
  tagTREEVIEWLISTITEMPARAM *gTreeViewListItemParam; // esi
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_32; // edi
  int v39; // eax
  signed int dwProcessorIdx; // edx
  __m128i v41; // xmm7
  SYSTEM_INTERRUPT_INFORMATION *gpSystemInterruptInf; // ecx
  SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorIdleCycleTimeInfo_37; // edi
  LARGE_INTEGER *v44; // eax
  __m128i v45; // xmm6
  __m128i v46; // xmm4
  __m128i v47; // xmm3
  __m128i v48; // xmm5
  int v49; // ecx
  __m128i v50; // xmm0
  __m128i v51; // xmm2
  __m128i v52; // xmm1
  __m128i v53; // xmm2
  __m128i v54; // xmm1
  __m128i v55; // xmm2
  __m128i v56; // xmm0
  __m128i v57; // xmm1
  __m128i v58; // xmm0
  __m128i v59; // xmm2
  __m128i v60; // xmm0
  __m128i v61; // xmm1
  __m128i v62; // xmm5
  __m128i v63; // xmm6
  __m128i v64; // xmm3
  __m128i v65; // xmm4
  __m128i v66; // xmm5
  __m128i v67; // xmm3
  __m128i v68; // xmm4
  __m128i v69; // xmm6
  int v70; // edi
  unsigned int v71; // esi
  LARGE_INTEGER *v72; // edi
  __int64 v73; // kr28_8
  LONGLONG v74; // kr30_8
  unsigned __int64 v75; // kr38_8
  unsigned __int64 v76; // kr10_8
  int v77; // eax
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_72; // eax
  int v79; // eax
  int v80; // ecx
  unsigned __int8 v81; // of
  bool v82; // dl
  char v83; // al
  bool v84; // cl
  char v85; // al
  int v86; // edi
  bool v87; // dl
  char v88; // al
  bool v89; // cl
  char v90; // al
  int v91; // edi
  float v92; // xmm0_4
  float v93; // xmm0_4
  float v94; // xmm1_4
  float v95; // xmm0_4
  float v96; // xmm0_4
  unsigned int v97; // edx
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_92; // ecx
  int v99; // eax
  float v100; // xmm0_4
  float v101; // xmm0_4
  float v102; // xmm1_4
  double v103; // ST2C_8
  CGraphData *v104; // eax
  bool v105; // cl
  char v106; // al
  char v107; // al
  signed int v108; // ecx
  char v109; // al
  signed int v110; // ecx
  char v111; // al
  char v112; // cl
  char v113; // al
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_108; // eax
  int v115; // esi
  tagTREEVIEWLISTITEMPARAM **TreeViewListItemParam_110; // edi
  char v117; // al
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_112; // edi
  int v119; // eax
  int v120; // eax
  char v121; // al
  char v122; // cl
  int v123; // edi
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_118; // esi
  DWORD UniqueProcessId; // eax
  DWORD v126; // edx
  LONG v127; // esi
  unsigned __int64 v128; // kr60_8
  tagTREEVIEWLISTITEMPARAM *gTreeViewListItemParam_123; // edi
  DWORD v130; // ecx
  LONG v131; // edx
  int nItemFound; // eax
  int v133; // ecx
  char v134; // al
  unsigned int v135; // edx
  DWORD v136; // kr00_4
  DWORD v137; // kr04_4
  unsigned __int64 v138; // kr68_8
  int v139; // ecx
  int v140; // edx
  float v141; // xmm0_4
  float v142; // xmm0_4
  float v143; // xmm1_4
  double v144; // xmm0_8
  float v145; // xmm0_4
  float v146; // xmm0_4
  float v147; // xmm0_4
  float v148; // xmm0_4
  float v149; // xmm1_4
  __int64 v150; // xmm0_8
  double v151; // xmm2_8
  __m128d v152; // xmm1
  __int64 v153; // xmm1_8
  bool v154; // al
  char v155; // al
  double v156; // xmm0_8
  char v157; // al
  tagTREEVIEWLISTITEMPARAM **ppTreeViewListItemParam_152; // esi
  char v159; // al
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_154; // esi
  char v161; // al
  unsigned int v162; // eax
  int v163; // ecx
  LONG v164; // esi
  int v165; // edx
  _DWORD *v166; // eax
  _DWORD *v167; // ecx
  _WORD *v168; // esi
  _WORD *v169; // eax
  char v170; // al
  char v171; // al
  int v172; // eax
  bool v173; // cf
  unsigned __int8 v174; // al
  unsigned __int8 v175; // al
  unsigned __int8 v176; // al
  int v177; // ecx
  char v178; // al
  unsigned __int8 v179; // al
  int v180; // esi
  int v181; // eax
  char v182; // al
  int v183; // eax
  int ArgList_16; // ST3C_4
  HMENU v185; // eax
  wchar_t *v186; // ecx
  bool v187; // al
  char v188; // al
  char v189; // al
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_184; // esi
  int v191; // eax
  char v192; // al
  int v193; // eax
  char v194; // al
  int v195; // eax
  char v196; // al
  int v197; // eax
  char v198; // al
  int v199; // eax
  char v200; // al
  int v201; // eax
  char v202; // al
  int v203; // eax
  char v204; // al
  int v205; // eax
  char v206; // al
  int v207; // eax
  char v208; // al
  unsigned int v209; // ecx
  int v210; // esi
  char v211; // al
  char v212; // al
  CGraphData *pGraphData_207; // edx
  int v214; // eax
  char v215; // al
  LPARAM UniqueProcessId_2; // esi
  HWND hMainWndBackup; // esi
  int v218; // eax
  char v219; // al
  int v220; // esi
  char v221; // al
  char v222; // al
  int v223; // eax
  char v224; // al
  unsigned int v225; // ecx
  int v226; // kr08_4
  unsigned int v227; // kr0C_4
  signed __int64 v228; // rax
  float v229; // xmm0_4
  unsigned int v230; // edx
  unsigned int v231; // ecx
  float v232; // xmm0_4
  double ArgList_8; // ST34_8
  double v234; // xmm0_8
  unsigned int v235; // edx
  unsigned int v236; // ecx
  char v237; // al
  char v238; // al
  unsigned __int64 v239; // kr90_8
  signed __int64 v240; // kr98_8
  unsigned __int64 v241; // krA0_8
  char v242; // cl
  char v243; // dl
  signed int v244; // eax
  char v245; // al
  const WCHAR **pszText; // eax
  int dwStyle; // eax
  DWORD InheritedFromUniqueProcessId; // eax
  HANDLE UniqueProcessId_1; // eax
  DWORD pGraphData_244; // ecx
  DWORD *ppszText_245; // eax
  WCHAR *szProcessName; // eax
  HICON hIcon; // ecx
  HICON hIcon_1; // ecx
  DWORD *pGraphData_249; // ecx
  int v256; // ecx
  unsigned int v257; // edx
  unsigned int *v258; // eax
  signed int v259; // ecx
  unsigned __int64 v260; // krA8_8
  int v261; // ecx
  ULONG v262; // eax
  int v263; // edx
  _DWORD *v264; // eax
  _DWORD *v265; // ecx
  int v266; // eax
  signed int v267; // ecx
  float v268; // xmm0_4
  float v269; // xmm0_4
  float v270; // xmm1_4
  float v271; // xmm0_4
  float v272; // xmm0_4
  __int64 v273; // xmm0_8
  wchar_t *v274; // eax
  int dwItemStyle; // eax
  int ItemStyle_270; // eax
  tagNetCclrInfo *NetCclrInfo_271; // eax
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_272; // ecx
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_273; // edx
  wchar_t *v280; // eax
  tagDLLLISTITEMPARAM *TreeViewListItemParam_275; // ecx
  int v282; // eax
  signed __int64 v283; // krC0_8
  unsigned __int64 v284; // krC8_8
  signed int dwProcessorIndex; // esi
  LARGE_INTEGER *v286; // edx
  ULONG *v287; // edi
  LONGLONG v288; // krE0_8
  int v289; // eax
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_285; // eax
  __int64 v292; // xmm0_8
  bool v293; // cf
  bool v294; // zf
  __int64 v295; // xmm0_8
  unsigned int v296; // esi
  unsigned int v297; // edi
  float v298; // xmm0_4
  float v299; // xmm0_4
  bool v300; // al
  char v301; // al
  double v302; // xmm0_8
  char v303; // al
  char v304; // al
  LRESULT v305; // edi
  signed int i; // esi
  double v307; // xmm0_8
  int v308; // eax
  signed int ret; // eax
  int v310; // eax
  double ArgList; // [esp+Ch] [ebp-2740h]
  LVITEMW ItemState; // [esp+2Ch] [ebp-2720h]
  LVITEMW item; // [esp+60h] [ebp-26ECh]
  int v315; // [esp+94h] [ebp-26B8h]
  double v316; // [esp+98h] [ebp-26B4h]
  LVFINDINFOW FindInfo; // [esp+A0h] [ebp-26ACh]
  __int64 dwUnavailPhys; // [esp+B8h] [ebp-2694h]
  double v319; // [esp+C0h] [ebp-268Ch]
  __int64 v320; // [esp+C8h] [ebp-2684h]
  __int64 v321; // [esp+D0h] [ebp-267Ch]
  int bVirtualizationEnabled; // [esp+DCh] [ebp-2670h]
  int fbUIAccess; // [esp+E0h] [ebp-266Ch]
  unsigned int v324; // [esp+E4h] [ebp-2668h]
  __int64 v325; // [esp+E8h] [ebp-2664h]
  __m128i v326; // [esp+F0h] [ebp-265Ch]
  double v327; // [esp+F8h] [ebp-2654h]
  __m128i v328; // [esp+100h] [ebp-264Ch]
  __int64 v329; // [esp+108h] [ebp-2644h]
  int cbPackageFullNameLength; // [esp+110h] [ebp-263Ch]
  int v331; // [esp+114h] [ebp-2638h]
  tagTREEVIEWLISTITEMPARAM *OutBuffer; // [esp+118h] [ebp-2634h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_327; // [esp+11Ch] [ebp-2630h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_328; // [esp+120h] [ebp-262Ch]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_329; // [esp+124h] [ebp-2628h]
  __int64 v336; // [esp+128h] [ebp-2624h]
  float v337; // [esp+134h] [ebp-2618h]
  double v338; // [esp+138h] [ebp-2614h]
  unsigned int v339; // [esp+140h] [ebp-260Ch]
  unsigned int v340; // [esp+144h] [ebp-2608h]
  LVITEMW Item; // [esp+148h] [ebp-2604h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_336; // [esp+17Ch] [ebp-25D0h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_337; // [esp+180h] [ebp-25CCh]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_338; // [esp+184h] [ebp-25C8h]
  __int64 v345; // [esp+188h] [ebp-25C4h]
  __int64 v346; // [esp+190h] [ebp-25BCh]
  HWND hWndListCtrl_1; // [esp+198h] [ebp-25B4h]
  unsigned int v348; // [esp+19Ch] [ebp-25B0h]
  int v349; // [esp+1A0h] [ebp-25ACh]
  unsigned int v350; // [esp+1A4h] [ebp-25A8h]
  double dbMemorySize; // [esp+1A8h] [ebp-25A4h]
  char bFlagsInExtendedProcessBasicInfo; // [esp+1B7h] [ebp-2595h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_347; // [esp+1B8h] [ebp-2594h]
  ULONG *v354; // [esp+1BCh] [ebp-2590h]
  signed __int64 v355; // [esp+1C0h] [ebp-258Ch]
  unsigned int v356; // [esp+1C8h] [ebp-2584h]
  char sbQueryServiceNamesInited; // [esp+1CFh] [ebp-257Dh]
  __m128i v358; // [esp+1D0h] [ebp-257Ch]
  double v359; // [esp+1D8h] [ebp-2574h]
  LARGE_INTEGER liParam; // [esp+1E8h] [ebp-2564h]
  unsigned int v361; // [esp+1F4h] [ebp-2558h]
  tagTREEVIEWLISTITEMPARAM *pItemFound; // [esp+1F8h] [ebp-2554h]
  unsigned int v363; // [esp+1FCh] [ebp-2550h]
  unsigned int v364; // [esp+200h] [ebp-254Ch]
  unsigned int variable_360; // [esp+204h] [ebp-2548h]
  wchar_t *packageFullName; // [esp+208h] [ebp-2544h]
  int v367; // [esp+20Ch] [ebp-2540h]
  unsigned int v368; // [esp+210h] [ebp-253Ch]
  unsigned int v369; // [esp+214h] [ebp-2538h]
  unsigned __int8 v370; // [esp+21Bh] [ebp-2531h]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // [esp+21Ch] [ebp-2530h]
  char v372; // [esp+223h] [ebp-2529h]
  tagTREEVIEWLISTITEMPARAM *ProcessHandle; // [esp+224h] [ebp-2528h]
  int v374; // [esp+228h] [ebp-2524h]
  unsigned __int8 fHungFlags; // [esp+22Fh] [ebp-251Dh]
  SHFILEINFOW FileInfo; // [esp+230h] [ebp-251Ch]
  tagTREEVIEWLISTITEMPARAM ItemParam; // [esp+4E8h] [ebp-2264h]
  tagItemWithSizeIs50H ItemWithSizeIs50H; // [esp+AA8h] [ebp-1CA4h]
  WCHAR szFullName[1024]; // [esp+AF8h] [ebp-1C54h]
  WCHAR szBuffer[1024]; // [esp+12F8h] [ebp-1454h]
  WCHAR szText[256]; // [esp+1AF8h] [ebp-C54h]
  WCHAR szDomainName[256]; // [esp+1CF8h] [ebp-A54h]
  WCHAR szUserName[256]; // [esp+1EF8h] [ebp-854h]
  WCHAR szText3[256]; // [esp+20F8h] [ebp-654h]
  WCHAR szText4[256]; // [esp+22F8h] [ebp-454h]
  WCHAR szText5[256]; // [esp+24F8h] [ebp-254h]
  WCHAR Buffer_382[34]; // [esp+26F8h] [ebp-54h]
  unsigned int v388; // [esp+273Ch] [ebp-10h]
  int v389; // [esp+2740h] [ebp-Ch]
  int v390; // [esp+2744h] [ebp-8h]
  int v391; // [esp+2748h] [ebp-4h]
  int retaddr; // [esp+274Ch] [ebp+0h]

  v389 = v2;
  v390 = retaddr;
  v10 = alloca(10008);
  v388 = (unsigned int)&v389 ^ __security_cookie;
  hWndListCtrl_1 = hWndListCtrl;
  fHungFlags = 0;
  v349 = 0;
  TreeViewListItemParam_327 = 0;
  szText3[0] = 0;
  TreeViewListItemParam_337 = 0;
  v338 = 0.0;
  dbMemorySize = 0.0;
  *(double *)&v345 = 0.0;
  TreeViewListItemParam_338 = 0;
  v319 = 0.0;
  v336 = 0i64;
  v329 = 0i64;
  v320 = 0i64;
  v346 = 0i64;
  liParam.QuadPart = 0i64;
  memset(&szText3[1], 0, 510u);
  v370 = 0;
  TreeViewListItemParam_336 = 0;
  v372 = 0;
  bVirtualizationEnabled = 0;
  fbUIAccess = 0;
  sbQueryServiceNamesInited = 0;
  v321 = 0i64;
  v359 = 0.0;
  PE_FlushTrace(&gProperties);
  TreeList_Item1::Reset(gTreeList_Item);
  TreeList_Item1::Reset(&gTreeList_Item[1]);
  TreeList_Item1::Reset(&gTreeList_Item[2]);
  v11 = 0;
  if ( gbShowProcessTreeLast != (unsigned __int8)gConfig.bShowProcessTree )
    v11 = 1;
  gbShowProcessTreeLast = (unsigned __int8)gConfig.bShowProcessTree;
  v374 = v11;
  szBuffer[0] = 0;
  memset(&ItemWithSizeIs50H, 0, 0x50u);
  pSystemProcessInfoLast = gpSystemProcessInfoLast;
  nSystemProcessInfoLengthLast = gnSystemProcessInfoLengthLast;
  Tree_node_8 = theSystemProcessInfoMap._Header;
  v15 = theSystemProcessInfoMap._Size;
  gpSystemProcessInfoLast = gpSystemProcessInfo;
  gnSystemProcessInfoLengthLast = gnSystemProcessInfoLength;
  gTimeQuerySystemInfoLast = gTimeQuerySystemInfo;
  gpSystemProcessInfo = pSystemProcessInfoLast;
  gnSystemProcessInfoLength = nSystemProcessInfoLengthLast;
  TimeRet = RequerySystemStatus(
              &gpSystemProcessInfo,
              &gnSystemProcessInfoLength,
              gpSystemPerformanceInfo,
              gpSystemInterruptInfo,
              gpSystemProcessorCycleTimeInfo,
              &theSystemProcessInfoMap,
              (int)&v359);
  gTimeQuerySystemInfo.dwLowDateTime = TimeRet.dwLowDateTime;
  gTimeQuerySystemInfo.dwHighDateTime = TimeRet.dwHighDateTime;
  v18 = (unsigned __int64)(*(_QWORD *)&TimeRet - *(_QWORD *)&gTimeQuerySystemInfoLast) >> 32;
  pSystemProcessInfo_11 = (SYSTEM_PROCESS_INFORMATION *)(TimeRet.dwLowDateTime - gTimeQuerySystemInfoLast.dwLowDateTime);
  pSystemProcessInfo_1 = pSystemProcessInfo_11;
  v348 = LODWORD(v359) + (char *)theSystemProcessInfoMap._Header - (char *)Tree_node_8;
  dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
  v369 = v18;
  v350 = (*(_QWORD *)&v359 + *(_QWORD *)&theSystemProcessInfoMap
                           - __PAIR__((unsigned int)v15, (unsigned int)Tree_node_8)) >> 32;
  if ( gSystemInfo.dwNumberOfProcessors <= 1 || (nProcessorIndex = 0, (signed int)gSystemInfo.dwNumberOfProcessors <= 0) )
  {
    v359 = v316;
  }
  else
  {
    nIndex = 0;
    do
    {
      v22 = gpSystemPerformanceInfo[nIndex].IdleTime.LowPart;
      v368 = gpSystemPerformanceInfo[nIndex].KernelTime.LowPart;
      v361 = gpSystemPerformanceInfo[nIndex].KernelTime.HighPart;
      v23 = gpSystemPerformanceInfo[nIndex].UserTime.LowPart;
      v173 = v23 < v22;
      v364 = v23 - v22;
      v363 = gpSystemPerformanceInfo[nIndex].UserTime.HighPart;
      v24 = gpSystemPerformanceInfo[nIndex].IdleTime.HighPart;
      v363 -= v173 + v24;
      v173 = __CFADD__(v368, v364);
      v364 += v368;
      v363 += v361 + v173;
      v25 = __PAIR__(v361, v368) - __PAIR__(v24, v22);
      v361 = (__PAIR__(v361, v368) - __PAIR__(v24, v22)) >> 32;
      v368 = v25;
      if ( v369 | (unsigned int)pSystemProcessInfo_1 )
      {
        v26 = (double)(signed __int64)(__PAIR__(v363, v364) - *(_QWORD *)&gppGraphInfo[nProcessorIndex]->field_888);
        v359 = v26 * 100.0;
        v27 = (double)(signed __int64)__PAIR__(v369, (unsigned int)pSystemProcessInfo_1);
        v28 = v359 / v27;
      }
      else
      {
        v28 = 0.0;
      }
      v29 = v28;
      v30 = gppGraphInfo[nProcessorIndex];
      v30->field_888 = v364;
      v30->field_88C = v363;
      v359 = v29;
      if ( v369 | (unsigned int)pSystemProcessInfo_1 )
      {
        v31 = (double)(signed __int64)(__PAIR__(v361, v368) - *(_QWORD *)&gppGraphInfo[nProcessorIndex]->field_890);
        v327 = v31 * 100.0;
        v32 = (double)(signed __int64)__PAIR__(v369, (unsigned int)pSystemProcessInfo_1);
        v33 = v327 / v32;
      }
      else
      {
        v33 = 0.0;
      }
      v34 = v33;
      v35 = gppGraphInfo[nProcessorIndex];
      v35->field_890 = v368;
      v35->field_894 = v361;
      CGraphData_Update(gppGraphInfo[nProcessorIndex], gTimeQuerySystemInfo, v359, v34, 0);
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
      ++nProcessorIndex;
      ++nIndex;
    }
    while ( nProcessorIndex < (signed int)gSystemInfo.dwNumberOfProcessors );
    pSystemProcessInfo_11 = pSystemProcessInfo_1;
    v18 = v369;
  }
  v36 = dwNumberOfProcessors * __PAIR__(v18, (unsigned int)pSystemProcessInfo_11);
  gTreeViewListItemParam = gpTreeViewListItemParam;
  variable_360 = v36;
  v363 = HIDWORD(v329);
  v369 = HIDWORD(v36);
  TreeViewListItemParam_347 = gpTreeViewListItemParam;
  v337 = 0.0;
  v361 = v329;
  if ( gpTreeViewListItemParam )
  {
    while ( 1 )
    {
      if ( gTreeViewListItemParam->InheritedFromUniqueProcessId != -1 || !gTreeViewListItemParam->dwProcessId )
        gTreeViewListItemParam->m_CPUUsage = 0i64;
      v294 = gTreeViewListItemParam->dwProcessId == -10;
      TreeViewListItemParam_32 = gTreeViewListItemParam->m_Prev;
      v339 = (unsigned int)gTreeViewListItemParam->m_Prev;
      if ( v294 )
        break;
      v120 = gTreeViewListItemParam->dwStyle;
      if ( (!(v120 & 2) || v120 & 1 && gConfig.byte_14012ADFE) && gTreeViewListItemParam->field_2C != -1 )
      {
        sub_C28570(ghWndTreeListView, gTreeViewListItemParam);
        Item.lParam = gTreeViewListItemParam;
        Item.iItem = -1;
        sub_C658D0((signed int)&v391, hWndListCtrl_1, &Item, (LPARAM)gTreeViewListItemParam, (int)&fHungFlags);
        LOBYTE(v374) = 1;
      }
      else
      {
        Item.lParam = gTreeViewListItemParam;
        Item.iItem = -1;
        v121 = sub_C658D0((signed int)&v391, hWndListCtrl_1, &Item, (LPARAM)gTreeViewListItemParam, (int)&fHungFlags);
        v122 = v374;
        if ( v121 )
          v122 = 1;
        LOBYTE(v374) = v122;
      }
      if ( !fHungFlags )
        goto LABEL_98;
      v119 = v349;
LABEL_97:
      v349 = v119 + 1;
      gTreeViewListItemParam->m_SelectedItem = (int)TreeViewListItemParam_337;
      TreeViewListItemParam_337 = gTreeViewListItemParam;
LABEL_98:
      TreeViewListItemParam_347 = TreeViewListItemParam_32;
      gTreeViewListItemParam = TreeViewListItemParam_32;
      if ( !TreeViewListItemParam_32 )
        goto LABEL_99;
    }
    v370 = 1;
    FindInfo.flags = 1;
    FindInfo.lParam = (LPARAM)gTreeViewListItemParam;
    Item.mask = ::SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&FindInfo);
    if ( Item.iItem == -1 )
    {
      v39 = gTreeViewListItemParam->dwStyle;
      if ( v39 & 2 )
      {
        if ( !(v39 & 1) || !gConfig.byte_14012ADFE )
          sub_C27F20(ghWndTreeListView, gTreeViewListItemParam);
      }
    }
    dwProcessorIdx = 0;
    Item.lParam = gTreeViewListItemParam;
    v329 = 0i64;
    v327 = 0.0;
    v325 = 0i64;
    v359 = 0.0;
    if ( (signed int)gSystemInfo.dwNumberOfProcessors <= 0 )
    {
      v70 = HIDWORD(v325);
      ProcessHandle = (tagTREEVIEWLISTITEMPARAM *)LODWORD(v359);
      v355 = __PAIR__(HIDWORD(v359), HIDWORD(v329));
      v368 = v329;
      pItemFound = (tagTREEVIEWLISTITEMPARAM *)HIDWORD(v327);
      v356 = LODWORD(v327);
      pSystemProcessInfo_72 = (SYSTEM_PROCESS_INFORMATION *)v325;
      pSystemProcessInfo_1 = (SYSTEM_PROCESS_INFORMATION *)v325;
    }
    else
    {
      if ( gSystemInfo.dwNumberOfProcessors < 4 )
      {
        v70 = HIDWORD(v325);
        ProcessHandle = (tagTREEVIEWLISTITEMPARAM *)LODWORD(v359);
        v355 = __PAIR__(HIDWORD(v359), HIDWORD(v329));
        v368 = v329;
        pItemFound = (tagTREEVIEWLISTITEMPARAM *)HIDWORD(v327);
        v356 = LODWORD(v327);
        pSystemProcessInfo_1 = (SYSTEM_PROCESS_INFORMATION *)v325;
      }
      else
      {
        v41 = 0i64;
        v367 = gSystemInfo.dwNumberOfProcessors - (signed int)gSystemInfo.dwNumberOfProcessors % 4;
        gpSystemInterruptInf = gpSystemInterruptInfo;
        pSystemProcessorIdleCycleTimeInfo_37 = gpSystemProcessorCycleTimeInfo + 2;
        v44 = &gpSystemPerformanceInfo->DpcTime;
        _mm_store_si128(&v326, (__m128i)0i64);
        v45 = 0i64;
        _mm_store_si128(&v328, (__m128i)0i64);
        v46 = 0i64;
        _mm_store_si128(&v358, (__m128i)0i64);
        v47 = 0i64;
        v48 = 0i64;
        v49 = (int)&gpSystemInterruptInf[1].DpcCount;
        do
        {
          v50 = _mm_cvtsi32_si128(v44[8].LowPart);
          pSystemProcessorIdleCycleTimeInfo_37 += 4;
          v51 = _mm_cvtsi32_si128(v44[2].LowPart);
          v49 += 96;
          v44 += 24;
          dwProcessorIdx += 4;
          *(LARGE_INTEGER *)v52.m128i_i8 = v44[-23];
          v52.m128i_i64[1] = v44[-17].QuadPart;
          v53 = _mm_unpacklo_epi32(
                  _mm_add_epi32(
                    _mm_unpacklo_epi32(v51, v50),
                    _mm_unpacklo_epi32(
                      _mm_cvtsi32_si128(*(_DWORD *)(v49 - 120)),
                      _mm_cvtsi32_si128(*(_DWORD *)(v49 - 96)))),
                  (__m128i)0i64);
          *(LARGE_INTEGER *)v50.m128i_i8 = v44[-24];
          v50.m128i_i64[1] = v44[-18].QuadPart;
          v54 = _mm_add_epi64(v52, v50);
          v55 = _mm_add_epi64(v53, v358);
          v56 = v54;
          v57 = _mm_add_epi64(v54, v328);
          _mm_store_si128(&v326, _mm_add_epi64(v56, v326));
          *(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *)v56.m128i_i8 = pSystemProcessorIdleCycleTimeInfo_37[-6];
          v56.m128i_i64[1] = pSystemProcessorIdleCycleTimeInfo_37[-5].CycleTime;
          v41 = _mm_add_epi64(v41, v56);
          v58 = _mm_cvtsi32_si128(v44[-4].LowPart);
          _mm_store_si128(&v358, v55);
          v59 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v44[-10].LowPart), v58);
          v60 = _mm_cvtsi32_si128(*(_DWORD *)(v49 - 48));
          _mm_store_si128(&v328, v57);
          *(LARGE_INTEGER *)v57.m128i_i8 = v44[-11];
          v57.m128i_i64[1] = v44[-5].QuadPart;
          v48 = _mm_add_epi64(
                  v48,
                  _mm_unpacklo_epi32(
                    _mm_add_epi32(v59, _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v49 - 72)), v60)),
                    (__m128i)0i64));
          *(LARGE_INTEGER *)v60.m128i_i8 = v44[-12];
          v60.m128i_i64[1] = v44[-6].QuadPart;
          v61 = _mm_add_epi64(v57, v60);
          *(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *)v60.m128i_i8 = pSystemProcessorIdleCycleTimeInfo_37[-4];
          v46 = _mm_add_epi64(v46, v61);
          v60.m128i_i64[1] = pSystemProcessorIdleCycleTimeInfo_37[-3].CycleTime;
          v47 = _mm_add_epi64(v47, v61);
          v45 = _mm_add_epi64(v45, v60);
        }
        while ( dwProcessorIdx < v367 );
        v62 = _mm_add_epi64(v48, v358);
        v63 = _mm_add_epi64(v45, v41);
        v64 = _mm_add_epi64(v47, v328);
        v65 = _mm_add_epi64(v46, v326);
        v66 = _mm_add_epi64(v62, _mm_srli_si128(v62, 8));
        v67 = _mm_add_epi64(v64, _mm_srli_si128(v64, 8));
        pSystemProcessInfo_1 = (SYSTEM_PROCESS_INFORMATION *)_mm_cvtsi128_si32(v66);
        v356 = _mm_cvtsi128_si32(v67);
        v68 = _mm_add_epi64(v65, _mm_srli_si128(v65, 8));
        v368 = _mm_cvtsi128_si32(v68);
        v69 = _mm_add_epi64(v63, _mm_srli_si128(v63, 8));
        ProcessHandle = (tagTREEVIEWLISTITEMPARAM *)_mm_cvtsi128_si32(v69);
        v70 = _mm_cvtsi128_si32(_mm_srli_si128(v66, 4));
        pItemFound = (tagTREEVIEWLISTITEMPARAM *)_mm_cvtsi128_si32(_mm_srli_si128(v67, 4));
        v355 = __PAIR__(_mm_cvtsi128_si32(_mm_srli_si128(v69, 4)), _mm_cvtsi128_si32(_mm_srli_si128(v68, 4)));
      }
      v364 = v70;
      if ( dwProcessorIdx < (signed int)gSystemInfo.dwNumberOfProcessors )
      {
        v71 = v364;
        v72 = &gpSystemPerformanceInfo[dwProcessorIdx].InterruptTime;
        v354 = &gpSystemInterruptInfo[dwProcessorIdx].DpcCount;
        do
        {
          v73 = (__int64)(SYSTEM_PROCESS_INFORMATION *)((char *)pSystemProcessInfo_1
                                                      + __PAIR__(v71, *v354 + v72[1].LowPart));
          v71 = (_DWORD)((_DWORD)pSystemProcessInfo_1 + __PAIR__(v71, *v354 + v72[1].LowPart)) >> 32;
          pSystemProcessInfo_1 = (SYSTEM_PROCESS_INFORMATION *)v73;
          v74 = *(_QWORD *)v72 + v72[-1].QuadPart;
          v72 += 6;
          v75 = v74 + __PAIR__(v355, v368);
          LODWORD(v355) = (v74 + __PAIR__((unsigned int)v355, v368)) >> 32;
          v368 = v75;
          v76 = v74 + __PAIR__((unsigned int)pItemFound, v356);
          pItemFound = (tagTREEVIEWLISTITEMPARAM *)(v76 >> 32);
          v356 = v76;
          v77 = (gpSystemProcessorCycleTimeInfo[dwProcessorIdx].CycleTime
               + __PAIR__(HIDWORD(v355), (unsigned int)ProcessHandle)) >> 32;
          ProcessHandle = (tagTREEVIEWLISTITEMPARAM *)((char *)ProcessHandle
                                                     + LODWORD(gpSystemProcessorCycleTimeInfo[dwProcessorIdx++].CycleTime));
          v354 += 6;
          HIDWORD(v355) = v77;
        }
        while ( dwProcessorIdx < (signed int)gSystemInfo.dwNumberOfProcessors );
        v364 = v71;
        gTreeViewListItemParam = TreeViewListItemParam_347;
        v70 = v364;
      }
      pSystemProcessInfo_72 = pSystemProcessInfo_1;
    }
    v81 = __OFSUB__(
            v70,
            ((unsigned int)pSystemProcessInfo_72 < LODWORD(gTreeViewListItemParam->ContextSwtiches))
          + HIDWORD(gTreeViewListItemParam->ContextSwtiches));
    v80 = (__PAIR__((unsigned int)v70, (unsigned int)pSystemProcessInfo_72) - gTreeViewListItemParam->ContextSwtiches) >> 32;
    v79 = (int)pSystemProcessInfo_72 - LODWORD(gTreeViewListItemParam->ContextSwtiches);
    if ( v80 < 0 || (unsigned __int8)((v80 < 0) ^ v81) | (v80 == 0) && !v79 )
    {
      v359 = 0.0;
      v80 = 0;
      v79 = 0;
    }
    v82 = v79 != LODWORD(gTreeViewListItemParam->ContextSwtichDelta)
       || v80 != HIDWORD(gTreeViewListItemParam->ContextSwtichDelta);
    LODWORD(gTreeViewListItemParam->ContextSwtichDelta) = v79;
    HIDWORD(gTreeViewListItemParam->ContextSwtichDelta) = v80;
    v83 = RedrawColumn(v82, ghWndTreeListView, 1092, Item.iItem);
    LOBYTE(v374) = v83 | v374;
    v84 = pSystemProcessInfo_1 != (SYSTEM_PROCESS_INFORMATION *)LODWORD(gTreeViewListItemParam->ContextSwtiches)
       || v70 != HIDWORD(gTreeViewListItemParam->ContextSwtiches);
    LODWORD(gTreeViewListItemParam->ContextSwtiches) = pSystemProcessInfo_1;
    HIDWORD(gTreeViewListItemParam->ContextSwtiches) = v70;
    v85 = RedrawColumn(v84, ghWndTreeListView, 1091, Item.iItem);
    LOBYTE(v374) = v85 | v374;
    v86 = HIDWORD(v355);
    v87 = __PAIR__(HIDWORD(v355), (unsigned int)ProcessHandle) - gTreeViewListItemParam->Cycles != gTreeViewListItemParam->CyclesDelta;
    gTreeViewListItemParam->CyclesDelta = __PAIR__(HIDWORD(v355), (unsigned int)ProcessHandle)
                                        - gTreeViewListItemParam->Cycles;
    v88 = RedrawColumn(v87, ghWndTreeListView, 1200, Item.iItem);
    LOBYTE(v374) = v88 | v374;
    v89 = ProcessHandle != (tagTREEVIEWLISTITEMPARAM *)LODWORD(gTreeViewListItemParam->Cycles)
       || v86 != HIDWORD(gTreeViewListItemParam->Cycles);
    LODWORD(gTreeViewListItemParam->Cycles) = ProcessHandle;
    HIDWORD(gTreeViewListItemParam->Cycles) = v86;
    v90 = RedrawColumn(v89, ghWndTreeListView, 1195, Item.iItem);
    LOBYTE(v374) = v90 | v374;
    v91 = v355;
    if ( GetProcessorSystemCycleTime )
    {
      if ( v350 | v348 )
      {
        v92 = (double)gTreeViewListItemParam->CyclesDelta;
        *(float *)&v367 = v92 * 100.0;
        v93 = (double)(signed __int64)__PAIR__(v350, v348);
        v94 = *(float *)&v367 / v93;
LABEL_59:
        v359 = v94;
        if ( v94 > 100.0 )
          v359 = db_onehundred;
        TreeViewListItemParam_92 = pItemFound;
        v97 = (__PAIR__((unsigned int)pItemFound, v356) - *(_QWORD *)&gTreeViewListItemParam->KernelTime) >> 32;
        v367 = v356 - gTreeViewListItemParam->KernelTime.dwLowDateTime;
        v173 = __CFADD__(v356, v361);
        v361 += v356;
        gTreeViewListItemParam->KernelTime.dwLowDateTime = v356;
        v363 += (unsigned int)TreeViewListItemParam_92 + v173;
        v99 = v369 | variable_360;
        gTreeViewListItemParam->KernelTime.dwHighDateTime = (DWORD)TreeViewListItemParam_92;
        if ( v99 )
        {
          v100 = (double)(signed __int64)__PAIR__(v97, v367);
          *(float *)&v367 = v100 * 100.0;
          v101 = (double)(signed __int64)__PAIR__(v369, variable_360);
          v102 = *(float *)&v367 / v101;
        }
        else
        {
          v102 = 0.0;
        }
        CGraphData_Update(gTreeViewListItemParam->pGraphData1, gTimeQuerySystemInfo, v359, v102, 0);
        CGraphData_Update(gTreeViewListItemParam->pGraphData2, gTimeQuerySystemInfo, v103, COERCE_DOUBLE(0i64 >> 63), 0);
        v104 = gTreeViewListItemParam->pGraphDataPROCCPU;
        if ( v104 )
          CGraphData_Update(v104, gTimeQuerySystemInfo, ArgList, COERCE_DOUBLE(0i64 >> 63), 0);
        if ( gTreeViewListItemParam->dwStyle & 0x40 )
          dbMemorySize = v359 + dbMemorySize;
        if ( gTreeViewListItemParam->dwProcessId )
          v338 = v359 + v338;
        if ( v359 > *(double *)&v345 )
        {
          *(double *)&v345 = v359;
          TreeViewListItemParam_338 = gTreeViewListItemParam;
        }
        v105 = v368 != LODWORD(gTreeViewListItemParam->m_CPUTime) || v91 != HIDWORD(gTreeViewListItemParam->m_CPUTime);
        LODWORD(gTreeViewListItemParam->m_CPUTime) = v368;
        HIDWORD(gTreeViewListItemParam->m_CPUTime) = v91;
        v106 = RedrawColumn(v105, ghWndTreeListView, 1087, Item.iItem);
        LOBYTE(v374) = v106 | v374;
        Item.lParam->field_10 = 0;
        v107 = RedrawColumn(1, ghWndTreeListView, 1191, Item.iItem);
        v108 = (unsigned __int8)v374;
        if ( v107 )
          v108 = 1;
        v367 = v108;
        v109 = RedrawColumn(1, ghWndTreeListView, 1193, Item.iItem);
        v110 = (unsigned __int8)v367;
        if ( v109 )
          v110 = 1;
        v367 = v110;
        v111 = RedrawColumn(1, ghWndTreeListView, 1330, Item.iItem);
        v112 = v367;
        if ( v111 )
          v112 = 1;
        v294 = v359 == *(double *)&gTreeViewListItemParam->m_CPU;
        LOBYTE(v374) = v112;
        *(double *)&gTreeViewListItemParam->m_CPU = v359;
        RedrawColumn(v294 == 0, ghWndTreeListView, 1055, Item.iItem);
        *(double *)&gTreeViewListItemParam->m_CPUUsage = v359 + *(double *)&gTreeViewListItemParam->m_CPUUsage;
        v113 = RedrawColumn(1, ghWndTreeListView, 1637, Item.iItem);
        LOBYTE(v374) = v113 | v374;
        v367 = (int)&gTreeViewListItemParam->pItemParam;
        TreeViewListItemParam_108 = gTreeViewListItemParam->pItemParam;
        if ( TreeViewListItemParam_108 )
        {
          v115 = v367;
          TreeViewListItemParam_110 = (tagTREEVIEWLISTITEMPARAM **)v367;
          do
          {
            *(double *)&TreeViewListItemParam_108->m_CPUUsage = v359;
            v117 = RedrawColumn(1, ghWndTreeListView, 1637, *(_DWORD *)(*(_DWORD *)v115 + 44));
            TreeViewListItemParam_112 = *TreeViewListItemParam_110;
            LOBYTE(v374) = v117 | v374;
            TreeViewListItemParam_110 = &TreeViewListItemParam_112->pItemParam;
            TreeViewListItemParam_108 = *TreeViewListItemParam_110;
          }
          while ( *TreeViewListItemParam_110 );
          gTreeViewListItemParam = TreeViewListItemParam_347;
        }
        TreeViewListItemParam_32 = (tagTREEVIEWLISTITEMPARAM *)v339;
        v119 = v349 - 1;
        --Item.iItem;
        fHungFlags = 1;
        goto LABEL_97;
      }
    }
    else if ( v369 | variable_360 )
    {
      v95 = (double)(__PAIR__(v355, v368) - gTreeViewListItemParam->m_CPUTime);
      *(float *)&v367 = v95 * 100.0;
      v96 = (double)(signed __int64)__PAIR__(v369, variable_360);
      v94 = *(float *)&v367 / v96;
      goto LABEL_59;
    }
    v94 = 0.0;
    goto LABEL_59;
  }
LABEL_99:
  v123 = HIDWORD(v336);
  pSystemProcessInfo_118 = gpSystemProcessInfo;
  v324 = v336;
  v367 = HIDWORD(v320);
  v339 = v320;
  v356 = HIDWORD(v346);
  v355 = __PAIR__(liParam.HighPart, (unsigned int)v346);
  v368 = liParam.LowPart;
  v364 = HIDWORD(v321);
  v331 = HIDWORD(v336);
  v354 = (ULONG *)v321;
  while ( 1 )
  {
    ++ItemWithSizeIs50H.nRefCount;
    ItemWithSizeIs50H.NumberOfThreads += pSystemProcessInfo_118->NumberOfThreads;
    ItemWithSizeIs50H.HandleCount += pSystemProcessInfo_118->HandleCount;
    UniqueProcessId = (DWORD)pSystemProcessInfo_118->UniqueProcessId;
    pSystemProcessInfo_1 = pSystemProcessInfo_118;
    packageFullName = (wchar_t *)UniqueProcessId;
    if ( UniqueProcessId )
    {
      v126 = pSystemProcessInfo_118->KernelTime.LowPart;
      v127 = pSystemProcessInfo_118->KernelTime.HighPart;
      v128 = __PAIR__(v127, v126) + pSystemProcessInfo_1->UserTime.QuadPart + __PAIR__(v123, v324);
      v324 += v126 + pSystemProcessInfo_1->UserTime.LowPart;
      v173 = __CFADD__(v126, v361);
      v361 += v126;
      UniqueProcessId = (DWORD)packageFullName;
      v363 += v127 + v173;
      pSystemProcessInfo_118 = pSystemProcessInfo_1;
      v331 = HIDWORD(v128);
    }
    gTreeViewListItemParam_123 = gpTreeViewListItemParam;
    TreeViewListItemParam_328 = gpTreeViewListItemParam;
    if ( !gpTreeViewListItemParam )
    {
LABEL_108:
      HIDWORD(v346) = UniqueProcessId;
      ProcessHandle = (tagTREEVIEWLISTITEMPARAM *)OpenProcess(0x410u, 0, UniqueProcessId);
      OutBuffer = ProcessHandle;
      if ( !ProcessHandle )
      {
        if ( GetLastError() == ERROR_ACCESS_DENIED )
          DeviceIoControl(
            ghDriverHandle,
            CTRLCODE_QUERY_PROCESS_HANDLE,
            (char *)&v346 + 4,
            4u,
            &OutBuffer,
            4u,
            (LPDWORD)&v327 + 1,
            0);
        ProcessHandle = OutBuffer;
        if ( !OutBuffer )
        {
          HIDWORD(v336) = pSystemProcessInfo_118->UniqueProcessId;
          ProcessHandle = (tagTREEVIEWLISTITEMPARAM *)OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, 0, HIDWORD(v336));
          TreeViewListItemParam_329 = ProcessHandle;
          if ( !ProcessHandle )
          {
            if ( GetLastError() == ERROR_ACCESS_DENIED )
              DeviceIoControl(
                ghDriverHandle,
                CTRLCODE_QUERY_PROCESS_HANDLE,
                (char *)&v336 + 4,
                4u,
                &TreeViewListItemParam_329,
                4u,
                (LPDWORD)&v329 + 1,
                0);
            ProcessHandle = TreeViewListItemParam_329;
          }
        }
      }
      memset(&ItemParam, 0, sizeof(tagTREEVIEWLISTITEMPARAM));
      ItemParam.dwProcessId = (int)pSystemProcessInfo_118->UniqueProcessId;
      if ( pSystemProcessInfo_118->ImageName.Length )
        wcsncpy_s(
          szText,
          256u,
          pSystemProcessInfo_118->ImageName.Buffer,
          (unsigned int)pSystemProcessInfo_118->ImageName.Length >> 1);
      else
        wcscpy_s(szText, 256u, L"System Idle Process");
      QueryProcessUsers(
        ProcessHandle,
        (DWORD)pSystemProcessInfo_118->UniqueProcessId,
        (int)&pSystemProcessInfo_118->CreateTime,
        szUserName,
        256u,
        szDomainName,
        256u,
        szText3,
        256u,
        &bVirtualizationEnabled,
        &fbUIAccess);
      if ( !szDomainName[0] || (pszText = (const WCHAR **)L"\\", !szUserName[0]) )
        pszText = &gszNullString;
      wsprintfW(szFullName, L"%s%s%s", szDomainName, pszText, szUserName);
      ItemParam.pszFullUserName = (int)_wcsdup(szText3);
      dwStyle = ItemParam.dwStyle;
      if ( bVirtualizationEnabled )
      {
        dwStyle = ItemParam.dwStyle | TVLS_VirtualizationEnabled;
        ItemParam.dwStyle |= TVLS_VirtualizationEnabled;
      }
      if ( fbUIAccess )
        ItemParam.dwStyle = dwStyle | TVLS_UIAccess;
      NtQueryInformationProcess(
        ProcessHandle,
        ProcessProtectionInformation,
        &ItemParam.bProcessProtectionInfo,
        1u,
        (PULONG)&v315);
      if ( IsImmersiveProcess && IsImmersiveProcess(ProcessHandle) )
      {
        if ( GetPackageFullName )
        {
          cbPackageFullNameLength = 0;
          if ( GetPackageFullName(ProcessHandle, (UINT32 *)&cbPackageFullNameLength, 0) == ERROR_INSUFFICIENT_BUFFER )
          {
            packageFullName = (wchar_t *)malloc(2 * cbPackageFullNameLength);
            if ( !GetPackageFullName(ProcessHandle, (UINT32 *)&cbPackageFullNameLength, packageFullName) )
              ItemParam.pszPackageFullName = (int)_wcsdup(packageFullName);
            free(packageFullName);
          }
        }
        ItemParam.dwStyle |= TVLS_ProcessIsImmersive;
      }
      ItemParam.m_ProcessMemoryPriority = -1;
      ItemParam.m_ProcessIoPriority = -1;
      TreeViewListItemParam_GetSystemInfo(
        pSystemProcessInfo_118,
        ProcessHandle,
        variable_360,
        v369,
        gTimeQuerySystemInfo.dwLowDateTime,
        gTimeQuerySystemInfo.dwHighDateTime,
        &ItemParam,
        0xFFFFFFFF);
      InheritedFromUniqueProcessId = (DWORD)pSystemProcessInfo_118->InheritedFromUniqueProcessId;
      if ( InheritedFromUniqueProcessId )
      {
        SystemProcessInfo_GetSystemProcessName(
          InheritedFromUniqueProcessId,
          &pSystemProcessInfo_118->CreateTime,
          szText4,
          0x100u);
        wsprintf_s(Buffer_382, L"(%d)", pSystemProcessInfo_118->InheritedFromUniqueProcessId);
        wcscat_s(szText4, 0x100u, Buffer_382);
      }
      else
      {
        wsprintf(szText4, L"<None>");
      }
      QueryProcessArguments(
        ProcessHandle,
        (ULONG_PTR)pSystemProcessInfo_118->UniqueProcessId,
        (WCHAR **)&ItemParam.pszCommandLine,
        (WCHAR **)&ItemParam.pszCurrentDirectory,
        (WCHAR **)&ItemParam.pszEnvBlock,
        (PDWORD)&bFlagsInExtendedProcessBasicInfo);
      if ( bFlagsInExtendedProcessBasicInfo )
        ItemParam.dwStyle |= TVLS_SupportExtendedProcessBasicInfo;
      liParam.HighPart = (LONG)pSystemProcessInfo_118->UniqueProcessId;
      wcscpy_s(szText5, 0x100u, (const wchar_t *)&gszNullString);
      ghMainWndBackup = 0;
      if ( liParam.HighPart == GetCurrentProcessId() )
      {
        ghMainWndBackup = ghMainWnd;
        GetWindowTextW(ghMainWnd, gpszWindowText, 256);
      }
      else
      {
        gbWindowTextFlags = 0;
        gpszWindowText = szText5;
        gdwWindowTextLength = 256;
        EnumWindows(EnumChildrenWindows, liParam.HighPart);
      }
      ItemParam.hMainWndBackup = ghMainWndBackup;
      if ( ghMainWndBackup )
        ItemParam.bMainWndIsHung = IsHungAppWindow(ghMainWndBackup);
      if ( !sbQueryServiceNamesInited )
      {
        QueryServiceNames();
        sbQueryServiceNamesInited = 1;
      }
      UniqueProcessId_1 = pSystemProcessInfo_118->UniqueProcessId;
      liParam.HighPart = (LONG)pSystemProcessInfo_118->UniqueProcessId;
      if ( *(_DWORD *)EnumServicesStatusExW && UniqueProcessId_1 && (pGraphData_244 = 0, gdwServiceReturned) )
      {
        ppszText_245 = &gpszServiceNames->ServiceStatusProcess.dwProcessId;
        while ( 1 )
        {
          pSystemProcessInfo_118 = pSystemProcessInfo_1;
          if ( *ppszText_245 == liParam.HighPart )
            break;
          ++pGraphData_244;
          ppszText_245 += 11;
          if ( pGraphData_244 >= gdwServiceReturned )
            goto LABEL_297;
        }
        ItemParam.dwStyle |= TVLS_SHOWSERVICE;
      }
      else
      {
LABEL_297:
        ItemParam.dwStyle &= -0x21u;
      }
      wcscpy_s((wchar_t *)ItemParam.field_28E, 0x41u, (const wchar_t *)&gszNullString);
      ItemParam.szProcessName2 = _wcsdup(szText);
      if ( !sub_C4D0C0(ProcessHandle, &ItemParam) )
      {
        szProcessName = ItemParam.szProcessName;
        hIcon = 0;
        FileInfo.hIcon = 0;
        if ( ItemParam.szProcessName )
        {
          SHGetFileInfoW(ItemParam.szProcessName, 0, &FileInfo, sizeof(SHFILEINFOW), 0x101u);// SHGFI_ICON | SHGFI_SMALLICON 
          szProcessName = ItemParam.szProcessName;
          hIcon = FileInfo.hIcon;
        }
        ItemParam.hIcon = hIcon;
        hIcon_1 = 0;
        FileInfo.hIcon = 0;
        if ( szProcessName )
        {
          SHGetFileInfoW(szProcessName, 0, &FileInfo, sizeof(SHFILEINFOW), SHGFI_ICON);
          hIcon_1 = FileInfo.hIcon;
        }
        ItemParam.hFileIcon = (int)hIcon_1;
      }
      pGraphData_249 = &pSystemProcessInfo_118->CreateTime.LowPart;
      ItemParam.ProcessBasePriority = pSystemProcessInfo_118->BasePriority;
      if ( !pSystemProcessInfo_118->InheritedFromUniqueProcessId && ItemParam.dwProcessId )
      {
        gdwProcessIdLast = ItemParam.dwProcessId;
        gCreateTimeLast.dwLowDateTime = *pGraphData_249;
        gCreateTimeLast.dwHighDateTime = pSystemProcessInfo_118->CreateTime.HighPart;
        pSystemProcessInfo_118->InheritedFromUniqueProcessId = (HANDLE)-1;
      }
      ItemParam.InheritedFromUniqueProcessId = (int)pSystemProcessInfo_118->InheritedFromUniqueProcessId;
      ItemParam.pItemParam = 0;
      ItemParam.dwHandleCount = pSystemProcessInfo_118->HandleCount;
      ItemParam.CreateTime.dwLowDateTime = *pGraphData_249;
      ItemParam.CreateTime.dwHighDateTime = pSystemProcessInfo_118->CreateTime.HighPart;
      v359 = 0.0;
      fHungFlags = 0;
      if ( (unsigned __int8)GetVersion() <= 4u )
      {
        fHungFlags = 1;
        v256 = (int)&pSystemProcessInfo_118->ReadOperationCount;
      }
      else
      {
        v256 = (int)&pSystemProcessInfo_118[1];
      }
      packageFullName = (wchar_t *)pSystemProcessInfo_118->NumberOfThreads;
      if ( !packageFullName )
        goto LABEL_455;
      v257 = LODWORD(v359);
      v258 = (unsigned int *)(v256 + 48);
      v259 = HIDWORD(v359);
      do
      {
        v260 = *v258 + __PAIR__(v259, v257);
        v259 = v260 >> 32;
        v257 = v260;
        v258 += 16;
        packageFullName = (wchar_t *)((char *)packageFullName - 1);
      }
      while ( packageFullName );
      if ( v259 >= 0 && (v259 > 0 || (_DWORD)v260) )
        ItemParam.ContextSwtiches = __PAIR__(v259, (unsigned int)v260);
      else
LABEL_455:
        ItemParam.ContextSwtiches = 0i64;
      ItemParam.m_SelectedItem = 0;
      fHungFlags = 0;
      if ( (unsigned __int8)GetVersion() <= 4u )
      {
        fHungFlags = 1;
        v261 = (int)&pSystemProcessInfo_118->ReadOperationCount;
      }
      else
      {
        v261 = (int)&pSystemProcessInfo_118[1];
      }
      v262 = pSystemProcessInfo_118->NumberOfThreads;
      v263 = 0;
      if ( v262 )
      {
        v264 = (_DWORD *)(v261 + 56);
        packageFullName = (wchar_t *)pSystemProcessInfo_118->NumberOfThreads;
        v265 = (_DWORD *)(v261 + 52);
        gTreeViewListItemParam_123 = TreeViewListItemParam_328;
        do
        {
          if ( *v265 == 5 && *v264 == 5 )
            ++v263;
          v265 += 16;
          v264 += 16;
          packageFullName = (wchar_t *)((char *)packageFullName - 1);
        }
        while ( packageFullName );
        v262 = pSystemProcessInfo_118->NumberOfThreads;
      }
      if ( v262 == v263 )
        ItemParam.dwStyle |= 0x80u;
      if ( PE_IsProcessInJob(ProcessHandle, ItemParam.dwProcessId, 0, 0) )
        ItemParam.dwStyle |= 0x800u;
      else
        ItemParam.dwStyle &= 0xFFFFF7FF;
      ItemParam.ProcessMitigationPolicy = Fake_GetProcessMitigationPolicy(&ItemParam, ProcessHandle);
      ItemParam.nSpaceNumber = 0;
      ItemParam.m_CPUTime = pSystemProcessInfo_118->KernelTime.QuadPart + pSystemProcessInfo_118->UserTime.QuadPart;
      ItemParam.KernelTime.dwLowDateTime = pSystemProcessInfo_118->KernelTime.LowPart;
      ItemParam.KernelTime.dwHighDateTime = pSystemProcessInfo_118->KernelTime.HighPart;
      ItemParam.field_64 = 0;
      ItemParam.PageFaultCount = pSystemProcessInfo_118->PageFaultCount;
      ItemParam.PagefileUsage = pSystemProcessInfo_118->PagefileUsage;
      ItemParam.VirtualSize = pSystemProcessInfo_118->VirtualSize;
      ItemParam.PeakPagefileUsage = pSystemProcessInfo_118->PeakPagefileUsage;
      ItemParam.WorkingSetSize = pSystemProcessInfo_118->WorkingSetSize;
      ItemParam.PeakWorkingSetSize = pSystemProcessInfo_118->PeakWorkingSetSize;
      if ( !_wcsicmp(ItemParam.szProcessName2, L"wmiprvse.exe") )
        sub_C73A00(ItemParam.dwProcessId, (int)&ItemParam.bSupportWMIProviders);
      ItemParam.m_DPIAwareness = -1;
      if ( GetProcessDpiAwareness )
        GetProcessDpiAwareness(ProcessHandle, &ItemParam.m_DPIAwareness);
      if ( v364 <= 0 && pSystemProcessInfo_118->PagefileUsage > (unsigned int)v354 )
      {
        v354 = (ULONG *)pSystemProcessInfo_118->PagefileUsage;
        v364 = 0;
      }
      if ( gpfnProcessIdToSessionId )
      {
        v266 = gpfnProcessIdToSessionId((DWORD)pSystemProcessInfo_118->UniqueProcessId, (DWORD *)&ItemParam.field_64);
        v267 = ItemParam.field_64;
        if ( !v266 )
          v267 = -1;
        ItemParam.field_64 = v267;
      }
      if ( sdwValueInInitTreeList )
      {
        ItemParam.m_CPU = 0i64;
        v359 = 0.0;
LABEL_360:
        ItemParam.pszSystemName = (int)_wcsdup(szText4);
        v274 = _wcsdup(szFullName);
        ItemParam.dwStyle |= 4u;
        ItemParam.pszName = (int)v274;
        v294 = _wcsicmp(v274, gszMainTitle) == 0;
        dwItemStyle = ItemParam.dwStyle;
        if ( v294 )
        {
          dwItemStyle = ItemParam.dwStyle | 0x40;
          ItemParam.dwStyle |= 0x40u;
        }
        if ( gConfig.bShowAllUsers || ItemParam.dwStyle & 0x40 )
          ItemStyle_270 = dwItemStyle | 2;
        else
          ItemStyle_270 = dwItemStyle & 0xFFFFFFFD;
        ItemParam.dwStyle = ItemStyle_270;
        wcscpy_s((wchar_t *)&ItemParam.field_68, 0x100u, szText5);
        if ( sdwValueInInitTreeList )
        {
          ItemParam.field_10 = 0;
        }
        else
        {
          if ( *(signed __int64 *)&gTimeQuerySystemInfoLast <= *(_QWORD *)&ItemParam.CreateTime )
          {
            ItemParam.field_10 = 2;
          }
          else
          {
            ItemParam.field_10 = 0;
            ItemParam.m_CPU = 0i64;
          }
          ItemParam.field_14 = 0;
          LOBYTE(ItemParam.field_18) = 0;
        }
        LOBYTE(ItemParam.field_500) = 0;
        ItemParam.pNetCclrInfo = (tagNetCclrInfo *)sub_C3B9D0(ItemParam.dwProcessId);
        LOBYTE(ItemParam.field_508) = ProcessIsNetCclr_0(&ItemParam);
        NetCclrInfo_271 = ItemParam.pNetCclrInfo;
        if ( ItemParam.pNetCclrInfo )
        {
          if ( !v372 )
          {
            dynamic_initializer_for_gPerformanceInfoInMemory__();
            NetCclrInfo_271 = ItemParam.pNetCclrInfo;
            v372 = 1;
          }
          if ( NetCclrInfo_271 )
            ++ItemWithSizeIs50H.field_48;
        }
        sub_C3C540(&ItemParam, 0xFFFFFFFF);
        ItemParam.m_GdiObjects = 0;
        ItemParam.m_UserObjects = 0;
        ItemParam.field_14 = 0;
        pItemFound = (tagTREEVIEWLISTITEMPARAM *)::SendMessageW(
                                                   ghMainWnd,
                                                   WM_MSG_7EE,
                                                   (HANDLE)gdwProcessIdSelected == pSystemProcessInfo_118->UniqueProcessId,
                                                   (LPARAM)&ItemParam);
        TreeViewListItemParam_GetSystemInfo(
          pSystemProcessInfo_118,
          ProcessHandle,
          variable_360,
          v369,
          gTimeQuerySystemInfo.dwLowDateTime,
          gTimeQuerySystemInfo.dwHighDateTime,
          pItemFound,
          0xFFFFFFFF);
        TreeViewListItemParam_272 = pItemFound;
        TreeViewListItemParam_273 = TreeViewListItemParam_337;
        TreeViewListItemParam_337 = pItemFound;
        LOBYTE(v374) = 1;
        LODWORD(TreeViewListItemParam_337->ContextSwtichDelta) = TreeViewListItemParam_337->ContextSwtiches;
        HIDWORD(TreeViewListItemParam_272->ContextSwtichDelta) = HIDWORD(TreeViewListItemParam_272->ContextSwtiches);
        LODWORD(TreeViewListItemParam_272->CyclesDelta) = TreeViewListItemParam_272->Cycles;
        HIDWORD(TreeViewListItemParam_272->CyclesDelta) = HIDWORD(TreeViewListItemParam_272->Cycles);
        TreeViewListItemParam_272->m_SelectedItem = (int)TreeViewListItemParam_273;
        if ( ItemParam.szProcessName && *ItemParam.szProcessName != 91 )
        {
          if ( gConfig.bVerifySignatures )
          {
            InterlockedIncrement(&TreeViewListItemParam_272->nRefCount);
            _beginthread((int)VerifyImageThreadProc, 0, (int)pItemFound);
            TreeViewListItemParam_272 = pItemFound;
          }
          v280 = sub_C1BB70((wchar_t *)TreeViewListItemParam_272->pszName, TreeViewListItemParam_272->szProcessName);
          TreeViewListItemParam_275 = (tagDLLLISTITEMPARAM *)pItemFound;
          pItemFound->field_33C = (int)v280;
          v282 = 2;
          if ( gConfig.bCheckVirusTotal )
            v282 = 0;
          sub_C71C30(TreeViewListItemParam_275, 1, v282);
          TreeViewListItemParam_272 = pItemFound;
        }
        if ( TreeViewListItemParam_272->dwProcessId && v359 > *(double *)&v345 )
        {
          *(double *)&v345 = v359;
          TreeViewListItemParam_338 = TreeViewListItemParam_272;
        }
        if ( ItemParam.dwStyle & 0x40 )
        {
          v283 = __PAIR__(v356, pSystemProcessInfo_118->PagefileUsage) + (unsigned int)v355;
          v356 = (__PAIR__(v356, pSystemProcessInfo_118->PagefileUsage) + (unsigned int)v355) >> 32;
          LODWORD(v355) = v283;
          v284 = __PAIR__(HIDWORD(v355), pSystemProcessInfo_118->WorkingSetSize) + v368;
          HIDWORD(v355) = (__PAIR__(HIDWORD(v355), pSystemProcessInfo_118->WorkingSetSize) + v368) >> 32;
          v368 = v284;
          ++ItemWithSizeIs50H.field_34;
          ItemWithSizeIs50H.field_3C += pSystemProcessInfo_118->NumberOfThreads;
          ItemWithSizeIs50H.field_44 += pSystemProcessInfo_118->HandleCount;
          if ( ItemParam.pNetCclrInfo )
            ++ItemWithSizeIs50H.field_4C;
        }
        goto LABEL_259;
      }
      if ( GetProcessorSystemCycleTime && gdwVersion >= 2 )
      {
        if ( v350 | v348 )
        {
          v268 = (double)(unsigned __int64)pSystemProcessInfo_118->SpareLi3.QuadPart;
          *(float *)&liParam.HighPart = v268 * 100.0;
          v269 = (double)(signed __int64)__PAIR__(v350, v348);
          v270 = *(float *)&liParam.HighPart / v269;
LABEL_354:
          *(double *)&v273 = v270;
          v359 = v270;
          if ( v270 > 100.0 )
          {
            *(double *)&v273 = db_onehundred;
            v359 = db_onehundred;
          }
          ItemParam.m_CPU = v273;
          if ( ItemParam.dwStyle & 0x40 )
          {
            dbMemorySize = *(double *)&v273 + dbMemorySize;
            *(double *)&v273 = v359;
          }
          if ( ItemParam.dwProcessId )
            v338 = *(double *)&v273 + v338;
          goto LABEL_360;
        }
      }
      else if ( v369 | variable_360 )
      {
        v271 = (double)(pSystemProcessInfo_118->KernelTime.QuadPart + pSystemProcessInfo_118->UserTime.QuadPart);
        *(float *)&liParam.HighPart = v271 * 100.0;
        v272 = (double)(signed __int64)__PAIR__(v369, variable_360);
        v270 = *(float *)&liParam.HighPart / v272;
        goto LABEL_354;
      }
      v270 = 0.0;
      goto LABEL_354;
    }
    v130 = pSystemProcessInfo_118->CreateTime.LowPart;
    v131 = pSystemProcessInfo_118->CreateTime.HighPart;
    while ( gTreeViewListItemParam_123->CreateTime.dwLowDateTime != v130
         || gTreeViewListItemParam_123->CreateTime.dwHighDateTime != v131
         || gTreeViewListItemParam_123->dwProcessId != UniqueProcessId )
    {
      gTreeViewListItemParam_123 = gTreeViewListItemParam_123->m_Prev;
      TreeViewListItemParam_328 = gTreeViewListItemParam_123;
      if ( !gTreeViewListItemParam_123 )
        goto LABEL_108;
    }
    HIDWORD(v321) = UniqueProcessId;
    ProcessHandle = (tagTREEVIEWLISTITEMPARAM *)OpenProcess(0x2000000u, 0, UniqueProcessId);
    TreeViewListItemParam_347 = ProcessHandle;
    if ( !ProcessHandle )
    {
      if ( GetLastError() == ERROR_ACCESS_DENIED )
        DeviceIoControl(
          ghDriverHandle,
          0x8335003C,
          (char *)&v321 + 4,
          4u,
          &TreeViewListItemParam_347,
          4u,
          (LPDWORD)&v325 + 1,
          0);
      ProcessHandle = TreeViewListItemParam_347;
    }
    if ( (FindInfo.flags = 1,
          FindInfo.lParam = (LPARAM)gTreeViewListItemParam_123,
          nItemFound = ::SendMessageW(hWndListCtrl_1, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&FindInfo),
          Item.iItem = nItemFound,
          v133 = gTreeViewListItemParam_123->dwStyle,
          !(v133 & 2))
      || v133 & 1 && gConfig.byte_14012ADFE
      || nItemFound != -1 )
    {
      gTreeViewListItemParam_123->field_2C = nItemFound;
    }
    else
    {
      sub_C27F20(ghWndTreeListView, gTreeViewListItemParam_123);
    }
    v134 = TreeViewListItemParam_GetSystemInfo(
             pSystemProcessInfo_118,
             ProcessHandle,
             variable_360,
             v369,
             gTimeQuerySystemInfo.dwLowDateTime,
             gTimeQuerySystemInfo.dwHighDateTime,
             gTreeViewListItemParam_123,
             Item.iItem);
    LOBYTE(v374) = v134 | v374;
    v136 = pSystemProcessInfo_118->KernelTime.LowPart;
    v137 = pSystemProcessInfo_118->UserTime.LowPart;
    v135 = pSystemProcessInfo_118->UserTime.LowPart + pSystemProcessInfo_118->KernelTime.LowPart;
    v340 = pSystemProcessInfo_118->KernelTime.HighPart;
    v138 = __PAIR__(v340, v137) + __PAIR__(pSystemProcessInfo_118->UserTime.HighPart, v136);
    v173 = v135 < LODWORD(gTreeViewListItemParam_123->m_CPUTime);
    v139 = v135 - LODWORD(gTreeViewListItemParam_123->m_CPUTime);
    HIDWORD(v346) = v137 + v136;
    v140 = HIDWORD(v138) - (v173 + HIDWORD(gTreeViewListItemParam_123->m_CPUTime));
    packageFullName = (wchar_t *)HIDWORD(v138);
    if ( GetProcessorSystemCycleTime )
    {
      if ( !(v350 | v348) )
        goto LABEL_135;
      v141 = (double)gTreeViewListItemParam_123->CyclesDelta;
      *(float *)&liParam.HighPart = v141 * 100.0;
      v142 = (double)(signed __int64)__PAIR__(v350, v348);
      v143 = *(float *)&liParam.HighPart / v142;
    }
    else
    {
      if ( !gTreeViewListItemParam_123->dwProcessId )
      {
        v144 = v359;
        TreeViewListItemParam_336 = gTreeViewListItemParam_123;
        goto LABEL_137;
      }
      if ( !(v369 | variable_360) )
      {
LABEL_135:
        v143 = 0.0;
        goto LABEL_136;
      }
      v145 = (double)__PAIR__(v140, v139);
      *(float *)&liParam.HighPart = v145 * 100.0;
      v146 = (double)(signed __int64)__PAIR__(v369, variable_360);
      v143 = *(float *)&liParam.HighPart / v146;
    }
LABEL_136:
    v144 = v143;
    v359 = v143;
LABEL_137:
    if ( v144 > 100.0 )
      v359 = db_onehundred;
    if ( v369 | variable_360 )
    {
      v147 = (double)(signed __int64)(__PAIR__(v340, pSystemProcessInfo_118->KernelTime.LowPart)
                                    - *(_QWORD *)&gTreeViewListItemParam_123->KernelTime);
      *(float *)&liParam.HighPart = v147 * 100.0;
      v148 = (double)(signed __int64)__PAIR__(v369, variable_360);
      v149 = *(float *)&liParam.HighPart / v148;
    }
    else
    {
      v149 = 0.0;
    }
    v150 = gTreeViewListItemParam_123->m_Gpu2;
    v173 = *(double *)&v150 < v319;
    v294 = *(double *)&v150 == v319;
    gTreeViewListItemParam_123->KernelTime.dwLowDateTime = pSystemProcessInfo_118->KernelTime.LowPart;
    gTreeViewListItemParam_123->KernelTime.dwHighDateTime = v340;
    v151 = v149;
    if ( !v173 && !v294 )
    {
      TreeViewListItemParam_327 = gTreeViewListItemParam_123;
      v319 = (float)*(double *)&v150;
    }
    if ( gTreeViewListItemParam_123->dwStyle & 0x40 )
      dbMemorySize = v359 + dbMemorySize;
    v152 = _mm_unpckl_pd((__m128d)*(unsigned __int64 *)&v359, (__m128d)*(unsigned __int64 *)&v359);
    if ( gTreeViewListItemParam_123->dwProcessId )
    {
      if ( pSystemProcessInfo_118->UserTime.QuadPart )
        CGraphData_Update(gTreeViewListItemParam_123->pGraphData1, gTimeQuerySystemInfo, v152.m128d_f64[0], v151, 0);
      else
        CGraphData_Update(
          gTreeViewListItemParam_123->pGraphData1,
          gTimeQuerySystemInfo,
          v152.m128d_f64[0],
          v152.m128d_f64[1],
          0);
      *(double *)&v153 = v359;
      v338 = v359 + v338;
      if ( v359 > *(double *)&v345 )
      {
        *(double *)&v345 = v359;
        TreeViewListItemParam_338 = gTreeViewListItemParam_123;
      }
    }
    else
    {
      CGraphData_Update(gTreeViewListItemParam_123->pGraphData1, gTimeQuerySystemInfo, 0.0, v152.m128d_f64[0], 0);
      *(double *)&v153 = v359;
    }
    v154 = *(double *)&v153 != *(double *)&gTreeViewListItemParam_123->m_CPU;
    gTreeViewListItemParam_123->m_CPU = v153;
    v155 = RedrawColumn(v154, ghWndTreeListView, IDS_CPU, Item.iItem);
    v156 = *(double *)&gTreeViewListItemParam_123->m_CPUUsage + v359;
    LOBYTE(v374) = v155 | v374;
    fHungFlags = 1;
    if ( v156 == *(double *)&gTreeViewListItemParam_123->m_CPUUsage )
      fHungFlags = 0;
    *(double *)&gTreeViewListItemParam_123->m_CPUUsage = v156;
    v157 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, Item.iItem);
    LOBYTE(v374) = v157 | v374;
    v294 = gTreeViewListItemParam_123->pItemParam == 0;
    liParam.HighPart = (LONG)&gTreeViewListItemParam_123->pItemParam;
    if ( !v294 )
    {
      ppTreeViewListItemParam_152 = &gTreeViewListItemParam_123->pItemParam;
      do
      {
        *(double *)&(*ppTreeViewListItemParam_152)->m_CPUUsage = (float)*(double *)&(*ppTreeViewListItemParam_152)->m_CPUUsage
                                                               + v359;
        v159 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, (*ppTreeViewListItemParam_152)->field_2C);
        TreeViewListItemParam_154 = *ppTreeViewListItemParam_152;
        LOBYTE(v374) = v159 | v374;
        ppTreeViewListItemParam_152 = &TreeViewListItemParam_154->pItemParam;
      }
      while ( *ppTreeViewListItemParam_152 );
      pSystemProcessInfo_118 = pSystemProcessInfo_1;
    }
    v161 = RedrawColumn(fHungFlags, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
    LOBYTE(v374) = v161 | v374;
    --v349;
    if ( sub_C4D0C0(ProcessHandle, gTreeViewListItemParam_123) )
    {
      PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
      RefreshTreeView();
    }
    v162 = ((unsigned int)gTreeViewListItemParam_123->dwStyle >> 7) & 0xFFFFFF01;
    fHungFlags = 0;
    v340 = v162;
    if ( (unsigned __int8)GetVersion() <= 4u )
    {
      fHungFlags = 1;
      v163 = (int)&pSystemProcessInfo_118->ReadOperationCount;
    }
    else
    {
      v163 = (int)&pSystemProcessInfo_118[1];
    }
    v164 = pSystemProcessInfo_118->NumberOfThreads;
    v165 = 0;
    liParam.HighPart = v164;
    if ( v164 )
    {
      v166 = (_DWORD *)(v163 + 56);
      v167 = (_DWORD *)(v163 + 52);
      do
      {
        if ( *v167 == 5 && *v166 == 5 )
          ++v165;
        v167 += 16;
        v166 += 16;
        --v164;
      }
      while ( v164 );
      v164 = liParam.HighPart;
    }
    if ( v164 == v165 )
      gTreeViewListItemParam_123->dwStyle |= 0x80u;
    else
      gTreeViewListItemParam_123->dwStyle &= -0x81u;
    if ( (((unsigned int)gTreeViewListItemParam_123->dwStyle >> 7) & 1) != (_BYTE)v340 )
    {
      PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
      RefreshTreeView();
    }
    v168 = (_WORD *)gTreeViewListItemParam_123->pszCommandLine;
    if ( (!v168 || !*v168) && gTreeViewListItemParam_123->field_28D < 2u )
    {
      QueryProcessArguments(
        ProcessHandle,
        gTreeViewListItemParam_123->dwProcessId,
        (WCHAR **)&gTreeViewListItemParam_123->pszCommandLine,
        (WCHAR **)&gTreeViewListItemParam_123->pszCurrentDirectory,
        (WCHAR **)&gTreeViewListItemParam_123->pszEnvBlock,
        0);
      free(v168);
      ++gTreeViewListItemParam_123->field_28D;
      v169 = (_WORD *)gTreeViewListItemParam_123->pszCommandLine;
      if ( v169 )
      {
        if ( *v169 )
        {
          v170 = RedrawColumn(1, ghWndTreeListView, IDS_COMMAND_LINE, Item.iItem);
          LOBYTE(v374) = v170 | v374;
        }
      }
    }
    v171 = gTreeViewListItemParam_123->field_28C;
    if ( (unsigned __int8)v171 < 2u )
    {
      if ( !flags )
        gTreeViewListItemParam_123->field_28C = v171 + 1;
    }
    else if ( !flags )
    {
      goto LABEL_190;
    }
    if ( PE_IsProcessInJob(ProcessHandle, gTreeViewListItemParam_123->dwProcessId, 0, 0) )
      gTreeViewListItemParam_123->dwStyle |= TVLS_ENABLEJOBS;
    else
      gTreeViewListItemParam_123->dwStyle &= -0x801u;
LABEL_190:
    if ( ProcessHandle )
    {
      liParam.HighPart = gTreeViewListItemParam_123->ProcessMitigationPolicy;
      v172 = Fake_GetProcessMitigationPolicy(gTreeViewListItemParam_123, ProcessHandle);
      gTreeViewListItemParam_123->ProcessMitigationPolicy = v172;
      if ( v172 != liParam.HighPart
        && ((v173 = (unsigned __int8)v172 < BYTE4(liParam.QuadPart), (_BYTE)v172 != BYTE4(liParam.QuadPart))
         || (v174 = BYTE1(gTreeViewListItemParam_123->ProcessMitigationPolicy),
             v173 = v174 < BYTE5(liParam.QuadPart),
             v174 != BYTE5(liParam.QuadPart))
         || (v175 = BYTE2(gTreeViewListItemParam_123->ProcessMitigationPolicy),
             v173 = v175 < BYTE6(liParam.QuadPart),
             v175 != BYTE6(liParam.QuadPart))
         || (v176 = HIBYTE(gTreeViewListItemParam_123->ProcessMitigationPolicy),
             v173 = v176 < HIBYTE(liParam.QuadPart),
             v176 != HIBYTE(liParam.QuadPart))) )
      {
        v177 = -v173 | 1;
      }
      else
      {
        v177 = 0;
      }
      v178 = RedrawColumn(v177 == 0, ghWndTreeListView, 1199, Item.iItem);
      LOBYTE(v374) = v178 | v374;
    }
    if ( gTreeViewListItemParam_123->pNetCclrInfo )
    {
LABEL_210:
      ++ItemWithSizeIs50H.field_48;
      goto LABEL_211;
    }
    v179 = gTreeViewListItemParam_123->field_500;
    if ( v179 < 2u )
    {
      if ( !flags )
        LOBYTE(gTreeViewListItemParam_123->field_500) = v179 + 1;
    }
    else if ( !flags )
    {
      goto LABEL_209;
    }
    gTreeViewListItemParam_123->pNetCclrInfo = (tagNetCclrInfo *)sub_C3B9D0(gTreeViewListItemParam_123->dwProcessId);
    LOBYTE(gTreeViewListItemParam_123->field_508) = ProcessIsNetCclr_0(gTreeViewListItemParam_123);
    if ( !gTreeViewListItemParam_123->pNetCclrInfo )
      goto LABEL_211;
    if ( !v372 )
    {
      dynamic_initializer_for_gPerformanceInfoInMemory__();
      v372 = 1;
    }
    PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
    RefreshTreeView();
LABEL_209:
    if ( gTreeViewListItemParam_123->pNetCclrInfo )
      goto LABEL_210;
LABEL_211:
    v180 = gTreeViewListItemParam_123->ProcessBasePriority;
    v181 = pSystemProcessInfo_1->BasePriority;
    gTreeViewListItemParam_123->ProcessBasePriority = v181;
    v182 = RedrawColumn(v181 != v180, ghWndTreeListView, IDS_PRIORITY, Item.iItem);
    LOBYTE(v374) = v182 | v374;
    if ( gTreeViewListItemParam_123->ProcessBasePriority != v180 )
    {
      v183 = Item.lParam->ProcessBasePriority;
      if ( v183 == 4 && !Item.lParam->m_ProcessIoPriority )
        v183 = 0;
      ArgList_16 = v183;
      v185 = GetMenu(ghMainWnd);
      UpateProirtyMenuItem(v185, ArgList_16);
    }
    v186 = packageFullName;
    v187 = HIDWORD(v346) != LODWORD(gTreeViewListItemParam_123->m_CPUTime)
        || packageFullName != (wchar_t *)HIDWORD(gTreeViewListItemParam_123->m_CPUTime);
    LODWORD(gTreeViewListItemParam_123->m_CPUTime) = HIDWORD(v346);
    HIDWORD(gTreeViewListItemParam_123->m_CPUTime) = v186;
    v188 = RedrawColumn(v187, ghWndTreeListView, IDS_CPU_TIME, Item.iItem);
    LOBYTE(v374) = v188 | v374;
    if ( GetProcessDpiAwareness )
    {
      GetProcessDpiAwareness(ProcessHandle, (char *)&v320 + 4);
      v294 = HIDWORD(v320) == gTreeViewListItemParam_123->m_DPIAwareness;
      gTreeViewListItemParam_123->m_DPIAwareness = HIDWORD(v320);
      v189 = RedrawColumn(!v294, ghWndTreeListView, IDS_DPI_AWARENESS, Item.iItem);
      LOBYTE(v374) = v189 | v374;
    }
    pSystemProcessInfo_184 = pSystemProcessInfo_1;
    v191 = pSystemProcessInfo_1->HandleCount;
    v294 = v191 == gTreeViewListItemParam_123->dwHandleCount;
    gTreeViewListItemParam_123->dwHandleCount = v191;
    v192 = RedrawColumn(!v294, ghWndTreeListView, IDS_HANDLES, Item.iItem);
    LOBYTE(v374) = v192 | v374;
    v193 = pSystemProcessInfo_184->PageFaultCount - gTreeViewListItemParam_123->PageFaultCount;
    v294 = v193 == gTreeViewListItemParam_123->m_PFDelta;
    gTreeViewListItemParam_123->m_PFDelta = v193;
    v194 = RedrawColumn(!v294, ghWndTreeListView, IDS_PF_DELTA, Item.iItem);
    LOBYTE(v374) = v194 | v374;
    v195 = pSystemProcessInfo_184->PageFaultCount;
    v294 = v195 == gTreeViewListItemParam_123->PageFaultCount;
    gTreeViewListItemParam_123->PageFaultCount = v195;
    v196 = RedrawColumn(!v294, ghWndTreeListView, IDS_PAGE_FAULTS, Item.iItem);
    LOBYTE(v374) = v196 | v374;
    v197 = pSystemProcessInfo_184->WorkingSetSize;
    v294 = v197 == gTreeViewListItemParam_123->WorkingSetSize;
    gTreeViewListItemParam_123->WorkingSetSize = v197;
    v198 = RedrawColumn(!v294, ghWndTreeListView, IDS_WORKING_SET, Item.iItem);
    LOBYTE(v374) = v198 | v374;
    v199 = pSystemProcessInfo_184->PeakWorkingSetSize;
    v294 = v199 == gTreeViewListItemParam_123->PeakWorkingSetSize;
    gTreeViewListItemParam_123->PeakWorkingSetSize = v199;
    v200 = RedrawColumn(!v294, ghWndTreeListView, IDS_PEAK_WORKING_SET, Item.iItem);
    LOBYTE(v374) = v200 | v374;
    v201 = pSystemProcessInfo_184->QuotaPagedPoolUsage;
    v294 = v201 == gTreeViewListItemParam_123->m_PagedPool;
    gTreeViewListItemParam_123->m_PagedPool = v201;
    v202 = RedrawColumn(!v294, ghWndTreeListView, IDS_PAGEDPOOL, Item.iItem);
    LOBYTE(v374) = v202 | v374;
    v203 = pSystemProcessInfo_184->QuotaNonPagedPoolUsage;
    v294 = v203 == gTreeViewListItemParam_123->m_NonpagedPool;
    gTreeViewListItemParam_123->m_NonpagedPool = v203;
    v204 = RedrawColumn(!v294, ghWndTreeListView, IDS_NONPAGEDPOOL, Item.iItem);
    LOBYTE(v374) = v204 | v374;
    v205 = pSystemProcessInfo_184->PeakPagefileUsage;
    v294 = v205 == gTreeViewListItemParam_123->PeakPagefileUsage;
    gTreeViewListItemParam_123->PeakPagefileUsage = v205;
    v206 = RedrawColumn(!v294, ghWndTreeListView, IDS_PEAK_PRIVATE_BYTES, Item.iItem);
    LOBYTE(v374) = v206 | v374;
    v207 = pSystemProcessInfo_184->PagefileUsage - gTreeViewListItemParam_123->PagefileUsage;
    v294 = v207 == gTreeViewListItemParam_123->m_PrivatedDeltaBytes;
    gTreeViewListItemParam_123->m_PrivatedDeltaBytes = v207;
    v208 = RedrawColumn(!v294, ghWndTreeListView, IDS_PRIVATE_DELTA_BYTES, Item.iItem);
    LOBYTE(v374) = v208 | v374;
    v209 = pSystemProcessInfo_184->PagefileUsage;
    if ( v364 <= 0 && v209 > (unsigned int)v354 )
    {
      v354 = (ULONG *)pSystemProcessInfo_184->PagefileUsage;
      v364 = 0;
    }
    v294 = v209 == gTreeViewListItemParam_123->PagefileUsage;
    gTreeViewListItemParam_123->PagefileUsage = v209;
    v210 = !v294;
    v211 = RedrawColumn(v210, ghWndTreeListView, IDS_PRIVATE_BYTES, Item.iItem);
    LOBYTE(v374) = v211 | v374;
    v212 = RedrawColumn(v210, ghWndTreeListView, IDS_PRIVATE_BYTES_HISTORY, Item.iItem);
    LOBYTE(v374) = v212 | v374;
    pGraphData_207 = gTreeViewListItemParam_123->pGraphData2;
    if ( pGraphData_207
      && (double)((unsigned int)gTreeViewListItemParam_123->PeakPagefileUsage >> 10)
       + qword_CAD110[(unsigned int)gTreeViewListItemParam_123->PeakPagefileUsage >> 41] >= pGraphData_207->m_dbMemorySize )
    {
      pGraphData_207->m_dbMemorySize = (float)((float)((double)((unsigned int)gTreeViewListItemParam_123->PeakPagefileUsage >> 10)
                                                     + qword_CAD110[(unsigned int)gTreeViewListItemParam_123->PeakPagefileUsage >> 41])
                                             * 1.2);
    }
    CGraphData_Update(
      gTreeViewListItemParam_123->pGraphData2,
      gTimeQuerySystemInfo,
      (float)((float)(unsigned int)gTreeViewListItemParam_123->PagefileUsage * 0.0009765625),
      0.0,
      0);
    pSystemProcessInfo_118 = pSystemProcessInfo_1;
    v214 = pSystemProcessInfo_1->VirtualSize;
    v294 = v214 == gTreeViewListItemParam_123->VirtualSize;
    gTreeViewListItemParam_123->VirtualSize = v214;
    v215 = RedrawColumn(!v294, ghWndTreeListView, IDS_VIRTUAL_SIZE, Item.iItem);
    LOBYTE(v374) = v215 | v374;
    if ( IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_TITLE) || IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_STATUS) )
    {
      UniqueProcessId_2 = (LPARAM)pSystemProcessInfo_118->UniqueProcessId;
      wcscpy_s(szText5, 0x100u, (const wchar_t *)&gszNullString);
      ghMainWndBackup = 0;
      if ( UniqueProcessId_2 == GetCurrentProcessId() )
      {
        ghMainWndBackup = ghMainWnd;
        GetWindowTextW(ghMainWnd, gpszWindowText, 256);
      }
      else
      {
        gbWindowTextFlags = 0;
        gpszWindowText = szText5;
        gdwWindowTextLength = 256;
        EnumWindows(EnumChildrenWindows, UniqueProcessId_2);
      }
      hMainWndBackup = ghMainWndBackup;
      fHungFlags = gTreeViewListItemParam_123->bMainWndIsHung;
      if ( IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_STATUS) && hMainWndBackup )
        fHungFlags = IsHungAppWindow(hMainWndBackup);
      v218 = wcscmp(szText5, (const unsigned __int16 *)&gTreeViewListItemParam_123->field_68);
      if ( v218 )
        v218 = -(v218 < 0) | 1;
      v294 = v218 == 0;
      v219 = fHungFlags;
      if ( !v294 || (fHungFlags = 0, v219 != gTreeViewListItemParam_123->bMainWndIsHung) )
        fHungFlags = 1;
      gTreeViewListItemParam_123->bMainWndIsHung = v219;
      wcscpy_s((wchar_t *)&gTreeViewListItemParam_123->field_68, 0x100u, szText5);
      gTreeViewListItemParam_123->hMainWndBackup = hMainWndBackup;
      v220 = fHungFlags;
      v221 = RedrawColumn(fHungFlags, ghWndTreeListView, IDS_WINDOW_TITLE, Item.iItem);
      LOBYTE(v374) = v221 | v374;
      v222 = RedrawColumn(v220, ghWndTreeListView, IDS_WINDOW_STATUS, Item.iItem);
      pSystemProcessInfo_118 = pSystemProcessInfo_1;
      LOBYTE(v374) = v222 | v374;
    }
    v223 = pSystemProcessInfo_118->NumberOfThreads;
    v294 = v223 == gTreeViewListItemParam_123->dwThreadCount;
    gTreeViewListItemParam_123->dwThreadCount = v223;
    v224 = RedrawColumn(!v294, ghWndTreeListView, IDS_THREADS2, Item.iItem);
    LOBYTE(v374) = v224 | v374;
    if ( gTreeViewListItemParam_123->pGraphDataPROCCPU )
    {
      v225 = (gTreeViewListItemParam_123->DeltaWriteBytes + gTreeViewListItemParam_123->DeltaOtherBytes) >> 32;
      v226 = LODWORD(gTreeViewListItemParam_123->DeltaWriteBytes) + LODWORD(gTreeViewListItemParam_123->DeltaOtherBytes);
      v227 = gTreeViewListItemParam_123->DeltaReadBytes;
      liParam.HighPart = LODWORD(gTreeViewListItemParam_123->DeltaReadBytes) + v226;
      LODWORD(v228) = v227 + v226;
      HIDWORD(v346) = (__PAIR__(v225, v227) + __PAIR__(HIDWORD(gTreeViewListItemParam_123->DeltaReadBytes), v226)) >> 32;
      HIDWORD(v228) = HIDWORD(v346);
      if ( (double)v228 >= gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize )
      {
        v229 = (double)(signed __int64)__PAIR__(HIDWORD(v346), liParam.HighPart);
        gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize = (float)(v229 * 1.2);
        gTreeViewListItemParam_123->pGraphDataPROCCPU->m_Item[0].dbMemorySize = gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize;
      }
    }
    v230 = HIDWORD(gTreeViewListItemParam_123->DeltaReadBytes);
    v231 = gTreeViewListItemParam_123->DeltaReadBytes;
    v232 = (double)(signed __int64)gTreeViewListItemParam_123->DeltaWriteBytes;
    *((float *)&v346 + 1) = v232;
    ArgList_8 = v232;
    v234 = (double)(signed __int64)__PAIR__(v230, v231);
    v235 = HIDWORD(gTreeViewListItemParam_123->DeltaOtherBytes);
    v236 = gTreeViewListItemParam_123->DeltaOtherBytes;
    *(float *)&v234 = v234;
    *((float *)&v346 + 1) = *(float *)&v234 + *((float *)&v346 + 1);
    *(float *)&v234 = (double)(signed __int64)__PAIR__(v235, v236);
    CGraphData_Update(
      gTreeViewListItemParam_123->pGraphDataPROCCPU,
      gTimeQuerySystemInfo,
      (float)(*((float *)&v346 + 1) + *(float *)&v234),
      ArgList_8,
      0);
    sub_C247C0((int)gTreeViewListItemParam_123, (TreeList_Item1 *)&gTreeViewListItemParam_123->ReadOperationCount);
    sub_C247C0((int)gTreeViewListItemParam_123, (TreeList_Item1 *)&gTreeViewListItemParam_123->dbNetworkDeltaReceives);
    sub_C247C0((int)gTreeViewListItemParam_123, (TreeList_Item1 *)&gTreeViewListItemParam_123->field_498);
    v237 = RedrawColumn(1, ghWndTreeListView, IDS_IO_HISTORY, Item.iItem);
    LOBYTE(v374) = v237 | v374;
    if ( gTreeViewListItemParam_123->pNetCclrInfo && !v372 )
    {
      dynamic_initializer_for_gPerformanceInfoInMemory__();
      v372 = 1;
    }
    v238 = sub_C3C540(gTreeViewListItemParam_123, Item.iItem);
    LOBYTE(v374) = v238 | v374;
    if ( gTreeViewListItemParam_123->dwStyle & 0x40 )
    {
      v239 = pSystemProcessInfo_118->KernelTime.QuadPart
           + pSystemProcessInfo_118->UserTime.QuadPart
           + __PAIR__(v367, v339);
      v367 = v239 >> 32;
      v339 = v239;
      v240 = __PAIR__(v356, pSystemProcessInfo_118->PagefileUsage) + (unsigned int)v355;
      v356 = (__PAIR__(v356, pSystemProcessInfo_118->PagefileUsage) + (unsigned int)v355) >> 32;
      LODWORD(v355) = v240;
      v241 = __PAIR__(HIDWORD(v355), pSystemProcessInfo_118->WorkingSetSize) + v368;
      HIDWORD(v355) = (__PAIR__(HIDWORD(v355), pSystemProcessInfo_118->WorkingSetSize) + v368) >> 32;
      v368 = v241;
      ++ItemWithSizeIs50H.field_34;
      ItemWithSizeIs50H.field_3C += pSystemProcessInfo_118->NumberOfThreads;
      ItemWithSizeIs50H.field_44 += pSystemProcessInfo_118->HandleCount;
      if ( gTreeViewListItemParam_123->pNetCclrInfo )
        ++ItemWithSizeIs50H.field_4C;
    }
    RedrawColumn(1, ghWndTreeListView, IDS_PRIVATE_BYTES_HISTORY, Item.iItem);
    RedrawColumn(1, ghWndTreeListView, IDS_IO_HISTORY, Item.iItem);
    RedrawColumn(1, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
    v242 = gTreeViewListItemParam_123->field_18;
    v243 = 0;
    if ( v242 )
    {
      v244 = gTreeViewListItemParam_123->field_1C;
      if ( v244 < (signed int)gConfig.dwHighlightDuration )
      {
        gTreeViewListItemParam_123->field_10 = 2;
        gTreeViewListItemParam_123->field_14 = v244;
        goto LABEL_259;
      }
      if ( v242 )
      {
        v243 = 1;
        LOBYTE(gTreeViewListItemParam_123->field_18) = 0;
      }
    }
    v245 = v374;
    if ( v243 )
      v245 = 1;
    gTreeViewListItemParam_123->field_10 = 0;
    LOBYTE(v374) = v245;
LABEL_259:
    if ( ProcessHandle )
      CloseHandle(ProcessHandle);
    if ( !pSystemProcessInfo_118->NextEntryOffset )
      break;
    v123 = v331;
    pSystemProcessInfo_118 = (SYSTEM_PROCESS_INFORMATION *)((char *)pSystemProcessInfo_118
                                                          + pSystemProcessInfo_118->NextEntryOffset);
  }
  if ( v370 || !gConfig.bShowAllUsers )
  {
    SendMessageW = ::SendMessageW;
  }
  else
  {
    // 初始化tagTREEVIEWLISTITEMPARAM
    memset(&ItemParam, 0, sizeof(tagTREEVIEWLISTITEMPARAM));
    ItemParam.dwStyle |= 6u;
    dwProcessorIndex = 0;
    LOBYTE(ItemParam.ProcessMitigationPolicy) = -1;
    ItemParam.pNetCclrInfo = 0;
    ItemParam.m_ProcessIoPriority = -1;
    ItemParam.m_ProcessMemoryPriority = -1;
    ItemParam.m_SelectedItem = 0;
    ItemParam.field_10 = 0;
    ItemParam.dwProcessId = -10;
    if ( (signed int)gSystemInfo.dwNumberOfProcessors > 0 )
    {
      v286 = &gpSystemPerformanceInfo->InterruptTime;
      v287 = &gpSystemInterruptInfo->DpcCount;
      do
      {
        v287 += 6;
        ItemParam.ContextSwtiches += *(v287 - 6) + v286[1].LowPart;
        ItemParam.m_CPUTime += *(_QWORD *)v286 + v286[-1].QuadPart;
        v288 = *(_QWORD *)v286 + v286[-1].QuadPart;
        v286 += 6;
        *(_QWORD *)&ItemParam.KernelTime += v288;
        v289 = (gpSystemProcessorCycleTimeInfo[dwProcessorIndex].CycleTime + ItemParam.Cycles) >> 32;
        LODWORD(ItemParam.Cycles) += LODWORD(gpSystemProcessorCycleTimeInfo[dwProcessorIndex++].CycleTime);
        HIDWORD(ItemParam.Cycles) = v289;
      }
      while ( dwProcessorIndex < (signed int)gSystemInfo.dwNumberOfProcessors );
      gTreeViewListItemParam_123 = TreeViewListItemParam_328;
    }
    ItemParam.pszTitle = (int)_wcsdup(L"Hardware Interrupts and DPCs");
    ItemParam.szProcessName2 = _wcsdup(L"Interrupts");
    ItemParam.CreateTime = gCreateTimeLast;
    ItemParam.InheritedFromUniqueProcessId = gdwProcessIdLast;
    SendMessageW = ::SendMessageW;
    ItemParam.pszSystemName = (int)_wcsdup(L"System");
    TreeViewListItemParam_285 = (tagTREEVIEWLISTITEMPARAM *)::SendMessageW(
                                                              ghMainWnd,
                                                              WM_MSG_7EE,
                                                              gdwProcessIdSelected == 0,
                                                              (LPARAM)&ItemParam);
    TreeViewListItemParam_285->m_SelectedItem = (int)TreeViewListItemParam_337;
  }
  if ( !gbShowProcessTreeLast
    && gConfig.dwProcessSortColumn != 1000
    && !(_BYTE)v374
    && gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn] == 1055 )
  {
    Item.mask = LVIF_PARAM;
    Item.iItem = 1;
    Item.iSubItem = 0;
    if ( SendMessageW(hWndListCtrl_1, LVM_GETITEMW, 0, (LPARAM)&Item) )
    {
      while ( 1 )
      {
        if ( gConfig.bProcessSortDirection )
        {
          v292 = gTreeViewListItemParam_123->m_CPU;
          v293 = *(double *)&v292 < *(double *)&Item.lParam->m_CPU;
          v294 = *(double *)&v292 == *(double *)&Item.lParam->m_CPU;
        }
        else
        {
          v295 = Item.lParam->m_CPU;
          v293 = *(double *)&v295 < *(double *)&gTreeViewListItemParam_123->m_CPU;
          v294 = *(double *)&v295 == *(double *)&gTreeViewListItemParam_123->m_CPU;
        }
        if ( !v293 && !v294 )
          break;
        ++Item.iItem;
        gTreeViewListItemParam_123 = Item.lParam;
        if ( !SendMessageW(hWndListCtrl_1, LVM_GETITEMW, 0, (LPARAM)&Item) )
          goto LABEL_410;
      }
      LOBYTE(v374) = 1;
    }
  }
LABEL_410:
  v296 = variable_360;
  v297 = v369;
  if ( v369 | variable_360 )
  {
    v298 = (double)(signed __int64)(__PAIR__(v363, v361) - qword_CEBC30);
    v337 = v298 * 100.0;
    v299 = (double)(signed __int64)__PAIR__(v369, variable_360);
    v337 = v337 / v299;
  }
  LODWORD(qword_CEBC30) = v361;
  HIDWORD(qword_CEBC30) = v363;
  ItemWithSizeIs50H.dbMemorySize = dbMemorySize;
  PE_QueryMemoryInfo(__PAIR__(v356, (unsigned int)v355), 0, (DWORD)&dwUnavailPhys, &dbMemorySize);
  *(double *)&ItemWithSizeIs50H.field_18 = v9;
  LODWORD(qword_CEBA40) = v354;
  HIDWORD(qword_CEBA40) = v364;
  *(double *)&ItemWithSizeIs50H.field_28 = (double)((signed __int64)__PAIR__(HIDWORD(v355), v368) / 1024)
                                         / dbMemorySize
                                         * 100.0;
  if ( TreeViewListItemParam_336 )
  {
    dbMemorySize = 100.0 - v338;
    if ( 100.0 - v338 < 0.0 )
      dbMemorySize = 0.0;
    FindInfo.lParam = (LPARAM)TreeViewListItemParam_336;
    FindInfo.flags = 1;
    Item.iItem = ::SendMessageW(hWndListCtrl_1, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&FindInfo);
    v300 = dbMemorySize != *(double *)&TreeViewListItemParam_336->m_CPU;
    *(double *)&TreeViewListItemParam_336->m_CPU = dbMemorySize;
    v301 = RedrawColumn(v300, ghWndTreeListView, IDS_CPU, Item.iItem);
    LOBYTE(v374) = v301 | v374;
    v370 = 1;
    v302 = *(double *)&TreeViewListItemParam_336->m_CPUUsage + dbMemorySize;
    if ( v302 == *(double *)&TreeViewListItemParam_336->m_CPUUsage )
      v370 = 0;
    *(double *)&TreeViewListItemParam_336->m_CPUUsage = v302;
    v303 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, Item.iItem);
    LOBYTE(v374) = v303 | v374;
    v304 = RedrawColumn(v370, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
    LOBYTE(v374) = v304 | v374;
    CGraphData_Update(TreeViewListItemParam_336->pGraphData1, gTimeQuerySystemInfo, 0.0, dbMemorySize, 0);
  }
  if ( !(_BYTE)v374 && v349 )
  {
    v305 = ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
    for ( i = 0; i < v305; ++i )
      PostMessageW(ghMainWnd, WM_MSG_7EB, i, -1);
    v297 = v369;
    v296 = variable_360;
  }
  v307 = db_onehundred;
  if ( v338 <= 100.0 )
    v307 = v338;
  *(double *)&ItemWithSizeIs50H.field_0 = v307;
  sub_C70410(
    v9,
    v8,
    v7,
    v6,
    v5,
    v4,
    v3,
    ghWndStatusBar,
    (tagPEStatusBarItem *)&ItemWithSizeIs50H,
    &v316,
    (double *)&dwUnavailPhys);
  if ( TreeViewListItemParam_338 )
  {
    v308 = TreeViewListItemParam_338->dwProcessId;
    if ( gConfig.bShowCpuFractions )
    {
      if ( v308 <= 0 )
        wsprintfW(szBuffer, L"%02.02f%% %s", v345, TreeViewListItemParam_338->szProcessName2);
      else
        wsprintfW(
          szBuffer,
          L"%02.02f%% %s:%d",
          v345,
          TreeViewListItemParam_338->szProcessName2,
          TreeViewListItemParam_338->dwProcessId);
    }
    else if ( v308 <= 0 )
    {
      wsprintfW(szBuffer, L"%02.0f%% %s", v345, TreeViewListItemParam_338->szProcessName2);
    }
    else
    {
      wsprintfW(
        szBuffer,
        L"%02.0f%% %s:%d",
        v345,
        TreeViewListItemParam_338->szProcessName2,
        TreeViewListItemParam_338->dwProcessId);
    }
  }
  CGraphData_Update(gpGraphInfoOfCPU, gTimeQuerySystemInfo, *(double *)&ItemWithSizeIs50H.field_0, v337, szBuffer);
  if ( gdwAdapterRuntingTime )
  {
    sub_C238F0(
      gTimeQuerySystemInfo,
      (signed __int64)__PAIR__(v297, v296) / gSystemInfo.dwNumberOfProcessors,
      (int)gpGraphInfoOfGPU,
      (int)TreeViewListItemParam_327,
      dword_CEBA1C,
      gpGraphInfoOfSystemMemory,
      gpGraphInfoOfDedicatedMemory);
    *((float *)&v336 + 1) = v9;
    sub_C6FD50(gpGraphInfoOfGPU, *((float *)&v336 + 1), (int)TreeViewListItemParam_327, v319);
  }
  if ( gIOGraphInfo.pGraphData )
    sub_C244A0(&gIOGraphInfo, gTreeList_Item);
  if ( gNetworkGraphInfo.pGraphData )
    sub_C244A0(&gNetworkGraphInfo, &gTreeList_Item[1]);
  if ( gDiskGraphInfo.pGraphData )
    sub_C244A0(&gDiskGraphInfo, &gTreeList_Item[2]);
  RedrawColumn(1, ghWndTreeListView, IDS_CPU, 0xFFFFFFFE);
  RedrawColumn(1, ghWndTreeListView, IDS_PRIVATE_BYTES, 0xFFFFFFFE);
  RedrawColumn(1, ghWndTreeListView, IDS_WORKING_SET, 0xFFFFFFFE);
  RedrawColumn(1, ghWndTreeListView, IDS_GPU2, 0xFFFFFFFE);
  sub_C6FD50(gpGraphInfoOfCPU, *(double *)&ItemWithSizeIs50H.field_0, (int)TreeViewListItemParam_338, *(double *)&v345);
  sub_C6FCA0(gpGraphInfoOfMemory, *(__int64 *)&v316);
  sub_C70360(gpGraphInfoOfPhysicalMemory, dwUnavailPhys);
  ret = (unsigned __int8)v374;
  if ( flags )
    ret = 1;
  HIDWORD(v336) = ret;
  if ( sdwValueInInitTreeList )
  {
    if ( gdwProcessId_0 == -1 )
    {
      ItemState.stateMask = 3;
      ItemState.state = 3;
      ::SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, 0, (LPARAM)&ItemState);
    }
    else
    {
      item.iItem = 0;
      item.mask = LVIF_PARAM;
      item.iSubItem = 0;
      if ( ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0) > 0 )
      {
        while ( 1 )
        {
          ::SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&item);
          if ( item.lParam->dwProcessId == gdwProcessId_0 )
            break;
          ++item.iItem;
          item.mask = 4;
          item.iSubItem = 0;
          v310 = ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
          if ( item.iItem >= v310 )
            goto LABEL_451;
        }
        ItemState.mask = 3;
        ItemState.state = 3;
        ::SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, item.iItem, (LPARAM)&ItemState);
      }
    }
LABEL_451:
    LOBYTE(ret) = BYTE4(v336);
    sdwValueInInitTreeList = 0;
  }
  return ret;
}
// C6AD00: could not find valid save-restore pair for ebp
// CACDC0: using guessed type double db_onehundred;
// CB44C8: using guessed type wchar_t a0202fS[13];
// CCE100: using guessed type int gdwProcessId_0;
// CD10C8: using guessed type int sdwValueInInitTreeList;
// CD4E54: using guessed type int gdwVersion;
// CDB1BC: using guessed type int gdwProcessIdLast;
// CDF2F4: using guessed type int GetProcessorSystemCycleTime;
// CDF36C: using guessed type int (__stdcall *GetProcessDpiAwareness)(_DWORD, _DWORD);
// CDF374: using guessed type int gnSystemProcessInfoLengthLast;
// CDF378: using guessed type FILETIME gTimeQuerySystemInfoLast;
// CEBA1C: using guessed type int dword_CEBA1C;
// CEBA40: using guessed type __int64 qword_CEBA40;
// CEBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);
// CEBA5C: using guessed type char gbWindowTextFlags;
// CEBC28: using guessed type int gbShowProcessTreeLast;
// CEBC30: using guessed type __int64 qword_CEBC30;

//----- (00C6E3B0) --------------------------------------------------------
HCURSOR __cdecl PE_Save(int bFlags)
{
  DWORD wProcessId; // ebx
  HWND v2; // eax
  HCURSOR result; // eax
  HCURSOR v4; // eax
  HCURSOR v5; // eax
  int dwProcessColumnCount; // ebx
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // edi
  signed int v8; // ecx
  __m128i v9; // xmm1
  int *v10; // edx
  unsigned int v11; // eax
  __m128i v12; // xmm0
  int nIndex; // esi
  const wchar_t *v14; // eax
  int nItemIndex; // esi
  int i; // edi
  int j; // esi
  const wchar_t *v18; // eax
  signed int dwCount; // esi
  signed int dwIdx; // ecx
  __m128i v21; // xmm1
  __m128i *v22; // edx
  unsigned int v23; // eax
  __m128i v24; // xmm0
  signed int k; // edi
  const wchar_t *v26; // eax
  void (__stdcall *SendMessageW_1)(HWND, UINT, WPARAM, LPARAM); // edi
  int nItem; // ebx
  signed int l; // edi
  const wchar_t *v30; // eax
  LVITEMW TextItem; // [esp+4h] [ebp-2684h]
  LVITEMW Item; // [esp+38h] [ebp-2650h]
  struct tagOFNW OpenFileName; // [esp+6Ch] [ebp-261Ch]
  LVCOLUMNW ColumnInfo; // [esp+C4h] [ebp-25C4h]
  LRESULT nItemCount; // [esp+E4h] [ebp-25A4h]
  HCURSOR hCursor; // [esp+E8h] [ebp-25A0h]
  int v37; // [esp+ECh] [ebp-259Ch]
  LRESULT wProcessId_1; // [esp+F0h] [ebp-2598h]
  HWND hWnd; // [esp+F4h] [ebp-2594h]
  FILE *pFile; // [esp+F8h] [ebp-2590h]
  int pIds[96]; // [esp+FCh] [ebp-258Ch]
  __int16 szError[4095]; // [esp+27Ch] [ebp-240Ch]
  __int16 v43; // [esp+227Ah] [ebp-40Eh]
  __int16 szName[256]; // [esp+227Ch] [ebp-40Ch]
  __int16 szFileName[260]; // [esp+247Ch] [ebp-20Ch]

  szFileName[0] = 0;
  memset(&szFileName[1], 0, 0x206u);
  wProcessId = gdwProcessIdSelected;
  wProcessId_1 = gdwProcessIdSelected;
  SystemProcessInfo_GetSystemProcessName(gdwProcessIdSelected, 0, (WCHAR *)szName, 0x100u);
  v2 = ghWndHandlesListCtrl;
  if ( gConfig.bShowDllView )
    v2 = ghWndDllsListCtrl;
  hWnd = v2;
  if ( !bFlags && sdwFlagsInPE_Save )
  {
    wcscpy_s((wchar_t *)szFileName, 0x104u, &sszFileNameInPE_Save);
LABEL_12:
    if ( wProcessId != gdwProcessIdSelected )
      return (HCURSOR)MessageBoxW(ghMainWnd, L"The process has exited", L"Process Explorer", 0x10u);
    if ( _wfopen_s(&pFile, (const wchar_t *)szFileName, L"w, ccs=UTF-8") )
    {
      wsprintfW((wchar_t *)szError, L"Error saving %s", szFileName);
      result = (HCURSOR)ReportMsg((WCHAR *)szError, ghMainWnd);
    }
    else
    {
      v4 = (HCURSOR)shCursorInPE_Save;
      if ( !shCursorInPE_Save )
      {
        v4 = LoadCursorW(shCursorInPE_Save, (LPCWSTR)IDC_WAIT);
        shCursorInPE_Save = (HINSTANCE)v4;
      }
      v5 = SetCursor(v4);
      dwProcessColumnCount = gConfig.dwProcessColumnCount;
      SendMessageW = ::SendMessageW;
      hCursor = v5;
      ColumnInfo.pszText = (LPWSTR)szError;
      ColumnInfo.mask = 4;
      ColumnInfo.cchTextMax = 4096;
      if ( !::SendMessageW(ghWndTreeListView, LVM_GETCOLUMNORDERARRAY, gConfig.dwProcessColumnCount, (LPARAM)pIds) )
      {
        v8 = 0;
        if ( dwProcessColumnCount > 0 )
        {
          if ( (unsigned int)dwProcessColumnCount >= 8 )
          {
            v9 = _mm_load_si128((const __m128i *)&gIntArray);
            v10 = &pIds[4];
            do
            {
              v11 = v8 + 4;
              v10 += 8;
              v12 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v8), 0), v9);
              v8 += 8;
              _mm_storeu_si128((__m128i *)v10 - 3, v12);
              _mm_storeu_si128((__m128i *)v10 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v11), 0), v9));
            }
            while ( v8 < dwProcessColumnCount - dwProcessColumnCount % 8 );
          }
          for ( ; v8 < dwProcessColumnCount; ++v8 )
            pIds[v8] = v8;
        }
      }
      nIndex = 0;
      if ( dwProcessColumnCount > 0 )
      {
        do
        {
          ::SendMessageW(ghWndTreeListView, LVM_GETCOLUMNW, pIds[nIndex], (LPARAM)&ColumnInfo);
          v14 = L"\t";
          if ( nIndex == dwProcessColumnCount - 1 )
            v14 = L"\n";
          fwprintf(pFile, L"%s%s", ColumnInfo.pszText, v14);
          ++nIndex;
        }
        while ( nIndex < dwProcessColumnCount );
        SendMessageW = ::SendMessageW;
      }
      nItemIndex = 0;
      nItemCount = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
      v37 = 0;
      if ( nItemCount > 0 )
      {
        do
        {
          Item.mask = 4;
          szError[0] = 0;
          Item.iSubItem = 0;
          Item.iItem = nItemIndex;
          SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item);
          for ( i = 0; i < dwProcessColumnCount; ++i )
          {
            TextItem.cchTextMax = 4096;

            szError[0] = 0;
            TextItem.iSubItem = pIds[i];
            TextItem.pszText = (LPWSTR)szError;
            ::SendMessageW(ghWndTreeListView, LVM_GETITEMTEXTW, nItemIndex, (LPARAM)&TextItem);
            v43 = 0;
            if ( !i && gConfig.bShowProcessTree )
            {
              for ( j = 0; j < Item.lParam->nSpaceNumber; ++j )
                fwprintf(pFile, L" ");
              nItemIndex = v37;
            }
            v18 = L"\t";
            if ( i == dwProcessColumnCount - 1 )
              v18 = L"\n";
            fwprintf(pFile, L"%s%s", szError, v18);
          }
          SendMessageW = ::SendMessageW;
          v37 = ++nItemIndex;
        }
        while ( nItemIndex < nItemCount );
      }
      fwprintf(pFile, L"\n");
      if ( wProcessId_1 == gdwProcessIdSelected )
      {
        if ( gConfig.bShowLowerPane && (gdwProcessIdSelected & 0x80000000) == 0 )
        {
          fwprintf(pFile, L"Process: %s Pid: %d\n\n", szName, gdwProcessIdSelected);
          dwCount = gConfig.dwHandleColumnCount;
          if ( gConfig.bShowDllView )
            dwCount = gConfig.dwDllColumnCount;
          if ( !SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, dwCount, (LPARAM)pIds) )
          {
            dwIdx = 0;
            if ( dwCount > 0 )
            {
              if ( (unsigned int)dwCount >= 8 )
              {
                v21 = _mm_load_si128((const __m128i *)&gIntArray);
                v22 = (__m128i *)&pIds[4];
                do
                {
                  v23 = dwIdx + 4;
                  v22 += 2;
                  v24 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(dwIdx), 0), v21);
                  dwIdx += 8;
                  _mm_storeu_si128(v22 - 3, v24);
                  _mm_storeu_si128(v22 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v23), 0), v21));
                }
                while ( dwIdx < dwCount - dwCount % 8 );
              }
              for ( ; dwIdx < dwCount; ++dwIdx )
                pIds[dwIdx] = dwIdx;
            }
          }
          for ( k = 0; k < dwCount; ++k )
          {
            ::SendMessageW(hWnd, LVM_GETCOLUMNW, pIds[k], (LPARAM)&ColumnInfo);
            v26 = L"\t";
            if ( k == dwCount - 1 )
              v26 = L"\n";
            fwprintf(pFile, L"%s%s", ColumnInfo.pszText, v26);
          }
          SendMessageW_1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
          nItem = 0;
          wProcessId_1 = ::SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
          if ( wProcessId_1 > 0 )
          {
            do
            {
              Item.mask = LVIF_PARAM;
              szError[0] = 0;
              Item.iSubItem = 0;
              Item.iItem = nItem;
              SendMessageW_1(hWnd, LVM_GETITEMW, 0, (LPARAM)&Item);
              for ( l = 0; l < dwCount; ++l )
              {
                TextItem.cchTextMax = 4096;
                szError[0] = 0;
                TextItem.iSubItem = pIds[l];
                TextItem.pszText = (LPWSTR)szError;
                ::SendMessageW(hWnd, LVM_GETITEMTEXTW, nItem, (LPARAM)&TextItem);
                v43 = 0;
                v30 = L"\t";
                if ( l == dwCount - 1 )
                  v30 = L"\n";
                fwprintf(pFile, L"%s%s", szError, v30);
              }
              SendMessageW_1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
              ++nItem;
            }
            while ( nItem < wProcessId_1 );
          }
        }
      }
      else
      {
        MessageBoxW(ghMainWnd, L"The process has exited", L"Process Explorer", MB_ICONHAND);
      }
      fclose(pFile);
      wcscpy_s(&sszFileNameInPE_Save, 0x104u, (const wchar_t *)szFileName);
      sdwFlagsInPE_Save = 1;
      result = SetCursor(hCursor);
    }
    return result;
  }
  if ( szName[0] == '<' )
    wcscpy_s((wchar_t *)szName, 0x100u, L"Procexp");
  if ( sszFileNameInPE_Save )
    wcscpy_s((wchar_t *)szFileName, 0x104u, &sszFileNameInPE_Save);
  else
    swprintf((wchar_t *)szFileName, L"%s.txt", szName);
  OpenFileName.hwndOwner = ghMainWnd;
  OpenFileName.hInstance = ghInstance;
  OpenFileName.lpstrFile = (LPWSTR)szFileName;
  *(_DWORD *)&OpenFileName.nFileOffset = 0;
  OpenFileName.lpfnHook = 0;
  OpenFileName.lStructSize = 0x4C;
  OpenFileName.lpstrCustomFilter = 0;
  OpenFileName.nMaxCustFilter = 0;
  OpenFileName.nFilterIndex = 1;
  OpenFileName.nMaxFile = 256;
  OpenFileName.lpstrFileTitle = 0;
  OpenFileName.nMaxFileTitle = 0;
  OpenFileName.lpstrInitialDir = 0;
  OpenFileName.Flags = 0x200004;
  OpenFileName.lpstrTitle = L"Save Process Explorer Data...";
  OpenFileName.lpstrDefExt = L"*.txt";
  OpenFileName.lpstrFilter = L"Process Explorer Data (*.TXT)";
  result = (HCURSOR)GetSaveFileNameW(&OpenFileName);
  if ( result )
    goto LABEL_12;
  return result;
}
// CAEA50: using guessed type tagRECT gIntArray;
// CB6A18: using guessed type wchar_t aSaveProcessExp[30];
// CB6A54: using guessed type wchar_t aTxt[6];
// CB6A60: using guessed type wchar_t aProcessExplore_11[30];
// CF54FC: using guessed type int sdwFlagsInPE_Save;

//----- (00C6EB40) --------------------------------------------------------
HCURSOR __cdecl SaveProcessStrings(HWND hWnd, LPCWSTR lpszFileName)
{
  HCURSOR result; // eax
  HCURSOR v3; // eax
  LRESULT nCount; // ebx
  signed int i; // esi
  LVITEMW ItemText; // [esp+8h] [ebp-22D8h]
  LVITEMW Item; // [esp+3Ch] [ebp-22A4h]
  struct tagOFNW OpenFileName; // [esp+70h] [ebp-2270h]
  HWND hWndIn; // [esp+C8h] [ebp-2218h]
  HCURSOR hCursor; // [esp+CCh] [ebp-2214h]
  FILE *pFile; // [esp+D0h] [ebp-2210h]
  WCHAR szBuffer[4096]; // [esp+D4h] [ebp-220Ch]
  WCHAR szFileName[260]; // [esp+20D4h] [ebp-20Ch]

  szFileName[0] = 0;
  hWndIn = hWnd;
  memset(&szFileName[1], 0, 0x206u);
  swprintf(szFileName, L"%s.txt", lpszFileName);
  OpenFileName.hwndOwner = ghMainWnd;
  OpenFileName.hInstance = ghInstance;
  OpenFileName.lpstrFile = szFileName;
  *(_DWORD *)&OpenFileName.nFileOffset = 0;
  OpenFileName.lpfnHook = 0;
  OpenFileName.lStructSize = 76;
  OpenFileName.lpstrCustomFilter = 0;
  OpenFileName.nMaxCustFilter = 0;
  OpenFileName.nFilterIndex = 1;
  OpenFileName.nMaxFile = 256;
  OpenFileName.lpstrFileTitle = 0;
  OpenFileName.nMaxFileTitle = 0;
  OpenFileName.lpstrInitialDir = 0;
  OpenFileName.Flags = 2097156;
  OpenFileName.lpstrTitle = L"Save Process Explorer Strings...";
  OpenFileName.lpstrDefExt = L"*.txt";
  OpenFileName.lpstrFilter = L"Process Explorer Strings (*.TXT)";
  result = (HCURSOR)GetSaveFileNameW(&OpenFileName);
  if ( result )
  {
    if ( _wfopen_s(&pFile, szFileName, L"w, ccs=UTF-8") )
    {
      wsprintfW(szBuffer, L"Error saving %s", szFileName);
      result = (HCURSOR)ReportMsg(szBuffer, ghMainWnd);
    }
    else
    {
      v3 = (HCURSOR)shWaitCursor;
      if ( !shWaitCursor )
      {
        v3 = LoadCursorW(shWaitCursor, (LPCWSTR)IDC_WAIT);
        shWaitCursor = (HINSTANCE)v3;
      }
      hCursor = SetCursor(v3);
      nCount = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
      for ( i = 0; i < nCount; ++i )
      {
        Item.mask = 4;
        szBuffer[0] = 0;
        Item.iSubItem = 0;
        Item.iItem = i;
        SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item);
        ItemText.cchTextMax = 4096;
        szBuffer[0] = 0;
        ItemText.iSubItem = 0;
        ItemText.pszText = szBuffer;
        SendMessageW(hWndIn, LVM_GETITEMTEXTW, i, (LPARAM)&ItemText);
        szBuffer[4095] = 0;
        fwprintf(pFile, L"%s\n", szBuffer);
      }
      fclose(pFile);
      result = SetCursor(hCursor);
    }
  }
  return result;
}
// CB6A54: using guessed type wchar_t aTxt[6];
// CB6B60: using guessed type wchar_t aSaveProcessExp_0[33];
// CB6BA8: using guessed type wchar_t aProcessExplore_12[33];

//----- (00C6EDC0) --------------------------------------------------------
BOOL __stdcall DialogFunc(HWND hDlg, UINT ProcessAffinityMask, WPARAM SystemAffinityMask, LPARAM hProcess)
{
  unsigned int v5; // edi
  signed int v6; // esi
  unsigned int v7; // edi
  signed int v8; // esi
  DWORD v9; // esi
  HWND v10; // eax

  if ( ProcessAffinityMask == 272 )
  {
    ghProcess = (HANDLE)hProcess;
    if ( GetProcessAffinityMask((HANDLE)hProcess, &ProcessAffinityMask, &SystemAffinityMask) )
    {
      v7 = 0;
      v8 = 1;
      do
      {
        if ( v8 & ProcessAffinityMask )
          CheckDlgButton(hDlg, v7 + 2000, 1u);
        ++v7;
        v8 = __ROL4__(v8, 1);
      }
      while ( v7 < 0x3F );
      v9 = 63;
      if ( gSystemInfo.dwNumberOfProcessors <= 0x3F )
      {
        do
        {
          v10 = GetDlgItem(hDlg, v9 + 2000);
          EnableWindow(v10, 0);
          --v9;
        }
        while ( v9 >= gSystemInfo.dwNumberOfProcessors );
      }
      return 1;
    }
    ReportMsg(L"Error retrieving process affinity", hDlg);
    EndDialog(hDlg, 0);
    return 0;
  }
  if ( ProcessAffinityMask != 273 )
    return 0;
  if ( (unsigned __int16)SystemAffinityMask == 1 )
  {
    v5 = 0;
    ProcessAffinityMask = 0;
    v6 = 1;
    do
    {
      if ( IsDlgButtonChecked(hDlg, v5 + 2000) == 1 )
        ProcessAffinityMask |= v6;
      ++v5;
      v6 = __ROL4__(v6, 1);
    }
    while ( v5 < 0x1F );
    if ( !SetProcessAffinityMask(ghProcess, ProcessAffinityMask) )
      ReportMsg(L"Error setting affinity", hDlg);
  }
  else if ( (unsigned __int16)SystemAffinityMask != 2 )
  {
    return 0;
  }
  EndDialog(hDlg, 0);
  return 1;
}

//----- (00C6EF00) --------------------------------------------------------
int __cdecl UpateProirtyMenuItem(HMENU hMenu, int dwProirity)
{
  int result; // eax

  result = dwProirity;
  switch ( dwProirity )
  {
    case 0:
      result = CheckMenuRadioItem(
                 hMenu,
                 IDM_PRIORITY_IDLE,
                 IDM_PROIRITY_REALTIME,
                 IDM_PROCESS_SETPRIORITY_BACKGROUND_FOUR,
                 MF_UNCHECKED);
      break;
    case 1:
    case 2:
    case 3:
    case 4:
      result = CheckMenuRadioItem(hMenu, IDM_PRIORITY_IDLE, IDM_PROIRITY_REALTIME, IDM_PRIORITY_IDLE, MF_UNCHECKED);
      break;
    case 5:
    case 6:
      result = CheckMenuRadioItem(
                 hMenu,
                 IDM_PRIORITY_IDLE,
                 IDM_PROIRITY_REALTIME,
                 IDM_PROCESS_SETPRIORITY_BELOW_NORMAL_SIX,
                 MF_UNCHECKED);
      break;
    case 7:
    case 8:
    case 9:
      result = CheckMenuRadioItem(hMenu, IDM_PRIORITY_IDLE, IDM_PROIRITY_REALTIME, IDM_PRIORITY_NORMAL, MF_UNCHECKED);
      break;
    case 10:
    case 11:
      result = CheckMenuRadioItem(
                 hMenu,
                 IDM_PRIORITY_IDLE,
                 IDM_PROIRITY_REALTIME,
                 IDM_PROCESS_SETPRIORITY_ABOVE_NORMAL_TEN,
                 MF_UNCHECKED);
      break;
    case 12:
    case 13:
    case 14:
    case 15:
      result = CheckMenuRadioItem(hMenu, IDM_PRIORITY_IDLE, IDM_PROIRITY_REALTIME, IDM_PRIORITY_HIGH, MF_UNCHECKED);
      break;
    case 24:
      result = CheckMenuRadioItem(hMenu, IDM_PRIORITY_IDLE, IDM_PROIRITY_REALTIME, IDM_PROIRITY_REALTIME, MF_UNCHECKED);
      break;
    default:
      return result;
  }
  return result;
}

//----- (00C6EFB0) --------------------------------------------------------
int __cdecl sub_C6EFB0(int a1)
{
  int v1; // ebx
  DWORD v3; // eax
  unsigned int v4; // ecx
  int v5; // ecx
  DWORD v6; // edi
  DWORD v7; // edx
  int v8; // ecx
  DWORD v9; // edi
  DWORD v10; // edx

  v1 = pdwValue3;
  if ( a1 > pdwValue3 )
  {
    QueryTagInformationEx((PVOID *)&ppv, 0, &pdwValue3, &pdwValue4);
    v1 = pdwValue3;
    if ( a1 > pdwValue3 )
      return 0;
  }
  if ( gdwVersion < 2 )
    v3 = pdwValue4 + 12 * (a1 - 1);
  else
    v3 = pdwValue4 + 16 * a1 - 16;
  v4 = *(_DWORD *)(v3 + 4);
  if ( v4 <= a1 )
  {
    if ( v4 < a1 )
    {
      v8 = a1 - 1;
      if ( a1 - 1 < v1 )
      {
        v9 = pdwValue4 + 12 * v8;
        v10 = pdwValue4 + 16 * v8;
        do
        {
          v3 = v9;
          if ( gdwVersion >= 2 )
            v3 = v10;
          if ( *(_DWORD *)(v3 + 4) == a1 )
            break;
          ++v8;
          v10 += 16;
          v9 += 12;
        }
        while ( v8 < v1 );
      }
    }
  }
  else
  {
    v5 = a1 - 1;
    if ( a1 - 1 > 0 )
    {
      v6 = pdwValue4 + 12 * v5;
      v7 = pdwValue4 + 16 * v5;
      while ( 1 )
      {
        v3 = v6;
        if ( gdwVersion >= 2 )
          v3 = v7;
        if ( *(_DWORD *)(v3 + 4) == a1 )
          break;
        --v5;
        v7 -= 16;
        v6 -= 12;
        if ( v5 <= 0 )
          return *(_DWORD *)(v3 + 8);
      }
    }
  }
  return *(_DWORD *)(v3 + 8);
}
// CD4E54: using guessed type int gdwVersion;

//----- (00C6F0A0) --------------------------------------------------------
PBOOL __cdecl PE_SuspendProcess(unsigned __int8 bFlags, DWORD dwProcessId, PBOOL pbRet)
{
  PBOOL dwError; // edi
  int i; // esi
  signed int nTry; // eax
  SYSTEM_PROCESS_INFORMATION *v6; // eax
  DWORD v7; // eax
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+Ch] [ebp-4h]

  *pbRet = 0;
  pSystemProcessInfo = 0;
  GetSystemProcessInfo(&pSystemProcessInfo, 0);
  dwError = pbRet;
  for ( i = 0; ; ++i )
  {
    nTry = NtSuspendProcess ? 1 : bFlags + 1;
    if ( i >= nTry )
      break;
    dwError = (PBOOL)ERROR_INVALID_PARAMETER;
    v6 = pSystemProcessInfo;
    if ( pSystemProcessInfo->UniqueProcessId == (HANDLE)dwProcessId )
    {
LABEL_9:
      v7 = PE_SuspendOneProcess(bFlags, v6, i);
      dwError = (PBOOL)v7;
      if ( !v7 || !i && v7 == ERROR_ALREADY_WAITING )
      {
        *pbRet = 1;
        goto LABEL_17;
      }
    }
    else
    {
      while ( v6->NextEntryOffset )
      {
        v6 = (SYSTEM_PROCESS_INFORMATION *)((char *)v6 + v6->NextEntryOffset);
        if ( v6->UniqueProcessId == (HANDLE)dwProcessId )
          goto LABEL_9;
      }
    }
    if ( !*pbRet )
      break;
LABEL_17:
    if ( bFlags )
      Sleep(100u);
  }
  free(pSystemProcessInfo);
  if ( *pbRet )
    dwError = 0;
  return dwError;
}

//----- (00C6F170) --------------------------------------------------------
bool __cdecl LoadDbgHelp(LPCWSTR lpLibFileName)
{
  HMODULE v1; // esi
  FARPROC v2; // eax
  int (__stdcall *v3)(HANDLE, HANDLE, PCWSTR, PCWSTR, DWORD64, DWORD, PMODLOAD_DATA, DWORD); // ecx
  int (__stdcall *v4)(HANDLE, PCSTR, BOOL); // eax
  bool v5; // zf

  v1 = LoadLibraryW(lpLibFileName);
  SymInitialize = (int (__stdcall *)(HANDLE, PCSTR, BOOL))GetProcAddress(v1, "SymInitialize");
  *(_DWORD *)EnumerateLoadedModulesW64 = GetProcAddress(v1, "EnumerateLoadedModulesW64");
  *(_DWORD *)SymRegisterCallback64 = GetProcAddress(v1, "SymRegisterCallback64");
  *(_DWORD *)SymGetModuleInfoW64 = GetProcAddress(v1, "SymGetModuleInfoW64");
  SymCleanup = (int (__stdcall *)(HANDLE))GetProcAddress(v1, "SymCleanup");
  *(_DWORD *)SymFromAddrW = GetProcAddress(v1, "SymFromAddrW");
  SymGetSymFromName = (int (__cdecl *)(HANDLE, PCSTR, PIMAGEHLP_SYMBOL))GetProcAddress(v1, "SymGetSymFromName");
  MiniDumpWriteDump = (int (__stdcall *)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION))GetProcAddress(v1, "MiniDumpWriteDump");
  SymSetOptions = (int (__stdcall *)(DWORD))GetProcAddress(v1, "SymSetOptions");
  *(_DWORD *)SymGetOptions = GetProcAddress(v1, "SymGetOptions");
  *(_DWORD *)SymLoadModuleExW = GetProcAddress(v1, "SymLoadModuleExW");
  if ( *(_DWORD *)SymLoadModuleExW )
  {
    SymLoadModuleExW_1 = (int (__stdcall *)(HANDLE, HANDLE, PCWSTR, PCWSTR, DWORD64, DWORD, PMODLOAD_DATA, DWORD))SymLoadModuleExW_0;
  }
  else
  {
    v2 = GetProcAddress(v1, "SymLoadModule64");
    v3 = 0;
    *(_DWORD *)SymLoadModule64 = v2;
    if ( v2 )
      v3 = (int (__stdcall *)(HANDLE, HANDLE, PCWSTR, PCWSTR, DWORD64, DWORD, PMODLOAD_DATA, DWORD))sub_C608E0;
    SymLoadModuleExW_1 = v3;
  }
  *(_DWORD *)SymUnloadModule64 = GetProcAddress(v1, "SymUnloadModule64");
  *(_DWORD *)ImageNtHeader = GetProcAddress(v1, "ImageNtHeader");
  *(_DWORD *)StackWalk64 = GetProcAddress(v1, "StackWalk64");
  *(_DWORD *)SymGetModuleBase64 = GetProcAddress(v1, "SymGetModuleBase64");
  *(_DWORD *)SymFunctionTableAccess64 = GetProcAddress(v1, "SymFunctionTableAccess64");
  if ( LOBYTE(gConfig.bSymbolWarningShown) )
    goto LABEL_9;
  v4 = SymInitialize;
  v5 = SymInitialize == 0;
  if ( SymInitialize )
  {
    if ( !gConfig.strNtSymbolPath[0] )
    {
LABEL_10:
      v5 = v4 == 0;
      return !v5;
    }
LABEL_9:
    SetEnvironmentVariableW(L"_NT_SYMBOL_PATH", gConfig.strNtSymbolPath);
    v4 = SymInitialize;
    goto LABEL_10;
  }
  return !v5;
}

//----- (00C6F2C0) --------------------------------------------------------
BOOL __stdcall SysinfoPropSheet(HWND hDlg, UINT uMsg, WPARAM wParamIn, LPARAM lParamIn)
{
  HWND v4; // eax
  LRESULT v5; // ST14_4
  HWND v6; // eax
  int v7; // eax
  HWND v8; // eax
  CResizer *v9; // eax
  CResizer *v10; // esi
  HWND v11; // eax
  char v12; // al
  const wchar_t *TemplateName1; // ecx
  const wchar_t *v14; // eax
  bool v15; // zf
  const wchar_t *v16; // ecx
  const wchar_t *v17; // eax
  HWND v18; // eax
  HWND v19; // ebx
  LONG v20; // eax
  LONG v21; // eax
  HWND hWndTab_1; // edi
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ecx
  const WCHAR **v24; // ebx
  WPARAM nTab; // edx
  LPARAM v26; // eax
  const WCHAR *v27; // esi
  WCHAR *v28; // eax
  HWND v29; // edi
  HWND v30; // ebx
  HWND v32; // eax
  signed int v33; // esi
  HWND v34; // eax
  HWND v35; // eax
  LRESULT nTabCount; // esi
  HWND v37; // eax
  LRESULT nCurTab; // edi
  HWND hWndTab; // eax
  HWND v40; // eax
  HWND v41; // eax
  NMHDR nmhdr; // [esp+Ch] [ebp-98h]
  HWND hWnd; // [esp+18h] [ebp-8Ch]
  TCITEMW Item; // [esp+1Ch] [ebp-88h]
  WPARAM wParam; // [esp+38h] [ebp-6Ch]
  HWND hDlg_1; // [esp+3Ch] [ebp-68h]
  LPARAM lParam_1; // [esp+40h] [ebp-64h]
  struct tagRECT Rect; // [esp+44h] [ebp-60h]
  struct tagRECT rcTab; // [esp+54h] [ebp-50h]
  SYSINFOPAGEITEM Pages[5]; // [esp+64h] [ebp-40h]

  lParam_1 = lParamIn;
  hDlg_1 = hDlg;
  if ( uMsg > WM_INITDIALOG )
  {
    if ( uMsg == WM_COMMAND )
    {
      if ( (unsigned __int16)wParamIn > (signed int)IDM_VIEW_REFRESH_NOW )
      {
        switch ( (unsigned __int16)wParamIn )
        {
          case 40018u:
          case 40019u:
          case 40020u:
          case 40021u:
          case 40022u:
          case 40023u:
            PostMessageW(ghMainWnd, WM_COMMAND, wParamIn, lParamIn);
            break;
          case 40092u:
          case 40093u:
            v35 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
            nTabCount = ::SendMessageW(v35, TCM_GETITEMCOUNT, 0, 0);
            v37 = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            nCurTab = ::SendMessageW(v37, TCM_GETCURSEL, 0, 0);
            hWndTab = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            ::SendMessageW(
              hWndTab,
              TCM_SETCURSEL,
              (nTabCount + nCurTab + 2 * ((_WORD)wParamIn == 40092) - 1) % nTabCount,
              0);
            Item.mask = TCIF_PARAM;
            Item.lParam = 0;
            v40 = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            ::SendMessageW(v40, TCM_GETITEMW, nCurTab, (LPARAM)&Item);
            ShowWindow((HWND)Item.lParam, 0);
            v41 = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            ::SendMessageW(
              v41,
              TCM_GETITEMW,
              (nTabCount + nCurTab + 2 * ((_WORD)wParamIn == 40092) - 1) % nTabCount,
              (LPARAM)&Item);
            ShowWindow((HWND)Item.lParam, SW_SHOW);
            break;
          default:
            return 0;
        }
      }
      else if ( (unsigned __int16)wParamIn == IDM_VIEW_REFRESH_NOW )
      {
        SetEvent(ghRefreshEventHandle);
      }
      else if ( (signed int)(unsigned __int16)wParamIn > 0
             && ((signed int)(unsigned __int16)wParamIn <= 2 || (unsigned __int16)wParamIn == IDM_FILE_EXIT) )
      {
        ::SendMessageW(hDlg, WM_CLOSE, 0, 0);
      }
    }
    else if ( uMsg == WM_TIMER )
    {
      v32 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      v33 = 0;
      lParam_1 = ::SendMessageW(v32, TCM_GETITEMCOUNT, 0, 0);
      if ( lParam_1 > 0 )
      {
        do
        {
          Item.mask = TCIF_PARAM;
          Item.lParam = 0;
          v34 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
          ::SendMessageW(v34, TCM_GETITEMW, v33, (LPARAM)&Item);
          ::SendMessageW((HWND)Item.lParam, WM_TIMER, 0, 0);
          ++v33;
        }
        while ( v33 < lParam_1 );
      }
    }
    return 0;
  }
  if ( uMsg != WM_INITDIALOG )
  {
    if ( uMsg == WM_DESTROY )
    {
      GetWindowPlacement(hDlg, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[6] + 8));
      v8 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      gConfig.dwDefaultSysInfoPage = ::SendMessageW(v8, TCM_GETCURSEL, 0, 0);
      EnterCriticalSection(&gSysInfoPropSheetLock);
      ghWndSysinfoPropSheet = 0;
      LeaveCriticalSection(&gSysInfoPropSheetLock);
      _endthread();
    }
    if ( uMsg == WM_CLOSE )
    {
      DestroyWindow(hDlg);
    }
    else if ( uMsg == WM_NOTIFY && (unsigned int)(*(_DWORD *)(lParamIn + 8) + 552) <= 1 )
    {
      v4 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      Item.mask = 8;
      v5 = ::SendMessageW(v4, TCM_GETCURSEL, 0, 0);
      Item.lParam = 0;
      v6 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      ::SendMessageW(v6, TCM_GETITEMW, v5, (LPARAM)&Item);
      v7 = 0;
      if ( *(_DWORD *)(lParam_1 + 8) == -551 )
        v7 = 5;
      ShowWindow((HWND)Item.lParam, v7);
    }
    return 0;
  }
  v9 = (CResizer *)operator new(0x40u);
  if ( v9 )
    CResizer::CResizer(v9, hDlg);
  v10 = (CResizer *)operator new(0x40u);
  if ( v10 )
  {
    v11 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
    CResizer::CResizer(v10, v11);
  }
  Pages[0].szText = (int)L"Summary";
  Pages[0].DlgProc = (int)PropSummary;
  v12 = IsBuiltinAdministrative();
  Pages[1].szText = (int)L"CPU";
  Pages[1].DlgProc = (int)PropSystemInfoSumETW;
  TemplateName1 = L"SYSTEMINFOSUMETW";
  Pages[1].szTemplateName = (int)L"SYSTEMINFOCPU";
  if ( !v12 )
    TemplateName1 = L"SYSTEMINFOSUM";
  Pages[2].szText = (int)L"Memory";
  v14 = L"SYSTEMINFOMEM";
  Pages[0].szTemplateName = (int)TemplateName1;
  if ( gdwVersion < 1 )
    v14 = L"SYSTEMINFOMEMXP";
  Pages[2].DlgProc = (int)PropSystemInfoMem;
  Pages[2].szTemplateName = (int)v14;
  Pages[3].szText = (int)L"I/O";
  Pages[3].DlgProc = (int)PropSystemInfoIO;
  v15 = IsBuiltinAdministrative() == 0;
  Pages[4].szText = (int)L"GPU";
  Pages[4].DlgProc = (int)PropSystemInfoGPU;
  v16 = L"SYSTEMINFOIOETW";
  v17 = L"SYSTEMINFOGPU";
  if ( v15 )
    v16 = L"SYSTEMINFOIO";
  Pages[3].szTemplateName = (int)v16;
  if ( gdwAdapterRuntingTime <= 0 )
    v17 = 0;
  Pages[4].szTemplateName = (int)v17;
  v18 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
  v19 = v18;
  hWnd = v18;
  v20 = GetWindowLongW(v18, -20);
  SetWindowLongW(v19, -20, v20 | 0x10000);
  v21 = GetWindowLongW(v19, -16);
  hWndTab_1 = v19;
  SetWindowLongW(v19, -16, v21 | 0x2000000);
  SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
  v24 = (const WCHAR **)&Pages[0].szTemplateName;
  nTab = 0;
  v26 = 5;
  wParam = 0;
  lParam_1 = 5;
  do
  {
    v27 = *v24;
    if ( *v24 )
    {
      v28 = (WCHAR *)*(v24 - 2);
      _mm_storeu_si128((__m128i *)&Item.dwState, (__m128i)0i64);
      Item.pszText = v28;
      *(_QWORD *)&Item.iImage = 0i64;
      Item.mask = 1;
      SendMessageW(hWndTab_1, TCM_INSERTITEMW, nTab, (LPARAM)&Item);
      GetClientRect(hWndTab_1, &rcTab);
      ::SendMessageW(hWndTab_1, TCM_ADJUSTRECT, 0, (LPARAM)&rcTab);
      v29 = CreateDialogParamW(ghInstance, v27, hWndTab_1, (DLGPROC)*(v24 - 1), 0);
      MoveWindow(v29, rcTab.left, rcTab.top, rcTab.right - rcTab.left, rcTab.bottom - rcTab.top, 1);
      ShowWindow(v29, 0);
      Item.lParam = (LPARAM)v29;
      hWndTab_1 = hWnd;
      Item.mask = TCIF_PARAM;
      ::SendMessageW(hWnd, TCM_SETITEMW, wParam, (LPARAM)&Item);
      v26 = lParam_1;
      nTab = wParam + 1;
      SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
      ++wParam;
    }
    v24 += 3;
    lParam_1 = --v26;
  }
  while ( v26 );
  SendMessageW(hWndTab_1, TCM_SETCURSEL, gConfig.dwDefaultSysInfoPage, 0);
  v30 = hDlg_1;
  nmhdr.idFrom = IDC_SYSINFO_PROPSHEET_TAB;
  nmhdr.code = TCN_SELCHANGE;
  ::SendMessageW(hDlg_1, WM_NOTIFY, 0, (LPARAM)&nmhdr);
  if ( gConfig.WindowPlacement[7].ptMinPosition.y )
    _mm_storeu_si128((__m128i *)&Rect, _mm_loadu_si128((const __m128i *)&gConfig.WindowPlacement[7].showCmd));
  else
    GetWindowRect(v30, &Rect);
  gConfig.WindowPlacement[6].ptMinPosition.y = 5;
  SetWindowPlacement(v30, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[6] + 8));
  if ( gConfig.bAlwaysOntop )
    SetWindowPos(v30, HWND_MESSAGE|0x2, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
  return 1;
}
// C7A009: using guessed type int _endthread(void);
// CB67DC: using guessed type wchar_t aSummary[8];
// CB67EC: using guessed type wchar_t aSysteminfosume[17];
// CB6810: using guessed type wchar_t aSysteminfosum[14];
// CB682C: using guessed type wchar_t aCpu_0[4];
// CB6834: using guessed type wchar_t aSysteminfocpu[14];
// CB6850: using guessed type wchar_t aMemory[7];
// CB6860: using guessed type wchar_t aSysteminfomem[14];
// CB687C: using guessed type wchar_t aSysteminfomemx[16];
// CB689C: using guessed type wchar_t aIO_0[4];
// CB68A4: using guessed type wchar_t aSysteminfoioet[16];
// CB68C4: using guessed type wchar_t aSysteminfoio[13];
// CB68E0: using guessed type wchar_t aGpu_0[4];
// CB68E8: using guessed type wchar_t aSysteminfogpu[14];
// CD4E54: using guessed type int gdwVersion;

//----- (00C6F8F0) --------------------------------------------------------
bool __cdecl sub_C6F8F0(double a1, double *a2)
{
  bool result; // al

  result = a1 != *a2;
  *a2 = a1;
  return result;
}

//----- (00C6F920) --------------------------------------------------------
char __cdecl sub_C6F920(int a1, int a2, _DWORD *a3)
{
  char result; // al

  if ( a1 != *a3 || a2 != a3[1] )
  {
    *a3 = a1;
    a3[1] = a2;
    result = 1;
  }
  else
  {
    *a3 = a1;
    a3[1] = a2;
    result = 0;
  }
  return result;
}

//----- (00C6F950) --------------------------------------------------------
void __cdecl VerifyImageThreadProc(tagTREEVIEWLISTITEMPARAM *pItemParam)
{
  VerifyImage(pItemParam, 1);
  if ( pItemParam->nListType )
    DLLLISTITEMPARAM_Release(pItemParam);
  else
    TreeViewListItemParam_Release(pItemParam);
}

//----- (00C6F980) --------------------------------------------------------
int __thiscall ATL::CComCriticalSection::Init(LPCRITICAL_SECTION lpCriticalSection)
{
  int result; // eax

  if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection, 0) )
    return 0;
  result = GetLastError();
  if ( result > 0 )
    result = (unsigned __int16)result | 0x80070000;
  return result;
}

//----- (00C6F9B0) --------------------------------------------------------
int sub_C6F9B0(wchar_t *DstBuf, size_t MaxCount, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+14h] [ebp+14h]

  va_start(ArgList, Format);
  return _vsnwprintf_s(DstBuf, 0x100u, MaxCount, Format, ArgList);
}

//----- (00C6F9D0) --------------------------------------------------------
LRESULT __cdecl CMainWnd::InitStatusBar(HWND hWnd)
{
  HWND v1; // edx
  WPARAM wParam; // ecx
  signed int dwMaxCount; // edi
  signed int dwFlags; // esi
  int v5; // eax
  int nID[32]; // [esp+10h] [ebp-84h]

  v1 = hWnd;
  wParam = 0;
  dwMaxCount = 32;
  gnStatusBarItemCount = 0;
  dwFlags = 1;
  do
  {
    if ( dwFlags & gConfig.dwStatusBarColumns )
    {
      nID[wParam] = 10 * (wParam + 1);
      SendMessageW(v1, SB_SETTEXTW, wParam, (LPARAM)gszStatusBarText);
      v1 = hWnd;
      wParam = gnStatusBarItemCount++ + 1;
    }
    dwFlags = __ROL4__(dwFlags, 1);
    --dwMaxCount;
  }
  while ( dwMaxCount );
  SendMessageW(v1, SB_SETTEXTW, wParam, (LPARAM)gszStatusBarText);
  v5 = gnStatusBarItemCount;
  nID[gnStatusBarItemCount] = -1;
  gnStatusBarItemCount = v5 + 1;
  return SendMessageW(ghWndStatusBar, SB_SETPARTS, v5 + 1, (LPARAM)nID);
}
// CF5720: using guessed type int gnStatusBarItemCount;
// C6F9D0: using guessed type LPARAM nID[32];

//----- (00C6FA90) --------------------------------------------------------
int __cdecl CMainWnd::HandleTTNGetDispInfo(WPARAM wParam, void *pItem)
{
  unsigned int uMenuID; // eax
  __int16 Buffer[1024]; // [esp+4h] [ebp-804h]

  uMenuID = *((_DWORD *)pItem + 1);
  if ( uMenuID <= IDM_VIEW_PROCESS_PROPERTIES )
  {
    if ( uMenuID == IDM_VIEW_PROCESS_PROPERTIES )
    {
      LoadStringW(ghInstance, IDS_PROPERTIES, (LPWSTR)Buffer, 1024);
    }
    else
    {
      switch ( uMenuID )
      {
        case IDM_VIEW_REFRESH_NOW:
          LoadStringW(ghInstance, IDS_REFRESH_NOW, (LPWSTR)Buffer, 1024);
          break;
        case IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS:
          LoadStringW(ghInstance, IDS_SHOW_UNNAMED_OBJECTS, (LPWSTR)Buffer, 1024);
          break;
        case IDC_DLG_DLLSTRINGS_BUTTON_SAVE:
          LoadStringW(ghInstance, IDS_SAVE, (LPWSTR)Buffer, 1024);
          break;
        case IDM_PROCESS_KILL_PROCESS:
          LoadStringW(ghInstance, IDS_KILL_PROCESS_CLOSE_HANDLE, (LPWSTR)Buffer, 1024);
          break;
        case IDM_POPUP_DLL_PROPERTIES:
          if ( gConfig.bShowDllView )
            LoadStringW(ghInstance, IDS_VIEW_HANDLES, (LPWSTR)Buffer, 1024);
          else
            LoadStringW(ghInstance, IDS_VIEW_DLLS, (LPWSTR)Buffer, 1024);
          break;
        case IDM_VIEW_SHOW_PROCESS_TREE:
          LoadStringW(ghInstance, IDS_SHOW_PROCESS_TREE, (LPWSTR)Buffer, 1024);
          break;
        case IDM_VIEW_SHOW_LOWER_PANE:
          if ( gConfig.bShowLowerPane )
            LoadStringW(ghInstance, IDS_HIDE_LOWER_PANE, (LPWSTR)Buffer, 1024);
          else
            LoadStringW(ghInstance, IDS_SHOW_LOWER_PANE, (LPWSTR)Buffer, 1024);
          break;
        case IDM_TRAYMENU_CONTEXT_SYSTEM_INFORMATION:
          LoadStringW(ghInstance, IDS_SYSTEM_INFORMATION, (LPWSTR)Buffer, 1024);
          break;
        case IDM_FIND_HANDLE_OR_DLL:
          LoadStringW(ghInstance, IDS_FIND_HANDLE_, (LPWSTR)Buffer, 1024);
          break;
        case IDM_SEARCH_IN_PROCESS:
          LoadStringW(ghInstance, IDS_FIND_HANDLE_OR_DLL_, (LPWSTR)Buffer, 1024);
          break;
        case IDM_FIND_PROCESS_BY_WINDOW:
          LoadStringW(ghInstance, IDS_FIND_WINDOW_PROCESS, (LPWSTR)Buffer, 1024);
          break;
        default:
          break;
      }
    }
  }
  *((_DWORD *)pItem + 3) = Buffer;
  return 0;
}

//----- (00C6FCA0) --------------------------------------------------------
void __cdecl sub_C6FCA0(CGraphData *pGraphData, __int64 a2)
{
  bool v2; // zf
  HICON v3; // esi
  int v4; // [esp+Ch] [ebp-21Ch]
  wchar_t Src; // [esp+1Ch] [ebp-20Ch]

  v2 = dword_CDA3C4 == 0;
  _mm_storeu_si128((__m128i *)&v4, _mm_load_si128((const __m128i *)&xmmword_CB7010));
  if ( !v2 )
  {
    sub_C22410(&Src, 0x104u, (int)L"Current Commit: ", a2);
    v3 = GraphData_DrawChart(pGraphData, 0, (#153 *)&v4, gConfig.ColorGraphBk, 0, 0.0);
    sub_C36910((int)ghMainWnd, dword_CDA3C4, (int)v3, &Src);
    DestroyIcon(v3);
  }
}
// CB6CEC: using guessed type wchar_t aCurrentCommit[17];
// CB7010: using guessed type __int128 xmmword_CB7010;

//----- (00C6FD50) --------------------------------------------------------
char __cdecl sub_C6FD50(CGraphData *pGraphData, double a2, int a3, double a4)
{
  int v4; // eax
  CGraphData *v5; // edi
  bool v6; // zf
  double v7; // xmm0_8
  signed int v8; // ebx
  HICON v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  HICON v12; // esi
  ICONINFO piconinfo; // [esp+14h] [ebp-234h]
  CGraphData *v15; // [esp+28h] [ebp-220h]
  int v16; // [esp+2Ch] [ebp-21Ch]
  int v17; // [esp+30h] [ebp-218h]
  __int16 Dst[260]; // [esp+3Ch] [ebp-20Ch]

  LOBYTE(v4) = dword_CF5738;
  v5 = pGraphData;
  v15 = pGraphData;
  if ( !(dword_CF5738 & 1) )
  {
    dword_CF5728 = 0;
    dword_CF5738 |= 1u;
    dword_CF572C = 0;
    hdc = 0;
    dword_CF5724 = 0;
    LOBYTE(v4) = atexit(sub_C9ADC0);
  }
  v6 = byte_CF573C == 0;
  _mm_storeu_si128((__m128i *)&v16, _mm_load_si128((const __m128i *)&xmmword_CB7010));
  if ( v6 )
  {
    byte_CF573C = 1;
    LOBYTE(v4) = BitmapItem_Create((BitmapItem *)&dword_CF5724, 16, 16);
  }
  if ( dword_CDA3BC || dword_CDA3C0 )
  {
    v7 = a2;
    if ( a2 > 100.0 )
    {
      v7 = db_onehundred;
      a2 = db_onehundred;
    }
    if ( pGraphData->m_nItemID )
      v4 = swprintf((wchar_t *)Dst, L"GPU Usage: %.0f%%", LODWORD(v7), HIDWORD(v7));
    else
      v4 = swprintf((wchar_t *)Dst, L"CPU Usage: %.0f%%", LODWORD(v7), HIDWORD(v7));
    if ( a3 && a4 > 0.5 )
      LOBYTE(v4) = swprintf_s((wchar_t *)&Dst[v4], 260 - v4, L"%c%s: %.0f%%", 10, *(_DWORD *)(a3 + 60), a4);
    v8 = (signed int)(a2 / 100.0 * 16.0);
    if ( gConfig.bTrayCPUHistory )
    {
      v9 = GraphData_DrawChart(pGraphData, 0, (#153 *)&v16, 0xFFFFFFFF, 0, 0.0);
    }
    else
    {
      if ( a2 == -1.0 )
      {
        v8 = dword_CF5740;
      }
      else if ( v8 == dword_CF5740 )
      {
        return v4;
      }
      v10 = dword_CF5728 * dword_CF572C;
      if ( dword_CF5734 && v10 )
      {
        memset32(
          (void *)dword_CF5734,
          (unsigned __int16)(gConfig.ColorGraphBk & 0xFF00) | (LOBYTE(gConfig.ColorGraphBk) << 16) | (gConfig.ColorGraphBk >> 16) & 0xFF,
          v10);
        v5 = v15;
      }
      v17 = 16 - v8;
      if ( a2 <= 90.0 )
      {
        v11 = 4652870;
        if ( a2 > 70.0 )
          v11 = 10551295;
      }
      else
      {
        v11 = 4605695;
      }
      BitmapItem_SetRectColor((BitmapItem *)&dword_CF5724, (#153 *)&v16, v11);
      piconinfo.hbmColor = (HBITMAP)dword_CF5724;
      piconinfo.hbmMask = (HBITMAP)dword_CF5724;
      piconinfo.fIcon = 1;
      piconinfo.xHotspot = 0;
      piconinfo.yHotspot = 0;
      v9 = CreateIconIndirect(&piconinfo);
    }
    v12 = v9;
    if ( v5->m_nItemID )
      sub_C36910((int)ghMainWnd, dword_CDA3C0, (int)v9, (wchar_t *)Dst);
    else
      sub_C36910((int)ghMainWnd, dword_CDA3BC, (int)v9, (wchar_t *)Dst);
    LOBYTE(v4) = DestroyIcon(v12);
    dword_CF5740 = v8;
  }
  return v4;
}
// CACDC0: using guessed type double db_onehundred;
// CB6C80: using guessed type wchar_t aCpuUsage0f[18];
// CB7010: using guessed type __int128 xmmword_CB7010;
// CDA3BC: using guessed type int dword_CDA3BC;
// CF5728: using guessed type int dword_CF5728;
// CF572C: using guessed type int dword_CF572C;
// CF5734: using guessed type int dword_CF5734;
// CF5738: using guessed type int dword_CF5738;
// CF573C: using guessed type char byte_CF573C;
// CF5740: using guessed type int dword_CF5740;
// C6FD50: using guessed type wchar_t Dst[260];

//----- (00C70010) --------------------------------------------------------
CGraphData *__cdecl sub_C70010(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // ebx
  HICON v8; // esi
  int v9; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_CDA3F4 == 0;
  result = a1;
  _mm_storeu_si128((__m128i *)&v9, _mm_load_si128((const __m128i *)&xmmword_CB7010));
  if ( !v5 )
  {
    v7 = swprintf((wchar_t *)Dst, L"Disk\n");
    if ( a2 )
    {
      PE_FormatDouble(1, (wchar_t *)&Dst[v7], 260 - v7, *(long double *)&a4, *(long double *)&a3, *(long double *)&a5);
      if ( v7 >= 0 )
        swprintf_s((wchar_t *)&Dst[v7], 260 - v7, L"\n%s", *(_DWORD *)(a2 + 60));
    }
    v8 = GraphData_DrawChart(a1, 0, (#153 *)&v9, gConfig.ColorGraphBk, 0, 0.0);
    sub_C36910((int)ghMainWnd, dword_CDA3F4, (int)v8, (wchar_t *)Dst);
    result = (CGraphData *)DestroyIcon(v8);
  }
  return result;
}
// CB7010: using guessed type __int128 xmmword_CB7010;
// C70010: using guessed type wchar_t Dst[260];

//----- (00C70130) --------------------------------------------------------
CGraphData *__cdecl sub_C70130(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // eax
  int v8; // esi
  HICON v9; // esi
  int v10; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_CDA3C8 == 0;
  result = a1;
  _mm_storeu_si128((__m128i *)&v10, _mm_load_si128((const __m128i *)&xmmword_CB7010));
  if ( !v5 )
  {
    v7 = swprintf((wchar_t *)Dst, L"I/O\n");
    if ( a2 )
    {
      v8 = PE_FormatDouble(
             1,
             (wchar_t *)&Dst[v7],
             260 - v7,
             *(long double *)&a4,
             *(long double *)&a3,
             *(long double *)&a5)
         + v7;
      if ( v8 >= 0 )
        swprintf_s((wchar_t *)&Dst[v8], 260 - v8, L"\n%s", *(_DWORD *)(a2 + 60));
    }
    v9 = GraphData_DrawChart(a1, 0, (#153 *)&v10, gConfig.ColorGraphBk, 0, 0.0);
    sub_C36910((int)ghMainWnd, dword_CDA3C8, (int)v9, (wchar_t *)Dst);
    result = (CGraphData *)DestroyIcon(v9);
  }
  return result;
}
// CB7010: using guessed type __int128 xmmword_CB7010;
// C70130: using guessed type wchar_t Dst[260];

//----- (00C70250) --------------------------------------------------------
CGraphData *__cdecl sub_C70250(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // eax
  wchar_t *v8; // esi
  size_t v9; // edi
  HICON v10; // esi
  int v11; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_CDA600 == 0;
  result = a1;
  _mm_storeu_si128((__m128i *)&v11, _mm_load_si128((const __m128i *)&xmmword_CB7010));
  if ( !v5 )
  {
    v7 = swprintf((wchar_t *)Dst, L"Network\n");
    if ( a2 )
    {
      v8 = (wchar_t *)&Dst[v7];
      v9 = 260 - v7;
      PE_FormatDouble(1, (wchar_t *)&Dst[v7], 260 - v7, *(long double *)&a4, *(long double *)&a3, *(long double *)&a5);
      swprintf_s(v8, v9, L"\n%s", *(_DWORD *)(a2 + 60));
    }
    v10 = GraphData_DrawChart(a1, 0, (#153 *)&v11, gConfig.ColorGraphBk, 0, 0.0);
    sub_C36910((int)ghMainWnd, dword_CDA600, (int)v10, (wchar_t *)Dst);
    result = (CGraphData *)DestroyIcon(v10);
  }
  return result;
}
// CB7010: using guessed type __int128 xmmword_CB7010;
// C70250: using guessed type wchar_t Dst[260];

//----- (00C70360) --------------------------------------------------------
void __cdecl sub_C70360(CGraphData *pGraphData, __int64 a2)
{
  bool v2; // zf
  HICON v3; // esi
  int v4; // [esp+Ch] [ebp-21Ch]
  wchar_t Src; // [esp+1Ch] [ebp-20Ch]

  v2 = dword_CDA3F0 == 0;
  _mm_storeu_si128((__m128i *)&v4, _mm_load_si128((const __m128i *)&xmmword_CB7010));
  if ( !v2 )
  {
    sub_C22410(&Src, 0x104u, (int)L"Physical Usage: ", a2);
    v3 = GraphData_DrawChart(pGraphData, 0, (#153 *)&v4, gConfig.ColorGraphBk, 0, 0.0);
    sub_C36910((int)ghMainWnd, dword_CDA3F0, (int)v3, &Src);
    DestroyIcon(v3);
  }
}
// CB6D10: using guessed type wchar_t aPhysicalUsage[17];
// CB7010: using guessed type __int128 xmmword_CB7010;

//----- (00C70410) --------------------------------------------------------
double *__usercall sub_C70410@<eax>(double a1@<st0>, double st6_0@<st1>, double st5_0@<st2>, double st4_0@<st3>, double st3_0@<st4>, double a6@<st5>, double a7@<st6>, HWND a2, tagPEStatusBarItem *a3, double *a4, double *a5)
{
  double v11; // st0
  double *result; // eax
  WPARAM v13; // edi
  HDC v14; // esi
  void *v15; // eax
  signed int v16; // esi
  signed int v17; // edx
  DWORD v18; // eax
  double v19; // xmm0_8
  char v20; // al
  double v21; // xmm0_8
  int v22; // esi
  HDC v23; // ST04_4
  int v24; // eax
  int v25; // ecx
  HDC v26; // ebx
  struct _FILETIME LocalFileTime; // [esp+14h] [ebp-2CCh]
  double pdbMemorySize; // [esp+1Ch] [ebp-2C4h]
  HGDIOBJ h; // [esp+24h] [ebp-2BCh]
  int v30; // [esp+28h] [ebp-2B8h]
  int v31; // [esp+2Ch] [ebp-2B4h]
  HWND hWnd; // [esp+30h] [ebp-2B0h]
  HDC hdc; // [esp+34h] [ebp-2ACh]
  char v34; // [esp+3Bh] [ebp-2A5h]
  struct _SYSTEMTIME SystemTime; // [esp+3Ch] [ebp-2A4h]
  struct tagRECT rc; // [esp+4Ch] [ebp-294h]
  int lParam[32]; // [esp+5Ch] [ebp-284h]
  __int16 chText[256]; // [esp+DCh] [ebp-204h]

  result = a4;
  v13 = 0;
  hWnd = a2;
  v34 = 0;
  if ( !a2 )
  {
    dword_CD10E8 = -1;
    dword_CD10EC = -1;
    dword_CD10F0 = -1;
    dword_CD10F4 = -1;
    dword_CD10F8 = -1;
    dword_CD10FC = -1;
    dword_CD1100 = -1;
    dword_CD1104 = -1;
    dbl_CD1110 = dbValue3;
    dbl_CD1108 = dbValue3;
    dbl_CD1118 = dbValue3;
    return result;
  }
  PE_QueryMemoryInfo(0i64, a4, (DWORD)a5, &pdbMemorySize);
  a3->double10 = v11;
  a3->dbPhysicalUsage = *a5 / pdbMemorySize * 100.0;
  v14 = GetDC(ghWndStatusBar);
  hdc = v14;
  v15 = (void *)SendMessageW(hWnd, WM_GETFONT, 0, 0);
  h = SelectObject(v14, v15);
  SendMessageW(ghWndStatusBar, SB_GETPARTS, 0x20u, (LPARAM)lParam);
  v16 = 1;
  v17 = 32;
  v30 = 1;
  v31 = 32;
  do
  {
    v18 = gConfig.dwStatusBarColumns & v16;
    if ( gConfig.dwStatusBarColumns & v16 )
    {
      if ( v18 > 0x80 )
      {
        if ( v18 > 0x800 )
        {
          switch ( v18 )
          {
            case MEM_COMMIT:
              v22 = sub_C6F9B0((wchar_t *)chText, 0xFFFFFFFF, L"Refresh: ");
              FileTimeToLocalFileTime(&gTimeQuerySystemInfo, &LocalFileTime);
              FileTimeToSystemTime(&LocalFileTime, &SystemTime);
              GetTimeFormatW(0x400u, 0, &SystemTime, 0, (LPWSTR)&chText[v22], 256 - v22);
              v16 = v30;
              break;
            case MEM_RESERVE:
              if ( a3->dbPhysicalUsage == dbl_CD1128 )
              {
                v20 = v34;
                if ( !v34 )
                {
                  ++v13;
                  goto LABEL_86;
                }
              }
              wsprintf((wchar_t *)chText, L"Physical Usage: %02.2f%%", a3->dbPhysicalUsage);
              dbl_CD1128 = a3->dbPhysicalUsage;
              break;
            case MEM_DECOMMIT:
              if ( a3->double28 == dbl_CD1130 )
              {
                v20 = v34;
                if ( !v34 )
                {
                  ++v13;
                  goto LABEL_86;
                }
              }
              wsprintf((wchar_t *)chText, L"Own Physical Usage: %02.2f%%", a3->double28);
              dbl_CD1130 = a3->double28;
              break;
          }
        }
        else
        {
          switch ( v18 )
          {
            case 0x800u:
              if ( a3->dword44 == dword_CD10FC )
              {
                v20 = v34;
                if ( !v34 )
                {
                  ++v13;
                  goto LABEL_86;
                }
              }
              wsprintf((wchar_t *)chText, L"Own Handles: %d", a3->dword44);
              dword_CD10FC = a3->dword44;
              break;
            case 0x100u:
              if ( a3->dword38 == dword_CD10F0 )
              {
                v20 = v34;
                if ( !v34 )
                {
                  ++v13;
                  goto LABEL_86;
                }
              }
              wsprintf((wchar_t *)chText, L"Threads: %d", a3->dword38);
              dword_CD10F0 = a3->dword38;
              break;
            case 0x200u:
              if ( a3->dword3C == dword_CD10F4 )
              {
                v20 = v34;
                if ( !v34 )
                {
                  ++v13;
                  goto LABEL_86;
                }
              }
              wsprintf((wchar_t *)chText, L"Own Threads: %d", a3->dword3C);
              dword_CD10F4 = a3->dword3C;
              break;
            case 0x400u:
              if ( a3->dword40 == dword_CD10F8 )
              {
                v20 = v34;
                if ( !v34 )
                {
                  ++v13;
                  goto LABEL_86;
                }
              }
              wsprintf((wchar_t *)chText, L"Handles: %d", a3->dword40);
              dword_CD10F8 = a3->dword40;
              break;
          }
        }
      }
      else if ( v18 == 128 )
      {
        if ( a3->dword4C == dword_CD1104 )
        {
          v20 = v34;
          if ( !v34 )
          {
            ++v13;
            goto LABEL_86;
          }
        }
        wsprintf((wchar_t *)chText, L"Own .NET Processes: %d", a3->dword4C);
        dword_CD1104 = a3->dword4C;
      }
      else
      {
        switch ( v18 )
        {
          case 1u:
            v19 = a3->double0;
            if ( a3->double0 == dbl_CD1110 )
            {
              v20 = v34;
              if ( !v34 )
              {
                ++v13;
                goto LABEL_86;
              }
            }
            if ( gConfig.bShowCpuFractions )
              wsprintf((wchar_t *)chText, L"CPU Usage: %02.2f%%", LODWORD(v19), HIDWORD(v19));
            else
              wsprintf((wchar_t *)chText, L"CPU Usage: %0.0f%%", LODWORD(v19), HIDWORD(v19));
            dbl_CD1110 = a3->double0;
            break;
          case 2u:
            v21 = a3->double8;
            if ( v21 == dbl_CD1108 )
            {
              v20 = v34;
              if ( !v34 )
              {
                ++v13;
                goto LABEL_86;
              }
            }
            if ( gConfig.bShowCpuFractions )
              wsprintf((wchar_t *)chText, L"Own CPU Usage: %02.2f%%", LODWORD(v21), HIDWORD(v21));
            else
              wsprintf((wchar_t *)chText, L"Own CPU Usage: %0.0f%%", LODWORD(v21), HIDWORD(v21));
            dbl_CD1108 = a3->double8;
            break;
          case 4u:
            if ( a3->double10 == dbl_CD1118 )
            {
              v20 = v34;
              if ( !v34 )
              {
                ++v13;
                goto LABEL_86;
              }
            }
            wsprintf((wchar_t *)chText, L"Commit Charge: %02.2f%%", a3->double10);
            dbl_CD1118 = a3->double10;
            break;
          case 8u:
            if ( a3->double18 == dbl_CD1120 )
            {
              v20 = v34;
              if ( !v34 )
              {
                ++v13;
                goto LABEL_86;
              }
            }
            wsprintf((wchar_t *)chText, L"Own Commit Charge: %02.2f%%", a3->double18);
            dbl_CD1120 = a3->double18;
            break;
          case 0x10u:
            if ( a3->dword30 == dword_CD10E8 )
            {
              v20 = v34;
              if ( !v34 )
              {
                ++v13;
                goto LABEL_86;
              }
            }
            wsprintf((wchar_t *)chText, L"Processes: %d", a3->dword30);
            dword_CD10E8 = a3->dword30;
            break;
          case 0x20u:
            if ( a3->dword34 == dword_CD10EC )
            {
              v20 = v34;
              if ( !v34 )
              {
                ++v13;
                goto LABEL_86;
              }
            }
            wsprintf((wchar_t *)chText, L"Own Processes: %d", a3->dword34);
            dword_CD10EC = a3->dword34;
            break;
          case 0x40u:
            if ( a3->dword48 == dword_CD1100 )
            {
              v20 = v34;
              if ( !v34 )
              {
                ++v13;
                goto LABEL_86;
              }
            }
            wsprintf((wchar_t *)chText, &off_CB6EFC, a3->dword48);
            dword_CD1100 = a3->dword48;
            break;
          default:
            break;
        }
      }
      v23 = hdc;
      _mm_storeu_si128((__m128i *)&rc, (__m128i)0i64);
      DrawTextW(v23, (LPCWSTR)chText, -1, &rc, 0xD20u);
      v24 = rc.right + 10;
      rc.right += 10;
      if ( v13 )
        v25 = lParam[v13] - *(&rc.bottom + v13);
      else
        v25 = lParam[0];
      if ( v25 < v24 )
      {
        v34 = 1;
        lParam[v13] += v24 - v25;
      }
      SendMessageW(hWnd, 0x40Bu, v13, (LPARAM)chText);
      v17 = v31;
      ++v13;
    }
    v20 = v34;
LABEL_86:
    v16 = __ROL4__(v16, 1);
    --v17;
    v30 = v16;
    v31 = v17;
  }
  while ( v17 );
  if ( v20 )
  {
    lParam[v13] = -1;
    SendMessageW(ghWndStatusBar, 0x404u, v13 + 1, (LPARAM)lParam);
  }
  v26 = hdc;
  SelectObject(hdc, h);
  return (double *)ReleaseDC(ghWndStatusBar, v26);
}
// CACDC0: using guessed type double db_onehundred;
// CB6D34: using guessed type wchar_t aCpuUsage022f[20];
// CB6D84: using guessed type wchar_t aOwnCpuUsage022[24];
// CD10E8: using guessed type int dword_CD10E8;
// CD10EC: using guessed type int dword_CD10EC;
// CD10F0: using guessed type int dword_CD10F0;
// CD10F4: using guessed type int dword_CD10F4;
// CD10F8: using guessed type int dword_CD10F8;
// CD10FC: using guessed type int dword_CD10FC;
// CD1100: using guessed type int dword_CD1100;
// CD1104: using guessed type int dword_CD1104;
// CD1108: using guessed type double dbl_CD1108;
// CD1110: using guessed type double dbl_CD1110;
// CD1118: using guessed type double dbl_CD1118;
// CD1120: using guessed type double dbl_CD1120;
// CD1130: using guessed type double dbl_CD1130;
// C70410: using guessed type LPARAM lParam[32];
// C70410: using guessed type WCHAR chText[256];

//----- (00C70BB0) --------------------------------------------------------
HWND __cdecl CMainWnd::InitToolbar(HWND hWnd, unsigned int nIDToolbar)
{
  unsigned int nButtonSize; // edi
  WPARAM nBandIndex; // edi
  unsigned int nIndex; // esi
  LRESULT v6; // eax
  bool fBreak; // zf
  REBARINFO RebarInfo; // [esp+0h] [ebp-1B0h]
  INITCOMMONCONTROLSEX picce; // [esp+Ch] [ebp-1A4h]
  tagREBARBANDINFOW RebarBandInfo; // [esp+14h] [ebp-19Ch]
  int rcItem1; // [esp+64h] [ebp-14Ch]
  int rcItem2; // [esp+74h] [ebp-13Ch]
  struct tagRECT rect; // [esp+84h] [ebp-12Ch]
  TBBUTTON buttons[14]; // [esp+94h] [ebp-11Ch]

  buttons[0].iBitmap = BMP_SAVE;
  buttons[0].idCommand = IDM_FILE_SAVE;
  *(_DWORD *)&buttons[0].fsState = 4;
  *(_QWORD *)&buttons[0].dwData = 0i64;
  buttons[1].iBitmap = 0;
  buttons[1].idCommand = 0;
  *(_DWORD *)&buttons[1].fsState = 0x104;
  *(_QWORD *)&buttons[1].dwData = 0i64;
  buttons[2].iBitmap = BMP_REFRESH;
  buttons[2].idCommand = IDM_VIEW_REFRESH_NOW;
  *(_DWORD *)&buttons[2].fsState = 4;
  *(_QWORD *)&buttons[2].dwData = 0i64;
  buttons[3].iBitmap = 0;
  buttons[3].idCommand = 0;
  *(_DWORD *)&buttons[3].fsState = 0x104;
  *(_QWORD *)&buttons[3].dwData = 0i64;
  buttons[4].iBitmap = BMP_VIEW_SYSTEM_INFORMATION;
  buttons[4].idCommand = IDM_TRAYMENU_CONTEXT_SYSTEM_INFORMATION;
  *(_DWORD *)&buttons[4].fsState = 4;
  *(_QWORD *)&buttons[4].dwData = 0i64;
  buttons[5].iBitmap = BMP_SHOW_PROCESS_TREE;
  buttons[5].idCommand = IDM_VIEW_SHOW_PROCESS_TREE;
  *(_DWORD *)&buttons[5].fsState = 4;
  *(_QWORD *)&buttons[5].dwData = 0i64;
  buttons[6].iBitmap = BMP_SHOW_LOWER_PANE;
  buttons[6].idCommand = IDM_VIEW_SHOW_LOWER_PANE;
  *(_DWORD *)&buttons[6].fsState = 4;
  *(_QWORD *)&buttons[6].dwData = 0i64;
  buttons[7].iBitmap = BMP_VIEW_HANDLES;
  buttons[7].idCommand = IDM_POPUP_DLL_PROPERTIES;
  *(_DWORD *)&buttons[7].fsState = 4;
  *(_QWORD *)&buttons[7].dwData = 0i64;
  buttons[8].iBitmap = 0;
  buttons[8].idCommand = 0;
  *(_DWORD *)&buttons[8].fsState = 260;
  *(_QWORD *)&buttons[8].dwData = 0i64;
  buttons[9].iBitmap = BMP_PROPERTIES;
  buttons[9].idCommand = IDM_VIEW_PROCESS_PROPERTIES;
  *(_DWORD *)&buttons[9].fsState = 4;
  *(_QWORD *)&buttons[9].dwData = 0i64;
  buttons[10].iBitmap = BMP_KILL_PROCESS;
  buttons[10].idCommand = IDM_PROCESS_KILL_PROCESS;
  *(_DWORD *)&buttons[10].fsState = 4;
  *(_QWORD *)&buttons[10].dwData = 0i64;
  buttons[11].iBitmap = 0;
  buttons[11].idCommand = 0;
  *(_DWORD *)&buttons[11].fsState = 260;
  *(_QWORD *)&buttons[11].dwData = 0i64;
  buttons[12].iBitmap = 2;
  buttons[12].idCommand = IDM_SEARCH_IN_PROCESS;
  *(_DWORD *)&buttons[12].fsState = 4;
  *(_QWORD *)&buttons[12].dwData = 0i64;
  buttons[13].iBitmap = BMP_FIND_PROCESS_BY_WINDOW;
  buttons[13].idCommand = IDM_FIND_PROCESS_BY_WINDOW;
  *(_DWORD *)&buttons[13].fsState = 4;
  *(_QWORD *)&buttons[13].dwData = 0i64;
  picce.dwSize = 8;
  picce.dwICC = 1540;
  InitCommonControlsEx(&picce);
  ghWndReBar = CreateWindowExW(
                 WS_EX_TOOLWINDOW,
                 L"ReBarWindow32",
                 0,
                 0x56800448u,
                 0,
                 0,
                 400,
                 275,
                 hWnd,
                 0,
                 ghInstance,
                 0);
  RebarInfo.cbSize = sizeof(REBARINFO);
  RebarInfo.fMask = 0;
  if ( !SendMessageW(ghWndReBar, RB_SETBARINFO, 0, (LPARAM)&RebarInfo) )
    return 0;
  ghWndToolbar = CreateToolbarEx(
                   ghWndReBar,
                   0x56000944u,
                   (unsigned __int16)nIDToolbar,
                   12,
                   ghInstance,
                   108u,
                   buttons,
                   14,
                   0,
                   0,
                   0,
                   0,
                   20u);
  if ( !ghWndToolbar )
    return 0;
  nButtonSize = AutoSetToolbarButtonSize();
  SendMessageW(ghWndToolbar, TB_GETRECT, 0x9C49u, (LPARAM)&rcItem1);
  SendMessageW(ghWndToolbar, TB_GETRECT, 0x9CADu, (LPARAM)&rcItem2);
  UnionRect(&rect, (const RECT *)&rcItem1, (const RECT *)&rcItem2);
  memset(&RebarBandInfo, 0, sizeof(tagREBARBANDINFOW));
  RebarBandInfo.cbSize = sizeof(tagREBARBANDINFOW);
  // RBBIM_ID | RBBIM_CHILD | RBBIM_CHILDSIZE | RBBIM_SIZE | RBBIM_STYLE | RBBIM_COLORS;
  RebarBandInfo.fMask = 0x173;
  // RBBS_GRIPPERALWAYS| RBBS_CHILDEDGE
  RebarBandInfo.fStyle = 0x80;
  RebarBandInfo.hwndChild = ghWndToolbar;
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.clrFore = GetSysColor(COLOR_BTNTEXT);
  RebarBandInfo.clrBack = GetSysColor(COLOR_BTNFACE);
  RebarBandInfo.cx = rect.right - rect.left;
  RebarBandInfo.cxMinChild = rect.right - rect.left;
  RebarBandInfo.cyMinChild = nButtonSize >> 16;
  RebarBandInfo.wID = 0;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  ghWndCPUGraph = CreateWindowExW(
                    0,
                    L"CpuGraphClassGraph",
                    (LPCWSTR)&gszNullString,
                    0x56010004u,
                    0,
                    0,
                    0,
                    0,
                    ghWndReBar,
                    (HMENU)2000,
                    ghInstance,
                    gpGraphInfoOfCPU);
  RebarBandInfo.hwndChild = ghWndCPUGraph;
  RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.wID = GRAPHID_CPU;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  ghWndMemoryGraph = CreateWindowExW(
                       0,
                       L"CpuGraphClassGraph",
                       (LPCWSTR)&gszNullString,
                       0x56010004u,
                       0,
                       0,
                       0,
                       0,
                       ghWndReBar,
                       (HMENU)2000,
                       ghInstance,
                       gpGraphInfoOfMemory);
  RebarBandInfo.hwndChild = ghWndMemoryGraph;
  RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.wID = GRAPHID_Memory;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  ghWndPhysicalMemoryGraph = CreateWindowExW(
                               0,
                               L"CpuGraphClassGraph",
                               (LPCWSTR)&gszNullString,
                               0x56010004u,
                               0,
                               0,
                               0,
                               0,
                               ghWndReBar,
                               (HMENU)IDC_GRAPH_IN_REBAR,
                               ghInstance,
                               gpGraphInfoOfPhysicalMemory);
  RebarBandInfo.hwndChild = ghWndPhysicalMemoryGraph;
  RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.wID = GRAPHID_PhysicalMemory;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  if ( gIOGraphInfo.pGraphData )
  {
    ghWndIOGraphCtrl = CreateWindowExW(
                         0,
                         L"CpuGraphClassGraph",
                         (LPCWSTR)&gszNullString,
                         0x56010004u,
                         0,
                         0,
                         0,
                         0,
                         ghWndReBar,
                         (HMENU)2000,
                         ghInstance,
                         gIOGraphInfo.pGraphData);
    RebarBandInfo.hwndChild = ghWndIOGraphCtrl;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = GRAPHID_IO;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  }
  if ( IsBuiltinAdministrative() && gNetworkGraphInfo.pGraphData )
  {
    ghWndNetworkGraph = CreateWindowExW(
                          0,
                          L"CpuGraphClassGraph",
                          (LPCWSTR)&gszNullString,
                          0x56010004u,
                          0,
                          0,
                          0,
                          0,
                          ghWndReBar,
                          (HMENU)IDC_GRAPH_IN_REBAR,
                          ghInstance,
                          gNetworkGraphInfo.pGraphData);
    RebarBandInfo.hwndChild = ghWndNetworkGraph;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = GRAPHID_Network;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  }
  if ( IsBuiltinAdministrative() && gDiskGraphInfo.pGraphData )
  {
    ghWndDiskGraph = CreateWindowExW(
                       0,
                       L"CpuGraphClassGraph",
                       (LPCWSTR)&gszNullString,
                       0x56010004u,
                       0,
                       0,
                       0,
                       0,
                       ghWndReBar,
                       (HMENU)IDC_GRAPH_IN_REBAR,
                       ghInstance,
                       gDiskGraphInfo.pGraphData);
    RebarBandInfo.hwndChild = ghWndDiskGraph;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = GRAPHID_Disk;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  }
  if ( gdwAdapterRuntingTime )
  {
    ghWndGPUGraph = CreateWindowExW(
                      0,
                      L"CpuGraphClassGraph",
                      (LPCWSTR)&gszNullString,
                      0x56010004u,
                      0,
                      0,
                      0,
                      0,
                      ghWndReBar,
                      (HMENU)IDC_GRAPH_IN_REBAR,
                      ghInstance,
                      gpGraphInfoOfGPU);
    RebarBandInfo.hwndChild = ghWndGPUGraph;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = GRAPHID_GPU;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);
  }
  if ( gConfig.ToolBandInfo[0].nWidth != -1 )
  {
    nBandIndex = 0;
    nIndex = 0;
    do
    {
      v6 = SendMessageW(ghWndReBar, RB_IDTOINDEX, gConfig.ToolBandInfo[nIndex].nID, 0);
      SendMessageW(ghWndReBar, RB_MOVEBAND, v6, nBandIndex);
      SendMessageW(ghWndReBar, RB_GETBANDINFOW, nBandIndex, (LPARAM)&RebarBandInfo);
      fBreak = gConfig.ToolBandInfo[nIndex].fBreak == 0;
      RebarBandInfo.fMask = 0x141;              // RBBIM_STYLE|RBBIM_SIZE|RBBIM_ID
      if ( fBreak )
        RebarBandInfo.fStyle &= -2u;
      else
        RebarBandInfo.fStyle |= RBBS_BREAK;
      RebarBandInfo.cx = MulDiv(gConfig.ToolBandInfo[nIndex].nWidth, gLogPixelSize.x, 96);
      RebarBandInfo.wID = gConfig.ToolBandInfo[nIndex].nID;
      SendMessageW(ghWndReBar, RB_SETBANDINFOW, nBandIndex, (LPARAM)&RebarBandInfo);
      ++nIndex;
      ++nBandIndex;
    }
    while ( nIndex < 8 );
  }
  return ghWndToolbar;
}

//----- (00C713B0) --------------------------------------------------------
LPARAM AutoSetToolbarButtonSize()
{
  int v0; // edi
  unsigned __int16 v1; // ax
  LPARAM v2; // esi

  v0 = (unsigned __int16)GetSystemMetrics(50) << 16;
  v1 = GetSystemMetrics(49);
  SendMessageW(ghWndToolbar, 0x420u, 0, v0 | v1);
  v2 = SendMessageW(ghWndToolbar, 0x43Au, 0, 0);
  SendMessageW(ghWndToolbar, 0x420u, 0, 983056);
  SendMessageW(ghWndToolbar, 0x41Fu, 0, v2);
  return v2;
}

//----- (00C71420) --------------------------------------------------------
std__list_node *__stdcall std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(EventList *a1, _DWORD *a2, _DWORD *a3)
{
  std__list_node *result; // eax

  result = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                               a1,
                               a2);
  if ( result != (std__list_node *)-8 )
    result->_Myval = (void *)*a3;
  return result;
}

//----- (00C71440) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_C71440(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, char a3, CSystemProcessInfoMapNode *a4, int *a5, int a6)
{
  CSystemProcessInfoMap *v6; // edi
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

  v6 = this;
  if ( this->_Size >= 0xAAAAAA9u )
    std::_Xlength_error("map/set<T> too long");
  v7 = sub_C01310(this, a5);
  ++v6->_Size;
  v8 = v7;
  v7->baseclass._Parent = a4;
  if ( a4 == (CSystemProcessInfoMapNode *)v6->_Header )
  {
    v6->_Header->_Parent = (std_Tree_node_for_tagKeyName *)v7;
    v6->_Header->_Left = (std_Tree_node_for_tagKeyName *)v7;
    v9 = v6->_Header;
LABEL_8:
    v9->_Right = (std__Tree_node_For__bstr_t *)v8;
    goto LABEL_9;
  }
  if ( !a3 )
  {
    a4->baseclass._Right = v7;
    v9 = v6->_Header;
    if ( a4 != (CSystemProcessInfoMapNode *)v6->_Header->_Right )
      goto LABEL_9;
    goto LABEL_8;
  }
  a4->baseclass._Left = v7;
  if ( a4 == (CSystemProcessInfoMapNode *)v6->_Header->_Left )
    v6->_Header->_Left = (std_Tree_node_for_tagKeyName *)v7;
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
            if ( v11 == v6->_Header->_Parent )
            {
              v6->_Header->_Parent = v14;
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
          if ( v16 == v6->_Header->_Parent )
          {
            v6->_Header->_Parent = v17;
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
          if ( v10 == v6->_Header->_Parent )
          {
            v6->_Header->_Parent = v20;
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
        if ( v16 == v6->_Header->_Parent )
        {
          v6->_Header->_Parent = v17;
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
  v6->_Header->_Parent->_Color = 1;
  result = a2;
  *a2 = v8;
  return result;
}

//----- (00C71650) --------------------------------------------------------
int __thiscall sub_C71650(CSystemProcessInfoMap *this, int a2, CSystemProcessInfoMapNode *a3, int *a4, int a5)
{
  CSystemProcessInfoMap *v5; // edx
  CSystemProcessInfoMapNode *v6; // ecx
  bool v7; // al
  int *v8; // ebx
  CSystemProcessInfoMapNode *v9; // esi
  Data_t_bstr_t *v10; // ecx
  Data_t_bstr_t *v11; // ecx
  CSystemProcessInfoMapNode *v12; // esi
  CSystemProcessInfoMapNode **v13; // eax
  CSystemProcessInfoMapNode *v14; // ecx
  int result; // eax
  Data_t_bstr_t *v16; // ecx
  Data_t_bstr_t *v17; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v18; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v19; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v20; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v21; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v22; // [esp-4h] [ebp-30h]
  int v23; // [esp+0h] [ebp-2Ch]
  CSystemProcessInfoMap *v24; // [esp+10h] [ebp-1Ch]
  int v25; // [esp+14h] [ebp-18h]
  CSystemProcessInfoMapNode *v26; // [esp+18h] [ebp-14h]
  int *v27; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+28h] [ebp-4h]

  v27 = &v23;
  v5 = this;
  v24 = this;
  v6 = (CSystemProcessInfoMapNode *)this->_Header;
  v7 = 1;
  v8 = a4;
  v28 = 0;
  v9 = v6->baseclass._Parent;
  v26 = v6;
  LOBYTE(v25) = 1;
  if ( !v9->baseclass._isnil )
  {
    do
    {
      v26 = v9;
      if ( (_BYTE)a3 )
      {
        v20 = (Data_t_bstr_t *)*v8;
        if ( *v8 )
          InterlockedIncrement((volatile LONG *)(*v8 + 8));
        v10 = (Data_t_bstr_t *)v9->_Keyvalue._Key;
        v17 = v10;
        if ( v10 )
          InterlockedIncrement(&v10->m_RefCount);
        v7 = sub_C014B0(v17, v20) == 0;
      }
      else
      {
        v11 = (Data_t_bstr_t *)v9->_Keyvalue._Key;
        v21 = v11;
        if ( v11 )
          InterlockedIncrement(&v11->m_RefCount);
        v18 = (Data_t_bstr_t *)*v8;
        if ( *v8 )
          InterlockedIncrement(&v18->m_RefCount);
        v7 = sub_C014B0(v18, v21);
      }
      LOBYTE(v25) = v7;
      if ( v7 )
        v9 = v9->baseclass._Left;
      else
        v9 = v9->baseclass._Right;
    }
    while ( !v9->baseclass._isnil );
    v6 = v26;
    v5 = v24;
  }
  v12 = v6;
  a3 = v6;
  if ( v7 )
  {
    if ( v6 == (CSystemProcessInfoMapNode *)v5->_Header->_Left )
    {
      v13 = sub_C71440(v5, &a3, 1, v6, v8, a5);
LABEL_21:
      v14 = *v13;
      result = a2;
      *(_DWORD *)a2 = v14;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&a3);
    v12 = a3;
  }
  v22 = (Data_t_bstr_t *)*v8;
  if ( *v8 )
    InterlockedIncrement(&v22->m_RefCount);
  v16 = (Data_t_bstr_t *)v12->_Keyvalue._Key;
  v19 = v16;
  if ( v16 )
    InterlockedIncrement(&v16->m_RefCount);
  if ( sub_C014B0(v19, v22) )
  {
    v13 = sub_C71440(v24, (CSystemProcessInfoMapNode **)&a4, v25, v26, v8, a5);
    goto LABEL_21;
  }
  result = a2;
  *(_DWORD *)a2 = v12;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C717E0) --------------------------------------------------------
char SubmitExeToVirusTotalDotCom()
{
  char result; // al

  result = AskForAgreementLicense(ghMainWnd, L"Process Explorer", 0, 0, (int)aYouMustAgreeTo_2);
  gbAgreenmentLicensed = result;
  if ( result )
  {
    StartVirusTotalCheck();
    result = gbAgreenmentLicensed;
  }
  return result;
}
// CD1138: using guessed type wchar_t aYouMustAgreeTo_2[298];
// CF5774: using guessed type char gbAgreenmentLicensed;

//----- (00C71820) --------------------------------------------------------
char __cdecl sub_C71820(ListItemData1 *a1)
{
  char result; // al

  result = 0;
  if ( a1 && (a1->field_4 == 1 || a1->field_4 == 4) )
    result = 1;
  return result;
}

//----- (00C71840) --------------------------------------------------------
BOOL __cdecl sub_C71840(LPCWSTR lpFileName, wchar_t *Dest, int a3)
{
  wchar_t *v3; // edi
  BOOL v4; // ebx
  HANDLE v5; // eax
  void *v6; // esi
  DWORD v7; // eax
  DWORD v8; // ecx
  DWORD v9; // edx
  SIZE_T v10; // esi
  const BYTE *v11; // eax
  bool v12; // zf
  HCRYPTHASH v13; // ST08_4
  DWORD v14; // esi
  HANDLE v16; // [esp+Ch] [ebp-48h]
  const BYTE *dwFileOffsetHigh_4; // [esp+14h] [ebp-40h]
  DWORD v18; // [esp+18h] [ebp-3Ch]
  DWORD v19; // [esp+1Ch] [ebp-38h]
  LPFILETIME lpCreationTime; // [esp+20h] [ebp-34h]
  HCRYPTPROV phProv; // [esp+24h] [ebp-30h]
  HCRYPTHASH phHash; // [esp+28h] [ebp-2Ch]
  DWORD pdwDataLen; // [esp+2Ch] [ebp-28h]
  BYTE pbData; // [esp+30h] [ebp-24h]
  __int128 v25; // [esp+31h] [ebp-23h]
  __int64 v26; // [esp+41h] [ebp-13h]
  int v27; // [esp+49h] [ebp-Bh]
  __int16 v28; // [esp+4Dh] [ebp-7h]
  char v29; // [esp+4Fh] [ebp-5h]

  v3 = Dest;
  v4 = 0;
  phProv = 0;
  phHash = 0;
  v5 = CreateFileW(lpFileName, 0x80000000, 7u, 0, 3u, 0, 0);
  v6 = v5;
  v16 = v5;
  if ( v5 == (HANDLE)-1 )
    return v4 != 0;
  GetFileTime(v5, (LPFILETIME)a3, 0, 0);
  v4 = CryptAcquireContextW(&phProv, 0, 0, 0x18u, 0xF0000000);
  if ( !v4 )
  {
    v4 = CryptAcquireContextW(&phProv, 0, 0, 1u, 0xF0000000);
    if ( !v4 )
      goto LABEL_24;
  }
  if ( !CryptCreateHash(phProv, 0x8004u, 0, 0, &phHash) )
    goto LABEL_23;
  lpCreationTime = (LPFILETIME)CreateFileMappingW(v6, 0, 2u, 0, 0, 0);
  if ( !lpCreationTime )
  {
    v4 = 0;
    goto LABEL_22;
  }
  v7 = GetFileSize(v6, 0);
  v19 = v7;
  v4 = 1;
  if ( !v7 )
    goto LABEL_16;
  v8 = 0;
  v9 = 0;
  v18 = 0;
  pdwDataLen = 0;
  while ( 1 )
  {
    v10 = v7;
    if ( v7 > 0x100000 )
      v10 = 0x100000;
    v11 = (const BYTE *)MapViewOfFile(lpCreationTime, 4u, v8, v9, v10);
    dwFileOffsetHigh_4 = v11;
    if ( !v11 )
      goto LABEL_13;
    if ( !CryptHashData(phHash, v11, v10, 0) )
      break;
    v11 = dwFileOffsetHigh_4;
LABEL_13:
    UnmapViewOfFile(v11);
    v8 = (v10 + __PAIR__(v18, pdwDataLen)) >> 32;
    v9 = v10 + pdwDataLen;
    pdwDataLen += v10;
    v7 = v19 - v10;
    v12 = v19 == v10;
    v18 = v8;
    v19 -= v10;
    if ( v12 )
      goto LABEL_16;
  }
  v4 = 0;
LABEL_16:
  CloseHandle(lpCreationTime);
  if ( v4 )
  {
    pbData = 0;
    v27 = 0;
    v13 = phHash;
    v28 = 0;
    _mm_storeu_si128((__m128i *)&v25, (__m128i)0i64);
    v29 = 0;
    v26 = 0i64;
    pdwDataLen = 32;
    if ( CryptGetHashParam(v13, 2u, &pbData, &pdwDataLen, 0) )
    {
      v14 = 0;
      if ( pdwDataLen )
      {
        do
        {
          _swprintf(v3, L"%02X", *(&pbData + v14++));
          v3 += 2;
        }
        while ( v14 < pdwDataLen );
      }
    }
  }
LABEL_22:
  CryptDestroyHash(phHash);
  v6 = v16;
LABEL_23:
  CryptReleaseContext(phProv, 0);
LABEL_24:
  CloseHandle(v6);
  return v4 != 0;
}

//----- (00C71A50) --------------------------------------------------------
int __cdecl sub_C71A50(int pHash, wchar_t *Dest)
{
  int result; // eax
  const wchar_t *v3; // edx
  const wchar_t *v4; // edx
  const wchar_t *v5; // edx
  char **v6; // edx
  char *v7; // edx
  char *v8; // ecx
  _DWORD *v9; // eax

  result = 0;
  *Dest = 0;
  if ( pHash )
  {
    result = *(_DWORD *)(pHash + 4) - 1;
    switch ( *(_DWORD *)(pHash + 4) )
    {
      case 1:
      case 6:
        v9 = *(_DWORD **)(pHash + 40);
        if ( v9 )
          result = _swprintf(Dest, L"%s", *v9);
        else
          result = _swprintf(Dest, L"%s", 0);
        break;
      case 2:
        v3 = L"Hash submitted...";
        do
        {
          result = *v3;
          ++v3;
          *(const wchar_t *)((char *)v3 + (char *)Dest - (char *)L"Hash submitted..." - 2) = result;
        }
        while ( (_WORD)result );
        break;
      case 3:
        v5 = L"File submitted...";
        do
        {
          result = *v5;
          ++v5;
          *(const wchar_t *)((char *)v5 + (char *)Dest - (char *)L"File submitted..." - 2) = result;
        }
        while ( (_WORD)result );
        break;
      case 4:
        v4 = L"Scanning file...";
        do
        {
          result = *v4;
          ++v4;
          *(const wchar_t *)((char *)v4 + (char *)Dest - (char *)L"Scanning file..." - 2) = result;
        }
        while ( (_WORD)result );
        break;
      case 5:
        v6 = *(char ***)(pHash + 32);
        if ( v6 )
          v7 = *v6;
        else
          v7 = 0;
        v8 = (char *)((char *)Dest - v7);
        do
        {
          result = *(unsigned __int16 *)v7;
          v7 += 2;
          *(_WORD *)&v7[(_DWORD)v8 - 2] = result;
        }
        while ( (_WORD)result );
        break;
      default:
        return result;
    }
  }
  return result;
}
// CA2BBC: using guessed type wchar_t aHashSubmitted[18];
// CA2BE0: using guessed type wchar_t aScanningFile[17];
// CA2C04: using guessed type wchar_t aFileSubmitted[18];

//----- (00C71B40) --------------------------------------------------------
void StartVirusTotalCheck()
{
  if ( !byte_CF57B4 )
  {
    HttpInfo_Open(&gHttpInfo, ghMainWnd, L"Process Explorer", 0, 0, 0);
    InitializeCriticalSection(&stru_CF5744);
    ghEventHandle = CreateEventW(0, 0, 0, 0);
    ghEventHandle2 = CreateEventW(0, 0, 0, 0);
    ghThreadHandle = _beginthreadex(0, 0, (int)BackendThreadProc1, 0, 0, 0);
    ghEventHandle3 = CreateEventW(0, 0, 0, 0);
    ghThreadHandle2 = _beginthreadex(0, 0, (int)BackendThreadProc2, 0, 0, 0);
    ghThreadHandle3 = _beginthreadex(0, 0, (int)BackendThreadProc3, 0, 0, 0);
    byte_CF57B4 = 1;
  }
}
// CF5760: using guessed type int ghThreadHandle;
// CF5768: using guessed type int ghThreadHandle2;
// CF5770: using guessed type int ghThreadHandle3;
// CF57B4: using guessed type char byte_CF57B4;

//----- (00C71C10) --------------------------------------------------------
char __cdecl sub_C71C10(ListItemData1 *a1)
{
  char result; // al
  int v2; // ecx

  result = 0;
  if ( !a1 || (v2 = a1->field_4, v2 == 1) || (unsigned int)(v2 - 5) <= 1 )
    result = 1;
  return result;
}

//----- (00C71C30) --------------------------------------------------------
void __cdecl sub_C71C30(tagDLLLISTITEMPARAM *pItemParam, char a2, int a3)
{
  tagDLLLISTITEMPARAM *pItemParam_1; // ebx
  _bstr_t *v4; // edi
  CHAR *v5; // ST0C_4
  std__Tree_node *v6; // eax
  WCHAR *v7; // ecx
  Data_t_bstr_t *v8; // eax
  int v9; // esi
  LONG (__stdcall *v10)(volatile LONG *); // ecx
  _DWORD *v11; // eax
  Data_t_bstr_t *v12; // esi
  OLECHAR *v13; // eax
  Data_t_bstr_t *v14; // eax
  BSTR v15; // eax
  tagDLLLISTITEMPARAM *v16; // eax
  _bstr_t v17; // [esp+10h] [ebp-28h]
  _bstr_t v18; // [esp+14h] [ebp-24h]
  char v19; // [esp+18h] [ebp-20h]
  OLECHAR *psz; // [esp+1Ch] [ebp-1Ch]
  tagDLLLISTITEMPARAM *pItemParam_2; // [esp+20h] [ebp-18h]
  int a2a; // [esp+24h] [ebp-14h]
  _bstr_t v23; // [esp+28h] [ebp-10h]
  int v24; // [esp+34h] [ebp-4h]

  if ( gbAgreenmentLicensed )
  {
    EnterCriticalSection(&stru_CF5744);
    pItemParam_1 = 0;
    v4 = 0;
    pItemParam_2 = 0;
    a2a = 0;
    v23.m_Data = 0;
    v24 = 0;
    if ( pItemParam->m_Type )
    {
      v5 = pItemParam->m_strPath.pszData;
      pItemParam_2 = pItemParam;
      _bstr_t::operator=((EventItem *)&v23, (OLECHAR *)v5);
      psz = (OLECHAR *)pItemParam->m_strLocation;
    }
    else
    {
      pItemParam_1 = pItemParam;
      _bstr_t::operator=((EventItem *)&v23, (OLECHAR *)pItemParam[2].field_8);
      psz = (OLECHAR *)pItemParam[2].field_2C;
    }
    v6 = (std__Tree_node *)*sub_C72F90((int *)&gHttpInfo.m_Map, (int *)&v18, (volatile LONG **)&v23);
    if ( v6 == gHttpInfo.m_Map._Mypair._Myval2._Myhead
      || ((v7 = (WCHAR *)v6[1]._Parent, !pItemParam_1) ? (pItemParam_2->m_HashData = (int)v7) : (pItemParam_1[2].m_szProcessName2 = v7),
          (v4 = (_bstr_t *)v6[1]._Parent, a2a = (int)v4, v8 = v4[1].m_Data, v8 == (Data_t_bstr_t *)6)
       || v8 == (Data_t_bstr_t *)5) )
    {
      v9 = a3;
      if ( a3 != 2 )
      {
        v10 = InterlockedIncrement;
        if ( !v4 )
        {
          v11 = operator new(0x2Cu);
          if ( v11 )
            v4 = (_bstr_t *)sub_C01350(v11);
          else
            v4 = 0;
          v12 = v23.m_Data;
          LOBYTE(v4->m_Data) = a2;
          a2a = (int)v4;
          if ( &v4[5] != &v23 )
          {
            _bstr_t::_Free(v4 + 5);
            v4[5].m_Data = v12;
            if ( v12 )
              InterlockedIncrement(&v12->m_RefCount);
          }
          v13 = (OLECHAR *)&gszNullString;
          if ( psz )
            v13 = psz;
          psz = (OLECHAR *)_bstr_t::_bstr_t((tagEventSetItem *)&v18, v13);
          if ( &v4[2] != (_bstr_t *)psz )
          {
            _bstr_t::_Free(v4 + 2);
            v14 = *(Data_t_bstr_t **)psz;
            v4[2].m_Data = *(Data_t_bstr_t **)psz;
            if ( v14 )
              InterlockedIncrement(&v14->m_RefCount);
          }
          _bstr_t::_Free(&v18);
          v18.m_Data = (Data_t_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&psz, (OLECHAR *)&gszNullString);
          if ( &v4[3] != (_bstr_t *)v18.m_Data )
          {
            _bstr_t::_Free(v4 + 3);
            v15 = v18.m_Data->m_wstr;
            v4[3].m_Data = (Data_t_bstr_t *)v18.m_Data->m_wstr;
            if ( v15 )
              InterlockedIncrement((volatile LONG *)v15 + 2);
          }
          _bstr_t::_Free((_bstr_t *)&psz);
          v17.m_Data = v12;
          if ( v12 )
            InterlockedIncrement(&v12->m_RefCount);
          v18.m_Data = (Data_t_bstr_t *)v4;
          LOBYTE(v24) = 1;
          sub_C71650((CSystemProcessInfoMap *)&gHttpInfo.m_Map, (int)&v19, 0, (int *)&v17, (unsigned __int8)byte_CF5775);
          LOBYTE(v24) = 0;
          _bstr_t::_Free(&v17);
          v10 = InterlockedIncrement;
          v9 = a3;
        }
        v4[1].m_Data = (Data_t_bstr_t *)(3 - (v9 != 1));
        if ( pItemParam_1 )
        {
          pItemParam_1[2].m_szProcessName2 = (WCHAR *)v4;
          v16 = (tagDLLLISTITEMPARAM *)((char *)pItemParam_1 + 36);
        }
        else
        {
          v16 = pItemParam_2;
          pItemParam_2->m_HashData = (int)v4;
        }
        v10(&v16->m_nRefCount);
        if ( v9 == 1 )
        {
          std::list<tagEventItem *,std::allocator<tagEventItem *>>::push_back(&gList10, (int)&a2a);
          SetEvent(ghEventHandle3);
        }
        else
        {
          sub_C017F0((int **)&gList11, (int)&a2a);
          SetEvent(ghEventHandle2);
        }
      }
    }
    LeaveCriticalSection(&stru_CF5744);
    _bstr_t::_Free(&v23);
  }
}
// CF5774: using guessed type char gbAgreenmentLicensed;
// CF5775: using guessed type char byte_CF5775;

//----- (00C71EC0) --------------------------------------------------------
int __stdcall BackendThreadProc2(void *a1)
{
  void (__stdcall *v1)(LPCRITICAL_SECTION); // ebx
  void (__stdcall *v2)(LPCRITICAL_SECTION); // esi
  std__list_node *v3; // ST0C_4
  std__list_node *v4; // ecx
  _DWORD *v5; // edi
  std__list_node *v6; // eax
  Data_t_bstr_t *v7; // eax
  Data_t_bstr_t *v8; // esi
  BSTR v9; // eax
  Data_t_bstr_t *v10; // ecx
  int v11; // eax
  bool v12; // bl
  const wchar_t **v13; // eax
  const wchar_t *v14; // eax
  std__list_node *v15; // ebx
  std__list_node *v16; // eax
  void (__stdcall *v17)(HWND, UINT, WPARAM, LPARAM); // ebx
  const wchar_t **v18; // eax
  const wchar_t *v19; // eax
  EventList *v20; // ebx
  std__list_node *v21; // eax
  int v22; // esi
  HANDLE Handles; // [esp+10h] [ebp-24h]
  HANDLE v25; // [esp+14h] [ebp-20h]
  void *v26; // [esp+18h] [ebp-1Ch]
  OLECHAR psz[2]; // [esp+1Ch] [ebp-18h]
  int a3; // [esp+20h] [ebp-14h]
  char v29; // [esp+27h] [ebp-Dh]
  int v30; // [esp+30h] [ebp-4h]

  Handles = ghEventHandle3;
  v25 = ghEventHandle;
  *(_DWORD *)psz = 0;
  v30 = 0;
  if ( WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF) != 1 )
  {
    v1 = EnterCriticalSection;
    v2 = LeaveCriticalSection;
    while ( 1 )
    {
      v1(&stru_CF5744);
      if ( gList10._Mypair._Myval2._Mysize )
        break;
LABEL_42:
      v2(&stru_CF5744);
      if ( WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF) == 1 )
        goto LABEL_43;
    }
    while ( 1 )
    {
      v3 = gList10._Mypair._Myval2._Myhead->_Next;
      v4 = gList10._Mypair._Myval2._Myhead->_Next->_Prev;
      v6 = gList10._Mypair._Myval2._Myhead->_Next->_Next;
      a3 = (int)gList10._Mypair._Myval2._Myhead->_Next->_Myval;
      v5 = (_DWORD *)a3;
      v4->_Next = v6;
      v3->_Next->_Prev = v3->_Prev;
      --gList10._Mypair._Myval2._Mysize;
      operator delete(v3);
      v2(&stru_CF5744);
      sub_C155A0(&gHttpInfo, (int)(v5 + 2), (unsigned int)psz);
      v1(&stru_CF5744);
      v29 = 0;
      v7 = (Data_t_bstr_t *)operator new(0xCu);
      v8 = v7;
      v26 = v7;
      LOBYTE(v30) = 1;
      if ( v7 )
      {
        v7->m_str = 0;
        v7->m_RefCount = 1;
        v9 = SysAllocString((const OLECHAR *)&gszNullString);
        v8->m_wstr = v9;
        if ( !v9 )
          goto LABEL_6;
      }
      else
      {
        v8 = 0;
      }
      LOBYTE(v30) = 0;
      if ( !v8 )
LABEL_6:
        _com_issue_error(-2147024882);
      v10 = (Data_t_bstr_t *)v5[8];
      if ( v10 == v8 )
        break;
      if ( v10 )
      {
        v11 = _bstr_t::Data_t::Compare(v10, v8);
      }
      else
      {
        if ( !v8->m_wstr || !SysStringLen(v8->m_wstr) )
          break;
        v11 = -1;
      }
LABEL_16:
      v12 = v11 != 0;
      if ( !InterlockedDecrement(&v8->m_RefCount) )
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
      if ( !v12 )
      {
        v18 = (const wchar_t **)v5[10];
        if ( v18 )
          v19 = *v18;
        else
          v19 = 0;
        if ( _wcsicmp(v19, L"Submitted") )
        {
          v5[1] = 1;
        }
        else
        {
          v20 = gList12;
          v21 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                  gList12,
                  (_DWORD *)gList12->_Mysize,
                  &a3);
          if ( (unsigned int)(357913940 - (_DWORD)*(&gList12 + 1)) < 1 )
LABEL_52:
            std::_Xlength_error("list<T> too long");
          *(&gList12 + 1) = (EventList *)((char *)*(&gList12 + 1) + 1);
          v20->_Mysize = (int)v21;
          v21->_Prev->_Next = v21;
          v5[1] = 4;
        }
        v29 = 1;
        goto LABEL_38;
      }
      v13 = (const wchar_t **)v5[8];
      if ( v13 )
        v14 = *v13;
      else
        v14 = 0;
      if ( wcsstr(v14, L"throttle") )
      {
        v15 = gList10._Mypair._Myval2._Myhead->_Next;
        v16 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                (EventList *)gList10._Mypair._Myval2._Myhead->_Next,
                &gList10._Mypair._Myval2._Myhead->_Next->_Prev->_Next,
                &a3);
        if ( 357913940 - gList10._Mypair._Myval2._Mysize < 1 )
          goto LABEL_52;
        ++gList10._Mypair._Myval2._Mysize;
        v15->_Prev = v16;
        v16->_Prev->_Next = v16;
        SetEvent(ghEventHandle3);
LABEL_38:
        v17 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))PostMessageW;
        goto LABEL_39;
      }
      v17 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))PostMessageW;
      v5[1] = 5;
      v29 = 1;
      PostMessageW(ghMainWnd, 0x7F9u, 0, (LPARAM)v5);
LABEL_39:
      v2 = LeaveCriticalSection;
      LeaveCriticalSection(&stru_CF5744);
      if ( v29 )
        v17(ghMainWnd, 0x7F9u, 0, (LPARAM)v5);
      v1 = EnterCriticalSection;
      EnterCriticalSection(&stru_CF5744);
      if ( !gList10._Mypair._Myval2._Mysize )
        goto LABEL_42;
    }
    v11 = 0;
    goto LABEL_16;
  }
LABEL_43:
  v22 = *(_DWORD *)psz;
  if ( *(_DWORD *)psz && !InterlockedDecrement((volatile LONG *)(*(_DWORD *)psz + 8)) && v22 )
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
  return 0;
}
// C0C3D4: using guessed type int (__stdcall *)(_DWORD);

//----- (00C72230) --------------------------------------------------------
int __stdcall BackendThreadProc1(int a1)
{
  int v1; // edi
  EventList *v2; // ebx
  void (__stdcall *v3)(LPCRITICAL_SECTION); // esi
  _DWORD *v4; // ST530_4
  _DWORD *v5; // ecx
  int v6; // ebx
  int v7; // eax
  OLECHAR **v8; // eax
  OLECHAR *v9; // eax
  _DWORD *v10; // ecx
  const WCHAR *v11; // ecx
  OLECHAR **v12; // eax
  OLECHAR *v13; // eax
  EventList *v14; // esi
  std__list_node *v15; // eax
  std__list_node *v16; // ecx
  DWORD v17; // eax
  void **v18; // edi
  void *v19; // esi
  void *v20; // esi
  EventList *v21; // esi
  EventListNode *v22; // ebx
  Data_t_bstr_t *v23; // eax
  Data_t_bstr_t *v24; // edi
  BSTR v25; // eax
  Data_t_bstr_t *v26; // ecx
  int v27; // eax
  const wchar_t **v28; // eax
  const wchar_t *v29; // eax
  std__list_node *v30; // eax
  OLECHAR **v31; // eax
  OLECHAR *v32; // eax
  const wchar_t **v33; // eax
  const wchar_t *v34; // eax
  std__list_node *v35; // eax
  std__list_node *v36; // eax
  EventList *v37; // eax
  EventListNode *v38; // esi
  EventList *v39; // eax
  EventListNode *v40; // esi
  HANDLE Handles; // [esp+10h] [ebp-B4h]
  HANDLE v43; // [esp+14h] [ebp-B0h]
  int v44; // [esp+18h] [ebp-ACh]
  EventList **v45; // [esp+1Ch] [ebp-A8h]
  int v46; // [esp+20h] [ebp-A4h]
  void *v47; // [esp+24h] [ebp-A0h]
  int a3; // [esp+28h] [ebp-9Ch]
  void *v49; // [esp+2Ch] [ebp-98h]
  bool v50; // [esp+32h] [ebp-92h]
  char v51; // [esp+33h] [ebp-91h]
  OLECHAR psz; // [esp+34h] [ebp-90h]
  int v53; // [esp+C0h] [ebp-4h]

  v1 = 0;
  Handles = ghEventHandle2;
  v43 = ghEventHandle;
  v46 = 0;
  v2 = (EventList *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                      0,
                      0);
  v45 = (EventList **)v2;
  v53 = 0;
  v44 = 0;
  while ( WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF) != 1 )
  {
    v3 = LeaveCriticalSection;
    Sleep(0x1388u);
    EnterCriticalSection(&stru_CF5744);
    if ( *(&gList11 + 1) )
    {
      do
      {
        v4 = *(_DWORD **)gList11;
        v5 = *(_DWORD **)(*(_DWORD *)gList11 + 4);
        v7 = **(_DWORD **)gList11;
        a3 = *(_DWORD *)(*(_DWORD *)gList11 + 8);
        v6 = a3;
        *v5 = v7;
        *(_DWORD *)(*v4 + 4) = v4[1];
        *(&gList11 + 1) = (char *)*(&gList11 + 1) - 1;
        operator delete(v4);
        v3(&stru_CF5744);
        v8 = *(OLECHAR ***)(v6 + 16);
        if ( !v8 || (v9 = *v8) == 0 || !SysStringLen(v9) )
        {
          v10 = *(_DWORD **)(v6 + 20);
          v11 = (const WCHAR *)(v10 ? *v10 : 0);
          if ( (unsigned __int8)sub_C71840(v11, &psz, v6 + 24) )
            _bstr_t::operator=((EventItem *)(v6 + 16), &psz);
        }
        v12 = *(OLECHAR ***)(v6 + 16);
        if ( v12 && (v13 = *v12) != 0 && SysStringLen(v13) )
        {
          ++v44;
          v14 = *v45;
          v15 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                  *v45,
                  (_DWORD *)(*v45)->_Mysize,
                  &a3);
          if ( (unsigned int)(357913940 - v1) < 1 )
LABEL_89:
            std::_Xlength_error("list<T> too long");
          v14->_Mysize = (int)v15;
          ++v1;
          v16 = v15->_Prev;
          v46 = v1;
          v16->_Next = v15;
          sub_C15160(&gHttpInfo, v6 + 8);
        }
        else
        {
          v17 = GetLastError();
          sub_C14320((int)&v47, v17);
          v18 = (void **)(v6 + 32);
          if ( (void **)(v6 + 32) != &v47 )
          {
            v19 = *v18;
            if ( *v18 )
            {
              if ( !InterlockedDecrement((volatile LONG *)v19 + 2) && v19 )
              {
                if ( *(_DWORD *)v19 )
                {
                  SysFreeString(*(BSTR *)v19);
                  *(_DWORD *)v19 = 0;
                }
                if ( *((_DWORD *)v19 + 1) )
                {
                  operator delete[](*((void **)v19 + 1));
                  *((_DWORD *)v19 + 1) = 0;
                }
                operator delete(v19);
              }
              *v18 = 0;
            }
            *v18 = v47;
            if ( v47 )
              InterlockedIncrement((volatile LONG *)v47 + 2);
          }
          *(_DWORD *)(v6 + 4) = 5;
          v20 = v47;
          if ( v47 )
          {
            if ( !InterlockedDecrement((volatile LONG *)v47 + 2) && v20 )
            {
              if ( *(_DWORD *)v20 )
              {
                SysFreeString(*(BSTR *)v20);
                *(_DWORD *)v20 = 0;
              }
              if ( *((_DWORD *)v20 + 1) )
              {
                operator delete[](*((void **)v20 + 1));
                *((_DWORD *)v20 + 1) = 0;
              }
              operator delete(v20);
            }
            v47 = 0;
          }
          v1 = v46;
        }
        EnterCriticalSection(&stru_CF5744);
        v3 = LeaveCriticalSection;
      }
      while ( *(&gList11 + 1) );
      v2 = (EventList *)v45;
    }
    v3(&stru_CF5744);
    sub_C11FC0(&gHttpInfo);
    v21 = (EventList *)v2->_Myheader;
    if ( (EventList *)v2->_Myheader != v2 )
    {
      while ( 1 )
      {
        EnterCriticalSection(&stru_CF5744);
        v22 = v21[1]._Myheader;
        v51 = 0;
        a3 = (int)v22;
        v23 = (Data_t_bstr_t *)operator new(0xCu);
        v24 = v23;
        v49 = v23;
        LOBYTE(v53) = 1;
        if ( v23 )
        {
          v23->m_str = 0;
          v23->m_RefCount = 1;
          v25 = SysAllocString((const OLECHAR *)&gszNullString);
          v24->m_wstr = v25;
          if ( !v25 )
            goto LABEL_44;
        }
        else
        {
          v24 = 0;
        }
        LOBYTE(v53) = 0;
        if ( !v24 )
LABEL_44:
          _com_issue_error(-2147024882);
        v26 = (Data_t_bstr_t *)v22[4].field_0;
        if ( v26 == v24 )
          break;
        if ( v26 )
        {
          v27 = _bstr_t::Data_t::Compare(v26, v24);
        }
        else
        {
          if ( !v24->m_wstr || !SysStringLen(v24->m_wstr) )
            break;
          v27 = -1;
        }
LABEL_54:
        v50 = v27 != 0;
        if ( !InterlockedDecrement(&v24->m_RefCount) )
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
        if ( v50 )
        {
          v28 = (const wchar_t **)v22[4].field_0;
          if ( v28 )
            v29 = *v28;
          else
            v29 = 0;
          if ( wcsstr(v29, L"Throttle") )
          {
            v49 = *(void **)gList11;
            v30 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                    (EventList *)v49,
                    *((_DWORD **)v49 + 1),
                    &a3);
            if ( (unsigned int)(357913940 - (_DWORD)*(&gList11 + 1)) < 1 )
              goto LABEL_89;
            *(&gList11 + 1) = (char *)*(&gList11 + 1) + 1;
            *((_DWORD *)v49 + 1) = v30;
            v30->_Prev->_Next = v30;
            SetEvent(ghEventHandle2);
            goto LABEL_83;
          }
          v22->field_4 = 5;
        }
        else
        {
          v31 = (OLECHAR **)v22[4].field_4;
          if ( v31 && (v32 = *v31) != 0 && SysStringLen(v32) )
          {
            v33 = (const wchar_t **)v22[5].field_0;
            if ( v33 )
              v34 = *v33;
            else
              v34 = 0;
            if ( _wcsicmp(v34, L"Submitted") )
            {
              v22->field_4 = 1;
            }
            else
            {
              v49 = *(void **)gList11;
              v35 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                      (EventList *)v49,
                      *((_DWORD **)v49 + 1),
                      &a3);
              if ( (unsigned int)(357913940 - (_DWORD)*(&gList11 + 1)) < 1 )
                goto LABEL_89;
              *(&gList11 + 1) = (char *)*(&gList11 + 1) + 1;
              *((_DWORD *)v49 + 1) = v35;
              v35->_Prev->_Next = v35;
              SetEvent(ghEventHandle2);
            }
          }
          else
          {
            v22->field_4 = 6;
            if ( gConfig.bVirusTotalSubmitUnknown && LOBYTE(v22->field_0) )
            {
              v22->field_4 = 3;
              v49 = gList10._Mypair._Myval2._Myhead;
              v36 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                      (EventList *)gList10._Mypair._Myval2._Myhead,
                      &gList10._Mypair._Myval2._Myhead->_Prev->_Next,
                      &a3);
              if ( 357913940 - gList10._Mypair._Myval2._Mysize < 1 )
                goto LABEL_89;
              ++gList10._Mypair._Myval2._Mysize;
              *((_DWORD *)v49 + 1) = v36;
              v36->_Prev->_Next = v36;
              SetEvent(ghEventHandle3);
            }
          }
        }
        v51 = 1;
LABEL_83:
        LeaveCriticalSection(&stru_CF5744);
        if ( v51 )
          PostMessageW(ghMainWnd, 0x7F9u, 0, (LPARAM)v22);
        v21 = (EventList *)v21->_Myheader;
        v2 = (EventList *)v45;
        if ( v21 == (EventList *)v45 )
          goto LABEL_86;
      }
      v27 = 0;
      goto LABEL_54;
    }
LABEL_86:
    v37 = (EventList *)v2->_Myheader;
    v1 = 0;
    v2->_Myheader = (EventListNode *)v2;
    v2->_Mysize = (int)v2;
    v46 = 0;
    if ( v37 != v2 )
    {
      do
      {
        v38 = v37->_Myheader;
        operator delete(v37);
        v37 = (EventList *)v38;
      }
      while ( v38 != (EventListNode *)v2 );
    }
  }
  v39 = (EventList *)v2->_Myheader;
  v2->_Myheader = (EventListNode *)v2;
  v2->_Mysize = (int)v2;
  if ( v39 != v2 )
  {
    do
    {
      v40 = v39->_Myheader;
      operator delete(v39);
      v39 = (EventList *)v40;
    }
    while ( v40 != (EventListNode *)v2 );
  }
  operator delete(v2);
  return 0;
}

//----- (00C72860) --------------------------------------------------------
LRESULT __stdcall EditVTClassCallback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
  HWND v6; // eax
  DLLINFOLISTITEMPARAM *v7; // eax
  int v8; // eax
  const WCHAR **v9; // eax
  const WCHAR *v10; // eax
  int v12; // eax
  HCURSOR v13; // eax

  v6 = GetParent(hWnd);
  v7 = (DLLINFOLISTITEMPARAM *)GetWindowLongW(v6, GWLP_USERDATA);
  if ( v7->m_dwType )
    v8 = v7->m_ItemData1;
  else
    v8 = v7[2].field_3C;
  if ( uMsg != WM_MOUSEMOVE )
  {
    if ( uMsg == 514 && v8 && (*(_DWORD *)(v8 + 4) == 1 || *(_DWORD *)(v8 + 4) == 4) )
    {
      v9 = *(const WCHAR ***)(v8 + 36);
      if ( v9 )
        v10 = *v9;
      else
        v10 = 0;
      LaunchWebBrowser(hWnd, 0, v10);
    }
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
  }
  if ( !v8 )
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
  v12 = *(_DWORD *)(v8 + 4) - 1;
  if ( v12 )
  {
    if ( v12 != 3 )
      return DefSubclassProc(hWnd, uMsg, wParam, lParam);
  }
  v13 = LoadCursorW(ghInstance, L"HAND");
  SetCursor(v13);
  return 1;
}

//----- (00C72910) --------------------------------------------------------
char __cdecl sub_C72910(ListItemData1 *a1)
{
  wchar_t **v1; // eax
  wchar_t *v2; // eax
  char result; // al
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = 0;
  if ( a1->field_4 != 1 )
    return 0;
  v1 = (wchar_t **)a1[5].field_0;
  if ( v1 )
    v2 = *v1;
  else
    v2 = 0;
  scan_fn(v2, (int)L"%d/%d", (int)&v5);
  result = 0;
  if ( v5 )
    result = 1;
  return result;
}
// CA2BB0: using guessed type wchar_t aDD[6];

//----- (00C72970) --------------------------------------------------------
int __stdcall BackendThreadProc3(void *a1)
{
  DWORD (__stdcall *v1)(HANDLE, DWORD); // edi
  EventList *v2; // esi
  EventListNode *v3; // edi
  const wchar_t **v4; // eax
  const wchar_t *v5; // eax
  EventList *v6; // eax

  v1 = WaitForSingleObject;
  while ( v1(ghEventHandle, 0x2710u) == 258 )
  {
    if ( !sub_C137E0(&gHttpInfo) )
    {
      v2 = (EventList *)gList12->_Myheader;
      if ( (EventList *)gList12->_Myheader != gList12 )
      {
        do
        {
          EnterCriticalSection(&stru_CF5744);
          v3 = v2[1]._Myheader;
          v4 = (const wchar_t **)v3[5].field_0;
          if ( v4 )
            v5 = *v4;
          else
            v5 = 0;
          if ( _wcsicmp(v5, L"Submitted") )
          {
            v6 = v2;
            v3->field_4 = 1;
            v2 = (EventList *)v2->_Myheader;
            *(_DWORD *)v6->_Mysize = v6->_Myheader;
            v6->_Myheader->field_4 = v6->_Mysize;
            *(&gList12 + 1) = (EventList *)((char *)*(&gList12 + 1) - 1);
            operator delete(v6);
          }
          else
          {
            v2 = (EventList *)v2->_Myheader;
          }
          LeaveCriticalSection(&stru_CF5744);
        }
        while ( v2 != gList12 );
        v1 = WaitForSingleObject;
      }
      PostMessageW(ghMainWnd, 0x7F9u, 0, 0);
    }
  }
  return 0;
}

//----- (00C72A70) --------------------------------------------------------
_DWORD *__stdcall std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // edx

  result = operator new(0xCu);
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

//----- (00C72AB0) --------------------------------------------------------
void __stdcall sub_C72AB0(void *a1)
{
  _DWORD *v1; // edi
  void *i; // ebx
  int v3; // esi

  v1 = a1;
  for ( i = a1; !*((_BYTE *)i + 13); v1 = i )
  {
    sub_C72AB0(*((void **)i + 2));
    v3 = v1[4];
    i = *(void **)i;
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
      v1[4] = 0;
    }
    operator delete(v1);
  }
}

//----- (00C72B40) --------------------------------------------------------
_bstr_t *__thiscall sub_C72B40(void *this, _bstr_t *a2)
{
  _bstr_t *v2; // edi
  _bstr_t *v3; // esi
  Data_t_bstr_t *v4; // ecx
  Data_t_bstr_t *v6; // [esp-8h] [ebp-1Ch]
  Data_t_bstr_t *v7; // [esp-4h] [ebp-18h]

  v2 = *(_bstr_t **)this;
  v3 = *(_bstr_t **)(*(_DWORD *)this + 4);
  while ( !BYTE1(v3[3].m_Data) )
  {
    v7 = a2->m_Data;
    if ( a2->m_Data )
      InterlockedIncrement(&v7->m_RefCount);
    v4 = v3[4].m_Data;
    v6 = v4;
    if ( v4 )
      InterlockedIncrement(&v4->m_RefCount);
    if ( sub_C014B0(v6, v7) )
    {
      v3 = (_bstr_t *)v3[2].m_Data;
    }
    else
    {
      v2 = v3;
      v3 = (_bstr_t *)v3->m_Data;
    }
  }
  return v2;
}

//----- (00C72BB0) --------------------------------------------------------
std__Tree_node *__thiscall sub_C72BB0(std__tree *this, std__Tree_node *a2)
{
  std__Tree_node *v2; // esi
  std__Tree_node *v3; // eax
  std__Tree_node *result; // eax

  v2 = (std__Tree_node *)a2->_Left;
  a2->_Left = a2->_Left->_Right;
  v3 = (std__Tree_node *)v2->_Right;
  if ( !v3->_IsNil )
    v3->_Parent = (std_Tree_node_for_tagKeyName *)a2;
  v2->_Parent = a2->_Parent;
  result = this->_Mypair._Myval2._Myhead;
  if ( a2 == (std__Tree_node *)this->_Mypair._Myval2._Myhead->_Parent )
  {
    result->_Parent = (std_Tree_node_for_tagKeyName *)v2;
    v2->_Right = (std__Tree_node_For__bstr_t *)a2;
    a2->_Parent = (std_Tree_node_for_tagKeyName *)v2;
  }
  else
  {
    result = (std__Tree_node *)a2->_Parent;
    if ( a2 == (std__Tree_node *)result->_Right )
      result->_Right = (std__Tree_node_For__bstr_t *)v2;
    else
      result->_Left = (std_Tree_node_for_tagKeyName *)v2;
    v2->_Right = (std__Tree_node_For__bstr_t *)a2;
    a2->_Parent = (std_Tree_node_for_tagKeyName *)v2;
  }
  return result;
}

//----- (00C72C10) --------------------------------------------------------
int **__thiscall sub_C72C10(int **this, int **a2, int **a3, int **a4)
{
  int **v4; // eax
  int **v5; // esi
  int *v6; // ecx
  int **v7; // eax
  int *v8; // ecx
  int **result; // eax
  int **v10; // ecx
  int *i; // edx
  int *v12; // eax
  char v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  v6 = *this;
  if ( a3 != (int **)*v6 || a4 != (int **)v6 )
  {
    for ( ; a3 != a4; v4 = a3 )
    {
      v10 = v4;
      if ( !*((_BYTE *)v4 + 13) )
      {
        i = v4[2];
        if ( *((_BYTE *)i + 13) )
        {
          for ( i = v4[1]; !*((_BYTE *)i + 13); i = (int *)i[1] )
          {
            if ( v4 != (int **)i[2] )
              break;
            v4 = (int **)i;
          }
        }
        else
        {
          v12 = (int *)*i;
          if ( !*(_BYTE *)(*i + 13) )
          {
            do
            {
              i = v12;
              v12 = (int *)*v12;
            }
            while ( !*((_BYTE *)v12 + 13) );
          }
        }
        a3 = (int **)i;
      }
      sub_C72CD0(v5, &v13, v10);
    }
    *a2 = (int *)v4;
    result = a2;
  }
  else
  {
    sub_C72AB0((void *)v6[1]);
    (*v5)[1] = (int)*v5;
    **v5 = (int)*v5;
    (*v5)[2] = (int)*v5;
    v7 = (int **)*v5;
    v5[1] = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00C72CD0) --------------------------------------------------------
_DWORD *__thiscall sub_C72CD0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  std__tree *v3; // ebx
  _DWORD *v4; // edx
  std_Tree_node_for_tagKeyName *v5; // edi
  std__Tree_node *v6; // ecx
  std__Tree_node *v7; // esi
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std__Tree_node_For__bstr_t *v11; // eax
  std__Tree_node_For__bstr_t *i; // ecx
  std__Tree_node **v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  int v16; // esi
  unsigned int v17; // eax
  _DWORD *v18; // ecx
  _DWORD *result; // eax
  _DWORD *v20; // [esp+Ch] [ebp-8h]
  _DWORD *v21; // [esp+10h] [ebp-4h]

  v3 = (std__tree *)this;
  v21 = a3;
  sub_C04CE0((std__tree *)&a3);
  v4 = v21;
  if ( *(_BYTE *)(*v21 + 13) )
  {
    v5 = (std_Tree_node_for_tagKeyName *)v21[2];
  }
  else if ( *(_BYTE *)(v21[2] + 13) )
  {
    v5 = (std_Tree_node_for_tagKeyName *)*v21;
  }
  else
  {
    v6 = (std__Tree_node *)a3;
    v20 = a3;
    v5 = (std_Tree_node_for_tagKeyName *)a3[2];
    if ( a3 != v21 )
    {
      *(_DWORD *)(*v21 + 4) = a3;
      v6->_Left = (std_Tree_node_for_tagKeyName *)*v21;
      if ( v6 == (std__Tree_node *)v21[2] )
      {
        v7 = v6;
      }
      else
      {
        v7 = (std__Tree_node *)v6->_Parent;
        if ( !v5->_IsNil )
          v5->_Parent = (std_Tree_node_for_tagKeyName *)v7;
        v7->_Left = v5;
        v6->_Right = (std__Tree_node_For__bstr_t *)v21[2];
        *(_DWORD *)(v21[2] + 4) = v6;
      }
      if ( v3->_Mypair._Myval2._Myhead->_Parent == (std_Tree_node_for_tagKeyName *)v21 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v6;
      }
      else
      {
        v13 = (std__Tree_node **)v21[1];
        if ( *v13 == (std__Tree_node *)v21 )
          *v13 = v6;
        else
          v13[2] = v6;
      }
      v6->_Parent = (std_Tree_node_for_tagKeyName *)v21[1];
      v14 = v6->_Color;
      *((_BYTE *)v20 + 12) = *((_BYTE *)v21 + 12);
      v4 = v21;
      *((_BYTE *)v21 + 12) = v14;
      goto LABEL_37;
    }
  }
  v7 = (std__Tree_node *)v21[1];
  if ( !v5->_IsNil )
    v5->_Parent = (std_Tree_node_for_tagKeyName *)v7;
  if ( v3->_Mypair._Myval2._Myhead->_Parent == (std_Tree_node_for_tagKeyName *)v21 )
  {
    v3->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else if ( v7->_Left == (std_Tree_node_for_tagKeyName *)v21 )
  {
    v7->_Left = v5;
  }
  else
  {
    v7->_Right = (std__Tree_node_For__bstr_t *)v5;
  }
  v8 = v3->_Mypair._Myval2._Myhead;
  if ( &v3->_Mypair._Myval2._Myhead->_Left->_Left == v21 )
  {
    if ( v5->_IsNil )
    {
      v9 = v7;
    }
    else
    {
      v10 = (std__Tree_node *)v5->_Left;
      v9 = (std__Tree_node *)v5;
      if ( !v5->_Left->_IsNil )
      {
        do
        {
          v9 = v10;
          v10 = (std__Tree_node *)v10->_Left;
        }
        while ( !v10->_IsNil );
      }
      v8 = v3->_Mypair._Myval2._Myhead;
    }
    v8->_Left = (std_Tree_node_for_tagKeyName *)v9;
  }
  if ( v3->_Mypair._Myval2._Myhead->_Right == (std__Tree_node_For__bstr_t *)v21 )
  {
    if ( v5->_IsNil )
    {
      v3->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v7;
    }
    else
    {
      v11 = (std__Tree_node_For__bstr_t *)v5->_Right;
      for ( i = (std__Tree_node_For__bstr_t *)v5; !v11->_IsNil; v11 = (std__Tree_node_For__bstr_t *)v11->_Right )
        i = v11;
      v3->_Mypair._Myval2._Myhead->_Right = i;
    }
  }
LABEL_37:
  if ( *((_BYTE *)v4 + 12) != 1 )
    goto LABEL_62;
  if ( v5 == v3->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->_Color == 1 )
  {
    v15 = (std__Tree_node *)v7->_Left;
    if ( v5 == v7->_Left )
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
    v5 = (std_Tree_node_for_tagKeyName *)v7;
    v7 = (std__Tree_node *)v7->_Parent;
    if ( v5 == v3->_Mypair._Myval2._Myhead->_Parent )
      break;
  }
  v4 = v21;
LABEL_61:
  v5->_Color = 1;
LABEL_62:
  v16 = v4[4];
  if ( v16 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v16 + 8)) && v16 )
    {
      if ( *(_DWORD *)v16 )
      {
        SysFreeString(*(BSTR *)v16);
        *(_DWORD *)v16 = 0;
      }
      if ( *(_DWORD *)(v16 + 4) )
      {
        operator delete[](*(void **)(v16 + 4));
        *(_DWORD *)(v16 + 4) = 0;
      }
      operator delete((void *)v16);
    }
    v4 = v21;
    v21[4] = 0;
  }
  operator delete(v4);
  v17 = v3->_Mypair._Myval2._Mysize;
  v18 = a3;
  if ( v17 )
    v3->_Mypair._Myval2._Mysize = v17 - 1;
  result = a2;
  *a2 = v18;
  return result;
}

//----- (00C72F90) --------------------------------------------------------
int *__thiscall sub_C72F90(int *this, int *a2, volatile LONG **a3)
{
  int *v3; // edi
  _bstr_t *v4; // eax
  int v5; // esi
  Data_t_bstr_t *v6; // ecx
  int *result; // eax
  Data_t_bstr_t *v8; // [esp-8h] [ebp-14h]
  Data_t_bstr_t *v9; // [esp-4h] [ebp-10h]

  v3 = this;
  v4 = sub_C72B40(this, (_bstr_t *)a3);
  v5 = (int)v4;
  if ( v4 == (_bstr_t *)*v3 )
    goto LABEL_11;
  v6 = v4[4].m_Data;
  v9 = v6;
  if ( v6 )
    InterlockedIncrement(&v6->m_RefCount);
  v8 = (Data_t_bstr_t *)*a3;
  if ( *a3 )
    InterlockedIncrement(&v8->m_RefCount);
  if ( sub_C014B0(v8, v9) )
  {
LABEL_11:
    result = a2;
    *a2 = *v3;
  }
  else
  {
    result = a2;
    *a2 = v5;
  }
  return result;
}

//----- (00C73010) --------------------------------------------------------
HANDLE LoadSharedMemory()
{
  HANDLE v0; // eax
  void *v1; // ebx
  HANDLE result; // eax
  HANDLE v3; // eax
  char *v4; // esi
  DWORD (__stdcall *v5)(); // ebx
  const WCHAR *v6; // ecx
  HANDLE v7; // edi
  HANDLE v8; // ebx
  HANDLE hHandle; // [esp+8h] [ebp-8h]
  HANDLE hEvent; // [esp+Ch] [ebp-4h]

  LoadDbgHelp(L"Dbghelp.dll");
  v0 = CreateEventW(0, 0, 0, L"Procexp32bitServerEvent");
  v1 = v0;
  hHandle = v0;
  result = CreateEventW(0, 0, 0, L"Procexp32bitClientEvent");
  hEvent = result;
  if ( result )
  {
    if ( v1 )
    {
      v3 = CreateFileMappingW((HANDLE)0xFFFFFFFF, 0, 0x8000004u, 0, gSystemInfo.dwPageSize, L"Procexp32bitSection");
      v4 = (char *)MapViewOfFile(v3, 6u, 0, 0, gSystemInfo.dwPageSize);
      result = (HANDLE)WaitForSingleObject(v1, 0xFFFFFFFF);
      if ( !result )
      {
        v5 = GetLastError;
        v6 = (const WCHAR *)(v4 + 12);
        do
        {
          v7 = CreateFileW(v6, GENERIC_WRITE, 7u, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
          if ( v7 == (HANDLE)-1 )
          {
            *((_DWORD *)v4 + 2) = v5();
          }
          else
          {
            v8 = OpenProcess(PROCESS_TRACE_MODE_EVENT_RECORD, 0, *(_DWORD *)v4);
            if ( v8 )
            {
              if ( !(unsigned __int8)DumpFileProcess((int)v7, v8, v4[4]) )
                *((_DWORD *)v4 + 2) = GetLastError();
              CloseHandle(v8);
              v5 = GetLastError;
            }
            else
            {
              v5 = GetLastError;
              *((_DWORD *)v4 + 2) = GetLastError();
            }
            CloseHandle(v7);
          }
          SetEvent(hEvent);
          result = (HANDLE)WaitForSingleObject(hHandle, 0xFFFFFFFF);
          v6 = (const WCHAR *)(v4 + 12);
        }
        while ( !result );
      }
    }
  }
  return result;
}

//----- (00C73150) --------------------------------------------------------
signed int sub_C73150()
{
  if ( (unsigned __int8)GetVersion() < 6u )
    MessageBoxW(
      0,
      L"Usage: Process Explorer [/t] [/p:[r|h|l]] [/s:<PID>]\n"
       "\n"
       "/t\tStart minimized in the tray\n"
       "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
       "/s\tSelect the specified process\n",
      L"Process Explorer",
      0x40u);
  else
    MessageBoxW(
      0,
      L"Usage: Process Explorer [/e] [/t] [/p:[r|h|l]] [/s:<PID>]\n"
       "\n"
       "/e\tRequest UAC elevation\n"
       "/t\tStart minimized in the tray\n"
       "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
       "/s\tSelect the specified process\n",
      L"Process Explorer",
      0x40u);
  return -1;
}

//----- (00C73190) --------------------------------------------------------
int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
  HMODULE v4; // eax
  void (__stdcall *GetNativeSystemInfo)(); // eax
  int result; // eax
  __int16 dwVersion; // ax
  int dwPlatform; // eax
  HANDLE v9; // eax
  int nIndex_1; // esi
  wchar_t *pszArgs; // edx
  int nArgLength; // eax
  int nChar; // ecx
  int v14; // ecx
  int v15; // eax
  wchar_t *v16; // eax
  int v17; // esi
  wchar_t *v18; // ecx
  int v19; // edi
  wchar_t v20; // ax
  wchar_t *v21; // ecx
  int v22; // eax
  HANDLE v23; // eax
  DWORD v24; // eax
  HACCEL v25; // ebx
  HWND v26; // eax
  DWORD v27; // [esp-8h] [ebp-C0h]
  struct tagMSG Msg; // [esp+8h] [ebp-B0h]
  HINSTANCE hInst; // [esp+24h] [ebp-94h]
  const WCHAR *lpCmdLine_1; // [esp+28h] [ebp-90h]
  int nIndex; // [esp+2Ch] [ebp-8Ch]
  int v32; // [esp+30h] [ebp-88h]
  char v33; // [esp+33h] [ebp-85h]
  wchar_t *ppszArgs[32]; // [esp+34h] [ebp-84h]

  hInst = hInstance;
  lpCmdLine_1 = lpCmdLine;
  v33 = 0;
  v4 = LoadLibraryW(L"kernel32.dll");
  GetNativeSystemInfo = (void (__stdcall *)())GetProcAddress(v4, "GetNativeSystemInfo");
  if ( GetNativeSystemInfo )
    GetNativeSystemInfo();
  else
    GetSystemInfo(&gSystemInfo);
  if ( Fake_IsWow64Process() )
  {
    _beginthread((int)LoadSharedMemory, 0, (int)hInstance);
    if ( LaunchProcExplorer64(1, nShowCmd) )
      return 0;
    MessageBoxW(
      0,
      L"Unable to extract 64-bit image. Run Process Explorer from a writeable directory.",
      L"Process Explorer",
      0x10u);
    return 1;
  }
  gdwTebAddressOffset = 0xF60;
  dwVersion = GetVersion();
  if ( (unsigned __int8)dwVersion >= 5u )
  {
    gdwVersion = 0;
    if ( (unsigned __int8)dwVersion < 0xAu )
    {
      if ( (unsigned __int8)dwVersion >= 6u )
      {
        dwPlatform = HIBYTE(dwVersion);
        if ( dwPlatform )
        {
          if ( dwPlatform == 1 )
            gdwVersion = WINDOWS_7;
          else
            gdwVersion = WINDOWS_8;
        }
        else
        {
          gdwVersion = WINDOWS_VISTA;
        }
      }
    }
    else
    {
      gdwVersion = WINDOWS_10;
    }
  }
  v9 = GetCurrentProcess();
  SetPriorityClass(v9, HIGH_PRIORITY_CLASS);
  nIndex_1 = 0;
  gszCmdLine = (int)lpCmdLine;
  nIndex = 0;
  ppszArgs[0] = lpCmdLine;
  if ( *lpCmdLine )
  {
    do
    {
      pszArgs = ppszArgs[nIndex_1];
      nArgLength = 0;
      if ( *pszArgs )
      {
        nChar = 0;
        do
        {
          if ( pszArgs[nChar] == ' ' )
            break;
          nChar = ++nArgLength;
        }
        while ( pszArgs[nArgLength] );
        if ( nArgLength )
          nIndex = ++nIndex_1;
      }
      v14 = 2 * nArgLength;
      v15 = *(&v32 + nIndex_1);
      if ( !*(_WORD *)(v15 + v14) )
        break;
      *(_WORD *)(v15 + v14) = 0;
      nIndex_1 = nIndex;
      v16 = (wchar_t *)(v14 + *(&v32 + nIndex) + 2);
      ppszArgs[nIndex] = v16;
      if ( nIndex_1 == ' ' )
        break;
    }
    while ( *v16 );
  }
  if ( !LicenseCheck(L"Process Explorer", (int)&nIndex, (int)ppszArgs) )
    return 1;
  v17 = 0;
  if ( nIndex <= 0 )
  {
LABEL_61:
    if ( !CMainWnd::Create(hInst, nShowCmd) )
      return 0;
    v25 = LoadAcceleratorsW(hInst, L"PROCEXPLORER");
    if ( !GetMessageW(&Msg, 0, 0, 0) )
      return 0;
    while ( 1 )
    {
      v26 = ghWndThreadStack;
      if ( ghWndThreadStack )
      {
        if ( TranslateAcceleratorW(ghWndThreadStack, v25, &Msg) )
          goto LABEL_73;
        v26 = ghWndThreadStack;
      }
      if ( !ghFindDlg )
        goto LABEL_69;
      if ( !IsDialogMessageW(ghFindDlg, &Msg) )
      {
        v26 = ghWndThreadStack;
LABEL_69:
        if ( (!v26 || !IsDialogMessageW(v26, &Msg)) && !TranslateAcceleratorW(ghMainWnd, v25, &Msg) )
        {
          TranslateMessage(&Msg);
          DispatchMessageW(&Msg);
        }
      }
LABEL_73:
      if ( !GetMessageW(&Msg, 0, 0, 0) )
        return 0;
    }
  }
  while ( 2 )
  {
    v18 = ppszArgs[v17];
    v19 = (int)(v18 + 1);
    do
    {
      v20 = *v18;
      ++v18;
    }
    while ( v20 );
    _wcsupr_s(ppszArgs[v17], (((signed int)v18 - v19) >> 1) + 1);
    v21 = ppszArgs[v17];
    v22 = *v21;
    if ( v22 != 47 && v22 != 45 )
    {
      if ( !wcsstr(v21, L"TASKMGR") )
        return sub_C73150();
LABEL_48:
      if ( v33 && !IsBuiltinAdministrative() )
      {
        v24 = sub_C36180(lpCmdLine_1, nShowCmd, 0);
        if ( v24 )
        {
          if ( v24 != 1223 )
            ReportMsg(L"Error elevating", ghMainWnd);
          return 1;
        }
        return 0;
      }
      goto LABEL_61;
    }
    switch ( v21[1] )
    {
      case 0x45u:
        if ( (unsigned __int8)GetVersion() < 6u )
          return sub_C73150();
        v33 = 1;
        goto LABEL_45;
      case 0x50u:
        if ( v21[2] == 58 )
        {
          switch ( v21[3] )
          {
            case 0x48u:
              goto LABEL_45;
            case 0x4Cu:
              v27 = 64;
              goto LABEL_44;
            case 0x4Eu:
              v27 = 32;
              goto LABEL_44;
            case 0x52u:
              v27 = 256;
LABEL_44:
              v23 = GetCurrentProcess();
              SetPriorityClass(v23, v27);
              goto LABEL_45;
            default:
              return sub_C73150();
          }
        }
        return sub_C73150();
      case 0x52u:
        if ( v21[2] != 84 )
          return sub_C73150();
        Command_ReplaceTaskManager(0);
        return 0;
      case 0x53u:
        if ( v21[2] != 58 )
          return sub_C73150();
        gdwProcessId_0 = _wtoi(v21 + 3);
        goto LABEL_45;
      case 0x54u:
        gbHide = 1;
LABEL_45:
        if ( ++v17 >= nIndex )
          goto LABEL_48;
        continue;
      default:
        if ( (unsigned __int8)GetVersion() < 6u )
          MessageBoxW(
            0,
            L"Usage: Process Explorer [/t] [/p:[r|h|l]] [/s:<PID>]\n"
             "\n"
             "/t\tStart minimized in the tray\n"
             "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
             "/s\tSelect the specified process\n",
            L"Process Explorer",
            0x40u);
        else
          MessageBoxW(
            0,
            L"Usage: Process Explorer [/e] [/t] [/p:[r|h|l]] [/s:<PID>]\n"
             "\n"
             "/e\tRequest UAC elevation\n"
             "/t\tStart minimized in the tray\n"
             "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
             "/s\tSelect the specified process\n",
            L"Process Explorer",
            0x40u);
        result = -1;
        break;
    }
    return result;
  }
}
// CCE100: using guessed type int gdwProcessId_0;
// CD4E54: using guessed type int gdwVersion;
// CDA388: using guessed type char gbHide;
// CDA38C: using guessed type int gszCmdLine;
// CDB1CC: using guessed type int gdwTebAddressOffset;

//----- (00C736C0) --------------------------------------------------------
wchar_t *__cdecl sub_C736C0(wchar_t *Src)
{
  size_t v2; // eax
  rsize_t v3; // ebx
  wchar_t *v4; // eax
  wchar_t *v5; // esi

  if ( !Src )
    return 0;
  v2 = wcsnlen(Src, 0xFFu);
  v3 = v2 + 1;
  v4 = (wchar_t *)malloc(2 * (v2 + 1));
  v5 = v4;
  if ( !v4 || !wcscpy_s(v4, v3, Src) )
    return v5;
  free(v5);
  return 0;
}

//----- (00C73720) --------------------------------------------------------
int __cdecl sub_C73720(int a1, int a2, wchar_t *a3, int a4, int a5)
{
  int *v5; // edi
  void *v6; // esi
  int v8; // edi

  v5 = (int *)a1;
  if ( !a1 || !a2 || !a3 || !a4 || !a5 )
    return -2147024809;
  v6 = malloc(0x190u);
  if ( !v6 )
    return -2147024882;
  a1 = 0;
  v8 = sub_C737B0(v5, a2, (int)v6, &a1);
  if ( !v8 )
    v8 = sub_C738A0(a3, (int)v6, a1, a4, a5);
  free(v6);
  return v8;
}

//----- (00C737B0) --------------------------------------------------------
int __cdecl sub_C737B0(int *a1, int a2, int a3, _DWORD *a4)
{
  int *v4; // ecx
  int v5; // edi
  _DWORD *v6; // esi
  int v7; // eax
  int result; // eax
  int *v9; // ecx
  int v10; // ebx
  int v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]

  v4 = a1;
  if ( !a1 )
    return -2147024809;
  if ( !a2 )
    return -2147024809;
  v5 = a3;
  if ( !a3 )
    return -2147024809;
  v6 = a4;
  if ( !a4 )
    return -2147024809;
  v7 = *a1;
  a1 = 0;
  v12 = 0;
  v11 = 0;
  result = (*(int (__stdcall **)(int *, const OLECHAR *, int, signed int, _DWORD, int **))(v7 + 80))(
             v4,
             L"WQL",
             a2,
             48,
             0,
             &a1);
  if ( result >= 0 )
  {
    v9 = a1;
    if ( a1 )
    {
      while ( 1 )
      {
        v10 = (*(int (__stdcall **)(int *, signed int, signed int, int *, int *))(*v9 + 16))(v9, -1, 1, &v12, &v11);
        if ( v10 < 0 )
        {
          if ( a1 )
            (*(void (__stdcall **)(int *))(*a1 + 8))(a1);
          return v10;
        }
        if ( !v11 )
          break;
        *(_DWORD *)(v5 + 4 * (*v6)++) = v12;
        if ( *v6 >= 0x64u )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v12 + 8))(v12);
          break;
        }
        v9 = a1;
        if ( !a1 )
          goto LABEL_11;
      }
      if ( !a1 )
        goto LABEL_11;
      (*(void (__stdcall **)(int *))(*a1 + 8))(a1);
      result = 0;
    }
    else
    {
LABEL_11:
      result = 0;
    }
  }
  return result;
}

//----- (00C738A0) --------------------------------------------------------
int __cdecl sub_C738A0(wchar_t *a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // edi
  int v6; // esi
  VARIANTARG pvarg; // [esp+4h] [ebp-18h]
  unsigned int v9; // [esp+14h] [ebp-8h]
  int Value; // [esp+18h] [ebp-4h]

  if ( !a1 || !a2 || !a4 || !a5 )
    return -2147024809;
  VariantInit(&pvarg);
  v5 = 0;
  if ( !a3 )
    return 0;
  do
  {
    v6 = *(_DWORD *)(a2 + 4 * v5);
    *(_DWORD *)(a2 + 4 * v5) = 0;
    if ( (*(int (__stdcall **)(int, const wchar_t *, _DWORD, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)v6 + 16))(
           v6,
           L"hostprocessidentifier",
           0,
           &pvarg,
           0,
           0)
      || pvarg.vt != 3
      || !pvarg.lVal
      || (Value = 0, _set_errno(0), v9 = wcstoul(a1, 0, 10), _get_errno(&Value), v9 == -1)
      || Value
      || pvarg.lVal != v9 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
    }
    else
    {
      *(_DWORD *)(a4 + 4 * (*(_DWORD *)a5)++) = v6;
      if ( *(_DWORD *)a5 >= 0x64u )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
        return 0;
      }
    }
    ++v5;
  }
  while ( v5 < a3 );
  return 0;
}
// CB7564: using guessed type wchar_t aHostprocesside[22];

//----- (00C739A0) --------------------------------------------------------
MACRO_HRESULT __cdecl sub_C739A0(int *a1)
{
  int v2; // edi
  void **v3; // esi

  if ( !a1 )
    return E_INVALIDARG;
  v2 = *a1;
  while ( v2 )
  {
    v3 = (void **)v2;
    v2 = *(_DWORD *)(v2 + 12);
    free(*v3);
    free(v3[1]);
    free(v3[2]);
    free(v3);
  }
  *a1 = 0;
  return 0;
}

//----- (00C73A00) --------------------------------------------------------
int __cdecl sub_C73A00(int ArgList, int a2)
{
  signed int v2; // ebx
  _DWORD *v3; // esi
  HRESULT v4; // eax
  int v5; // eax
  HRESULT v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // ebx
  __m128i *v12; // eax
  __int64 v14; // [esp+8h] [ebp-2A0h]
  int v15; // [esp+10h] [ebp-298h]
  _DWORD *v16; // [esp+14h] [ebp-294h]
  int v17; // [esp+18h] [ebp-290h]
  LPVOID ppv; // [esp+1Ch] [ebp-28Ch]
  IUnknown *pProxy; // [esp+20h] [ebp-288h]
  wchar_t Dst; // [esp+24h] [ebp-284h]
  char v21; // [esp+9Ch] [ebp-20Ch]
  wchar_t Src; // [esp+224h] [ebp-84h]

  MakeDeviceName(&Src, L"%d", ArgList);
  if ( !a2 )
    return -2147024809;
  ppv = 0;
  v2 = 0;
  pProxy = 0;
  v3 = 0;
  v4 = CoCreateInstance(&CLSID_WbemLocator, 0, 1u, &IID_IWbemLocator, &ppv);
  if ( v4 < 0 )
  {
    v2 = v4;
    goto LABEL_24;
  }
  v5 = (*(int (__stdcall **)(LPVOID, const wchar_t *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IUnknown **))(*(_DWORD *)ppv + 12))(
         ppv,
         L"root/cimv2",
         0,
         0,
         0,
         0,
         0,
         0,
         &pProxy);
  if ( v5 < 0 )
  {
    v2 = v5;
    goto LABEL_24;
  }
  v6 = CoSetProxyBlanket(pProxy, 0xAu, 0, 0, 3u, 3u, 0, 0);
  if ( v6 < 0 )
  {
    v2 = v6;
    goto LABEL_24;
  }
  qmemcpy(&Dst, L"select * from msft_providers where HostProcessIdentifier = ", 0x78u);
  memset(&v21, 0, 0x186u);
  if ( wcscat_s(&Dst, 0xFFu, &Src) )
  {
    v2 = -2147418113;
    v3 = 0;
    goto LABEL_24;
  }
  v7 = malloc(0x190u);
  v3 = v7;
  v16 = v7;
  if ( !v7 )
  {
    v2 = -2147024882;
    goto LABEL_24;
  }
  v17 = 0;
  if ( sub_C737B0((int *)pProxy, (int)&Dst, (int)v7, &v17) )
  {
    v8 = sub_C73720((int)pProxy, (int)L"select * from msft_providers", &Src, (int)v3, (int)&v17);
    if ( v8 )
    {
      v2 = v8;
      goto LABEL_24;
    }
  }
  v9 = 0;
  if ( (unsigned int)v17 > 0 )
  {
    while ( 1 )
    {
      v10 = v3[v9];
      v14 = 0i64;
      v15 = 0;
      if ( !sub_C73CB0(v10, (int)ppv, (void **)&v14) )
      {
        v11 = v15;
        if ( v15 )
        {
          if ( (_DWORD)v14 && HIDWORD(v14) )
          {
            v12 = (__m128i *)malloc(0x10u);
            if ( !v12 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 8))(v10);
              v3 = v16;
              v2 = -2147024882;
              break;
            }
            _mm_storel_epi64(v12, _mm_loadl_epi64((const __m128i *)&v14));
            v12->m128i_i32[2] = v11;
            v12->m128i_i32[3] = *(_DWORD *)a2;
            *(_DWORD *)a2 = v12;
          }
        }
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 8))(v10);
      v3 = v16;
      if ( ++v9 >= (unsigned int)v17 )
      {
        v2 = 0;
        break;
      }
    }
  }
LABEL_24:
  if ( pProxy )
    pProxy->lpVtbl->Release(pProxy);
  if ( ppv )
    (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
  if ( v3 )
    free(v3);
  return v2;
}
// CB7494: using guessed type wchar_t aRootCimv2[11];
// CB74B0: using guessed type wchar_t aSelectFromMsft[60];
// CB7528: using guessed type wchar_t aSelectFromMsft_0[29];

//----- (00C73CB0) --------------------------------------------------------
signed int __cdecl sub_C73CB0(int a1, int a2, void **a3)
{
  void **v3; // edi
  signed int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  const wchar_t *v11; // esi
  wchar_t *v12; // eax
  wchar_t *v13; // eax
  wchar_t *v14; // eax
  VARIANTARG v16; // [esp+8h] [ebp-654h]
  VARIANTARG pvarg; // [esp+18h] [ebp-644h]
  VARIANTARG v18; // [esp+28h] [ebp-634h]
  DWORD cbData; // [esp+38h] [ebp-624h]
  int v20; // [esp+3Ch] [ebp-620h]
  int v21; // [esp+40h] [ebp-61Ch]
  HKEY phkResult; // [esp+44h] [ebp-618h]
  int v23; // [esp+48h] [ebp-614h]
  int v24; // [esp+4Ch] [ebp-610h]
  int v25; // [esp+50h] [ebp-60Ch]
  void **v26; // [esp+54h] [ebp-608h]
  wchar_t Data[256]; // [esp+58h] [ebp-604h]
  wchar_t Dst; // [esp+258h] [ebp-404h]
  char v29; // [esp+2B2h] [ebp-3AAh]
  WCHAR SubKey[8]; // [esp+458h] [ebp-204h]
  __int128 v31; // [esp+468h] [ebp-1F4h]
  __int128 v32; // [esp+478h] [ebp-1E4h]
  char v33; // [esp+488h] [ebp-1D4h]

  v20 = a2;
  v3 = a3;
  v26 = a3;
  if ( !a1 || !a2 || !a3 )
    return -2147024809;
  v23 = 0;
  v24 = 0;
  v4 = 0;
  v21 = 0;
  v25 = 0;
  VariantInit(&pvarg);
  VariantInit(&v18);
  v5 = (*(int (__stdcall **)(int, const wchar_t *, _DWORD, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)a1 + 16))(
         a1,
         L"namespace",
         0,
         &pvarg,
         0,
         0);
  if ( !v5 )
  {
    v6 = (*(int (__stdcall **)(int, const wchar_t *, _DWORD, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)a1 + 16))(
           a1,
           L"provider",
           0,
           &v18,
           0,
           0);
    if ( v6 )
    {
      v4 = v6;
      goto LABEL_38;
    }
    if ( v18.vt != 8 || pvarg.vt != 8 || !v18.lVal || !pvarg.lVal )
    {
      v4 = -2147418113;
      goto LABEL_38;
    }
    v7 = (*(int (__stdcall **)(int, LONG, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int *))(*(_DWORD *)v20 + 12))(
           v20,
           pvarg.lVal,
           0,
           0,
           0,
           0,
           0,
           0,
           &v25);
    if ( v7 < 0 )
    {
      v4 = v7;
      goto LABEL_38;
    }
    qmemcpy(&Dst, L"select * from __win32provider where Name = '", 0x5Au);
    memset(&v29, 0, 0x1A4u);
    if ( !wcscat_s(&Dst, 0xFFu, v18.bstrVal) && !wcscat_s(&Dst, 0xFFu, L"'") )
    {
      v8 = (*(int (__stdcall **)(int, const OLECHAR *, wchar_t *, signed int, _DWORD, int *))(*(_DWORD *)v25 + 80))(
             v25,
             L"WQL",
             &Dst,
             48,
             0,
             &v23);
      if ( v8 )
      {
        v4 = v8;
LABEL_37:
        v3 = v26;
        goto LABEL_38;
      }
      v9 = (*(int (__stdcall **)(int, signed int, signed int, int *, int *))(*(_DWORD *)v23 + 16))(
             v23,
             -1,
             1,
             &v24,
             &v21);
      if ( v9 )
      {
        v4 = v9;
        goto LABEL_37;
      }
      VariantInit(&v16);
      v10 = (*(int (__stdcall **)(int, const wchar_t *, _DWORD, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)v24 + 16))(
              v24,
              L"clsid",
              0,
              &v16,
              0,
              0);
      if ( v10 )
      {
        v4 = v10;
        goto LABEL_37;
      }
      if ( v16.vt != 8 )
        goto LABEL_37;
      v11 = v16.bstrVal;
      if ( !v16.lVal )
        goto LABEL_37;
      _mm_storeu_si128((__m128i *)SubKey, _mm_loadu_si128((const __m128i *)&xmmword_CB7624));
      _mm_storeu_si128((__m128i *)&v31, _mm_loadu_si128((const __m128i *)&xmmword_CB7634));
      _mm_storeu_si128((__m128i *)&v32, _mm_loadu_si128((const __m128i *)&xmmword_CB7644));
      memset(&v33, 0, 0x1CEu);
      if ( !wcscat_s(SubKey, 0xFFu, v11)
        && !wcscat_s(SubKey, 0xFFu, L"\\InprocServer32")
        && !RegOpenKeyExW(HKEY_LOCAL_MACHINE, SubKey, 0, 0x20119u, &phkResult) )
      {
        memset(Data, 0, 0x1FEu);
        cbData = 510;
        if ( !RegQueryValueExW(phkResult, (LPCWSTR)&gszNullString, 0, 0, (LPBYTE)Data, &cbData) )
        {
          v12 = sub_C736C0(v18.bstrVal);
          v3 = v26;
          *v26 = v12;
          if ( v12 )
          {
            v13 = sub_C736C0(pvarg.bstrVal);
            v3[1] = v13;
            if ( v13 )
            {
              v14 = sub_C736C0(Data);
              v3[2] = v14;
              if ( v14 )
                RegCloseKey(phkResult);
              else
                v4 = -2147024882;
            }
            else
            {
              v4 = -2147024882;
            }
          }
          else
          {
            v4 = -2147024882;
          }
          goto LABEL_38;
        }
      }
    }
    v4 = -2147418113;
    goto LABEL_37;
  }
  v4 = v5;
LABEL_38:
  if ( v24 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v24 + 8))(v24);
  if ( v23 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v23 + 8))(v23);
  if ( v25 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v25 + 8))(v25);
  VariantClear(&pvarg);
  VariantClear(&v18);
  if ( v4 )
  {
    if ( *v3 )
      free(*v3);
    if ( v3[1] )
      free(v3[1]);
    if ( v3[2] )
      free(v3[2]);
  }
  return v4;
}
// CB7590: using guessed type wchar_t aNamespace_0[10];
// CB75A4: using guessed type wchar_t aProvider[9];
// CB75B8: using guessed type wchar_t aSelectFromWin3[45];
// CB7618: using guessed type wchar_t aClsid_0[6];
// CB7624: using guessed type __int128 xmmword_CB7624;
// CB7634: using guessed type __int128 xmmword_CB7634;
// CB7644: using guessed type __int128 xmmword_CB7644;

//----- (00C74170) --------------------------------------------------------
void __stdcall __noreturn _com_issue_error(int a1)
{
  ATL::_com_error::_com_error(a1, 0);
}
// CD138C: using guessed type int (__cdecl *ATL::_com_error::_com_error)(_DWORD, _DWORD);

//----- (00C74190) --------------------------------------------------------
_DWORD *__thiscall sub_C74190(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  int v3; // ecx

  v2 = this;
  *this = &ATL::_com_error::`vftable';
  this[1] = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 8);
  v2[2] = v3;
  v2[3] = 0;
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 4))(v3);
  return v2;
}
// CB7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (00C741D0) --------------------------------------------------------
HLOCAL __thiscall ATL::_com_error::~_com_error(ATL::_com_error *this)
{
  ATL::_com_error *v1; // esi
  int v2; // ecx
  HLOCAL result; // eax

  v1 = this;
  v2 = *((_DWORD *)this + 2);
  *(_DWORD *)v1 = &ATL::_com_error::`vftable';
  if ( v2 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
  result = (HLOCAL)*((_DWORD *)v1 + 3);
  if ( result )
    result = LocalFree(*((HLOCAL *)v1 + 3));
  return result;
}
// CB7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (00C74200) --------------------------------------------------------
HLOCAL *__thiscall ATL::_com_error::`scalar deleting destructor'(void *this, char a2)
{
  HLOCAL *v2; // esi
  int v3; // ecx

  v2 = (HLOCAL *)this;
  v3 = *((_DWORD *)this + 2);
  *v2 = &ATL::_com_error::`vftable';
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
  if ( v2[3] )
    LocalFree(v2[3]);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CB7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (00C74240) --------------------------------------------------------
void __cdecl __noreturn sub_C74240(int a1, int a2)
{
  int (__thiscall **v2)(void *, char); // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ch] [ebp-4h]

  v3 = a1;
  v4 = a2;
  v2 = &ATL::_com_error::`vftable';
  v5 = 0;
  _CxxThrowException(&v2, &_TI1_AV_com_error__);
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CB7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);
// CC5BFC: using guessed type int _TI1_AV_com_error__;

//----- (00C74270) --------------------------------------------------------
CHAR *__stdcall _com_util::ConvertBSTRToString(LPCWSTR lpWideCharStr)
{
  unsigned int v2; // kr00_4
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  CHAR *v6; // eax
  CHAR *v7; // esi
  int v8; // eax
  int v9; // [esp+0h] [ebp-20h]
  int *v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-4h]

  v10 = &v9;
  if ( !lpWideCharStr )
    return 0;
  v2 = wcslen(lpWideCharStr);
  v3 = WideCharToMultiByte(0, 0, lpWideCharStr, v2 + 1, 0, 0, 0, 0);
  v4 = v3;
  if ( !v3 )
  {
    v5 = GetLastError();
    if ( v5 > 0 )
      v5 = (unsigned __int16)v5 | 0x80070000;
    _com_issue_error(v5);
  }
  v11 = 0;
  v6 = (CHAR *)operator new(v3);
  v7 = v6;
  v11 = -1;
  if ( !v6 )
    _com_issue_error(E_OUTOFMEMORY);
  if ( !WideCharToMultiByte(0, 0, lpWideCharStr, v2 + 1, v6, v4, 0, 0) )
  {
    operator delete(v7);
    v8 = GetLastError();
    if ( v8 > 0 )
      v8 = (unsigned __int16)v8 | 0x80070000;
    _com_issue_error(v8);
  }
  return v7;
}

//----- (00C74390) --------------------------------------------------------
BSTR __stdcall _com_util::ConvertStringToBSTR(LPCSTR lpszText)
{
  int nLength; // eax
  int ret; // eax
  int ret_1; // edi
  int v5; // eax
  int v6; // eax
  void *v7; // esp
  WCHAR *pBuf; // esi
  int v9; // eax
  BSTR v10; // ebx
  WCHAR v11[8]; // [esp+0h] [ebp-38h]
  int v12; // [esp+10h] [ebp-28h]
  WCHAR *pWideString; // [esp+14h] [ebp-24h]
  int cbMultiByte; // [esp+18h] [ebp-20h]
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]

  if ( !lpszText )
    return 0;
  nLength = lstrlenA(lpszText);
  cbMultiByte = nLength + 1;
  ret = MultiByteToWideChar(CP_ACP, 0, lpszText, nLength + 1, 0, 0);
  ret_1 = ret;
  v12 = ret;
  if ( !ret )
  {
    v5 = GetLastError();
    if ( v5 > 0 )
      v5 = (unsigned __int16)v5 | 0x80070000;
    _com_issue_error(v5);
  }
  ms_exc.registration.TryLevel = 0;
  v6 = 2 * ret;
  if ( ret_1 >= 4096 )
  {
    pBuf = (WCHAR *)malloc(2 * ret_1);
    pWideString = pBuf;
  }
  else
  {
    v7 = alloca(v6);
    ms_exc.old_esp = (DWORD)v11;
    pBuf = v11;
    pWideString = v11;
  }
  ms_exc.registration.TryLevel = -2;
  if ( !pBuf )
    _com_issue_error(E_OUTOFMEMORY);
  if ( !MultiByteToWideChar(0, 0, lpszText, cbMultiByte, pBuf, ret_1) )
  {
    if ( ret_1 >= 4096 )
      free(pBuf);
    v9 = GetLastError();
    if ( v9 > 0 )
      v9 = (unsigned __int16)v9 | 0x80070000;
    _com_issue_error(v9);
  }
  v10 = SysAllocString(pBuf);
  if ( ret_1 >= 4096 )
    free(pBuf);
  if ( !v10 )
    _com_issue_error(E_OUTOFMEMORY);
  return v10;
}

//----- (00C74501) --------------------------------------------------------
std::exception *__thiscall sub_C74501(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::bad_alloc::`vftable';
  return v2;
}
// CB7BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (00C7451C) --------------------------------------------------------
std::exception *__thiscall sub_C7451C(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::length_error::`vftable';
  return v2;
}
// CB7BFC: using guessed type void *std::length_error::`vftable';

//----- (00C74537) --------------------------------------------------------
std::exception *__thiscall sub_C74537(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::logic_error::`vftable';
  return v2;
}
// CB7BF0: using guessed type void *std::logic_error::`vftable';

//----- (00C74552) --------------------------------------------------------
std::exception *__thiscall sub_C74552(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::out_of_range::`vftable';
  return v2;
}
// CB7C08: using guessed type void *std::out_of_range::`vftable';

//----- (00C7456D) --------------------------------------------------------
void __thiscall sub_C7456D(std::exception *this)
{
  *(_DWORD *)this = &std::bad_alloc::`vftable';
  std::_system_error::~_system_error(this);
}
// CB7BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (00C74585) --------------------------------------------------------
void *__thiscall sub_C74585(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *(_DWORD *)this = &std::bad_alloc::`vftable';
  std::_system_error::~_system_error((std::exception *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CB7BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (00C745AA) --------------------------------------------------------
void *__thiscall sub_C745AA(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  std::_system_error::~_system_error((std::exception *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00C7465F) --------------------------------------------------------
int __cdecl sub_C7465F(int a1)
{
  _DWORD *v1; // eax

  v1 = &unk_CB7E68;
  if ( !"address family not supported" )
    return 0;
  while ( *v1 != a1 )
  {
    v1 += 2;
    if ( !v1[1] )
      return 0;
  }
  return v1[1];
}

//----- (00C74689) --------------------------------------------------------
int __cdecl sub_C74689(int a1)
{
  int *v1; // eax

  v1 = &dword_CB7C10;
  if ( !"permission denied" )
    return 0;
  while ( *v1 != a1 )
  {
    v1 += 2;
    if ( !v1[1] )
      return 0;
  }
  return v1[1];
}
// CB7C10: using guessed type int dword_CB7C10;

//----- (00C74C4A) --------------------------------------------------------
int sub_C74C4A()
{
  return *(_DWORD *)&dword_CF5844;
}

//----- (00C74F3E) --------------------------------------------------------
void __cdecl sub_C74F3E(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

//----- (00C74F4C) --------------------------------------------------------
void __cdecl sub_C74F4C(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

//----- (00C74FDB) --------------------------------------------------------
CAtlBaseModule *__thiscall ATL::CAtlWinModule::CAtlWinModule(char *this)
{
  CAtlBaseModule *v1; // esi

  v1 = (CAtlBaseModule *)this;
  ATL::_ATL_WIN_MODULE70::_ATL_WIN_MODULE70(this);
  v1->baseclass.cbSize = 56;
  v1->baseclass.m_hInstResource = (HINSTANCE)12451840;
  v1->baseclass.m_hInst = (HINSTANCE)12451840;
  v1->baseclass.dwAtlBuildVer = 0xC00;
  v1->baseclass.pguidVer = &GUID_ATLVer110;
  if ( ATL::CComCriticalSection::Init(&v1->baseclass.m_csResource.m_Lock) < 0 )
  {
    if ( IsDebuggerPresent() )
      OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
    ATL::CAtlBaseModule::m_bInitFailed = 1;
  }
  return v1;
}
// CB8AF0: using guessed type GUID GUID_ATLVer110;
// CF5714: using guessed type char ATL::CAtlBaseModule::m_bInitFailed;

//----- (00C7502E) --------------------------------------------------------
_DWORD *__thiscall ATL::_ATL_WIN_MODULE70::_ATL_WIN_MODULE70(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *result; // eax

  v1 = this;
  memset(this + 5, 0, 0x18u);
  v1[11] = 0;
  v1[12] = 0;
  result = v1;
  v1[13] = 0;
  return result;
}

//----- (00C75051) --------------------------------------------------------
void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(int this)
{
  int v1; // esi
  void **v2; // ecx
  void **v3; // esi

  v1 = this;
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 20));
  v2 = (void **)(v1 + 44);
  v3 = v2;
  if ( *v2 )
  {
    free(*v2);
    *v3 = 0;
  }
  v3[1] = 0;
  v3[2] = 0;
}

//----- (00C75067) --------------------------------------------------------
int __thiscall ATL::CSimpleArray<HINSTANCE__ *,ATL::CSimpleArrayEqualHelper<HINSTANCE__ *>>::operator[](_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[1] )
  {
    RaiseException(STATUS_ARRAY_BOUNDS_EXCEEDED, 1u, 0, 0);
    JUMPOUT(loc_C75090);
  }
  return *this + 4 * a2;
}

//----- (00C75091) --------------------------------------------------------
CHAR *__thiscall ATL::CAtlBaseModule::GetHInstanceAt(CAtlBaseModule *this, int a2)
{
  CAtlBaseModule *v2; // esi
  struct _RTL_CRITICAL_SECTION *v3; // edi
  HINSTANCE v4; // esi

  v2 = this;
  v3 = &this->baseclass.m_csResource.m_Lock;
  EnterCriticalSection(&this->baseclass.m_csResource.m_Lock);
  if ( a2 > v2->baseclass.m_rgResourceInstance.m_nSize || a2 < 0 )
  {
    v4 = 0;
  }
  else if ( a2 == v2->baseclass.m_rgResourceInstance.m_nSize )
  {
    v4 = v2->baseclass.m_hInstResource;
  }
  else
  {
    v4 = *(HINSTANCE *)ATL::CSimpleArray<HINSTANCE__ *,ATL::CSimpleArrayEqualHelper<HINSTANCE__ *>>::operator[](
                         &v2->baseclass.m_rgResourceInstance.m_aT,
                         a2);
  }
  LeaveCriticalSection(v3);
  return (CHAR *)v4;
}

//----- (00C77B15) --------------------------------------------------------
FILE *__acrt_iob_func()
{
  return _iob;
}

//----- (00C789CE) --------------------------------------------------------
int __thiscall sub_C789CE(_DWORD *this)
{
  *this = &type_info::`vftable';
  return unknown_libname_8(this);
}
// C85348: using guessed type _DWORD __cdecl unknown_libname_8(_DWORD);
// CB8BE8: using guessed type void *type_info::`vftable';

//----- (00C789FA) --------------------------------------------------------
void *__thiscall sub_C789FA(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  sub_C789CE(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00C7918B) --------------------------------------------------------
int sub_C7918B()
{
  return flsall(1);
}
// C791ED: using guessed type _DWORD __cdecl flsall(_DWORD);

//----- (00C79CF7) --------------------------------------------------------
std::exception *__thiscall sub_C79CF7(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::bad_cast::`vftable';
  return v2;
}
// CB8FEC: using guessed type void *std::bad_cast::`vftable';

//----- (00C79D12) --------------------------------------------------------
std::exception *__thiscall sub_C79D12(std::exception *this, char *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, (const char *const *)&a2);
  *(_DWORD *)v2 = &std::bad_cast::`vftable';
  return v2;
}
// CB8FEC: using guessed type void *std::bad_cast::`vftable';

//----- (00C79D91) --------------------------------------------------------
void __thiscall std::_system_error::~_system_error(std::exception *this)
{
  *(_DWORD *)this = &std::exception::`vftable';
  std::exception::_Tidy(this);
}
// CB8FCC: using guessed type void *std::exception::`vftable';

//----- (00C79DCF) --------------------------------------------------------
void *__thiscall sub_C79DCF(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *(_DWORD *)this = &std::exception::`vftable';
  std::exception::_Tidy((std::exception *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CB8FCC: using guessed type void *std::exception::`vftable';

//----- (00C7B822) --------------------------------------------------------
std::exception *__thiscall sub_C7B822(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *(_DWORD *)v2 = &std::bad_exception::`vftable';
  return v2;
}
// CB8FFC: using guessed type void *std::bad_exception::`vftable';

//----- (00C7B83D) --------------------------------------------------------
void __thiscall sub_C7B83D(std::exception *this)
{
  *(_DWORD *)this = &std::bad_exception::`vftable';
  std::_system_error::~_system_error(this);
}
// CB8FFC: using guessed type void *std::bad_exception::`vftable';

//----- (00C7B848) --------------------------------------------------------
void *__thiscall sub_C7B848(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *(_DWORD *)this = &std::bad_exception::`vftable';
  std::_system_error::~_system_error((std::exception *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CB8FFC: using guessed type void *std::bad_exception::`vftable';

//----- (00C7D342) --------------------------------------------------------
void __cdecl sub_C7D342(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}

//----- (00C7F821) --------------------------------------------------------
void *__cdecl sub_C7F821(void *a1)
{
  void *result; // eax

  result = a1;
  dword_CF5EBC = a1;
  return result;
}

//----- (00C7F8CF) --------------------------------------------------------
void *__cdecl sub_C7F8CF(void *a1)
{
  void *result; // eax

  result = a1;
  dword_CF5EC4 = a1;
  return result;
}

//----- (00C7FAF6) --------------------------------------------------------
DWORD sub_C7FAF6()
{
  return dwTlsIndex;
}

//----- (00C8007A) --------------------------------------------------------
void sub_C8007A()
{
  dword_CF69AC = 0;
}
// CF69AC: using guessed type int dword_CF69AC;

//----- (00C8533B) --------------------------------------------------------
void *__cdecl sub_C8533B(void *a1)
{
  void *result; // eax

  result = a1;
  dword_CF6628 = a1;
  return result;
}

//----- (00C87C9C) --------------------------------------------------------
void sub_C87C9C()
{
  void (**i)(void); // esi

  for ( i = (void (**)(void))&unk_CBF88C; i < (void (**)(void))&unk_CBF88C; ++i )
  {
    if ( *i )
      (*i)();
  }
}

//----- (00C87CBC) --------------------------------------------------------
void __cdecl sub_C87CBC()
{
  void (**i)(void); // esi

  for ( i = (void (**)(void))&unk_CBF894; i < (void (**)(void))&unk_CBF894; ++i )
  {
    if ( *i )
      (*i)();
  }
}

//----- (00C87CDC) --------------------------------------------------------
PVOID sub_C87CDC()
{
  return DecodePointer(dword_CF663C);
}

//----- (00C87EFA) --------------------------------------------------------
int __cdecl sub_C87EFA(int a1)
{
  int result; // eax

  result = a1;
  dword_CF6648 = a1;
  return result;
}
// CF6648: using guessed type int dword_CF6648;

//----- (00C88B73) --------------------------------------------------------
HANDLE sub_C88B73()
{
  HANDLE result; // eax

  result = hObject;
  if ( hObject != (HANDLE)-1 && hObject != (HANDLE)-2 )
    result = (HANDLE)CloseHandle(hObject);
  return result;
}

//----- (00C89F90) --------------------------------------------------------
int sub_C89F90()
{
  __crtSetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return 0;
}

//----- (00C8A2BD) --------------------------------------------------------
int __cdecl sub_C8A2BD(int a1)
{
  int result; // eax

  result = a1;
  dword_CF5EC8 = a1;
  return result;
}
// CF5EC8: using guessed type int dword_CF5EC8;

//----- (00C8B1A0) --------------------------------------------------------
int *sub_C8B1A0()
{
  return &dword_CD2434;
}
// CD2434: using guessed type int dword_CD2434;

//----- (00C8B1A6) --------------------------------------------------------
int *sub_C8B1A6()
{
  return &dword_CD2438;
}
// CD2438: using guessed type int dword_CD2438;

//----- (00C8B1AC) --------------------------------------------------------
int *sub_C8B1AC()
{
  return &dword_CD2430;
}
// CD2430: using guessed type int dword_CD2430;

//----- (00C8B1B2) --------------------------------------------------------
void **sub_C8B1B2()
{
  return &off_CD24C0;
}
// CD24C0: using guessed type void *off_CD24C0;

//----- (00C8B1B8) --------------------------------------------------------
signed int __cdecl sub_C8B1B8(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_CD2434;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// C7F859: using guessed type int _invalid_parameter_noinfo(void);
// CD2434: using guessed type int dword_CD2434;

//----- (00C8B1E2) --------------------------------------------------------
signed int __cdecl sub_C8B1E2(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_CD2438;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// C7F859: using guessed type int _invalid_parameter_noinfo(void);
// CD2438: using guessed type int dword_CD2438;

//----- (00C8B20C) --------------------------------------------------------
signed int __cdecl sub_C8B20C(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_CD2430;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// C7F859: using guessed type int _invalid_parameter_noinfo(void);
// CD2430: using guessed type int dword_CD2430;

//----- (00C8B5FC) --------------------------------------------------------
int __cdecl sub_C8B5FC(const WCHAR *a1, int a2, int a3)
{
  int v3; // esi
  PVOID v4; // edi
  HMODULE v5; // edi
  FARPROC v6; // eax
  FARPROC v7; // eax
  FARPROC v8; // eax
  FARPROC v9; // eax
  FARPROC v10; // eax
  PVOID v12; // eax
  int v13; // eax
  int v14; // edi
  int (*v15)(void); // eax
  int (__stdcall *v16)(int); // eax
  int (__stdcall *v17)(int, LPCWSTR, int, int); // eax
  char v19; // [esp+Ch] [ebp-24h]
  int v20; // [esp+10h] [ebp-20h]
  LPCWSTR lpOutputString; // [esp+14h] [ebp-1Ch]
  int (__stdcall *v22)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [esp+18h] [ebp-18h]
  int (*v23)(void); // [esp+1Ch] [ebp-14h]
  char v24; // [esp+20h] [ebp-10h]
  char v25; // [esp+28h] [ebp-8h]

  lpOutputString = a1;
  v3 = 0;
  v20 = a2;
  v4 = EncodePointer(0);
  v22 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v4;
  v23 = (int (*)(void))__crtIsPackagedApp();
  if ( !dword_CF694C )
  {
    v5 = LoadLibraryExW(L"USER32.DLL", 0, 0x800u);
    if ( !v5 )
    {
      if ( GetLastError() != 87 )
        return 0;
      v5 = LoadLibraryExW(L"USER32.DLL", 0, 0);
      if ( !v5 )
        return 0;
    }
    v6 = GetProcAddress(v5, "MessageBoxW");
    if ( !v6 )
      return 0;
    dword_CF694C = EncodePointer(v6);
    v7 = GetProcAddress(v5, "GetActiveWindow");
    dword_CF6950 = EncodePointer(v7);
    v8 = GetProcAddress(v5, "GetLastActivePopup");
    dword_CF6954 = EncodePointer(v8);
    v9 = GetProcAddress(v5, "GetUserObjectInformationW");
    dword_CF695C = EncodePointer(v9);
    if ( dword_CF695C )
    {
      v10 = GetProcAddress(v5, "GetProcessWindowStation");
      dword_CF6958 = EncodePointer(v10);
    }
    v4 = v22;
  }
  if ( IsDebuggerPresent() )
  {
    if ( lpOutputString )
      OutputDebugStringW(lpOutputString);
    if ( v23 )
      return 4;
  }
  else if ( v23 )
  {
    DecodePointer(dword_CF694C);
    return 3;
  }
  if ( dword_CF6958 == v4
    || dword_CF695C == v4
    || (v23 = (int (*)(void))DecodePointer(dword_CF6958),
        v12 = DecodePointer(dword_CF695C),
        v22 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v12,
        !v23)
    || !v12
    || (v13 = v23()) != 0 && v22(v13, 1, &v24, 12, &v19) && v25 & 1 )
  {
    if ( dword_CF6950 != v4 )
    {
      v15 = (int (*)(void))DecodePointer(dword_CF6950);
      if ( v15 )
      {
        v3 = v15();
        if ( v3 )
        {
          if ( dword_CF6954 != v4 )
          {
            v16 = (int (__stdcall *)(int))DecodePointer(dword_CF6954);
            if ( v16 )
              v3 = v16(v3);
          }
        }
      }
    }
    v14 = a3;
  }
  else
  {
    v14 = a3 | 0x200000;
  }
  v17 = (int (__stdcall *)(int, LPCWSTR, int, int))DecodePointer(dword_CF694C);
  if ( v17 )
    return v17(v3, lpOutputString, v20, v14);
  return 0;
}
// C7D069: using guessed type int __crtIsPackagedApp(void);

//----- (00C8F550) --------------------------------------------------------
int CMainWnd::HandleTVSN7D1()
{
  return 0;
}

//----- (00C8FE30) --------------------------------------------------------
signed int __cdecl sub_C8FE30(unsigned __int16 *a1, int *a2)
{
  signed int v2; // ebx
  int *v3; // edi
  int v4; // edx
  int v5; // esi
  int v6; // eax
  int v7; // edx
  char v8; // cl
  bool i; // zf
  int v10; // edx
  unsigned int v11; // eax
  bool v12; // cf
  unsigned int v13; // eax
  signed int v14; // ecx
  int j; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // edx
  int *v21; // edx
  int v22; // eax
  signed int v23; // ecx
  int v24; // edx
  int v25; // ecx
  char v26; // cl
  bool k; // zf
  int v28; // edx
  unsigned int v29; // eax
  signed int v30; // ecx
  unsigned int v31; // eax
  int l; // edx
  unsigned int v33; // eax
  unsigned int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // edx
  int *v39; // edx
  signed int v40; // ecx
  int v41; // ecx
  int v42; // edi
  unsigned int v43; // edx
  unsigned int v44; // eax
  int v45; // edx
  int *v46; // edx
  signed int v47; // ecx
  int v48; // ecx
  signed int v49; // esi
  unsigned int v50; // edx
  int *v51; // edx
  signed int v52; // ecx
  int v53; // esi
  int v54; // eax
  int v56; // [esp+Ch] [ebp-44h]
  int v57; // [esp+14h] [ebp-3Ch]
  int v58; // [esp+14h] [ebp-3Ch]
  unsigned int v59; // [esp+18h] [ebp-38h]
  int v60; // [esp+18h] [ebp-38h]
  int v61; // [esp+18h] [ebp-38h]
  int v62; // [esp+1Ch] [ebp-34h]
  int v63; // [esp+1Ch] [ebp-34h]
  int v64; // [esp+1Ch] [ebp-34h]
  int v65; // [esp+20h] [ebp-30h]
  char v66; // [esp+20h] [ebp-30h]
  signed int v67; // [esp+24h] [ebp-2Ch]
  int v68; // [esp+28h] [ebp-28h]
  char v69; // [esp+28h] [ebp-28h]
  int v70; // [esp+28h] [ebp-28h]
  int v71; // [esp+2Ch] [ebp-24h]
  unsigned int v72; // [esp+2Ch] [ebp-24h]
  int v73; // [esp+30h] [ebp-20h]
  int v74; // [esp+30h] [ebp-20h]
  int v75; // [esp+30h] [ebp-20h]
  int v76; // [esp+30h] [ebp-20h]
  int v77; // [esp+30h] [ebp-20h]
  int v78; // [esp+34h] [ebp-1Ch]
  int v79; // [esp+38h] [ebp-18h]
  int v80; // [esp+3Ch] [ebp-14h]
  int v81; // [esp+40h] [ebp-10h]
  int v82; // [esp+44h] [ebp-Ch]
  int v83; // [esp+48h] [ebp-8h]

  v2 = 0;
  v3 = a2;
  v56 = a1[5] & 0x8000;
  v4 = (a1[5] & 0x7FFF) - 0x3FFF;
  v81 = *(_DWORD *)(a1 + 3);
  v82 = *(_DWORD *)(a1 + 1);
  v73 = v4;
  v83 = *a1 << 16;
  if ( v4 == -16383 )
  {
    v5 = 0;
    v6 = 0;
    while ( !*(&v81 + v6) )
    {
      if ( ++v6 >= 3 )
        goto LABEL_84;
    }
    v81 = 0;
    v82 = 0;
    v83 = 0;
  }
  else
  {
    v71 = v4;
    v78 = v81;
    v62 = dword_CD2570 - 1;
    v67 = 0;
    v79 = v82;
    v80 = v83;
    v7 = dword_CD2570 / 32;
    v57 = dword_CD2570 / 32;
    v65 = 31 - dword_CD2570 % 32;
    v8 = v65;
    if ( (1 << v65) & *(&v81 + dword_CD2570 / 32) )
    {
      for ( i = (~(-1 << v65) & *(&v81 + v7)) == 0; i; i = *(&v81 + v7) == 0 )
      {
        if ( ++v7 >= 3 )
          goto LABEL_24;
      }
      v10 = v62 / 32;
      v67 = 0;
      v59 = 1 << (31 - v62 % 32);
      v11 = *(&v81 + v62 / 32);
      v12 = v11 + v59 < v11;
      v13 = v11 + v59;
      v14 = 0;
      if ( v12 || v13 < v59 )
      {
        v14 = 1;
        v67 = 1;
      }
      *(&v81 + v10) = v13;
      for ( j = v10 - 1; j >= 0; *(&v81 + j--) = v17 )
      {
        if ( !v14 )
          break;
        v16 = *(&v81 + j);
        v14 = 0;
        v67 = 0;
        v12 = v16 + 1 < v16;
        v17 = v16 + 1;
        if ( v12 || v17 < 1 )
        {
          v14 = 1;
          v67 = 1;
        }
      }
      v8 = v65;
LABEL_24:
      v7 = v57;
    }
    *(&v81 + v7) &= -1 << v8;
    if ( v7 + 1 < 3 )
      memset(&v81 + v7 + 1, 0, 4 * (3 - (v7 + 1)));
    v18 = v73;
    if ( v67 )
      v18 = v73 + 1;
    if ( v18 >= dword_CD256C - dword_CD2570 )
    {
      if ( v18 > dword_CD256C )
      {
        if ( v18 < dword_CD2568 )
        {
          v81 &= 0x7FFFFFFFu;
          v61 = v18 + dword_CD257C;
          v70 = dword_CD2574 / 32;
          v48 = dword_CD2574 % 32;
          v77 = 0;
          v49 = 0;
          do
          {
            v50 = *(&v81 + v49);
            *(&v81 + v49++) = v77 | (v50 >> v48);
            v77 = (~(-1 << v48) & v50) << (32 - v48);
          }
          while ( v49 < 3 );
          v5 = v61;
          v51 = &v83 - v70;
          v2 = 0;
          v52 = 2;
          do
          {
            if ( v52 < v70 )
              *(&v81 + v52) = 0;
            else
              *(&v81 + v52) = *v51;
            --v51;
            --v52;
          }
          while ( v52 >= 0 );
        }
        else
        {
          v82 = 0;
          v83 = 0;
          v81 = 2147483648;
          v64 = dword_CD2574 / 32;
          v41 = dword_CD2574 % 32;
          v60 = dword_CD2574 % 32;
          v76 = 0;
          v42 = ~(-1 << dword_CD2574 % 32);
          v69 = 32 - dword_CD2574 % 32;
          do
          {
            v43 = *(&v81 + v2);
            v44 = v43;
            v45 = v76 | (v43 >> v41);
            LOBYTE(v41) = v60;
            *(&v81 + v2++) = v45;
            v76 = (v42 & v44) << v69;
          }
          while ( v2 < 3 );
          v46 = &v83 - v64;
          v47 = 2;
          do
          {
            if ( v47 < v64 )
              *(&v81 + v47) = 0;
            else
              *(&v81 + v47) = *v46;
            --v46;
            --v47;
          }
          while ( v47 >= 0 );
          v5 = dword_CD2568 + dword_CD257C;
          v2 = 1;
        }
        goto LABEL_83;
      }
      v81 = v78;
      v82 = v79;
      v58 = (dword_CD256C - v71) / 32;
      v83 = v80;
      v19 = (dword_CD256C - v71) % 32;
      v74 = 0;
      do
      {
        v20 = *(&v81 + v2);
        *(&v81 + v2++) = v74 | (v20 >> v19);
        v74 = (~(-1 << v19) & v20) << (32 - v19);
      }
      while ( v2 < 3 );
      v21 = &v83 - v58;
      v22 = v58;
      v23 = 2;
      do
      {
        if ( v23 < v22 )
        {
          *(&v81 + v23) = 0;
        }
        else
        {
          *(&v81 + v23) = *v21;
          v22 = v58;
        }
        --v21;
        --v23;
      }
      while ( v23 >= 0 );
      v24 = (v62 + 1) / 32;
      v25 = (v62 + 1) % 32;
      v66 = 31 - v25;
      v26 = 31 - v25;
      if ( (1 << v26) & *(&v81 + v24) )
      {
        for ( k = (~(-1 << v26) & *(&v81 + v24)) == 0; k; k = *(&v81 + v24) == 0 )
        {
          if ( ++v24 >= 3 )
            goto LABEL_56;
        }
        v28 = v62 / 32;
        v29 = *(&v81 + v62 / 32);
        v30 = 0;
        v72 = 1 << (31 - v62 % 32);
        v12 = v29 + v72 < v29;
        v31 = v29 + v72;
        if ( v12 || v31 < v72 )
          v30 = 1;
        *(&v81 + v28) = v31;
        for ( l = v28 - 1; l >= 0; *(&v81 + l--) = v34 )
        {
          if ( !v30 )
            break;
          v33 = *(&v81 + l);
          v30 = 0;
          v12 = v33 + 1 < v33;
          v34 = v33 + 1;
          if ( v12 || v34 < 1 )
            v30 = 1;
        }
        v26 = v66;
LABEL_56:
        v24 = (v62 + 1) / 32;
      }
      *(&v81 + v24) &= -1 << v26;
      v35 = v24 + 1;
      if ( v35 < 3 )
        memset(&v81 + v35, 0, 4 * (3 - v35));
      v68 = (dword_CD2574 + 1) / 32;
      v36 = (dword_CD2574 + 1) % 32;
      v37 = 0;
      v75 = 0;
      v63 = 0;
      do
      {
        v38 = *(&v81 + v37);
        *(&v81 + v63) = v75 | (v38 >> v36);
        v75 = (~(-1 << v36) & v38) << (32 - v36);
        v37 = v63 + 1;
        v63 = v37;
      }
      while ( v37 < 3 );
      v39 = &v83 - v68;
      v40 = 2;
      do
      {
        if ( v40 < v68 )
          *(&v81 + v40) = 0;
        else
          *(&v81 + v40) = *v39;
        --v39;
        --v40;
      }
      while ( v40 >= 0 );
    }
    else
    {
      v81 = 0;
      v82 = 0;
      v83 = 0;
    }
    v5 = 0;
  }
  v2 = 2;
LABEL_83:
  v3 = a2;
LABEL_84:
  v53 = v81 | (v56 != 0 ? 0x80000000 : 0) | (v5 << (31 - dword_CD2574));
  if ( dword_CD2578 == 64 )
  {
    v54 = v82;
    v3[1] = v53;
    *v3 = v54;
  }
  else if ( dword_CD2578 == 32 )
  {
    *v3 = v53;
  }
  return v2;
}
// CD2568: using guessed type int dword_CD2568;
// CD256C: using guessed type int dword_CD256C;
// CD2570: using guessed type int dword_CD2570;
// CD2574: using guessed type int dword_CD2574;
// CD2578: using guessed type int dword_CD2578;
// CD257C: using guessed type int dword_CD257C;

//----- (00C903A2) --------------------------------------------------------
signed int __cdecl sub_C903A2(unsigned __int16 *a1, int *a2)
{
  signed int v2; // ebx
  int *v3; // edi
  int v4; // edx
  int v5; // esi
  int v6; // eax
  int v7; // edx
  char v8; // cl
  bool i; // zf
  int v10; // edx
  unsigned int v11; // eax
  bool v12; // cf
  unsigned int v13; // eax
  signed int v14; // ecx
  int j; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // edx
  int *v21; // edx
  int v22; // eax
  signed int v23; // ecx
  int v24; // edx
  int v25; // ecx
  char v26; // cl
  bool k; // zf
  int v28; // edx
  unsigned int v29; // eax
  signed int v30; // ecx
  unsigned int v31; // eax
  int l; // edx
  unsigned int v33; // eax
  unsigned int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // edx
  int *v39; // edx
  signed int v40; // ecx
  int v41; // ecx
  int v42; // edi
  unsigned int v43; // edx
  unsigned int v44; // eax
  int v45; // edx
  int *v46; // edx
  signed int v47; // ecx
  int v48; // ecx
  signed int v49; // esi
  unsigned int v50; // edx
  int *v51; // edx
  signed int v52; // ecx
  int v53; // esi
  int v54; // eax
  int v56; // [esp+Ch] [ebp-44h]
  int v57; // [esp+14h] [ebp-3Ch]
  int v58; // [esp+14h] [ebp-3Ch]
  unsigned int v59; // [esp+18h] [ebp-38h]
  int v60; // [esp+18h] [ebp-38h]
  int v61; // [esp+18h] [ebp-38h]
  int v62; // [esp+1Ch] [ebp-34h]
  int v63; // [esp+1Ch] [ebp-34h]
  int v64; // [esp+1Ch] [ebp-34h]
  int v65; // [esp+20h] [ebp-30h]
  char v66; // [esp+20h] [ebp-30h]
  signed int v67; // [esp+24h] [ebp-2Ch]
  int v68; // [esp+28h] [ebp-28h]
  char v69; // [esp+28h] [ebp-28h]
  int v70; // [esp+28h] [ebp-28h]
  int v71; // [esp+2Ch] [ebp-24h]
  unsigned int v72; // [esp+2Ch] [ebp-24h]
  int v73; // [esp+30h] [ebp-20h]
  int v74; // [esp+30h] [ebp-20h]
  int v75; // [esp+30h] [ebp-20h]
  int v76; // [esp+30h] [ebp-20h]
  int v77; // [esp+30h] [ebp-20h]
  int v78; // [esp+34h] [ebp-1Ch]
  int v79; // [esp+38h] [ebp-18h]
  int v80; // [esp+3Ch] [ebp-14h]
  int v81; // [esp+40h] [ebp-10h]
  int v82; // [esp+44h] [ebp-Ch]
  int v83; // [esp+48h] [ebp-8h]

  v2 = 0;
  v3 = a2;
  v56 = a1[5] & 0x8000;
  v4 = (a1[5] & 0x7FFF) - 0x3FFF;
  v81 = *(_DWORD *)(a1 + 3);
  v82 = *(_DWORD *)(a1 + 1);
  v73 = v4;
  v83 = *a1 << 16;
  if ( v4 == -16383 )
  {
    v5 = 0;
    v6 = 0;
    while ( !*(&v81 + v6) )
    {
      if ( ++v6 >= 3 )
        goto LABEL_84;
    }
    v81 = 0;
    v82 = 0;
    v83 = 0;
  }
  else
  {
    v71 = v4;
    v78 = v81;
    v62 = dword_CD2588 - 1;
    v67 = 0;
    v79 = v82;
    v80 = v83;
    v7 = dword_CD2588 / 32;
    v57 = dword_CD2588 / 32;
    v65 = 31 - dword_CD2588 % 32;
    v8 = v65;
    if ( (1 << v65) & *(&v81 + dword_CD2588 / 32) )
    {
      for ( i = (~(-1 << v65) & *(&v81 + v7)) == 0; i; i = *(&v81 + v7) == 0 )
      {
        if ( ++v7 >= 3 )
          goto LABEL_24;
      }
      v10 = v62 / 32;
      v67 = 0;
      v59 = 1 << (31 - v62 % 32);
      v11 = *(&v81 + v62 / 32);
      v12 = v11 + v59 < v11;
      v13 = v11 + v59;
      v14 = 0;
      if ( v12 || v13 < v59 )
      {
        v14 = 1;
        v67 = 1;
      }
      *(&v81 + v10) = v13;
      for ( j = v10 - 1; j >= 0; *(&v81 + j--) = v17 )
      {
        if ( !v14 )
          break;
        v16 = *(&v81 + j);
        v14 = 0;
        v67 = 0;
        v12 = v16 + 1 < v16;
        v17 = v16 + 1;
        if ( v12 || v17 < 1 )
        {
          v14 = 1;
          v67 = 1;
        }
      }
      v8 = v65;
LABEL_24:
      v7 = v57;
    }
    *(&v81 + v7) &= -1 << v8;
    if ( v7 + 1 < 3 )
      memset(&v81 + v7 + 1, 0, 4 * (3 - (v7 + 1)));
    v18 = v73;
    if ( v67 )
      v18 = v73 + 1;
    if ( v18 >= dword_CD2584 - dword_CD2588 )
    {
      if ( v18 > dword_CD2584 )
      {
        if ( v18 < dword_CD2580 )
        {
          v81 &= 0x7FFFFFFFu;
          v61 = v18 + dword_CD2594;
          v70 = dword_CD258C / 32;
          v48 = dword_CD258C % 32;
          v77 = 0;
          v49 = 0;
          do
          {
            v50 = *(&v81 + v49);
            *(&v81 + v49++) = v77 | (v50 >> v48);
            v77 = (~(-1 << v48) & v50) << (32 - v48);
          }
          while ( v49 < 3 );
          v5 = v61;
          v51 = &v83 - v70;
          v2 = 0;
          v52 = 2;
          do
          {
            if ( v52 < v70 )
              *(&v81 + v52) = 0;
            else
              *(&v81 + v52) = *v51;
            --v51;
            --v52;
          }
          while ( v52 >= 0 );
        }
        else
        {
          v82 = 0;
          v83 = 0;
          v81 = 2147483648;
          v64 = dword_CD258C / 32;
          v41 = dword_CD258C % 32;
          v60 = dword_CD258C % 32;
          v76 = 0;
          v42 = ~(-1 << dword_CD258C % 32);
          v69 = 32 - dword_CD258C % 32;
          do
          {
            v43 = *(&v81 + v2);
            v44 = v43;
            v45 = v76 | (v43 >> v41);
            LOBYTE(v41) = v60;
            *(&v81 + v2++) = v45;
            v76 = (v42 & v44) << v69;
          }
          while ( v2 < 3 );
          v46 = &v83 - v64;
          v47 = 2;
          do
          {
            if ( v47 < v64 )
              *(&v81 + v47) = 0;
            else
              *(&v81 + v47) = *v46;
            --v46;
            --v47;
          }
          while ( v47 >= 0 );
          v5 = dword_CD2580 + dword_CD2594;
          v2 = 1;
        }
        goto LABEL_83;
      }
      v81 = v78;
      v82 = v79;
      v58 = (dword_CD2584 - v71) / 32;
      v83 = v80;
      v19 = (dword_CD2584 - v71) % 32;
      v74 = 0;
      do
      {
        v20 = *(&v81 + v2);
        *(&v81 + v2++) = v74 | (v20 >> v19);
        v74 = (~(-1 << v19) & v20) << (32 - v19);
      }
      while ( v2 < 3 );
      v21 = &v83 - v58;
      v22 = v58;
      v23 = 2;
      do
      {
        if ( v23 < v22 )
        {
          *(&v81 + v23) = 0;
        }
        else
        {
          *(&v81 + v23) = *v21;
          v22 = v58;
        }
        --v21;
        --v23;
      }
      while ( v23 >= 0 );
      v24 = (v62 + 1) / 32;
      v25 = (v62 + 1) % 32;
      v66 = 31 - v25;
      v26 = 31 - v25;
      if ( (1 << v26) & *(&v81 + v24) )
      {
        for ( k = (~(-1 << v26) & *(&v81 + v24)) == 0; k; k = *(&v81 + v24) == 0 )
        {
          if ( ++v24 >= 3 )
            goto LABEL_56;
        }
        v28 = v62 / 32;
        v29 = *(&v81 + v62 / 32);
        v30 = 0;
        v72 = 1 << (31 - v62 % 32);
        v12 = v29 + v72 < v29;
        v31 = v29 + v72;
        if ( v12 || v31 < v72 )
          v30 = 1;
        *(&v81 + v28) = v31;
        for ( l = v28 - 1; l >= 0; *(&v81 + l--) = v34 )
        {
          if ( !v30 )
            break;
          v33 = *(&v81 + l);
          v30 = 0;
          v12 = v33 + 1 < v33;
          v34 = v33 + 1;
          if ( v12 || v34 < 1 )
            v30 = 1;
        }
        v26 = v66;
LABEL_56:
        v24 = (v62 + 1) / 32;
      }
      *(&v81 + v24) &= -1 << v26;
      v35 = v24 + 1;
      if ( v35 < 3 )
        memset(&v81 + v35, 0, 4 * (3 - v35));
      v68 = (dword_CD258C + 1) / 32;
      v36 = (dword_CD258C + 1) % 32;
      v37 = 0;
      v75 = 0;
      v63 = 0;
      do
      {
        v38 = *(&v81 + v37);
        *(&v81 + v63) = v75 | (v38 >> v36);
        v75 = (~(-1 << v36) & v38) << (32 - v36);
        v37 = v63 + 1;
        v63 = v37;
      }
      while ( v37 < 3 );
      v39 = &v83 - v68;
      v40 = 2;
      do
      {
        if ( v40 < v68 )
          *(&v81 + v40) = 0;
        else
          *(&v81 + v40) = *v39;
        --v39;
        --v40;
      }
      while ( v40 >= 0 );
    }
    else
    {
      v81 = 0;
      v82 = 0;
      v83 = 0;
    }
    v5 = 0;
  }
  v2 = 2;
LABEL_83:
  v3 = a2;
LABEL_84:
  v53 = v81 | (v56 != 0 ? 0x80000000 : 0) | (v5 << (31 - dword_CD258C));
  if ( dword_CD2590 == 64 )
  {
    v54 = v82;
    v3[1] = v53;
    *v3 = v54;
  }
  else if ( dword_CD2590 == 32 )
  {
    *v3 = v53;
  }
  return v2;
}
// CD2580: using guessed type int dword_CD2580;
// CD2584: using guessed type int dword_CD2584;
// CD2588: using guessed type int dword_CD2588;
// CD258C: using guessed type int dword_CD258C;
// CD2590: using guessed type int dword_CD2590;
// CD2594: using guessed type int dword_CD2594;

//----- (00C91B17) --------------------------------------------------------
signed int __cdecl sub_C91B17(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_CF69A4;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// C7F859: using guessed type int _invalid_parameter_noinfo(void);
// CF69A4: using guessed type int dword_CF69A4;

//----- (00C91C0E) --------------------------------------------------------
HANDLE sub_C91C0E()
{
  HANDLE result; // eax

  result = hConsoleOutput;
  if ( hConsoleOutput != (HANDLE)-1 && hConsoleOutput != (HANDLE)-2 )
    result = (HANDLE)CloseHandle(hConsoleOutput);
  return result;
}

//----- (00C93624) --------------------------------------------------------
int __cdecl SEH_402480(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C937AA) --------------------------------------------------------
int __cdecl SEH_402D60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C937E9) --------------------------------------------------------
int __cdecl SEH_403440(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93810) --------------------------------------------------------
int __cdecl SEH_4035A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93830) --------------------------------------------------------
int __cdecl SEH_4038F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93869) --------------------------------------------------------
int __cdecl SEH_4314F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93898) --------------------------------------------------------
int __cdecl SEH_403D40(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C938CB) --------------------------------------------------------
int __cdecl SEH_404130(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93910) --------------------------------------------------------
int __cdecl SEH_404890(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93950) --------------------------------------------------------
int __cdecl SEH_404AC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93978) --------------------------------------------------------
int __cdecl SEH_404F20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C939C1) --------------------------------------------------------
int __cdecl SEH_404FB0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93A00) --------------------------------------------------------
int __cdecl SEH_4052B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93A30) --------------------------------------------------------
int __cdecl SEH_405520(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93A79) --------------------------------------------------------
int __cdecl SEH_405C70(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93AAB) --------------------------------------------------------
int __cdecl SEH_406440(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93AF0) --------------------------------------------------------
int __cdecl SEH_406090(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93B50) --------------------------------------------------------
int __cdecl SEH_4067A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93B78) --------------------------------------------------------
int __cdecl SEH_406CC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93BB8) --------------------------------------------------------
int __cdecl SEH_406DD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93C38) --------------------------------------------------------
int __cdecl SEH_4070E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93C81) --------------------------------------------------------
int __cdecl SEH_407CC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93CD1) --------------------------------------------------------
int __cdecl SEH_4085A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C93E47) --------------------------------------------------------
int __cdecl SEH_4087A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9403E) --------------------------------------------------------
int __cdecl SEH_409270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9420F) --------------------------------------------------------
int __cdecl SEH_409B70(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94238) --------------------------------------------------------
int __cdecl SEH_425730(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C943B3) --------------------------------------------------------
int __cdecl SEH_40AB10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94910) --------------------------------------------------------
int __cdecl SEH_40B220(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C949A0) --------------------------------------------------------
int __cdecl SEH_40F2D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C949D8) --------------------------------------------------------
int __cdecl SEH_40F610(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94A00) --------------------------------------------------------
int __cdecl SEH_40F9D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94A20) --------------------------------------------------------
int __cdecl SEH_40FD00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94A40) --------------------------------------------------------
int __cdecl SEH_40FDF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94A92) --------------------------------------------------------
int __cdecl SEH_410460(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94C1A) --------------------------------------------------------
int __cdecl SEH_410790(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94C48) --------------------------------------------------------
int __cdecl SEH_411150(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C94E28) --------------------------------------------------------
int __cdecl SEH_411610(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95006) --------------------------------------------------------
int __cdecl SEH_412090(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95187) --------------------------------------------------------
int __cdecl SEH_413160(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95307) --------------------------------------------------------
int __cdecl SEH_413A80(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95509) --------------------------------------------------------
int __cdecl SEH_414200(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9580D) --------------------------------------------------------
int __cdecl SEH_414FF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95A24) --------------------------------------------------------
int __cdecl SEH_415FF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95AE0) --------------------------------------------------------
int __cdecl SEH_416A10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95B20) --------------------------------------------------------
int __cdecl SEH_416E10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95C9F) --------------------------------------------------------
int __cdecl SEH_417000(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95E4B) --------------------------------------------------------
int __cdecl SEH_4177C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C95E78) --------------------------------------------------------
int __cdecl SEH_417FE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96013) --------------------------------------------------------
int __cdecl SEH_418050(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96048) --------------------------------------------------------
int __cdecl SEH_418A90(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C961C7) --------------------------------------------------------
int __cdecl SEH_418C20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C961F8) --------------------------------------------------------
int __cdecl SEH_4193C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96399) --------------------------------------------------------
int __cdecl SEH_419580(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96533) --------------------------------------------------------
int __cdecl SEH_41A120(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96568) --------------------------------------------------------
int __cdecl SEH_41AD20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9659B) --------------------------------------------------------
int __cdecl SEH_45ED60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96802) --------------------------------------------------------
int __cdecl SEH_41B1A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9699B) --------------------------------------------------------
int __cdecl SEH_41D790(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96BBC) --------------------------------------------------------
int __cdecl SEH_41E3A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96BF8) --------------------------------------------------------
int __cdecl SEH_41EFE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96C38) --------------------------------------------------------
int __cdecl SEH_41F0E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C96F3B) --------------------------------------------------------
int __cdecl SEH_41F260(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9704E) --------------------------------------------------------
int __cdecl SEH_420760(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C970E8) --------------------------------------------------------
int __cdecl SEH_420EA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97120) --------------------------------------------------------
int __cdecl SEH_4211B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9714A) --------------------------------------------------------
int __cdecl SEH_4013A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97178) --------------------------------------------------------
int __cdecl SEH_421590(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C972D4) --------------------------------------------------------
int __cdecl SEH_421860(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97308) --------------------------------------------------------
int __cdecl SEH_422060(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9747C) --------------------------------------------------------
int __cdecl SEH_422110(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9764A) --------------------------------------------------------
int __cdecl SEH_4227D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9782A) --------------------------------------------------------
int __cdecl SEH_423190(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97860) --------------------------------------------------------
int __cdecl SEH_424040(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97880) --------------------------------------------------------
int __cdecl SEH_424270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C978A0) --------------------------------------------------------
int __cdecl SEH_4244A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C978C0) --------------------------------------------------------
int __cdecl SEH_4245C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C978FE) --------------------------------------------------------
int __cdecl SEH_424740(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97938) --------------------------------------------------------
int __cdecl SEH_424920(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97998) --------------------------------------------------------
int __cdecl SEH_424FE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C979D0) --------------------------------------------------------
int __cdecl SEH_425120(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C979F8) --------------------------------------------------------
int __cdecl SEH_425350(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97A28) --------------------------------------------------------
int __cdecl SEH_425440(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97A58) --------------------------------------------------------
int __cdecl SEH_425850(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97A99) --------------------------------------------------------
int __cdecl SEH_425940(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97AC8) --------------------------------------------------------
int __cdecl SEH_425AB0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97BBA) --------------------------------------------------------
int __cdecl SEH_425D10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97BF8) --------------------------------------------------------
int __cdecl SEH_426830(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97C28) --------------------------------------------------------
int __cdecl SEH_4269A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97C50) --------------------------------------------------------
int __cdecl SEH_426BB0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97C78) --------------------------------------------------------
int __cdecl SEH_427AC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97CAB) --------------------------------------------------------
int __cdecl SEH_45E760(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97CE6) --------------------------------------------------------
int __cdecl SEH_428730(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97D45) --------------------------------------------------------
int __cdecl SEH_428970(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97D80) --------------------------------------------------------
int __cdecl SEH_429580(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97DA8) --------------------------------------------------------
int __cdecl SEH_42A1F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97DDB) --------------------------------------------------------
int __cdecl SEH_42FAF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97E10) --------------------------------------------------------
int __cdecl SEH_431240(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97E60) --------------------------------------------------------
int __cdecl SEH_431560(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97EDE) --------------------------------------------------------
int __cdecl SEH_4318A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C97F83) --------------------------------------------------------
int __cdecl SEH_431BC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98191) --------------------------------------------------------
int __cdecl SEH_431FC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9825C) --------------------------------------------------------
int __cdecl SEH_4337E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C982B1) --------------------------------------------------------
int __cdecl SEH_434530(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C982E9) --------------------------------------------------------
int __cdecl SEH_434810(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98320) --------------------------------------------------------
int __cdecl SEH_434AA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98358) --------------------------------------------------------
int __cdecl SEH_434F00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C985A0) --------------------------------------------------------
int __cdecl SEH_4355A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C985D0) --------------------------------------------------------
int __cdecl SEH_437DF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C985F8) --------------------------------------------------------
int __cdecl SEH_438150(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9866A) --------------------------------------------------------
int __cdecl SEH_438360(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98698) --------------------------------------------------------
int __cdecl SEH_438570(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C986C8) --------------------------------------------------------
int __cdecl SEH_438630(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98735) --------------------------------------------------------
int __cdecl SEH_438CE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9876B) --------------------------------------------------------
int __cdecl SEH_439090(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C987A0) --------------------------------------------------------
int __cdecl SEH_4391F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C987D0) --------------------------------------------------------
int __cdecl SEH_4392D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C987F8) --------------------------------------------------------
int __cdecl SEH_439D10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98828) --------------------------------------------------------
int __cdecl SEH_439E70(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98850) --------------------------------------------------------
int __cdecl SEH_43B100(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98889) --------------------------------------------------------
int __cdecl SEH_43B460(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C988D0) --------------------------------------------------------
int __cdecl SEH_43B780(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9894F) --------------------------------------------------------
int __cdecl SEH_43BF00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C989A4) --------------------------------------------------------
int __cdecl SEH_43D080(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C989C8) --------------------------------------------------------
int __cdecl SEH_43D1D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98A19) --------------------------------------------------------
int __cdecl SEH_43D3B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98A5E) --------------------------------------------------------
int __cdecl SEH_43D590(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98AD5) --------------------------------------------------------
int __cdecl SEH_43D670(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98B03) --------------------------------------------------------
int __cdecl SEH_43DF10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98B3E) --------------------------------------------------------
int __cdecl SEH_43E1A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98B7B) --------------------------------------------------------
int __cdecl SEH_43EAD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98BAB) --------------------------------------------------------
int __cdecl SEH_43EBA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98BE0) --------------------------------------------------------
int __cdecl SEH_43EEA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98C75) --------------------------------------------------------
int __cdecl SEH_43F0A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98CA8) --------------------------------------------------------
int __cdecl SEH_43FFF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98CD8) --------------------------------------------------------
int __cdecl SEH_469E00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98D16) --------------------------------------------------------
int __cdecl SEH_445F60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98EBE) --------------------------------------------------------
int __cdecl SEH_446270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C98FC9) --------------------------------------------------------
int __cdecl SEH_451E50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9902D) --------------------------------------------------------
int __cdecl SEH_4526B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99081) --------------------------------------------------------
int __cdecl SEH_457640(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C990B1) --------------------------------------------------------
int __cdecl SEH_457740(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C990F6) --------------------------------------------------------
int __cdecl SEH_4577E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99138) --------------------------------------------------------
int __cdecl SEH_457DD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C991C3) --------------------------------------------------------
int __cdecl SEH_4580C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C991F0) --------------------------------------------------------
int __cdecl SEH_458AE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99218) --------------------------------------------------------
int __cdecl SEH_458C80(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99248) --------------------------------------------------------
int __cdecl SEH_458D10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C992D3) --------------------------------------------------------
int __cdecl SEH_458E20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9930B) --------------------------------------------------------
int __cdecl SEH_459500(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C993FF) --------------------------------------------------------
int __cdecl SEH_459C50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99452) --------------------------------------------------------
int __cdecl SEH_45A570(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99504) --------------------------------------------------------
int __cdecl SEH_45B0A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9954B) --------------------------------------------------------
int __cdecl SEH_45B680(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99580) --------------------------------------------------------
int __cdecl SEH_45B8A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C995A0) --------------------------------------------------------
int __cdecl SEH_45C840(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C995CB) --------------------------------------------------------
int __cdecl SEH_45EE00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9964C) --------------------------------------------------------
int __cdecl SEH_45D510(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C996B2) --------------------------------------------------------
int __cdecl SEH_45DCE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C996F9) --------------------------------------------------------
int __cdecl SEH_45E4E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9972B) --------------------------------------------------------
int __cdecl SEH_45E8B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99758) --------------------------------------------------------
int __cdecl SEH_466900(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99780) --------------------------------------------------------
int __cdecl SEH_469AF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C997A0) --------------------------------------------------------
int __cdecl SEH_469C10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C997C8) --------------------------------------------------------
int __cdecl SEH_469EA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C997FE) --------------------------------------------------------
int __cdecl SEH_46A670(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9983E) --------------------------------------------------------
int __cdecl SEH_46ADD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9987B) --------------------------------------------------------
int __cdecl SEH_46B930(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C998D1) --------------------------------------------------------
int __cdecl SEH_46BC50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99908) --------------------------------------------------------
int __cdecl SEH_46C350(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99938) --------------------------------------------------------
int __cdecl SEH_46DAF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99976) --------------------------------------------------------
int __cdecl SEH_46DD60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C999B3) --------------------------------------------------------
int __cdecl SEH_46EC30(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99A01) --------------------------------------------------------
int __cdecl SEH_4703E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99A3B) --------------------------------------------------------
int __cdecl SEH_4723A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99A6E) --------------------------------------------------------
int __cdecl SEH_472810(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99B48) --------------------------------------------------------
int __cdecl SEH_472C20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99B7E) --------------------------------------------------------
int __cdecl SEH_473C50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99BBB) --------------------------------------------------------
int __cdecl SEH_474990(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99BEE) --------------------------------------------------------
int __cdecl SEH_4766A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99C2E) --------------------------------------------------------
int __cdecl SEH_477710(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99C6E) --------------------------------------------------------
int __cdecl SEH_478E00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99CAB) --------------------------------------------------------
int __cdecl SEH_479A30(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99CEE) --------------------------------------------------------
int __cdecl SEH_47ACF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99D2B) --------------------------------------------------------
int __cdecl SEH_47D5B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99D70) --------------------------------------------------------
int __cdecl SEH_4808E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99D9E) --------------------------------------------------------
int __cdecl SEH_4809B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99DDE) --------------------------------------------------------
int __cdecl SEH_4818B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99E1E) --------------------------------------------------------
int __cdecl SEH_482010(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99E5E) --------------------------------------------------------
int __cdecl SEH_4825E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99E9B) --------------------------------------------------------
int __cdecl SEH_483260(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99ECE) --------------------------------------------------------
int __cdecl SEH_483AF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99F3D) --------------------------------------------------------
int __cdecl SEH_483FC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99F70) --------------------------------------------------------
int __cdecl SEH_491650(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99F9A) --------------------------------------------------------
int __cdecl SEH_401FF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C99FD0) --------------------------------------------------------
int __cdecl SEH_491C30(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9A003) --------------------------------------------------------
int __cdecl SEH_491EC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9A039) --------------------------------------------------------
int __cdecl SEH_492230(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9A070) --------------------------------------------------------
int __cdecl SEH_494270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9A093) --------------------------------------------------------
int __cdecl sub_C9A093(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9A0AE) --------------------------------------------------------
int __cdecl sub_C9A0AE(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// C75CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (00C9A0D0) --------------------------------------------------------
void __cdecl sub_C9A0D0()
{
  `eh vector destructor iterator'(word_CD4900, 0x28u, 20, sub_BE3850);
}
// CD4900: using guessed type __int16 word_CD4900[400];

//----- (00C9A0F0) --------------------------------------------------------
void __thiscall sub_C9A0F0(void *this)
{
  void *v1; // [esp-2h] [ebp-4h]

  v1 = this;
  if ( garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst )
  {
    nullsub_1(garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst, garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast);
    ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)((char *)&v1 + 3));
    operator delete(garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst);
    garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst = 0;
    garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast = 0;
    garrAccountInfo.baseclass_0._Mypair._Myval2._Myend = 0;
  }
}
// BEFB30: using guessed type _DWORD __stdcall nullsub_1(_DWORD, _DWORD);

//----- (00C9A150) --------------------------------------------------------
void __cdecl sub_C9A150()
{
  free(gpszTipText);
}

//----- (00C9A160) --------------------------------------------------------
void __cdecl sub_C9A160()
{
  void *v0; // esi

  v0 = dword_CD48F8;
  if ( dword_CD48F8 )
  {
    if ( !InterlockedDecrement((volatile LONG *)dword_CD48F8 + 2) && v0 )
    {
      if ( *(_DWORD *)v0 )
      {
        SysFreeString(*(BSTR *)v0);
        *(_DWORD *)v0 = 0;
      }
      if ( *((_DWORD *)v0 + 1) )
      {
        operator delete[](*((void **)v0 + 1));
        *((_DWORD *)v0 + 1) = 0;
      }
      operator delete(v0);
    }
    dword_CD48F8 = 0;
  }
}

//----- (00C9A1C0) --------------------------------------------------------
void __cdecl sub_C9A1C0()
{
  void *v0; // esi

  v0 = dword_CD48F4;
  if ( dword_CD48F4 )
  {
    if ( !InterlockedDecrement((volatile LONG *)dword_CD48F4 + 2) && v0 )
    {
      if ( *(_DWORD *)v0 )
      {
        SysFreeString(*(BSTR *)v0);
        *(_DWORD *)v0 = 0;
      }
      if ( *((_DWORD *)v0 + 1) )
      {
        operator delete[](*((void **)v0 + 1));
        *((_DWORD *)v0 + 1) = 0;
      }
      operator delete(v0);
    }
    dword_CD48F4 = 0;
  }
}

//----- (00C9A220) --------------------------------------------------------
void __cdecl sub_C9A220()
{
  free(dword_4F48E4);
}

//----- (00C9A230) --------------------------------------------------------
void __cdecl sub_C9A230()
{
  free((void *)gpszSystemPathInfo);
}

//----- (00C9A240) --------------------------------------------------------
void __cdecl sub_C9A240()
{
  free(dword_4F48FC);
}

//----- (00C9A250) --------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gKeyNameMap__()
{
  std__Tree_node *v0; // esi
  int a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(
    &gKeyNameMap,
    (std__Tree_node **)&a2,
    (std__Tree_node *)gKeyNameMap._Mypair._Myval2._Myhead->_Left,
    gKeyNameMap._Mypair._Myval2._Myhead);
  v0 = gKeyNameMap._Mypair._Myval2._Myhead;
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  operator delete(v0);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A2D0) --------------------------------------------------------
void __cdecl sub_C9A2D0()
{
  free(dword_4F48F0);
}

//----- (00C9A2E0) --------------------------------------------------------
void __cdecl sub_C9A2E0()
{
  free(sStringInPE_UpdateSystemKey.m_String);
}

//----- (00C9A2F0) --------------------------------------------------------
void __cdecl sub_C9A2F0()
{
  free(gszPrintDirectoryForX86.m_String);
}

//----- (00C9A300) --------------------------------------------------------
void __cdecl sub_C9A300()
{
  free(gszPrintDirectoryForNTX86.m_String);
}

//----- (00C9A310) --------------------------------------------------------
void __cdecl sub_C9A310()
{
  _DWORD **v0; // eax
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  _DWORD **v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // esi

  v0 = (_DWORD **)*(&dword_CD4CD0 + 4);
  v1 = *v0;
  *v0 = v0;
  *(_DWORD *)(*(&dword_CD4CD0 + 4) + 4) = *(&dword_CD4CD0 + 4);
  *(&dword_CD4CD0 + 5) = 0;
  if ( v1 != (_DWORD *)*(&dword_CD4CD0 + 4) )
  {
    do
    {
      v2 = (_DWORD *)*v1;
      operator delete(v1);
      v1 = v2;
    }
    while ( v2 != (_DWORD *)*(&dword_CD4CD0 + 4) );
  }
  operator delete((void *)*(&dword_CD4CD0 + 4));
  v3 = (_DWORD **)*(&dword_CD4CD0 + 2);
  v4 = *v3;
  *v3 = v3;
  *(_DWORD *)(*(&dword_CD4CD0 + 2) + 4) = *(&dword_CD4CD0 + 2);
  *(&dword_CD4CD0 + 3) = 0;
  if ( v4 != (_DWORD *)*(&dword_CD4CD0 + 2) )
  {
    do
    {
      v5 = (_DWORD *)*v4;
      operator delete(v4);
      v4 = v5;
    }
    while ( v5 != (_DWORD *)*(&dword_CD4CD0 + 2) );
  }
  operator delete((void *)*(&dword_CD4CD0 + 2));
}
// CD4CD0: using guessed type int dword_CD4CD0;

//----- (00C9A320) --------------------------------------------------------
void __cdecl sub_C9A320()
{
  std__list_node *v0; // edi
  std__list_node *v1; // ebx
  std__list_node *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = gList1._Mypair._Myval2._Myhead->_Next;
  gList1._Mypair._Myval2._Myhead->_Next = gList1._Mypair._Myval2._Myhead;
  gList1._Mypair._Myval2._Myhead->_Prev = gList1._Mypair._Myval2._Myhead;
  v1 = gList1._Mypair._Myval2._Myhead;
  gList1._Mypair._Myval2._Mysize = 0;
  if ( v0 != gList1._Mypair._Myval2._Myhead )
  {
    do
    {
      v2 = v0->_Next;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(&v0->_Prev);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(&v0->_Myval);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = gList1._Mypair._Myval2._Myhead;
      v0 = v2;
    }
    while ( v2 != gList1._Mypair._Myval2._Myhead );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(&v1->_Prev);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A3F0) --------------------------------------------------------
void __cdecl sub_C9A3F0()
{
  void **v0; // edi
  char *v1; // ebx
  void **v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *(void ***)gList2;
  *(_DWORD *)gList2 = gList2;
  *((_DWORD *)gList2 + 1) = gList2;
  v1 = (char *)gList2;
  *(&gList2 + 1) = 0;
  if ( v0 != gList2 )
  {
    do
    {
      v2 = (void **)*v0;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = (char *)gList2;
      v0 = v2;
    }
    while ( v2 != gList2 );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A4C0) --------------------------------------------------------
void __cdecl sub_C9A4C0()
{
  void **v0; // edi
  char *v1; // ebx
  void **v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *(void ***)gList3;
  *(_DWORD *)gList3 = gList3;
  *((_DWORD *)gList3 + 1) = gList3;
  v1 = (char *)gList3;
  *(&gList3 + 1) = 0;
  if ( v0 != gList3 )
  {
    do
    {
      v2 = (void **)*v0;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = (char *)gList3;
      v0 = v2;
    }
    while ( v2 != gList3 );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A590) --------------------------------------------------------
void __cdecl sub_C9A590()
{
  char *v0; // esi
  char v1; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_C72C10((int **)&gMap5, (int **)&v1, *(int ***)gMap5, (int **)gMap5);
  v0 = (char *)gMap5;
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0 + 4);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0 + 8);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  operator delete(v0);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A610) --------------------------------------------------------
void __cdecl sub_C9A610()
{
  off_CCAA3C[0] = (int (__thiscall **)(void *, char))&std::error_category::`vftable';
}
// CA2D74: using guessed type void *std::error_category::`vftable';
// CCAA3C: using guessed type int (__thiscall **off_CCAA3C[3])(void *, char);

//----- (00C9A620) --------------------------------------------------------
void __cdecl sub_C9A620()
{
  off_CCAA40[0] = (int (__thiscall **)(void *, char))&std::error_category::`vftable';
}
// CA2D74: using guessed type void *std::error_category::`vftable';
// CCAA40: using guessed type int (__thiscall **off_CCAA40[2])(void *, char);

//----- (00C9A630) --------------------------------------------------------
void __cdecl sub_C9A630()
{
  off_CCAA44 = (int (__thiscall **)(void *, char))&std::error_category::`vftable';
}
// CA2D74: using guessed type void *std::error_category::`vftable';
// CCAA44: using guessed type int (__thiscall **off_CCAA44)(void *, char);

//----- (00C9A640) --------------------------------------------------------
void __cdecl sub_C9A640()
{
  free(gActiveScriptEventConsumer.baseclass.m_pszURL);
  free(gActiveScriptEventConsumer.baseclass.m_pszDescription);
}
// CD4D28: using guessed type struct ActiveScriptEventConsumer gActiveScriptEventConsumer;

//----- (00C9A660) --------------------------------------------------------
void __cdecl sub_C9A660()
{
  free(gCommandLineEventConsumer.baseclass.m_pszURL);
  free(gCommandLineEventConsumer.baseclass.m_pszDescription);
}

//----- (00C9A680) --------------------------------------------------------
void __cdecl sub_C9A680()
{
  std__Tree_node *v0; // esi
  char v1; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_C07560(
    (CSystemProcessInfoMap *)&gEventConsumerMap,
    (CSystemProcessInfoMapNode **)&v1,
    (CSystemProcessInfoMapNode *)gEventConsumerMap._Mypair._Myval2._Myhead->_Left,
    (CSystemProcessInfoMapNode *)gEventConsumerMap._Mypair._Myval2._Myhead);
  v0 = gEventConsumerMap._Mypair._Myval2._Myhead;
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  operator delete(v0);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A700) --------------------------------------------------------
void __cdecl sub_C9A700()
{
  if ( ghUxthemeModule )
    FreeLibrary(ghUxthemeModule);
}

//----- (00C9A720) --------------------------------------------------------
void __cdecl sub_C9A720()
{
  int *v0; // edi
  int *v1; // ebx
  int *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = (int *)*gBstrList;
  *gBstrList = (int)gBstrList;
  gBstrList[1] = (int)gBstrList;
  v1 = gBstrList;
  *(&gBstrList + 1) = 0;
  if ( v0 != gBstrList )
  {
    do
    {
      v2 = (int *)*v0;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = gBstrList;
      v0 = v2;
    }
    while ( v2 != gBstrList );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1 + 1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A7F0) --------------------------------------------------------
void __cdecl sub_C9A7F0()
{
  strHeap.baseclass.vtptr = (IAtlMemMgrVTable *)&ATL::CWin32Heap::`vftable';
  if ( strHeap.m_bOwnHeap )
  {
    if ( strHeap.m_hHeap )
      HeapDestroy(strHeap.m_hHeap);
  }
}
// CAC4F8: using guessed type void *ATL::CWin32Heap::`vftable';

//----- (00C9A820) --------------------------------------------------------
void __cdecl sub_C9A820()
{
  strMgr.baseclass.vtptr = (IAtlStringMgrVTable *)&ATL::CAtlStringMgr::`vftable';
  byte_CD4DF4 = 0;
}
// CAC510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// CD4DF4: using guessed type char byte_CD4DF4;

//----- (00C9A840) --------------------------------------------------------
void __cdecl sub_C9A840()
{
  std__list_node *v0; // edi
  std__list_node *v1; // ebx
  std__list_node *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = gAdapterList._Mypair._Myval2._Myhead->_Next;
  gAdapterList._Mypair._Myval2._Myhead->_Next = gAdapterList._Mypair._Myval2._Myhead;
  gAdapterList._Mypair._Myval2._Myhead->_Prev = gAdapterList._Mypair._Myval2._Myhead;
  v1 = gAdapterList._Mypair._Myval2._Myhead;
  gAdapterList._Mypair._Myval2._Mysize = 0;
  if ( v0 != gAdapterList._Mypair._Myval2._Myhead )
  {
    do
    {
      v2 = v0->_Next;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(&v0->_Prev);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(&v0->_Myval);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = gAdapterList._Mypair._Myval2._Myhead;
      v0 = v2;
    }
    while ( v2 != gAdapterList._Mypair._Myval2._Myhead );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(&v1->_Prev);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9A910) --------------------------------------------------------
void __cdecl sub_C9A910()
{
  Data_t_bstr_t *v0; // esi

  v0 = a2.m_Data;
  if ( a2.m_Data )
  {
    if ( !InterlockedDecrement(&a2.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        operator delete[](v0->m_str);
        v0->m_str = 0;
      }
      operator delete(v0);
    }
    a2.m_Data = 0;
  }
}

//----- (00C9A970) --------------------------------------------------------
void __cdecl sub_C9A970()
{
  Data_t_bstr_t *v0; // esi

  v0 = stru_CD9E50.m_Data;
  if ( stru_CD9E50.m_Data )
  {
    if ( !InterlockedDecrement(&stru_CD9E50.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        operator delete[](v0->m_str);
        v0->m_str = 0;
      }
      operator delete(v0);
    }
    stru_CD9E50.m_Data = 0;
  }
}

//----- (00C9A9D0) --------------------------------------------------------
void __cdecl sub_C9A9D0()
{
  PerformanceInfoInMemory::~PerformanceInfoInMemory(&gPerformanceInfoInMemory);
}

//----- (00C9A9E0) --------------------------------------------------------
void __cdecl sub_C9A9E0()
{
  PerformanceInfo::~PerformanceInfo((void **)&gPerformanceInfo.m_pBuffer);
}

//----- (00C9A9F0) --------------------------------------------------------
void __cdecl sub_C9A9F0()
{
  Data_t_bstr_t *v0; // esi

  v0 = gNullString.m_Data;
  if ( gNullString.m_Data )
  {
    if ( !InterlockedDecrement(&gNullString.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        operator delete[](v0->m_str);
        v0->m_str = 0;
      }
      operator delete(v0);
    }
    gNullString.m_Data = 0;
  }
}

//----- (00C9AA50) --------------------------------------------------------
void __cdecl sub_C9AA50()
{
  IWbemServices *v0; // edi
  char *v1; // ebx
  IWbemServices *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = (IWbemServices *)(*(&gWbemServiceList + 1))->lpVtbl;
  (*(&gWbemServiceList + 1))->lpVtbl = (IWbemServicesVtbl *)*(&gWbemServiceList + 1);
  (*(&gWbemServiceList + 1))[1].lpVtbl = (IWbemServicesVtbl *)*(&gWbemServiceList + 1);
  v1 = (char *)*(&gWbemServiceList + 1);
  *(&gWbemServiceList + 2) = 0;
  if ( v0 != *(&gWbemServiceList + 1) )
  {
    do
    {
      v2 = (IWbemServices *)v0->lpVtbl;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(&v0[1]);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(&v0[2]);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = (char *)*(&gWbemServiceList + 1);
      v0 = v2;
    }
    while ( v2 != *(&gWbemServiceList + 1) );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9AB20) --------------------------------------------------------
void __cdecl sub_C9AB20()
{
  std__Tree_node *v0; // esi
  int *a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_C65510(
    (std__tree *)&gThreadProcessMap,
    &a2,
    (std__Tree_node *)gThreadProcessMap._Header->_Left,
    (int *)gThreadProcessMap._Header);
  v0 = gThreadProcessMap._Header;
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  operator delete(v0);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9ABA0) --------------------------------------------------------
void __cdecl sub_C9ABA0()
{
  Data_t_bstr_t *v0; // esi

  v0 = gDiskGraphInfo.strName.m_Data;
  if ( gDiskGraphInfo.strName.m_Data )
  {
    if ( !InterlockedDecrement(&gDiskGraphInfo.strName.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        operator delete[](v0->m_str);
        v0->m_str = 0;
      }
      operator delete(v0);
    }
    gDiskGraphInfo.strName.m_Data = 0;
  }
}

//----- (00C9AC00) --------------------------------------------------------
void __cdecl sub_C9AC00()
{
  Data_t_bstr_t *v0; // esi

  v0 = gIOGraphInfo.strName.m_Data;
  if ( gIOGraphInfo.strName.m_Data )
  {
    if ( !InterlockedDecrement(&gIOGraphInfo.strName.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        operator delete[](v0->m_str);
        v0->m_str = 0;
      }
      operator delete(v0);
    }
    gIOGraphInfo.strName.m_Data = 0;
  }
}

//----- (00C9AC60) --------------------------------------------------------
void __cdecl sub_C9AC60()
{
  Data_t_bstr_t *v0; // esi

  v0 = gNetworkGraphInfo.strName.m_Data;
  if ( gNetworkGraphInfo.strName.m_Data )
  {
    if ( !InterlockedDecrement(&gNetworkGraphInfo.strName.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        operator delete[](v0->m_str);
        v0->m_str = 0;
      }
      operator delete(v0);
    }
    gNetworkGraphInfo.strName.m_Data = 0;
  }
}

//----- (00C9ACC0) --------------------------------------------------------
void __cdecl sub_C9ACC0()
{
  std__Tree_node *v0; // esi
  int *a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_C65510(
    &gMap2_NodeSizeIs48H,
    &a2,
    (std__Tree_node *)gMap2_NodeSizeIs48H._Mypair._Myval2._Myhead->_Left,
    (int *)gMap2_NodeSizeIs48H._Mypair._Myval2._Myhead);
  v0 = gMap2_NodeSizeIs48H._Mypair._Myval2._Myhead;
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  operator delete(v0);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9AD40) --------------------------------------------------------
void __cdecl sub_C9AD40()
{
  std__Tree_node *v0; // esi
  int *a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_C65510(
    &gMap3_NodeSizeIs48H,
    &a2,
    (std__Tree_node *)gMap3_NodeSizeIs48H._Mypair._Myval2._Myhead->_Left,
    (int *)gMap3_NodeSizeIs48H._Mypair._Myval2._Myhead);
  v0 = gMap3_NodeSizeIs48H._Mypair._Myval2._Myhead;
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  operator delete(v0);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9ADC0) --------------------------------------------------------
void __cdecl sub_C9ADC0()
{
  if ( hdc )
    DeleteDC(hdc);
  if ( dword_CF5724 )
    DeleteObject(dword_CF5724);
}

//----- (00C9ADF0) --------------------------------------------------------
void __cdecl HttpInfo_Release()
{
  std__list_node *v0; // eax
  std__list_node *v1; // ecx
  std__list_node *v2; // esi
  std__list_node *v3; // eax
  std__list_node *v4; // ecx
  std__list_node *v5; // esi

  v0 = gHttpInfo.m_List2._Mypair._Myval2._Myhead;
  v1 = v0->_Next;
  v0->_Next = v0;
  gHttpInfo.m_List2._Mypair._Myval2._Myhead->_Prev = gHttpInfo.m_List2._Mypair._Myval2._Myhead;
  gHttpInfo.m_List2._Mypair._Myval2._Mysize = 0;
  if ( v1 != gHttpInfo.m_List2._Mypair._Myval2._Myhead )
  {
    do
    {
      v2 = v1->_Next;
      operator delete(v1);
      v1 = v2;
    }
    while ( v2 != gHttpInfo.m_List2._Mypair._Myval2._Myhead );
  }
  operator delete(gHttpInfo.m_List2._Mypair._Myval2._Myhead);
  v3 = gHttpInfo.m_List._Mypair._Myval2._Myhead;
  v4 = v3->_Next;
  v3->_Next = v3;
  gHttpInfo.m_List._Mypair._Myval2._Myhead->_Prev = gHttpInfo.m_List._Mypair._Myval2._Myhead;
  gHttpInfo.m_List._Mypair._Myval2._Mysize = 0;
  if ( v4 != gHttpInfo.m_List._Mypair._Myval2._Myhead )
  {
    do
    {
      v5 = v4->_Next;
      operator delete(v4);
      v4 = v5;
    }
    while ( v5 != gHttpInfo.m_List._Mypair._Myval2._Myhead );
  }
  operator delete(gHttpInfo.m_List._Mypair._Myval2._Myhead);
}

//----- (00C9AE00) --------------------------------------------------------
void __cdecl sub_C9AE00()
{
  std__list_node *v0; // edi
  std__list_node *v1; // ebx
  std__list_node *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = gList10._Mypair._Myval2._Myhead->_Next;
  gList10._Mypair._Myval2._Myhead->_Next = gList10._Mypair._Myval2._Myhead;
  gList10._Mypair._Myval2._Myhead->_Prev = gList10._Mypair._Myval2._Myhead;
  v1 = gList10._Mypair._Myval2._Myhead;
  gList10._Mypair._Myval2._Mysize = 0;
  if ( v0 != gList10._Mypair._Myval2._Myhead )
  {
    do
    {
      v2 = v0->_Next;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(&v0->_Prev);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(&v0->_Myval);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = gList10._Mypair._Myval2._Myhead;
      v0 = v2;
    }
    while ( v2 != gList10._Mypair._Myval2._Myhead );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(&v1->_Prev);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9AED0) --------------------------------------------------------
void __cdecl sub_C9AED0()
{
  void **v0; // edi
  char *v1; // ebx
  void **v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *(void ***)gList11;
  *(_DWORD *)gList11 = gList11;
  *((_DWORD *)gList11 + 1) = gList11;
  v1 = (char *)gList11;
  *(&gList11 + 1) = 0;
  if ( v0 != gList11 )
  {
    do
    {
      v2 = (void **)*v0;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = (char *)gList11;
      v0 = v2;
    }
    while ( v2 != gList11 );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9AFA0) --------------------------------------------------------
void __cdecl sub_C9AFA0()
{
  EventList *v0; // edi
  EventList *v1; // ebx
  EventList *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = (EventList *)gList12->_Myheader;
  gList12->_Myheader = (EventListNode *)gList12;
  gList12->_Mysize = (int)gList12;
  v1 = gList12;
  *(&gList12 + 1) = 0;
  if ( v0 != gList12 )
  {
    do
    {
      v2 = (EventList *)v0->_Myheader;
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v5);
      nullsub_2(&v0->_Mysize);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
      nullsub_2(&v0[1]);
      ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
      operator delete(v0);
      v1 = gList12;
      v0 = v2;
    }
    while ( v2 != gList12 );
  }
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v4);
  nullsub_2(&v1->_Mysize);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v3);
  operator delete(v1);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9B070) --------------------------------------------------------
void __cdecl sub_C9B070()
{
  std__Tree_node *v0; // esi
  char v1; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_C72C10(
    (int **)&gHttpInfo.m_Map,
    (int **)&v1,
    (int **)gHttpInfo.m_Map._Mypair._Myval2._Myhead->_Left,
    (int **)gHttpInfo.m_Map._Mypair._Myval2._Myhead);
  v0 = gHttpInfo.m_Map._Mypair._Myval2._Myhead;
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone((ATL::CAtlStringMgr *)&v2);
  operator delete(v0);
}
// C07A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (00C9B0F0) --------------------------------------------------------
void __cdecl sub_C9B0F0()
{
  VariantClear(&pvarg);
}

//----- (00C9B0FC) --------------------------------------------------------
void __cdecl sub_C9B0FC()
{
  struct _RTL_CRITICAL_SECTION *v0; // esi

  if ( _InterlockedExchangeAdd((volatile signed __int32 *)&unk_CD13A0, 0xFFFFFFFF) < 0 )
  {
    v0 = &stru_CF57E0;
    do
    {
      _Mtxdst(v0);
      ++v0;
    }
    while ( (signed int)v0 < (signed int)&dword_CF5840 );
  }
}
// CF5840: using guessed type int dword_CF5840;

//----- (00C9B106) --------------------------------------------------------
void __cdecl sub_C9B106()
{
  std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t((std::_Fac_tidy_reg_t *)&unk_CF585A);
}

//----- (00C9B110) --------------------------------------------------------
void __cdecl sub_C9B110()
{
  std::locale::~locale((std::locale *)&dword_CF5864);
}
// CF5864: using guessed type int dword_CF5864;

//----- (00C9B11A) --------------------------------------------------------
void __cdecl sub_C9B11A()
{
  _Init_atexit::~_Init_atexit((_Init_atexit *)&unk_CF58F3);
}

//----- (00C9B124) --------------------------------------------------------
void __cdecl sub_C9B124()
{
  struct _RTL_CRITICAL_SECTION *v0; // esi

  if ( _InterlockedExchangeAdd((volatile signed __int32 *)&unk_CD13A0, 0xFFFFFFFF) < 0 )
  {
    v0 = &stru_CF57E0;
    do
    {
      _Mtxdst(v0);
      ++v0;
    }
    while ( (signed int)v0 < (signed int)&dword_CF5840 );
  }
}
// CF5840: using guessed type int dword_CF5840;

//----- (00C9B12E) --------------------------------------------------------
void __cdecl ATL::_dynamic_atexit_destructor_for___AtlBaseModule__()
{
  ATL::CAtlBaseModule::~CAtlBaseModule((int)&ATL::_AtlBaseModule);
}

#error "There were 1 decompilation failure(s) on 1648 function(s)"
