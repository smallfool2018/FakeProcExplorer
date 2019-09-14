
//----- (0104DF20) --------------------------------------------------------
int __cdecl TreeViewListItemParam_GetSystemInfo(SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo, HANDLE ProcessHandleIn, int a3, int a4, int a5, int a6, tagTREEVIEWLISTITEMPARAM *pItemParam, WPARAM wParam)
{
  signed int v8; // edx
  char fUsingCSwitchDelta; // bh
  char v10; // bl
  int dwIndex; // esi
  int uID; // ecx
  bool fNeedObjects; // al
  bool fUsingProcessCycle; // al
  bool fUsingMemoryPriority; // al
  int fUsingWS; // eax
  bool v17; // zf
  WPARAM v18; // ebx
  int v19; // edx
  bool v20; // cf
  int v21; // ecx
  int v22; // esi
  bool v23; // al
  char v24; // al
  unsigned int v25; // edx
  bool v26; // cl
  unsigned int v27; // edx
  unsigned int v28; // ecx
  signed int v29; // eax
  unsigned __int64 v30; // kr10_8
  __int64 v31; // kr18_8
  bool v32; // al
  char v33; // al
  int v34; // ecx
  int v35; // ecx
  bool v36; // al
  HANDLE ProcessHandle; // esi
  void *v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // ecx
  unsigned __int64 v41; // kr28_8
  bool v42; // al
  signed int v43; // ecx
  unsigned __int8 v44; // al
  int v45; // ecx
  char v46; // al
  int v47; // ecx
  char v48; // al
  char v49; // al
  char v50; // al
  char v51; // al
  char v52; // al
  char v53; // al
  int v54; // eax
  char v55; // al
  char v56; // bl
  int v57; // eax
  char v58; // al
  char v59; // cl
  char v60; // al
  char v61; // cl
  char v62; // al
  char v63; // cl
  int v64; // esi
  SYSTEM_PROCESS_INFORMATION *v65; // ecx
  int v66; // edx
  int v67; // eax
  unsigned int v68; // eax
  unsigned __int64 v69; // kr48_8
  int v70; // esi
  char v71; // al
  signed int v72; // ecx
  int v73; // esi
  char v74; // al
  signed int v75; // ecx
  HWND v76; // esi
  char v77; // al
  SYSTEM_PROCESS_INFORMATION *v78; // edx
  HWND v79; // ecx
  unsigned __int8 v80; // al
  HWND v81; // ST34_4
  int v82; // edx
  unsigned __int8 v83; // al
  HWND v84; // ecx
  HWND v85; // ST34_4
  int v86; // edx
  unsigned __int8 v87; // al
  HWND v88; // ecx
  HWND v89; // ST34_4
  unsigned int v90; // edx
  unsigned __int8 v91; // al
  HWND v92; // ecx
  HWND v93; // ST34_4
  char v94; // al
  int v95; // esi
  HWND v96; // ecx
  unsigned __int8 v97; // al
  char v98; // al
  unsigned int v99; // edx
  HWND v100; // ecx
  unsigned __int8 v101; // al
  HWND v102; // ST34_4
  char v103; // al
  int v104; // esi
  HWND v105; // ecx
  unsigned __int8 v106; // al
  char v107; // al
  unsigned int v108; // edx
  HWND v109; // ecx
  unsigned __int8 v110; // al
  HWND v111; // ST34_4
  char v112; // al
  int v113; // esi
  HWND v114; // ecx
  unsigned __int8 v115; // al
  char v116; // al
  unsigned int v117; // edx
  HWND v118; // ecx
  unsigned __int8 v119; // al
  HWND v120; // ST34_4
  char v121; // al
  SYSTEM_PROCESS_INFORMATION *v122; // ecx
  int v123; // esi
  unsigned int v124; // ecx
  char v125; // al
  signed int v126; // ecx
  unsigned int v127; // eax
  unsigned int v128; // eax
  unsigned __int64 v129; // kr58_8
  char v130; // al
  signed int v131; // ecx
  unsigned int v132; // eax
  unsigned int v133; // eax
  unsigned __int64 v134; // kr60_8
  char v135; // al
  signed int v136; // ecx
  unsigned int v137; // ecx
  int v138; // ecx
  int v139; // eax
  bool v140; // dl
  HWND v141; // ST34_4
  char v142; // al
  unsigned int v143; // edx
  signed int v144; // ecx
  int v145; // edx
  int v146; // eax
  bool v147; // cl
  HWND v148; // ST34_4
  char v149; // al
  unsigned int v150; // edx
  signed int v151; // ecx
  int v152; // edx
  int v153; // ecx
  bool v154; // al
  HWND v155; // ST34_4
  char v156; // al
  HWND v157; // ecx
  int v158; // eax
  bool v159; // al
  char v160; // al
  signed int v161; // ecx
  int v162; // edx
  int v163; // ecx
  bool v164; // al
  HWND v165; // ST34_4
  char v166; // al
  HWND v167; // ecx
  int v168; // eax
  bool v169; // al
  char v170; // al
  signed int v171; // ecx
  int v172; // edx
  int v173; // ecx
  bool v174; // al
  HWND v175; // ST34_4
  char v176; // al
  HWND v177; // ecx
  int v178; // eax
  bool v179; // al
  char v180; // al
  signed int v181; // ecx
  int v182; // edx
  int v183; // ecx
  bool v184; // al
  HWND v185; // ST34_4
  char v186; // al
  HWND v187; // esi
  HWND v188; // ecx
  int v189; // eax
  unsigned int v190; // eax
  unsigned __int64 v191; // kr70_8
  bool v192; // dl
  char v193; // al
  char v194; // cl
  _DWORD *v195; // esi
  unsigned int v196; // ecx
  char v197; // al
  signed int v198; // ecx
  unsigned int v199; // eax
  unsigned int v200; // eax
  unsigned __int64 v201; // kr80_8
  char v202; // al
  signed int v203; // ecx
  unsigned int v204; // eax
  unsigned int v205; // eax
  unsigned __int64 v206; // kr88_8
  char v207; // al
  signed int v208; // ecx
  unsigned int v209; // ecx
  int v210; // ecx
  int v211; // eax
  bool v212; // dl
  HWND v213; // ST34_4
  char v214; // al
  unsigned int v215; // edx
  signed int v216; // ecx
  int v217; // edx
  int v218; // eax
  bool v219; // cl
  HWND v220; // ST34_4
  char v221; // al
  unsigned int v222; // edx
  signed int v223; // ecx
  int v224; // edx
  int v225; // ecx
  bool v226; // al
  HWND v227; // ST34_4
  char v228; // al
  HWND v229; // ecx
  int v230; // eax
  bool v231; // al
  char v232; // al
  signed int v233; // ecx
  int v234; // edx
  int v235; // ecx
  bool v236; // al
  HWND v237; // ST34_4
  char v238; // al
  HWND v239; // ecx
  int v240; // eax
  bool v241; // al
  char v242; // al
  signed int v243; // ecx
  int v244; // edx
  int v245; // ecx
  bool v246; // al
  HWND v247; // ST34_4
  char v248; // al
  HWND v249; // ecx
  int v250; // eax
  bool v251; // al
  char v252; // al
  signed int v253; // ecx
  int v254; // edx
  int v255; // ecx
  bool v256; // al
  HWND v257; // ST34_4
  char v258; // al
  HWND v259; // esi
  HWND v260; // ecx
  int v261; // eax
  unsigned int v262; // eax
  unsigned __int64 v263; // kr98_8
  bool v264; // dl
  char v265; // cl
  UINT_PTR MaximumWorkingSetSize; // [esp+8h] [ebp-88Ch]
  UINT_PTR MinimumWorkingSetSize; // [esp+Ch] [ebp-888h]
  unsigned int v268; // [esp+10h] [ebp-884h]
  int ProcessInformation; // [esp+14h] [ebp-880h]
  int v270; // [esp+18h] [ebp-87Ch]
  int v271; // [esp+1Ch] [ebp-878h]
  ULONG ReturnLength; // [esp+20h] [ebp-874h]
  int v273; // [esp+24h] [ebp-870h]
  int v274; // [esp+28h] [ebp-86Ch]
  int v275; // [esp+2Ch] [ebp-868h]
  HANDLE hProcess; // [esp+30h] [ebp-864h]
  unsigned __int64 llValue277; // [esp+34h] [ebp-860h]
  SYSTEM_PROCESS_INFORMATION *SystemProcessInfo; // [esp+3Ch] [ebp-858h]
  char v279; // [esp+40h] [ebp-854h]
  char v280; // [esp+41h] [ebp-853h]
  char v281; // [esp+42h] [ebp-852h]
  char v282; // [esp+43h] [ebp-851h]
  int v283; // [esp+48h] [ebp-84Ch]
  unsigned int v284; // [esp+4Ch] [ebp-848h]
  bool v285; // [esp+53h] [ebp-841h]
  int v286; // [esp+54h] [ebp-840h]
  HWND hWnd[2]; // [esp+58h] [ebp-83Ch]
  IO_COUNTERS IoCounters; // [esp+60h] [ebp-834h]
  __int64 ProcessorIdleCycleTime[256]; // [esp+90h] [ebp-804h]

  LOBYTE(v8) = 0;
  fUsingCSwitchDelta = 0;
  SystemProcessInfo = pSystemProcessInfo;
  v10 = 0;
  dwIndex = 0;
  hProcess = ProcessHandleIn;
  v286 = v8;
  v281 = 0;
  v280 = 0;
  v279 = 0;
  v282 = 0;
  v285 = 0;
  llValue277 = 0i64;
  if ( gConfig.dwProcessColumnCount <= 0 )
    goto LABEL_271;
  BYTE1(v8) = 0;
  v285 = gdwVersion >= 1;
  do
  {
    uID = gConfig.dwProcessColumnMap[dwIndex];
    fNeedObjects = uID == IDS_GDI_OBJECTS || uID == IDS_USER_OBJECTS;
    v281 |= fNeedObjects;
    fUsingCSwitchDelta |= uID == IDS_CSWITCH_DELTA;
    fUsingProcessCycle = QueryProcessCycleTime
                      || uID == IDS_CPU
                      || uID == IDS_CYCLES
                      || uID == IDS_CYCLES_DELTA
                      || uID == IDS_CYCLECPUUSAGE;
    v10 |= fUsingProcessCycle;
    v279 |= v285;
    fUsingMemoryPriority = gdwVersion >= 1 && uID == IDS_MEMORY_PRIORITY;
    BYTE1(v8) |= fUsingMemoryPriority;
    fUsingWS = uID == IDS_WS_PRIVATE || uID == IDS_WS_SHAREABLE || uID == IDS_WS_SHARED;
    ++dwIndex;
    LOBYTE(v8) = fUsingWS | v8;
  }
  while ( dwIndex < gConfig.dwProcessColumnCount );
  v282 = BYTE1(v8);
  v17 = v8 == 0;
  v280 = v8;
  LOBYTE(v8) = v286;
  v285 = v10;
  if ( v17 )
  {
LABEL_271:
    fUsingWS = pItemParam->field_3A0;
    if ( fUsingWS )
    {
      free(pItemParam->field_3A0);
      LOBYTE(v8) = v286;
      pItemParam->field_3A0 = 0;
      pItemParam->field_3A4 = 0;
    }
  }
  v17 = fUsingCSwitchDelta == 0;
  v18 = wParam;
  if ( v17 )
  {
    pItemParam->ContextSwtichDelta = 0i64;
  }
  else
  {
    v284 = sub_103A500(SystemProcessInfo);
    v20 = v284 < LODWORD(pItemParam->ContextSwtiches);
    v21 = v284 - LODWORD(pItemParam->ContextSwtiches);
    v274 = v19;
    v22 = v19 - (v20 + HIDWORD(pItemParam->ContextSwtiches));
    if ( v19 - (v20 + HIDWORD(pItemParam->ContextSwtiches)) < 0
      || v19 <= v20 + HIDWORD(pItemParam->ContextSwtiches) && !v21 )
    {
      *hWnd = 0i64;
      v22 = 0;
      v21 = 0;
    }
    v23 = v21 != LODWORD(pItemParam->ContextSwtichDelta) || v22 != HIDWORD(pItemParam->ContextSwtichDelta);
    LODWORD(pItemParam->ContextSwtichDelta) = v21;
    HIDWORD(pItemParam->ContextSwtichDelta) = v22;
    v24 = RedrawColumn(v23, ghWndTreeListView, IDS_CSWITCH_DELTA, wParam);
    v25 = v284;
    LOBYTE(v286) = v24;
    v26 = v284 != LODWORD(pItemParam->ContextSwtiches) || v274 != HIDWORD(pItemParam->ContextSwtiches);
    HIDWORD(pItemParam->ContextSwtiches) = v274;
    LODWORD(pItemParam->ContextSwtiches) = v25;
    LOBYTE(fUsingWS) = RedrawColumn(v26, ghWndTreeListView, IDS_CONTEXT_SWITCHES, wParam);
    v8 = v286;
    LOBYTE(v8) = fUsingWS | v286;
    v286 = v8;
  }
  if ( !pItemParam->dwProcessId )
  {
    if ( v285 && QueryIdleProcessorCycleTime )
    {
      if ( gdwVersion < 2
        || (v28 = SystemProcessInfo->SpareLi3.QuadPart >> 32,
            v27 = SystemProcessInfo->SpareLi3.QuadPart,
            !SystemProcessInfo->SpareLi3.QuadPart) )
      {
        ReturnLength = 8 * gSystemInfo.dwNumberOfProcessors;
        QueryIdleProcessorCycleTime(&ReturnLength, ProcessorIdleCycleTime);
        v29 = 0;
        v28 = HIDWORD(llValue277);
        v27 = llValue277;
        if ( gSystemInfo.dwNumberOfProcessors <= 0 )
        {
LABEL_50:
          v31 = __PAIR__(v28, v27) - pItemParam->Cycles;
          v32 = v31 != pItemParam->CyclesDelta;
          pItemParam->CyclesDelta = v31;
          v33 = RedrawColumn(v32, ghWndTreeListView, IDS_CYCLES_DELTA, wParam);
          v34 = v286;
          LOBYTE(v34) = v33 | v286;
          v286 = v34;
          v35 = HIDWORD(llValue277);
          v36 = llValue277 != pItemParam->Cycles;
          LODWORD(pItemParam->Cycles) = llValue277;
          HIDWORD(pItemParam->Cycles) = v35;
          LOBYTE(fUsingWS) = RedrawColumn(v36, ghWndTreeListView, IDS_CYCLES, wParam);
          LOBYTE(fUsingWS) = fUsingWS | v286;
          return fUsingWS;
        }
        do
        {
          v30 = __PAIR__(HIDWORD(ProcessorIdleCycleTime[v29]), ProcessorIdleCycleTime[v29]) + __PAIR__(v28, v27);
          v28 = (__PAIR__(HIDWORD(ProcessorIdleCycleTime[v29]), ProcessorIdleCycleTime[v29]) + __PAIR__(v28, v27)) >> 32;
          v27 = v30;
          ++v29;
        }
        while ( v29 < gSystemInfo.dwNumberOfProcessors );
      }
      llValue277 = __PAIR__(v28, v27);
      goto LABEL_50;
    }
    goto LABEL_268;
  }
  ProcessHandle = hProcess;
  if ( v285 && QueryIdleProcessorCycleTime )
  {
    v38 = SystemProcessInfo;
    if ( !hProcess )
    {
      fUsingWS = SystemProcessInfo->SpareLi3.HighPart | SystemProcessInfo->SpareLi3.LowPart;
      if ( !SystemProcessInfo->SpareLi3.QuadPart )
        goto LABEL_268;
    }
    if ( gdwVersion >= 2
      && (v38 = (SystemProcessInfo->SpareLi3.QuadPart >> 32),
          v39 = SystemProcessInfo->SpareLi3.QuadPart,
          SystemProcessInfo->SpareLi3.QuadPart) )
    {
      llValue277 = __PAIR__(v38, v39);
    }
    else
    {
      QueryProcessCycleTime(v38, hProcess);
      v38 = HIDWORD(llValue277);
      v39 = llValue277;
    }
    v41 = __PAIR__(v38, v39) - pItemParam->Cycles;
    v40 = (__PAIR__(v38, v39) - pItemParam->Cycles) >> 32;
    v42 = __PAIR__(v40, v41) != pItemParam->CyclesDelta;
    pItemParam->CyclesDelta = __PAIR__(v40, v41);
    v17 = RedrawColumn(v42, ghWndTreeListView, IDS_CYCLES_DELTA, wParam) == 0;
    v43 = v286;
    v44 = 1;
    if ( !v17 )
      v43 = 1;
    v284 = v43;
    v45 = HIDWORD(llValue277);
    if ( llValue277 == pItemParam->Cycles )
      v44 = 0;
    LODWORD(pItemParam->Cycles) = llValue277;
    HIDWORD(pItemParam->Cycles) = v45;
    v17 = RedrawColumn(v44, ghWndTreeListView, IDS_CYCLES, wParam) == 0;
    v8 = v284;
    fUsingWS = 1;
    if ( !v17 )
      v8 = 1;
    v286 = v8;
  }
  if ( !ProcessHandle )
  {
LABEL_268:
    LOBYTE(fUsingWS) = v8;
    return fUsingWS;
  }
  if ( wParam != -1 && GetProcessWorkingSetSize(ProcessHandle, &MinimumWorkingSetSize, &MaximumWorkingSetSize) )
  {
    v17 = MinimumWorkingSetSize == pItemParam->dwMinimumWorkingSetSize;
    pItemParam->dwMinimumWorkingSetSize = MinimumWorkingSetSize;
    v46 = RedrawColumn(!v17, ghWndTreeListView, IDS_MIN_WORKING_SET, wParam);
    v47 = v286;
    LOBYTE(v47) = v46 | v286;
    v17 = MaximumWorkingSetSize == pItemParam->dwMaximumWorkingSetSize;
    v286 = v47;
    pItemParam->dwMaximumWorkingSetSize = MaximumWorkingSetSize;
    v48 = RedrawColumn(!v17, ghWndTreeListView, IDS_MAX_WORKING_SET, wParam);
    LOBYTE(v286) = v48 | v286;
  }
  v49 = sub_1013340(
          ProcessHandle,
          __PAIR__(a4, a3) / gSystemInfo.dwNumberOfProcessors,
          (__PAIR__(a4, a3) / gSystemInfo.dwNumberOfProcessors) >> 32,
          a5,
          a6,
          pItemParam,
          wParam);
  LOBYTE(v286) = v49 | v286;
  if ( v280 )
  {
    sub_103EB20(ProcessHandle, &pItemParam->field_3A0, &pItemParam->field_3A4, &v284, &v275, &v271, &v273);
    if ( wParam != -1 )
    {
      v17 = v284 == pItemParam->WSTotal;
      pItemParam->WSTotal = v284;
      v50 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_TOTAL, wParam);
      LOBYTE(v286) = v50 | v286;
      v17 = v275 == pItemParam->WSPrivate;
      pItemParam->WSPrivate = v275;
      v51 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_PRIVATE, wParam);
      LOBYTE(v286) = v51 | v286;
      v17 = v271 == pItemParam->WSShareable;
      pItemParam->WSShareable = v271;
      v52 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_SHAREABLE, wParam);
      LOBYTE(v286) = v52 | v286;
      v17 = v273 == pItemParam->WSShared;
      pItemParam->WSShared = v273;
      v53 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_SHARED, wParam);
      LOBYTE(v286) = v53 | v286;
    }
  }
  if ( v281 )
  {
    v54 = GetGuiResources(ProcessHandle, 0);
    v17 = v54 == pItemParam->m_GdiObjects;
    pItemParam->m_GdiObjects = v54;
    v55 = RedrawColumn(!v17, ghWndTreeListView, IDS_GDI_OBJECTS, wParam);
    v56 = v286;
    if ( v55 )
      v56 = 1;
    v57 = GetGuiResources(ProcessHandle, 1u);
    v17 = v57 == pItemParam->m_UserObjects;
    pItemParam->m_UserObjects = v57;
    v58 = RedrawColumn(!v17, ghWndTreeListView, IDS_USER_OBJECTS, wParam);
    v59 = v56;
    v18 = wParam;
    if ( v58 )
      v59 = 1;
    LOBYTE(v286) = v59;
  }
  if ( v282 )
  {
    ProcessInformation = -1;
    NtQueryInformationProcess(ProcessHandle, ProcessPagePriority, &ProcessInformation, 4u, &ReturnLength);
    v17 = ProcessInformation == pItemParam->m_ProcessMemoryPriority;
    pItemParam->m_ProcessMemoryPriority = ProcessInformation;
    v60 = RedrawColumn(!v17, ghWndTreeListView, IDS_MEMORY_PRIORITY, v18);
    v61 = v286;
    if ( v60 )
      v61 = 1;
    LOBYTE(v286) = v61;
  }
  if ( v279 )
  {
    v270 = -1;
    NtQueryInformationProcess(ProcessHandle, ProcessIoPriority, &v270, 4u, &ReturnLength);
    v17 = v270 == pItemParam->m_ProcessIoPriority;
    pItemParam->m_ProcessIoPriority = v270;
    v62 = RedrawColumn(!v17, ghWndTreeListView, IDS_IO_PRIORITY, v18);
    v63 = v286;
    if ( v62 )
      v63 = 1;
    LOBYTE(v286) = v63;
  }
  fUsingWS = NtQueryInformationProcess(ProcessHandle, ProcessIoCounters, &IoCounters, 0x30u, &ReturnLength);
  if ( fUsingWS )
  {
    LOBYTE(fUsingWS) = v286;
  }
  else
  {
    v64 = LODWORD(IoCounters.ReadTransferCount) - LODWORD(pItemParam->IO_COUNTERS);
    v65 = ((IoCounters.ReadTransferCount - pItemParam->IO_COUNTERS) >> 32);
    v283 = LODWORD(IoCounters.WriteOperationCount) - LODWORD(pItemParam->WriteOperationCount);
    v66 = (IoCounters.WriteTransferCount - pItemParam->WriteTransferCount) >> 32;
    v268 = LODWORD(IoCounters.WriteTransferCount) - LODWORD(pItemParam->WriteTransferCount);
    hWnd[1] = (LODWORD(IoCounters.OtherOperationCount) - LODWORD(pItemParam->OtherOperationCount));
    v67 = (IoCounters.OtherTransferCount - pItemParam->OtherTransferCount) >> 32;
    v271 = LODWORD(IoCounters.OtherTransferCount) - LODWORD(pItemParam->OtherTransferCount);
    v274 = v64;
    v275 = v67;
    v69 = __PAIR__(v65, v64) + __PAIR__(v66, v268) + __PAIR__(v67, v271);
    v68 = (__PAIR__(v65, v64) + __PAIR__(v66, v268) + __PAIR__(v67, v271)) >> 32;
    hProcess = v69;
    SystemProcessInfo = v65;
    v70 = LODWORD(IoCounters.ReadOperationCount) - LODWORD(pItemParam->ReadOperationCount);
    v273 = v66;
    v284 = v68;
    v71 = RedrawColumn(v70 != LODWORD(pItemParam->IoDeltaReads), ghWndTreeListView, IDS_IO_DELTA_READS, v18);
    v72 = v286;
    LODWORD(pItemParam->IoDeltaReads) = v70;
    v73 = v283;
    if ( v71 )
      v72 = 1;
    v286 = v72;
    v74 = RedrawColumn(v283 != LODWORD(pItemParam->IoDeltaWrites), ghWndTreeListView, IDS_IO_DELTA_WRITES, v18);
    v75 = v286;
    LODWORD(pItemParam->IoDeltaWrites) = v73;
    v76 = hWnd[1];
    if ( v74 )
      v75 = 1;
    v283 = v75;
    v77 = RedrawColumn(hWnd[1] != LODWORD(pItemParam->IoDeltaOthers), ghWndTreeListView, IDS_IO_DELTA_OTHER, v18);
    v78 = SystemProcessInfo;
    v17 = v77 == 0;
    v79 = v283;
    v80 = 1;
    if ( !v17 )
      v79 = 1;
    LODWORD(pItemParam->IoDeltaOthers) = v76;
    hWnd[1] = v79;
    if ( v274 == LODWORD(pItemParam->DeltaReadBytes) && v78 == HIDWORD(pItemParam->DeltaReadBytes) )
      v80 = 0;
    v81 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaReadBytes) = v274;
    HIDWORD(pItemParam->DeltaReadBytes) = v78;
    v17 = RedrawColumn(v80, v81, IDS_IO_DELTA_READ_BYTES, v18) == 0;
    v82 = v273;
    v83 = 1;
    v84 = LOBYTE(hWnd[1]);
    if ( !v17 )
      v84 = 1;
    hWnd[1] = v84;
    if ( v268 == LODWORD(pItemParam->DeltaWriteBytes) && v273 == HIDWORD(pItemParam->DeltaWriteBytes) )
      v83 = 0;
    v85 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaWriteBytes) = v268;
    HIDWORD(pItemParam->DeltaWriteBytes) = v82;
    v17 = RedrawColumn(v83, v85, IDS_IO_DELTA_WRITE_BYTES, v18) == 0;
    v86 = v275;
    v87 = 1;
    v88 = LOBYTE(hWnd[1]);
    if ( !v17 )
      v88 = 1;
    hWnd[1] = v88;
    if ( v271 == LODWORD(pItemParam->DeltaOtherBytes) && v275 == HIDWORD(pItemParam->DeltaOtherBytes) )
      v87 = 0;
    v89 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaOtherBytes) = v271;
    HIDWORD(pItemParam->DeltaOtherBytes) = v86;
    v17 = RedrawColumn(v87, v89, IDS_IO_DELTA_OTHER_BYTES, v18) == 0;
    v90 = v284;
    v91 = 1;
    v92 = LOBYTE(hWnd[1]);
    if ( !v17 )
      v92 = 1;
    hWnd[1] = v92;
    if ( hProcess == LODWORD(pItemParam->DeltaTotalBytes) && v284 == HIDWORD(pItemParam->DeltaTotalBytes) )
      v91 = 0;
    v93 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaTotalBytes) = hProcess;
    HIDWORD(pItemParam->DeltaTotalBytes) = v90;
    v94 = RedrawColumn(v91, v93, IDS_IO_DELTA_TOTAL_BYTES, v18);
    v95 = IoCounters.ReadOperationCount;
    v17 = v94 == 0;
    v96 = LOBYTE(hWnd[1]);
    v97 = 1;
    if ( !v17 )
      v96 = 1;
    hWnd[1] = v96;
    if ( IoCounters.ReadOperationCount == LODWORD(pItemParam->ReadOperationCount) )
      v97 = 0;
    v283 = HIDWORD(IoCounters.ReadOperationCount);
    v98 = RedrawColumn(v97, ghWndTreeListView, IDS_IO_READS, v18);
    v99 = IoCounters.ReadTransferCount;
    v17 = v98 == 0;
    v100 = LOBYTE(hWnd[1]);
    v101 = 1;
    if ( !v17 )
      v100 = 1;
    LODWORD(pItemParam->ReadOperationCount) = v95;
    hWnd[1] = v100;
    if ( __PAIR__(HIDWORD(IoCounters.ReadTransferCount), v99) == pItemParam->IO_COUNTERS )
      v101 = 0;
    v102 = ghWndTreeListView;
    pItemParam->IO_COUNTERS = __PAIR__(HIDWORD(IoCounters.ReadTransferCount), v99);
    v103 = RedrawColumn(v101, v102, IDS_IO_READ_BYTES, v18);
    v104 = IoCounters.WriteOperationCount;
    v17 = v103 == 0;
    v105 = LOBYTE(hWnd[1]);
    v106 = 1;
    if ( !v17 )
      v105 = 1;
    hWnd[1] = v105;
    if ( IoCounters.WriteOperationCount == LODWORD(pItemParam->WriteOperationCount) )
      v106 = 0;
    v283 = HIDWORD(IoCounters.WriteOperationCount);
    v107 = RedrawColumn(v106, ghWndTreeListView, IDS_IO_WRITES, v18);
    v108 = IoCounters.WriteTransferCount;
    v17 = v107 == 0;
    v109 = LOBYTE(hWnd[1]);
    v110 = 1;
    if ( !v17 )
      v109 = 1;
    LODWORD(pItemParam->WriteOperationCount) = v104;
    hWnd[1] = v109;
    if ( __PAIR__(HIDWORD(IoCounters.WriteTransferCount), v108) == pItemParam->WriteTransferCount )
      v110 = 0;
    v111 = ghWndTreeListView;
    pItemParam->WriteTransferCount = __PAIR__(HIDWORD(IoCounters.WriteTransferCount), v108);
    v112 = RedrawColumn(v110, v111, IDS_IO_WRITE_BYTES, v18);
    v113 = IoCounters.OtherOperationCount;
    v17 = v112 == 0;
    v114 = LOBYTE(hWnd[1]);
    v115 = 1;
    if ( !v17 )
      v114 = 1;
    hWnd[1] = v114;
    if ( IoCounters.OtherOperationCount == LODWORD(pItemParam->OtherOperationCount) )
      v115 = 0;
    v283 = HIDWORD(IoCounters.OtherOperationCount);
    v116 = RedrawColumn(v115, ghWndTreeListView, IDS_IO_OTHER, v18);
    v117 = IoCounters.OtherTransferCount;
    v17 = v116 == 0;
    v118 = LOBYTE(hWnd[1]);
    v119 = 1;
    if ( !v17 )
      v118 = 1;
    LODWORD(pItemParam->OtherOperationCount) = v113;
    hWnd[1] = v118;
    if ( __PAIR__(HIDWORD(IoCounters.OtherTransferCount), v117) == pItemParam->OtherTransferCount )
      v119 = 0;
    v120 = ghWndTreeListView;
    pItemParam->OtherTransferCount = __PAIR__(HIDWORD(IoCounters.OtherTransferCount), v117);
    v121 = RedrawColumn(v119, v120, IDS_IO_OTHER_BYTES, v18);
    v122 = LOBYTE(hWnd[1]);
    if ( v121 )
      v122 = 1;
    SystemProcessInfo = v122;
    v123 = *sub_1055820(&gMap3, &v275, &pItemParam->dwProcessId);
    if ( v123 != gMap3._Header )
    {
      v124 = (*(v123 + 48) - pItemParam->field_430) >> 32;
      hWnd[1] = (*(v123 + 48) - pItemParam->field_430);
      v125 = RedrawColumn(
               __PAIR__(v124, hWnd[1]) != pItemParam->NetworkDeltaReceives,
               ghWndTreeListView,
               IDS_NETWORK_DELTA_RECEIVES,
               v18);
      v126 = SystemProcessInfo;
      if ( v125 )
        v126 = 1;
      pItemParam->NetworkDeltaReceives = hWnd[1];
      v127 = *(v123 + 60);
      v283 = v126;
      v129 = __PAIR__(v127, *(v123 + 56)) - pItemParam->field_450;
      v128 = (__PAIR__(v127, *(v123 + 56)) - pItemParam->field_450) >> 32;
      hWnd[1] = v129;
      v130 = RedrawColumn(
               __PAIR__(v128, v129) != pItemParam->NetworkDeltaSends,
               ghWndTreeListView,
               IDS_NETWORK_DELTA_SENDS,
               v18);
      v131 = v283;
      if ( v130 )
        v131 = 1;
      pItemParam->NetworkDeltaSends = hWnd[1];
      v132 = *(v123 + 68);
      v283 = v131;
      v134 = __PAIR__(v132, *(v123 + 64)) - pItemParam->field_470;
      v133 = (__PAIR__(v132, *(v123 + 64)) - pItemParam->field_470) >> 32;
      hWnd[1] = v134;
      v135 = RedrawColumn(
               __PAIR__(v133, v134) != pItemParam->field_480,
               ghWndTreeListView,
               IDS_NETWORK_DELTA_OTHERS,
               v18);
      v136 = v283;
      if ( v135 )
        v136 = 1;
      pItemParam->field_480 = hWnd[1];
      v283 = v136;
      v137 = *(v123 + 24);
      v20 = v137 < pItemParam->field_438;
      v138 = v137 - pItemParam->field_438;
      hWnd[1] = ghWndTreeListView;
      v139 = *(v123 + 28) - (v20 + pItemParam->field_43C);
      v140 = v138 != pItemParam->field_448 || v139 != pItemParam->field_44C;
      v141 = hWnd[1];
      pItemParam->field_44C = v139;
      pItemParam->field_448 = v138;
      v142 = RedrawColumn(v140, v141, IDS_NETWORK_DELTA_RECEIVE_BYTES, v18);
      v143 = *(v123 + 32);
      v144 = v283;
      if ( v142 )
        v144 = 1;
      v20 = v143 < pItemParam->field_458;
      v145 = v143 - pItemParam->field_458;
      hWnd[1] = ghWndTreeListView;
      v146 = *(v123 + 36) - (v20 + pItemParam->field_45C);
      v283 = v144;
      v147 = v145 != pItemParam->field_468 || v146 != pItemParam->field_46C;
      v148 = hWnd[1];
      pItemParam->field_46C = v146;
      pItemParam->field_468 = v145;
      v149 = RedrawColumn(v147, v148, 1619, v18);
      v150 = *(v123 + 40);
      v151 = v283;
      if ( v149 )
        v151 = 1;
      v20 = v150 < pItemParam->field_478;
      v152 = v150 - pItemParam->field_478;
      v283 = v151;
      v153 = *(v123 + 44) - (v20 + pItemParam->field_47C);
      hWnd[1] = ghWndTreeListView;
      v154 = v152 != pItemParam->field_488 || v153 != pItemParam->field_48C;
      v155 = hWnd[1];
      pItemParam->field_488 = v152;
      pItemParam->field_48C = v153;
      v156 = RedrawColumn(v154, v155, IDS_NETWORK_DELTA_OTHER_BYTES, v18);
      v157 = v283;
      if ( v156 )
        v157 = 1;
      v158 = *(v123 + 48);
      hWnd[1] = v157;
      v283 = v158;
      v159 = v158 != pItemParam->field_430 || *(v123 + 52);
      v160 = RedrawColumn(v159, ghWndTreeListView, IDS_NETWORK_RECEIVES, v18);
      v161 = LOBYTE(hWnd[1]);
      if ( v160 )
        v161 = 1;
      pItemParam->field_430 = v283;
      v162 = *(v123 + 24);
      v284 = v161;
      v163 = *(v123 + 28);
      hWnd[1] = ghWndTreeListView;
      v164 = v162 != pItemParam->field_438 || v163 != pItemParam->field_43C;
      v165 = hWnd[1];
      pItemParam->field_438 = v162;
      pItemParam->field_43C = v163;
      v166 = RedrawColumn(v164, v165, IDS_NETWORK_RECEIVE_BYTES, v18);
      v167 = v284;
      if ( v166 )
        v167 = 1;
      v168 = *(v123 + 56);
      hWnd[1] = v167;
      v283 = v168;
      v169 = v168 != pItemParam->field_450 || *(v123 + 60);
      v170 = RedrawColumn(v169, ghWndTreeListView, IDS_NETWORK_SENDS, v18);
      v171 = LOBYTE(hWnd[1]);
      if ( v170 )
        v171 = 1;
      pItemParam->field_450 = v283;
      v172 = *(v123 + 32);
      v284 = v171;
      v173 = *(v123 + 36);
      hWnd[1] = ghWndTreeListView;
      v174 = v172 != pItemParam->field_458 || v173 != pItemParam->field_45C;
      v175 = hWnd[1];
      pItemParam->field_458 = v172;
      pItemParam->field_45C = v173;
      v176 = RedrawColumn(v174, v175, IDS_NETWORK_SEND_BYTES, v18);
      v177 = v284;
      if ( v176 )
        v177 = 1;
      v178 = *(v123 + 64);
      hWnd[1] = v177;
      v283 = v178;
      v179 = v178 != pItemParam->field_470 || *(v123 + 68);
      v180 = RedrawColumn(v179, ghWndTreeListView, IDS_NETWORK_OTHER, v18);
      v181 = LOBYTE(hWnd[1]);
      if ( v180 )
        v181 = 1;
      pItemParam->field_470 = v283;
      v182 = *(v123 + 40);
      v284 = v181;
      v183 = *(v123 + 44);
      hWnd[1] = ghWndTreeListView;
      v184 = v182 != pItemParam->field_478 || v183 != pItemParam->field_47C;
      v185 = hWnd[1];
      pItemParam->field_478 = v182;
      pItemParam->field_47C = v183;
      v186 = RedrawColumn(v184, v185, IDS_NETWORK_OTHER_BYTES, v18);
      v187 = ghWndTreeListView;
      v188 = v284;
      if ( v186 )
        v188 = 1;
      v189 = pItemParam->field_46C;
      hWnd[1] = v188;
      v191 = *&pItemParam->field_488 + *&pItemParam->field_448 + __PAIR__(v189, pItemParam->field_468);
      v190 = v191 >> 32;
      v192 = __PAIR__(v190, v191) != *&pItemParam->field_490;
      *&pItemParam->field_490 = __PAIR__(v190, v191);
      v193 = RedrawColumn(v192, v187, 1622, v18);
      v194 = hWnd[1];
      if ( v193 )
        v194 = 1;
      LOBYTE(SystemProcessInfo) = v194;
    }
    fUsingWS = sub_1055820(&gMap2, &v275, &pItemParam->dwProcessId);
    v195 = *fUsingWS;
    if ( *fUsingWS == gMap2._Header )
    {
      LOBYTE(fUsingWS) = SystemProcessInfo;
    }
    else
    {
      v196 = (*(v195 + 6) - pItemParam->field_498) >> 32;
      hWnd[1] = (v195[12] - pItemParam->field_498);
      v197 = RedrawColumn(__PAIR__(v196, hWnd[1]) != pItemParam->field_4A8, ghWndTreeListView, 1624, v18);
      v198 = SystemProcessInfo;
      if ( v197 )
        v198 = 1;
      pItemParam->field_4A8 = hWnd[1];
      v199 = v195[15];
      v283 = v198;
      v201 = __PAIR__(v199, v195[14]) - pItemParam->field_4B8;
      v200 = (__PAIR__(v199, v195[14]) - pItemParam->field_4B8) >> 32;
      hWnd[1] = v201;
      v202 = RedrawColumn(__PAIR__(v200, v201) != pItemParam->field_4C8, ghWndTreeListView, 1626, v18);
      v203 = v283;
      if ( v202 )
        v203 = 1;
      pItemParam->field_4C8 = hWnd[1];
      v204 = v195[17];
      v283 = v203;
      v206 = __PAIR__(v204, v195[16]) - pItemParam->field_4D8;
      v205 = (__PAIR__(v204, v195[16]) - pItemParam->field_4D8) >> 32;
      hWnd[1] = v206;
      v207 = RedrawColumn(__PAIR__(v205, v206) != pItemParam->field_4E8, ghWndTreeListView, 1628, v18);
      v208 = v283;
      if ( v207 )
        v208 = 1;
      pItemParam->field_4E8 = hWnd[1];
      v283 = v208;
      v209 = v195[6];
      v20 = v209 < pItemParam->field_4A0;
      v210 = v209 - pItemParam->field_4A0;
      hWnd[1] = ghWndTreeListView;
      v211 = v195[7] - (v20 + pItemParam->field_4A4);
      v212 = v210 != pItemParam->field_4B0 || v211 != pItemParam->field_4B4;
      v213 = hWnd[1];
      pItemParam->field_4B4 = v211;
      pItemParam->field_4B0 = v210;
      v214 = RedrawColumn(v212, v213, IDS_DISK_DELTA_READ_BYTES, v18);
      v215 = v195[8];
      v216 = v283;
      if ( v214 )
        v216 = 1;
      v20 = v215 < pItemParam->field_4C0;
      v217 = v215 - pItemParam->field_4C0;
      hWnd[1] = ghWndTreeListView;
      v218 = v195[9] - (v20 + pItemParam->field_4C4);
      v283 = v216;
      v219 = v217 != pItemParam->field_4D0 || v218 != pItemParam->field_4D4;
      v220 = hWnd[1];
      pItemParam->field_4D4 = v218;
      pItemParam->field_4D0 = v217;
      v221 = RedrawColumn(v219, v220, IDS_DISK_DELTA_WRITE_BYTES, v18);
      v222 = v195[10];
      v223 = v283;
      if ( v221 )
        v223 = 1;
      v20 = v222 < pItemParam->field_4E0;
      v224 = v222 - pItemParam->field_4E0;
      v283 = v223;
      v225 = v195[11] - (v20 + pItemParam->field_4E4);
      hWnd[1] = ghWndTreeListView;
      v226 = v224 != pItemParam->field_4F0 || v225 != pItemParam->field_4F4;
      v227 = hWnd[1];
      pItemParam->field_4F0 = v224;
      pItemParam->field_4F4 = v225;
      v228 = RedrawColumn(v226, v227, IDS_DISK_DELTA_OTHER_BYTES, v18);
      v229 = v283;
      if ( v228 )
        v229 = 1;
      v230 = v195[12];
      hWnd[1] = v229;
      v283 = v230;
      v231 = v230 != pItemParam->field_498 || v195[13];
      v232 = RedrawColumn(v231, ghWndTreeListView, IDS_DISK_READS, v18);
      v233 = LOBYTE(hWnd[1]);
      if ( v232 )
        v233 = 1;
      pItemParam->field_498 = v283;
      v234 = v195[6];
      v284 = v233;
      v235 = v195[7];
      hWnd[1] = ghWndTreeListView;
      v236 = v234 != pItemParam->field_4A0 || v235 != pItemParam->field_4A4;
      v237 = hWnd[1];
      pItemParam->field_4A0 = v234;
      pItemParam->field_4A4 = v235;
      v238 = RedrawColumn(v236, v237, IDS_DISK_READ_BYTES, v18);
      v239 = v284;
      if ( v238 )
        v239 = 1;
      v240 = v195[14];
      hWnd[1] = v239;
      v283 = v240;
      v241 = v240 != pItemParam->field_4B8 || v195[15];
      v242 = RedrawColumn(v241, ghWndTreeListView, IDS_DISK_WRITES, v18);
      v243 = LOBYTE(hWnd[1]);
      if ( v242 )
        v243 = 1;
      pItemParam->field_4B8 = v283;
      v244 = v195[8];
      v284 = v243;
      v245 = v195[9];
      hWnd[1] = ghWndTreeListView;
      v246 = v244 != pItemParam->field_4C0 || v245 != pItemParam->field_4C4;
      v247 = hWnd[1];
      pItemParam->field_4C0 = v244;
      pItemParam->field_4C4 = v245;
      v248 = RedrawColumn(v246, v247, IDS_DISK_WRITE_BYTES, v18);
      v249 = v284;
      if ( v248 )
        v249 = 1;
      v250 = v195[16];
      hWnd[1] = v249;
      v283 = v250;
      v251 = v250 != pItemParam->field_4D8 || v195[17];
      v252 = RedrawColumn(v251, ghWndTreeListView, IDS_DISK_OTHER, v18);
      v253 = LOBYTE(hWnd[1]);
      if ( v252 )
        v253 = 1;
      pItemParam->field_4D8 = v283;
      v254 = v195[10];
      v284 = v253;
      v255 = v195[11];
      hWnd[1] = ghWndTreeListView;
      v256 = v254 != pItemParam->field_4E0 || v255 != pItemParam->field_4E4;
      v257 = hWnd[1];
      pItemParam->field_4E0 = v254;
      pItemParam->field_4E4 = v255;
      v258 = RedrawColumn(v256, v257, IDS_DISK_OTHER_BYTES, v18);
      v259 = ghWndTreeListView;
      v260 = v284;
      if ( v258 )
        v260 = 1;
      v261 = pItemParam->field_4F4;
      hWnd[1] = v260;
      v263 = *&pItemParam->field_4B0 + *&pItemParam->field_4D0 + __PAIR__(v261, pItemParam->field_4F0);
      v262 = v263 >> 32;
      v264 = __PAIR__(v262, v263) != *&pItemParam->field_4F8;
      *&pItemParam->field_4F8 = __PAIR__(v262, v263);
      v17 = RedrawColumn(v264, v259, IDS_DISK_DELTA_TOTAL_BYTES, v18) == 0;
      v265 = hWnd[1];
      fUsingWS = 1;
      if ( !v17 )
        v265 = 1;
      LOBYTE(fUsingWS) = v265;
    }
  }
  return fUsingWS;
}
// 10C4E54: using guessed type int gdwVersion;
// 104DF20: using guessed type unsigned __int64 ProcessorIdleCycleTime[256];

//----- (0104F7C0) --------------------------------------------------------
int __thiscall TreeList_Item1::Reset(TreeList_Item1 *this)
{
  int result; // eax

  this->field_C = this->field_0;
  this->field_30 = this->field_18;
  this->field_34 = this->field_1C;
  this->field_10 = this->field_4;
  this->field_38 = this->field_20;
  this->field_3C = this->field_24;
  this->field_14 = this->field_8;
  this->field_40 = this->field_28;
  result = this->field_2C;
  this->field_44 = result;
  this->field_0 = 0;
  this->field_4 = 0;
  this->field_8 = 0;
  this->field_18 = 0;
  this->field_1C = 0;
  this->field_20 = 0;
  this->field_24 = 0;
  this->field_28 = 0;
  this->field_2C = 0;
  this->field_48 = 0;
  this->field_4C = 0;
  this->field_50 = 0;
  this->field_54 = 0;
  *&this->field_58 = 0;
  *(&this->field_59 + 3) = 0;
  this->field_60 = 0;
  return result;
}

//----- (0104F870) --------------------------------------------------------
char __usercall sub_104F870@<al>(int a1@<ebx>, int a2, int a3, int a4, DWORD dwProcessId, int a6, int a7, int a8)
{
  HANDLE v8; // edi
  SIZE_T (__stdcall *v9)(HANDLE, LPCVOID, PMEMORY_BASIC_INFORMATION, SIZE_T); // esi
  SIZE_T v10; // ebx
  unsigned int v11; // kr00_4
  size_t v12; // eax
  unsigned int v13; // ebx
  WCHAR *v14; // edi
  unsigned int v15; // kr04_4
  char *v16; // eax
  DLLLISTITEMPARAM *v17; // esi
  char v18; // al
  signed int v19; // ecx
  HANDLE v20; // esi
  PIMAGE_NT_HEADERS v21; // ecx
  WORD v22; // ax
  PIMAGE_NT_HEADERS v23; // eax
  PVOID v24; // eax
  char v26; // [esp-188h] [ebp-1774h]
  wchar_t *v27; // [esp-10h] [ebp-15FCh]
  LPCWSTR v28; // [esp-Ch] [ebp-15F8h]
  WCHAR *v29; // [esp-8h] [ebp-15F4h]
  WCHAR *v30; // [esp-4h] [ebp-15F0h]
  struct _FILETIME CreationTime; // [esp+Ch] [ebp-15E0h]
  struct _FILETIME LastAccessTime; // [esp+14h] [ebp-15D8h]
  struct _MEMORY_BASIC_INFORMATION v33; // [esp+1Ch] [ebp-15D0h]
  SIZE_T NumberOfBytesRead; // [esp+38h] [ebp-15B4h]
  struct _FILETIME LocalFileTime; // [esp+3Ch] [ebp-15B0h]
  int v36; // [esp+44h] [ebp-15A8h]
  wchar_t *v37; // [esp+48h] [ebp-15A4h]
  _DWORD *v38; // [esp+4Ch] [ebp-15A0h]
  struct _FILETIME LastWriteTime; // [esp+50h] [ebp-159Ch]
  DWORD v40; // [esp+58h] [ebp-1594h]
  HWND hWnd; // [esp+5Ch] [ebp-1590h]
  int *v42; // [esp+60h] [ebp-158Ch]
  SIZE_T v43; // [esp+64h] [ebp-1588h]
  HANDLE v44; // [esp+68h] [ebp-1584h]
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+6Ch] [ebp-1580h]
  int v46; // [esp+88h] [ebp-1564h]
  char v47; // [esp+8Fh] [ebp-155Dh]
  char v48; // [esp+90h] [ebp-155Ch]
  int v49; // [esp+A0h] [ebp-154Ch]
  wchar_t *v50; // [esp+B4h] [ebp-1538h]
  wchar_t v51; // [esp+B8h] [ebp-1534h]
  DWORD v52; // [esp+138h] [ebp-14B4h]
  PVOID v53; // [esp+13Ch] [ebp-14B0h]
  int v54; // [esp+140h] [ebp-14ACh]
  wchar_t *v55; // [esp+144h] [ebp-14A8h]
  char v56; // [esp+148h] [ebp-14A4h]
  int v57; // [esp+158h] [ebp-1494h]
  int v58; // [esp+15Ch] [ebp-1490h]
  char v59; // [esp+160h] [ebp-148Ch]
  PVOID v60; // [esp+16Ch] [ebp-1480h]
  int v61; // [esp+174h] [ebp-1478h]
  DWORD v62; // [esp+178h] [ebp-1474h]
  char hObject; // [esp+17Ch] [ebp-1470h]
  char BaseAddress; // [esp+17Eh] [ebp-146Eh]
  SIZE_T v65; // [esp+180h] [ebp-146Ch]
  __int16 v66; // [esp+184h] [ebp-1468h]
  struct _FILETIME v67; // [esp+188h] [ebp-1464h]
  int v68; // [esp+190h] [ebp-145Ch]
  wchar_t v69; // [esp+194h] [ebp-1458h]
  wchar_t Dst; // [esp+216h] [ebp-13D6h]
  DWORD dwLen; // [esp+298h] [ebp-1354h]
  int v72; // [esp+29Ch] [ebp-1350h]
  LPCWSTR lpFileName; // [esp+2A0h] [ebp-134Ch]
  wchar_t *v74; // [esp+2A4h] [ebp-1348h]
  struct _SYSTEMTIME SystemTime; // [esp+2D0h] [ebp-131Ch]
  __int16 Base; // [esp+2E0h] [ebp-130Ch]
  WCHAR DateStr; // [esp+12E0h] [ebp-30Ch]
  WCHAR TimeStr; // [esp+1360h] [ebp-28Ch]
  WCHAR FileName; // [esp+13E0h] [ebp-20Ch]

  hWnd = a2;
  LOBYTE(a1) = 0;
  v36 = a4;
  v42 = a6;
  v37 = a7;
  v40 = dwProcessId;
  v38 = a8;
  v46 = a1;
  v8 = OpenProcess(0x410u, 0, dwProcessId);
  v44 = v8;
  if ( !v8 )
    return a1;
  v9 = VirtualQueryEx;
  Buffer.BaseAddress = 0;
  if ( !VirtualQueryEx(v8, 0, &Buffer, 0x1Cu) )
    goto LABEL_68;
  while ( !a3 || *a3 != 1 )
  {
    v10 = Buffer.RegionSize;
    v47 = 0;
    v43 = Buffer.RegionSize;
    v33.BaseAddress = Buffer.BaseAddress + Buffer.RegionSize;
    if ( v9(v8, Buffer.BaseAddress + Buffer.RegionSize, &v33, 0x1Cu) )
    {
      do
      {
        if ( v33.AllocationBase != Buffer.AllocationBase )
          break;
        v33.BaseAddress = v33.BaseAddress + v33.RegionSize;
        v10 = v33.BaseAddress - Buffer.AllocationBase;
      }
      while ( v9(v8, v33.BaseAddress, &v33, 0x1Cu) );
      v43 = v10;
    }
    if ( Buffer.Type != 0x40000 && Buffer.Type != 0x1000000 )
      goto LABEL_63;
    FileName = 0;
    if ( GetMappedFileNameW(v8, Buffer.BaseAddress, &FileName, 0x104u) )
    {
      sub_1040DD0(&FileName);
    }
    else
    {
      if ( !gConfig.bShowUnnamedHandles )
        goto LABEL_64;
      v47 = 1;
      wcscpy_s(&FileName, 0x104u, L"<Pagefile Backed>");
    }
    if ( !a3 )
    {
      v17 = gpDllListItemParamHeader;
      if ( gpDllListItemParamHeader )
      {
        while ( 1 )
        {
          if ( v17->m_LoadAddress == Buffer.BaseAddress && v17->m_MappedSize == v10 )
          {
            v30 = &FileName;
            v29 = v17->m_strPath.pszData;
            if ( !_wcsicmp(v29, &FileName) )
              break;
          }
          v17 = v17->m_Prev;
          if ( !v17 )
            goto LABEL_33;
        }
        v30 = v17;
        ++*v38;
        v18 = sub_1058A20(v30);
        v19 = v46;
        if ( v18 )
          v19 = 1;
        Buffer.BaseAddress = Buffer.BaseAddress + v10;
        v46 = v19;
        sub_103C400(v42, v17);
        v16 = Buffer.BaseAddress;
        v9 = VirtualQueryEx;
        goto LABEL_66;
      }
LABEL_33:
      memset(&v56, 0, 0x188u);
      if ( v47 )
        v61 |= 8u;
      lpFileName = _wcsdup(&FileName);
      wcscpy_s(&Dst, 0x41u, &gszNullString);
      v10 = v43;
      v60 = Buffer.BaseAddress;
      hObject = Buffer.Type == 0x1000000;
      v65 = v43;
      v66 = 1;
      v62 = 0;
      dwLen = 0;
      v72 = 0;
      PE_GetProductCopyright(&FileName, &Dst, 0x41u, &dwLen, &v72);
      if ( Buffer.Type == 0x40000 )
        v61 |= 2u;
      wcscpy_s(&v69, 0x41u, &gszNullString);
      v67 = 0i64;
      v20 = CreateFileW(&FileName, 0x80000000, 7u, 0, 3u, 0, 0);
      if ( v20 != -1 )
      {
        GetFileTime(v20, &CreationTime, &LastAccessTime, &LastWriteTime);
        CloseHandle(v20);
        v67 = LastWriteTime;
        FileTimeToLocalFileTime(&LastWriteTime, &LocalFileTime);
        FileTimeToSystemTime(&LocalFileTime, &SystemTime);
        GetDateFormatW(0x400u, 1u, &SystemTime, 0, &DateStr, 64);
        GetTimeFormatW(0x400u, 2u, &SystemTime, 0, &TimeStr, 64);
        v30 = &TimeStr;
        v29 = &DateStr;
        sub_1039DE0(&v69, L"%s %s", &DateStr, &TimeStr);
      }
      if ( a3 )
      {
        v54 = 0;
        v50 = _wcsdup(v37);
        v55 = _wcsdup(&FileName);
        v52 = v40;
        v53 = Buffer.BaseAddress;
        v49 = 0;
        wcscpy_s(&v51, 0x40u, L"DLL");
        sub_10178D0(hWnd, &v48);
LABEL_62:
        v9 = VirtualQueryEx;
LABEL_63:
        v8 = v44;
LABEL_64:
        v16 = Buffer.BaseAddress + v10;
        goto LABEL_65;
      }
      v62 = 0;
      if ( *ImageNtHeader )
      {
        if ( !(v61 & 2) )
        {
          if ( ReadProcessMemory(v8, Buffer.AllocationBase, &Base, 0x1000u, &NumberOfBytesRead) )
          {
            if ( Base == 23117 )
            {
              v21 = ImageNtHeader(&Base);
              if ( v21 )
              {
                if ( v21->FileHeader.Characteristics & 0x100
                  && (v22 = v21->FileHeader.Machine, v22 != -31132)
                  && v22 != 512 )
                {
                  hObject = 1;
                  v23 = ImageNtHeader(&Base);
                  if ( v23 )
                  {
                    v62 = v23->OptionalHeader.ImageBase;
                    v24 = v23->OptionalHeader.ImageBase;
                    goto LABEL_52;
                  }
                }
                else
                {
                  hObject = 2;
                  v62 = v21->OptionalHeader.ImageBase;
                  v24 = v21->OptionalHeader.ImageBase;
LABEL_52:
                  if ( v24 != Buffer.AllocationBase && Buffer.Type == 0x1000000 )
                    v61 |= 1u;
                }
              }
            }
          }
        }
      }
      sub_103C400(v42, &v56);
      v28 = lpFileName;
      v58 = 0;
      v27 = *(v36 + 88);
      v74 = sub_100BB70(v27, lpFileName);
      if ( gdwValue_4F10B8[1] == v40 )
      {
        v57 = 2;
      }
      else
      {
        v59 = 0;
        v57 = 0;
      }
      if ( Buffer.Type == 0x1000000 && PE_CheckExeFile(lpFileName, &v68, &hObject, &BaseAddress) )
        v61 |= 4u;
      qmemcpy(&v26, &v56, 0x188u);
      sub_1017790(hWnd, v26);
      LOBYTE(v46) = 1;
      goto LABEL_62;
    }
    v11 = wcslen(&FileName);
    v12 = wcslen(gszStringToFindLast);
    if ( v11 >= v12 )
    {
      v13 = 0;
      if ( v11 - v12 != -1 )
      {
        v14 = &FileName;
        while ( _wcsnicmp(v14, gszStringToFindLast, v12) )
        {
          ++v13;
          ++v14;
          v15 = wcslen(&FileName);
          v12 = wcslen(gszStringToFindLast);
          if ( v13 >= v15 - v12 + 1 )
          {
            v8 = v44;
            goto LABEL_22;
          }
        }
        v8 = v44;
        goto LABEL_33;
      }
    }
LABEL_22:
    v16 = Buffer.BaseAddress + v43;
    v9 = VirtualQueryEx;
LABEL_65:
    Buffer.BaseAddress = v16;
LABEL_66:
    if ( !v9(v8, v16, &Buffer, 0x1Cu) )
      break;
  }
  LOBYTE(a1) = v46;
LABEL_68:
  CloseHandle(v8);
  return a1;
}
// 10C10B8: using guessed type int gdwValue_4F10B8[3];

//----- (0104FFD0) --------------------------------------------------------
BOOL __stdcall DlgServiceControl(HWND hWnd, UINT a2, WPARAM a3, LPARAM a4)
{
  HANDLE v4; // edi
  __int16 v5; // cx
  void (__stdcall *v6)(HWND, UINT, WPARAM, LPARAM); // edi
  HWND v7; // eax
  HWND v8; // eax
  HANDLE v9; // eax
  bool v10; // zf
  HANDLE v11; // eax
  HWND v12; // eax
  HANDLE v13; // eax
  HWND v15; // eax
  HWND v16; // eax
  SC_HANDLE v17; // eax
  DWORD v18; // esi
  struct _QUERY_SERVICE_CONFIGW *v19; // ebx
  DWORD v20; // ST0C_4
  SC_HANDLE v21; // esi
  HANDLE v22; // ebx
  HANDLE v23; // eax
  DWORD pcbBytesNeeded; // [esp+14h] [ebp-2Ch]
  HANDLE hData; // [esp+18h] [ebp-28h]
  SC_HANDLE hService; // [esp+1Ch] [ebp-24h]
  struct _SERVICE_STATUS ServiceStatus; // [esp+20h] [ebp-20h]

  if ( a2 != 272 )
  {
    if ( a2 == 273 )
    {
      if ( a3 == 1 )
      {
        v13 = GetPropW(hWnd, L"hService");
        CloseServiceHandle(v13);
        EndDialog(hWnd, 0);
      }
    }
    else if ( a2 == 275 )
    {
      v4 = GetPropW(hWnd, L"hService");
      if ( !v4 )
        goto LABEL_9;
      QueryServiceStatus(v4, &ServiceStatus);
      v5 = GetPropW(hWnd, L"Command");
      switch ( v5 )
      {
        case 0x4BA:
        case 0x4BF:
          if ( ServiceStatus.dwCurrentState != 1 )
            goto LABEL_9;
          if ( v5 != 1215 )
            goto LABEL_16;
          SetPropW(hWnd, L"Command", 0x4BD);
          StartServiceW(v4, 0, 0);
          goto LABEL_9;
        case 0x4BB:
        case 0x4BD:
          v10 = ServiceStatus.dwCurrentState == 4;
          break;
        case 0x4BC:
          v10 = ServiceStatus.dwCurrentState == 7;
          break;
        default:
          goto LABEL_9;
      }
      if ( v10 )
      {
LABEL_16:
        v11 = GetPropW(hWnd, L"hService");
        CloseServiceHandle(v11);
        SetPropW(hWnd, L"hService", 0);
        v12 = GetDlgItem(hWnd, 1316);
        v6 = SendMessageW;
        SendMessageW(v12, 0x402u, 0x26u, 0);
      }
      else
      {
LABEL_9:
        v6 = SendMessageW;
      }
      v7 = GetDlgItem(hWnd, 1316);
      v6(v7, 0x405u, 0, 0);
      v8 = GetDlgItem(hWnd, 1316);
      if ( (v6)(v8, 0x408u, 0, 0) == 40 )
      {
        if ( GetPropW(hWnd, L"hService") )
        {
          v9 = GetPropW(hWnd, L"hService");
          CloseServiceHandle(v9);
          EndDialog(hWnd, 1);
        }
        else
        {
          EndDialog(hWnd, 2);
        }
      }
      return 1;
    }
    return 0;
  }
  hData = *(a4 + 8);
  switch ( hData )
  {
    case 0x4BAu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to stop the following service...");
      hService = 32;
      break;
    case 0x4BBu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to resume the following service...");
      hService = 64;
      break;
    case 0x4BCu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to pause the following service...");
      hService = 64;
      break;
    case 0x4BDu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to start the following service...");
      hService = 16;
      break;
    case 0x4BFu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to restart the following service...");
      hService = 48;
      break;
    default:
      hService = hData;
      break;
  }
  v15 = GetDlgItem(hWnd, 1316);
  SendMessageW(v15, 0x401u, 0, 2621440);
  v16 = GetDlgItem(hWnd, 1316);
  SendMessageW(v16, 0x404u, 1u, 0);
  v17 = OpenServiceW(ghSCManagerHandle, *(a4 + 20), hService | 5);
  hService = v17;
  if ( !v17 )
  {
    ReportMsg(L"Error opening service for control", ghMainWnd);
    EndDialog(hWnd, 0);
    return 0;
  }
  QueryServiceConfigW(v17, 0, 0, &pcbBytesNeeded);
  v18 = pcbBytesNeeded;
  v19 = malloc(pcbBytesNeeded);
  v20 = v18;
  v21 = hService;
  QueryServiceConfigW(hService, v19, v20, &pcbBytesNeeded);
  SetDlgItemTextW(hWnd, 1315, v19->lpDisplayName);
  free(v19);
  v22 = hData;
  switch ( hData )
  {
    case 0x4BAu:
    case 0x4BFu:
      v23 = ControlService(v21, 1u, &ServiceStatus);
      break;
    case 0x4BBu:
      v23 = ControlService(v21, 3u, &ServiceStatus);
      break;
    case 0x4BCu:
      v23 = ControlService(v21, 2u, &ServiceStatus);
      break;
    case 0x4BDu:
      v23 = StartServiceW(v21, 0, 0);
      break;
    default:
      v23 = hData;
      break;
  }
  if ( !v23 )
  {
    ReportMsg(L"Error sending control to service", ghMainWnd);
    EndDialog(hWnd, 0);
    CloseServiceHandle(v21);
    return 0;
  }
  SetPropW(hWnd, L"command", v22);
  SetPropW(hWnd, L"hService", hService);
  SetTimer(hWnd, 1u, 0x1F4u, 0);
  QueryServiceNames();
  return 1;
}
// 10A5560: using guessed type wchar_t aErrorOpeningSe_0[34];
// 10A55A8: using guessed type wchar_t aErrorSendingCo[33];

//----- (01050400) --------------------------------------------------------
BOOL __cdecl sub_1050400(HWND hDlg, int nIDDlgItem, int ArgList, int a4)
{
  WCHAR String; // [esp+4h] [ebp-68h]

  sub_1039DA0(&String, L"%I64d", ArgList, a4);
  PE_GetNumberFormat(&String, 0x32u);
  return SetDlgItemTextW(hDlg, nIDDlgItem, &String);
}

//----- (01050460) --------------------------------------------------------
BOOL __cdecl sub_1050460(HWND hDlg, int nIDDlgItem, int a3, int a4)
{
  WCHAR String; // [esp+4h] [ebp-68h]

  sub_1039DA0(&String, L"%I64d", __PAIR__(a4, a3) / 1024);
  PE_GetNumberFormat(&String, 0x32u);
  wcscat_s(&String, 0x32u, L" KB");
  return SetDlgItemTextW(hDlg, nIDDlgItem, &String);
}

//----- (010504E0) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_10504E0(CResizer *this, int a2, int a3))(HWND hWnd, LPRECT lpRect)
{
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v4 = a2;
  v5 = a3;
  return sub_1050550(this, 2, &v4);
}

//----- (01050510) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_1050510(CResizer *this, int a2, int a3, int a4))(HWND hWnd, LPRECT lpRect)
{
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]

  v5 = a2;
  v6 = a3;
  v7 = a4;
  return sub_1050550(this, 3, &v5);
}

//----- (01050550) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_1050550(CResizer *this, int a2, int a3))(HWND hWnd, LPRECT lpRect)
{
  BOOL (__stdcall *result)(HWND, LPRECT); // eax
  int v4; // esi
  int j; // esi
  struct tagResizerItem *v6; // eax
  double v7; // [esp+0h] [ebp-40h]
  CResizer *v8; // [esp+8h] [ebp-38h]
  double i; // [esp+Ch] [ebp-34h]
  double v10; // [esp+14h] [ebp-2Ch]
  struct tagRECT v11; // [esp+1Ch] [ebp-24h]
  struct tagRECT Rect; // [esp+2Ch] [ebp-14h]

  result = GetWindowRect;
  v4 = 0;
  v8 = this;
  v10 = 0.0;
  for ( i = 0.0; v4 < a2; i = (Rect.bottom - Rect.top) + i )
  {
    result(*(a3 + 4 * v4++), &Rect);
    result = GetWindowRect;
  }
  for ( j = 0; j < a2; v10 = *&Rect.right )
  {
    result(*(a3 + 4 * j), &v11);
    *&Rect.right = (v11.bottom - v11.top) / i + v10;
    v7 = (v11.bottom - v11.top) / i + v10;
    if ( *&Rect.right >= 0.99999 )
      v7 = db_one;
    v6 = CResizer::AddItem(v8, *(a3 + 4 * j++), 1);
    *&v6->m_rect2.left = v10;
    *&v6->m_rect2.right = v7;
    result = GetWindowRect;
  }
  return result;
}

//----- (01050640) --------------------------------------------------------
BOOL __stdcall sub_1050640(int a1, PVOID pApplicationAddress, DWORD BytesReturned, LPVOID lpOutBuffer, DWORD nOutBufferSize, DWORD *pcbRet)
{
  BOOL result; // eax
  DWORD v7; // esi
  int InBuffer[2]; // [esp+0h] [ebp-8h]

  if ( pApplicationAddress >= gSystemInfo.lpMaximumApplicationAddress )
  {
    v7 = nOutBufferSize;
    InBuffer[0] = dword_10CAB88;
    InBuffer[1] = pApplicationAddress;
    result = DeviceIoControl(ghDriverHandle, 0x83350024, InBuffer, 8u, lpOutBuffer, nOutBufferSize, &BytesReturned, 0);
    if ( result )
    {
      *pcbRet = v7;
      result = 1;
    }
    else
    {
      *pcbRet = 0;
    }
  }
  else
  {
    result = 1;
    *pcbRet = 0;
  }
  return result;
}
// 10CAB88: using guessed type int dword_10CAB88;

//----- (010506C0) --------------------------------------------------------
int __cdecl PE_SuspendOneProcess(char bSuspended, SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo, int a3)
{
  SYSTEM_PROCESS_INFORMATION *v3; // esi
  HANDLE v4; // ebx
  int result; // eax
  int v6; // esi
  _SYSTEM_THREAD_INFORMATION *pInfo; // ecx
  ULONG NumberOfThreads; // edi
  int dwSuspendedCount; // ebx
  PUCHAR v10; // eax
  ULONG dwNumberOfThreads; // edx
  PUCHAR v12; // ecx
  _SYSTEM_THREAD_INFORMATION *pThreadInfo; // esi
  PUCHAR pWaitReason; // edi
  PUCHAR pThreadState; // ebx
  PUCHAR ThreadId; // esi
  void *v17; // ecx
  ULONG *v18; // esi
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+8h] [ebp-3Ch]
  struct _CLIENT_ID ClientId; // [esp+20h] [ebp-24h]
  HANDLE v21; // [esp+28h] [ebp-1Ch]
  HANDLE hObject; // [esp+2Ch] [ebp-18h]
  int dwThreadIndex; // [esp+30h] [ebp-14h]
  int v24; // [esp+34h] [ebp-10h]
  int v25; // [esp+38h] [ebp-Ch]
  UCHAR *v26; // [esp+3Ch] [ebp-8h]
  char bSmallStruct; // [esp+43h] [ebp-1h]

  v3 = pSystemProcessInfo;
  bSmallStruct = 0;
  v4 = OpenProcess(PROCESS_SUSPEND_RESUME, 0, pSystemProcessInfo->UniqueProcessId);
  v21 = v4;
  if ( !v4 )
    return GetLastError();
  if ( NtSuspendProcess )
  {
    if ( bSuspended )
      v6 = NtSuspendProcess(v4);
    else
      v6 = NtResumeProcess(v4);
    CloseHandle(v4);
    return v6;
  }
  if ( GetVersion() <= 4u )
  {
    bSmallStruct = 1;
    pInfo = &pSystemProcessInfo->ReadOperationCount;
  }
  else
  {
    pInfo = &pSystemProcessInfo[1];
  }
  NumberOfThreads = pSystemProcessInfo->NumberOfThreads;
  dwSuspendedCount = 0;
  v25 = 0;
  if ( NumberOfThreads )
  {
    v10 = &pInfo->WaitReason;
    dwNumberOfThreads = NumberOfThreads;
    v12 = &pInfo->ThreadState;
    do
    {
      if ( *v12 == Suspended && *v10 == Suspended )
        ++dwSuspendedCount;
      v12 += sizeof(SYSTEM_THREAD_INFORMATION);
      v10 += sizeof(SYSTEM_THREAD_INFORMATION);
      --dwNumberOfThreads;
    }
    while ( dwNumberOfThreads );
    v25 = dwSuspendedCount;
  }
  if ( bSuspended )
  {
    if ( NumberOfThreads == dwSuspendedCount )
      goto __quit;
  }
  else if ( NumberOfThreads != dwSuspendedCount )
  {
    goto __quit;
  }
  if ( bSmallStruct )
    pThreadInfo = &pSystemProcessInfo->ReadOperationCount;
  else
    pThreadInfo = &pSystemProcessInfo[1];
  dwThreadIndex = 0;
  if ( NumberOfThreads )
  {
    pWaitReason = &pThreadInfo->WaitReason;
    pThreadState = &pThreadInfo->ThreadState;
    ThreadId = &pThreadInfo->ClientId.UniqueThread;
    v26 = ThreadId;
    while ( 1 )
    {
      ClientId.UniqueThread = *ThreadId;
      ClientId.UniqueProcess = 0;
      ObjectAttributes.Length = 24;
      ObjectAttributes.RootDirectory = 0;
      ObjectAttributes.Attributes = 0;
      ObjectAttributes.ObjectName = 0;
      ObjectAttributes.SecurityDescriptor = 0;
      ObjectAttributes.SecurityQualityOfService = 0;
      if ( !NtOpenThread(&hObject, THREAD_SUSPEND_RESUME, &ObjectAttributes, &ClientId) )
        break;
LABEL_40:
      ThreadId += 64;
      pThreadState += 64;
      v26 = ThreadId;
      pWaitReason += 64;
      if ( ++dwThreadIndex >= pSystemProcessInfo->NumberOfThreads )
      {
        dwSuspendedCount = v25;
        v3 = pSystemProcessInfo;
        goto __quit;
      }
    }
    v18 = hObject;
    if ( !hObject )
    {
LABEL_39:
      ThreadId = v26;
      goto LABEL_40;
    }
    if ( bSuspended )
    {
      if ( a3 && (a3 != 1 || *pThreadState == 5 && *pWaitReason == 5) )
        goto LABEL_38;
      NtSuspendThread(v17, hObject);
      if ( *pWaitReason == 5 || !v24 )
        goto LABEL_38;
      ++v25;
    }
    NtResumeThread(v17, v18);
LABEL_38:
    CloseHandle(v18);
    goto LABEL_39;
  }
  v3 = pSystemProcessInfo;
__quit:
  CloseHandle(v21);
  if ( bSuspended && v3->NumberOfThreads == dwSuspendedCount )
    result = ERROR_ALREADY_WAITING;
  else
    result = 0;
  return result;
}
// 105076B: CONTAINING_RECORD: no field 'PUCHAR' in struct 'SYSTEM_THREAD_INFORMATION' at 64
// 105076E: CONTAINING_RECORD: no field 'PUCHAR' in struct 'SYSTEM_THREAD_INFORMATION' at 64

//----- (010508B0) --------------------------------------------------------
DWORD64 __stdcall SymLoadModuleExW_0(HANDLE hProcess, HANDLE hFile, PCWSTR ImageName, PCWSTR ModuleName, DWORD64 BaseOfDll, DWORD DllSize, PMODLOAD_DATA Data, DWORD Flags)
{
  return SymLoadModuleExW(hProcess, hFile, ImageName, ModuleName, BaseOfDll, DllSize, 0, 0);
}

//----- (010508E0) --------------------------------------------------------
int __stdcall sub_10508E0(int hProcess, int hFile, LPCWSTR a3, LPCWSTR lpWideCharStr, int BaseOfDll, int BaseOfDll_4, int SizeOfDll)
{
  int *v7; // esi
  int *v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // edx
  int v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]

  v7 = sub_1039E00(&v13, lpWideCharStr);
  v15 = 0;
  v8 = sub_1039E00(&v14, a3);
  LOBYTE(v15) = 1;
  v9 = SymLoadModule64(hProcess, hFile, *v8, *v7, __PAIR__(BaseOfDll_4, BaseOfDll), SizeOfDll);
  v10 = v14 - 16;
  LOBYTE(v15) = 0;
  if ( _InterlockedDecrement((v14 - 16 + 12)) <= 0 )
    (*(**v10 + 4))(v10);
  v11 = v13 - 16;
  v15 = -1;
  if ( _InterlockedDecrement((v13 - 16 + 12)) <= 0 )
    (*(**v11 + 4))(v11);
  return v9;
}

//----- (010509B0) --------------------------------------------------------
int __stdcall PropSystemInfoSumETW(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  int v4; // esi
  HWND hWnd_1; // edi
  LONG v6; // eax
  void *v7; // eax
  DWORD v8; // edx
  LOGICAL_PROCESSOR_RELATIONSHIP *v9; // eax
  CResizer *v10; // edi
  HWND v11; // eax
  DWORD v12; // ecx
  signed int v13; // esi
  int v14; // ecx
  HWND v15; // eax
  void *v16; // ecx
  int v17; // esi
  int v18; // eax
  HMENU v19; // esi
  int v20; // edi
  char v21; // al
  int v22; // ecx
  const WCHAR *v23; // eax
  const WCHAR *v24; // eax
  CResizer *v25; // eax
  CResizer *pResizer; // esi
  HWND v27; // eax
  struct tagResizerItem *v28; // eax
  HWND v29; // eax
  struct tagResizerItem *v30; // eax
  double v31; // xmm1_8
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  int v33; // esi
  HWND v34; // eax
  struct tagResizerItem *v35; // eax
  HWND v36; // eax
  double v37; // xmm0_8
  double *v38; // eax
  HWND v39; // eax
  int result; // eax
  signed int nCount; // esi
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // eax
  ULONG HandleCount; // edx
  ULONG v44; // ecx
  CResizer *v45; // edi
  const WCHAR *v46; // eax
  const WCHAR *v47; // eax
  const WCHAR *v48; // eax
  DWORD v49; // esi
  DWORD v50; // eax
  __m128i v51; // xmm6
  __m128i v52; // xmm7
  int v53; // eax
  __m128i v54; // xmm5
  __m128i v55; // xmm4
  int v56; // ecx
  __m128i v57; // xmm2
  __m128i v58; // xmm4
  __m128i v59; // xmm5
  __m128i v60; // xmm4
  __m128i v61; // xmm5
  SYSTEM_PROCESS_INFORMATION *v62; // ecx
  int v63; // edx
  SYSTEM_PROCESS_INFORMATION *v64; // edi
  int v65; // ecx
  _DWORD *v66; // eax
  DWORD v67; // edx
  int v68; // esi
  int v69; // ST58_4
  int v70; // esi
  char *v71; // esi
  int v72; // esi
  int v73; // eax
  HWND v74; // esi
  HWND v75; // eax
  HWND v76; // eax
  HWND v77; // eax
  HWND v78; // eax
  HWND v79; // eax
  HWND v80; // eax
  signed int v81; // edi
  HWND v82; // eax
  signed int v83; // eax
  int v84; // ST2C_4
  HWND v85; // eax
  signed int i; // esi
  signed int v87; // eax
  int v88; // ST2C_4
  HWND v89; // eax
  double v90; // [esp+Ch] [ebp-3B4h]
  int nHeight; // [esp+10h] [ebp-3B0h]
  double v92; // [esp+14h] [ebp-3ACh]
  int v93; // [esp+18h] [ebp-3A8h]
  signed int v94; // [esp+20h] [ebp-3A0h]
  double v95; // [esp+24h] [ebp-39Ch]
  int v96; // [esp+28h] [ebp-398h]
  int v97; // [esp+2Ch] [ebp-394h]
  ULONG ReturnLength; // [esp+30h] [ebp-390h]
  double v99; // [esp+34h] [ebp-38Ch]
  void *v100[2]; // [esp+3Ch] [ebp-384h]
  double v101; // [esp+44h] [ebp-37Ch]
  HWND hWnd_2; // [esp+4Ch] [ebp-374h]
  int v103; // [esp+50h] [ebp-370h]
  int v104; // [esp+54h] [ebp-36Ch]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+58h] [ebp-368h]
  CResizer *NumberOfThreads; // [esp+5Ch] [ebp-364h]
  int SystemInformation[74]; // [esp+60h] [ebp-360h]
  int v108; // [esp+188h] [ebp-238h]
  struct tagRECT Rect; // [esp+198h] [ebp-228h]
  WCHAR szText[260]; // [esp+1A8h] [ebp-218h]
  int v111; // [esp+3BCh] [ebp-4h]

  v4 = 0;
  hWnd_1 = hWnd;
  hWnd_2 = hWnd;
  HIDWORD(v99) = 0;
  NumberOfThreads = 0;
  if ( uMsg <= WM_CTLCOLOREDIT )
  {
    if ( uMsg != WM_CTLCOLOREDIT )
    {
      switch ( uMsg )
      {
        case 0x24u:
          *(lParam + 8) = 2 * gdwVirtualScreenWidth;
          result = 0;
          break;
        case WM_INITDIALOG:
          v6 = GetWindowLongW(hWnd, -16);
          SetWindowLongW(hWnd, -16, v6 | 0x2000000);
          HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) = malloc(48 * gSystemInfo.dwNumberOfProcessors);
          v7 = malloc(24 * gSystemInfo.dwNumberOfProcessors);
          v8 = gdwLogicalProcessorInfoItemCount;
          LODWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) = v7;
          if ( gdwLogicalProcessorInfoItemCount > 0 )
          {
            v9 = &gpLogicalProcessorInfo->Relationship;
            v10 = 0;
            do
            {
              if ( *v9 )
              {
                if ( *v9 == 3 )
                  v10 = (v10 + 1);
              }
              else
              {
                ++v4;
              }
              v9 += 6;
              --v8;
            }
            while ( v8 );
            NumberOfThreads = v10;
            hWnd_1 = hWnd_2;
            HIDWORD(v99) = v4;
          }
          if ( gSystemInfo.dwNumberOfProcessors <= 1 )
          {
            v22 = 0;
            v103 = v100[1];
            NumberOfThreads = 0;
            pSystemProcessInfo = v100[1];
          }
          else
          {
            v11 = GetDlgItem(hWnd_1, 2000);
            GetWindowRect(v11, &Rect);
            v12 = gSystemInfo.dwNumberOfProcessors;
            if ( gSystemInfo.dwNumberOfProcessors > 8 )
              v12 = 8 * (gSystemInfo.dwNumberOfProcessors / 8 > 16) + 8;
            pSystemProcessInfo = ((v12 + gSystemInfo.dwNumberOfProcessors - 1) / v12);
            v13 = 4;
            v14 = (v12 * pSystemProcessInfo - gSystemInfo.dwNumberOfProcessors) / -2 + v12;
            v103 = v14;
            if ( gSystemInfo.dwNumberOfProcessors > 0x10 )
              v13 = 3;
            v94 = v13;
            if ( gSystemInfo.dwNumberOfProcessors > 0x20 )
              v94 = --v13;
            v97 = (Rect.right - v13 * (v14 - 1) - Rect.left) / v103;
            nHeight = (Rect.bottom - v13 * (&pSystemProcessInfo[-1].OtherTransferCount.QuadPart + 7) - Rect.top)
                    / pSystemProcessInfo;
            v15 = GetDlgItem(hWnd_1, 2000);
            GetWindowRect(v15, &Rect);
            MapWindowPoints(0, hWnd_1, &Rect, 2u);
            v16 = Rect.left;
            v100[1] = Rect.left;
            v104 = 0;
            if ( gSystemInfo.dwNumberOfProcessors > 0 )
            {
              v17 = 1;
              HIDWORD(v101) = 1;
              do
              {
                v93 = 0;
                v96 = v17 % v103;
                if ( !(v17 % v103) )
                  v93 = Rect.right - v16 - v97;
                v18 = sub_1023F20(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, v17 - 1);
                v19 = (v17 + 2000);
                v20 = v18;
                CreateWindowExW(
                  0,
                  L"Static",
                  0,
                  0x40000000u,
                  Rect.left,
                  Rect.top,
                  v93 + v97,
                  nHeight,
                  hWnd_2,
                  v19,
                  ghInstance,
                  0);
                CreateGraphWindow(hWnd_2, v19, gppGraphInfo[v20]);
                Rect.left += v97;
                v21 = sub_1023F20(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, SHIDWORD(v101));
                if ( sub_10236B0(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, v20, v21) )
                {
                  v16 = (Rect.left + 2);
                  v104 = v94 + v104 - 2;
                }
                else
                {
                  v16 = (v94 + v104 + Rect.left);
                  v104 = 0;
                }
                Rect.left = v16;
                if ( !v96 )
                {
                  v16 = v100[1];
                  Rect.left = v100[1];
                  Rect.top += nHeight + 2;
                }
                v17 = HIDWORD(v101) + 1;
                HIDWORD(v101) = v17;
              }
              while ( v17 - 1 < gSystemInfo.dwNumberOfProcessors );
              hWnd_1 = hWnd_2;
            }
            v22 = HIDWORD(v99);
          }
          swprintf(szText, L"%d", v22);
          v23 = PE_GetNumberFormat(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1665, v23);
          swprintf(szText, L"%d", NumberOfThreads);
          v24 = PE_GetNumberFormat(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1666, v24);
          CreateGraphWindow(hWnd_1, 1158, gpGraphInfoOfCPU);
          CreateGraphWindow(hWnd_1, 2000, gpGraphInfoOfCPU);
          v25 = operator new(0x40u);
          v100[1] = v25;
          v111 = 0;
          if ( v25 )
          {
            pResizer = CResizer::CResizer(v25, hWnd_1);
            NumberOfThreads = pResizer;
          }
          else
          {
            pResizer = 0;
            NumberOfThreads = 0;
          }
          v111 = -1;
          pResizer->m_nXRatio = 100;
          pResizer->m_nYRatio = 20;
          v27 = GetDlgItem(hWnd_1, 2000);
          if ( v27 )
          {
            v28 = CResizer::AddItem(pResizer, v27, 1);
            *&v28->m_rect1.left = 0i64;
            *&v28->m_rect1.right = db_one;
          }
          v29 = GetDlgItem(hWnd_1, 1114);
          if ( v29 )
          {
            v30 = CResizer::AddItem(pResizer, v29, 1);
            v31 = db_one;
            *&v30->m_rect1.left = 0i64;
            *&v30->m_rect1.right = db_one;
          }
          else
          {
            v31 = db_one;
          }
          SendMessageW = ::SendMessageW;
          if ( gSystemInfo.dwNumberOfProcessors <= 1 )
          {
            v39 = GetDlgItem(hWnd_1, 1301);
            ShowWindow(v39, 0);
          }
          else
          {
            *v100 = 0.0;
            v95 = 0.0;
            if ( gSystemInfo.dwNumberOfProcessors > 0 )
            {
              v33 = 2001;
              v92 = v31 / v103;
              v90 = v31 / pSystemProcessInfo;
              do
              {
                v34 = GetDlgItem(hWnd_1, v33);
                v101 = v90 + v95;
                if ( v90 + v95 >= 0.99999 )
                  v101 = db_one;
                v35 = CResizer::AddItem(NumberOfThreads, v34, 1);
                *&v35->m_rect2.left = v95;
                *&v35->m_rect2.right = v101;
                v36 = GetDlgItem(hWnd_1, v33);
                v37 = *v100 + v92;
                v99 = *v100 + v92;
                v101 = *v100 + v92;
                if ( *v100 + v92 >= 0.99999 )
                  v101 = db_one;
                if ( v36 )
                {
                  v38 = CResizer::AddItem(NumberOfThreads, v36, 1);
                  *v38 = *v100;
                  v38[1] = v101;
                  v37 = v99;
                }
                *v100 = v37;
                if ( !((v33 - 2000) % v103) )
                {
                  *v100 = 0.0;
                  v95 = v90 + v95;
                }
                ++v33;
              }
              while ( v33 - 2001 < gSystemInfo.dwNumberOfProcessors );
              SendMessageW = ::SendMessageW;
            }
            CheckDlgButton(hWnd_1, 1301, gConfig.bShowAllCpus != 0);
            SendMessageW(hWnd_1, 0x464u, 0, 0);
          }
          PropSheet_UpdateTab(hWnd_1);
          NtQuerySystemInformation(
            SystemPerformanceInformation,
            &gSystenPerformanceInfoInProcSecurity,
            offsetof(SYSTEM_PERFORMANCE_INFORMATION, CcTotalDirtyPages),
            &ReturnLength);
          SendMessageW(hWnd_1, WM_TIMER, 0, 0);
          result = 1;
          break;
        case WM_COMMAND:
          if ( wParam != 1301 || wParam >> 16 )
            return 0;
          gConfig.bShowAllCpus = gConfig.bShowAllCpus == 0;
          ::SendMessageW(hWnd, 0x464u, 0, 0);
          result = 0;
          break;
        case WM_TIMER:
          pSystemProcessInfo = 0;
          GetSystemProcessInfo(&pSystemProcessInfo, 0);
          NtQuerySystemInformation(SystemPerformanceInformation, SystemInformation, 0x138u, &ReturnLength);
          NtQuerySystemInformation(
            SystemProcessorPerformanceInformation,
            HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold),
            48 * gSystemInfo.dwNumberOfProcessors,
            &ReturnLength);
          NtQuerySystemInformation(
            SystemInterruptInformation,
            gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages,
            24 * gSystemInfo.dwNumberOfProcessors,
            &ReturnLength);
          nCount = 1;
          pSystemProcessInfo_1 = pSystemProcessInfo;
          HandleCount = pSystemProcessInfo->HandleCount;
          NumberOfThreads = pSystemProcessInfo->NumberOfThreads;
          HIDWORD(v101) = HandleCount;
          v44 = pSystemProcessInfo->NextEntryOffset;
          if ( pSystemProcessInfo->NextEntryOffset )
          {
            v45 = NumberOfThreads;
            do
            {
              HandleCount += *(&pSystemProcessInfo_1->HandleCount + v44);
              pSystemProcessInfo_1 = (pSystemProcessInfo_1 + v44);
              ++nCount;
              v45 = (v45 + pSystemProcessInfo_1->NumberOfThreads);
              v44 = pSystemProcessInfo_1->NextEntryOffset;
            }
            while ( pSystemProcessInfo_1->NextEntryOffset );
            NumberOfThreads = v45;
            hWnd_1 = hWnd_2;
            HIDWORD(v101) = HandleCount;
          }
          free(pSystemProcessInfo);
          swprintf(szText, L"%d", HIDWORD(v101));
          v46 = PE_GetNumberFormat(szText, MAX_PATH);
          SetDlgItemTextW(hWnd_1, 1096, v46);
          swprintf(szText, L"%d", NumberOfThreads);
          v47 = PE_GetNumberFormat(szText, MAX_PATH);
          SetDlgItemTextW(hWnd_1, 1097, v47);
          swprintf(szText, L"%d", nCount);
          v48 = PE_GetNumberFormat(szText, MAX_PATH);
          SetDlgItemTextW(hWnd_1, 1098, v48);
          v49 = 0;
          v103 = 0;
          v104 = 0;
          v50 = gSystemInfo.dwNumberOfProcessors;
          if ( gSystemInfo.dwNumberOfProcessors && gSystemInfo.dwNumberOfProcessors >= 8 )
          {
            v51 = 0i64;
            v52 = 0i64;
            v53 = LODWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) + 52;
            v54 = 0i64;
            v55 = 0i64;
            v56 = HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) + 136;
            do
            {
              v57 = _mm_cvtsi32_si128(*(v56 + 48));
              v56 += 384;
              v53 += 192;
              v49 += 8;
              v51 = _mm_add_epi32(
                      v51,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v56 - 480)), _mm_cvtsi32_si128(*(v56 - 384))),
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v56 - 432)), v57)));
              v52 = _mm_add_epi32(
                      v52,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v53 - 240)), _mm_cvtsi32_si128(*(v53 - 192))),
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v53 - 216)), _mm_cvtsi32_si128(*(v53 - 168)))));
              v54 = _mm_add_epi32(
                      v54,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v56 - 288)), _mm_cvtsi32_si128(*(v56 - 192))),
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v56 - 240)), _mm_cvtsi32_si128(*(v56 - 144)))));
              v55 = _mm_add_epi32(
                      v55,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v53 - 144)), _mm_cvtsi32_si128(*(v53 - 96))),
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v53 - 120)), _mm_cvtsi32_si128(*(v53 - 72)))));
            }
            while ( v49 < gSystemInfo.dwNumberOfProcessors - (gSystemInfo.dwNumberOfProcessors & 7) );
            v50 = gSystemInfo.dwNumberOfProcessors;
            v58 = _mm_add_epi32(v55, v52);
            v59 = _mm_add_epi32(v54, v51);
            v60 = _mm_add_epi32(v58, _mm_srli_si128(v58, 8));
            v61 = _mm_add_epi32(v59, _mm_srli_si128(v59, 8));
            v103 = _mm_cvtsi128_si32(_mm_add_epi32(v60, _mm_srli_si128(v60, 4)));
            v104 = _mm_cvtsi128_si32(_mm_add_epi32(v61, _mm_srli_si128(v61, 4)));
          }
          v62 = 0;
          v63 = 0;
          pSystemProcessInfo = 0;
          NumberOfThreads = 0;
          HIDWORD(v99) = 0;
          if ( v49 >= v50 )
          {
            v71 = v103;
          }
          else
          {
            if ( v50 - v49 >= 2 )
            {
              v64 = 0;
              v65 = LODWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) + 24 * v49 + 4;
              v66 = (HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) + 40 + 48 * v49);
              v67 = ((gSystemInfo.dwNumberOfProcessors - v49 - 2) >> 1) + 1;
              v100[1] = (v49 + 2 * v67);
              v68 = 0;
              do
              {
                v64 = (v64 + *v66);
                v66 += 24;
                v68 += *(v66 - 12);
                v65 += 48;
                pSystemProcessInfo = v64;
                NumberOfThreads = (NumberOfThreads + *(v65 - 48));
                HIDWORD(v99) += *(v65 - 24);
                --v67;
              }
              while ( v67 );
              hWnd_1 = hWnd_2;
              v62 = pSystemProcessInfo;
              v69 = v68;
              v49 = v100[1];
              v63 = v69;
            }
            if ( v49 >= gSystemInfo.dwNumberOfProcessors )
            {
              v70 = v103;
            }
            else
            {
              v104 += *(HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) + 48 * v49 + 40);
              hWnd_1 = hWnd_2;
              v70 = *(LODWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) + 24 * v49 + 4) + v103;
              v62 = pSystemProcessInfo;
            }
            v104 += v62 + v63;
            v71 = NumberOfThreads + HIDWORD(v99) + v70;
            v103 = v71;
          }
          swprintf(szText, L"%u", v108 - gSystenPerformanceInfoInProcSecurity.ContextSwitches);
          PE_GetNumberFormat(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1082, szText);
          if ( HIDWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) )
            v72 = &v71[-HIDWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages)];
          else
            v72 = 0;
          swprintf(szText, L"%u", v72);
          PE_GetNumberFormat(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1084, szText);
          if ( LODWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) )
            v73 = v104 - LODWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold);
          else
            v73 = 0;
          swprintf(szText, L"%u", v73);
          PE_GetNumberFormat(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1083, szText);
          HIDWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) = v103;
          qmemcpy(&gSystenPerformanceInfoInProcSecurity, SystemInformation, 0x138u);
          v74 = hWnd_2;
          LODWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) = v104;
          v75 = GetDlgItem(hWnd_2, 1158);
          ::SendMessageW(v75, 0x400u, 0, 0);
          v76 = GetDlgItem(v74, 2000);
          ::SendMessageW(v76, 0x400u, 0, 0);
          v77 = GetDlgItem(v74, 1161);
          ::SendMessageW(v77, 0x400u, 0, 0);
          v78 = GetDlgItem(v74, 1159);
          ::SendMessageW(v78, 0x400u, 0, 0);
          v79 = GetDlgItem(v74, 1637);
          ::SendMessageW(v79, 0x400u, 0, 0);
          v80 = GetDlgItem(v74, 1333);
          ::SendMessageW(v80, 0x400u, 0, 0);
          if ( gSystemInfo.dwNumberOfProcessors <= 1 )
            return 0;
          v81 = 0;
          if ( gSystemInfo.dwNumberOfProcessors <= 0 )
            return 0;
          do
          {
            v82 = GetDlgItem(v74, v81 + 2001);
            ::SendMessageW(v82, 0x400u, 0, 0);
            ++v81;
          }
          while ( v81 < gSystemInfo.dwNumberOfProcessors );
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    }
    return PE_FillControl(hWnd, wParam);
  }
  if ( uMsg == 310 || uMsg == 312 )
    return PE_FillControl(hWnd, wParam);
  if ( uMsg == 1124 )
  {
    v83 = 5;
    if ( gConfig.bShowAllCpus )
      v83 = 0;
    v84 = v83;
    v85 = GetDlgItem(hWnd, 2000);
    ShowWindow(v85, v84);
    for ( i = 1; i < (gSystemInfo.dwNumberOfProcessors + 1); ++i )
    {
      v87 = 0;
      if ( gConfig.bShowAllCpus )
        v87 = 5;
      v88 = v87;
      v89 = GetDlgItem(hWnd, i + 2000);
      ShowWindow(v89, v88);
    }
  }
  return 0;
}
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (010518B0) --------------------------------------------------------
int __stdcall PropSystemInfoGPU(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LONG v4; // eax
  signed int v5; // eax
  int v6; // ST44_4
  HWND v7; // eax
  CResizer *v8; // eax
  CResizer *v9; // esi
  HWND v10; // eax
  struct tagResizerItem *v11; // eax
  HWND v12; // eax
  struct tagResizerItem *v13; // eax
  HWND v14; // eax
  struct tagResizerItem *v15; // eax
  HWND v16; // eax
  struct tagResizerItem *v17; // eax
  HWND v18; // eax
  struct tagResizerItem *v19; // eax
  HWND v20; // eax
  struct tagResizerItem *v21; // eax
  HWND v22; // ST44_4
  HWND v23; // ST40_4
  HWND v24; // eax
  HWND v25; // ST44_4
  HWND v26; // ST40_4
  HWND v27; // eax
  HWND v28; // ST44_4
  HWND v29; // ST40_4
  HWND v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // eax
  HWND v35; // eax
  HWND v37; // eax
  HWND v38; // eax
  HWND v39; // eax
  HWND v40; // eax
  HWND v41; // eax
  HWND v42; // eax
  int j; // esi
  HWND v44; // eax
  const WCHAR *v45; // eax
  const WCHAR *v46; // eax
  const WCHAR *v47; // eax
  const WCHAR *v48; // eax
  signed int v49; // eax
  int v50; // ST44_4
  HWND v51; // eax
  int i; // esi
  signed int v53; // eax
  int v54; // ST44_4
  HWND v55; // eax
  int v56[2]; // [esp+14h] [ebp-218h]
  wchar_t Dst; // [esp+1Ch] [ebp-210h]
  int v58; // [esp+228h] [ebp-4h]

  if ( msg > 0x133 )
  {
    if ( msg != 310 && msg != 312 )
    {
      if ( msg == 1124 )
      {
        v49 = 5;
        if ( gConfig.bShowAllGpus )
          v49 = 0;
        v50 = v49;
        v51 = GetDlgItem(hDlg, 2501);
        ShowWindow(v51, v50);
        for ( i = 1; i < gdwAdapterRuntingTime + 1; ++i )
        {
          v53 = 0;
          if ( gConfig.bShowAllGpus )
            v53 = 5;
          v54 = v53;
          v55 = GetDlgItem(hDlg, i + 2501);
          ShowWindow(v55, v54);
        }
      }
      return 0;
    }
  }
  else if ( msg != 307 )
  {
    switch ( msg )
    {
      case 0x24u:
        *(lParam + 8) = 2 * gdwVirtualScreenWidth;
        return 0;
      case 0x110u:
        v4 = GetWindowLongW(hDlg, -16);
        SetWindowLongW(hDlg, -16, v4 | 0x2000000);
        v5 = 0;
        if ( gdwAdapterRuntingTime > 1 )
          v5 = 5;
        v6 = v5;
        v7 = GetDlgItem(hDlg, 1210);
        ShowWindow(v7, v6);
        CreateGraphWindow(hDlg, IDC_SYSINFO_GPU_STATIC_GPU_USAGE_GRAPH, gpGraphInfoOfGPU);
        CreateGraphWindow(hDlg, IDC_SYSINFO_GPU_NODES_STATIC_GRAPH, gpGraphInfoOfGPU);
        CreateGraphWindow(hDlg, IDC_SYSINFO_GPU_STATIC_GPU_DEDICATED_MEMORY_GRAPH, gpGraphInfoOfDedicatedMemory);
        CreateGraphWindow(hDlg, IDC_SYSINFO_GPU_STATIC_GPU_DEDICATED_MEMORY_CHART, gpGraphInfoOfDedicatedMemory);
        CreateGraphWindow(hDlg, IDC_SYSINFO_GPU_STATIC_GPU_SYSTEM_MEMORY_GRAPH, gpGraphInfoOfSystemMemory);
        CreateGraphWindow(hDlg, IDC_SYSINFO_GPU_STATIC_GPU_SYSTEM_MEMORY_CHART, gpGraphInfoOfSystemMemory);
        v8 = operator new(0x40u);
        v58 = 0;
        if ( v8 )
          v9 = CResizer::CResizer(v8, hDlg);
        else
          v9 = 0;
        v58 = -1;
        v9->m_nXRatio = 100;
        v9->m_nYRatio = 0;
        v10 = GetDlgItem(hDlg, 2501);
        if ( v10 )
        {
          v11 = CResizer::AddItem(v9, v10, 1);
          *&v11->m_rect1.left = 0i64;
          *&v11->m_rect1.right = db_one;
        }
        v12 = GetDlgItem(hDlg, 1649);
        if ( v12 )
        {
          v13 = CResizer::AddItem(v9, v12, 1);
          *&v13->m_rect1.left = 0i64;
          *&v13->m_rect1.right = db_one;
        }
        v14 = GetDlgItem(hDlg, 2601);
        if ( v14 )
        {
          v15 = CResizer::AddItem(v9, v14, 1);
          *&v15->m_rect1.left = 0i64;
          *&v15->m_rect1.right = db_one;
        }
        v16 = GetDlgItem(hDlg, 1115);
        if ( v16 )
        {
          v17 = CResizer::AddItem(v9, v16, 1);
          *&v17->m_rect1.left = 0i64;
          *&v17->m_rect1.right = db_one;
        }
        v18 = GetDlgItem(hDlg, 2602);
        if ( v18 )
        {
          v19 = CResizer::AddItem(v9, v18, 1);
          *&v19->m_rect1.left = 0i64;
          *&v19->m_rect1.right = db_one;
        }
        v20 = GetDlgItem(hDlg, 1116);
        if ( v20 )
        {
          v21 = CResizer::AddItem(v9, v20, 1);
          *&v21->m_rect1.left = 0i64;
          *&v21->m_rect1.right = db_one;
        }
        v22 = GetDlgItem(hDlg, 1161);
        v23 = GetDlgItem(hDlg, 1159);
        v24 = GetDlgItem(hDlg, 1157);
        sub_1050510(v9, v24, v23, v22);
        v25 = GetDlgItem(hDlg, 1162);
        v26 = GetDlgItem(hDlg, 1160);
        v27 = GetDlgItem(hDlg, 1651);
        sub_1050510(v9, v27, v26, v25);
        v28 = GetDlgItem(hDlg, 2602);
        v29 = GetDlgItem(hDlg, 2601);
        v30 = GetDlgItem(hDlg, 2501);
        sub_1050510(v9, v30, v29, v28);
        v31 = GetDlgItem(hDlg, 1157);
        *&CResizer::AddItem(v9, v31, 1)->m_rect2.right = db_four;
        v32 = GetDlgItem(hDlg, 1159);
        *&CResizer::AddItem(v9, v32, 1)->m_rect2.right = db_four;
        v33 = GetDlgItem(hDlg, 1161);
        *&CResizer::AddItem(v9, v33, 1)->m_rect2.right = db_four;
        v34 = GetDlgItem(hDlg, 1210);
        if ( v34 )
          CResizer::AddItem(v9, v34, 1)->m_rect1 = 0i64;
        if ( gdwAdapterRuntingTime <= 1 )
        {
          v35 = GetDlgItem(hDlg, 1648);
          ShowWindow(v35, 0);
        }
        PropSheet_UpdateTab(hDlg);
        SendMessageW(hDlg, 0x113u, 0, 0);
        return 1;
      case 0x111u:
        if ( wParam == 1210 )
        {
          DialogBoxParamW(ghMainInstance, L"SYSTEMINFOGPUNODES", hDlg, DlgSystemInfoGPUNodes, 0);
          return 0;
        }
        if ( wParam == 1648 && !(wParam >> 16) )
        {
          gConfig.bShowAllGpus = gConfig.bShowAllGpus == 0;
          SendMessageW(hDlg, 0x464u, 0, 0);
          return 0;
        }
        break;
      case 0x113u:
        if ( !IsWindowVisible(hDlg) )
          return 0;
        v37 = GetDlgItem(hDlg, 1651);
        SendMessageW(v37, 0x400u, 0, 0);
        v38 = GetDlgItem(hDlg, 2501);
        SendMessageW(v38, 0x400u, 0, 0);
        v39 = GetDlgItem(hDlg, 1160);
        SendMessageW(v39, 0x400u, 0, 0);
        v40 = GetDlgItem(hDlg, 2601);
        SendMessageW(v40, 0x400u, 0, 0);
        v41 = GetDlgItem(hDlg, 1162);
        SendMessageW(v41, 0x400u, 0, 0);
        v42 = GetDlgItem(hDlg, 2602);
        SendMessageW(v42, 0x400u, 0, 0);
        if ( gdwAdapterRuntingTime > 1 )
        {
          for ( j = 0; j < gdwAdapterRuntingTime; ++j )
          {
            v44 = GetDlgItem(hDlg, j + 2502);
            SendMessageW(v44, 0x400u, 0, 0);
          }
        }
        GraphData_QueryData(gpGraphInfoOfSystemMemory, v56, 0);
        wsprintf(&Dst, L"%u", *v56);
        v45 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1104, v45);
        wsprintf(&Dst, L"%u", gpGraphInfoOfSystemMemory->m_dbMemorySize);
        v46 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1105, v46);
        GraphData_QueryData(gpGraphInfoOfDedicatedMemory, v56, 0);
        wsprintf(&Dst, L"%d", *v56);
        v47 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1660, v47);
        wsprintf(&Dst, L"%d", gpGraphInfoOfDedicatedMemory->m_dbMemorySize);
        v48 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1661, v48);
        return 0;
      default:
        return 0;
    }
    return 0;
  }
  return PE_FillControl(hDlg, wParam);
}
// 109CB38: using guessed type double db_four;
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (01052010) --------------------------------------------------------
int __stdcall PropSystemInfoIO(HWND hDlg, int a2, HDC hdc, int a4)
{
  HWND v4; // eax
  HWND v5; // eax
  HWND v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  LONG v11; // eax
  CResizer *v12; // eax
  CResizer *v13; // esi
  HWND v14; // edi
  HWND v15; // esi
  HWND v16; // edi
  HWND v17; // esi
  HWND v18; // edi
  HWND v19; // esi
  CResizer *v20; // esi
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  ULONG ReturnLength; // [esp+10h] [ebp-15Ch]
  CResizer *v26; // [esp+14h] [ebp-158h]
  int SystemInformation; // [esp+18h] [ebp-154h]
  __int64 v28; // [esp+20h] [ebp-14Ch]
  __int64 v29; // [esp+28h] [ebp-144h]
  __int64 v30; // [esp+30h] [ebp-13Ch]
  int v31; // [esp+38h] [ebp-134h]
  int v32; // [esp+3Ch] [ebp-130h]
  int v33; // [esp+40h] [ebp-12Ch]
  HWND v34; // [esp+150h] [ebp-1Ch]
  HWND v35; // [esp+154h] [ebp-18h]
  HWND v36; // [esp+158h] [ebp-14h]
  int v37; // [esp+168h] [ebp-4h]

  if ( a2 > 0x133 )
  {
    if ( a2 != 310 && a2 != 312 )
      return 0;
    return PE_FillControl(hDlg, hdc);
  }
  if ( a2 == 307 )
    return PE_FillControl(hDlg, hdc);
  if ( a2 == 36 )
  {
    *(a4 + 8) = 2 * gdwVirtualScreenWidth;
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 275 )
    {
      NtQuerySystemInformation(SystemPerformanceInformation, &SystemInformation, 0x138u, &ReturnLength);
      sub_1050400(hDlg, 1176, v31 - dword_10E53A8, 0);
      sub_1050460(hDlg, 1190, v28 - qword_10E5390, (v28 - qword_10E5390) >> 32);
      sub_1050400(hDlg, 1177, v32 - dword_10E53AC, 0);
      sub_1050460(hDlg, 1192, v29 - qword_10E5398, (v29 - qword_10E5398) >> 32);
      sub_1050400(hDlg, 1178, v33 - dword_10E53B0, 0);
      sub_1050460(hDlg, 1194, v30 - qword_10E53A0, (v30 - qword_10E53A0) >> 32);
      qmemcpy(&unk_10E5388, &SystemInformation, 0x138u);
      sub_1050400(hDlg, 1180, gTreeList_Item[1].field_10, 0);
      sub_1050460(hDlg, 1196, gTreeList_Item[1].field_38, gTreeList_Item[1].field_3C);
      sub_1050400(hDlg, 1181, gTreeList_Item[1].field_C, 0);
      sub_1050460(hDlg, 1198, gTreeList_Item[1].field_30, gTreeList_Item[1].field_34);
      sub_1050400(hDlg, 1182, gTreeList_Item[1].field_14, 0);
      sub_1050460(hDlg, 1200, gTreeList_Item[1].field_40, gTreeList_Item[1].field_44);
      sub_1050400(hDlg, 1186, gTreeList_Item[2].field_10, 0);
      sub_1050460(hDlg, 1202, gTreeList_Item[2].field_38, gTreeList_Item[2].field_3C);
      sub_1050400(hDlg, 1187, gTreeList_Item[2].field_C, 0);
      sub_1050460(hDlg, 1204, gTreeList_Item[2].field_30, gTreeList_Item[2].field_34);
      sub_1050400(hDlg, 1188, gTreeList_Item[2].field_14, 0);
      sub_1050460(hDlg, 1206, gTreeList_Item[2].field_40, gTreeList_Item[2].field_44);
      if ( gIOGraphInfo.pGraphData )
      {
        v4 = GetDlgItem(hDlg, 1332);
        SendMessageW(v4, 0x400u, 0, 0);
        v5 = GetDlgItem(hDlg, 1330);
        SendMessageW(v5, 0x400u, 0, 0);
      }
      if ( gNetworkGraphInfo.pGraphData )
      {
        v6 = GetDlgItem(hDlg, 1351);
        SendMessageW(v6, 0x400u, 0, 0);
        v7 = GetDlgItem(hDlg, 1335);
        SendMessageW(v7, 0x400u, 0, 0);
      }
      if ( gDiskGraphInfo.pGraphData )
      {
        v8 = GetDlgItem(hDlg, 1337);
        SendMessageW(v8, 0x400u, 0, 0);
        v9 = GetDlgItem(hDlg, 1338);
        SendMessageW(v9, 0x400u, 0, 0);
        return 0;
      }
    }
    return 0;
  }
  v11 = GetWindowLongW(hDlg, -16);
  SetWindowLongW(hDlg, -16, v11 | 0x2000000);
  v12 = operator new(0x40u);
  v26 = v12;
  v37 = 0;
  if ( v12 )
  {
    v13 = CResizer::CResizer(v12, hDlg);
    v26 = v13;
  }
  else
  {
    v13 = 0;
    v26 = 0;
  }
  v37 = -1;
  if ( gIOGraphInfo.pGraphData )
  {
    CreateGraphWindow(hDlg, 1332, gIOGraphInfo.pGraphData);
    CreateGraphWindow(hDlg, 1330, gIOGraphInfo.pGraphData);
  }
  if ( IsBuiltinAdministrative() )
  {
    if ( gNetworkGraphInfo.pGraphData )
    {
      CreateGraphWindow(hDlg, 1351, gNetworkGraphInfo.pGraphData);
      CreateGraphWindow(hDlg, 1335, gNetworkGraphInfo.pGraphData);
    }
    if ( gDiskGraphInfo.pGraphData )
    {
      CreateGraphWindow(hDlg, 1337, gDiskGraphInfo.pGraphData);
      CreateGraphWindow(hDlg, 1338, gDiskGraphInfo.pGraphData);
    }
    v13->m_nXRatio = 93;
    v13->m_nYRatio = 20;
    v14 = GetDlgItem(hDlg, 1338);
    v15 = GetDlgItem(hDlg, 1335);
    v34 = GetDlgItem(hDlg, 1330);
    v35 = v15;
    v36 = v14;
    sub_1050550(v26, 3, &v34);
    v16 = GetDlgItem(hDlg, 1336);
    v17 = GetDlgItem(hDlg, 1352);
    v34 = GetDlgItem(hDlg, 1331);
    v35 = v17;
    v36 = v16;
    sub_1050550(v26, 3, &v34);
    v18 = GetDlgItem(hDlg, 1337);
    v19 = GetDlgItem(hDlg, 1351);
    v34 = GetDlgItem(hDlg, 1332);
    v35 = v19;
    v20 = v26;
    v36 = v18;
    sub_1050550(v26, 3, &v34);
    v21 = GetDlgItem(hDlg, 1183);
    if ( v21 )
      CResizer::AddItem(v26, v21, 1)->m_rect1 = 0i64;
    v22 = GetDlgItem(hDlg, 1331);
    *&CResizer::AddItem(v20, v22, 1)->m_rect2.right = db_four;
    v23 = GetDlgItem(hDlg, 1352);
    *&CResizer::AddItem(v20, v23, 1)->m_rect2.right = db_four;
    v24 = GetDlgItem(hDlg, 1336);
    *&CResizer::AddItem(v20, v24, 1)->m_rect2.right = db_four;
  }
  else
  {
    v13->m_nXRatio = 93;
    v13->m_nYRatio = 20;
  }
  PropSheet_UpdateTab(hDlg);
  NtQuerySystemInformation(SystemPerformanceInformation, &unk_10E5388, 0x138u, &ReturnLength);
  SendMessageW(hDlg, 0x113u, 0, 0);
  return 1;
}
// 109CB38: using guessed type double db_four;
// 10C4E28: using guessed type int gdwVirtualScreenWidth;
// 10E5390: using guessed type __int64 qword_10E5390;
// 10E5398: using guessed type __int64 qword_10E5398;
// 10E53A0: using guessed type __int64 qword_10E53A0;
// 10E53A8: using guessed type int dword_10E53A8;
// 10E53AC: using guessed type int dword_10E53AC;
// 10E53B0: using guessed type int dword_10E53B0;

//----- (010525E0) --------------------------------------------------------
int __stdcall PropSystemInfoMem(HWND hWnd, int a2, HDC hdc, int a4)
{
  LONG v4; // eax
  signed int v5; // eax
  int ArgList_4; // ST34_4
  HWND v7; // eax
  signed int v8; // eax
  int v9; // ST34_4
  HWND v10; // eax
  CResizer *v11; // eax
  CResizer *v12; // esi
  HWND v13; // eax
  struct tagResizerItem *v14; // eax
  HWND v15; // eax
  struct tagResizerItem *v16; // eax
  HWND v17; // esi
  HWND v18; // esi
  HWND v19; // esi
  CResizer *v20; // esi
  HWND v21; // eax
  HWND v22; // eax
  const WCHAR *v24; // eax
  void (__stdcall *v25)(HWND, int, LPCWSTR); // esi
  const WCHAR *v26; // eax
  const WCHAR *v27; // eax
  const WCHAR *v28; // eax
  DWORD v29; // eax
  const WCHAR *v30; // eax
  const WCHAR *v31; // eax
  const WCHAR *v32; // eax
  const WCHAR *v33; // eax
  const WCHAR *v34; // eax
  const WCHAR *v35; // eax
  const WCHAR *v36; // eax
  const WCHAR *v37; // eax
  unsigned int v38; // esi
  const WCHAR *v39; // eax
  char *v40; // ecx
  const WCHAR *v41; // eax
  const WCHAR *v42; // ST34_4
  const WCHAR *v43; // ST34_4
  const WCHAR *v44; // eax
  const WCHAR *v45; // eax
  HWND v46; // eax
  HWND v47; // eax
  HWND v48; // eax
  HWND v49; // eax
  double ArgList; // [esp+30h] [ebp-450h]
  double ArgLista; // [esp+30h] [ebp-450h]
  ULONG ReturnLength; // [esp+44h] [ebp-43Ch]
  HWND v53; // [esp+48h] [ebp-438h]
  void *v54; // [esp+4Ch] [ebp-434h]
  HWND hDlg; // [esp+50h] [ebp-430h]
  int v56; // [esp+54h] [ebp-42Ch]
  unsigned __int64 v57; // [esp+5Ch] [ebp-424h]
  int SystemInformation; // [esp+94h] [ebp-3ECh]
  int v59; // [esp+C0h] [ebp-3C0h]
  unsigned int v60; // [esp+C4h] [ebp-3BCh]
  unsigned int v61; // [esp+C8h] [ebp-3B8h]
  unsigned int v62; // [esp+CCh] [ebp-3B4h]
  int v63; // [esp+D0h] [ebp-3B0h]
  int v64; // [esp+E8h] [ebp-398h]
  int v65; // [esp+F4h] [ebp-38Ch]
  int v66; // [esp+FCh] [ebp-384h]
  int v67; // [esp+104h] [ebp-37Ch]
  int v68; // [esp+108h] [ebp-378h]
  int v69; // [esp+120h] [ebp-360h]
  int v70; // [esp+138h] [ebp-348h]
  int v71; // [esp+13Ch] [ebp-344h]
  int v72; // [esp+140h] [ebp-340h]
  struct _MEMORYSTATUS Buffer; // [esp+1CCh] [ebp-2B4h]
  int v74; // [esp+1ECh] [ebp-294h]
  int v75; // [esp+1F0h] [ebp-290h]
  int v76; // [esp+1F4h] [ebp-28Ch]
  int v77; // [esp+1F8h] [ebp-288h]
  int v78[16]; // [esp+200h] [ebp-280h]
  int v79; // [esp+240h] [ebp-240h]
  _DWORD v80[4]; // [esp+244h] [ebp-23Ch]
  __int128 v81; // [esp+254h] [ebp-22Ch]
  int v82; // [esp+264h] [ebp-21Ch]
  WCHAR String; // [esp+268h] [ebp-218h]
  int v84; // [esp+47Ch] [ebp-4h]

  hDlg = hWnd;
  if ( a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, hdc);
    return 0;
  }
  if ( a2 != 275 )
  {
    switch ( a2 )
    {
      case 36:
        *(a4 + 8) = 2 * gdwVirtualScreenWidth;
        return 0;
      case 256:
        if ( hdc == 116 )
        {
          PostMessageW(hWnd, 0x113u, 1u, 0);
          return 0;
        }
        break;
      case 272:
        v4 = GetWindowLongW(hWnd, -16);
        SetWindowLongW(hWnd, -16, v4 | 0x2000000);
        CreateGraphWindow(hWnd, 1161, gpGraphInfoOfMemory);
        CreateGraphWindow(hWnd, 1159, gpGraphInfoOfMemory);
        CreateGraphWindow(hWnd, 1333, gpGraphInfoOfPhysicalMemory);
        CreateGraphWindow(hWnd, 1637, gpGraphInfoOfPhysicalMemory);
        v5 = 0;
        if ( gdwVersion >= 3 )
          v5 = 5;
        ArgList_4 = v5;
        v7 = GetDlgItem(hWnd, 1662);
        ShowWindow(v7, ArgList_4);
        v8 = 0;
        if ( gdwVersion >= 3 )
          v8 = 5;
        v9 = v8;
        v10 = GetDlgItem(hWnd, 1663);
        ShowWindow(v10, v9);
        v11 = operator new(0x40u);
        v54 = v11;
        v84 = 0;
        if ( v11 )
        {
          v12 = CResizer::CResizer(v11, hWnd);
          hDlg = v12;
        }
        else
        {
          v12 = 0;
          hDlg = 0;
        }
        v84 = -1;
        v12->m_nXRatio = 100;
        v12->m_nYRatio = 20;
        v13 = GetDlgItem(hWnd, 1159);
        if ( v13 )
        {
          v14 = CResizer::AddItem(v12, v13, 1);
          *&v14->m_rect1.left = 0i64;
          *&v14->m_rect1.right = db_one;
        }
        v15 = GetDlgItem(hWnd, 1333);
        if ( v15 )
        {
          v16 = CResizer::AddItem(v12, v15, 1);
          *&v16->m_rect1.left = 0i64;
          *&v16->m_rect1.right = db_one;
        }
        v17 = GetDlgItem(hWnd, 1333);
        v53 = GetDlgItem(hWnd, 1159);
        v54 = v17;
        sub_1050550(hDlg, 2, &v53);
        v18 = GetDlgItem(hWnd, 1334);
        v53 = GetDlgItem(hWnd, 1160);
        v54 = v18;
        sub_1050550(hDlg, 2, &v53);
        v19 = GetDlgItem(hWnd, 1637);
        v53 = GetDlgItem(hWnd, 1161);
        v54 = v19;
        v20 = hDlg;
        sub_1050550(hDlg, 2, &v53);
        v21 = GetDlgItem(hWnd, 1160);
        *&CResizer::AddItem(v20, v21, 1)->m_rect2.right = db_four;
        v22 = GetDlgItem(hWnd, 1334);
        *&CResizer::AddItem(v20, v22, 1)->m_rect2.right = db_four;
        PropSheet_UpdateTab(hWnd);
        NtQuerySystemInformation(
          SystemPerformanceInformation,
          &gSystenPerformanceInfoInProcSecurity.ResidentAvailablePages,
          0x138u,
          &ReturnLength);
        SendMessageW(hWnd, 0x113u, 0, 0);
        return 1;
    }
    return 0;
  }
  sub_103CE20(&qword_10E5378, &qword_10E5380);
  NtQuerySystemInformation(SystemPerformanceInformation, &SystemInformation, 0x138u, &ReturnLength);
  v82 = 0;
  _mm_storeu_si128(v80, 0i64);
  _mm_storeu_si128(&v81, 0i64);
  NtQuerySystemInformation(SystemFileCacheInformation, v80, 0x24u, &ReturnLength);
  memset(&v74, 0, 0x58u);
  NtQuerySystemInformation(SystemMemoryListInformation, &v74, 0x58u, &ReturnLength);
  swprintf(&String, L"%d", v61 * (gSystemInfo.dwPageSize >> 10));
  v24 = PE_GetNumberFormat(&String, 0x104u);
  v25 = SetDlgItemTextW;
  SetDlgItemTextW(hWnd, 1103, v24);
  ArgList = v60 * 100.0 / v61;
  if ( gConfig.bShowCpuFractions )
    swprintf(&String, L"%02.2f%%", ArgList);
  else
    swprintf(&String, L"%0.0f%%", ArgList);
  SetDlgItemTextW(hWnd, 1110, &String);
  swprintf(&String, L"%u", v60 * (gSystemInfo.dwPageSize >> 10));
  v26 = PE_GetNumberFormat(&String, 0x104u);
  SetDlgItemTextW(hWnd, 1102, v26);
  swprintf(&String, L"%u", v62 * (gSystemInfo.dwPageSize >> 10));
  v27 = PE_GetNumberFormat(&String, 0x104u);
  SetDlgItemTextW(hWnd, 1104, v27);
  ArgLista = v62 * 100.0 / v61;
  if ( gConfig.bShowCpuFractions )
    swprintf(&String, L"%02.2f%%", ArgLista);
  else
    swprintf(&String, L"%0.0f%%", ArgLista);
  SetDlgItemTextW(hWnd, 1111, &String);
  swprintf(&String, L"%u", v59 * (gSystemInfo.dwPageSize >> 10));
  v28 = PE_GetNumberFormat(&String, 0x104u);
  SetDlgItemTextW(hWnd, 1100, v28);
  v29 = gSystemInfo.dwPageSize >> 10;
  if ( DWORD1(v81) )
    v54 = (DWORD1(v81) * v29);
  else
    v54 = (v29 * (v71 + v70 + v72 + v69));
  if ( GlobalMemoryStatusEx )
  {
    v56 = 64;
    GlobalMemoryStatusEx(&v56);
    swprintf(&String, L"%I64d", v57 >> 10);
  }
  else
  {
    Buffer.dwLength = 32;
    GlobalMemoryStatus(&Buffer);
    swprintf(&String, L"%d", Buffer.dwTotalPhys >> 10);
  }
  v30 = PE_GetNumberFormat(&String, 0x104u);
  SetDlgItemTextW(hWnd, 1099, v30);
  if ( gdwVersion < 1 )
  {
    swprintf(&String, L"%d", v54);
    v43 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1101, v43);
  }
  else
  {
    swprintf(&String, L"%u", v72 * (gSystemInfo.dwPageSize >> 10));
    v31 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1116, v31);
    swprintf(&String, L"%u", v69 * (gSystemInfo.dwPageSize >> 10));
    v32 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1114, v32);
    swprintf(&String, L"%u", v70 * (gSystemInfo.dwPageSize >> 10));
    v33 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1101, v33);
    swprintf(&String, L"%u", v74 * (gSystemInfo.dwPageSize >> 10));
    v34 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1112, v34);
    swprintf(&String, L"%u", v75 * (gSystemInfo.dwPageSize >> 10));
    v35 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1113, v35);
    swprintf(&String, L"%u", v76 * (gSystemInfo.dwPageSize >> 10));
    v36 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1118, v36);
    swprintf(&String, L"%u", v77 * (gSystemInfo.dwPageSize >> 10));
    v37 = PE_GetNumberFormat(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1119, v37);
    v54 = 0;
    v38 = 0;
    do
    {
      swprintf(&String, L"%u", v78[v38] * (gSystemInfo.dwPageSize >> 10));
      v39 = PE_GetNumberFormat(&String, 0x104u);
      SetDlgItemTextW(hWnd, v38 + 1120, v39);
      v40 = v54 + v78[v38++];
      v54 = v40;
    }
    while ( v38 < 8 );
    swprintf(&String, L"%u", v40 * (gSystemInfo.dwPageSize >> 10));
    v41 = PE_GetNumberFormat(&String, 0x104u);
    v25 = SetDlgItemTextW;
    SetDlgItemTextW(hWnd, 1117, v41);
    if ( gdwVersion >= 3 )
    {
      swprintf(&String, L"%u", v79 * (gSystemInfo.dwPageSize >> 10));
      v42 = PE_GetNumberFormat(&String, 0x104u);
      SetDlgItemTextW(hWnd, 1663, v42);
    }
  }
  if ( qword_10E5378 )
  {
    swprintf(&String, L"%I64u", qword_10E5378 >> 10);
    PE_GetNumberFormat(&String, 0x104u);
    v25(hWnd, 1108, &String);
  }
  swprintf(&String, L"%u", v68 * (gSystemInfo.dwPageSize >> 10));
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1107, &String);
  swprintf(&String, L"%u", v71 * (gSystemInfo.dwPageSize >> 10));
  v44 = PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1105, v44);
  swprintf(&String, L"%u", v67 * (gSystemInfo.dwPageSize >> 10));
  v45 = PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1106, v45);
  if ( qword_10E5380 )
  {
    swprintf(&String, L"%I64u", qword_10E5380 >> 10);
    PE_GetNumberFormat(&String, 0x104u);
    v25(hWnd, 1664, &String);
  }
  swprintf(&String, L"%u", v63 - dword_10E527C);
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1171, &String);
  swprintf(&String, L"%u", v64 - dword_10E5294);
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1172, &String);
  swprintf(&String, L"%u", v65 - dword_10E52A0);
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1173, &String);
  swprintf(&String, L"%u", v66 - dword_10E52A8);
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1174, &String);
  qmemcpy(&gSystenPerformanceInfoInProcSecurity.ResidentAvailablePages, &SystemInformation, 0x138u);
  v46 = GetDlgItem(hDlg, 1161);
  SendMessageW(v46, 0x400u, 0, 0);
  v47 = GetDlgItem(hDlg, 1159);
  SendMessageW(v47, 0x400u, 0, 0);
  v48 = GetDlgItem(hDlg, 1637);
  SendMessageW(v48, 0x400u, 0, 0);
  v49 = GetDlgItem(hDlg, 1333);
  SendMessageW(v49, 0x400u, 0, 0);
  return 0;
}
// 109CB38: using guessed type double db_four;
// 109CDC0: using guessed type double db_onehundred;
// 10A67B8: using guessed type wchar_t a022f_0[9];
// 10C4E28: using guessed type int gdwVirtualScreenWidth;
// 10C4E54: using guessed type int gdwVersion;
// 10CF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);
// 10E527C: using guessed type int dword_10E527C;
// 10E5294: using guessed type int dword_10E5294;
// 10E52A0: using guessed type int dword_10E52A0;
// 10E52A8: using guessed type int dword_10E52A8;
// 10E5378: using guessed type __int64 qword_10E5378;
// 10E5380: using guessed type __int64 qword_10E5380;
// 10525E0: using guessed type int var_280[16];

//----- (01053260) --------------------------------------------------------
int __stdcall PropSummary(HWND hDlg, int a2, HDC hdc, int a4)
{
  HWND v4; // eax
  HWND v5; // eax
  HWND v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  LONG v21; // eax
  CResizer *v22; // eax
  CResizer *v23; // ebx
  HWND v24; // eax
  struct tagResizerItem *v25; // eax
  HWND v26; // eax
  struct tagResizerItem *v27; // eax
  HWND v28; // eax
  struct tagResizerItem *v29; // eax
  HWND v30; // eax
  struct tagResizerItem *v31; // eax
  HWND v32; // ST5C_4
  HWND v33; // ST58_4
  HWND v34; // ebx
  HWND v35; // edi
  HWND v36; // esi
  HWND v37; // ST58_4
  HWND v38; // ST5C_4
  HWND v39; // ebx
  HWND v40; // edi
  HWND v41; // esi
  HWND v42; // ST58_4
  HWND v43; // ST5C_4
  HWND v44; // ebx
  HWND v45; // edi
  HWND v46; // esi
  CResizer *v47; // edi
  HWND v48; // ebx
  HWND (__stdcall *v49)(HWND, int); // esi
  HWND v50; // eax
  HWND v51; // eax
  HWND v52; // ebx
  HWND v53; // edi
  HWND v54; // esi
  HWND v55; // ebx
  HWND v56; // edi
  HWND v57; // esi
  HWND v58; // ebx
  HWND v59; // edi
  HWND v60; // esi
  HWND v61; // eax
  HWND v62; // eax
  HWND v63; // eax
  HWND v64; // eax
  CResizer *v65; // [esp+18h] [ebp-30h]
  HWND v66; // [esp+20h] [ebp-28h]
  HWND v67; // [esp+24h] [ebp-24h]
  HWND v68; // [esp+28h] [ebp-20h]
  HWND v69; // [esp+2Ch] [ebp-1Ch]
  HWND v70; // [esp+30h] [ebp-18h]
  HWND v71; // [esp+34h] [ebp-14h]
  int v72; // [esp+44h] [ebp-4h]

  if ( a2 > 0x133 )
  {
    if ( a2 != 310 && a2 != 312 )
      return 0;
    return PE_FillControl(hDlg, hdc);
  }
  if ( a2 == 307 )
    return PE_FillControl(hDlg, hdc);
  if ( a2 == 36 )
  {
    *(a4 + 8) = 2 * gdwVirtualScreenWidth;
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 275 )
    {
      v4 = GetDlgItem(hDlg, 1158);
      SendMessageW(v4, 0x400u, 0, 0);
      v5 = GetDlgItem(hDlg, 2000);
      SendMessageW(v5, 0x400u, 0, 0);
      v6 = GetDlgItem(hDlg, 1161);
      SendMessageW(v6, 0x400u, 0, 0);
      v7 = GetDlgItem(hDlg, 1159);
      SendMessageW(v7, 0x400u, 0, 0);
      v8 = GetDlgItem(hDlg, 1637);
      SendMessageW(v8, 0x400u, 0, 0);
      v9 = GetDlgItem(hDlg, 1333);
      SendMessageW(v9, 0x400u, 0, 0);
      v10 = GetDlgItem(hDlg, 1161);
      SendMessageW(v10, 0x400u, 0, 0);
      v11 = GetDlgItem(hDlg, 1159);
      SendMessageW(v11, 0x400u, 0, 0);
      v12 = GetDlgItem(hDlg, 1637);
      SendMessageW(v12, 0x400u, 0, 0);
      v13 = GetDlgItem(hDlg, 1333);
      SendMessageW(v13, 0x400u, 0, 0);
      if ( gIOGraphInfo.pGraphData )
      {
        v14 = GetDlgItem(hDlg, 1332);
        SendMessageW(v14, 0x400u, 0, 0);
        v15 = GetDlgItem(hDlg, 1330);
        SendMessageW(v15, 0x400u, 0, 0);
      }
      if ( gNetworkGraphInfo.pGraphData )
      {
        v16 = GetDlgItem(hDlg, 1351);
        SendMessageW(v16, 0x400u, 0, 0);
        v17 = GetDlgItem(hDlg, 1335);
        SendMessageW(v17, 0x400u, 0, 0);
      }
      if ( gDiskGraphInfo.pGraphData )
      {
        v18 = GetDlgItem(hDlg, 1337);
        SendMessageW(v18, 0x400u, 0, 0);
        v19 = GetDlgItem(hDlg, 1338);
        SendMessageW(v19, 0x400u, 0, 0);
        return 0;
      }
    }
    return 0;
  }
  v21 = GetWindowLongW(hDlg, -16);
  SetWindowLongW(hDlg, -16, v21 | 0x2000000);
  v22 = operator new(0x40u);
  v72 = 0;
  if ( v22 )
  {
    v23 = CResizer::CResizer(v22, hDlg);
    v65 = v23;
  }
  else
  {
    v23 = 0;
    v65 = 0;
  }
  v72 = -1;
  CreateGraphWindow(hDlg, 1158, gpGraphInfoOfCPU);
  CreateGraphWindow(hDlg, 2000, gpGraphInfoOfCPU);
  CreateGraphWindow(hDlg, 1161, gpGraphInfoOfMemory);
  CreateGraphWindow(hDlg, 1159, gpGraphInfoOfMemory);
  CreateGraphWindow(hDlg, 1333, gpGraphInfoOfPhysicalMemory);
  CreateGraphWindow(hDlg, 1637, gpGraphInfoOfPhysicalMemory);
  v24 = GetDlgItem(hDlg, 2000);
  if ( v24 )
  {
    v25 = CResizer::AddItem(v23, v24, 1);
    *&v25->m_rect1.left = 0i64;
    *&v25->m_rect1.right = db_one;
  }
  v26 = GetDlgItem(hDlg, 1114);
  if ( v26 )
  {
    v27 = CResizer::AddItem(v23, v26, 1);
    *&v27->m_rect1.left = 0i64;
    *&v27->m_rect1.right = db_one;
  }
  v28 = GetDlgItem(hDlg, 1159);
  if ( v28 )
  {
    v29 = CResizer::AddItem(v23, v28, 1);
    *&v29->m_rect1.left = 0i64;
    *&v29->m_rect1.right = db_one;
  }
  v30 = GetDlgItem(hDlg, 1333);
  if ( v30 )
  {
    v31 = CResizer::AddItem(v23, v30, 1);
    *&v31->m_rect1.left = 0i64;
    *&v31->m_rect1.right = db_one;
  }
  if ( gIOGraphInfo.pGraphData )
  {
    CreateGraphWindow(hDlg, 1332, gIOGraphInfo.pGraphData);
    CreateGraphWindow(hDlg, 1330, gIOGraphInfo.pGraphData);
  }
  if ( IsBuiltinAdministrative() )
  {
    if ( gNetworkGraphInfo.pGraphData )
    {
      CreateGraphWindow(hDlg, 1351, gNetworkGraphInfo.pGraphData);
      CreateGraphWindow(hDlg, 1335, gNetworkGraphInfo.pGraphData);
    }
    if ( gDiskGraphInfo.pGraphData )
    {
      CreateGraphWindow(hDlg, 1337, gDiskGraphInfo.pGraphData);
      CreateGraphWindow(hDlg, 1338, gDiskGraphInfo.pGraphData);
    }
    v23->m_nXRatio = 93;
    v23->m_nYRatio = 10;
    v32 = GetDlgItem(hDlg, 1338);
    v33 = GetDlgItem(hDlg, 1335);
    v34 = GetDlgItem(hDlg, 1330);
    v35 = GetDlgItem(hDlg, 1333);
    v36 = GetDlgItem(hDlg, 1159);
    v66 = GetDlgItem(hDlg, 2000);
    v70 = v33;
    v71 = v32;
    v67 = v36;
    v68 = v35;
    v69 = v34;
    sub_1050550(v65, 6, &v66);
    v37 = GetDlgItem(hDlg, 1336);
    v38 = GetDlgItem(hDlg, 1352);
    v39 = GetDlgItem(hDlg, 1331);
    v40 = GetDlgItem(hDlg, 1334);
    v41 = GetDlgItem(hDlg, 1160);
    v66 = GetDlgItem(hDlg, 1157);
    v70 = v38;
    v71 = v37;
    v67 = v41;
    v68 = v40;
    v69 = v39;
    sub_1050550(v65, 6, &v66);
    v42 = GetDlgItem(hDlg, 1337);
    v43 = GetDlgItem(hDlg, 1351);
    v44 = GetDlgItem(hDlg, 1332);
    v45 = GetDlgItem(hDlg, 1637);
    v46 = GetDlgItem(hDlg, 1161);
    v66 = GetDlgItem(hDlg, 1158);
    v70 = v43;
    v71 = v42;
    v68 = v45;
    v47 = v65;
    v67 = v46;
    v69 = v44;
    sub_1050550(v65, 6, &v66);
    v48 = hDlg;
    v49 = GetDlgItem;
    v50 = GetDlgItem(hDlg, 1352);
    *&CResizer::AddItem(v65, v50, 1)->m_rect2.right = db_four;
    v51 = GetDlgItem(hDlg, 1336);
    *&CResizer::AddItem(v65, v51, 1)->m_rect2.right = db_four;
  }
  else
  {
    v23->m_nXRatio = 93;
    v23->m_nYRatio = 10;
    v52 = GetDlgItem(hDlg, 1330);
    v53 = GetDlgItem(hDlg, 1333);
    v54 = GetDlgItem(hDlg, 1159);
    v68 = GetDlgItem(hDlg, 2000);
    v69 = v54;
    v70 = v53;
    v71 = v52;
    sub_1050550(v65, 4, &v68);
    v55 = GetDlgItem(hDlg, 1331);
    v56 = GetDlgItem(hDlg, 1334);
    v57 = GetDlgItem(hDlg, 1160);
    v68 = GetDlgItem(hDlg, 1157);
    v69 = v57;
    v70 = v56;
    v71 = v55;
    sub_1050550(v65, 4, &v68);
    v58 = GetDlgItem(hDlg, 1332);
    v59 = GetDlgItem(hDlg, 1637);
    v60 = GetDlgItem(hDlg, 1161);
    v68 = GetDlgItem(hDlg, 1158);
    v70 = v59;
    v47 = v65;
    v69 = v60;
    v71 = v58;
    sub_1050550(v65, 4, &v68);
    v48 = hDlg;
    v49 = GetDlgItem;
  }
  v61 = v49(v48, 1157);
  *&CResizer::AddItem(v47, v61, 1)->m_rect2.right = db_four;
  v62 = v49(v48, 1160);
  *&CResizer::AddItem(v47, v62, 1)->m_rect2.right = db_four;
  v63 = v49(v48, 1334);
  *&CResizer::AddItem(v47, v63, 1)->m_rect2.right = db_four;
  v64 = v49(v48, 1331);
  *&CResizer::AddItem(v47, v64, 1)->m_rect2.right = db_four;
  PropSheet_UpdateTab(v48);
  SendMessageW(v48, 0x113u, 0, 0);
  return 1;
}
// 109CB38: using guessed type double db_four;
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (010539C0) --------------------------------------------------------
_DWORD *__cdecl sub_10539C0(SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo, DWORD dwProcessId)
{
  ULONG *GrantedAccess; // esi
  UCHAR *ObjectTypeIndex; // ebx
  PE_SYSTEM_HANDLE_TABLE_ENTRY_INFO *pInfo; // edi
  _DWORD *v5; // eax
  unsigned int v6; // edi
  int a2; // [esp+4h] [ebp-14h]
  int a4; // [esp+8h] [ebp-10h]
  int a3; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  _DWORD *v12; // [esp+14h] [ebp-4h]

  v12 = 0;
  v11 = 0;
  if ( SystemHandleInfo_GetHandlesNumber(pSystemHandleInfo) )
  {
    GrantedAccess = &pSystemHandleInfo->Handles[0].GrantedAccess;
    ObjectTypeIndex = &pSystemHandleInfo->Handles[0].ObjectTypeIndex;
    do
    {
      if ( gbSupportExtendedSystemHandleInformation )
      {
        pInfo = ObjectTypeIndex;
      }
      else
      {
        pInfo = &stru_10DBC0C;
        stru_10DBC0C.field_10 = *(GrantedAccess - 5);
        stru_10DBC0C.GrantedAccess = *GrantedAccess;
        LOBYTE(stru_10DBC0C.field_14) = *(GrantedAccess - 7);
        stru_10DBC0C.Object = *(GrantedAccess - 3);
        *&stru_10DBC0C.field_0 = *(GrantedAccess - 1);
        *(&stru_10DBC0C.field_10 + 1) = *(GrantedAccess - 8);
        *&stru_10DBC0C.ObjectTypeIndex = *(GrantedAccess - 6);
      }
      if ( *&pInfo->ObjectTypeIndex == dwProcessId
        && !_wcsicmp(&gpszObjectTypeNames[0x40 * *(&pInfo->field_10 + 1)], L"File")
        && sub_103C4F0(pInfo, &a2, &a3, &a4) )
      {
        v5 = malloc(0x890u);
        v5[11] = a3;
        v5[146] = a4;
        v5[10] = a2;
        v5[547] = v12;
        v12 = v5;
      }
      ObjectTypeIndex += sizeof(_SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX);
      GrantedAccess += 4;
      v6 = ++v11;
    }
    while ( v6 < SystemHandleInfo_GetHandlesNumber(pSystemHandleInfo) );
  }
  sub_103C4F0(0, 0, 0, 0);
  return v12;
}
// 10CABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// 10DBC0C: using guessed type PE_SYSTEM_HANDLE_TABLE_ENTRY_INFO stru_10DBC0C;

//----- (01053AF0) --------------------------------------------------------
BOOL __stdcall DlgThreadStack(HWND hWnd, UINT a2, WPARAM a3, LPARAM a4)
{
  HWND v4; // edi
  HICON v5; // eax
  CResizer *v6; // eax
  HWND v7; // ebx
  tagTREEVIEWLISTITEMPARAM **v8; // ST14_4
  HWND v9; // eax
  POINT v10; // ST10_8
  int v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  int v16; // esi
  HWND v17; // eax
  LRESULT v18; // eax
  HGLOBAL v19; // ebx
  wchar_t *v20; // edi
  unsigned int v21; // esi
  rsize_t v22; // esi
  LRESULT v23; // esi
  HWND v24; // edi
  LVITEMW lParam; // [esp+10h] [ebp-268h]
  struct tagPOINT Point; // [esp+44h] [ebp-234h]
  UINT pnIDs; // [esp+4Ch] [ebp-22Ch]
  int v28; // [esp+50h] [ebp-228h]
  int v29; // [esp+54h] [ebp-224h]
  WORD pnWidths[2]; // [esp+58h] [ebp-220h]
  HWND v31; // [esp+5Ch] [ebp-21Ch]
  WPARAM wParam; // [esp+60h] [ebp-218h]
  HGLOBAL hMem; // [esp+64h] [ebp-214h]
  wchar_t Src; // [esp+68h] [ebp-210h]
  int v35; // [esp+274h] [ebp-4h]

  v4 = hWnd;
  hMem = hWnd;
  wParam = a4;
  pnIDs = 43;
  v28 = 44;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    if ( a2 == 2033 )
    {
      GetWindowRect(hWnd, &Rect);
      nWidth = Rect.right - Rect.left;
      nHeight = Rect.bottom - Rect.top;
      DestroyWindow(hWnd);
    }
    return 0;
  }
  if ( a2 == 273 )
  {
    if ( a3 > 40083 )
    {
      if ( a3 == 40631 )
      {
        v23 = 0;
        v24 = GetDlgItem(hWnd, 1087);
        if ( SendMessageW(v24, 0x1004u, 0, 0) > 0 )
        {
          do
          {
            lParam.stateMask = 2;
            lParam.state = 2;
            SendMessageW(v24, 0x102Bu, v23++, &lParam);
          }
          while ( v23 < SendMessageW(v24, 0x1004u, 0, 0) );
        }
      }
    }
    else if ( a3 == 40083 )
    {
      v16 = 0;
      v17 = GetDlgItem(hWnd, 1087);
      v31 = v17;
      v18 = SendMessageW(v17, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
      v19 = hMem;
      wParam = v18;
      if ( v18 != -1 )
      {
        v20 = 0;
        do
        {
          lParam.iSubItem = 1;
          lParam.pszText = &Src;
          lParam.cchTextMax = 256;
          SendMessageW(v31, LVM_GETITEMTEXTW, v18, &lParam);
          v21 = wcslen(&Src) + v16 + 2;
          v29 = v21;
          if ( v20 )
          {
            v19 = GlobalReAlloc(v19, 2 * v21 + 2, 0);
            v20 = GlobalLock(v19);
          }
          else
          {
            v19 = GlobalAlloc(0x2002u, 2 * v21 + 2);
            v20 = GlobalLock(v19);
            *v20 = 0;
          }
          v22 = v21 + 1;
          wcscat_s(v20, v22, &Src);
          wcscat_s(v20, v22, L"\r\n");
          GlobalUnlock(v19);
          v18 = SendMessageW(v31, LVM_GETNEXTITEM, wParam, 2);
          v16 = v29;
          wParam = v18;
        }
        while ( v18 != -1 );
        v4 = hMem;
      }
      if ( OpenClipboard(v4) )
      {
        EmptyClipboard();
        SetClipboardData(0xDu, v19);
        CloseClipboard();
      }
      SetFocus(v31);
    }
    else if ( a3 - 1 <= 1 )
    {
      ghWndThreadStack = 0;
      EndDialog(hWnd, 0);
    }
    return 0;
  }
  if ( a2 == 78 )
  {
    v12 = *(a4 + 8);
    if ( v12 == -101 || (v12 + 3) <= 1 )
    {
      v13 = GetDlgItem(hWnd, 1087);
      if ( SendMessageW(v13, 0x100Cu, 0xFFFFFFFF, 2) == -1 )
      {
        v15 = GetDlgItem(hWnd, 40083);
        EnableWindow(v15, 0);
      }
      else
      {
        v14 = GetDlgItem(hWnd, 40083);
        EnableWindow(v14, 1);
      }
    }
    return 0;
  }
  if ( a2 != 272 )
    return 0;
  v5 = LoadIconW(ghInstance, 0x65);
  SendMessageW(hWnd, 0x80u, 0, v5);
  v6 = operator new(0x40u);
  hMem = v6;
  v35 = 0;
  if ( v6 )
    CResizer::CResizer(v6, hWnd);
  v35 = -1;
  v7 = GetDlgItem(hWnd, 1087);
  ProcPageInitList(v7, 2, &pnIDs, pnWidths, 0);
  v8 = wParam;
  v9 = GetDlgItem(hWnd, 1087);
  sub_103B490(v9, v8);
  SendMessageW(v7, 0x101Eu, 0, 0xFFFF);
  SendMessageW(v7, 0x101Eu, 1u, 0xFFFF);
  lParam.stateMask = 3;
  lParam.state = 3;
  SendMessageW(v7, 0x102Bu, 0, &lParam);
  SetFocus(v7);
  if ( nWidth )
  {
    MoveWindow(hWnd, Rect.left, Rect.top, nWidth, nHeight, 0);
  }
  else
  {
    GetCursorPos(&Point);
    v10.y = Point.y - 220;
    v10.x = Point.x - 350;
    PE_SetWindowPlacement(hWnd, v10);
  }
  ghWndThreadStack = hWnd;
  SetFocus(v7);
  ShowWindow(hWnd, 1);
  return 1;
}

//----- (01053FC0) --------------------------------------------------------
BOOL __stdcall DlgThreadStack(HWND hWnd, UINT a2, WPARAM a3, LPARAM dwNewLong)
{
  LONG v4; // edi
  HICON v5; // eax
  HWND v6; // esi
  CResizer *v7; // eax
  HWND v8; // esi
  LONG v9; // eax
  HWND v10; // eax
  HWND v11; // esi
  HWND v12; // eax
  int v14; // eax
  HWND v15; // ebx
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // ebx
  HWND v20; // eax
  HWND v21; // ebx
  int v22; // esi
  wchar_t *v23; // ebx
  HWND v24; // eax
  LRESULT v25; // eax
  void *v26; // edi
  unsigned int v27; // esi
  rsize_t v28; // esi
  LRESULT v29; // esi
  HWND v30; // edi
  int v31; // esi
  wchar_t *v32; // ebx
  HWND v33; // eax
  LRESULT v34; // eax
  unsigned int v35; // esi
  rsize_t v36; // esi
  HANDLE v37; // ecx
  HWND v38; // ebx
  HWND v39; // eax
  HWND v40; // eax
  LPCONTEXT v41; // esi
  _DWORD *v42; // eax
  HWND v43; // ebx
  void *v44; // ecx
  int v45; // edx
  bool v46; // cf
  _DWORD *v47; // esi
  int v48; // eax
  char v49; // ST28_1
  HWND v50; // edi
  int v51; // eax
  int i; // eax
  int v53; // eax
  int v54; // ebx
  signed int v55; // edi
  PULONG *v56; // esi
  void *v57; // ecx
  ULONG *v58; // eax
  LPCONTEXT v59; // ecx
  PULONG v60; // eax
  CONTEXT *v61; // ebx
  signed int v62; // esi
  void *v63; // ecx
  ULONG *v64; // eax
  HWND v65; // esi
  HWND v66; // eax
  HWND v67; // eax
  DWORD v68; // eax
  signed int v69; // esi
  unsigned int *v70; // ST20_4
  int v71; // eax
  int v72; // eax
  char v73; // ST20_1
  tagTREEVIEWLISTITEMPARAM *v74; // eax
  HWND v75; // esi
  int v76; // eax
  HWND v77; // esi
  HWND v78; // eax
  HWND v79; // esi
  HWND v80; // edi
  HWND v81; // eax
  int v82; // [esp+0h] [ebp-EC0h]
  char v83; // [esp+10h] [ebp-EB0h]
  char v84; // [esp+44h] [ebp-E7Ch]
  DWORD BytesReturned; // [esp+2A0h] [ebp-C20h]
  LVITEMW lParam; // [esp+2A4h] [ebp-C1Ch]
  UINT pnIDs; // [esp+2D8h] [ebp-BE8h]
  int v88; // [esp+2DCh] [ebp-BE4h]
  int v89; // [esp+2E0h] [ebp-BE0h]
  unsigned int v90; // [esp+2E4h] [ebp-BDCh]
  int v91; // [esp+2E8h] [ebp-BD8h]
  int v92; // [esp+2ECh] [ebp-BD4h]
  WORD pnWidths[2]; // [esp+2F0h] [ebp-BD0h]
  LVITEMW Item; // [esp+2F4h] [ebp-BCCh]
  int v95; // [esp+328h] [ebp-B98h]
  PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine; // [esp+32Ch] [ebp-B94h]
  int v97; // [esp+330h] [ebp-B90h]
  char ArgList[4]; // [esp+334h] [ebp-B8Ch]
  void *v99; // [esp+338h] [ebp-B88h]
  int v100; // [esp+33Ch] [ebp-B84h]
  int ThreadHandle; // [esp+340h] [ebp-B80h]
  LONG v102; // [esp+344h] [ebp-B7Ch]
  HWND v103; // [esp+348h] [ebp-B78h]
  int v104; // [esp+34Ch] [ebp-B74h]
  LPCONTEXT lpContext; // [esp+350h] [ebp-B70h]
  HWND v106; // [esp+354h] [ebp-B6Ch]
  HWND v107; // [esp+358h] [ebp-B68h]
  HWND hDlg; // [esp+35Ch] [ebp-B64h]
  struct _tagSTACKFRAME64 StackFrame; // [esp+360h] [ebp-B60h]
  char v110; // [esp+468h] [ebp-A58h]
  char v111; // [esp+49Ch] [ebp-A24h]
  struct tagRECT Rect; // [esp+6F8h] [ebp-7C8h]
  DWORD OutBuffer; // [esp+708h] [ebp-7B8h]
  DWORD v114; // [esp+70Ch] [ebp-7B4h]
  DWORD v115; // [esp+710h] [ebp-7B0h]
  char v116; // [esp+723h] [ebp-79Dh]
  WCHAR String; // [esp+CACh] [ebp-214h]
  int *v118; // [esp+EB0h] [ebp-10h]
  int v119; // [esp+EBCh] [ebp-4h]

  v118 = &v82;
  hDlg = hWnd;
  v4 = GetWindowLongW(hWnd, -21);
  v97 = 0;
  v102 = v4;
  v104 = 0;
  lpContext = (&v116 & 0xFFFFFFF0);
  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v106 = GetDlgItem(hWnd, 1087);
  pnIDs = 43;
  v88 = 44;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  ReadMemoryRoutine = 0;
  if ( a2 > 0x111 )
  {
    if ( a2 == 2033 )
    {
      DestroyWindow(hDlg);
      return 0;
    }
    if ( a2 != 2042 )
      return 0;
    memset(&v83, 0, 0x290u);
    if ( NtSuspendThread(v37, *(v4 + 8)) )
    {
      v38 = hDlg;
      EndDialog(hDlg, 0);
      MessageBoxW(v38, L"Error accessing thread.", L"Process Explorer", 0x10u);
      v39 = GetParent(v38);
      SetFocus(v39);
      v40 = GetDlgItem(v38, 1210);
      EnableWindow(v40, 0);
      return 0;
    }
    v41 = lpContext;
    GetThreadContext(*(v4 + 8), lpContext);
    EnterCriticalSection(&gPE_ImageItemVerifiedLock);
    *ArgList = 0;
    v103 = 0;
    v119 = 1;
    v42 = operator new(0x28u);
    v99 = v42;
    LOBYTE(v119) = 2;
    if ( v42 )
      v43 = sub_10275A0(v42);
    else
      v43 = 0;
    v107 = v43;
    LOBYTE(v119) = 1;
    v103 = v43;
    if ( sub_1028940(v43, v4) == 1 && sub_1028D10(v43, *(v4 + 4)) == 1 )
    {
      v89 = 0;
      v90 = 0;
      v91 = 0;
      v92 = 0;
      LOBYTE(v119) = 3;
      v100 = sub_102B0A0(v43, *(v4 + 4), &v89);
      if ( v100 == 1 )
      {
        v45 = 0;
        v104 = 0;
        if ( v90 > 0 )
        {
          v46 = v90 > 0;
          while ( 1 )
          {
            if ( !v46 )
              ATL::AtlThrowImpl(-2147024809);
            v47 = *(v89 + 4 * v45);
            v99 = v47;
            if ( v47 )
              (*(*v47 + 4))(v47);
            LOBYTE(v119) = 4;
            v48 = wcscmp(sub_1027F60(v47), L"0x0");
            if ( v48 )
              v48 = -(v48 < 0) | 1;
            if ( v48 )
            {
              v49 = ArgList[0];
              Item.mask = 5;
              Item.iItem = 0x7FFFFFFF;
              Item.iSubItem = 0;
              Item.stateMask = 0;
              Item.state = 0;
              ++*ArgList;
              wsprintf(&String, L"%d", v49);
              v50 = v106;
              Item.pszText = &String;
              Item.iImage = 0;
              Item.lParam = (v104 + 1);
              v51 = SendMessageW(v106, LVM_INSERTITEMW, 0, &Item);
              if ( v51 == -1 )
              {
                LOBYTE(v119) = 3;
                if ( v47 )
                  (*(*v47 + 8))(v47);
                sub_1039F20(&v89);
LABEL_77:
                v119 = -1;
                if ( v43 )
                  (*(*v43 + 8))(v43);
                return 0;
              }
              Item.mask = 1;
              Item.iItem = v51;
              Item.iSubItem = 1;
              Item.pszText = sub_1027F60(v47);
              SendMessageW(v50, LVM_SETITEMW, 0, &Item);
            }
            LOBYTE(v119) = 3;
            if ( v47 )
              (*(*v47 + 8))(v47);
            v45 = v104 + 1;
            v104 = v45;
            v46 = v45 < v90;
            if ( v45 >= v90 )
            {
              v4 = v102;
              v41 = lpContext;
              break;
            }
          }
        }
      }
      LOBYTE(v119) = 1;
      sub_1039F20(&v89);
      if ( v100 )
      {
LABEL_104:
        NtResumeThread(v44, *(v4 + 8));
        LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
        if ( !(v97 + v104) )
        {
          v77 = hDlg;
          EndDialog(hDlg, 0);
          MessageBoxW(
            0,
            L"Cannot access stack information. The stack may be swapped out, Process Explorer cannot access the support in"
             " the Windows Debugging Tools, or you previously ran an old version of Process Explorer and must reboot.",
            L"Process Explorer",
            0x10u);
          v78 = GetParent(v77);
          SetFocus(v78);
          goto LABEL_77;
        }
        v79 = v106;
        SendMessageW(v106, LVM_SETCOLUMNWIDTH, 0, 0xFFFF);
        SendMessageW(v79, LVM_SETCOLUMNWIDTH, 1u, 0xFFFF);
        lParam.stateMask = 3;
        lParam.state = 3;
        SendMessageW(v79, LVM_SETITEMSTATE, 0, &lParam);
        SetFocus(v79);
        v80 = hDlg;
        if ( gConfig.WindowPlacement[5].rcNormalPosition.right == gConfig.WindowPlacement[5].rcNormalPosition.left )
          GetWindowRect(hDlg, &Rect);
        else
          _mm_storeu_si128(&Rect, _mm_loadu_si128(&gConfig.WindowPlacement[5].rcNormalPosition));
        v81 = GetDlgItem(v80, 1210);
        EnableWindow(v81, 1);
        ghWndThreadStack = v80;
        SetFocus(v106);
        ShowWindow(v80, 1);
        v119 = -1;
        if ( v43 )
          (*(*v43 + 8))(v43);
        return 1;
      }
    }
    for ( i = 0; ; i = v95 + 1 )
    {
LABEL_67:
      v95 = i;
      if ( i >= 2 )
        goto LABEL_104;
      v97 = v104;
      v99 = v104;
      memset(v41, 0, 0x2CCu);
      v53 = v95;
      v41->ContextFlags = 65537;
      if ( v53 )
      {
        if ( v53 != 1 )
          goto LABEL_87;
        v61 = lpContext;
        v62 = 0;
        do
        {
          if ( GetThreadContext(*(v4 + 8), v61) )
            break;
          NtResumeThread(v63, *(v4 + 8));
          CloseHandle(*(v4 + 8));
          v64 = Fake_OpenThread(*(v4 + 4), 0x4Au);
          *(v4 + 8) = v64;
          if ( !v64 )
            break;
          NtSuspendThread(&ThreadHandle, v64);
          ++v62;
        }
        while ( v62 < 2 );
        v41 = lpContext;
        ReadMemoryRoutine = 0;
      }
      else
      {
        v54 = v102;
        v55 = 0;
        v56 = (v102 + 8);
        do
        {
          if ( DeviceIoControl(ghDriverHandle, 0x83350028, v56, 4u, &OutBuffer, 0xCu, &BytesReturned, 0) )
            break;
          NtResumeThread(v57, *v56);
          CloseHandle(*v56);
          v58 = Fake_OpenThread(*(v54 + 4), 2u);
          *v56 = v58;
          if ( !v58 )
            break;
          NtSuspendThread(&ThreadHandle, v58);
          Sleep(0x64u);
          ++v55;
        }
        while ( v55 < 2 );
        v59 = lpContext;
        v4 = v102;
        ReadMemoryRoutine = sub_1050640;
        lpContext->Eip = OutBuffer;
        v59->Esp = v114;
        v59->Ebp = v115;
        v60 = *v56;
        v41 = v59;
        dword_10CAB88 = v60;
      }
      v43 = v107;
LABEL_87:
      if ( !*(v4 + 8) )
      {
        v65 = hDlg;
        EndDialog(hDlg, 0);
        MessageBoxW(0, L"Error opening thread for stack trace.", L"Process Explorer", 0x10u);
        v66 = GetParent(v65);
        SetFocus(v66);
        v67 = GetDlgItem(v65, 1210);
        EnableWindow(v67, 0);
        goto LABEL_77;
      }
      memset(&StackFrame, 0, 0x108u);
      v44 = v41->Eip;
      StackFrame.AddrStack.Offset = v41->Esp;
      v68 = v41->Ebp;
      v69 = 0;
      StackFrame.AddrPC.Offset = v44;
      StackFrame.AddrPC.Mode = 3;
      StackFrame.AddrStack.Mode = 3;
      StackFrame.AddrFrame.Offset = v68;
      StackFrame.AddrFrame.Mode = 3;
      StackFrame.AddrBStore.Offset = v68;
      StackFrame.AddrBStore.Mode = 3;
      while ( 1 )
      {
        v100 = v69;
        v104 = v69;
        if ( v69 >= 100 )
          break;
        v70 = *(v4 + 16);
        LOBYTE(v119) = 5;
        sub_103DD60(1, v44, &v110, *(v4 + 12), 0, 0, *(v4 + 20), v70);
        if ( !StackWalk64(
                0x14Cu,
                *(v4 + 12),
                *(v4 + 8),
                &StackFrame,
                lpContext,
                ReadMemoryRoutine,
                SymFunctionTableAccess64,
                SymGetModuleBase64,
                0) )
        {
          v41 = lpContext;
          i = v95 + 1;
          LOBYTE(v119) = 1;
          goto LABEL_67;
        }
        v44 = StackFrame.AddrPC.Offset;
        v119 = 1;
        if ( !StackFrame.AddrPC.Offset )
          break;
        sub_103DD60(1, StackFrame.AddrPC.Offset, &v110, *(v4 + 12), 0, 0, *(v4 + 20), *(v4 + 16));
        v71 = wcscmp(&v111, L"0x0");
        if ( v71 )
          v71 = -(v71 < 0) | 1;
        if ( v71 )
        {
          v72 = wcscmp(&v111, &v84);
          if ( v72 )
            v72 = -(v72 < 0) | 1;
          if ( v72 )
          {
            v73 = ArgList[0];
            Item.mask = 5;
            Item.iItem = 0x7FFFFFFF;
            Item.iSubItem = 0;
            Item.stateMask = 0;
            Item.state = 0;
            ++*ArgList;
            wsprintf(&String, L"%d", v73);
            Item.pszText = &String;
            v74 = (v69 + 1);
            Item.iImage = 0;
            v75 = v106;
            Item.lParam = v74;
            v76 = SendMessageW(v106, 0x104Du, 0, &Item);
            if ( v76 == -1 )
              goto LABEL_77;
            Item.iItem = v76;
            Item.pszText = &v111;
            Item.mask = 1;
            Item.iSubItem = 1;
            SendMessageW(v75, 0x104Cu, 0, &Item);
            qmemcpy(&v83, &v110, 0x290u);
            v4 = v102;
            v69 = v104;
          }
        }
        v44 = StackFrame.AddrPC.Offset;
        ++v69;
      }
      v41 = lpContext;
    }
  }
  if ( a2 == 273 )
  {
    if ( a3 > 40083 )
    {
      if ( a3 != 40084 )
      {
        if ( a3 == 40631 )
        {
          v29 = 0;
          v30 = GetDlgItem(hDlg, 1087);
          if ( SendMessageW(v30, 0x1004u, 0, 0) > 0 )
          {
            do
            {
              lParam.stateMask = 2;
              lParam.state = 2;
              SendMessageW(v30, 0x102Bu, v29++, &lParam);
            }
            while ( v29 < SendMessageW(v30, 0x1004u, 0, 0) );
          }
        }
        return 0;
      }
      v31 = 0;
      Item.iItem = -1;
      v32 = 0;
      v33 = GetDlgItem(hDlg, 1087);
      v107 = v33;
      v34 = SendMessageW(v33, 0x100Cu, Item.iItem, 0);
      v26 = v107;
      for ( Item.iItem = v34; v34 != -1; Item.iItem = v34 )
      {
        lParam.iSubItem = 1;
        lParam.pszText = &String;
        lParam.cchTextMax = 256;
        SendMessageW(v107, 0x1073u, v34, &lParam);
        v35 = wcslen(&String) + v31 + 2;
        v103 = v35;
        if ( v32 )
        {
          v26 = GlobalReAlloc(v26, 2 * v35 + 2, 0);
          v32 = GlobalLock(v26);
        }
        else
        {
          v26 = GlobalAlloc(0x2002u, 2 * v35 + 2);
          v32 = GlobalLock(v26);
          *v32 = 0;
        }
        v36 = v35 + 1;
        wcscat_s(v32, v36, &String);
        wcscat_s(v32, v36, L"\r\n");
        GlobalUnlock(v26);
        v34 = SendMessageW(v107, 0x100Cu, Item.iItem, 0);
        v31 = v103;
      }
    }
    else
    {
      if ( a3 != 40083 )
      {
        if ( a3 > 0 )
        {
          if ( a3 <= 2 )
          {
            v21 = hDlg;
            GetWindowPlacement(hDlg, &gConfig.WindowPlacement[5]);
            ghWndThreadStack = 0;
            EndDialog(v21, 0);
          }
          else if ( a3 == 1210 )
          {
            v19 = hDlg;
            v20 = GetDlgItem(hDlg, 1210);
            EnableWindow(v20, 0);
            SendMessageW(v106, 0x1009u, 0, 0);
            SendMessageW(v19, 0x7FAu, 0, 0);
          }
        }
        return 0;
      }
      v22 = 0;
      Item.iItem = -1;
      v23 = 0;
      v24 = GetDlgItem(hDlg, 1087);
      v107 = v24;
      v25 = SendMessageW(v24, 0x100Cu, Item.iItem, 2);
      v26 = v107;
      for ( Item.iItem = v25; v25 != -1; Item.iItem = v25 )
      {
        lParam.iSubItem = 1;
        lParam.pszText = &String;
        lParam.cchTextMax = 256;
        SendMessageW(v107, 0x1073u, v25, &lParam);
        v27 = wcslen(&String) + v22 + 2;
        v103 = v27;
        if ( v23 )
        {
          v26 = GlobalReAlloc(v26, 2 * v27 + 2, 0);
          v23 = GlobalLock(v26);
        }
        else
        {
          v26 = GlobalAlloc(0x2002u, 2 * v27 + 2);
          v23 = GlobalLock(v26);
          *v23 = 0;
        }
        v28 = v27 + 1;
        wcscat_s(v23, v28, &String);
        wcscat_s(v23, v28, L"\r\n");
        GlobalUnlock(v26);
        v25 = SendMessageW(v107, 0x100Cu, Item.iItem, 2);
        v22 = v103;
      }
    }
    if ( OpenClipboard(hDlg) )
    {
      EmptyClipboard();
      SetClipboardData(0xDu, v26);
      CloseClipboard();
    }
    SetFocus(v107);
    return 0;
  }
  if ( a2 == 78 )
  {
    v14 = *(dwNewLong + 8);
    if ( v14 == -101 || (v14 + 3) <= 1 )
    {
      v15 = hDlg;
      v16 = GetDlgItem(hDlg, 1087);
      if ( SendMessageW(v16, 0x100Cu, 0xFFFFFFFF, 2) == -1 )
      {
        v18 = GetDlgItem(v15, 40083);
        EnableWindow(v18, 0);
      }
      else
      {
        v17 = GetDlgItem(v15, 40083);
        EnableWindow(v17, 1);
      }
    }
    return 0;
  }
  if ( a2 != 272 )
    return 0;
  v5 = LoadIconW(ghInstance, 0x65);
  v6 = hDlg;
  SendMessageW(hDlg, 0x80u, 0, v5);
  v7 = operator new(0x40u);
  v99 = v7;
  v119 = 0;
  if ( v7 )
    CResizer::CResizer(v7, v6);
  v8 = v106;
  v9 = GetWindowLongW(v106, -16);
  SetWindowLongW(v8, -16, v9 & 0xFFFFFFFD | 1);
  SetWindowLongW(v106, -21, 2);
  SendMessageW(v106, 0x1036u, 0x4020u, 16416);
  v10 = SendMessageW(v106, 0x104Eu, 0, 0);
  CTreeList::InitToolTips(v10);
  gOldListWndProc = SetWindowLongW(v106, -4, Proxy_ListCtrlWndProc);
  SendMessageW(v106, 0x30u, ghConfigFont, 0);
  InitListHeader(v106, &pnIDs, pnWidths, 2);
  SetWindowLongW(hDlg, -21, dwNewLong);
  wsprintf(&String, L"Stack for thread %d", *(dwNewLong + 4));
  v11 = hDlg;
  SetWindowTextW(hDlg, &String);
  gConfig.WindowPlacement[5].showCmd = 5;
  SetWindowPlacement(v11, &gConfig.WindowPlacement[5]);
  if ( GetCurrentProcessId() == *dwNewLong )
  {
    EndDialog(v11, 0);
    MessageBoxW(0, L"Thread stack not available for Process Explorer.", L"Process Explorer", 0x10u);
    v12 = GetParent(v11);
    SetFocus(v12);
    return 0;
  }
  SendMessageW(v11, 0x7FAu, 0, 0);
  return 1;
}
// 10A5208: using guessed type wchar_t a0x0[4];
// 10CAB88: using guessed type int dword_10CAB88;

//----- (01055020) --------------------------------------------------------
void __noreturn ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException()
{
  ATL::AtlThrowImpl(E_OUTOFMEMORY);
}

//----- (01055030) --------------------------------------------------------
BOOL __stdcall EnumChildrenWindows(HWND hWnd, LPARAM dwPId)
{
  HWND v2; // eax
  DWORD dwProcessId; // [esp+8h] [ebp-208h]
  WCHAR szText[256]; // [esp+Ch] [ebp-204h]

  if ( GetParent(hWnd) )
  {
    if ( !GetParent(hWnd) )
      return 1;
    v2 = GetParent(hWnd);
    if ( IsWindowVisible(v2) )
      return 1;
  }
  if ( !IsWindowVisible(hWnd) )
    return 1;
  GetWindowThreadProcessId(hWnd, &dwProcessId);
  if ( dwProcessId != dwPId )
    return 1;
  GetWindowTextW(hWnd, szText, 256);
  if ( !szText[0] )
    return 1;
  if ( gbWindowTextFlags )
  {
    *gpszWindowText = 0;
  }
  else
  {
    gbWindowTextFlags = 1;
    wcsncpy_s(gpszWindowText, gdwWindowTextLength, szText, 0xFFFFFFFF);
    ghMainWndBackup = hWnd;
  }
  return 0;
}
// 10DBA5C: using guessed type char gbWindowTextFlags;

//----- (01055140) --------------------------------------------------------
signed int __usercall sub_1055140@<eax>(int a1@<ebx>, int a2, _BYTE *a3)
{
  HANDLE v3; // eax
  int v5; // [esp+4h] [ebp-234h]
  PROCESSENTRY32W pe; // [esp+8h] [ebp-230h]

  pe.dwSize = 0;
  memset(&pe.cntUsage, 0, 0x228u);
  if ( hSnapshot != -1 )
    CloseHandle(hSnapshot);
  v3 = CreateToolhelp32Snapshot_0(TH32CS_SNAPPROCESS, 0);
  hSnapshot = v3;
  if ( v3 == -1 )
    return 0;
  pe.dwSize = 556;
  if ( !Process32FirstW_0(v3, &pe) )
    return 0;
  do
  {
    if ( a3 && *a3 == 1 )
      break;
    sub_104F870(a1, a2, a3, 0, pe.th32ProcessID, 0, pe.szExeFile, &v5);
  }
  while ( Process32NextW_0(hSnapshot, &pe) );
  return 1;
}

//----- (01055230) --------------------------------------------------------
errno_t __cdecl wcsncpy_s(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return wcsncpy_s(Dst, SizeInWords, *(a3 + 4), *a3 >> 1);
}

//----- (01055250) --------------------------------------------------------
int __cdecl sub_1055250(int *a1)
{
  int v1; // eax
  __m128i v2; // xmm0
  int v3; // ST0C_4
  _DWORD *v4; // ecx
  int v5; // eax
  unsigned __int8 v6; // cf
  int result; // eax
  int v8; // eax
  int v9; // [esp+0h] [ebp-70h]
  __int128 v10; // [esp+8h] [ebp-68h]
  __int128 v11; // [esp+18h] [ebp-58h]
  __int128 v12; // [esp+28h] [ebp-48h]
  __int128 v13; // [esp+38h] [ebp-38h]
  __int128 v14; // [esp+48h] [ebp-28h]
  __int128 v15; // [esp+58h] [ebp-18h]
  _DWORD *v16; // [esp+68h] [ebp-8h]

  *&v13 = 0i64;
  *(&v13 + 1) = 0i64;
  *&v14 = 0i64;
  v1 = *a1;
  *(&v14 + 1) = 0i64;
  *&v15 = 0i64;
  *(&v15 + 1) = 0i64;
  v2 = _mm_loadu_si128(&v13);
  v9 = v1;
  v3 = byte_10DBC00;
  _mm_storeu_si128(&v10, v2);
  _mm_storeu_si128(&v11, _mm_loadu_si128(&v14));
  _mm_storeu_si128(&v12, _mm_loadu_si128(&v15));
  sub_1039C10(&gMap2, &v16, 0, &v9, v3);
  v4 = v16;
  if ( a1[2] == 10 )
  {
    v8 = a1[8];
    v6 = __CFADD__(v8, v16[6]);
    v16[6] += v8;
    result = a1[9];
    v4[7] += result + v6;
    v6 = __CFADD__(v4[12]++, 1);
    v4[13] += v6;
  }
  else
  {
    v5 = a1[8];
    if ( a1[2] == 11 )
    {
      v6 = __CFADD__(v5, v16[8]);
      v16[8] += v5;
      result = a1[9];
      v4[9] += result + v6;
      v6 = __CFADD__(v4[14]++, 1);
      v4[15] += v6;
    }
    else
    {
      v6 = __CFADD__(v5, v16[10]);
      v16[10] += v5;
      result = a1[9];
      v4[11] += result + v6;
      v6 = __CFADD__(v4[16]++, 1);
      v4[17] += v6;
    }
  }
  return result;
}
// 10DBC00: using guessed type char byte_10DBC00;

//----- (01055310) --------------------------------------------------------
int __cdecl sub_1055310(int *a1)
{
  int v1; // eax
  __m128i v2; // xmm0
  int v3; // ST0C_4
  _DWORD *v4; // ecx
  int result; // eax
  unsigned __int8 v6; // cf
  int v7; // [esp+0h] [ebp-70h]
  __int128 v8; // [esp+8h] [ebp-68h]
  __int128 v9; // [esp+18h] [ebp-58h]
  __int128 v10; // [esp+28h] [ebp-48h]
  __int128 v11; // [esp+38h] [ebp-38h]
  __int128 v12; // [esp+48h] [ebp-28h]
  __int128 v13; // [esp+58h] [ebp-18h]
  _DWORD *v14; // [esp+68h] [ebp-8h]

  *&v11 = 0i64;
  *(&v11 + 1) = 0i64;
  *&v12 = 0i64;
  v1 = *a1;
  *(&v12 + 1) = 0i64;
  *&v13 = 0i64;
  *(&v13 + 1) = 0i64;
  v2 = _mm_loadu_si128(&v11);
  v7 = v1;
  v3 = byte_10DBC00;
  _mm_storeu_si128(&v8, v2);
  _mm_storeu_si128(&v9, _mm_loadu_si128(&v12));
  _mm_storeu_si128(&v10, _mm_loadu_si128(&v13));
  sub_1039C10(&gMap3, &v14, 0, &v7, v3);
  v4 = v14;
  if ( a1[2] == 2 )
  {
    result = a1[7];
    v6 = __CFADD__(result, v14[8]);
    v14[8] += result;
    v4[9] += v6;
    ++*(v4 + 7);
  }
  else
  {
    result = a1[7];
    if ( a1[2] == 3 )
    {
      v6 = __CFADD__(result, v14[6]);
      v14[6] += result;
      v4[7] += v6;
      ++*(v4 + 6);
    }
    else
    {
      v6 = __CFADD__(result, v14[10]);
      v14[10] += result;
      v4[11] += v6;
      ++*(v4 + 8);
    }
  }
  return result;
}
// 10DBC00: using guessed type char byte_10DBC00;

//----- (010553D0) --------------------------------------------------------
void __cdecl PE_ImageItemVerified_Create(wchar_t *a1, int a2, wchar_t *a3)
{
  PE_ImageItemVerified *v3; // esi

  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  if ( !PE_ImageItemVerified_Find(a1) )
  {
    v3 = malloc(0x10u);
    v3->pszText1 = _wcsdup(a1);
    v3->dwValue = a2;
    v3->pszTitle = _wcsdup(a3);
    v3->pNext = gpPE_ImageItemVerified;
    gpPE_ImageItemVerified = v3;
  }
  LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
}

//----- (01055440) --------------------------------------------------------
_DWORD *sub_1055440()
{
  _DWORD *result; // eax

  result = operator new(0x48u);
  JUMPOUT(result, 0, std::_Xbad_alloc);
  *result = result;
  if ( result != -4 )
    result[1] = result;
  if ( result != -8 )
    result[2] = result;
  *(result + 6) = 257;
  return result;
}

//----- (01055470) --------------------------------------------------------
_DWORD *__thiscall sub_1055470(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edx

  v1 = this;
  v2 = operator new(0x48u);
  if ( !v2 )
    std::_Xbad_alloc();
  *v2 = *v1;
  if ( v2 != -4 )
    v2[1] = *v1;
  if ( v2 != -8 )
    v2[2] = *v1;
  return v2;
}

//----- (010554B0) --------------------------------------------------------
std_Tree_node_for_tagKeyName *__thiscall sub_10554B0(std__tree *this, std__Tree_node *_Node)
{
  std__Tree_node_For__bstr_t *_Right; // esi
  std_Tree_node_for_tagKeyName *result; // eax

  _Right = _Node->_Right;
  _Node->_Right = _Right->_Left;
  if ( !_Right->_Left->_IsNil )
    _Right->_Left->_Parent = _Node;
  _Right->_Parent = _Node->_Parent;
  result = this->_Mypair._Myval2._Myhead;
  if ( _Node == this->_Mypair._Myval2._Myhead->_Parent )
  {
    result->_Parent = _Right;
    _Right->_Left = _Node;
    _Node->_Parent = _Right;
  }
  else
  {
    result = _Node->_Parent;
    if ( _Node == result->_Left )
      result->_Left = _Right;
    else
      result->_Right = _Right;
    _Right->_Left = _Node;
    _Node->_Parent = _Right;
  }
  return result;
}

//----- (01055510) --------------------------------------------------------
int **__thiscall sub_1055510(CSystemProcessInfoMap *this, int **a2, CSystemProcessInfoMapNode *a3, int *a4)
{
  CSystemProcessInfoMapNode *v4; // eax
  CSystemProcessInfoMap *v5; // edi
  int **result; // eax
  CSystemProcessInfoMapNode *v7; // ecx
  CSystemProcessInfoMapNode *i; // edx
  CSystemProcessInfoMapNode *v9; // eax
  int a2a; // [esp+8h] [ebp-4h]

  v4 = a3;
  v5 = this;
  if ( a3 != this->_Header->_Left || a4 != this->_Header )
  {
    for ( ; a3 != a4; v4 = a3 )
    {
      v7 = v4;
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
          v9 = i->baseclass._Left;
          if ( !i->baseclass._Left->baseclass._isnil )
          {
            do
            {
              i = v9;
              v9 = v9->baseclass._Left;
            }
            while ( !v9->baseclass._isnil );
          }
        }
        a3 = i;
      }
      sub_10555B0(v5, &a2a, v7);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_102E620(this);
    result = a2;
    *a2 = v5->_Header->_Left;
  }
  return result;
}

//----- (010555B0) --------------------------------------------------------
_DWORD *__thiscall sub_10555B0(CSystemProcessInfoMap *this, _DWORD *a2, _DWORD *a3)
{
  std__tree *v3; // ebx
  std_Tree_node_for_tagKeyName *v4; // ecx
  std_Tree_node_for_tagKeyName *v5; // edi
  std__Tree_node *v6; // edx
  std__Tree_node *v7; // esi
  std_Tree_node_for_tagKeyName *v8; // eax
  std__Tree_node *v9; // edx
  std__Tree_node *v10; // eax
  std_Tree_node_for_tagKeyName *v11; // eax
  std_Tree_node_for_tagKeyName *i; // edx
  std_Tree_node_for_tagKeyName **v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  unsigned int v16; // eax
  _DWORD *v17; // ecx
  _DWORD *result; // eax
  std_Tree_node_for_tagKeyName *v19; // [esp+10h] [ebp-4h]

  v3 = this;
  v19 = a3;
  sub_FF4CE0(&a3);
  v4 = v19;
  if ( v19->_Left->_IsNil )
  {
    v5 = v19->_Right;
  }
  else if ( v19->_Right->_IsNil )
  {
    v5 = v19->_Left;
  }
  else
  {
    v6 = a3;
    v5 = a3[2];
    if ( a3 != v19 )
    {
      v19->_Left->_Parent = a3;
      v6->_Left = v19->_Left;
      if ( v6 == v19->_Right )
      {
        v7 = v6;
      }
      else
      {
        v7 = v6->_Parent;
        if ( !v5->_IsNil )
          v5->_Parent = v7;
        v7->_Left = v5;
        v6->_Right = v19->_Right;
        v19->_Right->_Parent = v6;
      }
      if ( v3->_Mypair._Myval2._Myhead->_Parent == v19 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = v6;
      }
      else
      {
        v13 = &v19->_Parent->_Left;
        if ( *v13 == v19 )
          *v13 = v6;
        else
          v13[2] = v6;
      }
      v6->_Parent = v19->_Parent;
      v14 = v6->_Color;
      v6->_Color = v19->_Color;
      v19->_Color = v14;
      v4 = v19;
      goto LABEL_37;
    }
  }
  v7 = v19->_Parent;
  if ( !v5->_IsNil )
    v5->_Parent = v7;
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
    if ( v5->_IsNil )
    {
      v9 = v7;
    }
    else
    {
      v10 = v5->_Left;
      v9 = v5;
      if ( !v5->_Left->_IsNil )
      {
        do
        {
          v9 = v10;
          v10 = v10->_Left;
        }
        while ( !v10->_IsNil );
      }
      v8 = v3->_Mypair._Myval2._Myhead;
    }
    v8->_Left = v9;
  }
  if ( v3->_Mypair._Myval2._Myhead->_Right == v19 )
  {
    if ( v5->_IsNil )
    {
      v3->_Mypair._Myval2._Myhead->_Right = v7;
    }
    else
    {
      v11 = v5->_Right;
      for ( i = v5; !v11->_IsNil; v11 = v11->_Right )
        i = v11;
      v3->_Mypair._Myval2._Myhead->_Right = i;
    }
  }
LABEL_37:
  if ( v4->_Color != 1 )
    goto LABEL_62;
  if ( v5 == v3->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->_Color == 1 )
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
  v5->_Color = 1;
LABEL_62:
  j__free(v4);
  v16 = v3->_Mypair._Myval2._Mysize;
  v17 = a3;
  if ( v16 )
    v3->_Mypair._Myval2._Mysize = v16 - 1;
  result = a2;
  *a2 = v17;
  return result;
}

//----- (01055820) --------------------------------------------------------
_DWORD *__thiscall sub_1055820(int *this, _DWORD *a2, unsigned int *a3)
{
  int v3; // esi
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // eax
  _DWORD *result; // eax
  int v8; // [esp+14h] [ebp+Ch]

  v3 = *this;
  v4 = v3;
  v5 = *(v3 + 4);
  while ( !*(v5 + 13) )
  {
    if ( *(v5 + 16) >= *a3 )
    {
      v4 = v5;
      v5 = *v5;
    }
    else
    {
      v5 = *(v5 + 8);
    }
  }
  if ( v4 == v3 || (v6 = *a3, v8 = v4, v6 < *(v4 + 16)) )
    v8 = v3;
  result = a2;
  *a2 = v8;
  return result;
}

//----- (01055870) --------------------------------------------------------
HANDLE __cdecl Fake_OpenThread(HANDLE ThreadHandle, ACCESS_MASK DesiredAccess)
{
  int v2; // eax
  HANDLE v3; // ecx
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+0h] [ebp-20h]
  struct _CLIENT_ID ClientId; // [esp+18h] [ebp-8h]

  ClientId.UniqueThread = ThreadHandle;
  ClientId.UniqueProcess = 0;
  ObjectAttributes.Length = 24;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 0;
  ObjectAttributes.ObjectName = 0;
  ObjectAttributes.SecurityDescriptor = 0;
  ObjectAttributes.SecurityQualityOfService = 0;
  v2 = NtOpenThread(&ThreadHandle, DesiredAccess, &ObjectAttributes, &ClientId);
  v3 = 0;
  if ( !v2 )
    v3 = ThreadHandle;
  return v3;
}

//----- (010558D0) --------------------------------------------------------
char __usercall sub_10558D0@<al>(signed int a1@<ebx>, HWND hWnd, LVITEMW *pItem, LPARAM pItemParam, int a5)
{
  DWORD v5; // ecx
  int v6; // eax
  signed int v7; // ecx
  int v8; // eax
  HWND v9; // ecx
  int v10; // eax
  int v11; // eax
  WPARAM v12; // eax
  char result; // al
  bool v14; // zf
  LVITEMW StateItem; // [esp+Ch] [ebp-50h]
  LVFINDINFOW FindInfo; // [esp+40h] [ebp-1Ch]
  int v17; // [esp+58h] [ebp-4h]
  int v18; // [esp+70h] [ebp+14h]

  LOBYTE(a1) = 0;
  v17 = a1;
  *(pItemParam + 8) = gdwRefreshCount;
  *(pItemParam + 12) = *(pItemParam + 16);
  *a5 = 0;
  v5 = gConfig.dwHighlightDuration;
  if ( gConfig.dwRefreshRate )
    v5 = gConfig.dwRefreshRate;
  v6 = *(pItemParam + 16);
  *(pItemParam + 20) += v5;
  v7 = *(pItemParam + 20);
  if ( v6 == 2 )
  {
    a1 = 0;
    if ( v7 >= gConfig.dwHighlightDuration )
      a1 = 1;
    v17 = a1;
  }
  if ( v6 == 4 )
  {
LABEL_31:
    --pItem->iItem;
    return a1;
  }
  if ( v6 == 1 )
  {
    if ( v7 >= gConfig.dwHighlightDuration )
    {
      v8 = *(pItemParam + 4);
      v9 = hWnd;
      *(pItemParam + 16) = 4;
      v18 = v8;
      if ( pItem->iItem != -1
        || (FindInfo.lParam = pItem->lParam,
            FindInfo.flags = 1,
            v10 = SendMessageW(hWnd, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo),
            v9 = hWnd,
            pItem->iItem = v10,
            v10 != -1) )
      {
        SendMessageW(v9, WM_SETREDRAW, 0, 0);
        LOBYTE(v17) = 1;
        pItem->mask = 8;
        SendMessageW(hWnd, LVM_GETITEMW, 0, pItem);
        SendMessageW(hWnd, LVM_DELETEITEM, pItem->iItem, 0);
        if ( pItem->state & 2 )
        {
          v11 = pItem->iItem;
          StateItem.stateMask = 3;
          StateItem.state = 3;
          if ( v11 )
            v12 = v11 - 1;
          else
            v12 = 0;
          SendMessageW(hWnd, LVM_SETITEMSTATE, v12, &StateItem);
        }
      }
      if ( !v18 )
      {
        SendMessageW(ghMainWnd, 0x7EFu, 0, pItemParam);
        --pItem->iItem;
        return 1;
      }
      LOBYTE(a1) = v17;
    }
    goto LABEL_31;
  }
  if ( v6 != 2 || v7 >= gConfig.dwHighlightDuration )
  {
    *(pItemParam + 24) = 0;
    *(pItemParam + 16) = 0;
  }
  else
  {
    *(pItemParam + 24) = 1;
    *(pItemParam + 28) = v7;
  }
  if ( *(pItemParam + 4) != 2 )
  {
    *(pItemParam + 16) = 1;
    *(pItemParam + 20) = 0;
    *a5 = 1;
    result = a1;
    --pItem->iItem;
    return result;
  }
  if ( PE_QueryObjectInfo(pItem->lParam) )
    goto LABEL_31;
  v14 = hWnd == ghWndHandlesListCtrl;
  *(pItemParam + 16) = 1;
  if ( v14 )
    LOBYTE(a1) = 1;
  *(pItemParam + 20) = 0;
  *a5 = 1;
  result = a1;
  --pItem->iItem;
  return result;
}
// 10CA11C: using guessed type int gdwRefreshCount;

//----- (01055AB0) --------------------------------------------------------
BOOL __cdecl CDriver::Control(DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize, LPVOID lpOutBuffer, DWORD nOutBufferSize)
{
  DWORD v5; // ecx
  DWORD BytesReturned; // [esp+0h] [ebp-4h]

  BytesReturned = v5;
  return DeviceIoControl(
           ghDriverHandle,
           dwIoControlCode,
           lpInBuffer,
           nInBufferSize,
           lpOutBuffer,
           nOutBufferSize,
           &BytesReturned,
           0) != 0;
}

//----- (01055AE0) --------------------------------------------------------
int __stdcall CGraphWnd::ChartWndProc(HWND hWnd, UINT Msg, WPARAM wParam, int lParam)
{
  CGraphData *pGraphData; // esi
  HWND hWndTooltips; // eax
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ecx
  HWND hWndTooltips_1; // ebx
  UINT uMsg; // eax
  int v9; // eax
  int v10; // eax
  HDC hDC; // ebx
  int uID; // eax
  int result; // eax
  int v14; // eax
  HWND hWndTooltip; // esi
  int v16; // eax
  HWND v17; // eax
  wchar_t *v18; // esi
  __int32 v19; // eax
  int v20; // eax
  HWND v21; // eax
  __int16 v22; // ah^1
  struct tagPOINT Point; // [esp+14h] [ebp-890h]
  LPARAM lParam_2; // [esp+1Ch] [ebp-888h]
  HWND v25; // [esp+20h] [ebp-884h]
  wchar_t Src; // [esp+24h] [ebp-880h]
  __int16 v27; // [esp+824h] [ebp-80h]
  __int16 v28; // [esp+826h] [ebp-7Eh]
  CGraphData *v29; // [esp+828h] [ebp-7Ch]
  tagTOOLINFOW ToolInfo; // [esp+830h] [ebp-74h]
  int v31; // [esp+85Ch] [ebp-48h]
  struct tagPAINTSTRUCT Paint; // [esp+860h] [ebp-44h]

  lParam_2 = lParam;
  pGraphData = GetWindowLongW(hWnd, GWLP_USERDATA);
  hWndTooltips = GetPropW(hWnd, L"Balloon");
  SendMessageW = ::SendMessageW;
  hWndTooltips_1 = hWndTooltips;
  uMsg = Msg;
  if ( hWndTooltips_1 )
  {
    if ( Msg != WM_LBUTTONDOWN )
    {
      uMsg = Msg;
      if ( Msg - 512 <= 13 )
      {
        ToolInfo.rect.right = Msg;
        ToolInfo.rect.bottom = wParam;
        ToolInfo.hinst = lParam_2;
        ToolInfo.rect.top = hWnd;
        *&ToolInfo.lpszText = 0i64;
        v31 = 0;
        ::SendMessageW(hWndTooltips_1, TTM_RELAYEVENT, 0, &ToolInfo.rect.top);
        uMsg = Msg;
        SendMessageW = ::SendMessageW;
      }
    }
  }
  if ( uMsg > WM_NOTIFY )
  {
    v19 = uMsg - WM_MOUSEMOVE;
    if ( v19 )
    {
      v20 = v19 - 1;
      if ( v20 )
      {
        if ( v20 == 511 )
        {
          if ( !LOBYTE(pGraphData->field_854) )
            SendMessageW(hWndTooltips_1, TTM_UPDATE, 0, 0);
          InvalidateRect(hWnd, 0, 0);
          UpdateWindow(hWnd);
        }
      }
      else
      {
        KillTimer(hWnd, 0);
        LOBYTE(pGraphData->field_854) = LOBYTE(pGraphData->field_854) == 0;
        v21 = pGraphData->m_Item[1].nItemID;
        if ( v21 )
          ::SendMessageW(v21, RB_GETBANDBORDERS, 0, 0);
        if ( GetParent(hWnd) == ghWndReBar )
        {
          if ( hWnd == ghWndCPUGraph )
          {
            gConfig.dwDefaultSysInfoPage = 1;
          }
          else if ( hWnd == ghWndMemoryGraph || hWnd == ghWndPhysicalMemoryGraph )
          {
            gConfig.dwDefaultSysInfoPage = 2;
          }
          else
          {
            gConfig.dwDefaultSysInfoPage = (hWnd == ghWndGPUGraph) + 3;
          }
          Command_SystemInformation();
        }
      }
      return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
    }
    if ( hWndTooltips_1 )
    {
      v22 = HIWORD(lParam_2);
      if ( lParam_2 == pGraphData->field_858 )
      {
        if ( SHIWORD(lParam_2) == pGraphData->field_85C )
          return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
        v22 = HIWORD(lParam_2);
      }
      pGraphData->field_858 = lParam_2;
      pGraphData->field_85C = v22;
      SendMessageW(hWndTooltips_1, TTM_UPDATE, 0, 0);
      LOBYTE(pGraphData->field_854) = 0;
    }
    return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
  }
  if ( uMsg == WM_NOTIFY )
  {
    if ( *lParam_2 == hWndTooltips_1 )
    {
      v16 = *(lParam_2 + 8);
      if ( v16 == -530 )
      {
        GetCursorPos(&Point);
        if ( WindowFromPoint(Point) == hWnd && (v17 = GetParent(hWnd), sub_1012A70(v17)) )
        {
          v25 = hWnd;
          v29 = pGraphData;
          GetCursorPos(&Point);
          ScreenToClient(hWnd, &Point);
          v27 = Point.x;
          v28 = Point.y;
          sub_10124C0(&v25);
          if ( Src )
          {
            v18 = &pGraphData->m_Item[1].dwValue;
            wcscpy_s(v18, 0x400u, &Src);
            *(lParam_2 + 12) = v18;
          }
        }
        else
        {
          ::SendMessageW(hWndTooltips_1, 0x41Cu, 0, 0);
        }
      }
      else if ( v16 == -521 )
      {
        return 0;
      }
    }
    return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
  }
  v9 = uMsg - 1;
  if ( v9 )
  {
    v10 = v9 - 4;
    if ( v10 )
    {
      if ( v10 == 10 )
      {
        hDC = BeginPaint(hWnd, &Paint);
        GetClientRect(hWnd, &ToolInfo.hinst);
        uID = GetDlgCtrlID(hWnd);
        if ( uID == IDC_SYSINFO_IO_STATIC_IO_CHART
          || uID == IDC_SYSINFO_SUM_STATIC_SYSTEM_COMMIT_CHART
          || uID == IDC_SYSINFO_MEMORY_STATIC_PHYSICAL_MEMORY_CHART
          || uID == IDC_SYSINFO_IOETW_STATIC_NETWORK_CHART
          || uID == IDC_SYSINFO_IOETW_STATIC_DISK_CHART
          || uID == IDC_SYSINFO_GPU_STATIC_GPU_DEDICATED_MEMORY_CHART
          || uID == IDC_SYSINFO_GPU_STATIC_GPU_SYSTEM_MEMORY_CHART
          || uID == 2603
          || uID >= IDC_GRAPH_IN_REBAR && uID < 2500
          || uID >= IDC_SYSINFO_GPU_STATIC_GPU_USAGE_CHART && uID < 2600 )
        {
          GraphData_DrawChart(pGraphData, hDC, &ToolInfo.hinst, 0xFFFFFFFF, 0, 0.0);
          EndPaint(hWnd, &Paint);
          result = 0;
        }
        else
        {
          GraphData_DrawGraph(pGraphData, hDC, &ToolInfo.hinst);
          EndPaint(hWnd, &Paint);
          result = 0;
        }
        return result;
      }
    }
    else
    {
      ToolInfo.cbSize = 48;
      ToolInfo.uFlags = 0;
      _mm_storeu_si128(&ToolInfo.hwnd, 0i64);
      _mm_storeu_si128(&ToolInfo.rect.right, 0i64);
      ToolInfo.hwnd = hWnd;
      *&ToolInfo.lParam = 0i64;
      GetClientRect(hWnd, &ToolInfo.rect);
      ::SendMessageW(hWndTooltips_1, TTM_NEWTOOLRECTW, 0, &ToolInfo);
    }
    return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
  }
  SetWindowLongW(hWnd, GWLP_USERDATA, *lParam_2);
  v14 = GetDlgCtrlID(hWnd);
  if ( v14 == 1159
    || v14 == 1330
    || v14 == 1333
    || v14 == 1335
    || v14 == 1338
    || v14 == 2601
    || v14 == 2602
    || v14 == 2603
    || v14 >= 2000 && v14 < 2500
    || (v14 - 2501) <= 0x62 )
  {
    hWndTooltip = CreateWindowExW(WS_EX_TOPMOST, L"tooltips_class32", 0, 0x80000033, 0, 0, 0, 0, hWnd, 0, ghInstance, 0);
    ToolInfo.cbSize = 48;
    ToolInfo.uFlags = 0x100;
    _mm_storeu_si128(&ToolInfo.hwnd, 0i64);
    _mm_storeu_si128(&ToolInfo.rect.right, 0i64);
    ToolInfo.hwnd = hWnd;
    *&ToolInfo.lParam = 0i64;
    ToolInfo.lpszText = -1;
    ::SendMessageW(hWndTooltip, TTM_ADDTOOLW, 0, &ToolInfo);
    SetPropW(hWnd, L"Balloon", hWndTooltip);
    CTreeList::InitToolTips(hWndTooltip);
  }
  return 1;
}

//----- (01056020) --------------------------------------------------------
char __cdecl sub_1056020(tagTREEVIEWLISTITEMPARAM *pItem)
{
  tagTREEVIEWLISTITEMPARAM *v1; // eax
  tagTREEVIEWLISTITEMPARAM *v2; // esi
  tagTREEVIEWLISTITEMPARAM *v3; // edx
  bool v4; // zf
  int v5; // edi
  tagTREEVIEWLISTITEMPARAM *v6; // ecx
  char i; // dl

  LOBYTE(v1) = SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  v2 = pItem;
  v3 = pItem;
  if ( pItem )
  {
    do
    {
      v4 = v3->dwProcessId == 0;
      v3->field_30 = 0;
      v3->pItemParam = 0;
      if ( !v4 )
      {
        v1 = pItem;
        while ( v1->dwProcessId != v3->InheritedFromUniqueProcessId || *&v1->CreateTime > *&v3->CreateTime )
        {
          v1 = v1->m_Prev;
          if ( !v1 )
            goto LABEL_9;
        }
        v3->pItemParam = v1;
      }
LABEL_9:
      v3 = v3->m_Prev;
    }
    while ( v3 );
    if ( pItem )
    {
      do
      {
        v5 = 0;
        v6 = v2->pItemParam;
        for ( i = (v2->dwStyle >> 1) & 1; v6; ++v5 )
        {
          LOBYTE(v1) = -((v6->dwStyle & 4) != 0);
          ++v6->field_30;
          v6 = v6->pItemParam;
          i &= v1;
        }
        v2->field_50 = v5;
        if ( (!i || v2->dwStyle & 1 && gConfig.byte_14012ADFE) && v2->field_2C != -1 )
        {
          if ( !i )
            v2->dwStyle &= 0xFFFFFFFD;
          LOBYTE(v1) = sub_1018570(ghWndTreeListView, v2);
        }
        v2 = v2->m_Prev;
      }
      while ( v2 );
    }
  }
  return v1;
}

//----- (01056110) --------------------------------------------------------
int *__cdecl FillHandleListParam(HWND hWndList, tagHANDLELISTITEMPARAM *pListParam)
{
  signed int v2; // edi
  IAtlStringMgr *v3; // ecx
  int v4; // eax
  HINSTANCE ghInstance; // ecx
  CString v6; // esi
  signed int nPage; // eax
  const PROPSHEETPAGEW *v8; // eax
  int nType; // edi
  int v10; // ecx
  tagHANDLELISTITEMPARAM *v11; // ecx
  __int16 v12; // ax
  int fIsObjDirectory; // ecx
  signed int nPages; // edi
  bool v15; // zf
  HWND v16; // edi
  const wchar_t *v17; // eax
  CStringData *v18; // esi
  int *result; // eax
  PE_PROPSHEETPAGEW Pages[2]; // [esp+Ch] [ebp-4C8h]
  PROPSHEETHEADERW PropSheet; // [esp+74h] [ebp-460h]
  int v22[2]; // [esp+A8h] [ebp-42Ch]
  char *v23; // [esp+B0h] [ebp-424h]
  HWND hWnd; // [esp+B4h] [ebp-420h]
  CString strName; // [esp+B8h] [ebp-41Ch]
  CObjSecurity *pObjSecurity; // [esp+BCh] [ebp-418h]
  WCHAR szCaption[520]; // [esp+C0h] [ebp-414h]

  hWnd = hWndList;
  v2 = 0;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(E_FAIL);
  v4 = (v3->vtptr->GetNilData)();
  ghInstance = ::ghInstance;
  v6.pszData = (v4 + 16);
  strName.pszData = (v4 + 16);
  if ( pListParam[10].dwValue )
  {
    Pages[0].u2.hIcon = 0;
    Pages[0].pfnCallback = 0;
    v2 = 1;
    Pages[0].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[0].dwFlags = PSP_USETITLE;
    Pages[0].hInstance = ::ghInstance;
    Pages[0].u.pszTemplate = L"HANDLEINFO";
    Pages[0].pfnDlgProc = PropHandleInfo;
    Pages[0].pszTitle = L"Details";
    Pages[0].lParam = pListParam;
  }
  if ( *CreateSecurityPage )
  {
    if ( _wcsicmp(&pListParam[14], L"ObjDirectory") )
    {
      if ( _wcsicmp(&pListParam[14], L"Device") )
      {
        if ( _wcsicmp(&pListParam[14], L"Process") )
        {
          if ( _wcsicmp(&pListParam[14], L"Service") )
            nType = _wcsicmp(&pListParam[14], L"Thread") != 0 ? 1 : 5;
          else
            nType = 4;
        }
        else
        {
          nType = 3;
        }
      }
      else
      {
        nType = 2;
      }
    }
    else
    {
      nType = 0;
    }
    if ( pListParam == -184 )
    {
      v10 = 0;
    }
    else
    {
      v11 = pListParam + 46;
      v23 = &pListParam[46].dwValue + 2;
      do
      {
        v12 = v11->dwValue;
        v11 = (v11 + 2);
      }
      while ( v12 );
      v10 = (v11 - v23) >> 1;
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString(&strName, &pListParam[46], v10);
    fIsObjDirectory = wcscmp(&pListParam[14], L"ObjDirectory");
    if ( fIsObjDirectory )
      fIsObjDirectory = -(fIsObjDirectory < 0) | 1;
    v6.pszData = strName.pszData;
    CObjSecurity::Create(pListParam, strName.pszData, &pObjSecurity, nType, fIsObjDirectory == 0);
    nPages = 0;
    PropSheet.dwFlags = PSH_NOAPPLYNOW;
    if ( pListParam[10].dwValue )
    {
      v22[0] = CreatePropertySheetPageW(Pages);
      nPages = 1;
    }
    v22[nPages] = CreateSecurityPage(pObjSecurity);
    PropSheet.nPages = nPages + 1;
    v8 = v22;
  }
  else
  {
    nPage = v2;
    PropSheet.dwFlags = 0x88;
    Pages[nPage].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[nPage].dwFlags = PSP_USETITLE;
    Pages[nPage].hInstance = ghInstance;
    Pages[nPage].u.pszTemplate = L"SECURITY";
    Pages[nPage].pfnDlgProc = PropSecurity;
    Pages[nPage].pszTitle = L"Security";
    Pages[nPage].lParam = pListParam;
    Pages[nPage].pfnCallback = 0;
    PropSheet.nPages = v2 + 1;
    v8 = Pages;
  }
  v15 = pListParam[10].dwValue == 0;
  v16 = hWnd;
  PropSheet.ppsp = v8;
  PropSheet.hInstance = ghMainInstance;
  v17 = L"Properties";
  if ( v15 )
    v17 = L"Permissions";
  PropSheet.dwSize = sizeof(PROPSHEETHEADERW);
  PropSheet.hwndParent = hWnd;
  MakeHandlePropSheetCaption(szCaption, L"%s %s", &pListParam[46], v17);
  PropSheet.nStartPage = 0;
  PropSheet.hwndParent = v16;
  PropSheet.pszCaption = szCaption;
  PropSheet.pfnCallback = 0;
  PropertySheetW(&PropSheet);
  if ( *CreateSecurityPage )
    CObjSecurity::~CObjSecurity(pObjSecurity);
  v18 = (v6.pszData - 16);
  result = &v18->nRefs;
  if ( _InterlockedDecrement(&v18->nRefs) <= 0 )
    result = (v18->pStringMgr->vtptr->Free)(v18);
  return result;
}
// 10A2AE8: using guessed type wchar_t aSecurity_1[9];
// 10A5140: using guessed type wchar_t aHandleinfo[11];
// 10A5158: using guessed type wchar_t aDetails[8];
// 10A5168: using guessed type wchar_t aSecurity_0[9];
// 10A51A8: using guessed type wchar_t aProperties_0[11];
// 10A51C0: using guessed type wchar_t aPermissions[12];
// 1056110: using guessed type int var_42C[2];

//----- (01056450) --------------------------------------------------------
HANDLE __cdecl CTreeList::FillTreeViewParam(tagTREEVIEWLISTITEMPARAM *pInfo)
{
  InterlockedIncrement(&pInfo->nRefCount);
  return _beginthread(CTreeList::BackendFillTreeViewParamThreadProc, 0, pInfo);
}

//----- (01056480) --------------------------------------------------------
BOOL __cdecl PropertiesThreadProc(HACCEL hAccTable)
{
  HCURSOR v1; // eax
  tagPropItem *propItem; // eax
  tagPropItem *PropItem; // esi
  HWND hDlgPropSheet; // ebx
  BOOL result; // eax
  int v6; // edi
  int v7; // eax
  HWND v8; // esi
  struct tagMSG msg; // [esp+8h] [ebp-20h]
  tagPropItem *v10; // [esp+24h] [ebp-4h]
  HACCEL hAccTablea; // [esp+30h] [ebp+8h]

  InterlockedIncrement(&gnRefCount);
  v1 = LoadCursorW(0, IDC_APPSTARTING);
  SetCursor(v1);
  propItem = malloc(sizeof(tagPropItem));
  PropItem = propItem;
  v10 = propItem;
  memset(propItem, 0, sizeof(tagPropItem));
  PropItem->pListItem = hAccTable;
  hDlgPropSheet = CreateDialogParamW(ghMainInstance, L"PROCPROPSHEET", ghMainWnd, ProcPropSheet, PropItem);
  hAccTablea = LoadAcceleratorsW(ghMainInstance, L"DLLPROPERTIES");
  for ( result = GetMessageW(&msg, 0, 0, 0); result; result = GetMessageW(&msg, 0, 0, 0) )
  {
    v6 = PropItem + sizeof(PROPPAGEDATA) * PropItem->nTabIndex;
    v7 = *(v6 + 8);
    if ( v7 && TranslateAcceleratorW(v7, hAccTablea, &msg) )
      continue;
    v8 = GetPropW(hDlgPropSheet, L"FindWindow");
    if ( !v8 )
    {
LABEL_8:
      if ( !IsDialogMessageW(*(v6 + 8), &msg) && !IsDialogMessageW(hDlgPropSheet, &msg) )
      {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
      }
      goto LABEL_11;
    }
    if ( IsDialogMessageW(v8, &msg) )
    {
      if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
        goto LABEL_11;
    }
    else if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
    {
      goto LABEL_8;
    }
    PostMessageW(v8, WM_COMMAND, IDC_DLG_DLLINFO_EDIT_COMPANY, 0);
    SetPropW(hDlgPropSheet, L"FindWindow", 0);
LABEL_11:
    PropItem = v10;
  }
  return result;
}

//----- (01056600) --------------------------------------------------------
HANDLE CDriver::Close()
{
  HANDLE result; // eax

  result = ghDriverHandle;
  if ( ghDriverHandle != INVALID_HANDLE_VALUE )
    result = CloseHandle(ghDriverHandle);
  return result;
}

//----- (01056620) --------------------------------------------------------
bool GetProcessDEPStatus()
{
  DWORD v1; // eax
  HANDLE v2; // esi
  HANDLE v3; // eax
  int v4; // edi
  int ProcessInformation; // [esp+0h] [ebp-8h]
  ULONG ReturnLength; // [esp+4h] [ebp-4h]

  if ( gdwVersion >= 3 || gdwVersion >= 2 )
    return 1;
  if ( gdwVersion >= 1 )
    return 0;
  v1 = GetCurrentProcessId();
  v2 = OpenProcess(0x400u, 0, v1);
  if ( !v2 )
    return 0;
  v3 = GetCurrentProcess();
  v4 = NtQueryInformationProcess(v3, ProcessExecuteFlags, &ProcessInformation, 4u, &ReturnLength);
  CloseHandle(v2);
  return !v4 || v4 == -1073741811;
}
// 1056620: using guessed type bool __cdecl GetProcessDEPStatus();
// 10C4E54: using guessed type int gdwVersion;

//----- (010566B0) --------------------------------------------------------
BOOL __stdcall DlgFind(HWND hDlg, UINT uMsg, WPARAM wParamIn, LPARAM lParamIn)
{
  BOOL result; // eax
  HWND v5; // ecx
  char v6; // al
  HWND v7; // ST08_4
  tagTREEVIEWLISTITEMPARAM *v8; // eax
  void *v9; // eax
  HWND v10; // ST08_4
  tagTREEVIEWLISTITEMPARAM *v11; // eax
  int v12; // eax
  int v13; // edx
  DLLLISTITEMPARAM *v14; // eax
  LPARAM v15; // eax
  CResizer *v16; // eax
  HWND v17; // eax
  LONG v18; // eax
  HWND v19; // eax
  struct _IMAGELIST *v20; // edi
  LONG v21; // eax
  HCURSOR v22; // esi
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  WPARAM v32; // esi
  int v33; // ST14_4
  int v34; // eax
  char nItemMatched; // al
  LPARAM v36; // [esp+Ch] [ebp-2A4h]
  int v37; // [esp+18h] [ebp-298h]
  int v38; // [esp+1Ch] [ebp-294h]
  tagLVITEMW lParam; // [esp+40h] [ebp-270h]
  LPARAM v40; // [esp+74h] [ebp-23Ch]
  void *v41; // [esp+7Ch] [ebp-234h]
  HCURSOR hCursor; // [esp+8Ch] [ebp-224h]
  tagTREEVIEWLISTITEMPARAM *v43; // [esp+90h] [ebp-220h]
  int nIDs[4]; // [esp+94h] [ebp-21Ch]
  WCHAR String[256]; // [esp+A4h] [ebp-20Ch]
  int nWidths; // [esp+2A4h] [ebp-Ch]
  int v47; // [esp+2A8h] [ebp-8h]

  hCursor = hDlg;
  if ( !(dword_10E54C8 & 1) )
  {
    dword_10E54C8 |= 1u;
    gwWidthsOfListInFindDlg[0] = MulDiv(75, gLogPixelSize.x, 96);
    gwWidthsOfListInFindDlg[1] = MulDiv(-1, gLogPixelSize.x, 96);
    gwWidthsOfListInFindDlg[2] = MulDiv(50, gLogPixelSize.x, 96);
    gwWidthsOfListInFindDlg[3] = MulDiv(150, gLogPixelSize.x, 96);
  }
  lParam.mask = 0;
  memset(&lParam.iItem, 0, 0x30u);
  _mm_storeu_si128(nIDs, _mm_load_si128(&xmmword_10A6C30));
  if ( uMsg > WM_INITDIALOG )
  {
    if ( uMsg > WM_CHOOSEFONT_SETLOGFONT )
    {
      if ( uMsg == WM_MSG_7F1 )
      {
        ghFindDlg = 0;
        ghWndListInFindDlg = 0;
        GetWindowRect(hDlg, &gRectFindDlg);
        gnWidthFindDlg = gRectFindDlg.right - gRectFindDlg.left;
        gnHeightFindDlg = gRectFindDlg.bottom - gRectFindDlg.top;
      }
      return 0;
    }
    if ( uMsg == WM_CHOOSEFONT_SETLOGFONT )
    {
      SendMessageW(ghWndListInFindDlg, LVM_SORTITEMS, gnColumnSortedInFindDlg, FindDlg_SortCallback);
      nItemMatched = SendMessageW(ghWndListInFindDlg, LVM_GETITEMCOUNT, 0, 0);
      wsprintf(String, L"%d matching items.", nItemMatched);
      SetDlgItemTextW(hDlg, IDC_FINDDLG_STATIC_RESULT, String);
      return 1;
    }
    if ( uMsg != WM_COMMAND )
    {
      if ( uMsg == 0x464 )
      {
        CloseHandle(ghThreadHandleInFindDlg);
        ghThreadHandleInFindDlg = 0;
        v23 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_SEARCH);
        EnableWindow(v23, 1);
        v24 = GetDlgItem(hDlg, IDC_FINDDLG_EDIT);
        EnableWindow(v24, 1);
        v25 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_CANCEL);
        EnableWindow(v25, 0);
        SendMessageW(hDlg, WM_CHOOSEFONT_SETLOGFONT, 0, 0);
        v26 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_SEARCH);
        SetFocus(v26);
        return 1;
      }
      return 0;
    }
    if ( wParamIn == IDC_FINDDLG_BUTTON_CANCEL )
    {
      gbSearching = 1;
      return 0;
    }
    if ( wParamIn == 2 )
    {
      v31 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_CANCEL);
      if ( IsWindowEnabled(v31) )
      {
        SendMessageW(hDlg, WM_COMMAND, IDC_FINDDLG_BUTTON_CANCEL, 0);
        return 1;
      }
    }
    else if ( wParamIn != 1 )
    {
      if ( wParamIn == IDC_FINDDLG_BUTTON_SEARCH )
      {
        dword_10E54D0 = -1;
        GetDlgItemTextW(hDlg, IDC_FINDDLG_EDIT, gszStringToFindLast, 256);
        if ( wcslen(gszStringToFindLast) )
        {
          CTreeList::InitHeaderColumn(
            ghWndListInFindDlg,
            gnColumnSortedInFindDlg,
            gnColumnSortedInFindDlg,
            byte_10BE8B0);
          v27 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_SEARCH);
          EnableWindow(v27, 0);
          v28 = GetDlgItem(hDlg, IDC_FINDDLG_EDIT);
          EnableWindow(v28, 0);
          v29 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_CANCEL);
          EnableWindow(v29, 1);
          v30 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_CANCEL);
          SetFocus(v30);
          if ( ghThreadHandleInFindDlg )
          {
            WaitForSingleObject(ghThreadHandleInFindDlg, 0xFFFFFFFF);
            CloseHandle(ghThreadHandleInFindDlg);
          }
          gbSearching = 0;
          SendMessageW(ghWndListInFindDlg, LVM_DELETEALLITEMS, 0, 0);
          SetDlgItemTextW(hDlg, IDC_FINDDLG_STATIC_RESULT, L"Searching...");
          ghThreadHandleInFindDlg = _beginthreadex(0, 0, FindDlg_SearchThreadProc, &gbSearching, 0, 0);
        }
      }
      return 0;
    }
    ShowWindow(hDlg, 0);
    gbSearching = 1;
    SendMessageW(ghWndListInFindDlg, LVM_DELETEALLITEMS, 0, 0);
    v32 = 0;
    do
    {
      v33 = gLogPixelSize.x;
      v34 = SendMessageW(ghWndListInFindDlg, LVM_GETCOLUMNWIDTH, v32, 0);
      gwWidthsOfListInFindDlg[v32++] = MulDiv(v34, 96, v33);
    }
    while ( v32 < 4 );
    wcscpy_s(gszStringToFind, 256u, gszStringToFindLast);
    return 1;
  }
  if ( uMsg != WM_INITDIALOG )
  {
    switch ( uMsg )
    {
      case WM_CLOSE:
        SendMessageW(hDlg, WM_COMMAND, 2u, 0);
        return 1;
      case WM_SHOWWINDOW:
        if ( wParamIn == 1 )
        {
          SetDlgItemTextW(hDlg, IDC_FINDDLG_STATIC_RESULT, &gszNullString);
          CTreeList::InitListCtrl(ghWndListInFindDlg, ghConfigFont);
          SendMessageW(ghWndListInFindDlg, 0x1009u, 0, 0);
          SetDlgItemTextW(hDlg, IDC_FINDDLG_STATIC_SUBSTRING, L"Handle or DLL substring:");
          gdwRefreshRateLast = gConfig.dwRefreshRate;
          gConfig.dwRefreshRate = 0;
          SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, L"Paused");
          return 1;
        }
        gConfig.dwRefreshRate = gdwRefreshRateLast;
        SetEvent(ghRefreshEventHandle);
        if ( !gdwRefreshRateLast )
          return 1;
        SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, &gszNullString);
        return 1;
      case WM_DRAWITEM:
        CMainWnd::DrawList(lParamIn);
        return 0;
      case WM_MEASUREITEM:
        return CMainWnd::HandleMeasureItem(hDlg, uMsg, wParamIn, lParamIn);
      case 0x4Eu:
        switch ( *(lParamIn + 8) )
        {
          case 0xFFFFFF94:
            v5 = *(lParamIn + 16);
            if ( v5 == gnColumnSortedInFindDlg )
            {
              v6 = byte_10BE8B0 == 0;
              byte_10BE8B0 = byte_10BE8B0 == 0;
            }
            else
            {
              v6 = byte_10BE8B0;
            }
            CTreeList::InitHeaderColumn(*lParamIn, gnColumnSortedInFindDlg, v5, v6);
            gnColumnSortedInFindDlg = *(lParamIn + 16);
            SendMessageW(*lParamIn, 0x1030u, gnColumnSortedInFindDlg, FindDlg_SortCallback);
            return 0;
          case 0xFFFFFF99:
            lParam.iItem = *(lParamIn + 12);
            v7 = *lParamIn;
            lParam.iSubItem = 0;
            lParam.mask = 4;
            SendMessageW(v7, 0x104Bu, 0, &lParam);
            v8 = lParam.lParam;
            if ( lParam.lParam->nRefCount )
            {
              free(lParam.lParam->nRefCount);
              v8 = lParam.lParam;
            }
            v9 = v8->field_B4;
            if ( v9 )
              free(v9);
            return 0;
          case 0xFFFFFF9B:
          case 0xFFFFFFFD:
          case 0xFFFFFFFE:
            if ( dword_10E54D0 == SendMessageW(*lParamIn, LVM_GETNEXTITEM, 0xFFFFFFFF, 2) )
              return 0;
            dword_10E54D0 = SendMessageW(*lParamIn, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( dword_10E54D0 == -1 )
              return 0;
            hCursor = SetCursor(::hCursor);
            v10 = *lParamIn;
            lParam.iItem = dword_10E54D0;
            lParam.iSubItem = 0;
            lParam.mask = 4;
            if ( SendMessageW(v10, LVM_GETITEMW, 0, &lParam) != 1 )
              goto LABEL_41;
            v11 = gpTreeViewListItemParam;
            v43 = lParam.lParam;
            if ( !gpTreeViewListItemParam )
              goto LABEL_27;
            while ( v11->dwProcessId != lParam.lParam->field_A8 )
            {
              v11 = v11->m_Prev;
              if ( !v11 )
              {
LABEL_27:
                MessageBoxW(
                  hDlg,
                  L"The selected process is not in the displayed process list.",
                  L"Process Explorer",
                  0x30u);
                return 0;
              }
            }
            v41 = v11;
            v40 = 1;
            lParam.iItem = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, &v40);
            v38 = 3;
            v37 = 3;
            SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, lParam.iItem, &v36);
            SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, lParam.iItem, 0);
            gdwProcessIdSelected = v43->field_A8;
            if ( !gConfig.bShowLowerPane )
              Command_ShowLowerPane(0);
            v12 = v43;
            if ( v43->field_B0 )
            {
              if ( gConfig.bShowDllView )
              {
                Command_ShowHandlesPane(0);
                v12 = v43;
              }
              CMainWnd::RefreshHandlesView(hDlg, ghWndHandlesListCtrl, *(v12 + 168), 0);
              SendMessageW(ghMainWnd, 0x7E8u, 0x66u, 0);
            }
            else
            {
              if ( !gConfig.bShowDllView )
              {
                Command_ShowDllsPane(0);
                v12 = v43;
              }
              CMainWnd::RefreshDllsView(hDlg, ghWndDllsListCtrl, *(v12 + 168), 0);
              SendMessageW(ghMainWnd, 0x7E8u, 0x68u, 0);
            }
            v13 = v43->field_B0;
            if ( !v13 )
            {
              v14 = gpDllListItemParamHeader;
              if ( gpDllListItemParamHeader )
              {
                while ( v14->m_LoadAddress != v43->field_AC )
                {
                  v14 = v14->m_Prev;
                  if ( !v14 )
                    goto LABEL_41;
                }
                v41 = v14;
                v40 = 1;
                lParam.iItem = SendMessageW(ghWndDllsListCtrl, 0x1053u, 0xFFFFFFFF, &v40);
                v38 = 3;
                v37 = 3;
                SendMessageW(ghWndDllsListCtrl, 0x102Bu, lParam.iItem, &v36);
                SendMessageW(ghWndDllsListCtrl, 0x1013u, lParam.iItem, 0);
                if ( *(lParamIn + 8) == -3 )
                {
                  SetFocus(ghWndDllsListCtrl);
                  PostMessageW(hDlg, 0x111u, 2u, 0);
                  SetCursor(hCursor);
                  return 0;
                }
              }
              goto LABEL_41;
            }
            v15 = dword_10C539C;
            if ( !dword_10C539C )
              goto LABEL_41;
            while ( *(v15 + 44) != v13 )
            {
              v15 = *(v15 + 4280);
              if ( !v15 )
              {
                SetCursor(hCursor);
                return 0;
              }
            }
            v41 = v15;
            v40 = 1;
            lParam.iItem = SendMessageW(ghWndHandlesListCtrl, 0x1053u, 0xFFFFFFFF, &v40);
            v38 = 3;
            v37 = 3;
            SendMessageW(ghWndHandlesListCtrl, 0x102Bu, lParam.iItem, &v36);
            SendMessageW(ghWndHandlesListCtrl, 0x1013u, lParam.iItem, 0);
            if ( *(lParamIn + 8) != -3 )
            {
LABEL_41:
              SetCursor(hCursor);
              return 0;
            }
            PostMessageW(hDlg, 0x111u, 2u, 0);
            SetFocus(ghWndHandlesListCtrl);
            SetCursor(hCursor);
            break;
          default:
            return 0;
        }
        break;
      default:
        return 0;
    }
    return 0;
  }
  v16 = operator new(0x40u);
  if ( v16 )
    CResizer::CResizer(v16, hDlg);
  ghMainIcon = LoadIconW(ghInstance, 0x65);
  SendMessageW(hDlg, WM_SETICON, 0, ghMainIcon);
  v17 = GetDlgItem(hDlg, 1001);
  ghWndListInFindDlg = v17;
  v18 = GetWindowLongW(v17, -16);
  SetWindowLongW(ghWndListInFindDlg, GWL_STYLE, v18 & -3u | LVS_REPORT);
  SetWindowLongW(ghWndListInFindDlg, GWL_USERDATA, 3);
  SendMessageW(ghWndListInFindDlg, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 0x4020);
  v19 = SendMessageW(ghWndListInFindDlg, LVM_GETTOOLTIPS, 0, 0);
  CTreeList::InitToolTips(v19);
  gOldListWndProc = SetWindowLongW(ghWndListInFindDlg, GWLP_WNDPROC, Proxy_ListCtrlWndProc);
  SendMessageW(ghWndListInFindDlg, WM_SETFONT, ghConfigFont, 0);
  v20 = ImageList_Create(16, 16, 1u, 256, 256);
  ghMainIcon = LoadIconW(ghInstance, 0xCB);
  ImageList_ReplaceIcon(v20, -1, ghMainIcon);
  ghMainIcon = LoadIconW(ghInstance, 0x71);
  ImageList_ReplaceIcon(v20, -1, ghMainIcon);
  v21 = GetWindowLongW(ghWndListInFindDlg, -16);
  SetWindowLongW(ghWndListInFindDlg, -16, v21 | 0x40);
  SendMessageW(ghWndListInFindDlg, 0x1003u, 1u, v20);
  if ( gwWidthsOfListInFindDlg[1] == -1 )
    gwWidthsOfListInFindDlg[1] = MulDiv(40, gLogPixelSize.x, 96);
  nWidths = *gwWidthsOfListInFindDlg;
  v47 = *&gwWidthsOfListInFindDlg[2];
  InitListHeader(ghWndListInFindDlg, nIDs, &nWidths, 4);
  SendMessageW(ghWndListInFindDlg, LVM_SETCOLUMNWIDTH, 3u, 65534);
  v22 = hCursor;
  SetDlgItemTextW(hCursor, 1002, gszStringToFind);
  if ( gnWidthFindDlg )
  {
    MoveWindow(v22, gRectFindDlg.left, gRectFindDlg.top, gnWidthFindDlg, gnHeightFindDlg, 0);
    ShowWindow(v22, 1);
    result = 1;
  }
  else
  {
    if ( gConfig.WindowPlacement[1].rcNormalPosition.right )
      SetWindowPlacement(v22, &gConfig.WindowPlacement[1]);
    ShowWindow(v22, 1);
    result = 1;
  }
  return result;
}
// 103BBC0: using guessed type int __stdcall FindDlg_SortCallback(int, int, int);
// 10A0D80: using guessed type wchar_t aPaused[7];
// 10A6C30: using guessed type __int128 xmmword_10A6C30;
// 10BE8B0: using guessed type char byte_10BE8B0;
// 10E54C0: using guessed type __int16 gwWidthsOfListInFindDlg[4];
// 10E54C8: using guessed type int dword_10E54C8;
// 10E54D0: using guessed type int dword_10E54D0;
// 10E54D4: using guessed type int gdwRefreshRateLast;
// 10E54F0: using guessed type int ghMainIcon;
// 10E54F4: using guessed type char gbSearching;
// 10E5720: using guessed type int gnStatusBarItemCount;
