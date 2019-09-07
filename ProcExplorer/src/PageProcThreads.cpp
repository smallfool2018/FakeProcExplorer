
int __stdcall UpdateProcThreadsInfoThreadProc(tagThreadItem *pThreadItem)
{
	HWND hWndList; // edi
	tagThreadItem *pThreadItem_2; // esi
	DWORD dwRet; // eax
	int v4; // ecx
	LRESULT(__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ebx
	LRESULT nCount; // eax
	int nIndex_1; // esi
	char v8; // al
	int v9; // ecx
	struct _FILETIME FileTime; // rax
	DWORD dwLowDateTime; // ebx
	HANDLE dwProcessId; // ecx
	SYSTEM_PROCESS_INFORMATION *v13; // eax
	ULONG v14; // eax
	_RTL_PROCESS_MODULES *v15; // eax
	ULONG v16; // esi
	_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfor; // edi
	__int64 v18; // rax
	ULONGLONG v19; // kr10_8
	int v20; // ebx
	unsigned int v21; // ecx
	int v22; // esi
	LPARAM v23; // ecx
	int v24; // eax
	void *v25; // eax
	LPARAM v26; // edi
	unsigned int v27; // ecx
	__int64 v28; // rax
	bool v29; // cf
	int v30; // ecx
	int v31; // edx
	double v32; // xmm0_8
	WPARAM v33; // edx
	int v34; // ecx
	double v35; // xmm0_8
	char v36; // dl
	double v37; // xmm1_8
	LPARAM v38; // ecx
	double v39; // xmm1_8
	char v40; // dh
	signed int v41; // eax
	char v42; // al
	int v43; // eax
	void *ThreadHandle_1; // ecx
	tagThreadItem *v45; // esi
	int v46; // eax
	HANDLE v47; // edx
	const wchar_t *v48; // eax
	HWND hWndParent_1; // ebx
	HWND v50; // eax
	HWND v51; // eax
	HWND v52; // eax
	HWND v53; // eax
	HANDLE v54; // edi
	tagThreadItem *v55; // edi
	HWND v56; // esi
	char LocalBuffer2; // [esp-294h] [ebp-E24h]
	int v59; // [esp-290h] [ebp-E20h]
	int v60; // [esp-28Ch] [ebp-E1Ch]
	int v61; // [esp-288h] [ebp-E18h]
	int v62; // [esp-284h] [ebp-E14h]
	int v63; // [esp-280h] [ebp-E10h]
	int v64; // [esp-27Ch] [ebp-E0Ch]
	int v65; // [esp-278h] [ebp-E08h]
	int v66; // [esp-274h] [ebp-E04h]
	int v67; // [esp-270h] [ebp-E00h]
	int v68; // [esp-26Ch] [ebp-DFCh]
	int v69; // [esp-268h] [ebp-DF8h]
	int v70; // [esp-264h] [ebp-DF4h]
	int v71; // [esp-260h] [ebp-DF0h]
	int v72; // [esp-25Ch] [ebp-DECh]
	int v73; // [esp-258h] [ebp-DE8h]
	int v74; // [esp-254h] [ebp-DE4h]
	int v75; // [esp-250h] [ebp-DE0h]
	int v76; // [esp-24Ch] [ebp-DDCh]
	int v77; // [esp-248h] [ebp-DD8h]
	int v78; // [esp-244h] [ebp-DD4h]
	int v79; // [esp-240h] [ebp-DD0h]
	int v80; // [esp-23Ch] [ebp-DCCh]
	int v81; // [esp-238h] [ebp-DC8h]
	int v82; // [esp-234h] [ebp-DC4h]
	int v83; // [esp-230h] [ebp-DC0h]
	int v84; // [esp-22Ch] [ebp-DBCh]
	int v85; // [esp-228h] [ebp-DB8h]
	int v86; // [esp-224h] [ebp-DB4h]
	int v87; // [esp-220h] [ebp-DB0h]
	int v88; // [esp-21Ch] [ebp-DACh]
	int v89; // [esp-218h] [ebp-DA8h]
	int v90; // [esp-214h] [ebp-DA4h]
	int v91; // [esp-210h] [ebp-DA0h]
	int v92; // [esp-20Ch] [ebp-D9Ch]
	int v93; // [esp-208h] [ebp-D98h]
	int v94; // [esp-204h] [ebp-D94h]
	int v95; // [esp-200h] [ebp-D90h]
	int v96; // [esp-1FCh] [ebp-D8Ch]
	int v97; // [esp-1F8h] [ebp-D88h]
	int v98; // [esp-1F4h] [ebp-D84h]
	int v99; // [esp-1F0h] [ebp-D80h]
	int v100; // [esp-1ECh] [ebp-D7Ch]
	int v101; // [esp-1E8h] [ebp-D78h]
	int v102; // [esp-1E4h] [ebp-D74h]
	int v103; // [esp-1E0h] [ebp-D70h]
	int v104; // [esp-1DCh] [ebp-D6Ch]
	int v105; // [esp-1D8h] [ebp-D68h]
	int v106; // [esp-1D4h] [ebp-D64h]
	int v107; // [esp-1D0h] [ebp-D60h]
	int v108; // [esp-1CCh] [ebp-D5Ch]
	int v109; // [esp-1C8h] [ebp-D58h]
	int v110; // [esp-1C4h] [ebp-D54h]
	int v111; // [esp-1C0h] [ebp-D50h]
	int v112; // [esp-1BCh] [ebp-D4Ch]
	int v113; // [esp-1B8h] [ebp-D48h]
	int v114; // [esp-1B4h] [ebp-D44h]
	int v115; // [esp-1B0h] [ebp-D40h]
	int v116; // [esp-1ACh] [ebp-D3Ch]
	int v117; // [esp-1A8h] [ebp-D38h]
	int v118; // [esp-1A4h] [ebp-D34h]
	int v119; // [esp-1A0h] [ebp-D30h]
	int v120; // [esp-19Ch] [ebp-D2Ch]
	int v121; // [esp-198h] [ebp-D28h]
	int v122; // [esp-194h] [ebp-D24h]
	int v123; // [esp-190h] [ebp-D20h]
	int v124; // [esp-18Ch] [ebp-D1Ch]
	int v125; // [esp-188h] [ebp-D18h]
	int v126; // [esp-184h] [ebp-D14h]
	int v127; // [esp-180h] [ebp-D10h]
	int v128; // [esp-17Ch] [ebp-D0Ch]
	int v129; // [esp-178h] [ebp-D08h]
	int v130; // [esp-174h] [ebp-D04h]
	int v131; // [esp-170h] [ebp-D00h]
	int v132; // [esp-16Ch] [ebp-CFCh]
	int v133; // [esp-168h] [ebp-CF8h]
	int v134; // [esp-164h] [ebp-CF4h]
	int v135; // [esp-160h] [ebp-CF0h]
	int v136; // [esp-15Ch] [ebp-CECh]
	int v137; // [esp-158h] [ebp-CE8h]
	int v138; // [esp-154h] [ebp-CE4h]
	int v139; // [esp-150h] [ebp-CE0h]
	int v140; // [esp-14Ch] [ebp-CDCh]
	int v141; // [esp-148h] [ebp-CD8h]
	int v142; // [esp-144h] [ebp-CD4h]
	int v143; // [esp-140h] [ebp-CD0h]
	int v144; // [esp-13Ch] [ebp-CCCh]
	int v145; // [esp-138h] [ebp-CC8h]
	int v146; // [esp-134h] [ebp-CC4h]
	int v147; // [esp-130h] [ebp-CC0h]
	int v148; // [esp-12Ch] [ebp-CBCh]
	int v149; // [esp-128h] [ebp-CB8h]
	int v150; // [esp-124h] [ebp-CB4h]
	int v151; // [esp-120h] [ebp-CB0h]
	int v152; // [esp-11Ch] [ebp-CACh]
	int v153; // [esp-118h] [ebp-CA8h]
	int v154; // [esp-114h] [ebp-CA4h]
	int v155; // [esp-110h] [ebp-CA0h]
	int v156; // [esp-10Ch] [ebp-C9Ch]
	int v157; // [esp-108h] [ebp-C98h]
	int v158; // [esp-104h] [ebp-C94h]
	int v159; // [esp-100h] [ebp-C90h]
	int v160; // [esp-FCh] [ebp-C8Ch]
	int v161; // [esp-F8h] [ebp-C88h]
	int v162; // [esp-F4h] [ebp-C84h]
	int v163; // [esp-F0h] [ebp-C80h]
	int v164; // [esp-ECh] [ebp-C7Ch]
	int v165; // [esp-E8h] [ebp-C78h]
	int v166; // [esp-E4h] [ebp-C74h]
	int v167; // [esp-E0h] [ebp-C70h]
	int v168; // [esp-DCh] [ebp-C6Ch]
	int v169; // [esp-D8h] [ebp-C68h]
	int v170; // [esp-D4h] [ebp-C64h]
	int v171; // [esp-D0h] [ebp-C60h]
	int v172; // [esp-CCh] [ebp-C5Ch]
	int v173; // [esp-C8h] [ebp-C58h]
	int v174; // [esp-C4h] [ebp-C54h]
	int v175; // [esp-C0h] [ebp-C50h]
	int v176; // [esp-BCh] [ebp-C4Ch]
	int v177; // [esp-B8h] [ebp-C48h]
	int v178; // [esp-B4h] [ebp-C44h]
	int v179; // [esp-B0h] [ebp-C40h]
	int v180; // [esp-ACh] [ebp-C3Ch]
	int v181; // [esp-A8h] [ebp-C38h]
	int v182; // [esp-A4h] [ebp-C34h]
	int v183; // [esp-A0h] [ebp-C30h]
	int v184; // [esp-9Ch] [ebp-C2Ch]
	int v185; // [esp-98h] [ebp-C28h]
	int v186; // [esp-94h] [ebp-C24h]
	int v187; // [esp-90h] [ebp-C20h]
	int v188; // [esp-8Ch] [ebp-C1Ch]
	int v189; // [esp-88h] [ebp-C18h]
	int v190; // [esp-84h] [ebp-C14h]
	int v191; // [esp-80h] [ebp-C10h]
	int v192; // [esp-7Ch] [ebp-C0Ch]
	int v193; // [esp-78h] [ebp-C08h]
	int v194; // [esp-74h] [ebp-C04h]
	int v195; // [esp-70h] [ebp-C00h]
	int v196; // [esp-6Ch] [ebp-BFCh]
	int v197; // [esp-68h] [ebp-BF8h]
	int v198; // [esp-64h] [ebp-BF4h]
	int v199; // [esp-60h] [ebp-BF0h]
	int v200; // [esp-5Ch] [ebp-BECh]
	int v201; // [esp-58h] [ebp-BE8h]
	int v202; // [esp-54h] [ebp-BE4h]
	int v203; // [esp-50h] [ebp-BE0h]
	int v204; // [esp-4Ch] [ebp-BDCh]
	int v205; // [esp-48h] [ebp-BD8h]
	int v206; // [esp-44h] [ebp-BD4h]
	int v207; // [esp-40h] [ebp-BD0h]
	int v208; // [esp-3Ch] [ebp-BCCh]
	int v209; // [esp-38h] [ebp-BC8h]
	int v210; // [esp-34h] [ebp-BC4h]
	int v211; // [esp-30h] [ebp-BC0h]
	int v212; // [esp-2Ch] [ebp-BBCh]
	int v213; // [esp-28h] [ebp-BB8h]
	int v214; // [esp-24h] [ebp-BB4h]
	int v215; // [esp-20h] [ebp-BB0h]
	int v216; // [esp-1Ch] [ebp-BACh]
	int v217; // [esp-18h] [ebp-BA8h]
	_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfor_1; // [esp-14h] [ebp-BA4h]
	unsigned __int64 timeDelta; // [esp-10h] [ebp-BA0h]
	PRTL_DEBUG_BUFFER dwNumberOfProcessors; // [esp-8h] [ebp-B98h]
	_RTL_PROCESS_MODULES *bFalse; // [esp-4h] [ebp-B94h]
	LPARAM lParam; // [esp+Ch] [ebp-B84h]
	int v223; // [esp+18h] [ebp-B78h]
	int v224; // [esp+1Ch] [ebp-B74h]
	THREAD_BASIC_INFORMATION ThreadInformation; // [esp+24h] [ebp-B6Ch]
	SIZE_T NumberOfBytesRead; // [esp+40h] [ebp-B50h]
	ULONG ReturnLength; // [esp+44h] [ebp-B4Ch]
	CLIENT_ID ClientID; // [esp+48h] [ebp-B48h]
	int v229; // [esp+50h] [ebp-B40h]
	HANDLE hEvent2[2]; // [esp+54h] [ebp-B3Ch]
	size_t cbRet; // [esp+5Ch] [ebp-B34h]
	int v232; // [esp+60h] [ebp-B30h]
	double v233; // [esp+64h] [ebp-B2Ch]
	int ThreadHandle; // [esp+6Ch] [ebp-B24h]
	tagLVITEMW item; // [esp+70h] [ebp-B20h]
	WPARAM wParam; // [esp+A4h] [ebp-AECh]
	WPARAM v237; // [esp+A8h] [ebp-AE8h]
	_DWORD v238[2]; // [esp+ACh] [ebp-AE4h]
	WPARAM v239; // [esp+B4h] [ebp-ADCh]
	WPARAM v240; // [esp+B8h] [ebp-AD8h]
	WPARAM v241; // [esp+BCh] [ebp-AD4h]
	unsigned int dwTebAddress; // [esp+C0h] [ebp-AD0h]
	unsigned int v243; // [esp+C4h] [ebp-ACCh]
	int v244; // [esp+C8h] [ebp-AC8h]
	HANDLE hHandle; // [esp+CCh] [ebp-AC4h]
	HWND hWndParent; // [esp+D0h] [ebp-AC0h]
	int nItem; // [esp+D4h] [ebp-ABCh]
	int nIndex; // [esp+D8h] [ebp-AB8h]
	char dwHighDateTime[4]; // [esp+DCh] [ebp-AB4h]
	HWND hWndList_1; // [esp+E0h] [ebp-AB0h]
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+E4h] [ebp-AACh]
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // [esp+E8h] [ebp-AA8h]
	tagThreadItem *pThreadItem_1; // [esp+ECh] [ebp-AA4h]
	int v254; // [esp+F3h] [ebp-A9Dh]
	char fOK; // [esp+FBh] [ebp-A95h]
	int LocalBuffer[164]; // [esp+FCh] [ebp-A94h]
	__int16 String[1024]; // [esp+38Ch] [ebp-804h]

	hWndList = pThreadItem->m_hWndList;
	pThreadItem_1 = pThreadItem;
	hWndList_1 = hWndList;
	pSystemProcessInfo = 0;
	cbRet = 0;
	item.mask = 0;
	memset(&item.iItem, 0, 0x30u);
	MulDiv(-50, gLogPixelSize.x, 96);
	MulDiv(-100, gLogPixelSize.x, 96);
	MulDiv(-100, gLogPixelSize.x, 96);
	MulDiv(100, gLogPixelSize.x, 96);
	pThreadItem_2 = pThreadItem_1;
	bFalse = INFINITE;
	dwNumberOfProcessors = 0;
	hHandle = 0;
	hEvent2[0] = pThreadItem_1->m_hEvent2;
	hEvent2[1] = pThreadItem_1->m_hEvent3;
	fOK = 1;
	dwRet = WaitForMultipleObjects(2u, hEvent2, 0, INFINITE);
	SendMessageW = ::SendMessageW;
	if (pThreadItem_2->field_18)
		goto __cleanup;
	LOBYTE(v4) = v254;
	v240 = v237;
	*(&v254 + 1) = v4;
	v241 = wParam;
	while (1)
	{
		nItem = 0;
		nIndex = 0;
		*dwHighDateTime = 0;
		if (dwRet)
			goto LABEL_85;
		BYTE1(v254) = 0;
		hWndParent = GetParent(hWndList);
		if (!fOK)
		{
			item.mask = LVIF_PARAM;
			nCount = SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
			item.iSubItem = 0;
			item.iItem = nCount - 1;
			if (SendMessageW(hWndList, LVM_GETITEMW, 0, &item))
			{
				nIndex_1 = nIndex;
				do
				{
					v8 = sub_4858D0(hWndList, &item, item.lParam, &v254);
					v9 = BYTE1(v254);
					if (v8)
						v9 = 1;
					*(&v254 + 1) = v9;
					if (v254)
					{
						if (*(item.lParam + 12) != 1)
							--*(item.lParam + 20);
						++nIndex_1;
					}
					item.mask = 4;
					item.iSubItem = 0;
				} while (SendMessageW(hWndList, LVM_GETITEMW, 0, &item));
				nIndex = nIndex_1;
				pThreadItem_2 = pThreadItem_1;
			}
		}
		FileTime = GetSystemProcessInfo(&pSystemProcessInfo, &cbRet);
		dwLowDateTime = FileTime.dwLowDateTime;
		*dwHighDateTime = FileTime.dwHighDateTime;
		pSystemProcessInfo_1 = pSystemProcessInfo;
		dwProcessId = *(pThreadItem_2->m_Param + 68);
		if (pSystemProcessInfo->UniqueProcessId != dwProcessId)
			break;
	LABEL_19:
		*&dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
		timeDelta = __PAIR__(FileTime.dwHighDateTime, dwLowDateTime) - *&pThreadItem_2->m_TimeLast;
		v239 = timeDelta * gSystemInfo.dwNumberOfProcessors >> 32;
		v244 = timeDelta * gSystemInfo.dwNumberOfProcessors;
		if (!(timeDelta * gSystemInfo.dwNumberOfProcessors))
		{
			v244 = 1;
			v239 = 0;
		}
		v15 = *dwHighDateTime;
		pThreadItem_2->m_TimeLast.dwLowDateTime = dwLowDateTime;
		pThreadItem_2->m_TimeLast.dwHighDateTime = v15;
		if (GetProcessorSystemCycleTime)
		{
			v16 = 8 * gSystemInfo.dwNumberOfProcessors;
			pSystemProcessorCycleTimeInfor = malloc(8 * gSystemInfo.dwNumberOfProcessors);
			NtQuerySystemInformation(SystemProcessorCycleTimeInformation, pSystemProcessorCycleTimeInfor, v16, &ReturnLength);
			LODWORD(v18) = sub_46E4B0(0, pSystemProcessInfo, pSystemProcessorCycleTimeInfor, 0);
			pThreadItem_2 = pThreadItem_1;
			pSystemProcessorCycleTimeInfor_1 = pSystemProcessorCycleTimeInfor;
			v19 = v18 - pThreadItem_1->m_CycleTime;
			v240 = (v18 - pThreadItem_1->m_CycleTime) >> 32;
			v241 = v19;
			LODWORD(pThreadItem_1->m_CycleTime) = v18;
			HIDWORD(pThreadItem_2->m_CycleTime) = HIDWORD(v18);
			free(pSystemProcessorCycleTimeInfor_1);
			hWndList = hWndList_1;
		}
		v20 = &pSystemProcessInfo_1[1];
		if (pThreadItem_2->field_34)
			v20 = &pSystemProcessInfo_1->ReadOperationCount;
		v21 = 0;
		*dwHighDateTime = pSystemProcessInfo_1->NumberOfThreads;
		v243 = 0;
		if (*dwHighDateTime)
		{
			while (1)
			{
				if (pThreadItem_2->field_18)
					goto __cleanup1;
				if (!*(v20 + 36))
					*(v20 + 36) = v21;
				v22 = 0;
				if (::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0))
					break;
			LABEL_61:
				if (pThreadItem_1->field_18)
				{
					pThreadItem_2 = pThreadItem_1;
					goto __cleanup1;
				}
				if (v22 == ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0))
				{
					BYTE1(v254) = 1;
					memset(LocalBuffer, 0, 0x290u);
					LocalBuffer[1] = 3;
					ClientID.UniqueThread = *(v20 + 36);
					ClientID.UniqueProcess = 0;
					ThreadInformation.TebBaseAddrss = sizeof(OBJECT_ATTRIBUTES);
					ThreadInformation.ClientId.UniqueProcess = 0;
					ThreadInformation.AffinityMask = 0;
					ThreadInformation.ClientId.UniqueThread = 0;
					ThreadInformation.Priority = 0;
					ThreadInformation.BasePriority = 0;
					v43 = NtOpenThread(&ThreadHandle, 0x48u, &ThreadInformation.TebBaseAddrss, &ClientID);
					ThreadHandle_1 = 0;
					if (!v43)
						ThreadHandle_1 = ThreadHandle;
					LocalBuffer[10] = ThreadHandle_1;
					if (QueryThreadCycleTime && ThreadHandle_1)
						QueryThreadCycleTime(ThreadHandle_1, &LocalBuffer[154]);
					v45 = pThreadItem_1;
					LocalBuffer[11] = *(v20 + 36);
					LocalBuffer[148] = *(v20 + 48);
					bFalse = pThreadItem_1->m_SystemModules;
					LocalBuffer[149] = 0;
					dwNumberOfProcessors = pThreadItem_1->m_DebugBuffer;
					LocalBuffer[12] = *(v20 + 28);
					sub_46DD60(
						0,
						0,
						LocalBuffer,
						pThreadItem_1->m_hProcess,
						*(v20 + 28),
						*(v20 + 28) >> 31,
						dwNumberOfProcessors,
						bFalse);
					*&LocalBuffer[156] = *v20 + *(v20 + 8);
					v46 = 2;
					if (fOK)
						v46 = 0;
					LocalBuffer[5] = 0;
					LocalBuffer[4] = v46;
					LocalBuffer[158] = v45->m_Param;
					*&LocalBuffer[144] = 0i64;
					LocalBuffer[162] = 0;
					if (GetThreadIdealProcessorEx)
						GetThreadIdealProcessorEx(LocalBuffer[10], &LocalBuffer[152]);
					if (*(v45->m_Param + 40) & 0x20 && gdwVersion >= 1)
					{
						if (!NtQueryInformationThread(
							LocalBuffer[10],
							ThreadBasicInformation,
							&ThreadInformation,
							sizeof(_THREAD_BASIC_INFORMATION),
							0))
						{
							v47 = v45->m_hProcess;
							LocalBuffer[160] = ThreadInformation.TebBaseAddrss;
							LocalBuffer[159] = v47;
							ReadProcessMemory(
								v47,
								ThreadInformation.TebBaseAddrss + gdwTebAddressOffset,
								&dwTebAddress,
								4u,
								&NumberOfBytesRead);
							LocalBuffer[161] = dwTebAddress;
							if (dwTebAddress)
							{
								if (sub_48EFB0(dwTebAddress))
								{
									v48 = sub_48EFB0(dwTebAddress);
									LocalBuffer[162] = _wcsdup(v48);
								}
							}
						}
					}
					else
					{
						LocalBuffer[161] = -1;
					}
					qmemcpy(&LocalBuffer2, LocalBuffer, 656u);
					hWndList = hWndList_1;
					sub_447E70(
						hWndList_1,
						LocalBuffer2,
						v59,
						v60,
						v61,
						v62,
						v63,
						v64,
						v65,
						v66,
						v67,
						v68,
						v69,
						v70,
						v71,
						v72,
						v73,
						v74,
						v75,
						v76,
						v77,
						v78,
						v79,
						v80,
						v81,
						v82,
						v83,
						v84,
						v85,
						v86,
						v87,
						v88,
						v89,
						v90,
						v91,
						v92,
						v93,
						v94,
						v95,
						v96,
						v97,
						v98,
						v99,
						v100,
						v101,
						v102,
						v103,
						v104,
						v105,
						v106,
						v107,
						v108,
						v109,
						v110,
						v111,
						v112,
						v113,
						v114,
						v115,
						v116,
						v117,
						v118,
						v119,
						v120,
						v121,
						v122,
						v123,
						v124,
						v125,
						v126,
						v127,
						v128,
						v129,
						v130,
						v131,
						v132,
						v133,
						v134,
						v135,
						v136,
						v137,
						v138,
						v139,
						v140,
						v141,
						v142,
						v143,
						v144,
						v145,
						v146,
						v147,
						v148,
						v149,
						v150,
						v151,
						v152,
						v153,
						v154,
						v155,
						v156,
						v157,
						v158,
						v159,
						v160,
						v161,
						v162,
						v163,
						v164,
						v165,
						v166,
						v167,
						v168,
						v169,
						v170,
						v171,
						v172,
						v173,
						v174,
						v175,
						v176,
						v177,
						v178,
						v179,
						v180,
						v181,
						v182,
						v183,
						v184,
						v185,
						v186,
						v187,
						v188,
						v189,
						v190,
						v191,
						v192,
						v193,
						v194,
						v195,
						v196,
						v197,
						v198,
						v199,
						v200,
						v201,
						v202,
						v203,
						v204,
						v205,
						v206,
						v207,
						v208,
						v209,
						v210,
						v211,
						v212,
						v213,
						v214,
						v215,
						v216,
						v217,
						pSystemProcessorCycleTimeInfor_1,
						timeDelta,
						SHIDWORD(timeDelta),
						dwNumberOfProcessors,
						v45);
					pThreadItem_2 = pThreadItem_1;
					SetEvent(pThreadItem_1->m_hEvent);
				}
				else
				{
					pThreadItem_2 = pThreadItem_1;
				}
				v20 += 64;
				v21 = v243 + 1;
				v243 = v21;
				if (v21 >= pSystemProcessInfo_1->NumberOfThreads)
					goto LABEL_82;
			}
			while (1)
			{
				item.mask = 4;
				item.iItem = v22;
				item.iSubItem = 0;
				::SendMessageW(hWndList, LVM_GETITEMW, 0, &item);
				v23 = item.lParam;
				if (*(item.lParam + 44) == *(v20 + 36))
					break;
				if (++v22 >= ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0))
					goto LABEL_61;
			}
			v24 = *(v20 + 48) - *(item.lParam + 592);
			if (v24 != *(item.lParam + 584) || 0 != *(item.lParam + 588))
			{
				if (v24 <= 0)
					*(item.lParam + 584) = 0;
				else
					*(item.lParam + 584) = v24;
				*(v23 + 588) = 0;
				v23 = item.lParam;
				BYTE1(v254) = 1;
			}
			*(v23 + 592) = *(v20 + 48);
			*(item.lParam + 596) = 0;
			if (QueryThreadCycleTime)
			{
				v25 = *(item.lParam + 40);
				if (v25)
				{
					QueryThreadCycleTime(v25, v238);
					if (((*v238 - *(item.lParam + 616)) >> 32) < 0
						|| (*v238 < *(item.lParam + 616) || (*v238 - *(item.lParam + 616)) >> 32 == 0)
						&& v238[0] == *(item.lParam + 616))
					{
						*(item.lParam + 600) = 0;
						*(item.lParam + 604) = 0;
					}
					else
					{
						*(item.lParam + 600) = *v238 - *(item.lParam + 616);
					}
					BYTE1(v254) = 1;
				}
			}
			*(item.lParam + 616) = v238[0];
			*(item.lParam + 620) = v238[1];
			v26 = item.lParam;
			v27 = *v20 + *(v20 + 8);
			v28 = *v20 + *(v20 + 8);
			v232 = HIDWORD(v28);
			v29 = v27 < *(item.lParam + 624);
			v30 = v27 - *(item.lParam + 624);
			v229 = v28;
			v31 = HIDWORD(v28) - (v29 + *(item.lParam + 628));
			if (GetProcessorSystemCycleTime && *(item.lParam + 40))
			{
				v32 = *(item.lParam + 600);
				v33 = v240;
				v34 = v241;
			}
			else
			{
				v32 = __PAIR__(v31, v30);
				v33 = v239;
				v34 = v244;
			}
			v233 = v32 * 100.0;
			v35 = __PAIR__(v33, v34);
			v36 = 0;
			v37 = v233;
			++nItem;
			*(item.lParam + 624) = v229;
			*(v26 + 628) = v232;
			v38 = item.lParam;
			v39 = v37 / v35;
			v40 = *(item.lParam + 24);
			if (v40)
			{
				v41 = *(item.lParam + 28);
				if (v41 < gConfig.dwHighlightDuration)
				{
					*(item.lParam + 16) = 2;
					*(v38 + 20) = v41;
				LABEL_59:
					hWndList = hWndList_1;
					if (v39 != *(item.lParam + 576))
					{
						*(item.lParam + 576) = v39;
						BYTE1(v254) = 1;
					}
					goto LABEL_61;
				}
				if (v40)
				{
					v36 = 1;
					*(item.lParam + 24) = 0;
				}
			}
			v42 = BYTE1(v254);
			*(v38 + 16) = 0;
			if (v36)
				v42 = 1;
			BYTE1(v254) = v42;
			goto LABEL_59;
		}
	LABEL_82:
		SendMessageW = ::SendMessageW;
		if (pThreadItem_2->field_18)
			goto __cleanup;
		if (nItem == nIndex)
		{
			LOBYTE(v4) = BYTE1(v254);
		LABEL_85:
			if (!v4)
				goto LABEL_87;
		}
		InvalidateRect(hWndList, 0, 0);
		v237 = ::wParam;
		wParam = 1044;
		SendMessageW(hWndList, LVM_SORTITEMS, &wParam, PropProcThreadsSortCallback);
		SendMessageW(hWndList, WM_SETREDRAW, 1u, 0);
		bFalse = *dwHighDateTime;
		wsprintfW(String, L"%d", *dwHighDateTime);
		SetDlgItemTextW(hWndParent, IDC_PAGE_PROCTHREADS_STATIC_STATIC, String);
	LABEL_87:
		if (fOK)
		{
			SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 3u, 65534);
			v224 = 3;
			v223 = 3;
			SendMessageW(hWndList, LVM_SETITEMSTATE, 0, &lParam);
			hHandle = _beginthreadex(0, 0, sub_47D400, pThreadItem_2, 0, 0);
			fOK = 0;
		}
		if (pThreadItem_2->field_4)
			goto __cleanup;
		dwRet = WaitForMultipleObjects(2u, hEvent2, 0, 0xFFFFFFFF);
		if (pThreadItem_2->field_18)
			goto __cleanup;
		LOBYTE(v4) = BYTE1(v254);
	}
	v13 = pSystemProcessInfo_1;
	while (1)
	{
		v14 = v13->NextEntryOffset;
		if (!v14)
			break;
		pSystemProcessInfo_1 = (pSystemProcessInfo_1 + v14);
		v13 = pSystemProcessInfo_1;
		if (pSystemProcessInfo_1->UniqueProcessId == dwProcessId)
			goto LABEL_19;
	}
	wsprintfW(String, L"n/a");
	hWndParent_1 = hWndParent;
	SetDlgItemTextW(hWndParent, IDC_PAGE_PROCTHREADS_STATIC_THREAD_ID_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_START_TIME_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_CONTEXT_SWITCHES_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_KERNEL_TIME_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_USER_TIME_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_STATE_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, String);
	SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE, String);
	InvalidateRect(hWndList, 0, 1);
	bFalse = 0;
	v50 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_MODULE);
	EnableWindow(v50, bFalse);
	bFalse = 0;
	v51 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
	EnableWindow(v51, bFalse);
	bFalse = 0;
	v52 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
	EnableWindow(v52, bFalse);
	bFalse = 0;
	v53 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
	EnableWindow(v53, bFalse);
	pThreadItem_2 = pThreadItem_1;
__cleanup1:
	SendMessageW = ::SendMessageW;
__cleanup:
	free(pSystemProcessInfo);
	if (pThreadItem_2->field_4 || InterlockedDecrement(&pThreadItem_2->m_nRefCount))
	{
		v56 = hWndList_1;
		InvalidateRect(hWndList_1, 0, 1);
		SendMessageW(v56, WM_SETREDRAW, 1u, 0);
	}
	else
	{
		v54 = hHandle;
		if (hHandle)
		{
			SetEvent(pThreadItem_2->m_hEvent);
			WaitForSingleObject(v54, 0xFFFFFFFF);
		}
		v55 = pThreadItem_2->m_Next;
		if (pThreadItem_2->m_Next)
		{
			do
			{
				pThreadItem_2->m_Next = v55;
				v55 = v55[8].m_hEvent3;
				if (pThreadItem_2->m_Next->m_SystemModules)
					CloseHandle(pThreadItem_2->m_Next->m_SystemModules);
				if (pThreadItem_2->m_Next[7].m_hEvent3)
					free(pThreadItem_2->m_Next[7].m_hEvent3);
				if (pThreadItem_2->m_Next[8].m_hEvent2)
					free(pThreadItem_2->m_Next[8].m_hEvent2);
				free(pThreadItem_2->m_Next);
			} while (v55);
		}
		if (pThreadItem_2->m_hProcess)
		{
			CloseHandle(pThreadItem_2->m_hProcess);
			if (dword_4FF29C)
				dword_4FF29C(pThreadItem_2->m_hProcess);
		}
		CloseHandle(pThreadItem_2->m_hEvent);
		CloseHandle(pThreadItem_2->m_hEvent2);
		CloseHandle(pThreadItem_2->m_hEvent3);
		if (pThreadItem_2->m_DebugBuffer)
			RtlDestroyQueryDebugBuffer(pThreadItem_2->m_DebugBuffer);
		if (pThreadItem_2->m_SystemModules)
			free(pThreadItem_2->m_SystemModules);
		free(pThreadItem_2);
	}
	return 0;
}


int __stdcall PageProcThreads(HWND hWnd, int uMsg, WPARAM wParam, int a4)
{
	HWND hWnd_1; // ebx
	tagThreadItem *pUserData; // edi
	int v6; // ST20_4
	tagThreadItem *v7; // eax
	CResizer *pResizer; // esi
	HWND hWndList_1; // eax
	int v10; // eax
	HWND v11; // eax
	_OWORD *v12; // eax
	HWND v13; // ST20_4
	HWND v14; // eax
	_OWORD *v15; // eax
	HWND v16; // ST20_4
	HWND v17; // eax
	_OWORD *v18; // eax
	HWND v19; // ST20_4
	HWND v20; // eax
	_OWORD *v21; // eax
	HWND v22; // ST20_4
	HWND v23; // eax
	_OWORD *v24; // eax
	HWND v25; // ST20_4
	HWND v26; // eax
	_OWORD *v27; // eax
	HWND v28; // ST20_4
	HWND v29; // eax
	_OWORD *v30; // eax
	HWND v31; // ST20_4
	HWND v32; // eax
	HWND v33; // eax
	HWND v34; // eax
	_OWORD *v35; // eax
	HWND v36; // ST20_4
	__int128 *v37; // ecx
	HWND v38; // eax
	HWND v39; // eax
	HWND v40; // eax
	HWND v41; // eax
	HWND v42; // eax
	HWND v43; // eax
	int v44; // ST24_4
	HWND v45; // eax
	int v46; // ST24_4
	HWND v47; // eax
	tagThreadItem *pThreadItem; // esi
	HCURSOR lParam_1; // eax
	HWND hWndList; // eax
	LONG v51; // eax
	HWND v52; // eax
	SYSTEM_PROCESS_INFORMATION *v53; // edi
	HANDLE v54; // ecx
	HCURSOR v55; // eax
	HCURSOR v56; // eax
	int v57; // ecx
	HANDLE v58; // eax
	int v59; // eax
	int result; // eax
	HANDLE v61; // eax
	HANDLE v62; // eax
	_RTL_PROCESS_MODULES *v63; // eax
	_RTL_PROCESS_MODULES *v64; // eax
	int v65; // eax
	struct _RTL_DEBUG_BUFFER *v66; // eax
	void *hThread; // edi
	struct _IMAGELIST *v68; // ebx
	HICON v69; // eax
	HICON v70; // eax
	tagThreadItem *pThreadItem_2; // esi
	LONG v72; // eax
	HANDLE v73; // eax
	void *v74; // ST24_4
	HWND v75; // esi
	HWND(__stdcall *v76)(HWND, int); // edi
	HWND v77; // eax
	HWND v78; // eax
	HWND v79; // eax
	HWND v80; // eax
	HWND v81; // eax
	tagNMHDR *pNMHDR; // esi
	UINT v83; // eax
	HWND v84; // eax
	HWND v85; // eax
	HWND v86; // eax
	HWND v87; // eax
	HWND v88; // eax
	HWND v89; // eax
	HWND v90; // eax
	BOOL v91; // ST24_4
	HWND v92; // eax
	BOOL v93; // ST24_4
	HWND v94; // eax
	BOOL v95; // eax
	BOOL v96; // ST24_4
	HWND v97; // eax
	BOOL v98; // eax
	BOOL v99; // ST24_4
	HWND v100; // eax
	BOOL v101; // eax
	BOOL v102; // ST24_4
	HWND v103; // eax
	SYSTEM_PROCESS_INFORMATION *v104; // ecx
	HANDLE v105; // edx
	HCURSOR v106; // esi
	ULONG v107; // edx
	bool v108; // zf
	HWND v109; // ebx
	HCURSOR v110; // ebx
	HWND hWnd_2; // ebx
	HCURSOR lParamIn_1; // esi
	HWND v113; // eax
	unsigned int v114; // eax
	const WCHAR *v115; // eax
	HWND v116; // esi
	void *v117; // eax
	tagThreadItem *v118; // eax
	void *ThreadHandle; // esi
	void *v120; // esi
	HWND v121; // eax
	wchar_t *v122; // ecx
	__int16 *v123; // eax
	bool v124; // cf
	unsigned __int16 v125; // dx
	int v126; // eax
	LPARAM v127; // esi
	void *v128; // eax
	HWND v129; // eax
	void *v130; // ST24_4
	WPARAM v131; // [esp-8h] [ebp-1E98h]
	const WCHAR *v132; // [esp-4h] [ebp-1E94h]
	int v133; // [esp-4h] [ebp-1E94h]
	int v134; // [esp-4h] [ebp-1E94h]
	char v135[572]; // [esp+10h] [ebp-1E80h]
	int v136[21]; // [esp+24Ch] [ebp-1C44h]
	SHELLEXECUTEINFOW pExecInfo; // [esp+2A0h] [ebp-1BF0h]
	tagNMHDR nmhdr; // [esp+2DCh] [ebp-1BB4h]
	int v139; // [esp+2E8h] [ebp-1BA8h]
	struct _FILETIME LocalFileTime; // [esp+2F0h] [ebp-1BA0h]
	LPARAM dwInitParam; // [esp+2F8h] [ebp-1B98h]
	int v142; // [esp+2FCh] [ebp-1B94h]
	HANDLE hObject; // [esp+300h] [ebp-1B90h]
	HANDLE v144; // [esp+304h] [ebp-1B8Ch]
	_RTL_PROCESS_MODULES *v145; // [esp+308h] [ebp-1B88h]
	PRTL_DEBUG_BUFFER v146; // [esp+30Ch] [ebp-1B84h]
	int v147; // [esp+310h] [ebp-1B80h]
	PRTL_DEBUG_BUFFER v148; // [esp+314h] [ebp-1B7Ch]
	ULONG ReturnLength; // [esp+318h] [ebp-1B78h]
	int v150; // [esp+31Ch] [ebp-1B74h]
	DWORD ExitCode; // [esp+320h] [ebp-1B70h]
	DWORD ThreadId; // [esp+324h] [ebp-1B6Ch]
	tagLVITEMW lParam; // [esp+328h] [ebp-1B68h]
	int ThreadInformation; // [esp+35Ch] [ebp-1B34h]
	char ArgList[4]; // [esp+360h] [ebp-1B30h]
	int v156; // [esp+364h] [ebp-1B2Ch]
	HWND hWnd_3; // [esp+368h] [ebp-1B28h]
	SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+36Ch] [ebp-1B24h]
	ULONG SystemInformationLength; // [esp+370h] [ebp-1B20h]
	tagThreadItem *pThreadItem_1; // [esp+374h] [ebp-1B1Ch]
	HCURSOR lParamIn; // [esp+378h] [ebp-1B18h]
	HWND v162; // [esp+37Ch] [ebp-1B14h]
	char v163; // [esp+380h] [ebp-1B10h]
	DWORD v164; // [esp+3A4h] [ebp-1AECh]
	int v165; // [esp+3A8h] [ebp-1AE8h]
	void *v166; // [esp+3ACh] [ebp-1AE4h]
	__int16 szText[64]; // [esp+3B8h] [ebp-1AD8h]
	__int16 szBuffer[2052]; // [esp+438h] [ebp-1A58h]
	struct _SYSTEMTIME SystemTime; // [esp+1440h] [ebp-A50h]
	__int128 v170; // [esp+1450h] [ebp-A40h]
	__int128 v171; // [esp+1460h] [ebp-A30h]
	int v172; // [esp+1470h] [ebp-A20h]
	__int16 szText2[256]; // [esp+1474h] [ebp-A1Ch]
	__int16 szBuffer2[1024]; // [esp+1674h] [ebp-81Ch]
	int v175; // [esp+1E74h] [ebp-1Ch]
	__int16 v176; // [esp+1E78h] [ebp-18h]
	__int16 v177; // [esp+1E7Ah] [ebp-16h]
	__int16 v178; // [esp+1E7Ch] [ebp-14h]
	int v179; // [esp+1E8Ch] [ebp-4h]

	hWnd_1 = hWnd;
	hWnd_3 = hWnd;
	lParamIn = a4;
	pUserData = GetWindowLongW(hWnd, GWLP_USERDATA);
	pSystemProcessInfo = 0;
	pThreadItem_1 = pUserData;
	lParam.mask = 0;
	memset(&lParam.iItem, 0, 0x30u);
	_mm_storeu_si128(&v171, _mm_load_si128(&xmmword_4D6C60));
	v172 = 0x435;
	v6 = gLogPixelSize.x;
	_mm_storeu_si128(&v170, _mm_load_si128(&xmmword_4D6C40));
	LOWORD(v175) = MulDiv(-50, v6, 96);
	HIWORD(v175) = MulDiv(-50, gLogPixelSize.x, 96);
	v176 = MulDiv(-75, gLogPixelSize.x, 96);
	v177 = MulDiv(100, gLogPixelSize.x, 96);
	v178 = MulDiv(200, gLogPixelSize.x, 96);
	SystemInformationLength = 0;
	if (uMsg > WM_COMMAND)
	{
		if (uMsg > WM_CTLCOLORDLG)
		{
			if (uMsg != WM_CTLCOLORSTATIC)
			{
				if (uMsg == 0x7F1)
				{
					v130 = pUserData->m_hEvent2;
					pUserData->field_18 = 1;
					SetEvent(v130);
					InterlockedDecrement(&pUserData->m_nRefCount);
					return 0;
				}
				return 0;
			}
		}
		else if (uMsg != WM_CTLCOLORDLG)
		{
			if (uMsg == WM_TIMER)
			{
				if (pUserData)
					SetEvent(pUserData->m_hEvent2);
				nmhdr.code = 0xFFFFFFF1;
				v139 = 0x74;
				SendMessageW(hWnd, WM_NOTIFY, 0, &nmhdr);
				return 1;
			}
			if (uMsg != WM_CTLCOLOREDIT)
				return 0;
		}
		return FillBlack(hWnd, wParam);
	}
	if (uMsg != WM_COMMAND)
	{
		switch (uMsg)
		{
		case WM_DRAWITEM:
			sub_4488B0(lParamIn);
			return 0;
		case WM_MEASUREITEM:
			return CMainWnd::HandleMeasureItem(hWnd, uMsg, wParam, lParamIn);
		case 0x4E:                                // WM_NOTIFY
			pNMHDR = lParamIn;
			switch (*(lParamIn + 2))
			{
			case LVN_GETDISPINFOW:
				result = sub_44D7B0(wParam, lParamIn);
				break;
			case LVN_COLUMNCLICK:
				result = sub_44D040(IDC_PAGE_PROCTHREADS_LISTCTRL, lParamIn);
				break;
			case LVN_DELETEITEM:
				result = sub_44D4B0(IDC_PAGE_PROCTHREADS_LISTCTRL, lParamIn);
				break;
			case LVN_ITEMCHANGED:
			case LVN_BEGINRDRAG | 0x60:
				GetWindowLongW(pUserData->m_hWndList, GWL_STYLE);
				v83 = pNMHDR->code;
				if (v83 != LVN_ITEMCHANGED && (v83 != -15 || pNMHDR[1].hwndFrom != 116))
					return 0;
				v84 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
				lParam.iItem = SendMessageW(v84, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
				lParam.iSubItem = 0;
				lParam.mask = 4;
				v85 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
				SendMessageW(v85, LVM_GETITEMW, 0, &lParam);
				if (lParam.iItem == -1)
				{
					wsprintfW(szBuffer2, &gszNullString);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_THREAD_ID_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_START_TIME_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CONTEXT_SWITCHES_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_KERNEL_TIME_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_USER_TIME_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_STATE_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE, szBuffer2);
					SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE, szBuffer2);
					v86 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_MODULE);
					EnableWindow(v86, 0);
					v87 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
					EnableWindow(v87, 0);
					v88 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
					EnableWindow(v88, 0);
					v89 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
					EnableWindow(v89, 0);
					v90 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
					EnableWindow(v90, 0);
					result = 0;
				}
				else
				{
					v91 = *(pUserData->m_Param + 68) != 0;
					v92 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_MODULE);
					EnableWindow(v92, v91);
					v93 = *(pUserData->m_Param + 68) != 0;
					v94 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
					EnableWindow(v94, v93);
					v95 = pUserData->m_hProcess && *(pUserData->m_Param + 68);
					v96 = v95;
					v97 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
					EnableWindow(v97, v96);
					v98 = pUserData->m_hProcess && *(pUserData->m_Param + 68);
					v99 = v98;
					v100 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
					EnableWindow(v100, v99);
					v101 = pUserData->m_hProcess && *(pUserData->m_Param + 68);
					v102 = v101;
					v103 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
					EnableWindow(v103, v102);
					v162 = lParam.lParam;
					pThreadItem_1 = 0;
					pSystemProcessInfo = 0;
					GetSystemProcessInfo(&pSystemProcessInfo, &pThreadItem_1);
					v104 = pSystemProcessInfo;
					v105 = *(pUserData->m_Param + 68);
					if (pSystemProcessInfo->UniqueProcessId != v105)
					{
						do
						{
							if (!v104->NextEntryOffset)
								break;
							v104 = (v104 + v104->NextEntryOffset);
						} while (v104->UniqueProcessId != v105);
					}
					v106 = &v104[1];
					if (pUserData->field_34)
						v106 = &v104->ReadOperationCount;
					v107 = 0;
					lParamIn = v106;
					v108 = v104->NumberOfThreads == 0;
					if (v104->NumberOfThreads > 0)
					{
						v109 = v162;
						do
						{
							if (!*(v106 + 9))
								*(v106 + 9) = v107;
							if (*(v109 + 11) == *(v106 + 9))
								break;
							++v107;
							v106 += 16;
						} while (v107 < v104->NumberOfThreads);
						hWnd_1 = hWnd_3;
						v108 = v107 == v104->NumberOfThreads;
						lParamIn = v106;
					}
					if (!v108)
					{
						wsprintfW(szBuffer2, L"%d", *(v106 + 9));
						SetDlgItemTextW(hWnd_1, IDC_PAGE_PROCTHREADS_STATIC_THREAD_ID_VALUE, szBuffer2);
						v110 = lParamIn;
						wsprintfW(
							szBuffer2,
							L"%I64d:%02I64d:%02I64d.%03I64d",
							*lParamIn / 0x861C46800ui64,
							*lParamIn / 0x23C34600ui64 % 0x3C,
							*v106 / 10000000i64 % 60,
							*v106 % 10000000i64 / 10000);
						SetDlgItemTextW(hWnd_3, IDC_PAGE_PROCTHREADS_STATIC_KERNEL_TIME_VALUE, szBuffer2);
						wsprintfW(
							szBuffer2,
							L"%I64d:%02I64d:%02I64d.%03I64d",
							*(lParamIn + 1) / 0x861C46800ui64,
							*(lParamIn + 1) / 0x23C34600ui64 % 0x3C,
							*(v110 + 1) / 10000000i64 % 60,
							*(v110 + 1) % 10000000i64 / 10000);
						hWnd_2 = hWnd_3;
						SetDlgItemTextW(hWnd_3, IDC_PAGE_PROCTHREADS_STATIC_USER_TIME_VALUE, szBuffer2);
						lParamIn_1 = lParamIn;
						if (*(lParamIn + 2)
							&& (FileTimeToLocalFileTime(lParamIn + 2, &LocalFileTime),
								FileTimeToSystemTime(&LocalFileTime, &SystemTime),
								GetTimeFormatW(0x400u, 0, &SystemTime, 0, szBuffer2, 512))
							&& GetDateFormatW(0x400u, 0, &SystemTime, 0, szText2, 128))
						{
							wcscat_s(szBuffer2, 0x400u, L"   ");
							wcscat_s(szBuffer2, 0x400u, szText2);
						}
						else
						{
							wcscpy_s(szBuffer2, 0x400u, L"n/a");
						}
						SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_START_TIME_VALUE, szBuffer2);
						if (*(lParamIn_1 + 13) != 5 || *(lParamIn_1 + 14) != 5)
							v132 = L"Sus&pend";
						else
							v132 = L"R&esume";
						v113 = GetDlgItem(hWnd_2, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
						SetWindowTextW(v113, v132);
						switch (*(lParamIn_1 + 13))
						{
						case 0:
							wcscpy_s(szBuffer2, 0x400u, L"Initialized");
							break;
						case 1:
							wcscpy_s(szBuffer2, 0x400u, L"Ready");
							break;
						case 2:
							wcscpy_s(szBuffer2, 0x400u, L"Running");
							break;
						case 4:
							wcscpy_s(szBuffer2, 0x400u, L"Terminated");
							break;
						case 5:
							v114 = *(lParamIn_1 + 14);
							if (v114 >= 0x28)
								wsprintfW(szBuffer2, L"Waiting");
							else
								wsprintfW(szBuffer2, L"Wait:%s", &aExecutive[64 * v114]);
							break;
						case 6:
							wcscpy_s(szBuffer2, 0x400u, L"Transition");
							break;
						case 7:
							wcscpy_s(szBuffer2, 0x400u, L"DeferredReady");
							break;
						default:
							wsprintfW(szBuffer2, L"<Unknown: %d>", *(lParamIn_1 + 13));
							break;
						}
						SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_STATE_VALUE, szBuffer2);
						if (*(lParamIn_1 + 8))
						{
							wsprintfW(szBuffer2, L"%d", *(lParamIn_1 + 11));
							SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE, szBuffer2);
							wsprintfW(szBuffer2, L"%d", *(lParamIn_1 + 10));
							SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE, szBuffer2);
							v133 = *(lParamIn_1 + 12);
							if (*(lParamIn_1 + 8))
							{
								wsprintfW(szBuffer2, L"%d", v133);
								v115 = sub_453290(szBuffer2, 0x400u);
								SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_CONTEXT_SWITCHES_VALUE, v115);
							}
							else
							{
								wsprintfW(szBuffer2, L"n/a", v133);
							}
							v116 = v162;
							*ArgList = -1;
							ThreadInformation = -1;
							v117 = *(v162 + 10);
							if (v117)
							{
								NtQueryInformationThread(v117, ThreadIoPriority, &ThreadInformation, 4u, &ReturnLength);
								NtQueryInformationThread(*(v116 + 10), ThreadPagePriority, ArgList, 4u, &ReturnLength);
							}
							if (*(v116 + 10))
							{
								wsprintfW(szBuffer2, L"%I64u", *(v116 + 154), *(v116 + 155));
								sub_453290(szBuffer2, 0x400u);
							}
							else
							{
								wsprintfW(szBuffer2, L"n/a");
							}
							SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE, szBuffer2);
							if (ThreadInformation == -1)
								wsprintfW(szBuffer2, L"n/a");
							else
								sub_487790(ThreadInformation, szBuffer2, 0x400u);
							SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, szBuffer2);
							if (*ArgList == -1)
								wsprintfW(szBuffer2, L"n/a");
							else
								wsprintfW(szBuffer2, L"%d", *ArgList);
							SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, szBuffer2);
							if (GetThreadIdealProcessorEx)
							{
								v134 = *(v116 + 610);
								if (dword_4F10DC <= 1)
									wsprintfW(szBuffer2, L"%d", v134);
								else
									wsprintfW(szBuffer2, L"[%d]:%d", *(v116 + 304), v134);
								SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE, szBuffer2);
							}
						}
					}
					free(pSystemProcessInfo);
					result = 0;
				}
				break;
			case LVN_SETDISPINFO | 0x94:
				SendMessageW(hWnd, WM_COMMAND, IDC_PAGE_PROCTHREADS_BUTTON_STACK, 0);
				result = 0;
				break;
			default:
				return 0;
			}
			return result;
		case 0x100:                               // WM_KEYDOWN
			if (wParam != 116)
				return 0;
			SetEvent(pUserData->m_hEvent3);
			return 0;
		case 0x110:                               // WM_INITDIALOG
			if (GetLogicalProcessorInformationEx)
			{
				GetLogicalProcessorInformationEx(4, 0, &SystemInformationLength);
				dword_4F10DC = SystemInformationLength / 0x4C;
			}
			v7 = operator new(0x40u);
			pThreadItem_1 = v7;
			v179 = 0;
			if (v7)
				pResizer = CResizer::CResizer(v7, hWnd);
			else
				pResizer = 0;
			v179 = -1;
			pResizer->m_nXRatio = 80;
			pResizer->m_nYRatio = 50;
			hWndList_1 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
			if (hWndList_1)
			{
				v10 = sub_43E870(hWndList_1, 1);
				*(v10 + 16) = 0i64;
				*(v10 + 24) = dbl_4CCB30;
			}
			v11 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE);
			v162 = v11;
			if (v11)
			{
				v12 = sub_43E870(v11, 1);
				v13 = v162;
				*v12 = 0i64;
				*(sub_43E870(v13, 1) + 16) = xmmword_4D6C70;
			}
			v14 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE);
			v162 = v14;
			if (v14)
			{
				v15 = sub_43E870(v14, 1);
				v16 = v162;
				*v15 = 0i64;
				*(sub_43E870(v16, 1) + 16) = xmmword_4D6C70;
			}
			v17 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY);
			v162 = v17;
			if (v17)
			{
				v18 = sub_43E870(v17, 1);
				v19 = v162;
				*v18 = 0i64;
				*(sub_43E870(v19, 1) + 16) = xmmword_4D6C70;
			}
			v20 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY);
			v162 = v20;
			if (v20)
			{
				v21 = sub_43E870(v20, 1);
				v22 = v162;
				*v21 = 0i64;
				*(sub_43E870(v22, 1) + 16) = xmmword_4D6C70;
			}
			v23 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE);
			v162 = v23;
			if (v23)
			{
				v24 = sub_43E870(v23, 1);
				v25 = v162;
				*v24 = 0i64;
				*(sub_43E870(v25, 1) + 16) = xmmword_4D6C70;
			}
			v26 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE);
			v162 = v26;
			if (v26)
			{
				v27 = sub_43E870(v26, 1);
				v28 = v162;
				*v27 = 0i64;
				*(sub_43E870(v28, 1) + 16) = xmmword_4D6C70;
			}
			v29 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
			v162 = v29;
			if (v29)
			{
				v30 = sub_43E870(v29, 1);
				v31 = v162;
				*v30 = xmmword_4D6C70;
				*(sub_43E870(v31, 1) + 16) = xmmword_4D6C70;
			}
			v32 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
			if (v32)
				*sub_43E870(v32, 1) = xmmword_4D6C70;
			v33 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
			if (v33)
				*sub_43E870(v33, 1) = xmmword_4D6C70;
			v34 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE);
			v162 = v34;
			if (v34)
			{
				v35 = sub_43E870(v34, 1);
				v36 = v162;
				*v35 = 0i64;
				*(sub_43E870(v36, 1) + 16) = xmmword_4D6C70;
			}
			sub_453710(hWnd);
			if (*(lParamIn + 40) & 0x20 && gdwVersion >= 1)
			{
				v37 = &v171;
				v162 = 5;
			}
			else
			{
				v37 = &v170;
				v162 = 4;
			}
			v108 = *(lParamIn + 17) == 0;
			v156 = v37;
			if (v108)
			{
				LODWORD(v171) = 1638;
				LODWORD(v170) = 1638;
			}
			if (gdwVersion >= 1)
			{
				*(v37 + 2) = 1200;
			}
			else
			{
				v38 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMORY_PRIORITY);
				ShowWindow(v38, 0);
				v39 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE);
				ShowWindow(v39, 0);
				v40 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY);
				ShowWindow(v40, 0);
				v41 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE);
				ShowWindow(v41, 0);
				v42 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE);
				ShowWindow(v42, 0);
				v43 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CYCLES);
				ShowWindow(v43, 0);
			}
			v44 = GetThreadIdealProcessorEx != 0 ? 5 : 0;
			v45 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR);
			ShowWindow(v45, v44);
			v46 = GetThreadIdealProcessorEx != 0 ? 5 : 0;
			v47 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE);
			ShowWindow(v47, v46);
			pThreadItem = malloc(0x50u);
			pThreadItem_1 = pThreadItem;
			memset(pThreadItem, 0, 0x50u);
			lParam_1 = lParamIn;
			pThreadItem->m_Next = 0;
			pThreadItem->m_hProcess = 0;
			pThreadItem->m_Param = lParam_1;
			pThreadItem->m_hEvent = CreateEventW(0, 0, 0, 0);
			hWndList = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
			pThreadItem->m_hWndList = hWndList;
			SetWindowLongW(hWndList, GWLP_WNDPROC, Proxy_ProcThreadListCtrlWndProc);
			SetWindowLongW(hWnd, GWLP_USERDATA, pThreadItem);
			v51 = GetWindowLongW(pThreadItem->m_hWndList, GWL_STYLE);
			SetWindowLongW(pThreadItem->m_hWndList, -16, v51 & -3u | 9);
			SetWindowLongW(pThreadItem->m_hWndList, GWLP_USERDATA, 5);
			v52 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_LOADING_SYMBOLS_FOR);
			SetWindowTextW(v52, &gszNullString);
			sub_4692A0(0);
			SendMessageW(pThreadItem->m_hWndList, WM_SETFONT, ghConfigFont, 0);
			GetSystemProcessInfo(&pSystemProcessInfo, 0);
			v53 = pSystemProcessInfo;
			v54 = *(pThreadItem->m_Param + 0x44);
			if (pSystemProcessInfo->UniqueProcessId == v54)
				goto LABEL_43;
			break;
		default:
			return 0;
		}
		do
		{
			if (!v53->NextEntryOffset)
			{
				free(pSystemProcessInfo);
				return 1;
			}
			v53 = (v53 + v53->NextEntryOffset);
		} while (v53->UniqueProcessId != v54);
	LABEL_43:
		v55 = LoadCursorW(0, IDC_WAIT);
		v56 = SetCursor(v55);
		v57 = pThreadItem->m_Param;
		lParamIn = v56;
		v58 = OpenProcess(GENERIC_READ, 0, *(v57 + 0x44));
		pThreadItem->m_hProcess = v58;
		if (v58)
		{
			v59 = v156;
		}
		else
		{
			pThreadItem->m_hProcess = OpenProcess(PROCESS_MODE_BACKGROUND_BEGIN, 0, *(pThreadItem->m_Param + 0x44));
			v59 = v156;
			*(v156 + 8) = 1092;
		}
		sub_449BB0(pThreadItem->m_hWndList, v162, v59, &v175, 1);
		if (SymInitialize)
		{
			EnterCriticalSection(&gProcThreadsLock);
			SymSetOptions(0x10037);
			v61 = pThreadItem->m_hProcess;
			if (v61)
				pThreadItem->m_bSymInited = SymInitialize(v61, 0, 1);
			if (!pThreadItem->m_bSymInited)
			{
				if (pThreadItem->m_hProcess)
					CloseHandle(pThreadItem->m_hProcess);
				v62 = GetCurrentProcess();
				pThreadItem->m_hProcess = v62;
				pThreadItem->m_bSymInited = SymInitialize(v62, 0, 1);
			}
		}
		SystemInformationLength = 1000;
		v63 = malloc(1000u);
		pThreadItem->m_SystemModules = v63;
		if (NtQuerySystemInformation(SystemModuleInformation, v63, SystemInformationLength, &SystemInformationLength))
		{
			do
			{
				free(pThreadItem->m_SystemModules);
				SystemInformationLength += 1000;
				v64 = malloc(SystemInformationLength);
				pThreadItem->m_SystemModules = v64;
			} while (NtQuerySystemInformation(SystemModuleInformation, v64, SystemInformationLength, &SystemInformationLength));
		}
		v65 = pThreadItem->m_Param;
		pThreadItem->m_DebugBuffer = 0;
		if (!(*(v65 + 40) & 0x10))
		{
			v66 = RtlCreateQueryDebugBuffer(0, 0);
			pThreadItem->m_DebugBuffer = v66;
			if (v66)
			{
				v147 = v53->UniqueProcessId;
				v148 = pThreadItem->m_DebugBuffer;
				hThread = _beginthreadex(0, 0, QueryProcessDebugInforThreadProc, &v147, 0, &ThreadId);
				CloseHandle(pThreadItem->m_hThread);
				if (WaitForSingleObject(hThread, 4000u) == WAIT_TIMEOUT)
				{
					LeaveCriticalSection(&gProcThreadsLock);
					TerminateThread(hThread, 1u);
				}
				GetExitCodeThread(hThread, &ExitCode);
				if (ExitCode)
				{
					RtlDestroyQueryDebugBuffer(pThreadItem->m_DebugBuffer);
					pThreadItem->m_DebugBuffer = 0;
				}
				CloseHandle(hThread);
			}
		}
		if (SymInitialize)
			LeaveCriticalSection(&gProcThreadsLock);
		free(pSystemProcessInfo);
		v68 = ImageList_Create(16, 16, 1u, 256, 256);
		v69 = LoadIconW(ghInstance, IDC_DOWNARROW);
		ImageList_ReplaceIcon(v68, -1, v69);
		v70 = LoadIconW(ghInstance, IDC_UPARROW);
		ImageList_ReplaceIcon(v68, -1, v70);
		pThreadItem_2 = pThreadItem_1;
		v72 = GetWindowLongW(pThreadItem_1->m_hWndList, GWL_STYLE);
		SetWindowLongW(pThreadItem_2->m_hWndList, -16, v72 | 0x48);
		SendMessageW(pThreadItem_2->m_hWndList, 0x1003u, 1u, v68);
		sub_44F9E0(pThreadItem_2->m_hWndList, ::wParam, ::wParam, byte_4F53B4);
		pThreadItem_2->field_18 = 0;
		pThreadItem_2->m_nRefCount = 2;
		pThreadItem_2->m_hEvent2 = CreateEventW(0, 0, 1, 0);
		pThreadItem_2->m_hEvent2 = CreateEventW(0, 0, 1, 0);
		v73 = CreateEventW(0, 0, 1, 0);
		pThreadItem_2->m_hEvent3 = v73;
		ResetEvent(v73);
		v74 = pThreadItem_2->m_hEvent2;
		pThreadItem_2->field_4 = 0;
		SetEvent(v74);
		pThreadItem_2->m_hThread = _beginthreadex(0, 0, UpdateProcThreadsInfoThreadProc, pThreadItem_2, 0, &ThreadId);
		SetFocus(pThreadItem_2->m_hWndList);
		SetCursor(lParamIn);
		ReleaseCapture();
		if (GetCurrentProcessId() != *(pThreadItem_2->m_Param + 68) && pThreadItem_2->m_hProcess)
		{
			v75 = hWnd_3;
			v76 = GetDlgItem;
		}
		else
		{
			v75 = hWnd_3;
			v76 = GetDlgItem;
			v77 = GetDlgItem(hWnd_3, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
			EnableWindow(v77, 0);
			v78 = GetDlgItem(v75, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
			EnableWindow(v78, 0);
			v79 = GetDlgItem(v75, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
			EnableWindow(v79, 0);
			v80 = GetDlgItem(v75, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
			EnableWindow(v80, 0);
		}
		if (!dword_4FF2A4)
		{
			v81 = v76(v75, 1085);
			EnableWindow(v81, 0);
		}
		return 1;
	}
	// Handler for WM_COMMAND
	if (wParam > IDC_PAGE_PROCTHREADS_BUTTON_MODULE)
	{
		if (wParam > 40001)
		{
			if (wParam == 40002)
			{
				SetEvent(dword_4FA36C);
				return 0;
			}
			if (wParam - 40092 > 1)
				return 0;
			v131 = wParam;
		}
		else
		{
			if (wParam != 40001)
			{
				switch (wParam)
				{
				case IDC_PAGE_PROCTHREADS_BUTTON_STACK:
					if (!dword_4FF2A4)
						return 0;
					lParam.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
					if (lParam.iItem == -1)
						return 0;
					lParam.iSubItem = 0;
					lParam.mask = 4;
					if (!SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParam))
						return 0;
					v127 = lParam.lParam;
					v128 = sub_485870(*(lParam.lParam + 44), 74);
					if (v128)
					{
						dwInitParam = *(pUserData->m_Param + 68);
						v142 = *(v127 + 44);
						v144 = pUserData->m_hProcess;
						hObject = v128;
						v146 = pUserData->m_DebugBuffer;
						v145 = pUserData->m_SystemModules;
						DialogBoxParamW(ghMainInstance, L"THREADSTACK", hWnd, DialogFunc, &dwInitParam);
						if (hObject)
						{
							CloseHandle(hObject);
							return 0;
						}
						return 0;
					}
					break;
				case IDC_PAGE_PROCTHREADS_BUTTON_KILL:
					goto LABEL_156;
				case IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS:
					lParam.iItem = SendMessageW(pUserData->m_hWndList, 0x100Cu, 0xFFFFFFFF, 2);
					if (lParam.iItem == -1)
						return 0;
					lParam.iSubItem = 0;
					lParam.mask = 4;
					if (!SendMessageW(pUserData->m_hWndList, 0x104Bu, 0, &lParam))
						return 0;
					pThreadItem_1 = lParam.lParam;
					v120 = sub_485870(*(lParam.lParam + 44), 0x20000);
					if (v120)
					{
						memset(&v163, 0, 0x10C0u);
						wsprintfW(szBuffer, L"Thread %d", pThreadItem_1->m_hProcess);
						v165 = 0;
						wcscpy_s(szText, 0x40u, L"Thread");
						v166 = v120;
						v164 = GetCurrentProcessId();
						FillHandleListParam(hWnd, &v163);
						CloseHandle(v120);
						return 0;
					}
					break;
				default:
					return 0;
				}
				MessageBoxW(pUserData->m_hWndList, L"Unable to access thread", L"Process Explorer", 0x10u);
				return 0;
			}
			v131 = 40014;
		}
		v129 = GetParent(hWnd);
		PostMessageW(v129, 0x111u, v131, 0);
		return 0;
	}
	if (wParam == IDC_PAGE_PROCTHREADS_BUTTON_MODULE)
	{
		lParam.iItem = SendMessageW(pUserData->m_hWndList, 0x100Cu, 0xFFFFFFFF, 2);
		if (lParam.iItem != -1)
		{
			lParam.iSubItem = 0;
			lParam.mask = 4;
			if (SendMessageW(pUserData->m_hWndList, 0x104Bu, 0, &lParam))
			{
				qmemcpy(v135, lParam.lParam, 0x290u);
				if (v136[0])
				{
					memset(&pExecInfo, 0, 0x3Cu);
					pExecInfo.cbSize = 60;
					pExecInfo.lpFile = v136[0];
					pExecInfo.lpVerb = L"properties";
					pExecInfo.fMask = 12;
					ShellExecuteExW(&pExecInfo);
					SetFocus(pThreadItem_1->m_hWndList);
				}
				else
				{
					MessageBoxW(hWnd, L"The module cannot be located", L"Process Explorer", 0x10u);
				}
				return 0;
			}
		}
		return 0;
	}
	if (wParam != IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND)
		return 0;
LABEL_156:
	lParam.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
	if (lParam.iItem == -1)
		return 0;
	lParam.iSubItem = 0;
	lParam.mask = 4;
	if (!SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParam))
		return 0;
	v118 = lParam.lParam;
	pThreadItem_1 = lParam.lParam;
	if (wParam == IDC_PAGE_PROCTHREADS_BUTTON_KILL)
	{
		wsprintfW(szBuffer2, L"Are you sure you want to kill thread %d?", *(lParam.lParam + 44));
		if (MessageBoxW(ghWndNewOwner, szBuffer2, L"Process Explorer", 0x31u) != 2)
		{
			v118 = pThreadItem_1;
			goto LABEL_161;
		}
		return 0;
	}
LABEL_161:
	ThreadHandle = sub_485870(v118->m_hProcess, 3);
	if (!ThreadHandle)
	{
		sub_488A60(L"Unable to access thread", pUserData->m_hWndList);
		return 0;
	}
	if (wParam == IDC_PAGE_PROCTHREADS_BUTTON_KILL)
	{
		if (!TerminateThread(ThreadHandle, 0))
		{
			sub_488A60(L"Unable to terminate thread", ghWndNewOwner);
			CloseHandle(ThreadHandle);
			return 0;
		}
	}
	else
	{
		v121 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
		GetWindowTextW(v121, szBuffer2, 1024);
		v122 = L"R&esume";
		v123 = szBuffer2;
		while (1)
		{
			v124 = *v123 < *v122;
			if (*v123 != *v122)
				break;
			if (!*v123)
				goto LABEL_187;
			v125 = v123[1];
			v124 = v125 < v122[1];
			if (v125 != v122[1])
				break;
			v123 += 2;
			v122 += 2;
			if (!v125)
			{
			LABEL_187:
				v126 = 0;
				goto LABEL_189;
			}
		}
		v126 = -v124 | 1;
	LABEL_189:
		if (v126)
		{
			if (NtSuspendThread(v122, ThreadHandle))
				sub_488A60(L"Unable to suspend thread", ghWndNewOwner);
		}
		else if (NtResumeThread(v122, ThreadHandle, &v150))
		{
			sub_488A60(L"Unable to resume thread", ghWndNewOwner);
			CloseHandle(ThreadHandle);
			return 0;
		}
	}
	CloseHandle(ThreadHandle);
	return 0;
}