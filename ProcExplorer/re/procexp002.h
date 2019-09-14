
//----- (00FD1000) --------------------------------------------------------
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
      chText = *(pszPathNameBuf + lpszPathName - pszPathName);
      if ( !chText )
        break;
      *pszPathNameBuf = chText;
      pszPathNameBuf = (pszPathNameBuf + 1);
      --v6;
    }
    while ( v6 );
    if ( !v6 )
    {
LABEL_14:
      pszPathNameBuf = (pszPathNameBuf - 1);
      v5 = 0x8007007A;
    }
    *pszPathNameBuf = 0;
    result = v5;
  }
  return result;
}

//----- (00FD1063) --------------------------------------------------------
// 返回 hhctrl.ocx的路�?
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
  if ( !RegQueryValueExA(hSubKey, 0, 0, &dwType, szPathName, &cbRet) )
  {
    szPathName[259] = 0;
    if ( dwType == REG_EXPAND_SZ )
      v1 = ExpandEnvironmentStringsA(szPathName, pszFileName, 260u) - 1 <= 259;
    else
      v1 = Fake_ExpandEnvironmentStrings(pszFileName, 260u, szPathName) >= 0;
  }
  RegCloseKey(hSubKey);
  return v1;
}

//----- (00FD1149) --------------------------------------------------------
int __stdcall Fake_HtmlHelp(int a1, int a2, int a3, int a4)
{
  HMODULE v4; // ecx
  FARPROC v6; // eax
  CHAR LibFileName; // [esp+Ch] [ebp-108h]

  v4 = ghHHCtrlModule;
  if ( ghHHCtrlModule || gbHHCtrlModuleInited != ghHHCtrlModule )
    goto LABEL_13;
  if ( GetHtmlHelpXPathName(&LibFileName) )
    ghHHCtrlModule = LoadLibraryA(&LibFileName);
  v4 = ghHHCtrlModule;
  if ( ghHHCtrlModule || (v4 = LoadLibraryA("hhctrl.ocx"), (ghHHCtrlModule = v4) != 0) )
  {
LABEL_13:
    v6 = HtmlHelp;
    if ( HtmlHelp )
      return (v6)(a1, a2, a3, a4);
    v6 = GetProcAddress(v4, 0xF);
    HtmlHelp = v6;
    if ( v6 )
      return (v6)(a1, a2, a3, a4);
  }
  gbHHCtrlModuleInited = 1;
  return 0;
}
// 10E57BC: using guessed type int HtmlHelp;
// 10E57C0: using guessed type int gbHHCtrlModuleInited;

//----- (00FD1200) --------------------------------------------------------
int sub_FD1200()
{
  `eh vector constructor iterator'(word_10C4900, 0x28u, 20, sub_FD3750, sub_FD3850);
  return atexit(sub_108A0D0);
}
// 10C4900: using guessed type __int16 word_10C4900[400];

//----- (00FD1230) --------------------------------------------------------
int dynamic_initializer_for__garrAccountInfo__()
{
  return atexit(sub_108A0F0);
}

//----- (00FD1240) --------------------------------------------------------
int dynamic_initializer_for__gpszTipText__()
{
  gpszTipText = _wcsdup(L"Autoruns - Sysinternals: www.sysinternals.com");
  return atexit(sub_108A150);
}

//----- (00FD1260) --------------------------------------------------------
int sub_FD1260()
{
  return atexit(sub_108A160);
}

//----- (00FD1270) --------------------------------------------------------
int sub_FD1270()
{
  return atexit(sub_108A1C0);
}

//----- (00FD1280) --------------------------------------------------------
HCURSOR dynamic_initializer_for__ghHandCursor__()
{
  HCURSOR result; // eax

  result = LoadCursorW(0, IDC_HAND);
  ghHandCursor = result;
  return result;
}
// 10C48EC: using guessed type int ghHandCursor;

//----- (00FD12A0) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48E4__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48E4 = v0;
  *v0 = 0;
  return atexit(sub_108A220);
}

//----- (00FD12C0) --------------------------------------------------------
int dynamic_initializer_for__gpszSystemPathInfo__()
{
  WCHAR *v0; // eax

  v0 = malloc(2u);
  gpszSystemPathInfo = v0;
  *v0 = 0;
  return atexit(sub_108A230);
}

//----- (00FD12E0) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48FC__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48FC = v0;
  *v0 = 0;
  return atexit(sub_108A240);
}

//----- (00FD1300) --------------------------------------------------------
int dynamic_initializer_for__gKeyNameMap__()
{
  gKeyNameMap._Mypair._Myval2._Myhead = std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode();
  return atexit(dynamic_atexit_destructor_for__gKeyNameMap__);
}

//----- (00FD1320) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48F0__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48F0 = v0;
  *v0 = 0;
  return atexit(sub_108A2D0);
}

//----- (00FD1340) --------------------------------------------------------
HCURSOR dynamic_initializer_for__ghWaitCursor__()
{
  HCURSOR result; // eax

  result = LoadCursorW(0, IDC_WAIT);
  ghWaitCursor = result;
  return result;
}
// 10C48E8: using guessed type int ghWaitCursor;

//----- (00FD1360) --------------------------------------------------------
int dynamic_initializer_for__dword_4F4C54__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  gszPrintDirectoryForX86 = v0;
  *v0 = 0;
  return atexit(sub_108A2F0);
}

//----- (00FD1380) --------------------------------------------------------
int dynamic_initializer_for__dword_4F4C50__()
{
  WCHAR *v0; // eax

  v0 = malloc(2u);
  gszPrintDirectoryForNTX86.m_String = v0;
  *v0 = 0;
  return atexit(sub_108A300);
}

//----- (00FD13A0) --------------------------------------------------------
int dynamic_initializer_for__gList5_gList6__()
{
  gList5._Mypair._Myval2._Myhead = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                     0,
                                     0);
  gList6._Mypair._Myval2._Myhead = 0;
  gList6._Mypair._Myval2._Mysize = 0;
  gList6._Mypair._Myval2._Myhead = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                     0,
                                     0);
  return atexit(sub_108A310);
}
// 10C4CD8: using guessed type std__List gList5;
// 10C4CE0: using guessed type std__List gList6;

//----- (00FD1420) --------------------------------------------------------
int dynamic_initializer_for__gList1__()
{
  gList1 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_108A320);
}

//----- (00FD1440) --------------------------------------------------------
int dynamic_initializer_for__gList2__()
{
  gList2 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_108A3F0);
}

//----- (00FD1460) --------------------------------------------------------
int dynamic_initializer_for__gList3__()
{
  gList3 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_108A4C0);
}

//----- (00FD1480) --------------------------------------------------------
int dynamic_initializer_for__gMap5__()
{
  gMap5 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_108A590);
}

//----- (00FD14A0) --------------------------------------------------------
int sub_FD14A0()
{
  return atexit(sub_108A610);
}

//----- (00FD14B0) --------------------------------------------------------
int sub_FD14B0()
{
  return atexit(sub_108A620);
}

//----- (00FD14C0) --------------------------------------------------------
int sub_FD14C0()
{
  return atexit(sub_108A630);
}

//----- (00FD14D0) --------------------------------------------------------
int dynamic_initializer_for__gActiveScriptEventConsumer__()
{
  ActiveScriptEventConsumer::ActiveScriptEventConsumer(&gActiveScriptEventConsumer);
  return atexit(sub_108A640);
}
// 10C4D28: using guessed type struct ActiveScriptEventConsumer gActiveScriptEventConsumer;

//----- (00FD14F0) --------------------------------------------------------
int dynamic_initializer_for__gCommandLineEventConsumer__()
{
  CommandLineEventConsumer::CommandLineEventConsumer(&gCommandLineEventConsumer);
  return atexit(sub_108A660);
}
// 10C4D1C: using guessed type struct CommandLineEventConsumer gCommandLineEventConsumer;

//----- (00FD1510) --------------------------------------------------------
int dynamic_initializer_for__gMap6__()
{
  gMap6 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_108A680);
}

//----- (00FD1530) --------------------------------------------------------
ATOM dynamic_initializer_for__gAtomTreeListProperty__()
{
  ATOM result; // ax

  result = GlobalAddAtomW(L"TreeListProperty");
  gAtomTreeListProperty = result;
  return result;
}
// 10C4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00FD1550) --------------------------------------------------------
ATOM dynamic_initializer_for__gAtomTreeList__()
{
  ATOM result; // ax

  result = CTreeList::Register();
  gAtomTreeList = result;
  return result;
}
// 10C4D9C: using guessed type __int16 gAtomTreeList;

//----- (00FD1560) --------------------------------------------------------
BOOL dynamic_initializer_for__gLogPixelSize__()
{
  HDC v0; // edi

  v0 = CreateCompatibleDC(0);
  gLogPixelSize.x = GetDeviceCaps(v0, 88);
  gLogPixelSize.y = GetDeviceCaps(v0, 90);
  return DeleteDC(v0);
}

//----- (00FD1590) --------------------------------------------------------
int dynamic_initializer_for__ghUxthemeModule__()
{
  ghUxthemeModule = LoadLibraryW(L"uxtheme.dll");
  return atexit(sub_108A700);
}

//----- (00FD15B0) --------------------------------------------------------
FARPROC dynamic_initializer_for__gpfnCloseThemeData__()
{
  FARPROC result; // eax

  result = ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "CloseThemeData");
    gpfnCloseThemeData = result;
  }
  else
  {
    gpfnCloseThemeData = 0;
  }
  return result;
}

//----- (00FD15E0) --------------------------------------------------------
int (__stdcall *sub_FD15E0())(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCRECT pRect, LPCRECT pClipRect)
{
  int (__stdcall *result)(HTHEME, HDC, int, int, LPCRECT, LPCRECT); // eax

  result = ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "DrawThemeBackground");
    gpfnDrawThemeBackground = result;
  }
  else
  {
    gpfnDrawThemeBackground = 0;
  }
  return result;
}

//----- (00FD1610) --------------------------------------------------------
int (__stdcall *sub_FD1610())()
{
  int (__stdcall *result)(); // eax

  result = ghUxthemeModule;
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
// 10C4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (00FD1640) --------------------------------------------------------
FARPROC sub_FD1640()
{
  FARPROC result; // eax

  result = ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "OpenThemeData");
    gpfnOpenThemeData = result;
  }
  else
  {
    gpfnOpenThemeData = 0;
  }
  return result;
}

//----- (00FD1670) --------------------------------------------------------
IAtlStringMgr *sub_FD1670()
{
  IAtlStringMgr *result; // eax

  result = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  byte_10C4DF4 = 1;
  return result;
}
// 10C4DF4: using guessed type char byte_10C4DF4;

//----- (00FD1680) --------------------------------------------------------
int dynamic_initializer_for__gList4__()
{
  gBstrList = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_108A720);
}

//----- (00FD16A0) --------------------------------------------------------
FARPROC sub_FD16A0()
{
  HMODULE v0; // eax
  FARPROC result; // eax

  v0 = LoadLibraryW(L"Advapi32.dll");
  result = GetProcAddress(v0, "EnableTraceEx");
  EnableTraceEx = result;
  return result;
}

//----- (00FD16C0) --------------------------------------------------------
int dynamic_initializer_for__gList7__()
{
  gAdapterLuidList._Mypair._Myval2._Myhead = sub_1014360(0, 0);
  return atexit(sub_108A840);
}

//----- (00FD16E0) --------------------------------------------------------
HANDLE dynamic_initializer_for__gProperties__()
{
  HANDLE result; // eax

  result = CreateEventW(0, 1, 0, 0);
  gProperties.EventHandle = result;
  gProperties.ThreadHandle = 0;
  return result;
}

//----- (00FD1700) --------------------------------------------------------
DWORD sub_FD1700()
{
  DWORD v0; // eax
  double v1; // xmm0_8
  DWORD result; // eax
  double v3; // xmm0_8

  v0 = GetSysColor(15);
  stru_10BDDF0.Name = L"ColorJobs";
  stru_10BDDF0.KeyType = 0;
  v1 = v0;
  result = v0 >> 31;
  stru_10BDDF0.StructSize = 0;
  stru_10BDDF0.Address = &gConfig.ColorJobs;
  off_10BDE08 = L"ColorDelProc";
  dword_10BDE0C = 0;
  dword_10BDE10 = 0;
  v3 = v1 + qword_109D110[result];
  dword_10BDE14 = &gConfig.ColorDelProc;
  off_10BDE20 = L"ColorNewProc";
  dword_10BDE24 = 0;
  dword_10BDE28 = 0;
  stru_10BDDD8.dbValue = v3;
  stru_10BDDF0.dbValue = dbl_109EA10;
  dbl_10BDE18 = dbl_109EA18;
  dbl_10BDE30 = dbl_109EA20;
  qword_10BDE48 = qword_109EA38;
  qword_10BDE60 = *&dbl_109EA28;
  qword_10BDE90 = *&dbl_109EA30;
  qword_10BDEA8 = *&dbl_109EA08;
  dword_10BDE2C = &gConfig.ColorNewProc;
  off_10BDE38 = L"ColorNet";
  dword_10BDE3C = 0;
  dword_10BDE40 = 0;
  dword_10BDE44 = &gConfig.ColorNet;
  dword_10BDE50 = L"ColorProtected";
  dword_10BDE54 = 0;
  dword_10BDE58 = 0;
  dword_10BDE5C = &gConfig.ColorProtected;
  dword_10BDE68 = L"ShowHeatmaps";
  dword_10BDE6C = 1;
  dword_10BDE70 = 0;
  dword_10BDE74 = &gConfig.bShowColumnHeatmaps;
  qword_10BDE78 = *&db_one;
  dword_10BDE80 = L"ColorSuspend";
  dword_10BDE84 = 0;
  dword_10BDE88 = 0;
  dword_10BDE8C = &gConfig.ColorSuspend;
  dword_10BDE98 = L"StatusBarColumns";
  dword_10BDE9C = 0;
  dword_10BDEA0 = 0;
  dword_10BDEA4 = &gConfig.dwStatusBarColumns;
  dword_10BDEB0 = L"ShowAllCpus";
  dword_10BDEB4 = 1;
  dword_10BDEB8 = 0;
  dword_10BDEBC = &gConfig.bShowAllCpus;
  qword_10BDEC0 = 0i64;
  dword_10BDEC8 = L"ShowAllGpus";
  dword_10BDECC = 1;
  dword_10BDED0 = 0;
  dword_10BDED4 = &gConfig.bShowAllGpus;
  qword_10BDED8 = 0i64;
  dword_10BDEE0 = L"Opacity";
  dword_10BDEE4 = 0;
  dword_10BDEE8 = 0;
  dword_10BDEEC = &gConfig.dwOpacity;
  qword_10BDEF0 = *&db_onehundred;
  dword_10BDEF8 = L"GpuNodeUsageMask";
  dword_10BDEFC = 0;
  dword_10BDF00 = 0;
  dword_10BDF04 = &gConfig.dwGpuNodeUsageMask;
  qword_10BDF08 = *&db_one;
  dword_10BDF10 = L"VerifySignatures";
  dword_10BDF14 = 1;
  dword_10BDF18 = 0;
  dword_10BDF1C = &gConfig.bVerifySignatures;
  qword_10BDF20 = 0i64;
  dword_10BDF28 = L"VirusTotalCheck";
  dword_10BDF2C = 1;
  dword_10BDF30 = 0;
  dword_10BDF34 = &gConfig.bCheckVirusTotal;
  qword_10BDF38 = 0i64;
  dword_10BDF40 = L"VirusTotalSubmitUnknown";
  dword_10BDF44 = 1;
  dword_10BDF48 = 0;
  dword_10BDF4C = &gConfig.bVirusTotalSubmitUnknown;
  qword_10BDF50 = 0i64;
  dword_10BDF58 = L"ToolbarBands";
  dword_10BDF5C = 7;
  dword_10BDF60 = 96;
  dword_10BDF64 = gConfig.ToolBandInfo;
  qword_10BDF68 = 0i64;
  dword_10BDF70 = L"UseGoogle";
  dword_10BDF74 = 1;
  dword_10BDF78 = 0;
  dword_10BDF7C = &gConfig.bUseGoogle;
  qword_10BDF80 = 0i64;
  dword_10BDF88 = L"ShowNewProcesses";
  dword_10BDF8C = 1;
  dword_10BDF90 = 0;
  dword_10BDF94 = &gConfig.bShowNewProcesses;
  qword_10BDF98 = 0i64;
  dword_10BDFA0 = L"TrayCPUHistory";
  dword_10BDFA4 = 1;
  dword_10BDFA8 = 0;
  dword_10BDFAC = &gConfig.bTrayCPUHistory;
  qword_10BDFB0 = *&db_one;
  dword_10BDFB8 = L"ShowIoTray";
  dword_10BDFBC = 1;
  dword_10BDFC0 = 0;
  dword_10BDFC4 = &gConfig.bShowIoTray;
  qword_10BDFC8 = 0i64;
  dword_10BDFD0 = L"ShowNetTray";
  dword_10BDFD4 = 1;
  dword_10BDFD8 = 0;
  dword_10BDFDC = &gConfig.bShowNetTray;
  qword_10BDFE0 = 0i64;
  dword_10BDFE8 = L"ShowDiskTray";
  dword_10BDFEC = 1;
  dword_10BDFF0 = 0;
  dword_10BDFF4 = &gConfig.bShowDiskTray;
  qword_10BDFF8 = 0i64;
  dword_10BE000 = L"ShowPhysTray";
  dword_10BE004 = 1;
  dword_10BE008 = 0;
  dword_10BE00C = &gConfig.bShowPhysTray;
  qword_10BE010 = 0i64;
  dword_10BE018 = L"ShowCommitTray";
  dword_10BE01C = 1;
  dword_10BE020 = 0;
  dword_10BE024 = &gConfig.bShowCommitTray;
  qword_10BE028 = 0i64;
  dword_10BE030 = L"ShowGpuTray";
  dword_10BE034 = 1;
  dword_10BE038 = 0;
  dword_10BE03C = &gConfig.bShowGpuHistory;
  qword_10BE040 = 0i64;
  dword_10BE048 = L"FormatIoBytes";
  dword_10BE04C = 1;
  dword_10BE050 = 0;
  dword_10BE054 = &gConfig.bFormatIoBytes;
  qword_10BE058 = *&db_one;
  dword_10BE060 = L"StackWindowPlacement";
  dword_10BE064 = 7;
  dword_10BE068 = 44;
  dword_10BE06C = &gConfig.WindowPlacement[5];
  qword_10BE070 = 0i64;
  dword_10BE078 = L"ETWstandardUserWarning";
  dword_10BE07C = 1;
  dword_10BE080 = 0;
  dword_10BE084 = &gConfig.bETWStandardUserWarning;
  qword_10BE088 = 0i64;
  dword_10BE090 = 0;
  dword_10BE094 = 0;
  dword_10BE098 = 0;
  dword_10BE09C = 0;
  qword_10BE0A0 = 0i64;
  return result;
}
// 109CDC0: using guessed type double db_onehundred;
// 109DAD8: using guessed type wchar_t aColorjobs[10];
// 109DAEC: using guessed type wchar_t aColordelproc[13];
// 109DB08: using guessed type wchar_t aColornewproc[13];
// 109DB24: using guessed type wchar_t aColornet[9];
// 109DB38: using guessed type wchar_t aColorprotected[15];
// 109DB58: using guessed type wchar_t aShowheatmaps[13];
// 109DB74: using guessed type wchar_t aColorsuspend[13];
// 109DB90: using guessed type wchar_t aStatusbarcolum[17];
// 109DBB4: using guessed type wchar_t aShowallcpus[12];
// 109DBCC: using guessed type wchar_t aShowallgpus[12];
// 109DBF4: using guessed type wchar_t aGpunodeusagema[17];
// 109DC18: using guessed type wchar_t aVerifysignatur[17];
// 109DC3C: using guessed type wchar_t aVirustotalchec[16];
// 109DC5C: using guessed type wchar_t aVirustotalsubm[24];
// 109DC8C: using guessed type wchar_t aToolbarbands[13];
// 109DCA8: using guessed type wchar_t aUsegoogle[10];
// 109DCBC: using guessed type wchar_t aShownewprocess[17];
// 109DCE0: using guessed type wchar_t aTraycpuhistory[15];
// 109DD00: using guessed type wchar_t aShowiotray[11];
// 109DD18: using guessed type wchar_t aShownettray[12];
// 109DD30: using guessed type wchar_t aShowdisktray[13];
// 109DD4C: using guessed type wchar_t aShowphystray[13];
// 109DD68: using guessed type wchar_t aShowcommittray[15];
// 109DD88: using guessed type wchar_t aShowgputray[12];
// 109DDA0: using guessed type wchar_t aFormatiobytes[14];
// 109DDBC: using guessed type wchar_t aStackwindowpla[21];
// 109DDE8: using guessed type wchar_t aEtwstandarduse[23];
// 109EA08: using guessed type double dbl_109EA08;
// 109EA10: using guessed type double dbl_109EA10;
// 109EA18: using guessed type double dbl_109EA18;
// 109EA20: using guessed type double dbl_109EA20;
// 109EA28: using guessed type double dbl_109EA28;
// 109EA30: using guessed type double dbl_109EA30;
// 109EA38: using guessed type __int64 qword_109EA38;
// 10BDDD8: using guessed type tagConfigItem;
// 10BDDF0: using guessed type tagConfigItem stru_10BDDF0;
// 10BDE08: using guessed type void *off_10BDE08;
// 10BDE0C: using guessed type int dword_10BDE0C;
// 10BDE10: using guessed type int dword_10BDE10;
// 10BDE14: using guessed type int dword_10BDE14;
// 10BDE18: using guessed type double dbl_10BDE18;
// 10BDE20: using guessed type void *off_10BDE20;
// 10BDE24: using guessed type int dword_10BDE24;
// 10BDE28: using guessed type int dword_10BDE28;
// 10BDE2C: using guessed type int dword_10BDE2C;
// 10BDE30: using guessed type double dbl_10BDE30;
// 10BDE38: using guessed type void *off_10BDE38;
// 10BDE3C: using guessed type int dword_10BDE3C;
// 10BDE40: using guessed type int dword_10BDE40;
// 10BDE44: using guessed type int dword_10BDE44;
// 10BDE48: using guessed type __int64 qword_10BDE48;
// 10BDE50: using guessed type int dword_10BDE50;
// 10BDE54: using guessed type int dword_10BDE54;
// 10BDE58: using guessed type int dword_10BDE58;
// 10BDE5C: using guessed type int dword_10BDE5C;
// 10BDE60: using guessed type __int64 qword_10BDE60;
// 10BDE68: using guessed type int dword_10BDE68;
// 10BDE6C: using guessed type int dword_10BDE6C;
// 10BDE70: using guessed type int dword_10BDE70;
// 10BDE74: using guessed type int dword_10BDE74;
// 10BDE78: using guessed type __int64 qword_10BDE78;
// 10BDE80: using guessed type int dword_10BDE80;
// 10BDE84: using guessed type int dword_10BDE84;
// 10BDE88: using guessed type int dword_10BDE88;
// 10BDE8C: using guessed type int dword_10BDE8C;
// 10BDE90: using guessed type __int64 qword_10BDE90;
// 10BDE98: using guessed type int dword_10BDE98;
// 10BDE9C: using guessed type int dword_10BDE9C;
// 10BDEA0: using guessed type int dword_10BDEA0;
// 10BDEA4: using guessed type int dword_10BDEA4;
// 10BDEA8: using guessed type __int64 qword_10BDEA8;
// 10BDEB0: using guessed type int dword_10BDEB0;
// 10BDEB4: using guessed type int dword_10BDEB4;
// 10BDEB8: using guessed type int dword_10BDEB8;
// 10BDEBC: using guessed type int dword_10BDEBC;
// 10BDEC0: using guessed type __int64 qword_10BDEC0;
// 10BDEC8: using guessed type int dword_10BDEC8;
// 10BDECC: using guessed type int dword_10BDECC;
// 10BDED0: using guessed type int dword_10BDED0;
// 10BDED4: using guessed type int dword_10BDED4;
// 10BDED8: using guessed type __int64 qword_10BDED8;
// 10BDEE0: using guessed type int dword_10BDEE0;
// 10BDEE4: using guessed type int dword_10BDEE4;
// 10BDEE8: using guessed type int dword_10BDEE8;
// 10BDEEC: using guessed type int dword_10BDEEC;
// 10BDEF0: using guessed type __int64 qword_10BDEF0;
// 10BDEF8: using guessed type int dword_10BDEF8;
// 10BDEFC: using guessed type int dword_10BDEFC;
// 10BDF00: using guessed type int dword_10BDF00;
// 10BDF04: using guessed type int dword_10BDF04;
// 10BDF08: using guessed type __int64 qword_10BDF08;
// 10BDF10: using guessed type int dword_10BDF10;
// 10BDF14: using guessed type int dword_10BDF14;
// 10BDF18: using guessed type int dword_10BDF18;
// 10BDF1C: using guessed type int dword_10BDF1C;
// 10BDF20: using guessed type __int64 qword_10BDF20;
// 10BDF28: using guessed type int dword_10BDF28;
// 10BDF2C: using guessed type int dword_10BDF2C;
// 10BDF30: using guessed type int dword_10BDF30;
// 10BDF34: using guessed type int dword_10BDF34;
// 10BDF38: using guessed type __int64 qword_10BDF38;
// 10BDF40: using guessed type int dword_10BDF40;
// 10BDF44: using guessed type int dword_10BDF44;
// 10BDF48: using guessed type int dword_10BDF48;
// 10BDF4C: using guessed type int dword_10BDF4C;
// 10BDF50: using guessed type __int64 qword_10BDF50;
// 10BDF58: using guessed type int dword_10BDF58;
// 10BDF5C: using guessed type int dword_10BDF5C;
// 10BDF60: using guessed type int dword_10BDF60;
// 10BDF64: using guessed type int dword_10BDF64;
// 10BDF68: using guessed type __int64 qword_10BDF68;
// 10BDF70: using guessed type int dword_10BDF70;
// 10BDF74: using guessed type int dword_10BDF74;
// 10BDF78: using guessed type int dword_10BDF78;
// 10BDF7C: using guessed type int dword_10BDF7C;
// 10BDF80: using guessed type __int64 qword_10BDF80;
// 10BDF88: using guessed type int dword_10BDF88;
// 10BDF8C: using guessed type int dword_10BDF8C;
// 10BDF90: using guessed type int dword_10BDF90;
// 10BDF94: using guessed type int dword_10BDF94;
// 10BDF98: using guessed type __int64 qword_10BDF98;
// 10BDFA0: using guessed type int dword_10BDFA0;
// 10BDFA4: using guessed type int dword_10BDFA4;
// 10BDFA8: using guessed type int dword_10BDFA8;
// 10BDFAC: using guessed type int dword_10BDFAC;
// 10BDFB0: using guessed type __int64 qword_10BDFB0;
// 10BDFB8: using guessed type int dword_10BDFB8;
// 10BDFBC: using guessed type int dword_10BDFBC;
// 10BDFC0: using guessed type int dword_10BDFC0;
// 10BDFC4: using guessed type int dword_10BDFC4;
// 10BDFC8: using guessed type __int64 qword_10BDFC8;
// 10BDFD0: using guessed type int dword_10BDFD0;
// 10BDFD4: using guessed type int dword_10BDFD4;
// 10BDFD8: using guessed type int dword_10BDFD8;
// 10BDFDC: using guessed type int dword_10BDFDC;
// 10BDFE0: using guessed type __int64 qword_10BDFE0;
// 10BDFE8: using guessed type int dword_10BDFE8;
// 10BDFEC: using guessed type int dword_10BDFEC;
// 10BDFF0: using guessed type int dword_10BDFF0;
// 10BDFF4: using guessed type int dword_10BDFF4;
// 10BDFF8: using guessed type __int64 qword_10BDFF8;
// 10BE000: using guessed type int dword_10BE000;
// 10BE004: using guessed type int dword_10BE004;
// 10BE008: using guessed type int dword_10BE008;
// 10BE00C: using guessed type int dword_10BE00C;
// 10BE010: using guessed type __int64 qword_10BE010;
// 10BE018: using guessed type int dword_10BE018;
// 10BE01C: using guessed type int dword_10BE01C;
// 10BE020: using guessed type int dword_10BE020;
// 10BE024: using guessed type int dword_10BE024;
// 10BE028: using guessed type __int64 qword_10BE028;
// 10BE030: using guessed type int dword_10BE030;
// 10BE034: using guessed type int dword_10BE034;
// 10BE038: using guessed type int dword_10BE038;
// 10BE03C: using guessed type int dword_10BE03C;
// 10BE040: using guessed type __int64 qword_10BE040;
// 10BE048: using guessed type int dword_10BE048;
// 10BE04C: using guessed type int dword_10BE04C;
// 10BE050: using guessed type int dword_10BE050;
// 10BE054: using guessed type int dword_10BE054;
// 10BE058: using guessed type __int64 qword_10BE058;
// 10BE060: using guessed type int dword_10BE060;
// 10BE064: using guessed type int dword_10BE064;
// 10BE068: using guessed type int dword_10BE068;
// 10BE06C: using guessed type int dword_10BE06C;
// 10BE070: using guessed type __int64 qword_10BE070;
// 10BE078: using guessed type int dword_10BE078;
// 10BE07C: using guessed type int dword_10BE07C;
// 10BE080: using guessed type int dword_10BE080;
// 10BE084: using guessed type int dword_10BE084;
// 10BE088: using guessed type __int64 qword_10BE088;
// 10BE090: using guessed type int dword_10BE090;
// 10BE094: using guessed type int dword_10BE094;
// 10BE098: using guessed type int dword_10BE098;
// 10BE09C: using guessed type int dword_10BE09C;
// 10BE0A0: using guessed type __int64 qword_10BE0A0;

//----- (00FD1CE0) --------------------------------------------------------
FARPROC sub_FD1CE0()
{
  FARPROC result; // eax

  result = ghUxthemeModule;
  if ( ghUxthemeModule )
  {
    result = GetProcAddress(ghUxthemeModule, "EnableThemeDialogTexture");
    gpfnEnableThemeDialogTexture = result;
  }
  else
  {
    gpfnEnableThemeDialogTexture = 0;
  }
  return result;
}
// 10C9E88: using guessed type int (__stdcall *gpfnEnableThemeDialogTexture)(_DWORD, _DWORD);

//----- (00FD1D10) --------------------------------------------------------
int dynamic_initializer_for__gPerformanceInfoInMemory__()
{
  PE_PerfInfo::PE_PerfInfo(&gPerformanceInfoInMemory, &gPerformanceInfo);
  return atexit(sub_108A9D0);
}

//----- (00FD1D30) --------------------------------------------------------
int dynamic_initializer_for__gPerformanceInfo__()
{
  PerformanceInfo::PerformanceInfo(&gPerformanceInfo, 0);
  return atexit(sub_108A9E0);
}

//----- (00FD1D50) --------------------------------------------------------
int dynamic_initializer_for__gNullString__()
{
  BSTR v0; // esi
  Data_t_bstr_t *v1; // eax

  v0 = SysAllocStringLen(&strIn, 1u);
  v1 = operator new(0xCu);
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
    _com_issue_error(-2147024882);
  return atexit(sub_108A9F0);
}

//----- (00FD1DE0) --------------------------------------------------------
int dynamic_initializer_for__gWbemServicesList__()
{
  *(&gWbemServiceList + 1) = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                               0,
                               0);
  return atexit(sub_108AA50);
}

//----- (00FD1E00) --------------------------------------------------------
BOOL dynamic_initializer_for__gTime__()
{
  GetSystemTimeAsFileTime(&gTime);
  QueryPerformanceCounter(&gTime.Performance);
  return QueryPerformanceFrequency(&gTime.Frequency);
}

//----- (00FD1E30) --------------------------------------------------------
int dynamic_initializer_for__gMap1__()
{
  gThreadProcessMap._Header = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_108AB20);
}

//----- (00FD1E50) --------------------------------------------------------
bool dynamic_initializer_for__gbBitmapOnRight__()
{
  bool result; // al

  result = IsXPDll();
  gbBitmapOnRight = result;
  return result;
}
// 10CA8F8: using guessed type char gbBitmapOnRight;

//----- (00FD1E60) --------------------------------------------------------
int dynamic_initializer_for__gDiskGraphInfo__()
{
  _bstr_t::_bstr_t(&gDiskGraphInfo.strName, "Disk");
  gDiskGraphInfo.pGraphData = 0;
  gDiskGraphInfo.dbMemorySize = 0i64;
  gDiskGraphInfo.nItemID = 8;
  return atexit(sub_108ABA0);
}

//----- (00FD1EA0) --------------------------------------------------------
int dynamic_initializer_for__gIOGraphInfo__()
{
  _bstr_t::_bstr_t(&gIOGraphInfo.strName, "I/O");
  gIOGraphInfo.pGraphData = 0;
  gIOGraphInfo.dbMemorySize = 0i64;
  gIOGraphInfo.nItemID = 2;
  return atexit(sub_108AC00);
}

//----- (00FD1EE0) --------------------------------------------------------
int dynamic_initializer_for__gNetworkGraphInfo__()
{
  _bstr_t::_bstr_t(&gNetworkGraphInfo.strName, "Network");
  gNetworkGraphInfo.pGraphData = 0;
  gNetworkGraphInfo.dbMemorySize = 0i64;
  gNetworkGraphInfo.nItemID = 9;
  return atexit(sub_108AC60);
}

//----- (00FD1F20) --------------------------------------------------------
int sub_FD1F20()
{
  gMap2._Header = sub_1055440();
  return atexit(sub_108ACC0);
}

//----- (00FD1F40) --------------------------------------------------------
int sub_FD1F40()
{
  gMap3._Header = sub_1055440();
  return atexit(sub_108AD40);
}

//----- (00FD1F60) --------------------------------------------------------
int sub_FD1F60()
{
  int result; // eax

  result = TreeList_Item1::Reset(&gTreeList_Item[2]);
  gTreeList_Item[2].field_14 = 0;
  gTreeList_Item[2].field_10 = 0;
  gTreeList_Item[2].field_C = 0;
  return result;
}

//----- (00FD1F90) --------------------------------------------------------
int sub_FD1F90()
{
  int result; // eax

  result = TreeList_Item1::Reset(gTreeList_Item);
  gTreeList_Item[0].field_14 = 0;
  gTreeList_Item[0].field_10 = 0;
  gTreeList_Item[0].field_C = 0;
  return result;
}

//----- (00FD1FC0) --------------------------------------------------------
int sub_FD1FC0()
{
  int result; // eax

  result = TreeList_Item1::Reset(&gTreeList_Item[1]);
  gTreeList_Item[1].field_14 = 0;
  gTreeList_Item[1].field_10 = 0;
  gTreeList_Item[1].field_C = 0;
  return result;
}

//----- (00FD1FF0) --------------------------------------------------------
int dynamic_initializer_for__gHttpInfo__()
{
  gHttpInfo.m_List._Mypair._Myval2._Myhead = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                               0,
                                               0);
  gHttpInfo.m_List2._Mypair._Myval2._Myhead = 0;
  gHttpInfo.m_List2._Mypair._Myval2._Mysize = 0;
  gHttpInfo.m_List2._Mypair._Myval2._Myhead = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                0,
                                                0);
  return atexit(HttpInfo_Release);
}

//----- (00FD2070) --------------------------------------------------------
int sub_FD2070()
{
  off_10E57A4 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_108AE00);
}

//----- (00FD2090) --------------------------------------------------------
int sub_FD2090()
{
  dword_10E579C = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                    0,
                    0);
  return atexit(sub_108AED0);
}

//----- (00FD20B0) --------------------------------------------------------
int sub_FD20B0()
{
  off_10E57AC = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_108AFA0);
}

//----- (00FD20D0) --------------------------------------------------------
int sub_FD20D0()
{
  gHttpInfo.field_1C = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_108B070);
}

//----- (00FD20F0) --------------------------------------------------------
int sub_FD20F0()
{
  return atexit(sub_108B0F0);
}

//----- (00FD20FC) --------------------------------------------------------
int sub_FD20FC()
{
  std::_Init_locks::_Init_locks(&unk_10E57D8);
  return atexit(sub_108B0FC);
}

//----- (00FD2112) --------------------------------------------------------
int sub_FD2112()
{
  return atexit(sub_108B106);
}

//----- (00FD211E) --------------------------------------------------------
int sub_FD211E()
{
  return atexit(sub_108B110);
}

//----- (00FD212A) --------------------------------------------------------
int sub_FD212A()
{
  return atexit(sub_108B11A);
}

//----- (00FD2136) --------------------------------------------------------
int sub_FD2136()
{
  std::_Init_locks::_Init_locks(&unk_10E58F0);
  return atexit(sub_108B124);
}

//----- (00FD214C) --------------------------------------------------------
int dynamic_initializer_for__ATL::_AtlBaseModule___()
{
  ATL::CAtlWinModule::CAtlWinModule(&ATL::_AtlBaseModule);
  return atexit(ATL::_dynamic_atexit_destructor_for___AtlBaseModule__);
}

//----- (00FD2170) --------------------------------------------------------
_DWORD *__thiscall sub_FD2170(_DWORD *this)
{
  _DWORD *v1; // esi
  _WORD *v2; // eax
  _DWORD *result; // eax

  v1 = this;
  v2 = malloc(2u);
  *v1 = v2;
  *v2 = 0;
  result = v1;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}

//----- (00FD21A0) --------------------------------------------------------
void __thiscall sub_FD21A0(void ***this)
{
  void ***v1; // edi
  void **v2; // esi
  void **i; // ebx

  v1 = this;
  v2 = *this;
  if ( *this )
  {
    for ( i = this[1]; v2 != i; ++v2 )
      free(*v2);
    j__free(*v1);
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
  }
}

//----- (00FD21F0) --------------------------------------------------------
void __thiscall sub_FD21F0(tagPEStringStruct *this)
{
  tagPEStringStruct *v1; // edi
  void **v2; // esi
  int i; // ebx

  v1 = this;
  v2 = this->strValue[1];
  if ( v2 )
  {
    for ( i = this->strValue[2]; v2 != i; ++v2 )
      free(*v2);
    j__free(v1->strValue[1]);
    v1->strValue[1] = 0;
    v1->strValue[2] = 0;
    v1->strValue[3] = 0;
  }
  free(v1->strValue[0]);
}

//----- (00FD2250) --------------------------------------------------------
CPEString *__thiscall CPEString::Reset2(CPEString *this, CPEString *a2)
{
  CPEString *v2; // edi
  WCHAR *v3; // esi

  v2 = this;
  v3 = this->m_String;
  this->m_String = _wcsdup(a2->m_String);
  free(v3);
  return v2;
}

//----- (00FD2280) --------------------------------------------------------
CPEString *__thiscall CPEString::Reset(CPEString *this, wchar_t *a2)
{
  CPEString *v2; // edi
  WCHAR *v3; // esi

  v2 = this;
  v3 = this->m_String;
  this->m_String = _wcsdup(a2);
  free(v3);
  return v2;
}

//----- (00FD22B0) --------------------------------------------------------
CPEString *__cdecl CPEString::Append(CPEString *str, CPEString *strText1, LPCWSTR lpszText2)
{
  const wchar_t *v3; // ecx
  wchar_t *v4; // eax
  wchar_t *pszText2; // esi

  v3 = &gszNullString;
  if ( lpszText2 )
    v3 = lpszText2;
  v4 = _wcsdup(v3);
  pszText2 = v4;
  lpszText2 = v4;
  CPEString::Append(str, strText1, &lpszText2);
  free(pszText2);
  return str;
}

//----- (00FD2300) --------------------------------------------------------
void __thiscall CPEString::InsertAt(CPEString *this, const wchar_t *lpszText, unsigned int dwPos, unsigned int dwLength)
{
  CPEString *ppv_1; // eax
  WCHAR *pstr; // ecx
  unsigned int dwTextLen; // esi
  unsigned int dwLengthIn; // ebx
  unsigned int dwPosIn; // edx
  unsigned int nTextLen2; // edi
  WCHAR *v10; // eax
  CPEString *ppv_3; // ecx
  CPEString *ppv_2; // [esp+Ch] [ebp-4h]
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
  if ( (nTextLen2 - dwLengthIn) <= 0 )
  {
    // 直接复制到字符串的指定的位置
    ppv_3 = ppv_2;
  }
  else
  {
    // 重新开辟内存，进行复制
    v10 = realloc(pstr, 2 * (dwTextLen + nTextLen2 - dwLengthIn + 2));
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

//----- (00FD23D0) --------------------------------------------------------
void __cdecl sub_FD23D0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FD2480(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FD2480(a1, a2, v7, v5);
  free(v7);
}

//----- (00FD2480) --------------------------------------------------------
void *__cdecl sub_FD2480(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  HKEY v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  CPEString *v8; // esi
  CPEString *v9; // eax
  unsigned int v10; // eax
  const WCHAR *v11; // esi
  unsigned int v12; // eax
  WCHAR *v13; // esi
  void *v14; // esi
  const wchar_t **v15; // eax
  WCHAR *v16; // esi
  const wchar_t *v17; // ecx
  const wchar_t *v18; // eax
  CPEString *v19; // esi
  CPEString *v20; // eax
  char v21; // bl
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  HKEY v24; // ebx
  CPEString *v25; // esi
  CPEString *v26; // eax
  const wchar_t *v27; // eax
  CPEString *v28; // eax
  int a2a; // [esp+10h] [ebp-A4h]
  int v31; // [esp+14h] [ebp-A0h]
  int v32; // [esp+18h] [ebp-9Ch]
  int v33; // [esp+1Ch] [ebp-98h]
  WCHAR v34[2]; // [esp+20h] [ebp-94h]
  WCHAR v35[2]; // [esp+24h] [ebp-90h]
  WCHAR v36[2]; // [esp+28h] [ebp-8Ch]
  DWORD dwValue; // [esp+2Ch] [ebp-88h]
  void *v38; // [esp+30h] [ebp-84h]
  int v39; // [esp+34h] [ebp-80h]
  WCHAR v40[2]; // [esp+38h] [ebp-7Ch]
  WCHAR v41[2]; // [esp+3Ch] [ebp-78h]
  DWORD v42; // [esp+40h] [ebp-74h]
  void *v43; // [esp+44h] [ebp-70h]
  void *v44; // [esp+48h] [ebp-6Ch]
  void *v45; // [esp+4Ch] [ebp-68h]
  void *v46; // [esp+50h] [ebp-64h]
  WCHAR *v47; // [esp+54h] [ebp-60h]
  HKEY hKey; // [esp+58h] [ebp-5Ch]
  void *v49; // [esp+5Ch] [ebp-58h]
  WCHAR szArg[2]; // [esp+60h] [ebp-54h]
  void *v51; // [esp+64h] [ebp-50h]
  void *a1a; // [esp+68h] [ebp-4Ch]
  HKEY KeyHandle; // [esp+6Ch] [ebp-48h]
  LPCWSTR v54; // [esp+70h] [ebp-44h]
  LPCWSTR v55; // [esp+74h] [ebp-40h]
  LPCWSTR v56; // [esp+78h] [ebp-3Ch]
  LPCWSTR szArg3; // [esp+7Ch] [ebp-38h]
  WCHAR *pszText; // [esp+80h] [ebp-34h]
  LPCWSTR v59; // [esp+84h] [ebp-30h]
  LPCWSTR v60; // [esp+88h] [ebp-2Ch]
  LPCWSTR szArg4; // [esp+8Ch] [ebp-28h]
  LPCWSTR v62; // [esp+90h] [ebp-24h]
  LPCWSTR szKeyName; // [esp+94h] [ebp-20h]
  WCHAR *ppv3; // [esp+98h] [ebp-1Ch]
  CPEString str3; // [esp+9Ch] [ebp-18h]
  LPCWSTR lpSubKey; // [esp+A0h] [ebp-14h]
  std__List *v67; // [esp+A4h] [ebp-10h]
  int v68; // [esp+B0h] [ebp-4h]

  v4 = 0;
  v42 = 0;
  v67 = malloc(2u);
  LOWORD(v67->_Mypair._Myval2._Myhead) = 0;
  v68 = 0;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  lpSubKey = malloc(2u);
  *lpSubKey = 0;
  str3.m_String = malloc(2u);
  *str3.m_String = 0;
  v49 = malloc(2u);
  *v49 = 0;
  v46 = malloc(2u);
  *v46 = 0;
  v47 = malloc(2u);
  *v47 = 0;
  v51 = malloc(2u);
  *v51 = 0;
  v5 = a2;
  LOBYTE(v68) = 7;
  if ( a4 == -1 )
  {
    v62 = _wcsdup(&gszNullString);
    v54 = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v55 = _wcsdup(&gszNullString);
    v59 = _wcsdup(&gszNullString);
    v60 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    pszText = _wcsdup(v6);
    v56 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    szArg3 = _wcsdup(v7);
    LOBYTE(v68) = 17;
    v8 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v68) = 18;
    v9 = MakeRegistryKeyName(szArg, a2, &szArg3, &v56);
    LOBYTE(v68) = 19;
    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v9, v8, &v60);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v56);
    free(pszText);
    free(szArg4);
    free(v60);
    free(v59);
    free(v55);
    free(szKeyName);
    free(v54);
    LOBYTE(v68) = 7;
    free(v62);
    v5 = a2;
  }
  v10 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(v5, psz, 0, v10 | 0x20019, &KeyHandle) )
  {
    if ( !PE_LoadRegKeys(KeyHandle, 0, &lpSubKey) )
    {
      do
      {
        v11 = lpSubKey;
        v12 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v11, 0, v12 | 0x20019, &hKey) )
        {
          if ( !PE_LoadStrKey(KeyHandle, lpSubKey, &ppv3) )
          {
            if ( (LOWORD(v67->_Mypair._Myval2._Myhead) = 0, !PE_ReadRegKey(hKey, L"ShellComponent", 0, 0, &v67))
              && LOWORD(v67->_Mypair._Myval2._Myhead)
              || (PE_ReadRegKey(hKey, L"StubPath", 0, 0, &v67), LOWORD(v67->_Mypair._Myval2._Myhead)) )
            {
              v13 = ppv3;
              if ( !*ppv3 )
              {
                ppv3 = _wcsdup(L"n/a");
                free(v13);
              }
              a2a = malloc(2u);
              *a2a = 0;
              v31 = 0;
              v32 = 0;
              v33 = 0;
              LOBYTE(v68) = 20;
              sub_FD6CC0(v67, &a2a);
              v14 = v51;
              v51 = _wcsdup(v67);
              free(v14);
              v15 = sub_FD4EE0(&v38, a1, &a2a, 0);
              v16 = str3.m_String;
              str3.m_String = _wcsdup(*v15);
              free(v16);
              free(v38);
              dwValue = sub_FD4ED0();
              v17 = &gszNullString;
              if ( psz )
                v17 = psz;
              szKeyName = _wcsdup(v17);
              v54 = _wcsdup(&gszNullString);
              v18 = &gszNullString;
              if ( psz )
                v18 = psz;
              v62 = _wcsdup(v18);
              LOBYTE(v68) = 23;
              v19 = MakeRegistryKeyName(v41, a2, &szKeyName, &lpSubKey);
              LOBYTE(v68) = 24;
              v20 = MakeRegistryKeyName(v36, a2, &v62, &v54);
              LOBYTE(v68) = 25;
              v21 = sub_FD3D40(a1, v20, v19, &ppv3, &str3, &v49, &v47, &v39);
              free(*v36);
              free(*v41);
              free(v62);
              free(v54);
              free(szKeyName);
              if ( v21 )
              {
                if ( a4 == -1 )
                {
                  v44 = _wcsdup(&gszNullString);
                  v43 = _wcsdup(&gszNullString);
                  v45 = _wcsdup(&gszNullString);
                  szArg3 = _wcsdup(&gszNullString);
                  v56 = _wcsdup(&gszNullString);
                  pszText = _wcsdup(&gszNullString);
                  szArg4 = _wcsdup(&gszNullString);
                  v22 = &gszNullString;
                  if ( psz )
                    v22 = psz;
                  v60 = _wcsdup(v22);
                  v59 = _wcsdup(&gszNullString);
                  v23 = &gszNullString;
                  if ( psz )
                    v23 = psz;
                  v55 = _wcsdup(v23);
                  v24 = a2;
                  LOBYTE(v68) = 35;
                  v25 = MakeRegistryKeyName(v40, a2, &v60, &szArg4);
                  LOBYTE(v68) = 36;
                  v26 = MakeRegistryKeyName(v34, a2, &v55, &v59);
                  LOBYTE(v68) = 37;
                  a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v26, v25, &pszText);
                  free(*v34);
                  free(*v40);
                  free(v55);
                  free(v59);
                  free(v60);
                  free(szArg4);
                  free(pszText);
                  free(v56);
                  free(szArg3);
                  free(v45);
                  free(v43);
                  free(v44);
                }
                else
                {
                  v24 = a2;
                }
                *szArg = _wcsdup(&gszNullString);
                v27 = &gszNullString;
                if ( psz )
                  v27 = psz;
                a1a = _wcsdup(v27);
                LOBYTE(v68) = 39;
                v28 = MakeRegistryKeyName(v35, v24, &a1a, &lpSubKey);
                LOBYTE(v68) = 40;
                sub_FD3FF0(a1, dwValue, a4, 3u, &ppv3, v28, &str3);
                free(*v35);
                free(a1a);
                free(*szArg);
              }
              LOBYTE(v68) = 7;
              sub_FD21F0(&a2a);
              v4 = v42;
            }
          }
          RegCloseKey(hKey);
        }
        v42 = ++v4;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v4, &lpSubKey) );
    }
    RegCloseKey(KeyHandle);
  }
  free(v51);
  free(v47);
  free(v46);
  free(v49);
  free(str3.m_String);
  free(lpSubKey);
  free(ppv3);
  free(v67);
  return a4;
}

//----- (00FD2BC0) --------------------------------------------------------
void __stdcall sub_FD2BC0(void **a1, void **a2)
{
  void **i; // esi

  for ( i = a1; i != a2; ++i )
    free(*i);
}

//----- (00FD2BF0) --------------------------------------------------------
char *__cdecl sub_FD2BF0(int a1, int a2)
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
      v3 = *v2;
      if ( *v2 )
      {
        for ( i = *(v2 + 4); v3 != i; ++v3 )
          free(*v3);
        j__free(*v2);
        *v2 = 0;
        *(v2 + 4) = 0;
        *(v2 + 8) = 0;
      }
      free(*(v2 - 4));
      v2 += 16;
      result = (v2 - 4);
    }
    while ( v2 - 4 != a2 );
  }
  return result;
}

//----- (00FD2C60) --------------------------------------------------------
void __thiscall sub_FD2C60(int *this)
{
  int *v1; // esi

  v1 = this;
  if ( *this )
  {
    sub_FD2BF0(*this, this[1]);
    j__free(*v1);
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
  }
}

//----- (00FD2CB0) --------------------------------------------------------
void __cdecl sub_FD2CB0(int a1, void *a2, void *a3, LPCWSTR lpValueName)
{
  _WORD *v4; // ST58_4
  CPEString *v5; // esi
  void *v6; // edi
  CPEString *v7; // eax
  wchar_t *v8; // ST5C_4

  v4 = malloc(2u);
  *v4 = 0;
  v5 = a3;
  v6 = sub_FD2D60(a1, a2, *a3, lpValueName, 0xFFFFFFFF);
  v7 = CPEString::Append(&a3, v5, L"\\AutorunsDisabled");
  v8 = _wcsdup(v7->m_String);
  free(v4);
  free(a3);
  sub_FD2D60(a1, a2, v8, lpValueName, v6);
  free(v8);
}

//----- (00FD2D60) --------------------------------------------------------
void *__cdecl sub_FD2D60(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, void *a5)
{
  LPCWSTR v5; // ebx
  HKEY v6; // esi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  const wchar_t *v10; // eax
  CPEString *v11; // esi
  CPEString *v12; // eax
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
  CPEString *v24; // esi
  CPEString *v25; // eax
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  const wchar_t *v29; // eax
  const wchar_t *v30; // eax
  CPEString *v31; // esi
  CPEString *v32; // eax
  const WCHAR **v33; // eax
  const wchar_t *v34; // eax
  CPEString *v35; // eax
  WCHAR v37[2]; // [esp+10h] [ebp-A4h]
  WCHAR v38[2]; // [esp+14h] [ebp-A0h]
  WCHAR v39[2]; // [esp+18h] [ebp-9Ch]
  WCHAR v40[2]; // [esp+1Ch] [ebp-98h]
  int a2a; // [esp+20h] [ebp-94h]
  WCHAR v42[2]; // [esp+24h] [ebp-90h]
  int v43; // [esp+28h] [ebp-8Ch]
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
  wchar_t *v58; // [esp+64h] [ebp-50h]
  WCHAR *v59; // [esp+6Ch] [ebp-48h]
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
  CPEString str3; // [esp+A4h] [ebp-10h]
  int v74; // [esp+B0h] [ebp-4h]

  v58 = malloc(2u);
  *v58 = 0;
  v74 = 0;
  str3.m_String = malloc(2u);
  *str3.m_String = 0;
  v62 = malloc(2u);
  *v62 = 0;
  v57 = malloc(2u);
  *v57 = 0;
  v59 = malloc(2u);
  *v59 = 0;
  v5 = lpValueName;
  v6 = a2;
  LOBYTE(v74) = 4;
  if ( a5 == -1 )
  {
    v68 = _wcsdup(&gszNullString);
    v63 = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v67 = _wcsdup(&gszNullString);
    v69 = _wcsdup(&gszNullString);
    v70 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( lpValueName )
      v7 = lpValueName;
    szArg4 = _wcsdup(v7);
    v8 = &gszNullString;
    if ( psz )
      v8 = psz;
    pszText = _wcsdup(v8);
    v9 = &gszNullString;
    if ( lpValueName )
      v9 = lpValueName;
    v66 = _wcsdup(v9);
    v10 = &gszNullString;
    if ( psz )
      v10 = psz;
    szArg3 = _wcsdup(v10);
    LOBYTE(v74) = 14;
    v11 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v74) = 15;
    v12 = MakeRegistryKeyName(szArg, a2, &szArg3, &v66);
    LOBYTE(v74) = 16;
    a5 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v12, v11, &v70);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v66);
    free(pszText);
    free(szArg4);
    free(v70);
    free(v69);
    free(v67);
    free(szKeyName);
    free(v63);
    LOBYTE(v74) = 4;
    free(v68);
    v6 = a2;
  }
  v13 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(v6, psz, 0, v13 | 0x20019, &hKey) )
  {
    if ( !PE_ReadRegKey(hKey, lpValueName, 0, 0, &v58) )
    {
      v52 = 0;
      v53 = 0;
      v54 = 0;
      LOBYTE(v74) = 17;
      sub_FD6DD0(v58, 44, &v52, 32);
      v14 = v53;
      v15 = v52;
      v16 = 0;
      if ( (v53 - v52) >> 4 )
      {
        v17 = 0;
        *szArg = 0;
        do
        {
          ppv3 = (v15 + v17);
          v18 = sub_FD4EE0(&v44, a1, v15 + v17, 0);
          v19 = str3.m_String;
          str3.m_String = _wcsdup(*v18);
          free(v19);
          free(v44);
          a2a = sub_FD4ED0();
          v20 = &gszNullString;
          if ( v5 )
            v20 = v5;
          v67 = _wcsdup(v20);
          v21 = &gszNullString;
          if ( psz )
            v21 = psz;
          szKeyName = _wcsdup(v21);
          v22 = &gszNullString;
          if ( v5 )
            v22 = v5;
          v63 = _wcsdup(v22);
          v23 = &gszNullString;
          if ( psz )
            v23 = psz;
          v68 = _wcsdup(v23);
          LOBYTE(v74) = 21;
          v24 = MakeRegistryKeyName(v42, a2, &szKeyName, &v67);
          LOBYTE(v74) = 22;
          v25 = MakeRegistryKeyName(v37, a2, &v68, &v63);
          LOBYTE(v74) = 23;
          v26 = sub_FD3D40(a1, v25, v24, ppv3, &str3, &v62, &v59, &v43);
          free(*v37);
          free(*v42);
          free(v68);
          free(v63);
          free(szKeyName);
          LOBYTE(v74) = 17;
          free(v67);
          if ( v26 )
          {
            if ( a5 == -1 )
            {
              v45 = _wcsdup(&gszNullString);
              v49 = _wcsdup(&gszNullString);
              v56 = _wcsdup(&gszNullString);
              v51 = _wcsdup(&gszNullString);
              szArg3 = _wcsdup(&gszNullString);
              v66 = _wcsdup(&gszNullString);
              v5 = lpValueName;
              v27 = &gszNullString;
              if ( lpValueName )
                v27 = lpValueName;
              pszText = _wcsdup(v27);
              v28 = &gszNullString;
              if ( psz )
                v28 = psz;
              szArg4 = _wcsdup(v28);
              v29 = &gszNullString;
              if ( lpValueName )
                v29 = lpValueName;
              v70 = _wcsdup(v29);
              v30 = &gszNullString;
              if ( psz )
                v30 = psz;
              v69 = _wcsdup(v30);
              LOBYTE(v74) = 33;
              v31 = MakeRegistryKeyName(v40, a2, &szArg4, &pszText);
              LOBYTE(v74) = 34;
              v32 = MakeRegistryKeyName(v38, a2, &v69, &v70);
              LOBYTE(v74) = 35;
              a5 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v32, v31, &v66);
              free(*v38);
              free(*v40);
              free(v69);
              free(v70);
              free(szArg4);
              free(pszText);
              free(v66);
              free(szArg3);
              free(v51);
              free(v56);
              free(v49);
              free(v45);
            }
            else
            {
              v5 = lpValueName;
            }
            a1a = _wcsdup(&gszNullString);
            v55 = _wcsdup(&gszNullString);
            v33 = &gszNullString;
            if ( v5 )
              v33 = v5;
            v46 = _wcsdup(v33);
            v34 = &gszNullString;
            if ( psz )
              v34 = psz;
            v50 = _wcsdup(v34);
            LOBYTE(v74) = 39;
            v35 = MakeRegistryKeyName(v39, a2, &v50, &v46);
            LOBYTE(v74) = 40;
            sub_FD3FF0(a1, a2a, a5, 5u, ppv3, v35, &str3);
            free(*v39);
            free(v50);
            free(v46);
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
          v17 = *szArg + 16;
          *szArg += 16;
        }
        while ( v16 < (v53 - v52) >> 4 );
      }
      if ( v15 )
      {
        sub_FD2BF0(v15, v14);
        j__free(v52);
      }
    }
    RegCloseKey(hKey);
  }
  free(v59);
  free(v57);
  free(v62);
  free(str3.m_String);
  free(v58);
  return a5;
}

//----- (00FD3440) --------------------------------------------------------
int __cdecl sub_FD3440(int a1, int a2, int a3)
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
  v9 = a3;
  v11 = 0;
  while ( v4 != a2 )
  {
    if ( v3 )
    {
      *v3 = _wcsdup(*v4);
      LOBYTE(v11) = 2;
      sub_FD35A0((v3 + 4), (v4 + 4));
    }
    v3 += 16;
    LOBYTE(v11) = 0;
    v4 += 16;
  }
  return v3;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FD34F0) --------------------------------------------------------
wchar_t **__cdecl sub_FD34F0(std__vector *a1, const wchar_t **a2, wchar_t **a3)
{
  const wchar_t **v3; // esi
  wchar_t **v4; // edi

  v3 = a1;
  if ( a1 == a2 )
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

//----- (00FD3530) --------------------------------------------------------
_DWORD *__thiscall sub_FD3530(void *this, void *a2)
{
  _DWORD *v2; // edi

  v2 = this;
  *(this + 5) = 7;
  *(this + 4) = 0;
  *this = 0;
  if ( *(a2 + 5) >= 8u )
  {
    *this = *a2;
    *a2 = 0;
  }
  else if ( *(a2 + 4) != -1 )
  {
    memmove(this, a2, 2 * (*(a2 + 4) + 1));
  }
  v2[4] = *(a2 + 4);
  v2[5] = *(a2 + 5);
  *(a2 + 5) = 7;
  *(a2 + 4) = 0;
  *a2 = 0;
  return v2;
}

//----- (00FD35A0) --------------------------------------------------------
wchar_t ***__thiscall sub_FD35A0(wchar_t ***this, const wchar_t ***a2)
{
  wchar_t ***v2; // esi
  const wchar_t ***v3; // edi
  int v5; // [esp+0h] [ebp-24h]
  wchar_t ***v6; // [esp+10h] [ebp-14h]
  int *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v7 = &v5;
  v2 = this;
  v6 = this;
  v3 = a2;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  if ( sub_FDF930(this, v3[1] - *v3) )
  {
    v8 = 0;
    v2[1] = sub_FD34F0(*v3, v3[1], *v2);
  }
  return v2;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FD3650) --------------------------------------------------------
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
  return v3;
}

//----- (00FD3750) --------------------------------------------------------
void __thiscall sub_FD3750(void *this)
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

//----- (00FD3780) --------------------------------------------------------
BSTR **__thiscall _bstr_t::_bstr_t(_bstr_t *this, OLECHAR *psz)
{
  _bstr_t *v2; // edi
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // esi
  BSTR v5; // eax

  v2 = this;
  v3 = operator new(0xCu);
  v4 = v3;
  if ( v3 )
  {
    v3->m_str = 0;
    v3->m_RefCount = 1;
    v5 = SysAllocString(psz);
    v4->m_wstr = v5;
    if ( !v5 && psz )
      _com_issue_error(-2147024882);
  }
  else
  {
    v4 = 0;
  }
  v2->m_Data = v4;
  if ( !v4 )
    _com_issue_error(-2147024882);
  return v2;
}

//----- (00FD3820) --------------------------------------------------------
int __thiscall sub_FD3820(int this)
{
  int v1; // esi
  int result; // eax

  v1 = this;
  if ( *(this + 20) >= 8u )
    j__free(*this);
  *(v1 + 20) = 7;
  result = 0;
  *(v1 + 16) = 0;
  *v1 = 0;
  return result;
}

//----- (00FD3850) --------------------------------------------------------
void __thiscall sub_FD3850(void *this)
{
  void *v1; // esi

  v1 = this;
  if ( *(this + 5) )
  {
    j__free(*(this + 5));
    *(v1 + 5) = 0;
    *(v1 + 6) = 0;
    *(v1 + 7) = 0;
  }
  free(*(v1 + 4));
}

//----- (00FD3890) --------------------------------------------------------
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
        j_j__free(v2->m_str);
        v2->m_str = 0;
      }
      j__free(v2);
    }
    v1->m_Data = 0;
  }
}

//----- (00FD38F0) --------------------------------------------------------
int *__thiscall sub_FD38F0(int *this, const wchar_t ***a2)
{
  int *v2; // edi
  const wchar_t ***v3; // ebx
  const wchar_t **v4; // esi
  const wchar_t **v5; // eax
  void **v6; // ecx
  unsigned int v7; // edx
  void **v8; // esi
  void **v9; // ebx
  wchar_t **v10; // eax
  const wchar_t **v12; // esi
  int v13; // [esp+0h] [ebp-28h]
  int *v14; // [esp+10h] [ebp-18h]
  unsigned int v15; // [esp+14h] [ebp-14h]
  int *v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+24h] [ebp-4h]

  v16 = &v13;
  v2 = this;
  v14 = this;
  v3 = a2;
  if ( this != a2 )
  {
    v4 = *a2;
    v5 = a2[1];
    if ( *a2 == v5 )
    {
      sub_FE0010(this);
      return v2;
    }
    v6 = *this;
    v7 = v5 - v4;
    v15 = (v2[1] - *v2) >> 2;
    if ( v7 <= v15 )
    {
      v8 = sub_FF4700(v4, a2[1], v6);
      if ( v8 != v2[1] )
      {
        v9 = v2[1];
        do
        {
          free(*v8);
          ++v8;
        }
        while ( v8 != v9 );
        v3 = a2;
      }
      v10 = (*v2 + 4 * (v3[1] - *v3));
      goto LABEL_10;
    }
    if ( v7 <= (v2[2] - v6) >> 2 )
    {
      v12 = &v4[v15];
      sub_FF4700(*a2, v12, v6);
      v10 = sub_FD34F0(v12, v3[1], v2[1]);
LABEL_10:
      v2[1] = v10;
      return v2;
    }
    if ( v6 )
    {
      sub_FD2BC0(v6, v2[1]);
      j__free(*v2);
    }
    if ( sub_FDF930(v2, v3[1] - *v3) )
    {
      v17 = 0;
      v10 = sub_FD34F0(*v3, v3[1], *v2);
      goto LABEL_10;
    }
  }
  return v2;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FD3A50) --------------------------------------------------------
_bstr_t *__thiscall sub_FD3A50(_bstr_t *this, _bstr_t *a2)
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

//----- (00FD3A80) --------------------------------------------------------
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
    v4 = operator new(0xCu);
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

//----- (00FD3B40) --------------------------------------------------------
int __thiscall tagPEConfigFile::GetFileName(tagPEConfigFile *this)
{
  int result; // eax

  if ( this->pszConfigName )
    result = *this->pszConfigName;
  else
    result = 0;
  return result;
}

//----- (00FD3B50) --------------------------------------------------------
_bstr_t *__cdecl _bstr_t::operator+(_bstr_t *a1, OLECHAR *psz, _bstr_t *a2)
{
  _bstr_t::_bstr_t(a1, psz);
  _bstr_t::operator+=(a1, a2);
  return a1;
}

//----- (00FD3BC0) --------------------------------------------------------
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

//----- (00FD3C30) --------------------------------------------------------
BOOL __thiscall sub_FD3C30(BSTR **this, BSTR **a2)
{
  Data_t_bstr_t *v2; // ecx
  BSTR *v3; // eax
  OLECHAR *v5; // eax

  v2 = *this;
  v3 = *a2;
  if ( v2 == *a2 )
    return 0;
  if ( !v2 )
  {
    if ( v3 )
    {
      v5 = *v3;
      if ( v5 )
      {
        if ( SysStringLen(v5) )
          return 1;
      }
    }
    return 0;
  }
  if ( v3 )
    return bstr_t::Data_t::Compare(v2, *a2) < 0;
  if ( !v2->m_wstr || !SysStringLen(v2->m_wstr) )
    return 0;
  return 0;
}

//----- (00FD3CB0) --------------------------------------------------------
// inline _bstr_t& _bstr_t::operator+=(const _bstr_t& s)
OLECHAR ***__thiscall _bstr_t::operator+=(_bstr_t *this, _bstr_t *a2)
{
  _bstr_t *v2; // esi
  Data_t_bstr_t *v3; // eax
  BSTR *v4; // edi

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
    v4 = _bstr_t::Data_t::Data_t(v3, v2, a2);
  else
    v4 = 0;
  if ( !v4 )
    _com_issue_error(E_OUTOFMEMORY);
  _bstr_t::_Free(v2);
  v2->m_Data = v4;
  return v2;
}

//----- (00FD3D40) --------------------------------------------------------
int __cdecl sub_FD3D40(int a1, int a2, int a3, int a4, int a5, int a6, WCHAR **ppv3, int a8)
{
  const wchar_t **v8; // esi
  int result; // eax
  WCHAR *v10; // esi
  WCHAR *v11; // eax
  WCHAR *v12; // edi
  const wchar_t *v13; // eax
  wchar_t *v14; // eax
  int v15; // eax
  CPEString *v16; // esi
  CPEString *v17; // eax
  const wchar_t *v18; // edi
  const wchar_t *v19; // ecx
  WCHAR **v20; // esi
  WCHAR **v21; // esi
  CPEString *v22; // eax
  wchar_t *v23; // ST14_4
  WCHAR *v24; // ST10_4
  wchar_t *v25; // eax
  WCHAR *v26; // eax
  WCHAR *v27; // esi
  CPEString *v28; // eax
  int v29; // [esp+10h] [ebp-84h]
  OLECHAR **v30; // [esp+14h] [ebp-80h]
  int v31; // [esp+18h] [ebp-7Ch]
  OLECHAR **v32; // [esp+1Ch] [ebp-78h]
  CPEString v33; // [esp+20h] [ebp-74h]
  OLECHAR **v34; // [esp+24h] [ebp-70h]
  WCHAR *ppv1; // [esp+28h] [ebp-6Ch]
  WCHAR *ppv2; // [esp+2Ch] [ebp-68h]
  WCHAR **ppszText2; // [esp+30h] [ebp-64h]
  wchar_t *v38; // [esp+34h] [ebp-60h]
  int v39; // [esp+90h] [ebp-4h]

  v8 = a5;
  v30 = a3;
  v32 = a4;
  v34 = a5;
  ppszText2 = a6;
  v31 = a8;
  *a8 = 0;
  v29 = 20;
  if ( gbFlagsInPE_GetLongPathName )
    ExitThread(0);
  result = _wcsicmp(*a2, L"desktop.ini");
  if ( !result )
  {
    LOBYTE(result) = 0;
    return result;
  }
  if ( dword_10C3858 )
  {
    v10 = *ppv3;
    *ppv3 = _wcsdup(*a6);
    free(v10);
    v11 = malloc(2u);
    v12 = v11;
    v33.m_String = v11;
    *v11 = 0;
    v39 = 0;
    v13 = &gszNullString;
    if ( *v34 )
      v13 = *v34;
    v14 = _wcsdup(v13);
    v15 = sub_FF1290(v14, ppv3);
    if ( v15 != 2 )
    {
      if ( v15 )
      {
        if ( !**ppv3 )
          goto LABEL_24;
        v26 = _wcsdup(L"(Not Verified) ");
      }
      else
      {
        v26 = _wcsdup(L"(Verified) ");
      }
      v27 = v26;
      ppv2 = v26;
      v28 = CPEString::Append(&ppv1, &ppv2, ppv3);
      CPEString::Reset2(ppv3, v28);
      free(ppv1);
      free(v27);
      goto LABEL_24;
    }
    ppv2 = sub_FD6700(*v34, 0, 0, &v38, &v29, 0);
    if ( ppv2 )
    {
      v16 = ppszText2;
      if ( !**ppszText2 )
      {
LABEL_18:
        v23 = _wcsdup(v12);
        v24 = ppv2;
        v25 = _wcsdup(*v34);
        sub_FF11B0(v25, v24, v23);
LABEL_24:
        v39 = -1;
        free(v12);
        v8 = v34;
        goto LABEL_25;
      }
      CPEString::Reset2(&v33, ppszText2);
      v17 = operator+(&ppszText2, L"(Not verified) ", v16);
      CPEString::Reset2(ppv3, v17);
      free(ppszText2);
    }
    else
    {
      v18 = &gszNullString;
      v19 = &gszNullString;
      if ( v38 )
        v19 = v38;
      v20 = _wcsdup(v19);
      ppszText2 = v20;
      CPEString::Reset2(&v33, &ppszText2);
      free(v20);
      if ( v38 )
        v18 = v38;
      v21 = _wcsdup(v18);
      ppszText2 = v21;
      v22 = operator+(&ppv1, L"(Verified) ", &ppszText2);
      CPEString::Reset2(ppv3, v22);
      free(ppv1);
      free(v21);
    }
    v12 = v33.m_String;
    goto LABEL_18;
  }
LABEL_25:
  if ( dword_10C48D4 )
  {
    result = wcsncmp(*v8, L"File not found: ", 0x10u);
    if ( result )
      sub_FF1590(1, v31, *v30, *v32, *v8, 0);
  }
  LOBYTE(result) = 1;
  return result;
}
// 10C3858: using guessed type int dword_10C3858;
// 10C3860: using guessed type char gbFlagsInPE_GetLongPathName;
// 10C48D4: using guessed type int dword_10C48D4;

//----- (00FD3FF0) --------------------------------------------------------
int __cdecl sub_FD3FF0(int a1, DWORD dwValue, HANDLE Handle, DWORD dwFlags, CPEString *str1, CPEString *str2, CPEString *str3)
{
  CPEString strTemp; // edi
  CPEString *v8; // eax
  OLECHAR *v9; // esi
  OLECHAR *v10; // ecx
  int result; // eax
  void *v12; // esi

  if ( !(dword_10C4C48 & 1) )
  {
    dword_10C4C48 |= 1u;
    *&sStringInsub_1133FF0 = malloc(2u);
    **&sStringInsub_1133FF0 = 0;
    atexit(sub_108A2E0);
  }
  if ( Handle == -1 )
  {
    v12 = *&sStringInsub_1133FF0;
    *&sStringInsub_1133FF0 = _wcsdup(str1->m_String);
    free(v12);
    result = 0;
  }
  else
  {
    strTemp.m_String = malloc(2u);
    *strTemp.m_String = 0;
    if ( dwFlags == 9 )
    {
      v8 = CPEString::Append(&Handle, &sStringInsub_1133FF0, str1);
      v9 = _wcsdup(v8->m_String);
      free(strTemp.m_String);
      free(Handle);
    }
    else
    {
      v9 = _wcsdup(str2->m_String);
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
    sub_100BF00(v10, str3->m_String, v9);
    free(v9);
    result = 0;
  }
  return result;
}
// 108D5D8: using guessed type wchar_t aLocalSystem[13];
// 10C31C0: using guessed type int gdwFlagsInLoadServiceRegistry;
// 10C4C48: using guessed type int dword_10C4C48;

//----- (00FD4130) --------------------------------------------------------
void __cdecl LoadSystemAccountInfo(HWND hWnd)
{
  HANDLE v1; // eax
  HMENU v2; // eax
  tagAccountInfo *pAccountInfo; // eax
  OLECHAR *pszUserName_1; // edx
  tagAccountInfo *v5; // ebx
  WCHAR *v6; // esi
  OLECHAR v7; // cx
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
  OLECHAR *pszDefaultUserName; // esi
  unsigned int dwMode_1; // eax
  PSID pSID; // ebx
  tagAccountInfo *pInfo; // eax
  tagAccountInfo *pInfo_1; // esi
  OLECHAR *szDefaultUserName_1; // ecx
  WCHAR *szUserName; // edx
  OLECHAR chText; // ax
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
  OLECHAR *szDefaultUserName; // [esp+44h] [ebp-1424h]
  int TokenInformation[1024]; // [esp+48h] [ebp-1420h]
  WCHAR szName[260]; // [esp+1048h] [ebp-420h]
  WCHAR szDomainName[260]; // [esp+1250h] [ebp-218h]
  int v46; // [esp+1464h] [ebp-4h]

  hWnd1 = hWnd;
  szDefaultUserName = malloc(2u);
  *szDefaultUserName = 0;
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
  pAccountInfo = malloc(1568u);
  pszUserName_1 = szDefaultUserName;
  v5 = pAccountInfo;
  pInfo_2 = pAccountInfo;
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
  v9 = pAccountInfo->szUserName - L".Default";
  do
  {
    v10 = *v8;
    ++v8;
    *(v8 + v9 - 2) = v10;
  }
  while ( v10 );
  v5->nMenuID = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
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
  if ( EqualSid(pSid, TokenInformation[0]) )
  {
    LOBYTE(v5->bIsSystemUser) = 1;
    gpAccountInfo = v5;
  }
  else
  {
    LOBYTE(v5->bIsSystemUser) = 0;
  }
  _swprintf(v5->szProfileImgPath, L"%s\\%s", &gSystemDirInfo, L"Config");
  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(&garrAccountInfo, &pInfo_2);
  dwMode = TlsGetValue(gdwTlsIndex);
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
        pszDefaultUserName = szDefaultUserName;
        dwMode_1 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hSubKey, pszDefaultUserName, 0, dwMode_1 | KEY_READ, &hKey) )
        {
          cbData = 4;
          if ( !RegQueryValueExW(hKey, L"Flags", 0, 0, &Data, &cbData) && !(Data & 8) )
          {
            pSID = GetUserSID(szDefaultUserName);
            if ( pSID )
            {
              cchName = 260;
              cbDomainName = 260;
              if ( LookupAccountSidW(0, pSID, szName, &cchName, szDomainName, &cbDomainName, &nUse) )
              {
                pInfo = malloc(0x620u);
                cbData = 520;
                pInfo_1 = pInfo;
                pInfo_2 = pInfo;
                if ( RegQueryValueExW(hKey, L"ProfileImagePath", 0, 0, pInfo->szProfileImgPath, &cbData) )
                {
                  free(pInfo_1);
                }
                else
                {
                  szDefaultUserName_1 = szDefaultUserName;
                  szUserName = pInfo_1->szUserName;
                  do
                  {
                    chText = *szDefaultUserName_1;
                    ++szDefaultUserName_1;
                    *szUserName = chText;
                    ++szUserName;
                  }
                  while ( chText );
                  pInfo_1->nMenuID = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
                                    - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
                  _swprintf(pInfo_1->szReferenceName, L"%s\\%s", szDomainName, szName);
                  if ( hWnd1 )
                  {
                    v26 = pInfo_1->nMenuID;
                    v27 = GetMenu(hWnd1);
                    v28 = GetSubMenu(v27, 3);
                    InsertMenuW(v28, 0xFFFFFFFF, MF_BYPOSITION, v26, pInfo_1->szReferenceName);
                  }
                  if ( EqualSid(pSID, TokenInformation[0]) )
                  {
                    LOBYTE(pInfo_1->bIsSystemUser) = 1;
                    gpAccountInfo = pInfo_1;
                  }
                  else
                  {
                    LOBYTE(pInfo_1->bIsSystemUser) = 0;
                  }
                  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(&garrAccountInfo, &pInfo_2);
                  RegQueryValueExW = ::RegQueryValueExW;
                }
              }
              FreeSid(pSID);
            }
            dwIndex = pSid;
          }
          RegCloseKey(hKey);
        }
        pSid = ++dwIndex;
      }
      while ( !PE_LoadRegKeys(hSubKey, dwIndex, &szDefaultUserName) );
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
  free(szDefaultUserName);
}
// 108CA8C: using guessed type wchar_t aSystem_0[7];
// 1091FCC: using guessed type wchar_t aDefault[9];
// 1091FE0: using guessed type wchar_t aNtAuthority[13];
// 1092008: using guessed type wchar_t aConfig[7];
// 10C31CA: using guessed type char gbRestorePrivilegeFailed;

//----- (00FD4650) --------------------------------------------------------
char BackendThreadProc()
{
  const wchar_t **v0; // eax
  WCHAR *v1; // esi
  tagAccountInfo **pBuffer; // ecx
  unsigned int index; // esi
  unsigned int nCount; // eax
  WCHAR *ppstr; // [esp+4h] [ebp-4h]

  InitApis();
  gdwTlsIndex = TlsAlloc();
  TlsSetValue(gdwTlsIndex, 0);
  InitSystemPath();
  v0 = RequerySystemEnvironmentString(&ppstr, L"%PATH%");
  v1 = gpszSystemPathInfo;
  gpszSystemPathInfo = _wcsdup(*v0);
  free(v1);
  free(ppstr);
  InitializeCriticalSection(&gSystemDirInfo.Lock);
  AdjustRighToWinLogon();
  LoadSystemAccountInfo(0);
  LoadServiceRegistry(0xFFFFFFFF, 1u);
  LoadServiceRegistry(0xFFFFFFFF, 0);
  pBuffer = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
  index = 0;
  nCount = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  if ( nCount )
  {
    do
    {
      LOBYTE(nCount) = UpdateMenuItemWithAccountInfo(0, gpAccountInfo, pBuffer[index]->nMenuID);
      if ( !nCount )
        break;
      LoadServiceRegistry(0xFFFFFFFF, 0);
      ++index;
      pBuffer = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
      nCount = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
              - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    }
    while ( index < nCount );
  }
  return nCount;
}

//----- (00FD4730) --------------------------------------------------------
int __thiscall bstr_t::Data_t::Compare(Data_t_bstr_t *this, Data_t_bstr_t *str)
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
  v5 = l2;
  v6 = l1;
  len = l1;
  bstr2 = str->m_wstr;
  stra = v5;
  if ( l1 > v5 )
    len = v5;
  if ( len )
  {
    while ( 1 )
    {
      LOWORD(v9) = *bstr1;
      ++bstr2;
      ++bstr1;
      --len;
      if ( v9 != *(bstr2 - 1) )
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
    if ( v6 >= v5 )
      result = l1 != v5;
    else
      result = -1;
  }
  return result;
}

//----- (00FD47C0) --------------------------------------------------------
errno_t __cdecl wcscpy_s(wchar_t *Src, wchar_t *Dst, rsize_t SizeInWords)
{
  return wcscpy_s(Dst, SizeInWords, Src);
}

//----- (00FD47E0) --------------------------------------------------------
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

//----- (00FD4890) --------------------------------------------------------
int __cdecl sub_FD4890(int a1, wchar_t *a2)
{
  _WORD *v2; // esi
  _WORD *v3; // edi
  wchar_t *v4; // ebx
  wchar_t *v5; // esi
  int v6; // ecx
  wchar_t *v7; // ecx
  wchar_t v8; // ax
  const wchar_t **v9; // eax
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
  if ( TlsGetValue(gdwTlsIndex) == 256 )
  {
    v5 = _wcsdup(v4);
    _wcsupr(v5);
    if ( wcsstr(v5, L"%PROGRAMFILES%") )
    {
      v6 = wcsstr(v5, L"%PROGRAMFILES%") - v5;
      _mm_storeu_si128(&v4[v6], _mm_loadu_si128(L"%ProgramW6432%"));
      _mm_storel_epi64(&v4[v6 + 8], _mm_loadl_epi64(L"W6432%"));
      *&v4[v6 + 12] = *L"2%";
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
  v9 = RequerySystemEnvironmentString(&ppstr, v4);
  v10 = _wcsdup(*v9);
  free(v3);
  free(ppstr);
  v11 = _wcsdup(v10);
  free(v4);
  if ( *v10 != 34 )
  {
    if ( sub_FE1040(v10) != -1 )
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
      v18 = sub_FE1040(v10);
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
  *a1 = v19;
  free(v10);
  free(v11);
  return a1;
}

//----- (00FD4AC0) --------------------------------------------------------
int __cdecl sub_FD4AC0(int a1, wchar_t *psz)
{
  WCHAR *v2; // edi
  wchar_t *v3; // esi
  wchar_t *v4; // ebx
  unsigned int v5; // kr04_4
  const wchar_t *v6; // ecx
  WCHAR *v7; // esi
  CPEString *v8; // eax
  wchar_t *v9; // esi
  WCHAR *pszResult; // [esp+18h] [ebp-1Ch]
  void *v12; // [esp+1Ch] [ebp-18h]
  WCHAR *ppszText2; // [esp+20h] [ebp-14h]
  wchar_t *v14; // [esp+24h] [ebp-10h]
  int v15; // [esp+30h] [ebp-4h]

  v15 = 0;
  v2 = malloc(2u);
  ppszText2 = v2;
  *v2 = 0;
  v3 = _wcsdup(psz);
  v14 = v3;
  v4 = _wcsdup(gszProgameFilesX86EnvValueValue);
  LOBYTE(v15) = 3;
  _wcsupr(v4);
  _wcsupr(v3);
  if ( !wcsncmp(v3, v4, wcslen(v4)) && sub_FE1040(psz) == -1 )
  {
    v5 = wcslen(gszProgameFilesX86EnvValueValue);
    v6 = &gszNullString;
    if ( &psz[v5] )
      v6 = &psz[v5];
    v7 = _wcsdup(v6);
    ppszText2 = v7;
    v8 = operator+(&pszResult, gszProgramW6432EnvValue, &ppszText2);
    v12 = v2;
    v2 = _wcsdup(v8->m_String);
    ppszText2 = v2;
    free(v12);
    free(pszResult);
    free(v7);
    if ( sub_FE1040(v2) != -1 )
    {
      v9 = psz;
      psz = _wcsdup(v2);
      free(v9);
    }
    v3 = v14;
  }
  *a1 = _wcsdup(psz);
  free(v4);
  free(v3);
  free(v2);
  free(psz);
  return a1;
}

//----- (00FD4C50) --------------------------------------------------------
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
  *IdentifierAuthority.Value = 0;
  *&IdentifierAuthority.Value[4] = 0;
  do
  {
    chText = *pszUserName;
    ++pszUserName;
    *(pszUserName + psz - lpszUserName - 2) = chText;
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
    scan_fn(v7, L"%lu", &dwValue);
    IdentifierAuthority.Value[4] = BYTE1(dwValue);
    IdentifierAuthority.Value[5] = dwValue;
    IdentifierAuthority.Value[2] = HIBYTE(dwValue);
    IdentifierAuthority.Value[3] = BYTE2(dwValue);
  }
  else
  {
    scan_fn(v7, L"0x%02hx%02hx%02hx%02hx%02hx%02hx", &IdentifierAuthority);
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
  nCount = nCount;
  if ( nCount > 0 )
  {
    v13 = nSubAuthority;
    do
    {
      scan_fn(pstr4, L"%lu", v13);
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
  return (ret != 0 ? pSid : 0);
}

//----- (00FD4ED0) --------------------------------------------------------
signed int sub_FD4ED0()
{
  return -1;
}

//----- (00FD4EE0) --------------------------------------------------------
int __cdecl sub_FD4EE0(int a1, int a2, int a3, int a4)
{
  const WCHAR *v4; // ecx
  const WCHAR *v6; // [esp-4h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-4h]

  v6 = v4;
  v7 = 0;
  sub_FD70E0(&v6, a2, a3, a4);
  CPEString::AppendPath(a1, v6);
  return a1;
}

//----- (00FD4F20) --------------------------------------------------------
int __cdecl sub_FD4F20(int str, int a2, wchar_t *arg8)
{
  _WORD *v3; // eax
  const WCHAR *v5; // [esp-4h] [ebp-2Ch]
  tagPEStringStruct a3; // [esp+4h] [ebp-24h]
  int v7; // [esp+24h] [ebp-4h]

  a3.strValue[5] = 0;
  v3 = malloc(2u);
  a3.strValue[0] = v3;
  a3.strValue[1] = 0;
  a3.strValue[2] = 0;
  *v3 = 0;
  a3.strValue[3] = 0;
  v7 = 0;
  sub_FD7040(arg8, &a3);
  sub_FD70E0(&v5, a2, &a3, 0);
  CPEString::AppendPath(str, v5);
  sub_FD21F0(&a3);
  return str;
}

//----- (00FD4FB0) --------------------------------------------------------
wchar_t **__cdecl sub_FD4FB0(WCHAR **ppszArgs, HWND hWndIn, LPCWSTR lpszFileName)
{
  WCHAR **v3; // ebx
  wchar_t *v4; // esi
  wchar_t *pszArgs; // edi
  wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *pszPath; // ebx
  wchar_t *v9; // eax
  CPEString *v10; // eax
  WCHAR *v11; // ebx
  wchar_t *v12; // eax
  CPEString *v13; // eax
  WCHAR *ppv; // [esp+14h] [ebp-28Ch]
  std__vector theVector; // [esp+18h] [ebp-288h]
  IPersistFile *pPersistFile; // [esp+24h] [ebp-27Ch]
  HWND hWnd; // [esp+28h] [ebp-278h]
  WCHAR **v19; // [esp+2Ch] [ebp-274h]
  wchar_t *v20; // [esp+30h] [ebp-270h]
  IShellLinkW *pShellLink; // [esp+34h] [ebp-26Ch]
  void *pszFileName; // [esp+38h] [ebp-268h]
  wchar_t *a2; // [esp+3Ch] [ebp-264h]
  WIN32_FIND_DATAW FindData; // [esp+40h] [ebp-260h]
  int v25; // [esp+29Ch] [ebp-4h]

  v3 = ppszArgs;
  hWnd = hWndIn;
  v19 = ppszArgs;
  pszFileName = lpszFileName;
  v4 = malloc(2u);
  a2 = v4;
  *v4 = 0;
  v25 = 0;
  pszArgs = malloc(2u);
  v20 = pszArgs;
  *pszArgs = 0;
  LOBYTE(v25) = 1;
  CoInitializeEx(0, 0);
  if ( CoCreateInstance(&CLSID_ShellLink, 0, CLSCTX_INPROC_SERVER, &CLSID_IShellLinkW, &pShellLink) >= 0 )
  {
    if ( pShellLink->lpVtbl->QueryInterface(pShellLink, &CLSID_IPersistFile, &pPersistFile) >= 0 )
    {
      if ( pPersistFile->lpVtbl->Load(pPersistFile, pszFileName, STGM_DIRECT) >= 0
        && pShellLink->lpVtbl->Resolve(pShellLink, hWnd, 3) >= 0 )// SLR_ANY_MATCH | SLR_NO_UI
      {
        v7 = realloc(v4, 2002u);
        pszPath = v7;
        a2 = v7;
        if ( v7 )
          memset(v7, 0, 2002u);
        if ( pShellLink->lpVtbl->GetPath(pShellLink, pszPath, 1000, &FindData, SLGP_SHORTPATH) >= 0 )
        {
          sub_FD2170(&ppv);
          LOBYTE(v25) = 2;
          v9 = _wcsdup(pszPath);
          v10 = sub_FD4AC0(&pszFileName, v9);
          CPEString::Reset2(&a2, v10);
          free(pszFileName);
          v4 = a2;
          v11 = ppv;
          ppv = _wcsdup(a2);
          free(v11);
          v12 = realloc(pszArgs, 2002u);
          pszArgs = v12;
          v20 = v12;
          if ( v12 )
            memset(v12, 0, 2002u);
          if ( pShellLink->lpVtbl->GetArguments(pShellLink, pszArgs, 1000) >= 0 )
          {
            CPEString::InsertAt(&ppv, pszArgs, 0x7FFFFFFFu, 0);
            sub_FE0530(&theVector, &a2);
            sub_FE0530(&theVector, &v20);
            v13 = sub_FD70E0(&pszFileName, hWnd, &ppv, 0);
            CPEString::Reset2(&a2, v13);
            free(pszFileName);
            v4 = a2;
            pszArgs = v20;
          }
          LOBYTE(v25) = 1;
          sub_FD21F0(&ppv);
        }
        else
        {
          v4 = _wcsdup(&gszNullString);
          a2 = v4;
          free(pszPath);
        }
        v3 = v19;
      }
      pPersistFile->lpVtbl->Release(pPersistFile);
    }
    pShellLink->lpVtbl->Release(pShellLink);
    v6 = _wcsdup(v4);
  }
  else
  {
    v6 = _wcsdup(&gszNullString);
  }
  *v3 = v6;
  free(pszArgs);
  free(v4);
  return v3;
}
// 10A7B5C: using guessed type GUID CLSID_IPersistFile;

//----- (00FD52B0) --------------------------------------------------------
int __cdecl PE_GetLongPathName(CPEString *str, wchar_t *pszKeyName)
{
  HMODULE v2; // eax
  int (__stdcall *v3)(LPCWSTR, LPWSTR, DWORD); // eax
  const wchar_t *v4; // ecx
  Data_t_bstr_t *strKeyName2_bstrText1; // edi
  const WCHAR *v7; // eax
  CPEString strKeyName; // esi
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
  CPEString v19; // [esp+14h] [ebp-18h]
  int KeyNameNew; // [esp+18h] [ebp-14h]
  tagKeyName KeyName2; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+28h] [ebp-4h]

  if ( dword_10C4C40 & 1 )
  {
    v3 = GetLongPathNameW_0;
  }
  else
  {
    dword_10C4C40 |= 1u;
    v2 = LoadLibraryW(L"kernel32.dll");
    v3 = GetProcAddress(v2, "GetLongPathNameW");
    GetLongPathNameW_0 = v3;
  }
  if ( !v3 )
  {
    v4 = &gszNullString;
    if ( pszKeyName )
      v4 = pszKeyName;
    str->m_String = _wcsdup(v4);
    return str;
  }
  sub_FD7AB0(&gKeyNameMap, &KeyName2, pszKeyName);
  v22 = 0;
  if ( !gbFlagsInPE_GetLongPathName )
  {
    strKeyName2_bstrText1 = KeyName2.bstrText1.m_Data;
    if ( KeyName2.bstrText1.m_Data )
      v7 = KeyName2.bstrText1.m_Data->m_wstr;
    else
      v7 = 0;
    KeyNameNew = GetLongPathNameW_0(v7, 0, 0);
    strKeyName.m_String = malloc(2u);
    *strKeyName.m_String = 0;
    LOBYTE(v22) = 1;
    if ( !gbFlagsInPE_GetLongPathName )
    {
      strKeyName.m_String = realloc(strKeyName.m_String, 2 * KeyNameNew + 2);
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
            v14 = *sub_FD5DE0(&gKeyNameMap, &KeyNameNew, strKeyName.m_String);
            if ( v14 )
              v15 = *v14;
            else
              v15 = 0;
            CPEString::Reset(&v19, v15);
            _bstr_t::_Free(&KeyNameNew);
            strKeyName.m_String = v19.m_String;
          }
          v16 = _wcsdup(strKeyName.m_String);
        }
        else
        {
          v17 = &gszNullString;
          if ( pszKeyName )
            v17 = pszKeyName;
          v16 = _wcsdup(v17);
        }
        str->m_String = v16;
        free(strKeyName.m_String);
        _bstr_t::_Free(&KeyName2.bstrText1);
        return str;
      }
    }
    free(strKeyName.m_String);
  }
  v18 = &gszNullString;
  if ( pszKeyName )
    v18 = pszKeyName;
  str->m_String = _wcsdup(v18);
  _bstr_t::_Free(&KeyName2.bstrText1);
  return str;
}
// 10C3860: using guessed type char gbFlagsInPE_GetLongPathName;
// 10C4C40: using guessed type int dword_10C4C40;

//----- (00FD5520) --------------------------------------------------------
int __cdecl sub_FD5520(int a1, wchar_t *psz, int a3)
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
  if ( !sub_FD6090(v4) || (v5 = 1, v14 = 1, ((*(a3 + 8) - *(a3 + 4)) >> 2) <= 1) )
  {
LABEL_9:
    *a1 = _wcsdup(&gszNullString);
    free(v3);
    free(psz);
    return a1;
  }
  while ( 1 )
  {
    v13 = 4 * v5;
    v6 = *(4 * v5 + *(a3 + 4));
    if ( *v6 == 47 || *v6 == 45 )
      goto LABEL_8;
    v7 = _wcsdup(L"CMD");
    v8 = _wcsdup(v3);
    if ( !sub_FD5FD0(v8, v7) || _wcsicmp(*(v13 + *(a3 + 4)), L"start") )
      break;
    v5 = v14;
LABEL_8:
    v14 = ++v5;
    if ( v5 >= (*(a3 + 8) - *(a3 + 4)) >> 2 )
      goto LABEL_9;
  }
  v10 = _wcsdup(*(*(a3 + 4) + 4 * v14));
  v11 = v10;
  if ( *v10 != 34 )
  {
    v12 = wcschr(v10, 0x2Cu);
    if ( v12 )
      *v12 = 0;
  }
  *a1 = _wcsdup(v11);
  free(v11);
  free(v3);
  free(psz);
  return a1;
}

//----- (00FD56C0) --------------------------------------------------------
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
    (v1)(gszWindowsDirectory, 260);
  else
    GetWindowsDirectoryW(gszWindowsDirectory, 0x104u);
  v2 = 0;
  do
  {
    v3 = gszWindowsDirectory[v2];
    ++v2;
    *(&Wow64EnableWow64FsRedirection + v2 * 2 + 2) = v3;
  }
  while ( v3 );
  v4 = &gSystemDirInfo - 2;
  do
  {
    v5 = *(v4 + 1);
    v4 += 2;
  }
  while ( v5 );
  *v4 = *L"\\System32";
  *(v4 + 1) = *L"ystem32";
  *(v4 + 2) = *L"tem32";
  *(v4 + 3) = *L"m32";
  *(v4 + 4) = *L"2";
  v6 = LoadLibraryW(L"Kernel32.dll");
  GetSystemWow64DirectoryW = GetProcAddress(v6, "GetSystemWow64DirectoryW");
  if ( GetSystemWow64DirectoryW && !(GetSystemWow64DirectoryW)(gSystemDirInfo.szSystemWow64Directory, 260) )
  {
    index = 0;
    do
    {
      chText = gSystemDirInfo.szBuffer[index];
      ++index;
      *(&gSystemDirInfo.Lock.SpinCount + index * 2 + 2) = chText;
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
    result = SetEnvironmentVariableW(L"PROGRAMFILES(X86)", gszProgramW6432EnvValue);
  }
  return result;
}
// 108CEA8: using guessed type wchar_t aSystem32[10];

//----- (00FD5860) --------------------------------------------------------
char __cdecl sub_FD5860(wchar_t **a1, __int16 a2, const wchar_t **a3, char a4)
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
  const wchar_t **v24; // eax
  wchar_t *v25; // ebx
  DWORD v26; // eax
  CPEString *v27; // eax
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
  if ( v8 && v8 != a2 )
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
      v32 = *a3;
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
        v16 = *a3;
        *a3 = _wcsdup(v35);
        free(v16);
        (*a3)[v10 - v15] = 0;
        v17 = _wcsdup(*a3);
        v36 = 0;
        _wcsupr(v17);
        if ( TlsGetValue(gdwTlsIndex) == 256 && wcsstr(v17, L"%PROGRAMFILES%") )
        {
          v18 = wcsstr(v17, L"%PROGRAMFILES%");
          v19 = *a3;
          v20 = v18 - v17;
          _mm_storeu_si128(&(*a3)[v20], _mm_loadu_si128(L"%ProgramW6432%"));
          _mm_storel_epi64(&v19[v20 + 8], _mm_loadl_epi64(L"W6432%"));
          *&v19[v20 + 12] = *L"2%";
          v21 = &(*a3)[v20 + 14];
          v22 = *a3 - *a3;
          do
          {
            v23 = *v21;
            ++v21;
            *(v21 + v22 - 2) = v23;
          }
          while ( v23 );
        }
        v24 = RequerySystemEnvironmentString(&ppstr, *a3);
        v25 = *a3;
        *a3 = _wcsdup(*v24);
        free(v25);
        free(ppstr);
        v26 = sub_FE1040(*a3);
        if ( v26 != -1 && !(v26 & 0x10)
          || (v27 = CPEString::Append(&ppv, a3, L".exe"),
              v28 = *a3,
              *a3 = _wcsdup(v27->m_String),
              free(v28),
              free(ppv),
              v29 = sub_FE1040(*a3),
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

//----- (00FD5BB0) --------------------------------------------------------
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
  Wow64EnableWow64FsRedirection = GetProcAddress(v0, "Wow64EnableWow64FsRedirection");
  v1 = LoadLibraryW(L"Kernel32.dll");
  Wow64DisableWow64FsRedirection = GetProcAddress(v1, "Wow64DisableWow64FsRedirection");
  v2 = LoadLibraryW(L"Kernel32.dll");
  Wow64RevertWow64FsRedirection = GetProcAddress(v2, "Wow64RevertWow64FsRedirection");
  v3 = LoadLibraryW(L"advapi32.dll");
  *RegDeleteKeyExW = GetProcAddress(v3, "RegDeleteKeyExW");
  v4 = LoadLibraryW(L"ntdll.dll");
  NtDeleteKey = GetProcAddress(v4, "NtDeleteKey");
  v5 = LoadLibraryW(L"ntdll.dll");
  NtOpenKey = GetProcAddress(v5, "NtOpenKey");
  v6 = LoadLibraryW(L"ntdll.dll");
  NtCreateKey = GetProcAddress(v6, "NtCreateKey");
  v7 = LoadLibraryW(L"ntdll.dll");
  result = GetProcAddress(v7, "RtlNtStatusToDosError");
  RtlNtStatusToDosError = result;
  return result;
}

//----- (00FD5C70) --------------------------------------------------------
WCHAR **__cdecl PE_GetSystemPathInfo(WCHAR **a1, wchar_t *lpszText)
{
  wchar_t *v2; // eax
  wchar_t *v3; // esi
  unsigned int v4; // kr04_4
  wchar_t *v5; // esi
  CPEString *v6; // eax
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
    hKey.unused = v3;
    operator+(&s1, gszProgramW6432EnvValue, &hKey);
    LOBYTE(v14) = 2;
    free(v3);
    Wow64DisableWow64FsRedirection(&ImageBase);
    if ( !ImageBase && !_wcsnicmp(lpszText, &gSystemDirInfo, wcslen(&gSystemDirInfo)) )
    {
      v4 = wcslen(&gSystemDirInfo);
      v5 = _wcsdup(gSystemDirInfo.szSystemWow64Directory);
      hKey.unused = v5;
      v6 = CPEString::Append(&ppv, &hKey, &lpszText[v4]);
      v7 = *a1;
      *a1 = _wcsdup(v6->m_String);
      free(v7);
      free(ppv);
      free(v5);
    }
    Wow64RevertWow64FsRedirection(ImageBase);
    free(s1);
    v2 = lpszText;
  }
  free(v2);
  return a1;
}

//----- (00FD5DE0) --------------------------------------------------------
int __thiscall sub_FD5DE0(std__tree *this, int a2, OLECHAR *psz)
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
  if ( this->_Mypair._Myval2._Myhead->_Left == this->_Mypair._Myval2._Myhead )
  {
LABEL_23:
    v14 = operator new(0xCu);
    v15 = v14;
    psz = v14;
    if ( v14 )
    {
      v14[1] = 0;
      v14[2] = 1;
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
    *a2 = v15;
    if ( !v15 )
      _com_issue_error(0x8007000E);
    return result;
  }
  while ( 1 )
  {
    if ( v4->_Myval.second.bstrText2.m_Data )
      goto LABEL_13;
    v5 = v4->_Myval.second.dwValue;
    if ( !v5 )
      break;
    v6 = *v5;
    if ( !v6 )
      break;
    v7 = SysStringLen(v6);
    if ( !v7 )
      goto LABEL_28;
    v8 = v4->_Myval.second.dwValue;
    v9 = (v8 ? *v8 : 0);
    if ( !_wcsnicmp(v3, v9, v7) )
    {
      v10 = v3[v7];
      if ( !v10 || v10 == 92 )
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
    if ( v4 == this->_Mypair._Myval2._Myhead )
      goto LABEL_23;
  }
  v7 = 0;
LABEL_28:
  tagKeyName::Update(&psz, v3, v7, &v4->_Myval.second.bstrText1);
  v17 = psz;
  *a2 = psz;
  if ( v17 )
  {
    InterlockedIncrement(v17 + 2);
    v18 = psz;
    if ( psz )
    {
      if ( !InterlockedDecrement(psz + 2) && v18 )
      {
        if ( *v18 )
        {
          SysFreeString(*v18);
          *v18 = 0;
        }
        if ( *(v18 + 1) )
        {
          j_j__free(*(v18 + 1));
          *(v18 + 1) = 0;
        }
        j__free(v18);
      }
    }
  }
  return a2;
}

//----- (00FD5FD0) --------------------------------------------------------
char __cdecl sub_FD5FD0(wchar_t *a1, wchar_t *a2)
{
  wchar_t *v2; // esi
  wchar_t *v3; // edi
  wchar_t *v4; // eax
  wchar_t *v5; // eax
  int v6; // ecx
  int v7; // ecx
  char v8; // bl

  if ( !wcsstr(a1, a2) )
  {
    v5 = a1;
LABEL_16:
    v8 = 0;
    goto LABEL_17;
  }
  v2 = a1;
  v3 = a2;
  do
  {
    v4 = wcsstr(v2, a2);
    if ( !v4 )
      break;
    v3 = v4;
    v2 = v4 + 1;
    if ( v4 == -2 )
      break;
  }
  while ( wcsstr(v2, a2) );
  v5 = a1;
  if ( v3 != a1 )
  {
    v6 = *(v3 - 1);
    if ( v6 != 92 && v6 != 34 && v6 != 32 )
      goto LABEL_16;
  }
  v7 = v3[wcslen(a2)];
  if ( v7 )
  {
    if ( v7 != 34 && v7 != 32 && v7 != 46 )
      goto LABEL_16;
  }
  v8 = 1;
LABEL_17:
  free(v5);
  free(a2);
  return v8;
}

//----- (00FD6090) --------------------------------------------------------
char __cdecl sub_FD6090(wchar_t *psz)
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
  if ( !sub_FD5FD0(v2, v1) )
  {
    v3 = _wcsdup(L"RUNDLL");
    v4 = _wcsdup(psz);
    if ( !sub_FD5FD0(v4, v3) )
    {
      v5 = _wcsdup(L"CSCRIPT");
      v6 = _wcsdup(psz);
      if ( !sub_FD5FD0(v6, v5) )
      {
        v7 = _wcsdup(L"WSCRIPT");
        v8 = _wcsdup(psz);
        if ( !sub_FD5FD0(v8, v7) )
        {
          v9 = _wcsdup(L"REGSVR32");
          v10 = _wcsdup(psz);
          if ( !sub_FD5FD0(v10, v9) )
          {
            v11 = _wcsdup(L"POWERSHELL");
            v12 = _wcsdup(psz);
            if ( !sub_FD5FD0(v12, v11) )
            {
              v13 = _wcsdup(L"CMD");
              v14 = _wcsdup(psz);
              if ( !sub_FD5FD0(v14, v13) )
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
  v17 = malloc(2u);
  v33 = v17;
  *v17 = 0;
  v18 = malloc(2u);
  v19 = v18;
  *v18 = 0;
  LOBYTE(v36) = 3;
  v20 = &gszNullString;
  v31 = 20;
  if ( psz )
    v20 = psz;
  v21 = _wcsdup(v20);
  v22 = sub_FF1290(v21, &v33);
  if ( v22 == 2 )
  {
    v34 = sub_FD6700(psz, 0, 0, &v35, &v31, 0);
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
      v24 = &gszNullString;
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
    v22 = sub_FF11B0(v28, v27, v26);
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

//----- (00FD63B0) --------------------------------------------------------
char __cdecl sub_FD63B0(wchar_t *a1)
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

//----- (00FD6440) --------------------------------------------------------
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
  if ( this->_Mypair._Myval2._Myhead->_Left == this->_Mypair._Myval2._Myhead )
  {
LABEL_23:
    KeyName->bstrText1.m_Data = hRootKey;
    v16 = operator new(0xCu);
    v17 = v16;
    KeyName = v16;
    if ( v16 )
    {
      v16->bstrText2.m_Data = 0;
      v16->dwValue = 1;
      v18 = SysAllocString(lpszKeyID);
      v17->bstrText1.m_Data = v18;
      if ( !v18 && lpszKeyID )
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
      v17 = 0;
    }
    result = bstrKeyId.m_Data;
    bstrKeyId.m_Data->m_wstr = v17;
    if ( !v17 )
      _com_issue_error(E_OUTOFMEMORY);
    return result;
  }
  while ( 1 )
  {
    if ( pNode->_Myval.first != hRootKey )
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
      if ( !v12 || v12 == '\\' )
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
    if ( pNode == this->_Mypair._Myval2._Myhead )
      goto LABEL_23;
  }
  nLength = 0;
__found:
  KeyName->bstrText1.m_Data = pNode->_Myval.second.bstrText2.m_Data;
  tagKeyName::Update(&KeyName, lpszKeyID, nLength, &pNode->_Myval.second.dwValue);
  v19 = KeyName;
  bstrKeyId.m_Data->m_wstr = KeyName;
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
          SysFreeString(v20->bstrText1.m_Data);
          v20->bstrText1.m_Data = 0;
        }
        if ( v20->bstrText2.m_Data )
        {
          j_j__free(v20->bstrText2.m_Data);
          v20->bstrText2.m_Data = 0;
        }
        j__free(v20);
      }
    }
  }
  return bstrKeyId.m_Data;
}

//----- (00FD6640) --------------------------------------------------------
HANDLE __stdcall PE_OpenFile(OLECHAR *lpszKeyName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
  tagKeyName *KeyName; // esi
  tagKeyName *pszFileName; // ebx
  HANDLE v9; // edi

  sub_FD7AB0(&gKeyNameMap, &lpszKeyName, lpszKeyName);
  KeyName = lpszKeyName;
  if ( lpszKeyName )
    pszFileName = *lpszKeyName;
  else
    pszFileName = 0;
  v9 = CreateFileW(
         pszFileName,
         dwDesiredAccess,
         dwShareMode,
         lpSecurityAttributes,
         dwCreationDisposition,
         dwFlagsAndAttributes,
         hTemplateFile);
  if ( v9 == -1 )
  {
    ImpersonateLoggedOnUser(ghAppToken);
    v9 = CreateFileW(
           pszFileName,
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
      SysFreeString(KeyName->bstrText1.m_Data);
      KeyName->bstrText1.m_Data = 0;
    }
    if ( KeyName->bstrText2.m_Data )
    {
      j_j__free(KeyName->bstrText2.m_Data);
      KeyName->bstrText2.m_Data = 0;
    }
    j__free(KeyName);
  }
  return v9;
}

//----- (00FD6700) --------------------------------------------------------
#error "FD6700: local variable allocation failed (funcsize=61)"

//----- (00FD67A0) --------------------------------------------------------
int __cdecl PE_OpenKey(HKEY bstrSlash, LPCWSTR lpszKeyName, LONG CreateOptions, DWORD DesiredAccess, PHKEY KeyHandle)
{
  Data_t_bstr_t *bstrKeyName_1; // esi
  HKEY RootDirectory; // ebx
  Data_t_bstr_t *v7; // edi
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
    &lpszKeyName,
    &bstrSlash,

    bstrSlash,
    lpszKeyName);
  RootDirectory = bstrSlash;
  v7 = lpszKeyName;
  LOBYTE(nStep) = 1;
  if ( bstrSlash != HKEY_LOCAL_MACHINE )
  {
    if ( bstrSlash == HKEY_CURRENT_USER )
    {
      // \\Registry\\Users\\#szUserName#\\lpszKeyName
      _bstr_t::_bstr_t(&bstrSlash, L"\\");
      LOBYTE(nStep) = 2;
      v10 = _bstr_t::_bstr_t(&StringItem, gpAccountInfo->szUserName);
      LOBYTE(nStep) = 3;
      v11 = _bstr_t::operator+(&StringItem.strValue[1], L"\\Registry\\User\\", v10);
      LOBYTE(nStep) = 4;
      v12 = _bstr_t::operator+(v11, &StringItem.strValue[2], &bstrSlash);
      LOBYTE(nStep) = 5;
      v13 = _bstr_t::operator+(v12, &StringItem.strValue[3], &lpszKeyName);
      if ( &StringItem.strValue[4] != v13 )
      {
        _bstr_t::_Free(&StringItem.strValue[4]);
        bstrKeyName_1 = v13->m_Data;
        StringItem.strValue[4] = bstrKeyName_1;
        if ( bstrKeyName_1 )
          InterlockedIncrement(&bstrKeyName_1->m_RefCount);
      }
      _bstr_t::_Free(&StringItem.strValue[3]);
      _bstr_t::_Free(&StringItem.strValue[2]);
      _bstr_t::_Free(&StringItem.strValue[1]);
      _bstr_t::_Free(&StringItem);
      LOBYTE(nStep) = 1;
      _bstr_t::_Free(&bstrSlash);
      RootDirectory = 0;
      if ( bstrKeyName_1 )
      {
        pszObjectName = bstrKeyName_1->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( bstrSlash == HKEY_CLASSES_ROOT )
    {
      v14 = _bstr_t::operator+(&bstrSlash, L"\\Registry\\Machine\\Software\\Classes\\", &lpszKeyName);
      if ( &StringItem.strValue[4] != v14 )
      {
        _bstr_t::_Free(&StringItem.strValue[4]);
        bstrKeyName_1 = v14->m_Data;
        StringItem.strValue[4] = bstrKeyName_1;
        if ( bstrKeyName_1 )
          InterlockedIncrement(&bstrKeyName_1->m_RefCount);
      }
      _bstr_t::_Free(&bstrSlash);
      RootDirectory = 0;
      if ( bstrKeyName_1 )
      {
        pszObjectName = bstrKeyName_1->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( bstrSlash == HKEY_USERS )
    {
      v15 = _bstr_t::operator+(&bstrSlash, L"\\Registry\\User\\", &lpszKeyName);
      if ( &StringItem.strValue[4] != v15 )
      {
        _bstr_t::_Free(&StringItem.strValue[4]);
        bstrKeyName_1 = v15->m_Data;
        StringItem.strValue[4] = bstrKeyName_1;
        if ( bstrKeyName_1 )
          InterlockedIncrement(&bstrKeyName_1->m_RefCount);
      }
      _bstr_t::_Free(&bstrSlash);
      RootDirectory = 0;
      if ( bstrKeyName_1 )
      {
        pszObjectName = bstrKeyName_1->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( lpszKeyName )
    {
      pszObjectName = *lpszKeyName;
      goto LABEL_28;
    }
LABEL_27:
    pszObjectName = 0;
    goto LABEL_28;
  }
  v8 = _bstr_t::operator+(&bstrSlash, L"\\Registry\\Machine\\", &lpszKeyName);
  if ( &StringItem.strValue[4] != v8 )
  {
    _bstr_t::_Free(&StringItem.strValue[4]);
    bstrKeyName_1 = v8->m_Data;
    StringItem.strValue[4] = bstrKeyName_1;
    if ( bstrKeyName_1 )
      InterlockedIncrement(&bstrKeyName_1->m_RefCount);
  }
  _bstr_t::_Free(&bstrSlash);
  RootDirectory = 0;
  if ( !bstrKeyName_1 )
    goto LABEL_27;
  pszObjectName = bstrKeyName_1->m_wstr;
LABEL_28:
  v16 = pszObjectName;
  bstrSlash = (pszObjectName + 1);
  do
  {
    v17 = *v16;
    v16 += 2;
  }
  while ( v17 );
  nLength = (v16 - bstrSlash) >> 1;
  strObjectName.Buffer = pszObjectName;
  ObjectAttributes.Length = 24;
  ObjectAttributes.RootDirectory = RootDirectory;
  ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
  strObjectName.MaximumLength = 2 * nLength;
  strObjectName.Length = 2 * nLength;
  ObjectAttributes.ObjectName = &strObjectName;
  ObjectAttributes.SecurityDescriptor = 0;
  ObjectAttributes.SecurityQualityOfService = 0;
  v19 = NtOpenKey(KeyHandle, DesiredAccess, &ObjectAttributes);
  dwError = RtlNtStatusToDosError(v19);
  if ( dwError == ERROR_ACCESS_DENIED )
  {
    Status = NtCreateKey(
               KeyHandle,
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
        v22 = NtOpenKey(KeyHandle, DesiredAccess, &ObjectAttributes);
        dwError = RtlNtStatusToDosError(v22);
        RevertToSelf();
      }
    }
  }
  v23 = InterlockedDecrement;
  if ( v7 )
  {
    if ( !InterlockedDecrement(&v7->m_RefCount) )
    {
      if ( v7->m_wstr )
      {
        SysFreeString(v7->m_wstr);
        v7->m_wstr = 0;
      }
      if ( v7->m_str )
      {
        j_j__free(v7->m_str);
        v7->m_str = 0;
      }
      j__free(v7);
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
      j_j__free(bstrKeyName_1->m_str);
      bstrKeyName_1->m_str = 0;
    }
    j__free(bstrKeyName_1);
  }
  return dwError;
}

//----- (00FD6B30) --------------------------------------------------------
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

  result = TmAdjustPrivilege(L"SeDebugPrivilege");
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
            || (pstr = wcsrchr(ProcessEntry.szExeFile, '\\'), szExeFile = pstr + 1, pstr != 0xFFFFFFFE) )
          {
            if ( !_wcsicmp(szExeFile, L"winlogon.exe") )
              break;
          }
          if ( !Process32NextW(hFound, &ProcessEntry) )
            return CloseHandle(hFound);
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
      result = CloseHandle(hFound);
    }
  }
  return result;
}

//----- (00FD6CC0) --------------------------------------------------------
char __cdecl sub_FD6CC0(WCHAR *pszText1, WCHAR *pszText2)
{
  const wchar_t ***v2; // ebx
  void *v3; // esi
  WCHAR *v4; // ecx
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
  sub_FD6DD0(pszText1, 0, &v8, 0);
  v2 = v8;
  v3 = *pszText2;
  if ( (a2a - v8) & 0xFFFFFFF0 )
  {
    *pszText2 = _wcsdup(*v8);
    free(v3);
    sub_FD38F0(pszText2 + 1, v2 + 1);
    result = 1;
  }
  else
  {
    *pszText2 = _wcsdup(&gszNullString);
    free(v3);
    v4 = pszText2;
    v5 = *(pszText2 + 2);
    v6 = *(pszText2 + 1);
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
    *(v4 + 2) = *(v4 + 1);
    result = 0;
  }
  v11 = result;
  if ( v2 )
  {
    sub_FD2BF0(v2, a2a);
    j__free(v2);
    result = v11;
  }
  return result;
}

//----- (00FD6DD0) --------------------------------------------------------
void __cdecl sub_FD6DD0(wchar_t *a1, int a2, int a3, int a4)
{
  unsigned int v4; // esi
  wchar_t **v5; // ebx
  __int16 v6; // di
  wchar_t *v7; // eax
  char v8; // al
  wchar_t *v9; // edi
  char v10; // al
  void *v11; // esi
  wchar_t *v12; // edi
  int v13; // edi
  wchar_t *v14; // eax
  wchar_t *v15; // esi
  int v16; // ecx
  void *v17; // esi
  wchar_t *v18; // edi
  void **i; // esi
  tagPEStringStruct v20; // [esp+10h] [ebp-34h]
  wchar_t *v21; // [esp+2Ch] [ebp-18h]
  wchar_t *v22; // [esp+30h] [ebp-14h]
  char v23; // [esp+37h] [ebp-Dh]
  int v24; // [esp+40h] [ebp-4h]

  sub_FD2BF0(*a3, *(a3 + 4));
  *(a3 + 4) = *a3;
  v21 = a1;
  v20.strValue[0] = malloc(2u);
  v4 = 0;
  v20.strValue[3] = 0;
  v20.strValue[1] = 0;
  v5 = 0;
  *v20.strValue[0] = 0;
  v20.strValue[2] = 0;
  v6 = a4;
  v24 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = malloc(2u);
      v22 = v7;
      *v7 = 0;
      LOBYTE(v24) = 1;
      LOBYTE(v20.strValue[6]) = ((v5 - v4) & 0xFFFFFFFC) == 0;
      v8 = sub_FD5860(&v21, a2, &v22, v20.strValue[6]);
      v23 = v8;
      if ( v6 )
      {
        v20.strValue[5] = malloc(2u);
        *v20.strValue[5] = 0;
        v9 = v21;
        LOBYTE(v24) = 2;
        v20.strValue[4] = v21;
        v10 = sub_FD5860(&v20.strValue[4], a4, &v20.strValue[5], v20.strValue[6]);
        v11 = v20.strValue[5];
        if ( v10 )
        {
          if ( v23 )
          {
            if ( v20.strValue[4] < v9 )
            {
              v21 = v20.strValue[4];
              v12 = v22;
              v22 = _wcsdup(v20.strValue[5]);
              free(v12);
            }
          }
          else
          {
            v23 = 1;
          }
        }
        LOBYTE(v24) = 1;
        free(v11);
        v4 = v20.strValue[1];
        v8 = v23;
      }
      if ( !v8 )
      {
        v15 = v21;
        break;
      }
      if ( &v22 >= v5 || v4 > &v22 )
      {
        if ( v5 == v20.strValue[3] )
        {
          std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(&v20.strValue[1], 1u);
          v5 = v20.strValue[2];
        }
        if ( v5 )
        {
          v14 = _wcsdup(v22);
          goto LABEL_20;
        }
      }
      else
      {
        v13 = (&v22 - v4) >> 2;
        if ( v5 == v20.strValue[3] )
        {
          std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(&v20.strValue[1], 1u);
          v5 = v20.strValue[2];
          v4 = v20.strValue[1];
        }
        if ( v5 )
        {
          v14 = _wcsdup(*(v4 + 4 * v13));
LABEL_20:
          *v5 = v14;
          goto LABEL_21;
        }
      }
LABEL_21:
      v15 = v21;
      ++v5;
      v20.strValue[2] = v5;
      if ( *v21 == a2 )
        break;
      v6 = a4;
      if ( *v21 == a4 )
        break;
      v4 = v20.strValue[1];
      free(v22);
    }
    v16 = v20.strValue[1];
    if ( (v5 - v20.strValue[1]) & 0xFFFFFFFC )
    {
      v17 = v20.strValue[0];
      v18 = _wcsdup(a1);
      v20.strValue[0] = v18;
      free(v17);
      v15 = v21;
      v18[v21 - a1] = 0;
      sub_FE0460(a3, &v20);
      v5 = v20.strValue[2];
      v16 = v20.strValue[1];
    }
    if ( !*v15 )
      break;
    v21 = v15 + 1;
    for ( i = v16; i != v5; ++i )
      free(*i);
    v4 = v20.strValue[1];
    v5 = v20.strValue[1];
    a1 = v21;
    v6 = a4;
    v20.strValue[2] = v20.strValue[1];
    free(v22);
  }
  free(v22);
  sub_FD21F0(&v20);
}

//----- (00FD7040) --------------------------------------------------------
void __cdecl sub_FD7040(wchar_t *a1, int a2)
{
  void **v2; // edi
  void **i; // esi
  void *v4; // esi
  wchar_t *a2a; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v2 = *(a2 + 8);
  for ( i = *(a2 + 4); i != v2; ++i )
    free(*i);
  *(a2 + 8) = *(a2 + 4);
  sub_FDF8D0(&a2a, a1);
  v6 = 0;
  v4 = *a2;
  *a2 = _wcsdup(a1);
  free(v4);
  sub_FE0530((a2 + 4), &a2a);
  free(a2a);
}

//----- (00FD70E0) --------------------------------------------------------
wchar_t **__cdecl sub_FD70E0(wchar_t **a1, int a2, tagPEStringStruct *a3, void *a4)
{
  int v4; // ecx
  WCHAR **v6; // edi
  _WORD *v7; // esi
  wchar_t *v8; // ebx
  WCHAR *v9; // edi
  wchar_t *v10; // eax
  wchar_t *v11; // ebx
  wchar_t *v12; // edi
  int v13; // ecx
  wchar_t *v14; // ecx
  wchar_t v15; // ax
  const wchar_t **v16; // eax
  WCHAR *v17; // edx
  unsigned int v18; // eax
  OLECHAR *v19; // esi
  LSTATUS v20; // eax
  wchar_t *v21; // eax
  wchar_t *v22; // ecx
  WCHAR *pszFullPathName; // esi
  DWORD v24; // eax
  WCHAR *v25; // eax
  const wchar_t *v26; // eax
  CPEString *v27; // eax
  wchar_t *v28; // eax
  const wchar_t **v29; // eax
  const wchar_t **v30; // eax
  const wchar_t *v31; // eax
  LPCWSTR i; // ecx
  WCHAR *v33; // edi
  WCHAR *v34; // edi
  wchar_t *v35; // eax
  WCHAR *v36; // ecx
  WCHAR v37; // ax
  wchar_t *v38; // eax
  const wchar_t **v39; // eax
  wchar_t *v40; // esi
  const wchar_t **v41; // eax
  void *v42; // esi
  wchar_t *v43; // eax
  void *v44; // ST24_4
  wchar_t *v45; // eax
  void *v46; // ST24_4
  WCHAR **v47; // [esp-8h] [ebp-8Ch]
  wchar_t *v48; // [esp-4h] [ebp-88h]
  int v49; // [esp+10h] [ebp-74h]
  tagPEStringStruct a3a; // [esp+14h] [ebp-70h]
  wchar_t *a2a; // [esp+30h] [ebp-54h]
  HKEY hKey; // [esp+34h] [ebp-50h]
  int a1a; // [esp+38h] [ebp-4Ch]
  void *v54; // [esp+3Ch] [ebp-48h]
  void *v55; // [esp+40h] [ebp-44h]
  WCHAR *lpszText; // [esp+44h] [ebp-40h]
  WCHAR *pszResult; // [esp+48h] [ebp-3Ch]
  CPEString v58; // [esp+4Ch] [ebp-38h]
  int v59; // [esp+50h] [ebp-34h]
  WCHAR **v60; // [esp+54h] [ebp-30h]
  wchar_t **v61; // [esp+58h] [ebp-2Ch]
  OLECHAR *psz; // [esp+5Ch] [ebp-28h]
  wchar_t *ppv; // [esp+60h] [ebp-24h]
  DWORD nBufferLength; // [esp+64h] [ebp-20h]
  LPCWSTR lpFileName; // [esp+68h] [ebp-1Ch]
  size_t v66; // [esp+6Ch] [ebp-18h]
  int v67; // [esp+80h] [ebp-4h]

  a1a = a2;
  v4 = a3->strValue[2] - a3->strValue[1];
  v61 = a1;
  v59 = a3;
  pszResult = a4;
  LOBYTE(a3a.strValue[6]) = a4;
  v49 = 0;
  if ( !(v4 & 0xFFFFFFFC) )
  {
    *a1 = _wcsdup(L"<bad command>");
    return a1;
  }
  v54 = _wcsdup(*a3->strValue[1]);
  v67 = 0;
  lpFileName = malloc(2u);
  *lpFileName = 0;
  v6 = malloc(2u);
  v60 = v6;
  *v6 = 0;
  v7 = malloc(2u);
  v55 = v7;
  *v7 = 0;
  v8 = _wcsdup(*a3->strValue[1]);
  lpszText = v8;
  a2a = v8;
  ppv = _wcsdup(v8);
  _wcsupr(ppv);
  if ( !wcsncmp(ppv, L"\\??\\", 4u) )
  {
    v48 = v8 + 4;
LABEL_8:
    v10 = _wcsdup(v48);
    v47 = v6;
    goto LABEL_9;
  }
  if ( wcsncmp(ppv, L"\\SYSTEMROOT\\", 0xCu) )
  {
    v48 = v8;
    goto LABEL_8;
  }
  v9 = lpFileName;
  lpFileName = _wcsdup(gszWindowsDirectory);
  free(v9);
  CPEString::InsertAt(&lpFileName, L"\\", 0x7FFFFFFFu, 0);
  CPEString::InsertAt(&lpFileName, v8 + 12, 0x7FFFFFFFu, 0);
  v10 = _wcsdup(lpFileName);
  v47 = v60;
LABEL_9:
  v11 = v10;
  a3a.strValue[5] = v10;
  free(v47);
  v12 = _wcsdup(v11);
  a3a.strValue[4] = v12;
  LOBYTE(v67) = 6;
  _wcsupr(v12);
  if ( TlsGetValue(gdwTlsIndex) == 256 && wcsstr(v12, L"%PROGRAMFILES%") )
  {
    v13 = wcsstr(v12, L"%PROGRAMFILES%") - v12;
    _mm_storeu_si128(&v11[v13], _mm_loadu_si128(L"%ProgramW6432%"));
    _mm_storel_epi64(&v11[v13 + 8], _mm_loadl_epi64(L"W6432%"));
    *&v11[v13 + 12] = *L"2%";
    v14 = &v11[v13 + 14];
    do
    {
      v15 = *v14;
      ++v14;
      *(v14 - 1) = v15;
    }
    while ( v15 );
  }
  v16 = RequerySystemEnvironmentString(&psz, v11);
  v60 = lpFileName;
  lpFileName = _wcsdup(*v16);
  free(v60);
  free(psz);
  v17 = malloc(2u);
  v66 = v17;
  v58.m_String = v17;
  *v17 = 0;
  LOBYTE(v67) = 7;
  if ( !*lpFileName )
    goto LABEL_64;
  psz = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\");
  LOBYTE(v67) = 8;
  CPEString::InsertAt(&psz, lpszText, 0x7FFFFFFFu, 0);
  v18 = TlsGetValue(gdwTlsIndex);
  v19 = psz;
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, v18 | 0x20019, &hKey) )
  {
    v20 = PE_LoadStrKey(hKey, 0, &lpFileName);
    v48 = hKey;
    if ( !v20 )
    {
      RegCloseKey(v48);
      v21 = _wcsdup(lpFileName);
      *v61 = v21;
      free(v19);
      free(v66);
      free(v12);
      free(ppv);
      free(lpszText);
      free(v55);
      free(v11);
      free(lpFileName);
      free(v54);
      return v61;
    }
    RegCloseKey(v48);
  }
  v60 = _wcsdup(lpFileName);
  v58.m_String = v60;
  free(v66);
  if ( pszResult || gbFlagsInPE_GetLongPathName )
  {
LABEL_36:
    v26 = lpFileName;
    if ( *lpFileName == '\\' && lpFileName[1] != '\\' )
    {
      wcsncpy_s(&v66, 3u, gszWindowsDirectory, 2u);
      v27 = operator+(&pszResult, &v66, &lpFileName);
      nBufferLength = lpFileName;
      lpFileName = _wcsdup(v27->m_String);
      free(nBufferLength);
      free(pszResult);
      v26 = lpFileName;
    }
    v48 = v22;
    nBufferLength = &v48;
    v28 = _wcsdup(v26);
    *nBufferLength = v28;
    v29 = PE_GetSystemPathInfo(&pszResult, v48);
    nBufferLength = lpFileName;
    lpFileName = _wcsdup(*v29);
    free(nBufferLength);
    free(pszResult);
    v48 = lpFileName;
    if ( gbFlagsInPE_GetLongPathName )
    {
      v66 = _wcsdup(v48);
      v58.m_String = v66;
      free(v60);
    }
    else
    {
      v30 = PE_GetLongPathName(&nBufferLength, v48);
      v66 = _wcsdup(*v30);
      v58.m_String = v66;
      free(v60);
      free(nBufferLength);
    }
    _wcslwr(v66);
    LOBYTE(v67) = 7;
    free(v19);
    v7 = v55;
    v17 = v66;
LABEL_64:
    v36 = v17;
    nBufferLength = (v17 + 1);
    do
    {
      v37 = *v36;
      ++v36;
    }
    while ( v37 );
    if ( (v36 - nBufferLength) >> 1 )
    {
      v48 = v59;
      v38 = _wcsdup(v17);
      v39 = sub_FD5520(&nBufferLength, v38, v48);
      v40 = _wcsdup(*v39);
      a2a = v40;
      free(lpszText);
      free(nBufferLength);
      if ( wcslen(v40) )
      {
        a3a.strValue[0] = malloc(2u);
        *a3a.strValue[0] = 0;
        a3a.strValue[1] = 0;
        a3a.strValue[2] = 0;
        a3a.strValue[3] = 0;
        LOBYTE(v67) = 10;
        sub_FE0530(&a3a.strValue[1], &a2a);
        v41 = sub_FD70E0(&a3a.strValue[6], a1a, &a3a, a3a.strValue[6]);
        v42 = v66;
        v66 = _wcsdup(*v41);
        free(v42);
        free(a3a.strValue[6]);
        sub_FD21F0(&a3a);
        v40 = a2a;
      }
      v43 = _wcsdup(v66);
      v44 = v66;
      *v61 = v43;
      free(v44);
      free(v12);
      free(ppv);
      free(v40);
      free(v55);
    }
    else
    {
      v45 = _wcsdup(&gszNullString);
      v46 = v66;
      *v61 = v45;
      free(v46);
      free(v12);
      free(ppv);
      free(lpszText);
      free(v7);
    }
    free(v11);
    free(lpFileName);
    free(v54);
    return v61;
  }
  while ( 1 )
  {
    pszFullPathName = _wcsdup(lpFileName);
    pszResult = pszFullPathName;
    LOBYTE(v67) = 9;
    if ( wcsstr(lpFileName, L"..") )
    {
      v24 = GetFullPathNameW(lpFileName, 0, 0, 0);
      nBufferLength = v24;
      if ( v24 )
      {
        v66 = 2 * v24 + 2;
        v25 = realloc(pszFullPathName, v66);
        pszFullPathName = v25;
        pszResult = v25;
        if ( v25 )
          memset(v25, 0, v66);
        GetFullPathNameW(lpFileName, nBufferLength, pszFullPathName, 0);
      }
    }
    if ( !gbFlagsInPE_GetLongPathName )
    {
      if ( PE_GetPathName(a1a, gpszSystemPathInfo, pszFullPathName, &ppv) )
      {
        if ( !gbFlagsInPE_GetLongPathName && !(sub_FE1040(ppv) & 0x10) )
        {
          nBufferLength = lpFileName;
          lpFileName = _wcsdup(ppv);
          free(nBufferLength);
          LOBYTE(v67) = 8;
          free(pszFullPathName);
          goto LABEL_35;
        }
      }
      else if ( !wcschr(pszFullPathName, 0x2Fu)
             && wcslen(pszFullPathName) > 3
             && pszFullPathName[wcslen(pszFullPathName) - 4] != 46 )
      {
        nBufferLength = ppv;
        ppv = _wcsdup(pszFullPathName);
        free(nBufferLength);
        CPEString::InsertAt(&ppv, L".exe", 0x7FFFFFFFu, 0);
        if ( gbFlagsInPE_GetLongPathName
          || PE_GetPathName(a1a, gpszSystemPathInfo, ppv, &lpFileName)
          || (nBufferLength = ppv,
              ppv = _wcsdup(pszFullPathName),
              free(nBufferLength),
              CPEString::InsertAt(&ppv, L".dll", 0x7FFFFFFFu, 0),
              !gbFlagsInPE_GetLongPathName)
          && PE_GetPathName(a1a, gpszSystemPathInfo, ppv, &lpFileName) )
        {
          LOBYTE(v67) = 8;
          free(pszFullPathName);
LABEL_35:
          v19 = psz;
          goto LABEL_36;
        }
      }
    }
    v31 = lpFileName;
    for ( i = lpFileName; *i == 32; ++i )
      ;
    if ( !gbFlagsInPE_GetLongPathName )
      break;
LABEL_48:
    if ( wcsrchr(v31, 0x20u) )
      *wcsrchr(lpFileName, 0x20u) = 0;
    LOBYTE(v67) = 8;
    free(pszFullPathName);
    if ( gbFlagsInPE_GetLongPathName )
      goto LABEL_35;
  }
  if ( wcschr(i, 0x20u) )
  {
    v31 = lpFileName;
    goto LABEL_48;
  }
  v33 = lpFileName;
  lpFileName = _wcsdup(L"File not found: ");
  free(v33);
  CPEString::InsertAt(&lpFileName, v60, 0x7FFFFFFFu, 0);
  v34 = _wcsdup(lpFileName);
  v58.m_String = v34;
  free(v60);
  if ( sub_FE1040(**(v59 + 4)) != -1 && sub_FE1040(**(v59 + 4)) & 0x10 )
  {
    CPEString::Reset2(&v58, *(v59 + 4));
    v34 = v58.m_String;
  }
  else if ( !gbFlagsInPE_GetLongPathName && !wcsncmp(**(v59 + 4), L"||", 2u) )
  {
    if ( sub_FE1040((**(v59 + 4) + 4)) == -1 )
    {
      nBufferLength = lpFileName;
      lpFileName = _wcsdup(L"File not found: ");
      free(nBufferLength);
      CPEString::InsertAt(&lpFileName, (**(v59 + 4) + 4), 0x7FFFFFFFu, 0);
      nBufferLength = v34;
      v34 = _wcsdup(lpFileName);
      free(nBufferLength);
    }
    else
    {
      CPEString::Reset(&v58, (**(v59 + 4) + 4));
      v34 = v58.m_String;
    }
  }
  v35 = _wcsdup(v34);
  *v61 = v35;
  free(pszFullPathName);
  free(psz);
  free(v34);
  free(a3a.strValue[4]);
  free(ppv);
  free(lpszText);
  free(v55);
  free(v11);
  free(lpFileName);
  free(v54);
  return v61;
}
// 10C3860: using guessed type char gbFlagsInPE_GetLongPathName;
