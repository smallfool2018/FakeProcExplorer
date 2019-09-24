

//----- (00BE1000) --------------------------------------------------------
signed int __stdcall Fake_ExpandEnvironmentStrings(WCHAR *pszPathName, DWORD dwLength, LPCWSTR lpszPathName)
{
  signed int result; // eax
  WCHAR *pszPathNameBuf; // eax
  signed int v5; // ebx
  DWORD v6; // esi
  char chText; // cl

  result = 0;
  if ( !dwLength || dwLength > 0x7FFFFFFF )
    result = E_INVALIDARG;
  if ( result >= 0 )
  {
    pszPathNameBuf = pszPathName;
    v5 = 0;
    v6 = dwLength;
    if ( !dwLength )
      goto LABEL_14;
    do
    {
      if ( !(0x7FFFFFFE - dwLength + v6) )
        break;
      chText = *((_BYTE *)pszPathNameBuf + (char *)lpszPathName - (char *)pszPathName);
      if ( !chText )
        break;
      *(_BYTE *)pszPathNameBuf = chText;
      pszPathNameBuf = (WCHAR *)((char *)pszPathNameBuf + 1);
      --v6;
    }
    while ( v6 );
    if ( !v6 )
    {
LABEL_14:
      pszPathNameBuf = (WCHAR *)((char *)pszPathNameBuf - 1);
      v5 = 0x8007007A;
    }
    *(_BYTE *)pszPathNameBuf = 0;
    result = v5;
  }
  return result;
}

//----- (00BE1063) --------------------------------------------------------
// 返回 hhctrl.ocx的路弿
BOOL __stdcall GetHtmlHelpXPathName(CHAR *pszPathName)
{
  BOOL v1; // esi
  DWORD cbRet; // [esp+4h] [ebp-118h]
  DWORD dwType; // [esp+8h] [ebp-114h]
  LPSTR pszFileName; // [esp+Ch] [ebp-110h]
  HKEY hSubKey; // [esp+10h] [ebp-10Ch]
  char szPathName[260]; // [esp+14h] [ebp-108h]

  pszFileName = pszPathName;
  v1 = 0;
  if ( RegOpenKeyExA(
         HKEY_CLASSES_ROOT,
         "CLSID\\{ADB880A6-D8FF-11CF-9377-00AA003B7A11}\\InprocServer32",
         0,
         KEY_READ,
         &hSubKey) )
  {
    return 0;
  }
  cbRet = 260;
  dwType = 1;
  if ( !RegQueryValueExA(hSubKey, 0, 0, &dwType, (LPBYTE)szPathName, &cbRet) )
  {
    szPathName[259] = 0;
    if ( dwType == REG_EXPAND_SZ )
      v1 = ExpandEnvironmentStringsA(szPathName, pszFileName, 260u) - 1 <= 259;
    else
      v1 = Fake_ExpandEnvironmentStrings((WCHAR *)pszFileName, 260u, (LPCWSTR)szPathName) >= 0;
  }
  RegCloseKey(hSubKey);
  return v1;
}

//----- (00BE1149) --------------------------------------------------------
int __stdcall Fake_HtmlHelp(int a1, int a2, int a3, int a4)
{
  HMODULE v4; // ecx
  FARPROC v6; // eax
  CHAR LibFileName; // [esp+Ch] [ebp-108h]

  v4 = ghHHCtrlModule;
  if ( ghHHCtrlModule || (HMODULE)gbHHCtrlModuleInited != ghHHCtrlModule )
    goto LABEL_13;
  if ( GetHtmlHelpXPathName(&LibFileName) )
    ghHHCtrlModule = LoadLibraryA(&LibFileName);
  v4 = ghHHCtrlModule;
  if ( ghHHCtrlModule || (v4 = LoadLibraryA("hhctrl.ocx"), (ghHHCtrlModule = v4) != 0) )
  {
LABEL_13:
    v6 = (FARPROC)HtmlHelp;
    if ( HtmlHelp )
      return ((int (__stdcall *)(int, int, int, int))v6)(a1, a2, a3, a4);
    v6 = GetProcAddress(v4, (LPCSTR)0xF);
    HtmlHelp = (int)v6;
    if ( v6 )
      return ((int (__stdcall *)(int, int, int, int))v6)(a1, a2, a3, a4);
  }
  gbHHCtrlModuleInited = 1;
  return 0;
}
// CF57BC: using guessed type int HtmlHelp;
// CF57C0: using guessed type int gbHHCtrlModuleInited;

//----- (00BE1200) --------------------------------------------------------
int sub_BE1200()
{
  `eh vector constructor iterator\'(word_CD4900, 0x28u, 20, sub_BE3750, sub_BE3850);
  return atexit(sub_C9A0D0);
}
// CD4900: using guessed type __int16 word_CD4900[400];

//----- (00BE1230) --------------------------------------------------------
int dynamic_initializer_for__garrAccountInfo__()
{
  return atexit((void (__cdecl *)())sub_C9A0F0);
}

//----- (00BE1240) --------------------------------------------------------
int dynamic_initializer_for__gpszTipText__()
{
  gpszTipText = _wcsdup(L"Autoruns - Sysinternals: www.sysinternals.com");
  return atexit(sub_C9A150);
}

//----- (00BE1260) --------------------------------------------------------
int sub_BE1260()
{
  return atexit(sub_C9A160);
}

//----- (00BE1270) --------------------------------------------------------
int sub_BE1270()
{
  return atexit(sub_C9A1C0);
}

//----- (00BE1280) --------------------------------------------------------
HCURSOR dynamic_initializer_for__ghHandCursor__()
{
  HCURSOR result; // eax

  result = LoadCursorW(0, (LPCWSTR)IDC_HAND);
  ghHandCursor = (int)result;
  return result;
}
// CD48EC: using guessed type int ghHandCursor;

//----- (00BE12A0) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48E4__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48E4 = v0;
  *v0 = 0;
  return atexit(sub_C9A220);
}

//----- (00BE12C0) --------------------------------------------------------
int dynamic_initializer_for__gpszSystemPathInfo__()
{
  WCHAR *v0; // eax

  v0 = (WCHAR *)malloc(2u);
  gpszSystemPathInfo = v0;
  *v0 = 0;
  return atexit(sub_C9A230);
}

//----- (00BE12E0) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48FC__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48FC = v0;
  *v0 = 0;
  return atexit(sub_C9A240);
}

//----- (00BE1300) --------------------------------------------------------
int dynamic_initializer_for__gKeyNameMap__()
{
  gKeyNameMap._Mypair._Myval2._Myhead = (std__Tree_node *)std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode();
  return atexit(dynamic_atexit_destructor_for__gKeyNameMap__);
}

//----- (00BE1320) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48F0__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48F0 = v0;
  *v0 = 0;
  return atexit(sub_C9A2D0);
}

//----- (00BE1340) --------------------------------------------------------
HCURSOR dynamic_initializer_for__ghWaitCursor__()
{
  HCURSOR result; // eax

  result = LoadCursorW(0, (LPCWSTR)IDC_WAIT);
  ghWaitCursor = (int)result;
  return result;
}
// CD48E8: using guessed type int ghWaitCursor;

//----- (00BE1360) --------------------------------------------------------
int dynamic_initializer_for__dword_4F4C54__()
{
  WCHAR *v0; // eax

  v0 = (WCHAR *)malloc(2u);
  gszPrintDirectoryForX86.m_String = v0;
  *v0 = 0;
  return atexit(sub_C9A2F0);
}

//----- (00BE1380) --------------------------------------------------------
int dynamic_initializer_for__dword_4F4C50__()
{
  WCHAR *v0; // eax

  v0 = (WCHAR *)malloc(2u);
  gszPrintDirectoryForNTX86.m_String = v0;
  *v0 = 0;
  return atexit(sub_C9A300);
}

//----- (00BE13A0) --------------------------------------------------------
int dynamic_initializer_for__gList5_gList6__()
{
  gList5._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                       0,
                                                       0);
  gList6._Mypair._Myval2._Myhead = 0;
  gList6._Mypair._Myval2._Mysize = 0;
  gList6._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                       0,
                                                       0);
  return atexit(sub_C9A310);
}
// CD4CD8: using guessed type std__List gList5;
// CD4CE0: using guessed type std__List gList6;

//----- (00BE1420) --------------------------------------------------------
int dynamic_initializer_for__gList1__()
{
  gList1._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                       0,
                                                       0);
  return atexit(sub_C9A320);
}

//----- (00BE1440) --------------------------------------------------------
int dynamic_initializer_for__gList2__()
{
  gList2 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_C9A3F0);
}

//----- (00BE1460) --------------------------------------------------------
int dynamic_initializer_for__gList3__()
{
  gList3 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_C9A4C0);
}

//----- (00BE1480) --------------------------------------------------------
int dynamic_initializer_for__gMap5__()
{
  gMap5 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_C9A590);
}

//----- (00BE14A0) --------------------------------------------------------
int sub_BE14A0()
{
  return atexit(sub_C9A610);
}

//----- (00BE14B0) --------------------------------------------------------
int sub_BE14B0()
{
  return atexit(sub_C9A620);
}

//----- (00BE14C0) --------------------------------------------------------
int sub_BE14C0()
{
  return atexit(sub_C9A630);
}

//----- (00BE14D0) --------------------------------------------------------
int dynamic_initializer_for__gActiveScriptEventConsumer__()
{
  ActiveScriptEventConsumer::ActiveScriptEventConsumer(&gActiveScriptEventConsumer);
  return atexit(sub_C9A640);
}
// CD4D28: using guessed type struct ActiveScriptEventConsumer gActiveScriptEventConsumer;

//----- (00BE14F0) --------------------------------------------------------
int dynamic_initializer_for__gCommandLineEventConsumer__()
{
  CommandLineEventConsumer::CommandLineEventConsumer(&gCommandLineEventConsumer);
  return atexit(sub_C9A660);
}

//----- (00BE1510) --------------------------------------------------------
int dynamic_initializer_for__gEventConsumerMap6__()
{
  gEventConsumerMap._Mypair._Myval2._Myhead = (std__Tree_node *)std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_C9A680);
}

//----- (00BE1530) --------------------------------------------------------
ATOM dynamic_initializer_for__gAtomTreeListProperty__()
{
  ATOM result; // ax

  result = GlobalAddAtomW(L"TreeListProperty");
  gAtomTreeListProperty = result;
  return result;
}
// CD4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00BE1550) --------------------------------------------------------
ATOM dynamic_initializer_for__gAtomTreeList__()
{
  ATOM result; // ax

  result = CTreeList::Register();
  gAtomTreeList = result;
  return result;
}
// CD4D9C: using guessed type __int16 gAtomTreeList;

//----- (00BE1560) --------------------------------------------------------
BOOL dynamic_initializer_for__gLogPixelSize__()
{
  HDC v0; // edi

  v0 = CreateCompatibleDC(0);
  gLogPixelSize.x = GetDeviceCaps(v0, 88);
  gLogPixelSize.y = GetDeviceCaps(v0, 90);
  return DeleteDC(v0);
}

//----- (00BE1590) --------------------------------------------------------
int dynamic_initializer_for__ghUxthemeModule__()
{
  ghUxthemeModule = LoadLibraryW(L"uxtheme.dll");
  return atexit(sub_C9A700);
}

//----- (00BE15B0) --------------------------------------------------------
FARPROC dynamic_initializer_for__gpfnCloseThemeData__()
{
  FARPROC result; // eax

  result = (FARPROC)ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "CloseThemeData");
    gpfnCloseThemeData = (int (__stdcall *)(_DWORD))result;
  }
  else
  {
    gpfnCloseThemeData = 0;
  }
  return result;
}

//----- (00BE15E0) --------------------------------------------------------
int (__stdcall *dynamic_initializer_for__gpfnDrawThemeBackground__())(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCRECT pRect, LPCRECT pClipRect)
{
  int (__stdcall *result)(HTHEME, HDC, int, int, LPCRECT, LPCRECT); // eax

  result = (int (__stdcall *)(HTHEME, HDC, int, int, LPCRECT, LPCRECT))ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = (int (__stdcall *)(HTHEME, HDC, int, int, LPCRECT, LPCRECT))GetProcAddress(
                                                                           ghUxthemeModule,
                                                                           "DrawThemeBackground");
    gpfnDrawThemeBackground = result;
  }
  else
  {
    gpfnDrawThemeBackground = 0;
  }
  return result;
}

//----- (00BE1610) --------------------------------------------------------
int (__stdcall *dynamic_initializer_for__gpfnIsThemeActive__())()
{
  int (__stdcall *result)(); // eax

  result = (int (__stdcall *)())ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "IsThemeActive");
    gpfnIsThemeActive = result;
  }
  else
  {
    gpfnIsThemeActive = 0;
  }
  return result;
}
// CD4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (00BE1640) --------------------------------------------------------
FARPROC dynamic_initializer_for__gpfnOpenThemeData__()
{
  FARPROC result; // eax

  result = (FARPROC)ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "OpenThemeData");
    gpfnOpenThemeData = (int (__stdcall *)(_DWORD, _DWORD))result;
  }
  else
  {
    gpfnOpenThemeData = 0;
  }
  return result;
}

//----- (00BE1670) --------------------------------------------------------
IAtlStringMgr *sub_BE1670()
{
  IAtlStringMgr *result; // eax

  result = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  byte_CD4DF4 = 1;
  return result;
}
// CD4DF4: using guessed type char byte_CD4DF4;

//----- (00BE1680) --------------------------------------------------------
int dynamic_initializer_for__gBstrList__()
{
  gBstrList = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_C9A720);
}

//----- (00BE16A0) --------------------------------------------------------
FARPROC dynamic_initializer_for__gpfnEnableTraceEx__()
{
  HMODULE v0; // eax
  FARPROC result; // eax

  v0 = LoadLibraryW(L"Advapi32.dll");
  result = GetProcAddress(v0, "EnableTraceEx");
  EnableTraceEx = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result;
  return result;
}

//----- (00BE16C0) --------------------------------------------------------
int dynamic_initializer_for__gAdapterList__()
{
  gAdapterList._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<_LUID,std::allocator<_LUID>>>::_Buynode0(
                                                             0,
                                                             0);
  return atexit(sub_C9A840);
}

//----- (00BE16E0) --------------------------------------------------------
HANDLE dynamic_initializer_for__gProperties__()
{
  HANDLE result; // eax

  result = CreateEventW(0, 1, 0, 0);
  gProperties.EventHandle = result;
  gProperties.ThreadHandle = 0;
  return result;
}

//----- (00BE1700) --------------------------------------------------------
DWORD sub_BE1700()
{
  DWORD v0; // eax
  double v1; // xmm0_8
  DWORD result; // eax
  double v3; // xmm0_8

  v0 = GetSysColor(15);
  stru_CCDDF0.Name = L"ColorJobs";
  stru_CCDDF0.KeyType = 0;
  v1 = (double)(signed int)v0;
  result = v0 >> 31;
  stru_CCDDF0.StructSize = 0;
  stru_CCDDF0.Address = &gConfig.ColorJobs;
  off_CCDE08 = L"ColorDelProc";
  dword_CCDE0C = 0;
  dword_CCDE10 = 0;
  v3 = v1 + qword_CAD110[result];
  dword_CCDE14 = (int)&gConfig.ColorDelProc;
  off_CCDE20 = L"ColorNewProc";
  dword_CCDE24 = 0;
  dword_CCDE28 = 0;
  stru_CCDDD8.dbValue = v3;
  stru_CCDDF0.dbValue = dbl_CAEA10;
  dbl_CCDE18 = dbl_CAEA18;
  dbl_CCDE30 = dbl_CAEA20;
  qword_CCDE48 = *(_QWORD *)&dbl_CAEA38;
  qword_CCDE60 = *(_QWORD *)&dbl_CAEA28;
  qword_CCDE90 = *(_QWORD *)&dbl_CAEA30;
  qword_CCDEA8 = *(_QWORD *)&dbl_CAEA08;
  dword_CCDE2C = (int)&gConfig.ColorNewProc;
  off_CCDE38 = L"ColorNet";
  dword_CCDE3C = 0;
  dword_CCDE40 = 0;
  dword_CCDE44 = (int)&gConfig.ColorNet;
  dword_CCDE50 = (int)L"ColorProtected";
  dword_CCDE54 = 0;
  dword_CCDE58 = 0;
  dword_CCDE5C = (int)&gConfig.ColorProtected;
  dword_CCDE68 = (int)L"ShowHeatmaps";
  dword_CCDE6C = 1;
  dword_CCDE70 = 0;
  dword_CCDE74 = (int)&gConfig.bShowColumnHeatmaps;
  qword_CCDE78 = *(_QWORD *)&db_one;
  dword_CCDE80 = (int)L"ColorSuspend";
  dword_CCDE84 = 0;
  dword_CCDE88 = 0;
  dword_CCDE8C = (int)&gConfig.ColorSuspend;
  dword_CCDE98 = (int)L"StatusBarColumns";
  dword_CCDE9C = 0;
  dword_CCDEA0 = 0;
  dword_CCDEA4 = (int)&gConfig.dwStatusBarColumns;
  dword_CCDEB0 = (int)L"ShowAllCpus";
  dword_CCDEB4 = 1;
  dword_CCDEB8 = 0;
  dword_CCDEBC = (int)&gConfig.bShowAllCpus;
  qword_CCDEC0 = 0i64;
  dword_CCDEC8 = (int)L"ShowAllGpus";
  dword_CCDECC = 1;
  dword_CCDED0 = 0;
  dword_CCDED4 = (int)&gConfig.bShowAllGpus;
  qword_CCDED8 = 0i64;
  dword_CCDEE0 = (int)L"Opacity";
  dword_CCDEE4 = 0;
  dword_CCDEE8 = 0;
  dword_CCDEEC = (int)&gConfig.dwOpacity;
  qword_CCDEF0 = *(_QWORD *)&db_onehundred;
  dword_CCDEF8 = (int)L"GpuNodeUsageMask";
  dword_CCDEFC = 0;
  dword_CCDF00 = 0;
  dword_CCDF04 = (int)&gConfig.dwGpuNodeUsageMask;
  qword_CCDF08 = *(_QWORD *)&db_one;
  dword_CCDF10 = (int)L"VerifySignatures";
  dword_CCDF14 = 1;
  dword_CCDF18 = 0;
  dword_CCDF1C = (int)&gConfig.bVerifySignatures;
  qword_CCDF20 = 0i64;
  dword_CCDF28 = (int)L"VirusTotalCheck";
  dword_CCDF2C = 1;
  dword_CCDF30 = 0;
  dword_CCDF34 = (int)&gConfig.bCheckVirusTotal;
  qword_CCDF38 = 0i64;
  dword_CCDF40 = (int)L"VirusTotalSubmitUnknown";
  dword_CCDF44 = 1;
  dword_CCDF48 = 0;
  dword_CCDF4C = (int)&gConfig.bVirusTotalSubmitUnknown;
  qword_CCDF50 = 0i64;
  dword_CCDF58 = (int)L"ToolbarBands";
  dword_CCDF5C = 7;
  dword_CCDF60 = 96;
  dword_CCDF64 = (int)gConfig.ToolBandInfo;
  qword_CCDF68 = 0i64;
  dword_CCDF70 = (int)L"UseGoogle";
  dword_CCDF74 = 1;
  dword_CCDF78 = 0;
  dword_CCDF7C = (int)&gConfig.bUseGoogle;
  qword_CCDF80 = 0i64;
  dword_CCDF88 = (int)L"ShowNewProcesses";
  dword_CCDF8C = 1;
  dword_CCDF90 = 0;
  dword_CCDF94 = (int)&gConfig.bShowNewProcesses;
  qword_CCDF98 = 0i64;
  dword_CCDFA0 = (int)L"TrayCPUHistory";
  dword_CCDFA4 = 1;
  dword_CCDFA8 = 0;
  dword_CCDFAC = (int)&gConfig.bTrayCPUHistory;
  qword_CCDFB0 = *(_QWORD *)&db_one;
  dword_CCDFB8 = (int)L"ShowIoTray";
  dword_CCDFBC = 1;
  dword_CCDFC0 = 0;
  dword_CCDFC4 = (int)&gConfig.bShowIoTray;
  qword_CCDFC8 = 0i64;
  dword_CCDFD0 = (int)L"ShowNetTray";
  dword_CCDFD4 = 1;
  dword_CCDFD8 = 0;
  dword_CCDFDC = (int)&gConfig.bShowNetTray;
  qword_CCDFE0 = 0i64;
  dword_CCDFE8 = (int)L"ShowDiskTray";
  dword_CCDFEC = 1;
  dword_CCDFF0 = 0;
  dword_CCDFF4 = (int)&gConfig.bShowDiskTray;
  qword_CCDFF8 = 0i64;
  dword_CCE000 = (int)L"ShowPhysTray";
  dword_CCE004 = 1;
  dword_CCE008 = 0;
  dword_CCE00C = (int)&gConfig.bShowPhysTray;
  qword_CCE010 = 0i64;
  dword_CCE018 = (int)L"ShowCommitTray";
  dword_CCE01C = 1;
  dword_CCE020 = 0;
  dword_CCE024 = (int)&gConfig.bShowCommitTray;
  qword_CCE028 = 0i64;
  dword_CCE030 = (int)L"ShowGpuTray";
  dword_CCE034 = 1;
  dword_CCE038 = 0;
  dword_CCE03C = (int)&gConfig.bShowGpuHistory;
  qword_CCE040 = 0i64;
  dword_CCE048 = (int)L"FormatIoBytes";
  dword_CCE04C = 1;
  dword_CCE050 = 0;
  dword_CCE054 = (int)&gConfig.bFormatIoBytes;
  qword_CCE058 = *(_QWORD *)&db_one;
  dword_CCE060 = (int)L"StackWindowPlacement";
  dword_CCE064 = 7;
  dword_CCE068 = 44;
  dword_CCE06C = (int)&gConfig.WindowPlacement[7].ptMaxPosition.y;
  qword_CCE070 = 0i64;
  dword_CCE078 = (int)L"ETWstandardUserWarning";
  dword_CCE07C = 1;
  dword_CCE080 = 0;
  dword_CCE084 = (int)&gConfig.bETWStandardUserWarning;
  qword_CCE088 = 0i64;
  dword_CCE090 = 0;
  dword_CCE094 = 0;
  dword_CCE098 = 0;
  dword_CCE09C = 0;
  qword_CCE0A0 = 0i64;
  return result;
}
// CACDC0: using guessed type double db_onehundred;
// CADAD8: using guessed type wchar_t aColorjobs[10];
// CADAEC: using guessed type wchar_t aColordelproc[13];
// CADB08: using guessed type wchar_t aColornewproc[13];
// CADB24: using guessed type wchar_t aColornet[9];
// CADB38: using guessed type wchar_t aColorprotected[15];
// CADB58: using guessed type wchar_t aShowheatmaps[13];
// CADB74: using guessed type wchar_t aColorsuspend[13];
// CADB90: using guessed type wchar_t aStatusbarcolum[17];
// CADBB4: using guessed type wchar_t aShowallcpus[12];
// CADBCC: using guessed type wchar_t aShowallgpus[12];
// CADBF4: using guessed type wchar_t aGpunodeusagema[17];
// CADC18: using guessed type wchar_t aVerifysignatur[17];
// CADC3C: using guessed type wchar_t aVirustotalchec[16];
// CADC5C: using guessed type wchar_t aVirustotalsubm[24];
// CADC8C: using guessed type wchar_t aToolbarbands[13];
// CADCA8: using guessed type wchar_t aUsegoogle[10];
// CADCBC: using guessed type wchar_t aShownewprocess[17];
// CADCE0: using guessed type wchar_t aTraycpuhistory[15];
// CADD00: using guessed type wchar_t aShowiotray[11];
// CADD18: using guessed type wchar_t aShownettray[12];
// CADD30: using guessed type wchar_t aShowdisktray[13];
// CADD4C: using guessed type wchar_t aShowphystray[13];
// CADD68: using guessed type wchar_t aShowcommittray[15];
// CADD88: using guessed type wchar_t aShowgputray[12];
// CADDA0: using guessed type wchar_t aFormatiobytes[14];
// CADDBC: using guessed type wchar_t aStackwindowpla[21];
// CADDE8: using guessed type wchar_t aEtwstandarduse[23];
// CAEA08: using guessed type double dbl_CAEA08;
// CAEA10: using guessed type double dbl_CAEA10;
// CAEA18: using guessed type double dbl_CAEA18;
// CAEA20: using guessed type double dbl_CAEA20;
// CAEA28: using guessed type double dbl_CAEA28;
// CAEA30: using guessed type double dbl_CAEA30;
// CAEA38: using guessed type double dbl_CAEA38;
// CCDDD8: using guessed type tagConfigItem stru_CCDDD8;
// CCDDF0: using guessed type tagConfigItem stru_CCDDF0;
// CCDE08: using guessed type void *off_CCDE08;
// CCDE0C: using guessed type int dword_CCDE0C;
// CCDE10: using guessed type int dword_CCDE10;
// CCDE14: using guessed type int dword_CCDE14;
// CCDE18: using guessed type double dbl_CCDE18;
// CCDE20: using guessed type void *off_CCDE20;
// CCDE24: using guessed type int dword_CCDE24;
// CCDE28: using guessed type int dword_CCDE28;
// CCDE2C: using guessed type int dword_CCDE2C;
// CCDE30: using guessed type double dbl_CCDE30;
// CCDE38: using guessed type void *off_CCDE38;
// CCDE3C: using guessed type int dword_CCDE3C;
// CCDE40: using guessed type int dword_CCDE40;
// CCDE44: using guessed type int dword_CCDE44;
// CCDE48: using guessed type __int64 qword_CCDE48;
// CCDE50: using guessed type int dword_CCDE50;
// CCDE54: using guessed type int dword_CCDE54;
// CCDE58: using guessed type int dword_CCDE58;
// CCDE5C: using guessed type int dword_CCDE5C;
// CCDE60: using guessed type __int64 qword_CCDE60;
// CCDE68: using guessed type int dword_CCDE68;
// CCDE6C: using guessed type int dword_CCDE6C;
// CCDE70: using guessed type int dword_CCDE70;
// CCDE74: using guessed type int dword_CCDE74;
// CCDE78: using guessed type __int64 qword_CCDE78;
// CCDE80: using guessed type int dword_CCDE80;
// CCDE84: using guessed type int dword_CCDE84;
// CCDE88: using guessed type int dword_CCDE88;
// CCDE8C: using guessed type int dword_CCDE8C;
// CCDE90: using guessed type __int64 qword_CCDE90;
// CCDE98: using guessed type int dword_CCDE98;
// CCDE9C: using guessed type int dword_CCDE9C;
// CCDEA0: using guessed type int dword_CCDEA0;
// CCDEA4: using guessed type int dword_CCDEA4;
// CCDEA8: using guessed type __int64 qword_CCDEA8;
// CCDEB0: using guessed type int dword_CCDEB0;
// CCDEB4: using guessed type int dword_CCDEB4;
// CCDEB8: using guessed type int dword_CCDEB8;
// CCDEBC: using guessed type int dword_CCDEBC;
// CCDEC0: using guessed type __int64 qword_CCDEC0;
// CCDEC8: using guessed type int dword_CCDEC8;
// CCDECC: using guessed type int dword_CCDECC;
// CCDED0: using guessed type int dword_CCDED0;
// CCDED4: using guessed type int dword_CCDED4;
// CCDED8: using guessed type __int64 qword_CCDED8;
// CCDEE0: using guessed type int dword_CCDEE0;
// CCDEE4: using guessed type int dword_CCDEE4;
// CCDEE8: using guessed type int dword_CCDEE8;
// CCDEEC: using guessed type int dword_CCDEEC;
// CCDEF0: using guessed type __int64 qword_CCDEF0;
// CCDEF8: using guessed type int dword_CCDEF8;
// CCDEFC: using guessed type int dword_CCDEFC;
// CCDF00: using guessed type int dword_CCDF00;
// CCDF04: using guessed type int dword_CCDF04;
// CCDF08: using guessed type __int64 qword_CCDF08;
// CCDF10: using guessed type int dword_CCDF10;
// CCDF14: using guessed type int dword_CCDF14;
// CCDF18: using guessed type int dword_CCDF18;
// CCDF1C: using guessed type int dword_CCDF1C;
// CCDF20: using guessed type __int64 qword_CCDF20;
// CCDF28: using guessed type int dword_CCDF28;
// CCDF2C: using guessed type int dword_CCDF2C;
// CCDF30: using guessed type int dword_CCDF30;
// CCDF34: using guessed type int dword_CCDF34;
// CCDF38: using guessed type __int64 qword_CCDF38;
// CCDF40: using guessed type int dword_CCDF40;
// CCDF44: using guessed type int dword_CCDF44;
// CCDF48: using guessed type int dword_CCDF48;
// CCDF4C: using guessed type int dword_CCDF4C;
// CCDF50: using guessed type __int64 qword_CCDF50;
// CCDF58: using guessed type int dword_CCDF58;
// CCDF5C: using guessed type int dword_CCDF5C;
// CCDF60: using guessed type int dword_CCDF60;
// CCDF64: using guessed type int dword_CCDF64;
// CCDF68: using guessed type __int64 qword_CCDF68;
// CCDF70: using guessed type int dword_CCDF70;
// CCDF74: using guessed type int dword_CCDF74;
// CCDF78: using guessed type int dword_CCDF78;
// CCDF7C: using guessed type int dword_CCDF7C;
// CCDF80: using guessed type __int64 qword_CCDF80;
// CCDF88: using guessed type int dword_CCDF88;
// CCDF8C: using guessed type int dword_CCDF8C;
// CCDF90: using guessed type int dword_CCDF90;
// CCDF94: using guessed type int dword_CCDF94;
// CCDF98: using guessed type __int64 qword_CCDF98;
// CCDFA0: using guessed type int dword_CCDFA0;
// CCDFA4: using guessed type int dword_CCDFA4;
// CCDFA8: using guessed type int dword_CCDFA8;
// CCDFAC: using guessed type int dword_CCDFAC;
// CCDFB0: using guessed type __int64 qword_CCDFB0;
// CCDFB8: using guessed type int dword_CCDFB8;
// CCDFBC: using guessed type int dword_CCDFBC;
// CCDFC0: using guessed type int dword_CCDFC0;
// CCDFC4: using guessed type int dword_CCDFC4;
// CCDFC8: using guessed type __int64 qword_CCDFC8;
// CCDFD0: using guessed type int dword_CCDFD0;
// CCDFD4: using guessed type int dword_CCDFD4;
// CCDFD8: using guessed type int dword_CCDFD8;
// CCDFDC: using guessed type int dword_CCDFDC;
// CCDFE0: using guessed type __int64 qword_CCDFE0;
// CCDFE8: using guessed type int dword_CCDFE8;
// CCDFEC: using guessed type int dword_CCDFEC;
// CCDFF0: using guessed type int dword_CCDFF0;
// CCDFF4: using guessed type int dword_CCDFF4;
// CCDFF8: using guessed type __int64 qword_CCDFF8;
// CCE000: using guessed type int dword_CCE000;
// CCE004: using guessed type int dword_CCE004;
// CCE008: using guessed type int dword_CCE008;
// CCE00C: using guessed type int dword_CCE00C;
// CCE010: using guessed type __int64 qword_CCE010;
// CCE018: using guessed type int dword_CCE018;
// CCE01C: using guessed type int dword_CCE01C;
// CCE020: using guessed type int dword_CCE020;
// CCE024: using guessed type int dword_CCE024;
// CCE028: using guessed type __int64 qword_CCE028;
// CCE030: using guessed type int dword_CCE030;
// CCE034: using guessed type int dword_CCE034;
// CCE038: using guessed type int dword_CCE038;
// CCE03C: using guessed type int dword_CCE03C;
// CCE040: using guessed type __int64 qword_CCE040;
// CCE048: using guessed type int dword_CCE048;
// CCE04C: using guessed type int dword_CCE04C;
// CCE050: using guessed type int dword_CCE050;
// CCE054: using guessed type int dword_CCE054;
// CCE058: using guessed type __int64 qword_CCE058;
// CCE060: using guessed type int dword_CCE060;
// CCE064: using guessed type int dword_CCE064;
// CCE068: using guessed type int dword_CCE068;
// CCE06C: using guessed type int dword_CCE06C;
// CCE070: using guessed type __int64 qword_CCE070;
// CCE078: using guessed type int dword_CCE078;
// CCE07C: using guessed type int dword_CCE07C;
// CCE080: using guessed type int dword_CCE080;
// CCE084: using guessed type int dword_CCE084;
// CCE088: using guessed type __int64 qword_CCE088;
// CCE090: using guessed type int dword_CCE090;
// CCE094: using guessed type int dword_CCE094;
// CCE098: using guessed type int dword_CCE098;
// CCE09C: using guessed type int dword_CCE09C;
// CCE0A0: using guessed type __int64 qword_CCE0A0;

//----- (00BE1CE0) --------------------------------------------------------
FARPROC sub_BE1CE0()
{
  FARPROC result; // eax

  result = (FARPROC)ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "EnableThemeDialogTexture");
    gpfnEnableThemeDialogTexture = (int (__stdcall *)(_DWORD, _DWORD))result;
  }
  else
  {
    gpfnEnableThemeDialogTexture = 0;
  }
  return result;
}
// CD9E88: using guessed type int (__stdcall *gpfnEnableThemeDialogTexture)(_DWORD, _DWORD);

//----- (00BE1D10) --------------------------------------------------------
int dynamic_initializer_for__gPerformanceInfoInMemory__()
{
  PE_PerfInfo::PE_PerfInfo(&gPerformanceInfoInMemory, (PerformanceInfo *)&gPerformanceInfo);
  return atexit(sub_C9A9D0);
}

//----- (00BE1D30) --------------------------------------------------------
int dynamic_initializer_for__gPerformanceInfo__()
{
  PerformanceInfo::PerformanceInfo((PerformanceInfo *)&gPerformanceInfo, 0);
  return atexit(sub_C9A9E0);
}

//----- (00BE1D50) --------------------------------------------------------
int dynamic_initializer_for__gNullString__()
{
  BSTR v0; // esi
  Data_t_bstr_t *v1; // eax

  v0 = SysAllocStringLen(&strIn, 1u);
  v1 = (Data_t_bstr_t *)operator new(0xCu);
  if ( v1 )
  {
    v1->m_str = 0;
    v1->m_RefCount = 1;
    v1->m_wstr = v0;
  }
  else
  {
    v1 = 0;
  }
  gNullString.m_Data = v1;
  if ( !v1 )
    _com_issue_error(E_OUTOFMEMORY);
  return atexit(sub_C9A9F0);
}

//----- (00BE1DE0) --------------------------------------------------------
int dynamic_initializer_for__gWbemServicesList__()
{
  *(&gWbemServiceList + 1) = (IWbemServices *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                0,
                                                0);
  return atexit(sub_C9AA50);
}

//----- (00BE1E00) --------------------------------------------------------
BOOL dynamic_initializer_for__gTime__()
{
  GetSystemTimeAsFileTime((LPFILETIME)&gTime);
  QueryPerformanceCounter((LARGE_INTEGER *)&gTime.Performance);
  return QueryPerformanceFrequency((LARGE_INTEGER *)&gTime.Frequency);
}

//----- (00BE1E30) --------------------------------------------------------
int dynamic_initializer_for__gThreadProcessMap__()
{
  gThreadProcessMap._Header = (std__Tree_node *)std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_C9AB20);
}

//----- (00BE1E50) --------------------------------------------------------
bool dynamic_initializer_for__gbBitmapOnRight__()
{
  bool result; // al

  result = IsXPDll();
  gbBitmapOnRight = result;
  return result;
}
// CDA8F8: using guessed type char gbBitmapOnRight;

//----- (00BE1E60) --------------------------------------------------------
int dynamic_initializer_for__gDiskGraphInfo__()
{
  _bstr_t::_bstr_t(&gDiskGraphInfo.strName, "Disk");
  gDiskGraphInfo.pGraphData = 0;
  gDiskGraphInfo.dbMemorySize = 0i64;
  gDiskGraphInfo.nItemID = 8;
  return atexit(sub_C9ABA0);
}

//----- (00BE1EA0) --------------------------------------------------------
int dynamic_initializer_for__gIOGraphInfo__()
{
  _bstr_t::_bstr_t(&gIOGraphInfo.strName, "I/O");
  gIOGraphInfo.pGraphData = 0;
  gIOGraphInfo.dbMemorySize = 0i64;
  gIOGraphInfo.nItemID = 2;
  return atexit(sub_C9AC00);
}

//----- (00BE1EE0) --------------------------------------------------------
int dynamic_initializer_for__gNetworkGraphInfo__()
{
  _bstr_t::_bstr_t(&gNetworkGraphInfo.strName, "Network");
  gNetworkGraphInfo.pGraphData = 0;
  gNetworkGraphInfo.dbMemorySize = 0i64;
  gNetworkGraphInfo.nItemID = 9;
  return atexit(sub_C9AC60);
}

//----- (00BE1F20) --------------------------------------------------------
int dynamic_initializer_for__gMap2__()
{
  gMap2_NodeSizeIs48H._Mypair._Myval2._Myhead = sub_C65440();
  return atexit(sub_C9ACC0);
}

//----- (00BE1F40) --------------------------------------------------------
int dynamic_initializer_for__gMap3__()
{
  gMap3_NodeSizeIs48H._Mypair._Myval2._Myhead = sub_C65440();
  return atexit(sub_C9AD40);
}

//----- (00BE1F60) --------------------------------------------------------
int sub_BE1F60()
{
  int result; // eax

  result = TreeList_Item1::Reset(&gTreeList_Item[2]);
  gTreeList_Item[2].field_14 = 0;
  gTreeList_Item[2].field_10 = 0;
  gTreeList_Item[2].field_C = 0;
  return result;
}

//----- (00BE1F90) --------------------------------------------------------
int sub_BE1F90()
{
  int result; // eax

  result = TreeList_Item1::Reset(gTreeList_Item);
  gTreeList_Item[0].field_14 = 0;
  gTreeList_Item[0].field_10 = 0;
  gTreeList_Item[0].field_C = 0;
  return result;
}

//----- (00BE1FC0) --------------------------------------------------------
int sub_BE1FC0()
{
  int result; // eax

  result = TreeList_Item1::Reset(&gTreeList_Item[1]);
  gTreeList_Item[1].field_14 = 0;
  gTreeList_Item[1].field_10 = 0;
  gTreeList_Item[1].field_C = 0;
  return result;
}

//----- (00BE1FF0) --------------------------------------------------------
int dynamic_initializer_for__gHttpInfo__()
{
  gHttpInfo.m_List._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                                 0,
                                                                 0);
  gHttpInfo.m_List2._Mypair._Myval2._Myhead = 0;
  gHttpInfo.m_List2._Mypair._Myval2._Mysize = 0;
  gHttpInfo.m_List2._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                                  0,
                                                                  0);
  return atexit(HttpInfo_Release);
}

//----- (00BE2070) --------------------------------------------------------
int dynamic_initializer_for__gList10__()
{
  gList10._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                        0,
                                                        0);
  return atexit(sub_C9AE00);
}

//----- (00BE2090) --------------------------------------------------------
int dynamic_initializer_for__gList11__()
{
  gList11 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_C9AED0);
}

//----- (00BE20B0) --------------------------------------------------------
int dynamic_initializer_for__gList12__()
{
  gList12 = (EventList *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                           0,
                           0);
  return atexit(sub_C9AFA0);
}

//----- (00BE20D0) --------------------------------------------------------
int sub_BE20D0()
{
  gHttpInfo.m_Map._Mypair._Myval2._Myhead = (std__Tree_node *)std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_C9B070);
}

//----- (00BE20F0) --------------------------------------------------------
int sub_BE20F0()
{
  return atexit(sub_C9B0F0);
}

//----- (00BE20FC) --------------------------------------------------------
int sub_BE20FC()
{
  std::_Init_locks::_Init_locks((std::_Init_locks *)&unk_CF57D8);
  return atexit(sub_C9B0FC);
}

//----- (00BE2112) --------------------------------------------------------
int sub_BE2112()
{
  return atexit(sub_C9B106);
}

//----- (00BE211E) --------------------------------------------------------
int sub_BE211E()
{
  return atexit(sub_C9B110);
}

//----- (00BE212A) --------------------------------------------------------
int sub_BE212A()
{
  return atexit(sub_C9B11A);
}

//----- (00BE2136) --------------------------------------------------------
int sub_BE2136()
{
  std::_Init_locks::_Init_locks((std::_Init_locks *)&unk_CF58F0);
  return atexit(sub_C9B124);
}

//----- (00BE214C) --------------------------------------------------------
int dynamic_initializer_for__ATL::_AtlBaseModule___()
{
  ATL::CAtlWinModule::CAtlWinModule((char *)&ATL::_AtlBaseModule);
  return atexit(ATL::_dynamic_atexit_destructor_for___AtlBaseModule__);
}

//----- (00BE2170) --------------------------------------------------------
StringItem *__thiscall StringItem::StringItem(StringItem *this)
{
  StringItem *v1; // esi
  _WORD *v2; // eax
  StringItem *result; // eax

  v1 = this;
  v2 = malloc(2u);
  v1->strText = (int)v2;
  *v2 = 0;
  result = v1;
  v1->arrTexts.baseclass_0._Mypair._Myval2._Myfirst = 0;
  v1->arrTexts.baseclass_0._Mypair._Myval2._Mylast = 0;
  v1->arrTexts.baseclass_0._Mypair._Myval2._Myend = 0;
  return result;
}

//----- (00BE21A0) --------------------------------------------------------
void __thiscall StringItem::Clean(StringItem *this)
{
  StringItem *v1; // edi
  void **v2; // esi
  void **i; // ebx

  v1 = this;
  v2 = (void **)this->strText;
  if ( this->strText )
  {
    for ( i = (void **)this->arrTexts.baseclass_0._Mypair._Myval2._Myfirst; v2 != i; ++v2 )
      free(*v2);
    operator delete((void *)v1->strText);
    v1->strText = 0;
    v1->arrTexts.baseclass_0._Mypair._Myval2._Myfirst = 0;
    v1->arrTexts.baseclass_0._Mypair._Myval2._Mylast = 0;
  }
}

//----- (00BE21F0) --------------------------------------------------------
void __thiscall StringItem::~StringItem(tagPEStringStruct *this)
{
  tagPEStringStruct *v1; // edi
  void **v2; // esi
  int i; // ebx

  v1 = this;
  v2 = (void **)this->strValue[1];
  if ( v2 )
  {
    for ( i = this->strValue[2]; v2 != (void **)i; ++v2 )
      free(*v2);
    operator delete((void *)v1->strValue[1]);
    v1->strValue[1] = 0;
    v1->strValue[2] = 0;
    v1->strValue[3] = 0;
  }
  free((void *)v1->strValue[0]);
}

//----- (00BE2250) --------------------------------------------------------
CCmdString *__thiscall CCmdString::Reset(CCmdString *this, CCmdString *a2)
{
  CCmdString *v2; // edi
  WCHAR *v3; // esi

  v2 = this;
  v3 = this->m_String;
  this->m_String = _wcsdup(a2->m_String);
  free(v3);
  return v2;
}

//----- (00BE2280) --------------------------------------------------------
CCmdString *__thiscall CCmdString::Reset(CCmdString *this, wchar_t *a2)
{
  CCmdString *v2; // edi
  WCHAR *v3; // esi

  v2 = this;
  v3 = this->m_String;
  this->m_String = _wcsdup(a2);
  free(v3);
  return v2;
}

//----- (00BE22B0) --------------------------------------------------------
CCmdString *__cdecl CCmdString::operator+(CCmdString *str, CCmdString *strText1, LPCWSTR lpszText2)
{
  const wchar_t *v3; // ecx
  wchar_t *v4; // eax
  wchar_t *pszText2; // esi

  v3 = (const wchar_t *)&gszNullString;
  if ( lpszText2 )
    v3 = lpszText2;
  v4 = _wcsdup(v3);
  pszText2 = v4;
  lpszText2 = v4;
  CCmdString::Append(str, strText1, (CCmdString *)&lpszText2);
  free(pszText2);
  return str;
}

//----- (00BE2300) --------------------------------------------------------
void __thiscall CCmdString::InsertAt(CCmdString *this, const wchar_t *lpszText, unsigned int dwPos, unsigned int dwLength)
{
  CCmdString *ppv_1; // eax
  WCHAR *pstr; // ecx
  unsigned int dwTextLen; // esi
  unsigned int dwLengthIn; // ebx
  unsigned int dwPosIn; // edx
  unsigned int nTextLen2; // edi
  WCHAR *v10; // eax
  CCmdString *ppv_3; // ecx
  CCmdString *ppv_2; // [esp+Ch] [ebp-4h]
  DWORD dwPos_2; // [esp+1Ch] [ebp+Ch]

  ppv_1 = this;
  pstr = this->m_String;
  ppv_2 = ppv_1;
  dwTextLen = wcslen(pstr);
  dwLengthIn = dwLength;
  dwPosIn = dwPos;
  if ( dwPos > dwTextLen )
    dwPosIn = dwTextLen;
  dwPos_2 = dwPosIn;
  if ( dwPosIn + dwLength > dwTextLen )
    dwLengthIn = dwTextLen - dwPosIn;
  nTextLen2 = wcslen(lpszText);
  if ( (signed int)(nTextLen2 - dwLengthIn) <= 0 )
  {
    // 直接复制到字符串的指定的位置
    ppv_3 = ppv_2;
  }
  else
  {
    // 重新开辟内存，进行复制
    v10 = (WCHAR *)realloc(pstr, 2 * (dwTextLen + nTextLen2 - dwLengthIn + 2));
    ppv_3 = ppv_2;
    dwPosIn = dwPos_2;
    ppv_2->m_String = v10;
  }
  memmove(
    &ppv_3->m_String[dwPosIn + nTextLen2],
    &ppv_3->m_String[dwPosIn + dwLengthIn],
    2 * (dwTextLen - dwPosIn - dwLengthIn) + 2);
  memmove_0(&ppv_2->m_String[dwPos_2], lpszText, 2 * nTextLen2);
}

//----- (00BE23D0) --------------------------------------------------------
void __cdecl sub_BE23D0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  WCHAR **v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BE2480(a1, (HKEY)a2, *(wchar_t **)a3, (WCHAR **)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BE2480(a1, (HKEY)a2, v7, v5);
  free(v7);
}

//----- (00BE2480) --------------------------------------------------------
WCHAR **__cdecl sub_BE2480(int a1, HKEY hSubKey, wchar_t *lpszKeyName, WCHAR **pszReturned)
{
  DWORD v4; // ebx
  HKEY v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  CCmdString *v8; // esi
  CCmdString *v9; // eax
  unsigned int v10; // eax
  const WCHAR *v11; // esi
  unsigned int v12; // eax
  WCHAR *v13; // esi
  void *v14; // esi
  const wchar_t **v15; // eax
  WCHAR *v16; // esi
  const wchar_t *v17; // ecx
  const wchar_t *v18; // eax
  CCmdString *v19; // esi
  CCmdString *v20; // eax
  char v21; // bl
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  HKEY v24; // ebx
  CCmdString *v25; // esi
  CCmdString *v26; // eax
  const wchar_t *v27; // eax
  CCmdString *v28; // eax
  int a2a; // [esp+10h] [ebp-A4h]
  int v31; // [esp+14h] [ebp-A0h]
  int v32; // [esp+18h] [ebp-9Ch]
  int v33; // [esp+1Ch] [ebp-98h]
  WCHAR v34[2]; // [esp+20h] [ebp-94h]
  WCHAR v35[2]; // [esp+24h] [ebp-90h]
  WCHAR v36[2]; // [esp+28h] [ebp-8Ch]
  DWORD dwValue; // [esp+2Ch] [ebp-88h]
  void *v38; // [esp+30h] [ebp-84h]
  int a8; // [esp+34h] [ebp-80h]
  WCHAR v40[2]; // [esp+38h] [ebp-7Ch]
  WCHAR v41[2]; // [esp+3Ch] [ebp-78h]
  DWORD v42; // [esp+40h] [ebp-74h]
  void *v43; // [esp+44h] [ebp-70h]
  void *v44; // [esp+48h] [ebp-6Ch]
  void *v45; // [esp+4Ch] [ebp-68h]
  void *v46; // [esp+50h] [ebp-64h]
  CCmdString v47; // [esp+54h] [ebp-60h]
  HKEY hKey; // [esp+58h] [ebp-5Ch]
  void *v49; // [esp+5Ch] [ebp-58h]
  CCmdString szArg; // [esp+60h] [ebp-54h]
  void *v51; // [esp+64h] [ebp-50h]
  CCmdString a1a; // [esp+68h] [ebp-4Ch]
  HKEY KeyHandle; // [esp+6Ch] [ebp-48h]
  LPCWSTR v54; // [esp+70h] [ebp-44h]
  LPCWSTR v55; // [esp+74h] [ebp-40h]
  CCmdString strValueName; // [esp+78h] [ebp-3Ch]
  CCmdString szArg3; // [esp+7Ch] [ebp-38h]
  CCmdString pszText; // [esp+80h] [ebp-34h]
  LPCWSTR v59; // [esp+84h] [ebp-30h]
  LPCWSTR v60; // [esp+88h] [ebp-2Ch]
  CCmdString szArg4; // [esp+8Ch] [ebp-28h]
  LPCWSTR v62; // [esp+90h] [ebp-24h]
  LPCWSTR szKeyName; // [esp+94h] [ebp-20h]
  WCHAR *ppv3; // [esp+98h] [ebp-1Ch]
  CCmdString str3; // [esp+9Ch] [ebp-18h]
  LPCWSTR lpSubKey; // [esp+A0h] [ebp-14h]
  CCmdString ppv; // [esp+A4h] [ebp-10h]
  int v68; // [esp+B0h] [ebp-4h]

  v4 = 0;
  v42 = 0;
  ppv.m_String = (WCHAR *)malloc(2u);
  *ppv.m_String = 0;
  v68 = 0;
  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  lpSubKey = (LPCWSTR)malloc(2u);
  *lpSubKey = 0;
  str3.m_String = (WCHAR *)malloc(2u);
  *str3.m_String = 0;
  v49 = malloc(2u);
  *(_WORD *)v49 = 0;
  v46 = malloc(2u);
  *(_WORD *)v46 = 0;
  v47.m_String = (WCHAR *)malloc(2u);
  *v47.m_String = 0;
  v51 = malloc(2u);
  *(_WORD *)v51 = 0;
  v5 = hSubKey;
  LOBYTE(v68) = 7;
  if ( pszReturned == (WCHAR **)-1 )
  {
    v62 = _wcsdup((const wchar_t *)&gszNullString);
    v54 = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v55 = _wcsdup((const wchar_t *)&gszNullString);
    v59 = _wcsdup((const wchar_t *)&gszNullString);
    v60 = _wcsdup((const wchar_t *)&gszNullString);
    szArg4.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v6 = lpszKeyName;
    pszText.m_String = _wcsdup(v6);
    strValueName.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v7 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v7 = lpszKeyName;
    szArg3.m_String = _wcsdup(v7);
    LOBYTE(v68) = 17;
    v8 = MakeRegistryKeyName(&a1a, hSubKey, &pszText, &szArg4);
    LOBYTE(v68) = 18;
    v9 = MakeRegistryKeyName(&szArg, hSubKey, &szArg3, &strValueName);
    LOBYTE(v68) = 19;
    pszReturned = (WCHAR **)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v9, v8, (CCmdString *)&v60);
    free(szArg.m_String);
    free(a1a.m_String);
    free(szArg3.m_String);
    free(strValueName.m_String);
    free(pszText.m_String);
    free(szArg4.m_String);
    free((void *)v60);
    free((void *)v59);
    free((void *)v55);
    free((void *)szKeyName);
    free((void *)v54);
    LOBYTE(v68) = 7;
    free((void *)v62);
    v5 = hSubKey;
  }
  v10 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(v5, lpszKeyName, 0, v10 | 0x20019, &KeyHandle) )
  {
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&lpSubKey) )
    {
      do
      {
        v11 = lpSubKey;
        v12 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v11, 0, v12 | 0x20019, &hKey) )
        {
          if ( !PE_LoadStrKey(KeyHandle, lpSubKey, &ppv3) )
          {
            if ( (*ppv.m_String = 0, !PE_ReadRegKey(hKey, L"ShellComponent", 0, 0, &ppv)) && *ppv.m_String
              || (PE_ReadRegKey(hKey, L"StubPath", 0, 0, &ppv), *ppv.m_String) )
            {
              v13 = ppv3;
              if ( !*ppv3 )
              {
                ppv3 = _wcsdup(L"n/a");
                free(v13);
              }
              a2a = (int)malloc(2u);
              *(_WORD *)a2a = 0;
              v31 = 0;
              v32 = 0;
              v33 = 0;
              LOBYTE(v68) = 20;
              sub_BE6CC0(ppv.m_String, (StringItem *)&a2a);
              v14 = v51;
              v51 = _wcsdup(ppv.m_String);
              free(v14);
              v15 = (const wchar_t **)sub_BE4EE0((int)&v38, a1, (int)&a2a, 0);
              v16 = str3.m_String;
              str3.m_String = _wcsdup(*v15);
              free(v16);
              free(v38);
              dwValue = sub_BE4ED0();
              v17 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName )
                v17 = lpszKeyName;
              szKeyName = _wcsdup(v17);
              v54 = _wcsdup((const wchar_t *)&gszNullString);
              v18 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName )
                v18 = lpszKeyName;
              v62 = _wcsdup(v18);
              LOBYTE(v68) = 23;
              v19 = MakeRegistryKeyName((CCmdString *)v41, hSubKey, (CCmdString *)&szKeyName, (CCmdString *)&lpSubKey);
              LOBYTE(v68) = 24;
              v20 = MakeRegistryKeyName((CCmdString *)v36, hSubKey, (CCmdString *)&v62, (CCmdString *)&v54);
              LOBYTE(v68) = 25;
              v21 = sub_BE3D40(
                      a1,
                      (CCmdString)v20,
                      (int)v19,
                      (int)&ppv3,
                      (int)&str3,
                      (int)&v49,
                      (CCmdString)&v47,
                      (int)&a8);
              free(*(void **)v36);
              free(*(void **)v41);
              free((void *)v62);
              free((void *)v54);
              free((void *)szKeyName);
              if ( v21 )
              {
                if ( pszReturned == (WCHAR **)-1 )
                {
                  v44 = _wcsdup((const wchar_t *)&gszNullString);
                  v43 = _wcsdup((const wchar_t *)&gszNullString);
                  v45 = _wcsdup((const wchar_t *)&gszNullString);
                  szArg3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  strValueName.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  pszText.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  szArg4.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  v22 = (const wchar_t *)&gszNullString;
                  if ( lpszKeyName )
                    v22 = lpszKeyName;
                  v60 = _wcsdup(v22);
                  v59 = _wcsdup((const wchar_t *)&gszNullString);
                  v23 = (const wchar_t *)&gszNullString;
                  if ( lpszKeyName )
                    v23 = lpszKeyName;
                  v55 = _wcsdup(v23);
                  v24 = hSubKey;
                  LOBYTE(v68) = 35;
                  v25 = MakeRegistryKeyName((CCmdString *)v40, hSubKey, (CCmdString *)&v60, &szArg4);
                  LOBYTE(v68) = 36;
                  v26 = MakeRegistryKeyName((CCmdString *)v34, hSubKey, (CCmdString *)&v55, (CCmdString *)&v59);
                  LOBYTE(v68) = 37;
                  pszReturned = (WCHAR **)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v26, v25, &pszText);
                  free(*(void **)v34);
                  free(*(void **)v40);
                  free((void *)v55);
                  free((void *)v59);
                  free((void *)v60);
                  free(szArg4.m_String);
                  free(pszText.m_String);
                  free(strValueName.m_String);
                  free(szArg3.m_String);
                  free(v45);
                  free(v43);
                  free(v44);
                }
                else
                {
                  v24 = hSubKey;
                }
                szArg.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v27 = (const wchar_t *)&gszNullString;
                if ( lpszKeyName )
                  v27 = lpszKeyName;
                a1a.m_String = _wcsdup(v27);
                LOBYTE(v68) = 39;
                v28 = MakeRegistryKeyName((CCmdString *)v35, v24, &a1a, (CCmdString *)&lpSubKey);
                LOBYTE(v68) = 40;
                PE_UpdateSystemKey(a1, dwValue, pszReturned, 3u, (CCmdString *)&ppv3, v28, &str3);
                free(*(void **)v35);
                free(a1a.m_String);
                free(szArg.m_String);
              }
              LOBYTE(v68) = 7;
              StringItem::~StringItem((tagPEStringStruct *)&a2a);
              v4 = v42;
            }
          }
          RegCloseKey(hKey);
        }
        v42 = ++v4;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v4, (CCmdString *)&lpSubKey) );
    }
    RegCloseKey(KeyHandle);
  }
  free(v51);
  free(v47.m_String);
  free(v46);
  free(v49);
  free(str3.m_String);
  free((void *)lpSubKey);
  free(ppv3);
  free(ppv.m_String);
  return pszReturned;
}

//----- (00BE2BC0) --------------------------------------------------------
void __stdcall sub_BE2BC0(void **a1, void **a2)
{
  void **i; // esi

  for ( i = a1; i != a2; ++i )
    free(*i);
}

//----- (00BE2BF0) --------------------------------------------------------
char *__cdecl sub_BE2BF0(int a1, int a2)
{
  int v2; // edi
  void **v3; // esi
  void **i; // ebx
  char *result; // eax

  if ( a1 != a2 )
  {
    v2 = a1 + 4;
    do
    {
      v3 = *(void ***)v2;
      if ( *(_DWORD *)v2 )
      {
        for ( i = *(void ***)(v2 + 4); v3 != i; ++v3 )
          free(*v3);
        operator delete(*(void **)v2);
        *(_DWORD *)v2 = 0;
        *(_DWORD *)(v2 + 4) = 0;
        *(_DWORD *)(v2 + 8) = 0;
      }
      free(*(void **)(v2 - 4));
      v2 += 16;
      result = (char *)(v2 - 4);
    }
    while ( v2 - 4 != a2 );
  }
  return result;
}

//----- (00BE2C60) --------------------------------------------------------
void __thiscall sub_BE2C60(int *this)
{
  int *v1; // esi

  v1 = this;
  if ( *this )
  {
    sub_BE2BF0(*this, this[1]);
    operator delete((void *)*v1);
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
  }
}

//----- (00BE2CB0) --------------------------------------------------------
void __cdecl sub_BE2CB0(int a1, void *a2, void *a3, LPCWSTR lpValueName)
{
  _WORD *v4; // ST58_4
  CCmdString *v5; // esi
  void *v6; // edi
  CCmdString *v7; // eax
  wchar_t *v8; // ST5C_4

  v4 = malloc(2u);
  *v4 = 0;
  v5 = (CCmdString *)a3;
  v6 = sub_BE2D60(a1, a2, *(wchar_t **)a3, lpValueName, (void *)0xFFFFFFFF);
  v7 = CCmdString::operator+((CCmdString *)&a3, v5, L"\\AutorunsDisabled");
  v8 = _wcsdup(v7->m_String);
  free(v4);
  free(a3);
  sub_BE2D60(a1, a2, v8, lpValueName, v6);
  free(v8);
}

//----- (00BE2D60) --------------------------------------------------------
void *__cdecl sub_BE2D60(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, void *a5)
{
  LPCWSTR v5; // ebx
  HKEY v6; // esi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  const wchar_t *v10; // eax
  CCmdString *v11; // esi
  CCmdString *v12; // eax
  unsigned int v13; // eax
  int v14; // edx
  wchar_t *v15; // ecx
  unsigned int v16; // edi
  int v17; // esi
  const wchar_t **v18; // eax
  WCHAR *v19; // esi
  const WCHAR **v20; // ecx
  const wchar_t *v21; // eax
  const WCHAR **v22; // eax
  const wchar_t *v23; // eax
  CCmdString *v24; // esi
  CCmdString *v25; // eax
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  const wchar_t *v29; // eax
  const wchar_t *v30; // eax
  CCmdString *v31; // esi
  CCmdString *v32; // eax
  const WCHAR **v33; // eax
  const wchar_t *v34; // eax
  CCmdString *v35; // eax
  WCHAR v37[2]; // [esp+10h] [ebp-A4h]
  WCHAR v38[2]; // [esp+14h] [ebp-A0h]
  WCHAR v39[2]; // [esp+18h] [ebp-9Ch]
  WCHAR v40[2]; // [esp+1Ch] [ebp-98h]
  int a2a; // [esp+20h] [ebp-94h]
  WCHAR v42[2]; // [esp+24h] [ebp-90h]
  int a8; // [esp+28h] [ebp-8Ch]
  void *v44; // [esp+2Ch] [ebp-88h]
  void *v45; // [esp+30h] [ebp-84h]
  LPCWSTR v46; // [esp+34h] [ebp-80h]
  HKEY hKey; // [esp+38h] [ebp-7Ch]
  WCHAR **ppv3; // [esp+3Ch] [ebp-78h]
  void *v49; // [esp+40h] [ebp-74h]
  LPCWSTR v50; // [esp+44h] [ebp-70h]
  void *v51; // [esp+48h] [ebp-6Ch]
  wchar_t *v52; // [esp+4Ch] [ebp-68h]
  int v53; // [esp+50h] [ebp-64h]
  int v54; // [esp+54h] [ebp-60h]
  void *v55; // [esp+58h] [ebp-5Ch]
  void *v56; // [esp+5Ch] [ebp-58h]
  void *v57; // [esp+60h] [ebp-54h]
  CCmdString ppv; // [esp+64h] [ebp-50h]
  CCmdString v59; // [esp+6Ch] [ebp-48h]
  WCHAR szArg[2]; // [esp+70h] [ebp-44h]
  void *a1a; // [esp+74h] [ebp-40h]
  void *v62; // [esp+78h] [ebp-3Ch]
  LPCWSTR v63; // [esp+7Ch] [ebp-38h]
  LPCWSTR szArg3; // [esp+80h] [ebp-34h]
  LPCWSTR szKeyName; // [esp+84h] [ebp-30h]
  LPCWSTR v66; // [esp+88h] [ebp-2Ch]
  LPCWSTR v67; // [esp+8Ch] [ebp-28h]
  LPCWSTR v68; // [esp+90h] [ebp-24h]
  LPCWSTR v69; // [esp+94h] [ebp-20h]
  LPCWSTR v70; // [esp+98h] [ebp-1Ch]
  LPCWSTR szArg4; // [esp+9Ch] [ebp-18h]
  WCHAR *pszText; // [esp+A0h] [ebp-14h]
  CCmdString str3; // [esp+A4h] [ebp-10h]
  int v74; // [esp+B0h] [ebp-4h]

  ppv.m_String = (WCHAR *)malloc(2u);
  *ppv.m_String = 0;
  v74 = 0;
  str3.m_String = (WCHAR *)malloc(2u);
  *str3.m_String = 0;
  v62 = malloc(2u);
  *(_WORD *)v62 = 0;
  v57 = malloc(2u);
  *(_WORD *)v57 = 0;
  v59.m_String = (WCHAR *)malloc(2u);
  *v59.m_String = 0;
  v5 = lpValueName;
  v6 = (HKEY)a2;
  LOBYTE(v74) = 4;
  if ( a5 == (void *)-1 )
  {
    v68 = _wcsdup((const wchar_t *)&gszNullString);
    v63 = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v67 = _wcsdup((const wchar_t *)&gszNullString);
    v69 = _wcsdup((const wchar_t *)&gszNullString);
    v70 = _wcsdup((const wchar_t *)&gszNullString);
    v7 = (const wchar_t *)&gszNullString;
    if ( lpValueName )
      v7 = lpValueName;
    szArg4 = _wcsdup(v7);
    v8 = (const wchar_t *)&gszNullString;
    if ( psz )
      v8 = psz;
    pszText = _wcsdup(v8);
    v9 = (const wchar_t *)&gszNullString;
    if ( lpValueName )
      v9 = lpValueName;
    v66 = _wcsdup(v9);
    v10 = (const wchar_t *)&gszNullString;
    if ( psz )
      v10 = psz;
    szArg3 = _wcsdup(v10);
    LOBYTE(v74) = 14;
    v11 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v74) = 15;
    v12 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v66);
    LOBYTE(v74) = 16;
    a5 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v12, v11, (CCmdString *)&v70);
    free(*(void **)szArg);
    free(a1a);
    free((void *)szArg3);
    free((void *)v66);
    free(pszText);
    free((void *)szArg4);
    free((void *)v70);
    free((void *)v69);
    free((void *)v67);
    free((void *)szKeyName);
    free((void *)v63);
    LOBYTE(v74) = 4;
    free((void *)v68);
    v6 = (HKEY)a2;
  }
  v13 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(v6, psz, 0, v13 | 0x20019, &hKey) )
  {
    if ( !PE_ReadRegKey(hKey, lpValueName, 0, 0, &ppv) )
    {
      v52 = 0;
      v53 = 0;
      v54 = 0;
      LOBYTE(v74) = 17;
      sub_BE6DD0(ppv.m_String, 44, (int)&v52, 32);
      v14 = v53;
      v15 = v52;
      v16 = 0;
      if ( (v53 - (signed int)v52) >> 4 )
      {
        v17 = 0;
        *(_DWORD *)szArg = 0;
        do
        {
          ppv3 = (WCHAR **)((char *)v15 + v17);
          v18 = (const wchar_t **)sub_BE4EE0((int)&v44, a1, (int)v15 + v17, 0);
          v19 = str3.m_String;
          str3.m_String = _wcsdup(*v18);
          free(v19);
          free(v44);
          a2a = sub_BE4ED0();
          v20 = &gszNullString;
          if ( v5 )
            v20 = (const WCHAR **)v5;
          v67 = _wcsdup((const wchar_t *)v20);
          v21 = (const wchar_t *)&gszNullString;
          if ( psz )
            v21 = psz;
          szKeyName = _wcsdup(v21);
          v22 = &gszNullString;
          if ( v5 )
            v22 = (const WCHAR **)v5;
          v63 = _wcsdup((const wchar_t *)v22);
          v23 = (const wchar_t *)&gszNullString;
          if ( psz )
            v23 = psz;
          v68 = _wcsdup(v23);
          LOBYTE(v74) = 21;
          v24 = MakeRegistryKeyName((CCmdString *)v42, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&v67);
          LOBYTE(v74) = 22;
          v25 = MakeRegistryKeyName((CCmdString *)v37, (HKEY)a2, (CCmdString *)&v68, (CCmdString *)&v63);
          LOBYTE(v74) = 23;
          v26 = sub_BE3D40(a1, (CCmdString)v25, (int)v24, (int)ppv3, (int)&str3, (int)&v62, (CCmdString)&v59, (int)&a8);
          free(*(void **)v37);
          free(*(void **)v42);
          free((void *)v68);
          free((void *)v63);
          free((void *)szKeyName);
          LOBYTE(v74) = 17;
          free((void *)v67);
          if ( v26 )
          {
            if ( a5 == (void *)-1 )
            {
              v45 = _wcsdup((const wchar_t *)&gszNullString);
              v49 = _wcsdup((const wchar_t *)&gszNullString);
              v56 = _wcsdup((const wchar_t *)&gszNullString);
              v51 = _wcsdup((const wchar_t *)&gszNullString);
              szArg3 = _wcsdup((const wchar_t *)&gszNullString);
              v66 = _wcsdup((const wchar_t *)&gszNullString);
              v5 = lpValueName;
              v27 = (const wchar_t *)&gszNullString;
              if ( lpValueName )
                v27 = lpValueName;
              pszText = _wcsdup(v27);
              v28 = (const wchar_t *)&gszNullString;
              if ( psz )
                v28 = psz;
              szArg4 = _wcsdup(v28);
              v29 = (const wchar_t *)&gszNullString;
              if ( lpValueName )
                v29 = lpValueName;
              v70 = _wcsdup(v29);
              v30 = (const wchar_t *)&gszNullString;
              if ( psz )
                v30 = psz;
              v69 = _wcsdup(v30);
              LOBYTE(v74) = 33;
              v31 = MakeRegistryKeyName((CCmdString *)v40, (HKEY)a2, (CCmdString *)&szArg4, (CCmdString *)&pszText);
              LOBYTE(v74) = 34;
              v32 = MakeRegistryKeyName((CCmdString *)v38, (HKEY)a2, (CCmdString *)&v69, (CCmdString *)&v70);
              LOBYTE(v74) = 35;
              a5 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v32, v31, (CCmdString *)&v66);
              free(*(void **)v38);
              free(*(void **)v40);
              free((void *)v69);
              free((void *)v70);
              free((void *)szArg4);
              free(pszText);
              free((void *)v66);
              free((void *)szArg3);
              free(v51);
              free(v56);
              free(v49);
              free(v45);
            }
            else
            {
              v5 = lpValueName;
            }
            a1a = _wcsdup((const wchar_t *)&gszNullString);
            v55 = _wcsdup((const wchar_t *)&gszNullString);
            v33 = &gszNullString;
            if ( v5 )
              v33 = (const WCHAR **)v5;
            v46 = _wcsdup((const wchar_t *)v33);
            v34 = (const wchar_t *)&gszNullString;
            if ( psz )
              v34 = psz;
            v50 = _wcsdup(v34);
            LOBYTE(v74) = 39;
            v35 = MakeRegistryKeyName((CCmdString *)v39, (HKEY)a2, (CCmdString *)&v50, (CCmdString *)&v46);
            LOBYTE(v74) = 40;
            PE_UpdateSystemKey(a1, a2a, a5, 5u, (CCmdString *)ppv3, v35, &str3);
            free(*(void **)v39);
            free((void *)v50);
            free((void *)v46);
            free(v55);
            LOBYTE(v74) = 17;
            free(a1a);
          }
          else
          {
            v5 = lpValueName;
          }
          v14 = v53;
          ++v16;
          v15 = v52;
          v17 = *(_DWORD *)szArg + 16;
          *(_DWORD *)szArg += 16;
        }
        while ( v16 < (v53 - (signed int)v52) >> 4 );
      }
      if ( v15 )
      {
        sub_BE2BF0((int)v15, v14);
        operator delete(v52);
      }
    }
    RegCloseKey(hKey);
  }
  free(v59.m_String);
  free(v57);
  free(v62);
  free(str3.m_String);
  free(ppv.m_String);
  return a5;
}

//----- (00BE3440) --------------------------------------------------------
int __cdecl sub_BE3440(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // edi
  int v8; // [esp+0h] [ebp-24h]
  tagPEStringStruct *v9; // [esp+10h] [ebp-14h]
  int *v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+20h] [ebp-4h]

  v10 = &v8;
  v3 = a3;
  v4 = a1;
  v9 = (tagPEStringStruct *)a3;
  v11 = 0;
  while ( v4 != a2 )
  {
    if ( v3 )
    {
      *(_DWORD *)v3 = _wcsdup(*(const wchar_t **)v4);
      LOBYTE(v11) = 2;
      sub_BE35A0((StringItem *)(v3 + 4), (const wchar_t ***)(v4 + 4));
    }
    v3 += 16;
    LOBYTE(v11) = 0;
    v4 += 16;
  }
  return v3;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00BE34F0) --------------------------------------------------------
wchar_t **__cdecl sub_BE34F0(std__vector *a1, const wchar_t **a2, wchar_t **a3)
{
  const wchar_t **v3; // esi
  wchar_t **v4; // edi

  v3 = (const wchar_t **)a1;
  if ( a1 == (std__vector *)a2 )
    return a3;
  v4 = a3;
  do
  {
    if ( v4 )
      *v4 = _wcsdup(*v3);
    ++v3;
    ++v4;
  }
  while ( v3 != a2 );
  return v4;
}

//----- (00BE3530) --------------------------------------------------------
_DWORD *__thiscall sub_BE3530(void *this, void *a2)
{
  _DWORD *v2; // edi

  v2 = this;
  *((_DWORD *)this + 5) = 7;
  *((_DWORD *)this + 4) = 0;
  *(_WORD *)this = 0;
  if ( *((_DWORD *)a2 + 5) >= 8u )
  {
    *(_DWORD *)this = *(_DWORD *)a2;
    *(_DWORD *)a2 = 0;
  }
  else if ( *((_DWORD *)a2 + 4) != -1 )
  {
    memmove(this, a2, 2 * (*((_DWORD *)a2 + 4) + 1));
  }
  v2[4] = *((_DWORD *)a2 + 4);
  v2[5] = *((_DWORD *)a2 + 5);
  *((_DWORD *)a2 + 5) = 7;
  *((_DWORD *)a2 + 4) = 0;
  *(_WORD *)a2 = 0;
  return v2;
}

//----- (00BE35A0) --------------------------------------------------------
wchar_t ***__thiscall sub_BE35A0(StringItem *this, const wchar_t ***a2)
{
  StringItem *v2; // esi
  const wchar_t ***v3; // edi
  int v5; // [esp+0h] [ebp-24h]
  StringItem *v6; // [esp+10h] [ebp-14h]
  int *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v7 = &v5;
  v2 = this;
  v6 = this;
  v3 = a2;
  this->strText = 0;
  this->arrTexts.baseclass_0._Mypair._Myval2._Myfirst = 0;
  this->arrTexts.baseclass_0._Mypair._Myval2._Mylast = 0;
  if ( sub_BEF930(this, v3[1] - *v3) )
  {
    v8 = 0;
    v2->arrTexts.baseclass_0._Mypair._Myval2._Myfirst = sub_BE34F0((std__vector *)*v3, v3[1], (wchar_t **)v2->strText);
  }
  return (wchar_t ***)v2;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00BE3650) --------------------------------------------------------
BSTR *__thiscall _bstr_t::Data_t::Data_t(Data_t_bstr_t *this, _bstr_t *a2, _bstr_t *a3)
{
  Data_t_bstr_t *v3; // ebx
  OLECHAR *v4; // eax
  UINT v5; // edi
  OLECHAR *v6; // eax
  UINT v7; // esi
  unsigned int v8; // ecx
  BSTR v9; // edx
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // eax
  int v13; // [esp+Ch] [ebp-8h]

  v3 = this;
  this->m_str = 0;
  this->m_RefCount = 1;
  if ( a2->m_Data && (v4 = a2->m_Data->m_wstr) != 0 )
    v5 = SysStringLen(v4);
  else
    v5 = 0;
  if ( a3->m_Data && (v6 = a3->m_Data->m_wstr) != 0 )
    v7 = SysStringLen(v6);
  else
    v7 = 0;
  v8 = v7 + v5;
  if ( v7 + v5 < v7 || !is_mul_ok(2u, v8) || 2 * v8 > 0xFFFFFFFF )
LABEL_22:
    _com_issue_error(E_OUTOFMEMORY);
  v13 = 2 * v8;
  v9 = SysAllocStringByteLen(0, 2 * v8);
  v3->m_wstr = v9;
  if ( v9 )
  {
    v10 = a2->m_Data;
    if ( a2->m_Data && v10->m_wstr )
      memcpy_s(v9, v13 + 2, v10->m_wstr, 2 * v5 + 2);
    v11 = a3->m_Data;
    if ( a3->m_Data && v11->m_wstr )
      memcpy_s(&v3->m_wstr[v5], 2 * v7 + 2, v11->m_wstr, 2 * v7 + 2);
  }
  else if ( v7 + v5 )
  {
    goto LABEL_22;
  }
  return (BSTR *)v3;
}

//----- (00BE3750) --------------------------------------------------------
void __thiscall sub_BE3750(void *this)
{
  _DWORD *v1; // esi
  _WORD *v2; // eax

  v1 = this;
  v2 = malloc(2u);
  v1[4] = v2;
  *v2 = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
}

//----- (00BE3780) --------------------------------------------------------
BSTR **__thiscall _bstr_t::_bstr_t(tagEventSetItem *this, OLECHAR *psz)
{
  tagEventSetItem *v2; // edi
  BSTR *v3; // eax
  BSTR *v4; // esi
  BSTR v5; // eax

  v2 = this;
  v3 = (BSTR *)operator new(0xCu);
  v4 = v3;
  if ( v3 )
  {
    v3[1] = 0;
    v3[2] = (BSTR)1;
    v5 = SysAllocString(psz);
    *v4 = v5;
    if ( !v5 && psz )
      _com_issue_error(-2147024882);
  }
  else
  {
    v4 = 0;
  }
  v2->bstrName = (int)v4;
  if ( !v4 )
    _com_issue_error(-2147024882);
  return (BSTR **)v2;
}

//----- (00BE3820) --------------------------------------------------------
int __thiscall sub_BE3820(int this)
{
  int v1; // esi
  int result; // eax

  v1 = this;
  if ( *(_DWORD *)(this + 20) >= 8u )
    operator delete(*(void **)this);
  *(_DWORD *)(v1 + 20) = 7;
  result = 0;
  *(_DWORD *)(v1 + 16) = 0;
  *(_WORD *)v1 = 0;
  return result;
}

//----- (00BE3850) --------------------------------------------------------
void __thiscall sub_BE3850(void *this)
{
  void *v1; // esi

  v1 = this;
  if ( *((_DWORD *)this + 5) )
  {
    operator delete(*((void **)this + 5));
    *((_DWORD *)v1 + 5) = 0;
    *((_DWORD *)v1 + 6) = 0;
    *((_DWORD *)v1 + 7) = 0;
  }
  free(*((void **)v1 + 4));
}

//----- (00BE3890) --------------------------------------------------------
void __thiscall _bstr_t::_Free(_bstr_t *this)
{
  _bstr_t *v1; // edi
  Data_t_bstr_t *v2; // esi

  v1 = this;
  v2 = this->m_Data;
  if ( this->m_Data )
  {
    if ( !InterlockedDecrement(&v2->m_RefCount) && v2 )
    {
      if ( v2->m_wstr )
      {
        SysFreeString(v2->m_wstr);
        v2->m_wstr = 0;
      }
      if ( v2->m_str )
      {
        operator delete[](v2->m_str);
        v2->m_str = 0;
      }
      operator delete(v2);
    }
    v1->m_Data = 0;
  }
}

//----- (00BE38F0) --------------------------------------------------------
std__vector *__thiscall sub_BE38F0(std__vector *this, const wchar_t ***a2)
{
  std__vector *v2; // edi
  const wchar_t ***v3; // ebx
  const wchar_t **v4; // esi
  const wchar_t **v5; // eax
  StringItem *v6; // ecx
  unsigned int v7; // edx
  void **v8; // esi
  void **v9; // ebx
  wchar_t **v10; // eax
  const wchar_t **v12; // esi
  int v13; // [esp+0h] [ebp-28h]
  StringItem *v14; // [esp+10h] [ebp-18h]
  unsigned int v15; // [esp+14h] [ebp-14h]
  int *v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+24h] [ebp-4h]

  v16 = &v13;
  v2 = this;
  v14 = (StringItem *)this;
  v3 = a2;
  if ( this != (std__vector *)a2 )
  {
    v4 = *a2;
    v5 = a2[1];
    if ( *a2 == v5 )
    {
      sub_BF0010(this);
      return v2;
    }
    v6 = (StringItem *)this->baseclass_0._Mypair._Myval2._Myfirst;
    v7 = v5 - v4;
    v15 = (_DWORD)(v2->baseclass_0._Mypair._Myval2._Mylast - v2->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( v7 <= v15 )
    {
      v8 = (void **)sub_C04700((int)v4, a2[1], v6);
      if ( v8 != v2->baseclass_0._Mypair._Myval2._Mylast )
      {
        v9 = (void **)v2->baseclass_0._Mypair._Myval2._Mylast;
        do
        {
          free(*v8);
          ++v8;
        }
        while ( v8 != v9 );
        v3 = a2;
      }
      v10 = (wchar_t **)((char *)v2->baseclass_0._Mypair._Myval2._Myfirst + 4 * (v3[1] - *v3));
      goto LABEL_10;
    }
    if ( v7 <= (_DWORD)(v2->baseclass_0._Mypair._Myval2._Myend - (void *)v6) >> 2 )
    {
      v12 = &v4[v15];
      sub_C04700((int)*a2, v12, v6);
      v10 = sub_BE34F0((std__vector *)v12, v3[1], (wchar_t **)v2->baseclass_0._Mypair._Myval2._Mylast);
LABEL_10:
      v2->baseclass_0._Mypair._Myval2._Mylast = v10;
      return v2;
    }
    if ( v6 )
    {
      sub_BE2BC0((void **)v6, (void **)v2->baseclass_0._Mypair._Myval2._Mylast);
      operator delete(v2->baseclass_0._Mypair._Myval2._Myfirst);
    }
    if ( sub_BEF930((StringItem *)v2, v3[1] - *v3) )
    {
      v17 = 0;
      v10 = sub_BE34F0((std__vector *)*v3, v3[1], (wchar_t **)v2->baseclass_0._Mypair._Myval2._Myfirst);
      goto LABEL_10;
    }
  }
  return v2;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00BE3A50) --------------------------------------------------------
_bstr_t *__thiscall _bstr_t::operator=(_bstr_t *this, _bstr_t *a2)
{
  _bstr_t *v2; // esi
  Data_t_bstr_t *v3; // eax

  v2 = this;
  if ( this != a2 )
  {
    _bstr_t::_Free(this);
    v3 = a2->m_Data;
    v2->m_Data = a2->m_Data;
    if ( v3 )
      InterlockedIncrement(&v3->m_RefCount);
  }
  return v2;
}

//----- (00BE3A80) --------------------------------------------------------
EventItem *__thiscall _bstr_t::operator=(EventItem *this, OLECHAR *psz)
{
  EventItem *v2; // edi
  OLECHAR *v3; // eax
  Data_t_bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  BSTR v6; // eax

  v2 = this;
  // ??4_bstr_t@@QAEAAV0@PB_W@Z
  if ( !psz || (!this->strEventTrace.m_Data ? (v3 = 0) : (v3 = this->strEventTrace.m_Data->m_wstr), v3 != psz) )
  {
    _bstr_t::_Free(&this->strEventTrace);
    v4 = (Data_t_bstr_t *)operator new(0xCu);
    v5 = v4;
    if ( v4 )
    {
      v4->m_str = 0;
      v4->m_RefCount = 1;
      v6 = SysAllocString(psz);
      v5->m_wstr = v6;
      if ( !v6 && psz )
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
      v5 = 0;
    }
    v2->strEventTrace.m_Data = v5;
    if ( !v5 )
      _com_issue_error(E_OUTOFMEMORY);
  }
  return v2;
}

//----- (00BE3B40) --------------------------------------------------------
int __thiscall tagPEConfigFile::GetFileName(tagPEConfigFile *this)
{
  int result; // eax

  if ( this->pszConfigName )
    result = *(_DWORD *)this->pszConfigName;
  else
    result = 0;
  return result;
}

//----- (00BE3B50) --------------------------------------------------------
_bstr_t *__cdecl _bstr_t::operator+(_bstr_t *a1, OLECHAR *psz, _bstr_t *a2)
{
  _bstr_t::_bstr_t((tagEventSetItem *)a1, psz);
  _bstr_t::operator+=(a1, a2);
  return a1;
}

//----- (00BE3BC0) --------------------------------------------------------
// _bstr_t bstrResult = bstrConfigFile + bstrDisabled;
_bstr_t *__thiscall _bstr_t::operator+(_bstr_t *this, _bstr_t *bstrRet, _bstr_t *a3)
{
  _bstr_t v3; // eax

  v3.m_Data = this->m_Data;
  bstrRet->m_Data = this->m_Data;
  if ( v3.m_Data )
    InterlockedIncrement(&v3.m_Data->m_RefCount);
  _bstr_t::operator+=(bstrRet, a3);
  return bstrRet;
}

//----- (00BE3C30) --------------------------------------------------------
BOOL __thiscall _bstr_t::operator!=(_bstr_t *this, _bstr_t *a2)
{
  Data_t_bstr_t *v2; // ecx
  Data_t_bstr_t *v3; // eax
  OLECHAR *v5; // eax

  v2 = this->m_Data;
  v3 = a2->m_Data;
  if ( v2 == a2->m_Data )
    return 0;
  if ( !v2 )
  {
    if ( v3 )
    {
      v5 = v3->m_wstr;
      if ( v5 )
      {
        if ( SysStringLen(v5) )
          return 1;
      }
    }
    return 0;
  }
  if ( v3 )
    return _bstr_t::Data_t::Compare(v2, a2->m_Data) < 0;
  if ( !v2->m_wstr || !SysStringLen(v2->m_wstr) )
    return 0;
  return 0;
}

//----- (00BE3CB0) --------------------------------------------------------
// inline _bstr_t& _bstr_t::operator+=(const _bstr_t& s)
OLECHAR ***__thiscall _bstr_t::operator+=(_bstr_t *this, _bstr_t *a2)
{
  _bstr_t *v2; // esi
  Data_t_bstr_t *v3; // eax
  BSTR *v4; // edi

  v2 = this;
  v3 = (Data_t_bstr_t *)operator new(0xCu);
  if ( v3 )
    v4 = _bstr_t::Data_t::Data_t(v3, v2, a2);
  else
    v4 = 0;
  if ( !v4 )
    _com_issue_error(E_OUTOFMEMORY);
  _bstr_t::_Free(v2);
  v2->m_Data = (Data_t_bstr_t *)v4;
  return (OLECHAR ***)v2;
}

//----- (00BE3D40) --------------------------------------------------------
int __cdecl sub_BE3D40(int a1, CCmdString a2, int a3, int a4, int a5, int a6, CCmdString ppv3, int a8)
{
  const wchar_t **v8; // esi
  int result; // eax
  void *v10; // esi
  WCHAR *v11; // eax
  WCHAR *v12; // edi
  const wchar_t *v13; // eax
  wchar_t *v14; // eax
  int v15; // eax
  CCmdString *v16; // esi
  CCmdString *v17; // eax
  const wchar_t *v18; // edi
  const wchar_t *v19; // ecx
  WCHAR **v20; // esi
  WCHAR **v21; // esi
  CCmdString *v22; // eax
  wchar_t *v23; // ST14_4
  WCHAR *v24; // ST10_4
  wchar_t *v25; // eax
  WCHAR *v26; // eax
  WCHAR *v27; // esi
  CCmdString *v28; // eax
  int v29; // [esp+10h] [ebp-84h]
  OLECHAR **v30; // [esp+14h] [ebp-80h]
  int v31; // [esp+18h] [ebp-7Ch]
  OLECHAR **v32; // [esp+1Ch] [ebp-78h]
  CCmdString strText; // [esp+20h] [ebp-74h]
  OLECHAR **v34; // [esp+24h] [ebp-70h]
  CCmdString ppv1; // [esp+28h] [ebp-6Ch]
  CCmdString ppv2; // [esp+2Ch] [ebp-68h]
  WCHAR **ppszText2; // [esp+30h] [ebp-64h]
  wchar_t *v38; // [esp+34h] [ebp-60h]
  int v39; // [esp+90h] [ebp-4h]

  v8 = (const wchar_t **)a5;
  v30 = (OLECHAR **)a3;
  v32 = (OLECHAR **)a4;
  v34 = (OLECHAR **)a5;
  ppszText2 = (WCHAR **)a6;
  v31 = a8;
  *(_DWORD *)a8 = 0;
  v29 = 20;
  if ( gbFlagsInPE_GetLongPathName )
    ExitThread(0);
  result = _wcsicmp(*(const wchar_t **)a2.m_String, L"desktop.ini");
  if ( !result )
  {
    LOBYTE(result) = 0;
    return result;
  }
  if ( dword_CD3858 )
  {
    v10 = *(void **)ppv3.m_String;
    *(_DWORD *)ppv3.m_String = _wcsdup(*(const wchar_t **)a6);
    free(v10);
    v11 = (WCHAR *)malloc(2u);
    v12 = v11;
    strText.m_String = v11;
    *v11 = 0;
    v39 = 0;
    v13 = (const wchar_t *)&gszNullString;
    if ( *v34 )
      v13 = *v34;
    v14 = _wcsdup(v13);
    v15 = sub_C01290(v14, (int)ppv3.m_String);
    if ( v15 != 2 )
    {
      if ( v15 )
      {
        if ( !**(_WORD **)ppv3.m_String )
          goto LABEL_24;
        v26 = _wcsdup(L"(Not Verified) ");
      }
      else
      {
        v26 = _wcsdup(L"(Verified) ");
      }
      v27 = v26;
      ppv2.m_String = v26;
      v28 = CCmdString::Append(&ppv1, &ppv2, (CCmdString *)ppv3.m_String);
      CCmdString::Reset((CCmdString *)ppv3.m_String, v28);
      free(ppv1.m_String);
      free(v27);
      goto LABEL_24;
    }
    ppv2.m_String = (WCHAR *)sub_BE6700(*v34, 0, 0, (int)&v38, (int)&v29, 0);
    if ( ppv2.m_String )
    {
      v16 = (CCmdString *)ppszText2;
      if ( !**ppszText2 )
      {
LABEL_18:
        v23 = _wcsdup(v12);
        v24 = ppv2.m_String;
        v25 = _wcsdup(*v34);
        sub_C011B0(v25, (int)v24, v23);
LABEL_24:
        v39 = -1;
        free(v12);
        v8 = (const wchar_t **)v34;
        goto LABEL_25;
      }
      CCmdString::Reset(&strText, (CCmdString *)ppszText2);
      v17 = operator+((CCmdString *)&ppszText2, L"(Not verified) ", v16);
      CCmdString::Reset((CCmdString *)ppv3.m_String, v17);
      free(ppszText2);
    }
    else
    {
      v18 = (const wchar_t *)&gszNullString;
      v19 = (const wchar_t *)&gszNullString;
      if ( v38 )
        v19 = v38;
      v20 = (WCHAR **)_wcsdup(v19);
      ppszText2 = v20;
      CCmdString::Reset(&strText, (CCmdString *)&ppszText2);
      free(v20);
      if ( v38 )
        v18 = v38;
      v21 = (WCHAR **)_wcsdup(v18);
      ppszText2 = v21;
      v22 = operator+(&ppv1, L"(Verified) ", (CCmdString *)&ppszText2);
      CCmdString::Reset((CCmdString *)ppv3.m_String, v22);
      free(ppv1.m_String);
      free(v21);
    }
    v12 = strText.m_String;
    goto LABEL_18;
  }
LABEL_25:
  if ( dword_CD48D4 )
  {
    result = wcsncmp(*v8, L"File not found: ", 0x10u);
    if ( result )
      sub_C01590(1, v31, *v30, *v32, (OLECHAR *)*v8, 0);
  }
  LOBYTE(result) = 1;
  return result;
}
// CD3858: using guessed type int dword_CD3858;
// CD3860: using guessed type char gbFlagsInPE_GetLongPathName;
// CD48D4: using guessed type int dword_CD48D4;

//----- (00BE3FF0) --------------------------------------------------------
int __cdecl PE_UpdateSystemKey(int a1, DWORD dwValue, HANDLE Handle, DWORD dwFlags, CCmdString *strText, CCmdString *strId, CCmdString *strValue)
{
  CCmdString strTemp; // edi
  CCmdString *v8; // eax
  OLECHAR *v9; // esi
  OLECHAR *v10; // ecx
  int result; // eax
  WCHAR *v12; // esi

  if ( !(dword_CD4C48 & 1) )
  {
    dword_CD4C48 |= 1u;
    sStringInPE_UpdateSystemKey.m_String = (WCHAR *)malloc(2u);
    *sStringInPE_UpdateSystemKey.m_String = 0;
    atexit(sub_C9A2E0);
  }
  if ( Handle == (HANDLE)-1 )
  {
    v12 = sStringInPE_UpdateSystemKey.m_String;
    sStringInPE_UpdateSystemKey.m_String = _wcsdup(strText->m_String);
    free(v12);
    result = 0;
  }
  else
  {
    strTemp.m_String = (WCHAR *)malloc(2u);
    *strTemp.m_String = 0;
    if ( dwFlags == 9 )
    {
      v8 = CCmdString::Append((CCmdString *)&Handle, &sStringInPE_UpdateSystemKey, strText);
      v9 = _wcsdup(v8->m_String);
      free(strTemp.m_String);
      free(Handle);
    }
    else
    {
      v9 = _wcsdup(strId->m_String);
      free(strTemp.m_String);
    }
    if ( gdwFlagsInLoadServiceRegistry == 1 )
    {
      v10 = L"System";
    }
    else if ( gpAccountInfo )
    {
      v10 = gpAccountInfo->szReferenceName;
    }
    else
    {
      v10 = L"Local System";
    }
    PE_UpdateKey(v10, strValue->m_String, v9);
    free(v9);
    result = 0;
  }
  return result;
}
// C9D5D8: using guessed type wchar_t aLocalSystem[13];
// CD31C0: using guessed type int gdwFlagsInLoadServiceRegistry;
// CD4C48: using guessed type int dword_CD4C48;

//----- (00BE4130) --------------------------------------------------------
void __cdecl LoadSystemAccountInfo(HWND hWnd)
{
  HANDLE v1; // eax
  HMENU v2; // eax
  tagAccountInfo *pAccountInfo; // eax
  WCHAR *pszUserName_1; // edx
  tagAccountInfo *v5; // ebx
  WCHAR *v6; // esi
  WCHAR v7; // cx
  const wchar_t *v8; // ecx
  int v9; // edi
  wchar_t v10; // ax
  HWND v11; // edi
  UINT v12; // ST14_4
  HMENU v13; // eax
  HMENU v14; // eax
  unsigned int dwMode; // eax
  char *dwIndex; // ebx
  LSTATUS (__stdcall *RegQueryValueExW)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // edi
  WCHAR *pszDefaultUserName; // esi
  unsigned int dwMode_1; // eax
  PSID pSID; // ebx
  tagAccountInfo *pInfo; // eax
  tagAccountInfo *pInfo_1; // esi
  WCHAR *szDefaultUserName_1; // ecx
  WCHAR *szUserName; // edx
  WCHAR chText; // ax
  UINT_PTR v26; // ST14_4
  HMENU v27; // eax
  HMENU v28; // eax
  DWORD cchName; // [esp+10h] [ebp-1458h]
  DWORD ReturnLength; // [esp+14h] [ebp-1454h]
  BYTE Data; // [esp+18h] [ebp-1450h]
  enum _SID_NAME_USE nUse; // [esp+1Ch] [ebp-144Ch]
  DWORD cbSid; // [esp+20h] [ebp-1448h]
  HKEY hKey; // [esp+24h] [ebp-1444h]
  HANDLE TokenHandle; // [esp+28h] [ebp-1440h]
  DWORD cbDomainName; // [esp+2Ch] [ebp-143Ch]
  DWORD cbData; // [esp+30h] [ebp-1438h]
  unsigned int pInfo_2; // [esp+34h] [ebp-1434h]
  HWND hWnd1; // [esp+38h] [ebp-1430h]
  HKEY hSubKey; // [esp+3Ch] [ebp-142Ch]
  PSID pSid; // [esp+40h] [ebp-1428h]
  CCmdString szDefaultUserName; // [esp+44h] [ebp-1424h]
  int TokenInformation[1024]; // [esp+48h] [ebp-1420h]
  WCHAR szName[260]; // [esp+1048h] [ebp-420h]
  WCHAR szDomainName[260]; // [esp+1250h] [ebp-218h]
  int v46; // [esp+1464h] [ebp-4h]

  hWnd1 = hWnd;
  szDefaultUserName.m_String = (WCHAR *)malloc(2u);
  *szDefaultUserName.m_String = 0;
  v46 = 0;
  v1 = GetCurrentProcess();
  if ( !OpenProcessToken(v1, TOKEN_QUERY, &TokenHandle) )
  {
LABEL_4:
    if ( hWnd )
    {
      v2 = GetMenu(hWnd);
LABEL_42:
      DeleteMenu(v2, 3u, MF_BYPOSITION);
      goto __quit;
    }
    goto __quit;
  }
  ReturnLength = 4096;
  if ( !GetTokenInformation(TokenHandle, TokenUser, TokenInformation, 0x1000u, &ReturnLength) )
  {
    CloseHandle(TokenHandle);
    goto LABEL_4;
  }
  CloseHandle(TokenHandle);
  cbSid = 0;
  LookupAccountNameW(0, L"System", 0, &cbSid, szDomainName, &cbDomainName, &nUse);
  pSid = malloc(cbSid);
  LookupAccountNameW(0, L"System", pSid, &cbSid, szDomainName, &cbDomainName, &nUse);
  pAccountInfo = (tagAccountInfo *)malloc(1568u);
  pszUserName_1 = szDefaultUserName.m_String;
  v5 = pAccountInfo;
  pInfo_2 = (unsigned int)pAccountInfo;
  v6 = pAccountInfo->szUserName;
  do
  {
    v7 = *pszUserName_1;
    ++pszUserName_1;
    *v6 = v7;
    ++v6;
  }
  while ( v7 );
  v8 = L".Default";
  v9 = (char *)pAccountInfo->szUserName - (char *)L".Default";
  do
  {
    v10 = *v8;
    ++v8;
    *(const wchar_t *)((char *)v8 + v9 - 2) = v10;
  }
  while ( v10 );
  v5->nMenuID = (_DWORD)(garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
                       - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  _swprintf(v5->szReferenceName, L"%s\\%s", L"NT AUTHORITY", L"SYSTEM");
  v11 = hWnd1;
  if ( hWnd1 )
  {
    v12 = v5->nMenuID;
    v13 = GetMenu(hWnd1);
    v14 = GetSubMenu(v13, 3);
    InsertMenuW(v14, 0xFFFFFFFF, MF_BYPOSITION, v12, v5->szReferenceName);
  }
  if ( EqualSid(pSid, (PSID)TokenInformation[0]) )
  {
    LOBYTE(v5->bIsSystemUser) = 1;
    gpAccountInfo = v5;
  }
  else
  {
    LOBYTE(v5->bIsSystemUser) = 0;
  }
  _swprintf(v5->szProfileImgPath, L"%s\\%s", &gSystemDirInfo, L"Config");
  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(
    &garrAccountInfo,
    (tagAccountInfo *)&pInfo_2);
  dwMode = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(
          ghLocalMachineKey,
          L"Software\\Microsoft\\Windows NT\\CurrentVersion\\ProfileList",
          0,
          dwMode | KEY_READ,
          &hSubKey) )
  {
    dwIndex = 0;
    pSid = 0;
    if ( !PE_LoadRegKeys(hSubKey, 0, &szDefaultUserName) )
    {
      RegQueryValueExW = ::RegQueryValueExW;
      do
      {
        pszDefaultUserName = szDefaultUserName.m_String;
        dwMode_1 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hSubKey, pszDefaultUserName, 0, dwMode_1 | KEY_READ, &hKey) )
        {
          cbData = 4;
          if ( !RegQueryValueExW(hKey, L"Flags", 0, 0, &Data, &cbData) && !(Data & 8) )
          {
            pSID = GetUserSID(szDefaultUserName.m_String);
            if ( pSID )
            {
              cchName = 260;
              cbDomainName = 260;
              if ( LookupAccountSidW(0, pSID, szName, &cchName, szDomainName, &cbDomainName, &nUse) )
              {
                pInfo = (tagAccountInfo *)malloc(0x620u);
                cbData = 520;
                pInfo_1 = pInfo;
                pInfo_2 = (unsigned int)pInfo;
                if ( RegQueryValueExW(hKey, L"ProfileImagePath", 0, 0, (LPBYTE)pInfo->szProfileImgPath, &cbData) )
                {
                  free(pInfo_1);
                }
                else
                {
                  szDefaultUserName_1 = szDefaultUserName.m_String;
                  szUserName = pInfo_1->szUserName;
                  do
                  {
                    chText = *szDefaultUserName_1;
                    ++szDefaultUserName_1;
                    *szUserName = chText;
                    ++szUserName;
                  }
                  while ( chText );
                  pInfo_1->nMenuID = (_DWORD)(garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
                                            - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
                  _swprintf(pInfo_1->szReferenceName, L"%s\\%s", szDomainName, szName);
                  if ( hWnd1 )
                  {
                    v26 = pInfo_1->nMenuID;
                    v27 = GetMenu(hWnd1);
                    v28 = GetSubMenu(v27, 3);
                    InsertMenuW(v28, 0xFFFFFFFF, MF_BYPOSITION, v26, pInfo_1->szReferenceName);
                  }
                  if ( EqualSid(pSID, (PSID)TokenInformation[0]) )
                  {
                    LOBYTE(pInfo_1->bIsSystemUser) = 1;
                    gpAccountInfo = pInfo_1;
                  }
                  else
                  {
                    LOBYTE(pInfo_1->bIsSystemUser) = 0;
                  }
                  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(
                    &garrAccountInfo,
                    (tagAccountInfo *)&pInfo_2);
                  RegQueryValueExW = ::RegQueryValueExW;
                }
              }
              FreeSid(pSID);
            }
            dwIndex = (char *)pSid;
          }
          RegCloseKey(hKey);
        }
        pSid = ++dwIndex;
      }
      while ( !PE_LoadRegKeys(hSubKey, (DWORD)dwIndex, &szDefaultUserName) );
      v11 = hWnd1;
    }
    RegCloseKey(hSubKey);
  }
  if ( !TmAdjustPrivilege(L"SeRestorePrivilege") )
  {
    if ( v11 )
    {
      v2 = GetMenu(v11);
      goto LABEL_42;
    }
__quit:
    gbRestorePrivilegeFailed = 1;
  }
  free(szDefaultUserName.m_String);
}
// C9CA8C: using guessed type wchar_t aSystem_0[7];
// CA1FCC: using guessed type wchar_t aDefault[9];
// CA1FE0: using guessed type wchar_t aNtAuthority[13];
// CA2008: using guessed type wchar_t aConfig[7];
// CD31CA: using guessed type char gbRestorePrivilegeFailed;

//----- (00BE4650) --------------------------------------------------------
char BackendThreadProc()
{
  CCmdString *v0; // eax
  WCHAR *v1; // esi
  tagAccountInfo **pBuffer; // ecx
  unsigned int index; // esi
  unsigned int nCount; // eax
  WCHAR *ppstr; // [esp+4h] [ebp-4h]

  InitApis();
  gdwTlsIndex = TlsAlloc();
  TlsSetValue(gdwTlsIndex, 0);
  InitSystemPath();
  v0 = RequerySystemEnvironmentString((CCmdString *)&ppstr, (CCmdString *)L"%PATH%");
  v1 = (WCHAR *)gpszSystemPathInfo;
  gpszSystemPathInfo = _wcsdup(v0->m_String);
  free(v1);
  free(ppstr);
  InitializeCriticalSection(&gSystemDirInfo.Lock);
  AdjustRighToWinLogon();
  LoadSystemAccountInfo(0);
  LoadServiceRegistry(0xFFFFFFFF, 1u);
  LoadServiceRegistry(0xFFFFFFFF, 0);
  pBuffer = (tagAccountInfo **)garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
  index = 0;
  nCount = (_DWORD)(garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
                  - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  if ( nCount )
  {
    do
    {
      LOBYTE(nCount) = UpdateMenuItemWithAccountInfo(0, gpAccountInfo, pBuffer[index]->nMenuID);
      if ( !(_BYTE)nCount )
        break;
      LoadServiceRegistry(0xFFFFFFFF, 0);
      ++index;
      pBuffer = (tagAccountInfo **)garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
      nCount = (_DWORD)(garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
                      - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    }
    while ( index < nCount );
  }
  return nCount;
}

//----- (00BE4730) --------------------------------------------------------
int __thiscall _bstr_t::Data_t::Compare(Data_t_bstr_t *this, Data_t_bstr_t *str)
{
  Data_t_bstr_t *v2; // ebx
  UINT l2; // eax
  WCHAR *bstr1; // esi
  Data_t_bstr_t *v5; // edx
  UINT v6; // eax
  UINT len; // ecx
  WCHAR *bstr2; // edi
  WCHAR *v9; // edx
  int result; // eax
  UINT l1; // [esp+Ch] [ebp-4h]
  Data_t_bstr_t *stra; // [esp+18h] [ebp+8h]

  v2 = this;
  l1 = SysStringLen(this->m_wstr);
  l2 = SysStringLen(str->m_wstr);
  bstr1 = v2->m_wstr;
  v5 = (Data_t_bstr_t *)l2;
  v6 = l1;
  len = l1;
  bstr2 = str->m_wstr;
  stra = v5;
  if ( l1 > (unsigned int)v5 )
    len = (UINT)v5;
  if ( len )
  {
    while ( 1 )
    {
      LOWORD(v9) = *bstr1;
      ++bstr2;
      ++bstr1;
      --len;
      if ( (_WORD)v9 != *(bstr2 - 1) )
        break;
      if ( !len )
      {
        v5 = stra;
        v6 = l1;
        goto LABEL_7;
      }
    }
    result = *(bstr1 - 1) - *(bstr2 - 1);
  }
  else
  {
LABEL_7:
    if ( v6 >= (unsigned int)v5 )
      result = l1 != (_DWORD)v5;
    else
      result = -1;
  }
  return result;
}

//----- (00BE47C0) --------------------------------------------------------
errno_t __cdecl wcscpy_s(wchar_t *Src, wchar_t *Dst, rsize_t SizeInWords)
{
  return wcscpy_s(Dst, SizeInWords, Src);
}

//----- (00BE47E0) --------------------------------------------------------
BOOL __cdecl TmAdjustPrivilege(LPCWSTR lpszName)
{
  HANDLE ProcessHandle; // eax
  BOOL Ret; // esi
  struct _LUID Luid; // [esp+4h] [ebp-20h]
  HANDLE TokenHandle; // [esp+Ch] [ebp-18h]
  struct _TOKEN_PRIVILEGES Privileges; // [esp+10h] [ebp-14h]

  ProcessHandle = GetCurrentProcess();
  if ( !OpenProcessToken(ProcessHandle, 0x28u, &TokenHandle) || !LookupPrivilegeValueW(0, lpszName, &Luid) )
    return 0;
  Privileges.Privileges[0].Luid = Luid;
  Privileges.PrivilegeCount = 1;
  Privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
  Ret = AdjustTokenPrivileges(TokenHandle, FALSE, &Privileges, sizeof(_TOKEN_PRIVILEGES), 0, 0);
  if ( Ret )
  {
    if ( GetLastError() )
      Ret = 0;
  }
  CloseHandle(TokenHandle);
  return Ret;
}

//----- (00BE4890) --------------------------------------------------------
int __cdecl sub_BE4890(int a1, wchar_t *a2)
{
  _WORD *v2; // esi
  _WORD *v3; // edi
  wchar_t *v4; // ebx
  wchar_t *v5; // esi
  int v6; // ecx
  wchar_t *v7; // ecx
  wchar_t v8; // ax
  CCmdString *v9; // eax
  wchar_t *v10; // esi
  wchar_t *v11; // edi
  wchar_t *v12; // eax
  wchar_t *v13; // ST14_4
  WCHAR *v14; // eax
  signed __int16 v15; // cx
  wchar_t *v16; // ST14_4
  wchar_t *v17; // ebx
  DWORD v18; // eax
  wchar_t *v19; // eax
  WCHAR *v21; // [esp+14h] [ebp-18h]
  WCHAR *ppstr; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+28h] [ebp-4h]

  v2 = malloc(2u);
  *v2 = 0;
  v23 = 0;
  v3 = malloc(2u);
  *v3 = 0;
  LOBYTE(v23) = 1;
  v4 = _wcsdup(a2);
  free(v2);
  if ( TlsGetValue(gdwTlsIndex) == (LPVOID)256 )
  {
    v5 = _wcsdup(v4);
    _wcsupr(v5);
    if ( wcsstr(v5, L"%PROGRAMFILES%") )
    {
      v6 = wcsstr(v5, L"%PROGRAMFILES%") - v5;
      _mm_storeu_si128((__m128i *)&v4[v6], _mm_loadu_si128((const __m128i *)L"%ProgramW6432%"));
      _mm_storel_epi64((__m128i *)&v4[v6 + 8], _mm_loadl_epi64((const __m128i *)L"W6432%"));
      *(_DWORD *)&v4[v6 + 12] = *(_DWORD *)L"2%";
      v7 = &v4[v6 + 14];
      do
      {
        v8 = *v7;
        ++v7;
        *(v7 - 1) = v8;
      }
      while ( v8 );
    }
    free(v5);
  }
  v9 = RequerySystemEnvironmentString((CCmdString *)&ppstr, (CCmdString *)v4);
  v10 = _wcsdup(v9->m_String);
  free(v3);
  free(ppstr);
  v11 = _wcsdup(v10);
  free(v4);
  if ( *v10 != 34 )
  {
    if ( PE_GetFileAttributes(v10) != -1 )
      goto LABEL_20;
    ppstr = 0;
    v17 = wcsrchr(v10, 0x20u);
    if ( !v17 )
      goto LABEL_20;
    do
    {
      if ( ppstr )
        *ppstr = 32;
      *v17 = 0;
      v18 = PE_GetFileAttributes(v10);
      if ( v18 != -1 && !(v18 & 0x10) )
      {
        v19 = _wcsdup(v10);
        goto LABEL_21;
      }
      ppstr = v17;
      v17 = wcsrchr(v10, 0x20u);
    }
    while ( v17 );
    v14 = ppstr;
    if ( !ppstr )
      goto LABEL_20;
    v15 = 32;
    goto LABEL_19;
  }
  v12 = wcschr(v10 + 1, 0x22u);
  v21 = v12;
  if ( v12 )
  {
    *v12 = 0;
    v13 = v11;
    v11 = _wcsdup(v10 + 1);
    free(v13);
    v14 = v21;
    v15 = 34;
LABEL_19:
    *v14 = v15;
    goto LABEL_20;
  }
  v16 = v11;
  v11 = _wcsdup(v10 + 1);
  free(v16);
LABEL_20:
  v19 = _wcsdup(v11);
LABEL_21:
  *(_DWORD *)a1 = v19;
  free(v10);
  free(v11);
  return a1;
}

//----- (00BE4AC0) --------------------------------------------------------
_bstr_t *__cdecl PE_GetProgrameFilePath(_bstr_t *a1, wchar_t *lpszPathName)
{
  WCHAR *v2; // edi
  wchar_t *szPathNameszPathName; // esi
  wchar_t *szProgameFilesX86EnvValueValue; // ebx
  unsigned int v5; // kr04_4
  const wchar_t *v6; // ecx
  WCHAR *v7; // esi
  CCmdString *v8; // eax
  wchar_t *v9; // esi
  WCHAR *pszResult; // [esp+18h] [ebp-1Ch]
  void *v12; // [esp+1Ch] [ebp-18h]
  WCHAR *ppszText2; // [esp+20h] [ebp-14h]
  wchar_t *v14; // [esp+24h] [ebp-10h]
  int v15; // [esp+30h] [ebp-4h]

  v15 = 0;
  v2 = (WCHAR *)malloc(2u);
  ppszText2 = v2;
  *v2 = 0;
  szPathNameszPathName = _wcsdup(lpszPathName);
  v14 = szPathNameszPathName;
  szProgameFilesX86EnvValueValue = _wcsdup(gszProgameFilesX86EnvValueValue);
  LOBYTE(v15) = 3;
  _wcsupr(szProgameFilesX86EnvValueValue);
  _wcsupr(szPathNameszPathName);
  if ( !wcsncmp(szPathNameszPathName, szProgameFilesX86EnvValueValue, wcslen(szProgameFilesX86EnvValueValue))
    && PE_GetFileAttributes(lpszPathName) == -1 )
  {
    v5 = wcslen(gszProgameFilesX86EnvValueValue);
    v6 = (const wchar_t *)&gszNullString;
    if ( &lpszPathName[v5] )
      v6 = &lpszPathName[v5];
    v7 = _wcsdup(v6);
    ppszText2 = v7;
    v8 = operator+((CCmdString *)&pszResult, gszProgramW6432EnvValue, (CCmdString *)&ppszText2);
    v12 = v2;
    v2 = _wcsdup(v8->m_String);
    ppszText2 = v2;
    free(v12);
    free(pszResult);
    free(v7);
    if ( PE_GetFileAttributes(v2) != -1 )
    {
      v9 = lpszPathName;
      lpszPathName = _wcsdup(v2);
      free(v9);
    }
    szPathNameszPathName = v14;
  }
  a1->m_Data = (Data_t_bstr_t *)_wcsdup(lpszPathName);
  free(szProgameFilesX86EnvValueValue);
  free(szPathNameszPathName);
  free(v2);
  free(lpszPathName);
  return a1;
}

//----- (00BE4C50) --------------------------------------------------------
PSID __cdecl GetUserSID(wchar_t *lpszUserName)
{
  wchar_t *pszUserName; // ecx
  int nCount; // ebx
  wchar_t chText; // ax
  wchar_t *pstr1; // eax
  wchar_t *pstr2; // eax
  wchar_t *v7; // edi
  wchar_t *v8; // esi
  const wchar_t *v9; // eax
  wchar_t *pstr4; // esi
  signed int v11; // edi
  wchar_t *pstr3; // eax
  DWORD *v13; // edi
  BOOL ret; // eax
  int dwValue; // [esp+4h] [ebp-838h]
  BYTE nSubAuthorityCount[4]; // [esp+8h] [ebp-834h]
  PSID pSid; // [esp+Ch] [ebp-830h]
  struct _SID_IDENTIFIER_AUTHORITY IdentifierAuthority; // [esp+10h] [ebp-82Ch]
  DWORD nSubAuthority[8]; // [esp+18h] [ebp-824h]
  WCHAR psz[1024]; // [esp+38h] [ebp-804h]

  pszUserName = lpszUserName;
  pSid = 0;
  LOBYTE(nCount) = 0;
  nSubAuthority[0] = 0;
  nSubAuthorityCount[0] = 0;
  nSubAuthority[1] = 0;
  nSubAuthority[2] = 0;
  nSubAuthority[3] = 0;
  nSubAuthority[4] = 0;
  nSubAuthority[5] = 0;
  nSubAuthority[6] = 0;
  nSubAuthority[7] = 0;
  *(_DWORD *)IdentifierAuthority.Value = 0;
  *(_WORD *)&IdentifierAuthority.Value[4] = 0;
  do
  {
    chText = *pszUserName;
    ++pszUserName;
    *(wchar_t *)((char *)pszUserName + (char *)psz - (char *)lpszUserName - 2) = chText;
  }
  while ( chText );
  pstr1 = wcschr(psz, '-');
  if ( !pstr1 )
    return pSid;
  pstr2 = wcschr(pstr1 + 1, '-');
  if ( !pstr2 )
    return pSid;
  v7 = pstr2 + 1;
  v8 = wcschr(pstr2 + 1, '-');
  if ( !v8 )
    return pSid;
  *v8 = 0;
  if ( *v7 != '0' || v7[1] != 'x' )
  {
    scan_fn(v7, (int)L"%lu", (int)&dwValue);
    IdentifierAuthority.Value[4] = BYTE1(dwValue);
    IdentifierAuthority.Value[5] = dwValue;
    IdentifierAuthority.Value[2] = HIBYTE(dwValue);
    IdentifierAuthority.Value[3] = BYTE2(dwValue);
  }
  else
  {
    scan_fn(v7, (int)L"0x%02hx%02hx%02hx%02hx%02hx%02hx", (int)&IdentifierAuthority);
  }
  *v8 = '-';
  v9 = v8;
  pstr4 = v8 + 1;
  v11 = 0;
  do
  {
    pstr3 = wcschr(v9, '-');
    if ( !pstr3 )
      break;
    ++v11;
    *pstr3 = 0;
    LOBYTE(nCount) = nCount + 1;
    v9 = pstr3 + 1;
  }
  while ( v11 < 8 );
  nSubAuthorityCount[0] = nCount;
  nCount = (unsigned __int8)nCount;
  if ( (signed int)(unsigned __int8)nCount > 0 )
  {
    v13 = nSubAuthority;
    do
    {
      scan_fn(pstr4, (int)L"%lu", (int)v13);
      ++v13;
      pstr4 += lstrlenW(pstr4) + 1;
      --nCount;
    }
    while ( nCount );
  }
  ret = AllocateAndInitializeSid(
          &IdentifierAuthority,
          nSubAuthorityCount[0],
          nSubAuthority[0],
          nSubAuthority[1],
          nSubAuthority[2],
          nSubAuthority[3],
          nSubAuthority[4],
          nSubAuthority[5],
          nSubAuthority[6],
          nSubAuthority[7],
          &pSid);
  return (PSID)(ret != 0 ? (unsigned int)pSid : 0);
}

//----- (00BE4ED0) --------------------------------------------------------
signed int sub_BE4ED0()
{
  return -1;
}

//----- (00BE4EE0) --------------------------------------------------------
int __cdecl sub_BE4EE0(int a1, int a2, int a3, int a4)
{
  const WCHAR *v4; // ecx
  const WCHAR *v6; // [esp-4h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-4h]

  v6 = v4;
  v7 = 0;
  sub_BE70E0((CCmdString *)&v6, (HWND)a2, (StringItem *)a3, (WCHAR *)a4);
  CPEString::AppendPath((CCmdString *)a1, v6);
  return a1;
}

//----- (00BE4F20) --------------------------------------------------------
int __cdecl sub_BE4F20(int str, int a2, wchar_t *a1)
{
  _WORD *v3; // eax
  const WCHAR *v5; // [esp-4h] [ebp-2Ch]
  StringItem a3; // [esp+4h] [ebp-24h]
  int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  v7 = 0;
  v3 = malloc(2u);
  a3.strText = (int)v3;
  a3.arrTexts.baseclass_0._Mypair._Myval2._Myfirst = 0;
  a3.arrTexts.baseclass_0._Mypair._Myval2._Mylast = 0;
  *v3 = 0;
  a3.arrTexts.baseclass_0._Mypair._Myval2._Myend = 0;
  v8 = 0;
  sub_BE7040(a1, &a3);
  sub_BE70E0((CCmdString *)&v5, (HWND)a2, &a3, 0);
  CPEString::AppendPath((CCmdString *)str, v5);
  StringItem::~StringItem((tagPEStringStruct *)&a3);
  return str;
}

//----- (00BE4FB0) --------------------------------------------------------
CCmdString *__cdecl PE_LoadFileName(CCmdString *strRet, HWND hWndIn, LPCWSTR lpszFileName)
{
  CCmdString *res; // ebx
  Data_t_bstr_t *v4; // esi
  Data_t_bstr_t *pszArgs; // edi
  wchar_t *v6; // eax
  Data_t_bstr_t *v7; // eax
  wchar_t *pszPath; // ebx
  wchar_t *v9; // eax
  CCmdString *v10; // eax
  WCHAR *v11; // ebx
  Data_t_bstr_t *v12; // eax
  CCmdString *v13; // eax
  CCmdString ItemHere; // [esp+14h] [ebp-28Ch]
  int theStringItem; // [esp+18h] [ebp-288h]
  IPersistFile *pPersistFile; // [esp+24h] [ebp-27Ch]
  HWND hWnd; // [esp+28h] [ebp-278h]
  CCmdString *v19; // [esp+2Ch] [ebp-274h]
  _bstr_t strArgs; // [esp+30h] [ebp-270h]
  IShellLinkW *pShellLink; // [esp+34h] [ebp-26Ch]
  void *pszFileName; // [esp+38h] [ebp-268h]
  _bstr_t a2; // [esp+3Ch] [ebp-264h]
  WIN32_FIND_DATAW FindData; // [esp+40h] [ebp-260h]
  int v25; // [esp+29Ch] [ebp-4h]

  res = strRet;
  hWnd = hWndIn;
  v19 = strRet;
  pszFileName = (void *)lpszFileName;
  v4 = (Data_t_bstr_t *)malloc(2u);
  a2.m_Data = v4;
  LOWORD(v4->m_wstr) = 0;
  v25 = 0;
  pszArgs = (Data_t_bstr_t *)malloc(2u);
  strArgs.m_Data = pszArgs;
  LOWORD(pszArgs->m_wstr) = 0;
  LOBYTE(v25) = 1;
  CoInitializeEx(0, 0);
  if ( CoCreateInstance(&CLSID_ShellLink, 0, CLSCTX_INPROC_SERVER, &CLSID_IShellLinkW, (LPVOID *)&pShellLink) >= 0 )
  {
    if ( pShellLink->lpVtbl->QueryInterface(pShellLink, &CLSID_IPersistFile, (LPVOID *)&pPersistFile) >= 0 )
    {
      if ( pPersistFile->lpVtbl->Load(pPersistFile, (LPCOLESTR)pszFileName, STGM_DIRECT) >= 0
        && pShellLink->lpVtbl->Resolve(pShellLink, hWnd, 3) >= 0 )// SLR_ANY_MATCH | SLR_NO_UI
      {
        v7 = (Data_t_bstr_t *)realloc(v4, 2002u);
        pszPath = (wchar_t *)v7;
        a2.m_Data = v7;
        if ( v7 )
          memset(v7, 0, 2002u);
        if ( pShellLink->lpVtbl->GetPath(pShellLink, pszPath, 1000, &FindData, SLGP_SHORTPATH) >= 0 )
        {
          StringItem::StringItem((StringItem *)&ItemHere);
          LOBYTE(v25) = 2;
          v9 = _wcsdup(pszPath);
          v10 = (CCmdString *)PE_GetProgrameFilePath((_bstr_t *)&pszFileName, v9);
          CCmdString::Reset((CCmdString *)&a2, v10);
          free(pszFileName);
          v4 = a2.m_Data;
          v11 = ItemHere.m_String;
          ItemHere.m_String = _wcsdup((const wchar_t *)a2.m_Data);
          free(v11);
          v12 = (Data_t_bstr_t *)realloc(pszArgs, 2002u);
          pszArgs = v12;
          strArgs.m_Data = v12;
          if ( v12 )
            memset(v12, 0, 2002u);
          if ( pShellLink->lpVtbl->GetArguments(pShellLink, (LPWSTR)pszArgs, 1000) >= 0 )
          {
            CCmdString::InsertAt(&ItemHere, (const wchar_t *)pszArgs, 0x7FFFFFFFu, 0);
            sub_BF0530((std__vector *)&theStringItem, (const wchar_t **)&a2);
            sub_BF0530((std__vector *)&theStringItem, (const wchar_t **)&strArgs);
            v13 = sub_BE70E0((CCmdString *)&pszFileName, hWnd, (StringItem *)&ItemHere, 0);
            CCmdString::Reset((CCmdString *)&a2, v13);
            free(pszFileName);
            v4 = a2.m_Data;
            pszArgs = strArgs.m_Data;
          }
          LOBYTE(v25) = 1;
          StringItem::~StringItem((tagPEStringStruct *)&ItemHere);
        }
        else
        {
          v4 = (Data_t_bstr_t *)_wcsdup((const wchar_t *)&gszNullString);
          a2.m_Data = v4;
          free(pszPath);
        }
        res = v19;
      }
      pPersistFile->lpVtbl->Release(pPersistFile);
    }
    pShellLink->lpVtbl->Release(pShellLink);
    v6 = _wcsdup((const wchar_t *)v4);
  }
  else
  {
    v6 = _wcsdup((const wchar_t *)&gszNullString);
  }
  res->m_String = v6;
  free(pszArgs);
  free(v4);
  return res;
}
// CB7B5C: using guessed type GUID CLSID_IPersistFile;

//----- (00BE52B0) --------------------------------------------------------
int __cdecl PE_GetLongPathName(CCmdString *str, wchar_t *pszKeyName)
{
  HMODULE v2; // eax
  int (__stdcall *v3)(LPCWSTR, LPWSTR, DWORD); // eax
  const wchar_t *v4; // ecx
  Data_t_bstr_t *strKeyName2_bstrText1; // edi
  const WCHAR *v7; // eax
  CCmdString strKeyName; // esi
  const WCHAR *v9; // eax
  const unsigned __int16 *v10; // eax
  int v11; // eax
  const unsigned __int16 *v12; // eax
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t *v15; // eax
  WCHAR *v16; // eax
  const wchar_t *v17; // eax
  const wchar_t *v18; // eax
  CCmdString v19; // [esp+14h] [ebp-18h]
  int KeyNameNew; // [esp+18h] [ebp-14h]
  tagKeyName KeyName2; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+28h] [ebp-4h]

  if ( dword_CD4C40 & 1 )
  {
    v3 = GetLongPathNameW_0;
  }
  else
  {
    dword_CD4C40 |= 1u;
    v2 = LoadLibraryW(L"kernel32.dll");
    v3 = (int (__stdcall *)(LPCWSTR, LPWSTR, DWORD))GetProcAddress(v2, "GetLongPathNameW");
    GetLongPathNameW_0 = v3;
  }
  if ( !v3 )
  {
    v4 = (const wchar_t *)&gszNullString;
    if ( pszKeyName )
      v4 = pszKeyName;
    str->m_String = _wcsdup(v4);
    return (int)str;
  }
  sub_BE7AB0(&gKeyNameMap, &KeyName2, pszKeyName);
  v22 = 0;
  if ( !gbFlagsInPE_GetLongPathName )
  {
    strKeyName2_bstrText1 = KeyName2.bstrText1.m_Data;
    if ( KeyName2.bstrText1.m_Data )
      v7 = KeyName2.bstrText1.m_Data->m_wstr;
    else
      v7 = 0;
    KeyNameNew = GetLongPathNameW_0(v7, 0, 0);
    strKeyName.m_String = (WCHAR *)malloc(2u);
    *strKeyName.m_String = 0;
    LOBYTE(v22) = 1;
    if ( !gbFlagsInPE_GetLongPathName )
    {
      strKeyName.m_String = (WCHAR *)realloc(strKeyName.m_String, 2 * KeyNameNew + 2);
      v19.m_String = strKeyName.m_String;
      if ( strKeyName.m_String )
        memset(strKeyName.m_String, 0, 2 * KeyNameNew + 2);
      v9 = strKeyName2_bstrText1 ? strKeyName2_bstrText1->m_wstr : 0;
      if ( GetLongPathNameW_0(v9, strKeyName.m_String, KeyNameNew) )
      {
        if ( strKeyName2_bstrText1 )
          v10 = strKeyName2_bstrText1->m_wstr;
        else
          v10 = 0;
        v11 = wcscmp(strKeyName.m_String, v10);
        if ( v11 )
          v11 = -(v11 < 0) | 1;
        if ( v11 )
        {
          if ( strKeyName2_bstrText1 )
            v12 = strKeyName2_bstrText1->m_wstr;
          else
            v12 = 0;
          v13 = wcscmp(pszKeyName, v12);
          if ( v13 )
            v13 = -(v13 < 0) | 1;
          if ( v13 )
          {
            v14 = *(wchar_t ***)sub_BE5DE0(&gKeyNameMap, (int)&KeyNameNew, strKeyName.m_String);
            if ( v14 )
              v15 = *v14;
            else
              v15 = 0;
            CCmdString::Reset(&v19, v15);
            _bstr_t::_Free((_bstr_t *)&KeyNameNew);
            strKeyName.m_String = v19.m_String;
          }
          v16 = _wcsdup(strKeyName.m_String);
        }
        else
        {
          v17 = (const wchar_t *)&gszNullString;
          if ( pszKeyName )
            v17 = pszKeyName;
          v16 = _wcsdup(v17);
        }
        str->m_String = v16;
        free(strKeyName.m_String);
        _bstr_t::_Free(&KeyName2.bstrText1);
        return (int)str;
      }
    }
    free(strKeyName.m_String);
  }
  v18 = (const wchar_t *)&gszNullString;
  if ( pszKeyName )
    v18 = pszKeyName;
  str->m_String = _wcsdup(v18);
  _bstr_t::_Free(&KeyName2.bstrText1);
  return (int)str;
}
// CD3860: using guessed type char gbFlagsInPE_GetLongPathName;
// CD4C40: using guessed type int dword_CD4C40;

//----- (00BE5520) --------------------------------------------------------
CCmdString *__cdecl sub_BE5520(CCmdString *a1, wchar_t *psz, StringItem *a3)
{
  wchar_t *v3; // esi
  wchar_t *v4; // eax
  unsigned int v5; // ecx
  _WORD *v6; // eax
  wchar_t *v7; // ST0C_4
  wchar_t *v8; // eax
  wchar_t *v10; // eax
  wchar_t *v11; // edi
  wchar_t *v12; // eax
  int v13; // [esp+18h] [ebp-14h]
  signed int v14; // [esp+1Ch] [ebp-10h]

  v3 = _wcsdup(psz);
  _wcsupr(v3);
  v4 = _wcsdup(v3);
  if ( !sub_BE6090(v4)
    || (v5 = 1,
        v14 = 1,
        (unsigned int)((_DWORD)(a3->arrTexts.baseclass_0._Mypair._Myval2._Mylast
                              - a3->arrTexts.baseclass_0._Mypair._Myval2._Myfirst) >> 2) <= 1) )
  {
LABEL_9:
    a1->m_String = _wcsdup((const wchar_t *)&gszNullString);
    free(v3);
    free(psz);
    return a1;
  }
  while ( 1 )
  {
    v13 = 4 * v5;
    v6 = (_WORD *)*((_DWORD *)a3->arrTexts.baseclass_0._Mypair._Myval2._Myfirst + v5);
    if ( *v6 == 47 || *v6 == 45 )
      goto LABEL_8;
    v7 = _wcsdup(L"CMD");
    v8 = _wcsdup(v3);
    if ( !sub_BE5FD0(v8, v7)
      || _wcsicmp(*(const wchar_t **)((char *)a3->arrTexts.baseclass_0._Mypair._Myval2._Myfirst + v13), L"start") )
    {
      break;
    }
    v5 = v14;
LABEL_8:
    v14 = ++v5;
    if ( v5 >= (_DWORD)(a3->arrTexts.baseclass_0._Mypair._Myval2._Mylast
                      - a3->arrTexts.baseclass_0._Mypair._Myval2._Myfirst) >> 2 )
      goto LABEL_9;
  }
  v10 = _wcsdup(*((const wchar_t **)a3->arrTexts.baseclass_0._Mypair._Myval2._Myfirst + v14));
  v11 = v10;
  if ( *v10 != 34 )
  {
    v12 = wcschr(v10, 0x2Cu);
    if ( v12 )
      *v12 = 0;
  }
  a1->m_String = _wcsdup(v11);
  free(v11);
  free(v3);
  free(psz);
  return a1;
}

//----- (00BE56C0) --------------------------------------------------------
wchar_t *InitSystemPath()
{
  HMODULE v0; // eax
  FARPROC v1; // eax
  int v2; // ecx
  WCHAR v3; // ax
  char *v4; // ecx
  __int16 v5; // ax
  HMODULE v6; // eax
  FARPROC GetSystemWow64DirectoryW; // eax
  int index; // ecx
  WCHAR chText; // ax
  int v10; // eax
  wchar_t *result; // eax

  v0 = LoadLibraryW(L"Kernel32.dll");
  v1 = GetProcAddress(v0, "GetSystemWindowsDirectoryW");
  if ( v1 )
    ((void (__stdcall *)(WCHAR *, signed int))v1)(gszWindowsDirectory, 260);
  else
    GetWindowsDirectoryW(gszWindowsDirectory, 0x104u);
  v2 = 0;
  do
  {
    v3 = gszWindowsDirectory[v2];
    ++v2;
    *(_WORD *)((char *)&Wow64EnableWow64FsRedirection + v2 * 2 + 2) = v3;
  }
  while ( v3 );
  v4 = (char *)&gSystemDirInfo - 2;
  do
  {
    v5 = *((_WORD *)v4 + 1);
    v4 += 2;
  }
  while ( v5 );
  *(_DWORD *)v4 = *(_DWORD *)L"\\System32";
  *((_DWORD *)v4 + 1) = *(_DWORD *)L"ystem32";
  *((_DWORD *)v4 + 2) = *(_DWORD *)L"tem32";
  *((_DWORD *)v4 + 3) = *(_DWORD *)L"m32";
  *((_DWORD *)v4 + 4) = *(_DWORD *)L"2";
  v6 = LoadLibraryW(L"Kernel32.dll");
  GetSystemWow64DirectoryW = GetProcAddress(v6, "GetSystemWow64DirectoryW");
  if ( GetSystemWow64DirectoryW
    && !((int (__stdcall *)(__int16 *, signed int))GetSystemWow64DirectoryW)(gSystemDirInfo.szSystemWow64Directory, 260) )
  {
    index = 0;
    do
    {
      chText = gSystemDirInfo.szBuffer[index];
      ++index;
      *(_WORD *)((char *)&gSystemDirInfo.Lock.SpinCount + index * 2 + 2) = chText;
    }
    while ( chText );
  }
  ExpandEnvironmentStringsW(L"%ProgramW6432%", gszProgramW6432EnvValue, 0x104u);
  v10 = wcscmp(L"%ProgramW6432%", gszProgramW6432EnvValue);
  if ( v10 )
    v10 = -(v10 < 0) | 1;
  if ( !v10 )
  {
    ExpandEnvironmentStringsW(L"%ProgramFiles%", gszProgramW6432EnvValue, 0x104u);
    SetEnvironmentVariableW(L"ProgramW6432", gszProgramW6432EnvValue);
  }
  ExpandEnvironmentStringsW(L"%PROGRAMFILES(X86)%", gszProgameFilesX86EnvValueValue, MAX_PATH);
  result = wcsstr(gszProgramW6432EnvValue, L" (x86)");
  if ( result )
  {
    *wcsstr(gszProgramW6432EnvValue, L" (x86)") = 0;
    result = (wchar_t *)SetEnvironmentVariableW(L"PROGRAMFILES(X86)", gszProgramW6432EnvValue);
  }
  return result;
}
// C9CEA8: using guessed type wchar_t aSystem32[10];

//----- (00BE5860) --------------------------------------------------------
char __cdecl sub_BE5860(wchar_t **a1, __int16 a2, const wchar_t **a3, char a4)
{
  wchar_t *v4; // esi
  wchar_t v5; // ax
  __int16 j; // bx
  char result; // al
  int v8; // eax
  wchar_t v9; // ax
  wchar_t *v10; // edi
  wchar_t *v11; // eax
  wchar_t *v12; // eax
  wchar_t i; // ax
  int v14; // eax
  wchar_t *v15; // ebx
  wchar_t *v16; // esi
  wchar_t *v17; // esi
  wchar_t *v18; // eax
  const wchar_t *v19; // ecx
  int v20; // edx
  const wchar_t *v21; // edx
  int v22; // ecx
  wchar_t v23; // ax
  CCmdString *v24; // eax
  wchar_t *v25; // ebx
  DWORD v26; // eax
  CCmdString *v27; // eax
  wchar_t *v28; // ebx
  DWORD v29; // eax
  wchar_t v30; // ax
  wchar_t *v31; // ebx
  wchar_t *v32; // esi
  WCHAR *ppv; // [esp+14h] [ebp-18h]
  WCHAR *ppstr; // [esp+18h] [ebp-14h]
  wchar_t *v35; // [esp+1Ch] [ebp-10h]
  int v36; // [esp+28h] [ebp-4h]

  v4 = *a1;
  v35 = v4;
  v5 = *v4;
  if ( !*v4 )
    goto LABEL_5;
  while ( 1 )
  {
    if ( !isspace(v5) )
    {
      j = a2;
      if ( *v4 != a2 )
        break;
    }
    v5 = v4[1];
    ++v4;
    v35 = v4;
    if ( !v5 )
      goto LABEL_5;
  }
  v8 = *v4;
  if ( (_WORD)v8 && (_WORD)v8 != a2 )
  {
    if ( v8 == 34 )
    {
      v9 = v4[1];
      v35 = v4 + 1;
      v10 = v4 + 1;
      if ( v9 )
      {
        while ( v9 != 34 )
        {
          v9 = v10[1];
          ++v10;
          if ( !v9 )
            goto LABEL_14;
        }
      }
      v11 = v10 + 1;
      if ( !*v10 )
LABEL_14:
        v11 = v10;
      *a1 = v11;
      if ( a2 && *v11 )
      {
        do
        {
          if ( **a1 == a2 )
            break;
          v12 = *a1 + 1;
          *a1 = v12;
        }
        while ( *v12 );
      }
LABEL_45:
      v31 = v35;
      v32 = (wchar_t *)*a3;
      *a3 = _wcsdup(v35);
      free(v32);
      (*a3)[v10 - v31] = 0;
      result = 1;
    }
    else
    {
      v10 = v4;
      while ( 1 )
      {
        for ( i = *v10; i; ++v10 )
        {
          if ( i == j )
            break;
          if ( i == 32 )
            break;
          i = v10[1];
        }
        if ( !a4 )
          goto LABEL_44;
        v14 = *v4;
        if ( v14 != 37 && v14 != 92 && v4[1] != 58 )
          goto LABEL_44;
        v15 = v35;
        v16 = (wchar_t *)*a3;
        *a3 = _wcsdup(v35);
        free(v16);
        (*a3)[v10 - v15] = 0;
        v17 = _wcsdup(*a3);
        v36 = 0;
        _wcsupr(v17);
        if ( TlsGetValue(gdwTlsIndex) == (LPVOID)256 && wcsstr(v17, L"%PROGRAMFILES%") )
        {
          v18 = wcsstr(v17, L"%PROGRAMFILES%");
          v19 = *a3;
          v20 = v18 - v17;
          _mm_storeu_si128((__m128i *)&(*a3)[v20], _mm_loadu_si128((const __m128i *)L"%ProgramW6432%"));
          _mm_storel_epi64((__m128i *)&v19[v20 + 8], _mm_loadl_epi64((const __m128i *)L"W6432%"));
          *(_DWORD *)&v19[v20 + 12] = *(_DWORD *)L"2%";
          v21 = &(*a3)[v20 + 14];
          v22 = (char *)*a3 - (char *)*a3;
          do
          {
            v23 = *v21;
            ++v21;
            *(const wchar_t *)((char *)v21 + v22 - 2) = v23;
          }
          while ( v23 );
        }
        v24 = RequerySystemEnvironmentString((CCmdString *)&ppstr, (CCmdString *)*a3);
        v25 = (wchar_t *)*a3;
        *a3 = _wcsdup(v24->m_String);
        free(v25);
        free(ppstr);
        v26 = PE_GetFileAttributes((OLECHAR *)*a3);
        if ( v26 != -1 && !(v26 & 0x10)
          || (v27 = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)a3, L".exe"),
              v28 = (wchar_t *)*a3,
              *a3 = _wcsdup(v27->m_String),
              free(v28),
              free(ppv),
              v29 = PE_GetFileAttributes((OLECHAR *)*a3),
              v29 != -1)
          && !(v29 & 0x10) )
        {
          free(v17);
LABEL_44:
          *a1 = v10;
          goto LABEL_45;
        }
        v30 = *v10;
        for ( j = a2; v30 != a2; ++v10 )
        {
          if ( !isspace(v30) )
            break;
          v30 = v10[1];
        }
        if ( !*v10 || *v10 == a2 )
          break;
        v36 = -1;
        free(v17);
        v4 = v35;
      }
      free(v17);
      result = 1;
    }
  }
  else
  {
LABEL_5:
    *a1 = v4;
    result = 0;
  }
  return result;
}

//----- (00BE5BB0) --------------------------------------------------------
int (__stdcall *InitApis())(LONG Status)
{
  HMODULE v0; // eax
  HMODULE v1; // eax
  HMODULE v2; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  int (__stdcall *result)(LONG); // eax

  v0 = LoadLibraryW(L"Kernel32.dll");
  Wow64EnableWow64FsRedirection = (BOOLEAN (__stdcall *)(BOOLEAN))GetProcAddress(v0, "Wow64EnableWow64FsRedirection");
  v1 = LoadLibraryW(L"Kernel32.dll");
  Wow64DisableWow64FsRedirection = (BOOL (__stdcall *)(PVOID *))GetProcAddress(v1, "Wow64DisableWow64FsRedirection");
  v2 = LoadLibraryW(L"Kernel32.dll");
  Wow64RevertWow64FsRedirection = (int (__stdcall *)(PVOID))GetProcAddress(v2, "Wow64RevertWow64FsRedirection");
  v3 = LoadLibraryW(L"advapi32.dll");
  *(_DWORD *)RegDeleteKeyExW = GetProcAddress(v3, "RegDeleteKeyExW");
  v4 = LoadLibraryW(L"ntdll.dll");
  NtDeleteKey = (int (__stdcall *)(HANDLE))GetProcAddress(v4, "NtDeleteKey");
  v5 = LoadLibraryW(L"ntdll.dll");
  NtOpenKey = (int (__stdcall *)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES))GetProcAddress(v5, "NtOpenKey");
  v6 = LoadLibraryW(L"ntdll.dll");
  NtCreateKey = (int (__stdcall *)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG, PUNICODE_STRING, ULONG, PULONG))GetProcAddress(v6, "NtCreateKey");
  v7 = LoadLibraryW(L"ntdll.dll");
  result = (int (__stdcall *)(LONG))GetProcAddress(v7, "RtlNtStatusToDosError");
  RtlNtStatusToDosError = result;
  return result;
}

//----- (00BE5C70) --------------------------------------------------------
WCHAR **__cdecl PE_GetSystemPathInfo(WCHAR **a1, wchar_t *lpszText)
{
  wchar_t *v2; // eax
  wchar_t *v3; // esi
  unsigned int v4; // kr04_4
  wchar_t *v5; // esi
  CCmdString *v6; // eax
  WCHAR *v7; // edi
  WCHAR *s1; // [esp+10h] [ebp-20h]
  WCHAR *ppv; // [esp+14h] [ebp-1Ch]
  HKEY__ hKey; // [esp+18h] [ebp-18h]
  int v12; // [esp+1Ch] [ebp-14h]
  int ImageBase; // [esp+20h] [ebp-10h]
  int v14; // [esp+2Ch] [ebp-4h]

  v14 = 1;
  *a1 = _wcsdup(lpszText);
  v2 = lpszText;
  v12 = 1;
  if ( *lpszText && Wow64DisableWow64FsRedirection )
  {
    v3 = _wcsdup(L"\\");
    hKey.unused = (int)v3;
    operator+((CCmdString *)&s1, gszProgramW6432EnvValue, (CCmdString *)&hKey);
    LOBYTE(v14) = 2;
    free(v3);
    Wow64DisableWow64FsRedirection((PVOID *)&ImageBase);
    if ( !(_BYTE)ImageBase
      && !_wcsnicmp(lpszText, (const wchar_t *)&gSystemDirInfo, wcslen((const unsigned __int16 *)&gSystemDirInfo)) )
    {
      v4 = wcslen((const unsigned __int16 *)&gSystemDirInfo);
      v5 = _wcsdup((const wchar_t *)gSystemDirInfo.szSystemWow64Directory);
      hKey.unused = (int)v5;
      v6 = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)&hKey, &lpszText[v4]);
      v7 = *a1;
      *a1 = _wcsdup(v6->m_String);
      free(v7);
      free(ppv);
      free(v5);
    }
    Wow64RevertWow64FsRedirection((PVOID)ImageBase);
    free(s1);
    v2 = lpszText;
  }
  free(v2);
  return a1;
}

//----- (00BE5DE0) --------------------------------------------------------
int __thiscall sub_BE5DE0(std__tree *this, int a2, OLECHAR *psz)
{
  OLECHAR *v3; // ebx
  std_Tree_node_for_tagKeyName *v4; // esi
  OLECHAR **v5; // eax
  OLECHAR *v6; // eax
  UINT v7; // edi
  _DWORD *v8; // eax
  const wchar_t *v9; // eax
  int v10; // eax
  std_Tree_node_for_tagKeyName *v11; // eax
  std_Tree_node_for_tagKeyName *j; // eax
  std_Tree_node_for_tagKeyName *i; // eax
  BSTR *v14; // eax
  BSTR *v15; // esi
  BSTR v16; // eax
  OLECHAR *v17; // eax
  OLECHAR *v18; // esi
  int result; // eax
  std__tree *v20; // [esp+14h] [ebp-10h]

  v20 = this;
  v3 = psz;
  v4 = this->_Mypair._Myval2._Myhead->_Left;
  if ( this->_Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)this->_Mypair._Myval2._Myhead )
  {
LABEL_23:
    v14 = (BSTR *)operator new(0xCu);
    v15 = v14;
    psz = (OLECHAR *)v14;
    if ( v14 )
    {
      v14[1] = 0;
      v14[2] = (BSTR)1;
      v16 = SysAllocString(v3);
      *v15 = v16;
      if ( !v16 && v3 )
        _com_issue_error(0x8007000E);
    }
    else
    {
      v15 = 0;
    }
    result = a2;
    *(_DWORD *)a2 = v15;
    if ( !v15 )
      _com_issue_error(0x8007000E);
    return result;
  }
  while ( 1 )
  {
    if ( v4->_Myval.second.bstrText2.m_Data )
      goto LABEL_13;
    v5 = (OLECHAR **)v4->_Myval.second.dwValue;
    if ( !v5 )
      break;
    v6 = *v5;
    if ( !v6 )
      break;
    v7 = SysStringLen(v6);
    if ( !v7 )
      goto LABEL_28;
    v8 = (_DWORD *)v4->_Myval.second.dwValue;
    v9 = (const wchar_t *)(v8 ? *v8 : 0);
    if ( !_wcsnicmp(v3, v9, v7) )
    {
      v10 = v3[v7];
      if ( !(_WORD)v10 || v10 == 92 )
        goto LABEL_28;
    }
    this = v20;
LABEL_13:
    if ( !v4->_IsNil )
    {
      v11 = v4->_Right;
      if ( v11->_IsNil )
      {
        for ( i = v4->_Parent; !i->_IsNil; i = i->_Parent )
        {
          if ( v4 != i->_Right )
            break;
          v4 = i;
        }
        v4 = i;
      }
      else
      {
        v4 = v4->_Right;
        for ( j = v11->_Left; !j->_IsNil; j = j->_Left )
          v4 = j;
      }
    }
    if ( v4 == (std_Tree_node_for_tagKeyName *)this->_Mypair._Myval2._Myhead )
      goto LABEL_23;
  }
  v7 = 0;
LABEL_28:
  tagKeyName::Update((_bstr_t *)&psz, v3, v7, &v4->_Myval.second.bstrText1);
  v17 = psz;
  *(_DWORD *)a2 = psz;
  if ( v17 )
  {
    InterlockedIncrement((volatile LONG *)v17 + 2);
    v18 = psz;
    if ( psz )
    {
      if ( !InterlockedDecrement((volatile LONG *)psz + 2) && v18 )
      {
        if ( *(_DWORD *)v18 )
        {
          SysFreeString(*(BSTR *)v18);
          *(_DWORD *)v18 = 0;
        }
        if ( *((_DWORD *)v18 + 1) )
        {
          operator delete[](*((void **)v18 + 1));
          *((_DWORD *)v18 + 1) = 0;
        }
        operator delete(v18);
      }
    }
  }
  return a2;
}

//----- (00BE5FD0) --------------------------------------------------------
char __cdecl sub_BE5FD0(wchar_t *lpszText, wchar_t *lpszCmd)
{
  wchar_t *pstr2; // esi
  wchar_t *pstr1; // edi
  wchar_t *pstr; // eax
  wchar_t *v5; // eax
  int chText2; // ecx
  int chText; // ecx
  char bRet; // bl

  if ( !wcsstr(lpszText, lpszCmd) )
  {
    v5 = lpszText;
__returnFALSE:
    bRet = 0;
    goto __quit;
  }
  pstr2 = lpszText;
  pstr1 = lpszCmd;
  do
  {
    pstr = wcsstr(pstr2, lpszCmd);
    if ( !pstr )
      break;
    pstr1 = pstr;
    pstr2 = pstr + 1;
    if ( pstr == (wchar_t *)0xFFFFFFFE )
      break;
  }
  while ( wcsstr(pstr2, lpszCmd) );
  v5 = lpszText;
  if ( pstr1 != lpszText )
  {
    chText2 = *(pstr1 - 1);
    if ( chText2 != '\\' && chText2 != '"' && chText2 != ' ' )
      goto __returnFALSE;
  }
  chText = pstr1[wcslen(lpszCmd)];
  if ( (_WORD)chText )
  {
    if ( chText != '"' && chText != ' ' && chText != '.' )
      goto __returnFALSE;
  }
  bRet = 1;
__quit:
  free(v5);
  free(lpszCmd);
  return bRet;
}

//----- (00BE6090) --------------------------------------------------------
char __cdecl sub_BE6090(wchar_t *psz)
{
  wchar_t *v1; // ST14_4
  wchar_t *v2; // eax
  wchar_t *v3; // ST14_4
  wchar_t *v4; // eax
  wchar_t *v5; // ST14_4
  wchar_t *v6; // eax
  wchar_t *v7; // ST14_4
  wchar_t *v8; // eax
  wchar_t *v9; // ST14_4
  wchar_t *v10; // eax
  wchar_t *v11; // ST14_4
  wchar_t *v12; // eax
  wchar_t *v13; // ST14_4
  wchar_t *v14; // eax
  _WORD *v15; // eax
  void *v16; // ebx
  wchar_t *v17; // eax
  wchar_t *v18; // eax
  wchar_t *v19; // edi
  const wchar_t *v20; // eax
  wchar_t *v21; // eax
  wchar_t *v22; // esi
  wchar_t *v23; // esi
  const wchar_t *v24; // ecx
  wchar_t *v25; // esi
  wchar_t *v26; // ST14_4
  int v27; // ST10_4
  wchar_t *v28; // eax
  char v29; // bl
  int v31; // [esp+18h] [ebp-70h]
  void *v32; // [esp+1Ch] [ebp-6Ch]
  wchar_t *v33; // [esp+20h] [ebp-68h]
  int v34; // [esp+24h] [ebp-64h]
  wchar_t *v35; // [esp+28h] [ebp-60h]
  int v36; // [esp+84h] [ebp-4h]

  v36 = 0;
  if ( wcsstr(psz, L"POWERSHELL") )
    OutputDebugStringW(L"here");
  v1 = _wcsdup(L"RUNDLL32");
  v2 = _wcsdup(psz);
  if ( !sub_BE5FD0(v2, v1) )
  {
    v3 = _wcsdup(L"RUNDLL");
    v4 = _wcsdup(psz);
    if ( !sub_BE5FD0(v4, v3) )
    {
      v5 = _wcsdup(L"CSCRIPT");
      v6 = _wcsdup(psz);
      if ( !sub_BE5FD0(v6, v5) )
      {
        v7 = _wcsdup(L"WSCRIPT");
        v8 = _wcsdup(psz);
        if ( !sub_BE5FD0(v8, v7) )
        {
          v9 = _wcsdup(L"REGSVR32");
          v10 = _wcsdup(psz);
          if ( !sub_BE5FD0(v10, v9) )
          {
            v11 = _wcsdup(L"POWERSHELL");
            v12 = _wcsdup(psz);
            if ( !sub_BE5FD0(v12, v11) )
            {
              v13 = _wcsdup(L"CMD");
              v14 = _wcsdup(psz);
              if ( !sub_BE5FD0(v14, v13) )
                goto LABEL_24;
            }
          }
        }
      }
    }
  }
  v15 = malloc(2u);
  v16 = v15;
  *v15 = 0;
  v17 = (wchar_t *)malloc(2u);
  v33 = v17;
  *v17 = 0;
  v18 = (wchar_t *)malloc(2u);
  v19 = v18;
  *v18 = 0;
  LOBYTE(v36) = 3;
  v20 = (const wchar_t *)&gszNullString;
  v31 = 20;
  if ( psz )
    v20 = psz;
  v21 = _wcsdup(v20);
  v22 = (wchar_t *)sub_C01290(v21, (int)&v33);
  if ( v22 == (wchar_t *)2 )
  {
    v34 = sub_BE6700(psz, 0, 0, (int)&v35, (int)&v31, 0);
    if ( v34 )
    {
      if ( *v19 )
      {
        v23 = v33;
        v33 = _wcsdup(v19);
        free(v23);
      }
    }
    else
    {
      v24 = (const wchar_t *)&gszNullString;
      if ( v35 )
        v24 = v35;
      v25 = _wcsdup(v24);
      v32 = v33;
      v33 = _wcsdup(v25);
      free(v32);
      free(v25);
    }
    v26 = _wcsdup(v33);
    v27 = v34;
    v28 = _wcsdup(psz);
    v22 = sub_C011B0(v28, v27, v26);
  }
  _wcsupr(v33);
  if ( v22 || !wcsstr(v33, L"WINDOWS") )
  {
    free(v19);
    free(v33);
    free(v16);
LABEL_24:
    v29 = 0;
    goto LABEL_25;
  }
  free(v19);
  free(v33);
  free(v16);
  v29 = 1;
LABEL_25:
  free(psz);
  return v29;
}

//----- (00BE63B0) --------------------------------------------------------
char __cdecl sub_BE63B0(wchar_t *a1)
{
  wchar_t *v1; // ecx
  wchar_t v2; // ax
  int v3; // eax
  char result; // al

  v1 = a1;
  v2 = *a1;
  if ( !*a1 )
    goto LABEL_14;
  do
  {
    if ( v2 != 32 && v2 != 44 )
      break;
    v2 = v1[1];
    ++v1;
  }
  while ( v2 );
  if ( !*v1 || !_wcsicmp(a1, L"desktop.ini") )
    goto LABEL_14;
  v3 = wcscmp(a1, L"%1");
  if ( v3 )
    v3 = -(v3 < 0) | 1;
  if ( v3 )
    result = 1;
  else
LABEL_14:
    result = 0;
  return result;
}

//----- (00BE6440) --------------------------------------------------------
// RequeryRegKeyFronMap
int __thiscall std::map<wchar_t const *,_bstr_t,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>>::_Try_emplace<wchar_t const * const &,>(std__tree *this, _bstr_t bstrKeyId, tagKeyName *KeyName, HKEY hRootKey, OLECHAR *lpszKey)
{
  OLECHAR *lpszKeyID; // ebx
  std_Tree_node_for_tagKeyName *pNode; // esi
  Data_t_bstr_t *v7; // eax
  OLECHAR *v8; // eax
  UINT nLength; // edi
  Data_t_bstr_t *v10; // eax
  const wchar_t *v11; // eax
  int v12; // eax
  std_Tree_node_for_tagKeyName *v13; // eax
  std_Tree_node_for_tagKeyName *j; // eax
  std_Tree_node_for_tagKeyName *i; // eax
  tagKeyName *v16; // eax
  tagKeyName *v17; // esi
  Data_t_bstr_t *v18; // eax
  Data_t_bstr_t *v19; // eax
  tagKeyName *v20; // esi
  tagKeyName *result; // eax
  std__tree *pThis; // [esp+14h] [ebp-10h]

  pThis = this;
  lpszKeyID = lpszKey;
  pNode = this->_Mypair._Myval2._Myhead->_Left;
  if ( this->_Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)this->_Mypair._Myval2._Myhead )
  {
LABEL_23:
    KeyName->bstrText1.m_Data = (Data_t_bstr_t *)hRootKey;
    v16 = (tagKeyName *)operator new(0xCu);
    v17 = v16;
    KeyName = v16;
    if ( v16 )
    {
      v16->bstrText2.m_Data = 0;
      v16->dwValue = 1;
      v18 = (Data_t_bstr_t *)SysAllocString(lpszKeyID);
      v17->bstrText1.m_Data = v18;
      if ( !v18 && lpszKeyID )
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
      v17 = 0;
    }
    result = (tagKeyName *)bstrKeyId.m_Data;
    bstrKeyId.m_Data->m_wstr = (BSTR)v17;
    if ( !v17 )
      _com_issue_error(E_OUTOFMEMORY);
    return (int)result;
  }
  while ( 1 )
  {
    if ( (HKEY)pNode->_Myval.first != hRootKey )
      goto LABEL_13;
    v7 = pNode->_Myval.second.bstrText1.m_Data;
    if ( !v7 )
      break;
    v8 = v7->m_wstr;
    if ( !v8 )
      break;
    nLength = SysStringLen(v8);
    if ( !nLength )
      goto __found;
    v10 = pNode->_Myval.second.bstrText1.m_Data;
    v11 = v10 ? v10->m_wstr : 0;
    if ( !_wcsnicmp(lpszKeyID, v11, nLength) )
    {
      v12 = lpszKeyID[nLength];
      if ( !(_WORD)v12 || v12 == '\\' )
        goto __found;
    }
    this = pThis;
LABEL_13:
    if ( !pNode->_IsNil )
    {
      v13 = pNode->_Right;
      if ( v13->_IsNil )
      {
        for ( i = pNode->_Parent; !i->_IsNil; i = i->_Parent )
        {
          if ( pNode != i->_Right )
            break;
          pNode = i;
        }
        pNode = i;
      }
      else
      {
        pNode = pNode->_Right;
        for ( j = v13->_Left; !j->_IsNil; j = j->_Left )
          pNode = j;
      }
    }
    if ( pNode == (std_Tree_node_for_tagKeyName *)this->_Mypair._Myval2._Myhead )
      goto LABEL_23;
  }
  nLength = 0;
__found:
  KeyName->bstrText1.m_Data = pNode->_Myval.second.bstrText2.m_Data;
  tagKeyName::Update((_bstr_t *)&KeyName, lpszKeyID, nLength, (_bstr_t *)&pNode->_Myval.second.dwValue);
  v19 = (Data_t_bstr_t *)KeyName;
  bstrKeyId.m_Data->m_wstr = (BSTR)KeyName;
  if ( v19 )
  {
    InterlockedIncrement(&v19->m_RefCount);
    v20 = KeyName;
    if ( KeyName )
    {
      if ( !InterlockedDecrement(&KeyName->dwValue) && v20 )
      {
        if ( v20->bstrText1.m_Data )
        {
          SysFreeString((BSTR)v20->bstrText1.m_Data);
          v20->bstrText1.m_Data = 0;
        }
        if ( v20->bstrText2.m_Data )
        {
          operator delete[](v20->bstrText2.m_Data);
          v20->bstrText2.m_Data = 0;
        }
        operator delete(v20);
      }
    }
  }
  return (int)bstrKeyId.m_Data;
}

//----- (00BE6640) --------------------------------------------------------
void *__cdecl PE_OpenFile(const wchar_t *lpszKeyName, unsigned int dwDesiredAccess, unsigned int dwShareMode, _SECURITY_ATTRIBUTES *lpSecurityAttributes, unsigned int dwCreationDisposition, unsigned int dwFlagsAndAttributes, void *hTemplateFile)
{
  tagKeyName *KeyName; // esi
  tagKeyName *pszFileName; // ebx
  HANDLE v9; // edi

  sub_BE7AB0(&gKeyNameMap, (tagKeyName *)&lpszKeyName, lpszKeyName);
  KeyName = (tagKeyName *)lpszKeyName;
  if ( lpszKeyName )
    pszFileName = *(tagKeyName **)lpszKeyName;
  else
    pszFileName = 0;
  v9 = CreateFileW(
         (LPCWSTR)pszFileName,
         dwDesiredAccess,
         dwShareMode,
         lpSecurityAttributes,
         dwCreationDisposition,
         dwFlagsAndAttributes,
         hTemplateFile);
  if ( v9 == (HANDLE)-1 )
  {
    ImpersonateLoggedOnUser(ghAppToken);
    v9 = CreateFileW(
           (LPCWSTR)pszFileName,
           dwDesiredAccess,
           dwShareMode,
           lpSecurityAttributes,
           dwCreationDisposition,
           dwFlagsAndAttributes,
           hTemplateFile);
    RevertToSelf();
  }
  if ( KeyName && !InterlockedDecrement(&KeyName->dwValue) )
  {
    if ( KeyName->bstrText1.m_Data )
    {
      SysFreeString((BSTR)KeyName->bstrText1.m_Data);
      KeyName->bstrText1.m_Data = 0;
    }
    if ( KeyName->bstrText2.m_Data )
    {
      operator delete[](KeyName->bstrText2.m_Data);
      KeyName->bstrText2.m_Data = 0;
    }
    operator delete(KeyName);
  }
  return v9;
}

//----- (00BE6700) --------------------------------------------------------
#error "BE6700: local variable allocation failed (funcsize=61)"

//----- (00BE67A0) --------------------------------------------------------
int __cdecl PE_OpenKey(HKEY bstrSlash, LPCWSTR lpszKeyName, LONG CreateOptions, DWORD DesiredAccess, PHKEY KeyHandle)
{
  Data_t_bstr_t *bstrKeyName_1; // esi
  HKEY RootDirectory; // ebx
  tagKeyName *pKeyName; // edi
  _bstr_t *v8; // ebx
  WORD *pszObjectName; // edx
  _bstr_t *v10; // eax
  _bstr_t *v11; // eax
  _bstr_t *v12; // eax
  _bstr_t *v13; // ebx
  _bstr_t *v14; // ebx
  _bstr_t *v15; // ebx
  char *v16; // ecx
  __int16 v17; // ax
  int nLength; // ecx
  int v19; // eax
  int dwError; // ebx
  int Status; // eax
  int v22; // eax
  LONG (__stdcall *v23)(volatile LONG *); // ecx
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+10h] [ebp-44h]
  UNICODE_STRING strObjectName; // [esp+28h] [ebp-2Ch]
  ULONG Disposition; // [esp+30h] [ebp-24h]
  tagPEStringStruct StringItem; // [esp+34h] [ebp-20h]
  int nStep; // [esp+50h] [ebp-4h]

  bstrKeyName_1 = 0;
  StringItem.strValue[4] = 0;
  nStep = 0;
  std::map<wchar_t const *,_bstr_t,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>>::_Try_emplace<wchar_t const * const &,>(
    &gKeyNameMap,
    (_bstr_t)&lpszKeyName,
    (tagKeyName *)&bstrSlash,

    bstrSlash,
    (OLECHAR *)lpszKeyName);
  RootDirectory = bstrSlash;
  pKeyName = (tagKeyName *)lpszKeyName;
  LOBYTE(nStep) = 1;
  if ( bstrSlash != HKEY_LOCAL_MACHINE )
  {
    if ( bstrSlash == HKEY_CURRENT_USER )
    {
      // \\Registry\\Users\\#szUserName#\\lpszKeyName
      _bstr_t::_bstr_t((tagEventSetItem *)&bstrSlash, L"\\");
      LOBYTE(nStep) = 2;
      v10 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&StringItem, gpAccountInfo->szUserName);
      LOBYTE(nStep) = 3;
      v11 = _bstr_t::operator+((_bstr_t *)&StringItem.strValue[1], L"\\Registry\\User\\", v10);
      LOBYTE(nStep) = 4;
      v12 = _bstr_t::operator+(v11, (_bstr_t *)&StringItem.strValue[2], (_bstr_t *)&bstrSlash);
      LOBYTE(nStep) = 5;
      v13 = _bstr_t::operator+(v12, (_bstr_t *)&StringItem.strValue[3], (_bstr_t *)&lpszKeyName);
      if ( &StringItem.strValue[4] != (int *)v13 )
      {
        _bstr_t::_Free((_bstr_t *)&StringItem.strValue[4]);
        bstrKeyName_1 = v13->m_Data;
        StringItem.strValue[4] = (int)bstrKeyName_1;
        if ( bstrKeyName_1 )
          InterlockedIncrement(&bstrKeyName_1->m_RefCount);
      }
      _bstr_t::_Free((_bstr_t *)&StringItem.strValue[3]);
      _bstr_t::_Free((_bstr_t *)&StringItem.strValue[2]);
      _bstr_t::_Free((_bstr_t *)&StringItem.strValue[1]);
      _bstr_t::_Free((_bstr_t *)&StringItem);
      LOBYTE(nStep) = 1;
      _bstr_t::_Free((_bstr_t *)&bstrSlash);
      RootDirectory = 0;
      if ( bstrKeyName_1 )
      {
        pszObjectName = bstrKeyName_1->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( bstrSlash == HKEY_CLASSES_ROOT )
    {
      v14 = _bstr_t::operator+(
              (_bstr_t *)&bstrSlash,
              L"\\Registry\\Machine\\Software\\Classes\\",
              (_bstr_t *)&lpszKeyName);
      if ( &StringItem.strValue[4] != (int *)v14 )
      {
        _bstr_t::_Free((_bstr_t *)&StringItem.strValue[4]);
        bstrKeyName_1 = v14->m_Data;
        StringItem.strValue[4] = (int)bstrKeyName_1;
        if ( bstrKeyName_1 )
          InterlockedIncrement(&bstrKeyName_1->m_RefCount);
      }
      _bstr_t::_Free((_bstr_t *)&bstrSlash);
      RootDirectory = 0;
      if ( bstrKeyName_1 )
      {
        pszObjectName = bstrKeyName_1->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( bstrSlash == HKEY_USERS )
    {
      v15 = _bstr_t::operator+((_bstr_t *)&bstrSlash, L"\\Registry\\User\\", (_bstr_t *)&lpszKeyName);
      if ( &StringItem.strValue[4] != (int *)v15 )
      {
        _bstr_t::_Free((_bstr_t *)&StringItem.strValue[4]);
        bstrKeyName_1 = v15->m_Data;
        StringItem.strValue[4] = (int)bstrKeyName_1;
        if ( bstrKeyName_1 )
          InterlockedIncrement(&bstrKeyName_1->m_RefCount);
      }
      _bstr_t::_Free((_bstr_t *)&bstrSlash);
      RootDirectory = 0;
      if ( bstrKeyName_1 )
      {
        pszObjectName = bstrKeyName_1->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( lpszKeyName )
    {
      pszObjectName = *(WORD **)lpszKeyName;
      goto LABEL_28;
    }
LABEL_27:
    pszObjectName = 0;
    goto LABEL_28;
  }
  v8 = _bstr_t::operator+((_bstr_t *)&bstrSlash, L"\\Registry\\Machine\\", (_bstr_t *)&lpszKeyName);
  if ( &StringItem.strValue[4] != (int *)v8 )
  {
    _bstr_t::_Free((_bstr_t *)&StringItem.strValue[4]);
    bstrKeyName_1 = v8->m_Data;
    StringItem.strValue[4] = (int)bstrKeyName_1;
    if ( bstrKeyName_1 )
      InterlockedIncrement(&bstrKeyName_1->m_RefCount);
  }
  _bstr_t::_Free((_bstr_t *)&bstrSlash);
  RootDirectory = 0;
  if ( !bstrKeyName_1 )
    goto LABEL_27;
  pszObjectName = bstrKeyName_1->m_wstr;
LABEL_28:
  v16 = (char *)pszObjectName;
  bstrSlash = (HKEY)(pszObjectName + 1);
  do
  {
    v17 = *(_WORD *)v16;
    v16 += 2;
  }
  while ( v17 );
  nLength = (v16 - (char *)bstrSlash) >> 1;
  strObjectName.Buffer = pszObjectName;
  ObjectAttributes.Length = 24;
  ObjectAttributes.RootDirectory = RootDirectory;
  ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
  strObjectName.MaximumLength = 2 * nLength;
  strObjectName.Length = 2 * nLength;
  ObjectAttributes.ObjectName = &strObjectName;
  ObjectAttributes.SecurityDescriptor = 0;
  ObjectAttributes.SecurityQualityOfService = 0;
  v19 = NtOpenKey((PHANDLE)KeyHandle, DesiredAccess, &ObjectAttributes);
  dwError = RtlNtStatusToDosError(v19);
  if ( dwError == ERROR_ACCESS_DENIED )
  {
    Status = NtCreateKey(
               (PHANDLE)KeyHandle,
               DesiredAccess,
               &ObjectAttributes,
               0,
               0,
               CreateOptions | REG_OPTION_BACKUP_RESTORE,
               &Disposition);
    dwError = RtlNtStatusToDosError(Status);
    if ( dwError == ERROR_ACCESS_DENIED )
    {
      if ( ghAppToken )
      {
        ImpersonateLoggedOnUser(ghAppToken);
        v22 = NtOpenKey((PHANDLE)KeyHandle, DesiredAccess, &ObjectAttributes);
        dwError = RtlNtStatusToDosError(v22);
        RevertToSelf();
      }
    }
  }
  v23 = InterlockedDecrement;
  if ( pKeyName )
  {
    if ( !InterlockedDecrement(&pKeyName->dwValue) )
    {
      if ( pKeyName->bstrText1.m_Data )
      {
        SysFreeString((BSTR)pKeyName->bstrText1.m_Data);
        pKeyName->bstrText1.m_Data = 0;
      }
      if ( pKeyName->bstrText2.m_Data )
      {
        operator delete[](pKeyName->bstrText2.m_Data);
        pKeyName->bstrText2.m_Data = 0;
      }
      operator delete(pKeyName);
    }
    v23 = InterlockedDecrement;
  }
  if ( bstrKeyName_1 && !v23(&bstrKeyName_1->m_RefCount) )
  {
    if ( bstrKeyName_1->m_wstr )
    {
      SysFreeString(bstrKeyName_1->m_wstr);
      bstrKeyName_1->m_wstr = 0;
    }
    if ( bstrKeyName_1->m_str )
    {
      operator delete[](bstrKeyName_1->m_str);
      bstrKeyName_1->m_str = 0;
    }
    operator delete(bstrKeyName_1);
  }
  return dwError;
}

//----- (00BE6B30) --------------------------------------------------------
HANDLE AdjustRighToWinLogon()
{
  HANDLE result; // eax
  HANDLE hFound; // edi
  const wchar_t *szExeFile; // esi
  wchar_t *pstr; // eax
  HANDLE ProcessHandle; // esi
  HANDLE phNewToken; // [esp+0h] [ebp-238h]
  HANDLE TokenHandle; // [esp+4h] [ebp-234h]
  PROCESSENTRY32W ProcessEntry; // [esp+8h] [ebp-230h]

  result = (HANDLE)TmAdjustPrivilege(L"SeDebugPrivilege");
  if ( result )
  {
    result = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    hFound = result;
    if ( result )
    {
      ProcessEntry.dwSize = sizeof(PROCESSENTRY32W);
      if ( Process32FirstW(result, &ProcessEntry) )
      {
        while ( 1 )
        {
          szExeFile = ProcessEntry.szExeFile;
          if ( !wcsrchr(ProcessEntry.szExeFile, '\\')
            || (pstr = wcsrchr(ProcessEntry.szExeFile, '\\'), szExeFile = pstr + 1, pstr != (wchar_t *)0xFFFFFFFE) )
          {
            if ( !_wcsicmp(szExeFile, L"winlogon.exe") )
              break;
          }
          if ( !Process32NextW(hFound, &ProcessEntry) )
            return (HANDLE)CloseHandle(hFound);
        }
        ProcessHandle = OpenProcess(PROCESS_QUERY_INFORMATION, 0, ProcessEntry.th32ProcessID);
        if ( ProcessHandle )
        {
          TokenHandle = 0;
          if ( OpenProcessToken(ProcessHandle, TokenStatistics, &TokenHandle) )
          {
            if ( DuplicateTokenEx(
                   TokenHandle,
                   TOKEN_ALL_ACCESS,
                   0,
                   SecurityImpersonation,
                   TokenImpersonation,
                   &phNewToken) )
            {
              TmAdjustPrivilege(L"SeImpersonatePrivilege");
              if ( ImpersonateLoggedOnUser(phNewToken) )
              {
                TmAdjustPrivilege(L"SeSecurityPrivilege");
                TmAdjustPrivilege(L"SeDebugPrivilege");
                TmAdjustPrivilege(L"SeBackupPrivilege");
                RevertToSelf();
              }
              CloseHandle(phNewToken);
            }
            CloseHandle(TokenHandle);
          }
          CloseHandle(ProcessHandle);
        }
      }
      result = (HANDLE)CloseHandle(hFound);
    }
  }
  return result;
}

//----- (00BE6CC0) --------------------------------------------------------
char __cdecl sub_BE6CC0(WCHAR *pszText1, StringItem *pszText2)
{
  const wchar_t ***v2; // ebx
  void *v3; // esi
  StringItem *v4; // ecx
  void **v5; // edi
  void **v6; // esi
  char result; // al
  void *v8; // [esp+10h] [ebp-20h]
  int a2a; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+18h] [ebp-18h]
  char v11; // [esp+23h] [ebp-Dh]
  int v12; // [esp+2Ch] [ebp-4h]

  v8 = 0;
  a2a = 0;
  v10 = 0;
  v12 = 0;
  sub_BE6DD0(pszText1, 0, (int)&v8, 0);
  v2 = (const wchar_t ***)v8;
  v3 = (void *)pszText2->strText;
  if ( (a2a - (_DWORD)v8) & 0xFFFFFFF0 )
  {
    pszText2->strText = (int)_wcsdup(*(const wchar_t **)v8);
    free(v3);
    sub_BE38F0(&pszText2->arrTexts, v2 + 1);
    result = 1;
  }
  else
  {
    pszText2->strText = (int)_wcsdup((const wchar_t *)&gszNullString);
    free(v3);
    v4 = pszText2;
    v5 = (void **)pszText2->arrTexts.baseclass_0._Mypair._Myval2._Mylast;
    v6 = (void **)pszText2->arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
    if ( v6 != v5 )
    {
      do
      {
        free(*v6);
        ++v6;
      }
      while ( v6 != v5 );
      v4 = pszText2;
    }
    v4->arrTexts.baseclass_0._Mypair._Myval2._Mylast = v4->arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
    result = 0;
  }
  v11 = result;
  if ( v2 )
  {
    sub_BE2BF0((int)v2, a2a);
    operator delete(v2);
    result = v11;
  }
  return result;
}

//----- (00BE6DD0) --------------------------------------------------------
void __cdecl sub_BE6DD0(wchar_t *a1, int a2, int a3, int a4)
{
  wchar_t **v4; // esi
  char *v5; // ebx
  __int16 v6; // di
  wchar_t *v7; // eax
  char v8; // al
  wchar_t *v9; // edi
  char v10; // al
  wchar_t *v11; // esi
  wchar_t *v12; // edi
  int v13; // edi
  wchar_t *v14; // eax
  wchar_t *v15; // esi
  void **v16; // ecx
  void *v17; // esi
  wchar_t *v18; // edi
  void **i; // esi
  StringItem StringItem; // [esp+10h] [ebp-34h]
  wchar_t *v21; // [esp+20h] [ebp-24h]
  wchar_t *v22; // [esp+24h] [ebp-20h]
  int v23; // [esp+28h] [ebp-1Ch]
  wchar_t *v24; // [esp+2Ch] [ebp-18h]
  wchar_t *v25; // [esp+30h] [ebp-14h]
  char v26; // [esp+37h] [ebp-Dh]
  int v27; // [esp+40h] [ebp-4h]

  sub_BE2BF0(*(_DWORD *)a3, *(_DWORD *)(a3 + 4));
  *(_DWORD *)(a3 + 4) = *(_DWORD *)a3;
  v24 = a1;
  StringItem.strText = (int)malloc(2u);
  v4 = 0;
  StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myend = 0;
  StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst = 0;
  v5 = 0;
  *(_WORD *)StringItem.strText = 0;
  StringItem.arrTexts.baseclass_0._Mypair._Myval2._Mylast = 0;
  v6 = a4;
  v27 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = (wchar_t *)malloc(2u);
      v25 = v7;
      *v7 = 0;
      LOBYTE(v27) = 1;
      LOBYTE(v23) = ((v5 - (char *)v4) & 0xFFFFFFFC) == 0;
      v8 = sub_BE5860(&v24, a2, (const wchar_t **)&v25, v23);
      v26 = v8;
      if ( v6 )
      {
        v22 = (wchar_t *)malloc(2u);
        *v22 = 0;
        v9 = v24;
        LOBYTE(v27) = 2;
        v21 = v24;
        v10 = sub_BE5860(&v21, a4, (const wchar_t **)&v22, v23);
        v11 = v22;
        if ( v10 )
        {
          if ( v26 )
          {
            if ( v21 < v9 )
            {
              v24 = v21;
              v12 = v25;
              v25 = _wcsdup(v22);
              free(v12);
            }
          }
          else
          {
            v26 = 1;
          }
        }
        LOBYTE(v27) = 1;
        free(v11);
        v4 = (wchar_t **)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
        v8 = v26;
      }
      if ( !v8 )
      {
        v15 = v24;
        break;
      }
      if ( &v25 >= (wchar_t **)v5 || v4 > &v25 )
      {
        if ( v5 == StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myend )
        {
          std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(&StringItem.arrTexts, 1u);
          v5 = (char *)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Mylast;
        }
        if ( v5 )
        {
          v14 = _wcsdup(v25);
          goto LABEL_20;
        }
      }
      else
      {
        v13 = &v25 - v4;
        if ( v5 == StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myend )
        {
          std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(&StringItem.arrTexts, 1u);
          v5 = (char *)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Mylast;
          v4 = (wchar_t **)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
        }
        if ( v5 )
        {
          v14 = _wcsdup(v4[v13]);
LABEL_20:
          *(_DWORD *)v5 = v14;
          goto LABEL_21;
        }
      }
LABEL_21:
      v15 = v24;
      v5 += 4;
      StringItem.arrTexts.baseclass_0._Mypair._Myval2._Mylast = v5;
      if ( *v24 == (_WORD)a2 )
        break;
      v6 = a4;
      if ( *v24 == (_WORD)a4 )
        break;
      v4 = (wchar_t **)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
      free(v25);
    }
    v16 = (void **)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
    if ( (v5 - (char *)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC )
    {
      v17 = (void *)StringItem.strText;
      v18 = _wcsdup(a1);
      StringItem.strText = (int)v18;
      free(v17);
      v15 = v24;
      v18[v24 - a1] = 0;
      sub_BF0460((int *)a3, &StringItem);
      v5 = (char *)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Mylast;
      v16 = (void **)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
    }
    if ( !*v15 )
      break;
    v24 = v15 + 1;
    for ( i = v16; i != (void **)v5; ++i )
      free(*i);
    v4 = (wchar_t **)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
    v5 = (char *)StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
    a1 = v24;
    v6 = a4;
    StringItem.arrTexts.baseclass_0._Mypair._Myval2._Mylast = StringItem.arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
    free(v25);
  }
  free(v25);
  StringItem::~StringItem((tagPEStringStruct *)&StringItem);
}

//----- (00BE7040) --------------------------------------------------------
void __cdecl sub_BE7040(wchar_t *a1, StringItem *a2)
{
  void **v2; // edi
  void **i; // esi
  void *v4; // esi
  CCmdString a2a; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v2 = (void **)a2->arrTexts.baseclass_0._Mypair._Myval2._Mylast;
  for ( i = (void **)a2->arrTexts.baseclass_0._Mypair._Myval2._Myfirst; i != v2; ++i )
    free(*i);
  a2->arrTexts.baseclass_0._Mypair._Myval2._Mylast = a2->arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
  sub_BEF8D0(&a2a, a1);
  v6 = 0;
  v4 = (void *)a2->strText;
  a2->strText = (int)_wcsdup(a1);
  free(v4);
  sub_BF0530(&a2->arrTexts, (const wchar_t **)&a2a.m_String);
  free(a2a.m_String);
}

//----- (00BE70E0) --------------------------------------------------------
CCmdString *__cdecl sub_BE70E0(CCmdString *strRet, HWND hWnd, StringItem *pStringItem, WCHAR *lpszText)
{
  int nCount; // ecx
  CCmdString strCmd1; // edi
  CCmdString strCmd2; // esi
  wchar_t *pszFirstText; // ebx
  WCHAR *v9; // edi
  WCHAR *v10; // eax
  CCmdString strCmd9; // ebx
  CCmdString strCmd7; // edi
  int nOffset; // ecx
  WCHAR *v14; // ecx
  WCHAR v15; // ax
  CCmdString *v16; // eax
  WCHAR *v17; // edx
  unsigned int v18; // eax
  CCmdString strCmd5; // esi
  LSTATUS v20; // eax
  wchar_t *v21; // eax
  wchar_t *v22; // ecx
  WCHAR *pszFullPathName; // esi
  DWORD v24; // eax
  WCHAR *v25; // eax
  WCHAR *v26; // eax
  CCmdString *v27; // eax
  wchar_t *v28; // eax
  const wchar_t **v29; // eax
  const wchar_t **v30; // eax
  WCHAR *v31; // eax
  WCHAR *i; // ecx
  WCHAR *v33; // edi
  CCmdString v34; // edi
  wchar_t *v35; // eax
  WCHAR *v36; // ecx
  WCHAR v37; // ax
  wchar_t *v38; // eax
  CCmdString *v39; // eax
  CCmdString v40; // esi
  CCmdString *v41; // eax
  WCHAR *v42; // esi
  wchar_t *v43; // eax
  CCmdString v44; // ST24_4
  wchar_t *v45; // eax
  CCmdString v46; // ST24_4
  void *v47; // [esp-8h] [ebp-8Ch]
  wchar_t *v48; // [esp-4h] [ebp-88h]
  int v49; // [esp+10h] [ebp-74h]
  StringItem StringItemLocal; // [esp+14h] [ebp-70h]
  CCmdString v51; // [esp+24h] [ebp-60h]
  WCHAR *v52; // [esp+28h] [ebp-5Ch]
  CCmdString a1a; // [esp+2Ch] [ebp-58h]
  wchar_t *a2a; // [esp+30h] [ebp-54h]
  HKEY hKey; // [esp+34h] [ebp-50h]
  int hWndIn; // [esp+38h] [ebp-4Ch]
  CCmdString strCmd10; // [esp+3Ch] [ebp-48h]
  CCmdString strCmd8; // [esp+40h] [ebp-44h]
  CCmdString strText; // [esp+44h] [ebp-40h]
  WCHAR *pszResult; // [esp+48h] [ebp-3Ch]
  CCmdString strCmd3; // [esp+4Ch] [ebp-38h]
  StringItem *pStringItemIn; // [esp+50h] [ebp-34h]
  WCHAR **v63; // [esp+54h] [ebp-30h]
  CCmdString *strRes; // [esp+58h] [ebp-2Ch]
  CCmdString psz; // [esp+5Ch] [ebp-28h]
  CCmdString strCmd4; // [esp+60h] [ebp-24h]
  DWORD nBufferLength; // [esp+64h] [ebp-20h]
  CCmdString strFileName; // [esp+68h] [ebp-1Ch]
  CCmdString strCmd6; // [esp+6Ch] [ebp-18h]
  int v70; // [esp+80h] [ebp-4h]

  hWndIn = (int)hWnd;
  nCount = pStringItem->arrTexts.baseclass_0._Mypair._Myval2._Mylast
         - pStringItem->arrTexts.baseclass_0._Mypair._Myval2._Myfirst;
  strRes = strRet;
  pStringItemIn = pStringItem;
  pszResult = lpszText;
  LOBYTE(a1a.m_String) = (_BYTE)lpszText;
  v49 = 0;
  if ( !(nCount & 0xFFFFFFFC) )
  {
    strRet->m_String = _wcsdup(L"<bad command>");
    return strRet;
  }
  strCmd10.m_String = _wcsdup(*(const wchar_t **)pStringItem->arrTexts.baseclass_0._Mypair._Myval2._Myfirst);
  v70 = 0;
  strFileName.m_String = (WCHAR *)malloc(2u);
  *strFileName.m_String = 0;
  strCmd1.m_String = (WCHAR *)malloc(2u);
  v63 = (WCHAR **)strCmd1.m_String;
  *strCmd1.m_String = 0;
  strCmd2.m_String = (WCHAR *)malloc(2u);
  strCmd8.m_String = strCmd2.m_String;
  *strCmd2.m_String = 0;
  pszFirstText = _wcsdup(*(const wchar_t **)pStringItem->arrTexts.baseclass_0._Mypair._Myval2._Myfirst);
  strText.m_String = pszFirstText;
  a2a = pszFirstText;
  strCmd4.m_String = _wcsdup(pszFirstText);
  _wcsupr(strCmd4.m_String);
  if ( !wcsncmp(strCmd4.m_String, L"\\??\\", 4u) )
  {
    v48 = pszFirstText + 4;
LABEL_8:
    v10 = _wcsdup(v48);
    v47 = strCmd1.m_String;
    goto LABEL_9;
  }
  if ( wcsncmp(strCmd4.m_String, L"\\SYSTEMROOT\\", 12u) )
  {
    v48 = pszFirstText;
    goto LABEL_8;
  }
  v9 = strFileName.m_String;
  strFileName.m_String = _wcsdup(gszWindowsDirectory);
  free(v9);
  CCmdString::InsertAt(&strFileName, L"\\", 0x7FFFFFFFu, 0);
  CCmdString::InsertAt(&strFileName, pszFirstText + 12, 0x7FFFFFFFu, 0);
  v10 = _wcsdup(strFileName.m_String);
  v47 = v63;
LABEL_9:
  strCmd9.m_String = v10;
  v52 = v10;
  free(v47);
  strCmd7.m_String = _wcsdup(strCmd9.m_String);
  v51.m_String = strCmd7.m_String;
  LOBYTE(v70) = 6;
  _wcsupr(strCmd7.m_String);
  if ( TlsGetValue(gdwTlsIndex) == (LPVOID)256 && wcsstr(strCmd7.m_String, L"%PROGRAMFILES%") )
  {
    nOffset = wcsstr(strCmd7.m_String, L"%PROGRAMFILES%") - strCmd7.m_String;
    _mm_storeu_si128((__m128i *)&strCmd9.m_String[nOffset], _mm_loadu_si128((const __m128i *)L"%ProgramW6432%"));
    _mm_storel_epi64((__m128i *)&strCmd9.m_String[nOffset + 8], _mm_loadl_epi64((const __m128i *)L"W6432%"));
    *(_DWORD *)&strCmd9.m_String[nOffset + 12] = *(_DWORD *)L"2%";
    v14 = &strCmd9.m_String[nOffset + 14];
    do
    {
      v15 = *v14;
      ++v14;
      *(v14 - 1) = v15;
    }
    while ( v15 );
  }
  v16 = RequerySystemEnvironmentString(&psz, (CCmdString *)strCmd9.m_String);
  v63 = (WCHAR **)strFileName.m_String;
  strFileName.m_String = _wcsdup(v16->m_String);
  free(v63);
  free(psz.m_String);
  v17 = (WCHAR *)malloc(2u);
  strCmd6.m_String = v17;
  strCmd3.m_String = v17;
  *v17 = 0;
  LOBYTE(v70) = 7;
  if ( !*strFileName.m_String )
    goto LABEL_64;
  psz.m_String = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\");
  LOBYTE(v70) = 8;
  CCmdString::InsertAt(&psz, strText.m_String, 0x7FFFFFFFu, 0);
  v18 = (unsigned int)TlsGetValue(gdwTlsIndex);
  strCmd5.m_String = psz.m_String;
  if ( !PE_OpenKey(ghLocalMachineKey, psz.m_String, 0, v18 | 0x20019, &hKey) )
  {
    v20 = PE_LoadStrKey(hKey, 0, &strFileName.m_String);
    v48 = (wchar_t *)hKey;
    if ( !v20 )
    {
      RegCloseKey((HKEY)v48);
      v21 = _wcsdup(strFileName.m_String);
      strRes->m_String = v21;
      free(strCmd5.m_String);
      free(strCmd6.m_String);
      free(strCmd7.m_String);
      free(strCmd4.m_String);
      free(strText.m_String);
      free(strCmd8.m_String);
      free(strCmd9.m_String);
      free(strFileName.m_String);
      free(strCmd10.m_String);
      return strRes;
    }
    RegCloseKey((HKEY)v48);
  }
  v63 = (WCHAR **)_wcsdup(strFileName.m_String);
  strCmd3.m_String = (WCHAR *)v63;
  free(strCmd6.m_String);
  if ( (_BYTE)pszResult || gbFlagsInPE_GetLongPathName )
  {
LABEL_36:
    v26 = strFileName.m_String;
    if ( *strFileName.m_String == '\\' && strFileName.m_String[1] != '\\' )
    {
      wcsncpy_s((wchar_t *)&strCmd6, 3u, gszWindowsDirectory, 2u);
      v27 = operator+((CCmdString *)&pszResult, (LPCWSTR)&strCmd6, &strFileName);
      nBufferLength = (DWORD)strFileName.m_String;
      strFileName.m_String = _wcsdup(v27->m_String);
      free((void *)nBufferLength);
      free(pszResult);
      v26 = strFileName.m_String;
    }
    v48 = v22;
    nBufferLength = (DWORD)&v48;
    v28 = _wcsdup(v26);
    *(_DWORD *)nBufferLength = v28;
    v29 = (const wchar_t **)PE_GetSystemPathInfo(&pszResult, v48);
    nBufferLength = (DWORD)strFileName.m_String;
    strFileName.m_String = _wcsdup(*v29);
    free((void *)nBufferLength);
    free(pszResult);
    v48 = strFileName.m_String;
    if ( gbFlagsInPE_GetLongPathName )
    {
      strCmd6.m_String = _wcsdup(v48);
      strCmd3.m_String = strCmd6.m_String;
      free(v63);
    }
    else
    {
      v30 = (const wchar_t **)PE_GetLongPathName((CCmdString *)&nBufferLength, v48);
      strCmd6.m_String = _wcsdup(*v30);
      strCmd3.m_String = strCmd6.m_String;
      free(v63);
      free((void *)nBufferLength);
    }
    _wcslwr(strCmd6.m_String);
    LOBYTE(v70) = 7;
    free(strCmd5.m_String);
    strCmd2.m_String = strCmd8.m_String;
    v17 = strCmd6.m_String;
LABEL_64:
    v36 = v17;
    nBufferLength = (DWORD)(v17 + 1);
    do
    {
      v37 = *v36;
      ++v36;
    }
    while ( v37 );
    if ( (signed int)((signed int)v36 - nBufferLength) >> 1 )
    {
      v48 = (wchar_t *)pStringItemIn;
      v38 = _wcsdup(v17);
      v39 = sub_BE5520((CCmdString *)&nBufferLength, v38, (StringItem *)v48);
      v40.m_String = _wcsdup(v39->m_String);
      a2a = v40.m_String;
      free(strText.m_String);
      free((void *)nBufferLength);
      if ( wcslen(v40.m_String) )
      {
        StringItemLocal.strText = (int)malloc(2u);
        *(_WORD *)StringItemLocal.strText = 0;
        StringItemLocal.arrTexts.baseclass_0._Mypair._Myval2._Myfirst = 0;
        StringItemLocal.arrTexts.baseclass_0._Mypair._Myval2._Mylast = 0;
        StringItemLocal.arrTexts.baseclass_0._Mypair._Myval2._Myend = 0;
        LOBYTE(v70) = 10;
        sub_BF0530(&StringItemLocal.arrTexts, (const wchar_t **)&a2a);
        v41 = sub_BE70E0(&a1a, (HWND)hWndIn, &StringItemLocal, a1a.m_String);
        v42 = strCmd6.m_String;
        strCmd6.m_String = _wcsdup(v41->m_String);
        free(v42);
        free(a1a.m_String);
        StringItem::~StringItem((tagPEStringStruct *)&StringItemLocal);
        v40.m_String = a2a;
      }
      v43 = _wcsdup(strCmd6.m_String);
      v44.m_String = strCmd6.m_String;
      strRes->m_String = v43;
      free(v44.m_String);
      free(strCmd7.m_String);
      free(strCmd4.m_String);
      free(v40.m_String);
      free(strCmd8.m_String);
    }
    else
    {
      v45 = _wcsdup((const wchar_t *)&gszNullString);
      v46.m_String = strCmd6.m_String;
      strRes->m_String = v45;
      free(v46.m_String);
      free(strCmd7.m_String);
      free(strCmd4.m_String);
      free(strText.m_String);
      free(strCmd2.m_String);
    }
    free(strCmd9.m_String);
    free(strFileName.m_String);
    free(strCmd10.m_String);
    return strRes;
  }
  while ( 1 )
  {
    pszFullPathName = _wcsdup(strFileName.m_String);
    pszResult = pszFullPathName;
    LOBYTE(v70) = 9;
    if ( wcsstr(strFileName.m_String, L"..") )
    {
      v24 = GetFullPathNameW(strFileName.m_String, 0, 0, 0);
      nBufferLength = v24;
      if ( v24 )
      {
        strCmd6.m_String = (WCHAR *)(2 * v24 + 2);
        v25 = (WCHAR *)realloc(pszFullPathName, (size_t)strCmd6.m_String);
        pszFullPathName = v25;
        pszResult = v25;
        if ( v25 )
          memset(v25, 0, (size_t)strCmd6.m_String);
        GetFullPathNameW(strFileName.m_String, nBufferLength, pszFullPathName, 0);
      }
    }
    if ( !gbFlagsInPE_GetLongPathName )
    {
      if ( PE_GetPathName(hWndIn, gpszSystemPathInfo, pszFullPathName, &strCmd4) )
      {
        if ( !gbFlagsInPE_GetLongPathName && !(PE_GetFileAttributes(strCmd4.m_String) & 0x10) )
        {
          nBufferLength = (DWORD)strFileName.m_String;
          strFileName.m_String = _wcsdup(strCmd4.m_String);
          free((void *)nBufferLength);
          LOBYTE(v70) = 8;
          free(pszFullPathName);
          goto LABEL_35;
        }
      }
      else if ( !wcschr(pszFullPathName, 0x2Fu)
             && wcslen(pszFullPathName) > 3
             && pszFullPathName[wcslen(pszFullPathName) - 4] != '.' )
      {
        nBufferLength = (DWORD)strCmd4.m_String;
        strCmd4.m_String = _wcsdup(pszFullPathName);
        free((void *)nBufferLength);
        CCmdString::InsertAt(&strCmd4, L".exe", 0x7FFFFFFFu, 0);
        if ( gbFlagsInPE_GetLongPathName
          || PE_GetPathName(hWndIn, gpszSystemPathInfo, strCmd4.m_String, &strFileName)
          || (nBufferLength = (DWORD)strCmd4.m_String,
              strCmd4.m_String = _wcsdup(pszFullPathName),
              free((void *)nBufferLength),
              CCmdString::InsertAt(&strCmd4, L".dll", 0x7FFFFFFFu, 0),
              !gbFlagsInPE_GetLongPathName)
          && PE_GetPathName(hWndIn, gpszSystemPathInfo, strCmd4.m_String, &strFileName) )
        {
          LOBYTE(v70) = 8;
          free(pszFullPathName);
LABEL_35:
          strCmd5.m_String = psz.m_String;
          goto LABEL_36;
        }
      }
    }
    v31 = strFileName.m_String;
    for ( i = strFileName.m_String; *i == ' '; ++i )
      ;
    if ( !gbFlagsInPE_GetLongPathName )
      break;
LABEL_48:
    if ( wcsrchr(v31, ' ') )
      *wcsrchr(strFileName.m_String, ' ') = 0;
    LOBYTE(v70) = 8;
    free(pszFullPathName);
    if ( gbFlagsInPE_GetLongPathName )
      goto LABEL_35;
  }
  if ( wcschr(i, ' ') )
  {
    v31 = strFileName.m_String;
    goto LABEL_48;
  }
  v33 = strFileName.m_String;
  strFileName.m_String = _wcsdup(L"File not found: ");
  free(v33);
  CCmdString::InsertAt(&strFileName, (const wchar_t *)v63, 0x7FFFFFFFu, 0);
  v34.m_String = _wcsdup(strFileName.m_String);
  strCmd3.m_String = v34.m_String;
  free(v63);
  if ( PE_GetFileAttributes(*(OLECHAR **)pStringItemIn->arrTexts.baseclass_0._Mypair._Myval2._Myfirst) != INVALID_FILE_ATTRIBUTES
    && PE_GetFileAttributes(*(OLECHAR **)pStringItemIn->arrTexts.baseclass_0._Mypair._Myval2._Myfirst) & FILE_ATTRIBUTE_DIRECTORY )
  {
    CCmdString::Reset(&strCmd3, (CCmdString *)pStringItemIn->arrTexts.baseclass_0._Mypair._Myval2._Myfirst);
    v34.m_String = strCmd3.m_String;
  }
  else if ( !gbFlagsInPE_GetLongPathName
         && !wcsncmp(*(const wchar_t **)pStringItemIn->arrTexts.baseclass_0._Mypair._Myval2._Myfirst, L"||", 2u) )
  {
    if ( PE_GetFileAttributes((OLECHAR *)(*(_DWORD *)pStringItemIn->arrTexts.baseclass_0._Mypair._Myval2._Myfirst + 4)) == -1 )
    {
      nBufferLength = (DWORD)strFileName.m_String;
      strFileName.m_String = _wcsdup(L"File not found: ");
      free((void *)nBufferLength);
      CCmdString::InsertAt(
        &strFileName,
        (const wchar_t *)(*(_DWORD *)pStringItemIn->arrTexts.baseclass_0._Mypair._Myval2._Myfirst + 4),
        0x7FFFFFFFu,
        0);
      nBufferLength = (DWORD)v34.m_String;
      v34.m_String = _wcsdup(strFileName.m_String);
      free((void *)nBufferLength);
    }
    else
    {
      CCmdString::Reset(
        &strCmd3,
        (wchar_t *)(*(_DWORD *)pStringItemIn->arrTexts.baseclass_0._Mypair._Myval2._Myfirst + 4));
      v34.m_String = strCmd3.m_String;
    }
  }
  v35 = _wcsdup(v34.m_String);
  strRes->m_String = v35;
  free(pszFullPathName);
  free(psz.m_String);
  free(v34.m_String);
  free(v51.m_String);
  free(strCmd4.m_String);
  free(strText.m_String);
  free(strCmd8.m_String);
  free(strCmd9.m_String);
  free(strFileName.m_String);
  free(strCmd10.m_String);
  return strRes;
}
// CD3860: using guessed type char gbFlagsInPE_GetLongPathName;

//----- (00BE7AB0) --------------------------------------------------------
// tagKeyName* ret = gKeyNameMap[LPCWSTR lpszKeyName]
int __thiscall sub_BE7AB0(std__tree *this, tagKeyName *KeyName, LPCWSTR lpszKey)
{
  std::map<wchar_t const *,_bstr_t,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>>::_Try_emplace<wchar_t const * const &,>(
    this,
    (_bstr_t)KeyName,
    (tagKeyName *)&lpszKey,
    0,
    (OLECHAR *)lpszKey);
  return (int)KeyName;
}

//----- (00BE7AE0) --------------------------------------------------------
int __cdecl PE_OutputErrorMsg(DWORD dwMessageId)
{
  int result; // eax
  DWORD v2; // ebx
  _iobuf *v3; // edi
  const wchar_t *v4; // esi
  wchar_t v5; // cx
  const void *v6; // ST04_4
  HANDLE v7; // eax
  _iobuf *v8; // edi
  const wchar_t *v9; // esi
  wchar_t v10; // ax
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-8h]
  void *Buffer; // [esp+8h] [ebp-4h]

  result = FormatMessageA(0x1300u, 0, dwMessageId, 0x400u, (LPSTR)&Buffer, 0, 0);
  v2 = result;
  if ( result )
  {
    if ( sbFlagsInPE_OutputErrorMsg )
    {
      v3 = __acrt_iob_func() + 1;
      _fputwc_nolock('<', v3);
      v4 = L"error";
      v5 = 'e';
      do
      {
        _fputwc_nolock(v5, v3);
        v5 = v4[1];
        ++v4;
      }
      while ( v5 );
      _fputwc_nolock('>', v3);
    }
    v6 = Buffer;
    v7 = GetStdHandle(STD_ERROR_HANDLE);
    WriteFile(v7, v6, v2, &NumberOfBytesWritten, 0);
    if ( sbFlagsInPE_OutputErrorMsg )
    {
      v8 = __acrt_iob_func() + 1;
      _fputwc_nolock('<', v8);
      _fputwc_nolock('/', v8);
      v9 = L"error";
      v10 = 101;
      do
      {
        _fputwc_nolock(v10, v8);
        v10 = v9[1];
        ++v9;
      }
      while ( v10 );
      _fputwc_nolock('>', v8);
    }
    result = (int)LocalFree(Buffer);
  }
  return result;
}
// C9D008: using guessed type wchar_t aError[6];
// CD31C9: using guessed type char sbFlagsInPE_OutputErrorMsg;

//----- (00BE7BE0) --------------------------------------------------------
CCmdString *__cdecl MakeRegistryKeyName(CCmdString *strResult, HKEY hKey, CCmdString *strKeyName, CCmdString *strValueName)
{
  CCmdString strTemp; // eax
  CCmdString strKeyRoot; // ebx
  const wchar_t *lpszKeyRoot; // eax
  CCmdString *v7; // esi
  CCmdString *v8; // eax
  CCmdString *v9; // eax
  void *v10; // edi
  CCmdString *v11; // eax
  CCmdString str; // [esp+8h] [ebp-4h]

  strTemp.m_String = (WCHAR *)malloc(2u);
  strKeyRoot.m_String = (WCHAR *)strResult;
  strResult->m_String = strTemp.m_String;
  *strTemp.m_String = 0;
  if ( hKey == ghLocalMachineKey )
  {
    lpszKeyRoot = L"HKLM";
  }
  else
  {
    lpszKeyRoot = L"HKCU";
    if ( hKey != ghCurrentUserKey )
      lpszKeyRoot = L"?";
  }
  v7 = (CCmdString *)_wcsdup(lpszKeyRoot);
  strResult = v7;
  v8 = CCmdString::operator+(&str, (CCmdString *)&strResult, L"\\");
  v9 = CCmdString::Append((CCmdString *)&hKey, v8, strKeyName);
  v10 = *(void **)strKeyRoot.m_String;
  *(_DWORD *)strKeyRoot.m_String = _wcsdup(v9->m_String);
  free(v10);
  free(hKey);
  free(str.m_String);
  free(v7);
  if ( *strValueName->m_String )
  {
    v11 = operator+((CCmdString *)&strResult, L"\\", strValueName);
    CCmdString::InsertAt((CCmdString *)strKeyRoot.m_String, v11->m_String, 0x7FFFFFFFu, 0);
    free(strResult);
  }
  return (CCmdString *)strKeyRoot.m_String;
}
// C9D5F4: using guessed type wchar_t asc_C9D5F4[2];

//----- (00BE7CC0) --------------------------------------------------------
void __cdecl PE_LaunchRegedit(HWND hWnd, LPCWSTR pszCommandLine)
{
  WCHAR *pstr; // edi
  WCHAR *pszTemp; // ebx
  WCHAR *pszText; // esi
  WCHAR *v5; // eax
  WCHAR *v6; // esi
  CCmdString *v7; // eax
  WCHAR *v8; // eax
  unsigned int v9; // eax
  int dwRet; // eax
  wchar_t *v11; // eax
  wchar_t *v12; // esi
  CCmdString *v13; // eax
  WCHAR *v14; // eax
  wchar_t *v15; // eax
  wchar_t *v16; // esi
  CCmdString *v17; // eax
  WCHAR *v18; // eax
  HWND v19; // edi
  wchar_t *v20; // eax
  wchar_t *v21; // esi
  CCmdString *v22; // eax
  wchar_t *v23; // eax
  wchar_t *v24; // esi
  CCmdString *v25; // eax
  HWND hWndRegEdit; // ecx
  WCHAR *v27; // esi
  WCHAR *pszFileName; // eax
  CCmdString *strPathName; // eax
  HWND hWndFound; // eax
  HANDLE ProcessHandle; // eax
  HWND v32; // esi
  HWND v33; // esi
  signed int nTry; // ebx
  bool bFlags_1; // zf
  WCHAR *pstr_1; // eax
  HWND v37; // esi
  int v38; // eax
  int v39; // eax
  wchar_t v40; // ax
  wchar_t *v41; // esi
  WCHAR *v42; // ebx
  int chText; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+10h] [ebp-164h]
  struct _PROCESS_INFORMATION pi; // [esp+54h] [ebp-120h]
  wchar_t *pstr2; // [esp+64h] [ebp-110h]
  CCmdString strTemp; // [esp+68h] [ebp-10Ch]
  HWND hWndLV; // [esp+6Ch] [ebp-108h]
  HKEY hSubKey; // [esp+70h] [ebp-104h]
  CCmdString strApplicationName; // [esp+74h] [ebp-100h]
  WCHAR *strPath; // [esp+78h] [ebp-FCh]
  HWND lpszCommandLine; // [esp+7Ch] [ebp-F8h]
  DWORD strPath_1; // [esp+80h] [ebp-F4h]
  CCmdString strFullPath; // [esp+84h] [ebp-F0h]
  DEVMODEW DevMode; // [esp+88h] [ebp-ECh]
  int v56; // [esp+170h] [ebp-4h]

  hWndLV = hWnd;
  lpszCommandLine = (HWND)pszCommandLine;
  pstr2 = 0;
  pstr = (WCHAR *)malloc(2u);
  strFullPath.m_String = pstr;
  *pstr = 0;
  v56 = 0;
  pszTemp = (WCHAR *)malloc(2u);
  strTemp.m_String = pszTemp;
  *pszTemp = 0;
  pszText = (WCHAR *)malloc(2u);
  strApplicationName.m_String = pszText;
  *pszText = 0;
  LOBYTE(v56) = 2;
  DevMode.dmSize = 0xDC;
  EnumDisplaySettingsW(0, 0xFFFFFFFF, &DevMode);
  if ( *(_WORD *)lpszCommandLine == '0' )
  {
    MessageBoxW(
      hWndLV,
      L"The full name of the selected key or value is not available.",
      L"Process Explorer",
      MB_ICONWARNING);
    goto __quit;
  }
  if ( !wcsncmp((const wchar_t *)lpszCommandLine, L"HKLM", 4u) )
  {
    v5 = _wcsdup(L"\\HKEY_LOCAL_MACHINE");
    v6 = v5;
    strFullPath.m_String = v5;
    v7 = CCmdString::operator+((CCmdString *)&strPath_1, &strFullPath, (LPCWSTR)lpszCommandLine + 4);
    strPath = pstr;
    v8 = _wcsdup(v7->m_String);
    pstr = v8;
    strFullPath.m_String = v8;
    free(strPath);
    free((void *)strPath_1);
    free(v6);
    v9 = (unsigned int)TlsGetValue(gdwTlsIndex);
    dwRet = PE_OpenKey(ghLocalMachineKey, (LPCWSTR)lpszCommandLine + 5, 0, v9 | 0x20019, &hSubKey);
  }
  else if ( !wcsncmp((const wchar_t *)lpszCommandLine, L"HKCU", 4u) )
  {
    v11 = _wcsdup(L"\\HKEY_CURRENT_USER");
    v12 = v11;
    strPath_1 = (DWORD)v11;
    v13 = CCmdString::operator+((CCmdString *)&strPath, (CCmdString *)&strPath_1, (LPCWSTR)lpszCommandLine + 4);
    strPath_1 = (DWORD)pstr;
    v14 = _wcsdup(v13->m_String);
    pstr = v14;
    strFullPath.m_String = v14;
    free((void *)strPath_1);
    free(strPath);
    free(v12);
    dwRet = RegOpenKeyW(ghCurrentUserKey, (LPCWSTR)lpszCommandLine + 5, &hSubKey);
  }
  else if ( !wcsncmp((const wchar_t *)lpszCommandLine, L"HKCC", 4u) )
  {
    v15 = _wcsdup(L"\\HKEY_CURRENT_CONFIG");
    v16 = v15;
    strPath_1 = (DWORD)v15;
    v17 = CCmdString::operator+((CCmdString *)&strPath, (CCmdString *)&strPath_1, (LPCWSTR)lpszCommandLine + 4);
    strPath_1 = (DWORD)pstr;
    v18 = _wcsdup(v17->m_String);
    pstr = v18;
    strFullPath.m_String = v18;
    free((void *)strPath_1);
    free(strPath);
    free(v16);
    dwRet = RegOpenKeyW(HKEY_CURRENT_CONFIG, (LPCWSTR)lpszCommandLine + 5, &hSubKey);
  }
  else
  {
    v19 = lpszCommandLine;
    if ( !wcsncmp((const wchar_t *)lpszCommandLine, L"HKCR", 4u) )
    {
      v20 = _wcsdup(L"\\HKEY_CLASSES_ROOT");
      v21 = v20;
      strPath_1 = (DWORD)v20;
      v22 = CCmdString::operator+((CCmdString *)&strPath, (CCmdString *)&strPath_1, (LPCWSTR)lpszCommandLine + 4);
      CCmdString::Reset(&strFullPath, v22);
      free(strPath);
      free(v21);
      dwRet = RegOpenKeyW(HKEY_CLASSES_ROOT, (LPCWSTR)v19 + 5, &hSubKey);
    }
    else
    {
      if ( wcsncmp((const wchar_t *)lpszCommandLine, L"HKU", 3u) )
      {
        CCmdString::Reset(&strFullPath, (wchar_t *)lpszCommandLine);
        goto LABEL_17;
      }
      v23 = _wcsdup(L"\\HKEY_USERS");
      v24 = v23;
      strPath_1 = (DWORD)v23;
      v25 = CCmdString::operator+((CCmdString *)&strPath, (CCmdString *)&strPath_1, (LPCWSTR)lpszCommandLine + 3);
      CCmdString::Reset(&strFullPath, v25);
      free(strPath);
      free(v24);
      dwRet = RegOpenKeyW(HKEY_USERS, (LPCWSTR)v19 + 4, &hSubKey);
    }
    pstr = strFullPath.m_String;
  }
  if ( !dwRet )
  {
LABEL_17:
    RegCloseKey(hSubKey);
    CCmdString::InsertAt(&strFullPath, L"\\", 0x7FFFFFFFu, 0);
    pstr = strFullPath.m_String;
    goto LABEL_18;
  }
  pstr2 = wcsrchr(pstr, '\\') + 1;
  *wcsrchr(pstr, '\\') = 0;
LABEL_18:
  hWndRegEdit = FindWindowW(L"RegEdit_RegEdit", 0);
  lpszCommandLine = hWndRegEdit;
  if ( hWndRegEdit )
  {
    GetWindowThreadProcessId(hWndRegEdit, &strPath_1);
    ProcessHandle = OpenProcess(0, 0, strPath_1);
    pszText = strApplicationName.m_String;
    pi.hProcess = ProcessHandle;
    hWndFound = lpszCommandLine;
  }
  else
  {
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    memset(&StartupInfo, 0, sizeof(_STARTUPINFOW));
    StartupInfo.cb = sizeof(_STARTUPINFOW);
    StartupInfo.dwFlags = STARTF_USESHOWWINDOW;
    StartupInfo.wShowWindow = SW_SHOWNORMAL;
    v27 = pszTemp;
    if ( (GetVersion() & 0x80000000) == 0 )
      pszFileName = _wcsdup(L"%systemroot%\\regedit.exe");
    else
      pszFileName = _wcsdup(L"%windir%\\regedit.exe");
    pszTemp = pszFileName;
    strTemp.m_String = pszFileName;
    free(v27);
    strPathName = RequerySystemEnvironmentString((CCmdString *)&strPath, (CCmdString *)pszTemp);
    strPath_1 = (DWORD)strApplicationName.m_String;
    pszText = _wcsdup(strPathName->m_String);
    strApplicationName.m_String = pszText;
    free((void *)strPath_1);
    free(strPath);
    PE_GetFileAttributes(pszText);
    if ( CreateProcessW(pszText, pszText, 0, 0, 0, 0, 0, 0, &StartupInfo, &pi) )
    {
      WaitForInputIdle(pi.hProcess, INFINITE);
      CloseHandle(pi.hThread);
    }
    GetLastError();
    hWndFound = FindWindowW(L"RegEdit_RegEdit", 0);
    lpszCommandLine = hWndFound;
  }
  if ( hWndFound )
  {
    ShowWindow(hWndFound, SW_SHOW);
    v32 = lpszCommandLine;
    SetForegroundWindow(lpszCommandLine);
    hWndLV = FindWindowExW(v32, 0, L"SysTreeView32", 0);
    SetForegroundWindow(hWndLV);
    v33 = hWndLV;
    SetFocus(hWndLV);
    WaitForInputIdle(pi.hProcess, INFINITE);
    SendMessageW(lpszCommandLine, WM_COMMAND, 0x10288u, 0);
    WaitForInputIdle(pi.hProcess, INFINITE);
    nTry = 30;
    do
    {
      SendMessageW(v33, WM_KEYDOWN, VK_LEFT, 0);
      WaitForInputIdle(pi.hProcess, INFINITE);
      --nTry;
    }
    while ( nTry );
    bFlags_1 = *pstr == 0;
    pstr_1 = pstr;
    pszTemp = strTemp.m_String;
    pszText = strApplicationName.m_String;
    strFullPath.m_String = pstr;
    if ( !bFlags_1 )
    {
      v37 = hWndLV;
      do
      {
        v38 = *pstr_1;
        if ( v38 == '\\' )
        {
          SendMessageW(v37, WM_KEYDOWN, VK_RIGHT, 0);
        }
        else
        {
          v39 = toupper(v38);
          SendMessageW(v37, WM_CHAR, v39, 0);
        }
        WaitForInputIdle(pi.hProcess, INFINITE);
        pstr_1 = strFullPath.m_String + 1;
        strFullPath.m_String = pstr_1;
      }
      while ( *pstr_1 );
      pszText = strApplicationName.m_String;
    }
    WaitForInputIdle(pi.hProcess, INFINITE);
    if ( pstr2 )
    {
      strFullPath.m_String = (WCHAR *)FindWindowExW(lpszCommandLine, 0, L"SysListView32", 0);
      SetForegroundWindow((HWND)strFullPath.m_String);
      SetFocus((HWND)strFullPath.m_String);
      if ( DevMode.dmBitsPerPel > 8 )
        Sleep(750u);
      SendMessageW((HWND)strFullPath.m_String, WM_KEYDOWN, VK_HOME, 0);
      v40 = *pstr2;
      if ( *pstr2 )
      {
        v41 = pstr2;
        v42 = strFullPath.m_String;
        do
        {
          chText = toupper(v40);
          SendMessageW((HWND)v42, WM_CHAR, chText, 0);
          WaitForInputIdle(pi.hProcess, 0xFFFFFFFF);
          v40 = v41[1];
          ++v41;
        }
        while ( v40 );
        pszTemp = strTemp.m_String;
        pszText = strApplicationName.m_String;
      }
    }
    SetForegroundWindow(lpszCommandLine);
    SetFocus(lpszCommandLine);
    CloseHandle(pi.hProcess);
  }
  else
  {
    MessageBoxW(
      hWndLV,
      L"Error launching Regedit. Make sure you are running with Administrative rights.",
      L"Process Explorer",
      MB_ICONEXCLAMATION);
  }
__quit:
  free(pszText);
  free(pszTemp);
  free(pstr);
}
// C9D418: using guessed type wchar_t aWindirRegeditE[21];

//----- (00BE84A0) --------------------------------------------------------
CCmdString __cdecl CPEString::AppendPath(CCmdString *str, LPCWSTR lpszText)
{
  CCmdString v2; // eax
  char Ret; // bl
  unsigned int nIndex; // edi
  WCHAR *v5; // esi
  WCHAR *v6; // esi
  unsigned int i; // edx
  int v8; // eax

  v2.m_String = (WCHAR *)malloc(2u);
  Ret = 0;
  str->m_String = v2.m_String;
  nIndex = 2;
  *v2.m_String = 0;
  v5 = str->m_String;
  str->m_String = _wcsdup(lpszText);
  free(v5);
  v6 = str->m_String;
  if ( !wcsncmp(lpszText, L"File not found: ", 16u) )
    nIndex = ERROR_NO_MORE_FILES;
  for ( i = nIndex; nIndex < wcslen(lpszText); ++nIndex )
  {
    v8 = lpszText[nIndex];
    if ( v8 == '\\' )
    {
      if ( !Ret )
        v6[i++] = '\\';
      Ret = 1;
    }
    else
    {
      Ret = 0;
      v6[i++] = v8;
    }
  }
  v6[i] = lpszText[nIndex];
  free((void *)lpszText);
  return (CCmdString)str;
}

//----- (00BE85A0) --------------------------------------------------------
_bstr_t *__cdecl tagKeyName::Update(_bstr_t *ret, LPCWSTR lpszKeyName, int Off, _bstr_t *pbstr)
{
  _bstr_t *strIn; // edi
  UINT nLength; // ebx
  OLECHAR *v6; // edx
  BOOL fLengthIsZero; // eax
  int nFlags; // ecx
  _bstr_t *v10; // edi
  Data_t_bstr_t *v11; // eax
  Data_t_bstr_t *v12; // eax
  _bstr_t bstr1; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]

  ret->m_Data = 0;
  strIn = pbstr;
  v15 = 0;
  v14 = 1;
  if ( pbstr->m_Data && pbstr->m_Data->m_wstr )
    nLength = SysStringLen(pbstr->m_Data->m_wstr);
  else
    nLength = 0;
  v6 = (OLECHAR *)lpszKeyName;
  fLengthIsZero = nLength != 0;
  nFlags = (*lpszKeyName != 0) - fLengthIsZero;
  if ( nFlags == -1 )
  {
    if ( ret != strIn )
    {
      _bstr_t::_Free(ret);
      v12 = strIn->m_Data;
      ret->m_Data = strIn->m_Data;
      if ( v12 )
        InterlockedIncrement(&v12->m_RefCount);
    }
    return ret;
  }
  if ( (*lpszKeyName != 0) != fLengthIsZero )
  {
    if ( nFlags == 1 )
    {
      if ( Off )
        v6 = (OLECHAR *)&lpszKeyName[Off + 1];
      _bstr_t::operator=((EventItem *)ret, v6);
      return ret;
    }
    return ret;
  }
  _bstr_t::_bstr_t((tagEventSetItem *)&pbstr, (OLECHAR *)&lpszKeyName[Off]);
  v15 = 1;
  v10 = _bstr_t::operator+(strIn, &bstr1, (_bstr_t *)&pbstr);
  if ( ret != v10 )
  {
    _bstr_t::_Free(ret);
    v11 = v10->m_Data;
    ret->m_Data = v10->m_Data;
    if ( v11 )
      InterlockedIncrement(&v11->m_RefCount);
  }
  _bstr_t::_Free(&bstr1);
  _bstr_t::_Free((_bstr_t *)&pbstr);
  return ret;
}

//----- (00BE86F0) --------------------------------------------------------
void __cdecl sub_BE86F0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BE87A0(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BE87A0(a1, a2, v7, v5);
  free(v7);
}

//----- (00BE87A0) --------------------------------------------------------
void *__cdecl sub_BE87A0(int a1, void *a2, wchar_t *psz, void *a4)
{
  _WORD *v4; // ebx
  wchar_t *v5; // esi
  const wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *v8; // ebx
  WCHAR *v9; // eax
  WCHAR *v10; // edi
  const wchar_t *v11; // eax
  wchar_t *v12; // esi
  CCmdString *v13; // eax
  unsigned int v14; // eax
  WCHAR *v15; // edi
  WCHAR *v16; // esi
  CCmdString *v17; // eax
  CCmdString *v18; // eax
  WCHAR *v19; // esi
  CCmdString *v20; // eax
  void *v21; // esi
  const WCHAR *v22; // esi
  unsigned int v23; // eax
  const wchar_t **v24; // eax
  WCHAR *v25; // esi
  CCmdString *v26; // eax
  WCHAR *v27; // edi
  WCHAR *v28; // edi
  const WCHAR *v29; // esi
  unsigned int v30; // eax
  const wchar_t *v31; // eax
  WCHAR *v32; // eax
  WCHAR *v33; // ebx
  wchar_t *v34; // eax
  wchar_t *v35; // edi
  const wchar_t *v36; // eax
  wchar_t *v37; // esi
  CCmdString *v38; // eax
  const wchar_t *v39; // eax
  wchar_t *v40; // eax
  wchar_t *v41; // ebx
  wchar_t *v42; // eax
  wchar_t *v43; // edi
  const wchar_t *v44; // eax
  WCHAR *v45; // esi
  CCmdString *v46; // eax
  WCHAR *v47; // eax
  WCHAR *v48; // edi
  const wchar_t *v49; // eax
  wchar_t *v50; // esi
  CCmdString *v51; // eax
  WCHAR *ppv1; // [esp+10h] [ebp-A0h]
  WCHAR v54[2]; // [esp+14h] [ebp-9Ch]
  WCHAR v55[2]; // [esp+18h] [ebp-98h]
  int a4a; // [esp+1Ch] [ebp-94h]
  int a8; // [esp+20h] [ebp-90h]
  CCmdString v58; // [esp+24h] [ebp-8Ch]
  WCHAR v59[2]; // [esp+28h] [ebp-88h]
  WCHAR v60[2]; // [esp+2Ch] [ebp-84h]
  WCHAR v61[2]; // [esp+30h] [ebp-80h]
  void *v62; // [esp+34h] [ebp-7Ch]
  WCHAR *pszResult; // [esp+38h] [ebp-78h]
  void *v64; // [esp+3Ch] [ebp-74h]
  CCmdString strKeyName[7]; // [esp+40h] [ebp-70h]
  void *a1a; // [esp+5Ch] [ebp-54h]
  HKEY KeyHandle; // [esp+60h] [ebp-50h]
  LPCWSTR v68; // [esp+64h] [ebp-4Ch]
  _WORD *v69; // [esp+68h] [ebp-48h]
  CCmdString strValue; // [esp+6Ch] [ebp-44h]
  CCmdString str1; // [esp+70h] [ebp-40h]
  LPCWSTR szArg4; // [esp+74h] [ebp-3Ch]
  void *v73; // [esp+78h] [ebp-38h]
  DWORD dwIndex; // [esp+7Ch] [ebp-34h]
  LPCWSTR szKeyName; // [esp+80h] [ebp-30h]
  WCHAR szArg[2]; // [esp+84h] [ebp-2Ch]
  LPCWSTR szArg3; // [esp+88h] [ebp-28h]
  char v78; // [esp+8Fh] [ebp-21h]
  WCHAR *ppv2; // [esp+90h] [ebp-20h]
  CCmdString str3; // [esp+94h] [ebp-1Ch]
  HKEY hKey; // [esp+98h] [ebp-18h]
  wchar_t *ppv3; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v84; // [esp+ACh] [ebp-4h]

  v73 = malloc(2u);
  str1.m_String = (WCHAR *)v73;
  *(_WORD *)v73 = 0;
  v84 = 0;
  strKeyName[4].m_String = (WCHAR *)malloc(2u);
  *strKeyName[4].m_String = 0;
  v64 = malloc(2u);
  *(_WORD *)v64 = 0;
  strKeyName[6].m_String = (WCHAR *)malloc(2u);
  *strKeyName[6].m_String = 0;
  v4 = malloc(2u);
  v69 = v4;
  *v4 = 0;
  v5 = psz;
  LOBYTE(v84) = 4;
  if ( a4 == (void *)-1 )
  {
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
    lpszKeyName = _wcsdup((const wchar_t *)&gszNullString);
    ppv3 = _wcsdup((const wchar_t *)&gszNullString);
    hKey = (HKEY)_wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    dwIndex = (DWORD)_wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( psz )
      v6 = psz;
    v7 = _wcsdup(v6);
    v8 = v7;
    a4 = v7;
    v9 = _wcsdup((const wchar_t *)&gszNullString);
    v10 = v9;
    ppv2 = v9;
    v11 = (const wchar_t *)&gszNullString;
    if ( psz )
      v11 = psz;
    v12 = _wcsdup(v11);
    szArg3 = v12;
    szKeyName = (LPCWSTR)MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&a4, (CCmdString *)&dwIndex);
    v13 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&ppv2);
    LOBYTE(v84) = 16;
    a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v13, (CCmdString *)szKeyName, &str3);
    free(*(void **)szArg);
    free(a1a);
    free(v12);
    free(v10);
    free(v8);
    free((void *)dwIndex);
    free(str3.m_String);
    free(hKey);
    free(ppv3);
    free((void *)lpszKeyName);
    free(strValue.m_String);
    LOBYTE(v84) = 4;
    free((void *)szArg4);
    v4 = v69;
    v5 = psz;
  }
  v14 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey((HKEY)a2, v5, 0, v14 | 0x20019, &KeyHandle) )
  {
    dwIndex = 0;
    lpszKeyName = (LPCWSTR)malloc(2u);
    *lpszKeyName = 0;
    ppv3 = (wchar_t *)malloc(2u);
    *ppv3 = 0;
    v15 = (WCHAR *)malloc(2u);
    str3.m_String = v15;
    *v15 = 0;
    v16 = (WCHAR *)malloc(2u);
    strKeyName[0].m_String = v16;
    strKeyName[1].m_String = 0;
    strKeyName[2].m_String = 0;
    *v16 = 0;
    strKeyName[3].m_String = 0;
    LOBYTE(v84) = 20;
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&ppv3) )
    {
      do
      {
        v17 = operator+((CCmdString *)&pszResult, L"CLSID\\", (CCmdString *)&ppv3);
        v18 = CCmdString::operator+((CCmdString *)&a1a, v17, L"\\InprocServer32");
        v19 = (WCHAR *)lpszKeyName;
        lpszKeyName = _wcsdup(v18->m_String);
        free(v19);
        free(a1a);
        free(pszResult);
        v20 = operator+(&v58, L"HKCR\\CLSID\\", (CCmdString *)&ppv3);
        v21 = v4;
        v4 = _wcsdup(v20->m_String);
        v69 = v4;
        free(v21);
        free(v58.m_String);
        v22 = lpszKeyName;
        v23 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v22, 0, v23 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyName) )
          {
            sub_BE7040((wchar_t *)lpszKeyName, (StringItem *)strKeyName);
            v24 = (const wchar_t **)sub_BE4EE0((int)&v62, a1, (int)strKeyName, 0);
            str3.m_String = _wcsdup(*v24);
            free(v15);
            free(v62);
            RegCloseKey(hKey);
            v25 = _wcsdup(L"CLSID\\");
            ppv2 = v25;
            v26 = CCmdString::Append((CCmdString *)&ppv1, (CCmdString *)&ppv2, (CCmdString *)&ppv3);
            v27 = (WCHAR *)lpszKeyName;
            lpszKeyName = _wcsdup(v26->m_String);
            free(v27);
            free(ppv1);
            free(v25);
            v28 = _wcsdup(ppv3);
            str1.m_String = v28;
            free(v73);
            v29 = lpszKeyName;
            v30 = (unsigned int)TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v29, 0, v30 | 0x20019, &hKey) )
            {
              if ( !PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyName)
                && wcslen(lpszKeyName) )
              {
                str1.m_String = _wcsdup(lpszKeyName);
                free(v28);
              }
              RegCloseKey(hKey);
            }
            v31 = (const wchar_t *)&gszNullString;
            if ( psz )
              v31 = psz;
            v32 = _wcsdup(v31);
            v33 = v32;
            ppv2 = v32;
            v34 = _wcsdup((const wchar_t *)&gszNullString);
            v35 = v34;
            szArg3 = v34;
            v36 = (const wchar_t *)&gszNullString;
            if ( psz )
              v36 = psz;
            v37 = _wcsdup(v36);
            szKeyName = v37;
            *(_DWORD *)szArg = MakeRegistryKeyName(
                                 (CCmdString *)v60,
                                 (HKEY)a2,
                                 (CCmdString *)&ppv2,
                                 (CCmdString *)&ppv3);
            v38 = MakeRegistryKeyName((CCmdString *)v54, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&szArg3);
            LOBYTE(v84) = 25;
            v78 = sub_BE3D40(
                    a1,
                    (CCmdString)&str1,
                    (int)v38,
                    *(int *)szArg,
                    (int)&str3,
                    (int)&strKeyName[4],
                    (CCmdString)&strKeyName[6],
                    (int)&a8);
            free(*(void **)v54);
            free(*(void **)v60);
            free(v37);
            free(v35);
            free(v33);
            if ( v78 )
            {
              if ( a4 == (void *)-1 )
              {
                ppv2 = _wcsdup((const wchar_t *)&gszNullString);
                szArg3 = _wcsdup((const wchar_t *)&gszNullString);
                szKeyName = _wcsdup((const wchar_t *)&gszNullString);
                *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
                v73 = _wcsdup((const wchar_t *)&gszNullString);
                strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
                szArg4 = _wcsdup((const wchar_t *)&gszNullString);
                v39 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v39 = psz;
                v40 = _wcsdup(v39);
                v41 = v40;
                a4 = v40;
                v42 = _wcsdup((const wchar_t *)&gszNullString);
                v43 = v42;
                a4a = (int)v42;
                v44 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v44 = psz;
                v45 = _wcsdup(v44);
                strKeyName[5].m_String = v45;
                v68 = (LPCWSTR)MakeRegistryKeyName(
                                 (CCmdString *)v59,
                                 (HKEY)a2,
                                 (CCmdString *)&a4,
                                 (CCmdString *)&szArg4);
                v46 = MakeRegistryKeyName((CCmdString *)v61, (HKEY)a2, &strKeyName[5], (CCmdString *)&a4a);
                LOBYTE(v84) = 37;
                a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v46, (CCmdString *)v68, &strValue);
                free(*(void **)v61);
                free(*(void **)v59);
                free(v45);
                free(v43);
                free(v41);
                free((void *)szArg4);
                free(strValue.m_String);
                free(v73);
                free(*(void **)szArg);
                free((void *)szKeyName);
                free((void *)szArg3);
                free(ppv2);
              }
              v47 = _wcsdup((const wchar_t *)&gszNullString);
              v48 = v47;
              strKeyName[5].m_String = v47;
              v49 = (const wchar_t *)&gszNullString;
              if ( psz )
                v49 = psz;
              v50 = _wcsdup(v49);
              v68 = v50;
              v51 = MakeRegistryKeyName((CCmdString *)v55, (HKEY)a2, (CCmdString *)&v68, (CCmdString *)&ppv3);
              LOBYTE(v84) = 40;
              PE_UpdateSystemKey(a1, 0xFFFFFFFF, a4, 3u, &str1, v51, &str3);
              free(*(void **)v55);
              free(v50);
              free(v48);
            }
            StringItem::~StringItem((tagPEStringStruct *)strKeyName);
            free(str3.m_String);
            free(ppv3);
            free((void *)lpszKeyName);
            v4 = v69;
            v73 = str1.m_String;
            goto LABEL_33;
          }
          RegCloseKey(hKey);
        }
        StringItem::~StringItem((tagPEStringStruct *)strKeyName);
        free(v15);
        free(ppv3);
        free((void *)lpszKeyName);
LABEL_33:
        ++dwIndex;
        lpszKeyName = (LPCWSTR)malloc(2u);
        *lpszKeyName = 0;
        ppv3 = (wchar_t *)malloc(2u);
        *ppv3 = 0;
        v15 = (WCHAR *)malloc(2u);
        str3.m_String = v15;
        *v15 = 0;
        v16 = (WCHAR *)malloc(2u);
        strKeyName[0].m_String = v16;
        strKeyName[1].m_String = 0;
        strKeyName[2].m_String = 0;
        *v16 = 0;
        strKeyName[3].m_String = 0;
        LOBYTE(v84) = 20;
      }
      while ( !PE_LoadRegKeys(KeyHandle, dwIndex, (CCmdString *)&ppv3) );
    }
    free(v16);
    free(v15);
    free(ppv3);
    free((void *)lpszKeyName);
    RegCloseKey(KeyHandle);
  }
  free(v4);
  free(strKeyName[6].m_String);
  free(v64);
  free(strKeyName[4].m_String);
  free(v73);
  return a4;
}

//----- (00BE9030) --------------------------------------------------------
void __cdecl sub_BE9030(void *a1, int a2, void *a3, wchar_t *a4)
{
  _WORD *v4; // eax
  void *v5; // ebx
  const wchar_t *v6; // eax
  WCHAR *v7; // esi
  CCmdString *v8; // eax
  CCmdString *v9; // eax
  WCHAR *v10; // edi
  const wchar_t *v11; // ecx
  wchar_t *v12; // esi
  CCmdString *v13; // eax
  CCmdString *v14; // eax
  WCHAR *v15; // ebx
  WCHAR *pszResult; // [esp+10h] [ebp-18h]
  WCHAR *ppv; // [esp+14h] [ebp-14h]
  WCHAR *ppszText2; // [esp+18h] [ebp-10h]
  int v19; // [esp+24h] [ebp-4h]

  v4 = malloc(2u);
  v5 = v4;
  *v4 = 0;
  v19 = 0;
  v6 = (const wchar_t *)&gszNullString;
  if ( a4 )
    v6 = a4;
  v7 = _wcsdup(v6);
  ppszText2 = v7;
  v8 = operator+((CCmdString *)&pszResult, L"Software\\Classes\\CLSID\\", (CCmdString *)&ppszText2);
  v9 = CCmdString::operator+((CCmdString *)&ppv, v8, L"\\Instance");
  v10 = _wcsdup(v9->m_String);
  ppszText2 = v10;
  free(v5);
  free(ppv);
  free(pszResult);
  free(v7);
  sub_BE86F0(a2, a3, &ppszText2);
  if ( a1 )
  {
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    v11 = (const wchar_t *)&gszNullString;
    if ( a4 )
      v11 = a4;
    v12 = _wcsdup(v11);
    a4 = v12;
    v13 = operator+((CCmdString *)&pszResult, L"Software\\Wow6432Node\\Classes\\CLSID\\", (CCmdString *)&a4);
    v14 = CCmdString::operator+((CCmdString *)&a1, v13, L"\\Instance");
    v15 = v10;
    v10 = _wcsdup(v14->m_String);
    ppszText2 = v10;
    free(v15);
    free(a1);
    free(pszResult);
    free(v12);
    sub_BE86F0(a2, a3, &ppszText2);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
  }
  free(v10);
}

//----- (00BE91C0) --------------------------------------------------------
void __cdecl PE_RefreshRegistry2(int a1, int a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BE9270(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BE9270(a1, a2, v7, v5);
  free(v7);
}

//----- (00BE9270) --------------------------------------------------------
void *__cdecl sub_BE9270(int a1, int a2, wchar_t *psz, void *a4)
{
  int v4; // edi
  wchar_t *v5; // esi
  const wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *v8; // ebx
  wchar_t *v9; // eax
  wchar_t *v10; // edi
  const wchar_t *v11; // eax
  wchar_t *v12; // esi
  CCmdString *v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  CCmdString *v16; // eax
  const WCHAR **v17; // eax
  wchar_t *v18; // eax
  wchar_t *v19; // ebx
  wchar_t *v20; // eax
  wchar_t *v21; // edi
  const WCHAR **v22; // eax
  wchar_t *v23; // eax
  wchar_t *v24; // esi
  const wchar_t *v25; // eax
  CCmdString *v26; // eax
  wchar_t *v27; // esi
  const wchar_t *v28; // eax
  wchar_t *v29; // eax
  wchar_t *v30; // ebx
  wchar_t *v31; // eax
  wchar_t *v32; // edi
  const WCHAR **v33; // eax
  wchar_t *v34; // esi
  CCmdString *v35; // eax
  wchar_t *v36; // eax
  wchar_t *v37; // ebx
  const wchar_t *v38; // esi
  const wchar_t *v39; // eax
  wchar_t *v40; // edi
  wchar_t *v41; // esi
  CCmdString *v42; // eax
  CCmdString a2a; // [esp+10h] [ebp-3A4h]
  wchar_t **v45; // [esp+14h] [ebp-3A0h]
  int v46; // [esp+18h] [ebp-39Ch]
  int v47; // [esp+1Ch] [ebp-398h]
  int a8; // [esp+20h] [ebp-394h]
  void *v49; // [esp+24h] [ebp-390h]
  HKEY hKey; // [esp+28h] [ebp-38Ch]
  DWORD cbData; // [esp+2Ch] [ebp-388h]
  WCHAR v52[2]; // [esp+30h] [ebp-384h]
  wchar_t *v53; // [esp+34h] [ebp-380h]
  WCHAR *ppv3; // [esp+38h] [ebp-37Ch]
  void *v55; // [esp+3Ch] [ebp-378h]
  CCmdString strValue; // [esp+40h] [ebp-374h]
  wchar_t *pszText; // [esp+44h] [ebp-370h]
  CCmdString str3; // [esp+48h] [ebp-36Ch]
  void *v59; // [esp+4Ch] [ebp-368h]
  int a3; // [esp+50h] [ebp-364h]
  LPCWSTR szArg4; // [esp+54h] [ebp-360h]
  WCHAR v62[2]; // [esp+58h] [ebp-35Ch]
  void *v63; // [esp+5Ch] [ebp-358h]
  int v64; // [esp+60h] [ebp-354h]
  WCHAR v65[2]; // [esp+64h] [ebp-350h]
  void *szArg; // [esp+68h] [ebp-34Ch]
  char v67; // [esp+6Fh] [ebp-345h]
  WCHAR v68[2]; // [esp+70h] [ebp-344h]
  HKEY hRootKey; // [esp+74h] [ebp-340h]
  void *a1a; // [esp+78h] [ebp-33Ch]
  LPCWSTR v71; // [esp+7Ch] [ebp-338h]
  LPCWSTR v72; // [esp+80h] [ebp-334h]
  wchar_t Data[400]; // [esp+84h] [ebp-330h]
  int v74; // [esp+3B0h] [ebp-4h]

  v4 = a1;
  v5 = psz;
  v64 = a1;
  hRootKey = (HKEY)a2;
  v53 = psz;
  strValue.m_String = (WCHAR *)malloc(2u);
  *strValue.m_String = 0;
  v74 = 0;
  v55 = malloc(2u);
  *(_WORD *)v55 = 0;
  v49 = malloc(2u);
  *(_WORD *)v49 = 0;
  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  LOBYTE(v74) = 3;
  if ( a4 == (void *)-1 )
  {
    v72 = _wcsdup((const wchar_t *)&gszNullString);
    v71 = _wcsdup((const wchar_t *)&gszNullString);
    *(_DWORD *)v68 = _wcsdup((const wchar_t *)&gszNullString);
    v63 = _wcsdup((const wchar_t *)&gszNullString);
    v59 = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( psz )
      v6 = psz;
    v7 = _wcsdup(v6);
    v8 = v7;
    pszText = v7;
    v9 = _wcsdup(L"(Default)");
    v10 = v9;
    *(_DWORD *)v62 = v9;
    v11 = (const wchar_t *)&gszNullString;
    if ( psz )
      v11 = psz;
    v12 = _wcsdup(v11);
    a3 = (int)v12;
    *(_DWORD *)v65 = MakeRegistryKeyName((CCmdString *)&a1a, hRootKey, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    v13 = MakeRegistryKeyName((CCmdString *)&szArg, hRootKey, (CCmdString *)&a3, (CCmdString *)v62);
    LOBYTE(v74) = 15;
    a4 = (void *)PE_UpdateSystemKey(v64, 0, (HANDLE)0xFFFFFFFF, 0, v13, *(CCmdString **)v65, &str3);
    free(szArg);
    free(a1a);
    free(v12);
    free(v10);
    free(v8);
    free((void *)szArg4);
    free(str3.m_String);
    free(v59);
    free(v63);
    free(*(void **)v68);
    free((void *)v71);
    LOBYTE(v74) = 3;
    free((void *)v72);
    v5 = v53;
    v4 = v64;
  }
  v14 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hRootKey, v5, 0, v14 | 0x20019, &hKey) )
  {
    cbData = 800;
    if ( !RegQueryValueExW(hKey, (LPCWSTR)&gszNullString, 0, 0, (LPBYTE)Data, &cbData) && cbData )
    {
      a2a.m_String = (WCHAR *)malloc(2u);
      v45 = 0;
      v46 = 0;
      *a2a.m_String = 0;
      v47 = 0;
      LOBYTE(v74) = 16;
      if ( sub_BE6CC0(Data, (StringItem *)&a2a) )
      {
        pszText = *v45;
        v15 = wcscmp(pszText, L"%1");
        if ( v15 )
          v15 = -(v15 < 0) | 1;
        if ( v15 )
        {
          v16 = (CCmdString *)sub_BE4EE0((int)&a1a, v4, (int)&a2a, 0);
          CCmdString::Reset(&strValue, v16);
          free(a1a);
          v71 = _wcsdup(L"(Default)");
          v17 = &gszNullString;
          if ( v5 )
            v17 = (const WCHAR **)v5;
          v18 = _wcsdup((const wchar_t *)v17);
          v19 = v18;
          a1a = v18;
          v20 = _wcsdup((const wchar_t *)&gszNullString);
          v21 = v20;
          szArg = v20;
          v22 = &gszNullString;
          if ( v5 )
            v22 = (const WCHAR **)v5;
          v23 = _wcsdup((const wchar_t *)v22);
          v24 = v23;
          *(_DWORD *)v65 = v23;
          v25 = (const wchar_t *)&gszNullString;
          if ( pszText )
            v25 = pszText;
          v72 = _wcsdup(v25);
          a3 = (int)MakeRegistryKeyName((CCmdString *)v68, hRootKey, (CCmdString *)&a1a, (CCmdString *)&v71);
          v26 = MakeRegistryKeyName((CCmdString *)v62, hRootKey, (CCmdString *)v65, (CCmdString *)&szArg);
          LOBYTE(v74) = 23;
          v67 = sub_BE3D40(v64, (CCmdString)&v72, (int)v26, a3, (int)&strValue, (int)&v55, (CCmdString)&ppv3, (int)&a8);
          free(*(void **)v62);
          free(*(void **)v68);
          free((void *)v72);
          free(v24);
          free(v21);
          free(v19);
          LOBYTE(v74) = 16;
          free((void *)v71);
          if ( v67 )
          {
            if ( a4 == (void *)-1 )
            {
              szArg4 = _wcsdup((const wchar_t *)&gszNullString);
              str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
              v59 = _wcsdup((const wchar_t *)&gszNullString);
              v63 = _wcsdup((const wchar_t *)&gszNullString);
              *(_DWORD *)v68 = _wcsdup((const wchar_t *)&gszNullString);
              v71 = _wcsdup((const wchar_t *)&gszNullString);
              v72 = _wcsdup((const wchar_t *)&gszNullString);
              v27 = v53;
              v28 = (const wchar_t *)&gszNullString;
              if ( v53 )
                v28 = v53;
              v29 = _wcsdup(v28);
              v30 = v29;
              a1a = v29;
              v31 = _wcsdup(L"(Default)");
              v32 = v31;
              szArg = v31;
              v33 = &gszNullString;
              if ( v27 )
                v33 = (const WCHAR **)v27;
              v34 = _wcsdup((const wchar_t *)v33);
              *(_DWORD *)v65 = v34;
              a3 = (int)MakeRegistryKeyName((CCmdString *)v52, hRootKey, (CCmdString *)&a1a, (CCmdString *)&v72);
              v35 = MakeRegistryKeyName((CCmdString *)v62, hRootKey, (CCmdString *)v65, (CCmdString *)&szArg);
              LOBYTE(v74) = 35;
              a4 = (void *)PE_UpdateSystemKey(v64, 0, (HANDLE)0xFFFFFFFF, 0, v35, (CCmdString *)a3, (CCmdString *)&v71);
              free(*(void **)v62);
              free(*(void **)v52);
              free(v34);
              free(v32);
              free(v30);
              free((void *)v72);
              free((void *)v71);
              free(*(void **)v68);
              free(v63);
              free(v59);
              free(str3.m_String);
              free((void *)szArg4);
            }
            v71 = _wcsdup((const wchar_t *)&gszNullString);
            v72 = _wcsdup((const wchar_t *)&gszNullString);
            v36 = _wcsdup(L"(Default)");
            v37 = v36;
            *(_DWORD *)v52 = v36;
            v38 = (const wchar_t *)&gszNullString;
            v39 = (const wchar_t *)&gszNullString;
            if ( v53 )
              v39 = v53;
            v40 = _wcsdup(v39);
            a1a = v40;
            if ( pszText )
              v38 = pszText;
            v41 = _wcsdup(v38);
            szArg = v41;
            v42 = MakeRegistryKeyName((CCmdString *)v65, hRootKey, (CCmdString *)&a1a, (CCmdString *)v52);
            LOBYTE(v74) = 41;
            PE_UpdateSystemKey(v64, 0xFFFFFFFF, a4, 0xCu, (CCmdString *)&szArg, v42, &strValue);
            free(*(void **)v65);
            free(v41);
            free(v40);
            free(v37);
            free((void *)v72);
            free((void *)v71);
          }
        }
      }
      StringItem::~StringItem((tagPEStringStruct *)&a2a);
    }
    RegCloseKey(hKey);
  }
  free(ppv3);
  free(v49);
  free(v55);
  free(strValue.m_String);
  return a4;
}

//----- (00BE9AB0) --------------------------------------------------------
void __cdecl PE_LoadAutorunsDisabledFlags(DWORD dwValue, HKEY hKey, LPCWSTR lpszKeyName, bool bFlags1, bool bFlags2)
{
  _WORD *v5; // ST68_4
  CCmdString *v6; // esi
  void *Handle; // edi
  CCmdString *v8; // eax
  wchar_t *v9; // ST6C_4

  v5 = malloc(2u);
  *v5 = 0;
  v6 = (CCmdString *)lpszKeyName;
  Handle = sub_BE9B70(dwValue, hKey, *(LPCWSTR *)lpszKeyName, bFlags1, bFlags2, (HANDLE)0xFFFFFFFF, 1, 1);
  v8 = CCmdString::operator+((CCmdString *)&lpszKeyName, v6, L"\\AutorunsDisabled");
  v9 = _wcsdup(v8->m_String);
  free(v5);
  free((void *)lpszKeyName);
  sub_BE9B70(dwValue, hKey, v9, bFlags1, bFlags2, Handle, 0, 1);
  free(v9);
}

//----- (00BE9B70) --------------------------------------------------------
void *__cdecl sub_BE9B70(DWORD dwValue, HKEY hKey, LPCWSTR lpszKeyName, bool bFlags1, bool bFlags2, HANDLE handle, bool bFags3, bool bFlags4)
{
  wchar_t *v8; // edi
  const WCHAR *v9; // esi
  const wchar_t *v10; // eax
  wchar_t *v11; // eax
  wchar_t *v12; // ebx
  wchar_t *v13; // eax
  wchar_t *v14; // edi
  const wchar_t *v15; // eax
  wchar_t *v16; // esi
  CCmdString *v17; // eax
  unsigned int v18; // eax
  WCHAR *v19; // ebx
  _WORD *v20; // esi
  const wchar_t *v21; // edx
  __int16 *v22; // ecx
  __int16 v23; // ax
  WCHAR *v24; // esi
  CCmdString *v25; // eax
  CCmdString *v26; // eax
  WCHAR *v27; // esi
  CCmdString *v28; // eax
  wchar_t *v29; // esi
  const WCHAR *v30; // edi
  unsigned int v31; // eax
  WCHAR *v32; // esi
  void (__stdcall *v33)(HKEY); // edi
  CCmdString *v34; // eax
  CCmdString *v35; // eax
  WCHAR *v36; // edi
  CCmdString *v37; // eax
  const WCHAR *v38; // esi
  unsigned int v39; // eax
  int v40; // eax
  WCHAR *v41; // esi
  WCHAR *v42; // esi
  unsigned int v43; // eax
  int v44; // eax
  WCHAR *v45; // esi
  WCHAR *v46; // ebx
  const wchar_t **v47; // eax
  WCHAR *v48; // esi
  const wchar_t **v49; // eax
  WCHAR *v50; // esi
  CCmdString *v51; // eax
  CCmdString *v52; // eax
  WCHAR *v53; // esi
  CCmdString *v54; // eax
  wchar_t *v55; // esi
  const WCHAR *v56; // esi
  unsigned int v57; // eax
  const wchar_t **v58; // eax
  CCmdString *v59; // eax
  CCmdString *v60; // eax
  wchar_t *v61; // esi
  const wchar_t **v62; // eax
  const wchar_t **v63; // eax
  void *v64; // esi
  const wchar_t **v65; // eax
  wchar_t *v66; // eax
  const wchar_t *v67; // eax
  wchar_t *v68; // eax
  wchar_t *v69; // ebx
  wchar_t *v70; // eax
  wchar_t *v71; // edi
  const wchar_t *v72; // eax
  wchar_t *v73; // esi
  CCmdString *v74; // eax
  const wchar_t *v75; // eax
  wchar_t *v76; // eax
  wchar_t *v77; // ebx
  wchar_t *v78; // eax
  wchar_t *v79; // edi
  const wchar_t *v80; // eax
  wchar_t *v81; // esi
  CCmdString *v82; // eax
  const wchar_t *v83; // eax
  wchar_t *v84; // esi
  CCmdString *v85; // eax
  WCHAR v87[2]; // [esp+10h] [ebp-108h]
  int v88; // [esp+14h] [ebp-104h]
  int v89; // [esp+18h] [ebp-100h]
  int v90; // [esp+1Ch] [ebp-FCh]
  void *v91; // [esp+20h] [ebp-F8h]
  int a2a; // [esp+24h] [ebp-F4h]
  int v93; // [esp+28h] [ebp-F0h]
  int v94; // [esp+2Ch] [ebp-ECh]
  int v95; // [esp+30h] [ebp-E8h]
  CCmdString v96; // [esp+34h] [ebp-E4h]
  WCHAR *ppv; // [esp+38h] [ebp-E0h]
  void *v98; // [esp+3Ch] [ebp-DCh]
  WCHAR v99[2]; // [esp+40h] [ebp-D8h]
  CCmdString v100; // [esp+44h] [ebp-D4h]
  int a8; // [esp+48h] [ebp-D0h]
  CCmdString v102; // [esp+4Ch] [ebp-CCh]
  WCHAR v103[2]; // [esp+50h] [ebp-C8h]
  CCmdString v104; // [esp+54h] [ebp-C4h]
  WCHAR v105[2]; // [esp+58h] [ebp-C0h]
  void *v106; // [esp+5Ch] [ebp-BCh]
  WCHAR *pszResult; // [esp+60h] [ebp-B8h]
  WCHAR *ppv1; // [esp+64h] [ebp-B4h]
  int a3; // [esp+68h] [ebp-B0h]
  CCmdString v110; // [esp+6Ch] [ebp-ACh]
  int a4a; // [esp+70h] [ebp-A8h]
  CCmdString v112; // [esp+74h] [ebp-A4h]
  WCHAR v113[2]; // [esp+78h] [ebp-A0h]
  void *v114; // [esp+7Ch] [ebp-9Ch]
  WCHAR v115[2]; // [esp+80h] [ebp-98h]
  CCmdString v116; // [esp+84h] [ebp-94h]
  void *v117; // [esp+88h] [ebp-90h]
  CCmdString str; // [esp+8Ch] [ebp-8Ch]
  void *v119; // [esp+90h] [ebp-88h]
  CCmdString v120; // [esp+94h] [ebp-84h]
  WCHAR pszText2[2]; // [esp+98h] [ebp-80h]
  int v122; // [esp+9Ch] [ebp-7Ch]
  int v123; // [esp+A0h] [ebp-78h]
  int v124; // [esp+A4h] [ebp-74h]
  void *v125; // [esp+A8h] [ebp-70h]
  void *v126; // [esp+ACh] [ebp-6Ch]
  CCmdString v127; // [esp+B0h] [ebp-68h]
  void *v128; // [esp+B4h] [ebp-64h]
  HKEY KeyHandle; // [esp+B8h] [ebp-60h]
  DWORD Type; // [esp+BCh] [ebp-5Ch]
  unsigned int v131; // [esp+C0h] [ebp-58h]
  CCmdString *a1a; // [esp+C4h] [ebp-54h]
  DWORD dwIndex; // [esp+C8h] [ebp-50h]
  WCHAR szArg[2]; // [esp+CCh] [ebp-4Ch]
  LPCWSTR szKeyName; // [esp+D0h] [ebp-48h]
  WCHAR *ppv3; // [esp+D4h] [ebp-44h]
  LPCWSTR szArg4; // [esp+D8h] [ebp-40h]
  wchar_t *v138; // [esp+DCh] [ebp-3Ch]
  LPCWSTR szArg3; // [esp+E0h] [ebp-38h]
  CCmdString strValue; // [esp+E4h] [ebp-34h]
  LPCWSTR v141; // [esp+E8h] [ebp-30h]
  HKEY hKeya; // [esp+ECh] [ebp-2Ch]
  CCmdString str1; // [esp+F0h] [ebp-28h]
  CCmdString str3; // [esp+F4h] [ebp-24h]
  void *v145; // [esp+F8h] [ebp-20h]
  char v146; // [esp+FFh] [ebp-19h]
  wchar_t *ppszText2; // [esp+100h] [ebp-18h]
  HKEY__ v148; // [esp+104h] [ebp-14h]
  LPCWSTR lpszKeyNamea; // [esp+108h] [ebp-10h]
  int v150; // [esp+114h] [ebp-4h]

  v131 = 0;
  szArg3 = 0;
  v126 = malloc(2u);
  *(_WORD *)v126 = 0;
  v150 = 0;
  v128 = malloc(2u);
  *(_WORD *)v128 = 0;
  v125 = malloc(2u);
  *(_WORD *)v125 = 0;
  v127.m_String = (WCHAR *)malloc(2u);
  *v127.m_String = 0;
  v8 = (wchar_t *)malloc(2u);
  v138 = v8;
  *v8 = 0;
  v9 = lpszKeyName;
  LOBYTE(v150) = 4;
  if ( handle == (HANDLE)-1 )
  {
    v145 = _wcsdup((const wchar_t *)&gszNullString);
    str1.m_String = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v141 = _wcsdup((const wchar_t *)&gszNullString);
    ppv3 = _wcsdup((const wchar_t *)&gszNullString);
    dwIndex = (DWORD)_wcsdup((const wchar_t *)&gszNullString);
    v10 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v10 = lpszKeyName;
    v11 = _wcsdup(v10);
    v12 = v11;
    handle = v11;
    v13 = _wcsdup((const wchar_t *)&gszNullString);
    v14 = v13;
    Type = (DWORD)v13;
    v15 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v15 = lpszKeyName;
    v16 = _wcsdup(v15);
    szArg3 = v16;
    szArg4 = (LPCWSTR)MakeRegistryKeyName((CCmdString *)&a1a, hKey, (CCmdString *)&handle, (CCmdString *)&dwIndex);
    v17 = MakeRegistryKeyName((CCmdString *)szArg, hKey, (CCmdString *)&szArg3, (CCmdString *)&Type);
    LOBYTE(v150) = 16;
    handle = (HANDLE)PE_UpdateSystemKey(
                       dwValue,
                       0,
                       (HANDLE)0xFFFFFFFF,
                       0,
                       v17,
                       (CCmdString *)szArg4,
                       (CCmdString *)&ppv3);
    free(*(void **)szArg);
    free(a1a);
    free(v16);
    free(v14);
    free(v12);
    free((void *)dwIndex);
    free(ppv3);
    free((void *)v141);
    free(strValue.m_String);
    free(str3.m_String);
    free(str1.m_String);
    LOBYTE(v150) = 4;
    free(v145);
    v8 = v138;
    v9 = lpszKeyName;
  }
  v18 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hKey, v9, 0, v18 | 0x20019, &KeyHandle) )
  {
    dwIndex = 0;
    v148.unused = (int)malloc(2u);
    *(_WORD *)v148.unused = 0;
    v141 = (LPCWSTR)malloc(2u);
    str1.m_String = (WCHAR *)v141;
    *v141 = 0;
    ppszText2 = (wchar_t *)malloc(2u);
    *ppszText2 = 0;
    lpszKeyNamea = (LPCWSTR)malloc(2u);
    *lpszKeyNamea = 0;
    v19 = (WCHAR *)malloc(2u);
    ppv3 = v19;
    *v19 = 0;
    v20 = malloc(2u);
    v145 = v20;
    strValue.m_String = v20;
    *v20 = 0;
    LOBYTE(v150) = 22;
    if ( !PE_LoadRegValues(KeyHandle, 0, (LPWSTR *)&v148, 0, &Type, (void **)&ppszText2) )
    {
      while ( Type == 1 || Type == 2 || Type == 7 || Type == 3 )
      {
        v21 = (const wchar_t *)v148.unused;
        v22 = (__int16 *)v148.unused;
        szArg4 = (LPCWSTR)v148.unused;
        szArg3 = (LPCWSTR)(v148.unused + 2);
        do
        {
          v23 = *v22;
          ++v22;
        }
        while ( v23 );
        if ( !(((char *)v22 - (char *)szArg3) >> 1) )
        {
          if ( !bFlags4 )
            break;
          v148.unused = (int)_wcsdup(L"(Default)");
          free((void *)szArg4);
          v21 = (const wchar_t *)v148.unused;
        }
        v24 = _wcsdup(v21);
        str3.m_String = v24;
        str1.m_String = v24;
        free((void *)v141);
        if ( bFlags2 )
        {
          v25 = operator+((CCmdString *)&pszResult, L"CLSID\\", (CCmdString *)&v148);
          v26 = CCmdString::operator+((CCmdString *)&ppv, v25, L"\\InprocServer32");
          v27 = (WCHAR *)lpszKeyNamea;
          lpszKeyNamea = _wcsdup(v26->m_String);
          free(v27);
          free(ppv);
          free(pszResult);
          v28 = operator+(&v120, L"HKCR\\CLSID\\", (CCmdString *)&v148);
          v29 = _wcsdup(v28->m_String);
          v138 = v29;
          free(v8);
          free(v120.m_String);
          v30 = lpszKeyNamea;
          v31 = (unsigned int)TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v30, 0, v31 | 0x20019, &hKeya) )
          {
            v34 = operator+(&v96, L"CLSID\\", (CCmdString *)&v148);
            v35 = CCmdString::operator+(&str, v34, L"\\Shell\\Open\\Command");
            v36 = (WCHAR *)lpszKeyNamea;
            lpszKeyNamea = _wcsdup(v35->m_String);
            free(v36);
            free(str.m_String);
            free(v96.m_String);
            v37 = operator+(&v116, L"HKCR\\CLSID\\", (CCmdString *)&v148);
            v138 = _wcsdup(v37->m_String);
            free(v29);
            free(v116.m_String);
            v38 = lpszKeyNamea;
            v39 = (unsigned int)TlsGetValue(gdwTlsIndex);
            v40 = PE_OpenKey(HKEY_CLASSES_ROOT, v38, 0, v39 | 0x20019, &hKeya);
            v41 = (WCHAR *)lpszKeyNamea;
            if ( v40 )
            {
              lpszKeyNamea = _wcsdup((const wchar_t *)&gszNullString);
              free(v41);
              v33 = (void (__stdcall *)(HKEY))RegCloseKey;
            }
            else
            {
              lpszKeyNamea = _wcsdup((const wchar_t *)&gszNullString);
              free(v41);
              PE_ReadRegKey(hKeya, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyNamea);
              v33 = (void (__stdcall *)(HKEY))RegCloseKey;
              RegCloseKey(hKeya);
            }
          }
          else
          {
            v32 = (WCHAR *)lpszKeyNamea;
            lpszKeyNamea = _wcsdup((const wchar_t *)&gszNullString);
            free(v32);
            PE_ReadRegKey(hKeya, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyNamea);
            v33 = (void (__stdcall *)(HKEY))RegCloseKey;
            RegCloseKey(hKeya);
          }
          if ( wcslen(ppszText2)
            || (v42 = operator+(&v104, L"CLSID\\", (CCmdString *)&v148)->m_String,
                LOBYTE(v150) = 23,
                v131 |= 1u,
                szArg3 = (LPCWSTR)v131,
                v43 = (unsigned int)TlsGetValue(gdwTlsIndex),
                v44 = PE_OpenKey(HKEY_CLASSES_ROOT, v42, 0, v43 | 0x20019, &hKeya),
                v146 = 1,
                v44) )
          {
            v146 = 0;
          }
          v150 = 22;
          if ( v131 & 1 )
          {
            v131 &= 0xFFFFFFFE;
            free(v104.m_String);
          }
          if ( v146 )
          {
            PE_ReadRegKey(hKeya, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&ppszText2);
            v33(hKeya);
          }
          a2a = (int)malloc(2u);
          v93 = 0;
          v94 = 0;
          *(_WORD *)a2a = 0;
          v95 = 0;
          LOBYTE(v150) = 24;
          if ( sub_BE6CC0((WCHAR *)lpszKeyNamea, (StringItem *)&a2a) )
          {
            v45 = str3.m_String;
            v46 = _wcsdup(ppszText2);
            str1.m_String = v46;
            free(v45);
            v47 = (const wchar_t **)sub_BE4890((int)&v114, (wchar_t *)lpszKeyNamea);
            v48 = (WCHAR *)lpszKeyNamea;
            lpszKeyNamea = _wcsdup(*v47);
            free(v48);
            free(v114);
            v49 = (const wchar_t **)sub_BE4EE0((int)&v98, dwValue, (int)&a2a, 0);
            v50 = _wcsdup(*v49);
            strValue.m_String = v50;
            free(v145);
            free(v98);
            StringItem::~StringItem((tagPEStringStruct *)&a2a);
            goto LABEL_46;
          }
          StringItem::~StringItem((tagPEStringStruct *)&a2a);
          free(v145);
          free(v19);
          free((void *)lpszKeyNamea);
          free(ppszText2);
          free(str3.m_String);
LABEL_66:
          free((void *)v148.unused);
          v8 = v138;
          goto LABEL_67;
        }
        if ( bFlags1 )
        {
          *(_DWORD *)v87 = malloc(2u);
          v88 = 0;
          v89 = 0;
          **(_WORD **)v87 = 0;
          v90 = 0;
          LOBYTE(v150) = 26;
          if ( sub_BE6CC0(ppszText2, (StringItem *)v87) )
          {
            v138 = _wcsdup(ppszText2);
            free(v8);
            v63 = (const wchar_t **)sub_BE4890((int)&v119, ppszText2);
            v64 = v126;
            v126 = _wcsdup(*v63);
            free(v64);
            free(v119);
            v65 = (const wchar_t **)sub_BE4EE0((int)&v117, dwValue, (int)v87, 0);
            v50 = _wcsdup(*v65);
            strValue.m_String = v50;
            free(v145);
            free(v117);
            StringItem::~StringItem((tagPEStringStruct *)v87);
LABEL_45:
            v46 = str3.m_String;
LABEL_46:
            if ( !wcslen(v46) && wcslen(v50) )
            {
              if ( wcsrchr(v50, 0x5Cu) )
              {
                v66 = wcsrchr(v50, 0x5Cu);
                str1.m_String = _wcsdup(v66 + 1);
                free(v46);
              }
              else
              {
                str1.m_String = _wcsdup(v50);
                free(v46);
              }
            }
            v67 = (const wchar_t *)&gszNullString;
            if ( lpszKeyName )
              v67 = lpszKeyName;
            v68 = _wcsdup(v67);
            v69 = v68;
            szArg3 = v68;
            v70 = _wcsdup((const wchar_t *)&gszNullString);
            v71 = v70;
            szArg4 = v70;
            v72 = (const wchar_t *)&gszNullString;
            if ( lpszKeyName )
              v72 = lpszKeyName;
            v73 = _wcsdup(v72);
            *(_DWORD *)szArg = v73;
            a1a = MakeRegistryKeyName((CCmdString *)v113, hKey, (CCmdString *)&szArg3, (CCmdString *)&v148);
            v74 = MakeRegistryKeyName((CCmdString *)v115, hKey, (CCmdString *)szArg, (CCmdString *)&szArg4);
            LOBYTE(v150) = 31;
            v146 = sub_BE3D40(
                     dwValue,
                     (CCmdString)&str1,
                     (int)v74,
                     (int)a1a,
                     (int)&strValue,
                     (int)&v128,
                     (CCmdString)&v127,
                     (int)&a8);
            free(*(void **)v115);
            free(*(void **)v113);
            free(v73);
            free(v71);
            free(v69);
            if ( v146 )
            {
              if ( handle == (HANDLE)-1 )
              {
                szArg3 = _wcsdup((const wchar_t *)&gszNullString);
                szArg4 = _wcsdup((const wchar_t *)&gszNullString);
                *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
                a1a = (CCmdString *)_wcsdup((const wchar_t *)&gszNullString);
                v145 = _wcsdup((const wchar_t *)&gszNullString);
                str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v141 = _wcsdup((const wchar_t *)&gszNullString);
                v75 = (const wchar_t *)&gszNullString;
                if ( lpszKeyName )
                  v75 = lpszKeyName;
                v76 = _wcsdup(v75);
                v77 = v76;
                handle = v76;
                v78 = _wcsdup((const wchar_t *)&gszNullString);
                v79 = v78;
                a4a = (int)v78;
                v80 = (const wchar_t *)&gszNullString;
                if ( lpszKeyName )
                  v80 = lpszKeyName;
                v81 = _wcsdup(v80);
                a3 = (int)v81;
                szKeyName = (LPCWSTR)MakeRegistryKeyName(
                                       (CCmdString *)v103,
                                       hKey,
                                       (CCmdString *)&handle,
                                       (CCmdString *)&v141);
                v82 = MakeRegistryKeyName((CCmdString *)v105, hKey, (CCmdString *)&a3, (CCmdString *)&a4a);
                LOBYTE(v150) = 43;
                handle = (HANDLE)PE_UpdateSystemKey(
                                   dwValue,
                                   0,
                                   (HANDLE)0xFFFFFFFF,
                                   0,
                                   v82,
                                   (CCmdString *)szKeyName,
                                   &str3);
                free(*(void **)v105);
                free(*(void **)v103);
                free(v81);
                free(v79);
                free(v77);
                free((void *)v141);
                free(str3.m_String);
                free(v145);
                free(a1a);
                free(*(void **)szArg);
                free((void *)szArg4);
                free((void *)szArg3);
              }
              v83 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName )
                v83 = lpszKeyName;
              v84 = _wcsdup(v83);
              szKeyName = v84;
              v85 = MakeRegistryKeyName((CCmdString *)v99, hKey, (CCmdString *)&szKeyName, (CCmdString *)&v148);
              LOBYTE(v150) = 45;
              PE_UpdateSystemKey(dwValue, 0xFFFFFFFF, handle, 1u, &str1, v85, &strValue);
              free(*(void **)v99);
              free(v84);
            }
            free(strValue.m_String);
            free(ppv3);
            free((void *)lpszKeyNamea);
            free(ppszText2);
            free(str1.m_String);
            goto LABEL_66;
          }
          StringItem::~StringItem((tagPEStringStruct *)v87);
          free(v145);
          free(v19);
          free((void *)lpszKeyNamea);
          free(ppszText2);
          free(v24);
          free((void *)v148.unused);
        }
        else
        {
          v51 = operator+(&v102, L"CLSID\\", (CCmdString *)&ppszText2);
          v52 = CCmdString::operator+(&v112, v51, L"\\InprocServer32");
          v53 = (WCHAR *)lpszKeyNamea;
          lpszKeyNamea = _wcsdup(v52->m_String);
          free(v53);
          free(v112.m_String);
          free(v102.m_String);
          v54 = operator+(&v110, L"HKCR\\CLSID\\", (CCmdString *)&ppszText2);
          v55 = v8;
          v8 = _wcsdup(v54->m_String);
          v138 = v8;
          free(v55);
          free(v110.m_String);
          v56 = lpszKeyNamea;
          v57 = (unsigned int)TlsGetValue(gdwTlsIndex);
          if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v56, 0, v57 | 0x20019, &hKeya)
            && !PE_ReadRegKey(hKeya, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyNamea) )
          {
            *(_DWORD *)pszText2 = malloc(2u);
            v122 = 0;
            v123 = 0;
            **(_WORD **)pszText2 = 0;
            v124 = 0;
            LOBYTE(v150) = 25;
            if ( sub_BE6CC0((WCHAR *)lpszKeyNamea, (StringItem *)pszText2) )
            {
              v58 = (const wchar_t **)sub_BE4EE0((int)&v91, dwValue, (int)pszText2, 0);
              ppv3 = _wcsdup(*v58);
              free(v19);
              free(v91);
              v59 = CCmdString::operator+(&v100, (CCmdString *)&v148, L" -> ");
              v60 = CCmdString::Append((CCmdString *)&ppv1, v59, (CCmdString *)&ppv3);
              v61 = ppszText2;
              ppszText2 = _wcsdup(v60->m_String);
              free(v61);
              free(ppv1);
              free(v100.m_String);
              v62 = (const wchar_t **)sub_BE4EE0((int)&v106, dwValue, (int)pszText2, 0);
              v50 = _wcsdup(*v62);
              strValue.m_String = v50;
              free(v145);
              free(v106);
              StringItem::~StringItem((tagPEStringStruct *)pszText2);
              RegCloseKey(hKeya);
              goto LABEL_45;
            }
            StringItem::~StringItem((tagPEStringStruct *)pszText2);
          }
          free(v145);
          free(v19);
          free((void *)lpszKeyNamea);
          free(ppszText2);
          free(str3.m_String);
          free((void *)v148.unused);
        }
LABEL_67:
        ++dwIndex;
        v148.unused = (int)malloc(2u);
        *(_WORD *)v148.unused = 0;
        v141 = (LPCWSTR)malloc(2u);
        str1.m_String = (WCHAR *)v141;
        *v141 = 0;
        ppszText2 = (wchar_t *)malloc(2u);
        *ppszText2 = 0;
        lpszKeyNamea = (LPCWSTR)malloc(2u);
        *lpszKeyNamea = 0;
        v19 = (WCHAR *)malloc(2u);
        ppv3 = v19;
        *v19 = 0;
        v20 = malloc(2u);
        v145 = v20;
        strValue.m_String = v20;
        *v20 = 0;
        LOBYTE(v150) = 22;
        if ( PE_LoadRegValues(KeyHandle, dwIndex, (LPWSTR *)&v148, 0, &Type, (void **)&ppszText2) )
          goto LABEL_68;
      }
      free(v20);
      free(v19);
      free((void *)lpszKeyNamea);
      free(ppszText2);
      free((void *)v141);
      free((void *)v148.unused);
      goto LABEL_67;
    }
LABEL_68:
    free(v20);
    free(v19);
    free((void *)lpszKeyNamea);
    free(ppszText2);
    free((void *)v141);
    free((void *)v148.unused);
    RegCloseKey(KeyHandle);
  }
  free(v8);
  free(v127.m_String);
  free(v125);
  free(v128);
  free(v126);
  return handle;
}

//----- (00BEAA30) --------------------------------------------------------
void __cdecl PE_UpdateRegistryEx(unsigned int dwValue, HKEY__ *hKey, const wchar_t *lpszKeyName, const wchar_t *lpszValueName, unsigned int ValueNameLength)
{
  const wchar_t *v5; // esi
  void *v6; // eax
  const WCHAR **v7; // ecx
  void *v8; // ebx
  wchar_t *v9; // edi
  CCmdString *v10; // eax
  wchar_t *v11; // esi
  WCHAR *ppv; // [esp+10h] [ebp-18h]
  void *v13; // [esp+14h] [ebp-14h]
  void *v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v13 = malloc(2u);
  v14 = v13;
  *(_WORD *)v13 = 0;
  v5 = lpszKeyName;
  v15 = 0;
  v6 = sub_BEAB10(dwValue, hKey, (wchar_t *)lpszKeyName, lpszValueName, ValueNameLength, (void *)0xFFFFFFFF);
  v7 = &gszNullString;
  v8 = v6;
  if ( v5 )
    v7 = (const WCHAR **)v5;
  v9 = _wcsdup((const wchar_t *)v7);
  lpszKeyName = v9;
  v10 = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)&lpszKeyName, L"\\AutorunsDisabled");
  v11 = _wcsdup(v10->m_String);
  v14 = v11;
  free(v13);
  free(ppv);
  free(v9);
  sub_BEAB10(dwValue, hKey, v11, lpszValueName, ValueNameLength, v8);
  free(v11);
}

//----- (00BEAB10) --------------------------------------------------------
void *__cdecl sub_BEAB10(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5, void *a6)
{
  _WORD *v6; // edi
  const WCHAR *v7; // esi
  wchar_t *v8; // ebx
  const wchar_t *v9; // eax
  wchar_t *v10; // eax
  wchar_t *v11; // ebx
  const wchar_t *v12; // eax
  wchar_t *v13; // eax
  wchar_t *v14; // edi
  const wchar_t *v15; // eax
  wchar_t *v16; // esi
  CCmdString *v17; // eax
  unsigned int v18; // eax
  LPCWSTR v19; // edx
  WCHAR v20; // cx
  int v21; // edx
  void *v22; // ecx
  const wchar_t ***v23; // edi
  _WORD *v24; // eax
  const wchar_t **v25; // eax
  const wchar_t **v26; // eax
  const WCHAR **v27; // eax
  const WCHAR **v28; // eax
  wchar_t *v29; // eax
  wchar_t *v30; // ebx
  const WCHAR **v31; // eax
  wchar_t *v32; // eax
  wchar_t *v33; // edi
  const wchar_t *v34; // eax
  wchar_t *v35; // esi
  CCmdString *v36; // eax
  const wchar_t *v37; // eax
  wchar_t *v38; // eax
  wchar_t *v39; // ebx
  const wchar_t *v40; // eax
  wchar_t *v41; // eax
  wchar_t *v42; // edi
  const wchar_t *v43; // eax
  wchar_t *v44; // esi
  CCmdString *v45; // eax
  const wchar_t *v46; // eax
  wchar_t *v47; // eax
  wchar_t *v48; // ebx
  const wchar_t *v49; // eax
  wchar_t *v50; // eax
  wchar_t *v51; // edi
  const wchar_t *v52; // eax
  wchar_t *v53; // esi
  CCmdString *v54; // eax
  bool v55; // zf
  int a2a; // [esp+10h] [ebp-94h]
  int v58; // [esp+14h] [ebp-90h]
  int v59; // [esp+18h] [ebp-8Ch]
  int v60; // [esp+1Ch] [ebp-88h]
  int a8; // [esp+20h] [ebp-84h]
  WCHAR v62[2]; // [esp+24h] [ebp-80h]
  WCHAR v63[2]; // [esp+28h] [ebp-7Ch]
  WCHAR v64[2]; // [esp+2Ch] [ebp-78h]
  WCHAR v65[2]; // [esp+30h] [ebp-74h]
  WCHAR v66[2]; // [esp+34h] [ebp-70h]
  void *v67; // [esp+38h] [ebp-6Ch]
  int v68; // [esp+3Ch] [ebp-68h]
  int v69; // [esp+40h] [ebp-64h]
  HKEY hKey; // [esp+44h] [ebp-60h]
  void *v71; // [esp+48h] [ebp-5Ch]
  void *v72; // [esp+4Ch] [ebp-58h]
  CCmdString v73; // [esp+50h] [ebp-54h]
  int a4; // [esp+54h] [ebp-50h]
  int a3; // [esp+58h] [ebp-4Ch]
  CCmdString str3; // [esp+5Ch] [ebp-48h]
  void *a1a; // [esp+60h] [ebp-44h]
  int a7; // [esp+64h] [ebp-40h]
  void *v79; // [esp+68h] [ebp-3Ch]
  void *v80; // [esp+6Ch] [ebp-38h]
  void *v81; // [esp+70h] [ebp-34h]
  WCHAR *ppv3; // [esp+74h] [ebp-30h]
  CCmdString *str2; // [esp+78h] [ebp-2Ch]
  LPCWSTR pszValue; // [esp+7Ch] [ebp-28h]
  LPCWSTR szKeyName; // [esp+80h] [ebp-24h]
  LPCWSTR szArg3; // [esp+84h] [ebp-20h]
  WCHAR szArg[2]; // [esp+88h] [ebp-1Ch]
  void *v88; // [esp+8Ch] [ebp-18h]
  LPCWSTR szArg4; // [esp+90h] [ebp-14h]
  char v90; // [esp+97h] [ebp-Dh]
  int v91; // [esp+A0h] [ebp-4h]

  str2 = (CCmdString *)malloc(2u);
  a7 = (int)str2;
  LOWORD(str2->m_String) = 0;
  v91 = 0;
  v6 = malloc(2u);
  v81 = v6;
  ppv3 = v6;
  *v6 = 0;
  v72 = malloc(2u);
  *(_WORD *)v72 = 0;
  v71 = malloc(2u);
  *(_WORD *)v71 = 0;
  v73.m_String = (WCHAR *)malloc(2u);
  *v73.m_String = 0;
  v7 = lpValueName;
  v8 = psz;
  LOBYTE(v91) = 4;
  if ( a6 == (void *)-1 )
  {
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    szArg3 = _wcsdup((const wchar_t *)&gszNullString);
    v88 = _wcsdup((const wchar_t *)&gszNullString);
    v79 = _wcsdup((const wchar_t *)&gszNullString);
    v80 = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    pszValue = _wcsdup((const wchar_t *)&gszNullString);
    v9 = (const wchar_t *)&gszNullString;
    if ( psz )
      v9 = psz;
    v10 = _wcsdup(v9);
    v11 = v10;
    a6 = v10;
    v12 = (const wchar_t *)&gszNullString;
    if ( lpValueName )
      v12 = lpValueName;
    v13 = _wcsdup(v12);
    v14 = v13;
    a4 = (int)v13;
    v15 = (const wchar_t *)&gszNullString;
    if ( psz )
      v15 = psz;
    v16 = _wcsdup(v15);
    a3 = (int)v16;
    szKeyName = (LPCWSTR)MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&a6, (CCmdString *)&pszValue);
    v17 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&a3, (CCmdString *)&a4);
    LOBYTE(v91) = 16;
    a6 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v17, (CCmdString *)szKeyName, &str3);
    free(*(void **)szArg);
    free(a1a);
    free(v16);
    free(v14);
    free(v11);
    free((void *)pszValue);
    free(str3.m_String);
    free(v80);
    free(v79);
    free(v88);
    free((void *)szArg3);
    LOBYTE(v91) = 4;
    free((void *)szArg4);
    v7 = lpValueName;
    v8 = psz;
    v6 = v81;
  }
  v18 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey((HKEY)a2, v8, 0, v18 | 0x20019, &hKey) )
  {
    pszValue = (LPCWSTR)malloc(2u);
    *pszValue = 0;
    LOBYTE(v91) = 17;
    if ( !PE_ReadRegKey(hKey, v7, 0, 0, (CCmdString *)&pszValue) )
    {
      v19 = pszValue;
      a1a = (void *)(pszValue + 1);
      do
      {
        v20 = *v19;
        ++v19;
      }
      while ( v20 );
      if ( ((char *)v19 - (_BYTE *)a1a) >> 1 )
      {
        v67 = 0;
        v68 = 0;
        v69 = 0;
        LOBYTE(v91) = 18;
        sub_BE6DD0((wchar_t *)pszValue, a5, (int)&v67, 0);
        v21 = v68;
        v22 = v67;
        a4 = (v68 - (signed int)v67) >> 4;
        if ( a4 )
        {
          v23 = (const wchar_t ***)((char *)v67 + 4);
          a3 = (int)v67 + 4;
          while ( 1 )
          {
            ppv3 = _wcsdup(**v23);
            free(v81);
            v24 = malloc(2u);
            a2a = (int)v24;
            v58 = 0;
            v59 = 0;
            *v24 = 0;
            v60 = 0;
            v25 = *v23;
            LOBYTE(v91) = 19;
            sub_BE6CC0((WCHAR *)*v25, (StringItem *)&a2a);
            v26 = (const wchar_t **)sub_BE4EE0((int)&a1a, a1, (int)&a2a, 0);
            a7 = (int)_wcsdup(*v26);
            free(str2);
            free(a1a);
            v27 = &gszNullString;
            if ( v7 )
              v27 = (const WCHAR **)v7;
            szArg4 = _wcsdup((const wchar_t *)v27);
            v28 = &gszNullString;
            if ( v8 )
              v28 = (const WCHAR **)v8;
            v29 = _wcsdup((const wchar_t *)v28);
            v30 = v29;
            *(_DWORD *)szArg = v29;
            v31 = &gszNullString;
            if ( v7 )
              v31 = (const WCHAR **)v7;
            v32 = _wcsdup((const wchar_t *)v31);
            v33 = v32;
            szKeyName = v32;
            v34 = (const wchar_t *)&gszNullString;
            if ( psz )
              v34 = psz;
            v35 = _wcsdup(v34);
            szArg3 = v35;
            v88 = MakeRegistryKeyName((CCmdString *)v65, (HKEY)a2, (CCmdString *)szArg, (CCmdString *)&szArg4);
            v36 = MakeRegistryKeyName((CCmdString *)v64, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&szKeyName);
            LOBYTE(v91) = 25;
            v90 = sub_BE3D40(a1, (CCmdString)v36, (int)v88, (int)&ppv3, (int)&a7, (int)&v72, (CCmdString)&v73, (int)&a8);
            free(*(void **)v64);
            free(*(void **)v65);
            free(v35);
            free(v33);
            free(v30);
            free((void *)szArg4);
            if ( v90 )
            {
              if ( a6 == (void *)-1 )
              {
                v81 = _wcsdup((const wchar_t *)&gszNullString);
                str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v80 = _wcsdup((const wchar_t *)&gszNullString);
                v79 = _wcsdup((const wchar_t *)&gszNullString);
                v88 = _wcsdup((const wchar_t *)&gszNullString);
                szArg3 = _wcsdup((const wchar_t *)&gszNullString);
                szArg4 = _wcsdup((const wchar_t *)&gszNullString);
                v37 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v37 = psz;
                v38 = _wcsdup(v37);
                v39 = v38;
                a6 = v38;
                v40 = (const wchar_t *)&gszNullString;
                if ( lpValueName )
                  v40 = lpValueName;
                v41 = _wcsdup(v40);
                v42 = v41;
                *(_DWORD *)szArg = v41;
                v43 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v43 = psz;
                v44 = _wcsdup(v43);
                szKeyName = v44;
                str2 = MakeRegistryKeyName((CCmdString *)v63, (HKEY)a2, (CCmdString *)&a6, (CCmdString *)&szArg4);
                v45 = MakeRegistryKeyName((CCmdString *)v62, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)szArg);
                LOBYTE(v91) = 37;
                a6 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v45, str2, (CCmdString *)&szArg3);
                free(*(void **)v62);
                free(*(void **)v63);
                free(v44);
                free(v42);
                free(v39);
                free((void *)szArg4);
                free((void *)szArg3);
                free(v88);
                free(v79);
                free(v80);
                free(str3.m_String);
                free(v81);
              }
              v46 = (const wchar_t *)&gszNullString;
              if ( lpValueName )
                v46 = lpValueName;
              v47 = _wcsdup(v46);
              v48 = v47;
              szArg4 = v47;
              v49 = (const wchar_t *)&gszNullString;
              if ( lpValueName )
                v49 = lpValueName;
              v50 = _wcsdup(v49);
              v51 = v50;
              *(_DWORD *)szArg = v50;
              v52 = (const wchar_t *)&gszNullString;
              if ( psz )
                v52 = psz;
              v53 = _wcsdup(v52);
              szKeyName = v53;
              v54 = MakeRegistryKeyName((CCmdString *)v66, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)szArg);
              LOBYTE(v91) = 41;
              PE_UpdateSystemKey(a1, 0xFFFFFFFF, a6, 1u, (CCmdString *)&ppv3, v54, (CCmdString *)&a7);
              free(*(void **)v66);
              free(v53);
              free(v51);
              free(v48);
            }
            LOBYTE(v91) = 18;
            StringItem::~StringItem((tagPEStringStruct *)&a2a);
            v23 = (const wchar_t ***)(a3 + 16);
            v55 = a4-- == 1;
            a3 += 16;
            str2 = (CCmdString *)a7;
            if ( v55 )
              break;
            v7 = lpValueName;
            v8 = psz;
            v81 = ppv3;
          }
          v6 = ppv3;
          v22 = v67;
          v21 = v68;
        }
        if ( v22 )
        {
          sub_BE2BF0((int)v22, v21);
          operator delete(v67);
        }
      }
    }
    RegCloseKey(hKey);
    free((void *)pszValue);
  }
  free(v73.m_String);
  free(v71);
  free(v72);
  free(v6);
  free(str2);
  return a6;
}

//----- (00BEB220) --------------------------------------------------------
void __cdecl LoadServiceRegistry(DWORD dwType, DWORD dwFlags)
{
  DWORD dwFlagsIn; // edi
  unsigned __int8 (__stdcall *v3)(); // esi
  DWORD v4; // eax
  DWORD v5; // eax
  wchar_t *v6; // esi
  wchar_t *v7; // esi
  wchar_t *v8; // esi
  wchar_t *v9; // esi
  char v10; // al
  wchar_t *v11; // esi
  wchar_t *v12; // esi
  wchar_t *v13; // esi
  wchar_t *v14; // esi
  DWORD v15; // esi
  OLECHAR *v16; // eax
  OLECHAR *v17; // eax
  OLECHAR *v18; // eax
  OLECHAR *v19; // eax
  void *v20; // esi
  wchar_t *v21; // esi
  wchar_t *v22; // esi
  wchar_t *v23; // esi
  wchar_t *v24; // esi
  wchar_t *v25; // esi
  wchar_t *v26; // esi
  wchar_t *v27; // esi
  wchar_t *v28; // esi
  wchar_t *v29; // esi
  wchar_t *v30; // esi
  wchar_t *v31; // esi
  wchar_t *v32; // esi
  wchar_t *v33; // esi
  wchar_t *v34; // esi
  wchar_t *v35; // esi
  wchar_t *v36; // esi
  wchar_t *v37; // esi
  wchar_t *v38; // esi
  wchar_t *v39; // esi
  wchar_t *v40; // esi
  wchar_t *v41; // esi
  wchar_t *v42; // esi
  wchar_t *v43; // esi
  char v44; // al
  wchar_t *v45; // esi
  wchar_t *v46; // esi
  wchar_t *v47; // esi
  wchar_t *v48; // esi
  wchar_t *v49; // esi
  wchar_t *v50; // esi
  wchar_t *v51; // esi
  wchar_t *v52; // esi
  wchar_t *v53; // esi
  wchar_t *v54; // esi
  wchar_t *v55; // esi
  wchar_t *v56; // esi
  wchar_t *v57; // esi
  wchar_t *v58; // esi
  wchar_t *v59; // esi
  wchar_t *v60; // esi
  wchar_t *v61; // esi
  wchar_t *v62; // esi
  wchar_t *v63; // esi
  wchar_t *v64; // esi
  BYTE Data[4]; // [esp+10h] [ebp-1Ch]
  DWORD cbData; // [esp+14h] [ebp-18h]
  HKEY hKey; // [esp+18h] [ebp-14h]
  DWORD Type; // [esp+1Ch] [ebp-10h]
  int ret; // [esp+28h] [ebp-4h]

  dwFlagsIn = dwFlags;
  gdwFlagsInLoadServiceRegistry = dwFlags;
  SetErrorMode(1u);
  if ( Wow64EnableWow64FsRedirection )
  {
    Wow64EnableWow64FsRedirection(0);
    TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
  }
  v3 = (unsigned __int8 (__stdcall *)())GetVersion;
  if ( dwType & 0x100 )
  {
    gdwFlagsInLoadServiceRegistry = 0x100;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"BootExecute");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"SetupExecute");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"Execute");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(
        0,
        ghLocalMachineKey,
        L"System\\CurrentControlSet\\Control\\Session Manager",
        L"S0InitialCommand");
    if ( (unsigned __int8)GetVersion() >= 6u )
    {
      v4 = GetVersion();
      if ( BYTE1(v4) >= 1u && (dwFlagsIn == 2 || dwFlagsIn == 1) )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"System\\CurrentControlSet\\Control",
          L"ServiceControlManagerExtension",
          0x20u);
    }
  }
  v5 = dwType;
  if ( dwType & 0x40000 )
  {
    gdwFlagsInLoadServiceRegistry = 0x40000;
    sub_BFD790(0);
    v5 = dwType;
  }
  if ( v5 & 0x80000 )
  {
    gdwFlagsInLoadServiceRegistry = 0x80000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, (CCmdString *)&dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    LOWORD(v5) = dwType;
  }
  if ( v5 & 0x200 )
  {
    gdwFlagsInLoadServiceRegistry = 512;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_RefreshRegistry_0(
        0,
        ghLocalMachineKey,
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_RefreshRegistry_0(
        0,
        ghLocalMachineKey,
        L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(0, ghLocalMachineKey, L"Software\\Microsoft\\Command Processor", L"Autorun", 0x2Cu);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"Software\\Wow6432Node\\Microsoft\\Command Processor",
        L"Autorun",
        0x2Cu);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(0, ghCurrentUserKey, L"Software\\Microsoft\\Command Processor", L"Autorun", 0x2Cu);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v6 = _wcsdup(L"SOFTWARE\\Classes\\Exefile\\Shell\\Open\\Command");
      dwFlags = (DWORD)v6;
      PE_RefreshRegistry2(0, (int)ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(v6);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v7 = _wcsdup(L"SOFTWARE\\Classes\\Exefile\\Shell\\Open\\Command");
      dwFlags = (DWORD)v7;
      PE_RefreshRegistry2(0, (int)ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(v7);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry2(0, ghLocalMachineKey, L"Software\\Classes\\.exe");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistry2(0, ghCurrentUserKey, L"Software\\Classes\\.exe");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry2(0, ghLocalMachineKey, L"Software\\Classes\\.cmd");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistry2(0, ghCurrentUserKey, L"Software\\Classes\\.cmd");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v8 = _wcsdup(L"SOFTWARE\\Classes\\Htmlfile\\Shell\\Open\\Command");
      dwFlags = (DWORD)v8;
      PE_RefreshRegistry2(0, (int)ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(v8);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v9 = _wcsdup(L"SOFTWARE\\Classes\\Htmlfile\\Shell\\Open\\Command");
      dwFlags = (DWORD)v9;
      PE_RefreshRegistry2(0, (int)ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(v9);
    }
    LOWORD(v5) = dwType;
    v3 = (unsigned __int8 (__stdcall *)())GetVersion;
  }
  cbData = v5 & 0x1000;
  if ( v5 & 0x1000 )
  {
    gdwFlagsInLoadServiceRegistry = 4096;
    if ( v3() < 6u )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"ServiceControllerStart",
          0x20u);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"LsaStart",
          0x20u);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(0, ghLocalMachineKey, L"SYSTEM\\Setup", L"CmdLine", 0x2Cu);
  }
  v10 = dwType;
  if ( dwType & 0x20000 )
  {
    gdwFlagsInLoadServiceRegistry = 0x20000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      sub_C05D10(0);
      v10 = dwType;
    }
  }
  if ( v10 & 0x20 )
  {
    gdwFlagsInLoadServiceRegistry = 32;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      sub_BF9580(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Services");
      v10 = dwType;
    }
  }
  if ( v10 & 0x40 )
  {
    gdwFlagsInLoadServiceRegistry = 64;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_BF1610(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Services");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v11 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Font Drivers");
      dwFlags = (DWORD)v11;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&dwFlags, 1, 0);
      ret = -1;
      free(v11);
    }
  }
  if ( cbData )
  {
    gdwFlagsInLoadServiceRegistry = 4096;
    if ( (unsigned __int8)GetVersion() < 6u )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"GinaDLL",
          0x2Cu);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"UIHost",
          0x2Cu);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"System",
          0x2Cu);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        dwFlags = (DWORD)_wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\Notify");
        sub_C02060(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free((void *)dwFlags);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"SaveDumpStart",
          0x20u);
    }
    else
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v12 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\Credential Providers");
        dwFlags = (DWORD)v12;
        sub_BE86F0(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free(v12);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v13 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\Credential Provider Filters");
        dwFlags = (DWORD)v13;
        sub_BE86F0(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free(v13);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v14 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\PLAP Providers");
        dwFlags = (DWORD)v14;
        sub_BE86F0(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free(v14);
      }
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Taskman",
        0x20u);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"SOFTWARE\\Policies\\Microsoft\\Windows\\Control Panel\\Desktop",
        L"Scrnsave.exe",
        0x2Cu);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(0, ghCurrentUserKey, L"Control Panel\\Desktop", L"Scrnsave.exe", 0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"System\\CurrentControlSet\\Control\\BootVerificationProgram",
        L"ImagePath",
        0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\GpExtensions");
      sub_C02060(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
  }
  v15 = dwType;
  if ( dwType & 0x4000 )
  {
    gdwFlagsInLoadServiceRegistry = 0x4000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"SYSTEM\\CurrentControlSet\\Control\\Print\\Monitors");
      LoadPrintServiceDirectory(0, ghLocalMachineKey, (LPCWSTR)&dwFlags, 1u);
      ret = -1;
      free((void *)dwFlags);
    }
  }
  if ( v15 & 0x8000 )
  {
    gdwFlagsInLoadServiceRegistry = 0x8000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SYSTEM\\CurrentControlSet\\Control\\SecurityProviders",
        L"SecurityProviders",
        0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_BF6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Authentication Packages");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_BF6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Notification Packages");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_BF6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Security Packages");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_BF6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa\\OSConfig", L"Security Packages");
  }
  if ( v15 & 0x10000 )
  {
    gdwFlagsInLoadServiceRegistry = 0x10000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = (DWORD)_wcsdup(L"SYSTEM\\CurrentControlSet\\Control\\NetworkProvider\\Order");
      sub_BF7710(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free((void *)dwFlags);
    }
  }
  if ( v15 & 0x2000 )
  {
    gdwFlagsInLoadServiceRegistry = 0x10000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v16 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\Protocol_Catalog9\\Catalog_Entries");
      sub_C03190(0, v16);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v17 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\NameSpace_Catalog5\\Catalog_Entries");
      sub_C027D0(0, v17);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v18 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\Protocol_Catalog9\\Catalog_Entries64");
      sub_C03190(0, v18);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v19 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\NameSpace_Catalog5\\Catalog_Entries64");
      sub_C027D0(0, v19);
    }
    LOBYTE(v15) = dwType;
  }
  v20 = (void *)(v15 & 2);
  dwFlags = (DWORD)v20;
  if ( v20 && IsWinServer((int)TlsSetValue, (int)v20) )
  {
    gdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"System\\CurrentControlSet\\Control\\Terminal Server\\Wds\\rdpwd",
        L"StartupPrograms",
        0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"AppSetup",
        0x2Cu);
  }
  if ( v20 )
  {
    gdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Startup");
      ret = 32;
      sub_BF2060(0, (int)ghLocalMachineKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logon");
      ret = 33;
      sub_BF2060(0, (int)ghCurrentUserKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logon");
      ret = 34;
      sub_BF2060(0, (int)ghLocalMachineKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Userinit",
        0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"VmApplet",
        0);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Shutdown");
      ret = 35;
      sub_BF2060(0, (int)ghLocalMachineKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      ret = 36;
      sub_BF2060(0, (int)ghCurrentUserKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      ret = 37;
      sub_BF2060(0, (int)ghLocalMachineKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Group Policy\\Scripts\\Startup");
      ret = 38;
      sub_BF2060(0, (int)ghLocalMachineKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Group Policy\\Scripts\\Shutdown");
      ret = 39;
      sub_BF2060(0, (int)ghLocalMachineKey, (int *)&Type);
      ret = -1;
      free((void *)Type);
    }
  }
  if ( dwType & 0x400 )
  {
    gdwFlagsInLoadServiceRegistry = 1024;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Windows");
      ret = 40;
      sub_BE2CB0(0, ghLocalMachineKey, &Type, L"Appinit_Dlls");
      ret = -1;
      free((void *)Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Windows");
      ret = 41;
      sub_BE2CB0(0, ghLocalMachineKey, &Type, L"Appinit_Dlls");
      ret = -1;
      free((void *)Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v21 = _wcsdup(L"System\\CurrentControlSet\\Control\\Session Manager\\AppCertDlls");
      cbData = (DWORD)v21;
      ret = 42;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v21);
      v20 = (void *)dwFlags;
    }
  }
  if ( v20 )
  {
    gdwFlagsInLoadServiceRegistry = 2;
    if ( (GetVersion() & 0x80000000) != 0 )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunServices");
        cbData = (DWORD)v20;
        ret = 43;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
        ret = -1;
        free(v20);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunServicesOnce");
        cbData = (DWORD)v20;
        ret = 44;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
        ret = -1;
        free(v20);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\RunServices");
        cbData = (DWORD)v20;
        ret = 45;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&cbData, 1, 0);
        ret = -1;
        free(v20);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\RunServicesOnce");
        cbData = (DWORD)v20;
        ret = 46;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&cbData, 1, 0);
        ret = -1;
        free(v20);
      }
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",
        L"Shell",
        0x2Cu);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Shell",
        0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",
        L"Shell",
        0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Shell",
        0x2Cu);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Taskman",
        0x20u);
    if ( !PE_OpenKey(ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\SafeBoot\\Option", 0, 0x20019u, &hKey) )
    {
      cbData = 4;
      Type = 4;
      if ( !RegQueryValueExW(hKey, L"UseAlternateShell", 0, &Type, Data, &cbData) && (dwFlagsIn == 2 || dwFlagsIn == 1) )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"System\\CurrentControlSet\\Control\\SafeBoot",
          L"AlternateShell",
          0x2Cu);
      RegCloseKey(hKey);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\AlternateShells\\AvailableShells");
      cbData = (DWORD)v20;
      ret = 47;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( IsWinServer((int)TlsSetValue, (int)v20) )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v22 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Runonce");
        cbData = (DWORD)v22;
        ret = 48;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
        ret = -1;
        free(v22);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v23 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\RunonceEx");
        cbData = (DWORD)v23;
        ret = 49;
        sub_BEF2D0(0, ghLocalMachineKey, (int)&cbData, 1, 0);
        ret = -1;
        free(v23);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v24 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Run");
        cbData = (DWORD)v24;
        ret = 50;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
        ret = -1;
        free(v24);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp",
          L"InitialProgram",
          0x2Cu);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v25 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = (DWORD)v25;
      ret = 51;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v25);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v26 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = (DWORD)v26;
      ret = 52;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v26);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v27 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = (DWORD)v27;
      ret = 53;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v27);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v28 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = (DWORD)v28;
      ret = 54;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v28);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v29 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = (DWORD)v29;
      ret = 55;
      sub_BEF2D0(0, ghLocalMachineKey, (int)&cbData, 1, 0);
      ret = -1;
      free(v29);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v30 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = (DWORD)v30;
      ret = 56;
      sub_BEF2D0(0, ghLocalMachineKey, (int)&cbData, 1, 0);
      ret = -1;
      free(v30);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v31 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = (DWORD)v31;
      ret = 57;
      sub_BEF2D0(0, ghCurrentUserKey, (int)&cbData, 1, 0);
      ret = -1;
      free(v31);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v32 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = (DWORD)v32;
      ret = 58;
      sub_BEF2D0(0, ghCurrentUserKey, (int)&cbData, 1, 0);
      ret = -1;
      free(v32);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v33 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = (DWORD)v33;
      ret = 59;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v33);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v34 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = (DWORD)v34;
      ret = 60;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v34);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v35 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = (DWORD)v35;
      ret = 61;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v35);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v36 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = (DWORD)v36;
      ret = 62;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&cbData, 1, 0);
      ret = -1;
      free(v36);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    v20 = (void *)dwFlags;
  }
  cbData = dwType & 4;
  if ( dwType & 4 )
  {
    gdwFlagsInLoadServiceRegistry = 4;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Classes\\Protocols\\Filter");
      ret = 63;
      sub_BF30B0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Classes\\Protocols\\Filter");
      ret = 64;
      sub_BF30B0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Classes\\Protocols\\Handler");
      ret = 65;
      sub_BF30B0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Classes\\Protocols\\Handler");
      ret = 66;
      sub_BF30B0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free((void *)Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Microsoft\\Internet Explorer\\Desktop\\Components");
      ret = 67;
      sub_BF39D0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free((void *)Type);
    }
  }
  if ( v20 )
  {
    gdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      sub_BFEFA0(
        0,
        (int)ghCurrentUserKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"AltStartup");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_BFEFA0(
        0,
        (int)ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Common AltStartup");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_BFEFA0(
        0,
        (int)ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Common Startup");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      sub_BFEFA0(
        0,
        (int)ghCurrentUserKey,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Startup");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows",
        L"Load",
        0x20u);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows",
        L"Run",
        0x20u);
    if ( (GetVersion() & 0x80000000) != 0 )
      sub_C01840(0);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = (DWORD)v20;
      ret = 68;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = (DWORD)v20;
      ret = 69;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&Type, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Microsoft\\Active Setup\\Installed Components");
      ret = 70;
      sub_BE23D0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free((void *)Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = (DWORD)_wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Active Setup\\Installed Components");
      ret = 71;
      sub_BE23D0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free((void *)Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows",
        L"IconServiceLib",
        0x2Cu);
  }
  if ( cbData )
  {
    gdwFlagsInLoadServiceRegistry = 4;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\SharedTaskScheduler");
      Type = (DWORD)v20;
      ret = 72;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 0, 1);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\SharedTaskScheduler");
      Type = (DWORD)v20;
      ret = 73;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 0, 1);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = (DWORD)v20;
      ret = 74;
      sub_BE86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = (DWORD)v20;
      ret = 75;
      sub_BE86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = (DWORD)v20;
      ret = 76;
      sub_BE86F0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free(v20);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = (DWORD)v20;
      ret = 77;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 0, 0);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = (DWORD)v20;
      ret = 78;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 0, 0);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = (DWORD)v20;
      ret = 79;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&Type, 0, 0);
      ret = -1;
      free(v20);
    }
  }
  if ( dwFlags )
  {
    gdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = (DWORD)v20;
      ret = 80;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&Type, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( IsWinServer((int)TlsSetValue, (int)v20) )
    {
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v37 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Runonce");
        Type = (DWORD)v37;
        ret = 81;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&Type, 1, 0);
        ret = -1;
        free(v37);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v38 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\RunonceEx");
        Type = (DWORD)v38;
        ret = 82;
        sub_BEF2D0(0, ghCurrentUserKey, (int)&Type, 1, 0);
        ret = -1;
        free(v38);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v39 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Run");
        Type = (DWORD)v39;
        ret = 83;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&Type, 1, 0);
        ret = -1;
        free(v39);
      }
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v40 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows CE Services\\AutoStartOnConnect");
      Type = (DWORD)v40;
      ret = 84;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 1, 0);
      ret = -1;
      free(v40);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v41 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows CE Services\\AutoStartOnConnect");
      Type = (DWORD)v41;
      ret = 85;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 1, 0);
      ret = -1;
      free(v41);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v42 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows CE Services\\AutoStartOnDisconnect");
      Type = (DWORD)v42;
      ret = 86;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 1, 0);
      ret = -1;
      free(v42);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v43 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows CE Services\\AutoStartOnDisconnect");
      Type = (DWORD)v43;
      ret = 87;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&Type, 1, 0);
      ret = -1;
      free(v43);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
  }
  v44 = dwType;
  if ( dwType & 0x10 )
  {
    gdwFlagsInLoadServiceRegistry = 16;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      sub_C00760(0);
      v44 = dwType;
    }
  }
  *(_DWORD *)Data = v44 & 8;
  if ( v44 & 8 )
  {
    gdwFlagsInLoadServiceRegistry = 8;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v45 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects");
      Type = (DWORD)v45;
      ret = 88;
      sub_BE86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v45);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v46 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects");
      Type = (DWORD)v46;
      ret = 89;
      sub_BE86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v46);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
  }
  if ( cbData )
  {
    gdwFlagsInLoadServiceRegistry = 4;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v47 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellExecuteHooks");
      cbData = (DWORD)v47;
      ret = 90;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 0, 1);
      ret = -1;
      free(v47);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v48 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellExecuteHooks");
      cbData = (DWORD)v48;
      ret = 91;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&cbData, 0, 1);
      ret = -1;
      free(v48);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      ret = 92;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      ret = 93;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      ret = 94;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      ret = 95;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      ret = 96;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      ret = 97;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      ret = 98;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      ret = 99;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      ret = 100;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      ret = 101;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      ret = 102;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      ret = 103;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      ret = 104;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      ret = 105;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      ret = 106;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      ret = 107;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      ret = 108;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      ret = 109;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      ret = 110;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      ret = 111;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      ret = 112;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Shellex\\DragDropHandlers");
      ret = 113;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Shellex\\DragDropHandlers");
      ret = 114;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\DragDropHandlers");
      ret = 115;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      ret = 116;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      ret = 117;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      ret = 118;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      ret = 119;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      ret = 120;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      ret = 121;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      ret = 122;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      ret = 123;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      ret = 124;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v49 = _wcsdup(L"Software\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = (DWORD)v49;
      ret = 125;
      sub_BE86F0(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(v49);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v50 = _wcsdup(L"Software\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = (DWORD)v50;
      ret = 126;
      sub_BE86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v50);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v51 = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = (DWORD)v51;
      ret = 127;
      sub_BE86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v51);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      ret = 128;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      ret = 129;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      ret = 130;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      ret = 131;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      ret = 132;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      ret = 133;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      ret = 134;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      ret = 135;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      ret = 136;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      ret = 137;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      ret = 138;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      ret = 139;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      ret = 140;
      sub_BFA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      ret = 141;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(
                        L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      ret = 142;
      sub_BFA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"Software\\Classes\\Clsid\\{AB8902B4-09CA-4bb6-B78D-A8F59079A8D5}",
        L"Inprocserver32",
        0x20u);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v52 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = (DWORD)v52;
      ret = 143;
      sub_BE86F0(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(v52);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v53 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = (DWORD)v53;
      ret = 144;
      sub_BE86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v53);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v54 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = (DWORD)v54;
      ret = 145;
      sub_BE86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v54);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
  }
  if ( *(_DWORD *)Data )
  {
    gdwFlagsInLoadServiceRegistry = 8;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v55 = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\UrlSearchHooks");
      *(_DWORD *)Data = v55;
      ret = 146;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)Data, 0, 1);
      ret = -1;
      free(v55);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v56 = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Toolbar");
      *(_DWORD *)Data = v56;
      ret = 147;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)Data, 0, 1);
      ret = -1;
      free(v56);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v57 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Toolbar");
      *(_DWORD *)Data = v57;
      ret = 148;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)Data, 0, 1);
      ret = -1;
      free(v57);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 149;
      sub_BF4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 150;
      sub_BF4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 151;
      sub_BF4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 152;
      sub_BF4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Microsoft\\Internet Explorer\\Extensions");
      ret = 153;
      sub_BF4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Microsoft\\Internet Explorer\\Extensions");
      ret = 154;
      sub_BF4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Extensions");
      ret = 155;
      sub_BF4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = (DWORD)_wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Extensions");
      ret = 156;
      sub_BF4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free((void *)cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
    }
  }
  if ( (dwType & 0x80u) != 0 )
  {
    gdwFlagsInLoadServiceRegistry = 128;
    if ( PE_OpenKey(
           ghLocalMachineKey,
           L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32",
           0,
           0x20019u,
           (PHKEY)Data) )
    {
      if ( dword_CD3628[0] && (dwFlagsIn == 2 || dwFlagsIn == 1) )
        wprintf(L"\nNo entry to display for codecs. Codecs are not supported on Nano Server.\n");
    }
    else
    {
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v58 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = (DWORD)v58;
        ret = 157;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&dwType, 1, 0);
        ret = -1;
        free(v58);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v59 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = (DWORD)v59;
        ret = 158;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&dwType, 1, 0);
        ret = -1;
        free(v59);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v60 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = (DWORD)v60;
        ret = 159;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, (LPCWSTR)&dwType, 1, 0);
        ret = -1;
        free(v60);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v61 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = (DWORD)v61;
        ret = 160;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, (LPCWSTR)&dwType, 1, 0);
        ret = -1;
        free(v61);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v62 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = (DWORD)v62;
        ret = 161;
        sub_BE86F0(0, ghCurrentUserKey, &dwType);
        ret = -1;
        free(v62);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v63 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = (DWORD)v63;
        ret = 162;
        sub_BE86F0(0, ghLocalMachineKey, &dwType);
        ret = -1;
        free(v63);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v64 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = (DWORD)v64;
        ret = 163;
        sub_BE86F0(0, ghLocalMachineKey, &dwType);
        ret = -1;
        free(v64);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_BE9030((void *)1, 0, ghCurrentUserKey, L"{083863F1-70DE-11d0-BD40-00A0C911CE86}");
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_BE9030((void *)1, 0, ghCurrentUserKey, L"{AC757296-3522-4E11-9862-C17BE5A1767E}");
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_BE9030((void *)1, 0, ghCurrentUserKey, L"{7ED96837-96F0-4812-B211-F13C24117ED3}");
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_BE9030((void *)1, 0, ghCurrentUserKey, L"{ABE3B9A4-257D-4B97-BD1A-294AF496222E}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_BE9030((void *)1, 0, ghLocalMachineKey, L"{083863F1-70DE-11d0-BD40-00A0C911CE86}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_BE9030((void *)1, 0, ghLocalMachineKey, L"{AC757296-3522-4E11-9862-C17BE5A1767E}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_BE9030((void *)1, 0, ghLocalMachineKey, L"{7ED96837-96F0-4812-B211-F13C24117ED3}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_BE9030((void *)1, 0, ghLocalMachineKey, L"{ABE3B9A4-257D-4B97-BD1A-294AF496222E}");
    }
  }
  if ( dwFlags )
  {
    gdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwType = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      ret = 164;
      sub_BF2060(0, (int)ghCurrentUserKey, (int *)&dwType);
      ret = -1;
      free((void *)dwType);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwType = (DWORD)_wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Shutdown");
      ret = 165;
      sub_BF2060(0, (int)ghLocalMachineKey, (int *)&dwType);
      free((void *)dwType);
    }
  }
}
// CD31C0: using guessed type int gdwFlagsInLoadServiceRegistry;
// CD3628: using guessed type int dword_CD3628[140];
// CD48D8: using guessed type int gdwFlagsInLoadServiceRegistry;

//----- (00BEF2D0) --------------------------------------------------------
void __cdecl sub_BEF2D0(int a1, void *a2, int a3, char a4, char a5)
{
  CCmdString *v5; // edi
  const WCHAR *v6; // esi
  unsigned int v7; // eax
  _WORD *v8; // esi
  _WORD *v9; // ebx
  CCmdString *v10; // eax
  CCmdString *v11; // eax
  wchar_t *v12; // edi
  void *v13; // ebx
  CCmdString *v14; // eax
  wchar_t *v15; // esi
  void *v16; // edi
  LSTATUS v17; // eax
  WCHAR *v18; // ebx
  wchar_t *v19; // edi
  WCHAR *v20; // esi
  CCmdString *v21; // eax
  _WORD *v22; // [esp+10h] [ebp-40h]
  void *a1a; // [esp+14h] [ebp-3Ch]
  WCHAR szArg[2]; // [esp+18h] [ebp-38h]
  int a6; // [esp+1Ch] [ebp-34h]
  LPCWSTR szArg4; // [esp+20h] [ebp-30h]
  WCHAR *ppv; // [esp+24h] [ebp-2Ch]
  WCHAR *ppv1; // [esp+28h] [ebp-28h]
  void *v29; // [esp+2Ch] [ebp-24h]
  void *v30; // [esp+30h] [ebp-20h]
  void *v31; // [esp+34h] [ebp-1Ch]
  HKEY hKey; // [esp+38h] [ebp-18h]
  HKEY__ v33; // [esp+3Ch] [ebp-14h]
  WCHAR *ppv3; // [esp+40h] [ebp-10h]
  int v35; // [esp+4Ch] [ebp-4h]

  v22 = malloc(2u);
  *v22 = 0;
  v5 = (CCmdString *)a3;
  v35 = 0;
  v6 = *(const WCHAR **)a3;
  v7 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey((HKEY)a2, v6, 0, v7 | 0x20019, &hKey) )
  {
    ppv3 = _wcsdup((const wchar_t *)&gszNullString);
    v33.unused = (int)_wcsdup((const wchar_t *)&gszNullString);
    v31 = _wcsdup((const wchar_t *)&gszNullString);
    v30 = _wcsdup((const wchar_t *)&gszNullString);
    v29 = _wcsdup((const wchar_t *)&gszNullString);
    v18 = _wcsdup((const wchar_t *)&gszNullString);
    ppv1 = v18;
    v19 = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = v19;
    v20 = _wcsdup((const wchar_t *)&gszNullString);
    ppv = v20;
    a6 = (int)MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)a3, (CCmdString *)&szArg4);
    v21 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)a3, (CCmdString *)&ppv);
    LOBYTE(v35) = 13;
    PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v21, (CCmdString *)a6, (CCmdString *)&ppv1);
    free(*(void **)szArg);
    free(a1a);
    free(v20);
    free(v19);
    free(v18);
    free(v29);
    free(v30);
    free(v31);
    free((void *)v33.unused);
    free(ppv3);
  }
  else
  {
    v31 = 0;
    v8 = malloc(2u);
    v33.unused = (int)v8;
    *v8 = 0;
    v9 = malloc(2u);
    v30 = v9;
    v29 = v9;
    *v9 = 0;
    ppv3 = (WCHAR *)malloc(2u);
    *ppv3 = 0;
    LOBYTE(v35) = 3;
    if ( !PE_LoadRegKeys(hKey, 0, (CCmdString *)&ppv3) )
    {
      do
      {
        v10 = CCmdString::operator+((CCmdString *)&ppv, v5, L"\\");
        v11 = CCmdString::Append((CCmdString *)&ppv1, v10, (CCmdString *)&ppv3);
        v12 = _wcsdup(v11->m_String);
        v33.unused = (int)v12;
        free(v8);
        free(ppv1);
        free(ppv);
        v13 = sub_BE9B70(a1, (HKEY)a2, v12, a4, a5, (HANDLE)0xFFFFFFFF, 1, 0);
        v14 = CCmdString::operator+((CCmdString *)&szArg4, (CCmdString *)&v33, L"\\AutorunsDisabled");
        v15 = _wcsdup(v14->m_String);
        v29 = v15;
        free(v30);
        free((void *)szArg4);
        sub_BE9B70(a1, (HKEY)a2, v15, a4, a5, v13, 0, 0);
        free(ppv3);
        free(v15);
        free(v12);
        v31 = (char *)v31 + 1;
        v16 = v31;
        v8 = malloc(2u);
        v33.unused = (int)v8;
        *v8 = 0;
        v9 = malloc(2u);
        v30 = v9;
        v29 = v9;
        *v9 = 0;
        ppv3 = (WCHAR *)malloc(2u);
        *ppv3 = 0;
        LOBYTE(v35) = 3;
        v17 = PE_LoadRegKeys(hKey, (DWORD)v16, (CCmdString *)&ppv3);
        v5 = (CCmdString *)a3;
      }
      while ( !v17 );
    }
    free(ppv3);
    free(v9);
    free(v8);
    RegCloseKey(hKey);
  }
  free(v22);
}
