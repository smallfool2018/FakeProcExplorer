//----- (01045E50) --------------------------------------------------------
int __stdcall PageProcPerfETW(HWND hWnd, int a2, HDC hdc, int a4)
{
  void *v4; // eax
  void *v5; // ebx
  _DWORD *v6; // eax
  int result; // eax
  HWND v8; // eax
  const WCHAR *v9; // eax
  const WCHAR *v10; // eax
  const WCHAR *v11; // eax
  const WCHAR *v12; // eax
  const WCHAR *v13; // eax
  const WCHAR *v14; // eax
  const WCHAR *v15; // eax
  const WCHAR *v16; // eax
  const WCHAR *v17; // eax
  const WCHAR *v18; // eax
  const WCHAR *v19; // eax
  const WCHAR *v20; // eax
  signed __int64 v21; // [esp+10h] [ebp-218h]
  WCHAR String; // [esp+24h] [ebp-204h]

  v4 = GetWindowLongW(hWnd, -21);
  v5 = v4;
  if ( a2 <= 0x133 )
  {
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 256:
          if ( hdc != 116 )
            return 0;
          PostMessageW(hWnd, 0x113u, 1u, 0);
          result = 0;
          break;
        case 272:
          PropSheet_UpdateTab(hWnd);
          v6 = malloc(0x60u);
          *v6 = a4;
          SetWindowLongW(hWnd, -21, v6);
          SendMessageW(hWnd, 0x113u, 0, 0);
          result = 0;
          break;
        case 273:
          switch ( hdc )
          {
            case 0x9C41u:
              v21 = 40014i64;
              goto LABEL_11;
            case 0x9C42u:
              SetEvent(ghRefreshEventHandle);
              result = 0;
              break;
            case 0x9C9Cu:
            case 0x9C9Du:
              v21 = hdc;
LABEL_11:
              v8 = GetParent(hWnd);
              PostMessageW(v8, 0x111u, v21, SHIDWORD(v21));
              result = 0;
              break;
            default:
              return 0;
          }
          break;
        case 275:
          wsprintf(&String, L"%u", *(*v4 + 1176));
          v9 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1186, v9);
          wsprintf(&String, L"%u", *(*v5 + 1192));
          v10 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1048, v10);
          wsprintf(&String, L"%u", *(*v5 + 1208));
          v11 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1187, v11);
          wsprintf(&String, L"%u", *(*v5 + 1224));
          v12 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1053, v12);
          wsprintf(&String, L"%u", *(*v5 + 1240));
          v13 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1047, v13);
          wsprintf(&String, L"%u", *(*v5 + 1256));
          v14 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1052, v14);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1232), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1336, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1200), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1335, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1264), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1054, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1216), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1204, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1184), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1202, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1248), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1206, &String);
          wsprintf(&String, L"%u", *(*v5 + 1072));
          v15 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1638, v15);
          wsprintf(&String, L"%u", *(*v5 + 1088));
          v16 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1639, v16);
          wsprintf(&String, L"%u", *(*v5 + 1104));
          v17 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1641, v17);
          wsprintf(&String, L"%u", *(*v5 + 1120));
          v18 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1643, v18);
          wsprintf(&String, L"%u", *(*v5 + 1136));
          v19 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1645, v19);
          wsprintf(&String, L"%u", *(*v5 + 1152));
          v20 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1646, v20);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1128), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1644, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1096), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1640, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1160), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1647, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1112), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1205, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1080), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1203, &String);
          PE_FormatDouble(0, &String, 0x100u, *(*v5 + 1144), 0.0, COERCE_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1207, &String);
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
    free(v4);
    DestroyWindow(hWnd);
  }
  return 0;
}

//----- (010466A0) --------------------------------------------------------
BOOL __stdcall ProcPropSheet(HWND hDlg, UINT uMsg, WPARAM wParam, PROPITEM *PropItem)
{
  HWND hWndTab; // eax
  HWND hWndTab_1; // ebx
  HWND *v6; // eax
  HWND *v8; // edi
  HWND v9; // eax
  LRESULT v10; // eax
  _DWORD *v11; // ebx
  LRESULT v12; // esi
  char *v13; // edi
  BOOL (__stdcall *v14)(HWND, UINT, WPARAM, LPARAM); // ST14_4
  signed int v15; // edi
  HWND *v16; // esi
  WPARAM v17; // eax
  LRESULT v18; // eax
  WPARAM v19; // ecx
  _DWORD *i; // eax
  CResizer *v21; // eax
  LONG v22; // eax
  LONG v23; // eax
  const wchar_t *v24; // ecx
  WPARAM nTabIndex; // ebx
  WPARAM nTabIndex_1; // esi
  WPARAM nTabIndex_2; // esi
  tagTREEVIEWLISTITEMPARAM *pListItem; // eax
  WPARAM nTabIndex_3; // esi
  WPARAM nTabIndex_4; // esi
  HWND hWndTab_3; // esi
  WPARAM nTabIdx; // ebx
  _DWORD *v33; // eax
  int nTabItem; // ebx
  int v35; // esi
  int nTabItem_1; // esi
  int v37; // ebx
  HANDLE ProcessHandle; // eax
  tagTREEVIEWLISTITEMPARAM *pListItem_1; // ecx
  HANDLE v40; // esi
  bool v41; // zf
  tagTREEVIEWLISTITEMPARAM *pListItem_2; // eax
  int v43; // esi
  int v44; // esi
  void *v45; // esi
  int v46; // esi
  int v47; // esi
  WPARAM v48; // ST14_4
  _DWORD *v49; // eax
  HWND hWnd; // esi
  UINT v51; // eax
  WPARAM nTab; // ecx
  POINT v53; // ST14_8
  HCURSOR v54; // eax
  struct tagPOINT Point; // [esp+10h] [ebp-264h]
  NMHDR lParam; // [esp+18h] [ebp-25Ch]
  tagTCITEMW tcitem; // [esp+24h] [ebp-250h]
  HWND hDlg_1; // [esp+40h] [ebp-234h]
  HWND hWndTab_2; // [esp+44h] [ebp-230h]
  HANDLE hObject; // [esp+48h] [ebp-22Ch]
  struct tagRECT Rect; // [esp+4Ch] [ebp-228h]
  WCHAR pszBuffer[260]; // [esp+5Ch] [ebp-218h]
  int v63; // [esp+270h] [ebp-4h]

  hDlg_1 = hDlg;
  hWndTab = GetDlgItem(hDlg, IDS_PROCPROPSHEET_TABCTRL);
  hWndTab_1 = hWndTab;
  hWndTab_2 = hWndTab;
  v6 = GetWindowLongW(hDlg, GWL_USERDATA);
  hObject = v6;
  if ( uMsg > WM_NOTIFY )
  {
    if ( uMsg == WM_INITDIALOG )
    {
      ShowWindow(hDlg, 0);
      v21 = operator new(0x40u);
      hObject = v21;
      v63 = 0;
      if ( v21 )
        CResizer::CResizer(v21, hDlg);
      v63 = -1;
      SetWindowLongW(hDlg, GWL_USERDATA, PropItem);
      tcitem.mask = 3;
      tcitem.iImage = -1;
      v22 = GetWindowLongW(hWndTab_1, GWL_EXSTYLE);
      SetWindowLongW(hWndTab_1, -20, v22 | WS_EX_CONTROLPARENT);
      v23 = GetWindowLongW(hWndTab_1, -16);
      SetWindowLongW(hWndTab_1, GWL_STYLE, v23 | WS_CLIPCHILDREN);
      if ( PropItem->pListItem )
      {
        TreeViewItemParam_InitGraph(PropItem->pListItem);
        tcitem.pszText = L"Image";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 0, &tcitem);
        wcscpy_s(PropItem->PageData[1].szTemplateName, 256u, L"PROCPERF");
        PropItem->PageData[1].nTabId = 2;
        PropItem->PageData[1].PageWndProc = PageProcPerf;
        tcitem.pszText = L"Performance";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 1u, &tcitem);
        v24 = L"PROCCPUIO";
        if ( !*(PropItem->pListItem + 266) )
          v24 = L"PROCCPU";
        wcscpy_s(PropItem->PageData[2].szTemplateName, 256u, v24);
        PropItem->PageData[2].nTabId = 4;
        PropItem->PageData[2].PageWndProc = PageProcCPU;
        tcitem.pszText = L"Performance Graph";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 2u, &tcitem);
        nTabIndex = 3;
        if ( gbFlagsInProcPropSheet )
        {
          wcscpy_s(PropItem->PageData[3].szTemplateName, 256u, L"PROCPERFETW");
          PropItem->PageData[3].nTabId = 14;
          PropItem->PageData[3].PageWndProc = PageProcPerfETW;
          tcitem.pszText = L"Disk and Network";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, 3u, &tcitem);
          nTabIndex = 4;
        }
        if ( gdwAdapterRuntingTime )
        {
          nTabIndex_1 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCGPU");
          PropItem->PageData[nTabIndex_1].nTabId = 15;
          PropItem->PageData[nTabIndex_1].PageWndProc = PageProcGPU;
          tcitem.pszText = L"GPU Graph";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, &tcitem);
        }
        if ( *(PropItem->pListItem + 40) & 0x20 )
        {
          nTabIndex_2 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCSERVICES");
          PropItem->PageData[nTabIndex_2].nTabId = 5;
          PropItem->PageData[nTabIndex_2].PageWndProc = PageProcServices;
          tcitem.pszText = L"Services";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, &tcitem);
        }
        pListItem = PropItem->pListItem;
        if ( pListItem && pListItem->bSupportWMIProviders )
        {
          nTabIndex_3 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCWMIPROVIDERS");
          PropItem->PageData[nTabIndex_3].nTabId = 16;
          PropItem->PageData[nTabIndex_3].PageWndProc = PageProcWMIProviders;
          tcitem.pszText = L"WMI Providers";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, &tcitem);
        }
        nTabIndex_4 = nTabIndex;
        wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCTHREADS");
        PropItem->PageData[nTabIndex_4].nTabId = 6;
        PropItem->PageData[nTabIndex_4].PageWndProc = PageProcThreads;
        hWndTab_3 = hWndTab_2;
        tcitem.pszText = L"Threads";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex, &tcitem);
        nTabIdx = nTabIndex + 1;
        hObject = PropItem + sizeof(PROPPAGEDATA) * nTabIdx;
        if ( AllocateAndGetUdpExTable2FromStack )
          wcscpy_s(hObject + 6, 256u, L"PROCTCPUDPSTACK");
        else
          wcscpy_s(hObject + 6, 256u, L"PROCTCPUDP");
        v33 = hObject;
        tcitem.pszText = L"TCP/IP";
        *(hObject + 131) = 7;
        v33[132] = PageProcTcpUdp;
        SendMessageW(hWndTab_3, TCM_INSERTITEMW, nTabIdx, &tcitem);
        nTabItem = nTabIdx + 1;
        v35 = nTabItem;
        wcscpy_s(PropItem->PageData[nTabItem].szTemplateName, 256u, L"PROCSECURITY");
        PropItem->PageData[v35].nTabId = 8;
        PropItem->PageData[v35].PageWndProc = PageProcSecurity;
        tcitem.pszText = L"Security";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabItem++, &tcitem);
        nTabItem_1 = nTabItem;
        wcscpy_s(PropItem->PageData[nTabItem].szTemplateName, 256u, L"PROCENV");
        PropItem->PageData[nTabItem_1].nTabId = 9;
        PropItem->PageData[nTabItem_1].PageWndProc = PageProcEnv;
        tcitem.pszText = L"Environment";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabItem, &tcitem);
        v37 = nTabItem + 1;
        ProcessHandle = PE_OpenProcess(MAXIMUM_ALLOWED, 0, *(PropItem->pListItem + 17));
        pListItem_1 = PropItem->pListItem;
        v40 = ProcessHandle;
        hObject = ProcessHandle;
        v41 = PE_IsProcessInJob(ProcessHandle, pListItem_1->dwProcessId, 0, 0) == 0;
        pListItem_2 = PropItem->pListItem;
        if ( v41 )
        {
          pListItem_2->dwStyle &= -0x801u;
        }
        else
        {
          pListItem_2->dwStyle |= 0x800u;
          v43 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 256u, L"PROCJOB");
          PropItem->PageData[v43].nTabId = 10;
          PropItem->PageData[v43].PageWndProc = PageProcJob;
          tcitem.pszText = L"Job";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37, &tcitem);
          v40 = hObject;
          ++v37;
        }
        if ( v40 )
          CloseHandle(v40);
        if ( ProcessIsNetCclr_0(PropItem->pListItem) )
        {
          v44 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCCLR");
          PropItem->PageData[v44].nTabId = 11;
          PropItem->PageData[v44].PageWndProc = PageProcCclr;
          tcitem.pszText = L".NET Assemblies";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37++, &tcitem);
          if ( !*(PropItem->pListItem + 321) )
          {
            v45 = malloc(0x88u);
            memset(v45, 0, 0x88u);
            *(PropItem->pListItem + 321) = v45;
          }
        }
        if ( *(PropItem->pListItem + 321) )
        {
          CoInitialize(0);
          v46 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCNET");
          PropItem->PageData[v46].nTabId = 12;
          PropItem->PageData[v46].PageWndProc = PageProcNet;
          tcitem.pszText = L".NET Performance";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37++, &tcitem);
        }
        v47 = v37;
        wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCSTRINGS");
        PropItem->PageData[v47].nTabId = 13;
        PropItem->PageData[v47].PageWndProc = PageProcStrings;
        tcitem.pszText = L"Strings";
        v48 = v37;
        hWndTab_1 = hWndTab_2;
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, v48, &tcitem);
        v49 = PropItem->pListItem;
        if ( v49[216] )
        {
          swprintf(pszBuffer, L"%s:%d (%s) Properties", v49[15], v49[17], v49[216]);
        }
        else if ( v49[17] < 0 )
        {
          swprintf(pszBuffer, L"%s Properties", v49[15]);
        }
        else
        {
          swprintf(pszBuffer, L"%s:%d Properties", v49[15], v49[17]);
        }
        hWnd = hDlg_1;
        SetWindowTextW(hDlg_1, pszBuffer);
        PropItem->PageData[0].hWnd = CreateDialogParamW(
                                       ghMainInstance,
                                       L"PROCINFO",
                                       hWnd,
                                       PageProcInfo,
                                       PropItem->pListItem);
        PropItem->PageData[0].nTabId = 1;
      }
      else
      {
        hWnd = hDlg_1;
      }
      ShowWindow(PropItem->PageData[0].hWnd, SW_SHOW);
      SetForegroundWindow(hWnd);
      v51 = PropItem->PageData[0].nTabId;
      nTab = 0;
      if ( v51 )
      {
        while ( gConfig.dwDefaultProcPropPage != v51 )
        {
          v51 = *(&PropItem->nTabIndex + 131 * (++nTab + 1));
          if ( !v51 )
            goto LABEL_77;
        }
      }
      else
      {
LABEL_77:
        nTab = 0;
      }
      SendMessageW(hWndTab_1, TCM_SETCURSEL, nTab, 0);
      lParam.idFrom = IDS_PROCPROPSHEET_TABCTRL;
      lParam.code = TCN_SELCHANGE;
      SendMessageW(hWnd, WM_NOTIFY, 0, &lParam);
      if ( gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.right == gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.left )
      {
        GetCursorPos(&Point);
        v53.y = Point.y - 408;
        v53.x = Point.x - 385;
        PE_SetWindowPlacement(hWnd, v53);
      }
      else
      {
        sub_104DC50(hWnd, PropItem->pListItem);
      }
      ShowWindow(hWnd, 5);
      InterlockedDecrement(&gnRefCount);
      v54 = LoadCursorW(0, IDC_ARROW);
      SetCursor(v54);
      return 1;
    }
    if ( uMsg == 273 )
    {
      if ( wParam > 40092 )
      {
        if ( wParam == 40093 )
        {
          v18 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0);
          v19 = v18 - 1;
          if ( !v18 )
          {
            v19 = 0;
            for ( i = hObject + 1052; *i; ++v19 )
              i += 131;
          }
          SendMessageW(hWndTab_1, TCM_SETCURSEL, v19, 0);
          lParam.idFrom = 1110;
          lParam.code = -551;
          SendMessageW(hDlg, WM_NOTIFY, 0, &lParam);
        }
      }
      else
      {
        if ( wParam == 40092 )
        {
          v17 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0) + 1;
          if ( !*(hObject + 131 * v17 + 132) )
            v17 = 0;
          SendMessageW(hWndTab_1, TCM_SETCURSEL, v17, 0);
          lParam.idFrom = 1110;
          lParam.code = -551;
          SendMessageW(hDlg_1, WM_NOTIFY, 0, &lParam);
          return 0;
        }
        if ( wParam > 0 && (wParam <= 2 || wParam == 40014) )
        {
          ShowWindow(hDlg, 0);
          v15 = 32;
          v16 = (hObject + 8);
          while ( 1 )
          {
            if ( *v16 )
            {
              SendMessageW(*v16, WM_COMMAND, wParam, 0);
              SendMessageW(*v16, WM_MSG_7F1, 0, 0);
            }
            v16 += 131;
            if ( !--v15 )
            {
              PostMessageW(ghMainWnd, WM_MSG_7ED, 0, *(hObject + 1));
              if ( *(*(hObject + 1) + 1284) )
                CoUninitialize();
              free(hObject);
              GetWindowPlacement(hDlg_1, &gConfig.WindowPlacement[2]);
              DestroyWindow(hDlg_1);
              _endthread();
            }
          }
        }
      }
    }
    return 0;
  }
  if ( uMsg == WM_NOTIFY )
  {
    if ( PropItem->pListItem == 1110 && PropItem->PageData[0].hWnd == -551 )
    {
      v10 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0);
      v11 = hObject;
      v12 = v10;
      v13 = hObject + 524 * v10;
      hObject = v13;
      gConfig.dwDefaultProcPropPage = *(v13 + 131);
      ShowWindow(v11[131 * *v11 + 2], 0);
      *v11 = v12;
      if ( !*(v13 + 2) )
      {
        v14 = *(v13 + 132);
        v13 = hObject;
        *(hObject + 2) = CreateDialogParamW(ghMainInstance, hObject + 6, hDlg_1, v14, v11[1]);
      }
      ShowWindow(*(v13 + 2), 5);
      return 0;
    }
    return 0;
  }
  if ( uMsg != 5 )
  {
    if ( uMsg == 36 )
    {
      PropItem->PageData[0].hWnd = (2 * gdwVirtualScreenWidth);
      return 0;
    }
    return 0;
  }
  v8 = v6 + 2;
  v9 = 32;
  hDlg_1 = 32;
  do
  {
    if ( *v8 )
    {
      GetWindowRect(hWndTab_1, &Rect);
      SendMessageW(hWndTab_1, TCM_ADJUSTRECT, 0, &Rect);
      MapWindowPoints(0, hDlg, &Rect, 2u);
      MoveWindow(*v8, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 1);
      InvalidateRect(*v8, 0, 1);
      v9 = hDlg_1;
    }
    v8 += 131;
    v9 = (v9 - 1);
    hDlg_1 = v9;
  }
  while ( v9 );
  return 0;
}
// 106A009: using guessed type int _endthread(void);
// 108CFEC: using guessed type wchar_t aEnvironment[12];
// 10A5168: using guessed type wchar_t aSecurity_0[9];
// 10A6390: using guessed type wchar_t aPerformance[12];
// 10A63A8: using guessed type wchar_t aProccpuio[10];
// 10A63CC: using guessed type wchar_t aPerformanceGra[18];
// 10A6408: using guessed type wchar_t aDiskAndNetwork[17];
// 10A643C: using guessed type wchar_t aGpuGraph[10];
// 10A646C: using guessed type wchar_t aServices_0[9];
// 10A64A4: using guessed type wchar_t aWmiProviders_0[14];
// 10A64D8: using guessed type wchar_t aThreads[8];
// 10A64E8: using guessed type wchar_t aProctcpudpstac[16];
// 10A6520: using guessed type wchar_t aTcpIp[7];
// 10A657C: using guessed type wchar_t aNetAssemblies[16];
// 10A65AC: using guessed type wchar_t aNetPerformance[17];
// 10A65E8: using guessed type wchar_t aStrings[8];
// 10C4E28: using guessed type int gdwVirtualScreenWidth;
// 10C5390: using guessed type char gbFlagsInProcPropSheet;

//----- (01047240) --------------------------------------------------------
void __cdecl __noreturn CTreeList::BackendFillTreeViewParamThreadProc(tagTREEVIEWLISTITEMPARAM *pItem)
{
  HCURSOR v1; // eax
  PROPITEM *PropItem; // esi
  HWND hDlgSheet; // ebx
  char *v4; // edi
  HWND v5; // eax
  HWND hWndFind; // esi
  DWORD dwRet; // ebx
  PROPPAGEDATA *PageData; // esi
  signed int nPageIndex; // edi
  UINT uMsg; // eax
  struct tagMSG msg; // [esp+Ch] [ebp-2Ch]
  HANDLE Handles[2]; // [esp+28h] [ebp-10h]
  HACCEL hAccel; // [esp+30h] [ebp-8h]
  PROPITEM *v14; // [esp+34h] [ebp-4h]
  tagTREEVIEWLISTITEMPARAM *pInfoa; // [esp+40h] [ebp+8h]

  InterlockedIncrement(&gnRefCount);
  v1 = LoadCursorW(0, IDC_APPSTARTING);
  SetCursor(v1);
  PropItem = malloc(sizeof(PROPITEM));
  v14 = PropItem;
  memset(PropItem, 0, sizeof(PROPITEM));
  PropItem->pListItem = pItem;
  hDlgSheet = CreateDialogParamW(ghMainInstance, L"PROCPROPSHEET", ghMainWnd, ProcPropSheet, PropItem);
  pInfoa = hDlgSheet;
  hAccel = LoadAcceleratorsW(ghMainInstance, L"PROCPROPERTIES");
  while ( !PeekMessageW(&msg, 0, 0, 0, PM_REMOVE) )
  {
LABEL_15:
    Handles[0] = ghTimerRefreshProcPageEventHandle;
    Handles[1] = ghEvent6;
    dwRet = MsgWaitForMultipleObjects(2u, Handles, 0, 0xFFFFFFFF, QS_ALLINPUT);
    if ( dwRet != 2 )
    {
      PageData = PropItem->PageData;
      nPageIndex = 32;
      do
      {
        if ( PageData->hWnd )
        {
          uMsg = WM_USER;
          if ( !dwRet )
            uMsg = WM_TIMER;
          PostMessageW(PageData->hWnd, uMsg, 1u, 0);
        }
        ++PageData;
        --nPageIndex;
      }
      while ( nPageIndex );
      PropItem = v14;
    }
    hDlgSheet = pInfoa;
  }
  while ( 1 )
  {
    v4 = PropItem + sizeof(PROPPAGEDATA) * PropItem->nTabIndex;
    v5 = *(v4 + 2);
    if ( v5 && TranslateAcceleratorW(v5, hAccel, &msg) )
      goto LABEL_14;
    hWndFind = GetPropW(hDlgSheet, L"FindWindow");
    if ( !hWndFind )
    {
LABEL_10:
      if ( !IsDialogMessageW(*(v4 + 2), &msg) && !IsDialogMessageW(hDlgSheet, &msg) )
      {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
      }
      goto LABEL_13;
    }
    if ( IsDialogMessageW(hWndFind, &msg) )
    {
      if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
        goto LABEL_13;
    }
    else if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
    {
      goto LABEL_10;
    }
    PostMessageW(hWndFind, WM_COMMAND, IDABORT, 0);
    SetPropW(hDlgSheet, L"FindWindow", 0);
LABEL_13:
    PropItem = v14;
LABEL_14:
    if ( !PeekMessageW(&msg, 0, 0, 0, 1u) )
      goto LABEL_15;
  }
}

//----- (01047440) --------------------------------------------------------
int __stdcall sub_1047440(volatile LONG *lpAddend)
{
  signed int v1; // edi
  HWND v2; // ST0C_4
  DWORD v3; // eax
  void *v4; // ST18_4
  PSID v5; // ST14_4
  DWORD v6; // eax
  HWND v7; // eax
  wchar_t *v8; // eax
  LPARAM v9; // ST18_4
  HWND v10; // eax
  HWND v11; // ST0C_4
  LPARAM lParam; // [esp+Ch] [ebp-46Ch]
  int v14; // [esp+10h] [ebp-468h]
  int v15; // [esp+14h] [ebp-464h]
  int v16; // [esp+2Ch] [ebp-44Ch]
  enum _SID_NAME_USE peUse; // [esp+40h] [ebp-438h]
  WPARAM wParam; // [esp+44h] [ebp-434h]
  WPARAM v19; // [esp+48h] [ebp-430h]
  DWORD cchName; // [esp+4Ch] [ebp-42Ch]
  void *v21; // [esp+50h] [ebp-428h]
  DWORD cchReferencedDomainName; // [esp+54h] [ebp-424h]
  LRESULT v23; // [esp+58h] [ebp-420h]
  PSID Sid; // [esp+5Ch] [ebp-41Ch]
  int v25; // [esp+60h] [ebp-418h]
  WCHAR Name; // [esp+64h] [ebp-414h]
  WCHAR ReferencedDomainName; // [esp+26Ch] [ebp-20Ch]

  lParam = 0;
  memset(&v14, 0, 0x30u);
  EnterCriticalSection((lpAddend + 3));
  v1 = 0;
  v23 = SendMessageW(*(lpAddend + 9), 0x1004u, 0, 0);
  if ( v23 > 0 )
  {
    do
    {
      if ( *(lpAddend + 40) == 1 )
        break;
      lParam = 4;
      v2 = *(lpAddend + 9);
      v14 = v1;
      v15 = 0;
      if ( !SendMessageW(v2, 0x104Bu, 0, &lParam) )
        break;
      v25 = v16;
      v3 = GetLengthSid(*(v16 + 36));
      Sid = malloc(v3);
      v4 = *(v25 + 36);
      v5 = Sid;
      v6 = GetLengthSid(*(v25 + 36));
      CopySid(v6, v5, v4);
      LeaveCriticalSection((lpAddend + 3));
      cchName = 260;
      cchReferencedDomainName = 260;
      if ( LookupAccountSidW(
             &gszNullString,
             Sid,
             &Name,
             &cchName,
             &ReferencedDomainName,
             &cchReferencedDomainName,
             &peUse) )
      {
        if ( ReferencedDomainName )
        {
          wcscat_s(&ReferencedDomainName, 0x104u, L"\\");
          wcscat_s(&ReferencedDomainName, 0x104u, &Name);
        }
        else
        {
          wcscpy_s(&ReferencedDomainName, 0x104u, &Name);
        }
        EnterCriticalSection((lpAddend + 3));
        if ( *(lpAddend + 40) )
          break;
        LeaveCriticalSection((lpAddend + 3));
        v7 = GetParent(*(lpAddend + 9));
        SendMessageW(v7, 0x7F7u, v1, &ReferencedDomainName);
        v21 = *(v25 + 40);
        v8 = _wcsdup(&ReferencedDomainName);
        *(v25 + 40) = v8;
        if ( v21 )
          free(v21);
      }
      EnterCriticalSection((lpAddend + 3));
      free(Sid);
      ++v1;
    }
    while ( v1 < v23 );
  }
  v9 = *(lpAddend + 9);
  v10 = GetParent(*(lpAddend + 9));
  SendMessageW(v10, 0x7F6u, 0, v9);
  LeaveCriticalSection((lpAddend + 3));
  SendMessageW(*(lpAddend + 9), 0x101Eu, 0, 0xFFFF);
  if ( !InterlockedDecrement(lpAddend) )
  {
    DeleteCriticalSection((lpAddend + 3));
    free(lpAddend);
  }
  InvalidateRect(*(lpAddend + 9), 0, 0);
  v19 = nItem;
  v11 = *(lpAddend + 9);
  wParam = 1040;
  SendMessageW(v11, 0x1030u, &wParam, PropProcThreadsSortCallback);
  return 0;
}

//----- (01047710) --------------------------------------------------------
int __stdcall PageProcSecurity(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LONG v4; // ebx
  CResizer *v5; // eax
  CResizer *v6; // esi
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  struct tagResizerItem *v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HICON v18; // ST24_4
  HWND v19; // eax
  HICON v20; // ST24_4
  HWND v21; // eax
  HWND v22; // edi
  LONG v23; // eax
  HWND v24; // eax
  struct _IMAGELIST *v25; // edi
  HICON v26; // eax
  HICON v27; // eax
  HWND v28; // esi
  LONG v29; // eax
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ebx
  HWND v31; // esi
  HWND v32; // edi
  LONG v33; // eax
  HWND v34; // eax
  void *v35; // esi
  HWND v36; // eax
  HWND v37; // eax
  HWND v38; // eax
  HWND v39; // eax
  HWND v40; // esi
  const WCHAR *v41; // esi
  const WCHAR *v42; // eax
  unsigned __int8 v43; // cl
  void (__stdcall *GetTokenInformatio)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD); // ebx
  DWORD (__stdcall *GetLastError)(); // esi
  unsigned int v46; // eax
  TOKEN_INFORMATION_CLASS TokenClassInfo; // edi
  DWORD v48; // esi
  int *v49; // ebx
  bool v50; // zf
  int *v51; // esi
  void *v52; // edi
  tagTREEVIEWLISTITEMPARAM *v53; // ebx
  DWORD v54; // eax
  void *v55; // eax
  void *v56; // ST20_4
  DWORD v57; // eax
  DWORD v58; // esi
  PSID *v59; // edi
  tagTREEVIEWLISTITEMPARAM *v60; // eax
  tagTREEVIEWLISTITEMPARAM *v61; // ebx
  DWORD v62; // eax
  void *v63; // eax
  PSID v64; // ST24_4
  void *v65; // ST20_4
  DWORD v66; // eax
  HWND v67; // esi
  int v68; // eax
  wchar_t *v69; // eax
  DWORD v70; // esi
  DWORD v71; // esi
  void **v72; // edi
  void **v73; // ecx
  void *v74; // esi
  tagTREEVIEWLISTITEMPARAM *v75; // edi
  DWORD v76; // eax
  void *v77; // eax
  void *v78; // ST20_4
  DWORD v79; // eax
  HWND v80; // esi
  int v81; // eax
  wchar_t *v82; // eax
  unsigned int v83; // ecx
  char *v84; // eax
  int v85; // edi
  DWORD v86; // esi
  TOKEN_PRIVILEGES *v87; // eax
  struct _LUID *v88; // esi
  HWND v89; // esi
  HWND v90; // eax
  HWND v91; // edi
  HWND v93; // eax
  TOKEN_PRIVILEGES *v94; // ebx
  LONG v95; // eax
  HWND v96; // ST18_4
  HWND v97; // ST18_4
  WPARAM v98; // [esp-8h] [ebp-1C10h]
  WCHAR *v99; // [esp-4h] [ebp-1C0Ch]
  LVITEMW Item; // [esp+10h] [ebp-1BF8h]
  UINT v101; // [esp+44h] [ebp-1BC4h]
  int v102; // [esp+48h] [ebp-1BC0h]
  UINT pnIDs; // [esp+4Ch] [ebp-1BBCh]
  int v104; // [esp+50h] [ebp-1BB8h]
  WPARAM wParama; // [esp+54h] [ebp-1BB4h]
  WPARAM v106; // [esp+58h] [ebp-1BB0h]
  DWORD ReturnLength; // [esp+5Ch] [ebp-1BACh]
  DWORD cchName; // [esp+60h] [ebp-1BA8h]
  enum _SID_NAME_USE peUse; // [esp+64h] [ebp-1BA4h]
  WORD v110[2]; // [esp+68h] [ebp-1BA0h]
  WORD pnWidths[2]; // [esp+6Ch] [ebp-1B9Ch]
  DWORD cchReferencedDomainName; // [esp+70h] [ebp-1B98h]
  HWND v113; // [esp+74h] [ebp-1B94h]
  LVITEMW lParama; // [esp+78h] [ebp-1B90h]
  unsigned int v115; // [esp+ACh] [ebp-1B5Ch]
  HANDLE InBuffer; // [esp+B0h] [ebp-1B58h]
  int v117; // [esp+B4h] [ebp-1B54h]
  LPVOID TokenInformation; // [esp+B8h] [ebp-1B50h]
  HWND v119; // [esp+BCh] [ebp-1B4Ch]
  DWORD BytesReturned; // [esp+C0h] [ebp-1B48h]
  DWORD cbSid; // [esp+C4h] [ebp-1B44h]
  DWORD TokenInformationLength; // [esp+C8h] [ebp-1B40h]
  HANDLE OutBuffer; // [esp+CCh] [ebp-1B3Ch]
  HWND hDlg; // [esp+D0h] [ebp-1B38h]
  TOKEN_PRIVILEGES *pTokenPrivileges; // [esp+D4h] [ebp-1B34h]
  tagHANDLELISTITEMPARAM pListParam[1034]; // [esp+D8h] [ebp-1B30h]
  TOKEN_STATISTICS TokenStatisticsInfo; // [esp+1198h] [ebp-A70h]
  WCHAR Name[260]; // [esp+11D0h] [ebp-A38h]
  WCHAR ReferencedDomainName[260]; // [esp+13D8h] [ebp-830h]
  WCHAR Dst[260]; // [esp+15E0h] [ebp-628h]
  WCHAR String[260]; // [esp+17E8h] [ebp-420h]
  WCHAR szBuffer[260]; // [esp+19F0h] [ebp-218h]
  int v133; // [esp+1C04h] [ebp-4h]

  hDlg = hWnd;
  pTokenPrivileges = lParam;
  OutBuffer = 0;
  v4 = GetWindowLongW(hWnd, -21);
  lParama.mask = 0;
  v117 = v4;
  memset(&lParama.iItem, 0, 0x30u);
  pnIDs = 1046;
  v104 = 1049;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  v101 = 1047;
  v102 = 1051;
  v110[0] = MulDiv(100, gLogPixelSize.x, 96);
  v110[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( msg <= WM_CTLCOLOREDIT )
  {
    if ( msg != WM_CTLCOLOREDIT )
    {
      switch ( msg )
      {
        case WM_ALTTABACTIVE|WM_DESTROY:
          CMainWnd::DrawList(pTokenPrivileges);
          return 0;
        case 0x2Cu:
          return CMainWnd::HandleMeasureItem(hWnd, msg, wParam, pTokenPrivileges);
        case WM_NOTIFY:
          v94 = pTokenPrivileges;
          v95 = pTokenPrivileges->Privileges[0].Luid.HighPart;
          if ( v95 == -108 )
            return PE_ShowProcessTree(wParam, pTokenPrivileges);
          if ( v95 == -101 || v95 == -2 )
          {
            v96 = pTokenPrivileges->PrivilegeCount;
            lParama.mask = 4;
            lParama.iItem = ::SendMessageW(v96, 0x100Cu, 0xFFFFFFFF, 2);
            v97 = v94->PrivilegeCount;
            lParama.iSubItem = 0;
            if ( ::SendMessageW(v97, LVM_GETITEMW, 0, &lParama) && lParama.lParam > 1 )
            {
              if ( v94->PrivilegeCount == GetDlgItem(hWnd, 1040) )
              {
                cbSid = 260;
                QueryAuthorityInfoFromSID(lParama.lParam->nRefCount, String, &cbSid);
                SetDlgItemTextW(hWnd, 1342, String);
              }
              else
              {
                GetDlgItem(hWnd, 1038);
              }
            }
          }
          return 0;
        case WM_INITDIALOG:
          v5 = operator new(0x40u);
          BytesReturned = v5;
          v133 = 0;
          if ( v5 )
            v6 = CResizer::CResizer(v5, hWnd);
          else
            v6 = 0;
          v133 = -1;
          v7 = GetDlgItem(hWnd, 1337);
          if ( v7 )
            CResizer::AddItem(v6, v7, 1)->m_rect1 = 0i64;
          v8 = GetDlgItem(hWnd, 1669);
          if ( v8 )
            CResizer::AddItem(v6, v8, 1)->m_rect1 = 0i64;
          v9 = GetDlgItem(hWnd, 1668);
          if ( v9 )
            CResizer::AddItem(v6, v9, 1)->m_rect1 = 0i64;
          v10 = GetDlgItem(hWnd, 1057);
          if ( v10 )
            CResizer::AddItem(v6, v10, 1)->m_rect1 = 0i64;
          v11 = GetDlgItem(hWnd, 1040);
          if ( v11 )
          {
            v12 = CResizer::AddItem(v6, v11, 1);
            *&v12->m_rect2.left = 0i64;
            *&v12->m_rect2.right = db_one;
          }
          v13 = GetDlgItem(hWnd, 1342);
          if ( v13 )
            CResizer::AddItem(v6, v13, 1)->m_rect2 = stru_10A6C70;
          v14 = GetDlgItem(hWnd, 1346);
          if ( v14 )
            CResizer::AddItem(v6, v14, 1)->m_rect2 = stru_10A6C70;
          v15 = GetDlgItem(hWnd, 1128);
          if ( v15 )
            CResizer::AddItem(v6, v15, 1)->m_rect2 = stru_10A6C70;
          v16 = GetDlgItem(hWnd, 1038);
          if ( v16 )
            CResizer::AddItem(v6, v16, 1)->m_rect2 = stru_10A6C70;
          v17 = GetDlgItem(hWnd, 1038);
          if ( v17 )
            CResizer::AddItem(v6, v17, 1)->m_rect2 = stru_10A6C70;
          PropSheet_UpdateTab(hWnd);
          v18 = LoadIconW(ghInstance, 0x70);
          v19 = GetDlgItem(hWnd, 1127);
          ::SendMessageW(v19, STM_SETIMAGE, 1u, v18);
          v20 = LoadIconW(ghInstance, 0x6F);
          v21 = GetDlgItem(hWnd, 1128);
          ::SendMessageW(v21, STM_SETIMAGE, 1u, v20);
          SetDlgItemTextW(hWnd, 1342, L"n/a");
          SetDlgItemTextW(hDlg, 1057, L"n/a");
          v22 = GetDlgItem(hDlg, 1040);
          v119 = v22;
          v23 = GetWindowLongW(v22, -16);
          SetWindowLongW(v22, -16, v23 & 0xFFFFFFFD | 1);
          ::SendMessageW(v22, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 16416);
          v24 = ::SendMessageW(v22, LVM_GETTOOLTIPS, 0, 0);
          CTreeList::InitToolTips(v24);
          gOldListWndProc = SetWindowLongW(v22, -4, Proxy_ListCtrlWndProc);
          ::SendMessageW(v22, 0x30u, ghConfigFont, 0);
          InitListHeader(v22, &pnIDs, pnWidths, 2);
          v25 = ImageList_Create(16, 16, 1u, 256, 256);
          v26 = LoadIconW(ghInstance, 0xCB);
          ImageList_ReplaceIcon(v25, -1, v26);
          v27 = LoadIconW(ghInstance, 0x71);
          ImageList_ReplaceIcon(v25, -1, v27);
          v28 = v119;
          v29 = GetWindowLongW(v119, -16);
          SetWindowLongW(v28, -16, v29 | LVS_SHAREIMAGELISTS);
          SendMessageW = ::SendMessageW;
          ::SendMessageW(v28, LVM_SETIMAGELIST, 1u, v25);
          CTreeList::InitHeaderColumn(v28, nItem, nItem, byte_10BD224);
          v31 = hDlg;
          v32 = GetDlgItem(hDlg, 1038);
          v113 = v32;
          v33 = GetWindowLongW(v32, -16);
          SetWindowLongW(v32, -16, v33 & 0xFFFFFFFD | 1);
          ::SendMessageW(v32, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 16416);
          v34 = ::SendMessageW(v32, LVM_GETTOOLTIPS, 0, 0);
          CTreeList::InitToolTips(v34);
          gOldListWndProc = SetWindowLongW(v32, -4, Proxy_ListCtrlWndProc);
          ::SendMessageW(v32, WM_SETFONT, ghConfigFont, 0);
          InitListHeader(v32, &v101, v110, 2);
          SetDlgItemTextW(v31, 19, pTokenPrivileges[5].Privileges[0].Luid.HighPart);
          cbSid = 0;
          cchReferencedDomainName = 0;
          LookupAccountNameW(
            0,
            pTokenPrivileges[5].Privileges[0].Luid.HighPart,
            0,
            &cbSid,
            ReferencedDomainName,
            &cchReferencedDomainName,
            &peUse);
          if ( cbSid )
          {
            v35 = malloc(cbSid);
            LookupAccountNameW(
              0,
              pTokenPrivileges[5].Privileges[0].Luid.HighPart,
              v35,
              &cbSid,
              ReferencedDomainName,
              &cchReferencedDomainName,
              &peUse);
            cbSid = 260;
            QueryAuthorityInfoFromSID(v35, String, &cbSid);
            free(v35);
            v31 = hDlg;
          }
          else
          {
            swprintf(String, L"n/a");
          }
          SetDlgItemTextW(v31, 20, String);
          if ( pTokenPrivileges[6].Privileges[0].Luid.LowPart == -1 )
            swprintf(String, L"n/a");
          else
            swprintf(String, L"%d", pTokenPrivileges[6].Privileges[0].Luid.LowPart);
          SetDlgItemTextW(v31, 1056, String);
          if ( gdwVersion >= 1 )
          {
            v41 = L"Yes";
            v42 = L"Yes";
            if ( !(pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x200) )
              v42 = L"No";
            SetDlgItemTextW(hDlg, 1337, v42);
            if ( pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400 && gdwVersion >= 3 )
            {
              v43 = BYTE1(pTokenPrivileges[40].Privileges[0].Luid.HighPart);
              Name[0] = 0;
              if ( (v43 & 0xF0u) < 0x70 )
                wcscat_s(Name, 0x104u, &aPsprotectedsig[64 * (v43 >> 4)]);
              if ( (BYTE1(pTokenPrivileges[40].Privileges[0].Luid.HighPart) & 7) == 1 )
                wcscat_s(Name, 0x104u, L"-Light");
              v99 = Name;
            }
            else
            {
              if ( !(pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400) )
                v41 = L"No";
              v99 = v41;
            }
            v40 = hDlg;
            SetDlgItemTextW(hDlg, 1668, v99);
          }
          else
          {
            v36 = GetDlgItem(v31, 1335);
            ShowWindow(v36, 0);
            v37 = GetDlgItem(hDlg, 1337);
            ShowWindow(v37, 0);
            v38 = GetDlgItem(hDlg, 1669);
            ShowWindow(v38, 0);
            v39 = GetDlgItem(hDlg, 1668);
            ShowWindow(v39, 0);
            v40 = hDlg;
          }
          InBuffer = PE_OpenProcess(0x400u, 0, pTokenPrivileges[4].Privileges[0].Luid.LowPart);
          if ( InBuffer )
          {
            if ( !DeviceIoControl(ghDriverHandle, 0x8335000C, &InBuffer, 4u, &OutBuffer, 4u, &BytesReturned, 0) )
              OpenProcessToken(InBuffer, 8u, &OutBuffer);
            if ( OutBuffer )
            {
              GetTokenInformatio = GetTokenInformation;
              TokenStatisticsInfo.AuthenticationId.HighPart = 0;
              TokenStatisticsInfo.AuthenticationId.LowPart = 0;
              ReturnLength = 56;
              GetTokenInformation(OutBuffer, TokenStatistics, &TokenStatisticsInfo, 0x38u, &ReturnLength);
              swprintf_s(
                String,
                0x104u,
                L"%x",
                TokenStatisticsInfo.AuthenticationId.LowPart,
                TokenStatisticsInfo.AuthenticationId.HighPart);
              SetDlgItemTextW(v40, 1057, String);
              GetLastError = ::GetLastError;
              v46 = 0;
              v117 = 0;
              do
              {
                TokenClassInfo = TokenRestrictedSids;
                if ( !v46 )
                  TokenClassInfo = TokenGroups;
                GetTokenInformatio(OutBuffer, TokenClassInfo, 0, 0, &TokenInformationLength);
                if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
                {
                  v48 = TokenInformationLength;
                  v49 = malloc(TokenInformationLength);
                  TokenInformation = v49;
                  if ( GetTokenInformation(OutBuffer, TokenClassInfo, v49, v48, &TokenInformationLength) )
                  {
                    v50 = *v49 == 0;
                    v115 = 0;
                    if ( !v50 )
                    {
                      v51 = v49 + 2;
                      do
                      {
                        v52 = *(v51 - 1);
                        v53 = malloc(0x34u);
                        memset(v53, 0, 0x34u);
                        v53->field_2C = *v51;
                        v54 = GetLengthSid(v52);
                        v55 = malloc(v54);
                        v53->nRefCount = v55;
                        v56 = v55;
                        v57 = GetLengthSid(v52);
                        CopySid(v57, v56, v52);
                        QueryAuthorityInfoFromSID(v52, String, &cbSid);
                        if ( *GetSidSubAuthority(v52, 0) != 5 || *GetSidSubAuthority(v52, 1u) )
                          swprintf(ReferencedDomainName, L"%s", String);
                        else
                          swprintf(ReferencedDomainName, L"Logon SID (%s)", String);
                        lParama.pszText = ReferencedDomainName;
                        lParama.mask = 5;
                        lParama.iItem = 0x7FFFFFFF;
                        lParama.iSubItem = 0;
                        lParama.state = 0;
                        lParama.stateMask = 0;
                        lParama.iImage = 0;
                        lParama.lParam = v53;
                        BytesReturned = ::SendMessageW(v119, LVM_INSERTITEMW, 0, &lParama);
                        if ( BytesReturned == -1 )
                          return 0;
                        szBuffer[0] = 0;
                        if ( *v51 & 0x10 )
                          wcscpy_s(szBuffer, 0x104u, L"Deny");
                        if ( *v51 & 0x20000000 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Domain-Local");
                        }
                        if ( *v51 & 1 && !(*v51 & 8) )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Mandatory");
                        }
                        if ( *v51 & 8 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Owner");
                        }
                        if ( *v51 & 0x20 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          if ( *v51 & 0x40 )
                            wcscat_s(szBuffer, 0x104u, L"Integrity");
                          else
                            wcscat_s(szBuffer, 0x104u, L"DesktopIntegrity");
                        }
                        if ( v117 == 1 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Restricted");
                        }
                        lParama.iItem = BytesReturned;
                        lParama.pszText = szBuffer;
                        lParama.mask = 1;
                        lParama.iSubItem = 1;
                        ::SendMessageW(v119, LVM_SETITEMW, 0, &lParama);
                        v53->dwStyle = _wcsdup(ReferencedDomainName);
                        v53->field_30 = _wcsdup(szBuffer);
                        v51 += 2;
                        v49 = TokenInformation;
                        ++v115;
                      }
                      while ( v115 < *TokenInformation );
                    }
                  }
                  free(v49);
                  GetTokenInformatio = GetTokenInformation;
                  GetLastError = ::GetLastError;
                }
                v46 = v117 + 1;
                v117 = v46;
              }
              while ( v46 < 2 );
              GetTokenInformatio(OutBuffer, MaxTokenInfoClass|TokenGroups, 0, 0, &TokenInformationLength);
              if ( GetLastError() == 122 )
              {
                v58 = TokenInformationLength;
                v59 = malloc(TokenInformationLength);
                if ( (GetTokenInformatio)(OutBuffer, MaxTokenInfoClass|TokenGroups, v59, v58, &TokenInformationLength)
                  && *v59 )
                {
                  v60 = malloc(0x34u);
                  v61 = v60;
                  BytesReturned = v60;
                  memset(v60, 0, 0x34u);
                  v62 = GetLengthSid(*v59);
                  v63 = malloc(v62);
                  v61->nRefCount = v63;
                  v64 = *v59;
                  v65 = v63;
                  v66 = GetLengthSid(*v59);
                  CopySid(v66, v65, v64);
                  QueryAuthorityInfoFromSID(*v59, String, &cbSid);
                  v67 = v119;
                  lParama.pszText = String;
                  lParama.lParam = v61;
                  SendMessageW = ::SendMessageW;
                  lParama.mask = 5;
                  lParama.iItem = 0x7FFFFFFF;
                  lParama.iSubItem = 0;
                  lParama.state = 0;
                  lParama.stateMask = 0;
                  lParama.iImage = 0;
                  v68 = ::SendMessageW(v119, LVM_INSERTITEMW, 0, &lParama);
                  if ( v68 == -1 )
                    return 0;
                  lParama.iItem = v68;
                  lParama.mask = 1;
                  lParama.iSubItem = 1;
                  lParama.pszText = L"AppContainer";
                  ::SendMessageW(v67, LVM_SETITEMW, 0, &lParama);
                  v69 = _wcsdup(String);
                  v70 = BytesReturned;
                  *(BytesReturned + 40) = v69;
                  *(v70 + 48) = _wcsdup(lParama.pszText);
                  free(v59);
                  GetLastError = ::GetLastError;
                }
                else
                {
                  SendMessageW = ::SendMessageW;
                  free(v59);
                  GetLastError = ::GetLastError;
                }
              }
              else
              {
                SendMessageW = ::SendMessageW;
              }
              GetTokenInformation(OutBuffer, TokenLogonSid|TokenGroups, TokenInformation, 0, &TokenInformationLength);
              if ( GetLastError() == 122 )
              {
                v71 = TokenInformationLength;
                v72 = malloc(TokenInformationLength);
                BytesReturned = v72;
                if ( GetTokenInformation(OutBuffer, TokenLogonSid|TokenGroups, v72, v71, &TokenInformationLength) )
                {
                  v50 = *v72 == 0;
                  TokenInformation = 0;
                  if ( !v50 )
                  {
                    v73 = v72 + 1;
                    v115 = (v72 + 1);
                    do
                    {
                      v74 = *v73;
                      v75 = malloc(0x34u);
                      memset(v75, 0, 0x34u);
                      v76 = GetLengthSid(v74);
                      v77 = malloc(v76);
                      v75->nRefCount = v77;
                      v78 = v77;
                      v79 = GetLengthSid(v74);
                      CopySid(v79, v78, v74);
                      QueryAuthorityInfoFromSID(v74, String, &cbSid);
                      v80 = v119;
                      lParama.pszText = String;
                      lParama.mask = 5;
                      lParama.iItem = 0x7FFFFFFF;
                      lParama.iSubItem = 0;
                      lParama.state = 0;
                      lParama.stateMask = 0;
                      lParama.iImage = 0;
                      lParama.lParam = v75;
                      v81 = SendMessageW(v119, LVM_INSERTITEMW, 0, &lParama);
                      if ( v81 == -1 )
                        return 0;
                      lParama.iItem = v81;
                      lParama.mask = 1;
                      lParama.iSubItem = 1;
                      lParama.pszText = L"Capability";
                      SendMessageW(v80, LVM_SETITEMW, 0, &lParama);
                      v75->dwStyle = _wcsdup(String);
                      v82 = _wcsdup(lParama.pszText);
                      v83 = v115;
                      v75->field_30 = v82;
                      v73 = (v83 + 8);
                      v72 = BytesReturned;
                      TokenInformation = TokenInformation + 1;
                      v115 = v73;
                    }
                    while ( TokenInformation < *BytesReturned );
                  }
                }
                free(v72);
              }
              v84 = malloc(0x2Cu);
              v85 = v84;
              *(v84 + 1) = pTokenPrivileges;
              *(v84 + 9) = v119;
              *v84 = 2;
              v84[40] = 0;
              InitializeCriticalSection((v84 + 12));
              *(v85 + 8) = _beginthreadex(0, 0, sub_1047440, v85, 0, 0);
              SetWindowLongW(hDlg, GWLP_USERDATA, v85);
              GetTokenInformation(OutBuffer, TokenPrivileges, 0, 0, &TokenInformationLength);
              v86 = TokenInformationLength;
              pTokenPrivileges = malloc(TokenInformationLength);
              v50 = GetTokenInformation(OutBuffer, TokenPrivileges, pTokenPrivileges, v86, &TokenInformationLength) == 0;
              v87 = pTokenPrivileges;
              if ( !v50 )
              {
                v50 = pTokenPrivileges->PrivilegeCount == 0;
                TokenInformation = 0;
                if ( !v50 )
                {
                  v88 = &pTokenPrivileges->Privileges[0].Attributes;
                  do
                  {
                    cchName = 260;
                    if ( LookupPrivilegeNameW(0, v88 - 1, Name, &cchName) )
                    {
                      lParama.mask = 5;
                      lParama.pszText = Name;
                      lParama.iItem = 0x7FFFFFFF;
                      lParama.iSubItem = 0;
                      lParama.state = 0;
                      lParama.stateMask = 0;
                      lParama.iImage = 0;
                      lParama.lParam = 1;
                      BytesReturned = SendMessageW(v113, 0x104Du, 0, &lParama);
                      if ( BytesReturned == -1 )
                        return 0;
                      Dst[0] = 0;
                      if ( v88->LowPart & 2 )
                        wcscpy_s(Dst, 0x104u, L"Enabled");
                      else
                        wcscpy_s(Dst, 0x104u, L"Disabled");
                      if ( v88->LowPart & 1 )
                      {
                        if ( Dst[0] )
                          wcscat_s(Dst, 0x104u, L", ");
                        wcscpy_s(Dst, 0x104u, L"Default Enabled");
                      }
                      lParama.iItem = BytesReturned;
                      lParama.pszText = Dst;
                      lParama.mask = 1;
                      lParama.iSubItem = 1;
                      SendMessageW(v113, 0x104Cu, 0, &lParama);
                    }
                    v88 = (v88 + 12);
                    TokenInformation = TokenInformation + 1;
                  }
                  while ( TokenInformation < pTokenPrivileges->PrivilegeCount );
                  v87 = pTokenPrivileges;
                }
              }
              free(v87);
              CloseHandle(OutBuffer);
              CloseHandle(InBuffer);
              v89 = v119;
            }
            else
            {
              v85 = v117;
              CloseHandle(InBuffer);
              v89 = v119;
            }
          }
          else
          {
            v89 = v119;
            if ( pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400 )
            {
              lParama.mask = 5;
              lParama.iItem = 0x7FFFFFFF;
              lParama.iSubItem = 0;
              lParama.state = 0;
              lParama.stateMask = 0;
              lParama.pszText = L"Error: Process is Protected";
              lParama.iImage = 0;
              lParama.lParam = 1;
              if ( ::SendMessageW(v119, 0x104Du, 0, &lParama) == -1 )
                return 0;
            }
            v85 = v117;
          }
          if ( !v85 )
          {
            v90 = GetDlgItem(hDlg, 1210);
            EnableWindow(v90, 0);
          }
          InvalidateRect(v89, 0, 0);
          v106 = nItem;
          wParama = 1040;
          SendMessageW(v89, 0x1030u, &wParama, PropProcThreadsSortCallback);
          v91 = v113;
          SendMessageW(v113, 0x101Eu, 0, 0xFFFF);
          SendMessageW(v91, 0x101Eu, 1u, 65534);
          SendMessageW(v89, 0x101Eu, 0, 0xFFFF);
          SendMessageW(v89, 0x101Eu, 1u, 65534);
          return 1;
        case WM_COMMAND:
          if ( wParam > 40001 )
          {
            if ( wParam - 40092 > 1 )
              return 0;
            v98 = wParam;
          }
          else
          {
            if ( wParam != 40001 )
            {
              if ( wParam == 1210 )
              {
                InBuffer = OpenProcess(0xE0000u, 0, *(*(v4 + 4) + 68));
                if ( InBuffer || (InBuffer = OpenProcess(0x20000u, 0, *(*(v4 + 4) + 68))) != 0 )
                {
                  memset(pListParam, 0, 0x10C0u);
                  wsprintfW(&pListParam[46], L"%s: %d", *(*(v4 + 4) + 60), *(*(v4 + 4) + 68));
                  pListParam[10].dwValue = 0;
                  wcscpy_s(&pListParam[14], 0x40u, L"Process");
                  pListParam[11].dwValue = InBuffer;
                  pListParam[9].dwValue = GetCurrentProcessId();
                  FillHandleListParam(hWnd, pListParam);
                  CloseHandle(InBuffer);
                }
                else
                {
                  ReportMsg(L"Error opening process", hWnd);
                }
              }
              return 0;
            }
            v98 = 40014;
          }
          v93 = GetParent(hWnd);
          PostMessageW(v93, WM_COMMAND, v98, 0);
          return 0;
        default:
          return 0;
      }
    }
    return PE_FillControl(hWnd, wParam);
  }
  if ( msg > 0x7F1 )
  {
    if ( msg == 2038 )
    {
      InvalidateRect(pTokenPrivileges, 0, 0);
    }
    else if ( msg == 2039 )
    {
      Item.pszText = pTokenPrivileges;
      Item.iSubItem = 0;
      ::SendMessageW(*(v4 + 36), LVM_SETITEMTEXTW, wParam, &Item);
    }
    return 0;
  }
  if ( msg == 2033 )
  {
    if ( v4 )
    {
      EnterCriticalSection((v4 + 12));
      *(v4 + 40) = 1;
      LeaveCriticalSection((v4 + 12));
      if ( !InterlockedDecrement(v4) )
      {
        DeleteCriticalSection((v4 + 12));
        free(v4);
      }
    }
    return 0;
  }
  if ( msg == 310 || msg == 312 )
    return PE_FillControl(hWnd, wParam);
  return 0;
}
// 10A2088: using guessed type wchar_t aErrorOpeningPr[22];
// 10A60B4: using guessed type wchar_t aYes[4];
// 10A60C4: using guessed type wchar_t aLogonSidS[15];
// 10A612C: using guessed type wchar_t aIntegrity[10];
// 10A617C: using guessed type wchar_t aCapability[11];
// 10A61B4: using guessed type wchar_t aErrorProcessIs[28];
// 10A6C70: using guessed type RECT stru_10A6C70;
// 10BD224: using guessed type char byte_10BD224;
// 10C4E54: using guessed type int gdwVersion;

//----- (01048E00) --------------------------------------------------------
int __stdcall PageProcServices(HWND hDlg, int a2, WPARAM wParam, int a4)
{
  HWND v4; // edi
  CResizer *v5; // eax
  HWND v6; // eax
  struct tagResizerItem *v7; // eax
  HWND v8; // eax
  HICON v9; // ST20_4
  HWND v10; // eax
  LONG v11; // eax
  HWND v12; // eax
  void *v13; // ecx
  wchar_t *v14; // eax
  wchar_t *v15; // esi
  int v16; // edx
  wchar_t v17; // cx
  HWND v18; // eax
  DWORD v19; // ebx
  LONG v20; // edx
  int v21; // esi
  int v22; // eax
  WCHAR *v23; // eax
  int result; // eax
  LONG v25; // edi
  int v26; // eax
  int v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // ST14_4
  SC_HANDLE v35; // esi
  size_t v36; // esi
  BYTE *v37; // edi
  DWORD v38; // ST1C_4
  HWND v39; // eax
  BOOL v40; // ST20_4
  HWND v41; // eax
  BOOL v42; // eax
  BOOL v43; // ST20_4
  HWND v44; // eax
  BOOL v45; // ST20_4
  HWND v46; // eax
  BOOL v47; // eax
  BOOL v48; // ST20_4
  HWND v49; // eax
  BOOL v50; // eax
  BOOL v51; // ST20_4
  HWND v52; // eax
  HWND v53; // eax
  HWND v54; // eax
  HWND v55; // eax
  HWND v56; // eax
  HWND v57; // eax
  HWND v58; // eax
  SC_HANDLE v59; // esi
  INT_PTR v60; // eax
  HWND v61; // eax
  WPARAM v62; // [esp-8h] [ebp-13ACh]
  LPARAM lParam; // [esp+10h] [ebp-1394h]
  int v64; // [esp+1Ch] [ebp-1388h]
  int v65; // [esp+20h] [ebp-1384h]
  LPARAM v66; // [esp+44h] [ebp-1360h]
  int v67; // [esp+4Ch] [ebp-1358h]
  int v68; // [esp+50h] [ebp-1354h]
  size_t pcbBytesNeeded; // [esp+54h] [ebp-1350h]
  LVITEMW Item; // [esp+58h] [ebp-134Ch]
  void *v71; // [esp+8Ch] [ebp-1318h]
  SC_HANDLE hSCObject; // [esp+90h] [ebp-1314h]
  LONG dwNewLong; // [esp+94h] [ebp-1310h]
  char v74; // [esp+9Bh] [ebp-1309h]
  LPARAM pListParam; // [esp+9Ch] [ebp-1308h]
  DWORD v76; // [esp+C0h] [ebp-12E4h]
  int v77; // [esp+C4h] [ebp-12E0h]
  SC_HANDLE v78; // [esp+C8h] [ebp-12DCh]
  wchar_t v79; // [esp+D4h] [ebp-12D0h]
  wchar_t Dst; // [esp+154h] [ebp-1250h]
  struct _SERVICE_STATUS ServiceStatus; // [esp+115Ch] [ebp-248h]
  UINT pnIDs; // [esp+1178h] [ebp-22Ch]
  int v83; // [esp+117Ch] [ebp-228h]
  int v84; // [esp+1180h] [ebp-224h]
  WCHAR ServiceName; // [esp+1184h] [ebp-220h]
  WORD pnWidths[2]; // [esp+138Ch] [ebp-18h]
  __int16 v87; // [esp+1390h] [ebp-14h]
  int v88; // [esp+13A0h] [ebp-4h]

  dwNewLong = a4;
  v4 = GetDlgItem(hDlg, 1036);
  GetWindowLongW(hDlg, -21);
  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v74 = 0;
  pnIDs = 1039;
  v83 = 1044;
  v84 = 1061;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  v87 = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hDlg, wParam);
    return 0;
  }
  if ( a2 == 273 )
  {
    v71 = wParam;
    if ( wParam <= 40001 )
    {
      if ( wParam != 40001 )
      {
        switch ( wParam )
        {
          case 0x4BAu:
          case 0x4BBu:
          case 0x4BCu:
          case 0x4BDu:
          case 0x4BFu:
            Item.iItem = SendMessageW(v4, 0x100Cu, 0xFFFFFFFF, 2);
            Item.pszText = &ServiceName;
            Item.iSubItem = 0;
            Item.cchTextMax = 260;
            Item.mask = 1;
            SendMessageW(v4, 0x104Bu, 0, &Item);
            Item.iSubItem = v71;
            v60 = DialogBoxParamW(ghInstance, L"SERVICECONTROL", hDlg, DlgServiceControl, &Item);
            if ( v60 == 1 )
            {
              MessageBoxW(
                hDlg,
                L"The service didn't respond to the control request in a timely manner",
                L"Process Explorer",
                0x10u);
            }
            else if ( v60 == 2 && wParam == 1210 )
            {
              SendMessageW(v4, 0x1008u, Item.iItem, 0);
            }
            v66 = v4;
            v67 = -101;
            SendMessageW(hDlg, 0x4Eu, 0, &v66);
            QueryServiceNames();
            SetFocus(v4);
            result = 0;
            break;
          case 0x51Au:
            Item.iItem = SendMessageW(v4, 0x100Cu, 0xFFFFFFFF, 2);
            Item.pszText = &ServiceName;
            Item.iSubItem = 0;
            Item.cchTextMax = 260;
            Item.mask = 1;
            SendMessageW(v4, 0x104Bu, 0, &Item);
            v59 = OpenServiceW(ghSCManagerHandle, &ServiceName, 0x60000u);
            if ( v59 )
            {
              memset(&pListParam, 0, 0x10C0u);
              wcscpy_s(&Dst, 0x400u, &ServiceName);
              v77 = 0;
              wcscpy_s(&v79, 0x40u, L"Service");
              v78 = v59;
              v76 = GetCurrentProcessId();
              FillHandleListParam(hDlg, &pListParam);
              CloseServiceHandle(v59);
            }
            else
            {
              ReportMsg(L"Error opening service", hDlg);
            }
            result = 0;
            break;
          default:
            return 0;
        }
        return result;
      }
      v62 = 40014;
LABEL_78:
      v61 = GetParent(hDlg);
      PostMessageW(v61, 0x111u, v62, 0);
      return 0;
    }
    if ( wParam == 40002 )
    {
      SetEvent(ghRefreshEventHandle);
      return 0;
    }
    if ( wParam - 40092 <= 1 )
    {
      v62 = wParam;
      goto LABEL_78;
    }
    return 0;
  }
  switch ( a2 )
  {
    case 43:
      CMainWnd::DrawList(dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hDlg, a2, wParam, dwNewLong);
    case 78:
      v25 = dwNewLong;
      v26 = *(dwNewLong + 8);
      if ( v26 != -101 && (v26 + 3) > 1 )
        return 0;
      SetDlgItemTextW(hDlg, 1059, &gszNullString);
      v27 = SendMessageW(*v25, 0x100Cu, 0xFFFFFFFF, 2);
      if ( v27 == -1 )
      {
        v28 = GetDlgItem(hDlg, 1306);
        EnableWindow(v28, 0);
        v29 = GetDlgItem(hDlg, 1213);
        EnableWindow(v29, 0);
        v30 = GetDlgItem(hDlg, 1210);
        EnableWindow(v30, 0);
        v31 = GetDlgItem(hDlg, 1211);
        EnableWindow(v31, 0);
        v32 = GetDlgItem(hDlg, 1212);
        EnableWindow(v32, 0);
        v33 = GetDlgItem(hDlg, 1215);
        EnableWindow(v33, 0);
        return 0;
      }
      Item.iItem = v27;
      Item.pszText = &ServiceName;
      v34 = *v25;
      Item.iSubItem = 0;
      Item.cchTextMax = 260;
      Item.mask = 1;
      if ( SendMessageW(v34, 0x104Bu, 0, &Item) != 1 )
        return 0;
      v35 = OpenServiceW(ghSCManagerHandle, &ServiceName, 5u);
      hSCObject = v35;
      if ( !v35 )
      {
        v53 = GetDlgItem(hDlg, 1306);
        EnableWindow(v53, 0);
        v54 = GetDlgItem(hDlg, 1213);
        EnableWindow(v54, 0);
        v55 = GetDlgItem(hDlg, 1215);
        EnableWindow(v55, 0);
        v56 = GetDlgItem(hDlg, 1210);
        EnableWindow(v56, 0);
        v57 = GetDlgItem(hDlg, 1211);
        EnableWindow(v57, 0);
        v58 = GetDlgItem(hDlg, 1212);
        EnableWindow(v58, 0);
        return 0;
      }
      if ( *QueryServiceConfig2W )
      {
        QueryServiceConfig2W(v35, 1u, 0, 0, &pcbBytesNeeded);
        if ( GetLastError() == 122 )
        {
          v36 = pcbBytesNeeded;
          v37 = malloc(pcbBytesNeeded);
          v38 = v36;
          v35 = hSCObject;
          QueryServiceConfig2W(hSCObject, 1u, v37, v38, &pcbBytesNeeded);
          SetDlgItemTextW(hDlg, 1059, *v37);
          free(v37);
          v25 = dwNewLong;
        }
      }
      QueryServiceStatus(v35, &ServiceStatus);
      v39 = GetDlgItem(hDlg, 1306);
      EnableWindow(v39, 1);
      v40 = ServiceStatus.dwCurrentState == 1;
      v41 = GetDlgItem(hDlg, 1213);
      EnableWindow(v41, v40);
      v42 = ServiceStatus.dwCurrentState == 4 && ServiceStatus.dwControlsAccepted & 2;
      v43 = v42;
      v44 = GetDlgItem(hDlg, 1212);
      EnableWindow(v44, v43);
      v45 = ServiceStatus.dwCurrentState == 7;
      v46 = GetDlgItem(hDlg, 1211);
      EnableWindow(v46, v45);
      v47 = (ServiceStatus.dwCurrentState == 4 || ServiceStatus.dwCurrentState == 7)
         && ServiceStatus.dwControlsAccepted & 1;
      v48 = v47;
      v49 = GetDlgItem(hDlg, 1210);
      EnableWindow(v49, v48);
      v50 = (ServiceStatus.dwCurrentState == 4 || ServiceStatus.dwCurrentState == 7)
         && ServiceStatus.dwControlsAccepted & 1;
      v51 = v50;
      v52 = GetDlgItem(hDlg, 1215);
      EnableWindow(v52, v51);
      CloseServiceHandle(hSCObject);
      if ( *(v25 + 8) == -3 )
      {
        SendMessageW(hDlg, 0x111u, 0x51Au, 0);
        return 0;
      }
      return 0;
    case 272:
      v5 = operator new(0x40u);
      v71 = v5;
      v88 = 0;
      if ( v5 )
        hSCObject = CResizer::CResizer(v5, hDlg);
      else
        hSCObject = 0;
      v88 = -1;
      v6 = GetDlgItem(hDlg, 1036);
      if ( v6 )
      {
        v7 = CResizer::AddItem(hSCObject, v6, 1);
        *&v7->m_rect2.left = 0i64;
        *&v7->m_rect2.right = db_one;
      }
      v8 = GetDlgItem(hDlg, 1210);
      if ( v8 )
        CResizer::AddItem(hSCObject, v8, 1)->m_rect1 = stru_10A6C70;
      PropSheet_UpdateTab(hDlg);
      v9 = LoadIconW(ghInstance, 0xEB);
      v10 = GetDlgItem(hDlg, 1129);
      SendMessageW(v10, 0x172u, 1u, v9);
      SetWindowLongW(hDlg, -21, dwNewLong);
      v11 = GetWindowLongW(v4, -16);
      SetWindowLongW(v4, -16, v11 & 0xFFFFFFFD | 1);
      SendMessageW(v4, 0x1036u, 0x4020u, 16416);
      v12 = SendMessageW(v4, 0x104Eu, 0, 0);
      CTreeList::InitToolTips(v12);
      gOldListWndProc = SetWindowLongW(v4, -4, Proxy_ListCtrlWndProc);
      SendMessageW(v4, 0x30u, ghConfigFont, 0);
      v13 = *(dwNewLong + 792);
      hSCObject = v13;
      if ( !v13 )
      {
        v13 = *(dwNewLong + 60);
        hSCObject = *(dwNewLong + 60);
      }
      v14 = _wcsdup(v13);
      v15 = v14;
      v16 = (v14 + 1);
      do
      {
        v17 = *v14;
        ++v14;
      }
      while ( v17 );
      _wcsupr_s(v15, ((v14 - v16) >> 1) + 1);
      if ( wcsstr(v15, L"SVCHOST.EXE") )
      {
        InitListHeader(v4, &pnIDs, pnWidths, 3);
        v74 = 1;
      }
      else
      {
        InitListHeader(v4, &pnIDs, pnWidths, 2);
      }
      free(v15);
      if ( !*CreateSecurityPage )
      {
        v18 = GetDlgItem(hDlg, 1306);
        ShowWindow(v18, 0);
      }
      QueryServiceNames();
      EnterCriticalSection(&gServiceLock);
      v19 = 0;
      if ( !gdwServiceReturned )
        goto LABEL_29;
      v20 = dwNewLong;
      v21 = 0;
      break;
    default:
      return 0;
  }
  do
  {
    if ( gpszServiceNames[v21 + 9] == *(v20 + 68) )
    {
      Item.mask = 5;
      Item.iItem = 0x7FFFFFFF;
      Item.iSubItem = 0;
      Item.stateMask = 0;
      Item.state = 0;
      Item.pszText = gpszServiceNames[v21];
      Item.lParam = (v19 + 1);
      Item.iImage = 0;
      v22 = SendMessageW(v4, LVM_INSERTITEMW, 0, &Item);
      v68 = v22;
      if ( v22 == -1 )
        return 0;
      Item.iItem = v22;
      Item.mask = 1;
      Item.iSubItem = 1;
      Item.pszText = gpszServiceNames[v21 + 1];
      SendMessageW(v4, 0x104Cu, 0, &Item);
      if ( v74 )
      {
        v23 = sub_1024780(hSCObject, gpszServiceNames[v21]);
        v71 = v23;
        if ( v23 )
        {
          Item.pszText = v23;
          Item.mask = 1;
          Item.iItem = v68;
          Item.iSubItem = 2;
          SendMessageW(v4, 0x104Cu, 0, &Item);
          free(v71);
        }
      }
      v20 = dwNewLong;
    }
    ++v19;
    v21 += 11;
  }
  while ( v19 < gdwServiceReturned );
LABEL_29:
  LeaveCriticalSection(&gServiceLock);
  SendMessageW(v4, 0x101Eu, 0, 0xFFFF);
  SendMessageW(v4, 0x101Eu, 1u, (v74 != 0) + 65534);
  if ( v74 )
    SendMessageW(v4, 0x101Eu, 2u, 65534);
  v65 = 3;
  v64 = 3;
  SendMessageW(v4, 0x102Bu, 0, &lParam);
  SetFocus(v4);
  return 1;
}
// 10A5620: using guessed type wchar_t aErrorOpeningSe[22];
// 10A6C70: using guessed type RECT stru_10A6C70;

//----- (01049A30) --------------------------------------------------------
int __userpurge PageProcTcpUdp@<eax>(signed int a1@<ebx>, HWND hWnd, int a3, WPARAM wParam, int a5)
{
  HWND v5; // esi
  int v6; // eax
  HWND v7; // eax
  HWND v8; // edi
  CResizer *v9; // eax
  HWND v10; // eax
  void *v11; // eax
  __m128i *v12; // eax
  LONG v13; // ecx
  WPARAM v14; // esi
  UINT v15; // eax
  BOOL v16; // ST44_4
  HWND v17; // eax
  UINT v19; // eax
  HWND v20; // eax
  u_long *v21; // esi
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
  _DWORD *v42; // edx
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
  int *v62; // edi
  int *v63; // eax
  SYSTEM_HANDLE_INFORMATION *v64; // edx
  int *v65; // ecx
  tagTREEVIEWLISTITEMPARAM *v66; // eax
  int *v67; // edi
  SYSTEM_HANDLE_INFORMATION *v68; // ecx
  int *v69; // edi
  int v70; // ecx
  tagTREEVIEWLISTITEMPARAM *v71; // eax
  size_t *v72; // edi
  SYSTEM_HANDLE_INFORMATION *v73; // ecx
  tagTREEVIEWLISTITEMPARAM *v74; // eax
  _SYSTEM_INFORMATION_CLASS SystemInfoClass_1; // ecx
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo_1; // edi
  ULONG v77; // esi
  _SYSTEM_INFORMATION_CLASS SystemInfoClass; // eax
  struct _MIB_TCPTABLE *v79; // eax
  struct _MIB_TCPTABLE *v80; // esi
  int v81; // eax
  struct _MIB_UDPTABLE *v82; // eax
  struct _MIB_UDPTABLE *v83; // edi
  int v84; // eax
  int v85; // eax
  int v86; // ecx
  char *v87; // ecx
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
  u_long *v104; // [esp+64h] [ebp-48h]
  void *v105; // [esp+68h] [ebp-44h]
  HWND v106; // [esp+6Ch] [ebp-40h]
  LONG dwNewLong; // [esp+70h] [ebp-3Ch]
  LPARAM dwInitParam; // [esp+74h] [ebp-38h]
  size_t ReturnLength; // [esp+78h] [ebp-34h]
  size_t v110; // [esp+7Ch] [ebp-30h]
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo; // [esp+80h] [ebp-2Ch]
  int pnIDs[4]; // [esp+87h] [ebp-25h]
  int v113; // [esp+98h] [ebp-14h]
  int v114; // [esp+A8h] [ebp-4h]

  v5 = hWnd;
  pSystemHandleInfo = hWnd;
  dwNewLong = a5;
  dwInitParam = GetWindowLongW(hWnd, -21);
  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v6 = dword_10DD0B0;
  pTcpTable = 0;
  *&v101[1] = 0;
  ppTcpTable = 0;
  lpMem = 0;
  v113 = 1343;
  _mm_storeu_si128((pnIDs + 1), _mm_load_si128(&xmmword_10A6C50));
  if ( !(v6 & 1) )
  {
    dword_10DD0B0 = v6 | 1;
    pnWidths = MulDiv(50, gLogPixelSize.x, 96);
    word_10DD0A6 = MulDiv(100, gLogPixelSize.x, 96);
    word_10DD0A8 = MulDiv(100, gLogPixelSize.x, 96);
    word_10DD0AA = MulDiv(100, gLogPixelSize.x, 96);
    word_10DD0AC = MulDiv(100, gLogPixelSize.x, 96);
  }
  v7 = GetDlgItem(hWnd, 1192);
  v8 = v7;
  v106 = v7;
  if ( a3 <= WM_TIMER )
  {
    if ( a3 != WM_TIMER )
    {
      switch ( a3 )
      {
        case WM_ALTTABACTIVE|WM_DESTROY:
          CMainWnd::DrawList(dwNewLong);
          return 0;
        case 0x2C:
          return CMainWnd::HandleMeasureItem(hWnd, a3, wParam, dwNewLong);
        case WM_NOTIFY:
          switch ( *(dwNewLong + 8) )
          {
            case LVN_GETDISPINFOW:
              return sub_101D7B0(wParam, dwNewLong);
            case LVN_COLUMNCLICK:
              return PE_ShowProcessTree(wParam, dwNewLong);
            case LVN_ITEMCHANGED:
            case LVN_GETDISPINFO|0x94:
              v16 = SendMessageW(*(dwInitParam + 4), LVM_GETNEXTITEM, 0xFFFFFFFF, 2) != -1;
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
          v9 = operator new(0x40u);
          v98 = v9;
          v114 = 0;
          if ( v9 )
            v110 = CResizer::CResizer(v9, hWnd);
          else
            v110 = 0;
          v114 = -1;
          v10 = GetDlgItem(hWnd, 1209);
          if ( v10 )
            CResizer::AddItem(v110, v10, 1)->m_rect1 = stru_10A6C70;
          PropSheet_UpdateTab(hWnd);
          SetWindowLongW(hWnd, GWLP_USERDATA, dwNewLong);
          if ( gdwVersion < 1 || (v11 = 5, !(*(dwNewLong + 40) & 0x20)) )
            v11 = 4;
          v105 = v11;
          ProcPageInitList(v8, v11, (pnIDs + 1), &pnWidths, 1);
          SetWindowLongW(v8, -4, Proxy_ListCtrlWndProc);
          SendMessageW(v8, 0x30u, ghConfigFont, 0);
          v12 = malloc(0x1Cu);
          v13 = dwNewLong;
          _mm_storeu_si128(v12, 0i64);
          _mm_storel_epi64(v12 + 1, 0i64);
          v12[1].m128i_i32[2] = 0;
          v12->m128i_i32[3] = 0;
          v12->m128i_i32[0] = v13;
          v12->m128i_i32[1] = v8;
          v12[1].m128i_i32[2] = -1;
          SetWindowLongW(hWnd, -21, v12);
          SendMessageW(hWnd, WM_TIMER, 0, 1);
          if ( SendMessageW(v8, LVM_GETITEMCOUNT, 0, 0) )
          {
            v14 = 0;
            if ( v105 )
            {
              do
              {
                if ( v14 == 3 )
                  SendMessageW(v8, LVM_SETCOLUMNWIDTH, 3u, word_10DD0AA);
                else
                  SendMessageW(v8, LVM_SETCOLUMNWIDTH, v14, 0xFFFF);
                ++v14;
              }
              while ( v14 < v105 );
            }
            v5 = pSystemHandleInfo;
          }
          CheckDlgButton(v5, 1194, byte_10C10D8 != 0);
          v15 = IsDlgButtonChecked(v5, 1194);
          SetPropW(v8, L"resolve", (v15 == 1));
          SetFocus(v8);
          ReleaseCapture();
          return 0;
        case WM_COMMAND:
          if ( wParam <= 40001 )
          {
            if ( wParam != 40001 )
            {
              if ( wParam == 1085 )
              {
                if ( AllocateAndGetTcpExTableFromStack )
                  DialogBoxParamW(ghMainInstance, L"THREADSTACK", hWnd, DlgThreadStack, dwInitParam);
                else
                  MessageBoxW(hWnd, L"Stacks not available on this version of Windows", L"Process Explorer", 0x30u);
              }
              else if ( wParam == 1194 && !(wParam >> 16) )
              {
                v19 = IsDlgButtonChecked(hWnd, 1194);
                SetPropW(v8, L"resolve", (v19 == 1));
                byte_10C10D8 = IsDlgButtonChecked(pSystemHandleInfo, 1194) == 1;
                goto LABEL_33;
              }
              return 0;
            }
            v94 = 40014;
LABEL_43:
            v20 = GetParent(hWnd);
            PostMessageW(v20, 0x111u, v94, 0);
            return 0;
          }
          if ( wParam != 40002 )
          {
            if ( wParam - 40092 > 1 )
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
    LOBYTE(pnIDs[0]) = 0;
    v104 = 0;
    if ( !dwNewLong )
    {
      Item.mask = 4;
      v22 = SendMessageW(v7, LVM_GETITEMCOUNT, 0, 0);
      Item.iSubItem = 0;
      Item.iItem = v22 - 1;
      if ( SendMessageW(v8, LVM_GETITEMW, 0, &Item) )
      {
        do
        {
          LOBYTE(Item.lParam->nRefCount) = 0;
          v23 = sub_10558D0(a1, v8, &Item, Item.lParam, v101);
          v24 = pnIDs[0];
          if ( v23 )
            v24 = 1;
          LOBYTE(pnIDs[0]) = v24;
          if ( v101[0] )
          {
            v21 = (v21 + 1);
            Item.lParam->field_8 = 0;
          }
          Item.mask = 4;
          Item.iSubItem = 0;
        }
        while ( SendMessageW(v8, LVM_GETITEMW, 0, &Item) );
        v104 = v21;
      }
    }
    if ( !AllocateAndGetTcpExTableFromStack )
    {
      if ( *GetExtendedTcpTable )
      {
        ReturnLength = 0;
        if ( GetExtendedTcpTable(0, &ReturnLength, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 )
        {
          v55 = 0;
          do
          {
            if ( v55 )
              free(v55);
            v55 = malloc(ReturnLength);
          }
          while ( GetExtendedTcpTable(v55, &ReturnLength, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 );
          v110 = v55;
          v33 = v55 == 0;
          v21 = v104;
          if ( !v33 )
          {
            v56 = v110;
            v57 = 0;
            pSystemHandleInfo = 0;
            if ( *v110 )
            {
              v58 = (v110 + 28);
              do
              {
                if ( *v58 == *(*dwInitParam + 68) )
                {
                  v59 = *(v58 - 2);
                  if ( v59 )
                    v60 = *(v58 - 1);
                  else
                    v60 = 0;
                  v61 = sub_103A070(
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
                          (v58 + 3),
                          0,
                          pnIDs);
                  v57 = pSystemHandleInfo;
                  if ( v61 )
                    LOBYTE(pnIDs[0]) = 1;
                  else
                    v21 = (v21 - 1);
                }
                v56 = v110;
                v57 = (v57 + 1);
                v58 += 40;
                pSystemHandleInfo = v57;
              }
              while ( v57 < *v110 );
            }
            free(v56);
          }
        }
        ReturnLength = 0;
        if ( GetExtendedUdpTable(0, &ReturnLength, 0, 2u, UDP_TABLE_OWNER_MODULE, 0) == 122 )
        {
          v62 = 0;
          do
          {
            if ( v62 )
              free(v62);
            v62 = malloc(ReturnLength);
          }
          while ( GetExtendedUdpTable(v62, &ReturnLength, 0, 2u, UDP_TABLE_OWNER_MODULE, 0) == 122 );
          v110 = v62;
          if ( v62 )
          {
            v63 = v62;
            v64 = 0;
            pSystemHandleInfo = 0;
            if ( *v62 )
            {
              v65 = v62 + 4;
              v105 = v62 + 4;
              do
              {
                if ( *v65 == *(*dwInitParam + 68) )
                {
                  v66 = sub_103A070(
                          v106,
                          dwNewLong,
                          1,
                          2,
                          *(v65 - 2),
                          0,
                          *(v65 - 1),
                          0xFFFFFFFF,
                          0,
                          -1,
                          *v65,
                          (v65 + 6),
                          0,
                          pnIDs);
                  if ( v66 )
                  {
                    if ( dwNewLong )
                      v66->field_10 = 0;
                    LOBYTE(pnIDs[0]) = 1;
                  }
                  else
                  {
                    v21 = (v21 - 1);
                  }
                  v64 = pSystemHandleInfo;
                  v65 = v105;
                }
                v63 = v110;
                v64 = (v64 + 1);
                v65 += 40;
                pSystemHandleInfo = v64;
                v105 = v65;
              }
              while ( v64 < *v110 );
            }
            free(v63);
          }
        }
        v67 = 0;
        ReturnLength = 0;
        if ( GetExtendedTcpTable(0, &ReturnLength, 0, 0x17u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 )
        {
          do
          {
            if ( v67 )
              free(v67);
            v67 = malloc(ReturnLength);
          }
          while ( GetExtendedTcpTable(v67, &ReturnLength, 0, 0x17u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 );
          v110 = v67;
          if ( v67 )
          {
            v68 = 0;
            pSystemHandleInfo = 0;
            if ( *v67 )
            {
              v69 = v67 + 15;
              do
              {
                if ( *v69 == *(*dwInitParam + 68) )
                {
                  if ( v69 == 28 )
                    v70 = 0;
                  else
                    v70 = *(v69 - 2);
                  v71 = sub_103A070(
                          v106,
                          dwNewLong,
                          2,
                          *(v69 - 1),
                          0,
                          (v69 - 13),
                          *(v69 - 8),
                          0,
                          (v69 - 7),
                          v70,
                          *v69,
                          (v69 + 3),
                          0,
                          pnIDs);
                  v68 = pSystemHandleInfo;
                  if ( v71 )
                    LOBYTE(pnIDs[0]) = 1;
                  else
                    v21 = (v21 - 1);
                }
                v68 = (v68 + 1);
                v69 += 48;
                pSystemHandleInfo = v68;
              }
              while ( v68 < *v110 );
              v67 = v110;
            }
            free(v67);
          }
        }
        v72 = 0;
        ReturnLength = 0;
        if ( GetExtendedUdpTable(0, &ReturnLength, 0, 0x17u, UDP_TABLE_OWNER_MODULE, 0) == 122 )
        {
          do
          {
            if ( v72 )
              free(v72);
            v72 = malloc(ReturnLength);
          }
          while ( GetExtendedUdpTable(v72, &ReturnLength, 0, 0x17u, UDP_TABLE_OWNER_MODULE, 0) == 122 );
          if ( v72 )
          {
            v33 = *v72 == 0;
            v110 = 0;
            if ( !v33 )
            {
              v73 = (v72 + 8);
              pSystemHandleInfo = (v72 + 8);
              do
              {
                if ( v73->NumberOfHandles == *(*dwInitParam + 68) )
                {
                  v74 = sub_103A070(
                          v106,
                          dwNewLong,
                          3,
                          2,
                          0,
                          &v73[-2].Handles[0].GrantedAccess,
                          v73[-1].Handles[0].GrantedAccess,
                          0xFFFFFFFF,
                          0,
                          -1,
                          v73->NumberOfHandles,
                          v73[1].Handles,
                          0,
                          pnIDs);
                  if ( v74 )
                  {
                    if ( dwNewLong )
                      v74->field_10 = 0;
                    LOBYTE(pnIDs[0]) = 1;
                  }
                  else
                  {
                    v21 = (v21 - 1);
                  }
                  v73 = pSystemHandleInfo;
                }
                v73 = (v73 + 176);
                pSystemHandleInfo = v73;
                ++v110;
              }
              while ( v110 < *v72 );
            }
            free(v72);
          }
        }
        v8 = v106;
      }
      else
      {
        ReturnLength = 64000;
        pSystemHandleInfo = malloc(64000u);
        SystemInfoClass_1 = SystemHandleInformation;
        if ( gbSupportExtendedSystemHandleInformation )
          SystemInfoClass_1 = SystemExtendedHandleInformation;
        if ( NtQuerySystemInformation(SystemInfoClass_1, pSystemHandleInfo, 0xFA00u, &ReturnLength) )
        {
          pSystemHandleInfo_1 = pSystemHandleInfo;
          do
          {
            free(pSystemHandleInfo_1);
            ReturnLength *= 2;
            v77 = ReturnLength;
            pSystemHandleInfo_1 = malloc(ReturnLength);
            SystemInfoClass = SystemHandleInformation;
            if ( gbSupportExtendedSystemHandleInformation )
              SystemInfoClass = SystemExtendedHandleInformation;
          }
          while ( NtQuerySystemInformation(SystemInfoClass, pSystemHandleInfo_1, v77, &ReturnLength) );
          v21 = v104;
          pSystemHandleInfo = pSystemHandleInfo_1;
          v8 = v106;
        }
        v110 = sub_10539C0(pSystemHandleInfo, *(*dwInitParam + 0x44));
        ReturnLength = 0;
        dwInitParam = 0;
        if ( GetTcpTable(0, &ReturnLength, 1) == 122 )
        {
          do
          {
            v79 = malloc(ReturnLength);
            v80 = v79;
            dwInitParam = v79;
            v81 = GetTcpTable(v79, &ReturnLength, 1);
            v103 = v81;
            if ( v81 )
            {
              free(v80);
              v81 = v103;
              dwInitParam = 0;
            }
          }
          while ( v81 == 122 );
          v21 = v104;
        }
        ReturnLength = 0;
        v105 = 0;
        if ( GetUdpTable(0, &ReturnLength, 1) == 122 )
        {
          do
          {
            v82 = malloc(ReturnLength);
            v83 = v82;
            v105 = v82;
            v84 = GetUdpTable(v82, &ReturnLength, 1);
            v103 = v84;
            if ( v84 )
            {
              free(v83);
              v84 = v103;
              v105 = 0;
            }
          }
          while ( v84 == 122 );
          v8 = v106;
        }
        if ( dwInitParam )
        {
          v33 = *dwInitParam == 0;
          v103 = 0;
          if ( !v33 )
          {
            v85 = dwInitParam + 16;
            v104 = (dwInitParam + 16);
            do
            {
              if ( sub_103F600(v110, 0, *(v85 - 8), *(v85 - 4)) )
              {
                if ( *v104 )
                  v86 = v104[1];
                else
                  v86 = 0;
                v8 = v106;
                if ( sub_103A070(
                       v106,
                       dwNewLong,
                       0,
                       *(v104 - 3),
                       *(v104 - 2),
                       0,
                       *(v104 - 1),
                       *v104,
                       0,
                       v86,
                       0,
                       0,
                       0,
                       pnIDs) )
                {
                  LOBYTE(pnIDs[0]) = 1;
                }
                else
                {
                  v21 = (v21 - 1);
                }
              }
              v85 = (v104 + 5);
              ++v103;
              v104 += 5;
            }
            while ( v103 < *dwInitParam );
          }
        }
        if ( v105 )
        {
          v33 = *v105 == 0;
          v103 = 0;
          if ( !v33 )
          {
            v87 = v105 + 4;
            v104 = (v105 + 4);
            do
            {
              v88 = *v87;
              v106 = *(v87 + 1);
              v98 = v88;
              if ( sub_103F600(v110, 1, v88, v106) )
              {
                if ( sub_103A070(v8, dwNewLong, 1, 2, v98, 0, v106, 0xFFFFFFFF, 0, -1, 0, 0, 0, pnIDs) )
                  LOBYTE(pnIDs[0]) = 1;
                else
                  v21 = (v21 - 1);
              }
              v87 = (v104 + 2);
              ++v103;
              v104 += 2;
            }
            while ( v103 < *v105 );
          }
        }
        free(pSystemHandleInfo);
        if ( v105 )
          free(v105);
        if ( dwInitParam )
          free(dwInitParam);
        if ( v110 )
          free(v110);
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
    *&v101[1] = 0;
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
      v31 = AllocateAndGetUdpExTableFromStack(&v101[1], 1, v30, 2u, 2u);
      v32 = *&v101[1];
      if ( v31 )
        v32 = 0;
      *&v101[1] = v32;
    }
    if ( pTcpTable )
    {
      v33 = *pTcpTable == 0;
      v110 = 0;
      if ( !v33 )
      {
        v34 = 0;
        pSystemHandleInfo = 0;
        do
        {
          v21 = v104;
          if ( *(pTcpTable + v34 + 24) == *(*dwInitParam + 68) )
          {
            if ( *(pTcpTable + v34 + 16) )
              v35 = *(pTcpTable + v34 + 20);
            else
              v35 = 0;
            v8 = v106;
            v36 = sub_103A070(
                    v106,
                    dwNewLong,
                    0,
                    *(pTcpTable + v34 + 4),
                    *(pTcpTable + v34 + 8),
                    0,
                    *(pTcpTable + v34 + 12),
                    *(pTcpTable + v34 + 16),
                    0,
                    v35,
                    *(pTcpTable + v34 + 24),
                    0,
                    0,
                    pnIDs);
            v34 = pSystemHandleInfo;
            if ( v36 )
            {
              LOBYTE(pnIDs[0]) = 1;
            }
            else
            {
              v21 = (v21 - 1);
              v104 = v21;
            }
          }
          v34 = (v34 + 24);
          ++v110;
          pSystemHandleInfo = v34;
        }
        while ( v110 < *pTcpTable );
      }
    }
    else if ( ppTcpTable )
    {
      v33 = *ppTcpTable == 0;
      v37 = ppTcpTable + 8;
      pSystemHandleInfo = 0;
      if ( !v33 )
      {
        do
        {
          if ( v37[6] == *(*dwInitParam + 68) )
          {
            v110 = *v37 - 28;
            v103 = malloc(v110);
            memmove_0(v103, v37 + 7, v110);
            v38 = v37[4];
            if ( v38 )
              v39 = v37[5];
            else
              v39 = 0;
            if ( sub_103A070(v106, dwNewLong, 0, v37[1], v37[2], 0, v37[3], v38, 0, v39, v37[6], v103, v110, pnIDs) )
              LOBYTE(pnIDs[0]) = 1;
            else
              v21 = (v21 - 1);
          }
          v37 = (v37 + *v37);
          pSystemHandleInfo = (pSystemHandleInfo + 1);
        }
        while ( pSystemHandleInfo < *ppTcpTable );
        v104 = v21;
      }
      v8 = v106;
    }
    if ( *&v101[1] )
    {
      v33 = **&v101[1] == 0;
      v110 = 0;
      if ( !v33 )
      {
        v40 = 0;
        pSystemHandleInfo = 0;
        do
        {
          v8 = v106;
          if ( *(&v40->Handles[0].Object + *&v101[1]) == *(*dwInitParam + 68) )
          {
            v41 = sub_103A070(
                    v106,
                    dwNewLong,
                    1,
                    2,
                    *(&v40->Handles[0].UniqueProcessId + *&v101[1]),
                    0,
                    *(&v40->Handles[0].ObjectTypeIndex + *&v101[1]),
                    0xFFFFFFFF,
                    0,
                    -1,
                    *(&v40->Handles[0].Object + *&v101[1]),
                    0,
                    0,
                    pnIDs);
            if ( v41 )
            {
              if ( dwNewLong )
                v41->field_10 = 0;
              LOBYTE(pnIDs[0]) = 1;
            }
            else
            {
              v21 = (v21 - 1);
            }
            v40 = pSystemHandleInfo;
          }
          v40 = (v40 + 12);
          ++v110;
          pSystemHandleInfo = v40;
        }
        while ( v110 < **&v101[1] );
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
        if ( LOBYTE(pnIDs[0]) || v21 )
        {
          InvalidateRect(v8, 0, 0);
          CTreeList::InitHeaderColumn(v8, dword_10C9B98, dword_10C9B98, byte_10BD225);
          v97 = dword_10C9B98;
          v96 = 1192;
          SendMessageW(v8, 0x1030u, &v96, PropProcThreadsSortCallback);
          SendMessageW(v8, 0xBu, 1u, 0);
        }
        return 0;
      }
      v33 = *lpMem == 0;
      v42 = lpMem + 8;
      v105 = lpMem + 8;
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
        if ( v42[3] == *(*dwInitParam + 68) )
        {
          v43 = *v42 - 16;
          v44 = malloc(v43);
          memmove_0(v44, v105 + 16, v43);
          v45 = v43;
          v8 = v106;
          v46 = sub_103A070(
                  v106,
                  dwNewLong,
                  1,
                  2,
                  *(v105 + 1),
                  0,
                  *(v105 + 2),
                  0xFFFFFFFF,
                  0,
                  -1,
                  *(v105 + 3),
                  v44,
                  v45,
                  pnIDs);
          if ( v46 )
          {
            if ( dwNewLong )
              v46->field_10 = 0;
            v21 = v104;
            LOBYTE(pnIDs[0]) = 1;
          }
          else
          {
            v21 = (v104 - 1);
            v104 = (v104 - 1);
          }
          v42 = v105;
        }
        v42 = (v42 + *v42);
        v105 = v42;
        ++v110;
      }
      while ( v110 < *lpMem );
    }
    if ( *&v101[1] )
    {
      v47 = *&v101[1];
      v48 = GetProcessHeap();
      HeapFree(v48, 0, v47);
    }
    goto LABEL_116;
  }
  if ( a3 > 0x138 )
  {
    if ( a3 == 1024 )
    {
LABEL_33:
      InvalidateRect(v8, 0, 0);
    }
    else if ( a3 == 2033 )
    {
      v89 = dwInitParam;
      if ( gdwVersion < 1 || (v90 = *dwInitParam, v110 = 5, !(*(v90 + 40) & 0x20)) )
        v110 = 4;
      if ( *(dwInitParam + 12) )
      {
        CloseHandle(*(dwInitParam + 12));
        v89 = dwInitParam;
      }
      if ( *(v89 + 16) )
      {
        RtlDestroyQueryDebugBuffer(*(v89 + 16));
        v89 = dwInitParam;
      }
      if ( *(v89 + 8) )
      {
        free(*(v89 + 8));
        v89 = dwInitParam;
      }
      free(v89);
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
        v5 = pSystemHandleInfo;
      }
      DestroyWindow(v5);
    }
    return 0;
  }
  if ( a3 != 312 && a3 != 307 && a3 != 310 )
    return 0;
  return PE_FillControl(hWnd, wParam);
}
// 10A6C50: using guessed type __int128 xmmword_10A6C50;
// 10A6C70: using guessed type RECT stru_10A6C70;
// 10BD225: using guessed type char byte_10BD225;
// 10C10D8: using guessed type char byte_10C10D8;
// 10C4E54: using guessed type int gdwVersion;
// 10CABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// 10CF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 10DD0A6: using guessed type __int16 word_10DD0A6;
// 10DD0A8: using guessed type __int16 word_10DD0A8;
// 10DD0AA: using guessed type __int16 word_10DD0AA;
// 10DD0AC: using guessed type __int16 word_10DD0AC;
// 10DD0B0: using guessed type int dword_10DD0B0;

//----- (0104ACF0) --------------------------------------------------------
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
  lParamIn = lParam;
  pUserData = GetWindowLongW(hWnd, GWLP_USERDATA);
  pSystemProcessInfo = 0;
  pThreadItem_1 = pUserData;
  lParama.mask = 0;
  memset(&lParama.iItem, 0, 0x30u);
  _mm_storeu_si128(&v170, _mm_load_si128(dword_10A6C60));
  v171 = 0x435;
  v6 = gLogPixelSize.x;
  _mm_storeu_si128(&v169, _mm_load_si128(&xmmword_10A6C40));
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
      case WM_ALTTABACTIVE|WM_DESTROY:
        CMainWnd::DrawList(lParamIn);
        return 0;
      case 0x2C:
        return CMainWnd::HandleMeasureItem(hWnd, uMsg, wParam, lParamIn);
      case WM_NOTIFY:                           // WM_NOTIFY
        pNMHDR = lParamIn;
        switch ( *(lParamIn + 2) )
        {
          case LVN_GETDISPINFOW:
            result = sub_101D7B0(wParam, lParamIn);
            break;
          case LVN_COLUMNCLICK:
            result = PE_ShowProcessTree(IDC_PAGE_PROCTHREADS_LISTCTRL, lParamIn);
            break;
          case LVN_DELETEITEM:
            result = sub_101D4B0(IDC_PAGE_PROCTHREADS_LISTCTRL, lParamIn);
            break;
          case LVN_ITEMCHANGED:
          case LVN_BEGINRDRAG|0x60:
            GetWindowLongW(pUserData->m_hWndList, GWL_STYLE);
            v83 = pNMHDR->code;
            if ( v83 != LVN_ITEMCHANGED && (v83 != -15 || pNMHDR[1].hwndFrom != 116) )
              return 0;
            v84 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
            lParama.iItem = SendMessageW(v84, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            lParama.iSubItem = 0;
            lParama.mask = 4;
            v85 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_LISTCTRL);
            SendMessageW(v85, LVM_GETITEMW, 0, &lParama);
            if ( lParama.iItem == -1 )
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
              v98 = pUserData->m_hProcess && *(pUserData->m_Param + 0x44);
              v99 = v98;
              v100 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
              EnableWindow(v100, v99);
              v101 = pUserData->m_hProcess && *(pUserData->m_Param + 0x44);
              v102 = v101;
              v103 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_SUSPEND);
              EnableWindow(v103, v102);
              hWndEdit = lParama.lParam;
              pThreadItem_1 = 0;
              pSystemProcessInfo = 0;
              GetSystemProcessInfo(&pSystemProcessInfo, &pThreadItem_1);
              pSystemProcessInfo_1 = pSystemProcessInfo;
              v105 = *(pUserData->m_Param + 0x44);
              if ( pSystemProcessInfo->UniqueProcessId != v105 )
              {
                do
                {
                  if ( !pSystemProcessInfo_1->NextEntryOffset )
                    break;
                  pSystemProcessInfo_1 = (pSystemProcessInfo_1 + pSystemProcessInfo_1->NextEntryOffset);
                }
                while ( pSystemProcessInfo_1->UniqueProcessId != v105 );
              }
              v106 = &pSystemProcessInfo_1[1];
              if ( pUserData->m_bValue2 )
                v106 = &pSystemProcessInfo_1->ReadOperationCount;
              v107 = 0;
              lParamIn = v106;
              v108 = pSystemProcessInfo_1->NumberOfThreads == 0;
              if ( pSystemProcessInfo_1->NumberOfThreads > 0 )
              {
                v109 = hWndEdit;
                do
                {
                  if ( !*(v106 + 9) )
                    *(v106 + 9) = v107;
                  if ( *(v109 + 11) == *(v106 + 9) )
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
                    v115 = PE_GetNumberFormat(szBuffer2, 0x400u);
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
                    PE_GetNumberFormat(szBuffer2, 0x400u);
                  }
                  else
                  {
                    wsprintfW(szBuffer2, L"n/a");
                  }
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_CYCLES_VALUE, szBuffer2);
                  if ( ThreadInformation == -1 )
                    wsprintfW(szBuffer2, L"n/a");
                  else
                    sub_1057790(ThreadInformation, szBuffer2, 0x400u);
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE, szBuffer2);
                  if ( *ArgList == -1 )
                    wsprintfW(szBuffer2, L"n/a");
                  else
                    wsprintfW(szBuffer2, L"%d", *ArgList);
                  SetDlgItemTextW(hWnd_2, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE, szBuffer2);
                  if ( GetThreadIdealProcessorEx )
                  {
                    v134 = *(v116 + 610);
                    if ( sdwSystemLogicalProcessorInfoCount <= 1 )
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
      case WM_KEYDOWN:                          // WM_KEYDOWN
        if ( wParam != 116 )
          return 0;
        SetEvent(pUserData->m_hEvent3);
        return 0;
      case WM_INITDIALOG:                       // WM_INITDIALOG
        if ( GetLogicalProcessorInformationEx )
        {
          GetLogicalProcessorInformationEx(RelationGroup, 0, &SystemInformationLength);
          sdwSystemLogicalProcessorInfoCount = SystemInformationLength
                                             / sizeof(_SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX);
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
          CResizer::AddItem(pResizer, v13, 1)->m_rect2 = stru_10A6C70;
        }
        v14 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY_VALUE);
        hWndEdit = v14;
        if ( v14 )
        {
          v15 = CResizer::AddItem(pResizer, v14, 1);
          v16 = hWndEdit;
          v15->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v16, 1)->m_rect2 = stru_10A6C70;
        }
        v17 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_BASE_PRIORITY);
        hWndEdit = v17;
        if ( v17 )
        {
          v18 = CResizer::AddItem(pResizer, v17, 1);
          v19 = hWndEdit;
          v18->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v19, 1)->m_rect2 = stru_10A6C70;
        }
        v20 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_DYNAMIC_PRIORITY);
        hWndEdit = v20;
        if ( v20 )
        {
          v21 = CResizer::AddItem(pResizer, v20, 1);
          v22 = hWndEdit;
          v21->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v22, 1)->m_rect2 = stru_10A6C70;
        }
        v23 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_MEMROY_PRIORITY_VALUE);
        hWndEdit = v23;
        if ( v23 )
        {
          v24 = CResizer::AddItem(pResizer, v23, 1);
          v25 = hWndEdit;
          v24->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v25, 1)->m_rect2 = stru_10A6C70;
        }
        v26 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE);
        hWndEdit = v26;
        if ( v26 )
        {
          v27 = CResizer::AddItem(pResizer, v26, 1);
          v28 = hWndEdit;
          v27->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v28, 1)->m_rect2 = stru_10A6C70;
        }
        v29 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
        hWndEdit = v29;
        if ( v29 )
        {
          v30 = CResizer::AddItem(pResizer, v29, 1);
          v31 = hWndEdit;
          v30->m_rect1 = stru_10A6C70;
          CResizer::AddItem(pResizer, v31, 1)->m_rect2 = stru_10A6C70;
        }
        v32 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_PERMISSIONS);
        if ( v32 )
          CResizer::AddItem(pResizer, v32, 1)->m_rect1 = stru_10A6C70;
        v33 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_KILL);
        if ( v33 )
          CResizer::AddItem(pResizer, v33, 1)->m_rect1 = stru_10A6C70;
        v34 = ::GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_STATIC_IDLE_PROCESSOR_VALUE);
        hWndEdit = v34;
        if ( v34 )
        {
          v35 = CResizer::AddItem(pResizer, v34, 1);
          v36 = hWndEdit;
          v35->m_rect1 = 0i64;
          CResizer::AddItem(pResizer, v36, 1)->m_rect2 = stru_10A6C70;
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
    ProcPageInitList(pThreadItem->m_hWndList, hWndEdit, v59, pnWidths, 1);
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
    v69 = LoadIconW(ghInstance, IDC_DOWNARROW);
    ImageList_ReplaceIcon(v68, -1, v69);
    v70 = LoadIconW(ghInstance, IDC_UPARROW);
    ImageList_ReplaceIcon(v68, -1, v70);
    pThreadItem_2 = pThreadItem_1;
    v72 = GetWindowLongW(pThreadItem_1->m_hWndList, GWL_STYLE);
    SetWindowLongW(pThreadItem_2->m_hWndList, -16, v72 | 0x48);
    SendMessageW(pThreadItem_2->m_hWndList, 0x1003u, 1u, v68);
    CTreeList::InitHeaderColumn(pThreadItem_2->m_hWndList, ::wParam, ::wParam, byte_10C53B4);
    pThreadItem_2->m_bValue1 = 0;
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
            lParama.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( lParama.iItem == -1 )
              return 0;
            lParama.iSubItem = 0;
            lParama.mask = 4;
            if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParama) )
              return 0;
            v127 = lParama.lParam;
            v128 = Fake_OpenThread(lParama.lParam->field_2C, 0x4Au);
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
            lParama.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            if ( lParama.iItem == -1 )
              return 0;
            lParama.iSubItem = 0;
            lParama.mask = 4;
            if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParama) )
              return 0;
            pThreadItem_1 = lParama.lParam;
            ThreadHandle_1 = Fake_OpenThread(lParama.lParam->field_2C, 0x20000u);
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
    lParama.iItem = SendMessageW(pUserData->m_hWndList, 0x100Cu, 0xFFFFFFFF, 2);
    if ( lParama.iItem != -1 )
    {
      lParama.iSubItem = 0;
      lParama.mask = 4;
      if ( SendMessageW(pUserData->m_hWndList, 0x104Bu, 0, &lParama) )
      {
        qmemcpy(v135, lParama.lParam, 0x290u);
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
  lParama.iItem = SendMessageW(pUserData->m_hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( lParama.iItem == -1 )
    return 0;
  lParama.iSubItem = 0;
  lParama.mask = 4;
  if ( !SendMessageW(pUserData->m_hWndList, LVM_GETITEMW, 0, &lParama) )
    return 0;
  v118 = lParama.lParam;
  pThreadItem_1 = lParama.lParam;
  if ( wParam == IDC_PAGE_PROCTHREADS_BUTTON_KILL )
  {
    wsprintfW(szBuffer2, L"Are you sure you want to kill thread %d?", lParama.lParam->field_2C);
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
// 109E398: using guessed type wchar_t aREsume[8];
// 10A5A74: using guessed type wchar_t aWaitS[8];
// 10A5AF4: using guessed type wchar_t aProperties[11];
// 10A5BE4: using guessed type wchar_t aUnableToTermin[27];
// 10A5C1C: using guessed type wchar_t aUnableToResume[24];
// 10A5C4C: using guessed type wchar_t aUnableToSuspen_0[25];
// 10A6C40: using guessed type __int128 xmmword_10A6C40;
// 10A6C60: using guessed type int dword_10A6C60[4];
// 10A6C70: using guessed type RECT stru_10A6C70;
// 10BE8B8: using guessed type wchar_t aExecutive[10];
// 10C10DC: using guessed type int sdwSystemLogicalProcessorInfoCount;
// 10C4E54: using guessed type int gdwVersion;
// 10C53B4: using guessed type char byte_10C53B4;
// 10CF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);

//----- (0104C7F0) --------------------------------------------------------
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
  bFalse = INFINITE;
  dwNumberOfProcessors = 0;
  hHandle = 0;
  hEvent2[0] = pThreadItem_1->m_hEvent2;
  hEvent2[1] = pThreadItem_1->m_hEvent3;
  fOK = 1;
  dwRet = WaitForMultipleObjects(2u, hEvent2, 0, INFINITE);
  SendMessageW = ::SendMessageW;
  if ( pThreadItem_2->m_bValue1 )
    goto __cleanup;
  LOBYTE(v4) = a5;
  v81 = v78;
  *(&a5 + 1) = v4;
  v82 = wParam;
  while ( 1 )
  {
    nItem = 0;
    nIndex = 0;
    *dwHighDateTime = 0;
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
      if ( SendMessageW(hWndList, LVM_GETITEMW, 0, &item) )
      {
        nIndex_1 = nIndex;
        do
        {
          v8 = sub_10558D0(SendMessageW, hWndList, &item, item.lParam, &a5);
          v9 = BYTE1(a5);
          if ( v8 )
            v9 = 1;
          *(&a5 + 1) = v9;
          if ( a5 )
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
    v80 = timeDelta * gSystemInfo.dwNumberOfProcessors >> 32;
    v85 = timeDelta * gSystemInfo.dwNumberOfProcessors;
    if ( !(timeDelta * gSystemInfo.dwNumberOfProcessors) )
    {
      v85 = 1;
      v80 = 0;
    }
    v15 = *dwHighDateTime;
    pThreadItem_2->m_TimeLast.dwLowDateTime = dwLowDateTime;
    pThreadItem_2->m_TimeLast.dwHighDateTime = v15;
    if ( GetProcessorSystemCycleTime )
    {
      v16 = 8 * gSystemInfo.dwNumberOfProcessors;
      pSystemProcessorCycleTimeInfor = malloc(8 * gSystemInfo.dwNumberOfProcessors);
      NtQuerySystemInformation(SystemProcessorCycleTimeInformation, pSystemProcessorCycleTimeInfor, v16, &ReturnLength);
      LODWORD(v18) = sub_103E4B0(0, pSystemProcessInfo, pSystemProcessorCycleTimeInfor, 0);
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
      v20 = (pSystemProcessInfo_1 + 0x88);
    v21 = 0;
    *dwHighDateTime = pSystemProcessInfo_1->NumberOfThreads;
    v84 = 0;
    if ( *dwHighDateTime )
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
          ClientID.UniqueThread = v20->CreateTime.HighPart;
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
          LocalBuffer.ThreadHandle = ThreadHandle_1;
          if ( QueryThreadCycleTime && ThreadHandle_1 )
            QueryThreadCycleTime(ThreadHandle_1, &LocalBuffer.field_268);
          v45 = pThreadItem_1;
          LocalBuffer.field_2C = v20->CreateTime.HighPart;
          LocalBuffer.field_250 = v20->KernelTime.LowPart;
          bFalse = pThreadItem_1->m_SystemModules;
          LocalBuffer.field_254 = 0;
          dwNumberOfProcessors = pThreadItem_1->m_DebugBuffer;
          LocalBuffer.field_30 = v20->SpareLi3.HighPart;
          sub_103DD60(
            0,
            0,
            &LocalBuffer,
            pThreadItem_1->m_hProcess,
            v20->SpareLi3.HighPart,
            v20->SpareLi3.HighPart >> 31,
            dwNumberOfProcessors,
            &bFalse->NumberOfModules);
          *&LocalBuffer.field_270 = *&v20->NextEntryOffset + v20->SpareLi1.QuadPart;
          v46 = 2;
          if ( fOK )
            v46 = 0;
          LocalBuffer.field_14 = 0;
          LocalBuffer.field_10 = v46;
          LocalBuffer.field_278 = v45->m_Param;
          *&LocalBuffer.field_240 = 0i64;
          LocalBuffer.field_288 = 0;
          if ( GetThreadIdealProcessorEx )
            GetThreadIdealProcessorEx(LocalBuffer.ThreadHandle, &LocalBuffer.m_ProcessorNumber);
          if ( *(v45->m_Param + 40) & 0x20 && gdwVersion >= 1 )
          {
            if ( !NtQueryInformationThread(
                    LocalBuffer.ThreadHandle,
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
                ThreadInformation.TebBaseAddrss + gdwTebAddressOffset,
                &dwTebAddress,
                4u,
                &NumberOfBytesRead);
              LocalBuffer.m_dwTebAddress = dwTebAddress;
              if ( dwTebAddress )
              {
                if ( sub_105EFB0(dwTebAddress) )
                {
                  v48 = sub_105EFB0(dwTebAddress);
                  LocalBuffer.field_288 = _wcsdup(v48);
                }
              }
            }
          }
          else
          {
            LocalBuffer.m_dwTebAddress = -1;
          }
          bFalse = v45;
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
        v20 = (v20 + 64);
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
        ::SendMessageW(hWndList, LVM_GETITEMW, 0, &item);
        v23 = item.lParam;
        if ( item.lParam->field_2C == v20->CreateTime.HighPart )
          break;
        if ( ++v22 >= ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) )
          goto LABEL_61;
      }
      v24 = v20->KernelTime.LowPart - item.lParam->field_250;
      if ( v24 != *&item.lParam->gap234[20] || 0 != *&item.lParam->gap234[24] )
      {
        if ( v24 <= 0 )
          *&item.lParam->gap234[20] = 0;
        else
          *&item.lParam->gap234[20] = v24;
        *&v23->gap234[24] = 0;
        v23 = item.lParam;
        BYTE1(a5) = 1;
      }
      v23->field_250 = v20->KernelTime.LowPart;
      item.lParam->field_254 = 0;
      if ( QueryThreadCycleTime )
      {
        v25 = item.lParam->dwStyle;
        if ( v25 )
        {
          QueryThreadCycleTime(v25, v79);
          if ( ((*v79 - *&item.lParam->hMainWndBackup) >> 32) < 0
            || (*v79 < *&item.lParam->hMainWndBackup || (*v79 - *&item.lParam->hMainWndBackup) >> 32 == 0)
            && v79[0] == item.lParam->hMainWndBackup )
          {
            item.lParam->field_258 = 0;
            item.lParam->field_25C = 0;
          }
          else
          {
            *&item.lParam->field_258 = *v79 - *&item.lParam->hMainWndBackup;
          }
          BYTE1(a5) = 1;
        }
      }
      item.lParam->hMainWndBackup = v79[0];
      *&item.lParam->bMainWndIsHung = v79[1];
      v26 = item.lParam;
      v27 = v20->NextEntryOffset + v20->SpareLi1.LowPart;
      v28 = *&v20->NextEntryOffset + v20->SpareLi1.QuadPart;
      v73 = HIDWORD(v28);
      v29 = v27 < item.lParam->CreateTime.dwLowDateTime;
      v30 = v27 - item.lParam->CreateTime.dwLowDateTime;
      v70 = v28;
      v31 = HIDWORD(v28) - (v29 + item.lParam->CreateTime.dwHighDateTime);
      if ( GetProcessorSystemCycleTime && item.lParam->dwStyle )
      {
        v32 = *&item.lParam->field_258;
        v33 = v81;
        v34 = v82;
      }
      else
      {
        v32 = __PAIR__(v31, v30);
        v33 = v80;
        v34 = v85;
      }
      v74 = v32 * 100.0;
      v35 = __PAIR__(v33, v34);
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
        if ( v41 < gConfig.dwHighlightDuration )
        {
          item.lParam->field_10 = 2;
          v38->field_14 = v41;
LABEL_59:
          hWndList = hWndList_1;
          if ( v39 != *&item.lParam->gap234[12] )
          {
            *&item.lParam->gap234[12] = v39;
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
      if ( !v4 )
        goto LABEL_87;
    }
    InvalidateRect(hWndList, 0, 0);
    v78 = ::wParam;
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
      v65 = 3;
      v64 = 3;
      SendMessageW(hWndList, LVM_SETITEMSTATE, 0, &lParam);
      hHandle = _beginthreadex(0, 0, sub_104D400, pThreadItem_2, 0, 0);
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
// 104D400: using guessed type int __stdcall sub_104D400(int);
// 109CDC0: using guessed type double db_onehundred;
// 10C4E54: using guessed type int gdwVersion;
// 10CB1CC: using guessed type int gdwTebAddressOffset;
// 10CF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 10CF2F4: using guessed type int GetProcessorSystemCycleTime;

//----- (0104D400) --------------------------------------------------------
int __stdcall sub_104D400(int a1)
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
        sub_103DD60(1, 0, v15, *(v17 + 44), *(v6 + 48), *(v6 + 48) >> 31, *(v17 + 48), *(v17 + 40));
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
// 104D400: using guessed type int __stdcall sub_104D400(int);

//----- (0104D5B0) --------------------------------------------------------
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
      InitListHeader(v4, &pnIDs, pnWidths, 3);
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

//----- (0104DA70) --------------------------------------------------------
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
  if ( !*IsProcessInJob || !ProcessHandle )
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
    pEntry_1 = pEntry;
    nIndex = pEntry[1].CreatorBackTraceIndex;
    if ( _wcsicmp(&gpszObjectTypeNames[0x40 * nIndex], L"Job") )
      goto LABEL_13;
    v8 = PE_DuplicateProcessHandle(pEntry_1->UniqueProcessId, pEntry_1->HandleValue, 0x80000000);
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
  PE_QueryObject(&gpszObjectTypeNames[0x40 * nIndex], pEntry_1, szBuffer, 0x400u, 0);
  v9 = v13;
  if ( v13 )
    *v9 = _wcsdup(szBuffer);
  *v12 = v8;
  return 1;
}

//----- (0104DC00) --------------------------------------------------------
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

//----- (0104DC50) --------------------------------------------------------
BOOL __cdecl sub_104DC50(HWND hWnd_1, tagTREEVIEWLISTITEMPARAM *pItem)
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

//----- (0104DE20) --------------------------------------------------------
int __thiscall sub_104DE20(int *this, int a2)
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

//----- (0104DE60) --------------------------------------------------------
_DWORD *__cdecl sub_104DE60(DWORD dwProcessId)
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
