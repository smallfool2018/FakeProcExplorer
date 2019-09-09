char __usercall CTreeList::InitTreeList@<al > (HWND hWndListCtrl, char flags)
{
	int v2; // ebp
	double v3; // st7
	void *v4; // esp
	signed int v5; // ecx
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfoLast; // ecx
	int nSystemProcessInfoLengthLast; // edx
	std__Tree_node *Tree_node_8; // esi
	int v9; // edi
	FILETIME TimeRet; // rax
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_11; // eax
	unsigned int v12; // ecx
	DWORD dwNumberOfProcessors; // edx
	signed int nProcessorIndex; // esi
	int nIndex; // edi
	DWORD v16; // ecx
	DWORD v17; // edx
	LONG v18; // edx
	unsigned __int64 v19; // kr20_8
	float v20; // xmm0_4
	float v21; // xmm0_4
	double v22; // xmm1_8
	float v23; // xmm0_4
	CGraphData *v24; // eax
	float v25; // xmm0_4
	float v26; // xmm0_4
	double v27; // xmm1_8
	float v28; // xmm0_4
	CGraphData *v29; // eax
	unsigned __int64 v30; // rax
	tagTREEVIEWLISTITEMPARAM *gTreeViewListItemParam; // esi
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_32; // edi
	int v33; // eax
	signed int dwProcessorIdx; // edx
	__m128i v35; // xmm7
	SYSTEM_INTERRUPT_INFORMATION *gpSystemInterruptInf; // ecx
	SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorIdleCycleTimeInfo_37; // edi
	LARGE_INTEGER *v38; // eax
	__m128i v39; // xmm6
	__m128i v40; // xmm4
	__m128i v41; // xmm3
	__m128i v42; // xmm5
	int v43; // ecx
	__m128i v44; // xmm0
	__m128i v45; // xmm2
	__m128i v46; // xmm1
	__m128i v47; // xmm2
	__m128i v48; // xmm1
	__m128i v49; // xmm2
	__m128i v50; // xmm0
	__m128i v51; // xmm1
	__m128i v52; // xmm0
	__m128i v53; // xmm2
	__m128i v54; // xmm0
	__m128i v55; // xmm1
	__m128i v56; // xmm5
	__m128i v57; // xmm6
	__m128i v58; // xmm3
	__m128i v59; // xmm4
	__m128i v60; // xmm5
	__m128i v61; // xmm3
	__m128i v62; // xmm4
	__m128i v63; // xmm6
	int v64; // edi
	unsigned int v65; // esi
	LARGE_INTEGER *v66; // edi
	__int64 v67; // kr28_8
	LONGLONG v68; // kr30_8
	signed __int64 v69; // kr38_8
	unsigned __int64 v70; // kr10_8
	unsigned int v71; // eax
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_72; // eax
	int v73; // eax
	int v74; // ecx
	unsigned __int8 v75; // of
	bool v76; // dl
	char v77; // al
	bool v78; // cl
	char v79; // al
	unsigned int v80; // edi
	bool v81; // dl
	char v82; // al
	bool v83; // cl
	char v84; // al
	unsigned int v85; // edi
	float v86; // xmm0_4
	float v87; // xmm0_4
	float v88; // xmm1_4
	float v89; // xmm0_4
	float v90; // xmm0_4
	unsigned int v91; // edx
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_92; // ecx
	int v93; // eax
	float v94; // xmm0_4
	float v95; // xmm0_4
	float v96; // xmm1_4
	double v97; // ST2C_8
	CGraphData *v98; // eax
	bool v99; // cl
	char v100; // al
	char v101; // al
	signed int v102; // ecx
	char v103; // al
	signed int v104; // ecx
	char v105; // al
	char v106; // cl
	char v107; // al
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_108; // eax
	int v109; // esi
	tagTREEVIEWLISTITEMPARAM **TreeViewListItemParam_110; // edi
	char v111; // al
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_112; // edi
	int v113; // eax
	int v114; // eax
	char v115; // al
	char v116; // cl
	int v117; // edi
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_118; // esi
	DWORD UniqueProcessId; // eax
	DWORD v120; // edx
	LONG v121; // esi
	unsigned __int64 v122; // kr60_8
	tagTREEVIEWLISTITEMPARAM *gTreeViewListItemParam_123; // edi
	DWORD v124; // ecx
	LONG v125; // edx
	int nItemFound; // eax
	int v127; // ecx
	char v128; // al
	unsigned int v129; // edx
	DWORD v130; // kr00_4
	DWORD v131; // kr04_4
	unsigned __int64 v132; // kr68_8
	int v133; // ecx
	int v134; // edx
	float v135; // xmm0_4
	float v136; // xmm0_4
	float v137; // xmm1_4
	double v138; // xmm0_8
	float v139; // xmm0_4
	float v140; // xmm0_4
	float v141; // xmm0_4
	float v142; // xmm0_4
	float v143; // xmm1_4
	double v144; // xmm0_8
	double v145; // xmm2_8
	__m128d v146; // xmm1
	double v147; // xmm1_8
	bool v148; // al
	char v149; // al
	double v150; // xmm0_8
	char v151; // al
	tagTREEVIEWLISTITEMPARAM **ppTreeViewListItemParam_152; // esi
	char v153; // al
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_154; // esi
	char v155; // al
	unsigned int v156; // eax
	int v157; // ecx
	LONG v158; // esi
	int v159; // edx
	_DWORD *v160; // eax
	_DWORD *v161; // ecx
	_WORD *v162; // esi
	_WORD *v163; // eax
	char v164; // al
	unsigned __int8 v165; // al
	int v166; // eax
	bool v167; // cf
	unsigned __int8 v168; // al
	unsigned __int8 v169; // al
	unsigned __int8 v170; // al
	int v171; // ecx
	char v172; // al
	unsigned __int8 v173; // al
	int v174; // esi
	int v175; // eax
	char v176; // al
	int v177; // eax
	int ArgList_16; // ST3C_4
	HMENU v179; // eax
	int v180; // ecx
	bool v181; // al
	char v182; // al
	char v183; // al
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_184; // esi
	int v185; // eax
	char v186; // al
	int v187; // eax
	char v188; // al
	int v189; // eax
	char v190; // al
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
	unsigned int v203; // ecx
	int v204; // esi
	char v205; // al
	char v206; // al
	CGraphData *pGraphData_207; // edx
	int v208; // eax
	char v209; // al
	LPARAM UniqueProcessId_2; // esi
	HWND hMainWndBackup; // esi
	int v212; // eax
	char v213; // al
	int v214; // esi
	char v215; // al
	char v216; // al
	int v217; // eax
	char v218; // al
	unsigned int v219; // ecx
	int v220; // kr08_4
	unsigned int v221; // kr0C_4
	signed __int64 v222; // rax
	float v223; // xmm0_4
	unsigned int v224; // edx
	unsigned int v225; // ecx
	float v226; // xmm0_4
	double ArgList_8; // ST34_8
	double v228; // xmm0_8
	unsigned int v229; // edx
	unsigned int v230; // ecx
	char v231; // al
	char v232; // al
	unsigned __int64 v233; // kr90_8
	signed __int64 v234; // kr98_8
	signed __int64 v235; // krA0_8
	char v236; // cl
	char v237; // dl
	signed int v238; // eax
	char v239; // al
	const WCHAR **pszText; // eax
	int dwStyle; // eax
	DWORD InheritedFromUniqueProcessId; // eax
	HANDLE UniqueProcessId_1; // eax
	DWORD pGraphData_244; // ecx
	WCHAR **ppszText_245; // eax
	WCHAR *szProcessName; // eax
	HICON hIcon; // ecx
	HICON hIcon_1; // ecx
	DWORD *pGraphData_249; // ecx
	int v250; // ecx
	unsigned int v251; // edx
	unsigned int *v252; // eax
	signed int v253; // ecx
	unsigned __int64 v254; // krA8_8
	int v255; // ecx
	ULONG v256; // eax
	int v257; // edx
	_DWORD *v258; // eax
	_DWORD *v259; // ecx
	int v260; // eax
	signed int v261; // ecx
	float v262; // xmm0_4
	float v263; // xmm0_4
	float v264; // xmm1_4
	float v265; // xmm0_4
	float v266; // xmm0_4
	double v267; // xmm0_8
	wchar_t *v268; // eax
	int dwItemStyle; // eax
	int ItemStyle_270; // eax
	tagNetCclrInfo *NetCclrInfo_271; // eax
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_272; // ecx
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_273; // edx
	wchar_t *v274; // eax
	DLLLISTITEMPARAM *TreeViewListItemParam_275; // ecx
	int v276; // eax
	signed __int64 v277; // krC0_8
	signed __int64 v278; // krC8_8
	signed int dwProcessorIndex; // esi
	LARGE_INTEGER *v280; // edx
	ULONG *v281; // edi
	LONGLONG v282; // krE0_8
	int v283; // eax
	LRESULT(__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_285; // eax
	double v286; // xmm0_8
	bool v287; // cf
	bool v288; // zf
	double v289; // xmm0_8
	unsigned int v290; // esi
	unsigned int v291; // edi
	float v292; // xmm0_4
	float v293; // xmm0_4
	bool v294; // al
	char v295; // al
	double v296; // xmm0_8
	char v297; // al
	char v298; // al
	LRESULT v299; // edi
	signed int i; // esi
	double v301; // xmm0_8
	int v302; // eax
	signed int ret; // eax
	int v304; // eax
	double ArgList; // [esp+Ch] [ebp-2740h]
	LVITEMW ItemState; // [esp+2Ch] [ebp-2720h]
	LVITEMW item; // [esp+60h] [ebp-26ECh]
	int v309; // [esp+94h] [ebp-26B8h]
	double v310; // [esp+98h] [ebp-26B4h]
	LVFINDINFOW FindInfo; // [esp+A0h] [ebp-26ACh]
	__int64 v312; // [esp+B8h] [ebp-2694h]
	double v313; // [esp+C0h] [ebp-268Ch]
	__int64 v314; // [esp+C8h] [ebp-2684h]
	__int64 v315; // [esp+D0h] [ebp-267Ch]
	int bVirtualizationEnabled; // [esp+DCh] [ebp-2670h]
	int fbUIAccess; // [esp+E0h] [ebp-266Ch]
	unsigned int v318; // [esp+E4h] [ebp-2668h]
	__int64 v319; // [esp+E8h] [ebp-2664h]
	__m128i v320; // [esp+F0h] [ebp-265Ch]
	double v321; // [esp+F8h] [ebp-2654h]
	__m128i v322; // [esp+100h] [ebp-264Ch]
	__int64 v323; // [esp+108h] [ebp-2644h]
	int cbPackageFullNameLength; // [esp+110h] [ebp-263Ch]
	int v325; // [esp+114h] [ebp-2638h]
	tagTREEVIEWLISTITEMPARAM *OutBuffer; // [esp+118h] [ebp-2634h]
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_327; // [esp+11Ch] [ebp-2630h]
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_328; // [esp+120h] [ebp-262Ch]
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_329; // [esp+124h] [ebp-2628h]
	__int64 v330; // [esp+128h] [ebp-2624h]
	float v331; // [esp+134h] [ebp-2618h]
	double v332; // [esp+138h] [ebp-2614h]
	unsigned int v333; // [esp+140h] [ebp-260Ch]
	unsigned int v334; // [esp+144h] [ebp-2608h]
	LVITEMW Item; // [esp+148h] [ebp-2604h]
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_336; // [esp+17Ch] [ebp-25D0h]
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_337; // [esp+180h] [ebp-25CCh]
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_338; // [esp+184h] [ebp-25C8h]
	__int64 v339; // [esp+188h] [ebp-25C4h]
	__int64 v340; // [esp+190h] [ebp-25BCh]
	HWND hWndListCtrl_1; // [esp+198h] [ebp-25B4h]
	unsigned int v342; // [esp+19Ch] [ebp-25B0h]
	int v343; // [esp+1A0h] [ebp-25ACh]
	unsigned int v344; // [esp+1A4h] [ebp-25A8h]
	double v345; // [esp+1A8h] [ebp-25A4h]
	char bFlagsInExtendedProcessBasicInfo; // [esp+1B7h] [ebp-2595h]
	tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_347; // [esp+1B8h] [ebp-2594h]
	ULONG *v348; // [esp+1BCh] [ebp-2590h]
	unsigned int v349; // [esp+1C0h] [ebp-258Ch]
	unsigned int v350; // [esp+1C4h] [ebp-2588h]
	unsigned int v351; // [esp+1C8h] [ebp-2584h]
	char sbQueryServiceNamesInited; // [esp+1CFh] [ebp-257Dh]
	__m128i v353; // [esp+1D0h] [ebp-257Ch]
	double v354; // [esp+1D8h] [ebp-2574h]
	LARGE_INTEGER liParam; // [esp+1E8h] [ebp-2564h]
	unsigned int v356; // [esp+1F4h] [ebp-2558h]
	tagTREEVIEWLISTITEMPARAM *pItemFound; // [esp+1F8h] [ebp-2554h]
	unsigned int v358; // [esp+1FCh] [ebp-2550h]
	unsigned int v359; // [esp+200h] [ebp-254Ch]
	unsigned int variable_360; // [esp+204h] [ebp-2548h]
	wchar_t *packageFullName; // [esp+208h] [ebp-2544h]
	int v362; // [esp+20Ch] [ebp-2540h]
	unsigned int v363; // [esp+210h] [ebp-253Ch]
	unsigned int v364; // [esp+214h] [ebp-2538h]
	unsigned __int8 v365; // [esp+21Bh] [ebp-2531h]
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // [esp+21Ch] [ebp-2530h]
	char v367; // [esp+223h] [ebp-2529h]
	tagTREEVIEWLISTITEMPARAM *ProcessHandle; // [esp+224h] [ebp-2528h]
	int v369; // [esp+228h] [ebp-2524h]
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
	unsigned int v383; // [esp+273Ch] [ebp-10h]
	int v384; // [esp+2740h] [ebp-Ch]
	int v385; // [esp+2744h] [ebp-8h]
	int v386; // [esp+2748h] [ebp-4h]
	int retaddr; // [esp+274Ch] [ebp+0h]

	v384 = v2;
	v385 = retaddr;
	v4 = alloca(10008);
	v383 = &v384 ^ __security_cookie;
	hWndListCtrl_1 = hWndListCtrl;
	fHungFlags = 0;
	v343 = 0;
	TreeViewListItemParam_327 = 0;
	szText3[0] = 0;
	TreeViewListItemParam_337 = 0;
	v332 = 0.0;
	v345 = 0.0;
	*&v339 = 0.0;
	TreeViewListItemParam_338 = 0;
	v313 = 0.0;
	v330 = 0i64;
	v323 = 0i64;
	v314 = 0i64;
	v340 = 0i64;
	liParam.QuadPart = 0i64;
	memset(&szText3[1], 0, 510u);
	v365 = 0;
	TreeViewListItemParam_336 = 0;
	v367 = 0;
	bVirtualizationEnabled = 0;
	fbUIAccess = 0;
	sbQueryServiceNamesInited = 0;
	v315 = 0i64;
	v354 = 0.0;
	PE_FlushTrace(&gProperties);
	TreeList_Item1::Reset(gTreeList_Item);
	TreeList_Item1::Reset(&gTreeList_Item[1]);
	TreeList_Item1::Reset(&gTreeList_Item[2]);
	v5 = 0;
	if (gbShowProcessTreeLast != gConfig.bShowProcessTree)
		v5 = 1;
	gbShowProcessTreeLast = gConfig.bShowProcessTree;
	v369 = v5;
	szBuffer[0] = 0;
	memset(&ItemWithSizeIs50H, 0, 0x50u);

	Tree_node_8 = gSystemProcessInfoMap._Header;
	v9 = gSystemProcessInfoMap._Size;


	pSystemProcessInfoLast = gpSystemProcessInfoLast;
	nSystemProcessInfoLengthLast = gnSystemProcessInfoLengthLast;
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
		&gSystemProcessInfoMap,
		&v354);
	
	
	gTimeQuerySystemInfo.dwLowDateTime = TimeRet.dwLowDateTime;
	gTimeQuerySystemInfo.dwHighDateTime = TimeRet.dwHighDateTime;

	v12 = (*&TimeRet - *&gTimeQuerySystemInfoLast) >> 32;
	pSystemProcessInfo_11 = (TimeRet.dwLowDateTime - gTimeQuerySystemInfoLast.dwLowDateTime);
	pSystemProcessInfo_1 = pSystemProcessInfo_11;
	
	v342 = LODWORD(v354) + gSystemProcessInfoMap._Header - Tree_node_8;
	dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
	v364 = v12;
	v344 = (*&v354 + *&gSystemProcessInfoMap - __PAIR__(v9, Tree_node_8)) >> 32;
	if (gSystemInfo.dwNumberOfProcessors <= 1 || (nProcessorIndex = 0, gSystemInfo.dwNumberOfProcessors <= 0))
	{
		v354 = v310;
	}
	else
	{
		nIndex = 0;
		do
		{
			v16 = gpSystemPerformanceInfo[nIndex].IdleTime.LowPart;
			v363 = gpSystemPerformanceInfo[nIndex].KernelTime.LowPart;
			v356 = gpSystemPerformanceInfo[nIndex].KernelTime.HighPart;
			v17 = gpSystemPerformanceInfo[nIndex].UserTime.LowPart;
			v167 = v17 < v16;
			v359 = v17 - v16;
			v358 = gpSystemPerformanceInfo[nIndex].UserTime.HighPart;
			v18 = gpSystemPerformanceInfo[nIndex].IdleTime.HighPart;
			v358 -= v167 + v18;
			v167 = __CFADD__(v363, v359);
			v359 += v363;
			v358 += v356 + v167;
			v19 = __PAIR__(v356, v363) - __PAIR__(v18, v16);
			v356 = (__PAIR__(v356, v363) - __PAIR__(v18, v16)) >> 32;
			v363 = v19;
			if (v364 | pSystemProcessInfo_1)
			{
				v20 = (__PAIR__(v358, v359) - *&gppGraphInfo[nProcessorIndex]->field_888);
				v354 = v20 * 100.0;
				v21 = __PAIR__(v364, pSystemProcessInfo_1);
				v22 = v354 / v21;
			}
			else
			{
				v22 = 0.0;
			}
			v23 = v22;
			v24 = gppGraphInfo[nProcessorIndex];
			v24->field_888 = v359;
			v24->field_88C = v358;
			v354 = v23;
			if (v364 | pSystemProcessInfo_1)
			{
				v25 = (__PAIR__(v356, v363) - *&gppGraphInfo[nProcessorIndex]->field_890);
				v321 = v25 * 100.0;
				v26 = __PAIR__(v364, pSystemProcessInfo_1);
				v27 = v321 / v26;
			}
			else
			{
				v27 = 0.0;
			}
			v28 = v27;
			v29 = gppGraphInfo[nProcessorIndex];
			v29->field_890 = v363;
			v29->field_894 = v356;
			CGraphData_Update(gppGraphInfo[nProcessorIndex], gTimeQuerySystemInfo, v354, v28, 0);
			dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
			++nProcessorIndex;
			++nIndex;
		} while (nProcessorIndex < gSystemInfo.dwNumberOfProcessors);
		pSystemProcessInfo_11 = pSystemProcessInfo_1;
		v12 = v364;
	}
	v30 = dwNumberOfProcessors * __PAIR__(v12, pSystemProcessInfo_11);
	gTreeViewListItemParam = gpTreeViewListItemParam;
	variable_360 = v30;
	v358 = HIDWORD(v323);
	v364 = HIDWORD(v30);
	TreeViewListItemParam_347 = gpTreeViewListItemParam;
	v331 = 0.0;
	v356 = v323;
	if (gpTreeViewListItemParam)
	{
		while (1)
		{
			if (gTreeViewListItemParam->InheritedFromUniqueProcessId != -1 || !gTreeViewListItemParam->dwProcessId)
				*&gTreeViewListItemParam->m_CPUUsage = 0i64;
			v288 = gTreeViewListItemParam->dwProcessId == -10;
			TreeViewListItemParam_32 = gTreeViewListItemParam->m_Prev;
			v333 = gTreeViewListItemParam->m_Prev;
			if (v288)
				break;
			v114 = gTreeViewListItemParam->dwStyle;
			if ((!(v114 & 2) || v114 & 1 && gConfig.byte_14012ADFE) && gTreeViewListItemParam->field_2C != -1)
			{
				sub_FB8570(ghWndTreeListView, gTreeViewListItemParam);
				Item.lParam = gTreeViewListItemParam;
				Item.iItem = -1;
				sub_FF58D0(&v386, hWndListCtrl_1, &Item, gTreeViewListItemParam, &fHungFlags);
				LOBYTE(v369) = 1;
			}
			else
			{
				Item.lParam = gTreeViewListItemParam;
				Item.iItem = -1;
				v115 = sub_FF58D0(&v386, hWndListCtrl_1, &Item, gTreeViewListItemParam, &fHungFlags);
				v116 = v369;
				if (v115)
					v116 = 1;
				LOBYTE(v369) = v116;
			}
			if (!fHungFlags)
				goto LABEL_98;
			v113 = v343;
		LABEL_97:
			v343 = v113 + 1;
			gTreeViewListItemParam->m_SelectedItem = TreeViewListItemParam_337;
			TreeViewListItemParam_337 = gTreeViewListItemParam;
		LABEL_98:
			TreeViewListItemParam_347 = TreeViewListItemParam_32;
			gTreeViewListItemParam = TreeViewListItemParam_32;
			if (!TreeViewListItemParam_32)
				goto LABEL_99;
		}
		v365 = 1;
		FindInfo.flags = 1;
		FindInfo.lParam = gTreeViewListItemParam;
		Item.mask = ::SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
		if (Item.iItem == -1)
		{
			v33 = gTreeViewListItemParam->dwStyle;
			if (v33 & 2)
			{
				if (!(v33 & 1) || !gConfig.byte_14012ADFE)
					sub_FB7F20(ghWndTreeListView, gTreeViewListItemParam);
			}
		}
		dwProcessorIdx = 0;
		Item.lParam = gTreeViewListItemParam;
		v323 = 0i64;
		v321 = 0.0;
		v319 = 0i64;
		v354 = 0.0;
		if (gSystemInfo.dwNumberOfProcessors <= 0)
		{
			v64 = HIDWORD(v319);
			v350 = HIDWORD(v354);
			ProcessHandle = LODWORD(v354);
			v349 = HIDWORD(v323);
			v363 = v323;
			pItemFound = HIDWORD(v321);
			v351 = LODWORD(v321);
			pSystemProcessInfo_72 = v319;
			pSystemProcessInfo_1 = v319;
		}
		else
		{
			if (gSystemInfo.dwNumberOfProcessors < 4)
			{
				v64 = HIDWORD(v319);
				v350 = HIDWORD(v354);
				ProcessHandle = LODWORD(v354);
				v349 = HIDWORD(v323);
				v363 = v323;
				pItemFound = HIDWORD(v321);
				v351 = LODWORD(v321);
				pSystemProcessInfo_1 = v319;
			}
			else
			{
				v35 = 0i64;
				v362 = gSystemInfo.dwNumberOfProcessors - gSystemInfo.dwNumberOfProcessors % 4;
				gpSystemInterruptInf = gpSystemInterruptInfo;
				pSystemProcessorIdleCycleTimeInfo_37 = gpSystemProcessorCycleTimeInfo + 2;
				v38 = &gpSystemPerformanceInfo->DpcTime;
				_mm_store_si128(&v320, 0i64);
				v39 = 0i64;
				_mm_store_si128(&v322, 0i64);
				v40 = 0i64;
				_mm_store_si128(&v353, 0i64);
				v41 = 0i64;
				v42 = 0i64;
				v43 = &gpSystemInterruptInf[1].DpcCount;
				do
				{
					v44 = _mm_cvtsi32_si128(v38[8].LowPart);
					pSystemProcessorIdleCycleTimeInfo_37 += 4;
					v45 = _mm_cvtsi32_si128(v38[2].LowPart);
					v43 += 96;
					v38 += 24;
					dwProcessorIdx += 4;
					*v46.m128i_i8 = v38[-23];
					v46.m128i_i64[1] = v38[-17].QuadPart;
					v47 = _mm_unpacklo_epi32(
						_mm_add_epi32(
							_mm_unpacklo_epi32(v45, v44),
							_mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v43 - 120)), _mm_cvtsi32_si128(*(v43 - 96)))),
						0i64);
					*v44.m128i_i8 = v38[-24];
					v44.m128i_i64[1] = v38[-18].QuadPart;
					v48 = _mm_add_epi64(v46, v44);
					v49 = _mm_add_epi64(v47, v353);
					v50 = v48;
					v51 = _mm_add_epi64(v48, v322);
					_mm_store_si128(&v320, _mm_add_epi64(v50, v320));
					*v50.m128i_i8 = pSystemProcessorIdleCycleTimeInfo_37[-6];
					v50.m128i_i64[1] = pSystemProcessorIdleCycleTimeInfo_37[-5].CycleTime;
					v35 = _mm_add_epi64(v35, v50);
					v52 = _mm_cvtsi32_si128(v38[-4].LowPart);
					_mm_store_si128(&v353, v49);
					v53 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v38[-10].LowPart), v52);
					v54 = _mm_cvtsi32_si128(*(v43 - 48));
					_mm_store_si128(&v322, v51);
					*v51.m128i_i8 = v38[-11];
					v51.m128i_i64[1] = v38[-5].QuadPart;
					v42 = _mm_add_epi64(
						v42,
						_mm_unpacklo_epi32(_mm_add_epi32(v53, _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v43 - 72)), v54)), 0i64));
					*v54.m128i_i8 = v38[-12];
					v54.m128i_i64[1] = v38[-6].QuadPart;
					v55 = _mm_add_epi64(v51, v54);
					*v54.m128i_i8 = pSystemProcessorIdleCycleTimeInfo_37[-4];
					v40 = _mm_add_epi64(v40, v55);
					v54.m128i_i64[1] = pSystemProcessorIdleCycleTimeInfo_37[-3].CycleTime;
					v41 = _mm_add_epi64(v41, v55);
					v39 = _mm_add_epi64(v39, v54);
				} while (dwProcessorIdx < v362);
				v56 = _mm_add_epi64(v42, v353);
				v57 = _mm_add_epi64(v39, v35);
				v58 = _mm_add_epi64(v41, v322);
				v59 = _mm_add_epi64(v40, v320);
				v60 = _mm_add_epi64(v56, _mm_srli_si128(v56, 8));
				v61 = _mm_add_epi64(v58, _mm_srli_si128(v58, 8));
				pSystemProcessInfo_1 = _mm_cvtsi128_si32(v60);
				v351 = _mm_cvtsi128_si32(v61);
				v62 = _mm_add_epi64(v59, _mm_srli_si128(v59, 8));
				v363 = _mm_cvtsi128_si32(v62);
				v63 = _mm_add_epi64(v57, _mm_srli_si128(v57, 8));
				ProcessHandle = _mm_cvtsi128_si32(v63);
				v64 = _mm_cvtsi128_si32(_mm_srli_si128(v60, 4));
				pItemFound = _mm_cvtsi128_si32(_mm_srli_si128(v61, 4));
				v349 = _mm_cvtsi128_si32(_mm_srli_si128(v62, 4));
				v350 = _mm_cvtsi128_si32(_mm_srli_si128(v63, 4));
			}
			v359 = v64;
			if (dwProcessorIdx < gSystemInfo.dwNumberOfProcessors)
			{
				v65 = v359;
				v66 = &gpSystemPerformanceInfo[dwProcessorIdx].InterruptTime;
				v348 = &gpSystemInterruptInfo[dwProcessorIdx].DpcCount;
				do
				{
					v67 = (pSystemProcessInfo_1 + __PAIR__(v65, *v348 + v66[1].LowPart));
					v65 = (pSystemProcessInfo_1 + __PAIR__(v65, *v348 + v66[1].LowPart)) >> 32;
					pSystemProcessInfo_1 = v67;
					v68 = *v66 + v66[-1].QuadPart;
					v66 += 6;
					v69 = v68 + __PAIR__(v349, v363);
					v349 = (v68 + __PAIR__(v349, v363)) >> 32;
					v363 = v69;
					v70 = v68 + __PAIR__(pItemFound, v351);
					pItemFound = (v70 >> 32);
					v351 = v70;
					v71 = (gpSystemProcessorCycleTimeInfo[dwProcessorIdx].CycleTime + __PAIR__(v350, ProcessHandle)) >> 32;
					ProcessHandle = (ProcessHandle + LODWORD(gpSystemProcessorCycleTimeInfo[dwProcessorIdx++].CycleTime));
					v348 += 6;
					v350 = v71;
				} while (dwProcessorIdx < gSystemInfo.dwNumberOfProcessors);
				v359 = v65;
				gTreeViewListItemParam = TreeViewListItemParam_347;
				v64 = v359;
			}
			pSystemProcessInfo_72 = pSystemProcessInfo_1;
		}
		v75 = __OFSUB__(
			v64,
			(pSystemProcessInfo_72 < LODWORD(gTreeViewListItemParam->ContextSwtiches))
			+ HIDWORD(gTreeViewListItemParam->ContextSwtiches));
		v74 = (__PAIR__(v64, pSystemProcessInfo_72) - gTreeViewListItemParam->ContextSwtiches) >> 32;
		v73 = pSystemProcessInfo_72 - LODWORD(gTreeViewListItemParam->ContextSwtiches);
		if (v74 < 0 || ((v74 < 0) ^ v75) | (v74 == 0) && !v73)
		{
			v354 = 0.0;
			v74 = 0;
			v73 = 0;
		}
		v76 = v73 != LODWORD(gTreeViewListItemParam->ContextSwtichDelta)
			|| v74 != HIDWORD(gTreeViewListItemParam->ContextSwtichDelta);
		LODWORD(gTreeViewListItemParam->ContextSwtichDelta) = v73;
		HIDWORD(gTreeViewListItemParam->ContextSwtichDelta) = v74;
		v77 = RedrawColumn(v76, ghWndTreeListView, 1092, Item.iItem);
		LOBYTE(v369) = v77 | v369;
		v78 = pSystemProcessInfo_1 != LODWORD(gTreeViewListItemParam->ContextSwtiches)
			|| v64 != HIDWORD(gTreeViewListItemParam->ContextSwtiches);
		LODWORD(gTreeViewListItemParam->ContextSwtiches) = pSystemProcessInfo_1;
		HIDWORD(gTreeViewListItemParam->ContextSwtiches) = v64;
		v79 = RedrawColumn(v78, ghWndTreeListView, 1091, Item.iItem);
		LOBYTE(v369) = v79 | v369;
		v80 = v350;
		v81 = __PAIR__(v350, ProcessHandle) - gTreeViewListItemParam->Cycles != gTreeViewListItemParam->CyclesDelta;
		gTreeViewListItemParam->CyclesDelta = __PAIR__(v350, ProcessHandle) - gTreeViewListItemParam->Cycles;
		v82 = RedrawColumn(v81, ghWndTreeListView, 1200, Item.iItem);
		LOBYTE(v369) = v82 | v369;
		v83 = ProcessHandle != LODWORD(gTreeViewListItemParam->Cycles) || v80 != HIDWORD(gTreeViewListItemParam->Cycles);
		LODWORD(gTreeViewListItemParam->Cycles) = ProcessHandle;
		HIDWORD(gTreeViewListItemParam->Cycles) = v80;
		v84 = RedrawColumn(v83, ghWndTreeListView, 1195, Item.iItem);
		LOBYTE(v369) = v84 | v369;
		v85 = v349;
		if (GetProcessorSystemCycleTime)
		{
			if (v344 | v342)
			{
				v86 = gTreeViewListItemParam->CyclesDelta;
				*&v362 = v86 * 100.0;
				v87 = __PAIR__(v344, v342);
				v88 = *&v362 / v87;
			LABEL_59:
				v354 = v88;
				if (v88 > 100.0)
					v354 = db_onehundred;
				TreeViewListItemParam_92 = pItemFound;
				v91 = (__PAIR__(pItemFound, v351) - *&gTreeViewListItemParam->KernelTime) >> 32;
				v362 = v351 - gTreeViewListItemParam->KernelTime.dwLowDateTime;
				v167 = __CFADD__(v351, v356);
				v356 += v351;
				gTreeViewListItemParam->KernelTime.dwLowDateTime = v351;
				v358 += TreeViewListItemParam_92 + v167;
				v93 = v364 | variable_360;
				gTreeViewListItemParam->KernelTime.dwHighDateTime = TreeViewListItemParam_92;
				if (v93)
				{
					v94 = __PAIR__(v91, v362);
					*&v362 = v94 * 100.0;
					v95 = __PAIR__(v364, variable_360);
					v96 = *&v362 / v95;
				}
				else
				{
					v96 = 0.0;
				}
				CGraphData_Update(gTreeViewListItemParam->pGraphData1, gTimeQuerySystemInfo, v354, v96, 0);
				CGraphData_Update(gTreeViewListItemParam->pGraphData2, gTimeQuerySystemInfo, v97, COERCE_DOUBLE(0i64 >> 63), 0);
				v98 = gTreeViewListItemParam->pGraphDataPROCCPU;
				if (v98)
					CGraphData_Update(v98, gTimeQuerySystemInfo, ArgList, COERCE_DOUBLE(0i64 >> 63), 0);
				if (gTreeViewListItemParam->dwStyle & 0x40)
					v345 = v354 + v345;
				if (gTreeViewListItemParam->dwProcessId)
					v332 = v354 + v332;
				if (v354 > *&v339)
				{
					*&v339 = v354;
					TreeViewListItemParam_338 = gTreeViewListItemParam;
				}
				v99 = v363 != gTreeViewListItemParam->m_CPUTime || v85 != gTreeViewListItemParam->field_52C;
				gTreeViewListItemParam->m_CPUTime = v363;
				gTreeViewListItemParam->field_52C = v85;
				v100 = RedrawColumn(v99, ghWndTreeListView, 1087, Item.iItem);
				LOBYTE(v369) = v100 | v369;
				Item.lParam->field_10 = 0;
				v101 = RedrawColumn(1, ghWndTreeListView, 1191, Item.iItem);
				v102 = v369;
				if (v101)
					v102 = 1;
				v362 = v102;
				v103 = RedrawColumn(1, ghWndTreeListView, 1193, Item.iItem);
				v104 = v362;
				if (v103)
					v104 = 1;
				v362 = v104;
				v105 = RedrawColumn(1, ghWndTreeListView, 1330, Item.iItem);
				v106 = v362;
				if (v105)
					v106 = 1;
				v288 = v354 == *&gTreeViewListItemParam->m_CPU;
				LOBYTE(v369) = v106;
				*&gTreeViewListItemParam->m_CPU = v354;
				RedrawColumn(v288 == 0, ghWndTreeListView, 1055, Item.iItem);
				*&gTreeViewListItemParam->m_CPUUsage = v354 + *&gTreeViewListItemParam->m_CPUUsage;
				v107 = RedrawColumn(1, ghWndTreeListView, 1637, Item.iItem);
				LOBYTE(v369) = v107 | v369;
				v362 = &gTreeViewListItemParam->pItemParam;
				TreeViewListItemParam_108 = gTreeViewListItemParam->pItemParam;
				if (TreeViewListItemParam_108)
				{
					v109 = v362;
					TreeViewListItemParam_110 = v362;
					do
					{
						*&TreeViewListItemParam_108->m_CPUUsage = v354;
						v111 = RedrawColumn(1, ghWndTreeListView, 1637, *(*v109 + 44));
						TreeViewListItemParam_112 = *TreeViewListItemParam_110;
						LOBYTE(v369) = v111 | v369;
						TreeViewListItemParam_110 = &TreeViewListItemParam_112->pItemParam;
						TreeViewListItemParam_108 = *TreeViewListItemParam_110;
					} while (*TreeViewListItemParam_110);
					gTreeViewListItemParam = TreeViewListItemParam_347;
				}
				TreeViewListItemParam_32 = v333;
				v113 = v343 - 1;
				--Item.iItem;
				fHungFlags = 1;
				goto LABEL_97;
			}
		}
		else if (v364 | variable_360)
		{
			v89 = (__PAIR__(v349, v363) - *&gTreeViewListItemParam->m_CPUTime);
			*&v362 = v89 * 100.0;
			v90 = __PAIR__(v364, variable_360);
			v88 = *&v362 / v90;
			goto LABEL_59;
		}
		v88 = 0.0;
		goto LABEL_59;
	}
LABEL_99:
	v117 = HIDWORD(v330);
	pSystemProcessInfo_118 = gpSystemProcessInfo;
	v318 = v330;
	v362 = HIDWORD(v314);
	v333 = v314;
	v351 = HIDWORD(v340);
	v349 = v340;
	v350 = liParam.HighPart;
	v363 = liParam.LowPart;
	v359 = HIDWORD(v315);
	v325 = HIDWORD(v330);
	v348 = v315;
	while (1)
	{
		++ItemWithSizeIs50H.nRefCount;
		ItemWithSizeIs50H.NumberOfThreads += pSystemProcessInfo_118->NumberOfThreads;
		ItemWithSizeIs50H.HandleCount += pSystemProcessInfo_118->HandleCount;
		UniqueProcessId = pSystemProcessInfo_118->UniqueProcessId;
		pSystemProcessInfo_1 = pSystemProcessInfo_118;
		packageFullName = UniqueProcessId;
		if (UniqueProcessId)
		{
			v120 = pSystemProcessInfo_118->KernelTime.LowPart;
			v121 = pSystemProcessInfo_118->KernelTime.HighPart;
			v122 = __PAIR__(v121, v120) + pSystemProcessInfo_1->UserTime.QuadPart + __PAIR__(v117, v318);
			v318 += v120 + pSystemProcessInfo_1->UserTime.LowPart;
			v167 = __CFADD__(v120, v356);
			v356 += v120;
			UniqueProcessId = packageFullName;
			v358 += v121 + v167;
			pSystemProcessInfo_118 = pSystemProcessInfo_1;
			v325 = HIDWORD(v122);
		}
		gTreeViewListItemParam_123 = gpTreeViewListItemParam;
		TreeViewListItemParam_328 = gpTreeViewListItemParam;
		if (!gpTreeViewListItemParam)
		{
		LABEL_108:
			HIDWORD(v340) = UniqueProcessId;
			ProcessHandle = OpenProcess(0x410u, 0, UniqueProcessId);
			OutBuffer = ProcessHandle;
			if (!ProcessHandle)
			{
				if (GetLastError() == ERROR_ACCESS_DENIED)
					DeviceIoControl(ghDriverHandle, 0x8335003C, &v340 + 4, 4u, &OutBuffer, 4u, &v321 + 1, 0);
				ProcessHandle = OutBuffer;
				if (!OutBuffer)
				{
					HIDWORD(v330) = pSystemProcessInfo_118->UniqueProcessId;
					ProcessHandle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, 0, HIDWORD(v330));
					TreeViewListItemParam_329 = ProcessHandle;
					if (!ProcessHandle)
					{
						if (GetLastError() == ERROR_ACCESS_DENIED)
							DeviceIoControl(ghDriverHandle, 0x8335003C, &v330 + 4, 4u, &TreeViewListItemParam_329, 4u, &v323 + 1, 0);
						ProcessHandle = TreeViewListItemParam_329;
					}
				}
			}
			memset(&ItemParam, 0, sizeof(tagTREEVIEWLISTITEMPARAM));
			ItemParam.dwProcessId = pSystemProcessInfo_118->UniqueProcessId;
			if (pSystemProcessInfo_118->ImageName.Length)
				wcsncpy_s(szText, 256u, pSystemProcessInfo_118->ImageName.Buffer, pSystemProcessInfo_118->ImageName.Length >> 1);
			else
				wcscpy_s(szText, 256u, L"System Idle Process");
			QueryProcessUsers(
				ProcessHandle,
				pSystemProcessInfo_118->UniqueProcessId,
				&pSystemProcessInfo_118->CreateTime,
				szUserName,
				256u,
				szDomainName,
				256u,
				szText3,
				256u,
				&bVirtualizationEnabled,
				&fbUIAccess);
			if (!szDomainName[0] || (pszText = L"\\", !szUserName[0]))
				pszText = &gszNullString;
			wsprintfW(szFullName, L"%s%s%s", szDomainName, pszText, szUserName);
			ItemParam.pszFullUserName = _wcsdup(szText3);
			dwStyle = ItemParam.dwStyle;
			if (bVirtualizationEnabled)
			{
				dwStyle = ItemParam.dwStyle | TVLS_VirtualizationEnabled;
				ItemParam.dwStyle |= TVLS_VirtualizationEnabled;
			}
			if (fbUIAccess)
				ItemParam.dwStyle = dwStyle | TVLS_UIAccess;
			NtQueryInformationProcess(ProcessHandle, ProcessProtectionInformation, &ItemParam.field_288 + 1, 1u, &v309);
			if (IsImmersiveProcess && IsImmersiveProcess(ProcessHandle))
			{
				if (GetPackageFullName)
				{
					cbPackageFullNameLength = 0;
					if (GetPackageFullName(ProcessHandle, &cbPackageFullNameLength, 0) == ERROR_INSUFFICIENT_BUFFER)
					{
						packageFullName = malloc(2 * cbPackageFullNameLength);
						if (!GetPackageFullName(ProcessHandle, &cbPackageFullNameLength, packageFullName))
							ItemParam.pszPackageFullName = _wcsdup(packageFullName);
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
				v364,
				gTimeQuerySystemInfo.dwLowDateTime,
				gTimeQuerySystemInfo.dwHighDateTime,
				&ItemParam,
				0xFFFFFFFF);
			InheritedFromUniqueProcessId = pSystemProcessInfo_118->InheritedFromUniqueProcessId;
			if (InheritedFromUniqueProcessId)
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
				pSystemProcessInfo_118->UniqueProcessId,
				&ItemParam.pszCommandLine,
				&ItemParam.pszCurrentDirectory,
				&ItemParam.pszEnvBlock,
				&bFlagsInExtendedProcessBasicInfo);
			if (bFlagsInExtendedProcessBasicInfo)
				ItemParam.dwStyle |= TVLS_SupportExtendedProcessBasicInfo;
			liParam.HighPart = pSystemProcessInfo_118->UniqueProcessId;
			wcscpy_s(szText5, 0x100u, &gszNullString);
			ghMainWndBackup = 0;
			if (liParam.HighPart == GetCurrentProcessId())
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
			if (ghMainWndBackup)
				ItemParam.bMainWndIsHung = IsHungAppWindow(ghMainWndBackup);
			if (!sbQueryServiceNamesInited)
			{
				QueryServiceNames();
				sbQueryServiceNamesInited = 1;
			}
			UniqueProcessId_1 = pSystemProcessInfo_118->UniqueProcessId;
			liParam.HighPart = pSystemProcessInfo_118->UniqueProcessId;
			if (*EnumServicesStatusExW && UniqueProcessId_1 && (pGraphData_244 = 0, gdwServiceReturned))
			{
				ppszText_245 = gpszServiceNames + 9;
				while (1)
				{
					pSystemProcessInfo_118 = pSystemProcessInfo_1;
					if (*ppszText_245 == liParam.HighPart)
						break;
					++pGraphData_244;
					ppszText_245 += 11;
					if (pGraphData_244 >= gdwServiceReturned)
						goto LABEL_297;
				}
				ItemParam.dwStyle |= TVLS_SHOWSERVICE;
			}
			else
			{
			LABEL_297:
				ItemParam.dwStyle &= -0x21u;
			}
			wcscpy_s(&ItemParam.field_28C + 1, 0x41u, &gszNullString);
			ItemParam.szProcessName2 = _wcsdup(szText);
			if (!sub_FDD0C0(ProcessHandle, &ItemParam))
			{
				szProcessName = ItemParam.szProcessName;
				hIcon = 0;
				FileInfo.hIcon = 0;
				if (ItemParam.szProcessName)
				{
					SHGetFileInfoW(ItemParam.szProcessName, 0, &FileInfo, sizeof(SHFILEINFOW), 0x101u);// SHGFI_ICON | SHGFI_SMALLICON 
					szProcessName = ItemParam.szProcessName;
					hIcon = FileInfo.hIcon;
				}
				ItemParam.hIcon = hIcon;
				hIcon_1 = 0;
				FileInfo.hIcon = 0;
				if (szProcessName)
				{
					SHGetFileInfoW(szProcessName, 0, &FileInfo, sizeof(SHFILEINFOW), SHGFI_ICON);
					hIcon_1 = FileInfo.hIcon;
				}
				ItemParam.hFileIcon = hIcon_1;
			}
			pGraphData_249 = &pSystemProcessInfo_118->CreateTime.LowPart;
			ItemParam.ProcessBasePriority = pSystemProcessInfo_118->BasePriority;
			if (!pSystemProcessInfo_118->InheritedFromUniqueProcessId && ItemParam.dwProcessId)
			{
				gdwProcessIdLast = ItemParam.dwProcessId;
				gCreateTimeLast.dwLowDateTime = *pGraphData_249;
				gCreateTimeLast.dwHighDateTime = pSystemProcessInfo_118->CreateTime.HighPart;
				pSystemProcessInfo_118->InheritedFromUniqueProcessId = -1;
			}
			ItemParam.InheritedFromUniqueProcessId = pSystemProcessInfo_118->InheritedFromUniqueProcessId;
			ItemParam.pItemParam = 0;
			ItemParam.HandleCount = pSystemProcessInfo_118->HandleCount;
			ItemParam.CreateTime.dwLowDateTime = *pGraphData_249;
			ItemParam.CreateTime.dwHighDateTime = pSystemProcessInfo_118->CreateTime.HighPart;
			v354 = 0.0;
			fHungFlags = 0;
			if (GetVersion() <= 4u)
			{
				fHungFlags = 1;
				v250 = &pSystemProcessInfo_118->ReadOperationCount;
			}
			else
			{
				v250 = &pSystemProcessInfo_118[1];
			}
			packageFullName = pSystemProcessInfo_118->NumberOfThreads;
			if (!packageFullName)
				goto LABEL_455;
			v251 = LODWORD(v354);
			v252 = (v250 + 48);
			v253 = HIDWORD(v354);
			do
			{
				v254 = *v252 + __PAIR__(v253, v251);
				v253 = v254 >> 32;
				v251 = v254;
				v252 += 16;
				packageFullName = (packageFullName - 1);
			} while (packageFullName);
			if (v253 >= 0 && (v253 > 0 || v254))
				ItemParam.ContextSwtiches = __PAIR__(v253, v254);
			else
				LABEL_455:
			ItemParam.ContextSwtiches = 0i64;
			ItemParam.m_SelectedItem = 0;
			fHungFlags = 0;
			if (GetVersion() <= 4u)
			{
				fHungFlags = 1;
				v255 = &pSystemProcessInfo_118->ReadOperationCount;
			}
			else
			{
				v255 = &pSystemProcessInfo_118[1];
			}
			v256 = pSystemProcessInfo_118->NumberOfThreads;
			v257 = 0;
			if (v256)
			{
				v258 = (v255 + 56);
				packageFullName = pSystemProcessInfo_118->NumberOfThreads;
				v259 = (v255 + 52);
				gTreeViewListItemParam_123 = TreeViewListItemParam_328;
				do
				{
					if (*v259 == 5 && *v258 == 5)
						++v257;
					v259 += 16;
					v258 += 16;
					packageFullName = (packageFullName - 1);
				} while (packageFullName);
				v256 = pSystemProcessInfo_118->NumberOfThreads;
			}
			if (v256 == v257)
				ItemParam.dwStyle |= 0x80u;
			if (PE_IsProcessInJob(ProcessHandle, ItemParam.dwProcessId, 0, 0))
				ItemParam.dwStyle |= 0x800u;
			else
				ItemParam.dwStyle &= 0xFFFFF7FF;
			ItemParam.ProcessMitigationPolicy = Fake_GetProcessMitigationPolicy(&ItemParam, ProcessHandle);
			ItemParam.field_50 = 0;
			*&ItemParam.m_CPUTime = pSystemProcessInfo_118->KernelTime.QuadPart + pSystemProcessInfo_118->UserTime.QuadPart;
			ItemParam.KernelTime.dwLowDateTime = pSystemProcessInfo_118->KernelTime.LowPart;
			ItemParam.KernelTime.dwHighDateTime = pSystemProcessInfo_118->KernelTime.HighPart;
			ItemParam.field_64 = 0;
			ItemParam.PageFaultCount = pSystemProcessInfo_118->PageFaultCount;
			ItemParam.PagefileUsage = pSystemProcessInfo_118->PagefileUsage;
			ItemParam.VirtualSize = pSystemProcessInfo_118->VirtualSize;
			ItemParam.PeakPagefileUsage = pSystemProcessInfo_118->PeakPagefileUsage;
			ItemParam.WorkingSetSize = pSystemProcessInfo_118->WorkingSetSize;
			ItemParam.PeakWorkingSetSize = pSystemProcessInfo_118->PeakWorkingSetSize;
			if (!_wcsicmp(ItemParam.szProcessName2, L"wmiprvse.exe"))
				sub_1003A00(ItemParam.dwProcessId, &ItemParam.bSupportWMIProviders);
			ItemParam.m_DPIAwareness = -1;
			if (GetProcessDpiAwareness)
				GetProcessDpiAwareness(ProcessHandle, &ItemParam.m_DPIAwareness);
			if (v359 <= 0 && pSystemProcessInfo_118->PagefileUsage > v348)
			{
				v348 = pSystemProcessInfo_118->PagefileUsage;
				v359 = 0;
			}
			if (gpfnProcessIdToSessionId)
			{
				v260 = gpfnProcessIdToSessionId(pSystemProcessInfo_118->UniqueProcessId, &ItemParam.field_64);
				v261 = ItemParam.field_64;
				if (!v260)
					v261 = -1;
				ItemParam.field_64 = v261;
			}
			if (dword_10610C8)
			{
				*&ItemParam.m_CPU = 0i64;
				v354 = 0.0;
			LABEL_360:
				ItemParam.pszSystemName = _wcsdup(szText4);
				v268 = _wcsdup(szFullName);
				ItemParam.dwStyle |= 4u;
				ItemParam.pszName = v268;
				v288 = _wcsicmp(v268, gszMainTitle) == 0;
				dwItemStyle = ItemParam.dwStyle;
				if (v288)
				{
					dwItemStyle = ItemParam.dwStyle | 0x40;
					ItemParam.dwStyle |= 0x40u;
				}
				if (gConfig.bShowAllUsers || ItemParam.dwStyle & 0x40)
					ItemStyle_270 = dwItemStyle | 2;
				else
					ItemStyle_270 = dwItemStyle & 0xFFFFFFFD;
				ItemParam.dwStyle = ItemStyle_270;
				wcscpy_s(&ItemParam.field_68, 0x100u, szText5);
				if (dword_10610C8)
				{
					ItemParam.field_10 = 0;
				}
				else
				{
					if (*&gTimeQuerySystemInfoLast <= *&ItemParam.CreateTime)
					{
						ItemParam.field_10 = 2;
					}
					else
					{
						ItemParam.field_10 = 0;
						*&ItemParam.m_CPU = 0i64;
					}
					ItemParam.field_14 = 0;
					LOBYTE(ItemParam.field_18) = 0;
				}
				LOBYTE(ItemParam.field_500) = 0;
				ItemParam.pNetCclrInfo = sub_FCB9D0(ItemParam.dwProcessId);
				LOBYTE(ItemParam.field_508) = ProcessIsNetCclr_0(&ItemParam);
				NetCclrInfo_271 = ItemParam.pNetCclrInfo;
				if (ItemParam.pNetCclrInfo)
				{
					if (!v367)
					{
						dynamic_initializer_for_gPerformanceInfoInMemory__();
						NetCclrInfo_271 = ItemParam.pNetCclrInfo;
						v367 = 1;
					}
					if (NetCclrInfo_271)
						++ItemWithSizeIs50H.field_48;
				}
				sub_FCC540(&ItemParam, 0xFFFFFFFF);
				ItemParam.m_GdiObjects = 0;
				ItemParam.m_UserObjects = 0;
				ItemParam.field_14 = 0;
				pItemFound = ::SendMessageW(
					ghMainWnd,
					WM_MSG_7EE,
					gdwProcessIdSelected == pSystemProcessInfo_118->UniqueProcessId,
					&ItemParam);
				TreeViewListItemParam_GetSystemInfo(
					pSystemProcessInfo_118,
					ProcessHandle,
					variable_360,
					v364,
					gTimeQuerySystemInfo.dwLowDateTime,
					gTimeQuerySystemInfo.dwHighDateTime,
					pItemFound,
					0xFFFFFFFF);
				TreeViewListItemParam_272 = pItemFound;
				TreeViewListItemParam_273 = TreeViewListItemParam_337;
				TreeViewListItemParam_337 = pItemFound;
				LOBYTE(v369) = 1;
				LODWORD(TreeViewListItemParam_337->ContextSwtichDelta) = TreeViewListItemParam_337->ContextSwtiches;
				HIDWORD(TreeViewListItemParam_272->ContextSwtichDelta) = HIDWORD(TreeViewListItemParam_272->ContextSwtiches);
				LODWORD(TreeViewListItemParam_272->CyclesDelta) = TreeViewListItemParam_272->Cycles;
				HIDWORD(TreeViewListItemParam_272->CyclesDelta) = HIDWORD(TreeViewListItemParam_272->Cycles);
				TreeViewListItemParam_272->m_SelectedItem = TreeViewListItemParam_273;
				if (ItemParam.szProcessName && *ItemParam.szProcessName != 91)
				{
					if (gConfig.bVerifySignatures)
					{
						InterlockedIncrement(&TreeViewListItemParam_272->nRefCount);
						_beginthread(VerifyImageThreadProc, 0, pItemFound);
						TreeViewListItemParam_272 = pItemFound;
					}
					v274 = sub_FABB70(TreeViewListItemParam_272->pszName, TreeViewListItemParam_272->szProcessName);
					TreeViewListItemParam_275 = pItemFound;
					pItemFound->field_33C = v274;
					v276 = 2;
					if (gConfig.bCheckVirusTotal)
						v276 = 0;
					sub_1001C30(TreeViewListItemParam_275, 1, v276);
					TreeViewListItemParam_272 = pItemFound;
				}
				if (TreeViewListItemParam_272->dwProcessId && v354 > *&v339)
				{
					*&v339 = v354;
					TreeViewListItemParam_338 = TreeViewListItemParam_272;
				}
				if (ItemParam.dwStyle & 0x40)
				{
					v277 = __PAIR__(v351, pSystemProcessInfo_118->PagefileUsage) + v349;
					v351 = (__PAIR__(v351, pSystemProcessInfo_118->PagefileUsage) + v349) >> 32;
					v349 = v277;
					v278 = __PAIR__(v350, pSystemProcessInfo_118->WorkingSetSize) + v363;
					v350 = (__PAIR__(v350, pSystemProcessInfo_118->WorkingSetSize) + v363) >> 32;
					v363 = v278;
					++ItemWithSizeIs50H.field_34;
					ItemWithSizeIs50H.field_3C += pSystemProcessInfo_118->NumberOfThreads;
					ItemWithSizeIs50H.field_44 += pSystemProcessInfo_118->HandleCount;
					if (ItemParam.pNetCclrInfo)
						++ItemWithSizeIs50H.field_4C;
				}
				goto LABEL_259;
			}
			if (GetProcessorSystemCycleTime && gdwVersion >= 2)
			{
				if (v344 | v342)
				{
					v262 = pSystemProcessInfo_118->SpareLi3.QuadPart;
					*&liParam.HighPart = v262 * 100.0;
					v263 = __PAIR__(v344, v342);
					v264 = *&liParam.HighPart / v263;
				LABEL_354:
					v267 = v264;
					v354 = v264;
					if (v264 > 100.0)
					{
						v267 = db_onehundred;
						v354 = db_onehundred;
					}
					*&ItemParam.m_CPU = v267;
					if (ItemParam.dwStyle & 0x40)
					{
						v345 = v267 + v345;
						v267 = v354;
					}
					if (ItemParam.dwProcessId)
						v332 = v267 + v332;
					goto LABEL_360;
				}
			}
			else if (v364 | variable_360)
			{
				v265 = (pSystemProcessInfo_118->KernelTime.QuadPart + pSystemProcessInfo_118->UserTime.QuadPart);
				*&liParam.HighPart = v265 * 100.0;
				v266 = __PAIR__(v364, variable_360);
				v264 = *&liParam.HighPart / v266;
				goto LABEL_354;
			}
			v264 = 0.0;
			goto LABEL_354;
		}
		v124 = pSystemProcessInfo_118->CreateTime.LowPart;
		v125 = pSystemProcessInfo_118->CreateTime.HighPart;
		while (gTreeViewListItemParam_123->CreateTime.dwLowDateTime != v124
			|| gTreeViewListItemParam_123->CreateTime.dwHighDateTime != v125
			|| gTreeViewListItemParam_123->dwProcessId != UniqueProcessId)
		{
			gTreeViewListItemParam_123 = gTreeViewListItemParam_123->m_Prev;
			TreeViewListItemParam_328 = gTreeViewListItemParam_123;
			if (!gTreeViewListItemParam_123)
				goto LABEL_108;
		}
		HIDWORD(v315) = UniqueProcessId;
		ProcessHandle = OpenProcess(0x2000000u, 0, UniqueProcessId);
		TreeViewListItemParam_347 = ProcessHandle;
		if (!ProcessHandle)
		{
			if (GetLastError() == ERROR_ACCESS_DENIED)
				DeviceIoControl(ghDriverHandle, 0x8335003C, &v315 + 4, 4u, &TreeViewListItemParam_347, 4u, &v319 + 1, 0);
			ProcessHandle = TreeViewListItemParam_347;
		}
		if ((FindInfo.flags = 1,
			FindInfo.lParam = gTreeViewListItemParam_123,
			nItemFound = ::SendMessageW(hWndListCtrl_1, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo),
			Item.iItem = nItemFound,
			v127 = gTreeViewListItemParam_123->dwStyle,
			!(v127 & 2))
			|| v127 & 1 && gConfig.byte_14012ADFE
			|| nItemFound != -1)
		{
			gTreeViewListItemParam_123->field_2C = nItemFound;
		}
		else
		{
			sub_FB7F20(ghWndTreeListView, gTreeViewListItemParam_123);
		}
		v128 = TreeViewListItemParam_GetSystemInfo(
			pSystemProcessInfo_118,
			ProcessHandle,
			variable_360,
			v364,
			gTimeQuerySystemInfo.dwLowDateTime,
			gTimeQuerySystemInfo.dwHighDateTime,
			gTreeViewListItemParam_123,
			Item.iItem);
		LOBYTE(v369) = v128 | v369;
		v130 = pSystemProcessInfo_118->KernelTime.LowPart;
		v131 = pSystemProcessInfo_118->UserTime.LowPart;
		v129 = pSystemProcessInfo_118->UserTime.LowPart + pSystemProcessInfo_118->KernelTime.LowPart;
		v334 = pSystemProcessInfo_118->KernelTime.HighPart;
		v132 = __PAIR__(v334, v131) + __PAIR__(pSystemProcessInfo_118->UserTime.HighPart, v130);
		v167 = v129 < gTreeViewListItemParam_123->m_CPUTime;
		v133 = v129 - gTreeViewListItemParam_123->m_CPUTime;
		HIDWORD(v340) = v131 + v130;
		v134 = HIDWORD(v132) - (v167 + gTreeViewListItemParam_123->field_52C);
		packageFullName = HIDWORD(v132);
		if (GetProcessorSystemCycleTime)
		{
			if (!(v344 | v342))
				goto LABEL_135;
			v135 = gTreeViewListItemParam_123->CyclesDelta;
			*&liParam.HighPart = v135 * 100.0;
			v136 = __PAIR__(v344, v342);
			v137 = *&liParam.HighPart / v136;
		}
		else
		{
			if (!gTreeViewListItemParam_123->dwProcessId)
			{
				v138 = v354;
				TreeViewListItemParam_336 = gTreeViewListItemParam_123;
				goto LABEL_137;
			}
			if (!(v364 | variable_360))
			{
			LABEL_135:
				v137 = 0.0;
				goto LABEL_136;
			}
			v139 = __PAIR__(v134, v133);
			*&liParam.HighPart = v139 * 100.0;
			v140 = __PAIR__(v364, variable_360);
			v137 = *&liParam.HighPart / v140;
		}
	LABEL_136:
		v138 = v137;
		v354 = v137;
	LABEL_137:
		if (v138 > 100.0)
			v354 = db_onehundred;
		if (v364 | variable_360)
		{
			v141 = (__PAIR__(v334, pSystemProcessInfo_118->KernelTime.LowPart) - *&gTreeViewListItemParam_123->KernelTime);
			*&liParam.HighPart = v141 * 100.0;
			v142 = __PAIR__(v364, variable_360);
			v143 = *&liParam.HighPart / v142;
		}
		else
		{
			v143 = 0.0;
		}
		v144 = *&gTreeViewListItemParam_123->field_568;
		v167 = v144 < v313;
		v288 = v144 == v313;
		gTreeViewListItemParam_123->KernelTime.dwLowDateTime = pSystemProcessInfo_118->KernelTime.LowPart;
		gTreeViewListItemParam_123->KernelTime.dwHighDateTime = v334;
		v145 = v143;
		if (!v167 && !v288)
		{
			TreeViewListItemParam_327 = gTreeViewListItemParam_123;
			v313 = v144;
		}
		if (gTreeViewListItemParam_123->dwStyle & 0x40)
			v345 = v354 + v345;
		v146 = _mm_unpckl_pd(*&v354, *&v354);
		if (gTreeViewListItemParam_123->dwProcessId)
		{
			if (pSystemProcessInfo_118->UserTime.QuadPart)
				CGraphData_Update(gTreeViewListItemParam_123->pGraphData1, gTimeQuerySystemInfo, v146.m128d_f64[0], v145, 0);
			else
				CGraphData_Update(
					gTreeViewListItemParam_123->pGraphData1,
					gTimeQuerySystemInfo,
					v146.m128d_f64[0],
					v146.m128d_f64[1],
					0);
			v147 = v354;
			v332 = v354 + v332;
			if (v354 > *&v339)
			{
				*&v339 = v354;
				TreeViewListItemParam_338 = gTreeViewListItemParam_123;
			}
		}
		else
		{
			CGraphData_Update(gTreeViewListItemParam_123->pGraphData1, gTimeQuerySystemInfo, 0.0, v146.m128d_f64[0], 0);
			v147 = v354;
		}
		v148 = v147 != *&gTreeViewListItemParam_123->m_CPU;
		*&gTreeViewListItemParam_123->m_CPU = v147;
		v149 = RedrawColumn(v148, ghWndTreeListView, IDS_CPU, Item.iItem);
		v150 = *&gTreeViewListItemParam_123->m_CPUUsage + v354;
		LOBYTE(v369) = v149 | v369;
		fHungFlags = 1;
		if (v150 == *&gTreeViewListItemParam_123->m_CPUUsage)
			fHungFlags = 0;
		*&gTreeViewListItemParam_123->m_CPUUsage = v150;
		v151 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, Item.iItem);
		LOBYTE(v369) = v151 | v369;
		v288 = gTreeViewListItemParam_123->pItemParam == 0;
		liParam.HighPart = &gTreeViewListItemParam_123->pItemParam;
		if (!v288)
		{
			ppTreeViewListItemParam_152 = &gTreeViewListItemParam_123->pItemParam;
			do
			{
				*&(*ppTreeViewListItemParam_152)->m_CPUUsage = *&(*ppTreeViewListItemParam_152)->m_CPUUsage + v354;
				v153 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, (*ppTreeViewListItemParam_152)->field_2C);
				TreeViewListItemParam_154 = *ppTreeViewListItemParam_152;
				LOBYTE(v369) = v153 | v369;
				ppTreeViewListItemParam_152 = &TreeViewListItemParam_154->pItemParam;
			} while (*ppTreeViewListItemParam_152);
			pSystemProcessInfo_118 = pSystemProcessInfo_1;
		}
		v155 = RedrawColumn(fHungFlags, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
		LOBYTE(v369) = v155 | v369;
		--v343;
		if (sub_FDD0C0(ProcessHandle, gTreeViewListItemParam_123))
		{
			PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
			RefreshTreeView();
		}
		v156 = (gTreeViewListItemParam_123->dwStyle >> 7) & 0xFFFFFF01;
		fHungFlags = 0;
		v334 = v156;
		if (GetVersion() <= 4u)
		{
			fHungFlags = 1;
			v157 = &pSystemProcessInfo_118->ReadOperationCount;
		}
		else
		{
			v157 = &pSystemProcessInfo_118[1];
		}
		v158 = pSystemProcessInfo_118->NumberOfThreads;
		v159 = 0;
		liParam.HighPart = v158;
		if (v158)
		{
			v160 = (v157 + 56);
			v161 = (v157 + 52);
			do
			{
				if (*v161 == 5 && *v160 == 5)
					++v159;
				v161 += 16;
				v160 += 16;
				--v158;
			} while (v158);
			v158 = liParam.HighPart;
		}
		if (v158 == v159)
			gTreeViewListItemParam_123->dwStyle |= 0x80u;
		else
			gTreeViewListItemParam_123->dwStyle &= -0x81u;
		if (((gTreeViewListItemParam_123->dwStyle >> 7) & 1) != v334)
		{
			PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
			RefreshTreeView();
		}
		v162 = gTreeViewListItemParam_123->pszCommandLine;
		if ((!v162 || !*v162) && BYTE1(gTreeViewListItemParam_123->field_28C) < 2u)
		{
			QueryProcessArguments(
				ProcessHandle,
				gTreeViewListItemParam_123->dwProcessId,
				&gTreeViewListItemParam_123->pszCommandLine,
				&gTreeViewListItemParam_123->pszCurrentDirectory,
				&gTreeViewListItemParam_123->pszEnvBlock,
				0);
			free(v162);
			++BYTE1(gTreeViewListItemParam_123->field_28C);
			v163 = gTreeViewListItemParam_123->pszCommandLine;
			if (v163)
			{
				if (*v163)
				{
					v164 = RedrawColumn(1, ghWndTreeListView, IDS_COMMAND_LINE, Item.iItem);
					LOBYTE(v369) = v164 | v369;
				}
			}
		}
		v165 = gTreeViewListItemParam_123->field_28C;
		if (v165 < 2u)
		{
			if (!flags)
				LOBYTE(gTreeViewListItemParam_123->field_28C) = v165 + 1;
		}
		else if (!flags)
		{
			goto LABEL_190;
		}
		if (PE_IsProcessInJob(ProcessHandle, gTreeViewListItemParam_123->dwProcessId, 0, 0))
			gTreeViewListItemParam_123->dwStyle |= TVLS_ENABLEJOBS;
		else
			gTreeViewListItemParam_123->dwStyle &= -0x801u;
	LABEL_190:
		if (ProcessHandle)
		{
			liParam.HighPart = gTreeViewListItemParam_123->ProcessMitigationPolicy;
			v166 = Fake_GetProcessMitigationPolicy(gTreeViewListItemParam_123, ProcessHandle);
			gTreeViewListItemParam_123->ProcessMitigationPolicy = v166;
			if (v166 != liParam.HighPart
				&& ((v167 = v166 < BYTE4(liParam.QuadPart), v166 != BYTE4(liParam.QuadPart))
					|| (v168 = BYTE1(gTreeViewListItemParam_123->ProcessMitigationPolicy),
						v167 = v168 < BYTE5(liParam.QuadPart),
						v168 != BYTE5(liParam.QuadPart))
					|| (v169 = BYTE2(gTreeViewListItemParam_123->ProcessMitigationPolicy),
						v167 = v169 < BYTE6(liParam.QuadPart),
						v169 != BYTE6(liParam.QuadPart))
					|| (v170 = HIBYTE(gTreeViewListItemParam_123->ProcessMitigationPolicy),
						v167 = v170 < HIBYTE(liParam.QuadPart),
						v170 != HIBYTE(liParam.QuadPart))))
			{
				v171 = -v167 | 1;
			}
			else
			{
				v171 = 0;
			}
			v172 = RedrawColumn(v171 == 0, ghWndTreeListView, 1199, Item.iItem);
			LOBYTE(v369) = v172 | v369;
		}
		if (gTreeViewListItemParam_123->pNetCclrInfo)
		{
		LABEL_210:
			++ItemWithSizeIs50H.field_48;
			goto LABEL_211;
		}
		v173 = gTreeViewListItemParam_123->field_500;
		if (v173 < 2u)
		{
			if (!flags)
				LOBYTE(gTreeViewListItemParam_123->field_500) = v173 + 1;
		}
		else if (!flags)
		{
			goto LABEL_209;
		}
		gTreeViewListItemParam_123->pNetCclrInfo = sub_FCB9D0(gTreeViewListItemParam_123->dwProcessId);
		LOBYTE(gTreeViewListItemParam_123->field_508) = ProcessIsNetCclr_0(gTreeViewListItemParam_123);
		if (!gTreeViewListItemParam_123->pNetCclrInfo)
			goto LABEL_211;
		if (!v367)
		{
			dynamic_initializer_for_gPerformanceInfoInMemory__();
			v367 = 1;
		}
		PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
		RefreshTreeView();
	LABEL_209:
		if (gTreeViewListItemParam_123->pNetCclrInfo)
			goto LABEL_210;
	LABEL_211:
		v174 = gTreeViewListItemParam_123->ProcessBasePriority;
		v175 = pSystemProcessInfo_1->BasePriority;
		gTreeViewListItemParam_123->ProcessBasePriority = v175;
		v176 = RedrawColumn(v175 != v174, ghWndTreeListView, IDS_PRIORITY, Item.iItem);
		LOBYTE(v369) = v176 | v369;
		if (gTreeViewListItemParam_123->ProcessBasePriority != v174)
		{
			v177 = Item.lParam[16].field_18;
			if (v177 == 4 && !Item.lParam[11].field_1C)
				v177 = 0;
			ArgList_16 = v177;
			v179 = GetMenu(ghMainWnd);
			sub_FFEF00(v179, ArgList_16);
		}
		v180 = packageFullName;
		v181 = HIDWORD(v340) != gTreeViewListItemParam_123->m_CPUTime
			|| packageFullName != gTreeViewListItemParam_123->field_52C;
		gTreeViewListItemParam_123->m_CPUTime = HIDWORD(v340);
		gTreeViewListItemParam_123->field_52C = v180;
		v182 = RedrawColumn(v181, ghWndTreeListView, IDS_CPU_TIME, Item.iItem);
		LOBYTE(v369) = v182 | v369;
		if (GetProcessDpiAwareness)
		{
			GetProcessDpiAwareness(ProcessHandle, &v314 + 4);
			v288 = HIDWORD(v314) == gTreeViewListItemParam_123->m_DPIAwareness;
			gTreeViewListItemParam_123->m_DPIAwareness = HIDWORD(v314);
			v183 = RedrawColumn(!v288, ghWndTreeListView, IDS_DPI_AWARENESS, Item.iItem);
			LOBYTE(v369) = v183 | v369;
		}
		pSystemProcessInfo_184 = pSystemProcessInfo_1;
		v185 = pSystemProcessInfo_1->HandleCount;
		v288 = v185 == gTreeViewListItemParam_123->HandleCount;
		gTreeViewListItemParam_123->HandleCount = v185;
		v186 = RedrawColumn(!v288, ghWndTreeListView, IDS_HANDLES, Item.iItem);
		LOBYTE(v369) = v186 | v369;
		v187 = pSystemProcessInfo_184->PageFaultCount - gTreeViewListItemParam_123->PageFaultCount;
		v288 = v187 == gTreeViewListItemParam_123->m_PFDelta;
		gTreeViewListItemParam_123->m_PFDelta = v187;
		v188 = RedrawColumn(!v288, ghWndTreeListView, IDS_PF_DELTA, Item.iItem);
		LOBYTE(v369) = v188 | v369;
		v189 = pSystemProcessInfo_184->PageFaultCount;
		v288 = v189 == gTreeViewListItemParam_123->PageFaultCount;
		gTreeViewListItemParam_123->PageFaultCount = v189;
		v190 = RedrawColumn(!v288, ghWndTreeListView, IDS_PAGE_FAULTS, Item.iItem);
		LOBYTE(v369) = v190 | v369;
		v191 = pSystemProcessInfo_184->WorkingSetSize;
		v288 = v191 == gTreeViewListItemParam_123->WorkingSetSize;
		gTreeViewListItemParam_123->WorkingSetSize = v191;
		v192 = RedrawColumn(!v288, ghWndTreeListView, IDS_WORKING_SET, Item.iItem);
		LOBYTE(v369) = v192 | v369;
		v193 = pSystemProcessInfo_184->PeakWorkingSetSize;
		v288 = v193 == gTreeViewListItemParam_123->PeakWorkingSetSize;
		gTreeViewListItemParam_123->PeakWorkingSetSize = v193;
		v194 = RedrawColumn(!v288, ghWndTreeListView, IDS_PEAK_WORKING_SET, Item.iItem);
		LOBYTE(v369) = v194 | v369;
		v195 = pSystemProcessInfo_184->QuotaPagedPoolUsage;
		v288 = v195 == gTreeViewListItemParam_123->m_PagedPool;
		gTreeViewListItemParam_123->m_PagedPool = v195;
		v196 = RedrawColumn(!v288, ghWndTreeListView, IDS_PAGEDPOOL, Item.iItem);
		LOBYTE(v369) = v196 | v369;
		v197 = pSystemProcessInfo_184->QuotaNonPagedPoolUsage;
		v288 = v197 == gTreeViewListItemParam_123->m_NonpagedPool;
		gTreeViewListItemParam_123->m_NonpagedPool = v197;
		v198 = RedrawColumn(!v288, ghWndTreeListView, IDS_NONPAGEDPOOL, Item.iItem);
		LOBYTE(v369) = v198 | v369;
		v199 = pSystemProcessInfo_184->PeakPagefileUsage;
		v288 = v199 == gTreeViewListItemParam_123->PeakPagefileUsage;
		gTreeViewListItemParam_123->PeakPagefileUsage = v199;
		v200 = RedrawColumn(!v288, ghWndTreeListView, IDS_PEAK_PRIVATE_BYTES, Item.iItem);
		LOBYTE(v369) = v200 | v369;
		v201 = pSystemProcessInfo_184->PagefileUsage - gTreeViewListItemParam_123->PagefileUsage;
		v288 = v201 == gTreeViewListItemParam_123->m_PrivatedDeltaBytes;
		gTreeViewListItemParam_123->m_PrivatedDeltaBytes = v201;
		v202 = RedrawColumn(!v288, ghWndTreeListView, IDS_PRIVATE_DELTA_BYTES, Item.iItem);
		LOBYTE(v369) = v202 | v369;
		v203 = pSystemProcessInfo_184->PagefileUsage;
		if (v359 <= 0 && v203 > v348)
		{
			v348 = pSystemProcessInfo_184->PagefileUsage;
			v359 = 0;
		}
		v288 = v203 == gTreeViewListItemParam_123->PagefileUsage;
		gTreeViewListItemParam_123->PagefileUsage = v203;
		v204 = !v288;
		v205 = RedrawColumn(v204, ghWndTreeListView, IDS_PRIVATE_BYTES, Item.iItem);
		LOBYTE(v369) = v205 | v369;
		v206 = RedrawColumn(v204, ghWndTreeListView, IDS_PRIVATE_BYTES_HISTORY, Item.iItem);
		LOBYTE(v369) = v206 | v369;
		pGraphData_207 = gTreeViewListItemParam_123->pGraphData2;
		if (pGraphData_207
			&& (gTreeViewListItemParam_123->PeakPagefileUsage >> 10)
			+ qword_103D110[gTreeViewListItemParam_123->PeakPagefileUsage >> 41] >= pGraphData_207->m_dbMemorySize)
		{
			pGraphData_207->m_dbMemorySize = (((gTreeViewListItemParam_123->PeakPagefileUsage >> 10)
				+ qword_103D110[gTreeViewListItemParam_123->PeakPagefileUsage >> 41])
				* 1.2);
		}
		CGraphData_Update(
			gTreeViewListItemParam_123->pGraphData2,
			gTimeQuerySystemInfo,
			(gTreeViewListItemParam_123->PagefileUsage * 0.0009765625),
			0.0,
			0);
		pSystemProcessInfo_118 = pSystemProcessInfo_1;
		v208 = pSystemProcessInfo_1->VirtualSize;
		v288 = v208 == gTreeViewListItemParam_123->VirtualSize;
		gTreeViewListItemParam_123->VirtualSize = v208;
		v209 = RedrawColumn(!v288, ghWndTreeListView, IDS_VIRTUAL_SIZE, Item.iItem);
		LOBYTE(v369) = v209 | v369;
		if (IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_TITLE) || IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_STATUS))
		{
			UniqueProcessId_2 = pSystemProcessInfo_118->UniqueProcessId;
			wcscpy_s(szText5, 0x100u, &gszNullString);
			ghMainWndBackup = 0;
			if (UniqueProcessId_2 == GetCurrentProcessId())
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
			if (IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_STATUS) && hMainWndBackup)
				fHungFlags = IsHungAppWindow(hMainWndBackup);
			v212 = wcscmp(szText5, &gTreeViewListItemParam_123->field_68);
			if (v212)
				v212 = -(v212 < 0) | 1;
			v288 = v212 == 0;
			v213 = fHungFlags;
			if (!v288 || (fHungFlags = 0, v213 != gTreeViewListItemParam_123->bMainWndIsHung))
				fHungFlags = 1;
			gTreeViewListItemParam_123->bMainWndIsHung = v213;
			wcscpy_s(&gTreeViewListItemParam_123->field_68, 0x100u, szText5);
			gTreeViewListItemParam_123->hMainWndBackup = hMainWndBackup;
			v214 = fHungFlags;
			v215 = RedrawColumn(fHungFlags, ghWndTreeListView, IDS_WINDOW_TITLE, Item.iItem);
			LOBYTE(v369) = v215 | v369;
			v216 = RedrawColumn(v214, ghWndTreeListView, IDS_WINDOW_STATUS, Item.iItem);
			pSystemProcessInfo_118 = pSystemProcessInfo_1;
			LOBYTE(v369) = v216 | v369;
		}
		v217 = pSystemProcessInfo_118->NumberOfThreads;
		v288 = v217 == gTreeViewListItemParam_123->m_NumberOfThreads;
		gTreeViewListItemParam_123->m_NumberOfThreads = v217;
		v218 = RedrawColumn(!v288, ghWndTreeListView, IDS_THREADS2, Item.iItem);
		LOBYTE(v369) = v218 | v369;
		if (gTreeViewListItemParam_123->pGraphDataPROCCPU)
		{
			v219 = (gTreeViewListItemParam_123->DeltaWriteBytes + gTreeViewListItemParam_123->DeltaOtherBytes) >> 32;
			v220 = LODWORD(gTreeViewListItemParam_123->DeltaWriteBytes) + LODWORD(gTreeViewListItemParam_123->DeltaOtherBytes);
			v221 = gTreeViewListItemParam_123->DeltaReadBytes;
			liParam.HighPart = LODWORD(gTreeViewListItemParam_123->DeltaReadBytes) + v220;
			LODWORD(v222) = v221 + v220;
			HIDWORD(v340) = (__PAIR__(v219, v221) + __PAIR__(HIDWORD(gTreeViewListItemParam_123->DeltaReadBytes), v220)) >> 32;
			HIDWORD(v222) = HIDWORD(v340);
			if (v222 >= gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize)
			{
				v223 = __PAIR__(HIDWORD(v340), liParam.HighPart);
				gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize = (v223 * 1.2);
				gTreeViewListItemParam_123->pGraphDataPROCCPU->m_Item[0].dbMemorySize = gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize;
			}
		}
		v224 = HIDWORD(gTreeViewListItemParam_123->DeltaReadBytes);
		v225 = gTreeViewListItemParam_123->DeltaReadBytes;
		v226 = gTreeViewListItemParam_123->DeltaWriteBytes;
		*(&v340 + 1) = v226;
		ArgList_8 = v226;
		v228 = __PAIR__(v224, v225);
		v229 = HIDWORD(gTreeViewListItemParam_123->DeltaOtherBytes);
		v230 = gTreeViewListItemParam_123->DeltaOtherBytes;
		*&v228 = v228;
		*(&v340 + 1) = *&v228 + *(&v340 + 1);
		*&v228 = __PAIR__(v229, v230);
		CGraphData_Update(
			gTreeViewListItemParam_123->pGraphDataPROCCPU,
			gTimeQuerySystemInfo,
			(*(&v340 + 1) + *&v228),
			ArgList_8,
			0);
		sub_FB47C0(gTreeList_Item, gTreeViewListItemParam_123, &gTreeViewListItemParam_123->ReadOperationCount);
		sub_FB47C0(&gTreeList_Item[1].field_0, gTreeViewListItemParam_123, &gTreeViewListItemParam_123->field_430);
		sub_FB47C0(&gTreeList_Item[2].field_0, gTreeViewListItemParam_123, &gTreeViewListItemParam_123->field_498);
		v231 = RedrawColumn(1, ghWndTreeListView, IDS_IO_HISTORY, Item.iItem);
		LOBYTE(v369) = v231 | v369;
		if (gTreeViewListItemParam_123->pNetCclrInfo && !v367)
		{
			dynamic_initializer_for_gPerformanceInfoInMemory__();
			v367 = 1;
		}
		v232 = sub_FCC540(gTreeViewListItemParam_123, Item.iItem);
		LOBYTE(v369) = v232 | v369;
		if (gTreeViewListItemParam_123->dwStyle & 0x40)
		{
			v233 = pSystemProcessInfo_118->KernelTime.QuadPart
				+ pSystemProcessInfo_118->UserTime.QuadPart
				+ __PAIR__(v362, v333);
			v362 = v233 >> 32;
			v333 = v233;
			v234 = __PAIR__(v351, pSystemProcessInfo_118->PagefileUsage) + v349;
			v351 = (__PAIR__(v351, pSystemProcessInfo_118->PagefileUsage) + v349) >> 32;
			v349 = v234;
			v235 = __PAIR__(v350, pSystemProcessInfo_118->WorkingSetSize) + v363;
			v350 = (__PAIR__(v350, pSystemProcessInfo_118->WorkingSetSize) + v363) >> 32;
			v363 = v235;
			++ItemWithSizeIs50H.field_34;
			ItemWithSizeIs50H.field_3C += pSystemProcessInfo_118->NumberOfThreads;
			ItemWithSizeIs50H.field_44 += pSystemProcessInfo_118->HandleCount;
			if (gTreeViewListItemParam_123->pNetCclrInfo)
				++ItemWithSizeIs50H.field_4C;
		}
		RedrawColumn(1, ghWndTreeListView, IDS_PRIVATE_BYTES_HISTORY, Item.iItem);
		RedrawColumn(1, ghWndTreeListView, IDS_IO_HISTORY, Item.iItem);
		RedrawColumn(1, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
		v236 = gTreeViewListItemParam_123->field_18;
		v237 = 0;
		if (v236)
		{
			v238 = gTreeViewListItemParam_123->field_1C;
			if (v238 < gConfig.dwHighlightDuration)
			{
				gTreeViewListItemParam_123->field_10 = 2;
				gTreeViewListItemParam_123->field_14 = v238;
				goto LABEL_259;
			}
			if (v236)
			{
				v237 = 1;
				LOBYTE(gTreeViewListItemParam_123->field_18) = 0;
			}
		}
		v239 = v369;
		if (v237)
			v239 = 1;
		gTreeViewListItemParam_123->field_10 = 0;
		LOBYTE(v369) = v239;
	LABEL_259:
		if (ProcessHandle)
			CloseHandle(ProcessHandle);
		if (!pSystemProcessInfo_118->NextEntryOffset)
			break;
		v117 = v325;
		pSystemProcessInfo_118 = (pSystemProcessInfo_118 + pSystemProcessInfo_118->NextEntryOffset);
	}
	if (v365 || !gConfig.bShowAllUsers)
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
		if (gSystemInfo.dwNumberOfProcessors > 0)
		{
			v280 = &gpSystemPerformanceInfo->InterruptTime;
			v281 = &gpSystemInterruptInfo->DpcCount;
			do
			{
				v281 += 6;
				ItemParam.ContextSwtiches += *(v281 - 6) + v280[1].LowPart;
				*&ItemParam.m_CPUTime += *v280 + v280[-1].QuadPart;
				v282 = *v280 + v280[-1].QuadPart;
				v280 += 6;
				*&ItemParam.KernelTime += v282;
				v283 = (gpSystemProcessorCycleTimeInfo[dwProcessorIndex].CycleTime + ItemParam.Cycles) >> 32;
				LODWORD(ItemParam.Cycles) += LODWORD(gpSystemProcessorCycleTimeInfo[dwProcessorIndex++].CycleTime);
				HIDWORD(ItemParam.Cycles) = v283;
			} while (dwProcessorIndex < gSystemInfo.dwNumberOfProcessors);
			gTreeViewListItemParam_123 = TreeViewListItemParam_328;
		}
		ItemParam.pszTitle = _wcsdup(L"Hardware Interrupts and DPCs");
		ItemParam.szProcessName2 = _wcsdup(L"Interrupts");
		ItemParam.CreateTime = gCreateTimeLast;
		ItemParam.InheritedFromUniqueProcessId = gdwProcessIdLast;
		SendMessageW = ::SendMessageW;
		ItemParam.pszSystemName = _wcsdup(L"System");
		TreeViewListItemParam_285 = ::SendMessageW(ghMainWnd, WM_MSG_7EE, gdwProcessIdSelected == 0, &ItemParam);
		TreeViewListItemParam_285->m_SelectedItem = TreeViewListItemParam_337;
	}
	if (!gbShowProcessTreeLast
		&& gConfig.dwProcessSortColumn != 1000
		&& !v369
		&& gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn] == 1055)
	{
		Item.mask = LVIF_PARAM;
		Item.iItem = 1;
		Item.iSubItem = 0;
		if (SendMessageW(hWndListCtrl_1, LVM_GETITEMW, 0, &Item))
		{
			while (1)
			{
				if (gConfig.bProcessSortDirection)
				{
					v286 = *&gTreeViewListItemParam_123->m_CPU;
					v287 = v286 < *&Item.lParam[15].field_24;
					v288 = v286 == *&Item.lParam[15].field_24;
				}
				else
				{
					v289 = *&Item.lParam[15].field_24;
					v287 = v289 < *&gTreeViewListItemParam_123->m_CPU;
					v288 = v289 == *&gTreeViewListItemParam_123->m_CPU;
				}
				if (!v287 && !v288)
					break;
				++Item.iItem;
				gTreeViewListItemParam_123 = Item.lParam;
				if (!SendMessageW(hWndListCtrl_1, LVM_GETITEMW, 0, &Item))
					goto LABEL_410;
			}
			LOBYTE(v369) = 1;
		}
	}
LABEL_410:
	v290 = variable_360;
	v291 = v364;
	if (v364 | variable_360)
	{
		v292 = (__PAIR__(v358, v356) - qword_107BC30);
		v331 = v292 * 100.0;
		v293 = __PAIR__(v364, variable_360);
		v331 = v331 / v293;
	}
	LODWORD(qword_107BC30) = v356;
	HIDWORD(qword_107BC30) = v358;
	*&ItemWithSizeIs50H.field_8 = v345;
	sub_FF7400(__PAIR__(v351, v349), 0, &v312, &v345);
	*&ItemWithSizeIs50H.field_18 = v3;
	LODWORD(qword_107BA40) = v348;
	HIDWORD(qword_107BA40) = v359;
	*&ItemWithSizeIs50H.field_28 = (__PAIR__(v350, v363) / 1024) / v345 * 100.0;
	if (TreeViewListItemParam_336)
	{
		v345 = 100.0 - v332;
		if (100.0 - v332 < 0.0)
			v345 = 0.0;
		FindInfo.lParam = TreeViewListItemParam_336;
		FindInfo.flags = 1;
		Item.iItem = ::SendMessageW(hWndListCtrl_1, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
		v294 = v345 != *&TreeViewListItemParam_336->m_CPU;
		*&TreeViewListItemParam_336->m_CPU = v345;
		v295 = RedrawColumn(v294, ghWndTreeListView, IDS_CPU, Item.iItem);
		LOBYTE(v369) = v295 | v369;
		v365 = 1;
		v296 = *&TreeViewListItemParam_336->m_CPUUsage + v345;
		if (v296 == *&TreeViewListItemParam_336->m_CPUUsage)
			v365 = 0;
		*&TreeViewListItemParam_336->m_CPUUsage = v296;
		v297 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, Item.iItem);
		LOBYTE(v369) = v297 | v369;
		v298 = RedrawColumn(v365, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
		LOBYTE(v369) = v298 | v369;
		CGraphData_Update(TreeViewListItemParam_336->pGraphData1, gTimeQuerySystemInfo, 0.0, v345, 0);
	}
	if (!v369 && v343)
	{
		v299 = ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
		for (i = 0; i < v299; ++i)
			PostMessageW(ghMainWnd, WM_MSG_7EB, i, -1);
		v291 = v364;
		v290 = variable_360;
	}
	v301 = db_onehundred;
	if (v332 <= 100.0)
		v301 = v332;
	*&ItemWithSizeIs50H.field_0 = v301;
	sub_1000410(v3, ghWndStatusBar, &ItemWithSizeIs50H, &v310, &v312);
	if (TreeViewListItemParam_338)
	{
		v302 = TreeViewListItemParam_338->dwProcessId;
		if (gConfig.bShowCpuFractions)
		{
			if (v302 <= 0)
				wsprintfW(szBuffer, L"%02.02f%% %s", v339, TreeViewListItemParam_338->szProcessName2);
			else
				wsprintfW(
					szBuffer,
					L"%02.02f%% %s:%d",
					v339,
					TreeViewListItemParam_338->szProcessName2,
					TreeViewListItemParam_338->dwProcessId);
		}
		else if (v302 <= 0)
		{
			wsprintfW(szBuffer, L"%02.0f%% %s", v339, TreeViewListItemParam_338->szProcessName2);
		}
		else
		{
			wsprintfW(
				szBuffer,
				L"%02.0f%% %s:%d",
				v339,
				TreeViewListItemParam_338->szProcessName2,
				TreeViewListItemParam_338->dwProcessId);
		}
	}
	CGraphData_Update(gpGraphInfoOfCPU, gTimeQuerySystemInfo, *&ItemWithSizeIs50H.field_0, v331, szBuffer);
	if (gdwAdapterRuntingTime)
	{
		sub_FB38F0(
			gTimeQuerySystemInfo,
			__PAIR__(v291, v290) / gSystemInfo.dwNumberOfProcessors,
			gpGraphInfoOfGPU,
			TreeViewListItemParam_327,
			dword_107BA1C,
			gpGraphInfoOfSystemMemory,
			gpGraphInfoOfDedicatedMemory);
		*(&v330 + 1) = v3;
		sub_FFFD50(gpGraphInfoOfGPU, *(&v330 + 1), TreeViewListItemParam_327, v313);
	}
	if (gIOGraphInfo.pGraphData)
		sub_FB44A0(&gIOGraphInfo, gTreeList_Item);
	if (gNetworkGraphInfo.pGraphData)
		sub_FB44A0(&gNetworkGraphInfo, &gTreeList_Item[1]);
	if (gDiskGraphInfo.pGraphData)
		sub_FB44A0(&gDiskGraphInfo, &gTreeList_Item[2]);
	RedrawColumn(1, ghWndTreeListView, IDS_CPU, 0xFFFFFFFE);
	RedrawColumn(1, ghWndTreeListView, IDS_PRIVATE_BYTES, 0xFFFFFFFE);
	RedrawColumn(1, ghWndTreeListView, IDS_WORKING_SET, 0xFFFFFFFE);
	RedrawColumn(1, ghWndTreeListView, IDS_GPU2, 0xFFFFFFFE);
	sub_FFFD50(gpGraphInfoOfCPU, *&ItemWithSizeIs50H.field_0, TreeViewListItemParam_338, *&v339);
	sub_FFFCA0(gpGraphInfoOfMemory, *&v310);
	sub_1000360(gpGraphInfoOfPhysicalMemory, v312);
	ret = v369;
	if (flags)
		ret = 1;
	HIDWORD(v330) = ret;
	if (dword_10610C8)
	{
		if (gdwProcessId_0 == -1)
		{
			ItemState.stateMask = 3;
			ItemState.state = 3;
			::SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, 0, &ItemState);
		}
		else
		{
			item.iItem = 0;
			item.mask = LVIF_PARAM;
			item.iSubItem = 0;
			if (::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0) > 0)
			{
				while (1)
				{
					::SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &item);
					if (item.lParam->dwProcessId == gdwProcessId_0)
						break;
					++item.iItem;
					item.mask = 4;
					item.iSubItem = 0;
					v304 = ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
					if (item.iItem >= v304)
						goto LABEL_451;
				}
				ItemState.mask = 3;
				ItemState.state = 3;
				::SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, item.iItem, &ItemState);
			}
		}
	LABEL_451:
		LOBYTE(ret) = BYTE4(v330);
		dword_10610C8 = 0;
	}
	return ret;
}


FILETIME RequerySystemStatus(SYSTEM_PROCESS_INFORMATION **ppSystemProcessInfo, PULONG cbRet, SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *SystemProcessorPerformanceInfo, SYSTEM_INTERRUPT_INFORMATION *pSystemInterruptInfo, SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfo, CSystemProcessInfoMap *pMap, int dwBufLen)
{
	struct _FILETIME timeReturned; // rax
	DWORD v8; // ebx
	SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfo_1; // edi
	SYSTEM_PROCESS_INFORMATION *gpSystemProcessInfoLast; // esi
	CSystemProcessInfoMapNode *_Node; // eax
	ULONG i; // eax
	CSystemProcessInfoMapNode *_Node_1; // eax
	std__Tree_node *v14; // eax
	CSystemProcessInfoMap *v15; // ecx
	CSystemProcessInfoMap v16; // rax
	CSystemProcessInfoMap *v17; // ST0C_4
	int _Where; // [esp+10h] [ebp-2Ch]
	CSystemProcessInfoMapPair pair; // [esp+18h] [ebp-24h]
	CSystemProcessInfoMap *map; // [esp+20h] [ebp-1Ch]
	int v22; // [esp+24h] [ebp-18h]
	ULONG nSize; // [esp+28h] [ebp-14h]
	unsigned int v24; // [esp+2Ch] [ebp-10h]
	int v25; // [esp+38h] [ebp-4h]

	timeReturned = GetSystemProcessInfo(ppSystemProcessInfo, cbRet);
	v24 = timeReturned.dwHighDateTime;
	v8 = timeReturned.dwLowDateTime;

	if (SystemProcessorPerformanceInfo)
	{
		NtQuerySystemInformation(
			SystemProcessorPerformanceInformation,
			SystemProcessorPerformanceInfo,
			sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION) * gSystemInfo.dwNumberOfProcessors,
			&nSize);
	}


	if (pSystemInterruptInfo)
	{
		NtQuerySystemInformation(
			SystemInterruptInformation,
			pSystemInterruptInfo,
			sizeof(SYSTEM_INTERRUPT_INFORMATION) * gSystemInfo.dwNumberOfProcessors,
			&nSize);
	}

	pSystemProcessorCycleTimeInfo_1 = pSystemProcessorCycleTimeInfo;
	if (pSystemProcessorCycleTimeInfo)
	{
		NtQuerySystemInformation(
			SystemProcessorCycleTimeInformation,
			pSystemProcessorCycleTimeInfo,
			sizeof(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION) * gSystemInfo.dwNumberOfProcessors,
			&nSize);
	}


	if (GetProcessorSystemCycleTime && pSystemProcessorCycleTimeInfo_1)
	{
		v22 = 0;
		map = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long, SYSTEM_PROCESS_INFORMATION *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *>>, 0>>::_Buyheadnode();
		
		pSystemProcessInfoLast = gpSystemProcessInfoLast;
		
		v25 = 0;
		if (gpSystemProcessInfoLast)
		{
			pair._Key = gpSystemProcessInfoLast->UniqueProcessId;
			pair._Value = gpSystemProcessInfoLast;
			_Node = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long, SYSTEM_PROCESS_INFORMATION *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *>>, 0>>::_Buynode<std::piecewise_construct_t const &, std::tuple<unsigned long &&>, std::tuple<>>(
				&map,
				&pair);
			std::_Tree<std::_Tmap_traits<unsigned long, SYSTEM_PROCESS_INFORMATION *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *>>, 0>>::_Insert_hint<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *> &, std::_Tree_node<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *>, void *> *>(
				&map,
				&_Where,
				0,
				&_Node->_Keyvalue,
				_Node);


			for (i = gpSystemProcessInfoLast->NextEntryOffset;
				gpSystemProcessInfoLast->NextEntryOffset;
				i = gpSystemProcessInfoLast->NextEntryOffset)
			{
				gpSystemProcessInfoLast = (gpSystemProcessInfoLast + i);
				pair._Value = gpSystemProcessInfoLast;
				pair._Key = gpSystemProcessInfoLast->UniqueProcessId;
				_Node_1 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long, SYSTEM_PROCESS_INFORMATION *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *>>, 0>>::_Buynode<std::piecewise_construct_t const &, std::tuple<unsigned long &&>, std::tuple<>>(
					&map,
					&pair);
				std::_Tree<std::_Tmap_traits<unsigned long, SYSTEM_PROCESS_INFORMATION *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *>>, 0>>::_Insert_hint<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *> &, std::_Tree_node<std::pair<unsigned long const, SYSTEM_PROCESS_INFORMATION *>, void *> *>(
					&map,
					&_Where,
					0,
					&_Node_1->_Keyvalue,
					_Node_1);
			}
		}


		v14 = sub_FDE4B0(&map, *ppSystemProcessInfo, pSystemProcessorCycleTimeInfo_1, dwBufLen);
		v15 = pMap;
		pMap->_Header = v14;
		v16._Header = map;
		v17 = map;
		v15->_Size = v16._Size;
		sub_FF5510(&map, &SystemProcessorPerformanceInfo, v16._Header->_Left, v17);
		j__free(map);
	}
	return __PAIR__(v24, v8);
}


int __cdecl sub_FDE4B0(CSystemProcessInfoMap *theMap, SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo, SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pProcessorIdleCycleTimeInfo, unsigned int dwProcessorIdleCycleTimeInfoLen)
{
	unsigned __int64 v4; // rcx
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // esi
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
	std__Tree_node *v32; // edx
	std__Tree_node_For__bstr_t *v33; // ecx
	std__Tree_node_For__bstr_t *_Node_1; // ecx
	std__Tree_node *_Node_2; // ecx
	std__Tree_node *_Node_3; // ecx
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
	unsigned int dwProcessorIdleCycleTimeInfoLen_1; // [esp+18h] [ebp-824h]
	__int64 v60; // [esp+1Ch] [ebp-820h]
	__int64 v61; // [esp+24h] [ebp-818h]
	CSystemProcessInfoMap *theMap_1; // [esp+2Ch] [ebp-810h]
	unsigned int v63; // [esp+30h] [ebp-80Ch]
	unsigned int v64; // [esp+34h] [ebp-808h]
	ULONG64 ProcessorIdleCycleTime; // [esp+38h] [ebp-804h]
	int v66; // [esp+40h] [ebp-7FCh]
	int v67; // [esp+44h] [ebp-7F8h]
	char v68; // [esp+48h] [ebp-7F4h]

	v4 = theMap;
	pSystemProcessInfo_1 = pSystemProcessInfo;
	v60 = 0i64;
	v6 = 0;
	dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
	theMap_1 = theMap;
	dwProcessorIdleCycleTimeInfoLen_1 = dwProcessorIdleCycleTimeInfoLen;
	v63 = 0;
	v64 = 0;
	while (1)
	{
		if (!pSystemProcessInfo_1->UniqueProcessId && !pSystemProcessInfo_1->SpareLi3.QuadPart)
		{
			Buffer = 8 * dwNumberOfProcessors;
			QueryIdleProcessorCycleTime(&Buffer, &ProcessorIdleCycleTime);
			dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
			dwIndex = 0;
			if (gSystemInfo.dwNumberOfProcessors && gSystemInfo.dwNumberOfProcessors >= 4)
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
				} while (dwIndex < gSystemInfo.dwNumberOfProcessors - (gSystemInfo.dwNumberOfProcessors & 3));
				v13 = _mm_add_epi64(v9, v10);
				v14 = _mm_add_epi64(v13, _mm_srli_si128(v13, 8));
				LODWORD(v4) = _mm_cvtsi128_si32(v14);
				v15 = v4 + __PAIR__(_mm_cvtsi128_si32(_mm_srli_si128(v14, 4)), v64);
				HIDWORD(v4) = HIDWORD(v15);
				v63 = v15 >> 32;
				v64 = v15;
			}
			v60 = 0i64;
			v61 = 0i64;
			if (dwIndex >= gSystemInfo.dwNumberOfProcessors)
			{
				v6 = v64;
			}
			else
			{
				v4 = __PAIR__(HIDWORD(v61), v60);
				if (gSystemInfo.dwNumberOfProcessors - dwIndex < 2)
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
							+ __PAIR__(v16, v4)) >> 32;
						LODWORD(v4) = *(&ProcessorIdleCycleTime + 2 * dwIndex) + v4;
						v18 = *(&v66 + 2 * dwIndex) + v17;
						HIDWORD(v4) = (__PAIR__(*(&v67 + 2 * dwIndex), *(&v66 + 2 * dwIndex)) + __PAIR__(HIDWORD(v4), v17)) >> 32;
						v17 += *(&v66 + 2 * dwIndex);
						dwIndex += 2;
					} while (dwIndex < v57);
					HIDWORD(v61) = v18;
					dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
				}
				if (dwIndex < dwNumberOfProcessors)
				{
					v19 = __CFADD__(*(&ProcessorIdleCycleTime + 2 * dwIndex), v64);
					v64 += *(&ProcessorIdleCycleTime + 2 * dwIndex);
					v63 += *(&ProcessorIdleCycleTime + 2 * dwIndex + 1) + v19;
					dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
				}
				v20 = __PAIR__(v16, HIDWORD(v61)) + v4 + __PAIR__(v63, v64);
				HIDWORD(v4) = HIDWORD(v20);
				v6 = v20;
			}
			LODWORD(v4) = theMap_1;
		}
		v21 = pSystemProcessInfo_1->SpareLi3.LowPart;
		v64 = pSystemProcessInfo_1->SpareLi3.LowPart + v6;
		HIDWORD(v4) = (__PAIR__(HIDWORD(v4), v21) + __PAIR__(pSystemProcessInfo_1->SpareLi3.HighPart, v6)) >> 32;
		v6 += v21;
		v63 = HIDWORD(v4);
		if (v4)
		{
			v22 = *v4;
			v23 = v22;
			v24 = pSystemProcessInfo_1->UniqueProcessId;
			v25 = *(v22 + 4);
			while (!*(v25 + 13))
			{
				if (*(v25 + 16) >= v24)
				{
					v23 = v25;
					v25 = *v25;
				}
				else
				{
					v25 = *(v25 + 8);
				}
			}
			if (v23 == v22 || v24 < *(v23 + 16))
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
			if (v27 != v22)
			{
				v28 = v27[5];
				if (*(v28 + 32) == pSystemProcessInfo_1->CreateTime.LowPart)
				{
					LODWORD(v4) = theMap_1;
					if (*(v28 + 36) != pSystemProcessInfo_1->CreateTime.HighPart)
					{
					LABEL_35:
						v6 = v64;
						HIDWORD(v4) = v63;
						goto LABEL_36;
					}
					sub_FF55B0(theMap_1, &a2[1], v27);
					dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
				}
			}
			LODWORD(v4) = theMap_1;
			goto LABEL_35;
		}
	LABEL_36:
		if (!pSystemProcessInfo_1->NextEntryOffset)
			break;
		pSystemProcessInfo_1 = (pSystemProcessInfo_1 + pSystemProcessInfo_1->NextEntryOffset);
	}
	theMap_2 = theMap_1;
	if (theMap_1)
	{
		_Node = theMap_1->_Header->_Left;
		if (_Node != theMap_1->_Header)
		{
			v31 = dwProcessorIdleCycleTimeInfoLen_1;
			do
			{
				v32 = _Node[1]._Parent;
				v33 = v32[1]._Right;
				v19 = __CFADD__(v33, *v31);
				*v31 += v33;
				v31[1] += *&v32[1]._Color + v19;
				if (!_Node->_IsNil)
				{
					_Node_1 = _Node->_Right;
					if (_Node_1->_IsNil)
					{
						for (_Node_3 = _Node->_Parent; !_Node_3->_IsNil; _Node_3 = _Node_3->_Parent)
						{
							if (_Node != _Node_3->_Right)
								break;
							_Node = _Node_3;
						}
						_Node = _Node_3;
					}
					else
					{
						_Node = _Node->_Right;
						for (_Node_2 = _Node_1->_Left; !_Node_2->_IsNil; _Node_2 = _Node_2->_Left)
							_Node = _Node_2;
					}
				}
			} while (_Node != theMap_2->_Header);
			dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
		}
	}
	dwIndex_1 = 0;
	if (dwNumberOfProcessors && dwNumberOfProcessors >= 4)
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
		} while (dwIndex_1 < dwNumberOfProcessors - (dwNumberOfProcessors & 3));
		v42 = _mm_add_epi64(v38, v39);
		v43 = _mm_add_epi64(v42, _mm_srli_si128(v42, 8));
		LODWORD(v4) = _mm_cvtsi128_si32(v43);
		v44 = v4 + __PAIR__(_mm_cvtsi128_si32(_mm_srli_si128(v43, 4)), v64);
		v63 = v44 >> 32;
		v64 = v44;
	}
	*a2 = 0i64;
	v60 = 0i64;
	if (dwIndex_1 >= dwNumberOfProcessors)
	{
		LODWORD(v52) = v64;
	}
	else
	{
		v45 = __PAIR__(HIDWORD(v60), a2[0]);
		if (dwNumberOfProcessors - dwIndex_1 < 2)
		{
			HIDWORD(v61) = v60;
			v48 = a2[1];
		}
		else
		{
			v46 = dwNumberOfProcessors - 1;
			v47 = v60;
			dwProcessorIdleCycleTimeInfoLen_1 = v46;
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
			} while (dwIndex_1 < dwProcessorIdleCycleTimeInfoLen_1);
			HIDWORD(v61) = v50;
			dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
		}
		if (dwIndex_1 >= dwNumberOfProcessors)
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
