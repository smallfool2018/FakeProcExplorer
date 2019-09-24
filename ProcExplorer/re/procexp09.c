


//----- (00C59A30) --------------------------------------------------------
int __userpurge PageProcTcpUdp@<eax>(signed int a1@<ebx>, HWND hWnd, int a3, WPARAM wParam, int a5)
{
  HWND v5; // esi
  int v6; // eax
  HWND v7; // eax
  HWND v8; // edi
  CResizer *v9; // eax
  HWND v10; // eax
  struct _MIB_UDPTABLE *v11; // eax
  __m128i *v12; // eax
  LONG v13; // ecx
  WPARAM v14; // esi
  UINT v15; // eax
  BOOL v16; // ST44_4
  HWND v17; // eax
  UINT v19; // eax
  HWND v20; // eax
  MIB_UDPROW *v21; // esi
  LRESULT v22; // eax
  char v23; // al
  char v24; // cl
  HANDLE v25; // eax
  HANDLE v26; // eax
  int v27; // eax
  PVOID v28; // ecx
  HANDLE v29; // eax
  HANDLE v30; // eax
  int v31; // eax
  int v32; // ecx
  bool v33; // zf
  SYSTEM_HANDLE_INFORMATION *v34; // ecx
  int v35; // eax
  tagTREEVIEWLISTITEMPARAM *v36; // eax
  _DWORD *v37; // edi
  u_long v38; // ecx
  int v39; // eax
  SYSTEM_HANDLE_INFORMATION *v40; // ecx
  tagTREEVIEWLISTITEMPARAM *v41; // eax
  struct _MIB_UDPTABLE *v42; // edx
  size_t v43; // edi
  void *v44; // esi
  int v45; // ST30_4
  tagTREEVIEWLISTITEMPARAM *v46; // eax
  void *v47; // ST44_4
  HANDLE v48; // eax
  void *v49; // ST44_4
  HANDLE v50; // eax
  PVOID v51; // ST44_4
  HANDLE v52; // eax
  PVOID v53; // ST44_4
  HANDLE v54; // eax
  void *v55; // esi
  void *v56; // eax
  SYSTEM_HANDLE_INFORMATION *v57; // ecx
  int *v58; // edi
  u_long v59; // edx
  int v60; // ecx
  tagTREEVIEWLISTITEMPARAM *v61; // eax
  _DWORD *v62; // edi
  void *v63; // eax
  SYSTEM_HANDLE_INFORMATION *v64; // edx
  struct _MIB_UDPTABLE *v65; // ecx
  tagTREEVIEWLISTITEMPARAM *v66; // eax
  int *v67; // edi
  SYSTEM_HANDLE_INFORMATION *v68; // ecx
  int *v69; // edi
  int v70; // ecx
  tagTREEVIEWLISTITEMPARAM *v71; // eax
  MIB_UDPTABLE_OWNER_MODULE *pExtendedTable; // edi
  SYSTEM_HANDLE_INFORMATION *v73; // ecx
  tagTREEVIEWLISTITEMPARAM *v74; // eax
  _SYSTEM_INFORMATION_CLASS pSystemInfoClass; // ecx
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo1; // edi
  ULONG dwReturnLength; // esi
  _SYSTEM_INFORMATION_CLASS SystemInfoClass; // eax
  struct _MIB_TCPTABLE *v79; // eax
  struct _MIB_TCPTABLE *v80; // esi
  int v81; // eax
  struct _MIB_UDPTABLE *pUdpTable; // eax
  struct _MIB_UDPTABLE *v83; // edi
  int v84; // eax
  int v85; // eax
  int v86; // ecx
  MIB_UDPROW *v87; // ecx
  void *v88; // ST40_4
  LPARAM v89; // ecx
  int v90; // eax
  WPARAM v91; // esi
  int v92; // ST44_4
  int v93; // eax
  WPARAM v94; // [esp-8h] [ebp-B4h]
  LVITEMW Item; // [esp+Ch] [ebp-A0h]
  WPARAM v96; // [esp+40h] [ebp-6Ch]
  WPARAM v97; // [esp+44h] [ebp-68h]
  void *v98; // [esp+48h] [ebp-64h]
  PVOID ppTcpTable; // [esp+4Ch] [ebp-60h]
  LPVOID lpMem; // [esp+50h] [ebp-5Ch]
  char v101[5]; // [esp+57h] [ebp-55h]
  PVOID pTcpTable; // [esp+5Ch] [ebp-50h]
  int v103; // [esp+60h] [ebp-4Ch]
  MIB_UDPROW *v104; // [esp+64h] [ebp-48h]
  struct _MIB_UDPTABLE *v105; // [esp+68h] [ebp-44h]
  HWND v106; // [esp+6Ch] [ebp-40h]
  LONG dwNewLong; // [esp+70h] [ebp-3Ch]
  LPARAM dwInitParam; // [esp+74h] [ebp-38h]
  size_t ReturnLength; // [esp+78h] [ebp-34h]
  size_t v110; // [esp+7Ch] [ebp-30h]
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo; // [esp+80h] [ebp-2Ch]
  char pnIDs[17]; // [esp+87h] [ebp-25h]
  int v113; // [esp+98h] [ebp-14h]
  int v114; // [esp+A8h] [ebp-4h]

  v5 = hWnd;
  pSystemHandleInfo = (SYSTEM_HANDLE_INFORMATION *)hWnd;
  dwNewLong = a5;
  dwInitParam = GetWindowLongW(hWnd, -21);
  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v6 = dword_CED0B0;
  pTcpTable = 0;
  *(_DWORD *)&v101[1] = 0;
  ppTcpTable = 0;
  lpMem = 0;
  v113 = 1343;
  _mm_storeu_si128((__m128i *)&pnIDs[1], _mm_load_si128((const __m128i *)word_CB6C50));
  if ( !(v6 & 1) )
  {
    dword_CED0B0 = v6 | 1;
    pnWidths = MulDiv(50, gLogPixelSize.x, 96);
    word_CED0A6 = MulDiv(100, gLogPixelSize.x, 96);
    word_CED0A8 = MulDiv(100, gLogPixelSize.x, 96);
    word_CED0AA = MulDiv(100, gLogPixelSize.x, 96);
    word_CED0AC = MulDiv(100, gLogPixelSize.x, 96);
  }
  v7 = GetDlgItem(hWnd, 1192);
  v8 = v7;
  v106 = v7;
  if ( a3 <= (unsigned int)WM_TIMER )
  {
    if ( a3 != WM_TIMER )
    {
      switch ( a3 )
      {
        case WM_ALTTABACTIVE|WM_DESTROY:
          CMainWnd::DrawItem((LPDRAWITEMSTRUCT)dwNewLong);
          return 0;
        case 0x2C:
          return CMainWnd::HandleMeasureItem(hWnd, a3, wParam, (LPMEASUREITEMSTRUCT)dwNewLong);
        case WM_NOTIFY:
          switch ( *(_DWORD *)(dwNewLong + 8) )
          {
            case LVN_GETDISPINFOW:
              return CMainWnd::HandleLVNGetDispInfoW(wParam, dwNewLong);
            case LVN_COLUMNCLICK:
              return CMainWnd::HandleLVNColumnClick(wParam, (LPNMLVKEYDOWN)dwNewLong);
            case LVN_ITEMCHANGED:
            case LVN_GETDISPINFO|0x94:
              v16 = SendMessageW(*(HWND *)(dwInitParam + 4), LVM_GETNEXTITEM, 0xFFFFFFFF, 2) != -1;
              v17 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
              EnableWindow(v17, v16);
              return 0;
            case LVN_SETDISPINFO|0x94:
              SendMessageW(hWnd, WM_COMMAND, IDC_PAGE_PROCTHREADS_BUTTON_STACK, 0);
              break;
            default:
              return 0;
          }
          return 0;
        case WM_INITDIALOG:
          v9 = (CResizer *)operator new(0x40u);
          v98 = v9;
          v114 = 0;
          if ( v9 )
            v110 = (size_t)CResizer::CResizer(v9, hWnd);
          else
            v110 = 0;
          v114 = -1;
          v10 = GetDlgItem(hWnd, 1209);
          if ( v10 )
            *(_OWORD *)CResizer::AddItem((CResizer *)v110, v10, 1)->gap0 = xmmword_CB6C70;
          PropSheet_UpdateTab(hWnd);
          SetWindowLongW(hWnd, GWLP_USERDATA, dwNewLong);
          if ( gdwVersion < 1 || (v11 = (struct _MIB_UDPTABLE *)5, !(*(_BYTE *)(dwNewLong + 40) & 0x20)) )
            v11 = (struct _MIB_UDPTABLE *)4;
          v105 = v11;
          ProcPageInitList(v8, (LONG)v11, (UINT *)&pnIDs[1], &pnWidths, 1);
          SetWindowLongW(v8, -4, (LONG)Proxy_ListCtrlWndProc);
          SendMessageW(v8, 0x30u, (WPARAM)ghConfigFont, 0);
          v12 = (__m128i *)malloc(0x1Cu);
          v13 = dwNewLong;
          _mm_storeu_si128(v12, (__m128i)0i64);
          _mm_storel_epi64(v12 + 1, (__m128i)0i64);
          v12[1].m128i_i32[2] = 0;
          v12->m128i_i32[3] = 0;
          v12->m128i_i32[0] = v13;
          v12->m128i_i32[1] = (__int32)v8;
          v12[1].m128i_i32[2] = -1;
          SetWindowLongW(hWnd, GWLP_USERDATA, (LONG)v12);
          SendMessageW(hWnd, WM_TIMER, 0, 1);
          if ( SendMessageW(v8, LVM_GETITEMCOUNT, 0, 0) )
          {
            v14 = 0;
            if ( v105 )
            {
              do
              {
                if ( v14 == 3 )
                  SendMessageW(v8, LVM_SETCOLUMNWIDTH, 3u, (unsigned __int16)word_CED0AA);
                else
                  SendMessageW(v8, LVM_SETCOLUMNWIDTH, v14, 0xFFFF);
                ++v14;
              }
              while ( v14 < (unsigned int)v105 );
            }
            v5 = (HWND)pSystemHandleInfo;
          }
          CheckDlgButton(v5, 1194, byte_CD10D8 != 0);
          v15 = IsDlgButtonChecked(v5, 1194);
          SetPropW(v8, L"resolve", (HANDLE)(v15 == 1));
          SetFocus(v8);
          ReleaseCapture();
          return 0;
        case WM_COMMAND:
          if ( (signed int)(unsigned __int16)wParam <= 40001 )
          {
            if ( (unsigned __int16)wParam != 40001 )
            {
              if ( (unsigned __int16)wParam == 1085 )
              {
                if ( AllocateAndGetTcpExTableFromStack )
                  DialogBoxParamW(ghMainInstance, L"THREADSTACK", hWnd, DlgThreadStack, dwInitParam);
                else
                  MessageBoxW(hWnd, L"Stacks not available on this version of Windows", L"Process Explorer", 0x30u);
              }
              else if ( (unsigned __int16)wParam == 1194 && !(wParam >> 16) )
              {
                v19 = IsDlgButtonChecked(hWnd, 1194);
                SetPropW(v8, L"resolve", (HANDLE)(v19 == 1));
                byte_CD10D8 = IsDlgButtonChecked((HWND)pSystemHandleInfo, 1194) == 1;
                goto LABEL_33;
              }
              return 0;
            }
            v94 = 40014;
LABEL_43:
            v20 = GetParent(hWnd);
            PostMessageW(v20, WM_COMMAND, v94, 0);
            return 0;
          }
          if ( (unsigned __int16)wParam != IDM_VIEW_REFRESH_NOW )
          {
            if ( (unsigned int)(unsigned __int16)wParam - 40092 > 1 )
              return 0;
            v94 = wParam;
            goto LABEL_43;
          }
          SetEvent(ghRefreshEventHandle);
          break;
        default:
          return 0;
      }
      return 0;
    }
    v21 = 0;
    pnIDs[0] = 0;
    v104 = 0;
    if ( !(_BYTE)dwNewLong )
    {
      Item.mask = 4;
      v22 = SendMessageW(v7, LVM_GETITEMCOUNT, 0, 0);
      Item.iSubItem = 0;
      Item.iItem = v22 - 1;
      if ( SendMessageW(v8, LVM_GETITEMW, 0, (LPARAM)&Item) )
      {
        do
        {
          LOBYTE(Item.lParam->nRefCount) = 0;
          v23 = sub_C658D0(a1, v8, &Item, (LPARAM)Item.lParam, (int)v101);
          v24 = pnIDs[0];
          if ( v23 )
            v24 = 1;
          pnIDs[0] = v24;
          if ( v101[0] )
          {
            v21 = (MIB_UDPROW *)((char *)v21 + 1);
            Item.lParam->dwRefreshCount = 0;
          }
          Item.mask = 4;
          Item.iSubItem = 0;
        }
        while ( SendMessageW(v8, LVM_GETITEMW, 0, (LPARAM)&Item) );
        v104 = v21;
      }
    }
    if ( !AllocateAndGetTcpExTableFromStack )
    {
      if ( *(_DWORD *)GetExtendedTcpTable )
      {
        ReturnLength = 0;
        if ( GetExtendedTcpTable(0, &ReturnLength, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL, 0) == ERROR_INSUFFICIENT_BUFFER )
        {
          v55 = 0;
          do
          {
            if ( v55 )
              free(v55);
            v55 = malloc(ReturnLength);
          }
          while ( GetExtendedTcpTable(v55, &ReturnLength, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL, 0) == ERROR_INSUFFICIENT_BUFFER );
          v110 = (size_t)v55;
          v33 = v55 == 0;
          v21 = v104;
          if ( !v33 )
          {
            v56 = (void *)v110;
            v57 = 0;
            pSystemHandleInfo = 0;
            if ( *(_DWORD *)v110 )
            {
              v58 = (int *)(v110 + 28);
              do
              {
                if ( *v58 == *(_DWORD *)(*(_DWORD *)dwInitParam + 68) )
                {
                  v59 = *(v58 - 2);
                  if ( v59 )
                    v60 = *(v58 - 1);
                  else
                    v60 = 0;
                  v61 = sub_C4A070(
                          v106,
                          dwNewLong,
                          0,
                          *(v58 - 5),
                          *(v58 - 4),
                          0,
                          *(v58 - 3),
                          v59,
                          0,
                          v60,
                          *v58,
                          (int)(v58 + 3),
                          0,
                          (int)pnIDs);
                  v57 = pSystemHandleInfo;
                  if ( v61 )
                    pnIDs[0] = 1;
                  else
                    v21 = (MIB_UDPROW *)((char *)v21 - 1);
                }
                v56 = (void *)v110;
                v57 = (SYSTEM_HANDLE_INFORMATION *)((char *)v57 + 1);
                v58 += 40;
                pSystemHandleInfo = v57;
              }
              while ( (unsigned int)v57 < *(_DWORD *)v110 );
            }
            free(v56);
          }
        }
        ReturnLength = 0;
        if ( GetExtendedUdpTable(0, &ReturnLength, 0, 2u, UDP_TABLE_OWNER_MODULE, 0) == ERROR_INSUFFICIENT_BUFFER )
        {
          v62 = 0;
          do
          {
            if ( v62 )
              free(v62);
            v62 = malloc(ReturnLength);
          }
          while ( GetExtendedUdpTable(v62, &ReturnLength, 0, 2u, UDP_TABLE_OWNER_MODULE, 0) == ERROR_INSUFFICIENT_BUFFER );
          v110 = (size_t)v62;
          if ( v62 )
          {
            v63 = v62;
            v64 = 0;
            pSystemHandleInfo = 0;
            if ( *v62 )
            {
              v65 = (struct _MIB_UDPTABLE *)(v62 + 4);
              v105 = (struct _MIB_UDPTABLE *)(v62 + 4);
              do
              {
                if ( v65->dwNumEntries == *(_DWORD *)(*(_DWORD *)dwInitParam + 68) )
                {
                  v66 = sub_C4A070(
                          v106,
                          dwNewLong,
                          1,
                          2,
                          v65[-1].table[0].dwLocalAddr,
                          0,
                          v65[-1].table[0].dwLocalPort,
                          0xFFFFFFFF,
                          0,
                          -1,
                          v65->dwNumEntries,
                          (int)&v65[2],
                          0,
                          (int)pnIDs);
                  if ( v66 )
                  {
                    if ( (_BYTE)dwNewLong )
                      v66->field_10 = 0;
                    pnIDs[0] = 1;
                  }
                  else
                  {
                    v21 = (MIB_UDPROW *)((char *)v21 - 1);
                  }
                  v64 = pSystemHandleInfo;
                  v65 = v105;
                }
                v63 = (void *)v110;
                v64 = (SYSTEM_HANDLE_INFORMATION *)((char *)v64 + 1);
                v65 = (struct _MIB_UDPTABLE *)((char *)v65 + 160);
                pSystemHandleInfo = v64;
                v105 = v65;
              }
              while ( (unsigned int)v64 < *(_DWORD *)v110 );
            }
            free(v63);
          }
        }
        v67 = 0;
        ReturnLength = 0;
        if ( GetExtendedTcpTable(0, &ReturnLength, 0, 0x17u, TCP_TABLE_OWNER_MODULE_ALL, 0) == ERROR_INSUFFICIENT_BUFFER )
        {
          do
          {
            if ( v67 )
              free(v67);
            v67 = (int *)malloc(ReturnLength);
          }
          while ( GetExtendedTcpTable(v67, &ReturnLength, 0, 0x17u, TCP_TABLE_OWNER_MODULE_ALL, 0) == ERROR_INSUFFICIENT_BUFFER );
          v110 = (size_t)v67;
          if ( v67 )
          {
            v68 = 0;
            pSystemHandleInfo = 0;
            if ( *v67 )
            {
              v69 = v67 + 15;
              do
              {
                if ( *v69 == *(_DWORD *)(*(_DWORD *)dwInitParam + 68) )
                {
                  if ( v69 == (int *)28 )
                    v70 = 0;
                  else
                    v70 = *(v69 - 2);
                  v71 = sub_C4A070(
                          v106,
                          dwNewLong,
                          2,
                          *(v69 - 1),
                          0,
                          (int)(v69 - 13),
                          *(v69 - 8),
                          0,
                          (int)(v69 - 7),
                          v70,
                          *v69,
                          (int)(v69 + 3),
                          0,
                          (int)pnIDs);
                  v68 = pSystemHandleInfo;
                  if ( v71 )
                    pnIDs[0] = 1;
                  else
                    v21 = (MIB_UDPROW *)((char *)v21 - 1);
                }
                v68 = (SYSTEM_HANDLE_INFORMATION *)((char *)v68 + 1);
                v69 += 48;
                pSystemHandleInfo = v68;
              }
              while ( (unsigned int)v68 < *(_DWORD *)v110 );
              v67 = (int *)v110;
            }
            free(v67);
          }
        }
        pExtendedTable = 0;
        ReturnLength = 0;
        if ( GetExtendedUdpTable(0, &ReturnLength, 0, 0x17u, UDP_TABLE_OWNER_MODULE, 0) == ERROR_INSUFFICIENT_BUFFER )
        {
          do
          {
            if ( pExtendedTable )
              free(pExtendedTable);
            pExtendedTable = (MIB_UDPTABLE_OWNER_MODULE *)malloc(ReturnLength);
          }
          while ( GetExtendedUdpTable(pExtendedTable, &ReturnLength, 0, 0x17u, UDP_TABLE_OWNER_MODULE, 0) == ERROR_INSUFFICIENT_BUFFER );
          if ( pExtendedTable )
          {
            v33 = pExtendedTable->dwNumEntries == 0;
            v110 = 0;
            if ( !v33 )
            {
              v73 = (SYSTEM_HANDLE_INFORMATION *)&pExtendedTable->table[0].0;
              pSystemHandleInfo = (SYSTEM_HANDLE_INFORMATION *)&pExtendedTable->table[0].0;
              do
              {
                if ( v73->NumberOfHandles == *(_DWORD *)(*(_DWORD *)dwInitParam + 0x44) )
                {
                  v74 = sub_C4A070(
                          v106,
                          dwNewLong,
                          3,
                          2,
                          0,
                          (int)&v73[-2].Handles[0].GrantedAccess,
                          v73[-1].Handles[0].GrantedAccess,
                          0xFFFFFFFF,
                          0,
                          -1,
                          v73->NumberOfHandles,
                          (int)v73[1].Handles,
                          0,
                          (int)pnIDs);
                  if ( v74 )
                  {
                    if ( (_BYTE)dwNewLong )
                      v74->field_10 = 0;
                    pnIDs[0] = 1;
                  }
                  else
                  {
                    v21 = (MIB_UDPROW *)((char *)v21 - 1);
                  }
                  v73 = pSystemHandleInfo;
                }
                v73 = (SYSTEM_HANDLE_INFORMATION *)((char *)v73 + 176);
                pSystemHandleInfo = v73;
                ++v110;
              }
              while ( v110 < pExtendedTable->dwNumEntries );
            }
            free(pExtendedTable);
          }
        }
        v8 = v106;
      }
      else
      {
        ReturnLength = 64000;
        pSystemHandleInfo = (SYSTEM_HANDLE_INFORMATION *)malloc(64000u);
        pSystemInfoClass = SystemHandleInformation;
        if ( gbSupportExtendedSystemHandleInformation )
          pSystemInfoClass = SystemExtendedHandleInformation;
        if ( NtQuerySystemInformation(pSystemInfoClass, pSystemHandleInfo, 64000u, &ReturnLength) )
        {
          pSystemHandleInfo1 = pSystemHandleInfo;
          do
          {
            free(pSystemHandleInfo1);
            ReturnLength *= 2;
            dwReturnLength = ReturnLength;
            pSystemHandleInfo1 = (SYSTEM_HANDLE_INFORMATION *)malloc(ReturnLength);
            SystemInfoClass = SystemHandleInformation;
            if ( gbSupportExtendedSystemHandleInformation )
              SystemInfoClass = SystemExtendedHandleInformation;
          }
          while ( NtQuerySystemInformation(SystemInfoClass, pSystemHandleInfo1, dwReturnLength, &ReturnLength) );
          v21 = v104;
          pSystemHandleInfo = pSystemHandleInfo1;
          v8 = v106;
        }
        v110 = (size_t)sub_C639C0(pSystemHandleInfo, *(_DWORD *)(*(_DWORD *)dwInitParam + 0x44));
        ReturnLength = 0;
        dwInitParam = 0;
        if ( GetTcpTable(0, &ReturnLength, 1) == 122 )
        {
          do
          {
            v79 = (struct _MIB_TCPTABLE *)malloc(ReturnLength);
            v80 = v79;
            dwInitParam = (LPARAM)v79;
            v81 = GetTcpTable(v79, &ReturnLength, 1);
            v103 = v81;
            if ( v81 )
            {
              free(v80);
              v81 = v103;
              dwInitParam = 0;
            }
          }
          while ( v81 == ERROR_INSUFFICIENT_BUFFER );
          v21 = v104;
        }
        ReturnLength = 0;
        v105 = 0;
        if ( GetUdpTable(0, &ReturnLength, 1) == ERROR_INSUFFICIENT_BUFFER )
        {
          do
          {
            pUdpTable = (struct _MIB_UDPTABLE *)malloc(ReturnLength);
            v83 = pUdpTable;
            v105 = pUdpTable;
            v84 = GetUdpTable(pUdpTable, &ReturnLength, 1);
            v103 = v84;
            if ( v84 )
            {
              free(v83);
              v84 = v103;
              v105 = 0;
            }
          }
          while ( v84 == ERROR_INSUFFICIENT_BUFFER );
          v8 = v106;
        }
        if ( dwInitParam )
        {
          v33 = *(_DWORD *)dwInitParam == 0;
          v103 = 0;
          if ( !v33 )
          {
            v85 = dwInitParam + 16;
            v104 = (MIB_UDPROW *)(dwInitParam + 16);
            do
            {
              if ( (unsigned __int8)sub_C4F600(v110, 0, *(_DWORD *)(v85 - 8), *(_DWORD *)(v85 - 4)) )
              {
                if ( v104->dwLocalAddr )
                  v86 = v104->dwLocalPort;
                else
                  v86 = 0;
                v8 = v106;
                if ( sub_C4A070(
                       v106,
                       dwNewLong,
                       0,
                       v104[-2].dwLocalPort,
                       v104[-1].dwLocalAddr,
                       0,
                       v104[-1].dwLocalPort,
                       v104->dwLocalAddr,
                       0,
                       v86,
                       0,
                       0,
                       0,
                       (int)pnIDs) )
                {
                  pnIDs[0] = 1;
                }
                else
                {
                  v21 = (MIB_UDPROW *)((char *)v21 - 1);
                }
              }
              v85 = (int)&v104[2].dwLocalPort;
              ++v103;
              v104 = (MIB_UDPROW *)((char *)v104 + 20);
            }
            while ( (unsigned int)v103 < *(_DWORD *)dwInitParam );
          }
        }
        if ( v105 )
        {
          v33 = v105->dwNumEntries == 0;
          v103 = 0;
          if ( !v33 )
          {
            v87 = v105->table;
            v104 = v105->table;
            do
            {
              v88 = (void *)v87->dwLocalAddr;
              v106 = (HWND)v87->dwLocalPort;
              v98 = v88;
              if ( (unsigned __int8)sub_C4F600(v110, 1, (int)v88, (int)v106) )
              {
                if ( sub_C4A070(v8, dwNewLong, 1, 2, (int)v98, 0, (int)v106, 0xFFFFFFFF, 0, -1, 0, 0, 0, (int)pnIDs) )
                  pnIDs[0] = 1;
                else
                  v21 = (MIB_UDPROW *)((char *)v21 - 1);
              }
              v87 = v104 + 1;
              ++v103;
              ++v104;
            }
            while ( v103 < v105->dwNumEntries );
          }
        }
        free(pSystemHandleInfo);
        if ( v105 )
          free(v105);
        if ( dwInitParam )
          free((void *)dwInitParam);
        if ( v110 )
          free((void *)v110);
      }
      goto LABEL_191;
    }
    pTcpTable = 0;
    ppTcpTable = 0;
    if ( AllocateAndGetTcpExTable2FromStack )
    {
      v25 = GetProcessHeap();
      if ( AllocateAndGetTcpExTable2FromStack(&ppTcpTable, 1, v25, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL) )
        ppTcpTable = 0;
    }
    else
    {
      v26 = GetProcessHeap();
      v27 = AllocateAndGetTcpExTableFromStack(&pTcpTable, 1, v26, 2u, 2u);
      v28 = pTcpTable;
      if ( v27 )
        v28 = 0;
      pTcpTable = v28;
    }
    *(_DWORD *)&v101[1] = 0;
    lpMem = 0;
    if ( AllocateAndGetUdpExTable2FromStack )
    {
      v29 = GetProcessHeap();
      if ( AllocateAndGetUdpExTable2FromStack(&lpMem, 1, v29, 2u, 2u, UDP_TABLE_OWNER_MODULE) )
        lpMem = 0;
    }
    else
    {
      v30 = GetProcessHeap();
      v31 = AllocateAndGetUdpExTableFromStack((PVOID *)&v101[1], 1, v30, 2u, 2u);
      v32 = *(_DWORD *)&v101[1];
      if ( v31 )
        v32 = 0;
      *(_DWORD *)&v101[1] = v32;
    }
    if ( pTcpTable )
    {
      v33 = *(_DWORD *)pTcpTable == 0;
      v110 = 0;
      if ( !v33 )
      {
        v34 = 0;
        pSystemHandleInfo = 0;
        do
        {
          v21 = v104;
          if ( *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 24) == *(_DWORD *)(*(_DWORD *)dwInitParam + 68) )
          {
            if ( *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 16) )
              v35 = *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 20);
            else
              v35 = 0;
            v8 = v106;
            v36 = sub_C4A070(
                    v106,
                    dwNewLong,
                    0,
                    *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 4),
                    *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 8),
                    0,
                    *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 12),
                    *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 16),
                    0,
                    v35,
                    *(_DWORD *)((char *)pTcpTable + (_DWORD)v34 + 24),
                    0,
                    0,
                    (int)pnIDs);
            v34 = pSystemHandleInfo;
            if ( v36 )
            {
              pnIDs[0] = 1;
            }
            else
            {
              v21 = (MIB_UDPROW *)((char *)v21 - 1);
              v104 = v21;
            }
          }
          v34 = (SYSTEM_HANDLE_INFORMATION *)((char *)v34 + 24);
          ++v110;
          pSystemHandleInfo = v34;
        }
        while ( v110 < *(_DWORD *)pTcpTable );
      }
    }
    else if ( ppTcpTable )
    {
      v33 = *(_DWORD *)ppTcpTable == 0;
      v37 = (char *)ppTcpTable + 8;
      pSystemHandleInfo = 0;
      if ( !v33 )
      {
        do
        {
          if ( v37[6] == *(_DWORD *)(*(_DWORD *)dwInitParam + 68) )
          {
            v110 = *v37 - 28;
            v103 = (int)malloc(v110);
            memmove_0((void *)v103, v37 + 7, v110);
            v38 = v37[4];
            if ( v38 )
              v39 = v37[5];
            else
              v39 = 0;
            if ( sub_C4A070(v106, dwNewLong, 0, v37[1], v37[2], 0, v37[3], v38, 0, v39, v37[6], v103, v110, (int)pnIDs) )
              pnIDs[0] = 1;
            else
              v21 = (MIB_UDPROW *)((char *)v21 - 1);
          }
          v37 = (_DWORD *)((char *)v37 + *v37);
          pSystemHandleInfo = (SYSTEM_HANDLE_INFORMATION *)((char *)pSystemHandleInfo + 1);
        }
        while ( (unsigned int)pSystemHandleInfo < *(_DWORD *)ppTcpTable );
        v104 = v21;
      }
      v8 = v106;
    }
    if ( *(_DWORD *)&v101[1] )
    {
      v33 = **(_DWORD **)&v101[1] == 0;
      v110 = 0;
      if ( !v33 )
      {
        v40 = 0;
        pSystemHandleInfo = 0;
        do
        {
          v8 = v106;
          if ( *(PVOID *)((char *)&v40->Handles[0].Object + *(_DWORD *)&v101[1]) == *(PVOID *)(*(_DWORD *)dwInitParam
                                                                                             + 68) )
          {
            v41 = sub_C4A070(
                    v106,
                    dwNewLong,
                    1,
                    2,
                    *(_DWORD *)((char *)&v40->Handles[0].UniqueProcessId + *(_DWORD *)&v101[1]),
                    0,
                    *(_DWORD *)(&v40->Handles[0].ObjectTypeIndex + *(_DWORD *)&v101[1]),
                    0xFFFFFFFF,
                    0,
                    -1,
                    *(int *)((char *)&v40->Handles[0].Object + *(_DWORD *)&v101[1]),
                    0,
                    0,
                    (int)pnIDs);
            if ( v41 )
            {
              if ( (_BYTE)dwNewLong )
                v41->field_10 = 0;
              pnIDs[0] = 1;
            }
            else
            {
              v21 = (MIB_UDPROW *)((char *)v21 - 1);
            }
            v40 = pSystemHandleInfo;
          }
          v40 = (SYSTEM_HANDLE_INFORMATION *)((char *)v40 + 12);
          ++v110;
          pSystemHandleInfo = v40;
        }
        while ( v110 < **(_DWORD **)&v101[1] );
      }
    }
    else
    {
      if ( !lpMem )
      {
LABEL_118:
        if ( pTcpTable )
        {
          v51 = pTcpTable;
          v52 = GetProcessHeap();
          HeapFree(v52, 0, v51);
        }
        if ( ppTcpTable )
        {
          v53 = ppTcpTable;
          v54 = GetProcessHeap();
          HeapFree(v54, 0, v53);
        }
LABEL_191:
        if ( pnIDs[0] || v21 )
        {
          InvalidateRect(v8, 0, 0);
          CTreeList::InitHeaderColumn(v8, dword_CD9B98, (HWND)dword_CD9B98, byte_CCD225);
          v97 = dword_CD9B98;
          v96 = 1192;
          SendMessageW(v8, 0x1030u, (WPARAM)&v96, (LPARAM)BackendSortCallback);
          SendMessageW(v8, 0xBu, 1u, 0);
        }
        return 0;
      }
      v33 = *(_DWORD *)lpMem == 0;
      v42 = (struct _MIB_UDPTABLE *)((char *)lpMem + 8);
      v105 = (struct _MIB_UDPTABLE *)((char *)lpMem + 8);
      v110 = 0;
      if ( v33 )
      {
LABEL_116:
        if ( lpMem )
        {
          v49 = lpMem;
          v50 = GetProcessHeap();
          HeapFree(v50, 0, v49);
        }
        goto LABEL_118;
      }
      do
      {
        if ( v42[1].dwNumEntries == *(_DWORD *)(*(_DWORD *)dwInitParam + 68) )
        {
          v43 = v42->dwNumEntries - 16;
          v44 = malloc(v43);
          memmove_0(v44, v105[1].table, v43);
          v45 = v43;
          v8 = v106;
          v46 = sub_C4A070(
                  v106,
                  dwNewLong,
                  1,
                  2,
                  v105->table[0].dwLocalAddr,
                  0,
                  v105->table[0].dwLocalPort,
                  0xFFFFFFFF,
                  0,
                  -1,
                  v105[1].dwNumEntries,
                  (int)v44,
                  v45,
                  (int)pnIDs);
          if ( v46 )
          {
            if ( (_BYTE)dwNewLong )
              v46->field_10 = 0;
            v21 = v104;
            pnIDs[0] = 1;
          }
          else
          {
            v21 = (MIB_UDPROW *)((char *)v104 - 1);
            v104 = (MIB_UDPROW *)((char *)v104 - 1);
          }
          v42 = v105;
        }
        v42 = (struct _MIB_UDPTABLE *)((char *)v42 + v42->dwNumEntries);
        v105 = v42;
        ++v110;
      }
      while ( v110 < *(_DWORD *)lpMem );
    }
    if ( *(_DWORD *)&v101[1] )
    {
      v47 = *(void **)&v101[1];
      v48 = GetProcessHeap();
      HeapFree(v48, 0, v47);
    }
    goto LABEL_116;
  }
  if ( (unsigned int)a3 > 0x138 )
  {
    if ( a3 == 1024 )
    {
LABEL_33:
      InvalidateRect(v8, 0, 0);
    }
    else if ( a3 == 2033 )
    {
      v89 = dwInitParam;
      if ( gdwVersion < 1 || (v90 = *(_DWORD *)dwInitParam, v110 = 5, !(*(_BYTE *)(v90 + 40) & 0x20)) )
        v110 = 4;
      if ( *(_DWORD *)(dwInitParam + 12) )
      {
        CloseHandle(*(HANDLE *)(dwInitParam + 12));
        v89 = dwInitParam;
      }
      if ( *(_DWORD *)(v89 + 16) )
      {
        RtlDestroyQueryDebugBuffer(*(_DWORD *)(v89 + 16));
        v89 = dwInitParam;
      }
      if ( *(_DWORD *)(v89 + 8) )
      {
        free(*(void **)(v89 + 8));
        v89 = dwInitParam;
      }
      free((void *)v89);
      if ( SendMessageW(v8, 0x1004u, 0, 0) && v110 )
      {
        v91 = 0;
        do
        {
          v92 = gLogPixelSize.x;
          v93 = SendMessageW(v8, 0x101Du, v91, 0);
          *(&pnWidths + v91++) = MulDiv(v93, 96, v92);
        }
        while ( v91 < v110 );
        v5 = (HWND)pSystemHandleInfo;
      }
      DestroyWindow(v5);
    }
    return 0;
  }
  if ( a3 != 312 && a3 != 307 && a3 != 310 )
    return 0;
  return PE_FillControl((int)hWnd, (HDC)wParam);
}
// CB6C50: using guessed type __int16 word_CB6C50[8];
// CB6C70: using guessed type __int128 xmmword_CB6C70;
// CCD225: using guessed type char byte_CCD225;
// CD10D8: using guessed type char byte_CD10D8;
// CD4E54: using guessed type int gdwVersion;
// CDABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// CDF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// CED0A6: using guessed type __int16 word_CED0A6;
// CED0A8: using guessed type __int16 word_CED0A8;
// CED0AA: using guessed type __int16 word_CED0AA;
// CED0AC: using guessed type __int16 word_CED0AC;
// CED0B0: using guessed type int dword_CED0B0;

//----- (00C5ACF0) --------------------------------------------------------
int __stdcall PageProcThreads(HWND hWnd, int uMsg, WPARAM wParam, LPARAM lParam)
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
  _IMAGELIST *v68; // ebx
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
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // ecx
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
  tagTREEVIEWLISTITEMPARAM *v127; // esi
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
  tagLVITEMW lParama; // [esp+328h] [ebp-1B68h]
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
  lParamIn = (HCURSOR)lParam;
  pUserData = (tagThreadItem *)GetWindowLongW(hWnd, GWLP_USERDATA);
  pSystemProcessInfo = 0;
  pThreadItem_1 = pUserData;
  lParama.mask = 0;
  memset(&lParama.iItem, 0, 0x30u);
  _mm_storeu_si128((__m128i *)&v170, _mm_load_si128((const __m128i *)dword_CB6C60));
  v171 = 0x435;
  v6 = gLogPixelSize.x;
  _mm_storeu_si128((__m128i *)&v169, _mm_load_si128((const __m128i *)word_CB6C40));
  pnWidths[0] = MulDiv(-50, v6, 96);
  pnWidths[1] = MulDiv(-50, gLogPixelSize.x, 96);
  v175 = MulDiv(-75, gLogPixelSize.x, 96);
  v176 = MulDiv(100, gLogPixelSize.x, 96);
  v177 = MulDiv(200, gLogPixelSize.x, 96);
  SystemInformationLength = 0;
  if ( uMsg > (unsigned int)WM_COMMAND )
  {
    if ( uMsg > (unsigned int)WM_CTLCOLORDLG )
    {
      if ( uMsg != WM_CTLCOLORSTATIC )
      {
        if ( uMsg == 0x7F1 )
        {
          v130 = (void *)pUserData->m_hEvent2;
          pUserData->m_bValue1 = 1;
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
          SetEvent((HANDLE)pUserData->m_hEvent2);
        nmhdr.code = 0xFFFFFFF1;
        v139 = 0x74;
        SendMessageW(hWnd, WM_NOTIFY, 0, (LPARAM)&nmhdr);
        return 1;
      }
      if ( uMsg != WM_CTLCOLOREDIT )
        return 0;
    }
    return PE_FillControl((int)hWnd, (HDC)wParam);
  }
  if ( uMsg != WM_COMMAND )
  {
    switch ( uMsg )
    {
      case WM_ALTTABACTIVE|WM_DESTROY:
        CMainWnd::DrawItem((LPDRAWITEMSTRUCT)lParamIn);
        return 0;
      case 0x2C:
        return CMainWnd::HandleMeasureItem(hWnd, uMsg, wParam, (LPMEASUREITEMSTRUCT)lParamIn);
      case WM_NOTIFY:                           // WM_NOTIFY
        pNMHDR = (tagNMHDR *)lParamIn;
        switch ( *((_DWORD *)lParamIn + 2) )
        {
          case LVN_GETDISPINFOW:
            result = CMainWnd::HandleLVNGetDispInfoW(wParam, (int)lParamIn);
            break;
          case LVN_COLUMNCLICK:
            result = CMainWnd::HandleLVNColumnClick(IDC_PAGE_PROCTHREADS_LISTCTRL, (LPNMLVKEYDOWN)lParamIn);
            break;
          case LVN_DELETEITEM:
            result = CMainWnd::HandleLVNDeleteItem(IDC_PAGE_PROCTHREADS_LISTCTRL, (LPNMLISTVIEW)lParamIn);
            break;
          case LVN_ITEMCHANGED:
          case LVN_BEGINRDRAG|0x60:
            GetWindowLongW(pUserData->m_hWndList, GWL_STYLE);
            v83 = pNMHDR->code;
            if ( v83 != LVN_ITEMCHANGED && (v83 != -15 || pNMHDR[1].hwndFrom != (HWND)116) )
              return 0;
            v84 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
            lParama.iItem = SendMessageW(v84, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            lParama.iSubItem = 0;
            lParama.mask = 4;
            v85 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
            SendMessageW(v85, LVM_GETITEMW, 0, (LPARAM)&lParama);
            if ( lParama.iItem == -1 )
            {
              wsprintfW((wchar_t *)szBuffer2, (wchar_t *)&gszNullString);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_THREAD_ID_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_START_TIME_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CONTEXT_SWITCHES_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_KERNEL_TIME_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_USER_TIME_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_STATE_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE, (LPCWSTR)szBuffer2);
              SetDlgItemTextW(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE, (LPCWSTR)szBuffer2);
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
              v91 = *(_DWORD *)(pUserData->m_Param + 68) != 0;
              v92 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_MODULE);
              EnableWindow(v92, v91);
              v93 = *(_DWORD *)(pUserData->m_Param + 0x44) != 0;
              v94 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
              EnableWindow(v94, v93);
              v95 = pUserData->m_hProcess && *(_DWORD *)(pUserData->m_Param + 68);
              v96 = v95;
              v97 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
              EnableWindow(v97, v96);
              v98 = pUserData->m_hProcess && *(_DWORD *)(pUserData->m_Param + 0x44);
              v99 = v98;
              v100 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
              EnableWindow(v100, v99);
              v101 = pUserData->m_hProcess && *(_DWORD *)(pUserData->m_Param + 0x44);
              v102 = v101;
              v103 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
              EnableWindow(v103, v102);
              hWndEdit = (HWND)lParama.lParam;
              pThreadItem_1 = 0;
              pSystemProcessInfo = 0;
              GetSystemProcessInfo(&pSystemProcessInfo, (PULONG)&pThreadItem_1);
              pSystemProcessInfo_1 = pSystemProcessInfo;
              v105 = *(HANDLE *)(pUserData->m_Param + 0x44);
              if ( pSystemProcessInfo->UniqueProcessId != v105 )
              {
                do
                {
                  if ( !pSystemProcessInfo_1->NextEntryOffset )
                    break;
                  pSystemProcessInfo_1 = (SYSTEM_PROCESS_INFORMATION *)((char *)pSystemProcessInfo_1
                                                                      + pSystemProcessInfo_1->NextEntryOffset);
                }
                while ( pSystemProcessInfo_1->UniqueProcessId != v105 );
              }
              v106 = (HCURSOR)&pSystemProcessInfo_1[1];
              if ( pUserData->m_bValue2 )
                v106 = (HCURSOR)&pSystemProcessInfo_1->ReadOperationCount;
              v107 = 0;
              lParamIn = v106;
              v108 = pSystemProcessInfo_1->NumberOfThreads == 0;
              if ( pSystemProcessInfo_1->NumberOfThreads > 0 )
              {
                v109 = hWndEdit;
                do
                {
                  if ( !*((_DWORD *)v106 + 9) )
                    *((_DWORD *)v106 + 9) = v107;
                  if ( *((_DWORD *)v109 + 11) == *((_DWORD *)v106 + 9) )
                    break;
                  ++v107;
                  v106 += 0x10;
                }
                while ( v107 < pSystemProcessInfo_1->NumberOfThreads );
                hWnd_1 = hWnd_3;
                v108 = v107 == pSystemProcessInfo_1->NumberOfThreads;
                lParamIn = v106;
              }
              if ( !v108 )
              {
                wsprintfW((wchar_t *)szBuffer2, L"%d", *((_DWORD *)v106 + 9));
                SetDlgItemTextW(hWnd_1, IDC_PAGE_PROCTHREADS_STATIC_THREAD_ID_VALUE, (LPCWSTR)szBuffer2);
                v110 = lParamIn;
                wsprintfW(
                  (wchar_t *)szBuffer2,
                  L"%I64d:%02I64d:%02I64d.%03I64d",
                  *(_QWORD *)lParamIn / 0x861C46800ui64,
                  *(_QWORD *)lParamIn / 0x23C34600ui64 % 0x3C,
                  *(_QWORD *)v106 / 10000000i64 % 60,
                  *(_QWORD *)v106 % 10000000i64 / 10000);
                SetDlgItemTextW(hWnd_3, IDC_PAGE_PROCTHREADS_STATIC_KERNEL_TIME_VALUE, (LPCWSTR)szBuffer2);
                wsprintfW(
                  (wchar_t *)szBuffer2,
                  L"%I64d:%02I64d:%02I64d.%03I64d",
                  *((_QWORD *)lParamIn + 1) / 0x861C46800ui64,
                  *((_QWORD *)lParamIn + 1) / 0x23C34600ui64 % 0x3C,
                  *((_QWORD *)v110 + 1) / 10000000i64 % 60,
                  *((_QWORD *)v110 + 1) % 10000000i64 / 10000);
                hWnd_2 = hWnd_3;
                SetDlgItemTextW(hWnd_3, IDC_PAGE_PROCTHREADS_STATIC_USER_TIME_VALUE, (LPCWSTR)szBuffer2);
                lParamIn_1 = lParamIn;
                if ( *((_QWORD *)lParamIn + 2)
                  && (FileTimeToLocalFileTime((const FILETIME *)lParamIn + 2, &LocalFileTime),
                      FileTimeToSystemTime(&LocalFileTime, &SystemTime),
                      GetTimeFormatW(0x400u, 0, &SystemTime, 0, (LPWSTR)szBuffer2, 512))
                  && GetDateFormatW(0x400u, 0, &SystemTime, 0, (LPWSTR)szText2, 128) )
                {
                  wcscat_s((wchar_t *)szBuffer2, 0x400u, L"   ");
                  wcscat_s((wchar_t *)szBuffer2, 0x400u, (const wchar_t *)szText2);
                }
                else
                {
                  wcscpy_s((wchar_t *)szBuffer2, 0x400u, L"n/a");
                }
                SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_START_TIME_VALUE, (LPCWSTR)szBuffer2);
                if ( *((_DWORD *)lParamIn_1 + 13) != 5 || *((_DWORD *)lParamIn_1 + 14) != 5 )
                  v132 = L"Sus&pend";
                else
                  v132 = L"R&esume";
                v113 = ::GetDlgItem(hWnd_2, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
                SetWindowTextW(v113, v132);
                switch ( *((_DWORD *)lParamIn_1 + 13) )
                {
                  case 0:
                    wcscpy_s((wchar_t *)szBuffer2, 0x400u, L"Initialized");
                    break;
                  case 1:
                    wcscpy_s((wchar_t *)szBuffer2, 0x400u, L"Ready");
                    break;
                  case 2:
                    wcscpy_s((wchar_t *)szBuffer2, 0x400u, L"Running");
                    break;
                  case 4:
                    wcscpy_s((wchar_t *)szBuffer2, 0x400u, L"Terminated");
                    break;
                  case 5:
                    v114 = *((_DWORD *)lParamIn_1 + 14);
                    if ( v114 >= 0x28 )
                      wsprintfW((wchar_t *)szBuffer2, L"Waiting");
                    else
                      wsprintfW((wchar_t *)szBuffer2, L"Wait:%s", &aExecutive[64 * v114]);
                    break;
                  case 6:
                    wcscpy_s((wchar_t *)szBuffer2, 0x400u, L"Transition");
                    break;
                  case 7:
                    wcscpy_s((wchar_t *)szBuffer2, 0x400u, L"DeferredReady");
                    break;
                  default:
                    wsprintfW((wchar_t *)szBuffer2, L"<Unknown: %d>", *((_DWORD *)lParamIn_1 + 13));
                    break;
                }
                SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_STATE_VALUE, (LPCWSTR)szBuffer2);
                if ( *((_DWORD *)lParamIn_1 + 8) )
                {
                  wsprintfW((wchar_t *)szBuffer2, L"%d", *((_DWORD *)lParamIn_1 + 11));
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
                  wsprintfW((wchar_t *)szBuffer2, L"%d", *((_DWORD *)lParamIn_1 + 10));
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
                  v133 = *((_DWORD *)lParamIn_1 + 12);
                  if ( *((_DWORD *)lParamIn_1 + 8) )
                  {
                    wsprintfW((wchar_t *)szBuffer2, L"%d", v133);
                    v115 = PE_GetNumberFormat((LPCWSTR)szBuffer2, 0x400u);
                    SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_CONTEXT_SWITCHES_VALUE, v115);
                  }
                  else
                  {
                    wsprintfW((wchar_t *)szBuffer2, L"n/a", v133);
                  }
                  v116 = hWndEdit;
                  *(_DWORD *)ArgList = -1;
                  ThreadInformation = -1;
                  v117 = (void *)*((_DWORD *)hWndEdit + 10);
                  if ( v117 )
                  {
                    NtQueryInformationThread(v117, ThreadIoPriority, &ThreadInformation, 4u, &ReturnLength);
                    NtQueryInformationThread(*((HANDLE *)v116 + 10), ThreadPagePriority, ArgList, 4u, &ReturnLength);
                  }
                  if ( *((_DWORD *)v116 + 10) )
                  {
                    wsprintfW((wchar_t *)szBuffer2, L"%I64u", *((_DWORD *)v116 + 154), *((_DWORD *)v116 + 155));
                    PE_GetNumberFormat((LPCWSTR)szBuffer2, 0x400u);
                  }
                  else
                  {
                    wsprintfW((wchar_t *)szBuffer2, L"n/a");
                  }
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE, (LPCWSTR)szBuffer2);
                  if ( ThreadInformation == -1 )
                    wsprintfW((wchar_t *)szBuffer2, L"n/a");
                  else
                    sub_C67790(ThreadInformation, (wchar_t *)szBuffer2, 0x400u);
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
                  if ( *(_DWORD *)ArgList == -1 )
                    wsprintfW((wchar_t *)szBuffer2, L"n/a");
                  else
                    wsprintfW((wchar_t *)szBuffer2, L"%d", *(_DWORD *)ArgList);
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, (LPCWSTR)szBuffer2);
                  if ( GetThreadIdealProcessorEx )
                  {
                    v134 = *((unsigned __int8 *)v116 + 610);
                    if ( (unsigned int)sdwSystemLogicalProcessorInfoCount <= 1 )
                      wsprintfW((wchar_t *)szBuffer2, L"%d", v134);
                    else
                      wsprintfW((wchar_t *)szBuffer2, L"[%d]:%d", *((unsigned __int16 *)v116 + 304), v134);
                    SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE, (LPCWSTR)szBuffer2);
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
      case WM_KEYDOWN:                          // WM_KEYDOWN
        if ( wParam != 116 )
          return 0;
        SetEvent((HANDLE)pUserData->m_hEvent3);
        return 0;
      case WM_INITDIALOG:                       // WM_INITDIALOG
        if ( GetLogicalProcessorInformationEx )
        {
          GetLogicalProcessorInformationEx(RelationGroup, 0, &SystemInformationLength);
          sdwSystemLogicalProcessorInfoCount = SystemInformationLength
                                             / sizeof(_SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX);
        }
        v7 = (tagThreadItem *)operator new(0x40u);
        pThreadItem_1 = v7;
        v178 = 0;
        if ( v7 )
          pResizer = CResizer::CResizer((CResizer *)v7, hWnd);
        else
          pResizer = 0;
        v178 = -1;
        pResizer->m_nXRatio = 80;
        pResizer->m_nYRatio = 50;
        hWndList_1 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
        if ( hWndList_1 )
        {
          v10 = CResizer::AddItem(pResizer, hWndList_1, 1);
          *(_QWORD *)&v10->gap0[16] = 0i64;
          *(double *)&v10->gap0[24] = db_one;
        }
        v11 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE);
        hWndEdit = v11;
        if ( v11 )
        {
          v12 = CResizer::AddItem(pResizer, v11, 1);
          v13 = hWndEdit;
          *(_OWORD *)v12->gap0 = 0i64;
          *(_OWORD *)&CResizer::AddItem(pResizer, v13, 1)->gap0[16] = xmmword_CB6C70;
        }
        v14 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE);
        hWndEdit = v14;
        if ( v14 )
        {
          v15 = CResizer::AddItem(pResizer, v14, 1);
          v16 = hWndEdit;
          *(_OWORD *)v15->gap0 = 0i64;
          *(_OWORD *)&CResizer::AddItem(pResizer, v16, 1)->gap0[16] = xmmword_CB6C70;
        }
        v17 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY);
        hWndEdit = v17;
        if ( v17 )
        {
          v18 = CResizer::AddItem(pResizer, v17, 1);
          v19 = hWndEdit;
          *(_OWORD *)v18->gap0 = 0i64;
          *(_OWORD *)&CResizer::AddItem(pResizer, v19, 1)->gap0[16] = xmmword_CB6C70;
        }
        v20 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY);
        hWndEdit = v20;
        if ( v20 )
        {
          v21 = CResizer::AddItem(pResizer, v20, 1);
          v22 = hWndEdit;
          *(_OWORD *)v21->gap0 = 0i64;
          *(_OWORD *)&CResizer::AddItem(pResizer, v22, 1)->gap0[16] = xmmword_CB6C70;
        }
        v23 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE);
        hWndEdit = v23;
        if ( v23 )
        {
          v24 = CResizer::AddItem(pResizer, v23, 1);
          v25 = hWndEdit;
          *(_OWORD *)v24->gap0 = 0i64;
          *(_OWORD *)&CResizer::AddItem(pResizer, v25, 1)->gap0[16] = xmmword_CB6C70;
        }
        v26 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE);
        hWndEdit = v26;
        if ( v26 )
        {
          v27 = CResizer::AddItem(pResizer, v26, 1);
          v28 = hWndEdit;
          *(_OWORD *)v27->gap0 = 0i64;
          *(_OWORD *)&CResizer::AddItem(pResizer, v28, 1)->gap0[16] = xmmword_CB6C70;
        }
        v29 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
        hWndEdit = v29;
        if ( v29 )
        {
          v30 = CResizer::AddItem(pResizer, v29, 1);
          v31 = hWndEdit;
          *(_OWORD *)v30->gap0 = xmmword_CB6C70;
          *(_OWORD *)&CResizer::AddItem(pResizer, v31, 1)->gap0[16] = xmmword_CB6C70;
        }
        v32 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
        if ( v32 )
          *(_OWORD *)CResizer::AddItem(pResizer, v32, 1)->gap0 = xmmword_CB6C70;
        v33 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
        if ( v33 )
          *(_OWORD *)CResizer::AddItem(pResizer, v33, 1)->gap0 = xmmword_CB6C70;
        v34 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE);
        hWndEdit = v34;
        if ( v34 )
        {
          v35 = CResizer::AddItem(pResizer, v34, 1);
          v36 = hWndEdit;
          *(_OWORD *)v35->gap0 = 0i64;
          *(_OWORD *)&CResizer::AddItem(pResizer, v36, 1)->gap0[16] = xmmword_CB6C70;
        }
        PropSheet_UpdateTab(hWnd);
        if ( *((char *)lParamIn + 40) & 0x20 && gdwVersion >= 1 )
        {
          v37 = &v170;
          hWndEdit = (HWND)5;
        }
        else
        {
          v37 = &v169;
          hWndEdit = (HWND)4;
        }
        v108 = *((_DWORD *)lParamIn + 17) == 0;
        pnIDs = (UINT *)v37;
        if ( v108 )
        {
          LODWORD(v170) = 1638;
          LODWORD(v169) = 1638;
        }
        if ( gdwVersion >= 1 )
        {
          *((_DWORD *)v37 + 2) = 1200;
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
        pThreadItem = (tagThreadItem *)malloc(0x50u);
        pThreadItem_1 = pThreadItem;
        memset(pThreadItem, 0, 0x50u);
        lParam_1 = lParamIn;
        pThreadItem->m_Next = 0;
        pThreadItem->m_hProcess = 0;
        pThreadItem->m_Param = (int)lParam_1;
        pThreadItem->m_hEvent = CreateEventW(0, 0, 0, 0);
        hWndList = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
        pThreadItem->m_hWndList = hWndList;
        SetWindowLongW(hWndList, GWLP_WNDPROC, (LONG)Proxy_ListCtrlWndProc);
        SetWindowLongW(hWnd, GWLP_USERDATA, (LONG)pThreadItem);
        v51 = GetWindowLongW(pThreadItem->m_hWndList, GWL_STYLE);
        SetWindowLongW(pThreadItem->m_hWndList, -16, v51 & -3u | 9);
        SetWindowLongW(pThreadItem->m_hWndList, GWLP_USERDATA, 5);
        v52 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_LOADING_SYMBOLS_FOR);
        SetWindowTextW(v52, (LPCWSTR)&gszNullString);
        ShowSymbolConfigWarning(0);
        SendMessageW(pThreadItem->m_hWndList, WM_SETFONT, (WPARAM)ghConfigFont, 0);
        GetSystemProcessInfo(&pSystemProcessInfo, 0);
        v53 = pSystemProcessInfo;
        v54 = *(HANDLE *)(pThreadItem->m_Param + 0x44);
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
      v53 = (SYSTEM_PROCESS_INFORMATION *)((char *)v53 + v53->NextEntryOffset);
    }
    while ( v53->UniqueProcessId != v54 );
LABEL_43:
    v55 = LoadCursorW(0, (LPCWSTR)IDC_WAIT);
    v56 = SetCursor(v55);
    v57 = pThreadItem->m_Param;
    lParamIn = v56;
    v58 = OpenProcess(GENERIC_READ, 0, *(_DWORD *)(v57 + 0x44));
    pThreadItem->m_hProcess = v58;
    if ( v58 )
    {
      v59 = pnIDs;
    }
    else
    {
      pThreadItem->m_hProcess = OpenProcess(PROCESS_MODE_BACKGROUND_BEGIN, 0, *(_DWORD *)(pThreadItem->m_Param + 0x44));
      v59 = pnIDs;
      pnIDs[2] = 1092;
    }
    ProcPageInitList(pThreadItem->m_hWndList, (LONG)hWndEdit, v59, pnWidths, 1);
    if ( SymInitialize )
    {
      EnterCriticalSection(&gPE_ImageItemVerifiedLock);
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
    v63 = (_RTL_PROCESS_MODULES *)malloc(1000u);
    pThreadItem->m_SystemModules = v63;
    if ( NtQuerySystemInformation(SystemModuleInformation, v63, SystemInformationLength, &SystemInformationLength) )
    {
      do
      {
        free(pThreadItem->m_SystemModules);
        SystemInformationLength += 1000;
        v64 = (_RTL_PROCESS_MODULES *)malloc(SystemInformationLength);
        pThreadItem->m_SystemModules = v64;
      }
      while ( NtQuerySystemInformation(SystemModuleInformation, v64, SystemInformationLength, &SystemInformationLength) );
    }
    v65 = pThreadItem->m_Param;
    pThreadItem->m_DebugBuffer = 0;
    if ( !(*(_BYTE *)(v65 + 40) & 0x10) )
    {
      v66 = RtlCreateQueryDebugBuffer(0, 0);
      pThreadItem->m_DebugBuffer = v66;
      if ( v66 )
      {
        v147 = (int)v53->UniqueProcessId;
        v148 = pThreadItem->m_DebugBuffer;
        hThread = (void *)_beginthreadex(0, 0, (int)QueryProcessDebugInforThreadProc, (int)&v147, 0, &ThreadId);
        CloseHandle(pThreadItem->m_hThread);
        if ( WaitForSingleObject(hThread, 4000u) == WAIT_TIMEOUT )
        {
          LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
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
      LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    free(pSystemProcessInfo);
    v68 = ImageList_Create(16, 16, 1u, 256, 256);
    v69 = LoadIconW(ghInstance, (LPCWSTR)IDC_DOWNARROW);
    ImageList_ReplaceIcon(v68, -1, v69);
    v70 = LoadIconW(ghInstance, (LPCWSTR)IDC_UPARROW);
    ImageList_ReplaceIcon(v68, -1, v70);
    pThreadItem_2 = pThreadItem_1;
    v72 = GetWindowLongW(pThreadItem_1->m_hWndList, GWL_STYLE);
    SetWindowLongW(pThreadItem_2->m_hWndList, -16, v72 | 0x48);
    SendMessageW(pThreadItem_2->m_hWndList, 0x1003u, 1u, (LPARAM)v68);
    CTreeList::InitHeaderColumn(pThreadItem_2->m_hWndList, ::wParam, (HWND)::wParam, byte_CD53B4);
    pThreadItem_2->m_bValue1 = 0;
    pThreadItem_2->m_nRefCount = 2;
    pThreadItem_2->m_hEvent2 = (int)CreateEventW(0, 0, 1, 0);
    pThreadItem_2->m_hEvent2 = (int)CreateEventW(0, 0, 1, 0);
    v73 = CreateEventW(0, 0, 1, 0);
    pThreadItem_2->m_hEvent3 = (int)v73;
    ResetEvent(v73);
    v74 = (void *)pThreadItem_2->m_hEvent2;
    pThreadItem_2->field_4 = 0;
    SetEvent(v74);
    pThreadItem_2->m_hThread = (HANDLE)_beginthreadex(
                                         0,
                                         0,
                                         (int)UpdateProcThreadsInfoThreadProc,
                                         (int)pThreadItem_2,
                                         0,
                                         &ThreadId);
    SetFocus(pThreadItem_2->m_hWndList);
    SetCursor(lParamIn);
    ReleaseCapture();
    if ( GetCurrentProcessId() != *(_DWORD *)(pThreadItem_2->m_Param + 68) && pThreadItem_2->m_hProcess )
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
    if ( !*(_DWORD *)StackWalk64 )
    {
      v81 = GetDlgItem(hWnd_4, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
      EnableWindow(v81, 0);
    }
    return 1;
  }
  // Handler for WM_COMMAND
  if ( (unsigned __int16)wParam > (signed int)IDC_PAGE_PROCTHREADS_BUTTON_MODULE )
  {
    if ( (signed int)(unsigned __int16)wParam > 40001 )
    {
      if ( (unsigned __int16)wParam == IDM_VIEW_REFRESH_NOW )
      {
        SetEvent(ghRefreshEventHandle);
        return 0;
      }
      if ( (unsigned int)(unsigned __int16)wParam - 40092 > 1 )
        return 0;
      v131 = wParam;
    }
    else
    {
      if ( (unsigned __int16)wParam != 40001 )
      {
        switch ( (unsigned __int16)wParam )
        {
          case IDC_PAGE_PROCTHREADS_BUTTON_STACK:
            if ( !*(_DWORD *)StackWalk64 )
              return 0;
            lParama.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( lParama.iItem == -1 )
              return 0;
            lParama.iSubItem = 0;
            lParama.mask = 4;
            if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, (LPARAM)&lParama) )
              return 0;
            v127 = lParama.lParam;
            v128 = Fake_OpenThread((HANDLE)lParama.lParam->field_2C, 0x4Au);
            if ( v128 )
            {
              dwInitParam = *(_DWORD *)(pUserData->m_Param + 0x44);
              v142 = v127->field_2C;
              v144 = pUserData->m_hProcess;
              hObject = v128;
              v146 = pUserData->m_DebugBuffer;
              v145 = pUserData->m_SystemModules;
              DialogBoxParamW(ghMainInstance, L"THREADSTACK", hWnd, (DLGPROC)DlgThreadStack, (LPARAM)&dwInitParam);
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
            lParama.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( lParama.iItem == -1 )
              return 0;
            lParama.iSubItem = 0;
            lParama.mask = 4;
            if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, (LPARAM)&lParama) )
              return 0;
            pThreadItem_1 = (tagThreadItem *)lParama.lParam;
            ThreadHandle_1 = Fake_OpenThread((HANDLE)lParama.lParam->field_2C, 0x20000u);
            if ( ThreadHandle_1 )
            {
              memset(ListParam, 0, 4288u);
              wsprintfW((wchar_t *)szBuffer, L"Thread %d", pThreadItem_1->m_hProcess);
              v164 = 0;
              wcscpy_s((wchar_t *)szText, 0x40u, L"Thread");
              v165 = ThreadHandle_1;
              v163 = GetCurrentProcessId();
              FillHandleListParam(hWnd, (tagHANDLELISTITEMPARAM *)ListParam);
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
  if ( (unsigned __int16)wParam == IDC_PAGE_PROCTHREADS_BUTTON_MODULE )
  {
    lParama.iItem = SendMessageW(pUserData->m_hWndList, 0x100Cu, 0xFFFFFFFF, 2);
    if ( lParama.iItem != -1 )
    {
      lParama.iSubItem = 0;
      lParama.mask = 4;
      if ( SendMessageW(pUserData->m_hWndList, 0x104Bu, 0, (LPARAM)&lParama) )
      {
        qmemcpy(v135, lParama.lParam, 0x290u);
        if ( v136[0] )
        {
          memset(&pExecInfo, 0, 0x3Cu);
          pExecInfo.cbSize = 60;
          pExecInfo.lpFile = (LPCWSTR)v136[0];
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
  if ( (unsigned __int16)wParam != IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND )
    return 0;
LABEL_156:
  lParama.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( lParama.iItem == -1 )
    return 0;
  lParama.iSubItem = 0;
  lParama.mask = 4;
  if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, (LPARAM)&lParama) )
    return 0;
  v118 = (HANDLE *)lParama.lParam;
  pThreadItem_1 = (tagThreadItem *)lParama.lParam;
  if ( (_WORD)wParam == IDC_PAGE_PROCTHREADS_BUTTON_KILL )
  {
    wsprintfW((wchar_t *)szBuffer2, L"Are you sure you want to kill thread %d?", lParama.lParam->field_2C);
    if ( MessageBoxW(ghMainWnd, (LPCWSTR)szBuffer2, L"Process Explorer", 0x31u) != 2 )
    {
      v118 = (HANDLE *)&pThreadItem_1->m_Next;
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
  if ( (_WORD)wParam == IDC_PAGE_PROCTHREADS_BUTTON_KILL )
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
    GetWindowTextW(v121, (LPWSTR)szBuffer2, 1024);
    v122 = L"R&esume";
    v123 = szBuffer2;
    while ( 1 )
    {
      v124 = (unsigned __int16)*v123 < *v122;
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
      if ( NtSuspendThread(v122, (PULONG)ThreadHandle) )
        ReportMsg(L"Unable to suspend thread", ghMainWnd);
    }
    else if ( NtResumeThread(v122, (PULONG)ThreadHandle) )
    {
      ReportMsg(L"Unable to resume thread", ghMainWnd);
      CloseHandle(ThreadHandle);
      return 0;
    }
  }
  CloseHandle(ThreadHandle);
  return 0;
}
// CAE398: using guessed type wchar_t aREsume[8];
// CB5A74: using guessed type wchar_t aWaitS[8];
// CB5AF4: using guessed type wchar_t aProperties[11];
// CB6C40: using guessed type __int16 word_CB6C40[8];
// CB6C60: using guessed type int dword_CB6C60[4];
// CB6C70: using guessed type __int128 xmmword_CB6C70;
// CCE8B8: using guessed type wchar_t aExecutive[10];
// CD10DC: using guessed type int sdwSystemLogicalProcessorInfoCount;
// CD4E54: using guessed type int gdwVersion;
// CD53B4: using guessed type char byte_CD53B4;
// CDF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);

//----- (00C5C7F0) --------------------------------------------------------
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
  SYSTEM_PROCESS_INFORMATION *v20; // ebx
  unsigned int v21; // ecx
  int v22; // esi
  tagTREEVIEWLISTITEMPARAM *v23; // ecx
  signed int v24; // eax
  void *v25; // eax
  tagTREEVIEWLISTITEMPARAM *v26; // edi
  DWORD v27; // ecx
  LONGLONG v28; // rax
  bool v29; // cf
  DWORD v30; // ecx
  DWORD v31; // edx
  double v32; // xmm0_8
  WPARAM v33; // edx
  int v34; // ecx
  double v35; // xmm0_8
  char v36; // dl
  double v37; // xmm1_8
  tagTREEVIEWLISTITEMPARAM *v38; // ecx
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
  tagItem290_PageProcThreads LocalBuffer2; // [esp-294h] [ebp-E24h]
  _SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfor_1; // [esp-14h] [ebp-BA4h]
  unsigned __int64 timeDelta; // [esp-10h] [ebp-BA0h]
  PRTL_DEBUG_BUFFER dwNumberOfProcessors; // [esp-8h] [ebp-B98h]
  _RTL_PROCESS_MODULES *bFalse; // [esp-4h] [ebp-B94h]
  LPARAM lParam; // [esp+Ch] [ebp-B84h]
  int v64; // [esp+18h] [ebp-B78h]
  int v65; // [esp+1Ch] [ebp-B74h]
  THREAD_BASIC_INFORMATION ThreadInformation; // [esp+24h] [ebp-B6Ch]
  SIZE_T NumberOfBytesRead; // [esp+40h] [ebp-B50h]
  ULONG ReturnLength; // [esp+44h] [ebp-B4Ch]
  CLIENT_ID ClientID; // [esp+48h] [ebp-B48h]
  DWORD v70; // [esp+50h] [ebp-B40h]
  HANDLE hEvent2[2]; // [esp+54h] [ebp-B3Ch]
  size_t cbRet; // [esp+5Ch] [ebp-B34h]
  DWORD v73; // [esp+60h] [ebp-B30h]
  double v74; // [esp+64h] [ebp-B2Ch]
  int ThreadHandle; // [esp+6Ch] [ebp-B24h]
  tagLVITEMW item; // [esp+70h] [ebp-B20h]
  WPARAM wParam; // [esp+A4h] [ebp-AECh]
  WPARAM v78; // [esp+A8h] [ebp-AE8h]
  _DWORD v79[2]; // [esp+ACh] [ebp-AE4h]
  WPARAM v80; // [esp+B4h] [ebp-ADCh]
  WPARAM v81; // [esp+B8h] [ebp-AD8h]
  WPARAM v82; // [esp+BCh] [ebp-AD4h]
  int dwTebAddress; // [esp+C0h] [ebp-AD0h]
  unsigned int v84; // [esp+C4h] [ebp-ACCh]
  int v85; // [esp+C8h] [ebp-AC8h]
  HANDLE hHandle; // [esp+CCh] [ebp-AC4h]
  HWND hWndParent; // [esp+D0h] [ebp-AC0h]
  int nItem; // [esp+D4h] [ebp-ABCh]
  int nIndex; // [esp+D8h] [ebp-AB8h]
  char dwHighDateTime[4]; // [esp+DCh] [ebp-AB4h]
  HWND hWndList_1; // [esp+E0h] [ebp-AB0h]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+E4h] [ebp-AACh]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // [esp+E8h] [ebp-AA8h]
  tagThreadItem *pThreadItem_1; // [esp+ECh] [ebp-AA4h]
  int a5; // [esp+F3h] [ebp-A9Dh]
  char fOK; // [esp+FBh] [ebp-A95h]
  tagItem290_PageProcThreads LocalBuffer; // [esp+FCh] [ebp-A94h]
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
  bFalse = (_RTL_PROCESS_MODULES *)INFINITE;
  dwNumberOfProcessors = 0;
  hHandle = 0;
  hEvent2[0] = (HANDLE)pThreadItem_1->m_hEvent2;
  hEvent2[1] = (HANDLE)pThreadItem_1->m_hEvent3;
  fOK = 1;
  dwRet = WaitForMultipleObjects(2u, hEvent2, 0, INFINITE);
  SendMessageW = ::SendMessageW;
  if ( pThreadItem_2->m_bValue1 )
    goto __cleanup;
  LOBYTE(v4) = a5;
  v81 = v78;
  *(int *)((char *)&a5 + 1) = v4;
  v82 = wParam;
  while ( 1 )
  {
    nItem = 0;
    nIndex = 0;
    *(_DWORD *)dwHighDateTime = 0;
    if ( dwRet )
      goto LABEL_85;
    BYTE1(a5) = 0;
    hWndParent = GetParent(hWndList);
    if ( !fOK )
    {
      item.mask = LVIF_PARAM;
      nCount = SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
      item.iSubItem = 0;
      item.iItem = nCount - 1;
      if ( SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&item) )
      {
        nIndex_1 = nIndex;
        do
        {
          v8 = sub_C658D0((signed int)SendMessageW, hWndList, &item, (LPARAM)item.lParam, (int)&a5);
          v9 = BYTE1(a5);
          if ( v8 )
            v9 = 1;
          *(int *)((char *)&a5 + 1) = v9;
          if ( (_BYTE)a5 )
          {
            if ( item.lParam->field_C != 1 )
              --item.lParam->field_14;
            ++nIndex_1;
          }
          item.mask = 4;
          item.iSubItem = 0;
        }
        while ( SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&item) );
        nIndex = nIndex_1;
        pThreadItem_2 = pThreadItem_1;
      }
    }
    FileTime = GetSystemProcessInfo(&pSystemProcessInfo, &cbRet);
    dwLowDateTime = FileTime.dwLowDateTime;
    *(_DWORD *)dwHighDateTime = FileTime.dwHighDateTime;
    pSystemProcessInfo_1 = pSystemProcessInfo;
    dwProcessId = *(HANDLE *)(pThreadItem_2->m_Param + 68);
    if ( pSystemProcessInfo->UniqueProcessId != dwProcessId )
      break;
LABEL_19:
    *(_QWORD *)&dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    timeDelta = __PAIR__(FileTime.dwHighDateTime, dwLowDateTime) - *(_QWORD *)&pThreadItem_2->m_TimeLast;
    v80 = timeDelta * gSystemInfo.dwNumberOfProcessors >> 32;
    v85 = timeDelta * gSystemInfo.dwNumberOfProcessors;
    if ( !(timeDelta * gSystemInfo.dwNumberOfProcessors) )
    {
      v85 = 1;
      v80 = 0;
    }
    v15 = *(_RTL_PROCESS_MODULES **)dwHighDateTime;
    pThreadItem_2->m_TimeLast.dwLowDateTime = dwLowDateTime;
    pThreadItem_2->m_TimeLast.dwHighDateTime = (DWORD)v15;
    if ( GetProcessorSystemCycleTime )
    {
      v16 = 8 * gSystemInfo.dwNumberOfProcessors;
      pSystemProcessorCycleTimeInfor = (_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *)malloc(
                                                                                          8
                                                                                        * gSystemInfo.dwNumberOfProcessors);
      NtQuerySystemInformation(SystemProcessorCycleTimeInformation, pSystemProcessorCycleTimeInfor, v16, &ReturnLength);
      LODWORD(v18) = sub_C4E4B0(0, pSystemProcessInfo, pSystemProcessorCycleTimeInfor, 0);
      pThreadItem_2 = pThreadItem_1;
      pSystemProcessorCycleTimeInfor_1 = pSystemProcessorCycleTimeInfor;
      v19 = v18 - pThreadItem_1->m_CycleTime;
      v81 = (v18 - pThreadItem_1->m_CycleTime) >> 32;
      v82 = v19;
      LODWORD(pThreadItem_1->m_CycleTime) = v18;
      HIDWORD(pThreadItem_2->m_CycleTime) = HIDWORD(v18);
      free(pSystemProcessorCycleTimeInfor_1);
      hWndList = hWndList_1;
    }
    v20 = pSystemProcessInfo_1 + 1;
    if ( pThreadItem_2->m_bValue2 )
      v20 = (SYSTEM_PROCESS_INFORMATION *)((char *)pSystemProcessInfo_1 + 0x88);
    v21 = 0;
    *(_DWORD *)dwHighDateTime = pSystemProcessInfo_1->NumberOfThreads;
    v84 = 0;
    if ( *(_DWORD *)dwHighDateTime )
    {
      while ( 1 )
      {
        if ( pThreadItem_2->m_bValue1 )
          goto __cleanup1;
        if ( !v20->CreateTime.HighPart )
          v20->CreateTime.HighPart = v21;
        v22 = 0;
        if ( ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) )
          break;
LABEL_61:
        if ( pThreadItem_1->m_bValue1 )
        {
          pThreadItem_2 = pThreadItem_1;
          goto __cleanup1;
        }
        if ( v22 == ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) )
        {
          BYTE1(a5) = 1;
          memset(&LocalBuffer, 0, 0x290u);
          LocalBuffer.field_4 = 3;
          ClientID.UniqueThread = (void *)v20->CreateTime.HighPart;
          ClientID.UniqueProcess = 0;
          ThreadInformation.TebBaseAddrss = (PVOID)sizeof(OBJECT_ATTRIBUTES);
          ThreadInformation.ClientId.UniqueProcess = 0;
          ThreadInformation.AffinityMask = 0;
          ThreadInformation.ClientId.UniqueThread = 0;
          ThreadInformation.Priority = 0;
          ThreadInformation.BasePriority = 0;
          v43 = NtOpenThread(
                  (PHANDLE)&ThreadHandle,
                  0x48u,
                  (POBJECT_ATTRIBUTES)&ThreadInformation.TebBaseAddrss,
                  &ClientID);
          ThreadHandle_1 = 0;
          if ( !v43 )
            ThreadHandle_1 = (void *)ThreadHandle;
          LocalBuffer.ThreadHandle = (int)ThreadHandle_1;
          if ( QueryThreadCycleTime && ThreadHandle_1 )
            QueryThreadCycleTime(ThreadHandle_1, (PULONG64)&LocalBuffer.field_268);
          v45 = pThreadItem_1;
          LocalBuffer.field_2C = v20->CreateTime.HighPart;
          LocalBuffer.field_250 = v20->KernelTime.LowPart;
          bFalse = pThreadItem_1->m_SystemModules;
          LocalBuffer.field_254 = 0;
          dwNumberOfProcessors = pThreadItem_1->m_DebugBuffer;
          LocalBuffer.field_30 = v20->SpareLi3.HighPart;
          sub_C4DD60(
            0,
            0,
            (int)&LocalBuffer,
            (unsigned int)pThreadItem_1->m_hProcess,
            v20->SpareLi3.HighPart,
            v20->SpareLi3.HighPart >> 31,
            (int)dwNumberOfProcessors,
            &bFalse->NumberOfModules);
          *(_QWORD *)&LocalBuffer.field_270 = *(_QWORD *)&v20->NextEntryOffset + v20->SpareLi1.QuadPart;
          v46 = 2;
          if ( fOK )
            v46 = 0;
          LocalBuffer.field_14 = 0;
          LocalBuffer.field_10 = v46;
          LocalBuffer.field_278 = v45->m_Param;
          *(_QWORD *)&LocalBuffer.field_240 = 0i64;
          LocalBuffer.field_288 = 0;
          if ( GetThreadIdealProcessorEx )
            GetThreadIdealProcessorEx((HANDLE)LocalBuffer.ThreadHandle, &LocalBuffer.m_ProcessorNumber);
          if ( *(_BYTE *)(v45->m_Param + 40) & 0x20 && gdwVersion >= 1 )
          {
            if ( !NtQueryInformationThread(
                    (HANDLE)LocalBuffer.ThreadHandle,
                    ThreadBasicInformation,
                    &ThreadInformation,
                    sizeof(_THREAD_BASIC_INFORMATION),
                    0) )
            {
              v47 = v45->m_hProcess;
              LocalBuffer.m_TebBaseAddrss = ThreadInformation.TebBaseAddrss;
              LocalBuffer.m_hProcess = v47;
              ReadProcessMemory(
                v47,
                (char *)ThreadInformation.TebBaseAddrss + gdwTebAddressOffset,
                &dwTebAddress,
                4u,
                &NumberOfBytesRead);
              LocalBuffer.m_dwTebAddress = dwTebAddress;
              if ( dwTebAddress )
              {
                if ( sub_C6EFB0(dwTebAddress) )
                {
                  v48 = (const wchar_t *)sub_C6EFB0(dwTebAddress);
                  LocalBuffer.field_288 = (int)_wcsdup(v48);
                }
              }
            }
          }
          else
          {
            LocalBuffer.m_dwTebAddress = -1;
          }
          bFalse = (_RTL_PROCESS_MODULES *)v45;
          qmemcpy(&LocalBuffer2, &LocalBuffer, sizeof(LocalBuffer2));
          hWndList = hWndList_1;
          tagItem290_PageProcThreads_InsertToList(
            hWndList_1,
            LocalBuffer2.field_0,
            LocalBuffer2.field_4,
            LocalBuffer2.field_8,
            LocalBuffer2.field_C,
            LocalBuffer2.field_10,
            LocalBuffer2.field_14,
            LocalBuffer2.field_18,
            LocalBuffer2.field_1C,
            LocalBuffer2.field_20,
            LocalBuffer2.field_24,
            LocalBuffer2.ThreadHandle,
            LocalBuffer2.field_2C,
            LocalBuffer2.field_30,
            LocalBuffer2.field_34,
            LocalBuffer2.field_38,
            LocalBuffer2.field_3C,
            LocalBuffer2.field_40,
            LocalBuffer2.field_44,
            LocalBuffer2.field_48,
            LocalBuffer2.field_4C,
            LocalBuffer2.field_50,
            LocalBuffer2.field_54,
            LocalBuffer2.field_58,
            LocalBuffer2.field_5C,
            LocalBuffer2.field_60,
            LocalBuffer2.field_64,
            LocalBuffer2.field_68,
            LocalBuffer2.field_6C,
            LocalBuffer2.field_70,
            LocalBuffer2.field_74,
            LocalBuffer2.field_78,
            LocalBuffer2.field_7C,
            LocalBuffer2.field_80,
            LocalBuffer2.field_84,
            LocalBuffer2.field_88,
            LocalBuffer2.field_8C,
            LocalBuffer2.field_90,
            LocalBuffer2.field_94,
            LocalBuffer2.field_98,
            LocalBuffer2.field_9C,
            LocalBuffer2.field_A0,
            LocalBuffer2.field_A4,
            LocalBuffer2.field_A8,
            LocalBuffer2.field_AC,
            LocalBuffer2.field_B0,
            LocalBuffer2.field_B4,
            LocalBuffer2.field_B8,
            LocalBuffer2.field_BC,
            LocalBuffer2.field_C0,
            LocalBuffer2.field_C4,
            LocalBuffer2.field_C8,
            LocalBuffer2.field_CC,
            LocalBuffer2.field_D0,
            LocalBuffer2.field_D4,
            LocalBuffer2.field_D8,
            LocalBuffer2.field_DC,
            LocalBuffer2.field_E0,
            LocalBuffer2.field_E4,
            LocalBuffer2.field_E8,
            LocalBuffer2.field_EC,
            LocalBuffer2.field_F0,
            LocalBuffer2.field_F4);
          pThreadItem_2 = pThreadItem_1;
          SetEvent(pThreadItem_1->m_hEvent);
        }
        else
        {
          pThreadItem_2 = pThreadItem_1;
        }
        v20 = (SYSTEM_PROCESS_INFORMATION *)((char *)v20 + 64);
        v21 = v84 + 1;
        v84 = v21;
        if ( v21 >= pSystemProcessInfo_1->NumberOfThreads )
          goto LABEL_82;
      }
      while ( 1 )
      {
        item.mask = 4;
        item.iItem = v22;
        item.iSubItem = 0;
        ::SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&item);
        v23 = item.lParam;
        if ( item.lParam->field_2C == v20->CreateTime.HighPart )
          break;
        if ( ++v22 >= (unsigned int)::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) )
          goto LABEL_61;
      }
      v24 = v20->KernelTime.LowPart - item.lParam->field_250;
      if ( v24 != *(_DWORD *)&item.lParam->gap234[20] || 0 != *(_DWORD *)&item.lParam->gap234[24] )
      {
        if ( v24 <= 0 )
          *(_DWORD *)&item.lParam->gap234[20] = 0;
        else
          *(_DWORD *)&item.lParam->gap234[20] = v24;
        *(_DWORD *)&v23->gap234[24] = 0;
        v23 = item.lParam;
        BYTE1(a5) = 1;
      }
      v23->field_250 = v20->KernelTime.LowPart;
      item.lParam->field_254 = 0;
      if ( QueryThreadCycleTime )
      {
        v25 = (void *)item.lParam->dwStyle;
        if ( v25 )
        {
          QueryThreadCycleTime(v25, (PULONG64)v79);
          if ( (signed int)((*(_QWORD *)v79 - *(_QWORD *)&item.lParam->hMainWndBackup) >> 32) < 0
            || (*(_QWORD *)v79 < *(_QWORD *)&item.lParam->hMainWndBackup
             || (*(_QWORD *)v79 - *(_QWORD *)&item.lParam->hMainWndBackup) >> 32 == 0)
            && (HWND)v79[0] == item.lParam->hMainWndBackup )
          {
            item.lParam->field_258 = 0;
            item.lParam->field_25C = 0;
          }
          else
          {
            *(_QWORD *)&item.lParam->field_258 = *(_QWORD *)v79 - *(_QWORD *)&item.lParam->hMainWndBackup;
          }
          BYTE1(a5) = 1;
        }
      }
      item.lParam->hMainWndBackup = (HWND)v79[0];
      *(_DWORD *)&item.lParam->bMainWndIsHung = v79[1];
      v26 = item.lParam;
      v27 = v20->NextEntryOffset + v20->SpareLi1.LowPart;
      v28 = *(_QWORD *)&v20->NextEntryOffset + v20->SpareLi1.QuadPart;
      v73 = HIDWORD(v28);
      v29 = v27 < item.lParam->CreateTime.dwLowDateTime;
      v30 = v27 - item.lParam->CreateTime.dwLowDateTime;
      v70 = v28;
      v31 = HIDWORD(v28) - (v29 + item.lParam->CreateTime.dwHighDateTime);
      if ( GetProcessorSystemCycleTime && item.lParam->dwStyle )
      {
        v32 = (double)*(signed __int64 *)&item.lParam->field_258;
        v33 = v81;
        v34 = v82;
      }
      else
      {
        v32 = (double)(signed __int64)__PAIR__(v31, v30);
        v33 = v80;
        v34 = v85;
      }
      v74 = v32 * 100.0;
      v35 = (double)(signed __int64)__PAIR__(v33, v34);
      v36 = 0;
      v37 = v74;
      ++nItem;
      item.lParam->CreateTime.dwLowDateTime = v70;
      v26->CreateTime.dwHighDateTime = v73;
      v38 = item.lParam;
      v39 = v37 / v35;
      v40 = item.lParam->field_18;
      if ( v40 )
      {
        v41 = item.lParam->field_1C;
        if ( v41 < (signed int)gConfig.dwHighlightDuration )
        {
          item.lParam->field_10 = 2;
          v38->field_14 = v41;
LABEL_59:
          hWndList = hWndList_1;
          if ( v39 != *(double *)&item.lParam->gap234[12] )
          {
            *(double *)&item.lParam->gap234[12] = v39;
            BYTE1(a5) = 1;
          }
          goto LABEL_61;
        }
        if ( v40 )
        {
          v36 = 1;
          LOBYTE(item.lParam->field_18) = 0;
        }
      }
      v42 = BYTE1(a5);
      v38->field_10 = 0;
      if ( v36 )
        v42 = 1;
      BYTE1(a5) = v42;
      goto LABEL_59;
    }
LABEL_82:
    SendMessageW = ::SendMessageW;
    if ( pThreadItem_2->m_bValue1 )
      goto __cleanup;
    if ( nItem == nIndex )
    {
      LOBYTE(v4) = BYTE1(a5);
LABEL_85:
      if ( !(_BYTE)v4 )
        goto LABEL_87;
    }
    InvalidateRect(hWndList, 0, 0);
    v78 = ::wParam;
    wParam = 1044;
    SendMessageW(hWndList, LVM_SORTITEMS, (WPARAM)&wParam, (LPARAM)BackendSortCallback);
    SendMessageW(hWndList, WM_SETREDRAW, 1u, 0);
    bFalse = *(_RTL_PROCESS_MODULES **)dwHighDateTime;
    wsprintfW((wchar_t *)String, L"%d", *(_DWORD *)dwHighDateTime);
    SetDlgItemTextW(hWndParent, IDC_PAGE_PROCTHREADS_STATIC_STATIC, (LPCWSTR)String);
LABEL_87:
    if ( fOK )
    {
      SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 3u, 65534);
      v65 = 3;
      v64 = 3;
      SendMessageW(hWndList, LVM_SETITEMSTATE, 0, (LPARAM)&lParam);
      hHandle = (HANDLE)_beginthreadex(0, 0, (int)sub_C5D400, (int)pThreadItem_2, 0, 0);
      fOK = 0;
    }
    if ( pThreadItem_2->field_4 )
      goto __cleanup;
    dwRet = WaitForMultipleObjects(2u, hEvent2, 0, 0xFFFFFFFF);
    if ( pThreadItem_2->m_bValue1 )
      goto __cleanup;
    LOBYTE(v4) = BYTE1(a5);
  }
  v13 = pSystemProcessInfo_1;
  while ( 1 )
  {
    v14 = v13->NextEntryOffset;
    if ( !v14 )
      break;
    pSystemProcessInfo_1 = (SYSTEM_PROCESS_INFORMATION *)((char *)pSystemProcessInfo_1 + v14);
    v13 = pSystemProcessInfo_1;
    if ( pSystemProcessInfo_1->UniqueProcessId == dwProcessId )
      goto LABEL_19;
  }
  wsprintfW((wchar_t *)String, L"n/a");
  hWndParent_1 = hWndParent;
  SetDlgItemTextW(hWndParent, IDC_PAGE_PROCTHREADS_STATIC_THREAD_ID_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_START_TIME_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_CONTEXT_SWITCHES_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_KERNEL_TIME_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_USER_TIME_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_STATE_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, (LPCWSTR)String);
  SetDlgItemTextW(hWndParent_1, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE, (LPCWSTR)String);
  InvalidateRect(hWndList, 0, 1);
  bFalse = 0;
  v50 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_MODULE);
  EnableWindow(v50, (BOOL)bFalse);
  bFalse = 0;
  v51 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
  EnableWindow(v51, (BOOL)bFalse);
  bFalse = 0;
  v52 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
  EnableWindow(v52, (BOOL)bFalse);
  bFalse = 0;
  v53 = GetDlgItem(hWndParent_1, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
  EnableWindow(v53, (BOOL)bFalse);
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
        v55 = (tagThreadItem *)v55[8].m_hEvent3;
        if ( pThreadItem_2->m_Next->m_SystemModules )
          CloseHandle(pThreadItem_2->m_Next->m_SystemModules);
        if ( pThreadItem_2->m_Next[7].m_hEvent3 )
          free((void *)pThreadItem_2->m_Next[7].m_hEvent3);
        if ( pThreadItem_2->m_Next[8].m_hEvent2 )
          free((void *)pThreadItem_2->m_Next[8].m_hEvent2);
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
    CloseHandle((HANDLE)pThreadItem_2->m_hEvent2);
    CloseHandle((HANDLE)pThreadItem_2->m_hEvent3);
    if ( pThreadItem_2->m_DebugBuffer )
      RtlDestroyQueryDebugBuffer(pThreadItem_2->m_DebugBuffer);
    if ( pThreadItem_2->m_SystemModules )
      free(pThreadItem_2->m_SystemModules);
    free(pThreadItem_2);
  }
  return 0;
}
// C5D400: using guessed type int __stdcall sub_C5D400(int);
// CACDC0: using guessed type double db_onehundred;
// CD4E54: using guessed type int gdwVersion;
// CDB1CC: using guessed type int gdwTebAddressOffset;
// CDF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// CDF2F4: using guessed type int GetProcessorSystemCycleTime;

//----- (00C5D400) --------------------------------------------------------
int __stdcall sub_C5D400(int a1)
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
  v1 = *(HWND *)(a1 + 36);
  hWnd = v1;
  v2 = GetParent(v1);
  v3 = *(void **)(a1 + 20);
  hDlg = v2;
  WaitForSingleObject(v3, 0xFFFFFFFF);
  if ( !*(_BYTE *)(a1 + 24) )
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
          if ( SendMessageW(v1, 0x104Bu, 0, (LPARAM)&lParam) )
            break;
LABEL_7:
          if ( ++v5 >= v4 )
            goto LABEL_8;
        }
        v6 = v15;
        if ( *(_BYTE *)(v15 + 36) )
        {
          v1 = hWnd;
          goto LABEL_7;
        }
        wsprintfW(&String, L"Loading symbols for %s...", v15 + 52);
        v9 = GetDlgItem(hDlg, 1341);
        SetWindowTextW(v9, &String);
        sub_C4DD60(
          1,
          0,
          v15,
          *(_DWORD *)(v17 + 44),
          *(_DWORD *)(v6 + 48),
          *(_DWORD *)(v6 + 48) >> 31,
          *(_DWORD *)(v17 + 48),
          *(unsigned int **)(v17 + 40));
        InvalidateRect(hWnd, 0, 0);
        v10 = hDlg;
        *(_BYTE *)(v6 + 36) = 1;
        v11 = GetDlgItem(v10, 1341);
        SetWindowTextW(v11, (LPCWSTR)&gszNullString);
        v1 = hWnd;
      }
LABEL_8:
      v7 = v17;
      WaitForSingleObject(*(HANDLE *)(v17 + 20), 0xFFFFFFFF);
    }
    while ( !*(_BYTE *)(v7 + 24) );
  }
  return 0;
}
// C5D400: using guessed type int __stdcall sub_C5D400(int);

//----- (00C5D5B0) --------------------------------------------------------
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
      CMainWnd::DrawItem((LPDRAWITEMSTRUCT)dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hDlg, a2, wParam, (LPMEASUREITEMSTRUCT)dwNewLong);
    case 272:
      v5 = (CResizer *)operator new(0x40u);
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
        *(_QWORD *)&v8->gap0[16] = 0i64;
        *(double *)&v8->gap0[24] = db_one;
      }
      PropSheet_UpdateTab(hDlg);
      SetWindowLongW(hDlg, -21, dwNewLong);
      v9 = GetWindowLongW(v4, -16);
      SetWindowLongW(v4, -16, v9 & 0xFFFFFFFD | 1);
      SendMessageW(v4, 0x1036u, 0x4020u, 16416);
      v10 = (HWND)SendMessageW(v4, 0x104Eu, 0, 0);
      CTreeList::InitToolTips(v10);
      gOldListWndProc = (WNDPROC)SetWindowLongW(v4, -4, (LONG)Proxy_ListCtrlWndProc);
      SendMessageW(v4, 0x30u, (WPARAM)ghConfigFont, 0);
      InitListHeader(v4, &pnIDs, pnWidths, 3);
      v11 = *(int **)(dwNewLong + 868);
      if ( !v11 )
        goto LABEL_10;
      break;
    case 273:
      switch ( (unsigned __int16)wParam )
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
    v12 = SendMessageW(v4, 0x104Du, 0, (LPARAM)&lParam);
    dwNewLong = v12;
    if ( v12 == -1 )
      break;
    v21 = v12;
    lParam = 1;
    v22 = 1;
    v25 = v11[1];
    SendMessageW(v4, 0x104Cu, 0, (LPARAM)&lParam);
    v21 = dwNewLong;
    lParam = 1;
    v22 = 2;
    v25 = v11[2];
    SendMessageW(v4, 0x104Cu, 0, (LPARAM)&lParam);
    v11 = (int *)v11[3];
    if ( !v11 )
    {
LABEL_10:
      SendMessageW(v4, 0x101Eu, 0, 0xFFFF);
      SendMessageW(v4, 0x101Eu, 1u, 0xFFFF);
      SendMessageW(v4, 0x101Eu, 2u, 0xFFFF);
      v18 = 3;
      v17 = 3;
      SendMessageW(v4, 0x102Bu, 0, (LPARAM)&v16);
      SetFocus(v4);
      return 1;
    }
  }
  return 0;
}

//----- (00C5DA70) --------------------------------------------------------
char __cdecl PE_IsProcessInJob(HANDLE ProcessHandle, DWORD dwProcessId, DWORD *dwValue3, DWORD dwValue4)
{
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo; // eax
  ULONG NumberOfHandles; // edi
  int dwIndex; // edi
  SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *pEntry_1; // ebx
  void *v8; // esi
  _DWORD *v9; // edi
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *pEntry; // [esp+4h] [ebp-818h]
  DWORD *v12; // [esp+8h] [ebp-814h]
  DWORD v13; // [esp+Ch] [ebp-810h]
  int nIndex; // [esp+10h] [ebp-80Ch]
  int bProcessInJob; // [esp+14h] [ebp-808h]
  __int16 szBuffer[1024]; // [esp+18h] [ebp-804h]

  v13 = dwValue4;
  v12 = dwValue3;
  if ( !*(_DWORD *)IsProcessInJob || !ProcessHandle )
    return 0;
  if ( !dwValue3 )
  {
    if ( IsProcessInJob(ProcessHandle, 0, &bProcessInJob) && bProcessInJob == 1 )
      return 1;
    return 0;
  }
  pSystemHandleInfo = gpSystemHandleInfo;
  if ( gpSystemHandleInfo )
    NumberOfHandles = gpSystemHandleInfo->NumberOfHandles;
  else
    NumberOfHandles = 0;
  dwIndex = NumberOfHandles - 1;
  if ( dwIndex < 0 )
    return 0;
  while ( 1 )
  {
    GetHandleTableEntry(pSystemHandleInfo, dwIndex, &pEntry);
    pEntry_1 = (SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *)pEntry;
    nIndex = pEntry[1].CreatorBackTraceIndex;
    if ( _wcsicmp(&gpszObjectTypeNames[0x40 * nIndex], L"Job") )
      goto LABEL_13;
    v8 = (void *)PE_DuplicateProcessHandle(pEntry_1->UniqueProcessId, (HANDLE)pEntry_1->HandleValue, 0x80000000);
    if ( v8 )
    {
      if ( IsProcessInJob(ProcessHandle, v8, &bProcessInJob) && bProcessInJob == 1 )
        break;
    }
    CloseHandle(v8);
LABEL_13:
    if ( --dwIndex < 0 )
      return 0;
    pSystemHandleInfo = gpSystemHandleInfo;
  }
  PE_QueryObject(&gpszObjectTypeNames[0x40 * nIndex], pEntry_1, (wchar_t *)szBuffer, 0x400u, 0);
  v9 = (_DWORD *)v13;
  if ( v13 )
    *v9 = _wcsdup((const wchar_t *)szBuffer);
  *v12 = (DWORD)v8;
  return 1;
}

//----- (00C5DC00) --------------------------------------------------------
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

//----- (00C5DC50) --------------------------------------------------------
BOOL __cdecl sub_C5DC50(HWND hWnd_1, tagTREEVIEWLISTITEMPARAM *pItem)
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
  int v26; // [esp+4Ch] [ebp-34h]
  struct tagRECT v27; // [esp+5Ch] [ebp-24h]
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
    v7 = _mm_loadu_si128((const __m128i *)&gConfig.WindowPlacement[5].ptMaxPosition);
  else
    v7 = _mm_loadu_si128((const __m128i *)&gConfig.WindowPlacement[4].flags);
  _mm_storeu_si128((__m128i *)&Rect, v7);
  _mm_storeu_si128((__m128i *)&v19, v7);
  memset(&wp, 0, 0x2Cu);
  v8 = _mm_loadu_si128((const __m128i *)&v19);
  v9 = hWnd;
  wp.length = 0x2C;
  _mm_storeu_si128((__m128i *)&v26, v8);
  wp.showCmd = 0;
  SetWindowPlacement(v9, &wp);
  GetWindowRect(v9, &Rect);
  v10 = GetDesktopWindow();
  v11 = FindWindowExW(v10, 0, (LPCWSTR)0x8002, 0);
  if ( v11 )
  {
    do
    {
      GetWindowThreadProcessId(v11, &dwProcessId);
      if ( dwProcessId == GetCurrentProcessId() && v11 != hWnd )
      {
        GetWindowRect(v11, &v27);
        v12 = Rect.top;
        if ( v27.top == Rect.top )
        {
          v13 = Rect.left;
          if ( v27.left == Rect.left )
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
      v15 = FindWindowExW(v14, v11, (LPCWSTR)0x8002, 0);
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
// C5DCC5: user specified stroff has not been processed: WINDOWPLACEMENT offset 44
// C5DCEA: user specified stroff has not been processed: WINDOWPLACEMENT offset 44

//----- (00C5DE20) --------------------------------------------------------
CHAR *__thiscall sub_C5DE20(CString *this, int a2)
{
  CString *v2; // edi
  CHAR *v3; // edx
  int v4; // eax
  CHAR *result; // eax

  v2 = this;
  v3 = this->pszData - 16;
  if ( *((_DWORD *)v3 + 2) >= a2
    || a2 <= 0
    || (v4 = (*(int (__stdcall **)(CHAR *, int, signed int))(**(_DWORD **)v3 + 8))(v3, a2, 1)) == 0 )
  {
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  }
  result = (CHAR *)(v4 + 16);
  v2->pszData = result;
  return result;
}

//----- (00C5DE60) --------------------------------------------------------
_DWORD *__cdecl sub_C5DE60(DWORD dwProcessId)
{
  int v1; // ecx
  _DWORD *v2; // esi
  DWORD v3; // edi
  DWORD v4; // eax
  HANDLE v6; // ebx

  v1 = 0;
  v2 = 0;
  v3 = 0;
  if ( (signed int)gConfig.dwDllColumnCount <= 0 )
    return v2;
  while ( 1 )
  {
    v4 = gConfig.dwDllColumnMap[v1];
    if ( v4 == 1115 || v4 == 1116 || v4 == 1317 || v4 == 1118 )
      break;
    if ( ++v1 >= (signed int)gConfig.dwDllColumnCount )
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

//----- (00C5DF20) --------------------------------------------------------
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
  std__Tree_node_for_process_some_information *fUsingWS; // eax
  bool v17; // zf
  WPARAM wParam_1; // ebx
  int v19; // edx
  unsigned int v20; // eax
  bool v21; // cf
  int v22; // ecx
  int v23; // esi
  bool v24; // al
  char v25; // al
  int v26; // edx
  bool v27; // cl
  unsigned int v28; // edx
  unsigned int v29; // ecx
  signed int v30; // eax
  unsigned __int64 v31; // kr10_8
  __int64 v32; // kr18_8
  bool v33; // al
  char v34; // al
  int v35; // ecx
  int v36; // ecx
  bool v37; // al
  HANDLE ProcessHandle; // esi
  void *v39; // ecx
  unsigned int v40; // edx
  unsigned int v41; // ecx
  unsigned __int64 v42; // kr28_8
  bool v43; // al
  signed int v44; // ecx
  unsigned __int8 v45; // al
  int v46; // ecx
  char v47; // al
  int v48; // ecx
  char v49; // al
  char v50; // al
  char v51; // al
  char v52; // al
  char v53; // al
  char v54; // al
  int v55; // eax
  char v56; // al
  char v57; // bl
  int v58; // eax
  char v59; // al
  char v60; // cl
  char v61; // al
  char v62; // cl
  char v63; // al
  char v64; // cl
  int v65; // esi
  SYSTEM_PROCESS_INFORMATION *v66; // ecx
  DWORD v67; // edx
  std__Tree_node_for_process_some_information *v68; // eax
  int v69; // eax
  unsigned __int64 v70; // kr48_8
  int v71; // esi
  char v72; // al
  signed int v73; // ecx
  int v74; // esi
  char v75; // al
  signed int v76; // ecx
  HWND v77; // esi
  char v78; // al
  SYSTEM_PROCESS_INFORMATION *v79; // edx
  HWND v80; // ecx
  unsigned __int8 v81; // al
  HWND v82; // ST34_4
  DWORD v83; // edx
  unsigned __int8 v84; // al
  HWND v85; // ecx
  HWND v86; // ST34_4
  std__Tree_node_for_process_some_information *v87; // edx
  unsigned __int8 v88; // al
  HWND v89; // ecx
  HWND v90; // ST34_4
  int v91; // edx
  unsigned __int8 v92; // al
  HWND v93; // ecx
  HWND v94; // ST34_4
  char v95; // al
  int v96; // esi
  HWND v97; // ecx
  unsigned __int8 v98; // al
  char v99; // al
  unsigned int v100; // edx
  HWND v101; // ecx
  unsigned __int8 v102; // al
  HWND v103; // ST34_4
  char v104; // al
  int v105; // esi
  HWND v106; // ecx
  unsigned __int8 v107; // al
  char v108; // al
  unsigned int v109; // edx
  HWND v110; // ecx
  unsigned __int8 v111; // al
  HWND v112; // ST34_4
  char v113; // al
  int v114; // esi
  HWND v115; // ecx
  unsigned __int8 v116; // al
  char v117; // al
  unsigned int v118; // edx
  HWND v119; // ecx
  unsigned __int8 v120; // al
  HWND v121; // ST34_4
  char v122; // al
  SYSTEM_PROCESS_INFORMATION *v123; // ecx
  std__Tree_node_for_process_some_information *pNodeInMap3; // esi
  unsigned int v125; // ecx
  char v126; // al
  signed int v127; // ecx
  unsigned int v128; // eax
  unsigned int v129; // eax
  unsigned __int64 v130; // kr58_8
  char v131; // al
  signed int v132; // ecx
  unsigned int v133; // eax
  unsigned int v134; // eax
  unsigned __int64 v135; // kr60_8
  char v136; // al
  signed int v137; // ecx
  unsigned int v138; // ecx
  int v139; // ecx
  int v140; // eax
  bool v141; // dl
  HWND v142; // ST34_4
  char v143; // al
  unsigned int v144; // edx
  signed int v145; // ecx
  int v146; // edx
  int v147; // eax
  bool v148; // cl
  HWND v149; // ST34_4
  char v150; // al
  unsigned int v151; // edx
  signed int v152; // ecx
  int v153; // edx
  int v154; // ecx
  bool v155; // al
  HWND v156; // ST34_4
  char v157; // al
  HWND v158; // ecx
  int v159; // eax
  bool v160; // al
  char v161; // al
  signed int v162; // ecx
  int v163; // edx
  int v164; // ecx
  bool v165; // al
  HWND v166; // ST34_4
  char v167; // al
  HWND v168; // ecx
  int v169; // eax
  bool v170; // al
  char v171; // al
  signed int v172; // ecx
  int v173; // edx
  int v174; // ecx
  bool v175; // al
  HWND v176; // ST34_4
  char v177; // al
  HWND v178; // ecx
  int v179; // eax
  bool v180; // al
  char v181; // al
  signed int v182; // ecx
  int v183; // edx
  int v184; // ecx
  bool v185; // al
  HWND v186; // ST34_4
  char v187; // al
  HWND v188; // esi
  HWND v189; // ecx
  int v190; // eax
  unsigned int v191; // eax
  unsigned __int64 v192; // kr70_8
  bool v193; // dl
  char v194; // al
  char v195; // cl
  std__Tree_node_for_process_some_information *v196; // esi
  unsigned int v197; // ecx
  char v198; // al
  signed int v199; // ecx
  unsigned int v200; // eax
  unsigned int v201; // eax
  unsigned __int64 v202; // kr80_8
  char v203; // al
  signed int v204; // ecx
  unsigned int v205; // eax
  unsigned int v206; // eax
  unsigned __int64 v207; // kr88_8
  char v208; // al
  signed int v209; // ecx
  unsigned int v210; // ecx
  int v211; // ecx
  int v212; // eax
  bool v213; // dl
  HWND v214; // ST34_4
  char v215; // al
  unsigned int v216; // edx
  signed int v217; // ecx
  int v218; // edx
  int v219; // eax
  bool v220; // cl
  HWND v221; // ST34_4
  char v222; // al
  unsigned int v223; // edx
  signed int v224; // ecx
  int v225; // edx
  int v226; // ecx
  bool v227; // al
  HWND v228; // ST34_4
  char v229; // al
  HWND v230; // ecx
  int v231; // eax
  bool v232; // al
  char v233; // al
  signed int v234; // ecx
  int v235; // edx
  int v236; // ecx
  bool v237; // al
  HWND v238; // ST34_4
  char v239; // al
  HWND v240; // ecx
  int v241; // eax
  bool v242; // al
  char v243; // al
  signed int v244; // ecx
  int v245; // edx
  int v246; // ecx
  bool v247; // al
  HWND v248; // ST34_4
  char v249; // al
  HWND v250; // ecx
  int v251; // eax
  bool v252; // al
  char v253; // al
  signed int v254; // ecx
  int v255; // edx
  int v256; // ecx
  bool v257; // al
  HWND v258; // ST34_4
  char v259; // al
  HWND v260; // esi
  HWND v261; // ecx
  int v262; // eax
  unsigned int v263; // eax
  unsigned __int64 v264; // kr98_8
  bool v265; // dl
  char v266; // cl
  UINT_PTR MaximumWorkingSetSize; // [esp+8h] [ebp-88Ch]
  UINT_PTR MinimumWorkingSetSize; // [esp+Ch] [ebp-888h]
  unsigned int v269; // [esp+10h] [ebp-884h]
  int ProcessInformation; // [esp+14h] [ebp-880h]
  int v271; // [esp+18h] [ebp-87Ch]
  int a6a; // [esp+1Ch] [ebp-878h]
  ULONG ReturnLength; // [esp+20h] [ebp-874h]
  DWORD a7; // [esp+24h] [ebp-870h]
  int v275; // [esp+28h] [ebp-86Ch]
  std__Tree_node_for_process_some_information *pNode; // [esp+2Ch] [ebp-868h]
  HANDLE hProcess; // [esp+30h] [ebp-864h]
  unsigned __int64 llValue277; // [esp+34h] [ebp-860h]
  SYSTEM_PROCESS_INFORMATION *SystemProcessInfo; // [esp+3Ch] [ebp-858h]
  char v280; // [esp+40h] [ebp-854h]
  char v281; // [esp+41h] [ebp-853h]
  char v282; // [esp+42h] [ebp-852h]
  char v283; // [esp+43h] [ebp-851h]
  int v284; // [esp+48h] [ebp-84Ch]
  int v285; // [esp+4Ch] [ebp-848h]
  bool fVistaOrMore; // [esp+53h] [ebp-841h]
  int v287; // [esp+54h] [ebp-840h]
  HWND hWnd[2]; // [esp+58h] [ebp-83Ch]
  IO_COUNTERS IoCounters; // [esp+60h] [ebp-834h]
  __int64 ProcessorIdleCycleTime[256]; // [esp+90h] [ebp-804h]

  LOBYTE(v8) = 0;
  fUsingCSwitchDelta = 0;
  SystemProcessInfo = pSystemProcessInfo;
  v10 = 0;
  dwIndex = 0;
  hProcess = ProcessHandleIn;
  v287 = v8;
  v282 = 0;
  v281 = 0;
  v280 = 0;
  v283 = 0;
  fVistaOrMore = 0;
  llValue277 = 0i64;
  if ( gConfig.dwProcessColumnCount <= 0 )
    goto LABEL_271;
  BYTE1(v8) = 0;
  fVistaOrMore = gdwVersion >= WINDOWS_VISTA;
  do
  {
    uID = gConfig.dwProcessColumnMap[dwIndex];
    fNeedObjects = uID == IDS_GDI_OBJECTS || uID == IDS_USER_OBJECTS;
    v282 |= fNeedObjects;
    fUsingCSwitchDelta |= uID == IDS_CSWITCH_DELTA;
    fUsingProcessCycle = QueryProcessCycleTime
                      || uID == IDS_CPU
                      || uID == IDS_CYCLES
                      || uID == IDS_CYCLES_DELTA
                      || uID == IDS_CYCLECPUUSAGE;
    v10 |= fUsingProcessCycle;
    v280 |= fVistaOrMore;
    fUsingMemoryPriority = gdwVersion >= WINDOWS_VISTA && uID == IDS_MEMORY_PRIORITY;
    BYTE1(v8) |= fUsingMemoryPriority;
    fUsingWS = (std__Tree_node_for_process_some_information *)(uID == IDS_WS_PRIVATE
                                                            || uID == IDS_WS_SHAREABLE
                                                            || uID == IDS_WS_SHARED);
    ++dwIndex;
    LOBYTE(v8) = (unsigned __int8)fUsingWS | v8;
  }
  while ( dwIndex < gConfig.dwProcessColumnCount );
  v283 = BYTE1(v8);
  v17 = (_BYTE)v8 == 0;
  v281 = v8;
  LOBYTE(v8) = v287;
  fVistaOrMore = v10;
  if ( v17 )
  {
LABEL_271:
    fUsingWS = (std__Tree_node_for_process_some_information *)pItemParam->field_3A0;
    if ( fUsingWS )
    {
      free((void *)pItemParam->field_3A0);
      LOBYTE(v8) = v287;
      pItemParam->field_3A0 = 0;
      pItemParam->field_3A4 = 0;
    }
  }
  v17 = fUsingCSwitchDelta == 0;
  wParam_1 = wParam;
  if ( v17 )
  {
    pItemParam->ContextSwtichDelta = 0i64;
  }
  else
  {
    PE_ComputeProcessThreadContextSwitchCount(SystemProcessInfo);
    v285 = v20;
    v21 = v20 < LODWORD(pItemParam->ContextSwtiches);
    v22 = v20 - LODWORD(pItemParam->ContextSwtiches);
    v275 = v19;
    v23 = v19 - (v21 + HIDWORD(pItemParam->ContextSwtiches));
    if ( v19 - (v21 + HIDWORD(pItemParam->ContextSwtiches)) < 0
      || v19 <= v21 + HIDWORD(pItemParam->ContextSwtiches) && !v22 )
    {
      *(_QWORD *)hWnd = 0i64;
      v23 = 0;
      v22 = 0;
    }
    v24 = v22 != LODWORD(pItemParam->ContextSwtichDelta) || v23 != HIDWORD(pItemParam->ContextSwtichDelta);
    LODWORD(pItemParam->ContextSwtichDelta) = v22;
    HIDWORD(pItemParam->ContextSwtichDelta) = v23;
    v25 = RedrawColumn(v24, ghWndTreeListView, IDS_CSWITCH_DELTA, wParam);
    v26 = v285;
    LOBYTE(v287) = v25;
    v27 = v285 != LODWORD(pItemParam->ContextSwtiches) || v275 != HIDWORD(pItemParam->ContextSwtiches);
    HIDWORD(pItemParam->ContextSwtiches) = v275;
    LODWORD(pItemParam->ContextSwtiches) = v26;
    LOBYTE(fUsingWS) = RedrawColumn(v27, ghWndTreeListView, IDS_CONTEXT_SWITCHES, wParam);
    v8 = v287;
    LOBYTE(v8) = (unsigned __int8)fUsingWS | v287;
    v287 = v8;
  }
  if ( !pItemParam->dwProcessId )
  {
    if ( fVistaOrMore && QueryIdleProcessorCycleTime )
    {
      if ( gdwVersion < 2
        || (v29 = (unsigned __int64)SystemProcessInfo->SpareLi3.QuadPart >> 32,
            v28 = SystemProcessInfo->SpareLi3.QuadPart,
            !SystemProcessInfo->SpareLi3.QuadPart) )
      {
        ReturnLength = 8 * gSystemInfo.dwNumberOfProcessors;
        QueryIdleProcessorCycleTime(&ReturnLength, (PULONG64)ProcessorIdleCycleTime);
        v30 = 0;
        v29 = HIDWORD(llValue277);
        v28 = llValue277;
        if ( (signed int)gSystemInfo.dwNumberOfProcessors <= 0 )
        {
LABEL_50:
          v32 = __PAIR__(v29, v28) - pItemParam->Cycles;
          v33 = v32 != pItemParam->CyclesDelta;
          pItemParam->CyclesDelta = v32;
          v34 = RedrawColumn(v33, ghWndTreeListView, IDS_CYCLES_DELTA, wParam);
          v35 = v287;
          LOBYTE(v35) = v34 | v287;
          v287 = v35;
          v36 = HIDWORD(llValue277);
          v37 = llValue277 != pItemParam->Cycles;
          LODWORD(pItemParam->Cycles) = llValue277;
          HIDWORD(pItemParam->Cycles) = v36;
          LOBYTE(fUsingWS) = RedrawColumn(v37, ghWndTreeListView, IDS_CYCLES, wParam);
          LOBYTE(fUsingWS) = (unsigned __int8)fUsingWS | v287;
          return (int)fUsingWS;
        }
        do
        {
          v31 = __PAIR__(HIDWORD(ProcessorIdleCycleTime[v30]), ProcessorIdleCycleTime[v30]) + __PAIR__(v29, v28);
          v29 = (__PAIR__(HIDWORD(ProcessorIdleCycleTime[v30]), ProcessorIdleCycleTime[v30]) + __PAIR__(v29, v28)) >> 32;
          v28 = v31;
          ++v30;
        }
        while ( v30 < (signed int)gSystemInfo.dwNumberOfProcessors );
      }
      llValue277 = __PAIR__(v29, v28);
      goto LABEL_50;
    }
    goto LABEL_268;
  }
  ProcessHandle = hProcess;
  if ( fVistaOrMore && QueryIdleProcessorCycleTime )
  {
    v39 = SystemProcessInfo;
    if ( !hProcess )
    {
      fUsingWS = (std__Tree_node_for_process_some_information *)(SystemProcessInfo->SpareLi3.HighPart | SystemProcessInfo->SpareLi3.LowPart);
      if ( !SystemProcessInfo->SpareLi3.QuadPart )
        goto LABEL_268;
    }
    if ( gdwVersion >= 2
      && (v39 = (void *)((unsigned __int64)SystemProcessInfo->SpareLi3.QuadPart >> 32),
          v40 = SystemProcessInfo->SpareLi3.QuadPart,
          SystemProcessInfo->SpareLi3.QuadPart) )
    {
      llValue277 = __PAIR__((unsigned int)v39, v40);
    }
    else
    {
      QueryProcessCycleTime(v39, (PULONG64)hProcess);
      v39 = (void *)HIDWORD(llValue277);
      v40 = llValue277;
    }
    v42 = __PAIR__((unsigned int)v39, v40) - pItemParam->Cycles;
    v41 = (__PAIR__((unsigned int)v39, v40) - pItemParam->Cycles) >> 32;
    v43 = __PAIR__(v41, (unsigned int)v42) != pItemParam->CyclesDelta;
    pItemParam->CyclesDelta = __PAIR__(v41, (unsigned int)v42);
    v17 = RedrawColumn(v43, ghWndTreeListView, IDS_CYCLES_DELTA, wParam) == 0;
    v44 = (unsigned __int8)v287;
    v45 = 1;
    if ( !v17 )
      v44 = 1;
    v285 = v44;
    v46 = HIDWORD(llValue277);
    if ( llValue277 == pItemParam->Cycles )
      v45 = 0;
    LODWORD(pItemParam->Cycles) = llValue277;
    HIDWORD(pItemParam->Cycles) = v46;
    v17 = RedrawColumn(v45, ghWndTreeListView, IDS_CYCLES, wParam) == 0;
    v8 = (unsigned __int8)v285;
    fUsingWS = (std__Tree_node_for_process_some_information *)1;
    if ( !v17 )
      v8 = 1;
    v287 = v8;
  }
  if ( !ProcessHandle )
  {
LABEL_268:
    LOBYTE(fUsingWS) = v8;
    return (int)fUsingWS;
  }
  if ( wParam != -1 && GetProcessWorkingSetSize(ProcessHandle, &MinimumWorkingSetSize, &MaximumWorkingSetSize) )
  {
    v17 = MinimumWorkingSetSize == pItemParam->dwMinimumWorkingSetSize;
    pItemParam->dwMinimumWorkingSetSize = MinimumWorkingSetSize;
    v47 = RedrawColumn(!v17, ghWndTreeListView, IDS_MIN_WORKING_SET, wParam);
    v48 = v287;
    LOBYTE(v48) = v47 | v287;
    v17 = MaximumWorkingSetSize == pItemParam->dwMaximumWorkingSetSize;
    v287 = v48;
    pItemParam->dwMaximumWorkingSetSize = MaximumWorkingSetSize;
    v49 = RedrawColumn(!v17, ghWndTreeListView, IDS_MAX_WORKING_SET, wParam);
    LOBYTE(v287) = v49 | v287;
  }
  v50 = sub_C23340(
          ProcessHandle,
          __PAIR__(a4, a3) / gSystemInfo.dwNumberOfProcessors,
          (unsigned __int64)(__PAIR__(a4, a3) / gSystemInfo.dwNumberOfProcessors) >> 32,
          a5,
          a6,
          pItemParam,
          wParam);
  LOBYTE(v287) = v50 | v287;
  if ( v281 )
  {
    PE_QueryProcessWorkset(
      ProcessHandle,
      (_PSAPI_WORKING_SET_INFORMATION **)&pItemParam->field_3A0,
      (DWORD *)&pItemParam->field_3A4,
      &v285,
      &pNode,
      &a6a,
      &a7);
    if ( wParam != -1 )
    {
      v17 = v285 == pItemParam->WSTotal;
      pItemParam->WSTotal = v285;
      v51 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_TOTAL, wParam);
      LOBYTE(v287) = v51 | v287;
      v17 = pNode == (std__Tree_node_for_process_some_information *)pItemParam->WSPrivate;
      pItemParam->WSPrivate = (int)pNode;
      v52 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_PRIVATE, wParam);
      LOBYTE(v287) = v52 | v287;
      v17 = a6a == pItemParam->WSShareable;
      pItemParam->WSShareable = a6a;
      v53 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_SHAREABLE, wParam);
      LOBYTE(v287) = v53 | v287;
      v17 = a7 == pItemParam->WSShared;
      pItemParam->WSShared = a7;
      v54 = RedrawColumn(!v17, ghWndTreeListView, IDS_WS_SHARED, wParam);
      LOBYTE(v287) = v54 | v287;
    }
  }
  if ( v282 )
  {
    v55 = GetGuiResources(ProcessHandle, 0);
    v17 = v55 == pItemParam->m_GdiObjects;
    pItemParam->m_GdiObjects = v55;
    v56 = RedrawColumn(!v17, ghWndTreeListView, IDS_GDI_OBJECTS, wParam);
    v57 = v287;
    if ( v56 )
      v57 = 1;
    v58 = GetGuiResources(ProcessHandle, 1u);
    v17 = v58 == pItemParam->m_UserObjects;
    pItemParam->m_UserObjects = v58;
    v59 = RedrawColumn(!v17, ghWndTreeListView, IDS_USER_OBJECTS, wParam);
    v60 = v57;
    wParam_1 = wParam;
    if ( v59 )
      v60 = 1;
    LOBYTE(v287) = v60;
  }
  if ( v283 )
  {
    ProcessInformation = -1;
    NtQueryInformationProcess(ProcessHandle, ProcessPagePriority, &ProcessInformation, 4u, &ReturnLength);
    v17 = ProcessInformation == pItemParam->m_ProcessMemoryPriority;
    pItemParam->m_ProcessMemoryPriority = ProcessInformation;
    v61 = RedrawColumn(!v17, ghWndTreeListView, IDS_MEMORY_PRIORITY, wParam_1);
    v62 = v287;
    if ( v61 )
      v62 = 1;
    LOBYTE(v287) = v62;
  }
  if ( v280 )
  {
    v271 = -1;
    NtQueryInformationProcess(ProcessHandle, ProcessIoPriority, &v271, 4u, &ReturnLength);
    v17 = v271 == pItemParam->m_ProcessIoPriority;
    pItemParam->m_ProcessIoPriority = v271;
    v63 = RedrawColumn(!v17, ghWndTreeListView, IDS_IO_PRIORITY, wParam_1);
    v64 = v287;
    if ( v63 )
      v64 = 1;
    LOBYTE(v287) = v64;
  }
  fUsingWS = (std__Tree_node_for_process_some_information *)NtQueryInformationProcess(
                                                              ProcessHandle,
                                                              ProcessIoCounters,
                                                              &IoCounters,
                                                              0x30u,
                                                              &ReturnLength);
  if ( fUsingWS )
  {
    LOBYTE(fUsingWS) = v287;
  }
  else
  {
    v65 = LODWORD(IoCounters.ReadTransferCount) - LODWORD(pItemParam->IO_COUNTERS);
    v66 = (SYSTEM_PROCESS_INFORMATION *)((IoCounters.ReadTransferCount - pItemParam->IO_COUNTERS) >> 32);
    v284 = LODWORD(IoCounters.WriteOperationCount) - LODWORD(pItemParam->WriteOperationCount);
    v67 = (IoCounters.WriteTransferCount - pItemParam->WriteTransferCount) >> 32;
    v269 = LODWORD(IoCounters.WriteTransferCount) - LODWORD(pItemParam->WriteTransferCount);
    hWnd[1] = (HWND)(LODWORD(IoCounters.OtherOperationCount) - LODWORD(pItemParam->OtherOperationCount));
    v68 = (std__Tree_node_for_process_some_information *)((IoCounters.OtherTransferCount - pItemParam->OtherTransferCount) >> 32);
    a6a = LODWORD(IoCounters.OtherTransferCount) - LODWORD(pItemParam->OtherTransferCount);
    v275 = v65;
    pNode = v68;
    v70 = __PAIR__((unsigned int)v66, v65) + __PAIR__(v67, v269) + __PAIR__((unsigned int)v68, a6a);
    v69 = (__PAIR__((unsigned int)v66, v65) + __PAIR__(v67, v269) + __PAIR__((unsigned int)v68, a6a)) >> 32;
    hProcess = (HANDLE)v70;
    SystemProcessInfo = v66;
    v71 = LODWORD(IoCounters.ReadOperationCount) - LODWORD(pItemParam->ReadOperationCount);
    a7 = v67;
    v285 = v69;
    v72 = RedrawColumn(v71 != LODWORD(pItemParam->IoDeltaReads), ghWndTreeListView, IDS_IO_DELTA_READS, wParam_1);
    v73 = (unsigned __int8)v287;
    LODWORD(pItemParam->IoDeltaReads) = v71;
    v74 = v284;
    if ( v72 )
      v73 = 1;
    v287 = v73;
    v75 = RedrawColumn(v284 != LODWORD(pItemParam->IoDeltaWrites), ghWndTreeListView, IDS_IO_DELTA_WRITES, wParam_1);
    v76 = (unsigned __int8)v287;
    LODWORD(pItemParam->IoDeltaWrites) = v74;
    v77 = hWnd[1];
    if ( v75 )
      v76 = 1;
    v284 = v76;
    v78 = RedrawColumn(
            hWnd[1] != (HWND)LODWORD(pItemParam->IoDeltaOthers),
            ghWndTreeListView,
            IDS_IO_DELTA_OTHER,
            wParam_1);
    v79 = SystemProcessInfo;
    v17 = v78 == 0;
    v80 = (HWND)(unsigned __int8)v284;
    v81 = 1;
    if ( !v17 )
      v80 = (HWND)1;
    LODWORD(pItemParam->IoDeltaOthers) = v77;
    hWnd[1] = v80;
    if ( v275 == LODWORD(pItemParam->DeltaReadBytes)
      && v79 == (SYSTEM_PROCESS_INFORMATION *)HIDWORD(pItemParam->DeltaReadBytes) )
    {
      v81 = 0;
    }
    v82 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaReadBytes) = v275;
    HIDWORD(pItemParam->DeltaReadBytes) = v79;
    v17 = RedrawColumn(v81, v82, IDS_IO_DELTA_READ_BYTES, wParam_1) == 0;
    v83 = a7;
    v84 = 1;
    v85 = (HWND)LOBYTE(hWnd[1]);
    if ( !v17 )
      v85 = (HWND)1;
    hWnd[1] = v85;
    if ( v269 == LODWORD(pItemParam->DeltaWriteBytes) && a7 == HIDWORD(pItemParam->DeltaWriteBytes) )
      v84 = 0;
    v86 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaWriteBytes) = v269;
    HIDWORD(pItemParam->DeltaWriteBytes) = v83;
    v17 = RedrawColumn(v84, v86, IDS_IO_DELTA_WRITE_BYTES, wParam_1) == 0;
    v87 = pNode;
    v88 = 1;
    v89 = (HWND)LOBYTE(hWnd[1]);
    if ( !v17 )
      v89 = (HWND)1;
    hWnd[1] = v89;
    if ( a6a == LODWORD(pItemParam->DeltaOtherBytes)
      && pNode == (std__Tree_node_for_process_some_information *)HIDWORD(pItemParam->DeltaOtherBytes) )
    {
      v88 = 0;
    }
    v90 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaOtherBytes) = a6a;
    HIDWORD(pItemParam->DeltaOtherBytes) = v87;
    v17 = RedrawColumn(v88, v90, IDS_IO_DELTA_OTHER_BYTES, wParam_1) == 0;
    v91 = v285;
    v92 = 1;
    v93 = (HWND)LOBYTE(hWnd[1]);
    if ( !v17 )
      v93 = (HWND)1;
    hWnd[1] = v93;
    if ( hProcess == (HANDLE)LODWORD(pItemParam->DeltaTotalBytes) && v285 == HIDWORD(pItemParam->DeltaTotalBytes) )
      v92 = 0;
    v94 = ghWndTreeListView;
    LODWORD(pItemParam->DeltaTotalBytes) = hProcess;
    HIDWORD(pItemParam->DeltaTotalBytes) = v91;
    v95 = RedrawColumn(v92, v94, IDS_IO_DELTA_TOTAL_BYTES, wParam_1);
    v96 = IoCounters.ReadOperationCount;
    v17 = v95 == 0;
    v97 = (HWND)LOBYTE(hWnd[1]);
    v98 = 1;
    if ( !v17 )
      v97 = (HWND)1;
    hWnd[1] = v97;
    if ( IoCounters.ReadOperationCount == LODWORD(pItemParam->ReadOperationCount) )
      v98 = 0;
    v284 = HIDWORD(IoCounters.ReadOperationCount);
    v99 = RedrawColumn(v98, ghWndTreeListView, IDS_IO_READS, wParam_1);
    v100 = IoCounters.ReadTransferCount;
    v17 = v99 == 0;
    v101 = (HWND)LOBYTE(hWnd[1]);
    v102 = 1;
    if ( !v17 )
      v101 = (HWND)1;
    LODWORD(pItemParam->ReadOperationCount) = v96;
    hWnd[1] = v101;
    if ( __PAIR__(HIDWORD(IoCounters.ReadTransferCount), v100) == pItemParam->IO_COUNTERS )
      v102 = 0;
    v103 = ghWndTreeListView;
    pItemParam->IO_COUNTERS = __PAIR__(HIDWORD(IoCounters.ReadTransferCount), v100);
    v104 = RedrawColumn(v102, v103, IDS_IO_READ_BYTES, wParam_1);
    v105 = IoCounters.WriteOperationCount;
    v17 = v104 == 0;
    v106 = (HWND)LOBYTE(hWnd[1]);
    v107 = 1;
    if ( !v17 )
      v106 = (HWND)1;
    hWnd[1] = v106;
    if ( IoCounters.WriteOperationCount == LODWORD(pItemParam->WriteOperationCount) )
      v107 = 0;
    v284 = HIDWORD(IoCounters.WriteOperationCount);
    v108 = RedrawColumn(v107, ghWndTreeListView, IDS_IO_WRITES, wParam_1);
    v109 = IoCounters.WriteTransferCount;
    v17 = v108 == 0;
    v110 = (HWND)LOBYTE(hWnd[1]);
    v111 = 1;
    if ( !v17 )
      v110 = (HWND)1;
    LODWORD(pItemParam->WriteOperationCount) = v105;
    hWnd[1] = v110;
    if ( __PAIR__(HIDWORD(IoCounters.WriteTransferCount), v109) == pItemParam->WriteTransferCount )
      v111 = 0;
    v112 = ghWndTreeListView;
    pItemParam->WriteTransferCount = __PAIR__(HIDWORD(IoCounters.WriteTransferCount), v109);
    v113 = RedrawColumn(v111, v112, IDS_IO_WRITE_BYTES, wParam_1);
    v114 = IoCounters.OtherOperationCount;
    v17 = v113 == 0;
    v115 = (HWND)LOBYTE(hWnd[1]);
    v116 = 1;
    if ( !v17 )
      v115 = (HWND)1;
    hWnd[1] = v115;
    if ( IoCounters.OtherOperationCount == LODWORD(pItemParam->OtherOperationCount) )
      v116 = 0;
    v284 = HIDWORD(IoCounters.OtherOperationCount);
    v117 = RedrawColumn(v116, ghWndTreeListView, IDS_IO_OTHER, wParam_1);
    v118 = IoCounters.OtherTransferCount;
    v17 = v117 == 0;
    v119 = (HWND)LOBYTE(hWnd[1]);
    v120 = 1;
    if ( !v17 )
      v119 = (HWND)1;
    LODWORD(pItemParam->OtherOperationCount) = v114;
    hWnd[1] = v119;
    if ( __PAIR__(HIDWORD(IoCounters.OtherTransferCount), v118) == pItemParam->OtherTransferCount )
      v120 = 0;
    v121 = ghWndTreeListView;
    pItemParam->OtherTransferCount = __PAIR__(HIDWORD(IoCounters.OtherTransferCount), v118);
    v122 = RedrawColumn(v120, v121, IDS_IO_OTHER_BYTES, wParam_1);
    v123 = (SYSTEM_PROCESS_INFORMATION *)LOBYTE(hWnd[1]);
    if ( v122 )
      v123 = (SYSTEM_PROCESS_INFORMATION *)1;
    SystemProcessInfo = v123;
    pNodeInMap3 = *std__map_for_process_some_information::FindNodeByPid(
                     &gMap3_NodeSizeIs48H,
                     &pNode,
                     (unsigned int *)&pItemParam->dwProcessId);
    if ( pNodeInMap3 != (std__Tree_node_for_process_some_information *)gMap3_NodeSizeIs48H._Mypair._Myval2._Myhead )
    {
      v125 = (*(_QWORD *)&pNodeInMap3->dbNetworkDeltaReceives
            - (unsigned __int64)LODWORD(pItemParam->dbNetworkDeltaReceives)) >> 32;
      hWnd[1] = (HWND)(LODWORD(pNodeInMap3->dbNetworkDeltaReceives) - LODWORD(pItemParam->dbNetworkDeltaReceives));
      v126 = RedrawColumn(
               __PAIR__(v125, (unsigned int)hWnd[1]) != LODWORD(pItemParam->NetworkDeltaReceives),
               ghWndTreeListView,
               IDS_NETWORK_DELTA_RECEIVES,
               wParam_1);
      v127 = (unsigned __int8)SystemProcessInfo;
      if ( v126 )
        v127 = 1;
      *(HWND *)&pItemParam->NetworkDeltaReceives = hWnd[1];
      v128 = HIDWORD(pNodeInMap3->dbNetworkDeltaSends);
      v284 = v127;
      v130 = __PAIR__(v128, LODWORD(pNodeInMap3->dbNetworkDeltaSends)) - (unsigned int)pItemParam->field_450;
      v129 = (__PAIR__(v128, LODWORD(pNodeInMap3->dbNetworkDeltaSends)) - (unsigned int)pItemParam->field_450) >> 32;
      hWnd[1] = (HWND)v130;
      v131 = RedrawColumn(
               __PAIR__(v129, (unsigned int)v130) != LODWORD(pItemParam->NetworkDeltaSends),
               ghWndTreeListView,
               IDS_NETWORK_DELTA_SENDS,
               wParam_1);
      v132 = (unsigned __int8)v284;
      if ( v131 )
        v132 = 1;
      *(HWND *)&pItemParam->NetworkDeltaSends = hWnd[1];
      v133 = HIDWORD(pNodeInMap3->dbNetworkDeltaOthers);
      v284 = v132;
      v135 = __PAIR__(v133, LODWORD(pNodeInMap3->dbNetworkDeltaOthers)) - LODWORD(pItemParam->dbNetworkDeltaOthers);
      v134 = (__PAIR__(v133, LODWORD(pNodeInMap3->dbNetworkDeltaOthers)) - LODWORD(pItemParam->dbNetworkDeltaOthers)) >> 32;
      hWnd[1] = (HWND)v135;
      v136 = RedrawColumn(
               __PAIR__(v134, (unsigned int)v135) != LODWORD(pItemParam->NetworkDeltaOthers),
               ghWndTreeListView,
               IDS_NETWORK_DELTA_OTHERS,
               wParam_1);
      v137 = (unsigned __int8)v284;
      if ( v136 )
        v137 = 1;
      *(HWND *)&pItemParam->NetworkDeltaOthers = hWnd[1];
      v284 = v137;
      v138 = pNodeInMap3->field_18;
      v21 = v138 < pItemParam->field_438;
      v139 = v138 - pItemParam->field_438;
      hWnd[1] = ghWndTreeListView;
      v140 = pNodeInMap3->field_1C - (v21 + pItemParam->field_43C);
      v141 = v139 != pItemParam->field_448 || v140 != pItemParam->field_44C;
      v142 = hWnd[1];
      pItemParam->field_44C = v140;
      pItemParam->field_448 = v139;
      v143 = RedrawColumn(v141, v142, IDS_NETWORK_DELTA_RECEIVE_BYTES, wParam_1);
      v144 = pNodeInMap3->field_20;
      v145 = (unsigned __int8)v284;
      if ( v143 )
        v145 = 1;
      v21 = v144 < pItemParam->field_458;
      v146 = v144 - pItemParam->field_458;
      hWnd[1] = ghWndTreeListView;
      v147 = pNodeInMap3->field_24 - (v21 + pItemParam->field_45C);
      v284 = v145;
      v148 = v146 != pItemParam->field_468 || v147 != pItemParam->field_46C;
      v149 = hWnd[1];
      pItemParam->field_46C = v147;
      pItemParam->field_468 = v146;
      v150 = RedrawColumn(v148, v149, 1619, wParam_1);
      v151 = pNodeInMap3->field_28;
      v152 = (unsigned __int8)v284;
      if ( v150 )
        v152 = 1;
      v21 = v151 < pItemParam->field_478;
      v153 = v151 - pItemParam->field_478;
      v284 = v152;
      v154 = pNodeInMap3->field_2C - (v21 + pItemParam->field_47C);
      hWnd[1] = ghWndTreeListView;
      v155 = v153 != pItemParam->field_488 || v154 != pItemParam->field_48C;
      v156 = hWnd[1];
      pItemParam->field_488 = v153;
      pItemParam->field_48C = v154;
      v157 = RedrawColumn(v155, v156, IDS_NETWORK_DELTA_OTHER_BYTES, wParam_1);
      v158 = (HWND)(unsigned __int8)v284;
      if ( v157 )
        v158 = (HWND)1;
      v159 = LODWORD(pNodeInMap3->dbNetworkDeltaReceives);
      hWnd[1] = v158;
      v284 = v159;
      v160 = v159 != LODWORD(pItemParam->dbNetworkDeltaReceives) || HIDWORD(pNodeInMap3->dbNetworkDeltaReceives);
      v161 = RedrawColumn(v160, ghWndTreeListView, IDS_NETWORK_RECEIVES, wParam_1);
      v162 = LOBYTE(hWnd[1]);
      if ( v161 )
        v162 = 1;
      LODWORD(pItemParam->dbNetworkDeltaReceives) = v284;
      v163 = pNodeInMap3->field_18;
      v285 = v162;
      v164 = pNodeInMap3->field_1C;
      hWnd[1] = ghWndTreeListView;
      v165 = v163 != pItemParam->field_438 || v164 != pItemParam->field_43C;
      v166 = hWnd[1];
      pItemParam->field_438 = v163;
      pItemParam->field_43C = v164;
      v167 = RedrawColumn(v165, v166, IDS_NETWORK_RECEIVE_BYTES, wParam_1);
      v168 = (HWND)(unsigned __int8)v285;
      if ( v167 )
        v168 = (HWND)1;
      v169 = LODWORD(pNodeInMap3->dbNetworkDeltaSends);
      hWnd[1] = v168;
      v284 = v169;
      v170 = v169 != pItemParam->field_450 || HIDWORD(pNodeInMap3->dbNetworkDeltaSends);
      v171 = RedrawColumn(v170, ghWndTreeListView, IDS_NETWORK_SENDS, wParam_1);
      v172 = LOBYTE(hWnd[1]);
      if ( v171 )
        v172 = 1;
      pItemParam->field_450 = v284;
      v173 = pNodeInMap3->field_20;
      v285 = v172;
      v174 = pNodeInMap3->field_24;
      hWnd[1] = ghWndTreeListView;
      v175 = v173 != pItemParam->field_458 || v174 != pItemParam->field_45C;
      v176 = hWnd[1];
      pItemParam->field_458 = v173;
      pItemParam->field_45C = v174;
      v177 = RedrawColumn(v175, v176, IDS_NETWORK_SEND_BYTES, wParam_1);
      v178 = (HWND)(unsigned __int8)v285;
      if ( v177 )
        v178 = (HWND)1;
      v179 = LODWORD(pNodeInMap3->dbNetworkDeltaOthers);
      hWnd[1] = v178;
      v284 = v179;
      v180 = v179 != LODWORD(pItemParam->dbNetworkDeltaOthers) || HIDWORD(pNodeInMap3->dbNetworkDeltaOthers);
      v181 = RedrawColumn(v180, ghWndTreeListView, IDS_NETWORK_OTHER, wParam_1);
      v182 = LOBYTE(hWnd[1]);
      if ( v181 )
        v182 = 1;
      LODWORD(pItemParam->dbNetworkDeltaOthers) = v284;
      v183 = pNodeInMap3->field_28;
      v285 = v182;
      v184 = pNodeInMap3->field_2C;
      hWnd[1] = ghWndTreeListView;
      v185 = v183 != pItemParam->field_478 || v184 != pItemParam->field_47C;
      v186 = hWnd[1];
      pItemParam->field_478 = v183;
      pItemParam->field_47C = v184;
      v187 = RedrawColumn(v185, v186, IDS_NETWORK_OTHER_BYTES, wParam_1);
      v188 = ghWndTreeListView;
      v189 = (HWND)(unsigned __int8)v285;
      if ( v187 )
        v189 = (HWND)1;
      v190 = pItemParam->field_46C;
      hWnd[1] = v189;
      v192 = *(_QWORD *)&pItemParam->field_488
           + *(_QWORD *)&pItemParam->field_448
           + __PAIR__(v190, pItemParam->field_468);
      v191 = v192 >> 32;
      v193 = __PAIR__(v191, (unsigned int)v192) != *(_QWORD *)&pItemParam->field_490;
      *(_QWORD *)&pItemParam->field_490 = __PAIR__(v191, (unsigned int)v192);
      v194 = RedrawColumn(v193, v188, 1622, wParam_1);
      v195 = (char)hWnd[1];
      if ( v194 )
        v195 = 1;
      LOBYTE(SystemProcessInfo) = v195;
    }
    fUsingWS = (std__Tree_node_for_process_some_information *)std__map_for_process_some_information::FindNodeByPid(
                                                                &gMap2_NodeSizeIs48H,
                                                                &pNode,
                                                                (unsigned int *)&pItemParam->dwProcessId);
    v196 = (std__Tree_node_for_process_some_information *)fUsingWS->_Left;
    if ( fUsingWS->_Left == (std_Tree_node_for_tagKeyName *)gMap2_NodeSizeIs48H._Mypair._Myval2._Myhead )
    {
      LOBYTE(fUsingWS) = (_BYTE)SystemProcessInfo;
    }
    else
    {
      v197 = (*(_QWORD *)&v196->dbNetworkDeltaReceives - (unsigned __int64)(unsigned int)pItemParam->field_498) >> 32;
      hWnd[1] = (HWND)(LODWORD(v196->dbNetworkDeltaReceives) - pItemParam->field_498);
      v198 = RedrawColumn(
               __PAIR__(v197, (unsigned int)hWnd[1]) != pItemParam->field_4A8,
               ghWndTreeListView,
               1624,
               wParam_1);
      v199 = (unsigned __int8)SystemProcessInfo;
      if ( v198 )
        v199 = 1;
      pItemParam->field_4A8 = (int)hWnd[1];
      v200 = HIDWORD(v196->dbNetworkDeltaSends);
      v284 = v199;
      v202 = __PAIR__(v200, LODWORD(v196->dbNetworkDeltaSends)) - (unsigned int)pItemParam->field_4B8;
      v201 = (__PAIR__(v200, LODWORD(v196->dbNetworkDeltaSends)) - (unsigned int)pItemParam->field_4B8) >> 32;
      hWnd[1] = (HWND)v202;
      v203 = RedrawColumn(
               __PAIR__(v201, (unsigned int)v202) != pItemParam->field_4C8,
               ghWndTreeListView,
               1626,
               wParam_1);
      v204 = (unsigned __int8)v284;
      if ( v203 )
        v204 = 1;
      pItemParam->field_4C8 = (int)hWnd[1];
      v205 = HIDWORD(v196->dbNetworkDeltaOthers);
      v284 = v204;
      v207 = __PAIR__(v205, LODWORD(v196->dbNetworkDeltaOthers)) - (unsigned int)pItemParam->field_4D8;
      v206 = (__PAIR__(v205, LODWORD(v196->dbNetworkDeltaOthers)) - (unsigned int)pItemParam->field_4D8) >> 32;
      hWnd[1] = (HWND)v207;
      v208 = RedrawColumn(
               __PAIR__(v206, (unsigned int)v207) != pItemParam->field_4E8,
               ghWndTreeListView,
               1628,
               wParam_1);
      v209 = (unsigned __int8)v284;
      if ( v208 )
        v209 = 1;
      pItemParam->field_4E8 = (int)hWnd[1];
      v284 = v209;
      v210 = v196->field_18;
      v21 = v210 < pItemParam->field_4A0;
      v211 = v210 - pItemParam->field_4A0;
      hWnd[1] = ghWndTreeListView;
      v212 = v196->field_1C - (v21 + pItemParam->field_4A4);
      v213 = v211 != pItemParam->field_4B0 || v212 != pItemParam->field_4B4;
      v214 = hWnd[1];
      pItemParam->field_4B4 = v212;
      pItemParam->field_4B0 = v211;
      v215 = RedrawColumn(v213, v214, IDS_DISK_DELTA_READ_BYTES, wParam_1);
      v216 = v196->field_20;
      v217 = (unsigned __int8)v284;
      if ( v215 )
        v217 = 1;
      v21 = v216 < pItemParam->field_4C0;
      v218 = v216 - pItemParam->field_4C0;
      hWnd[1] = ghWndTreeListView;
      v219 = v196->field_24 - (v21 + pItemParam->field_4C4);
      v284 = v217;
      v220 = v218 != pItemParam->field_4D0 || v219 != pItemParam->field_4D4;
      v221 = hWnd[1];
      pItemParam->field_4D4 = v219;
      pItemParam->field_4D0 = v218;
      v222 = RedrawColumn(v220, v221, IDS_DISK_DELTA_WRITE_BYTES, wParam_1);
      v223 = v196->field_28;
      v224 = (unsigned __int8)v284;
      if ( v222 )
        v224 = 1;
      v21 = v223 < pItemParam->field_4E0;
      v225 = v223 - pItemParam->field_4E0;
      v284 = v224;
      v226 = v196->field_2C - (v21 + pItemParam->field_4E4);
      hWnd[1] = ghWndTreeListView;
      v227 = v225 != pItemParam->field_4F0 || v226 != pItemParam->field_4F4;
      v228 = hWnd[1];
      pItemParam->field_4F0 = v225;
      pItemParam->field_4F4 = v226;
      v229 = RedrawColumn(v227, v228, IDS_DISK_DELTA_OTHER_BYTES, wParam_1);
      v230 = (HWND)(unsigned __int8)v284;
      if ( v229 )
        v230 = (HWND)1;
      v231 = LODWORD(v196->dbNetworkDeltaReceives);
      hWnd[1] = v230;
      v284 = v231;
      v232 = v231 != pItemParam->field_498 || HIDWORD(v196->dbNetworkDeltaReceives);
      v233 = RedrawColumn(v232, ghWndTreeListView, IDS_DISK_READS, wParam_1);
      v234 = LOBYTE(hWnd[1]);
      if ( v233 )
        v234 = 1;
      pItemParam->field_498 = v284;
      v235 = v196->field_18;
      v285 = v234;
      v236 = v196->field_1C;
      hWnd[1] = ghWndTreeListView;
      v237 = v235 != pItemParam->field_4A0 || v236 != pItemParam->field_4A4;
      v238 = hWnd[1];
      pItemParam->field_4A0 = v235;
      pItemParam->field_4A4 = v236;
      v239 = RedrawColumn(v237, v238, IDS_DISK_READ_BYTES, wParam_1);
      v240 = (HWND)(unsigned __int8)v285;
      if ( v239 )
        v240 = (HWND)1;
      v241 = LODWORD(v196->dbNetworkDeltaSends);
      hWnd[1] = v240;
      v284 = v241;
      v242 = v241 != pItemParam->field_4B8 || HIDWORD(v196->dbNetworkDeltaSends);
      v243 = RedrawColumn(v242, ghWndTreeListView, IDS_DISK_WRITES, wParam_1);
      v244 = LOBYTE(hWnd[1]);
      if ( v243 )
        v244 = 1;
      pItemParam->field_4B8 = v284;
      v245 = v196->field_20;
      v285 = v244;
      v246 = v196->field_24;
      hWnd[1] = ghWndTreeListView;
      v247 = v245 != pItemParam->field_4C0 || v246 != pItemParam->field_4C4;
      v248 = hWnd[1];
      pItemParam->field_4C0 = v245;
      pItemParam->field_4C4 = v246;
      v249 = RedrawColumn(v247, v248, IDS_DISK_WRITE_BYTES, wParam_1);
      v250 = (HWND)(unsigned __int8)v285;
      if ( v249 )
        v250 = (HWND)1;
      v251 = LODWORD(v196->dbNetworkDeltaOthers);
      hWnd[1] = v250;
      v284 = v251;
      v252 = v251 != pItemParam->field_4D8 || HIDWORD(v196->dbNetworkDeltaOthers);
      v253 = RedrawColumn(v252, ghWndTreeListView, IDS_DISK_OTHER, wParam_1);
      v254 = LOBYTE(hWnd[1]);
      if ( v253 )
        v254 = 1;
      pItemParam->field_4D8 = v284;
      v255 = v196->field_28;
      v285 = v254;
      v256 = v196->field_2C;
      hWnd[1] = ghWndTreeListView;
      v257 = v255 != pItemParam->field_4E0 || v256 != pItemParam->field_4E4;
      v258 = hWnd[1];
      pItemParam->field_4E0 = v255;
      pItemParam->field_4E4 = v256;
      v259 = RedrawColumn(v257, v258, IDS_DISK_OTHER_BYTES, wParam_1);
      v260 = ghWndTreeListView;
      v261 = (HWND)(unsigned __int8)v285;
      if ( v259 )
        v261 = (HWND)1;
      v262 = pItemParam->field_4F4;
      hWnd[1] = v261;
      v264 = *(_QWORD *)&pItemParam->field_4B0
           + *(_QWORD *)&pItemParam->field_4D0
           + __PAIR__(v262, pItemParam->field_4F0);
      v263 = v264 >> 32;
      v265 = __PAIR__(v263, (unsigned int)v264) != *(_QWORD *)&pItemParam->field_4F8;
      *(_QWORD *)&pItemParam->field_4F8 = __PAIR__(v263, (unsigned int)v264);
      v17 = RedrawColumn(v265, v260, IDS_DISK_DELTA_TOTAL_BYTES, wParam_1) == 0;
      v266 = (char)hWnd[1];
      fUsingWS = (std__Tree_node_for_process_some_information *)1;
      if ( !v17 )
        v266 = 1;
      LOBYTE(fUsingWS) = v266;
    }
  }
  return (int)fUsingWS;
}
// C5E0B6: inconsistent fpu stack
// CD4E54: using guessed type int gdwVersion;
// C5DF20: using guessed type unsigned __int64 ProcessorIdleCycleTime[256];

//----- (00C5F7C0) --------------------------------------------------------
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
  *(_DWORD *)&this->field_58 = 0;
  *(int *)((char *)&this->field_59 + 3) = 0;
  this->field_60 = 0;
  return result;
}

//----- (00C5F870) --------------------------------------------------------
char __usercall sub_C5F870@<al>(int a1@<ebx>, int a2, int a3, int a4, DWORD dwProcessId, int a6, int a7, int a8)
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
  tagDLLLISTITEMPARAM *v17; // esi
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
  DWORD pTimeDateStamp; // [esp+190h] [ebp-145Ch]
  wchar_t v69; // [esp+194h] [ebp-1458h]
  wchar_t Dst; // [esp+216h] [ebp-13D6h]
  DWORD dwLen; // [esp+298h] [ebp-1354h]
  WCHAR *ppszCopyright; // [esp+29Ch] [ebp-1350h]
  LPCWSTR lpFileName; // [esp+2A0h] [ebp-134Ch]
  wchar_t *v74; // [esp+2A4h] [ebp-1348h]
  struct _SYSTEMTIME SystemTime; // [esp+2D0h] [ebp-131Ch]
  __int16 Base; // [esp+2E0h] [ebp-130Ch]
  WCHAR DateStr; // [esp+12E0h] [ebp-30Ch]
  WCHAR TimeStr; // [esp+1360h] [ebp-28Ch]
  WCHAR FileName; // [esp+13E0h] [ebp-20Ch]

  hWnd = (HWND)a2;
  LOBYTE(a1) = 0;
  v36 = a4;
  v42 = (int *)a6;
  v37 = (wchar_t *)a7;
  v40 = dwProcessId;
  v38 = (_DWORD *)a8;
  v46 = a1;
  v8 = OpenProcess(0x410u, 0, dwProcessId);
  v44 = v8;
  if ( !v8 )
    return a1;
  v9 = VirtualQueryEx;
  Buffer.BaseAddress = 0;
  if ( !VirtualQueryEx(v8, 0, &Buffer, 0x1Cu) )
    goto LABEL_68;
  while ( !a3 || *(_BYTE *)a3 != 1 )
  {
    v10 = Buffer.RegionSize;
    v47 = 0;
    v43 = Buffer.RegionSize;
    v33.BaseAddress = (char *)Buffer.BaseAddress + Buffer.RegionSize;
    if ( v9(v8, (char *)Buffer.BaseAddress + Buffer.RegionSize, &v33, 0x1Cu) )
    {
      do
      {
        if ( v33.AllocationBase != Buffer.AllocationBase )
          break;
        v33.BaseAddress = (char *)v33.BaseAddress + v33.RegionSize;
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
      sub_C50DD0(&FileName);
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
          if ( (PVOID)v17->m_LoadAddress == Buffer.BaseAddress && v17->m_MappedSize == v10 )
          {
            v30 = &FileName;
            v29 = (WCHAR *)v17->m_strPath.pszData;
            if ( !_wcsicmp(v29, &FileName) )
              break;
          }
          v17 = v17->m_Prev;
          if ( !v17 )
            goto LABEL_33;
        }
        v30 = (WCHAR *)v17;
        ++*v38;
        v18 = sub_C68A20((int)v30);
        v19 = (unsigned __int8)v46;
        if ( v18 )
          v19 = 1;
        Buffer.BaseAddress = (char *)Buffer.BaseAddress + v10;
        v46 = v19;
        sub_C4C400(v42, v17);
        v16 = (char *)Buffer.BaseAddress;
        v9 = VirtualQueryEx;
        goto LABEL_66;
      }
LABEL_33:
      memset(&v56, 0, 0x188u);
      if ( v47 )
        v61 |= 8u;
      lpFileName = _wcsdup(&FileName);
      wcscpy_s(&Dst, 0x41u, (const wchar_t *)&gszNullString);
      v10 = v43;
      v60 = Buffer.BaseAddress;
      hObject = Buffer.Type == 0x1000000;
      v65 = v43;
      v66 = 1;
      v62 = 0;
      dwLen = 0;
      ppszCopyright = 0;
      PE_GetProductCopyright(&FileName, &Dst, 0x41u, (WCHAR **)&dwLen, &ppszCopyright);
      if ( Buffer.Type == 0x40000 )
        v61 |= 2u;
      wcscpy_s(&v69, 0x41u, (const wchar_t *)&gszNullString);
      v67 = 0i64;
      v20 = CreateFileW(&FileName, 0x80000000, 7u, 0, 3u, 0, 0);
      if ( v20 != (HANDLE)-1 )
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
        sub_C49DE0(&v69, L"%s %s", &DateStr, &TimeStr);
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
        sub_C278D0(hWnd, (wchar_t *)&v48);
LABEL_62:
        v9 = VirtualQueryEx;
LABEL_63:
        v8 = v44;
LABEL_64:
        v16 = (char *)Buffer.BaseAddress + v10;
        goto LABEL_65;
      }
      v62 = 0;
      if ( *(_DWORD *)ImageNtHeader )
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
                    v24 = (PVOID)v23->OptionalHeader.ImageBase;
                    goto LABEL_52;
                  }
                }
                else
                {
                  hObject = 2;
                  v62 = v21->OptionalHeader.ImageBase;
                  v24 = (PVOID)v21->OptionalHeader.ImageBase;
LABEL_52:
                  if ( v24 != Buffer.AllocationBase && Buffer.Type == 0x1000000 )
                    v61 |= 1u;
                }
              }
            }
          }
        }
      }
      sub_C4C400(v42, &v56);
      v28 = lpFileName;
      v58 = 0;
      v27 = *(wchar_t **)(v36 + 88);
      v74 = sub_C1BB70(v27, (wchar_t *)lpFileName);
      if ( gdwValue_4F10B8[1] == v40 )
      {
        v57 = 2;
      }
      else
      {
        v59 = 0;
        v57 = 0;
      }
      if ( Buffer.Type == 0x1000000 && PE_CheckExeFile(lpFileName, &pTimeDateStamp, (BOOL *)&hObject, &BaseAddress) )
        v61 |= 4u;
      qmemcpy(&v26, &v56, 0x188u);
      sub_C27790(hWnd, v26);
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
    v16 = (char *)Buffer.BaseAddress + v43;
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
// CD10B8: using guessed type int gdwValue_4F10B8[3];

//----- (00C5FFD0) --------------------------------------------------------
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
      if ( (unsigned __int16)a3 == 1 )
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
      v5 = (unsigned int)GetPropW(hWnd, L"Command");
      switch ( v5 )
      {
        case 0x4BA:
        case 0x4BF:
          if ( ServiceStatus.dwCurrentState != 1 )
            goto LABEL_9;
          if ( v5 != 1215 )
            goto LABEL_16;
          SetPropW(hWnd, L"Command", (HANDLE)0x4BD);
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
        v6 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
        SendMessageW(v12, 0x402u, 0x26u, 0);
      }
      else
      {
LABEL_9:
        v6 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
      }
      v7 = GetDlgItem(hWnd, 1316);
      v6(v7, 0x405u, 0, 0);
      v8 = GetDlgItem(hWnd, 1316);
      if ( ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))v6)(v8, 0x408u, 0, 0) == 40 )
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
  hData = (HANDLE)*(unsigned __int16 *)(a4 + 8);
  switch ( (unsigned int)hData )
  {
    case 0x4BAu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to stop the following service...");
      hService = (SC_HANDLE)32;
      break;
    case 0x4BBu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to resume the following service...");
      hService = (SC_HANDLE)64;
      break;
    case 0x4BCu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to pause the following service...");
      hService = (SC_HANDLE)64;
      break;
    case 0x4BDu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to start the following service...");
      hService = (SC_HANDLE)16;
      break;
    case 0x4BFu:
      SetDlgItemTextW(hWnd, 1314, L"Process Explorer is attempting to restart the following service...");
      hService = (SC_HANDLE)48;
      break;
    default:
      hService = hData;
      break;
  }
  v15 = GetDlgItem(hWnd, 1316);
  SendMessageW(v15, 0x401u, 0, 2621440);
  v16 = GetDlgItem(hWnd, 1316);
  SendMessageW(v16, 0x404u, 1u, 0);
  v17 = OpenServiceW(ghSCManagerHandle, *(LPCWSTR *)(a4 + 20), (unsigned int)hService | 5);
  hService = v17;
  if ( !v17 )
  {
    ReportMsg(L"Error opening service for control", ghMainWnd);
    EndDialog(hWnd, 0);
    return 0;
  }
  QueryServiceConfigW(v17, 0, 0, &pcbBytesNeeded);
  v18 = pcbBytesNeeded;
  v19 = (struct _QUERY_SERVICE_CONFIGW *)malloc(pcbBytesNeeded);
  v20 = v18;
  v21 = hService;
  QueryServiceConfigW(hService, v19, v20, &pcbBytesNeeded);
  SetDlgItemTextW(hWnd, 1315, v19->lpDisplayName);
  free(v19);
  v22 = hData;
  switch ( (unsigned int)hData )
  {
    case 0x4BAu:
    case 0x4BFu:
      v23 = (HANDLE)ControlService(v21, 1u, &ServiceStatus);
      break;
    case 0x4BBu:
      v23 = (HANDLE)ControlService(v21, 3u, &ServiceStatus);
      break;
    case 0x4BCu:
      v23 = (HANDLE)ControlService(v21, 2u, &ServiceStatus);
      break;
    case 0x4BDu:
      v23 = (HANDLE)StartServiceW(v21, 0, 0);
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

//----- (00C60400) --------------------------------------------------------
BOOL __cdecl sub_C60400(HWND hDlg, int nIDDlgItem, int ArgList, int a4)
{
  WCHAR String; // [esp+4h] [ebp-68h]

  sub_C49DA0(&String, L"%I64d", ArgList, a4);
  PE_GetNumberFormat(&String, 0x32u);
  return SetDlgItemTextW(hDlg, nIDDlgItem, &String);
}

//----- (00C60460) --------------------------------------------------------
BOOL __cdecl sub_C60460(HWND hDlg, int nIDDlgItem, int a3, int a4)
{
  WCHAR String; // [esp+4h] [ebp-68h]

  sub_C49DA0(&String, L"%I64d", __PAIR__(a4, a3) / 1024);
  PE_GetNumberFormat(&String, 0x32u);
  wcscat_s(&String, 0x32u, L" KB");
  return SetDlgItemTextW(hDlg, nIDDlgItem, &String);
}

//----- (00C604E0) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_C604E0(CResizer *this, int a2, int a3))(HWND hWnd, LPRECT lpRect)
{
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v4 = a2;
  v5 = a3;
  return sub_C60550(this, 2, (int)&v4);
}

//----- (00C60510) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_C60510(CResizer *this, int a2, int a3, int a4))(HWND hWnd, LPRECT lpRect)
{
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]

  v5 = a2;
  v6 = a3;
  v7 = a4;
  return sub_C60550(this, 3, (int)&v5);
}

//----- (00C60550) --------------------------------------------------------
BOOL (__stdcall *__thiscall sub_C60550(CResizer *this, int a2, int a3))(HWND hWnd, LPRECT lpRect)
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
  for ( i = 0.0; v4 < a2; i = (double)(Rect.bottom - Rect.top) + i )
  {
    result(*(HWND *)(a3 + 4 * v4++), &Rect);
    result = GetWindowRect;
  }
  for ( j = 0; j < a2; v10 = *(double *)&Rect.right )
  {
    result(*(HWND *)(a3 + 4 * j), &v11);
    *(double *)&Rect.right = (double)(v11.bottom - v11.top) / i + v10;
    v7 = (double)(v11.bottom - v11.top) / i + v10;
    if ( *(double *)&Rect.right >= 0.99999 )
      v7 = db_one;
    v6 = CResizer::AddItem(v8, *(HWND *)(a3 + 4 * j++), 1);
    *(double *)&v6->gap0[16] = v10;
    *(double *)&v6->gap0[24] = v7;
    result = GetWindowRect;
  }
  return result;
}

//----- (00C60640) --------------------------------------------------------
BOOL __stdcall sub_C60640(int a1, PVOID pApplicationAddress, DWORD BytesReturned, LPVOID lpOutBuffer, DWORD nOutBufferSize, DWORD *pcbRet)
{
  BOOL result; // eax
  DWORD v7; // esi
  int InBuffer[2]; // [esp+0h] [ebp-8h]

  if ( pApplicationAddress >= gSystemInfo.lpMaximumApplicationAddress )
  {
    v7 = nOutBufferSize;
    InBuffer[0] = dword_CDAB88;
    InBuffer[1] = (int)pApplicationAddress;
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
// CDAB88: using guessed type int dword_CDAB88;

//----- (00C606C0) --------------------------------------------------------
DWORD __cdecl PE_SuspendOneProcess(char bSuspended, SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo, int a3)
{
  SYSTEM_PROCESS_INFORMATION *v3; // esi
  HANDLE v4; // ebx
  DWORD result; // eax
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
  v4 = OpenProcess(PROCESS_SUSPEND_RESUME, 0, (DWORD)pSystemProcessInfo->UniqueProcessId);
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
  if ( (unsigned __int8)GetVersion() <= 4u )
  {
    bSmallStruct = 1;
    pInfo = (_SYSTEM_THREAD_INFORMATION *)&pSystemProcessInfo->ReadOperationCount;
  }
  else
  {
    pInfo = (_SYSTEM_THREAD_INFORMATION *)&pSystemProcessInfo[1];
  }
  NumberOfThreads = pSystemProcessInfo->NumberOfThreads;
  dwSuspendedCount = 0;
  v25 = 0;
  if ( NumberOfThreads )
  {
    v10 = (PUCHAR)&pInfo->WaitReason;
    dwNumberOfThreads = NumberOfThreads;
    v12 = (PUCHAR)&pInfo->ThreadState;
    do
    {
      if ( *(_DWORD *)v12 == Suspended && *(_DWORD *)v10 == Suspended )
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
    pThreadInfo = (_SYSTEM_THREAD_INFORMATION *)&pSystemProcessInfo->ReadOperationCount;
  else
    pThreadInfo = (_SYSTEM_THREAD_INFORMATION *)&pSystemProcessInfo[1];
  dwThreadIndex = 0;
  if ( NumberOfThreads )
  {
    pWaitReason = (PUCHAR)&pThreadInfo->WaitReason;
    pThreadState = (PUCHAR)&pThreadInfo->ThreadState;
    ThreadId = (PUCHAR)&pThreadInfo->ClientId.UniqueThread;
    v26 = ThreadId;
    while ( 1 )
    {
      ClientId.UniqueThread = *(void **)ThreadId;
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
    v18 = (ULONG *)hObject;
    if ( !hObject )
    {
LABEL_39:
      ThreadId = v26;
      goto LABEL_40;
    }
    if ( bSuspended )
    {
      if ( a3 && (a3 != 1 || *(_DWORD *)pThreadState == 5 && *(_DWORD *)pWaitReason == 5) )
        goto LABEL_38;
      NtSuspendThread(v17, (PULONG)hObject);
      if ( *(_DWORD *)pWaitReason == 5 || !v24 )
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
// C6076B: CONTAINING_RECORD: no field 'PUCHAR' in struct 'SYSTEM_THREAD_INFORMATION' at 64
// C6076E: CONTAINING_RECORD: no field 'PUCHAR' in struct 'SYSTEM_THREAD_INFORMATION' at 64

//----- (00C608B0) --------------------------------------------------------
DWORD64 __stdcall SymLoadModuleExW_0(HANDLE hProcess, HANDLE hFile, PCWSTR ImageName, PCWSTR ModuleName, DWORD64 BaseOfDll, DWORD DllSize, PMODLOAD_DATA Data, DWORD Flags)
{
  return SymLoadModuleExW(hProcess, hFile, ImageName, ModuleName, BaseOfDll, DllSize, 0, 0);
}

//----- (00C608E0) --------------------------------------------------------
int __stdcall sub_C608E0(int hProcess, int hFile, LPCWSTR a3, LPCWSTR lpWideCharStr, int BaseOfDll, int BaseOfDll_4, int SizeOfDll)
{
  CString *v7; // esi
  CString *v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // edx
  int v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]

  v7 = sub_C49E00(&v13, lpWideCharStr);
  v15 = 0;
  v8 = sub_C49E00(&v14, a3);
  LOBYTE(v15) = 1;
  v9 = SymLoadModule64(
         (HANDLE)hProcess,
         (HANDLE)hFile,
         v8->pszData,
         v7->pszData,
         __PAIR__(BaseOfDll_4, BaseOfDll),
         SizeOfDll);
  v10 = v14 - 16;
  LOBYTE(v15) = 0;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v14 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v10 + 4))(v10);
  v11 = v13 - 16;
  v15 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v13 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v11 + 4))(v11);
  return v9;
}

//----- (00C609B0) --------------------------------------------------------
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
          *(_DWORD *)(lParam + 8) = 2 * gdwVirtualScreenWidth;
          result = 0;
          break;
        case WM_INITDIALOG:
          v6 = GetWindowLongW(hWnd, -16);
          SetWindowLongW(hWnd, -16, v6 | 0x2000000);
          HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) = malloc(48 * gSystemInfo.dwNumberOfProcessors);
          v7 = malloc(24 * gSystemInfo.dwNumberOfProcessors);
          v8 = gdwLogicalProcessorInfoItemCount;
          LODWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) = v7;
          if ( (signed int)gdwLogicalProcessorInfoItemCount > 0 )
          {
            v9 = &gpLogicalProcessorInfo->Relationship;
            v10 = 0;
            do
            {
              if ( *v9 )
              {
                if ( *v9 == 3 )
                  v10 = (CResizer *)((char *)v10 + 1);
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
            v103 = (int)v100[1];
            NumberOfThreads = 0;
            pSystemProcessInfo = (SYSTEM_PROCESS_INFORMATION *)v100[1];
          }
          else
          {
            v11 = GetDlgItem(hWnd_1, 2000);
            GetWindowRect(v11, &Rect);
            v12 = gSystemInfo.dwNumberOfProcessors;
            if ( (signed int)gSystemInfo.dwNumberOfProcessors > 8 )
              v12 = 8 * ((signed int)gSystemInfo.dwNumberOfProcessors / 8 > 16) + 8;
            pSystemProcessInfo = (SYSTEM_PROCESS_INFORMATION *)((v12 + gSystemInfo.dwNumberOfProcessors - 1) / v12);
            v13 = 4;
            v14 = (signed int)(v12 * (_DWORD)pSystemProcessInfo - gSystemInfo.dwNumberOfProcessors) / -2 + v12;
            v103 = v14;
            if ( gSystemInfo.dwNumberOfProcessors > 0x10 )
              v13 = 3;
            v94 = v13;
            if ( gSystemInfo.dwNumberOfProcessors > 0x20 )
              v94 = --v13;
            v97 = (Rect.right - v13 * (v14 - 1) - Rect.left) / v103;
            nHeight = (Rect.bottom
                     - v13 * ((signed int)&pSystemProcessInfo[-1].OtherTransferCount.QuadPart + 7)
                     - Rect.top)
                    / (signed int)pSystemProcessInfo;
            v15 = GetDlgItem(hWnd_1, 2000);
            GetWindowRect(v15, &Rect);
            MapWindowPoints(0, hWnd_1, (LPPOINT)&Rect, 2u);
            v16 = (void *)Rect.left;
            v100[1] = (void *)Rect.left;
            v104 = 0;
            if ( (signed int)gSystemInfo.dwNumberOfProcessors > 0 )
            {
              v17 = 1;
              HIDWORD(v101) = 1;
              do
              {
                v93 = 0;
                v96 = v17 % v103;
                if ( !(v17 % v103) )
                  v93 = Rect.right - (_DWORD)v16 - v97;
                v18 = sub_C33F20(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, v17 - 1);
                v19 = (HMENU)(v17 + 2000);
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
                CreateGraphWindow(hWnd_2, (int)v19, gppGraphInfo[v20]);
                Rect.left += v97;
                v21 = sub_C33F20(gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, SHIDWORD(v101));
                if ( sub_C336B0((int)gpLogicalProcessorInfo, gdwLogicalProcessorInfoItemCount, v20, v21) )
                {
                  v16 = (void *)(Rect.left + 2);
                  v104 = v94 + v104 - 2;
                }
                else
                {
                  v16 = (void *)(v94 + v104 + Rect.left);
                  v104 = 0;
                }
                Rect.left = (LONG)v16;
                if ( !v96 )
                {
                  v16 = v100[1];
                  Rect.left = (LONG)v100[1];
                  Rect.top += nHeight + 2;
                }
                v17 = HIDWORD(v101) + 1;
                HIDWORD(v101) = v17;
              }
              while ( v17 - 1 < (signed int)gSystemInfo.dwNumberOfProcessors );
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
          v25 = (CResizer *)operator new(0x40u);
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
            *(_QWORD *)v28->gap0 = 0i64;
            *(double *)&v28->gap0[8] = db_one;
          }
          v29 = GetDlgItem(hWnd_1, 1114);
          if ( v29 )
          {
            v30 = CResizer::AddItem(pResizer, v29, 1);
            v31 = db_one;
            *(_QWORD *)v30->gap0 = 0i64;
            *(double *)&v30->gap0[8] = db_one;
          }
          else
          {
            v31 = db_one;
          }
          SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
          if ( gSystemInfo.dwNumberOfProcessors <= 1 )
          {
            v39 = GetDlgItem(hWnd_1, 1301);
            ShowWindow(v39, 0);
          }
          else
          {
            *(double *)v100 = 0.0;
            v95 = 0.0;
            if ( (signed int)gSystemInfo.dwNumberOfProcessors > 0 )
            {
              v33 = 2001;
              v92 = v31 / (double)v103;
              v90 = v31 / (double)(signed int)pSystemProcessInfo;
              do
              {
                v34 = GetDlgItem(hWnd_1, v33);
                v101 = v90 + v95;
                if ( v90 + v95 >= 0.99999 )
                  v101 = db_one;
                v35 = CResizer::AddItem(NumberOfThreads, v34, 1);
                *(double *)&v35->gap0[16] = v95;
                *(double *)&v35->gap0[24] = v101;
                v36 = GetDlgItem(hWnd_1, v33);
                v37 = *(double *)v100 + v92;
                v99 = *(double *)v100 + v92;
                v101 = *(double *)v100 + v92;
                if ( *(double *)v100 + v92 >= 0.99999 )
                  v101 = db_one;
                if ( v36 )
                {
                  v38 = (double *)CResizer::AddItem(NumberOfThreads, v36, 1);
                  *v38 = *(double *)v100;
                  v38[1] = v101;
                  v37 = v99;
                }
                *(double *)v100 = v37;
                if ( !((v33 - 2000) % v103) )
                {
                  *(double *)v100 = 0.0;
                  v95 = v90 + v95;
                }
                ++v33;
              }
              while ( v33 - 2001 < (signed int)gSystemInfo.dwNumberOfProcessors );
              SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
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
          if ( (_WORD)wParam != 1301 || wParam >> 16 )
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
            (PVOID)HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold),
            48 * gSystemInfo.dwNumberOfProcessors,
            &ReturnLength);
          NtQuerySystemInformation(
            SystemInterruptInformation,
            (PVOID)gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages,
            24 * gSystemInfo.dwNumberOfProcessors,
            &ReturnLength);
          nCount = 1;
          pSystemProcessInfo_1 = pSystemProcessInfo;
          HandleCount = pSystemProcessInfo->HandleCount;
          NumberOfThreads = (CResizer *)pSystemProcessInfo->NumberOfThreads;
          HIDWORD(v101) = HandleCount;
          v44 = pSystemProcessInfo->NextEntryOffset;
          if ( pSystemProcessInfo->NextEntryOffset )
          {
            v45 = NumberOfThreads;
            do
            {
              HandleCount += *(ULONG *)((char *)&pSystemProcessInfo_1->HandleCount + v44);
              pSystemProcessInfo_1 = (SYSTEM_PROCESS_INFORMATION *)((char *)pSystemProcessInfo_1 + v44);
              ++nCount;
              v45 = (CResizer *)((char *)v45 + pSystemProcessInfo_1->NumberOfThreads);
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
              v57 = _mm_cvtsi32_si128(*(_DWORD *)(v56 + 48));
              v56 += 384;
              v53 += 192;
              v49 += 8;
              v51 = _mm_add_epi32(
                      v51,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(
                          _mm_cvtsi32_si128(*(_DWORD *)(v56 - 480)),
                          _mm_cvtsi32_si128(*(_DWORD *)(v56 - 384))),
                        _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v56 - 432)), v57)));
              v52 = _mm_add_epi32(
                      v52,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 240)),
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 192))),
                        _mm_unpacklo_epi32(
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 216)),
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 168)))));
              v54 = _mm_add_epi32(
                      v54,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(
                          _mm_cvtsi32_si128(*(_DWORD *)(v56 - 288)),
                          _mm_cvtsi32_si128(*(_DWORD *)(v56 - 192))),
                        _mm_unpacklo_epi32(
                          _mm_cvtsi32_si128(*(_DWORD *)(v56 - 240)),
                          _mm_cvtsi32_si128(*(_DWORD *)(v56 - 144)))));
              v55 = _mm_add_epi32(
                      v55,
                      _mm_unpacklo_epi32(
                        _mm_unpacklo_epi32(
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 144)),
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 96))),
                        _mm_unpacklo_epi32(
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 120)),
                          _mm_cvtsi32_si128(*(_DWORD *)(v53 - 72)))));
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
            v71 = (char *)v103;
          }
          else
          {
            if ( v50 - v49 >= 2 )
            {
              v64 = 0;
              v65 = LODWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) + 24 * v49 + 4;
              v66 = (_DWORD *)(HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) + 40 + 48 * v49);
              v67 = ((gSystemInfo.dwNumberOfProcessors - v49 - 2) >> 1) + 1;
              v100[1] = (void *)(v49 + 2 * v67);
              v68 = 0;
              do
              {
                v64 = (SYSTEM_PROCESS_INFORMATION *)((char *)v64 + *v66);
                v66 += 24;
                v68 += *(v66 - 12);
                v65 += 48;
                pSystemProcessInfo = v64;
                NumberOfThreads = (CResizer *)((char *)NumberOfThreads + *(_DWORD *)(v65 - 48));
                HIDWORD(v99) += *(_DWORD *)(v65 - 24);
                --v67;
              }
              while ( v67 );
              hWnd_1 = hWnd_2;
              v62 = pSystemProcessInfo;
              v69 = v68;
              v49 = (DWORD)v100[1];
              v63 = v69;
            }
            if ( v49 >= gSystemInfo.dwNumberOfProcessors )
            {
              v70 = v103;
            }
            else
            {
              v104 += *(_DWORD *)(HIDWORD(gSystenPerformanceInfoInProcSecurity.CcDirtyPageThreshold) + 48 * v49 + 40);
              hWnd_1 = hWnd_2;
              v70 = *(_DWORD *)(LODWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) + 24 * v49 + 4) + v103;
              v62 = pSystemProcessInfo;
            }
            v104 += (int)v62 + v63;
            v71 = (char *)NumberOfThreads + HIDWORD(v99) + v70;
            v103 = (int)v71;
          }
          swprintf(szText, L"%u", v108 - gSystenPerformanceInfoInProcSecurity.ContextSwitches);
          PE_GetNumberFormat(szText, 0x104u);
          SetDlgItemTextW(hWnd_1, 1082, szText);
          if ( HIDWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages) )
            v72 = (int)&v71[-HIDWORD(gSystenPerformanceInfoInProcSecurity.CcTotalDirtyPages)];
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
          if ( (signed int)gSystemInfo.dwNumberOfProcessors <= 0 )
            return 0;
          do
          {
            v82 = GetDlgItem(v74, v81 + 2001);
            ::SendMessageW(v82, 0x400u, 0, 0);
            ++v81;
          }
          while ( v81 < (signed int)gSystemInfo.dwNumberOfProcessors );
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    }
    return PE_FillControl((int)hWnd, (HDC)wParam);
  }
  if ( uMsg == 310 || uMsg == 312 )
    return PE_FillControl((int)hWnd, (HDC)wParam);
  if ( uMsg == 1124 )
  {
    v83 = 5;
    if ( gConfig.bShowAllCpus )
      v83 = 0;
    v84 = v83;
    v85 = GetDlgItem(hWnd, 2000);
    ShowWindow(v85, v84);
    for ( i = 1; i < (signed int)(gSystemInfo.dwNumberOfProcessors + 1); ++i )
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
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C618B0) --------------------------------------------------------
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
        *(_DWORD *)(lParam + 8) = 2 * gdwVirtualScreenWidth;
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
        v8 = (CResizer *)operator new(0x40u);
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
          *(_QWORD *)v11->gap0 = 0i64;
          *(double *)&v11->gap0[8] = db_one;
        }
        v12 = GetDlgItem(hDlg, 1649);
        if ( v12 )
        {
          v13 = CResizer::AddItem(v9, v12, 1);
          *(_QWORD *)v13->gap0 = 0i64;
          *(double *)&v13->gap0[8] = db_one;
        }
        v14 = GetDlgItem(hDlg, 2601);
        if ( v14 )
        {
          v15 = CResizer::AddItem(v9, v14, 1);
          *(_QWORD *)v15->gap0 = 0i64;
          *(double *)&v15->gap0[8] = db_one;
        }
        v16 = GetDlgItem(hDlg, 1115);
        if ( v16 )
        {
          v17 = CResizer::AddItem(v9, v16, 1);
          *(_QWORD *)v17->gap0 = 0i64;
          *(double *)&v17->gap0[8] = db_one;
        }
        v18 = GetDlgItem(hDlg, 2602);
        if ( v18 )
        {
          v19 = CResizer::AddItem(v9, v18, 1);
          *(_QWORD *)v19->gap0 = 0i64;
          *(double *)&v19->gap0[8] = db_one;
        }
        v20 = GetDlgItem(hDlg, 1116);
        if ( v20 )
        {
          v21 = CResizer::AddItem(v9, v20, 1);
          *(_QWORD *)v21->gap0 = 0i64;
          *(double *)&v21->gap0[8] = db_one;
        }
        v22 = GetDlgItem(hDlg, 1161);
        v23 = GetDlgItem(hDlg, 1159);
        v24 = GetDlgItem(hDlg, 1157);
        sub_C60510(v9, (int)v24, (int)v23, (int)v22);
        v25 = GetDlgItem(hDlg, 1162);
        v26 = GetDlgItem(hDlg, 1160);
        v27 = GetDlgItem(hDlg, 1651);
        sub_C60510(v9, (int)v27, (int)v26, (int)v25);
        v28 = GetDlgItem(hDlg, 2602);
        v29 = GetDlgItem(hDlg, 2601);
        v30 = GetDlgItem(hDlg, 2501);
        sub_C60510(v9, (int)v30, (int)v29, (int)v28);
        v31 = GetDlgItem(hDlg, 1157);
        *(double *)&CResizer::AddItem(v9, v31, 1)->gap0[24] = db_four;
        v32 = GetDlgItem(hDlg, 1159);
        *(double *)&CResizer::AddItem(v9, v32, 1)->gap0[24] = db_four;
        v33 = GetDlgItem(hDlg, 1161);
        *(double *)&CResizer::AddItem(v9, v33, 1)->gap0[24] = db_four;
        v34 = GetDlgItem(hDlg, 1210);
        if ( v34 )
          *(_OWORD *)CResizer::AddItem(v9, v34, 1)->gap0 = 0i64;
        if ( gdwAdapterRuntingTime <= 1 )
        {
          v35 = GetDlgItem(hDlg, 1648);
          ShowWindow(v35, 0);
        }
        PropSheet_UpdateTab(hDlg);
        SendMessageW(hDlg, 0x113u, 0, 0);
        return 1;
      case 0x111u:
        if ( (unsigned __int16)wParam == 1210 )
        {
          DialogBoxParamW(ghMainInstance, L"SYSTEMINFOGPUNODES", hDlg, DlgSystemInfoGPUNodes, 0);
          return 0;
        }
        if ( (unsigned __int16)wParam == 1648 && !(wParam >> 16) )
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
        GraphData_QueryData(gpGraphInfoOfSystemMemory, (double *)v56, 0);
        wsprintf(&Dst, L"%u", (signed int)*(double *)v56);
        v45 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1104, v45);
        wsprintf(&Dst, L"%u", (signed int)gpGraphInfoOfSystemMemory->m_dbMemorySize);
        v46 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1105, v46);
        GraphData_QueryData(gpGraphInfoOfDedicatedMemory, (double *)v56, 0);
        wsprintf(&Dst, L"%d", (signed int)*(double *)v56);
        v47 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1660, v47);
        wsprintf(&Dst, L"%d", (signed int)gpGraphInfoOfDedicatedMemory->m_dbMemorySize);
        v48 = PE_GetNumberFormat(&Dst, 0x100u);
        SetDlgItemTextW(hDlg, 1661, v48);
        return 0;
      default:
        return 0;
    }
    return 0;
  }
  return PE_FillControl((int)hDlg, (HDC)wParam);
}
// CACB38: using guessed type double db_four;
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C62010) --------------------------------------------------------
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

  if ( (unsigned int)a2 > 0x133 )
  {
    if ( a2 != 310 && a2 != 312 )
      return 0;
    return PE_FillControl((int)hDlg, hdc);
  }
  if ( a2 == 307 )
    return PE_FillControl((int)hDlg, hdc);
  if ( a2 == 36 )
  {
    *(_DWORD *)(a4 + 8) = 2 * gdwVirtualScreenWidth;
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 275 )
    {
      NtQuerySystemInformation(SystemPerformanceInformation, &SystemInformation, 0x138u, &ReturnLength);
      sub_C60400(hDlg, 1176, v31 - dword_CF53A8, 0);
      sub_C60460(hDlg, 1190, v28 - qword_CF5390, (unsigned __int64)(v28 - qword_CF5390) >> 32);
      sub_C60400(hDlg, 1177, v32 - dword_CF53AC, 0);
      sub_C60460(hDlg, 1192, v29 - qword_CF5398, (unsigned __int64)(v29 - qword_CF5398) >> 32);
      sub_C60400(hDlg, 1178, v33 - dword_CF53B0, 0);
      sub_C60460(hDlg, 1194, v30 - qword_CF53A0, (unsigned __int64)(v30 - qword_CF53A0) >> 32);
      qmemcpy(&unk_CF5388, &SystemInformation, 0x138u);
      sub_C60400(hDlg, 1180, gTreeList_Item[1].field_10, 0);
      sub_C60460(hDlg, 1196, gTreeList_Item[1].field_38, gTreeList_Item[1].field_3C);
      sub_C60400(hDlg, 1181, gTreeList_Item[1].field_C, 0);
      sub_C60460(hDlg, 1198, gTreeList_Item[1].field_30, gTreeList_Item[1].field_34);
      sub_C60400(hDlg, 1182, gTreeList_Item[1].field_14, 0);
      sub_C60460(hDlg, 1200, gTreeList_Item[1].field_40, gTreeList_Item[1].field_44);
      sub_C60400(hDlg, 1186, gTreeList_Item[2].field_10, 0);
      sub_C60460(hDlg, 1202, gTreeList_Item[2].field_38, gTreeList_Item[2].field_3C);
      sub_C60400(hDlg, 1187, gTreeList_Item[2].field_C, 0);
      sub_C60460(hDlg, 1204, gTreeList_Item[2].field_30, gTreeList_Item[2].field_34);
      sub_C60400(hDlg, 1188, gTreeList_Item[2].field_14, 0);
      sub_C60460(hDlg, 1206, gTreeList_Item[2].field_40, gTreeList_Item[2].field_44);
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
  v12 = (CResizer *)operator new(0x40u);
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
    sub_C60550(v26, 3, (int)&v34);
    v16 = GetDlgItem(hDlg, 1336);
    v17 = GetDlgItem(hDlg, 1352);
    v34 = GetDlgItem(hDlg, 1331);
    v35 = v17;
    v36 = v16;
    sub_C60550(v26, 3, (int)&v34);
    v18 = GetDlgItem(hDlg, 1337);
    v19 = GetDlgItem(hDlg, 1351);
    v34 = GetDlgItem(hDlg, 1332);
    v35 = v19;
    v20 = v26;
    v36 = v18;
    sub_C60550(v26, 3, (int)&v34);
    v21 = GetDlgItem(hDlg, 1183);
    if ( v21 )
      *(_OWORD *)CResizer::AddItem(v26, v21, 1)->gap0 = 0i64;
    v22 = GetDlgItem(hDlg, 1331);
    *(double *)&CResizer::AddItem(v20, v22, 1)->gap0[24] = db_four;
    v23 = GetDlgItem(hDlg, 1352);
    *(double *)&CResizer::AddItem(v20, v23, 1)->gap0[24] = db_four;
    v24 = GetDlgItem(hDlg, 1336);
    *(double *)&CResizer::AddItem(v20, v24, 1)->gap0[24] = db_four;
  }
  else
  {
    v13->m_nXRatio = 93;
    v13->m_nYRatio = 20;
  }
  PropSheet_UpdateTab(hDlg);
  NtQuerySystemInformation(SystemPerformanceInformation, &unk_CF5388, 0x138u, &ReturnLength);
  SendMessageW(hDlg, 0x113u, 0, 0);
  return 1;
}
// CACB38: using guessed type double db_four;
// CD4E28: using guessed type int gdwVirtualScreenWidth;
// CF5390: using guessed type __int64 qword_CF5390;
// CF5398: using guessed type __int64 qword_CF5398;
// CF53A0: using guessed type __int64 qword_CF53A0;
// CF53A8: using guessed type int dword_CF53A8;
// CF53AC: using guessed type int dword_CF53AC;
// CF53B0: using guessed type int dword_CF53B0;

//----- (00C625E0) --------------------------------------------------------
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
  if ( (unsigned int)a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl((int)hWnd, hdc);
    return 0;
  }
  if ( a2 != 275 )
  {
    switch ( a2 )
    {
      case 36:
        *(_DWORD *)(a4 + 8) = 2 * gdwVirtualScreenWidth;
        return 0;
      case 256:
        if ( hdc == (HDC)116 )
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
        v11 = (CResizer *)operator new(0x40u);
        v54 = v11;
        v84 = 0;
        if ( v11 )
        {
          v12 = CResizer::CResizer(v11, hWnd);
          hDlg = (HWND)v12;
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
          *(_QWORD *)v14->gap0 = 0i64;
          *(double *)&v14->gap0[8] = db_one;
        }
        v15 = GetDlgItem(hWnd, 1333);
        if ( v15 )
        {
          v16 = CResizer::AddItem(v12, v15, 1);
          *(_QWORD *)v16->gap0 = 0i64;
          *(double *)&v16->gap0[8] = db_one;
        }
        v17 = GetDlgItem(hWnd, 1333);
        v53 = GetDlgItem(hWnd, 1159);
        v54 = v17;
        sub_C60550((CResizer *)hDlg, 2, (int)&v53);
        v18 = GetDlgItem(hWnd, 1334);
        v53 = GetDlgItem(hWnd, 1160);
        v54 = v18;
        sub_C60550((CResizer *)hDlg, 2, (int)&v53);
        v19 = GetDlgItem(hWnd, 1637);
        v53 = GetDlgItem(hWnd, 1161);
        v54 = v19;
        v20 = (CResizer *)hDlg;
        sub_C60550((CResizer *)hDlg, 2, (int)&v53);
        v21 = GetDlgItem(hWnd, 1160);
        *(double *)&CResizer::AddItem(v20, v21, 1)->gap0[24] = db_four;
        v22 = GetDlgItem(hWnd, 1334);
        *(double *)&CResizer::AddItem(v20, v22, 1)->gap0[24] = db_four;
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
  sub_C4CE20((DWORD)&qword_CF5378, &qword_CF5380);
  NtQuerySystemInformation(SystemPerformanceInformation, &SystemInformation, 0x138u, &ReturnLength);
  v82 = 0;
  _mm_storeu_si128((__m128i *)v80, (__m128i)0i64);
  _mm_storeu_si128((__m128i *)&v81, (__m128i)0i64);
  NtQuerySystemInformation(SystemFileCacheInformation, v80, 0x24u, &ReturnLength);
  memset(&v74, 0, 0x58u);
  NtQuerySystemInformation(SystemMemoryListInformation, &v74, 0x58u, &ReturnLength);
  swprintf(&String, L"%d", v61 * (gSystemInfo.dwPageSize >> 10));
  v24 = PE_GetNumberFormat(&String, 0x104u);
  v25 = (void (__stdcall *)(HWND, int, LPCWSTR))SetDlgItemTextW;
  SetDlgItemTextW(hWnd, 1103, v24);
  ArgList = (double)v60 * 100.0 / (double)v61;
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
  ArgLista = (double)v62 * 100.0 / (double)v61;
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
    v54 = (void *)(DWORD1(v81) * v29);
  else
    v54 = (void *)(v29 * (v71 + v70 + v72 + v69));
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
      v40 = (char *)v54 + v78[v38++];
      v54 = v40;
    }
    while ( v38 < 8 );
    swprintf(&String, L"%u", (_DWORD)v40 * (gSystemInfo.dwPageSize >> 10));
    v41 = PE_GetNumberFormat(&String, 0x104u);
    v25 = (void (__stdcall *)(HWND, int, LPCWSTR))SetDlgItemTextW;
    SetDlgItemTextW(hWnd, 1117, v41);
    if ( gdwVersion >= 3 )
    {
      swprintf(&String, L"%u", v79 * (gSystemInfo.dwPageSize >> 10));
      v42 = PE_GetNumberFormat(&String, 0x104u);
      SetDlgItemTextW(hWnd, 1663, v42);
    }
  }
  if ( qword_CF5378 )
  {
    swprintf(&String, L"%I64u", (unsigned __int64)qword_CF5378 >> 10);
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
  if ( qword_CF5380 )
  {
    swprintf(&String, L"%I64u", (unsigned __int64)qword_CF5380 >> 10);
    PE_GetNumberFormat(&String, 0x104u);
    v25(hWnd, 1664, &String);
  }
  swprintf(&String, L"%u", v63 - dword_CF527C);
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1171, &String);
  swprintf(&String, L"%u", v64 - dword_CF5294);
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1172, &String);
  swprintf(&String, L"%u", v65 - dword_CF52A0);
  PE_GetNumberFormat(&String, 0x104u);
  v25(hWnd, 1173, &String);
  swprintf(&String, L"%u", v66 - dword_CF52A8);
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
// CACB38: using guessed type double db_four;
// CACDC0: using guessed type double db_onehundred;
// CB67B8: using guessed type wchar_t a022f_0[9];
// CD4E28: using guessed type int gdwVirtualScreenWidth;
// CD4E54: using guessed type int gdwVersion;
// CDF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);
// CF527C: using guessed type int dword_CF527C;
// CF5294: using guessed type int dword_CF5294;
// CF52A0: using guessed type int dword_CF52A0;
// CF52A8: using guessed type int dword_CF52A8;
// CF5378: using guessed type __int64 qword_CF5378;
// CF5380: using guessed type __int64 qword_CF5380;
// C625E0: using guessed type int var_280[16];

//----- (00C63260) --------------------------------------------------------
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

  if ( (unsigned int)a2 > 0x133 )
  {
    if ( a2 != 310 && a2 != 312 )
      return 0;
    return PE_FillControl((int)hDlg, hdc);
  }
  if ( a2 == 307 )
    return PE_FillControl((int)hDlg, hdc);
  if ( a2 == 36 )
  {
    *(_DWORD *)(a4 + 8) = 2 * gdwVirtualScreenWidth;
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
  v22 = (CResizer *)operator new(0x40u);
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
    *(_QWORD *)v25->gap0 = 0i64;
    *(double *)&v25->gap0[8] = db_one;
  }
  v26 = GetDlgItem(hDlg, 1114);
  if ( v26 )
  {
    v27 = CResizer::AddItem(v23, v26, 1);
    *(_QWORD *)v27->gap0 = 0i64;
    *(double *)&v27->gap0[8] = db_one;
  }
  v28 = GetDlgItem(hDlg, 1159);
  if ( v28 )
  {
    v29 = CResizer::AddItem(v23, v28, 1);
    *(_QWORD *)v29->gap0 = 0i64;
    *(double *)&v29->gap0[8] = db_one;
  }
  v30 = GetDlgItem(hDlg, 1333);
  if ( v30 )
  {
    v31 = CResizer::AddItem(v23, v30, 1);
    *(_QWORD *)v31->gap0 = 0i64;
    *(double *)&v31->gap0[8] = db_one;
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
    sub_C60550(v65, 6, (int)&v66);
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
    sub_C60550(v65, 6, (int)&v66);
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
    sub_C60550(v65, 6, (int)&v66);
    v48 = hDlg;
    v49 = GetDlgItem;
    v50 = GetDlgItem(hDlg, 1352);
    *(double *)&CResizer::AddItem(v65, v50, 1)->gap0[24] = db_four;
    v51 = GetDlgItem(hDlg, 1336);
    *(double *)&CResizer::AddItem(v65, v51, 1)->gap0[24] = db_four;
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
    sub_C60550(v65, 4, (int)&v68);
    v55 = GetDlgItem(hDlg, 1331);
    v56 = GetDlgItem(hDlg, 1334);
    v57 = GetDlgItem(hDlg, 1160);
    v68 = GetDlgItem(hDlg, 1157);
    v69 = v57;
    v70 = v56;
    v71 = v55;
    sub_C60550(v65, 4, (int)&v68);
    v58 = GetDlgItem(hDlg, 1332);
    v59 = GetDlgItem(hDlg, 1637);
    v60 = GetDlgItem(hDlg, 1161);
    v68 = GetDlgItem(hDlg, 1158);
    v70 = v59;
    v47 = v65;
    v69 = v60;
    v71 = v58;
    sub_C60550(v65, 4, (int)&v68);
    v48 = hDlg;
    v49 = GetDlgItem;
  }
  v61 = v49(v48, 1157);
  *(double *)&CResizer::AddItem(v47, v61, 1)->gap0[24] = db_four;
  v62 = v49(v48, 1160);
  *(double *)&CResizer::AddItem(v47, v62, 1)->gap0[24] = db_four;
  v63 = v49(v48, 1334);
  *(double *)&CResizer::AddItem(v47, v63, 1)->gap0[24] = db_four;
  v64 = v49(v48, 1331);
  *(double *)&CResizer::AddItem(v47, v64, 1)->gap0[24] = db_four;
  PropSheet_UpdateTab(v48);
  SendMessageW(v48, 0x113u, 0, 0);
  return 1;
}
// CACB38: using guessed type double db_four;
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C639C0) --------------------------------------------------------
_DWORD *__cdecl sub_C639C0(SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo, DWORD dwProcessId)
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
        pInfo = (PE_SYSTEM_HANDLE_TABLE_ENTRY_INFO *)ObjectTypeIndex;
      }
      else
      {
        pInfo = &stru_CEBC0C;
        stru_CEBC0C.field_10 = *((_WORD *)GrantedAccess - 5);
        stru_CEBC0C.GrantedAccess = *GrantedAccess;
        LOBYTE(stru_CEBC0C.field_14) = *((_BYTE *)GrantedAccess - 7);
        stru_CEBC0C.Object = (PVOID)*((unsigned __int16 *)GrantedAccess - 3);
        *(_DWORD *)&stru_CEBC0C.field_0 = *(GrantedAccess - 1);
        *(&stru_CEBC0C.field_10 + 1) = *((unsigned __int8 *)GrantedAccess - 8);
        *(_DWORD *)&stru_CEBC0C.ObjectTypeIndex = *((unsigned __int16 *)GrantedAccess - 6);
      }
      if ( *(_DWORD *)&pInfo->ObjectTypeIndex == dwProcessId
        && !_wcsicmp(&gpszObjectTypeNames[0x40 * *((unsigned __int16 *)&pInfo->field_10 + 1)], L"File")
        && sub_C4C4F0((tagHandleTableEntryInfo *)pInfo, (int)&a2, (int)&a3, (int)&a4) )
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
    while ( v6 < (unsigned int)SystemHandleInfo_GetHandlesNumber(pSystemHandleInfo) );
  }
  sub_C4C4F0(0, 0, 0, 0);
  return v12;
}
// CDABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// CEBC0C: using guessed type PE_SYSTEM_HANDLE_TABLE_ENTRY_INFO stru_CEBC0C;

//----- (00C63AF0) --------------------------------------------------------
BOOL __stdcall DlgThreadStack(HWND hWnd, UINT uMsg, WPARAM a3, LPARAM a4)
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
  if ( uMsg > WM_COMMAND )
  {
    if ( uMsg == 2033 )
    {
      GetWindowRect(hWnd, &Rect);
      nWidth = Rect.right - Rect.left;
      nHeight = Rect.bottom - Rect.top;
      DestroyWindow(hWnd);
    }
    return 0;
  }
  if ( uMsg == WM_COMMAND )
  {
    if ( (unsigned __int16)a3 > (signed int)IDC_THREADSTACK_BUTTON_COPY_ALL )
    {
      if ( (unsigned __int16)a3 == 40631 )
      {
        v23 = 0;
        v24 = GetDlgItem(hWnd, IDC_THREADSTACK_LIST);
        if ( SendMessageW(v24, LVM_GETITEMCOUNT, 0, 0) > 0 )
        {
          do
          {
            lParam.stateMask = 2;
            lParam.state = 2;
            SendMessageW(v24, LVM_SETITEMSTATE, v23++, (LPARAM)&lParam);
          }
          while ( v23 < SendMessageW(v24, LVM_GETITEMCOUNT, 0, 0) );
        }
      }
    }
    else if ( (unsigned __int16)a3 == IDC_THREADSTACK_BUTTON_COPY_ALL )
    {
      v16 = 0;
      v17 = GetDlgItem(hWnd, IDC_THREADSTACK_LIST);
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
          SendMessageW(v31, LVM_GETITEMTEXTW, v18, (LPARAM)&lParam);
          v21 = wcslen(&Src) + v16 + 2;
          v29 = v21;
          if ( v20 )
          {
            v19 = GlobalReAlloc(v19, 2 * v21 + 2, 0);
            v20 = (wchar_t *)GlobalLock(v19);
          }
          else
          {
            v19 = GlobalAlloc(0x2002u, 2 * v21 + 2);
            v20 = (wchar_t *)GlobalLock(v19);
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
        v4 = (HWND)hMem;
      }
      if ( OpenClipboard(v4) )
      {
        EmptyClipboard();
        SetClipboardData(0xDu, v19);
        CloseClipboard();
      }
      SetFocus(v31);
    }
    else if ( (unsigned int)(unsigned __int16)a3 - 1 <= 1 )
    {
      ghWndThreadStack = 0;
      EndDialog(hWnd, 0);
    }
    return 0;
  }
  if ( uMsg == WM_NOTIFY )
  {
    v12 = *(_DWORD *)(a4 + 8);
    if ( v12 == LVN_ITEMCHANGED || (unsigned int)(v12 + 3) <= 1 )
    {
      v13 = GetDlgItem(hWnd, IDC_THREADSTACK_LIST);
      if ( SendMessageW(v13, LVM_GETNEXTITEM, 0xFFFFFFFF, 2) == -1 )
      {
        v15 = GetDlgItem(hWnd, IDC_THREADSTACK_BUTTON_COPY_ALL);
        EnableWindow(v15, 0);
      }
      else
      {
        v14 = GetDlgItem(hWnd, IDC_THREADSTACK_BUTTON_COPY_ALL);
        EnableWindow(v14, 1);
      }
    }
    return 0;
  }
  if ( uMsg != WM_INITDIALOG )
    return 0;
  v5 = LoadIconW(ghInstance, (LPCWSTR)0x65);
  SendMessageW(hWnd, WM_SETICON, 0, (LPARAM)v5);
  v6 = (CResizer *)operator new(0x40u);
  hMem = v6;
  v35 = 0;
  if ( v6 )
    CResizer::CResizer(v6, hWnd);
  v35 = -1;
  v7 = GetDlgItem(hWnd, IDC_THREADSTACK_LIST);
  ProcPageInitList(v7, 2, &pnIDs, pnWidths, 0);
  v8 = (tagTREEVIEWLISTITEMPARAM **)wParam;
  v9 = GetDlgItem(hWnd, IDC_THREADSTACK_LIST);
  sub_C4B490(v9, v8);
  SendMessageW(v7, LVM_SETCOLUMNWIDTH, 0, 0xFFFF);
  SendMessageW(v7, LVM_SETCOLUMNWIDTH, 1u, 0xFFFF);
  lParam.stateMask = 3;
  lParam.state = 3;
  SendMessageW(v7, LVM_SETITEMSTATE, 0, (LPARAM)&lParam);
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

//----- (00C63FC0) --------------------------------------------------------
BOOL __userpurge DlgThreadStack@<eax>(__int128 a1@<xmm0>, HWND hWnd, UINT uMsg, WPARAM a3, LPARAM dwNewLong)
{
  int v5; // edi
  HICON v6; // eax
  HWND v7; // esi
  CResizer *v8; // eax
  HWND v9; // esi
  LONG v10; // eax
  HWND v11; // eax
  HWND v12; // esi
  HWND v13; // eax
  int v15; // eax
  HWND v16; // ebx
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  HWND v20; // ebx
  HWND v21; // eax
  HWND v22; // ebx
  MixedModeStackWalker *v23; // esi
  wchar_t *v24; // ebx
  HWND v25; // eax
  LRESULT v26; // eax
  void *v27; // edi
  unsigned int v28; // esi
  rsize_t v29; // esi
  LRESULT v30; // esi
  HWND v31; // edi
  MixedModeStackWalker *v32; // esi
  wchar_t *v33; // ebx
  HWND v34; // eax
  LRESULT v35; // eax
  unsigned int v36; // esi
  rsize_t v37; // esi
  HANDLE v38; // ecx
  HWND v39; // ebx
  HWND v40; // eax
  HWND v41; // eax
  LPCONTEXT pContext; // esi
  MixedModeStackWalker *v43; // eax
  MixedModeStackWalker *pMixedModeStackWalker1; // ebx
  void *v45; // ecx
  int v46; // edx
  bool v47; // cf
  _DWORD *v48; // esi
  int v49; // eax
  int v50; // ST28_4
  HWND v51; // edi
  int v52; // eax
  int i; // eax
  int v54; // eax
  int v55; // ebx
  signed int v56; // edi
  PULONG *v57; // esi
  void *v58; // ecx
  ULONG *v59; // eax
  LPCONTEXT v60; // ecx
  PULONG v61; // eax
  CONTEXT *v62; // ebx
  signed int v63; // esi
  void *v64; // ecx
  ULONG *v65; // eax
  HWND v66; // esi
  HWND v67; // eax
  HWND v68; // eax
  DWORD v69; // eax
  signed int v70; // esi
  unsigned int *v71; // ST20_4
  int v72; // eax
  int v73; // eax
  int v74; // ST20_4
  tagTREEVIEWLISTITEMPARAM *v75; // eax
  HWND v76; // esi
  int v77; // eax
  HWND v78; // esi
  HWND v79; // eax
  HWND v80; // esi
  HWND v81; // edi
  HWND v82; // eax
  int *v83; // [esp-Ch] [ebp-ECCh]
  int *v84; // [esp-8h] [ebp-EC8h]
  int *v85; // [esp-4h] [ebp-EC4h]
  int v86; // [esp+0h] [ebp-EC0h]
  char Buffer[52]; // [esp+10h] [ebp-EB0h]
  char v88[604]; // [esp+44h] [ebp-E7Ch]
  DWORD BytesReturned; // [esp+2A0h] [ebp-C20h]
  LVITEMW lParam; // [esp+2A4h] [ebp-C1Ch]
  UINT pnIDs; // [esp+2D8h] [ebp-BE8h]
  int v92; // [esp+2DCh] [ebp-BE4h]
  int a3a; // [esp+2E0h] [ebp-BE0h]
  unsigned int v94; // [esp+2E4h] [ebp-BDCh]
  int v95; // [esp+2E8h] [ebp-BD8h]
  int v96; // [esp+2ECh] [ebp-BD4h]
  WORD pnWidths[2]; // [esp+2F0h] [ebp-BD0h]
  LVITEMW Item; // [esp+2F4h] [ebp-BCCh]
  int v99; // [esp+328h] [ebp-B98h]
  PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine; // [esp+32Ch] [ebp-B94h]
  int v101; // [esp+330h] [ebp-B90h]
  char ArgList[4]; // [esp+334h] [ebp-B8Ch]
  void *v103; // [esp+338h] [ebp-B88h]
  int v104; // [esp+33Ch] [ebp-B84h]
  int ThreadHandle; // [esp+340h] [ebp-B80h]
  int v106; // [esp+344h] [ebp-B7Ch]
  MixedModeStackWalker *pMixedModeStackWalker2; // [esp+348h] [ebp-B78h]
  int v108; // [esp+34Ch] [ebp-B74h]
  LPCONTEXT lpContext; // [esp+350h] [ebp-B70h]
  HWND v110; // [esp+354h] [ebp-B6Ch]
  HWND pMixedModeStackWalker; // [esp+358h] [ebp-B68h]
  HWND hDlg; // [esp+35Ch] [ebp-B64h]
  struct _tagSTACKFRAME64 StackFrame; // [esp+360h] [ebp-B60h]
  char v114; // [esp+468h] [ebp-A58h]
  char v115; // [esp+49Ch] [ebp-A24h]
  struct tagRECT Rect; // [esp+6F8h] [ebp-7C8h]
  DWORD OutBuffer; // [esp+708h] [ebp-7B8h]
  DWORD v118; // [esp+70Ch] [ebp-7B4h]
  DWORD v119; // [esp+710h] [ebp-7B0h]
  char v120; // [esp+723h] [ebp-79Dh]
  WCHAR String; // [esp+CACh] [ebp-214h]
  int *v122; // [esp+EB0h] [ebp-10h]
  int v123; // [esp+EBCh] [ebp-4h]

  v122 = &v86;
  hDlg = hWnd;
  v5 = GetWindowLongW(hWnd, -21);
  v101 = 0;
  v106 = v5;
  v108 = 0;
  lpContext = (LPCONTEXT)((unsigned int)&v120 & 0xFFFFFFF0);
  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v110 = GetDlgItem(hWnd, 1087);
  pnIDs = 43;
  v92 = 44;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  ReadMemoryRoutine = 0;
  if ( uMsg > WM_COMMAND )
  {
    if ( uMsg == WM_MSG_7F1 )
    {
      DestroyWindow(hDlg);
      return 0;
    }
    if ( uMsg != WM_MSG_7FA )
      return 0;
    memset(Buffer, 0, 656u);
    v85 = &ThreadHandle;
    if ( NtSuspendThread(v38, *(PULONG *)(v5 + 8)) )
    {
      v39 = hDlg;
      EndDialog(hDlg, 0);
      MessageBoxW(v39, L"Error accessing thread.", L"Process Explorer", 0x10u);
      v40 = GetParent(v39);
      SetFocus(v40);
      v41 = GetDlgItem(v39, 1210);
      EnableWindow(v41, 0);
      return 0;
    }
    pContext = lpContext;
    GetThreadContext(*(HANDLE *)(v5 + 8), lpContext);
    EnterCriticalSection(&gPE_ImageItemVerifiedLock);
    *(_DWORD *)ArgList = 0;
    pMixedModeStackWalker2 = 0;
    v123 = 1;
    v43 = (MixedModeStackWalker *)operator new(0x28u);
    v103 = v43;
    LOBYTE(v123) = 2;
    if ( v43 )
      pMixedModeStackWalker1 = MixedModeStackWalker::MixedModeStackWalker(v43);
    else
      pMixedModeStackWalker1 = 0;
    pMixedModeStackWalker = (HWND)pMixedModeStackWalker1;
    LOBYTE(v123) = 1;
    pMixedModeStackWalker2 = pMixedModeStackWalker1;
    if ( sub_C38940(pMixedModeStackWalker1, v5) == (FARPROC)1
      && sub_C38D10(pMixedModeStackWalker1, *(_DWORD *)(v5 + 4)) == 1 )
    {
      a3a = 0;
      v94 = 0;
      v95 = 0;
      v96 = 0;
      LOBYTE(v123) = 3;
      v104 = sub_C3B0A0(pMixedModeStackWalker1, a1, *(_DWORD *)(v5 + 4), (int)&a3a);
      if ( v104 == 1 )
      {
        v46 = 0;
        v108 = 0;
        if ( (signed int)v94 > 0 )
        {
          v47 = v94 > 0;
          while ( 1 )
          {
            if ( !v47 )
              ATL::AtlThrowImpl(E_INVALIDARG);
            v48 = *(_DWORD **)(a3a + 4 * v46);
            v103 = v48;
            if ( v48 )
              (*(void (__stdcall **)(_DWORD *))(*v48 + 4))(v48);
            LOBYTE(v123) = 4;
            v49 = wcscmp((const unsigned __int16 *)sub_C37F60(v48), L"0x0");
            if ( v49 )
              v49 = -(v49 < 0) | 1;
            if ( v49 )
            {
              v50 = *(_DWORD *)ArgList;
              Item.mask = 5;
              Item.iItem = 0x7FFFFFFF;
              Item.iSubItem = 0;
              Item.stateMask = 0;
              Item.state = 0;
              ++*(_DWORD *)ArgList;
              wsprintf(&String, L"%d", v50, v85);
              v51 = v110;
              Item.pszText = &String;
              Item.iImage = 0;
              Item.lParam = (tagTREEVIEWLISTITEMPARAM *)(v108 + 1);
              v52 = SendMessageW(v110, LVM_INSERTITEMW, 0, (LPARAM)&Item);
              if ( v52 == -1 )
              {
                LOBYTE(v123) = 3;
                if ( v48 )
                  (*(void (__stdcall **)(_DWORD *))(*v48 + 8))(v48);
                sub_C49F20((CString *)&a3a);
LABEL_77:
                v123 = -1;
                if ( pMixedModeStackWalker1 )
                  pMixedModeStackWalker1->vtptr->Release((IUnknown *)pMixedModeStackWalker1);
                return 0;
              }
              Item.mask = 1;
              Item.iItem = v52;
              Item.iSubItem = 1;
              Item.pszText = (LPWSTR)sub_C37F60(v48);
              SendMessageW(v51, LVM_SETITEMW, 0, (LPARAM)&Item);
            }
            LOBYTE(v123) = 3;
            if ( v48 )
              (*(void (__stdcall **)(_DWORD *))(*v48 + 8))(v48);
            v46 = v108 + 1;
            v108 = v46;
            v47 = v46 < v94;
            if ( v46 >= (signed int)v94 )
            {
              v5 = v106;
              pContext = lpContext;
              break;
            }
          }
        }
      }
      LOBYTE(v123) = 1;
      sub_C49F20((CString *)&a3a);
      if ( v104 )
      {
LABEL_104:
        NtResumeThread(v45, *(PULONG *)(v5 + 8));
        LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
        if ( !(v101 + v108) )
        {
          v78 = hDlg;
          EndDialog(hDlg, 0);
          MessageBoxW(
            0,
            L"Cannot access stack information. The stack may be swapped out, Process Explorer cannot access the support in"
             " the Windows Debugging Tools, or you previously ran an old version of Process Explorer and must reboot.",
            L"Process Explorer",
            0x10u);
          v79 = GetParent(v78);
          SetFocus(v79);
          goto LABEL_77;
        }
        v80 = v110;
        SendMessageW(v110, LVM_SETCOLUMNWIDTH, 0, 0xFFFF);
        SendMessageW(v80, LVM_SETCOLUMNWIDTH, 1u, 0xFFFF);
        lParam.stateMask = 3;
        lParam.state = 3;
        SendMessageW(v80, LVM_SETITEMSTATE, 0, (LPARAM)&lParam);
        SetFocus(v80);
        v81 = hDlg;
        if ( *(_DWORD *)&gConfig.gapFC[4] == gConfig.WindowPlacement[8].ptMaxPosition.y )
          GetWindowRect(hDlg, &Rect);
        else
          _mm_storeu_si128(
            (__m128i *)&Rect,
            _mm_loadu_si128((const __m128i *)&gConfig.WindowPlacement[8].ptMaxPosition.y));
        v82 = GetDlgItem(v81, 1210);
        EnableWindow(v82, 1);
        ghWndThreadStack = v81;
        SetFocus(v110);
        ShowWindow(v81, 1);
        v123 = -1;
        if ( pMixedModeStackWalker1 )
          pMixedModeStackWalker1->vtptr->Release((IUnknown *)pMixedModeStackWalker1);
        return 1;
      }
    }
    for ( i = 0; ; i = v99 + 1 )
    {
LABEL_67:
      v99 = i;
      if ( i >= 2 )
        goto LABEL_104;
      v101 = v108;
      v103 = (void *)v108;
      memset(pContext, 0, sizeof(CONTEXT));
      v54 = v99;
      pContext->ContextFlags = 0x10001;
      if ( v54 )
      {
        if ( v54 != 1 )
          goto LABEL_87;
        v62 = lpContext;
        v63 = 0;
        do
        {
          if ( GetThreadContext(*(HANDLE *)(v5 + 8), v62) )
            break;
          v84 = &ThreadHandle;
          NtResumeThread(v64, *(PULONG *)(v5 + 8));
          CloseHandle(*(HANDLE *)(v5 + 8));
          v65 = (ULONG *)Fake_OpenThread(*(HANDLE *)(v5 + 4), 0x4Au);
          *(_DWORD *)(v5 + 8) = v65;
          if ( !v65 )
            break;
          v83 = &ThreadHandle;
          NtSuspendThread(&ThreadHandle, v65);
          ++v63;
        }
        while ( v63 < 2 );
        pContext = lpContext;
        ReadMemoryRoutine = 0;
      }
      else
      {
        v55 = v106;
        v56 = 0;
        v57 = (PULONG *)(v106 + 8);
        do
        {
          if ( DeviceIoControl(ghDriverHandle, 0x83350028, v57, 4u, &OutBuffer, 0xCu, &BytesReturned, 0) )
            break;
          v84 = &ThreadHandle;
          NtResumeThread(v58, *v57);
          CloseHandle(*v57);
          v59 = (ULONG *)Fake_OpenThread(*(HANDLE *)(v55 + 4), 2u);
          *v57 = v59;
          if ( !v59 )
            break;
          v83 = &ThreadHandle;
          NtSuspendThread(&ThreadHandle, v59);
          Sleep(0x64u);
          ++v56;
        }
        while ( v56 < 2 );
        v60 = lpContext;
        v5 = v106;
        ReadMemoryRoutine = (PREAD_PROCESS_MEMORY_ROUTINE64)sub_C60640;
        lpContext->Eip = OutBuffer;
        v60->Esp = v118;
        v60->Ebp = v119;
        v61 = *v57;
        pContext = v60;
        dword_CDAB88 = (int)v61;
      }
      pMixedModeStackWalker1 = (MixedModeStackWalker *)pMixedModeStackWalker;
LABEL_87:
      if ( !*(_DWORD *)(v5 + 8) )
      {
        v66 = hDlg;
        EndDialog(hDlg, 0);
        MessageBoxW(0, L"Error opening thread for stack trace.", L"Process Explorer", 0x10u);
        v67 = GetParent(v66);
        SetFocus(v67);
        v68 = GetDlgItem(v66, 1210);
        EnableWindow(v68, 0);
        goto LABEL_77;
      }
      memset(&StackFrame, 0, 0x108u);
      v45 = (void *)pContext->Eip;
      StackFrame.AddrStack.Offset = pContext->Esp;
      v69 = pContext->Ebp;
      v70 = 0;
      StackFrame.AddrPC.Offset = (unsigned int)v45;
      StackFrame.AddrPC.Mode = 3;
      StackFrame.AddrStack.Mode = 3;
      StackFrame.AddrFrame.Offset = v69;
      StackFrame.AddrFrame.Mode = 3;
      StackFrame.AddrBStore.Offset = v69;
      StackFrame.AddrBStore.Mode = 3;
      while ( 1 )
      {
        v104 = v70;
        v108 = v70;
        if ( v70 >= 100 )
          break;
        v71 = *(unsigned int **)(v5 + 16);
        LOBYTE(v123) = 5;
        sub_C4DD60(1, (unsigned int)v45, (int)&v114, *(_DWORD *)(v5 + 12), 0, 0, *(_DWORD *)(v5 + 20), v71);
        if ( !StackWalk64(
                0x14Cu,
                *(HANDLE *)(v5 + 12),
                *(HANDLE *)(v5 + 8),
                &StackFrame,
                lpContext,
                ReadMemoryRoutine,
                SymFunctionTableAccess64,
                SymGetModuleBase64,
                0) )
        {
          pContext = lpContext;
          i = v99 + 1;
          LOBYTE(v123) = 1;
          goto LABEL_67;
        }
        v45 = (void *)StackFrame.AddrPC.Offset;
        v123 = 1;
        if ( !StackFrame.AddrPC.Offset )
          break;
        sub_C4DD60(
          1,
          StackFrame.AddrPC.Offset,
          (int)&v114,
          *(_DWORD *)(v5 + 12),
          0,
          0,
          *(_DWORD *)(v5 + 20),
          *(unsigned int **)(v5 + 16));
        v72 = wcscmp((const unsigned __int16 *)&v115, L"0x0");
        if ( v72 )
          v72 = -(v72 < 0) | 1;
        if ( v72 )
        {
          v73 = wcscmp((const unsigned __int16 *)&v115, (const unsigned __int16 *)v88);
          if ( v73 )
            v73 = -(v73 < 0) | 1;
          if ( v73 )
          {
            v74 = *(_DWORD *)ArgList;
            Item.mask = 5;
            Item.iItem = 0x7FFFFFFF;
            Item.iSubItem = 0;
            Item.stateMask = 0;
            Item.state = 0;
            ++*(_DWORD *)ArgList;
            wsprintf(&String, L"%d", v74, v83, v84, v85);
            Item.pszText = &String;
            v75 = (tagTREEVIEWLISTITEMPARAM *)(v70 + 1);
            Item.iImage = 0;
            v76 = v110;
            Item.lParam = v75;
            v77 = SendMessageW(v110, LVM_INSERTITEMW, 0, (LPARAM)&Item);
            if ( v77 == -1 )
              goto LABEL_77;
            Item.iItem = v77;
            Item.pszText = (LPWSTR)&v115;
            Item.mask = 1;
            Item.iSubItem = 1;
            SendMessageW(v76, LVM_SETITEMW, 0, (LPARAM)&Item);
            qmemcpy(Buffer, &v114, 0x290u);
            v5 = v106;
            v70 = v108;
          }
        }
        v45 = (void *)StackFrame.AddrPC.Offset;
        ++v70;
      }
      pContext = lpContext;
    }
  }
  if ( uMsg == WM_COMMAND )
  {
    if ( (signed int)(unsigned __int16)a3 > 40083 )
    {
      if ( (unsigned __int16)a3 != 40084 )
      {
        if ( (unsigned __int16)a3 == 40631 )
        {
          v30 = 0;
          v31 = GetDlgItem(hDlg, 1087);
          if ( SendMessageW(v31, LVM_GETITEMCOUNT, 0, 0) > 0 )
          {
            do
            {
              lParam.stateMask = 2;
              lParam.state = 2;
              SendMessageW(v31, LVM_SETITEMSTATE, v30++, (LPARAM)&lParam);
            }
            while ( v30 < SendMessageW(v31, LVM_GETITEMCOUNT, 0, 0) );
          }
        }
        return 0;
      }
      v32 = 0;
      Item.iItem = -1;
      v33 = 0;
      v34 = GetDlgItem(hDlg, 1087);
      pMixedModeStackWalker = v34;
      v35 = SendMessageW(v34, LVM_GETNEXTITEM, Item.iItem, 0);
      v27 = pMixedModeStackWalker;
      for ( Item.iItem = v35; v35 != -1; Item.iItem = v35 )
      {
        lParam.iSubItem = 1;
        lParam.pszText = &String;
        lParam.cchTextMax = 256;
        SendMessageW(pMixedModeStackWalker, LVM_GETITEMTEXTW, v35, (LPARAM)&lParam);
        v36 = (unsigned int)&v32->vtptr + wcslen(&String) + 2;
        pMixedModeStackWalker2 = (MixedModeStackWalker *)v36;
        if ( v33 )
        {
          v27 = GlobalReAlloc(v27, 2 * v36 + 2, 0);
          v33 = (wchar_t *)GlobalLock(v27);
        }
        else
        {
          v27 = GlobalAlloc(0x2002u, 2 * v36 + 2);
          v33 = (wchar_t *)GlobalLock(v27);
          *v33 = 0;
        }
        v37 = v36 + 1;
        wcscat_s(v33, v37, &String);
        wcscat_s(v33, v37, L"\r\n");
        GlobalUnlock(v27);
        v35 = SendMessageW(pMixedModeStackWalker, LVM_GETNEXTITEM, Item.iItem, 0);
        v32 = pMixedModeStackWalker2;
      }
    }
    else
    {
      if ( (unsigned __int16)a3 != 40083 )
      {
        if ( (signed int)(unsigned __int16)a3 > 0 )
        {
          if ( (signed int)(unsigned __int16)a3 <= 2 )
          {
            v22 = hDlg;
            GetWindowPlacement(hDlg, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[7] + 24));
            ghWndThreadStack = 0;
            EndDialog(v22, 0);
          }
          else if ( (unsigned __int16)a3 == 1210 )
          {
            v20 = hDlg;
            v21 = GetDlgItem(hDlg, 1210);
            EnableWindow(v21, 0);
            SendMessageW(v110, LVM_DELETEALLITEMS, 0, 0);
            SendMessageW(v20, 0x7FAu, 0, 0);
          }
        }
        return 0;
      }
      v23 = 0;
      Item.iItem = -1;
      v24 = 0;
      v25 = GetDlgItem(hDlg, 1087);
      pMixedModeStackWalker = v25;
      v26 = SendMessageW(v25, LVM_GETNEXTITEM, Item.iItem, 2);
      v27 = pMixedModeStackWalker;
      for ( Item.iItem = v26; v26 != -1; Item.iItem = v26 )
      {
        lParam.iSubItem = 1;
        lParam.pszText = &String;
        lParam.cchTextMax = 256;
        SendMessageW(pMixedModeStackWalker, 0x1073u, v26, (LPARAM)&lParam);
        v28 = (unsigned int)&v23->vtptr + wcslen(&String) + 2;
        pMixedModeStackWalker2 = (MixedModeStackWalker *)v28;
        if ( v24 )
        {
          v27 = GlobalReAlloc(v27, 2 * v28 + 2, 0);
          v24 = (wchar_t *)GlobalLock(v27);
        }
        else
        {
          v27 = GlobalAlloc(0x2002u, 2 * v28 + 2);
          v24 = (wchar_t *)GlobalLock(v27);
          *v24 = 0;
        }
        v29 = v28 + 1;
        wcscat_s(v24, v29, &String);
        wcscat_s(v24, v29, L"\r\n");
        GlobalUnlock(v27);
        v26 = SendMessageW(pMixedModeStackWalker, LVM_GETNEXTITEM, Item.iItem, 2);
        v23 = pMixedModeStackWalker2;
      }
    }
    if ( OpenClipboard(hDlg) )
    {
      EmptyClipboard();
      SetClipboardData(0xDu, v27);
      CloseClipboard();
    }
    SetFocus(pMixedModeStackWalker);
    return 0;
  }
  if ( uMsg == 78 )
  {
    v15 = *(_DWORD *)(dwNewLong + 8);
    if ( v15 == -101 || (unsigned int)(v15 + 3) <= 1 )
    {
      v16 = hDlg;
      v17 = GetDlgItem(hDlg, 1087);
      if ( SendMessageW(v17, LVM_GETNEXTITEM, 0xFFFFFFFF, 2) == -1 )
      {
        v19 = GetDlgItem(v16, 40083);
        EnableWindow(v19, 0);
      }
      else
      {
        v18 = GetDlgItem(v16, 40083);
        EnableWindow(v18, 1);
      }
    }
    return 0;
  }
  if ( uMsg != 272 )
    return 0;
  v6 = LoadIconW(ghInstance, (LPCWSTR)0x65);
  v7 = hDlg;
  SendMessageW(hDlg, 0x80u, 0, (LPARAM)v6);
  v8 = (CResizer *)operator new(0x40u);
  v103 = v8;
  v123 = 0;
  if ( v8 )
    CResizer::CResizer(v8, v7);
  v9 = v110;
  v10 = GetWindowLongW(v110, -16);
  SetWindowLongW(v9, -16, v10 & 0xFFFFFFFD | 1);
  SetWindowLongW(v110, -21, 2);
  SendMessageW(v110, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 16416);
  v11 = (HWND)SendMessageW(v110, LVM_GETTOOLTIPS, 0, 0);
  CTreeList::InitToolTips(v11);
  gOldListWndProc = (WNDPROC)SetWindowLongW(v110, -4, (LONG)Proxy_ListCtrlWndProc);
  SendMessageW(v110, 0x30u, (WPARAM)ghConfigFont, 0);
  InitListHeader(v110, &pnIDs, pnWidths, 2);
  SetWindowLongW(hDlg, -21, dwNewLong);
  wsprintf(&String, L"Stack for thread %d", *(_DWORD *)(dwNewLong + 4));
  v12 = hDlg;
  SetWindowTextW(hDlg, &String);
  gConfig.WindowPlacement[8].flags = 5;
  SetWindowPlacement(v12, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[7] + 24));
  if ( GetCurrentProcessId() == *(_DWORD *)dwNewLong )
  {
    EndDialog(v12, 0);
    MessageBoxW(0, L"Thread stack not available for Process Explorer.", L"Process Explorer", 0x10u);
    v13 = GetParent(v12);
    SetFocus(v13);
    return 0;
  }
  SendMessageW(v12, WM_MSG_7FA, 0, 0);
  return 1;
}
// CB5208: using guessed type wchar_t a0x0[4];
// CDAB88: using guessed type int dword_CDAB88;

//----- (00C65020) --------------------------------------------------------
void __noreturn ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException()
{
  ATL::AtlThrowImpl(E_OUTOFMEMORY);
}

//----- (00C65030) --------------------------------------------------------
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
// CEBA5C: using guessed type char gbWindowTextFlags;

//----- (00C65140) --------------------------------------------------------
signed int __usercall sub_C65140@<eax>(int a1@<ebx>, int a2, _BYTE *a3)
{
  HANDLE v3; // eax
  int v5; // [esp+4h] [ebp-234h]
  PROCESSENTRY32W pe; // [esp+8h] [ebp-230h]

  pe.dwSize = 0;
  memset(&pe.cntUsage, 0, 0x228u);
  if ( hSnapshot != (HANDLE)-1 )
    CloseHandle(hSnapshot);
  v3 = CreateToolhelp32Snapshot_0(TH32CS_SNAPPROCESS, 0);
  hSnapshot = v3;
  if ( v3 == (HANDLE)-1 )
    return 0;
  pe.dwSize = 556;
  if ( !Process32FirstW_0(v3, &pe) )
    return 0;
  do
  {
    if ( a3 && *a3 == 1 )
      break;
    sub_C5F870(a1, a2, (int)a3, 0, pe.th32ProcessID, 0, (int)pe.szExeFile, (int)&v5);
  }
  while ( Process32NextW_0(hSnapshot, &pe) );
  return 1;
}

//----- (00C65230) --------------------------------------------------------
errno_t __cdecl wcsncpy_s(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return wcsncpy_s(Dst, SizeInWords, *(const wchar_t **)(a3 + 4), (unsigned int)*(unsigned __int16 *)a3 >> 1);
}

//----- (00C65250) --------------------------------------------------------
int __cdecl sub_C65250(int *a1)
{
  int v1; // eax
  __m128i v2; // xmm0
  int v3; // ST0C_4
  _DWORD *v4; // ecx
  int v5; // eax
  unsigned __int8 v6; // cf
  int result; // eax
  int v8; // eax
  int a4; // [esp+0h] [ebp-70h]
  __int128 v10; // [esp+8h] [ebp-68h]
  __int128 v11; // [esp+18h] [ebp-58h]
  __int128 v12; // [esp+28h] [ebp-48h]
  __int128 v13; // [esp+38h] [ebp-38h]
  __int128 v14; // [esp+48h] [ebp-28h]
  __int128 v15; // [esp+58h] [ebp-18h]
  int a2; // [esp+68h] [ebp-8h]

  *(_QWORD *)&v13 = 0i64;
  *((_QWORD *)&v13 + 1) = 0i64;
  *(_QWORD *)&v14 = 0i64;
  v1 = *a1;
  *((_QWORD *)&v14 + 1) = 0i64;
  *(_QWORD *)&v15 = 0i64;
  *((_QWORD *)&v15 + 1) = 0i64;
  v2 = _mm_loadu_si128((const __m128i *)&v13);
  a4 = v1;
  v3 = (unsigned __int8)byte_CEBC00;
  _mm_storeu_si128((__m128i *)&v10, v2);
  _mm_storeu_si128((__m128i *)&v11, _mm_loadu_si128((const __m128i *)&v14));
  _mm_storeu_si128((__m128i *)&v12, _mm_loadu_si128((const __m128i *)&v15));
  sub_C49C10(&gMap2_NodeSizeIs48H, (int)&a2, 0, &a4, v3);
  v4 = (_DWORD *)a2;
  if ( a1[2] == 10 )
  {
    v8 = a1[8];
    v6 = __CFADD__(v8, *(_DWORD *)(a2 + 24));
    *(_DWORD *)(a2 + 24) += v8;
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
      v6 = __CFADD__(v5, *(_DWORD *)(a2 + 32));
      *(_DWORD *)(a2 + 32) += v5;
      result = a1[9];
      v4[9] += result + v6;
      v6 = __CFADD__(v4[14]++, 1);
      v4[15] += v6;
    }
    else
    {
      v6 = __CFADD__(v5, *(_DWORD *)(a2 + 40));
      *(_DWORD *)(a2 + 40) += v5;
      result = a1[9];
      v4[11] += result + v6;
      v6 = __CFADD__(v4[16]++, 1);
      v4[17] += v6;
    }
  }
  return result;
}
// CEBC00: using guessed type char byte_CEBC00;

//----- (00C65310) --------------------------------------------------------
int __cdecl sub_C65310(int *a1)
{
  int v1; // eax
  __m128i v2; // xmm0
  int v3; // ST0C_4
  int v4; // ecx
  int result; // eax
  unsigned __int8 v6; // cf
  int a4; // [esp+0h] [ebp-70h]
  __int128 v8; // [esp+8h] [ebp-68h]
  __int128 v9; // [esp+18h] [ebp-58h]
  __int128 v10; // [esp+28h] [ebp-48h]
  __int128 v11; // [esp+38h] [ebp-38h]
  __int128 v12; // [esp+48h] [ebp-28h]
  __int128 v13; // [esp+58h] [ebp-18h]
  int a2; // [esp+68h] [ebp-8h]

  *(_QWORD *)&v11 = 0i64;
  *((_QWORD *)&v11 + 1) = 0i64;
  *(_QWORD *)&v12 = 0i64;
  v1 = *a1;
  *((_QWORD *)&v12 + 1) = 0i64;
  *(_QWORD *)&v13 = 0i64;
  *((_QWORD *)&v13 + 1) = 0i64;
  v2 = _mm_loadu_si128((const __m128i *)&v11);
  a4 = v1;
  v3 = (unsigned __int8)byte_CEBC00;
  _mm_storeu_si128((__m128i *)&v8, v2);
  _mm_storeu_si128((__m128i *)&v9, _mm_loadu_si128((const __m128i *)&v12));
  _mm_storeu_si128((__m128i *)&v10, _mm_loadu_si128((const __m128i *)&v13));
  sub_C49C10(&gMap3_NodeSizeIs48H, (int)&a2, 0, &a4, v3);
  v4 = a2;
  if ( a1[2] == 2 )
  {
    result = a1[7];
    v6 = __CFADD__(result, *(_DWORD *)(a2 + 32));
    *(_DWORD *)(a2 + 32) += result;
    *(_DWORD *)(v4 + 36) += v6;
    ++*(_QWORD *)(v4 + 56);
  }
  else
  {
    result = a1[7];
    if ( a1[2] == 3 )
    {
      v6 = __CFADD__(result, *(_DWORD *)(a2 + 24));
      *(_DWORD *)(a2 + 24) += result;
      *(_DWORD *)(v4 + 28) += v6;
      ++*(_QWORD *)(v4 + 48);
    }
    else
    {
      v6 = __CFADD__(result, *(_DWORD *)(a2 + 40));
      *(_DWORD *)(a2 + 40) += result;
      *(_DWORD *)(v4 + 44) += v6;
      ++*(_QWORD *)(v4 + 64);
    }
  }
  return result;
}
// CEBC00: using guessed type char byte_CEBC00;

//----- (00C653D0) --------------------------------------------------------
PE_ImageItemVerified *__cdecl PE_ImageItemVerified_Create(const wchar_t *lpszText1, unsigned int dwValue, const wchar_t *lpszText2)
{
  PE_ImageItemVerified *v3; // esi
  PE_ImageItemVerified *result; // eax

  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  if ( !PE_ImageItemVerified_Find((wchar_t *)lpszText1) )
  {
    v3 = (PE_ImageItemVerified *)malloc(0x10u);
    v3->pszText1 = (DWORD)_wcsdup(lpszText1);
    v3->dwValue = (HANDLE)dwValue;
    v3->pszTitle = _wcsdup(lpszText2);
    v3->pNext = (int)gpPE_ImageItemVerified;
    gpPE_ImageItemVerified = v3;
  }
  LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
  return result;
}

//----- (00C65440) --------------------------------------------------------
std__Tree_node *sub_C65440()
{
  std__Tree_node *result; // eax

  result = (std__Tree_node *)operator new(0x48u);
  JUMPOUT(result, 0, std::_Xbad_alloc);
  result->_Left = (std_Tree_node_for_tagKeyName *)result;
  if ( result != (std__Tree_node *)-4 )
    result->_Parent = (std_Tree_node_for_tagKeyName *)result;
  if ( result != (std__Tree_node *)-8 )
    result->_Right = (std__Tree_node_For__bstr_t *)result;
  *(_WORD *)&result->_Color = 257;
  return result;
}

//----- (00C65470) --------------------------------------------------------
std__Tree_node **__thiscall sub_C65470(std__tree *this)
{
  std__tree *v1; // esi
  std__Tree_node **v2; // edx

  v1 = this;
  v2 = (std__Tree_node **)operator new(0x48u);
  if ( !v2 )
    std::_Xbad_alloc();
  *v2 = v1->_Mypair._Myval2._Myhead;
  if ( v2 != (std__Tree_node **)-4 )
    v2[1] = v1->_Mypair._Myval2._Myhead;
  if ( v2 != (std__Tree_node **)-8 )
    v2[2] = v1->_Mypair._Myval2._Myhead;
  return v2;
}

//----- (00C654B0) --------------------------------------------------------
std__Tree_node *__thiscall sub_C654B0(std__tree *this, std__Tree_node *_Node)
{
  std__Tree_node *_Right; // esi
  std__Tree_node *result; // eax

  _Right = (std__Tree_node *)_Node->_Right;
  _Node->_Right = (std__Tree_node_For__bstr_t *)_Right->_Left;
  if ( !_Right->_Left->_IsNil )
    _Right->_Left->_Parent = (std_Tree_node_for_tagKeyName *)_Node;
  _Right->_Parent = _Node->_Parent;
  result = this->_Mypair._Myval2._Myhead;
  if ( _Node == (std__Tree_node *)this->_Mypair._Myval2._Myhead->_Parent )
  {
    result->_Parent = (std_Tree_node_for_tagKeyName *)_Right;
    _Right->_Left = (std_Tree_node_for_tagKeyName *)_Node;
    _Node->_Parent = (std_Tree_node_for_tagKeyName *)_Right;
  }
  else
  {
    result = (std__Tree_node *)_Node->_Parent;
    if ( _Node == (std__Tree_node *)result->_Left )
      result->_Left = (std_Tree_node_for_tagKeyName *)_Right;
    else
      result->_Right = (std__Tree_node_For__bstr_t *)_Right;
    _Right->_Left = (std_Tree_node_for_tagKeyName *)_Node;
    _Node->_Parent = (std_Tree_node_for_tagKeyName *)_Right;
  }
  return result;
}

//----- (00C65510) --------------------------------------------------------
int **__thiscall sub_C65510(std__tree *this, int **a2, std__Tree_node *a3, int *a4)
{
  std__Tree_node *v4; // eax
  std__Tree_node *This; // edi
  int **result; // eax
  std__Tree_node *v7; // ecx
  std__Tree_node *i; // edx
  std__Tree_node *v9; // eax
  int a2a; // [esp+8h] [ebp-4h]

  v4 = a3;
  This = (std__Tree_node *)this;
  if ( a3 != (std__Tree_node *)this->_Mypair._Myval2._Myhead->_Left || a4 != (int *)this->_Mypair._Myval2._Myhead )
  {
    for ( ; a3 != (std__Tree_node *)a4; v4 = a3 )
    {
      v7 = v4;
      if ( !v4->_IsNil )
      {
        i = (std__Tree_node *)v4->_Right;
        if ( i->_IsNil )
        {
          for ( i = (std__Tree_node *)v4->_Parent; !i->_IsNil; i = (std__Tree_node *)i->_Parent )
          {
            if ( v4 != (std__Tree_node *)i->_Right )
              break;
            v4 = i;
          }
        }
        else
        {
          v9 = (std__Tree_node *)i->_Left;
          if ( !i->_Left->_IsNil )
          {
            do
            {
              i = v9;
              v9 = (std__Tree_node *)v9->_Left;
            }
            while ( !v9->_IsNil );
          }
        }
        a3 = i;
      }
      sub_C655B0(This, &a2a, v7);
    }
    *a2 = (int *)v4;
    result = a2;
  }
  else
  {
    sub_C3E620(this);
    result = a2;
    *a2 = (int *)This->_Left->_Left;
  }
  return result;
}

//----- (00C655B0) --------------------------------------------------------
_DWORD *__thiscall sub_C655B0(std__Tree_node *this, _DWORD *a2, _DWORD *a3)
{
  std__tree *This; // ebx
  std__tree *v4; // ecx
  std__Tree_node *v5; // edi
  std__Tree_node *v6; // edx
  std__Tree_node *v7; // esi
  _DWORD *v8; // eax
  std__Tree_node *v9; // edx
  std__Tree_node *v10; // eax
  std__Tree_node *v11; // eax
  std__Tree_node *i; // edx
  std__tree **v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  unsigned int v16; // eax
  _DWORD *v17; // ecx
  _DWORD *result; // eax
  std__tree *v19; // [esp+10h] [ebp-4h]

  This = (std__tree *)this;
  v19 = (std__tree *)a3;
  sub_C04CE0((std__tree *)&a3);
  v4 = v19;
  if ( v19->_Mypair._Myval2._Myhead->_IsNil )
  {
    v5 = v19[1]._Mypair._Myval2._Myhead;
  }
  else if ( v19[1]._Mypair._Myval2._Myhead->_IsNil )
  {
    v5 = v19->_Mypair._Myval2._Myhead;
  }
  else
  {
    v6 = (std__Tree_node *)a3;
    v5 = (std__Tree_node *)a3[2];
    if ( a3 != (_DWORD *)v19 )
    {
      v19->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)a3;
      v6->_Left = (std_Tree_node_for_tagKeyName *)v19->_Mypair._Myval2._Myhead;
      if ( v6 == v19[1]._Mypair._Myval2._Myhead )
      {
        v7 = v6;
      }
      else
      {
        v7 = (std__Tree_node *)v6->_Parent;
        if ( !v5->_IsNil )
          v5->_Parent = (std_Tree_node_for_tagKeyName *)v7;
        v7->_Left = (std_Tree_node_for_tagKeyName *)v5;
        v6->_Right = (std__Tree_node_For__bstr_t *)v19[1]._Mypair._Myval2._Myhead;
        v19[1]._Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v6;
      }
      if ( (std__tree *)This->_Mypair._Myval2._Myhead->_Parent == v19 )
      {
        This->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v6;
      }
      else
      {
        v13 = (std__tree **)v19->_Mypair._Myval2._Mysize;
        if ( *v13 == v19 )
          *v13 = (std__tree *)v6;
        else
          v13[2] = (std__tree *)v6;
      }
      v6->_Parent = (std_Tree_node_for_tagKeyName *)v19->_Mypair._Myval2._Mysize;
      v14 = v6->_Color;
      v6->_Color = v19[1]._Mypair._Myval2._Mysize;
      LOBYTE(v19[1]._Mypair._Myval2._Mysize) = v14;
      v4 = v19;
      goto LABEL_37;
    }
  }
  v7 = (std__Tree_node *)v19->_Mypair._Myval2._Mysize;
  if ( !v5->_IsNil )
    v5->_Parent = (std_Tree_node_for_tagKeyName *)v7;
  if ( (std__tree *)This->_Mypair._Myval2._Myhead->_Parent == v19 )
  {
    This->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v5;
  }
  else if ( (std__tree *)v7->_Left == v19 )
  {
    v7->_Left = (std_Tree_node_for_tagKeyName *)v5;
  }
  else
  {
    v7->_Right = (std__Tree_node_For__bstr_t *)v5;
  }
  v8 = &This->_Mypair._Myval2._Myhead->_Left;
  if ( This->_Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)v19 )
  {
    if ( v5->_IsNil )
    {
      v9 = v7;
    }
    else
    {
      v10 = (std__Tree_node *)v5->_Left;
      v9 = v5;
      if ( !v5->_Left->_IsNil )
      {
        do
        {
          v9 = v10;
          v10 = (std__Tree_node *)v10->_Left;
        }
        while ( !v10->_IsNil );
      }
      v8 = &This->_Mypair._Myval2._Myhead->_Left;
    }
    *v8 = v9;
  }
  if ( (std__tree *)This->_Mypair._Myval2._Myhead->_Right == v19 )
  {
    if ( v5->_IsNil )
    {
      This->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v7;
    }
    else
    {
      v11 = (std__Tree_node *)v5->_Right;
      for ( i = v5; !v11->_IsNil; v11 = (std__Tree_node *)v11->_Right )
        i = v11;
      This->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)i;
    }
  }
LABEL_37:
  if ( LOBYTE(v4[1]._Mypair._Myval2._Mysize) != 1 )
    goto LABEL_62;
  if ( v5 == (std__Tree_node *)This->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->_Color == 1 )
  {
    v15 = (std__Tree_node *)v7->_Left;
    if ( v5 == (std__Tree_node *)v7->_Left )
    {
      v15 = (std__Tree_node *)v7->_Right;
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_C654B0(This, v7);
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
          sub_C72BB0(This, v15);
          v15 = (std__Tree_node *)v7->_Right;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Right->_Color = 1;
        sub_C654B0(This, v7);
        break;
      }
    }
    else
    {
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_C72BB0(This, v7);
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
          sub_C654B0(This, v15);
          v15 = (std__Tree_node *)v7->_Left;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Left->_Color = 1;
        sub_C72BB0(This, v7);
        break;
      }
    }
    v15->_Color = 0;
LABEL_55:
    v5 = v7;
    v7 = (std__Tree_node *)v7->_Parent;
    if ( v5 == (std__Tree_node *)This->_Mypair._Myval2._Myhead->_Parent )
      break;
  }
  v4 = v19;
LABEL_61:
  v5->_Color = 1;
LABEL_62:
  operator delete(v4);
  v16 = This->_Mypair._Myval2._Mysize;
  v17 = a3;
  if ( v16 )
    This->_Mypair._Myval2._Mysize = v16 - 1;
  result = a2;
  *a2 = v17;
  return result;
}

//----- (00C65820) --------------------------------------------------------
// std__map_for_process_some_information::find(std__map_for_process_some_information* pThis,std__Tree_node_for_process_some_information**ppNode,DWORD dwProcessId)
std__Tree_node_for_process_some_information **__thiscall std__map_for_process_some_information::FindNodeByPid(std__tree *this, std__Tree_node_for_process_some_information **ppNode, unsigned int *pdwProcessId)
{
  std__Tree_node_for_process_some_information *_Myhead; // esi
  std__Tree_node_for_process_some_information *_Node; // ecx
  std__Tree_node_for_process_some_information *_Parent; // eax
  unsigned int v6; // eax
  std__Tree_node_for_process_some_information **result; // eax
  std__Tree_node_for_process_some_information *pdwProcessIda; // [esp+14h] [ebp+Ch]

  _Myhead = (std__Tree_node_for_process_some_information *)this->_Mypair._Myval2._Myhead;
  _Node = _Myhead;
  _Parent = (std__Tree_node_for_process_some_information *)_Myhead->_Parent;
  while ( !_Parent->_IsNil )
  {
    if ( _Parent->dwProcessId >= *pdwProcessId )
    {
      _Node = _Parent;
      _Parent = (std__Tree_node_for_process_some_information *)_Parent->_Left;
    }
    else
    {
      _Parent = (std__Tree_node_for_process_some_information *)_Parent->_Right;
    }
  }
  if ( _Node == _Myhead || (v6 = *pdwProcessId, pdwProcessIda = _Node, v6 < _Node->dwProcessId) )
    pdwProcessIda = _Myhead;
  result = ppNode;
  *ppNode = pdwProcessIda;
  return result;
}

//----- (00C65870) --------------------------------------------------------
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

//----- (00C658D0) --------------------------------------------------------
char __usercall sub_C658D0@<al>(signed int a1@<ebx>, HWND hWnd, LVITEMW *pItem, LPARAM pItemParam, int a5)
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
  *(_DWORD *)(pItemParam + 8) = gdwRefreshCount;
  *(_DWORD *)(pItemParam + 12) = *(_DWORD *)(pItemParam + 16);
  *(_BYTE *)a5 = 0;
  v5 = gConfig.dwHighlightDuration;
  if ( gConfig.dwRefreshRate )
    v5 = gConfig.dwRefreshRate;
  v6 = *(_DWORD *)(pItemParam + 16);
  *(_DWORD *)(pItemParam + 20) += v5;
  v7 = *(_DWORD *)(pItemParam + 20);
  if ( v6 == 2 )
  {
    a1 = 0;
    if ( v7 >= (signed int)gConfig.dwHighlightDuration )
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
    if ( v7 >= (signed int)gConfig.dwHighlightDuration )
    {
      v8 = *(_DWORD *)(pItemParam + 4);
      v9 = hWnd;
      *(_DWORD *)(pItemParam + 16) = 4;
      v18 = v8;
      if ( pItem->iItem != -1
        || (FindInfo.lParam = (LPARAM)pItem->lParam,
            FindInfo.flags = 1,
            v10 = SendMessageW(hWnd, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&FindInfo),
            v9 = hWnd,
            pItem->iItem = v10,
            v10 != -1) )
      {
        SendMessageW(v9, WM_SETREDRAW, 0, 0);
        LOBYTE(v17) = 1;
        pItem->mask = 8;
        SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)pItem);
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
          SendMessageW(hWnd, LVM_SETITEMSTATE, v12, (LPARAM)&StateItem);
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
  if ( v6 != 2 || v7 >= (signed int)gConfig.dwHighlightDuration )
  {
    *(_BYTE *)(pItemParam + 24) = 0;
    *(_DWORD *)(pItemParam + 16) = 0;
  }
  else
  {
    *(_BYTE *)(pItemParam + 24) = 1;
    *(_DWORD *)(pItemParam + 28) = v7;
  }
  if ( *(_DWORD *)(pItemParam + 4) != 2 )
  {
    *(_DWORD *)(pItemParam + 16) = 1;
    *(_DWORD *)(pItemParam + 20) = 0;
    *(_BYTE *)a5 = 1;
    result = a1;
    --pItem->iItem;
    return result;
  }
  if ( PE_QueryObjectInfo((int)pItem->lParam) )
    goto LABEL_31;
  v14 = hWnd == ghWndHandlesListCtrl;
  *(_DWORD *)(pItemParam + 16) = 1;
  if ( v14 )
    LOBYTE(a1) = 1;
  *(_DWORD *)(pItemParam + 20) = 0;
  *(_BYTE *)a5 = 1;
  result = a1;
  --pItem->iItem;
  return result;
}
// CDA11C: using guessed type int gdwRefreshCount;

//----- (00C65AB0) --------------------------------------------------------
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

//----- (00C65AE0) --------------------------------------------------------
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
  GraphWndTipText TipTextInfo; // [esp+20h] [ebp-884h]
  LPARAM v26; // [esp+830h] [ebp-74h]
  int v27; // [esp+834h] [ebp-70h]
  HWND v28; // [esp+838h] [ebp-6Ch]
  struct tagRECT v29; // [esp+840h] [ebp-64h]
  struct tagRECT Rect; // [esp+850h] [ebp-54h]
  struct tagPAINTSTRUCT Paint; // [esp+860h] [ebp-44h]

  lParam_2 = lParam;
  pGraphData = (CGraphData *)GetWindowLongW(hWnd, GWLP_USERDATA);
  hWndTooltips = (HWND)GetPropW(hWnd, L"Balloon");
  SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
  hWndTooltips_1 = hWndTooltips;
  uMsg = Msg;
  if ( hWndTooltips_1 )
  {
    if ( Msg != WM_LBUTTONDOWN )
    {
      uMsg = Msg;
      if ( Msg - 512 <= 13 )
      {
        v29.right = Msg;
        v29.bottom = wParam;
        Rect.left = lParam_2;
        v29.top = (LONG)hWnd;
        *(_QWORD *)&Rect.top = 0i64;
        Rect.bottom = 0;
        ::SendMessageW(hWndTooltips_1, TTM_RELAYEVENT, 0, (LPARAM)&v29.top);
        uMsg = Msg;
        SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
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
        v21 = (HWND)pGraphData->m_Item[1].nItemID;
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
      if ( (signed __int16)lParam_2 == pGraphData->field_858 )
      {
        if ( SHIWORD(lParam_2) == pGraphData->field_85C )
          return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
        v22 = HIWORD(lParam_2);
      }
      pGraphData->field_858 = (signed __int16)lParam_2;
      pGraphData->field_85C = v22;
      SendMessageW(hWndTooltips_1, TTM_UPDATE, 0, 0);
      LOBYTE(pGraphData->field_854) = 0;
    }
    return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
  }
  if ( uMsg == WM_NOTIFY )
  {
    if ( *(HWND *)lParam_2 == hWndTooltips_1 )
    {
      v16 = *(_DWORD *)(lParam_2 + 8);
      if ( v16 == TTN_GETDISPINFOW )
      {
        GetCursorPos(&Point);
        if ( WindowFromPoint(Point) == hWnd && (v17 = GetParent(hWnd), sub_C22A70(v17)) )
        {
          TipTextInfo.hWnd = (int)hWnd;
          TipTextInfo.pGraphData = pGraphData;
          GetCursorPos(&Point);
          ScreenToClient(hWnd, &Point);
          TipTextInfo.x = Point.x;
          TipTextInfo.y = Point.y;
          GraphWnd_GenerateTipText(&TipTextInfo);
          if ( TipTextInfo.szText[0] )
          {
            v18 = (wchar_t *)&pGraphData->m_Item[1].dwValue;
            wcscpy_s(v18, 0x400u, (const wchar_t *)TipTextInfo.szText);
            *(_DWORD *)(lParam_2 + 12) = v18;
          }
        }
        else
        {
          ::SendMessageW(hWndTooltips_1, TTM_POP, 0, 0);
        }
      }
      else if ( v16 == TTN_SHOW )
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
        GetClientRect(hWnd, &Rect);
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
          GraphData_DrawChart(pGraphData, hDC, (#153 *)&Rect, 0xFFFFFFFF, 0, 0.0);
          EndPaint(hWnd, &Paint);
          result = 0;
        }
        else
        {
          GraphData_DrawGraph(pGraphData, hDC, (#153 *)&Rect);
          EndPaint(hWnd, &Paint);
          result = 0;
        }
        return result;
      }
    }
    else
    {
      v26 = 48;
      v27 = 0;
      _mm_storeu_si128((__m128i *)&v28, (__m128i)0i64);
      _mm_storeu_si128((__m128i *)&v29.right, (__m128i)0i64);
      v28 = hWnd;
      *(_QWORD *)&Rect.right = 0i64;
      GetClientRect(hWnd, &v29);
      ::SendMessageW(hWndTooltips_1, TTM_NEWTOOLRECTW, 0, (LPARAM)&v26);
    }
    return DefWindowProcW(hWnd, Msg, wParam, lParam_2);
  }
  SetWindowLongW(hWnd, GWLP_USERDATA, *(_DWORD *)lParam_2);
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
    || (unsigned int)(v14 - 2501) <= 0x62 )
  {
    hWndTooltip = CreateWindowExW(WS_EX_TOPMOST, L"tooltips_class32", 0, 0x80000033, 0, 0, 0, 0, hWnd, 0, ghInstance, 0);
    v26 = 48;
    v27 = 0x100;
    _mm_storeu_si128((__m128i *)&v28, (__m128i)0i64);
    _mm_storeu_si128((__m128i *)&v29.right, (__m128i)0i64);
    v28 = hWnd;
    *(_QWORD *)&Rect.right = 0i64;
    Rect.top = -1;
    ::SendMessageW(hWndTooltip, TTM_ADDTOOLW, 0, (LPARAM)&v26);
    SetPropW(hWnd, L"Balloon", hWndTooltip);
    CTreeList::InitToolTips(hWndTooltip);
  }
  return 1;
}

//----- (00C66020) --------------------------------------------------------
char __cdecl sub_C66020(tagTREEVIEWLISTITEMPARAM *pItem)
{
  tagTREEVIEWLISTITEMPARAM *q; // eax
  tagTREEVIEWLISTITEMPARAM *v2; // esi
  tagTREEVIEWLISTITEMPARAM *p; // edx
  bool v4; // zf
  int v5; // edi
  tagTREEVIEWLISTITEMPARAM *v6; // ecx
  char i; // dl

  LOBYTE(q) = SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  v2 = pItem;
  p = pItem;
  if ( pItem )
  {
    do
    {
      v4 = p->dwProcessId == 0;
      p->field_30 = 0;
      p->pItemParam = 0;
      if ( !v4 )
      {
        q = pItem;
        while ( q->dwProcessId != p->InheritedFromUniqueProcessId
             || *(_QWORD *)&q->CreateTime > *(_QWORD *)&p->CreateTime )
        {
          q = q->m_Prev;
          if ( !q )
            goto LABEL_9;
        }
        p->pItemParam = q;
      }
LABEL_9:
      p = p->m_Prev;
    }
    while ( p );
    if ( pItem )
    {
      do
      {
        v5 = 0;
        v6 = v2->pItemParam;
        for ( i = ((unsigned int)v2->dwStyle >> 1) & 1; v6; ++v5 )
        {
          LOBYTE(q) = -((v6->dwStyle & 4) != 0);
          ++v6->field_30;
          v6 = v6->pItemParam;
          i &= (unsigned __int8)q;
        }
        v2->nSpaceNumber = v5;
        if ( (!i || v2->dwStyle & 1 && gConfig.byte_14012ADFE) && v2->field_2C != -1 )
        {
          if ( !i )
            v2->dwStyle &= -3u;
          LOBYTE(q) = (unsigned int)sub_C28570(ghWndTreeListView, v2);
        }
        v2 = v2->m_Prev;
      }
      while ( v2 );
    }
  }
  return (char)q;
}

//----- (00C66110) --------------------------------------------------------
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
  char *v11; // ecx
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
  v4 = ((int (*)(void))v3->vtptr->GetNilData)();
  ghInstance = ::ghInstance;
  v6.pszData = (CHAR *)(v4 + 16);
  strName.pszData = (CHAR *)(v4 + 16);
  if ( pListParam->field_28 )
  {
    Pages[0].u2.hIcon = 0;
    Pages[0].pfnCallback = 0;
    v2 = 1;
    Pages[0].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[0].dwFlags = PSP_USETITLE;
    Pages[0].hInstance = ::ghInstance;
    Pages[0].u.pszTemplate = L"HANDLEINFO";
    Pages[0].pfnDlgProc = (DLGPROC)PropHandleInfo;
    Pages[0].pszTitle = L"Details";
    Pages[0].lParam = (LPARAM)pListParam;
  }
  if ( *(_DWORD *)CreateSecurityPage )
  {
    if ( _wcsicmp((const wchar_t *)&pListParam->field_38, L"ObjDirectory") )
    {
      if ( _wcsicmp((const wchar_t *)&pListParam->field_38, L"Device") )
      {
        if ( _wcsicmp((const wchar_t *)&pListParam->field_38, L"Process") )
        {
          if ( _wcsicmp((const wchar_t *)&pListParam->field_38, L"Service") )
            nType = _wcsicmp((const wchar_t *)&pListParam->field_38, L"Thread") != 0 ? 1 : 5;
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
    if ( pListParam == (tagHANDLELISTITEMPARAM *)0xFFFFFF48 )
    {
      v10 = 0;
    }
    else
    {
      v11 = (char *)&pListParam[3].field_4;
      v23 = (char *)&pListParam[3].field_4 + 2;
      do
      {
        v12 = *(_WORD *)v11;
        v11 += 2;
      }
      while ( v12 );
      v10 = (v11 - v23) >> 1;
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString(&strName, &pListParam[3].field_4, v10);
    fIsObjDirectory = wcscmp((const unsigned __int16 *)&pListParam->field_38, L"ObjDirectory");
    if ( fIsObjDirectory )
      fIsObjDirectory = -(fIsObjDirectory < 0) | 1;
    v6.pszData = strName.pszData;
    CObjSecurity::Create(pListParam, (LPCWSTR)strName.pszData, &pObjSecurity, nType, fIsObjDirectory == 0);
    nPages = 0;
    PropSheet.dwFlags = PSH_NOAPPLYNOW;
    if ( pListParam->field_28 )
    {
      v22[0] = (int)CreatePropertySheetPageW((LPCPROPSHEETPAGEW)Pages);
      nPages = 1;
    }
    v22[nPages] = (int)CreateSecurityPage((LPSECURITYINFO)pObjSecurity);
    PropSheet.nPages = nPages + 1;
    v8 = (const PROPSHEETPAGEW *)v22;
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
    Pages[nPage].lParam = (LPARAM)pListParam;
    Pages[nPage].pfnCallback = 0;
    PropSheet.nPages = v2 + 1;
    v8 = (const PROPSHEETPAGEW *)Pages;
  }
  v15 = pListParam->field_28 == 0;
  v16 = hWnd;
  PropSheet.ppsp = v8;
  PropSheet.hInstance = ghMainInstance;
  v17 = L"Properties";
  if ( v15 )
    v17 = L"Permissions";
  PropSheet.dwSize = sizeof(PROPSHEETHEADERW);
  PropSheet.hwndParent = hWnd;
  MakeHandlePropSheetCaption(szCaption, L"%s %s", &pListParam[3].field_4, v17);
  PropSheet.nStartPage = 0;
  PropSheet.hwndParent = v16;
  PropSheet.pszCaption = szCaption;
  PropSheet.pfnCallback = 0;
  PropertySheetW(&PropSheet);
  if ( *(_DWORD *)CreateSecurityPage )
    CObjSecurity::~CObjSecurity((int)pObjSecurity);
  v18 = (CStringData *)(v6.pszData - 16);
  result = &v18->nRefs;
  if ( _InterlockedDecrement(&v18->nRefs) <= 0 )
    result = (int *)((int (__stdcall *)(CStringData *))v18->pStringMgr->vtptr->Free)(v18);
  return result;
}
// CB2AE8: using guessed type wchar_t aSecurity_1[9];
// CB5140: using guessed type wchar_t aHandleinfo[11];
// CB5158: using guessed type wchar_t aDetails[8];
// CB5168: using guessed type wchar_t aSecurity_0[9];
// CB51A8: using guessed type wchar_t aProperties_0[11];
// CB51C0: using guessed type wchar_t aPermissions[12];
// C66110: using guessed type int var_42C[2];

//----- (00C66450) --------------------------------------------------------
HANDLE __cdecl CTreeList::FillTreeViewParam(tagTREEVIEWLISTITEMPARAM *pInfo)
{
  InterlockedIncrement(&pInfo->nRefCount);
  return _beginthread((int)CTreeList::BackendFillTreeViewParamThreadProc, 0, (int)pInfo);
}

//----- (00C66480) --------------------------------------------------------
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
  v1 = LoadCursorW(0, (LPCWSTR)IDC_APPSTARTING);
  SetCursor(v1);
  propItem = (tagPropItem *)malloc(sizeof(tagPropItem));
  PropItem = propItem;
  v10 = propItem;
  memset(propItem, 0, sizeof(tagPropItem));
  PropItem->pListItem = hAccTable;
  hDlgPropSheet = CreateDialogParamW(
                    ghMainInstance,
                    L"PROCPROPSHEET",
                    ghMainWnd,
                    (DLGPROC)ProcPropSheet,
                    (LPARAM)PropItem);
  hAccTablea = LoadAcceleratorsW(ghMainInstance, L"DLLPROPERTIES");
  for ( result = GetMessageW(&msg, 0, 0, 0); result; result = GetMessageW(&msg, 0, 0, 0) )
  {
    v6 = (int)PropItem + sizeof(PROPPAGEDATA) * PropItem->nTabIndex;
    v7 = *(_DWORD *)(v6 + 8);
    if ( v7 && TranslateAcceleratorW((HWND)v7, hAccTablea, &msg) )
      continue;
    v8 = (HWND)GetPropW(hDlgPropSheet, L"FindWindow");
    if ( !v8 )
    {
LABEL_8:
      if ( !IsDialogMessageW(*(HWND *)(v6 + 8), &msg) && !IsDialogMessageW(hDlgPropSheet, &msg) )
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

//----- (00C66600) --------------------------------------------------------
HANDLE CDriver::Close()
{
  HANDLE result; // eax

  result = ghDriverHandle;
  if ( ghDriverHandle != (HANDLE)INVALID_HANDLE_VALUE )
    result = (HANDLE)CloseHandle(ghDriverHandle);
  return result;
}

//----- (00C66620) --------------------------------------------------------
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
// C66620: using guessed type bool __cdecl GetProcessDEPStatus();
// CD4E54: using guessed type int gdwVersion;

//----- (00C666B0) --------------------------------------------------------
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
  tagDLLLISTITEMPARAM *v14; // eax
  LPARAM v15; // eax
  CResizer *v16; // eax
  HWND v17; // eax
  LONG v18; // eax
  HWND v19; // eax
  _IMAGELIST *v20; // edi
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
  LRESULT nItemMatched; // eax
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

  hCursor = (HCURSOR)hDlg;
  if ( !(dword_CF54C8 & 1) )
  {
    dword_CF54C8 |= 1u;
    gwWidthsOfListInFindDlg[0] = MulDiv(75, gLogPixelSize.x, 96);
    gwWidthsOfListInFindDlg[1] = MulDiv(-1, gLogPixelSize.x, 96);
    gwWidthsOfListInFindDlg[2] = MulDiv(50, gLogPixelSize.x, 96);
    gwWidthsOfListInFindDlg[3] = MulDiv(150, gLogPixelSize.x, 96);
  }
  lParam.mask = 0;
  memset(&lParam.iItem, 0, 0x30u);
  _mm_storeu_si128((__m128i *)nIDs, _mm_load_si128((const __m128i *)dword_CB6C30));
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
      SendMessageW(ghWndListInFindDlg, LVM_SORTITEMS, gnColumnSortedInFindDlg, (LPARAM)FindDlg_SortCallback);
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
    if ( (_WORD)wParamIn == IDC_FINDDLG_BUTTON_CANCEL )
    {
      gbSearching = 1;
      return 0;
    }
    if ( (_WORD)wParamIn == 2 )
    {
      v31 = GetDlgItem(hDlg, IDC_FINDDLG_BUTTON_CANCEL);
      if ( IsWindowEnabled(v31) )
      {
        SendMessageW(hDlg, WM_COMMAND, IDC_FINDDLG_BUTTON_CANCEL, 0);
        return 1;
      }
    }
    else if ( (_WORD)wParamIn != 1 )
    {
      if ( (_WORD)wParamIn == IDC_FINDDLG_BUTTON_SEARCH )
      {
        dword_CF54D0 = -1;
        GetDlgItemTextW(hDlg, IDC_FINDDLG_EDIT, gszStringToFindLast, 256);
        if ( wcslen(gszStringToFindLast) )
        {
          CTreeList::InitHeaderColumn(
            ghWndListInFindDlg,
            gnColumnSortedInFindDlg,
            (HWND)gnColumnSortedInFindDlg,
            byte_CCE8B0);
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
          ghThreadHandleInFindDlg = (HANDLE)_beginthreadex(0, 0, (int)FindDlg_SearchThreadProc, (int)&gbSearching, 0, 0);
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
    wcscpy_s((wchar_t *)gszStringToFind, 256u, gszStringToFindLast);
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
          SetDlgItemTextW(hDlg, IDC_FINDDLG_STATIC_RESULT, (LPCWSTR)&gszNullString);
          CTreeList::InitListCtrl(ghWndListInFindDlg, (WPARAM)ghConfigFont);
          SendMessageW(ghWndListInFindDlg, 0x1009u, 0, 0);
          SetDlgItemTextW(hDlg, IDC_FINDDLG_STATIC_SUBSTRING, L"Handle or DLL substring:");
          gdwRefreshRateLast = gConfig.dwRefreshRate;
          gConfig.dwRefreshRate = 0;
          SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, (LPARAM)L"Paused");
          return 1;
        }
        gConfig.dwRefreshRate = gdwRefreshRateLast;
        SetEvent(ghRefreshEventHandle);
        if ( !gdwRefreshRateLast )
          return 1;
        SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, (LPARAM)&gszNullString);
        return 1;
      case WM_DRAWITEM:
        CMainWnd::DrawItem((LPDRAWITEMSTRUCT)lParamIn);
        return 0;
      case WM_MEASUREITEM:
        return CMainWnd::HandleMeasureItem(hDlg, uMsg, wParamIn, (LPMEASUREITEMSTRUCT)lParamIn);
      case 0x4Eu:
        switch ( *(_DWORD *)(lParamIn + 8) )
        {
          case 0xFFFFFF94:
            v5 = *(HWND *)(lParamIn + 16);
            if ( v5 == (HWND)gnColumnSortedInFindDlg )
            {
              v6 = byte_CCE8B0 == 0;
              byte_CCE8B0 = byte_CCE8B0 == 0;
            }
            else
            {
              v6 = byte_CCE8B0;
            }
            CTreeList::InitHeaderColumn(*(HWND *)lParamIn, gnColumnSortedInFindDlg, v5, v6);
            gnColumnSortedInFindDlg = *(_DWORD *)(lParamIn + 16);
            SendMessageW(*(HWND *)lParamIn, 0x1030u, gnColumnSortedInFindDlg, (LPARAM)FindDlg_SortCallback);
            return 0;
          case 0xFFFFFF99:
            lParam.iItem = *(_DWORD *)(lParamIn + 12);
            v7 = *(HWND *)lParamIn;
            lParam.iSubItem = 0;
            lParam.mask = 4;
            SendMessageW(v7, 0x104Bu, 0, (LPARAM)&lParam);
            v8 = lParam.lParam;
            if ( lParam.lParam->nRefCount )
            {
              free((void *)lParam.lParam->nRefCount);
              v8 = lParam.lParam;
            }
            v9 = (void *)v8->field_B4;
            if ( v9 )
              free(v9);
            return 0;
          case 0xFFFFFF9B:
          case 0xFFFFFFFD:
          case 0xFFFFFFFE:
            if ( dword_CF54D0 == SendMessageW(*(HWND *)lParamIn, LVM_GETNEXTITEM, 0xFFFFFFFF, 2) )
              return 0;
            dword_CF54D0 = SendMessageW(*(HWND *)lParamIn, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( dword_CF54D0 == -1 )
              return 0;
            hCursor = SetCursor(::hCursor);
            v10 = *(HWND *)lParamIn;
            lParam.iItem = dword_CF54D0;
            lParam.iSubItem = 0;
            lParam.mask = 4;
            if ( SendMessageW(v10, LVM_GETITEMW, 0, (LPARAM)&lParam) != 1 )
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
            lParam.iItem = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&v40);
            v38 = 3;
            v37 = 3;
            SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, lParam.iItem, (LPARAM)&v36);
            SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, lParam.iItem, 0);
            gdwProcessIdSelected = v43->field_A8;
            if ( !gConfig.bShowLowerPane )
              Command_ShowLowerPane(0);
            v12 = (int)v43;
            if ( v43->field_B0 )
            {
              if ( gConfig.bShowDllView )
              {
                Command_ShowHandlesPane(0);
                v12 = (int)v43;
              }
              CMainWnd::RefreshHandlesView((signed int)hDlg, ghWndHandlesListCtrl, *(_DWORD *)(v12 + 168), 0);
              SendMessageW(ghMainWnd, 0x7E8u, 0x66u, 0);
            }
            else
            {
              if ( !gConfig.bShowDllView )
              {
                Command_ShowDllsPane(0);
                v12 = (int)v43;
              }
              CMainWnd::RefreshDllsView((signed int)hDlg, ghWndDllsListCtrl, *(_DWORD *)(v12 + 168), 0);
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
                lParam.iItem = SendMessageW(ghWndDllsListCtrl, 0x1053u, 0xFFFFFFFF, (LPARAM)&v40);
                v38 = 3;
                v37 = 3;
                SendMessageW(ghWndDllsListCtrl, 0x102Bu, lParam.iItem, (LPARAM)&v36);
                SendMessageW(ghWndDllsListCtrl, 0x1013u, lParam.iItem, 0);
                if ( *(_DWORD *)(lParamIn + 8) == -3 )
                {
                  SetFocus(ghWndDllsListCtrl);
                  PostMessageW(hDlg, 0x111u, 2u, 0);
                  SetCursor(hCursor);
                  return 0;
                }
              }
              goto LABEL_41;
            }
            v15 = pItemParam;
            if ( !pItemParam )
              goto LABEL_41;
            while ( *(_DWORD *)(v15 + 44) != v13 )
            {
              v15 = *(_DWORD *)(v15 + 4280);
              if ( !v15 )
              {
                SetCursor(hCursor);
                return 0;
              }
            }
            v41 = (void *)v15;
            v40 = 1;
            lParam.iItem = SendMessageW(ghWndHandlesListCtrl, 0x1053u, 0xFFFFFFFF, (LPARAM)&v40);
            v38 = 3;
            v37 = 3;
            SendMessageW(ghWndHandlesListCtrl, 0x102Bu, lParam.iItem, (LPARAM)&v36);
            SendMessageW(ghWndHandlesListCtrl, 0x1013u, lParam.iItem, 0);
            if ( *(_DWORD *)(lParamIn + 8) != -3 )
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
  v16 = (CResizer *)operator new(0x40u);
  if ( v16 )
    CResizer::CResizer(v16, hDlg);
  ghMainIcon = (int)LoadIconW(ghInstance, (LPCWSTR)0x65);
  SendMessageW(hDlg, WM_SETICON, 0, ghMainIcon);
  v17 = GetDlgItem(hDlg, 1001);
  ghWndListInFindDlg = v17;
  v18 = GetWindowLongW(v17, -16);
  SetWindowLongW(ghWndListInFindDlg, GWL_STYLE, v18 & -3u | LVS_REPORT);
  SetWindowLongW(ghWndListInFindDlg, GWL_USERDATA, 3);
  SendMessageW(ghWndListInFindDlg, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 0x4020);
  v19 = (HWND)SendMessageW(ghWndListInFindDlg, LVM_GETTOOLTIPS, 0, 0);
  CTreeList::InitToolTips(v19);
  gOldListWndProc = (WNDPROC)SetWindowLongW(ghWndListInFindDlg, GWLP_WNDPROC, (LONG)Proxy_ListCtrlWndProc);
  SendMessageW(ghWndListInFindDlg, WM_SETFONT, (WPARAM)ghConfigFont, 0);
  v20 = ImageList_Create(16, 16, 1u, 256, 256);
  ghMainIcon = (int)LoadIconW(ghInstance, (LPCWSTR)0xCB);
  ImageList_ReplaceIcon(v20, -1, (HICON)ghMainIcon);
  ghMainIcon = (int)LoadIconW(ghInstance, (LPCWSTR)0x71);
  ImageList_ReplaceIcon(v20, -1, (HICON)ghMainIcon);
  v21 = GetWindowLongW(ghWndListInFindDlg, -16);
  SetWindowLongW(ghWndListInFindDlg, -16, v21 | 0x40);
  SendMessageW(ghWndListInFindDlg, 0x1003u, 1u, (LPARAM)v20);
  if ( gwWidthsOfListInFindDlg[1] == -1 )
    gwWidthsOfListInFindDlg[1] = MulDiv(40, gLogPixelSize.x, 96);
  nWidths = *(_DWORD *)gwWidthsOfListInFindDlg;
  v47 = *(_DWORD *)&gwWidthsOfListInFindDlg[2];
  InitListHeader(ghWndListInFindDlg, (UINT *)nIDs, (WORD *)&nWidths, 4);
  SendMessageW(ghWndListInFindDlg, LVM_SETCOLUMNWIDTH, 3u, 65534);
  v22 = hCursor;
  SetDlgItemTextW((HWND)hCursor, 1002, gszStringToFind);
  if ( gnWidthFindDlg )
  {
    MoveWindow((HWND)v22, gRectFindDlg.left, gRectFindDlg.top, gnWidthFindDlg, gnHeightFindDlg, 0);
    ShowWindow((HWND)v22, 1);
    result = 1;
  }
  else
  {
    if ( gConfig.WindowPlacement[2].ptMaxPosition.y )
      SetWindowPlacement((HWND)v22, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[1] + 16));
    ShowWindow((HWND)v22, 1);
    result = 1;
  }
  return result;
}
// C4BBC0: using guessed type int __stdcall FindDlg_SortCallback(int, int, int);
// CB0D80: using guessed type wchar_t aPaused[7];
// CB6C30: using guessed type int dword_CB6C30[4];
// CCE8B0: using guessed type char byte_CCE8B0;
// CF54C0: using guessed type __int16 gwWidthsOfListInFindDlg[4];
// CF54C8: using guessed type int dword_CF54C8;
// CF54D0: using guessed type int dword_CF54D0;
// CF54D4: using guessed type int gdwRefreshRateLast;
// CF54F0: using guessed type int ghMainIcon;
// CF54F4: using guessed type char gbSearching;
// CF5720: using guessed type int gnStatusBarItemCount;

//----- (00C67400) --------------------------------------------------------
void __cdecl PE_QueryMemoryInfo(signed __int64 a1, double *pdbUnavailPageFile, DWORD pdwUnavailPhys, double *pdbMemorySize)
{
  double v4; // xmm0_8
  double v5; // xmm1_8
  double dbUnavailPageFile; // xmm3_8
  DWORD v7; // ecx
  double dbMemorySize; // xmm4_8
  double v9; // xmm5_8
  double dwUnavailPageFile; // xmm1_8
  double v11; // xmm1_8
  struct _FILETIME SystemTimeAsFileTime; // [esp+28h] [ebp-84h]
  double v13; // [esp+30h] [ebp-7Ch]
  double dwUnavailPhys; // [esp+38h] [ebp-74h]
  double v15; // [esp+40h] [ebp-6Ch]
  MEMORYSTATUSEX MemoryStatusX; // [esp+48h] [ebp-64h]
  struct _MEMORYSTATUS MemoryStatus; // [esp+88h] [ebp-24h]

  v13 = 0.0;
  MemoryStatus.dwLength = 32;
  GlobalMemoryStatus(&MemoryStatus);
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  if ( GlobalMemoryStatusEx )
  {
    MemoryStatusX.dwLength = 64;
    GlobalMemoryStatusEx(&MemoryStatusX);
    if ( a1 )
    {
      dwUnavailPhys = (double)a1;
      v15 = (double)a1 / (double)(signed __int64)MemoryStatusX.ullTotalPageFile * 100.0;
      goto LABEL_11;
    }
    gpGraphInfoOfMemory->m_dbMemorySize = (double)(signed __int64)MemoryStatusX.ullTotalPageFile * 0.0009765625;
    gpGraphInfoOfPhysicalMemory->m_dbMemorySize = (double)(signed __int64)MemoryStatusX.ullTotalPhys * 0.0009765625;
    dwUnavailPhys = (double)(MemoryStatusX.ullTotalPhys - MemoryStatusX.ullAvailPhys) * 0.0009765625;
    v13 = (double)(signed __int64)(MemoryStatusX.ullTotalPageFile - MemoryStatusX.ullAvailPageFile);
    v15 = v13 * 100.0;
    v4 = (double)(signed __int64)MemoryStatusX.ullTotalPageFile;
    v5 = v13 * 100.0;
    dbUnavailPageFile = v13 * 0.0009765625;
    v7 = MemoryStatus.dwTotalPageFile;
    dbMemorySize = (double)(MemoryStatusX.ullTotalPhys - MemoryStatusX.ullAvailPhys) * 0.0009765625;
    v9 = db_onehundred;
  }
  else
  {
    if ( a1 )
    {
      v15 = (double)a1 / (double)MemoryStatus.dwTotalPageFile * 100.0;
      goto LABEL_11;
    }
    v9 = db_onehundred;
    gpGraphInfoOfMemory->m_dbMemorySize = (double)MemoryStatus.dwTotalPageFile * 0.0009765625;
    gpGraphInfoOfPhysicalMemory->m_dbMemorySize = (double)MemoryStatus.dwTotalPhys * 0.0009765625;
    v7 = MemoryStatus.dwTotalPageFile;
    dbMemorySize = (double)(MemoryStatus.dwTotalPhys - MemoryStatus.dwAvailPhys) * 0.0009765625;
    dwUnavailPhys = (double)(MemoryStatus.dwTotalPhys - MemoryStatus.dwAvailPhys) * 0.0009765625;
    dwUnavailPageFile = (double)(MemoryStatus.dwTotalPageFile - MemoryStatus.dwAvailPageFile);
    dbUnavailPageFile = dwUnavailPageFile * 0.0009765625;
    v4 = (double)MemoryStatus.dwTotalPageFile;
    v5 = dwUnavailPageFile * 100.0;
  }
  v13 = dbUnavailPageFile;
  v15 = v5 / v4;
  if ( dbUnavailPageFile < 0.0 )
  {
    v15 = v9;
    v13 = (double)(v7 >> 10);
  }
  CGraphData_Update(gpGraphInfoOfPhysicalMemory, SystemTimeAsFileTime, dbMemorySize, 0.0, 0);
  CGraphData_Update(gpGraphInfoOfMemory, SystemTimeAsFileTime, v13, 0.0, 0);
LABEL_11:
  v11 = dwUnavailPhys;
  if ( pdbUnavailPageFile )
    *pdbUnavailPageFile = v13;
  if ( pdwUnavailPhys )
    *(double *)pdwUnavailPhys = v11;
  if ( pdbMemorySize )
    *pdbMemorySize = gpGraphInfoOfPhysicalMemory->m_dbMemorySize;
}
// CACDC0: using guessed type double db_onehundred;
// CDF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);

//----- (00C67720) --------------------------------------------------------
int __cdecl sub_C67720(int a1, wchar_t *Dst, rsize_t SizeInWords)
{
  int v3; // eax
  int result; // eax
  int v5; // [esp+8h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 636);
  v5 = v3;
  if ( (_BYTE)v3 == -1 )
    return wcscpy_s(Dst, SizeInWords, L"n/a");
  if ( v3 & 1 )
    result = wcscpy_s(Dst, SizeInWords, L"Enabled");
  else
    result = wcscpy_s(Dst, SizeInWords, L"Disabled");
  if ( v5 & 8 )
    result = wcscat_s(Dst, SizeInWords, L" (permanent)");
  return result;
}

//----- (00C67790) --------------------------------------------------------
int __cdecl sub_C67790(int a1, wchar_t *Dst, size_t SizeInWords)
{
  int result; // eax

  if ( a1 == -1 )
    return swprintf_s(Dst, SizeInWords, (const wchar_t *)&gszNullString);
  switch ( a1 )
  {
    case 0:
      result = swprintf_s(Dst, SizeInWords, L"Very Low");
      break;
    case 1:
      result = swprintf_s(Dst, SizeInWords, L"Low");
      break;
    case 2:
      result = swprintf_s(Dst, SizeInWords, L"Normal");
      break;
    case 3:
      result = swprintf_s(Dst, SizeInWords, L"High");
      break;
    case 4:
      result = swprintf_s(Dst, SizeInWords, L"Critical");
      break;
    default:
      result = swprintf_s(Dst, SizeInWords, L"%d", a1);
      break;
  }
  return result;
}

//----- (00C67850) --------------------------------------------------------
void *__cdecl QuerySystemHandleInfo(ULONG ReturnLength)
{
  int v1; // eax
  ULONG v2; // esi
  SYSTEM_HANDLE_INFORMATION *v3; // eax
  _SYSTEM_INFORMATION_CLASS v4; // eax
  void *result; // eax
  ULONG v6; // esi
  SYSTEM_HANDLE_INFORMATION *v7; // eax
  _SYSTEM_INFORMATION_CLASS v8; // eax
  size_t v9; // esi
  ULONG v10; // esi
  SYSTEM_HANDLE_INFORMATION *v11; // eax
  _SYSTEM_INFORMATION_CLASS ClassInfo; // eax
  size_t v13; // esi
  _SYSTEM_INFORMATION_CLASS v14; // eax
  SYSTEM_HANDLE_INFORMATION *v15; // [esp-Ch] [ebp-14h]
  SYSTEM_HANDLE_INFORMATION *v16; // [esp-Ch] [ebp-14h]
  SYSTEM_HANDLE_INFORMATION *v17; // [esp-Ch] [ebp-14h]

  if ( ReturnLength )
  {
    if ( gpSystemHandleInfo )
      free(gpSystemHandleInfo);
    v10 = gdwSystemHandleInfoLength;
    v11 = (SYSTEM_HANDLE_INFORMATION *)malloc(gdwSystemHandleInfoLength);
    gpSystemHandleInfo = v11;
    v17 = v11;
    ClassInfo = SystemHandleInformation;
    if ( gbSupportExtendedSystemHandleInformation )
      ClassInfo = SystemExtendedHandleInformation;
    result = (void *)NtQuerySystemInformation(ClassInfo, v17, v10, &ReturnLength);
    if ( result )
    {
      while ( result != (void *)STATUS_ACCESS_DENIED )
      {
        free(gpSystemHandleInfo);
        gdwSystemHandleInfoLength *= 2;
        v13 = gdwSystemHandleInfoLength;
        gpSystemHandleInfo = (SYSTEM_HANDLE_INFORMATION *)malloc(gdwSystemHandleInfoLength);
        memset(gpSystemHandleInfo, 0, v13);
        v14 = 16;
        if ( gbSupportExtendedSystemHandleInformation )
          v14 = SystemExtendedHandleInformation;
        result = (void *)NtQuerySystemInformation(v14, gpSystemHandleInfo, v13, &ReturnLength);
        if ( !result )
          return result;
      }
      result = memset(gpSystemHandleInfo, 0, gdwSystemHandleInfoLength);
    }
  }
  else
  {
    if ( gpSystemHandleInfo3 )
      free(gpSystemHandleInfo3);
    v1 = gdwProcessIdSelected;
    gpSystemHandleInfo3 = 0;
    if ( gdwValue_4F10B8[2] == gdwProcessIdSelected )
    {
      gpSystemHandleInfo3 = gpSystemHandleInfo2;
    }
    else
    {
      if ( gpSystemHandleInfo2 )
      {
        free(gpSystemHandleInfo2);
        v1 = gdwProcessIdSelected;
      }
      gdwValue_4F10B8[2] = v1;
    }
    v2 = gdwSystemHandleInfoLength;
    v3 = (SYSTEM_HANDLE_INFORMATION *)malloc(gdwSystemHandleInfoLength);
    gpSystemHandleInfo2 = v3;
    v15 = v3;
    v4 = SystemHandleInformation;
    if ( gbSupportExtendedSystemHandleInformation )
      v4 = SystemExtendedHandleInformation;
    result = (void *)NtQuerySystemInformation(v4, v15, v2, &ReturnLength);
    if ( result )
    {
      while ( result != (void *)STATUS_ACCESS_DENIED )
      {
        if ( result == (void *)STATUS_INSUFFICIENT_RESOURCES )
        {
          MessageBoxW(
            NULL,
            L"Insufficient system resources to get handle information.",
            L"Process Explorer",
            MB_ICONERROR);
          v9 = gdwSystemHandleInfoLength;
          memset(gpSystemHandleInfo2, 0, gdwSystemHandleInfoLength);
          return memset(gpSystemHandleInfo2, 0, v9);
        }
        free(gpSystemHandleInfo2);
        gdwSystemHandleInfoLength *= 2;
        v6 = gdwSystemHandleInfoLength;
        v7 = (SYSTEM_HANDLE_INFORMATION *)malloc(gdwSystemHandleInfoLength);
        gpSystemHandleInfo2 = v7;
        v16 = v7;
        v8 = 16;
        if ( gbSupportExtendedSystemHandleInformation )
          v8 = SystemExtendedHandleInformation;
        result = (void *)NtQuerySystemInformation(v8, v16, v6, &ReturnLength);
        if ( !result )
          return result;
      }
      result = memset(gpSystemHandleInfo2, 0, gdwSystemHandleInfoLength);
    }
  }
  return result;
}
// CD10B8: using guessed type int gdwValue_4F10B8[3];
// CDABA5: using guessed type char gbSupportExtendedSystemHandleInformation;

//----- (00C67A70) --------------------------------------------------------
signed int OnBeforeInit()
{
  int v0; // eax
  HMODULE v1; // eax
  int dwNumberOfProcessors; // esi
  signed int result; // eax
  int Status; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  char v8; // cl
  HMODULE v9; // eax
  HMODULE v10; // eax
  HMODULE v11; // eax
  HMODULE v12; // eax
  unsigned int nIndex; // edx
  RegItem *pItem; // ecx
  __int16 v15; // ax
  unsigned int nIndex_1; // edx
  wchar_t *v17; // ecx
  wchar_t v18; // ax
  double dwTotalPageFile; // xmm0_8
  void (__stdcall *GlobalMemoryStatusEx)(LPMEMORYSTATUS); // esi
  CGraphData *v21; // eax
  DWORD dwVersion; // [esp+10h] [ebp-80h]
  _MEMORYSTATUSEX MemoryStatusEx; // [esp+14h] [ebp-7Ch]
  struct _MEMORYSTATUS MemoryStatus; // [esp+54h] [ebp-3Ch]
  CPPEH_RECORD ms_exc; // [esp+78h] [ebp-18h]

  dwVersion = 152;
  ghMainInstance = ghInstance;
  v0 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
  gdwVirtualScreenWidth = v0;
  if ( !v0 )
    v0 = GetSystemMetrics(SM_CXSCREEN);
  gdwVirtualScreenWidth = v0 / 2;
  v1 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)GetLongPathNameW = GetProcAddress(v1, "GetLongPathNameW");
  dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
  gpSystemPerformanceInfo = (SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *)malloc(
                                                                          sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION)
                                                                        * gSystemInfo.dwNumberOfProcessors);
  gpSystemInterruptInfo = (SYSTEM_INTERRUPT_INFORMATION *)malloc(sizeof(SYSTEM_INTERRUPT_INFORMATION) * dwNumberOfProcessors);
  gpSystemProcessorCycleTimeInfo = (SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *)malloc(8 * dwNumberOfProcessors);
  TmAdjustPrivilege(L"SeDebugPrivilege");
  TmAdjustPrivilege(L"SeBackupPrivilege");
  TmAdjustPrivilege(L"SeSecurityPrivilege");
  if ( !CDriver::Load() )
    goto LABEL_7;
  dwNumberOfProcessors = (int)VirtualAlloc(NULL, 4u, MEM_COMMIT, PAGE_READWRITE);
  ms_exc.registration.TryLevel = 0;
  if ( !CDriver::Control(0x83350008, &dwVersion, 4u, (LPVOID)dwNumberOfProcessors, 4u)
    || *(_DWORD *)dwNumberOfProcessors < dwVersion )
  {
    CDriver::Close();
    if ( CDriver::Load() )
    {
      if ( CDriver::Control(0x83350008, &dwVersion, 4u, (LPVOID)dwNumberOfProcessors, 4u)
        && *(_DWORD *)dwNumberOfProcessors >= dwVersion )
      {
        goto LABEL_16;
      }
      MessageBoxW(
        0,
        L"Driver version mismatch. You must reboot before you can run this version of Process Explorer.",
        L"Process Explorer",
        MB_ICONERROR);
    }
    CDriver::Close();
LABEL_16:
    ms_exc.registration.TryLevel = -2;
    return 0;
  }
  ms_exc.registration.TryLevel = -2;
  VirtualFree((LPVOID)dwNumberOfProcessors, 4u, MEM_DECOMMIT);
LABEL_7:
  if ( LoadSystemApis() )
  {
    Status = NtQuerySystemInformation(SystemExtendedHandleInformation, 0, 0, 0);
    if ( Status == STATUS_INVALID_INFO_CLASS
      || (gbSupportExtendedSystemHandleInformation = 1, Status == STATUS_NOT_IMPLEMENTED) )
    {
      gbSupportExtendedSystemHandleInformation = 0;
    }
    ghSCManagerHandle = OpenSCManagerW(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
    *(_DWORD *)EnumServicesStatusExW = 0;
    if ( ghSCManagerHandle )
    {
      v5 = GetModuleHandleW(L"advapi32.dll");
      *(_DWORD *)EnumServicesStatusExW = GetProcAddress(v5, "EnumServicesStatusExW");
      v6 = GetModuleHandleW(L"advapi32.dll");
      *(_DWORD *)QueryServiceConfig2W = GetProcAddress(v6, "QueryServiceConfig2W");
    }
    if ( IsWinServer((int)GetModuleHandleW, dwNumberOfProcessors) )
    {
      v7 = GetModuleHandleW(L"kernel32.dll");
      gpfnProcessIdToSessionId = (int (__stdcall *)(DWORD, DWORD *))GetProcAddress(v7, "ProcessIdToSessionId");
      v8 = gbProcessIdToSessionIdValid;
      if ( gpfnProcessIdToSessionId )
        v8 = 1;
      gbProcessIdToSessionIdValid = v8;
    }
    v9 = LoadLibraryW(L"winsta.dll");
    WinStationGetProcessSid = (int (__stdcall *)(HANDLE, DWORD, FILETIME, LPBYTE, PDWORD))GetProcAddress(
                                                                                            v9,
                                                                                            "WinStationGetProcessSid");
    v10 = GetModuleHandleW(L"kernel32.dll");
    *(_DWORD *)IsProcessInJob = GetProcAddress(v10, "IsProcessInJob");
    v11 = GetModuleHandleW(L"kernel32.dll");
    *(_DWORD *)QueryInformationJobObject = GetProcAddress(v11, "QueryInformationJobObject");
    v12 = GetModuleHandleW(L"kernel32.dll");
    *(_DWORD *)SetProcessAffinityMask = GetProcAddress(v12, "SetProcessAffinityMask");
    InitializeCriticalSection(&gServiceLock);
    GetDriverNameAndLinkInfo();
    nIndex = 0;
    do
    {
      pItem = &aRegistryUser_1[nIndex / 0x244];
      do
      {
        v15 = pItem->field_0;
        pItem = (RegItem *)((char *)pItem + 2);
      }
      while ( v15 );
      dword_CD09E8[nIndex / 4] = (WCHAR *)(((char *)pItem - ((char *)&aRegistryUser_1[nIndex / 0x244].field_0 + 2)) >> 1);
      nIndex += 0x244;
    }
    while ( nIndex < 2320 );
    nIndex_1 = 0;
    do
    {
      v17 = &aRegistryUser_0[nIndex_1 / 2];
      do
      {
        v18 = *v17;
        ++v17;
      }
      while ( v18 );
      dword_CD0560[nIndex_1 / 4] = (WCHAR *)(v17 - &aRegistryUser_0[nIndex_1 / 2 + 1]);
      nIndex_1 += 580;
    }
    while ( nIndex_1 < 0x488 );
    LoadNetClrMemoryPerformanceInfo();
    if ( gdwVersion >= 1 )
      QueryTagInformationEx((PVOID *)&ppv, 0, &pdwValue3, &pdwValue4);
    gpGraphInfoOfCPU = InitGraphData(1, 2, 1);
    gpGraphInfoOfCPU->m_nItemID = 0;
    gpGraphInfoOfCPU->m_Color = 0x3C943C;
    gpGraphInfoOfCPU->m_dbMemorySize = db_onehundred;
    if ( gpGraphInfoOfCPU->m_nChildID == 2 )
    {
      gpGraphInfoOfCPU->m_Item[0].Color = 255;
      gpGraphInfoOfCPU->m_Item[0].dbMemorySize = db_onehundred;
    }
    gpGraphInfoOfMemory = InitGraphData(1, 1, 0);
    gpGraphInfoOfMemory->m_nItemID = 1;
    gpGraphInfoOfMemory->m_Color = 0xAAAA;
    if ( ::GlobalMemoryStatusEx )
    {
      MemoryStatusEx.dwLength = 64;
      ::GlobalMemoryStatusEx(&MemoryStatusEx);
      dwTotalPageFile = (double)(signed __int64)MemoryStatusEx.ullTotalPageFile;
      GlobalMemoryStatusEx = GlobalMemoryStatus;
    }
    else
    {
      MemoryStatus.dwLength = sizeof(_MEMORYSTATUS);
      GlobalMemoryStatusEx = GlobalMemoryStatus;
      GlobalMemoryStatus(&MemoryStatus);
      dwTotalPageFile = (double)MemoryStatus.dwTotalPageFile;
    }
    gpGraphInfoOfMemory->m_dbMemorySize = dwTotalPageFile * 0.0009765625;
    MemoryStatus.dwLength = 32;
    GlobalMemoryStatusEx(&MemoryStatus);
    v21 = InitGraphData(2, 1, 0);
    gpGraphInfoOfPhysicalMemory = v21;
    v21->m_nItemID = 3;
    gpGraphInfoOfPhysicalMemory->m_Color = 0x4080FF;
    gpGraphInfoOfPhysicalMemory->m_dbMemorySize = (float)MemoryStatus.dwTotalPhys;
    GraphInfo_Init(&gIOGraphInfo);
    GraphInfo_Init(&gNetworkGraphInfo);
    GraphInfo_Init(&gDiskGraphInfo);
    sub_C4E920();
    result = 1;
  }
  else
  {
    if ( ghDriverHandle != (HANDLE)-1 )
      CloseHandle(ghDriverHandle);
    result = 0;
  }
  return result;
}
// CACDC0: using guessed type double db_onehundred;
// CD0320: using guessed type wchar_t aRegistryUser_0[16];
// CD4E28: using guessed type int gdwVirtualScreenWidth;
// CD4E54: using guessed type int gdwVersion;
// CDA38A: using guessed type char gbProcessIdToSessionIdValid;
// CDABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// CDF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);

//----- (00C67F90) --------------------------------------------------------
LRESULT __cdecl sub_C67F90(HWND hWnd, int a2, int a3)
{
  LRESULT result; // eax
  LPARAM lParam; // [esp+0h] [ebp-34h]
  LRESULT v5; // [esp+4h] [ebp-30h]
  int v6; // [esp+8h] [ebp-2Ch]
  int v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+10h] [ebp-24h]
  int v9; // [esp+14h] [ebp-20h]
  int v10; // [esp+1Ch] [ebp-18h]
  int v11; // [esp+20h] [ebp-14h]

  memset(&v5, 0, 0x30u);
  v9 = a2;
  lParam = 5;
  v5 = 0x7FFFFFFF;
  v6 = 0;
  v8 = 0;
  v7 = 0;
  v10 = 0;
  v11 = 1;
  result = SendMessageW(hWnd, 0x104Du, 0, (LPARAM)&lParam);
  if ( result != -1 )
  {
    v5 = result;
    v9 = a3;
    lParam = 1;
    v6 = 1;
    result = SendMessageW(hWnd, 0x104Cu, 0, (LPARAM)&lParam);
  }
  return result;
}

//----- (00C68030) --------------------------------------------------------
char __cdecl PE_ConfirmToKillProcess(LPCWSTR ProcessName, DWORD dwProcessId)
{
  char result; // al
  HANDLE v3; // eax
  void *v4; // esi
  WCHAR Text; // [esp+4h] [ebp-804h]

  if ( gConfig.bConfirmKill
    && (wsprintfW(&Text, L"Are you sure you want to kill %s?", ProcessName),
        MessageBoxW(ghMainWnd, &Text, L"Process Explorer", 0x31u) == 2) )
  {
    SetFocus(ghWndTreeListView);
    result = 0;
  }
  else
  {
    v3 = OpenProcess(1u, 0, dwProcessId);
    v4 = v3;
    if ( v3 )
    {
      if ( TerminateProcess(v3, 1u) )
      {
        CloseHandle(v4);
        Sleep(250u);
        result = 1;
      }
      else
      {
        ReportMsg(L"Error terminating process", ghMainWnd);
        CloseHandle(v4);
        result = 0;
      }
    }
    else
    {
      ReportMsg(L"Error opening process", ghMainWnd);
      result = 0;
    }
  }
  return result;
}

//----- (00C68140) --------------------------------------------------------
void __cdecl PE_ConfirmToKillProcessTree(LPCWSTR ProcessName, DWORD dwProcessId)
{
  tagTREEVIEWLISTITEMPARAM *i; // esi
  tagTREEVIEWLISTITEMPARAM *p; // eax
  HANDLE ProcessHandle; // eax
  void *v5; // edi
  HWND v6; // edi
  DWORD dwErrror; // eax
  WCHAR Buffer[2]; // [esp+0h] [ebp-A08h]
  WCHAR Text[1024]; // [esp+4h] [ebp-A04h]
  WCHAR szText[256]; // [esp+804h] [ebp-204h]

  if ( gConfig.bConfirmKill
    && (wsprintfW(Text, L"Are you sure you want to kill %s and its descendants?", ProcessName),
        MessageBoxW(ghMainWnd, Text, L"Process Explorer", 0x31u) == IDCANCEL) )
  {
    SetFocus(ghWndTreeListView);
  }
  else
  {
    for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
    {
      p = i;
      if ( i )
      {
        while ( p->dwProcessId != dwProcessId )
        {
          p = p->pItemParam;
          if ( !p )
            goto LABEL_17;
        }
        ProcessHandle = OpenProcess(PROCESS_TERMINATE, 0, i->dwProcessId);
        v5 = ProcessHandle;
        if ( ProcessHandle )
        {
          if ( !TerminateProcess(ProcessHandle, 1u) )
          {
            wsprintfW(Text, L"Error terminating %s", i->szProcessName2);
            ReportMsg(Text, ghMainWnd);
          }
          CloseHandle(v5);
        }
        else
        {
          wsprintfW(Text, L"Error opening %s", i->szProcessName2);
          v6 = ghMainWnd;
          dwErrror = GetLastError();
          if ( dwErrror )
          {
            FormatMessageW(0x1100u, 0, dwErrror, 0x400u, Buffer, 0, 0);
            wsprintf(szText, L"%s: %s", Text, *(_DWORD *)Buffer);
            LocalFree(*(HLOCAL *)Buffer);
          }
          else
          {
            wsprintf(szText, L"%s.", Text);
          }
          MessageBoxW(v6, szText, L"Process Explorer", MB_ICONERROR);
        }
      }
LABEL_17:
      ;
    }
    Sleep(250u);
  }
}

//----- (00C68310) --------------------------------------------------------
int __cdecl SystemProcessInfo_GetSystemProcessName(DWORD dwProcessId, LARGE_INTEGER *FileTime, WCHAR *pszText, DWORD dwSize)
{
  int result; // eax
  SYSTEM_PROCESS_INFORMATION *i; // ecx

  if ( dwProcessId == -10 )
    return wcscpy_s(pszText, dwSize, L"Hardware Interrupts and DPCs");
  for ( i = gpSystemProcessInfo;
        (HANDLE)dwProcessId != i->UniqueProcessId || FileTime && i->CreateTime.QuadPart > *(_QWORD *)FileTime;
        i = (SYSTEM_PROCESS_INFORMATION *)((char *)i + i->NextEntryOffset) )
  {
    if ( !i->NextEntryOffset )
      return wcscpy_s(pszText, dwSize, L"<Non-existent Process>");
  }
  if ( i->ImageName.Length )
    result = wcsncpy_s(pszText, dwSize, i->ImageName.Buffer, (unsigned int)i->ImageName.Length >> 1);
  else
    result = wcscpy_s(pszText, dwSize, L"System Idle Process");
  return result;
}

//----- (00C683C0) --------------------------------------------------------
bool __cdecl QueryProcessUsers(HANDLE ProcessHandle, DWORD dwProcessId, int LowTime, wchar_t *pszUserName, DWORD cbUserName, WCHAR *szDomainName, DWORD cbDomainName, LPWSTR pszText, DWORD cbText, BOOL *pbVirtualizationEnabled, BOOL *pbUIAccess)
{
  BOOL Status; // eax
  BOOL (__stdcall *GetTokenInformation)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD); // eax
  BOOL (__stdcall *GetTokenInformation_1)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD); // ebx
  const wchar_t *v14; // eax
  FILETIME FileTime; // [esp+10h] [ebp-A24h]
  HANDLE ProcessHandle_1; // [esp+18h] [ebp-A1Ch]
  LPWSTR pszDomainName; // [esp+1Ch] [ebp-A18h]
  DWORD dwProcessId_1; // [esp+20h] [ebp-A14h]
  void *TokenHandle; // [esp+24h] [ebp-A10h]
  DWORD cbRet; // [esp+28h] [ebp-A0Ch]
  int fOK; // [esp+2Ch] [ebp-A08h]
  WCHAR ReferencedDomainName[256]; // [esp+30h] [ebp-A04h]
  char SidBuf[2048]; // [esp+230h] [ebp-804h]

  ProcessHandle_1 = ProcessHandle;
  dwProcessId_1 = dwProcessId;
  FileTime.dwLowDateTime = LowTime;
  pszDomainName = szDomainName;
  FileTime.dwHighDateTime = (DWORD)pbVirtualizationEnabled;
  TokenHandle = 0;
  HIBYTE(fOK) = 0;
  wcscpy_s(pszUserName, cbUserName, (const wchar_t *)&gszNullString);
  wcscpy_s(szDomainName, cbDomainName, (const wchar_t *)&gszNullString);
  LOBYTE(Status) = (_BYTE)pbVirtualizationEnabled;
  if ( pbVirtualizationEnabled )
    *(_DWORD *)FileTime.dwHighDateTime = 0;
  if ( !WinStationGetProcessSid
    || (LOBYTE(Status) = FileTime.dwLowDateTime, !FileTime.dwLowDateTime)
    || (cbRet = 2048,
        LOBYTE(Status) = WinStationGetProcessSid(
                           0,
                           dwProcessId_1,
                           *(FILETIME *)FileTime.dwLowDateTime,
                           (LPBYTE)SidBuf,
                           &cbRet),
        !(_BYTE)Status) )
  {
LABEL_8:
    if ( !pszText )
      goto LABEL_10;
    goto LABEL_9;
  }
  LOBYTE(Status) = UserInfoWithSIDList_Find(SidBuf, pszUserName, cbUserName, pszDomainName, cbDomainName);
  if ( !(_BYTE)Status )
  {
    LOBYTE(Status) = wcscpy_s(pszUserName, cbUserName, L"<unknown owner>");
    goto LABEL_8;
  }
  HIBYTE(fOK) = 1;
  if ( gdwVersion < WINDOWS_VISTA || !pszText )
    return Status;
LABEL_9:
  LOBYTE(Status) = wcscpy_s(pszText, cbText, (const wchar_t *)&gszNullString);
LABEL_10:
  if ( ProcessHandle_1 )
  {
    Status = DeviceIoControl(
               ghDriverHandle,
               0x8335000C,
               &ProcessHandle_1,
               4u,
               &TokenHandle,
               4u,
               &FileTime.dwLowDateTime,
               0);
    if ( !Status )
    {
      Status = OpenProcessToken(ProcessHandle_1, TOKEN_QUERY, &TokenHandle);
      if ( !Status )
        LOBYTE(Status) = wcscpy_s(pszUserName, cbUserName, L"<unable to open token>");
    }
    if ( TokenHandle )
    {
      GetTokenInformation = ::GetTokenInformation;
      if ( gdwVersion < WINDOWS_VISTA )
        goto LABEL_37;
      if ( !pszText )
      {
LABEL_29:
        if ( gdwVersion >= WINDOWS_VISTA )
        {
          if ( pbUIAccess && !GetTokenInformation(TokenHandle, TokenUIAccess, pbUIAccess, 4u, &cbRet) )
            *pbUIAccess = 0;
          if ( gdwVersion >= WINDOWS_VISTA )
          {
            GetTokenInformation_1 = ::GetTokenInformation;
            if ( FileTime.dwHighDateTime
              && !::GetTokenInformation(
                    TokenHandle,
                    TokenVirtualizationEnabled,
                    (LPVOID)FileTime.dwHighDateTime,
                    4u,
                    &cbRet) )
            {
              *(_DWORD *)FileTime.dwHighDateTime = -1;
            }
            goto LABEL_38;
          }
        }
LABEL_37:
        GetTokenInformation_1 = ::GetTokenInformation;
LABEL_38:
        if ( !HIBYTE(fOK) )
        {
          cbRet = 2048;
          if ( GetTokenInformation_1(TokenHandle, TokenUser, SidBuf, 0x800u, &cbRet) )
          {
            if ( !UserInfoWithSIDList_Find(*(PSID *)SidBuf, pszUserName, cbUserName, pszDomainName, cbDomainName) )
              wcscpy_s(pszUserName, cbUserName, L"<unknown owner>");
          }
          else
          {
            wcscpy_s(pszUserName, cbUserName, L"<unable to query owner>");
          }
        }
        LOBYTE(Status) = CloseHandle(TokenHandle);
        return Status;
      }
      dwProcessId_1 = 0;
      cbRet = 4;
      if ( gdwVersion >= WINDOWS_8 )
      {
        if ( ::GetTokenInformation(TokenHandle, MaxTokenInfoClass, &dwProcessId_1, 4u, &cbRet) && dwProcessId_1 )
        {
          wcscat_s(pszText, cbText, L"AppContainer");
LABEL_28:
          GetTokenInformation = ::GetTokenInformation;
          goto LABEL_29;
        }
        GetTokenInformation = ::GetTokenInformation;
      }
      cbRet = 2048;
      if ( GetTokenInformation(TokenHandle, TokenIntegrityLevel, SidBuf, 0x800u, &cbRet) )
      {
        UserInfoWithSIDList_Find(*(PSID *)SidBuf, pszText, cbText, ReferencedDomainName, 0x100u);
        if ( wcsstr(pszText, L" Mandatory Level") )
          *wcsstr(pszText, L" Mandatory Level") = 0;
      }
      goto LABEL_28;
    }
  }
  else if ( !HIBYTE(fOK) )
  {
    v14 = L"NT AUTHORITY\\SYSTEM";
    if ( dwProcessId_1 )
      v14 = L"<access denied>";
    LOBYTE(Status) = wcscpy_s(pszUserName, cbUserName, v14);
  }
  return Status;
}
// C9D238: using guessed type wchar_t aNtAuthoritySys[20];
// CD4E54: using guessed type int gdwVersion;

//----- (00C68790) --------------------------------------------------------
int GetDriverNameAndLinkInfo()
{
  unsigned __int16 iChar; // si
  WCHAR *pszDriverName; // ebx
  signed int chDriver; // edi
  int RtlInitUnicodeString; // eax
  HMODULE v4; // eax
  FARPROC RtlInitUnicodeString_1; // eax
  HMODULE v6; // eax
  int nDriverCount; // eax
  int result; // eax
  struct _UNICODE_STRING DestinationString; // [esp+Ch] [ebp-2E0h]
  struct _UNICODE_STRING strDeviceName; // [esp+14h] [ebp-2D8h]
  PCWSTR SourceString; // [esp+1Ch] [ebp-2D0h]
  ULONG ReturnedLength; // [esp+20h] [ebp-2CCh]
  OBJECT_ATTRIBUTES ObjectAttributes; // [esp+24h] [ebp-2C8h]
  int iDriver; // [esp+3Ch] [ebp-2B0h]
  HANDLE hLinkObject; // [esp+40h] [ebp-2ACh]
  WCHAR szDeviceName[64]; // [esp+44h] [ebp-2A8h]
  UNICODE_STRING strLinkTarget; // [esp+C4h] [ebp-228h]
  WCHAR szLinkNameBuffer[260]; // [esp+CCh] [ebp-220h]
  WCHAR szDriverName[10]; // [esp+2D4h] [ebp-18h]

  iDriver = 0;
  iChar = 0;
  pszDriverName = (WCHAR *)gszDriverName;
  chDriver = 'A';
  do
  {
    MakeDriverName(szDriverName, L"%c:\\", chDriver);
    if ( GetDriveTypeW(szDriverName) != FILE_TYPE_PIPE && GetDriveTypeW(szDriverName) != FILE_TYPE_CHAR )
      goto LABEL_17;
    MakeDeviceName(szDeviceName, L"\\DosDevices\\%c:", chDriver);
    RtlInitUnicodeString = *(_DWORD *)gpfnRtlInitUnicodeString;
    ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);
    ObjectAttributes.RootDirectory = 0;
    ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
    if ( !*(_DWORD *)gpfnRtlInitUnicodeString )
    {
      v4 = GetModuleHandleW(L"ntdll.dll");
      RtlInitUnicodeString = (int)GetProcAddress(v4, "RtlInitUnicodeString");
      *(_DWORD *)gpfnRtlInitUnicodeString = RtlInitUnicodeString;
    }
    ((void (__stdcall *)(struct _UNICODE_STRING *, WCHAR *))RtlInitUnicodeString)(&strDeviceName, szDeviceName);
    ObjectAttributes.SecurityDescriptor = 0;
    ObjectAttributes.ObjectName = &strDeviceName;
    ObjectAttributes.SecurityQualityOfService = 0;
    if ( gpfn_NtOpenSymbolicLinkObject(&hLinkObject, 0x20001u, &ObjectAttributes) )
    {
LABEL_17:
      nDriverCount = iDriver;
    }
    else
    {
      strLinkTarget.Length = MAX_PATH;
      strLinkTarget.Buffer = szLinkNameBuffer;
      gpfn_NtQuerySymbolicLinkObject(hLinkObject, &strLinkTarget, &ReturnedLength);
      CloseHandle(hLinkObject);
      SourceString = strLinkTarget.Buffer;
      RtlInitUnicodeString_1 = *(FARPROC *)gpfnRtlInitUnicodeString;
      ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);
      ObjectAttributes.RootDirectory = 0;
      ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
      if ( !*(_DWORD *)gpfnRtlInitUnicodeString )
      {
        v6 = GetModuleHandleW(L"ntdll.dll");
        RtlInitUnicodeString_1 = GetProcAddress(v6, "RtlInitUnicodeString");
        *(_DWORD *)gpfnRtlInitUnicodeString = RtlInitUnicodeString_1;
      }
      ((void (__stdcall *)(struct _UNICODE_STRING *, PCWSTR))RtlInitUnicodeString_1)(&DestinationString, SourceString);
      ObjectAttributes.SecurityDescriptor = 0;
      ObjectAttributes.ObjectName = &DestinationString;
      ObjectAttributes.SecurityQualityOfService = 0;
      if ( !gpfn_NtOpenSymbolicLinkObject(&hLinkObject, 0x20001u, &ObjectAttributes) )
      {
        strLinkTarget.MaximumLength = MAX_PATH;
        strLinkTarget.Buffer = szLinkNameBuffer;
        gpfn_NtQuerySymbolicLinkObject(hLinkObject, &strLinkTarget, &ReturnedLength);
        CloseHandle(hLinkObject);
      }
      wcscpy_s(pszDriverName - 256, 0x100u, strLinkTarget.Buffer);
      *pszDriverName = iChar + 'A';
      nDriverCount = iDriver + 1;
      pszDriverName += 257;
      ++iDriver;
    }
    ++iChar;
    ++chDriver;
  }
  while ( iChar < 26u );
  result = 257 * nDriverCount;
  gszDriverLinkName[result] = 0;
  return result * 2;
}

//----- (00C68A20) --------------------------------------------------------
char __cdecl sub_C68A20(int a1)
{
  char result; // al
  char v2; // dl
  signed int v3; // esi

  result = 0;
  v2 = *(_BYTE *)(a1 + 24);
  if ( v2 )
  {
    v3 = *(_DWORD *)(a1 + 28);
    if ( v3 < (signed int)gConfig.dwHighlightDuration )
    {
      *(_DWORD *)(a1 + 20) = v3;
      *(_DWORD *)(a1 + 16) = 2;
      return result;
    }
    if ( v2 )
    {
      result = 1;
      *(_BYTE *)(a1 + 24) = 0;
    }
  }
  *(_DWORD *)(a1 + 16) = 0;
  return result;
}

//----- (00C68A60) --------------------------------------------------------
int __cdecl ReportMsg(WCHAR *pszBuffer, HWND hWnd)
{
  DWORD v2; // eax
  WCHAR Buffer[2]; // [esp+8h] [ebp-208h]
  WCHAR Text; // [esp+Ch] [ebp-204h]

  v2 = GetLastError();
  if ( v2 )
  {
    FormatMessageW(0x1100u, 0, v2, 0x400u, Buffer, 0, 0);
    wsprintf(&Text, L"%s: %s", pszBuffer, *(_DWORD *)Buffer);
    LocalFree(*(HLOCAL *)Buffer);
  }
  else
  {
    wsprintf(&Text, L"%s.", pszBuffer);
  }
  return MessageBoxW(hWnd, &Text, L"Process Explorer", 0x10u);
}

//----- (00C68B10) --------------------------------------------------------
int __stdcall PageProcStrings(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  tagTREEVIEWLISTITEMPARAM *pTreeItem; // esi
  HWND hWndList; // ebx
  CResizer *v7; // eax
  LONG v8; // eax
  HWND v9; // ST14_4
  HWND v10; // eax
  LRESULT v11; // ST14_4
  HWND v12; // eax
  LRESULT v13; // ST14_4
  HWND v14; // eax
  void *dwProcessId; // eax
  WCHAR *pszClassName; // ecx
  HANDLE ProcessHandle; // eax
  char v18; // al
  HANDLE v19; // esi
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  LRESULT v21; // ST14_4
  HWND v22; // eax
  LRESULT v23; // ST14_4
  HWND v24; // eax
  wchar_t *v25; // eax
  HWND v26; // eax
  HANDLE v27; // esi
  LRESULT v28; // eax
  HGLOBAL v29; // edi
  _WORD *v30; // eax
  HGLOBAL v31; // eax
  int v32; // esi
  rsize_t v33; // ST04_4
  LRESULT i; // esi
  HCURSOR v35; // esi
  int v36; // eax
  HCURSOR v37; // esi
  char v38; // bl
  HWND v39; // esi
  HWND v40; // eax
  HWND hWndFindWindow; // eax
  HWND v42; // eax
  WPARAM v43; // [esp-8h] [ebp-29Ch]
  LVITEMW Item; // [esp+Ch] [ebp-288h]
  tagLVITEMW ItemInfo; // [esp+40h] [ebp-254h]
  LPCVOID lpBaseAddress; // [esp+74h] [ebp-220h]
  DWORD dwSize; // [esp+78h] [ebp-21Ch]
  UINT pnIDs; // [esp+7Ch] [ebp-218h]
  WORD pnWidths[2]; // [esp+80h] [ebp-214h]
  HANDLE dwPid; // [esp+84h] [ebp-210h]
  HANDLE hDlg; // [esp+88h] [ebp-20Ch]
  LONG dwNewLong; // [esp+8Ch] [ebp-208h]
  WCHAR szText[256]; // [esp+90h] [ebp-204h]

  hDlg = hWnd;
  dwNewLong = lParam;
  pTreeItem = (tagTREEVIEWLISTITEMPARAM *)GetWindowLongW(hWnd, GWLP_USERDATA);
  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  hWndList = GetDlgItem(hWnd, IDC_PROCSTRINGS_LISTCTRL);
  pnIDs = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  if ( msg > WM_INITDIALOG )
  {
    switch ( msg )
    {
      case WM_COMMAND:
        if ( (unsigned __int16)wParam > (signed int)IDC_PROCSTRINGS_BUTTON_SAVE )
        {
          if ( (unsigned __int16)wParam > (signed int)IDM_LISTCTRL_SELECTALL )
          {
            if ( (unsigned __int16)wParam == IDM_PROCSTRINGS_FINDITEM && (_BYTE)sbFound )
            {
              v35 = SetCursor((HCURSOR)ghWaitCursor);
              ProcStrings_FindItem((HWND)hDlg, hWndList, &gFindReplaceItem, sstrFindWhat, (PBOOL)&sbFound, &pszBuffer);
              SetCursor(v35);
              ReleaseCapture();
            }
          }
          else if ( (unsigned __int16)wParam == IDM_LISTCTRL_SELECTALL )
          {
            for ( i = 0; i < ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0); ++i )
            {
              Item.stateMask = LVIS_SELECTED;
              Item.state = LVIS_SELECTED;
              ::SendMessageW(hWndList, LVM_SETITEMSTATE, i, (LPARAM)&Item);
            }
          }
          else
          {
            if ( (unsigned __int16)wParam != IDM_LISTCTRL_COPY )
            {
              if ( (unsigned int)(unsigned __int16)wParam - 40092 > 1 )
                return 0;
              v43 = wParam;
              goto LABEL_50;
            }
            // 执行复制到剪贴板
            v27 = 0;
            dwNewLong = 0;
            v28 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, ItemInfo.iItem, 2);
            ItemInfo.iItem = v28;
            if ( v28 != -1 )
            {
              v29 = 0;
              do
              {
                Item.iSubItem = 0;
                Item.pszText = szText;
                Item.cchTextMax = 256;
                ::SendMessageW(hWndList, LVM_GETITEMTEXTW, v28, (LPARAM)&Item);
                dwNewLong += wcslen(szText) + 2;
                if ( v27 )
                {
                  v29 = GlobalReAlloc(v29, 2 * dwNewLong + 2, 0);
                  v30 = GlobalLock(v29);
                }
                else
                {
                  v31 = GlobalAlloc(0x2002u, 2 * dwNewLong + 2);
                  v29 = v31;
                  v30 = GlobalLock(v31);
                  *v30 = 0;
                }
                v32 = dwNewLong + 1;
                dwPid = v30;
                wcscat_s(v30, dwNewLong + 1, szText);
                v33 = v32;
                v27 = dwPid;
                wcscat_s((wchar_t *)dwPid, v33, L"\r\n");
                GlobalUnlock(v29);
                v28 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, ItemInfo.iItem, 2);
                ItemInfo.iItem = v28;
              }
              while ( v28 != -1 );
              dwPid = v29;
              if ( v29 )
              {
                if ( OpenClipboard((HWND)hDlg) )
                {
                  EmptyClipboard();
                  SetClipboardData(0xDu, dwPid);
                  CloseClipboard();
                }
              }
            }
          }
        }
        else if ( (unsigned __int16)wParam == IDC_PROCSTRINGS_BUTTON_SAVE )
        {
          if ( pTreeItem->nListType )
          {
            v25 = wcsrchr(*(const wchar_t **)&pTreeItem->gap154[4], 0x5Cu);
            SaveProcessStrings(hWndList, v25 + 1);
          }
          else
          {
            SaveProcessStrings(hWndList, pTreeItem->szProcessName2);
          }
        }
        else
        {
          // 内存模式
          if ( (signed int)(unsigned __int16)wParam <= 1304 )
          {
            switch ( (unsigned __int16)wParam )
            {
              case IDC_DLG_DLLSTRINGS_RADIO_IMAGE:
                ::SendMessageW(hWndList, WM_SETREDRAW, 0, 0);
                ::SendMessageW(hWndList, LVM_DELETEALLITEMS, 0, 0);
                if ( pTreeItem->nListType )
                  sub_C364C0(hWndList, *(LPCWSTR *)&pTreeItem->gap154[4]);
                else
                  sub_C364C0(hWndList, pTreeItem->szProcessName);
                ::SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 0, 0xFFFF);
                ::SendMessageW(hWndList, WM_SETREDRAW, 1u, 0);
                v11 = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
                v12 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_SAVE);
                EnableWindow(v12, v11);
                v13 = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
                v14 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_FIND);
                EnableWindow(v14, v13);
                break;
              case IDC_MYICON:
                EndDialog(hWnd, 0);
                return 1;
              case IDC_THREADSTACK_BUTTON_REFRESH:
                wcscpy_s(sstrFindWhat, 0x2000u, &pszBuffer);
                gFindReplaceItem.hInstance = ghInstance;
                gFindReplaceItem.lStructSize = 40;
                gFindReplaceItem.hwndOwner = hWnd;
                gFindReplaceItem.lpstrFindWhat = sstrFindWhat;
                gFindReplaceItem.lpstrReplaceWith = 0;
                *(_DWORD *)&gFindReplaceItem.wFindWhatLen = 0x2000;
                gFindReplaceItem.lCustData = 0;
                gFindReplaceItem.Flags = gdwFindReplaceFlags;
                gFindReplaceItem.lpfnHook = 0;
                gFindReplaceItem.lpTemplateName = 0;
                v9 = FindTextW(&gFindReplaceItem);
                v10 = GetParent(hWnd);
                SetPropW(v10, L"FindWindow", v9);
                break;
            }
            return 0;
          }
          // IDC_PROCSTRINGS_BUTTON_IMAGE，镜像模�?
          if ( (unsigned __int16)wParam != 1305 )
          {
            if ( (unsigned __int16)wParam != 40001 )
              return 0;
            v43 = 40014;
LABEL_50:
            v26 = GetParent(hWnd);
            PostMessageW(v26, WM_COMMAND, v43, 0);
            return 0;
          }
          ::SendMessageW(hWndList, 0xBu, 0, 0);
          ::SendMessageW(hWndList, LVM_DELETEALLITEMS, 0, 0);
          if ( pTreeItem->nListType )
          {
            dwProcessId = (void *)pTreeItem->dwStyle;
            pszClassName = *(WCHAR **)&pTreeItem->gap154[4];
          }
          else
          {
            dwProcessId = (void *)pTreeItem->dwProcessId;
            pszClassName = pTreeItem->szProcessName;
          }
          dwNewLong = (LONG)pszClassName;
          dwPid = dwProcessId;
          ProcessHandle = OpenProcess(0x410u, 0, (DWORD)dwProcessId);
          hDlg = ProcessHandle;
          if ( ProcessHandle )
          {
            if ( pTreeItem->nListType )
            {
              LoadStringToList(hWndList, ProcessHandle, (LPCVOID)pTreeItem->nRefCount, pTreeItem->hFileIcon);
              v19 = hDlg;
            }
            else
            {
              v18 = sub_C503E0(ProcessHandle, (DWORD)dwPid, (LPCWSTR)dwNewLong, (LPVOID *)&lpBaseAddress, &dwSize);
              v19 = hDlg;
              if ( v18 )
                LoadStringToList(hWndList, hDlg, lpBaseAddress, dwSize);
            }
            CloseHandle(v19);
            SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
          }
          else
          {
            SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
            ItemInfo.mask = 5;
            ItemInfo.iItem = 0x7FFFFFFF;
            ItemInfo.pszText = L"<Error opening process>";
            ItemInfo.lParam = (tagTREEVIEWLISTITEMPARAM *)1;
            ::SendMessageW(hWndList, LVM_INSERTITEMW, 0, (LPARAM)&ItemInfo);
          }
          SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 0, 0xFFFF);
          SendMessageW(hWndList, WM_SETREDRAW, 1u, 0);
          v21 = ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(hWndList, LVM_GETITEMCOUNT, 0, 0);
          v22 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_SAVE);
          EnableWindow(v22, v21);
          v23 = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
          v24 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_FIND);
          EnableWindow(v24, v23);
        }
        return 0;
      case WM_CTLCOLOREDIT:
      case WM_CTLCOLORDLG:
      case WM_CTLCOLORSTATIC:
        return PE_FillControl((int)hWnd, (HDC)wParam);
      default:
        goto LABEL_67;
    }
  }
  if ( msg != WM_INITDIALOG )
  {
    switch ( msg )
    {
      case WM_ALTTABACTIVE|WM_DESTROY:
        CMainWnd::DrawItem((LPDRAWITEMSTRUCT)dwNewLong);
        return 0;
      case 0x2Cu:
        return CMainWnd::HandleMeasureItem(hWnd, msg, wParam, (LPMEASUREITEMSTRUCT)dwNewLong);
      case WM_KEYUP:
        if ( wParam == VK_F3 )
          ::SendMessageW(hWnd, WM_COMMAND, IDM_PROCSTRINGS_FINDITEM, 0);
        return 0;
      case WM_CHAR:
        if ( wParam == 'F' || wParam == 'f' )
        {
          if ( GetKeyState(VK_CONTROL) )
            ::SendMessageW(hWnd, WM_COMMAND, IDC_PROCSTRINGS_BUTTON_FIND, 0);
        }
        return 0;
      default:
        break;
    }
LABEL_67:
    if ( msg == gdwComdlg_FindReplaceMessageID )
    {
      v36 = *(_DWORD *)(dwNewLong + 12);
      if ( v36 & 0x40 )
      {
        // FR_DOWN|FR_WHOLEWORD|FR_MATCHCASE
        gdwFindReplaceFlags = gFindReplaceItem.Flags & 7;
      }
      else if ( v36 & 8 )
      {
        v37 = SetCursor((HCURSOR)ghWaitCursor);
        v38 = ProcStrings_FindItem(
                (HWND)hDlg,
                hWndList,
                (tagFINDREPLACEW *)dwNewLong,
                sstrFindWhat,
                (PBOOL)&sbFound,
                &pszBuffer);
        SetCursor(v37);
        ReleaseCapture();
        v39 = (HWND)hDlg;
        v40 = GetParent((HWND)hDlg);
        hWndFindWindow = (HWND)GetPropW(v40, L"FindWindow");
        if ( v38 && hWndFindWindow )
        {
          PostMessageW(hWndFindWindow, WM_COMMAND, IDC_DLG_DLLINFO_EDIT_COMPANY, 0);
          v42 = GetParent(v39);
          SetPropW(v42, L"FindWindow", 0);
        }
        else
        {
          SetFocus(hWndFindWindow);
        }
      }
    }
    return 0;
  }
  // WM_INITDIALOG，对话框初始�?
  v7 = (CResizer *)operator new(0x40u);
  if ( v7 )
    CResizer::CResizer(v7, hWnd);
  GetWindowTextW(hWnd, szText, 256);
  PropSheet_UpdateTab(hWnd);
  SetWindowLongW(hWnd, GWLP_USERDATA, dwNewLong);
  CheckRadioButton(
    hWnd,
    IDC_DLG_DLLSTRINGS_RADIO_IMAGE,
    IDC_DLG_DLLSTRINGS_RADIO_MEMORY,
    IDC_DLG_DLLSTRINGS_RADIO_IMAGE);
  v8 = GetWindowLongW(hWndList, GWL_STYLE);
  SetWindowLongW(hWndList, -16, v8 & -3u | LVS_REPORT);
  SetWindowLongW(hWndList, -4, (LONG)Proxy_ListCtrlWndProc);
  ::SendMessageW(hWndList, WM_SETFONT, (WPARAM)ghConfigFont, 0);
  InitListHeader(hWndList, &pnIDs, pnWidths, 1);
  PostMessageW(hWnd, WM_COMMAND, IDC_DLG_DLLSTRINGS_RADIO_IMAGE, 0);
  return 1;
}
// CB606C: using guessed type wchar_t aErrorOpeningPr_1[24];
// CD10E0: using guessed type int gdwFindReplaceFlags;
// CDA32C: using guessed type int gdwComdlg_FindReplaceMessageID;

//----- (00C69520) --------------------------------------------------------
char __usercall CMainWnd::RefreshDllsView@<al>(signed int a1@<ebx>, HWND hWnd, DWORD dwProcessId, WPARAM wParam)
{
  DWORD v4; // esi
  HWND v5; // edi
  _BYTE *v6; // eax
  tagTREEVIEWLISTITEMPARAM *v7; // ecx
  tagDLLLISTITEMPARAM *v8; // eax
  tagDLLLISTITEMPARAM *v9; // esi
  char v10; // al
  _DWORD *v11; // edi
  ULONG v12; // esi
  bool v13; // zf
  int v14; // ebx
  tagDLLLISTITEMPARAM *v15; // ecx
  wchar_t *v16; // eax
  CHAR *v17; // edx
  int v18; // ecx
  HANDLE v19; // esi
  char v20; // dl
  char v21; // dh
  signed int v22; // eax
  void *v23; // esi
  tagDLLLISTITEMPARAM *v25; // eax
  tagDLLLISTITEMPARAM *v26; // esi
  char v27; // al
  SYSTEM_PROCESS_INFORMATION *v28; // edi
  tagTREEVIEWLISTITEMPARAM *v29; // esi
  CHAR *v30; // eax
  DWORD v31; // ecx
  void *v32; // edi
  unsigned int *v33; // eax
  IAtlStringMgr *v34; // eax
  const WCHAR *v35; // esi
  wchar_t *v36; // edi
  DWORD v37; // eax
  WCHAR *v38; // esi
  signed int v39; // edi
  int v40; // eax
  const wchar_t *v41; // ebx
  int v42; // eax
  tagDLLLISTITEMPARAM *v43; // edi
  char v44; // cl
  char v45; // dl
  signed int v46; // eax
  char v47; // al
  char v48; // al
  char v49; // cl
  HANDLE v50; // edi
  PIMAGE_NT_HEADERS v51; // eax
  HANDLE v52; // edi
  int v53; // edi
  int v54; // esi
  int v55; // ecx
  tagDLLLISTITEMPARAM *v56; // eax
  char v57; // dl
  signed int v58; // ecx
  char v59; // al
  char v60; // [esp-188h] [ebp-29A0h]
  DWORD v61; // [esp-20h] [ebp-2838h]
  void *v62; // [esp-1Ch] [ebp-2834h]
  wchar_t *v63; // [esp-18h] [ebp-2830h]
  int *v64; // [esp-14h] [ebp-282Ch]
  const void *v65; // [esp-10h] [ebp-2828h]
  char *v66; // [esp-Ch] [ebp-2824h]
  WCHAR *v67; // [esp-8h] [ebp-2820h]
  wchar_t *v68; // [esp-4h] [ebp-281Ch]
  LPARAM v69; // [esp+Ch] [ebp-280Ch]
  int v70; // [esp+10h] [ebp-2808h]
  tagDLLLISTITEMPARAM *v71; // [esp+2Ch] [ebp-27ECh]
  struct _FILETIME v72; // [esp+40h] [ebp-27D8h]
  DWORD ThreadId; // [esp+48h] [ebp-27D0h]
  struct _FILETIME LastAccessTime; // [esp+4Ch] [ebp-27CCh]
  unsigned int *v75; // [esp+54h] [ebp-27C4h]
  DWORD ExitCode; // [esp+58h] [ebp-27C0h]
  struct _FILETIME LocalFileTime; // [esp+5Ch] [ebp-27BCh]
  struct _FILETIME CreationTime; // [esp+64h] [ebp-27B4h]
  struct _FILETIME LastWriteTime; // [esp+6Ch] [ebp-27ACh]
  int v80; // [esp+74h] [ebp-27A4h]
  unsigned int v81; // [esp+78h] [ebp-27A0h]
  ULONG ReturnLength; // [esp+7Ch] [ebp-279Ch]
  CString v83; // [esp+80h] [ebp-2798h]
  DWORD v84; // [esp+84h] [ebp-2794h]
  LPCWSTR lptstrFilename; // [esp+88h] [ebp-2790h]
  int v86; // [esp+8Ch] [ebp-278Ch]
  int v87; // [esp+90h] [ebp-2788h]
  _DWORD *v88; // [esp+94h] [ebp-2784h]
  void *v89; // [esp+98h] [ebp-2780h]
  HWND v90; // [esp+9Ch] [ebp-277Ch]
  SYSTEM_PROCESS_INFORMATION *v91; // [esp+A0h] [ebp-2778h]
  DWORD v92; // [esp+A4h] [ebp-2774h]
  int v93; // [esp+A8h] [ebp-2770h]
  tagDLLLISTITEMPARAM *v94; // [esp+ACh] [ebp-276Ch]
  char v95; // [esp+B2h] [ebp-2766h]
  int a5; // [esp+B3h] [ebp-2765h]
  int v97; // [esp+C4h] [ebp-2754h]
  wchar_t *v98; // [esp+D8h] [ebp-2740h]
  wchar_t v99; // [esp+DCh] [ebp-273Ch]
  int v100; // [esp+15Ch] [ebp-26BCh]
  int v101; // [esp+160h] [ebp-26B8h]
  int v102; // [esp+164h] [ebp-26B4h]
  wchar_t *v103; // [esp+168h] [ebp-26B0h]
  char v104; // [esp+16Ch] [ebp-26ACh]
  int v105; // [esp+17Ch] [ebp-269Ch]
  int v106; // [esp+180h] [ebp-2698h]
  char v107; // [esp+184h] [ebp-2694h]
  int v108; // [esp+190h] [ebp-2688h]
  int v109; // [esp+198h] [ebp-2680h]
  DWORD v110; // [esp+19Ch] [ebp-267Ch]
  char hObject; // [esp+1A0h] [ebp-2678h]
  char BaseAddress; // [esp+1A2h] [ebp-2676h]
  int v113; // [esp+1A4h] [ebp-2674h]
  __int16 v114; // [esp+1A8h] [ebp-2670h]
  struct _FILETIME v115; // [esp+1ACh] [ebp-266Ch]
  DWORD pTimeDateStamp; // [esp+1B4h] [ebp-2664h]
  wchar_t Dst; // [esp+1B8h] [ebp-2660h]
  wchar_t pszBuffer; // [esp+23Ah] [ebp-25DEh]
  DWORD dwLen; // [esp+2BCh] [ebp-255Ch]
  WCHAR *ppszCopyright; // [esp+2C0h] [ebp-2558h]
  LPCWSTR lpFileName; // [esp+2C4h] [ebp-2554h]
  wchar_t *v122; // [esp+2C8h] [ebp-2550h]
  SYSTEMTIME Date; // [esp+2F4h] [ebp-2524h]
  struct _SYSTEMTIME SystemTime; // [esp+304h] [ebp-2514h]
  char Buffer; // [esp+314h] [ebp-2504h]
  wchar_t v126; // [esp+2314h] [ebp-504h]
  LPARAM lParam; // [esp+2514h] [ebp-304h]
  WCHAR TimeStr; // [esp+2714h] [ebp-104h]
  WCHAR DateStr; // [esp+2794h] [ebp-84h]

  v87 = 0;
  v4 = dwProcessId;
  LOBYTE(a1) = 0;
  v5 = hWnd;
  v93 = 0;
  v95 = 0;
  v86 = 0;
  v89 = 0;
  LOWORD(lParam) = 1;
  v90 = hWnd;
  v92 = dwProcessId;
  v94 = (tagDLLLISTITEMPARAM *)a1;
  memset((char *)&lParam + 2, 0, 0x1FEu);
  v6 = (_BYTE *)wParam;
  if ( !wParam )
  {
    if ( gConfig.dwDllColumnCount == wParam || !gConfig.bShowLowerPane )
      return 0;
    v89 = sub_C5DE60(dwProcessId);
    v6 = 0;
  }
  if ( dwProcessId )
  {
    v7 = gpTreeViewListItemParam;
    v86 = (int)gpTreeViewListItemParam;
    if ( gpTreeViewListItemParam )
    {
      do
      {
        if ( v7->dwProcessId == dwProcessId )
          break;
        v7 = v7->m_Prev;
      }
      while ( v7 );
      v86 = (int)v7;
    }
  }
  if ( !*(_DWORD *)CreateToolhelp32Snapshot_0 )
  {
    if ( !v6 )
    {
      if ( dwProcessId != gdwValue_4F10B8[1] )
      {
        v95 = 1;
        SendMessageW(hWnd, 0xBu, 0, 0);
        SendMessageW(hWnd, 0x1009u, 0, 0);
        SendMessageW(ghWndStatusBar, 0x40Du, gnStatusBarItemCount - 1, (LPARAM)&lParam);
        SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, (LPARAM)L"Refreshing DLLs...");
        UpdateMenuStatus(0, 5);
      }
      v25 = gpDllListItemParamHeader;
      if ( gpDllListItemParamHeader )
      {
        do
        {
          v26 = v25->m_Prev;
          v71 = v25;
          v70 = -1;
          v27 = sub_C658D0(a1, hWnd, (LVITEMW *)&v69, (LPARAM)v25, (int)&a5);
          a1 = (unsigned __int8)a1;
          if ( v27 )
            a1 = 1;
          if ( (_BYTE)a5 )
            ++v87;
          v25 = v26;
        }
        while ( v26 );
        v4 = v92;
        v94 = (tagDLLLISTITEMPARAM *)a1;
      }
      v6 = (_BYTE *)wParam;
    }
    v28 = gpSystemProcessInfo;
    while ( 1 )
    {
      v91 = v28;
      if ( !v6 && v28->UniqueProcessId != (HANDLE)v4 )
      {
        v23 = v89;
        goto LABEL_165;
      }
      v29 = gpTreeViewListItemParam;
      LOBYTE(v80) = 0;
      if ( !gpTreeViewListItemParam )
        goto LABEL_79;
      while ( (HANDLE)v29->dwProcessId != v28->UniqueProcessId )
      {
        v29 = v29->m_Prev;
        if ( !v29 )
          goto LABEL_79;
      }
      a1 = (unsigned int)v29->dwStyle >> 4;
      LOBYTE(a1) = a1 & 1;
      v80 = a1;
      if ( !(_BYTE)a1 )
      {
LABEL_79:
        v30 = (CHAR *)RtlCreateQueryDebugBuffer(0, 0);
        v83.pszData = v30;
        if ( !v30 )
          return 0;
        v31 = (DWORD)v28->UniqueProcessId;
        LocalFileTime.dwHighDateTime = (DWORD)v30;
        LocalFileTime.dwLowDateTime = v31;
        v32 = (void *)_beginthreadex(0, 0, (int)QueryProcessDebugInforThreadProc, (int)&LocalFileTime, 0, &ThreadId);
        if ( WaitForSingleObject(v32, 0xFA0u) == 258 )
          TerminateThread(v32, 1u);
        GetExitCodeThread(v32, &ExitCode);
        CloseHandle(v32);
        if ( !ExitCode )
        {
          v81 = 0;
          v33 = (unsigned int *)*((_DWORD *)v83.pszData + 12);
          v75 = v33;
          if ( *v33 )
          {
            a1 = (signed int)(v33 + 8);
            v88 = v33 + 8;
            while ( 1 )
            {
              memset(&v104, 0, 0x188u);
              v110 = 0;
              v108 = *(_DWORD *)(a1 - 20);
              v113 = *(_DWORD *)(a1 - 16);
              v114 = *(_WORD *)(a1 - 4);
              if ( *(_BYTE *)a1 == 92 && *(_BYTE *)(a1 + 1) == 63 )
                strcpy_s((char *)a1, 0x100u, (const char *)(a1 + 4));
              v34 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
              if ( !v34 )
                ATL::AtlThrowImpl(-2147467259);
              lptstrFilename = (LPCWSTR)(((int (__thiscall *)(IAtlStringMgr *))v34->vtptr->GetNilData)(v34) + 16);
              ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(
                (CString *)&lptstrFilename,
                (LPCSTR)a1);
              v35 = lptstrFilename;
              v36 = _wcsdup(lptstrFilename);
              if ( *(_DWORD *)GetLongPathNameW )
              {
                v37 = GetLongPathNameW(v36, 0, 0);
                v84 = v37;
                if ( v37 )
                {
                  v38 = (WCHAR *)malloc(2 * v37 + 2);
                  GetLongPathNameW(v36, v38, v84 + 1);
                  free(v36);
                  v36 = v38;
                  operator delete(0);
                  v35 = lptstrFilename;
                }
              }
              lpFileName = v36;
              wcscpy_s(&pszBuffer, 0x41u, (const wchar_t *)&gszNullString);
              if ( !wParam )
                break;
              v39 = wcslen(gszStringToFindLast);
              v40 = *((_DWORD *)v35 - 3);
              if ( v40 >= v39 )
              {
                v84 = 0;
                if ( v40 - v39 + 1 > 0 )
                {
                  v41 = v35;
                  while ( _wcsnicmp(v41, gszStringToFindLast, v39) )
                  {
                    ++v41;
                    v42 = *((_DWORD *)v35 - 3) - v39 + 1;
                    if ( (signed int)++v84 >= v42 )
                    {
                      a1 = (signed int)v88;
                      goto LABEL_134;
                    }
                  }
                  a1 = (signed int)v88;
LABEL_117:
                  PE_GetProductCopyright(v35, &pszBuffer, 0x41u, (WCHAR **)&dwLen, &ppszCopyright);
                  if ( !wParam )
                  {
                    v68 = (wchar_t *)v91->UniqueProcessId;
                    v50 = OpenProcess(0x410u, 0, (DWORD)v68);
                    if ( v50 )
                    {
                      v68 = (wchar_t *)&LastWriteTime.dwHighDateTime;
                      v67 = (WCHAR *)0x2000;
                      v66 = &Buffer;
                      v65 = *(const void **)(a1 - 20);
                      if ( ReadProcessMemory(v50, v65, &Buffer, 0x2000u, &LastWriteTime.dwHighDateTime) )
                      {
                        v51 = ImageNtHeader(&Buffer);
                        if ( v51 )
                        {
                          v110 = v51->OptionalHeader.ImageBase;
                          if ( v51->OptionalHeader.ImageBase != *(_DWORD *)(a1 - 20) )
                            v109 |= 1u;
                        }
                      }
                      CloseHandle(v50);
                    }
                  }
                  wcscpy_s(&Dst, 0x41u, (const wchar_t *)&gszNullString);
                  v115 = 0i64;
                  v52 = CreateFileW(v35, 0x80000000, 7u, 0, 3u, 0, 0);
                  if ( v52 != (HANDLE)-1 )
                  {
                    GetFileTime(v52, (LPFILETIME)&SystemTime.wHour, &v72, &CreationTime);
                    CloseHandle(v52);
                    v115 = CreationTime;
                    FileTimeToLocalFileTime(&CreationTime, &LastAccessTime);
                    FileTimeToSystemTime(&LastAccessTime, &Date);
                    GetDateFormatW(0x400u, 1u, &Date, 0, &TimeStr, 64);
                    GetTimeFormatW(0x400u, 2u, &Date, 0, &DateStr, 64);
                    v68 = &DateStr;
                    v67 = &TimeStr;
                    sub_C49DE0(&Dst, L"%s %s", &TimeStr, &DateStr);
                  }
                  if ( wParam )
                  {
                    v53 = (int)v91;
                    wcsncpy_s(&v126, 0x100u, v91->ImageName.Buffer, (unsigned int)v91->ImageName.Length >> 1);
                    v102 = 0;
                    v98 = _wcsdup(&v126);
                    v103 = _wcsdup(v35);
                    v100 = *(_DWORD *)(v53 + 68);
                    v97 = 0;
                    v101 = *(_DWORD *)(a1 - 20);
                    wcscpy_s(&v99, 0x40u, L"DLL");
                    sub_C278D0(v90, (wchar_t *)((char *)&a5 + 1));
                  }
                  else
                  {
                    sub_C4C400((int *)v89, &v104);
                    v106 = 0;
                    if ( gdwValue_4F10B8[1] == v92 )
                    {
                      v105 = 2;
                    }
                    else
                    {
                      v107 = 0;
                      v105 = 0;
                    }
                    if ( PE_CheckExeFile(lpFileName, &pTimeDateStamp, (BOOL *)&hObject, &BaseAddress) )
                      v109 |= 4u;
                    qmemcpy(&v60, &v104, 0x188u);
                    sub_C27790(v90, v60);
                    v35 = lptstrFilename;
                    LOBYTE(v94) = 1;
                  }
                  goto LABEL_134;
                }
              }
LABEL_134:
              v54 = (int)(v35 - 8);
              if ( _InterlockedDecrement((volatile signed __int32 *)(v54 + 12)) <= 0 )
              {
                v55 = *(_DWORD *)v54;
                v68 = (wchar_t *)v54;
                (*(void (__stdcall **)(int))(*(_DWORD *)v55 + 4))(v54);
              }
              a1 += 284;
              ++v81;
              v88 = (_DWORD *)a1;
              if ( v81 >= *v75 )
                goto LABEL_160;
            }
            v43 = gpDllListItemParamHeader;
            if ( gpDllListItemParamHeader )
            {
              while ( 1 )
              {
                if ( v43->m_LoadAddress == *(_DWORD *)(a1 - 20) && v43->m_MappedSize == *(_DWORD *)(a1 - 16) )
                {
                  v68 = (wchar_t *)v35;
                  v67 = (WCHAR *)v43->m_strPath.pszData;
                  if ( !_wcsicmp(v67, v35) )
                    break;
                }
                v43 = v43->m_Prev;
                if ( !v43 )
                  goto LABEL_104;
              }
              v44 = v43->field_18;
              v45 = 0;
              ++v93;
              if ( v44 )
              {
                v46 = v43->field_1C;
                if ( v46 < (signed int)gConfig.dwHighlightDuration )
                {
                  v43->field_10 = 2;
                  v43->field_14 = v46;
LABEL_113:
                  v48 = sub_C4C400((int *)v89, v43);
                  v49 = (char)v94;
                  if ( v48 )
                    v49 = 1;
                  LOBYTE(v94) = v49;
                  goto LABEL_134;
                }
                if ( v44 )
                {
                  v45 = 1;
                  LOBYTE(v43->field_18) = 0;
                }
              }
              v47 = (char)v94;
              if ( v45 )
                v47 = 1;
              v43->field_10 = 0;
              LOBYTE(v94) = v47;
              goto LABEL_113;
            }
LABEL_104:
            sub_C4C400((int *)v89, &v104);
            goto LABEL_117;
          }
LABEL_160:
          RtlDestroyQueryDebugBuffer(v83.pszData);
          goto LABEL_161;
        }
      }
      if ( !wParam )
      {
        v29->dwStyle |= 0x10u;
        v56 = gpDllListItemParamHeader;
        if ( !gpDllListItemParamHeader )
        {
LABEL_143:
          memset(&v104, 0, 0x188u);
          v108 = 0;
          v114 = 0;
          v113 = 0;
          if ( PE_CheckExeFile(lpFileName, &pTimeDateStamp, (BOOL *)&hObject, &BaseAddress) )
            v109 |= 4u;
          lpFileName = _wcsdup(L"<Unable to query process module information>");
          wcscpy_s(&pszBuffer, 0x41u, (const wchar_t *)&gszNullString);
          wcscpy_s(&Dst, 0x41u, (const wchar_t *)&gszNullString);
          v106 = 0;
          v115 = 0i64;
          if ( gdwValue_4F10B8[1] == v92 )
          {
            v105 = 2;
          }
          else
          {
            v107 = 0;
            v105 = 0;
          }
          if ( PE_CheckExeFile(lpFileName, &pTimeDateStamp, (BOOL *)&hObject, &BaseAddress) )
            v109 |= 4u;
          qmemcpy(&v60, &v104, 0x188u);
          sub_C27790(v90, v60);
LABEL_158:
          LOBYTE(v94) = 1;
          goto LABEL_159;
        }
        while ( v56->m_LoadAddress || v56->m_MappedSize )
        {
          v56 = v56->m_Prev;
          if ( !v56 )
            goto LABEL_143;
        }
        LOBYTE(a1) = v56->field_18;
        v57 = 0;
        ++v93;
        if ( (_BYTE)a1 )
        {
          v58 = v56->field_1C;
          if ( v58 < (signed int)gConfig.dwHighlightDuration )
          {
            v56->field_10 = 2;
            v56->field_14 = v58;
            goto LABEL_159;
          }
          if ( (_BYTE)a1 )
          {
            v57 = 1;
            LOBYTE(v56->field_18) = 0;
          }
        }
        v56->field_10 = 0;
        if ( v57 )
          goto LABEL_158;
      }
LABEL_159:
      if ( !(_BYTE)v80 )
        goto LABEL_160;
LABEL_161:
      v28 = v91;
      wcsncpy_s(&v126, 0x100u, v91->ImageName.Buffer, (unsigned int)v91->ImageName.Length >> 1);
      v23 = v89;
      v64 = &v93;
      v63 = &v126;
      v62 = v89;
      v61 = (DWORD)v28->UniqueProcessId;
      v59 = sub_C5F870(a1, (int)v90, wParam, v86, v61, (int)v89, (int)&v126, (int)&v93);
      a1 = (unsigned __int8)v94;
      if ( v59 )
        a1 = 1;
      v94 = (tagDLLLISTITEMPARAM *)a1;
LABEL_165:
      if ( !v28->NextEntryOffset )
      {
        v5 = v90;
        goto LABEL_168;
      }
      v4 = v92;
      v28 = (SYSTEM_PROCESS_INFORMATION *)((char *)v28 + v28->NextEntryOffset);
      v6 = (_BYTE *)wParam;
    }
  }
  if ( v6 )
  {
    sub_C65140(a1, (int)hWnd, v6);
    return 0;
  }
  if ( dwProcessId != gdwValue_4F10B8[1] )
  {
    v95 = 1;
    SendMessageW(hWnd, 0xBu, 0, 0);
    SendMessageW(hWnd, 0x1009u, 0, 0);
    SendMessageW(ghWndStatusBar, 0x40Du, gnStatusBarItemCount - 1, (LPARAM)&lParam);
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, (LPARAM)L"Refreshing DLLs...");
    UpdateMenuStatus(0, 5);
  }
  v8 = gpDllListItemParamHeader;
  if ( gpDllListItemParamHeader )
  {
    do
    {
      v9 = v8->m_Prev;
      v71 = v8;
      v70 = -1;
      v10 = sub_C658D0(a1, hWnd, (LVITEMW *)&v69, (LPARAM)v8, (int)&a5);
      a1 = (unsigned __int8)a1;
      if ( v10 )
        a1 = 1;
      if ( (_BYTE)a5 )
        ++v87;
      v8 = v9;
    }
    while ( v9 );
    v4 = v92;
    v94 = (tagDLLLISTITEMPARAM *)a1;
  }
  if ( v4 == 8 || v4 == 4 )
  {
    ReturnLength = 1000;
    v88 = malloc(0x3E8u);
    v11 = v88;
    if ( NtQuerySystemInformation(SystemModuleInformation, v88, 0x3E8u, &ReturnLength) )
    {
      do
      {
        free(v11);
        ReturnLength += 1000;
        v12 = ReturnLength;
        v11 = malloc(ReturnLength);
      }
      while ( NtQuerySystemInformation(SystemModuleInformation, v11, v12, &ReturnLength) );
      v88 = v11;
    }
    v13 = *v11 == 0;
    v91 = 0;
    if ( !v13 )
    {
      v14 = (int)(v11 + 4);
      while ( 1 )
      {
        v15 = gpDllListItemParamHeader;
        if ( gpDllListItemParamHeader )
        {
          while ( v15->m_LoadAddress != *(_DWORD *)(v14 - 4) || v15->m_MappedSize != *(_DWORD *)v14 )
          {
            v15 = v15->m_Prev;
            if ( !v15 )
              goto LABEL_32;
          }
          v20 = v15->field_18;
          v21 = 0;
          ++v93;
          if ( v20 )
          {
            v22 = v15->field_1C;
            if ( v22 < (signed int)gConfig.dwHighlightDuration )
            {
              v15->field_10 = 2;
              v15->field_14 = v22;
              goto LABEL_53;
            }
            if ( v20 )
            {
              v21 = 1;
              LOBYTE(v15->field_18) = 0;
            }
          }
          v15->field_10 = 0;
          if ( v21 )
          {
            LOBYTE(v15) = 1;
LABEL_52:
            v94 = v15;
            goto LABEL_53;
          }
        }
        else
        {
LABEL_32:
          if ( (LPVOID)*(_DWORD *)(v14 - 4) > gSystemInfo.lpMaximumApplicationAddress )
          {
            memset(&v104, 0, 0x188u);
            v68 = (wchar_t *)ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                               &v83,
                               (LPCSTR)(v14 + 16))->pszData;
            v16 = sub_C34280(v68);
            v17 = v83.pszData - 16;
            lpFileName = v16;
            if ( _InterlockedDecrement((volatile signed __int32 *)v83.pszData - 1) <= 0 )
            {
              v18 = *(_DWORD *)v17;
              v68 = (wchar_t *)v17;
              (*(void (__stdcall **)(CHAR *))(*(_DWORD *)v18 + 4))(v17);
            }
            v108 = *(_DWORD *)(v14 - 4);
            v113 = *(_DWORD *)v14;
            v110 = *(_DWORD *)(v14 - 4);
            PE_GetProductCopyright(lpFileName, &pszBuffer, 0x41u, (WCHAR **)&dwLen, &ppszCopyright);
            wcscpy_s(&Dst, 0x41u, (const wchar_t *)&gszNullString);
            v115 = 0i64;
            v19 = CreateFileW(lpFileName, 0x80000000, 3u, 0, 3u, 0, 0);
            if ( v19 != (HANDLE)-1 )
            {
              GetFileTime(v19, &CreationTime, &LastAccessTime, &LastWriteTime);
              CloseHandle(v19);
              v115 = LastWriteTime;
              FileTimeToLocalFileTime(&LastWriteTime, &LocalFileTime);
              FileTimeToSystemTime(&LocalFileTime, &SystemTime);
              GetDateFormatW(0x400u, 1u, &SystemTime, 0, &DateStr, 64);
              GetTimeFormatW(0x400u, 2u, &SystemTime, 0, &TimeStr, 64);
              v68 = &TimeStr;
              v67 = &DateStr;
              sub_C49DE0(&Dst, L"%s %s", &DateStr, &TimeStr);
            }
            v110 = 0;
            v106 = 0;
            if ( gdwValue_4F10B8[1] == v92 )
            {
              v105 = 2;
            }
            else
            {
              v107 = 0;
              v105 = 0;
            }
            if ( PE_CheckExeFile(lpFileName, &pTimeDateStamp, (BOOL *)&hObject, &BaseAddress) )
              v109 |= 4u;
            if ( v86 )
            {
              v68 = (wchar_t *)lpFileName;
              v67 = *(WCHAR **)(v86 + 88);
              v122 = sub_C1BB70(v67, (wchar_t *)lpFileName);
            }
            qmemcpy(&v60, &v104, 0x188u);
            sub_C27790(v90, v60);
            v11 = v88;
            v15 = (tagDLLLISTITEMPARAM *)1;
            goto LABEL_52;
          }
        }
LABEL_53:
        v14 += 284;
        v91 = (SYSTEM_PROCESS_INFORMATION *)((char *)v91 + 1);
        if ( (unsigned int)v91 >= *v11 )
        {
          a1 = (signed int)v94;
          break;
        }
      }
    }
    free(v11);
    v5 = v90;
  }
  v23 = v89;
  if ( !sub_C5F870(a1, (int)v5, 0, v86, v92, (int)v89, 0, (int)&v93) )
  {
LABEL_168:
    if ( !(_BYTE)a1 && v93 == v87 || wParam )
      goto LABEL_172;
  }
  LOBYTE(a1) = 1;
LABEL_172:
  gdwValue_4F10B8[1] = v92;
  if ( (_WORD)lParam != 1 )
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, (LPARAM)&lParam);
  if ( !(_BYTE)a1 && v95 == 1 )
    SendMessageW(v5, 0xBu, 1u, 0);
  if ( v23 )
    free(v23);
  return a1;
}
// CB43D4: using guessed type wchar_t aRefreshingDlls[19];
// CD10B8: using guessed type int gdwValue_4F10B8[3];
// CDF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// CF5720: using guessed type int gnStatusBarItemCount;

//----- (00C6A540) --------------------------------------------------------
char __usercall CMainWnd::RefreshHandlesView@<al>(signed int a1@<ebx>, HWND hWnd_1, DWORD dwProcessId, void *pItem)
{
  HWND hWndIn; // esi
  unsigned int v6; // edi
  _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *v7; // ebx
  SYSTEM_HANDLE_INFORMATION *v8; // ecx
  unsigned int i; // esi
  LPARAM v10; // eax
  HWND v11; // edi
  LPARAM v12; // esi
  char v13; // al
  LPARAM v14; // edx
  signed int v15; // eax
  unsigned int j; // esi
  char v17; // bl
  char v18; // cl
  unsigned int v19; // kr00_4
  size_t v20; // ecx
  int v21; // edi
  const wchar_t *v22; // esi
  unsigned int v23; // kr04_4
  int v24; // esi
  wchar_t *v25; // ecx
  int v26; // edx
  wchar_t v27; // ax
  unsigned int v28; // ecx
  unsigned int v29; // edx
  int v30; // edi
  wchar_t *v31; // eax
  int v32; // edx
  wchar_t v33; // cx
  int v34; // eax
  WCHAR *v35; // edx
  int v36; // eax
  WCHAR v37; // cx
  void *v38; // esp
  SYSTEM_HANDLE_INFORMATION *v39; // eax
  DWORD v40; // eax
  char v41; // [esp-10C0h] [ebp-36A4h]
  const wchar_t *v42; // [esp-Ch] [ebp-25F0h]
  WCHAR *v43; // [esp-8h] [ebp-25ECh]
  signed int v44; // [esp-4h] [ebp-25E8h]
  LPARAM v45; // [esp+Ch] [ebp-25D8h]
  int v46; // [esp+10h] [ebp-25D4h]
  int v47; // [esp+14h] [ebp-25D0h]
  LPARAM v48; // [esp+2Ch] [ebp-25B8h]
  int a5; // [esp+40h] [ebp-25A4h]
  void *pEntry; // [esp+44h] [ebp-25A0h]
  unsigned int v51; // [esp+48h] [ebp-259Ch]
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *v52; // [esp+4Fh] [ebp-2595h]
  WCHAR *v53; // [esp+54h] [ebp-2590h]
  int v54; // [esp+58h] [ebp-258Ch]
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo; // [esp+5Ch] [ebp-2588h]
  HWND hWnd; // [esp+60h] [ebp-2584h]
  char v57; // [esp+67h] [ebp-257Dh]
  char v58; // [esp+68h] [ebp-257Ch]
  int v59; // [esp+78h] [ebp-256Ch]
  int v60; // [esp+7Ch] [ebp-2568h]
  char v61; // [esp+80h] [ebp-2564h]
  ULONG_PTR v62; // [esp+8Ch] [ebp-2558h]
  PVOID v63; // [esp+90h] [ebp-2554h]
  ULONG_PTR v64; // [esp+94h] [ebp-2550h]
  ULONG v65; // [esp+98h] [ebp-254Ch]
  int v66; // [esp+9Ch] [ebp-2548h]
  wchar_t v67[64]; // [esp+A0h] [ebp-2544h]
  wchar_t v68[1024]; // [esp+120h] [ebp-24C4h]
  wchar_t v69[1028]; // [esp+920h] [ebp-1CC4h]
  char v70; // [esp+1128h] [ebp-14BCh]
  int v71; // [esp+1138h] [ebp-14ACh]
  wchar_t *v72; // [esp+114Ch] [ebp-1498h]
  wchar_t v73[64]; // [esp+1150h] [ebp-1494h]
  ULONG_PTR v74; // [esp+11D0h] [ebp-1414h]
  ULONG_PTR v75; // [esp+11D8h] [ebp-140Ch]
  wchar_t *v76; // [esp+11DCh] [ebp-1408h]
  __int16 Dst[1024]; // [esp+11E0h] [ebp-1404h]
  WCHAR pszText[256]; // [esp+19E0h] [ebp-C04h]
  __int16 Src[1024]; // [esp+1BE0h] [ebp-A04h]
  WCHAR szText[256]; // [esp+23E0h] [ebp-204h]

  hWnd = hWnd_1;
  LOBYTE(a1) = 0;
  v54 = a1;
  szText[0] = 1;
  v57 = 0;
  memset(&szText[1], 0, 0x1FEu);
  if ( !pItem && (!gConfig.dwHandleColumnCount || !gConfig.bShowLowerPane) )
    return 0;
  QuerySystemHandleInfo(pItem != 0);
  if ( pItem )
  {
    pSystemHandleInfo = gpSystemHandleInfo;
LABEL_7:
    hWndIn = hWnd;
    goto LABEL_8;
  }
  pSystemHandleInfo = gpSystemHandleInfo2;
  if ( dwProcessId == gdwValue_4F10B8[0] )
  {
    v10 = pItemParam;
    if ( !pItemParam )
      goto LABEL_7;
    v11 = hWnd;
    do
    {
      v12 = *(_DWORD *)(v10 + 0x10B8);
      v48 = v10;
      v46 = -1;
      v13 = sub_C658D0(a1, v11, (LVITEMW *)&v45, v10, (int)&v52);
      a1 = (unsigned __int8)a1;
      if ( v13 )
        a1 = 1;
      v10 = v12;
    }
    while ( v12 );
    v54 = a1;
    hWndIn = v11;
  }
  else
  {
    hWndIn = hWnd;
    v57 = 1;
    SendMessageW(hWnd, WM_SETREDRAW, 0, 0);
    SendMessageW(hWnd, LVM_DELETEALLITEMS, 0, 0);
    SendMessageW(ghWndStatusBar, SB_GETTEXTW, gnStatusBarItemCount - 1, (LPARAM)szText);
    SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, (LPARAM)L"Refreshing handles...");
    UpdateMenuStatus(0, 5);
  }
LABEL_8:
  v6 = 0;
  v51 = 0;
  if ( !SystemHandleInfo_GetHandlesNumber(pSystemHandleInfo) )
    goto LABEL_80;
  do
  {
    GetHandleTableEntry(pSystemHandleInfo, v6, (SYSTEM_HANDLE_TABLE_ENTRY_INFO **)&pEntry);
    v7 = (_SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *)pEntry;
    if ( pItem )
      goto LABEL_46;
    if ( *((_DWORD *)pEntry + 1) != dwProcessId )
      goto LABEL_78;
    if ( !SendMessageW(hWndIn, LVM_GETITEMCOUNT, 0, 0) )
      goto LABEL_46;
    v8 = gpSystemHandleInfo3;
    if ( gpSystemHandleInfo3 )
    {
      for ( i = 0; v8 && i < v8->NumberOfHandles; ++i )
      {
        GetHandleTableEntry(v8, i, (SYSTEM_HANDLE_TABLE_ENTRY_INFO **)((char *)&v52 + 1));
        if ( *(PVOID *)&(*(SYSTEM_HANDLE_TABLE_ENTRY_INFO **)((char *)&v52 + 1))->UniqueProcessId == v7->Object
          && (*(SYSTEM_HANDLE_TABLE_ENTRY_INFO **)((char *)&v52 + 1))->Object == (PVOID)v7->HandleValue )
        {
          goto LABEL_78;
        }
        v8 = gpSystemHandleInfo3;
      }
    }
    v14 = pItemParam;
    v45 = 4;
    v47 = 0;
    if ( !pItemParam )
    {
LABEL_31:
      if ( !gConfig.bShowUnnamedHandles && v8 )
      {
        for ( j = 0; v8 && j < v8->NumberOfHandles; ++j )
        {
          GetHandleTableEntry(v8, j, (SYSTEM_HANDLE_TABLE_ENTRY_INFO **)((char *)&v52 + 1));
          if ( (*(SYSTEM_HANDLE_TABLE_ENTRY_INFO **)((char *)&v52 + 1))->Object == (PVOID)v7->HandleValue
            && *(PVOID *)&(*(SYSTEM_HANDLE_TABLE_ENTRY_INFO **)((char *)&v52 + 1))->UniqueProcessId == v7->Object )
          {
            goto LABEL_78;
          }
          v8 = gpSystemHandleInfo3;
        }
      }
LABEL_46:
      Src[0] = 0;
      PE_QueryObject(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], v7, (wchar_t *)Src, 0x400u, (WCHAR **)&a5);
      if ( !gConfig.bShowUnnamedHandles && !Src[0] )
        goto LABEL_78;
      wcscpy_s((wchar_t *)Dst, 0x400u, (const wchar_t *)Src);
      if ( _wcsicmp(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], L"Key") )
      {
        if ( !_wcsicmp(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], L"File")
          || !_wcsicmp(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], L"Section") )
        {
          sub_C50DD0((wchar_t *)Src);
        }
      }
      else
      {
        sub_C50EE0((wchar_t *)Src);
      }
      if ( !pItem )
      {
        v62 = v7->UniqueProcessId;
        v64 = v7->HandleValue;
        v65 = v7->GrantedAccess;
        v63 = v7->Object;
        v66 = a5;
        wcscpy_s(v67, 0x40u, &gpszObjectTypeNames[64 * v7->ObjectTypeIndex]);
        wcscpy_s(v68, 0x400u, (const wchar_t *)Dst);
        wcscpy_s(v69, 0x400u, (const wchar_t *)Src);
        v60 = 0;
        if ( gdwValue_4F10B8[0] == dwProcessId )
        {
          v59 = 2;
        }
        else
        {
          v61 = 0;
          v59 = 0;
        }
        v38 = alloca(0x10C0);
        qmemcpy(&v41, &v58, 0x10C0u);
        sub_C27A90(hWnd);
        v54 = 1;
        goto LABEL_76;
      }
      if ( *(_BYTE *)pItem == 1 )
        break;
      v19 = wcslen((const unsigned __int16 *)Src);
      v20 = wcslen(gszStringToFindLast);
      if ( v19 < v20 || (v21 = 0, (signed int)(v19 - v20 + 1) <= 0) )
      {
LABEL_60:
        v24 = v7->ObjectTypeIndex;
        v25 = &gpszObjectTypeNames[64 * v24];
        v26 = (int)(v25 + 1);
        do
        {
          v27 = *v25;
          ++v25;
        }
        while ( v27 );
        v28 = ((signed int)v25 - v26) >> 1;
        v29 = wcslen(gszStringToFindLast);
        if ( v28 < v29 )
          goto LABEL_76;
        v30 = 0;
        if ( (signed int)(v28 - v29 + 1) <= 0 )
          goto LABEL_76;
        while ( 1 )
        {
          v42 = &gpszObjectTypeNames[v30 + (v24 << 6)];
          if ( !_wcsnicmp(v42, gszStringToFindLast, v29) )
            break;
          v24 = v7->ObjectTypeIndex;
          ++v30;
          v31 = &gpszObjectTypeNames[64 * v24];
          v32 = (int)(v31 + 1);
          do
          {
            v33 = *v31;
            ++v31;
          }
          while ( v33 );
          v34 = (int)v31 - v32;
          v35 = gszStringToFindLast;
          v36 = v34 >> 1;
          v53 = &gszStringToFindLast[1];
          do
          {
            v37 = *v35;
            ++v35;
          }
          while ( v37 );
          v29 = v35 - v53;
          if ( v30 >= (signed int)(v36 - v29 + 1) )
            goto LABEL_76;
        }
      }
      else
      {
        v22 = (const wchar_t *)Src;
        while ( _wcsnicmp(v22, gszStringToFindLast, v20) )
        {
          ++v22;
          v23 = wcslen((const unsigned __int16 *)Src);
          v20 = wcslen(gszStringToFindLast);
          v53 = (WCHAR *)++v21;
          if ( v21 >= (signed int)(v23 - v20 + 1) )
            goto LABEL_60;
        }
      }
      v44 = 256;
      v43 = pszText;
      v42 = 0;
      SystemProcessInfo_GetSystemProcessName(v7->UniqueProcessId, 0, pszText, 0x100u);
      v72 = _wcsdup(pszText);
      v76 = _wcsdup((const wchar_t *)Src);
      wcscpy_s(v73, 0x40u, &gpszObjectTypeNames[64 * v7->ObjectTypeIndex]);
      v74 = v7->UniqueProcessId;
      v71 = 0;
      v75 = v7->HandleValue;
      sub_C278D0(hWnd, (wchar_t *)&v70);
LABEL_76:
      if ( SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0) == 10000 )
        break;
      v6 = v51;
      goto LABEL_78;
    }
    while ( 1 )
    {
      if ( *(_DWORD *)(v14 + 44) == v7->HandleValue )
      {
        v15 = *(_DWORD *)(v14 + 40);
        if ( (PVOID)v15 == v7->Object )
          break;
      }
      v14 = *(_DWORD *)(v14 + 4280);
      if ( !v14 )
        goto LABEL_31;
    }
    v17 = *(_BYTE *)(v14 + 24);
    v18 = 0;
    if ( v17 )
    {
      v15 = *(_DWORD *)(v14 + 28);
      if ( v15 < (signed int)gConfig.dwHighlightDuration )
      {
        *(_DWORD *)(v14 + 16) = 2;
        *(_DWORD *)(v14 + 20) = v15;
        goto LABEL_78;
      }
      if ( v17 )
      {
        v18 = 1;
        *(_BYTE *)(v14 + 24) = 0;
      }
    }
    *(_DWORD *)(v14 + 16) = 0;
    if ( v18 )
    {
      LOBYTE(v15) = 1;
      v54 = v15;
    }
LABEL_78:
    v51 = ++v6;
    v39 = SystemHandleInfo_GetHandlesNumber(pSystemHandleInfo);
    hWndIn = hWnd;
  }
  while ( v6 < (unsigned int)v39 );
  LOBYTE(a1) = v54;
LABEL_80:
  v40 = gdwValue_4F10B8[0];
  if ( !pItem )
    v40 = dwProcessId;
  gdwValue_4F10B8[0] = v40;
  if ( szText[0] != 1 )
    SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, (LPARAM)szText);
  if ( !(_BYTE)a1 && v57 == 1 )
    SendMessageW(hWnd, WM_SETREDRAW, 1u, 0);
  return a1;
}
// CB445C: using guessed type wchar_t aRefreshingHand[22];
// CD10B8: using guessed type int gdwValue_4F10B8[3];
// CF5720: using guessed type int gnStatusBarItemCount;
