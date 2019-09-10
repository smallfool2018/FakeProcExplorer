
//----- (00FEACF0) --------------------------------------------------------
int __stdcall PageProcThreads(HWND hWnd, int uMsg, WPARAM wParam, int a4)
{
  HWND hWnd_1; // ebx
  tagThreadItem *pUserData; // edi
  int v6; // ST20_4
  tagThreadItem *v7; // eax
  CResizer *pResizer; // esi
  HWND hWndList_1; // eax
  struct tagResizerItem *v10; // eax
  HWND v11; // eax
  struct tagResizerItem *v12; // eax
  HWND v13; // ST20_4
  HWND v14; // eax
  struct tagResizerItem *v15; // eax
  HWND v16; // ST20_4
  HWND v17; // eax
  struct tagResizerItem *v18; // eax
  HWND v19; // ST20_4
  HWND v20; // eax
  struct tagResizerItem *v21; // eax
  HWND v22; // ST20_4
  HWND v23; // eax
  struct tagResizerItem *v24; // eax
  HWND v25; // ST20_4
  HWND v26; // eax
  struct tagResizerItem *v27; // eax
  HWND v28; // ST20_4
  HWND v29; // eax
  struct tagResizerItem *v30; // eax
  HWND v31; // ST20_4
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // eax
  struct tagResizerItem *v35; // eax
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
  UINT *v59; // eax
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
  HWND hWnd_4; // esi
  HWND (__stdcall *GetDlgItem)(HWND, int); // edi
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
  HANDLE *v118; // eax
  HANDLE ThreadHandle; // esi
  HANDLE ThreadHandle_1; // esi
  HWND v121; // eax
  wchar_t *v122; // ecx
  __int16 *v123; // eax
  bool v124; // cf
  unsigned __int16 v125; // dx
  int v126; // eax
  tagTREEVIEWITEMPARAM *v127; // esi
  HANDLE v128; // eax
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
  DWORD ExitCode; // [esp+320h] [ebp-1B70h]
  DWORD ThreadId; // [esp+324h] [ebp-1B6Ch]
  tagLVITEMW lParam; // [esp+328h] [ebp-1B68h]
  int ThreadInformation; // [esp+35Ch] [ebp-1B34h]
  char ArgList[4]; // [esp+360h] [ebp-1B30h]
  UINT *pnIDs; // [esp+364h] [ebp-1B2Ch]
  HWND hWnd_3; // [esp+368h] [ebp-1B28h]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+36Ch] [ebp-1B24h]
  ULONG SystemInformationLength; // [esp+370h] [ebp-1B20h]
  tagThreadItem *pThreadItem_1; // [esp+374h] [ebp-1B1Ch]
  HCURSOR lParamIn; // [esp+378h] [ebp-1B18h]
  HWND hWndEdit; // [esp+37Ch] [ebp-1B14h]
  char ListParam[36]; // [esp+380h] [ebp-1B10h]
  DWORD v163; // [esp+3A4h] [ebp-1AECh]
  int v164; // [esp+3A8h] [ebp-1AE8h]
  HANDLE v165; // [esp+3ACh] [ebp-1AE4h]
  __int16 szText[64]; // [esp+3B8h] [ebp-1AD8h]
  __int16 szBuffer[2052]; // [esp+438h] [ebp-1A58h]
  struct _SYSTEMTIME SystemTime; // [esp+1440h] [ebp-A50h]
  __int128 v169; // [esp+1450h] [ebp-A40h]
  __int128 v170; // [esp+1460h] [ebp-A30h]
  int v171; // [esp+1470h] [ebp-A20h]
  __int16 szText2[256]; // [esp+1474h] [ebp-A1Ch]
  __int16 szBuffer2[1024]; // [esp+1674h] [ebp-81Ch]
  WORD pnWidths[2]; // [esp+1E74h] [ebp-1Ch]
  __int16 v175; // [esp+1E78h] [ebp-18h]
  __int16 v176; // [esp+1E7Ah] [ebp-16h]
  __int16 v177; // [esp+1E7Ch] [ebp-14h]
  int v178; // [esp+1E8Ch] [ebp-4h]

  hWnd_1 = hWnd;
  hWnd_3 = hWnd;
  lParamIn = a4;
  pUserData = GetWindowLongW(hWnd, GWLP_USERDATA);
  pSystemProcessInfo = 0;
  pThreadItem_1 = pUserData;
  lParam.mask = 0;
  memset(&lParam.iItem, 0, 0x30u);
  _mm_storeu_si128(&v170, _mm_load_si128(&xmmword_1046C60));
  v171 = 0x435;
  v6 = gLogPixelSize.x;
  _mm_storeu_si128(&v169, _mm_load_si128(&xmmword_1046C40));
  pnWidths[0] = MulDiv(-50, v6, 96);
  pnWidths[1] = MulDiv(-50, gLogPixelSize.x, 96);
  v175 = MulDiv(-75, gLogPixelSize.x, 96);
  v176 = MulDiv(100, gLogPixelSize.x, 96);
  v177 = MulDiv(200, gLogPixelSize.x, 96);
  SystemInformationLength = 0;
  if ( uMsg > WM_COMMAND )
  {
    if ( uMsg > WM_CTLCOLORDLG )
    {
      if ( uMsg != WM_CTLCOLORSTATIC )
      {
        if ( uMsg == 0x7F1 )
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
    else if ( uMsg != WM_CTLCOLORDLG )
    {
      if ( uMsg == WM_TIMER )
      {
        if ( pUserData )
          SetEvent(pUserData->m_hEvent2);
        nmhdr.code = 0xFFFFFFF1;
        v139 = 0x74;
        SendMessageW(hWnd, WM_NOTIFY, 0, &nmhdr);
        return 1;
      }
      if ( uMsg != WM_CTLCOLOREDIT )
        return 0;
    }
    return PE_FillControl(hWnd, wParam);
  }
  if ( uMsg != WM_COMMAND )
  {
    switch ( uMsg )
    {
      case WM_DRAWITEM:
        CMainWnd::DrawList(lParamIn);
        return 0;
      case WM_MEASUREITEM:
        return CMainWnd::HandleMeasureItem(hWnd, uMsg, wParam, lParamIn);
      case 0x4E:                                // WM_NOTIFY
        pNMHDR = lParamIn;
        switch ( *(lParamIn + 2) )
        {
          case LVN_GETDISPINFOW:
            result = sub_FBD7B0(wParam, lParamIn);
            break;
          case LVN_COLUMNCLICK:
            result = sub_FBD040(IDC_PAGE_PROCTHREADS_LISTCTRL, lParamIn);
            break;
          case LVN_DELETEITEM:
            result = sub_FBD4B0(IDC_PAGE_PROCTHREADS_LISTCTRL, lParamIn);
            break;
          case LVN_ITEMCHANGED:
          case LVN_BEGINRDRAG|0x60:
            GetWindowLongW(pUserData->m_hWndList, GWL_STYLE);
            v83 = pNMHDR->code;
            if ( v83 != LVN_ITEMCHANGED && (v83 != -15 || pNMHDR[1].hwndFrom != 116) )
              return 0;
            v84 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
            lParam.iItem = SendMessageW(v84, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            lParam.iSubItem = 0;
            lParam.mask = 4;
            v85 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
            SendMessageW(v85, LVM_GETITEMW, 0, &lParam);
            if ( lParam.iItem == -1 )
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
              v86 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_MODULE);
              EnableWindow(v86, 0);
              v87 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
              EnableWindow(v87, 0);
              v88 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
              EnableWindow(v88, 0);
              v89 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
              EnableWindow(v89, 0);
              v90 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
              EnableWindow(v90, 0);
              result = 0;
            }
            else
            {
              v91 = *(pUserData->m_Param + 68) != 0;
              v92 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_MODULE);
              EnableWindow(v92, v91);
              v93 = *(pUserData->m_Param + 68) != 0;
              v94 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
              EnableWindow(v94, v93);
              v95 = pUserData->m_hProcess && *(pUserData->m_Param + 68);
              v96 = v95;
              v97 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
              EnableWindow(v97, v96);
              v98 = pUserData->m_hProcess && *(pUserData->m_Param + 68);
              v99 = v98;
              v100 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
              EnableWindow(v100, v99);
              v101 = pUserData->m_hProcess && *(pUserData->m_Param + 68);
              v102 = v101;
              v103 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
              EnableWindow(v103, v102);
              hWndEdit = lParam.lParam;
              pThreadItem_1 = 0;
              pSystemProcessInfo = 0;
              GetSystemProcessInfo(&pSystemProcessInfo, &pThreadItem_1);
              v104 = pSystemProcessInfo;
              v105 = *(pUserData->m_Param + 68);
              if ( pSystemProcessInfo->UniqueProcessId != v105 )
              {
                do
                {
                  if ( !v104->NextEntryOffset )
                    break;
                  v104 = (v104 + v104->NextEntryOffset);
                }
                while ( v104->UniqueProcessId != v105 );
              }
              v106 = &v104[1];
              if ( pUserData->field_34 )
                v106 = &v104->ReadOperationCount;
              v107 = 0;
              lParamIn = v106;
              v108 = v104->NumberOfThreads == 0;
              if ( v104->NumberOfThreads > 0 )
              {
                v109 = hWndEdit;
                do
                {
                  if ( !*(v106 + 9) )
                    *(v106 + 9) = v107;
                  if ( *(v109 + 11) == *(v106 + 9) )
                    break;
                  ++v107;
                  v106 += 16;
                }
                while ( v107 < v104->NumberOfThreads );
                hWnd_1 = hWnd_3;
                v108 = v107 == v104->NumberOfThreads;
                lParamIn = v106;
              }
              if ( !v108 )
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
                if ( *(lParamIn + 2)
                  && (FileTimeToLocalFileTime(lParamIn + 2, &LocalFileTime),
                      FileTimeToSystemTime(&LocalFileTime, &SystemTime),
                      GetTimeFormatW(0x400u, 0, &SystemTime, 0, szBuffer2, 512))
                  && GetDateFormatW(0x400u, 0, &SystemTime, 0, szText2, 128) )
                {
                  wcscat_s(szBuffer2, 0x400u, L"   ");
                  wcscat_s(szBuffer2, 0x400u, szText2);
                }
                else
                {
                  wcscpy_s(szBuffer2, 0x400u, L"n/a");
                }
                SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_START_TIME_VALUE, szBuffer2);
                if ( *(lParamIn_1 + 13) != 5 || *(lParamIn_1 + 14) != 5 )
                  v132 = L"Sus&pend";
                else
                  v132 = L"R&esume";
                v113 = ::GetDlgItem(hWnd_2, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
                SetWindowTextW(v113, v132);
                switch ( *(lParamIn_1 + 13) )
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
                    if ( v114 >= 0x28 )
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
                if ( *(lParamIn_1 + 8) )
                {
                  wsprintfW(szBuffer2, L"%d", *(lParamIn_1 + 11));
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE, szBuffer2);
                  wsprintfW(szBuffer2, L"%d", *(lParamIn_1 + 10));
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE, szBuffer2);
                  v133 = *(lParamIn_1 + 12);
                  if ( *(lParamIn_1 + 8) )
                  {
                    wsprintfW(szBuffer2, L"%d", v133);
                    v115 = sub_FC3290(szBuffer2, 0x400u);
                    SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_CONTEXT_SWITCHES_VALUE, v115);
                  }
                  else
                  {
                    wsprintfW(szBuffer2, L"n/a", v133);
                  }
                  v116 = hWndEdit;
                  *ArgList = -1;
                  ThreadInformation = -1;
                  v117 = *(hWndEdit + 10);
                  if ( v117 )
                  {
                    NtQueryInformationThread(v117, ThreadIoPriority, &ThreadInformation, 4u, &ReturnLength);
                    NtQueryInformationThread(*(v116 + 10), ThreadPagePriority, ArgList, 4u, &ReturnLength);
                  }
                  if ( *(v116 + 10) )
                  {
                    wsprintfW(szBuffer2, L"%I64u", *(v116 + 154), *(v116 + 155));
                    sub_FC3290(szBuffer2, 0x400u);
                  }
                  else
                  {
                    wsprintfW(szBuffer2, L"n/a");
                  }
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE, szBuffer2);
                  if ( ThreadInformation == -1 )
                    wsprintfW(szBuffer2, L"n/a");
                  else
                    sub_FF7790(ThreadInformation, szBuffer2, 0x400u);
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, szBuffer2);
                  if ( *ArgList == -1 )
                    wsprintfW(szBuffer2, L"n/a");
                  else
                    wsprintfW(szBuffer2, L"%d", *ArgList);
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, szBuffer2);
                  if ( GetThreadIdealProcessorEx )
                  {
                    v134 = *(v116 + 610);
                    if ( dword_10610DC <= 1 )
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
          case LVN_SETDISPINFO|0x94:
            SendMessageW(hWnd, WM_COMMAND, IDC_PAGE_PROCTHREADS_BUTTON_STACK, 0);
            result = 0;
            break;
          default:
            return 0;
        }
        return result;
      case 0x100:                               // WM_KEYDOWN
        if ( wParam != 116 )
          return 0;
        SetEvent(pUserData->m_hEvent3);
        return 0;
      case 0x110:                               // WM_INITDIALOG
        if ( GetLogicalProcessorInformationEx )
        {
          GetLogicalProcessorInformationEx(4, 0, &SystemInformationLength);
          dword_10610DC = SystemInformationLength / 0x4C;
        }
        v7 = operator new(0x40u);
        pThreadItem_1 = v7;
        v178 = 0;
        if ( v7 )
          pResizer = CResizer::CResizer(v7, hWnd);
        else
          pResizer = 0;
        v178 = -1;
        pResizer->m_nXRatio = 80;
        pResizer->m_nYRatio = 50;
        hWndList_1 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
        if ( hWndList_1 )
        {
          v10 = CResizer::AddItem(pResizer, hWndList_1, 1);
          *&v10->m_rect2.left = 0i64;
          *&v10->m_rect2.right = db_one;
        }
        v11 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE);
        hWndEdit = v11;
        if ( v11 )
        {
          v12 = CResizer::AddItem(pResizer, v11, 1);
          v13 = hWndEdit;
          v12->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v13, 1)->m_rect2 = stru_1046C70;
        }
        v14 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE);
        hWndEdit = v14;
        if ( v14 )
        {
          v15 = CResizer::AddItem(pResizer, v14, 1);
          v16 = hWndEdit;
          v15->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v16, 1)->m_rect2 = stru_1046C70;
        }
        v17 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY);
        hWndEdit = v17;
        if ( v17 )
        {
          v18 = CResizer::AddItem(pResizer, v17, 1);
          v19 = hWndEdit;
          v18->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v19, 1)->m_rect2 = stru_1046C70;
        }
        v20 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY);
        hWndEdit = v20;
        if ( v20 )
        {
          v21 = CResizer::AddItem(pResizer, v20, 1);
          v22 = hWndEdit;
          v21->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v22, 1)->m_rect2 = stru_1046C70;
        }
        v23 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE);
        hWndEdit = v23;
        if ( v23 )
        {
          v24 = CResizer::AddItem(pResizer, v23, 1);
          v25 = hWndEdit;
          v24->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v25, 1)->m_rect2 = stru_1046C70;
        }
        v26 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE);
        hWndEdit = v26;
        if ( v26 )
        {
          v27 = CResizer::AddItem(pResizer, v26, 1);
          v28 = hWndEdit;
          v27->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v28, 1)->m_rect2 = stru_1046C70;
        }
        v29 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
        hWndEdit = v29;
        if ( v29 )
        {
          v30 = CResizer::AddItem(pResizer, v29, 1);
          v31 = hWndEdit;
          v30->m_rect1 = stru_1046C70;
          CResizer::AddItem(pResizer, v31, 1)->m_rect2 = stru_1046C70;
        }
        v32 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
        if ( v32 )
          CResizer::AddItem(pResizer, v32, 1)->m_rect1 = stru_1046C70;
        v33 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
        if ( v33 )
          CResizer::AddItem(pResizer, v33, 1)->m_rect1 = stru_1046C70;
        v34 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE);
        hWndEdit = v34;
        if ( v34 )
        {
          v35 = CResizer::AddItem(pResizer, v34, 1);
          v36 = hWndEdit;
          v35->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v36, 1)->m_rect2 = stru_1046C70;
        }
        PropSheet_UpdateTab(hWnd);
        if ( *(lParamIn + 40) & 0x20 && gdwVersion >= 1 )
        {
          v37 = &v170;
          hWndEdit = 5;
        }
        else
        {
          v37 = &v169;
          hWndEdit = 4;
        }
        v108 = *(lParamIn + 17) == 0;
        pnIDs = v37;
        if ( v108 )
        {
          LODWORD(v170) = 1638;
          LODWORD(v169) = 1638;
        }
        if ( gdwVersion >= 1 )
        {
          *(v37 + 2) = 1200;
        }
        else
        {
          v38 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMORY_PRIORITY);
          ShowWindow(v38, 0);
          v39 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE);
          ShowWindow(v39, 0);
          v40 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY);
          ShowWindow(v40, 0);
          v41 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE);
          ShowWindow(v41, 0);
          v42 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE);
          ShowWindow(v42, 0);
          v43 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CYCLES);
          ShowWindow(v43, 0);
        }
        v44 = GetThreadIdealProcessorEx != 0 ? 5 : 0;
        v45 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR);
        ShowWindow(v45, v44);
        v46 = GetThreadIdealProcessorEx != 0 ? 5 : 0;
        v47 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE);
        ShowWindow(v47, v46);
        pThreadItem = malloc(0x50u);
        pThreadItem_1 = pThreadItem;
        memset(pThreadItem, 0, 0x50u);
        lParam_1 = lParamIn;
        pThreadItem->m_Next = 0;
        pThreadItem->m_hProcess = 0;
        pThreadItem->m_Param = lParam_1;
        pThreadItem->m_hEvent = CreateEventW(0, 0, 0, 0);
        hWndList = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
        pThreadItem->m_hWndList = hWndList;
        SetWindowLongW(hWndList, GWLP_WNDPROC, Proxy_ListCtrlWndProc);
        SetWindowLongW(hWnd, GWLP_USERDATA, pThreadItem);
        v51 = GetWindowLongW(pThreadItem->m_hWndList, GWL_STYLE);
        SetWindowLongW(pThreadItem->m_hWndList, -16, v51 & -3u | 9);
        SetWindowLongW(pThreadItem->m_hWndList, GWLP_USERDATA, 5);
        v52 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_LOADING_SYMBOLS_FOR);
        SetWindowTextW(v52, &gszNullString);
        ShowSymbolConfigWarning(0);
        SendMessageW(pThreadItem->m_hWndList, WM_SETFONT, ghConfigFont, 0);
        GetSystemProcessInfo(&pSystemProcessInfo, 0);
        v53 = pSystemProcessInfo;
        v54 = *(pThreadItem->m_Param + 0x44);
        if ( pSystemProcessInfo->UniqueProcessId == v54 )
          goto LABEL_43;
        break;
      default:
        return 0;
    }
    do
    {
      if ( !v53->NextEntryOffset )
      {
        free(pSystemProcessInfo);
        return 1;
      }
      v53 = (v53 + v53->NextEntryOffset);
    }
    while ( v53->UniqueProcessId != v54 );
LABEL_43:
    v55 = LoadCursorW(0, IDC_WAIT);
    v56 = SetCursor(v55);
    v57 = pThreadItem->m_Param;
    lParamIn = v56;
    v58 = OpenProcess(GENERIC_READ, 0, *(v57 + 0x44));
    pThreadItem->m_hProcess = v58;
    if ( v58 )
    {
      v59 = pnIDs;
    }
    else
    {
      pThreadItem->m_hProcess = OpenProcess(PROCESS_MODE_BACKGROUND_BEGIN, 0, *(pThreadItem->m_Param + 0x44));
      v59 = pnIDs;
      pnIDs[2] = 1092;
    }
    sub_FB9BB0(pThreadItem->m_hWndList, hWndEdit, v59, pnWidths, 1);
    if ( SymInitialize )
    {
      EnterCriticalSection(&gProcThreadsLock);
      SymSetOptions(0x10037u);
      v61 = pThreadItem->m_hProcess;
      if ( v61 )
        pThreadItem->m_bSymInited = SymInitialize(v61, 0, 1);
      if ( !pThreadItem->m_bSymInited )
      {
        if ( pThreadItem->m_hProcess )
          CloseHandle(pThreadItem->m_hProcess);
        v62 = GetCurrentProcess();
        pThreadItem->m_hProcess = v62;
        pThreadItem->m_bSymInited = SymInitialize(v62, 0, 1);
      }
    }
    SystemInformationLength = 1000;
    v63 = malloc(1000u);
    pThreadItem->m_SystemModules = v63;
    if ( NtQuerySystemInformation(SystemModuleInformation, v63, SystemInformationLength, &SystemInformationLength) )
    {
      do
      {
        free(pThreadItem->m_SystemModules);
        SystemInformationLength += 1000;
        v64 = malloc(SystemInformationLength);
        pThreadItem->m_SystemModules = v64;
      }
      while ( NtQuerySystemInformation(SystemModuleInformation, v64, SystemInformationLength, &SystemInformationLength) );
    }
    v65 = pThreadItem->m_Param;
    pThreadItem->m_DebugBuffer = 0;
    if ( !(*(v65 + 40) & 0x10) )
    {
      v66 = RtlCreateQueryDebugBuffer(0, 0);
      pThreadItem->m_DebugBuffer = v66;
      if ( v66 )
      {
        v147 = v53->UniqueProcessId;
        v148 = pThreadItem->m_DebugBuffer;
        hThread = _beginthreadex(0, 0, QueryProcessDebugInforThreadProc, &v147, 0, &ThreadId);
        CloseHandle(pThreadItem->m_hThread);
        if ( WaitForSingleObject(hThread, 4000u) == WAIT_TIMEOUT )
        {
          LeaveCriticalSection(&gProcThreadsLock);
          TerminateThread(hThread, 1u);
        }
        GetExitCodeThread(hThread, &ExitCode);
        if ( ExitCode )
        {
          RtlDestroyQueryDebugBuffer(pThreadItem->m_DebugBuffer);
          pThreadItem->m_DebugBuffer = 0;
        }
        CloseHandle(hThread);
      }
    }
    if ( SymInitialize )
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
    CTreeList::InitHeaderColumn(pThreadItem_2->m_hWndList, ::wParam, ::wParam, byte_10653B4);
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
    if ( GetCurrentProcessId() != *(pThreadItem_2->m_Param + 68) && pThreadItem_2->m_hProcess )
    {
      hWnd_4 = hWnd_3;
      GetDlgItem = ::GetDlgItem;
    }
    else
    {
      hWnd_4 = hWnd_3;
      GetDlgItem = ::GetDlgItem;
      v77 = ::GetDlgItem(hWnd_3, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
      EnableWindow(v77, 0);
      v78 = ::GetDlgItem(hWnd_4, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
      EnableWindow(v78, 0);
      v79 = ::GetDlgItem(hWnd_4, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
      EnableWindow(v79, 0);
      v80 = ::GetDlgItem(hWnd_4, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
      EnableWindow(v80, 0);
    }
    if ( !*StackWalk64 )
    {
      v81 = GetDlgItem(hWnd_4, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
      EnableWindow(v81, 0);
    }
    return 1;
  }
  // Handler for WM_COMMAND
  if ( wParam > IDC_PAGE_PROCTHREADS_BUTTON_MODULE )
  {
    if ( wParam > 40001 )
    {
      if ( wParam == IDM_VIEW_REFRESH_NOW )
      {
        SetEvent(ghRefreshEventHandle);
        return 0;
      }
      if ( wParam - 40092 > 1 )
        return 0;
      v131 = wParam;
    }
    else
    {
      if ( wParam != 40001 )
      {
        switch ( wParam )
        {
          case IDC_PAGE_PROCTHREADS_BUTTON_STACK:
            if ( !*StackWalk64 )
              return 0;
            lParam.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( lParam.iItem == -1 )
              return 0;
            lParam.iSubItem = 0;
            lParam.mask = 4;
            if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParam) )
              return 0;
            v127 = lParam.lParam;
            v128 = Fake_OpenThread(lParam.lParam->field_2C, 0x4Au);
            if ( v128 )
            {
              dwInitParam = *(pUserData->m_Param + 0x44);
              v142 = v127->field_2C;
              v144 = pUserData->m_hProcess;
              hObject = v128;
              v146 = pUserData->m_DebugBuffer;
              v145 = pUserData->m_SystemModules;
              DialogBoxParamW(ghMainInstance, L"THREADSTACK", hWnd, DlgThreadStack, &dwInitParam);
              if ( hObject )
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
            lParam.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( lParam.iItem == -1 )
              return 0;
            lParam.iSubItem = 0;
            lParam.mask = 4;
            if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParam) )
              return 0;
            pThreadItem_1 = lParam.lParam;
            ThreadHandle_1 = Fake_OpenThread(lParam.lParam->field_2C, 0x20000u);
            if ( ThreadHandle_1 )
            {
              memset(ListParam, 0, 4288u);
              wsprintfW(szBuffer, L"Thread %d", pThreadItem_1->m_hProcess);
              v164 = 0;
              wcscpy_s(szText, 0x40u, L"Thread");
              v165 = ThreadHandle_1;
              v163 = GetCurrentProcessId();
              FillHandleListParam(hWnd, ListParam);
              CloseHandle(ThreadHandle_1);
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
  if ( wParam == IDC_PAGE_PROCTHREADS_BUTTON_MODULE )
  {
    lParam.iItem = SendMessageW(pUserData->m_hWndList, 0x100Cu, 0xFFFFFFFF, 2);
    if ( lParam.iItem != -1 )
    {
      lParam.iSubItem = 0;
      lParam.mask = 4;
      if ( SendMessageW(pUserData->m_hWndList, 0x104Bu, 0, &lParam) )
      {
        qmemcpy(v135, lParam.lParam, 0x290u);
        if ( v136[0] )
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
  if ( wParam != IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND )
    return 0;
LABEL_156:
  lParam.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( lParam.iItem == -1 )
    return 0;
  lParam.iSubItem = 0;
  lParam.mask = 4;
  if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParam) )
    return 0;
  v118 = lParam.lParam;
  pThreadItem_1 = lParam.lParam;
  if ( wParam == IDC_PAGE_PROCTHREADS_BUTTON_KILL )
  {
    wsprintfW(szBuffer2, L"Are you sure you want to kill thread %d?", lParam.lParam->field_2C);
    if ( MessageBoxW(ghMainWnd, szBuffer2, L"Process Explorer", 0x31u) != 2 )
    {
      v118 = &pThreadItem_1->m_Next;
      goto LABEL_161;
    }
    return 0;
  }
LABEL_161:
  ThreadHandle = Fake_OpenThread(v118[11], 3u);
  if ( !ThreadHandle )
  {
    ReportMsg(L"Unable to access thread", pUserData->m_hWndList);
    return 0;
  }
  if ( wParam == IDC_PAGE_PROCTHREADS_BUTTON_KILL )
  {
    if ( !TerminateThread(ThreadHandle, 0) )
    {
      ReportMsg(L"Unable to terminate thread", ghMainWnd);
      CloseHandle(ThreadHandle);
      return 0;
    }
  }
  else
  {
    v121 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
    GetWindowTextW(v121, szBuffer2, 1024);
    v122 = L"R&esume";
    v123 = szBuffer2;
    while ( 1 )
    {
      v124 = *v123 < *v122;
      if ( *v123 != *v122 )
        break;
      if ( !*v123 )
        goto LABEL_187;
      v125 = v123[1];
      v124 = v125 < v122[1];
      if ( v125 != v122[1] )
        break;
      v123 += 2;
      v122 += 2;
      if ( !v125 )
      {
LABEL_187:
        v126 = 0;
        goto LABEL_189;
      }
    }
    v126 = -v124 | 1;
LABEL_189:
    if ( v126 )
    {
      if ( NtSuspendThread(v122, ThreadHandle) )
        ReportMsg(L"Unable to suspend thread", ghMainWnd);
    }
    else if ( NtResumeThread(v122, ThreadHandle) )
    {
      ReportMsg(L"Unable to resume thread", ghMainWnd);
      CloseHandle(ThreadHandle);
      return 0;
    }
  }
  CloseHandle(ThreadHandle);
  return 0;
}
// 103E398: using guessed type wchar_t aREsume[8];
// 1045A74: using guessed type wchar_t aWaitS[8];
// 1045AF4: using guessed type wchar_t aProperties[11];
// 1045BE4: using guessed type wchar_t aUnableToTermin[27];
// 1045C1C: using guessed type wchar_t aUnableToResume[24];
// 1045C4C: using guessed type wchar_t aUnableToSuspen_0[25];
// 1046C40: using guessed type __int128 xmmword_1046C40;
// 1046C60: using guessed type __int128 xmmword_1046C60;
// 1046C70: using guessed type RECT stru_1046C70;
// 105E8B8: using guessed type wchar_t aExecutive[10];
// 10610DC: using guessed type int dword_10610DC;
// 1064E54: using guessed type int gdwVersion;
// 10653B4: using guessed type char byte_10653B4;
// 106F258: using guessed type int (__stdcall *GetThreadIdealProcessorEx)(_DWORD, _DWORD);
// 106F264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 106F328: using guessed type int (__stdcall *GetLogicalProcessorInformationEx)(_DWORD, _DWORD, _DWORD);

//----- (00FEC7F0) --------------------------------------------------------
int __stdcall UpdateProcThreadsInfoThreadProc(tagThreadItem *pThreadItem)
{
  HWND hWndList; // edi
  tagThreadItem *pThreadItem_2; // esi
  DWORD dwRet; // eax
  int v4; // ecx
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ebx
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
  tagTREEVIEWITEMPARAM *v23; // ecx
  int v24; // eax
  void *v25; // eax
  tagTREEVIEWITEMPARAM *v26; // edi
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
  tagTREEVIEWITEMPARAM *v38; // ecx
  double v39; // xmm1_8
  char v40; // dh
  int v41; // eax
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
  _SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfor_1; // [esp-14h] [ebp-BA4h]
  unsigned __int64 timeDelta; // [esp-10h] [ebp-BA0h]
  PRTL_DEBUG_BUFFER dwNumberOfProcessors; // [esp-8h] [ebp-B98h]
  _RTL_PROCESS_MODULES *bFalse; // [esp-4h] [ebp-B94h]
  LPARAM lParam; // [esp+Ch] [ebp-B84h]
  int v125; // [esp+18h] [ebp-B78h]
  int v126; // [esp+1Ch] [ebp-B74h]
  THREAD_BASIC_INFORMATION ThreadInformation; // [esp+24h] [ebp-B6Ch]
  SIZE_T NumberOfBytesRead; // [esp+40h] [ebp-B50h]
  ULONG ReturnLength; // [esp+44h] [ebp-B4Ch]
  CLIENT_ID ClientID; // [esp+48h] [ebp-B48h]
  int v131; // [esp+50h] [ebp-B40h]
  HANDLE hEvent2[2]; // [esp+54h] [ebp-B3Ch]
  size_t cbRet; // [esp+5Ch] [ebp-B34h]
  int v134; // [esp+60h] [ebp-B30h]
  double v135; // [esp+64h] [ebp-B2Ch]
  int ThreadHandle; // [esp+6Ch] [ebp-B24h]
  tagLVITEMW item; // [esp+70h] [ebp-B20h]
  WPARAM wParam; // [esp+A4h] [ebp-AECh]
  WPARAM v139; // [esp+A8h] [ebp-AE8h]
  _DWORD v140[2]; // [esp+ACh] [ebp-AE4h]
  WPARAM v141; // [esp+B4h] [ebp-ADCh]
  WPARAM v142; // [esp+B8h] [ebp-AD8h]
  WPARAM v143; // [esp+BCh] [ebp-AD4h]
  int dwTebAddress; // [esp+C0h] [ebp-AD0h]
  unsigned int v145; // [esp+C4h] [ebp-ACCh]
  int v146; // [esp+C8h] [ebp-AC8h]
  HANDLE hHandle; // [esp+CCh] [ebp-AC4h]
  HWND hWndParent; // [esp+D0h] [ebp-AC0h]
  int nItem; // [esp+D4h] [ebp-ABCh]
  int nIndex; // [esp+D8h] [ebp-AB8h]
  char dwHighDateTime[4]; // [esp+DCh] [ebp-AB4h]
  HWND hWndList_1; // [esp+E0h] [ebp-AB0h]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+E4h] [ebp-AACh]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // [esp+E8h] [ebp-AA8h]
  tagThreadItem *pThreadItem_1; // [esp+ECh] [ebp-AA4h]
  int v156; // [esp+F3h] [ebp-A9Dh]
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
  if ( pThreadItem_2->field_18 )
    goto __cleanup;
  LOBYTE(v4) = v156;
  v142 = v139;
  *(&v156 + 1) = v4;
  v143 = wParam;
  while ( 1 )
  {
    nItem = 0;
    nIndex = 0;
    *dwHighDateTime = 0;
    if ( dwRet )
      goto LABEL_85;
    BYTE1(v156) = 0;
    hWndParent = GetParent(hWndList);
    if ( !fOK )
    {
      item.mask = LVIF_PARAM;
      nCount = SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
      item.iSubItem = 0;
      item.iItem = nCount - 1;
      if ( SendMessageW(hWndList, LVM_GETITEMW, 0, &item) )
      {
        nIndex_1 = nIndex;
        do
        {
          v8 = sub_FF58D0(SendMessageW, hWndList, &item, item.lParam, &v156);
          v9 = BYTE1(v156);
          if ( v8 )
            v9 = 1;
          *(&v156 + 1) = v9;
          if ( v156 )
          {
            if ( item.lParam->field_C != 1 )
              --item.lParam->field_14;
            ++nIndex_1;
          }
          item.mask = 4;
          item.iSubItem = 0;
        }
        while ( SendMessageW(hWndList, LVM_GETITEMW, 0, &item) );
        nIndex = nIndex_1;
        pThreadItem_2 = pThreadItem_1;
      }
    }
    FileTime = GetSystemProcessInfo(&pSystemProcessInfo, &cbRet);
    dwLowDateTime = FileTime.dwLowDateTime;
    *dwHighDateTime = FileTime.dwHighDateTime;
    pSystemProcessInfo_1 = pSystemProcessInfo;
    dwProcessId = *(pThreadItem_2->m_Param + 68);
    if ( pSystemProcessInfo->UniqueProcessId != dwProcessId )
      break;
LABEL_19:
    *&dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    timeDelta = __PAIR__(FileTime.dwHighDateTime, dwLowDateTime) - *&pThreadItem_2->m_TimeLast;
    v141 = timeDelta * gSystemInfo.dwNumberOfProcessors >> 32;
    v146 = timeDelta * gSystemInfo.dwNumberOfProcessors;
    if ( !(timeDelta * gSystemInfo.dwNumberOfProcessors) )
    {
      v146 = 1;
      v141 = 0;
    }
    v15 = *dwHighDateTime;
    pThreadItem_2->m_TimeLast.dwLowDateTime = dwLowDateTime;
    pThreadItem_2->m_TimeLast.dwHighDateTime = v15;
    if ( GetProcessorSystemCycleTime )
    {
      v16 = 8 * gSystemInfo.dwNumberOfProcessors;
      pSystemProcessorCycleTimeInfor = malloc(8 * gSystemInfo.dwNumberOfProcessors);
      NtQuerySystemInformation(SystemProcessorCycleTimeInformation, pSystemProcessorCycleTimeInfor, v16, &ReturnLength);
      LODWORD(v18) = sub_FDE4B0(0, pSystemProcessInfo, pSystemProcessorCycleTimeInfor, 0);
      pThreadItem_2 = pThreadItem_1;
      pSystemProcessorCycleTimeInfor_1 = pSystemProcessorCycleTimeInfor;
      v19 = v18 - pThreadItem_1->m_CycleTime;
      v142 = (v18 - pThreadItem_1->m_CycleTime) >> 32;
      v143 = v19;
      LODWORD(pThreadItem_1->m_CycleTime) = v18;
      HIDWORD(pThreadItem_2->m_CycleTime) = HIDWORD(v18);
      free(pSystemProcessorCycleTimeInfor_1);
      hWndList = hWndList_1;
    }
    v20 = &pSystemProcessInfo_1[1];
    if ( pThreadItem_2->field_34 )
      v20 = &pSystemProcessInfo_1->ReadOperationCount;
    v21 = 0;
    *dwHighDateTime = pSystemProcessInfo_1->NumberOfThreads;
    v145 = 0;
    if ( *dwHighDateTime )
    {
      while ( 1 )
      {
        if ( pThreadItem_2->field_18 )
          goto __cleanup1;
        if ( !*(v20 + 36) )
          *(v20 + 36) = v21;
        v22 = 0;
        if ( ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) )
          break;
LABEL_61:
        if ( pThreadItem_1->field_18 )
        {
          pThreadItem_2 = pThreadItem_1;
          goto __cleanup1;
        }
        if ( v22 == ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) )
        {
          BYTE1(v156) = 1;
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
          if ( !v43 )
            ThreadHandle_1 = ThreadHandle;
          LocalBuffer[10] = ThreadHandle_1;
          if ( QueryThreadCycleTime && ThreadHandle_1 )
            QueryThreadCycleTime(ThreadHandle_1, &LocalBuffer[154]);
          v45 = pThreadItem_1;
          LocalBuffer[11] = *(v20 + 36);
          LocalBuffer[148] = *(v20 + 48);
          bFalse = pThreadItem_1->m_SystemModules;
          LocalBuffer[149] = 0;
          dwNumberOfProcessors = pThreadItem_1->m_DebugBuffer;
          LocalBuffer[12] = *(v20 + 28);
          sub_FDDD60(
            0,
            0,
            LocalBuffer,
            pThreadItem_1->m_hProcess,
            *(v20 + 28),
            *(v20 + 28) >> 31,
            dwNumberOfProcessors,
            &bFalse->NumberOfModules);
          *&LocalBuffer[156] = *v20 + *(v20 + 8);
          v46 = 2;
          if ( fOK )
            v46 = 0;
          LocalBuffer[5] = 0;
          LocalBuffer[4] = v46;
          LocalBuffer[158] = v45->m_Param;
          *&LocalBuffer[144] = 0i64;
          LocalBuffer[162] = 0;
          if ( GetThreadIdealProcessorEx )
            GetThreadIdealProcessorEx(LocalBuffer[10], &LocalBuffer[152]);
          if ( *(v45->m_Param + 40) & 0x20 && gdwVersion >= 1 )
          {
            if ( !NtQueryInformationThread(
                    LocalBuffer[10],
                    ThreadBasicInformation,
                    &ThreadInformation,
                    sizeof(_THREAD_BASIC_INFORMATION),
                    0) )
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
              if ( dwTebAddress )
              {
                if ( sub_FFEFB0(dwTebAddress) )
                {
                  v48 = sub_FFEFB0(dwTebAddress);
                  LocalBuffer[162] = _wcsdup(v48);
                }
              }
            }
          }
          else
          {
            LocalBuffer[161] = -1;
          }
          bFalse = v45;
          qmemcpy(&LocalBuffer2, LocalBuffer, 656u);
          hWndList = hWndList_1;
          sub_FB7E70(
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
            v119);
          pThreadItem_2 = pThreadItem_1;
          SetEvent(pThreadItem_1->m_hEvent);
        }
        else
        {
          pThreadItem_2 = pThreadItem_1;
        }
        v20 += 64;
        v21 = v145 + 1;
        v145 = v21;
        if ( v21 >= pSystemProcessInfo_1->NumberOfThreads )
          goto LABEL_82;
      }
      while ( 1 )
      {
        item.mask = 4;
        item.iItem = v22;
        item.iSubItem = 0;
        ::SendMessageW(hWndList, LVM_GETITEMW, 0, &item);
        v23 = item.lParam;
        if ( item.lParam->field_2C == *(v20 + 36) )
          break;
        if ( ++v22 >= ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) )
          goto LABEL_61;
      }
      v24 = *(v20 + 48) - item.lParam[7].field_4;
      if ( v24 != item.lParam[6].field_50 || 0 != item.lParam[7].field_0 )
      {
        if ( v24 <= 0 )
          item.lParam[6].field_50 = 0;
        else
          item.lParam[6].field_50 = v24;
        v23[7].field_0 = 0;
        v23 = item.lParam;
        BYTE1(v156) = 1;
      }
      v23[7].field_4 = *(v20 + 48);
      item.lParam[7].field_8 = 0;
      if ( QueryThreadCycleTime )
      {
        v25 = item.lParam->field_28;
        if ( v25 )
        {
          QueryThreadCycleTime(v25, v140);
          if ( ((*v140 - *&item.lParam[7].field_1C) >> 32) < 0
            || (*v140 < *&item.lParam[7].field_1C || (*v140 - *&item.lParam[7].field_1C) >> 32 == 0)
            && v140[0] == item.lParam[7].field_1C )
          {
            item.lParam[7].field_C = 0;
            item.lParam[7].field_10 = 0;
          }
          else
          {
            *&item.lParam[7].field_C = *v140 - *&item.lParam[7].field_1C;
          }
          BYTE1(v156) = 1;
        }
      }
      item.lParam[7].field_1C = v140[0];
      item.lParam[7].field_20 = v140[1];
      v26 = item.lParam;
      v27 = *v20 + *(v20 + 8);
      v28 = *v20 + *(v20 + 8);
      v134 = HIDWORD(v28);
      v29 = v27 < item.lParam[7].field_24;
      v30 = v27 - item.lParam[7].field_24;
      v131 = v28;
      v31 = HIDWORD(v28) - (v29 + item.lParam[7].field_28);
      if ( GetProcessorSystemCycleTime && item.lParam->field_28 )
      {
        v32 = *&item.lParam[7].field_C;
        v33 = v142;
        v34 = v143;
      }
      else
      {
        v32 = __PAIR__(v31, v30);
        v33 = v141;
        v34 = v146;
      }
      v135 = v32 * 100.0;
      v35 = __PAIR__(v33, v34);
      v36 = 0;
      v37 = v135;
      ++nItem;
      item.lParam[7].field_24 = v131;
      v26[7].field_28 = v134;
      v38 = item.lParam;
      v39 = v37 / v35;
      v40 = item.lParam->field_18;
      if ( v40 )
      {
        v41 = item.lParam->field_1C;
        if ( v41 < gConfig.dwHighlightDuration )
        {
          item.lParam->field_10 = 2;
          v38->field_14 = v41;
LABEL_59:
          hWndList = hWndList_1;
          if ( v39 != *&item.lParam[6].field_48 )
          {
            *&item.lParam[6].field_48 = v39;
            BYTE1(v156) = 1;
          }
          goto LABEL_61;
        }
        if ( v40 )
        {
          v36 = 1;
          LOBYTE(item.lParam->field_18) = 0;
        }
      }
      v42 = BYTE1(v156);
      v38->field_10 = 0;
      if ( v36 )
        v42 = 1;
      BYTE1(v156) = v42;
      goto LABEL_59;
    }
LABEL_82:
    SendMessageW = ::SendMessageW;
    if ( pThreadItem_2->field_18 )
      goto __cleanup;
    if ( nItem == nIndex )
    {
      LOBYTE(v4) = BYTE1(v156);
LABEL_85:
      if ( !v4 )
        goto LABEL_87;
    }
    InvalidateRect(hWndList, 0, 0);
    v139 = ::wParam;
    wParam = 1044;
    SendMessageW(hWndList, LVM_SORTITEMS, &wParam, PropProcThreadsSortCallback);
    SendMessageW(hWndList, WM_SETREDRAW, 1u, 0);
    bFalse = *dwHighDateTime;
    wsprintfW(String, L"%d", *dwHighDateTime);
    SetDlgItemTextW(hWndParent, IDC_PAGE_PROCTHREADS_STATIC_STATIC, String);
LABEL_87:
    if ( fOK )
    {
      SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 3u, 65534);
      v126 = 3;
      v125 = 3;
      SendMessageW(hWndList, LVM_SETITEMSTATE, 0, &lParam);
      hHandle = _beginthreadex(0, 0, sub_FED400, pThreadItem_2, 0, 0);
      fOK = 0;
    }
    if ( pThreadItem_2->field_4 )
      goto __cleanup;
    dwRet = WaitForMultipleObjects(2u, hEvent2, 0, 0xFFFFFFFF);
    if ( pThreadItem_2->field_18 )
      goto __cleanup;
    LOBYTE(v4) = BYTE1(v156);
  }
  v13 = pSystemProcessInfo_1;
  while ( 1 )
  {
    v14 = v13->NextEntryOffset;
    if ( !v14 )
      break;
    pSystemProcessInfo_1 = (pSystemProcessInfo_1 + v14);
    v13 = pSystemProcessInfo_1;
    if ( pSystemProcessInfo_1->UniqueProcessId == dwProcessId )
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
  if ( pThreadItem_2->field_4 || InterlockedDecrement(&pThreadItem_2->m_nRefCount) )
  {
    v56 = hWndList_1;
    InvalidateRect(hWndList_1, 0, 1);
    SendMessageW(v56, WM_SETREDRAW, 1u, 0);
  }
  else
  {
    v54 = hHandle;
    if ( hHandle )
    {
      SetEvent(pThreadItem_2->m_hEvent);
      WaitForSingleObject(v54, 0xFFFFFFFF);
    }
    v55 = pThreadItem_2->m_Next;
    if ( pThreadItem_2->m_Next )
    {
      do
      {
        pThreadItem_2->m_Next = v55;
        v55 = v55[8].m_hEvent3;
        if ( pThreadItem_2->m_Next->m_SystemModules )
          CloseHandle(pThreadItem_2->m_Next->m_SystemModules);
        if ( pThreadItem_2->m_Next[7].m_hEvent3 )
          free(pThreadItem_2->m_Next[7].m_hEvent3);
        if ( pThreadItem_2->m_Next[8].m_hEvent2 )
          free(pThreadItem_2->m_Next[8].m_hEvent2);
        free(pThreadItem_2->m_Next);
      }
      while ( v55 );
    }
    if ( pThreadItem_2->m_hProcess )
    {
      CloseHandle(pThreadItem_2->m_hProcess);
      if ( SymCleanup )
        SymCleanup(pThreadItem_2->m_hProcess);
    }
    CloseHandle(pThreadItem_2->m_hEvent);
    CloseHandle(pThreadItem_2->m_hEvent2);
    CloseHandle(pThreadItem_2->m_hEvent3);
    if ( pThreadItem_2->m_DebugBuffer )
      RtlDestroyQueryDebugBuffer(pThreadItem_2->m_DebugBuffer);
    if ( pThreadItem_2->m_SystemModules )
      free(pThreadItem_2->m_SystemModules);
    free(pThreadItem_2);
  }
  return 0;
}
// FED400: using guessed type int __stdcall sub_FED400(int);
// 103CDC0: using guessed type double db_onehundred;
// 1064E54: using guessed type int gdwVersion;
// 106B1CC: using guessed type int gdwTebAddressOffset;
// 106F258: using guessed type int (__stdcall *GetThreadIdealProcessorEx)(_DWORD, _DWORD);
// 106F264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 106F2F4: using guessed type int GetProcessorSystemCycleTime;

//----- (00FED400) --------------------------------------------------------
int __stdcall sub_FED400(int a1)
{
  HWND v1; // edi
  HWND v2; // eax
  void *v3; // ST1C_4
  unsigned int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // esi
  HWND v9; // eax
  HWND v10; // ST14_4
  HWND v11; // eax
  LPARAM lParam; // [esp+8h] [ebp-844h]
  int v13; // [esp+Ch] [ebp-840h]
  int v14; // [esp+10h] [ebp-83Ch]
  int v15; // [esp+28h] [ebp-824h]
  HWND hDlg; // [esp+3Ch] [ebp-810h]
  int v17; // [esp+40h] [ebp-80Ch]
  HWND hWnd; // [esp+44h] [ebp-808h]
  WCHAR String; // [esp+48h] [ebp-804h]

  v17 = a1;
  lParam = 0;
  memset(&v13, 0, 0x30u);
  v1 = *(a1 + 36);
  hWnd = v1;
  v2 = GetParent(v1);
  v3 = *(a1 + 20);
  hDlg = v2;
  WaitForSingleObject(v3, 0xFFFFFFFF);
  if ( !*(a1 + 24) )
  {
    do
    {
      v4 = SendMessageW(v1, 0x1004u, 0, 0);
      while ( 1 )
      {
        v5 = 0;
        if ( !v4 )
          break;
        while ( 1 )
        {
          lParam = 4;
          v13 = v5;
          v14 = 0;
          if ( SendMessageW(v1, 0x104Bu, 0, &lParam) )
            break;
LABEL_7:
          if ( ++v5 >= v4 )
            goto LABEL_8;
        }
        v6 = v15;
        if ( *(v15 + 36) )
        {
          v1 = hWnd;
          goto LABEL_7;
        }
        wsprintfW(&String, L"Loading symbols for %s...", v15 + 52);
        v9 = GetDlgItem(hDlg, 1341);
        SetWindowTextW(v9, &String);
        sub_FDDD60(1, 0, v15, *(v17 + 44), *(v6 + 48), *(v6 + 48) >> 31, *(v17 + 48), *(v17 + 40));
        InvalidateRect(hWnd, 0, 0);
        v10 = hDlg;
        *(v6 + 36) = 1;
        v11 = GetDlgItem(v10, 1341);
        SetWindowTextW(v11, &gszNullString);
        v1 = hWnd;
      }
LABEL_8:
      v7 = v17;
      WaitForSingleObject(*(v17 + 20), 0xFFFFFFFF);
    }
    while ( !*(v7 + 24) );
  }
  return 0;
}
// FED400: using guessed type int __stdcall sub_FED400(int);

//----- (00FED5B0) --------------------------------------------------------
BOOL __stdcall PageProcWMIProviders(HWND hDlg, int a2, WPARAM wParam, int a4)
{
  HWND v4; // edi
  CResizer *v5; // eax
  CResizer *v6; // esi
  HWND v7; // eax
  struct tagResizerItem *v8; // eax
  LONG v9; // eax
  HWND v10; // eax
  int *v11; // esi
  LONG v12; // eax
  HWND v14; // eax
  WPARAM v15; // [esp-8h] [ebp-ACh]
  LPARAM v16; // [esp+10h] [ebp-94h]
  int v17; // [esp+1Ch] [ebp-88h]
  int v18; // [esp+20h] [ebp-84h]
  void *v19; // [esp+44h] [ebp-60h]
  LPARAM lParam; // [esp+48h] [ebp-5Ch]
  LONG v21; // [esp+4Ch] [ebp-58h]
  int v22; // [esp+50h] [ebp-54h]
  int v23; // [esp+54h] [ebp-50h]
  int v24; // [esp+58h] [ebp-4Ch]
  int v25; // [esp+5Ch] [ebp-48h]
  int v26; // [esp+64h] [ebp-40h]
  int v27; // [esp+68h] [ebp-3Ch]
  LONG dwNewLong; // [esp+7Ch] [ebp-28h]
  UINT pnIDs; // [esp+80h] [ebp-24h]
  int v30; // [esp+84h] [ebp-20h]
  int v31; // [esp+88h] [ebp-1Ch]
  WORD pnWidths[2]; // [esp+8Ch] [ebp-18h]
  __int16 v33; // [esp+90h] [ebp-14h]
  int v34; // [esp+A0h] [ebp-4h]

  dwNewLong = a4;
  v4 = GetDlgItem(hDlg, 40753);
  GetWindowLongW(hDlg, -21);
  lParam = 0;
  memset(&v21, 0, 0x30u);
  pnIDs = 40754;
  v30 = 40755;
  v31 = 40756;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  v33 = MulDiv(100, gLogPixelSize.x, 96);
  switch ( a2 )
  {
    case 43:
      CMainWnd::DrawList(dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hDlg, a2, wParam, dwNewLong);
    case 272:
      v5 = operator new(0x40u);
      v19 = v5;
      v34 = 0;
      if ( v5 )
        v6 = CResizer::CResizer(v5, hDlg);
      else
        v6 = 0;
      v34 = -1;
      v7 = GetDlgItem(hDlg, 40753);
      if ( v7 )
      {
        v8 = CResizer::AddItem(v6, v7, 1);
        *&v8->m_rect2.left = 0i64;
        *&v8->m_rect2.right = db_one;
      }
      PropSheet_UpdateTab(hDlg);
      SetWindowLongW(hDlg, -21, dwNewLong);
      v9 = GetWindowLongW(v4, -16);
      SetWindowLongW(v4, -16, v9 & 0xFFFFFFFD | 1);
      SendMessageW(v4, 0x1036u, 0x4020u, 16416);
      v10 = SendMessageW(v4, 0x104Eu, 0, 0);
      CTreeList::InitToolTips(v10);
      gOldListWndProc = SetWindowLongW(v4, -4, Proxy_ListCtrlWndProc);
      SendMessageW(v4, 0x30u, ghConfigFont, 0);
      CTreeView::InitListHeader(v4, &pnIDs, pnWidths, 3u);
      v11 = *(dwNewLong + 868);
      if ( !v11 )
        goto LABEL_10;
      break;
    case 273:
      switch ( wParam )
      {
        case 0x9C41u:
          v15 = 40014;
          goto LABEL_15;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          break;
        case 0x9C9Cu:
        case 0x9C9Du:
          v15 = wParam;
LABEL_15:
          v14 = GetParent(hDlg);
          PostMessageW(v14, 0x111u, v15, 0);
          break;
        default:
          return 0;
      }
      return 0;
    default:
      return 0;
  }
  while ( 1 )
  {
    lParam = 5;
    v21 = 0x7FFFFFFF;
    v22 = 0;
    v24 = 0;
    v23 = 0;
    v25 = *v11;
    v26 = 0;
    v27 = 1;
    v12 = SendMessageW(v4, 0x104Du, 0, &lParam);
    dwNewLong = v12;
    if ( v12 == -1 )
      break;
    v21 = v12;
    lParam = 1;
    v22 = 1;
    v25 = v11[1];
    SendMessageW(v4, 0x104Cu, 0, &lParam);
    v21 = dwNewLong;
    lParam = 1;
    v22 = 2;
    v25 = v11[2];
    SendMessageW(v4, 0x104Cu, 0, &lParam);
    v11 = v11[3];
    if ( !v11 )
    {
LABEL_10:
      SendMessageW(v4, 0x101Eu, 0, 0xFFFF);
      SendMessageW(v4, 0x101Eu, 1u, 0xFFFF);
      SendMessageW(v4, 0x101Eu, 2u, 0xFFFF);
      v18 = 3;
      v17 = 3;
      SendMessageW(v4, 0x102Bu, 0, &v16);
      SetFocus(v4);
      return 1;
    }
  }
  return 0;
}

//----- (00FEDA70) --------------------------------------------------------
char __cdecl PE_IsProcessInJob(HANDLE ProcessHandle, DWORD dwProcessId, DWORD *dwValue3, DWORD dwValue4)
{
  SYSTEM_HANDLE_INFORMATION *v4; // eax
  ULONG v5; // edi
  int v6; // edi
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *v7; // ebx
  void *v8; // esi
  _DWORD *v9; // edi
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *pEntry; // [esp+4h] [ebp-818h]
  DWORD *v12; // [esp+8h] [ebp-814h]
  DWORD v13; // [esp+Ch] [ebp-810h]
  int v14; // [esp+10h] [ebp-80Ch]
  int bProcessInJob; // [esp+14h] [ebp-808h]
  wchar_t v16; // [esp+18h] [ebp-804h]

  v13 = dwValue4;
  v12 = dwValue3;
  if ( !*IsProcessInJob || !ProcessHandle )
    return 0;
  if ( !dwValue3 )
  {
    if ( IsProcessInJob(ProcessHandle, 0, &bProcessInJob) && bProcessInJob == 1 )
      return 1;
    return 0;
  }
  v4 = gpSystemHandleInfo;
  if ( gpSystemHandleInfo )
    v5 = gpSystemHandleInfo->NumberOfHandles;
  else
    v5 = 0;
  v6 = v5 - 1;
  if ( v6 < 0 )
    return 0;
  while ( 1 )
  {
    GetHandleTableEntry(v4, v6, &pEntry);
    v7 = pEntry;
    v14 = pEntry[1].CreatorBackTraceIndex;
    if ( _wcsicmp(&gpszObjectTypeNames[0x40 * v14], L"Job") )
      goto LABEL_13;
    v8 = PE_DuplicateProcessHandle(*&v7->ObjectTypeIndex, v7->Object, 0x80000000);
    if ( v8 )
    {
      if ( IsProcessInJob(ProcessHandle, v8, &bProcessInJob) && bProcessInJob == 1 )
        break;
    }
    CloseHandle(v8);
LABEL_13:
    if ( --v6 < 0 )
      return 0;
    v4 = gpSystemHandleInfo;
  }
  sub_FDC750(&gpszObjectTypeNames[0x40 * v14], v7, &v16, 0x400u, 0);
  v9 = v13;
  if ( v13 )
    *v9 = _wcsdup(&v16);
  *v12 = v8;
  return 1;
}

//----- (00FEDC00) --------------------------------------------------------
HANDLE __cdecl PE_OpenProcess(DWORD dwDesiredAccess, int a2, DWORD dwProcessId)
{
  HANDLE result; // eax
  DWORD BytesReturned; // [esp+0h] [ebp-8h]
  HANDLE OutBuffer; // [esp+4h] [ebp-4h]

  result = OpenProcess(dwDesiredAccess, 0, dwProcessId);
  OutBuffer = result;
  if ( !result )
  {
    if ( GetLastError() == ERROR_ACCESS_DENIED )
      DeviceIoControl(ghDriverHandle, 0x8335003C, &dwProcessId, 4u, &OutBuffer, 4u, &BytesReturned, 0);
    result = OutBuffer;
  }
  return result;
}

//----- (00FEDC50) --------------------------------------------------------
BOOL __cdecl sub_FEDC50(HWND hWnd_1, tagTREEVIEWLISTITEMPARAM *pItem)
{
  int v2; // ebx
  int v3; // edi
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  __m128i v7; // xmm0
  __m128i v8; // xmm0
  HWND v9; // esi
  HWND v10; // eax
  HWND v11; // esi
  LONG v12; // ecx
  int v13; // edx
  HWND v14; // eax
  HWND v15; // eax
  LONG v16; // edi
  LONG v17; // esi
  __int128 v19; // [esp+Ch] [ebp-74h]
  DWORD dwProcessId; // [esp+1Ch] [ebp-64h]
  int v21; // [esp+20h] [ebp-60h]
  LONG v22; // [esp+24h] [ebp-5Ch]
  HWND hWnd; // [esp+28h] [ebp-58h]
  LONG v24; // [esp+2Ch] [ebp-54h]
  WINDOWPLACEMENT wp; // [esp+30h] [ebp-50h]
  struct tagRECT v26; // [esp+5Ch] [ebp-24h]
  struct tagRECT Rect; // [esp+6Ch] [ebp-14h]

  hWnd = hWnd_1;
  v2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
  v3 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
  if ( v2 )
  {
    v21 = GetSystemMetrics(SM_XVIRTUALSCREEN);
    v4 = v21 + v2;
    v6 = GetSystemMetrics(SM_YVIRTUALSCREEN);
    v5 = v6 + v3;
    v22 = v6;
  }
  else
  {
    v22 = SM_CXSCREEN;
    v21 = SM_CXSCREEN;
    v4 = GetSystemMetrics(SM_CXSCREEN);
    v5 = GetSystemMetrics(SM_CYSCREEN);
  }
  v24 = v5;
  if ( pItem->nListType )
    v7 = _mm_loadu_si128(&gConfig.WindowPlacement[3].rcNormalPosition);
  else
    v7 = _mm_loadu_si128(&gConfig.WindowPlacement[2].rcNormalPosition);
  _mm_storeu_si128(&Rect, v7);
  _mm_storeu_si128(&v19, v7);
  memset(&wp, 0, sizeof(WINDOWPLACEMENT));
  v8 = _mm_loadu_si128(&v19);
  v9 = hWnd;
  wp.length = sizeof(WINDOWPLACEMENT);
  _mm_storeu_si128(&wp.rcNormalPosition, v8);
  wp.showCmd = 0;
  SetWindowPlacement(v9, &wp);
  GetWindowRect(v9, &Rect);
  v10 = GetDesktopWindow();
  v11 = FindWindowExW(v10, 0, 0x8002, 0);
  if ( v11 )
  {
    do
    {
      GetWindowThreadProcessId(v11, &dwProcessId);
      if ( dwProcessId == GetCurrentProcessId() && v11 != hWnd )
      {
        GetWindowRect(v11, &v26);
        v12 = Rect.top;
        if ( v26.top == Rect.top )
        {
          v13 = Rect.left;
          if ( v26.left == Rect.left )
          {
            if ( Rect.top + 20 > v5 - 50 || Rect.left + 20 > v4 - 50 )
              goto LABEL_17;
            Rect.bottom += 20;
            Rect.right += 20;
            Rect.top += 20;
            v11 = 0;
            Rect.left += 20;
          }
        }
      }
      v14 = GetDesktopWindow();
      v15 = FindWindowExW(v14, v11, 0x8002, 0);
      v5 = v24;
      v11 = v15;
    }
    while ( v15 );
  }
  v12 = Rect.top;
  v13 = Rect.left;
LABEL_17:
  v16 = Rect.right;
  if ( Rect.right > v4 )
  {
    v16 = v4;
    v13 += v4 - Rect.right;
    Rect.right = v4;
    Rect.left = v13;
  }
  if ( v13 < v21 )
  {
    v13 = v21;
    Rect.left = v21;
  }
  v17 = Rect.bottom;
  if ( Rect.bottom > v24 )
  {
    v17 = v24;
    v12 += v24 - Rect.bottom;
    Rect.bottom = v24;
    Rect.top = v12;
  }
  if ( v12 < v22 )
  {
    v12 = v22;
    Rect.top = v22;
  }
  return MoveWindow(hWnd, v13, v12, v16 - v13, v17 - v12, 0);
}

//----- (00FEDE20) --------------------------------------------------------
int __thiscall sub_FEDE20(int *this, int a2)
{
  int *v2; // edi
  _DWORD *v3; // edx
  int v4; // eax
  int result; // eax

  v2 = this;
  v3 = (*this - 16);
  if ( v3[2] >= a2 || a2 <= 0 || (v4 = (*(**v3 + 8))(v3, a2, 1)) == 0 )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  result = v4 + 16;
  *v2 = result;
  return result;
}

//----- (00FEDE60) --------------------------------------------------------
_DWORD *__cdecl sub_FEDE60(DWORD dwProcessId)
{
  int v1; // ecx
  _DWORD *v2; // esi
  DWORD v3; // edi
  DWORD v4; // eax
  HANDLE v6; // ebx

  v1 = 0;
  v2 = 0;
  v3 = 0;
  if ( gConfig.dwDllColumnCount <= 0 )
    return v2;
  while ( 1 )
  {
    v4 = gConfig.dwDllColumnMap[v1];
    if ( v4 == 1115 || v4 == 1116 || v4 == 1317 || v4 == 1118 )
      break;
    if ( ++v1 >= gConfig.dwDllColumnCount )
      return 0;
  }
  v6 = OpenProcess(0x410u, 0, dwProcessId);
  if ( !v6 )
    return v2;
  while ( 1 )
  {
    if ( QueryWorkingSet(v6, v2, v3) )
    {
      if ( !v2 )
        goto LABEL_14;
      if ( v3 >= 4 * *v2 )
        goto LABEL_17;
    }
    if ( v2 )
      free(v2);
LABEL_14:
    if ( GetLastError() != 24 )
      break;
    v3 += 0x4000;
    v2 = malloc(v3);
  }
  v2 = 0;
LABEL_17:
  CloseHandle(v6);
  return v2;
}

//----- (00FEDF20) --------------------------------------------------------
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
    v284 = sub_FDA500(SystemProcessInfo);
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
  v49 = sub_FB3340(
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
    sub_FDEB20(ProcessHandle, &pItemParam->field_3A0, &pItemParam->field_3A4, &v284, &v275, &v271, &v273);
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
    v123 = *sub_FF5820(&gMap3, &v275, &pItemParam->dwProcessId);
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
    fUsingWS = sub_FF5820(&gMap2, &v275, &pItemParam->dwProcessId);
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
// 1064E54: using guessed type int gdwVersion;
// FEDF20: using guessed type unsigned __int64 ProcessorIdleCycleTime[256];

//----- (00FEF7C0) --------------------------------------------------------
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

//----- (00FEF870) --------------------------------------------------------
char __usercall sub_FEF870@<al>(int a1@<ebx>, int a2, int a3, int a4, DWORD dwProcessId, int a6, int a7, int a8)
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
      sub_FE0DD0(&FileName);
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
        v18 = sub_FF8A20(v30);
        v19 = v46;
        if ( v18 )
          v19 = 1;
        Buffer.BaseAddress = Buffer.BaseAddress + v10;
        v46 = v19;
        sub_FDC400(v42, v17);
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
      sub_FC43C0(&FileName, &Dst, 0x41u, &dwLen, &v72);
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
        sub_FD9DE0(&v69, L"%s %s", &DateStr, &TimeStr);
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
        sub_FB78D0(hWnd, &v48);
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
      sub_FDC400(v42, &v56);
      v28 = lpFileName;
      v58 = 0;
      v27 = *(v36 + 88);
      v74 = sub_FABB70(v27, lpFileName);
      if ( gdwValue_4F10B8[1] == v40 )
      {
        v57 = 2;
      }
      else
      {
        v59 = 0;
        v57 = 0;
      }
      if ( Buffer.Type == 0x1000000 && sub_FCE970(lpFileName, &v68, &hObject, &BaseAddress) )
        v61 |= 4u;
      qmemcpy(&v26, &v56, 0x188u);
      sub_FB7790(hWnd, v26);
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
// 10610B8: using guessed type int gdwValue_4F10B8[3];

//----- (00FEFFD0) --------------------------------------------------------
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
// 1045560: using guessed type wchar_t aErrorOpeningSe_0[34];
// 10455A8: using guessed type wchar_t aErrorSendingCo[33];

//----- (00FF0400) --------------------------------------------------------
BOOL __cdecl sub_FF0400(HWND hDlg, int nIDDlgItem, int ArgList, int a4)
{
  WCHAR String; // [esp+4h] [ebp-68h]

  sub_FD9DA0(&String, L"%I64d", ArgList, a4);
  sub_FC3290(&String, 0x32u);
  return SetDlgItemTextW(hDlg, nIDDlgItem, &String);
}

//----- (00FF0460) --------------------------------------------------------
BOOL __cdecl sub_FF0460(HWND hDlg, int nIDDlgItem, int a3, int a4)
{
  WCHAR String; // [esp+4h] [ebp-68h]

  sub_FD9DA0(&String, L"%I64d", __PAIR__(a4, a3) / 1024);
  sub_FC3290(&String, 0x32u);
  wcscat_s(&String, 0x32u, L" KB");
  return SetDlgItemTextW(hDlg, nIDDlgItem, &String);
}

//----- (00FF04E0) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_FF04E0(CResizer *this, int a2, int a3))(HWND hWnd, LPRECT lpRect)
{
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v4 = a2;
  v5 = a3;
  return sub_FF0550(this, 2, &v4);
}

//----- (00FF0510) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_FF0510(CResizer *this, int a2, int a3, int a4))(HWND hWnd, LPRECT lpRect)
{
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]

  v5 = a2;
  v6 = a3;
  v7 = a4;
  return sub_FF0550(this, 3, &v5);
}

//----- (00FF0550) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_FF0550(CResizer *this, int a2, int a3))(HWND hWnd, LPRECT lpRect)
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

//----- (00FF0640) --------------------------------------------------------
BOOL __stdcall sub_FF0640(int a1, int a2, DWORD BytesReturned, LPVOID lpOutBuffer, DWORD nOutBufferSize, int a6)
{
  BOOL result; // eax
  DWORD v7; // esi
  int InBuffer; // [esp+0h] [ebp-8h]
  int v9; // [esp+4h] [ebp-4h]

  if ( a2 >= gSystemInfo.lpMaximumApplicationAddress )
  {
    v7 = nOutBufferSize;
    InBuffer = dword_106AB88;
    v9 = a2;
    result = DeviceIoControl(ghDriverHandle, 0x83350024, &InBuffer, 8u, lpOutBuffer, nOutBufferSize, &BytesReturned, 0);
    if ( result )
    {
      *a6 = v7;
      result = 1;
    }
    else
    {
      *a6 = 0;
    }
  }
  else
  {
    result = 1;
    *a6 = 0;
  }
  return result;
}
// 106AB88: using guessed type int dword_106AB88;

//----- (00FF06C0) --------------------------------------------------------
DWORD __cdecl sub_FF06C0(char a1, int a2, int a3)
{
  int v3; // esi
  HANDLE v4; // ebx
  DWORD result; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // edx
  _DWORD *v12; // ecx
  int v13; // esi
  _DWORD *v14; // edi
  _DWORD *v15; // ebx
  void **v16; // esi
  void *v17; // ecx
  ULONG *v18; // esi
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+8h] [ebp-3Ch]
  struct _CLIENT_ID ClientId; // [esp+20h] [ebp-24h]
  HANDLE v21; // [esp+28h] [ebp-1Ch]
  HANDLE hObject; // [esp+2Ch] [ebp-18h]
  int v23; // [esp+30h] [ebp-14h]
  int v24; // [esp+34h] [ebp-10h]
  int v25; // [esp+38h] [ebp-Ch]
  void **v26; // [esp+3Ch] [ebp-8h]
  char v27; // [esp+43h] [ebp-1h]

  v3 = a2;
  v27 = 0;
  v4 = OpenProcess(0x800u, 0, *(a2 + 68));
  v21 = v4;
  if ( !v4 )
    return GetLastError();
  if ( NtSuspendProcess )
  {
    if ( a1 )
      v6 = NtSuspendProcess(v4);
    else
      v6 = NtResumeProcess(v4);
    CloseHandle(v4);
    return v6;
  }
  if ( GetVersion() <= 4u )
  {
    v27 = 1;
    v7 = a2 + 136;
  }
  else
  {
    v7 = a2 + 184;
  }
  v8 = *(a2 + 4);
  v9 = 0;
  v25 = 0;
  if ( v8 )
  {
    v10 = (v7 + 56);
    v11 = v8;
    v12 = (v7 + 52);
    do
    {
      if ( *v12 == 5 && *v10 == 5 )
        ++v9;
      v12 += 16;
      v10 += 16;
      --v11;
    }
    while ( v11 );
    v25 = v9;
  }
  if ( a1 )
  {
    if ( v8 == v9 )
      goto LABEL_43;
  }
  else if ( v8 != v9 )
  {
    goto LABEL_43;
  }
  if ( v27 )
    v13 = a2 + 136;
  else
    v13 = a2 + 184;
  v23 = 0;
  if ( v8 )
  {
    v14 = (v13 + 56);
    v15 = (v13 + 52);
    v16 = (v13 + 36);
    v26 = v16;
    while ( 1 )
    {
      ClientId.UniqueThread = *v16;
      ClientId.UniqueProcess = 0;
      ObjectAttributes.Length = 24;
      ObjectAttributes.RootDirectory = 0;
      ObjectAttributes.Attributes = 0;
      ObjectAttributes.ObjectName = 0;
      ObjectAttributes.SecurityDescriptor = 0;
      ObjectAttributes.SecurityQualityOfService = 0;
      if ( !NtOpenThread(&hObject, 2u, &ObjectAttributes, &ClientId) )
        break;
LABEL_40:
      v16 += 16;
      v15 += 16;
      v26 = v16;
      v14 += 16;
      if ( ++v23 >= *(a2 + 4) )
      {
        v9 = v25;
        v3 = a2;
        goto LABEL_43;
      }
    }
    v18 = hObject;
    if ( !hObject )
    {
LABEL_39:
      v16 = v26;
      goto LABEL_40;
    }
    if ( a1 )
    {
      if ( a3 && (a3 != 1 || *v15 == 5 && *v14 == 5) )
        goto LABEL_38;
      NtSuspendThread(v17, hObject);
      if ( *v14 == 5 || !v24 )
        goto LABEL_38;
      ++v25;
    }
    NtResumeThread(v17, v18);
LABEL_38:
    CloseHandle(v18);
    goto LABEL_39;
  }
  v3 = a2;
LABEL_43:
  CloseHandle(v21);
  if ( a1 && *(v3 + 4) == v9 )
    result = 1904;
  else
    result = 0;
  return result;
}

//----- (00FF08B0) --------------------------------------------------------
DWORD64 __stdcall SymLoadModuleExW_0(HANDLE hProcess, HANDLE hFile, PCWSTR ImageName, PCWSTR ModuleName, DWORD64 BaseOfDll, DWORD DllSize, PMODLOAD_DATA Data, DWORD Flags)
{
  return SymLoadModuleExW(hProcess, hFile, ImageName, ModuleName, BaseOfDll, DllSize, 0, 0);
}

//----- (00FF08E0) --------------------------------------------------------
int __stdcall sub_FF08E0(int hProcess, int hFile, LPCWSTR a3, LPCWSTR lpWideCharStr, int BaseOfDll, int BaseOfDll_4, int SizeOfDll)
{
  int *v7; // esi
  int *v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // edx
  int v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]

  v7 = sub_FD9E00(&v13, lpWideCharStr);
  v15 = 0;
  v8 = sub_FD9E00(&v14, a3);
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

//----- (00FF09B0) --------------------------------------------------------
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
                v18 = sub_FC3F20(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, v17 - 1);
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
                v21 = sub_FC3F20(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, SHIDWORD(v101));
                if ( sub_FC36B0(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, v20, v21) )
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
          v23 = sub_FC3290(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1665, v23);
          swprintf(szText, L"%d", NumberOfThreads);
          v24 = sub_FC3290(szText, 0x104u);
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
          v46 = sub_FC3290(szText, MAX_PATH);
          SetDlgItemTextW(hWnd_1, 1096, v46);
          swprintf(szText, L"%d", NumberOfThreads);
          v47 = sub_FC3290(szText, MAX_PATH);
          SetDlgItemTextW(hWnd_1, 1097, v47);
          swprintf(szText, L"%d", nCount);
          v48 = sub_FC3290(szText, MAX_PATH);
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
          sub_FC3290(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1082, szText);
          if ( HIDWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) )
            v72 = &v71[-HIDWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages)];
          else
            v72 = 0;
          swprintf(szText, L"%u", v72);
          sub_FC3290(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1084, szText);
          if ( LODWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) )
            v73 = v104 - LODWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold);
          else
            v73 = 0;
          swprintf(szText, L"%u", v73);
          sub_FC3290(szText, 0x104u);
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
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FF18B0) --------------------------------------------------------
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
        sub_FF0510(v9, v24, v23, v22);
        v25 = GetDlgItem(hDlg, 1162);
        v26 = GetDlgItem(hDlg, 1160);
        v27 = GetDlgItem(hDlg, 1651);
        sub_FF0510(v9, v27, v26, v25);
        v28 = GetDlgItem(hDlg, 2602);
        v29 = GetDlgItem(hDlg, 2601);
        v30 = GetDlgItem(hDlg, 2501);
        sub_FF0510(v9, v30, v29, v28);
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
        v45 = sub_FC3290(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1104, v45);
        wsprintf(&Dst, L"%u", gpGraphInfoOfSystemMemory->m_dbMemorySize);
        v46 = sub_FC3290(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1105, v46);
        GraphData_QueryData(gpGraphInfoOfDedicatedMemory, v56, 0);
        wsprintf(&Dst, L"%d", *v56);
        v47 = sub_FC3290(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1660, v47);
        wsprintf(&Dst, L"%d", gpGraphInfoOfDedicatedMemory->m_dbMemorySize);
        v48 = sub_FC3290(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1661, v48);
        return 0;
      default:
        return 0;
    }
    return 0;
  }
  return PE_FillControl(hDlg, wParam);
}
// 103CB38: using guessed type double db_four;
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FF2010) --------------------------------------------------------
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
      sub_FF0400(hDlg, 1176, v31 - dword_10853A8, 0);
      sub_FF0460(hDlg, 1190, v28 - qword_1085390, (v28 - qword_1085390) >> 32);
      sub_FF0400(hDlg, 1177, v32 - dword_10853AC, 0);
      sub_FF0460(hDlg, 1192, v29 - qword_1085398, (v29 - qword_1085398) >> 32);
      sub_FF0400(hDlg, 1178, v33 - dword_10853B0, 0);
      sub_FF0460(hDlg, 1194, v30 - qword_10853A0, (v30 - qword_10853A0) >> 32);
      qmemcpy(&unk_1085388, &SystemInformation, 0x138u);
      sub_FF0400(hDlg, 1180, gTreeList_Item[1].field_10, 0);
      sub_FF0460(hDlg, 1196, gTreeList_Item[1].field_38, gTreeList_Item[1].field_3C);
      sub_FF0400(hDlg, 1181, gTreeList_Item[1].field_C, 0);
      sub_FF0460(hDlg, 1198, gTreeList_Item[1].field_30, gTreeList_Item[1].field_34);
      sub_FF0400(hDlg, 1182, gTreeList_Item[1].field_14, 0);
      sub_FF0460(hDlg, 1200, gTreeList_Item[1].field_40, gTreeList_Item[1].field_44);
      sub_FF0400(hDlg, 1186, gTreeList_Item[2].field_10, 0);
      sub_FF0460(hDlg, 1202, gTreeList_Item[2].field_38, gTreeList_Item[2].field_3C);
      sub_FF0400(hDlg, 1187, gTreeList_Item[2].field_C, 0);
      sub_FF0460(hDlg, 1204, gTreeList_Item[2].field_30, gTreeList_Item[2].field_34);
      sub_FF0400(hDlg, 1188, gTreeList_Item[2].field_14, 0);
      sub_FF0460(hDlg, 1206, gTreeList_Item[2].field_40, gTreeList_Item[2].field_44);
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
    sub_FF0550(v26, 3, &v34);
    v16 = GetDlgItem(hDlg, 1336);
    v17 = GetDlgItem(hDlg, 1352);
    v34 = GetDlgItem(hDlg, 1331);
    v35 = v17;
    v36 = v16;
    sub_FF0550(v26, 3, &v34);
    v18 = GetDlgItem(hDlg, 1337);
    v19 = GetDlgItem(hDlg, 1351);
    v34 = GetDlgItem(hDlg, 1332);
    v35 = v19;
    v20 = v26;
    v36 = v18;
    sub_FF0550(v26, 3, &v34);
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
  NtQuerySystemInformation(SystemPerformanceInformation, &unk_1085388, 0x138u, &ReturnLength);
  SendMessageW(hDlg, 0x113u, 0, 0);
  return 1;
}
// 103CB38: using guessed type double db_four;
// 1064E28: using guessed type int gdwVirtualScreenWidth;
// 1085390: using guessed type __int64 qword_1085390;
// 1085398: using guessed type __int64 qword_1085398;
// 10853A0: using guessed type __int64 qword_10853A0;
// 10853A8: using guessed type int dword_10853A8;
// 10853AC: using guessed type int dword_10853AC;
// 10853B0: using guessed type int dword_10853B0;

//----- (00FF25E0) --------------------------------------------------------
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
        sub_FF0550(hDlg, 2, &v53);
        v18 = GetDlgItem(hWnd, 1334);
        v53 = GetDlgItem(hWnd, 1160);
        v54 = v18;
        sub_FF0550(hDlg, 2, &v53);
        v19 = GetDlgItem(hWnd, 1637);
        v53 = GetDlgItem(hWnd, 1161);
        v54 = v19;
        v20 = hDlg;
        sub_FF0550(hDlg, 2, &v53);
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
  sub_FDCE20(&qword_1085378, &qword_1085380);
  NtQuerySystemInformation(SystemPerformanceInformation, &SystemInformation, 0x138u, &ReturnLength);
  v82 = 0;
  _mm_storeu_si128(v80, 0i64);
  _mm_storeu_si128(&v81, 0i64);
  NtQuerySystemInformation(SystemFileCacheInformation, v80, 0x24u, &ReturnLength);
  memset(&v74, 0, 0x58u);
  NtQuerySystemInformation(SystemMemoryListInformation, &v74, 0x58u, &ReturnLength);
  swprintf(&String, L"%d", v61 * (gSystemInfo.dwPageSize >> 10));
  v24 = sub_FC3290(&String, 0x104u);
  v25 = SetDlgItemTextW;
  SetDlgItemTextW(hWnd, 1103, v24);
  ArgList = v60 * 100.0 / v61;
  if ( gConfig.bShowCpuFractions )
    swprintf(&String, L"%02.2f%%", ArgList);
  else
    swprintf(&String, L"%0.0f%%", ArgList);
  SetDlgItemTextW(hWnd, 1110, &String);
  swprintf(&String, L"%u", v60 * (gSystemInfo.dwPageSize >> 10));
  v26 = sub_FC3290(&String, 0x104u);
  SetDlgItemTextW(hWnd, 1102, v26);
  swprintf(&String, L"%u", v62 * (gSystemInfo.dwPageSize >> 10));
  v27 = sub_FC3290(&String, 0x104u);
  SetDlgItemTextW(hWnd, 1104, v27);
  ArgLista = v62 * 100.0 / v61;
  if ( gConfig.bShowCpuFractions )
    swprintf(&String, L"%02.2f%%", ArgLista);
  else
    swprintf(&String, L"%0.0f%%", ArgLista);
  SetDlgItemTextW(hWnd, 1111, &String);
  swprintf(&String, L"%u", v59 * (gSystemInfo.dwPageSize >> 10));
  v28 = sub_FC3290(&String, 0x104u);
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
  v30 = sub_FC3290(&String, 0x104u);
  SetDlgItemTextW(hWnd, 1099, v30);
  if ( gdwVersion < 1 )
  {
    swprintf(&String, L"%d", v54);
    v43 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1101, v43);
  }
  else
  {
    swprintf(&String, L"%u", v72 * (gSystemInfo.dwPageSize >> 10));
    v31 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1116, v31);
    swprintf(&String, L"%u", v69 * (gSystemInfo.dwPageSize >> 10));
    v32 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1114, v32);
    swprintf(&String, L"%u", v70 * (gSystemInfo.dwPageSize >> 10));
    v33 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1101, v33);
    swprintf(&String, L"%u", v74 * (gSystemInfo.dwPageSize >> 10));
    v34 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1112, v34);
    swprintf(&String, L"%u", v75 * (gSystemInfo.dwPageSize >> 10));
    v35 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1113, v35);
    swprintf(&String, L"%u", v76 * (gSystemInfo.dwPageSize >> 10));
    v36 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1118, v36);
    swprintf(&String, L"%u", v77 * (gSystemInfo.dwPageSize >> 10));
    v37 = sub_FC3290(&String, 0x104u);
    SetDlgItemTextW(hWnd, 1119, v37);
    v54 = 0;
    v38 = 0;
    do
    {
      swprintf(&String, L"%u", v78[v38] * (gSystemInfo.dwPageSize >> 10));
      v39 = sub_FC3290(&String, 0x104u);
      SetDlgItemTextW(hWnd, v38 + 1120, v39);
      v40 = v54 + v78[v38++];
      v54 = v40;
    }
    while ( v38 < 8 );
    swprintf(&String, L"%u", v40 * (gSystemInfo.dwPageSize >> 10));
    v41 = sub_FC3290(&String, 0x104u);
    v25 = SetDlgItemTextW;
    SetDlgItemTextW(hWnd, 1117, v41);
    if ( gdwVersion >= 3 )
    {
      swprintf(&String, L"%u", v79 * (gSystemInfo.dwPageSize >> 10));
      v42 = sub_FC3290(&String, 0x104u);
      SetDlgItemTextW(hWnd, 1663, v42);
    }
  }
  if ( qword_1085378 )
  {
    swprintf(&String, L"%I64u", qword_1085378 >> 10);
    sub_FC3290(&String, 0x104u);
    v25(hWnd, 1108, &String);
  }
  swprintf(&String, L"%u", v68 * (gSystemInfo.dwPageSize >> 10));
  sub_FC3290(&String, 0x104u);
  v25(hWnd, 1107, &String);
  swprintf(&String, L"%u", v71 * (gSystemInfo.dwPageSize >> 10));
  v44 = sub_FC3290(&String, 0x104u);
  v25(hWnd, 1105, v44);
  swprintf(&String, L"%u", v67 * (gSystemInfo.dwPageSize >> 10));
  v45 = sub_FC3290(&String, 0x104u);
  v25(hWnd, 1106, v45);
  if ( qword_1085380 )
  {
    swprintf(&String, L"%I64u", qword_1085380 >> 10);
    sub_FC3290(&String, 0x104u);
    v25(hWnd, 1664, &String);
  }
  swprintf(&String, L"%u", v63 - dword_108527C);
  sub_FC3290(&String, 0x104u);
  v25(hWnd, 1171, &String);
  swprintf(&String, L"%u", v64 - dword_1085294);
  sub_FC3290(&String, 0x104u);
  v25(hWnd, 1172, &String);
  swprintf(&String, L"%u", v65 - dword_10852A0);
  sub_FC3290(&String, 0x104u);
  v25(hWnd, 1173, &String);
  swprintf(&String, L"%u", v66 - dword_10852A8);
  sub_FC3290(&String, 0x104u);
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
// 103CB38: using guessed type double db_four;
// 103CDC0: using guessed type double db_onehundred;
// 10467B8: using guessed type wchar_t a022f_0[9];
// 1064E28: using guessed type int gdwVirtualScreenWidth;
// 1064E54: using guessed type int gdwVersion;
// 106F2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);
// 108527C: using guessed type int dword_108527C;
// 1085294: using guessed type int dword_1085294;
// 10852A0: using guessed type int dword_10852A0;
// 10852A8: using guessed type int dword_10852A8;
// 1085378: using guessed type __int64 qword_1085378;
// 1085380: using guessed type __int64 qword_1085380;
// FF25E0: using guessed type int var_280[16];

//----- (00FF3260) --------------------------------------------------------
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
    sub_FF0550(v65, 6, &v66);
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
    sub_FF0550(v65, 6, &v66);
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
    sub_FF0550(v65, 6, &v66);
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
    sub_FF0550(v65, 4, &v68);
    v55 = GetDlgItem(hDlg, 1331);
    v56 = GetDlgItem(hDlg, 1334);
    v57 = GetDlgItem(hDlg, 1160);
    v68 = GetDlgItem(hDlg, 1157);
    v69 = v57;
    v70 = v56;
    v71 = v55;
    sub_FF0550(v65, 4, &v68);
    v58 = GetDlgItem(hDlg, 1332);
    v59 = GetDlgItem(hDlg, 1637);
    v60 = GetDlgItem(hDlg, 1161);
    v68 = GetDlgItem(hDlg, 1158);
    v70 = v59;
    v47 = v65;
    v69 = v60;
    v71 = v58;
    sub_FF0550(v65, 4, &v68);
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
// 103CB38: using guessed type double db_four;
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FF39C0) --------------------------------------------------------
_DWORD *__cdecl sub_FF39C0(SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo, int a2)
{
  int *v2; // esi
  int *v3; // ebx
  int *v4; // edi
  _DWORD *v5; // eax
  unsigned int v6; // edi
  int v8; // [esp+4h] [ebp-14h]
  int v9; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  _DWORD *v12; // [esp+14h] [ebp-4h]

  v12 = 0;
  v11 = 0;
  if ( sub_FDD9D0(pSystemHandleInfo) )
  {
    v2 = &pSystemHandleInfo->Handles[0].GrantedAccess;
    v3 = &pSystemHandleInfo->Handles[0].ObjectTypeIndex;
    do
    {
      if ( gbSupportExtendedSystemHandleInformation )
      {
        v4 = v3;
      }
      else
      {
        v4 = &dword_107BC0C;
        word_107BC1C = *(v2 - 5);
        dword_107BC18 = *v2;
        byte_107BC20 = *(v2 - 7);
        dword_107BC14 = *(v2 - 3);
        dword_107BC0C = *(v2 - 1);
        word_107BC1E = *(v2 - 8);
        dword_107BC10 = *(v2 - 6);
      }
      if ( v4[1] == a2 && !_wcsicmp(&gpszObjectTypeNames[64 * *(v4 + 9)], L"File") && sub_FDC4F0(v4, &v8, &v10, &v9) )
      {
        v5 = malloc(2192u);
        v5[11] = v10;
        v5[146] = v9;
        v5[10] = v8;
        v5[547] = v12;
        v12 = v5;
      }
      v3 += 7;
      v2 += 4;
      v6 = ++v11;
    }
    while ( v6 < sub_FDD9D0(pSystemHandleInfo) );
  }
  sub_FDC4F0(0, 0, 0, 0);
  return v12;
}
// 106ABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// 107BC0C: using guessed type int dword_107BC0C;
// 107BC10: using guessed type int dword_107BC10;
// 107BC14: using guessed type int dword_107BC14;
// 107BC18: using guessed type int dword_107BC18;
// 107BC1C: using guessed type __int16 word_107BC1C;
// 107BC1E: using guessed type __int16 word_107BC1E;
// 107BC20: using guessed type char byte_107BC20;

//----- (00FF3AF0) --------------------------------------------------------
BOOL __stdcall DlgThreadStack(HWND hWnd, UINT a2, WPARAM a3, LPARAM a4)
{
  HWND v4; // edi
  HICON v5; // eax
  CResizer *v6; // eax
  HWND v7; // ebx
  int v8; // ST14_4
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
  LPARAM lParam; // [esp+10h] [ebp-268h]
  int v26; // [esp+18h] [ebp-260h]
  int v27; // [esp+1Ch] [ebp-25Ch]
  int v28; // [esp+20h] [ebp-258h]
  wchar_t *v29; // [esp+24h] [ebp-254h]
  int v30; // [esp+28h] [ebp-250h]
  struct tagPOINT Point; // [esp+44h] [ebp-234h]
  UINT pnIDs; // [esp+4Ch] [ebp-22Ch]
  int v33; // [esp+50h] [ebp-228h]
  int v34; // [esp+54h] [ebp-224h]
  WORD pnWidths[2]; // [esp+58h] [ebp-220h]
  HWND v36; // [esp+5Ch] [ebp-21Ch]
  WPARAM wParam; // [esp+60h] [ebp-218h]
  HGLOBAL hMem; // [esp+64h] [ebp-214h]
  wchar_t Src; // [esp+68h] [ebp-210h]
  int v40; // [esp+274h] [ebp-4h]

  v4 = hWnd;
  hMem = hWnd;
  wParam = a4;
  pnIDs = 43;
  v33 = 44;
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
            v28 = 2;
            v27 = 2;
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
      v36 = v17;
      v18 = SendMessageW(v17, 0x100Cu, 0xFFFFFFFF, 2);
      v19 = hMem;
      wParam = v18;
      if ( v18 != -1 )
      {
        v20 = 0;
        do
        {
          v26 = 1;
          v29 = &Src;
          v30 = 256;
          SendMessageW(v36, 0x1073u, v18, &lParam);
          v21 = wcslen(&Src) + v16 + 2;
          v34 = v21;
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
          v18 = SendMessageW(v36, 0x100Cu, wParam, 2);
          v16 = v34;
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
      SetFocus(v36);
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
  v40 = 0;
  if ( v6 )
    CResizer::CResizer(v6, hWnd);
  v40 = -1;
  v7 = GetDlgItem(hWnd, 1087);
  sub_FB9BB0(v7, 2, &pnIDs, pnWidths, 0);
  v8 = wParam;
  v9 = GetDlgItem(hWnd, 1087);
  sub_FDB490(v9, v8);
  SendMessageW(v7, 0x101Eu, 0, 0xFFFF);
  SendMessageW(v7, 0x101Eu, 1u, 0xFFFF);
  v28 = 3;
  v27 = 3;
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

//----- (00FF3FC0) --------------------------------------------------------
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
  LRESULT v51; // eax
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
  char *v69; // esi
  unsigned int *v70; // ST20_4
  int v71; // eax
  int v72; // eax
  char v73; // ST20_1
  int v74; // eax
  HWND v75; // esi
  LRESULT v76; // eax
  HWND v77; // esi
  HWND v78; // eax
  HWND v79; // esi
  HWND v80; // edi
  HWND v81; // eax
  int v82; // [esp+0h] [ebp-EC0h]
  char v83; // [esp+10h] [ebp-EB0h]
  char v84; // [esp+44h] [ebp-E7Ch]
  DWORD BytesReturned; // [esp+2A0h] [ebp-C20h]
  LPARAM lParam; // [esp+2A4h] [ebp-C1Ch]
  int v87; // [esp+2ACh] [ebp-C14h]
  int v88; // [esp+2B0h] [ebp-C10h]
  int v89; // [esp+2B4h] [ebp-C0Ch]
  WCHAR *v90; // [esp+2B8h] [ebp-C08h]
  int v91; // [esp+2BCh] [ebp-C04h]
  UINT pnIDs; // [esp+2D8h] [ebp-BE8h]
  int v93; // [esp+2DCh] [ebp-BE4h]
  int v94; // [esp+2E0h] [ebp-BE0h]
  unsigned int v95; // [esp+2E4h] [ebp-BDCh]
  int v96; // [esp+2E8h] [ebp-BD8h]
  int v97; // [esp+2ECh] [ebp-BD4h]
  WORD pnWidths[2]; // [esp+2F0h] [ebp-BD0h]
  LPARAM v99; // [esp+2F4h] [ebp-BCCh]
  WPARAM wParam; // [esp+2F8h] [ebp-BC8h]
  int v101; // [esp+2FCh] [ebp-BC4h]
  int v102; // [esp+300h] [ebp-BC0h]
  int v103; // [esp+304h] [ebp-BBCh]
  WCHAR *v104; // [esp+308h] [ebp-BB8h]
  int v105; // [esp+310h] [ebp-BB0h]
  char *v106; // [esp+314h] [ebp-BACh]
  int v107; // [esp+328h] [ebp-B98h]
  PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine; // [esp+32Ch] [ebp-B94h]
  char *v109; // [esp+330h] [ebp-B90h]
  char ArgList[4]; // [esp+334h] [ebp-B8Ch]
  void *v111; // [esp+338h] [ebp-B88h]
  char *v112; // [esp+33Ch] [ebp-B84h]
  int ThreadHandle; // [esp+340h] [ebp-B80h]
  LONG v114; // [esp+344h] [ebp-B7Ch]
  HWND v115; // [esp+348h] [ebp-B78h]
  char *v116; // [esp+34Ch] [ebp-B74h]
  LPCONTEXT lpContext; // [esp+350h] [ebp-B70h]
  HWND v118; // [esp+354h] [ebp-B6Ch]
  HWND v119; // [esp+358h] [ebp-B68h]
  HWND hDlg; // [esp+35Ch] [ebp-B64h]
  struct _tagSTACKFRAME64 StackFrame; // [esp+360h] [ebp-B60h]
  char v122; // [esp+468h] [ebp-A58h]
  char v123; // [esp+49Ch] [ebp-A24h]
  struct tagRECT Rect; // [esp+6F8h] [ebp-7C8h]
  DWORD OutBuffer; // [esp+708h] [ebp-7B8h]
  DWORD v126; // [esp+70Ch] [ebp-7B4h]
  DWORD v127; // [esp+710h] [ebp-7B0h]
  char v128; // [esp+723h] [ebp-79Dh]
  WCHAR String; // [esp+CACh] [ebp-214h]
  int *v130; // [esp+EB0h] [ebp-10h]
  int v131; // [esp+EBCh] [ebp-4h]

  v130 = &v82;
  hDlg = hWnd;
  v4 = GetWindowLongW(hWnd, -21);
  v109 = 0;
  v114 = v4;
  v116 = 0;
  lpContext = (&v128 & 0xFFFFFFF0);
  v99 = 0;
  memset(&wParam, 0, 0x30u);
  v118 = GetDlgItem(hWnd, 1087);
  pnIDs = 43;
  v93 = 44;
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
    EnterCriticalSection(&gProcThreadsLock);
    *ArgList = 0;
    v115 = 0;
    v131 = 1;
    v42 = operator new(0x28u);
    v111 = v42;
    LOBYTE(v131) = 2;
    if ( v42 )
      v43 = sub_FC75A0(v42);
    else
      v43 = 0;
    v119 = v43;
    LOBYTE(v131) = 1;
    v115 = v43;
    if ( sub_FC8940(v43, v4) == 1 && sub_FC8D10(v43, *(v4 + 4)) == 1 )
    {
      v94 = 0;
      v95 = 0;
      v96 = 0;
      v97 = 0;
      LOBYTE(v131) = 3;
      v112 = sub_FCB0A0(v43, *(v4 + 4), &v94);
      if ( v112 == 1 )
      {
        v45 = 0;
        v116 = 0;
        if ( v95 > 0 )
        {
          v46 = v95 > 0;
          while ( 1 )
          {
            if ( !v46 )
              ATL::AtlThrowImpl(-2147024809);
            v47 = *(v94 + 4 * v45);
            v111 = v47;
            if ( v47 )
              (*(*v47 + 4))(v47);
            LOBYTE(v131) = 4;
            v48 = wcscmp(sub_FC7F60(v47), L"0x0");
            if ( v48 )
              v48 = -(v48 < 0) | 1;
            if ( v48 )
            {
              v49 = ArgList[0];
              v99 = 5;
              wParam = 0x7FFFFFFF;
              v101 = 0;
              v103 = 0;
              v102 = 0;
              ++*ArgList;
              wsprintf(&String, L"%d", v49);
              v50 = v118;
              v104 = &String;
              v105 = 0;
              v106 = v116 + 1;
              v51 = SendMessageW(v118, 0x104Du, 0, &v99);
              if ( v51 == -1 )
              {
                LOBYTE(v131) = 3;
                if ( v47 )
                  (*(*v47 + 8))(v47);
                sub_FD9F20(&v94);
LABEL_77:
                v131 = -1;
                if ( v43 )
                  (*(*v43 + 8))(v43);
                return 0;
              }
              v99 = 1;
              wParam = v51;
              v101 = 1;
              v104 = sub_FC7F60(v47);
              SendMessageW(v50, 0x104Cu, 0, &v99);
            }
            LOBYTE(v131) = 3;
            if ( v47 )
              (*(*v47 + 8))(v47);
            v45 = (v116 + 1);
            v116 = v45;
            v46 = v45 < v95;
            if ( v45 >= v95 )
            {
              v4 = v114;
              v41 = lpContext;
              break;
            }
          }
        }
      }
      LOBYTE(v131) = 1;
      sub_FD9F20(&v94);
      if ( v112 )
      {
LABEL_104:
        NtResumeThread(v44, *(v4 + 8));
        LeaveCriticalSection(&gProcThreadsLock);
        if ( !&v116[v109] )
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
        v79 = v118;
        SendMessageW(v118, 0x101Eu, 0, 0xFFFF);
        SendMessageW(v79, 0x101Eu, 1u, 0xFFFF);
        v89 = 3;
        v88 = 3;
        SendMessageW(v79, 0x102Bu, 0, &lParam);
        SetFocus(v79);
        v80 = hDlg;
        if ( gConfig.WindowPlacement[5].rcNormalPosition.right == gConfig.WindowPlacement[5].rcNormalPosition.left )
          GetWindowRect(hDlg, &Rect);
        else
          _mm_storeu_si128(&Rect, _mm_loadu_si128(&gConfig.WindowPlacement[5].rcNormalPosition));
        v81 = GetDlgItem(v80, 1210);
        EnableWindow(v81, 1);
        ghWndThreadStack = v80;
        SetFocus(v118);
        ShowWindow(v80, 1);
        v131 = -1;
        if ( v43 )
          (*(*v43 + 8))(v43);
        return 1;
      }
    }
    for ( i = 0; ; i = v107 + 1 )
    {
LABEL_67:
      v107 = i;
      if ( i >= 2 )
        goto LABEL_104;
      v109 = v116;
      v111 = v116;
      memset(v41, 0, 0x2CCu);
      v53 = v107;
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
        v54 = v114;
        v55 = 0;
        v56 = (v114 + 8);
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
        v4 = v114;
        ReadMemoryRoutine = sub_FF0640;
        lpContext->Eip = OutBuffer;
        v59->Esp = v126;
        v59->Ebp = v127;
        v60 = *v56;
        v41 = v59;
        dword_106AB88 = v60;
      }
      v43 = v119;
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
        v112 = v69;
        v116 = v69;
        if ( v69 >= 100 )
          break;
        v70 = *(v4 + 16);
        LOBYTE(v131) = 5;
        sub_FDDD60(1, v44, &v122, *(v4 + 12), 0, 0, *(v4 + 20), v70);
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
          i = v107 + 1;
          LOBYTE(v131) = 1;
          goto LABEL_67;
        }
        v44 = StackFrame.AddrPC.Offset;
        v131 = 1;
        if ( !StackFrame.AddrPC.Offset )
          break;
        sub_FDDD60(1, StackFrame.AddrPC.Offset, &v122, *(v4 + 12), 0, 0, *(v4 + 20), *(v4 + 16));
        v71 = wcscmp(&v123, L"0x0");
        if ( v71 )
          v71 = -(v71 < 0) | 1;
        if ( v71 )
        {
          v72 = wcscmp(&v123, &v84);
          if ( v72 )
            v72 = -(v72 < 0) | 1;
          if ( v72 )
          {
            v73 = ArgList[0];
            v99 = 5;
            wParam = 0x7FFFFFFF;
            v101 = 0;
            v103 = 0;
            v102 = 0;
            ++*ArgList;
            wsprintf(&String, L"%d", v73);
            v104 = &String;
            v74 = (v69 + 1);
            v105 = 0;
            v75 = v118;
            v106 = v74;
            v76 = SendMessageW(v118, 0x104Du, 0, &v99);
            if ( v76 == -1 )
              goto LABEL_77;
            wParam = v76;
            v104 = &v123;
            v99 = 1;
            v101 = 1;
            SendMessageW(v75, 0x104Cu, 0, &v99);
            qmemcpy(&v83, &v122, 0x290u);
            v4 = v114;
            v69 = v116;
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
              v89 = 2;
              v88 = 2;
              SendMessageW(v30, 0x102Bu, v29++, &lParam);
            }
            while ( v29 < SendMessageW(v30, 0x1004u, 0, 0) );
          }
        }
        return 0;
      }
      v31 = 0;
      wParam = -1;
      v32 = 0;
      v33 = GetDlgItem(hDlg, 1087);
      v119 = v33;
      v34 = SendMessageW(v33, 0x100Cu, wParam, 0);
      v26 = v119;
      for ( wParam = v34; v34 != -1; wParam = v34 )
      {
        v87 = 1;
        v90 = &String;
        v91 = 256;
        SendMessageW(v119, 0x1073u, v34, &lParam);
        v35 = wcslen(&String) + v31 + 2;
        v115 = v35;
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
        v34 = SendMessageW(v119, 0x100Cu, wParam, 0);
        v31 = v115;
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
            SendMessageW(v118, 0x1009u, 0, 0);
            SendMessageW(v19, 0x7FAu, 0, 0);
          }
        }
        return 0;
      }
      v22 = 0;
      wParam = -1;
      v23 = 0;
      v24 = GetDlgItem(hDlg, 1087);
      v119 = v24;
      v25 = SendMessageW(v24, 0x100Cu, wParam, 2);
      v26 = v119;
      for ( wParam = v25; v25 != -1; wParam = v25 )
      {
        v87 = 1;
        v90 = &String;
        v91 = 256;
        SendMessageW(v119, 0x1073u, v25, &lParam);
        v27 = wcslen(&String) + v22 + 2;
        v115 = v27;
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
        v25 = SendMessageW(v119, 0x100Cu, wParam, 2);
        v22 = v115;
      }
    }
    if ( OpenClipboard(hDlg) )
    {
      EmptyClipboard();
      SetClipboardData(0xDu, v26);
      CloseClipboard();
    }
    SetFocus(v119);
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
  v111 = v7;
  v131 = 0;
  if ( v7 )
    CResizer::CResizer(v7, v6);
  v8 = v118;
  v9 = GetWindowLongW(v118, -16);
  SetWindowLongW(v8, -16, v9 & 0xFFFFFFFD | 1);
  SetWindowLongW(v118, -21, 2);
  SendMessageW(v118, 0x1036u, 0x4020u, 16416);
  v10 = SendMessageW(v118, 0x104Eu, 0, 0);
  CTreeList::InitToolTips(v10);
  gOldListWndProc = SetWindowLongW(v118, -4, Proxy_ListCtrlWndProc);
  SendMessageW(v118, 0x30u, ghConfigFont, 0);
  CTreeView::InitListHeader(v118, &pnIDs, pnWidths, 2u);
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
// 1045208: using guessed type wchar_t a0x0[4];
// 106AB88: using guessed type int dword_106AB88;

//----- (00FF5020) --------------------------------------------------------
void __noreturn ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException()
{
  ATL::AtlThrowImpl(E_OUTOFMEMORY);
}
