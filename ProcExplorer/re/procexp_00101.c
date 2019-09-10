

//----- (00F71000) --------------------------------------------------------
signed int __stdcall sub_F71000(_BYTE *a1, unsigned int a2, int a3)
{
  signed int result; // eax
  _BYTE *v4; // eax
  signed int v5; // ebx
  unsigned int v6; // esi
  char v7; // cl

  result = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    result = -2147024809;
  if ( result >= 0 )
  {
    v4 = a1;
    v5 = 0;
    v6 = a2;
    if ( !a2 )
      goto LABEL_14;
    do
    {
      if ( !(2147483646 - a2 + v6) )
        break;
      v7 = v4[a3 - a1];
      if ( !v7 )
        break;
      *v4++ = v7;
      --v6;
    }
    while ( v6 );
    if ( !v6 )
    {
LABEL_14:
      --v4;
      v5 = -2147024774;
    }
    *v4 = 0;
    result = v5;
  }
  return result;
}

//----- (00F71063) --------------------------------------------------------
BOOL __stdcall sub_F71063(CHAR *a1)
{
  BOOL v1; // esi
  DWORD cbData; // [esp+4h] [ebp-118h]
  DWORD Type; // [esp+8h] [ebp-114h]
  LPSTR lpDst; // [esp+Ch] [ebp-110h]
  HKEY phkResult; // [esp+10h] [ebp-10Ch]
  BYTE Data; // [esp+14h] [ebp-108h]
  char v8; // [esp+117h] [ebp-5h]

  lpDst = a1;
  v1 = 0;
  if ( RegOpenKeyExA(
         HKEY_CLASSES_ROOT,
         "CLSID\\{ADB880A6-D8FF-11CF-9377-00AA003B7A11}\\InprocServer32",
         0,
         0x20019u,
         &phkResult) )
  {
    return 0;
  }
  cbData = 260;
  Type = 1;
  if ( !RegQueryValueExA(phkResult, 0, 0, &Type, &Data, &cbData) )
  {
    v8 = 0;
    if ( Type == 2 )
      v1 = ExpandEnvironmentStringsA(&Data, lpDst, 0x104u) - 1 <= 0x103;
    else
      v1 = sub_F71000(lpDst, 0x104u, &Data) >= 0;
  }
  RegCloseKey(phkResult);
  return v1;
}

//----- (00F71149) --------------------------------------------------------
int __stdcall sub_F71149(int a1, int a2, int a3, int a4)
{
  HMODULE v4; // ecx
  FARPROC v6; // eax
  CHAR LibFileName; // [esp+Ch] [ebp-108h]

  v4 = hModule;
  if ( hModule || dword_10857C0 != hModule )
    goto LABEL_13;
  if ( sub_F71063(&LibFileName) )
    hModule = LoadLibraryA(&LibFileName);
  v4 = hModule;
  if ( hModule || (v4 = LoadLibraryA("hhctrl.ocx"), (hModule = v4) != 0) )
  {
LABEL_13:
    v6 = dword_10857BC;
    if ( dword_10857BC )
      return (v6)(a1, a2, a3, a4);
    v6 = GetProcAddress(v4, 0xF);
    dword_10857BC = v6;
    if ( v6 )
      return (v6)(a1, a2, a3, a4);
  }
  dword_10857C0 = 1;
  return 0;
}
// 10857BC: using guessed type int dword_10857BC;
// 10857C0: using guessed type int dword_10857C0;

//----- (00F71200) --------------------------------------------------------
int sub_F71200()
{
 //// `eh vector constructor iterator'(word_1064900, 0x28u, 20, sub_F73750, sub_F73850);
  return atexit(sub_102A0D0);
}
// 1064900: using guessed type __int16 word_1064900[400];

//----- (00F71230) --------------------------------------------------------
int dynamic_initializer_for__garrAccountInfo__()
{
  return atexit(sub_102A0F0);
}

//----- (00F71240) --------------------------------------------------------
int dynamic_initializer_for__gpszTipText__()
{
  gpszTipText = _wcsdup(L"Autoruns - Sysinternals: www.sysinternals.com");
  return atexit(sub_102A150);
}

//----- (00F71260) --------------------------------------------------------
int sub_F71260()
{
  return atexit(sub_102A160);
}

//----- (00F71270) --------------------------------------------------------
int sub_F71270()
{
  return atexit(sub_102A1C0);
}

//----- (00F71280) --------------------------------------------------------
HCURSOR dynamic_initializer_for__ghHandCursor__()
{
  HCURSOR result; // eax

  result = LoadCursorW(0, IDC_HAND);
  ghHandCursor = result;
  return result;
}
// 10648EC: using guessed type int ghHandCursor;

//----- (00F712A0) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48E4__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48E4 = v0;
  *v0 = 0;
  return atexit(sub_102A220);
}

//----- (00F712C0) --------------------------------------------------------
int dynamic_initializer_for__gpszSystemPathInfo__()
{
  wchar_t *v0; // eax

  v0 = malloc(2u);
  gpszSystemPathInfo = v0;
  *v0 = 0;
  return atexit(sub_102A230);
}

//----- (00F712E0) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48FC__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48FC = v0;
  *v0 = 0;
  return atexit(sub_102A240);
}

//----- (00F71300) --------------------------------------------------------
int dynamic_initializer_for__gKeyNameMap__()
{
  gKeyNameMap._Mypair._Myval2._Myhead = std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode();
  return atexit(dynamic_atexit_destructor_for__gKeyNameMap__);
}

//----- (00F71320) --------------------------------------------------------
int dynamic_initializer_for__dword_4F48F0__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F48F0 = v0;
  *v0 = 0;
  return atexit(sub_102A2D0);
}

//----- (00F71340) --------------------------------------------------------
HCURSOR dynamic_initializer_for__ghWaitCursor__()
{
  HCURSOR result; // eax

  result = LoadCursorW(0, IDC_WAIT);
  ghWaitCursor = result;
  return result;
}
// 10648E8: using guessed type int ghWaitCursor;

//----- (00F71360) --------------------------------------------------------
int dynamic_initializer_for__dword_4F4C54__()
{
  _WORD *v0; // eax

  v0 = malloc(2u);
  dword_4F4C54 = v0;
  *v0 = 0;
  return atexit(sub_102A2F0);
}

//----- (00F71380) --------------------------------------------------------
int dynamic_initializer_for__dword_4F4C50__()
{
  WCHAR *v0; // eax

  v0 = malloc(2u);
  dword_4F4C50 = v0;
  *v0 = 0;
  return atexit(sub_102A300);
}

//----- (00F713A0) --------------------------------------------------------
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
  return atexit(sub_102A310);
}
// 1064CD8: using guessed type std__List gList5;
// 1064CE0: using guessed type std__List gList6;

//----- (00F71420) --------------------------------------------------------
int dynamic_initializer_for__gList1__()
{
  gList1 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_102A320);
}

//----- (00F71440) --------------------------------------------------------
int dynamic_initializer_for__gList2__()
{
  gList2 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_102A3F0);
}

//----- (00F71460) --------------------------------------------------------
int dynamic_initializer_for__gList3__()
{
  gList3 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_102A4C0);
}

//----- (00F71480) --------------------------------------------------------
int dynamic_initializer_for__gMap5__()
{
  gMap5 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_102A590);
}

//----- (00F714A0) --------------------------------------------------------
int sub_F714A0()
{
  return atexit(sub_102A610);
}

//----- (00F714B0) --------------------------------------------------------
int sub_F714B0()
{
  return atexit(sub_102A620);
}

//----- (00F714C0) --------------------------------------------------------
int sub_F714C0()
{
  return atexit(sub_102A630);
}

//----- (00F714D0) --------------------------------------------------------
int dynamic_initializer_for__gActiveScriptEventConsumer__()
{
  ActiveScriptEventConsumer::ActiveScriptEventConsumer(&gActiveScriptEventConsumer);
  return atexit(sub_102A640);
}
// 1064D28: using guessed type struct ActiveScriptEventConsumer gActiveScriptEventConsumer;

//----- (00F714F0) --------------------------------------------------------
int dynamic_initializer_for__gCommandLineEventConsumer__()
{
  CommandLineEventConsumer::CommandLineEventConsumer(&gCommandLineEventConsumer);
  return atexit(sub_102A660);
}
// 1064D1C: using guessed type struct CommandLineEventConsumer gCommandLineEventConsumer;

//----- (00F71510) --------------------------------------------------------
int dynamic_initializer_for__gMap6__()
{
  gMap6 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_102A680);
}

//----- (00F71530) --------------------------------------------------------
ATOM dynamic_initializer_for__gAtomTreeListProperty__()
{
  ATOM result; // ax

  result = GlobalAddAtomW(L"TreeListProperty");
  gAtomTreeListProperty = result;
  return result;
}
// 1064DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00F71550) --------------------------------------------------------
ATOM dynamic_initializer_for__gAtomTreeList__()
{
  ATOM result; // ax

  result = CTreeList::Register();
  gAtomTreeList = result;
  return result;
}
// 1064D9C: using guessed type __int16 gAtomTreeList;

//----- (00F71560) --------------------------------------------------------
BOOL dynamic_initializer_for__gLogPixelSize__()
{
  HDC v0; // edi

  v0 = CreateCompatibleDC(0);
  gLogPixelSize.x = GetDeviceCaps(v0, 88);
  gLogPixelSize.y = GetDeviceCaps(v0, 90);
  return DeleteDC(v0);
}

//----- (00F71590) --------------------------------------------------------
int dynamic_initializer_for__ghUxthemeModule__()
{
  ghUxthemeModule = LoadLibraryW(L"uxtheme.dll");
  return atexit(sub_102A700);
}

//----- (00F715B0) --------------------------------------------------------
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

//----- (00F715E0) --------------------------------------------------------
int (__stdcall *sub_F715E0())(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCRECT pRect, LPCRECT pClipRect)
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

//----- (00F71610) --------------------------------------------------------
int (__stdcall *sub_F71610())()
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
// 1064D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (00F71640) --------------------------------------------------------
FARPROC sub_F71640()
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

//----- (00F71670) --------------------------------------------------------
IAtlStringMgr *sub_F71670()
{
  IAtlStringMgr *result; // eax

  result = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  byte_1064DF4 = 1;
  return result;
}
// 1064DF4: using guessed type char byte_1064DF4;

//----- (00F71680) --------------------------------------------------------
int dynamic_initializer_for__gList4__()
{
  gBstrList = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_102A720);
}

//----- (00F716A0) --------------------------------------------------------
FARPROC sub_F716A0()
{
  HMODULE v0; // eax
  FARPROC result; // eax

  v0 = LoadLibraryW(L"Advapi32.dll");
  result = GetProcAddress(v0, "EnableTraceEx");
  EnableTraceEx = result;
  return result;
}

//----- (00F716C0) --------------------------------------------------------
int dynamic_initializer_for__gList7__()
{
  gAdapterLuidList._Mypair._Myval2._Myhead = sub_FB4360(0, 0);
  return atexit(sub_102A840);
}

//----- (00F716E0) --------------------------------------------------------
HANDLE dynamic_initializer_for__gProperties__()
{
  HANDLE result; // eax

  result = CreateEventW(0, 1, 0, 0);
  gProperties.EventHandle = result;
  gProperties.ThreadHandle = 0;
  return result;
}

//----- (00F71700) --------------------------------------------------------
DWORD sub_F71700()
{
  DWORD v0; // eax
  double v1; // xmm0_8
  DWORD result; // eax
  double v3; // xmm0_8

  v0 = GetSysColor(15);
  stru_105DDF0.Name = L"ColorJobs";
  stru_105DDF0.KeyType = 0;
  v1 = v0;
  result = v0 >> 31;
  stru_105DDF0.StructSize = 0;
  stru_105DDF0.Address = &gConfig.ColorJobs;
  off_105DE08 = L"ColorDelProc";
  dword_105DE0C = 0;
  dword_105DE10 = 0;
  v3 = v1 + qword_103D110[result];
  dword_105DE14 = &gConfig.ColorDelProc;
  off_105DE20 = L"ColorNewProc";
  dword_105DE24 = 0;
  dword_105DE28 = 0;
  stru_105DDD8.dbValue = v3;
  stru_105DDF0.dbValue = dbl_103EA10;
  dbl_105DE18 = dbl_103EA18;
  dbl_105DE30 = dbl_103EA20;
  qword_105DE48 = qword_103EA38;
  qword_105DE60 = *&dbl_103EA28;
  qword_105DE90 = *&dbl_103EA30;
  qword_105DEA8 = *&dbl_103EA08;
  dword_105DE2C = &gConfig.ColorNewProc;
  off_105DE38 = L"ColorNet";
  dword_105DE3C = 0;
  dword_105DE40 = 0;
  dword_105DE44 = &gConfig.ColorNet;
  dword_105DE50 = L"ColorProtected";
  dword_105DE54 = 0;
  dword_105DE58 = 0;
  dword_105DE5C = &gConfig.ColorProtected;
  dword_105DE68 = L"ShowHeatmaps";
  dword_105DE6C = 1;
  dword_105DE70 = 0;
  dword_105DE74 = &gConfig.bShowColumnHeatmaps;
  qword_105DE78 = *&db_one;
  dword_105DE80 = L"ColorSuspend";
  dword_105DE84 = 0;
  dword_105DE88 = 0;
  dword_105DE8C = &gConfig.ColorSuspend;
  dword_105DE98 = L"StatusBarColumns";
  dword_105DE9C = 0;
  dword_105DEA0 = 0;
  dword_105DEA4 = &gConfig.dwStatusBarColumns;
  dword_105DEB0 = L"ShowAllCpus";
  dword_105DEB4 = 1;
  dword_105DEB8 = 0;
  dword_105DEBC = &gConfig.bShowAllCpus;
  qword_105DEC0 = 0i64;
  dword_105DEC8 = L"ShowAllGpus";
  dword_105DECC = 1;
  dword_105DED0 = 0;
  dword_105DED4 = &gConfig.bShowAllGpus;
  qword_105DED8 = 0i64;
  dword_105DEE0 = L"Opacity";
  dword_105DEE4 = 0;
  dword_105DEE8 = 0;
  dword_105DEEC = &gConfig.dwOpacity;
  qword_105DEF0 = *&db_onehundred;
  dword_105DEF8 = L"GpuNodeUsageMask";
  dword_105DEFC = 0;
  dword_105DF00 = 0;
  dword_105DF04 = &gConfig.dwGpuNodeUsageMask;
  qword_105DF08 = *&db_one;
  dword_105DF10 = L"VerifySignatures";
  dword_105DF14 = 1;
  dword_105DF18 = 0;
  dword_105DF1C = &gConfig.bVerifySignatures;
  qword_105DF20 = 0i64;
  dword_105DF28 = L"VirusTotalCheck";
  dword_105DF2C = 1;
  dword_105DF30 = 0;
  dword_105DF34 = &gConfig.bCheckVirusTotal;
  qword_105DF38 = 0i64;
  dword_105DF40 = L"VirusTotalSubmitUnknown";
  dword_105DF44 = 1;
  dword_105DF48 = 0;
  dword_105DF4C = &gConfig.bVirusTotalSubmitUnknown;
  qword_105DF50 = 0i64;
  dword_105DF58 = L"ToolbarBands";
  dword_105DF5C = 7;
  dword_105DF60 = 96;
  dword_105DF64 = gConfig.ToolBandInfo;
  qword_105DF68 = 0i64;
  dword_105DF70 = L"UseGoogle";
  dword_105DF74 = 1;
  dword_105DF78 = 0;
  dword_105DF7C = &gConfig.bUseGoogle;
  qword_105DF80 = 0i64;
  dword_105DF88 = L"ShowNewProcesses";
  dword_105DF8C = 1;
  dword_105DF90 = 0;
  dword_105DF94 = &gConfig.bShowNewProcesses;
  qword_105DF98 = 0i64;
  dword_105DFA0 = L"TrayCPUHistory";
  dword_105DFA4 = 1;
  dword_105DFA8 = 0;
  dword_105DFAC = &gConfig.bTrayCPUHistory;
  qword_105DFB0 = *&db_one;
  dword_105DFB8 = L"ShowIoTray";
  dword_105DFBC = 1;
  dword_105DFC0 = 0;
  dword_105DFC4 = &gConfig.bShowIoTray;
  qword_105DFC8 = 0i64;
  dword_105DFD0 = L"ShowNetTray";
  dword_105DFD4 = 1;
  dword_105DFD8 = 0;
  dword_105DFDC = &gConfig.bShowNetTray;
  qword_105DFE0 = 0i64;
  dword_105DFE8 = L"ShowDiskTray";
  dword_105DFEC = 1;
  dword_105DFF0 = 0;
  dword_105DFF4 = &gConfig.bShowDiskTray;
  qword_105DFF8 = 0i64;
  dword_105E000 = L"ShowPhysTray";
  dword_105E004 = 1;
  dword_105E008 = 0;
  dword_105E00C = &gConfig.bShowPhysTray;
  qword_105E010 = 0i64;
  dword_105E018 = L"ShowCommitTray";
  dword_105E01C = 1;
  dword_105E020 = 0;
  dword_105E024 = &gConfig.bShowCommitTray;
  qword_105E028 = 0i64;
  dword_105E030 = L"ShowGpuTray";
  dword_105E034 = 1;
  dword_105E038 = 0;
  dword_105E03C = &gConfig.bShowGpuHistory;
  qword_105E040 = 0i64;
  dword_105E048 = L"FormatIoBytes";
  dword_105E04C = 1;
  dword_105E050 = 0;
  dword_105E054 = &gConfig.bFormatIoBytes;
  qword_105E058 = *&db_one;
  dword_105E060 = L"StackWindowPlacement";
  dword_105E064 = 7;
  dword_105E068 = 44;
  dword_105E06C = &gConfig.WindowPlacement[5];
  qword_105E070 = 0i64;
  dword_105E078 = L"ETWstandardUserWarning";
  dword_105E07C = 1;
  dword_105E080 = 0;
  dword_105E084 = &gConfig.bETWStandardUserWarning;
  qword_105E088 = 0i64;
  dword_105E090 = 0;
  dword_105E094 = 0;
  dword_105E098 = 0;
  dword_105E09C = 0;
  qword_105E0A0 = 0i64;
  return result;
}
// 103CDC0: using guessed type double db_onehundred;
// 103DAD8: using guessed type wchar_t aColorjobs[10];
// 103DAEC: using guessed type wchar_t aColordelproc[13];
// 103DB08: using guessed type wchar_t aColornewproc[13];
// 103DB24: using guessed type wchar_t aColornet[9];
// 103DB38: using guessed type wchar_t aColorprotected[15];
// 103DB58: using guessed type wchar_t aShowheatmaps[13];
// 103DB74: using guessed type wchar_t aColorsuspend[13];
// 103DB90: using guessed type wchar_t aStatusbarcolum[17];
// 103DBB4: using guessed type wchar_t aShowallcpus[12];
// 103DBCC: using guessed type wchar_t aShowallgpus[12];
// 103DBF4: using guessed type wchar_t aGpunodeusagema[17];
// 103DC18: using guessed type wchar_t aVerifysignatur[17];
// 103DC3C: using guessed type wchar_t aVirustotalchec[16];
// 103DC5C: using guessed type wchar_t aVirustotalsubm[24];
// 103DC8C: using guessed type wchar_t aToolbarbands[13];
// 103DCA8: using guessed type wchar_t aUsegoogle[10];
// 103DCBC: using guessed type wchar_t aShownewprocess[17];
// 103DCE0: using guessed type wchar_t aTraycpuhistory[15];
// 103DD00: using guessed type wchar_t aShowiotray[11];
// 103DD18: using guessed type wchar_t aShownettray[12];
// 103DD30: using guessed type wchar_t aShowdisktray[13];
// 103DD4C: using guessed type wchar_t aShowphystray[13];
// 103DD68: using guessed type wchar_t aShowcommittray[15];
// 103DD88: using guessed type wchar_t aShowgputray[12];
// 103DDA0: using guessed type wchar_t aFormatiobytes[14];
// 103DDBC: using guessed type wchar_t aStackwindowpla[21];
// 103DDE8: using guessed type wchar_t aEtwstandarduse[23];
// 103EA08: using guessed type double dbl_103EA08;
// 103EA10: using guessed type double dbl_103EA10;
// 103EA18: using guessed type double dbl_103EA18;
// 103EA20: using guessed type double dbl_103EA20;
// 103EA28: using guessed type double dbl_103EA28;
// 103EA30: using guessed type double dbl_103EA30;
// 103EA38: using guessed type __int64 qword_103EA38;
// 105DDD8: using guessed type tagConfigItem;
// 105DDF0: using guessed type tagConfigItem stru_105DDF0;
// 105DE08: using guessed type void *off_105DE08;
// 105DE0C: using guessed type int dword_105DE0C;
// 105DE10: using guessed type int dword_105DE10;
// 105DE14: using guessed type int dword_105DE14;
// 105DE18: using guessed type double dbl_105DE18;
// 105DE20: using guessed type void *off_105DE20;
// 105DE24: using guessed type int dword_105DE24;
// 105DE28: using guessed type int dword_105DE28;
// 105DE2C: using guessed type int dword_105DE2C;
// 105DE30: using guessed type double dbl_105DE30;
// 105DE38: using guessed type void *off_105DE38;
// 105DE3C: using guessed type int dword_105DE3C;
// 105DE40: using guessed type int dword_105DE40;
// 105DE44: using guessed type int dword_105DE44;
// 105DE48: using guessed type __int64 qword_105DE48;
// 105DE50: using guessed type int dword_105DE50;
// 105DE54: using guessed type int dword_105DE54;
// 105DE58: using guessed type int dword_105DE58;
// 105DE5C: using guessed type int dword_105DE5C;
// 105DE60: using guessed type __int64 qword_105DE60;
// 105DE68: using guessed type int dword_105DE68;
// 105DE6C: using guessed type int dword_105DE6C;
// 105DE70: using guessed type int dword_105DE70;
// 105DE74: using guessed type int dword_105DE74;
// 105DE78: using guessed type __int64 qword_105DE78;
// 105DE80: using guessed type int dword_105DE80;
// 105DE84: using guessed type int dword_105DE84;
// 105DE88: using guessed type int dword_105DE88;
// 105DE8C: using guessed type int dword_105DE8C;
// 105DE90: using guessed type __int64 qword_105DE90;
// 105DE98: using guessed type int dword_105DE98;
// 105DE9C: using guessed type int dword_105DE9C;
// 105DEA0: using guessed type int dword_105DEA0;
// 105DEA4: using guessed type int dword_105DEA4;
// 105DEA8: using guessed type __int64 qword_105DEA8;
// 105DEB0: using guessed type int dword_105DEB0;
// 105DEB4: using guessed type int dword_105DEB4;
// 105DEB8: using guessed type int dword_105DEB8;
// 105DEBC: using guessed type int dword_105DEBC;
// 105DEC0: using guessed type __int64 qword_105DEC0;
// 105DEC8: using guessed type int dword_105DEC8;
// 105DECC: using guessed type int dword_105DECC;
// 105DED0: using guessed type int dword_105DED0;
// 105DED4: using guessed type int dword_105DED4;
// 105DED8: using guessed type __int64 qword_105DED8;
// 105DEE0: using guessed type int dword_105DEE0;
// 105DEE4: using guessed type int dword_105DEE4;
// 105DEE8: using guessed type int dword_105DEE8;
// 105DEEC: using guessed type int dword_105DEEC;
// 105DEF0: using guessed type __int64 qword_105DEF0;
// 105DEF8: using guessed type int dword_105DEF8;
// 105DEFC: using guessed type int dword_105DEFC;
// 105DF00: using guessed type int dword_105DF00;
// 105DF04: using guessed type int dword_105DF04;
// 105DF08: using guessed type __int64 qword_105DF08;
// 105DF10: using guessed type int dword_105DF10;
// 105DF14: using guessed type int dword_105DF14;
// 105DF18: using guessed type int dword_105DF18;
// 105DF1C: using guessed type int dword_105DF1C;
// 105DF20: using guessed type __int64 qword_105DF20;
// 105DF28: using guessed type int dword_105DF28;
// 105DF2C: using guessed type int dword_105DF2C;
// 105DF30: using guessed type int dword_105DF30;
// 105DF34: using guessed type int dword_105DF34;
// 105DF38: using guessed type __int64 qword_105DF38;
// 105DF40: using guessed type int dword_105DF40;
// 105DF44: using guessed type int dword_105DF44;
// 105DF48: using guessed type int dword_105DF48;
// 105DF4C: using guessed type int dword_105DF4C;
// 105DF50: using guessed type __int64 qword_105DF50;
// 105DF58: using guessed type int dword_105DF58;
// 105DF5C: using guessed type int dword_105DF5C;
// 105DF60: using guessed type int dword_105DF60;
// 105DF64: using guessed type int dword_105DF64;
// 105DF68: using guessed type __int64 qword_105DF68;
// 105DF70: using guessed type int dword_105DF70;
// 105DF74: using guessed type int dword_105DF74;
// 105DF78: using guessed type int dword_105DF78;
// 105DF7C: using guessed type int dword_105DF7C;
// 105DF80: using guessed type __int64 qword_105DF80;
// 105DF88: using guessed type int dword_105DF88;
// 105DF8C: using guessed type int dword_105DF8C;
// 105DF90: using guessed type int dword_105DF90;
// 105DF94: using guessed type int dword_105DF94;
// 105DF98: using guessed type __int64 qword_105DF98;
// 105DFA0: using guessed type int dword_105DFA0;
// 105DFA4: using guessed type int dword_105DFA4;
// 105DFA8: using guessed type int dword_105DFA8;
// 105DFAC: using guessed type int dword_105DFAC;
// 105DFB0: using guessed type __int64 qword_105DFB0;
// 105DFB8: using guessed type int dword_105DFB8;
// 105DFBC: using guessed type int dword_105DFBC;
// 105DFC0: using guessed type int dword_105DFC0;
// 105DFC4: using guessed type int dword_105DFC4;
// 105DFC8: using guessed type __int64 qword_105DFC8;
// 105DFD0: using guessed type int dword_105DFD0;
// 105DFD4: using guessed type int dword_105DFD4;
// 105DFD8: using guessed type int dword_105DFD8;
// 105DFDC: using guessed type int dword_105DFDC;
// 105DFE0: using guessed type __int64 qword_105DFE0;
// 105DFE8: using guessed type int dword_105DFE8;
// 105DFEC: using guessed type int dword_105DFEC;
// 105DFF0: using guessed type int dword_105DFF0;
// 105DFF4: using guessed type int dword_105DFF4;
// 105DFF8: using guessed type __int64 qword_105DFF8;
// 105E000: using guessed type int dword_105E000;
// 105E004: using guessed type int dword_105E004;
// 105E008: using guessed type int dword_105E008;
// 105E00C: using guessed type int dword_105E00C;
// 105E010: using guessed type __int64 qword_105E010;
// 105E018: using guessed type int dword_105E018;
// 105E01C: using guessed type int dword_105E01C;
// 105E020: using guessed type int dword_105E020;
// 105E024: using guessed type int dword_105E024;
// 105E028: using guessed type __int64 qword_105E028;
// 105E030: using guessed type int dword_105E030;
// 105E034: using guessed type int dword_105E034;
// 105E038: using guessed type int dword_105E038;
// 105E03C: using guessed type int dword_105E03C;
// 105E040: using guessed type __int64 qword_105E040;
// 105E048: using guessed type int dword_105E048;
// 105E04C: using guessed type int dword_105E04C;
// 105E050: using guessed type int dword_105E050;
// 105E054: using guessed type int dword_105E054;
// 105E058: using guessed type __int64 qword_105E058;
// 105E060: using guessed type int dword_105E060;
// 105E064: using guessed type int dword_105E064;
// 105E068: using guessed type int dword_105E068;
// 105E06C: using guessed type int dword_105E06C;
// 105E070: using guessed type __int64 qword_105E070;
// 105E078: using guessed type int dword_105E078;
// 105E07C: using guessed type int dword_105E07C;
// 105E080: using guessed type int dword_105E080;
// 105E084: using guessed type int dword_105E084;
// 105E088: using guessed type __int64 qword_105E088;
// 105E090: using guessed type int dword_105E090;
// 105E094: using guessed type int dword_105E094;
// 105E098: using guessed type int dword_105E098;
// 105E09C: using guessed type int dword_105E09C;
// 105E0A0: using guessed type __int64 qword_105E0A0;

//----- (00F71CE0) --------------------------------------------------------
FARPROC sub_F71CE0()
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
// 1069E88: using guessed type int (__stdcall *gpfnEnableThemeDialogTexture)(_DWORD, _DWORD);

//----- (00F71D10) --------------------------------------------------------
int dynamic_initializer_for__gPerformanceInfoInMemory__()
{
  PE_PerfInfo::PE_PerfInfo(&gPerformanceInfoInMemory, &gPerformanceInfo);
  return atexit(sub_102A9D0);
}

//----- (00F71D30) --------------------------------------------------------
int dynamic_initializer_for__gPerformanceInfo__()
{
  PerformanceInfo::PerformanceInfo(&gPerformanceInfo, 0);
  return atexit(sub_102A9E0);
}

//----- (00F71D50) --------------------------------------------------------
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
  return atexit(sub_102A9F0);
}

//----- (00F71DE0) --------------------------------------------------------
int dynamic_initializer_for__gWbemServicesList__()
{
  *(&gWbemServiceList + 1) = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                               0,
                               0);
  return atexit(sub_102AA50);
}

//----- (00F71E00) --------------------------------------------------------
BOOL dynamic_initializer_for__gTime__()
{
  GetSystemTimeAsFileTime(&gTime);
  QueryPerformanceCounter(&gTime.Performance);
  return QueryPerformanceFrequency(&gTime.Frequency);
}

//----- (00F71E30) --------------------------------------------------------
int dynamic_initializer_for__gMap1__()
{
  gThreadProcessMap._Header = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_102AB20);
}

//----- (00F71E50) --------------------------------------------------------
bool dynamic_initializer_for__gbBitmapOnRight__()
{
  bool result; // al

  result = IsXPDll();
  gbBitmapOnRight = result;
  return result;
}
// 106A8F8: using guessed type char gbBitmapOnRight;

//----- (00F71E60) --------------------------------------------------------
int dynamic_initializer_for__gDiskGraphInfo__()
{
  _bstr_t::_bstr_t(&gDiskGraphInfo.strName, "Disk");
  gDiskGraphInfo.pGraphData = 0;
  gDiskGraphInfo.dbMemorySize = 0i64;
  gDiskGraphInfo.nItemID = 8;
  return atexit(sub_102ABA0);
}

//----- (00F71EA0) --------------------------------------------------------
int dynamic_initializer_for__gIOGraphInfo__()
{
  _bstr_t::_bstr_t(&gIOGraphInfo.strName, "I/O");
  gIOGraphInfo.pGraphData = 0;
  gIOGraphInfo.dbMemorySize = 0i64;
  gIOGraphInfo.nItemID = 2;
  return atexit(sub_102AC00);
}

//----- (00F71EE0) --------------------------------------------------------
int dynamic_initializer_for__gNetworkGraphInfo__()
{
  _bstr_t::_bstr_t(&gNetworkGraphInfo.strName, "Network");
  gNetworkGraphInfo.pGraphData = 0;
  gNetworkGraphInfo.dbMemorySize = 0i64;
  gNetworkGraphInfo.nItemID = 9;
  return atexit(sub_102AC60);
}

//----- (00F71F20) --------------------------------------------------------
int sub_F71F20()
{
  gMap2._Header = sub_FF5440();
  return atexit(sub_102ACC0);
}

//----- (00F71F40) --------------------------------------------------------
int sub_F71F40()
{
  gMap3._Header = sub_FF5440();
  return atexit(sub_102AD40);
}

//----- (00F71F60) --------------------------------------------------------
int sub_F71F60()
{
  int result; // eax

  result = TreeList_Item1::Reset(&gTreeList_Item[2]);
  gTreeList_Item[2].field_14 = 0;
  gTreeList_Item[2].field_10 = 0;
  gTreeList_Item[2].field_C = 0;
  return result;
}

//----- (00F71F90) --------------------------------------------------------
int sub_F71F90()
{
  int result; // eax

  result = TreeList_Item1::Reset(gTreeList_Item);
  gTreeList_Item[0].field_14 = 0;
  gTreeList_Item[0].field_10 = 0;
  gTreeList_Item[0].field_C = 0;
  return result;
}

//----- (00F71FC0) --------------------------------------------------------
int sub_F71FC0()
{
  int result; // eax

  result = TreeList_Item1::Reset(&gTreeList_Item[1]);
  gTreeList_Item[1].field_14 = 0;
  gTreeList_Item[1].field_10 = 0;
  gTreeList_Item[1].field_C = 0;
  return result;
}

//----- (00F71FF0) --------------------------------------------------------
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

//----- (00F72070) --------------------------------------------------------
int sub_F72070()
{
  off_10857A4 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_102AE00);
}

//----- (00F72090) --------------------------------------------------------
int sub_F72090()
{
  dword_108579C = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                    0,
                    0);
  return atexit(sub_102AED0);
}

//----- (00F720B0) --------------------------------------------------------
int sub_F720B0()
{
  off_10857AC = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  return atexit(sub_102AFA0);
}

//----- (00F720D0) --------------------------------------------------------
int sub_F720D0()
{
  gHttpInfo.field_1C = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  return atexit(sub_102B070);
}

//----- (00F720F0) --------------------------------------------------------
int sub_F720F0()
{
  return atexit(sub_102B0F0);
}

//----- (00F720FC) --------------------------------------------------------
int sub_F720FC()
{
  std::_Init_locks::_Init_locks(&unk_10857D8);
  return atexit(sub_102B0FC);
}

//----- (00F72112) --------------------------------------------------------
int sub_F72112()
{
  return atexit(sub_102B106);
}

//----- (00F7211E) --------------------------------------------------------
int sub_F7211E()
{
  return atexit(sub_102B110);
}

//----- (00F7212A) --------------------------------------------------------
int sub_F7212A()
{
  return atexit(sub_102B11A);
}

//----- (00F72136) --------------------------------------------------------
int sub_F72136()
{
  std::_Init_locks::_Init_locks(&unk_10858F0);
  return atexit(sub_102B124);
}

//----- (00F7214C) --------------------------------------------------------
int dynamic_initializer_for__ATL::_AtlBaseModule___()
{
  ATL::CAtlWinModule::CAtlWinModule(&ATL::_AtlBaseModule);
  return atexit(ATL::_dynamic_atexit_destructor_for___AtlBaseModule__);
}

//----- (00F72170) --------------------------------------------------------
_DWORD *__thiscall sub_F72170(_DWORD *this)
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

//----- (00F721A0) --------------------------------------------------------
void __thiscall sub_F721A0(void ***this)
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

//----- (00F721F0) --------------------------------------------------------
void __thiscall sub_F721F0(void **this)
{
  void **v1; // edi
  void **v2; // esi
  void **i; // ebx

  v1 = this;
  v2 = this[1];
  if ( v2 )
  {
    for ( i = this[2]; v2 != i; ++v2 )
      free(*v2);
    j__free(v1[1]);
    v1[1] = 0;
    v1[2] = 0;
    v1[3] = 0;
  }
  free(*v1);
}

//----- (00F72250) --------------------------------------------------------
void **__thiscall sub_F72250(void **this, const wchar_t **a2)
{
  void **v2; // edi
  void *v3; // esi

  v2 = this;
  v3 = *this;
  *this = _wcsdup(*a2);
  free(v3);
  return v2;
}

//----- (00F72280) --------------------------------------------------------
void **__thiscall sub_F72280(void **this, wchar_t *a2)
{
  void **v2; // edi
  void *v3; // esi

  v2 = this;
  v3 = *this;
  *this = _wcsdup(a2);
  free(v3);
  return v2;
}

//----- (00F722B0) --------------------------------------------------------
int __cdecl PE_CopyString(WCHAR **ppv, WCHAR *lpszText1, LPCWSTR lpszText2)
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
  PE_CopyStringEx(ppv, lpszText1, &lpszText2);
  free(pszText2);
  return ppv;
}

//----- (00F72300) --------------------------------------------------------
void *__thiscall CopyStringToString(WCHAR **ppv, WCHAR *lpszText, DWORD dwPos, DWORD dwLength)
{
  WCHAR **ppv_1; // eax
  WCHAR *pstr; // ecx
  DWORD nTextLen1; // esi
  DWORD dwLength_1; // ebx
  DWORD dwPos_1; // edx
  unsigned int nTextLen2; // edi
  WCHAR *v10; // eax
  WCHAR **ppv_3; // ecx
  WCHAR **ppv_2; // [esp+Ch] [ebp-4h]
  DWORD dwPos_2; // [esp+1Ch] [ebp+Ch]

  ppv_1 = ppv;
  pstr = *ppv;
  ppv_2 = ppv_1;
  nTextLen1 = wcslen(pstr);
  dwLength_1 = dwLength;
  dwPos_1 = dwPos;
  if ( dwPos > nTextLen1 )
    dwPos_1 = nTextLen1;
  dwPos_2 = dwPos_1;
  if ( dwPos_1 + dwLength > nTextLen1 )
    dwLength_1 = nTextLen1 - dwPos_1;
  nTextLen2 = wcslen(lpszText);
  if ( (nTextLen2 - dwLength_1) <= 0 )
  {
    // 直接复制到字符串的指定的位置
    ppv_3 = ppv_2;
  }
  else
  {
    // 重新开辟内存，进行复制
    v10 = realloc(pstr, 2 * (nTextLen1 + nTextLen2 - dwLength_1 + 2));
    ppv_3 = ppv_2;
    dwPos_1 = dwPos_2;
    *ppv_2 = v10;
  }
  memmove(&(*ppv_3)[dwPos_1 + nTextLen2], &(*ppv_3)[dwPos_1 + dwLength_1], 2 * (nTextLen1 - dwPos_1 - dwLength_1) + 2);
  return memmove_0(&(*ppv_2)[dwPos_2], lpszText, 2 * nTextLen2);
}

//----- (00F723D0) --------------------------------------------------------
void __cdecl sub_F723D0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F72480(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F72480(a1, a2, v7, v5);
  free(v7);
}

//----- (00F72480) --------------------------------------------------------
void *__cdecl sub_F72480(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  HKEY v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  unsigned __int16 **v8; // esi
  unsigned __int16 **v9; // eax
  unsigned int v10; // eax
  tagKeyName *v11; // esi
  unsigned int v12; // eax
  WCHAR *v13; // esi
  void *v14; // esi
  const wchar_t **v15; // eax
  void *v16; // esi
  const wchar_t *v17; // ecx
  const wchar_t *v18; // eax
  unsigned __int16 **v19; // esi
  unsigned __int16 **v20; // eax
  char v21; // bl
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  HKEY v24; // ebx
  unsigned __int16 **v25; // esi
  unsigned __int16 **v26; // eax
  const wchar_t *v27; // eax
  unsigned __int16 **v28; // eax
  int a2a; // [esp+10h] [ebp-A4h]
  int v31; // [esp+14h] [ebp-A0h]
  int v32; // [esp+18h] [ebp-9Ch]
  int v33; // [esp+1Ch] [ebp-98h]
  WCHAR v34[2]; // [esp+20h] [ebp-94h]
  WCHAR v35[2]; // [esp+24h] [ebp-90h]
  WCHAR v36[2]; // [esp+28h] [ebp-8Ch]
  int v37; // [esp+2Ch] [ebp-88h]
  void *v38; // [esp+30h] [ebp-84h]
  int v39; // [esp+34h] [ebp-80h]
  WCHAR v40[2]; // [esp+38h] [ebp-7Ch]
  WCHAR v41[2]; // [esp+3Ch] [ebp-78h]
  DWORD v42; // [esp+40h] [ebp-74h]
  void *v43; // [esp+44h] [ebp-70h]
  void *v44; // [esp+48h] [ebp-6Ch]
  void *v45; // [esp+4Ch] [ebp-68h]
  void *v46; // [esp+50h] [ebp-64h]
  void *v47; // [esp+54h] [ebp-60h]
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
  LPCWSTR v63; // [esp+94h] [ebp-20h]
  WCHAR *ppv3; // [esp+98h] [ebp-1Ch]
  void *v65; // [esp+9Ch] [ebp-18h]
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
  v65 = malloc(2u);
  *v65 = 0;
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
    v63 = _wcsdup(&gszNullString);
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
    v8 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v68) = 18;
    v9 = sub_F77BE0(szArg, a2, &szArg3, &v56);
    LOBYTE(v68) = 19;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v9, v8, &v60);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v56);
    free(pszText);
    free(szArg4);
    free(v60);
    free(v59);
    free(v55);
    free(v63);
    free(v54);
    LOBYTE(v68) = 7;
    free(v62);
    v5 = a2;
  }
  v10 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(v5, psz, 0, v10 | 0x20019, &KeyHandle) )
  {
    if ( !PE_LoadKey(KeyHandle, 0, &lpSubKey) )
    {
      do
      {
        v11 = lpSubKey;
        v12 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v11, 0, v12 | 0x20019, &hKey) )
        {
          if ( !sub_F815A0(KeyHandle, lpSubKey, &ppv3) )
          {
            if ( (LOWORD(v67->_Mypair._Myval2._Myhead) = 0, !sub_F81520(hKey, L"ShellComponent", 0, 0, &v67))
              && LOWORD(v67->_Mypair._Myval2._Myhead)
              || (sub_F81520(hKey, L"StubPath", 0, 0, &v67), LOWORD(v67->_Mypair._Myval2._Myhead)) )
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
              sub_F76CC0(v67, &a2a);
              v14 = v51;
              v51 = _wcsdup(v67);
              free(v14);
              v15 = sub_F74EE0(&v38, a1, &a2a, 0);
              v16 = v65;
              v65 = _wcsdup(*v15);
              free(v16);
              free(v38);
              v37 = sub_F74ED0();
              v17 = &gszNullString;
              if ( psz )
                v17 = psz;
              v63 = _wcsdup(v17);
              v54 = _wcsdup(&gszNullString);
              v18 = &gszNullString;
              if ( psz )
                v18 = psz;
              v62 = _wcsdup(v18);
              LOBYTE(v68) = 23;
              v19 = sub_F77BE0(v41, a2, &v63, &lpSubKey);
              LOBYTE(v68) = 24;
              v20 = sub_F77BE0(v36, a2, &v62, &v54);
              LOBYTE(v68) = 25;
              v21 = sub_F73D40(a1, v20, v19, &ppv3, &v65, &v49, &v47, &v39);
              free(*v36);
              free(*v41);
              free(v62);
              free(v54);
              free(v63);
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
                  v25 = sub_F77BE0(v40, a2, &v60, &szArg4);
                  LOBYTE(v68) = 36;
                  v26 = sub_F77BE0(v34, a2, &v55, &v59);
                  LOBYTE(v68) = 37;
                  a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v26, v25, &pszText);
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
                v28 = sub_F77BE0(v35, v24, &a1a, &lpSubKey);
                LOBYTE(v68) = 40;
                sub_F73FF0(a1, v37, a4, 3, &ppv3, v28, &v65);
                free(*v35);
                free(a1a);
                free(*szArg);
              }
              LOBYTE(v68) = 7;
              sub_F721F0(&a2a);
              v4 = v42;
            }
          }
          RegCloseKey(hKey);
        }
        v42 = ++v4;
      }
      while ( !PE_LoadKey(KeyHandle, v4, &lpSubKey) );
    }
    RegCloseKey(KeyHandle);
  }
  free(v51);
  free(v47);
  free(v46);
  free(v49);
  free(v65);
  free(lpSubKey);
  free(ppv3);
  free(v67);
  return a4;
}

//----- (00F72BC0) --------------------------------------------------------
void __stdcall sub_F72BC0(void **a1, void **a2)
{
  void **i; // esi

  for ( i = a1; i != a2; ++i )
    free(*i);
}

//----- (00F72BF0) --------------------------------------------------------
char *__cdecl sub_F72BF0(int a1, int a2)
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

//----- (00F72C60) --------------------------------------------------------
void __thiscall sub_F72C60(int *this)
{
  int *v1; // esi

  v1 = this;
  if ( *this )
  {
    sub_F72BF0(*this, this[1]);
    j__free(*v1);
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
  }
}

//----- (00F72CB0) --------------------------------------------------------
void __cdecl sub_F72CB0(int a1, void *a2, void *a3, LPCWSTR lpValueName)
{
  _WORD *v4; // ST58_4
  WCHAR *v5; // esi
  void *v6; // edi
  const wchar_t **v7; // eax
  wchar_t *v8; // ST5C_4

  v4 = malloc(2u);
  *v4 = 0;
  v5 = a3;
  v6 = sub_F72D60(a1, a2, *a3, lpValueName, 0xFFFFFFFF);
  v7 = PE_CopyString(&a3, v5, L"\\AutorunsDisabled");
  v8 = _wcsdup(*v7);
  free(v4);
  free(a3);
  sub_F72D60(a1, a2, v8, lpValueName, v6);
  free(v8);
}

//----- (00F72D60) --------------------------------------------------------
void *__cdecl sub_F72D60(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, void *a5)
{
  LPCWSTR v5; // ebx
  HKEY v6; // esi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  const wchar_t *v10; // eax
  unsigned __int16 **v11; // esi
  unsigned __int16 **v12; // eax
  unsigned int v13; // eax
  int v14; // edx
  wchar_t *v15; // ecx
  unsigned int v16; // edi
  int v17; // esi
  const wchar_t **v18; // eax
  void *v19; // esi
  const WCHAR **v20; // ecx
  const wchar_t *v21; // eax
  const WCHAR **v22; // eax
  const wchar_t *v23; // eax
  unsigned __int16 **v24; // esi
  unsigned __int16 **v25; // eax
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  const wchar_t *v29; // eax
  const wchar_t *v30; // eax
  unsigned __int16 **v31; // esi
  unsigned __int16 **v32; // eax
  const WCHAR **v33; // eax
  const wchar_t *v34; // eax
  unsigned __int16 **v35; // eax
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
  void *v59; // [esp+6Ch] [ebp-48h]
  WCHAR szArg[2]; // [esp+70h] [ebp-44h]
  void *a1a; // [esp+74h] [ebp-40h]
  void *v62; // [esp+78h] [ebp-3Ch]
  LPCWSTR v63; // [esp+7Ch] [ebp-38h]
  LPCWSTR szArg3; // [esp+80h] [ebp-34h]
  LPCWSTR v65; // [esp+84h] [ebp-30h]
  LPCWSTR v66; // [esp+88h] [ebp-2Ch]
  LPCWSTR v67; // [esp+8Ch] [ebp-28h]
  LPCWSTR v68; // [esp+90h] [ebp-24h]
  LPCWSTR v69; // [esp+94h] [ebp-20h]
  LPCWSTR v70; // [esp+98h] [ebp-1Ch]
  LPCWSTR szArg4; // [esp+9Ch] [ebp-18h]
  WCHAR *pszText; // [esp+A0h] [ebp-14h]
  void *v73; // [esp+A4h] [ebp-10h]
  int v74; // [esp+B0h] [ebp-4h]

  v58 = malloc(2u);
  *v58 = 0;
  v74 = 0;
  v73 = malloc(2u);
  *v73 = 0;
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
    v65 = _wcsdup(&gszNullString);
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
    v11 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v74) = 15;
    v12 = sub_F77BE0(szArg, a2, &szArg3, &v66);
    LOBYTE(v74) = 16;
    a5 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v12, v11, &v70);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v66);
    free(pszText);
    free(szArg4);
    free(v70);
    free(v69);
    free(v67);
    free(v65);
    free(v63);
    LOBYTE(v74) = 4;
    free(v68);
    v6 = a2;
  }
  v13 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(v6, psz, 0, v13 | 0x20019, &hKey) )
  {
    if ( !sub_F81520(hKey, lpValueName, 0, 0, &v58) )
    {
      v52 = 0;
      v53 = 0;
      v54 = 0;
      LOBYTE(v74) = 17;
      sub_F76DD0(v58, 44, &v52, 32);
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
          v18 = sub_F74EE0(&v44, a1, v15 + v17, 0);
          v19 = v73;
          v73 = _wcsdup(*v18);
          free(v19);
          free(v44);
          a2a = sub_F74ED0();
          v20 = &gszNullString;
          if ( v5 )
            v20 = v5;
          v67 = _wcsdup(v20);
          v21 = &gszNullString;
          if ( psz )
            v21 = psz;
          v65 = _wcsdup(v21);
          v22 = &gszNullString;
          if ( v5 )
            v22 = v5;
          v63 = _wcsdup(v22);
          v23 = &gszNullString;
          if ( psz )
            v23 = psz;
          v68 = _wcsdup(v23);
          LOBYTE(v74) = 21;
          v24 = sub_F77BE0(v42, a2, &v65, &v67);
          LOBYTE(v74) = 22;
          v25 = sub_F77BE0(v37, a2, &v68, &v63);
          LOBYTE(v74) = 23;
          v26 = sub_F73D40(a1, v25, v24, ppv3, &v73, &v62, &v59, &v43);
          free(*v37);
          free(*v42);
          free(v68);
          free(v63);
          free(v65);
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
              v31 = sub_F77BE0(v40, a2, &szArg4, &pszText);
              LOBYTE(v74) = 34;
              v32 = sub_F77BE0(v38, a2, &v69, &v70);
              LOBYTE(v74) = 35;
              a5 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v32, v31, &v66);
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
            v35 = sub_F77BE0(v39, a2, &v50, &v46);
            LOBYTE(v74) = 40;
            sub_F73FF0(a1, a2a, a5, 5, ppv3, v35, &v73);
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
        sub_F72BF0(v15, v14);
        j__free(v52);
      }
    }
    RegCloseKey(hKey);
  }
  free(v59);
  free(v57);
  free(v62);
  free(v73);
  free(v58);
  return a5;
}

//----- (00F73440) --------------------------------------------------------
int __cdecl sub_F73440(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // edi
  int v8; // [esp+0h] [ebp-24h]
  int v9; // [esp+10h] [ebp-14h]
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
      sub_F735A0((v3 + 4), (v4 + 4));
    }
    v3 += 16;
    LOBYTE(v11) = 0;
    v4 += 16;
  }
  return v3;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F734F0) --------------------------------------------------------
wchar_t **__cdecl sub_F734F0(std__vector *a1, const wchar_t **a2, wchar_t **a3)
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

//----- (00F73530) --------------------------------------------------------
_DWORD *__thiscall sub_F73530(void *this, void *a2)
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

//----- (00F735A0) --------------------------------------------------------
wchar_t ***__thiscall sub_F735A0(wchar_t ***this, const wchar_t ***a2)
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
  if ( sub_F7F930(this, v3[1] - *v3) )
  {
    v8 = 0;
    v2[1] = sub_F734F0(*v3, v3[1], *v2);
  }
  return v2;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F73650) --------------------------------------------------------
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

//----- (00F73750) --------------------------------------------------------
void __thiscall sub_F73750(void *this)
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

//----- (00F73780) --------------------------------------------------------
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

//----- (00F73820) --------------------------------------------------------
int __thiscall sub_F73820(int this)
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

//----- (00F73850) --------------------------------------------------------
void __thiscall sub_F73850(void *this)
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

//----- (00F73890) --------------------------------------------------------
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

//----- (00F738F0) --------------------------------------------------------
int *__thiscall sub_F738F0(int *this, const wchar_t ***a2)
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
      sub_F80010(this);
      return v2;
    }
    v6 = *this;
    v7 = v5 - v4;
    v15 = (v2[1] - *v2) >> 2;
    if ( v7 <= v15 )
    {
      v8 = sub_F94700(v4, a2[1], v6);
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
      sub_F94700(*a2, v12, v6);
      v10 = sub_F734F0(v12, v3[1], v2[1]);
LABEL_10:
      v2[1] = v10;
      return v2;
    }
    if ( v6 )
    {
      sub_F72BC0(v6, v2[1]);
      j__free(*v2);
    }
    if ( sub_F7F930(v2, v3[1] - *v3) )
    {
      v17 = 0;
      v10 = sub_F734F0(*v3, v3[1], *v2);
      goto LABEL_10;
    }
  }
  return v2;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F73A50) --------------------------------------------------------
_bstr_t *__thiscall sub_F73A50(_bstr_t *this, _bstr_t *a2)
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

//----- (00F73A80) --------------------------------------------------------
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

//----- (00F73B40) --------------------------------------------------------
int __thiscall sub_F73B40(int **this)
{
  int result; // eax

  if ( *this )
    result = **this;
  else
    result = 0;
  return result;
}

//----- (00F73B50) --------------------------------------------------------
_bstr_t *__cdecl _bstr_t::operator+(_bstr_t *a1, OLECHAR *psz, _bstr_t *a2)
{
  _bstr_t::_bstr_t(a1, psz);
  _bstr_t::operator+=(a1, a2);
  return a1;
}

//----- (00F73BC0) --------------------------------------------------------
_bstr_t *__thiscall _bstr_t::operator+(Data_t_bstr_t **this, _bstr_t *a2, _bstr_t *a3)
{
  Data_t_bstr_t *v3; // eax

  v3 = *this;
  a2->m_Data = *this;
  if ( v3 )
    InterlockedIncrement(&v3->m_RefCount);
  _bstr_t::operator+=(a2, a3);
  return a2;
}

//----- (00F73C30) --------------------------------------------------------
BOOL __thiscall sub_F73C30(BSTR **this, BSTR **a2)
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

//----- (00F73CB0) --------------------------------------------------------
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

//----- (00F73D40) --------------------------------------------------------
char __cdecl sub_F73D40(int a1, const wchar_t **a2, OLECHAR **a3, OLECHAR **a4, OLECHAR **a5, const wchar_t **a6, void **a7, _DWORD *a8)
{
  OLECHAR **v8; // esi
  void *v10; // esi
  wchar_t *v11; // eax
  wchar_t *v12; // edi
  const wchar_t *v13; // eax
  wchar_t *v14; // eax
  int v15; // eax
  WCHAR **v16; // esi
  const wchar_t **v17; // eax
  const wchar_t *v18; // edi
  const wchar_t *v19; // ecx
  WCHAR **v20; // esi
  WCHAR **v21; // esi
  const wchar_t **v22; // eax
  wchar_t *v23; // ST14_4
  WCHAR *v24; // ST10_4
  wchar_t *v25; // eax
  WCHAR *v26; // eax
  WCHAR *v27; // esi
  unsigned __int16 **v28; // eax
  int v29; // [esp+10h] [ebp-84h]
  OLECHAR **v30; // [esp+14h] [ebp-80h]
  int v31; // [esp+18h] [ebp-7Ch]
  OLECHAR **v32; // [esp+1Ch] [ebp-78h]
  wchar_t *v33; // [esp+20h] [ebp-74h]
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
  if ( byte_1063860 )
    ExitThread(0);
  if ( !_wcsicmp(*a2, L"desktop.ini") )
    return 0;
  if ( dword_1063858 )
  {
    v10 = *a7;
    *a7 = _wcsdup(*a6);
    free(v10);
    v11 = malloc(2u);
    v12 = v11;
    v33 = v11;
    *v11 = 0;
    v39 = 0;
    v13 = &gszNullString;
    if ( *v34 )
      v13 = *v34;
    v14 = _wcsdup(v13);
    v15 = sub_F91290(v14, a7);
    if ( v15 != 2 )
    {
      if ( v15 )
      {
        if ( !**a7 )
          goto LABEL_24;
        v26 = _wcsdup(L"(Not Verified) ");
      }
      else
      {
        v26 = _wcsdup(L"(Verified) ");
      }
      v27 = v26;
      ppv2 = v26;
      v28 = PE_CopyStringEx(&ppv1, &ppv2, a7);
      sub_F72250(a7, v28);
      free(ppv1);
      free(v27);
      goto LABEL_24;
    }
    ppv2 = sub_F76700(*v34, 0, 0, &v38, &v29, 0);
    if ( ppv2 )
    {
      v16 = ppszText2;
      if ( !**ppszText2 )
      {
LABEL_18:
        v23 = _wcsdup(v12);
        v24 = ppv2;
        v25 = _wcsdup(*v34);
        sub_F911B0(v25, v24, v23);
LABEL_24:
        v39 = -1;
        free(v12);
        v8 = v34;
        goto LABEL_25;
      }
      sub_F72250(&v33, ppszText2);
      v17 = PE_CopyString2(&ppszText2, L"(Not verified) ", v16);
      sub_F72250(a7, v17);
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
      sub_F72250(&v33, &ppszText2);
      free(v20);
      if ( v38 )
        v18 = v38;
      v21 = _wcsdup(v18);
      ppszText2 = v21;
      v22 = PE_CopyString2(&ppv1, L"(Verified) ", &ppszText2);
      sub_F72250(a7, v22);
      free(ppv1);
      free(v21);
    }
    v12 = v33;
    goto LABEL_18;
  }
LABEL_25:
  if ( dword_10648D4 )
  {
    if ( wcsncmp(*v8, L"File not found: ", 0x10u) )
      sub_F91590(1, v31, *v30, *v32, *v8, 0);
  }
  return 1;
}
// 1063858: using guessed type int dword_1063858;
// 1063860: using guessed type char byte_1063860;
// 10648D4: using guessed type int dword_10648D4;

//----- (00F73FF0) --------------------------------------------------------
int __cdecl sub_F73FF0(int a1, int a2, void *ppv1, int a4, WCHAR **ppv3, int a6, int a7)
{
  WCHAR *v7; // edi
  unsigned __int16 **v8; // eax
  OLECHAR *v9; // esi
  OLECHAR *v10; // ecx
  int result; // eax
  void *v12; // esi

  if ( !(dword_1064C48 & 1) )
  {
    dword_1064C48 |= 1u;
    *&gpszText1 = malloc(2u);
    **&gpszText1 = 0;
    atexit(sub_102A2E0);
  }
  if ( ppv1 == -1 )
  {
    v12 = *&gpszText1;
    *&gpszText1 = _wcsdup(*ppv3);
    free(v12);
    result = 0;
  }
  else
  {
    v7 = malloc(2u);
    *v7 = 0;
    if ( a4 == 9 )
    {
      v8 = PE_CopyStringEx(&ppv1, &gpszText1, ppv3);
      v9 = _wcsdup(*v8);
      free(v7);
      free(ppv1);
    }
    else
    {
      v9 = _wcsdup(*a6);
      free(v7);
    }
    if ( gbFlagsInSub_40B220 == 1 )
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
    sub_FABF00(v10, *a7, v9);
    free(v9);
    result = 0;
  }
  return result;
}
// 102D5D8: using guessed type wchar_t aLocalSystem[13];
// 10631C0: using guessed type int gbFlagsInSub_40B220;
// 1064C48: using guessed type int dword_1064C48;

//----- (00F74130) --------------------------------------------------------
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
  tagKeyName *pszDefaultUserName; // esi
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
    if ( !PE_LoadKey(hSubKey, 0, &szDefaultUserName) )
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
      while ( !PE_LoadKey(hSubKey, dwIndex, &szDefaultUserName) );
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
// 102CA8C: using guessed type wchar_t aSystem_0[7];
// 1031FCC: using guessed type wchar_t aDefault[9];
// 1031FE0: using guessed type wchar_t aNtAuthority[13];
// 1032008: using guessed type wchar_t aConfig[7];
// 10631CA: using guessed type char gbRestorePrivilegeFailed;

//----- (00F74650) --------------------------------------------------------
char BackendThreadProc()
{
  const wchar_t **v0; // eax
  wchar_t *v1; // esi
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
  sub_F7B220(0xFFFFFFFF, 1u);
  sub_F7B220(0xFFFFFFFF, 0);
  pBuffer = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
  index = 0;
  nCount = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  if ( nCount )
  {
    do
    {
      LOBYTE(nCount) = sub_F7F610(0, gpAccountInfo, pBuffer[index]->nMenuID);
      if ( !nCount )
        break;
      sub_F7B220(0xFFFFFFFF, 0);
      ++index;
      pBuffer = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
      nCount = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
              - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    }
    while ( index < nCount );
  }
  return nCount;
}

//----- (00F74730) --------------------------------------------------------
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

//----- (00F747C0) --------------------------------------------------------
errno_t __cdecl sub_F747C0(wchar_t *Src, wchar_t *Dst, rsize_t SizeInWords)
{
  return wcscpy_s(Dst, SizeInWords, Src);
}

//----- (00F747E0) --------------------------------------------------------
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

//----- (00F74890) --------------------------------------------------------
int __cdecl sub_F74890(int a1, wchar_t *a2)
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
    if ( sub_F81040(v10) != -1 )
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
      v18 = sub_F81040(v10);
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

//----- (00F74AC0) --------------------------------------------------------
int __cdecl sub_F74AC0(int a1, wchar_t *psz)
{
  WCHAR *v2; // edi
  wchar_t *v3; // esi
  wchar_t *v4; // ebx
  unsigned int v5; // kr04_4
  const wchar_t *v6; // ecx
  WCHAR *v7; // esi
  const wchar_t **v8; // eax
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
  if ( !wcsncmp(v3, v4, wcslen(v4)) && sub_F81040(psz) == -1 )
  {
    v5 = wcslen(gszProgameFilesX86EnvValueValue);
    v6 = &gszNullString;
    if ( &psz[v5] )
      v6 = &psz[v5];
    v7 = _wcsdup(v6);
    ppszText2 = v7;
    v8 = PE_CopyString2(&pszResult, gszProgramW6432EnvValue, &ppszText2);
    v12 = v2;
    v2 = _wcsdup(*v8);
    ppszText2 = v2;
    free(v12);
    free(pszResult);
    free(v7);
    if ( sub_F81040(v2) != -1 )
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

//----- (00F74C50) --------------------------------------------------------
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

//----- (00F74ED0) --------------------------------------------------------
signed int sub_F74ED0()
{
  return -1;
}

//----- (00F74EE0) --------------------------------------------------------
int __cdecl sub_F74EE0(int a1, int a2, int a3, int a4)
{
  wchar_t *v4; // ecx
  wchar_t *v6; // [esp-4h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-4h]

  v6 = v4;
  v7 = 0;
  sub_F770E0(&v6, a2, a3, a4);
  sub_F784A0(a1, v6);
  return a1;
}

//----- (00F74F20) --------------------------------------------------------
int __cdecl sub_F74F20(int a1, int a2, wchar_t *a3)
{
  _WORD *v3; // eax
  wchar_t *v5; // [esp-4h] [ebp-2Ch]
  int v6; // [esp+4h] [ebp-24h]
  int v7; // [esp+8h] [ebp-20h]
  int v8; // [esp+Ch] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-18h]
  int v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v10 = 0;
  v3 = malloc(2u);
  v6 = v3;
  v7 = 0;
  v8 = 0;
  *v3 = 0;
  v9 = 0;
  v11 = 0;
  sub_F77040(a3, &v6);
  sub_F770E0(&v5, a2, &v6, 0);
  sub_F784A0(a1, v5);
  sub_F721F0(&v6);
  return a1;
}

//----- (00F74FB0) --------------------------------------------------------
wchar_t **__cdecl sub_F74FB0(WCHAR **ppszArgs, HWND hWndIn, LPCWSTR lpszFileName)
{
  WCHAR **v3; // ebx
  wchar_t *v4; // esi
  wchar_t *pszArgs; // edi
  wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *pszPath; // ebx
  wchar_t *v9; // eax
  const wchar_t **v10; // eax
  WCHAR *v11; // ebx
  wchar_t *v12; // eax
  wchar_t **v13; // eax
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
          sub_F72170(&ppv);
          LOBYTE(v25) = 2;
          v9 = _wcsdup(pszPath);
          v10 = sub_F74AC0(&pszFileName, v9);
          sub_F72250(&a2, v10);
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
            CopyStringToString(&ppv, pszArgs, 0x7FFFFFFFu, 0);
            sub_F80530(&theVector, &a2);
            sub_F80530(&theVector, &v20);
            v13 = sub_F770E0(&pszFileName, hWnd, &ppv, 0);
            sub_F72250(&a2, v13);
            free(pszFileName);
            v4 = a2;
            pszArgs = v20;
          }
          LOBYTE(v25) = 1;
          sub_F721F0(&ppv);
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
// 1047B5C: using guessed type GUID CLSID_IPersistFile;

//----- (00F752B0) --------------------------------------------------------
int __cdecl sub_F752B0(int a1, wchar_t *psz)
{
  HMODULE v2; // eax
  FARPROC v3; // eax
  const wchar_t *v4; // ecx
  Data_t_bstr_t *v6; // edi
  BSTR v7; // eax
  _WORD *v8; // esi
  BSTR v9; // eax
  const unsigned __int16 *v10; // eax
  int v11; // eax
  const unsigned __int16 *v12; // eax
  int v13; // eax
  wchar_t **v14; // eax
  wchar_t *v15; // eax
  wchar_t *v16; // eax
  const wchar_t *v17; // eax
  const wchar_t *v18; // eax
  _WORD *v19; // [esp+14h] [ebp-18h]
  _bstr_t v20; // [esp+18h] [ebp-14h]
  _bstr_t bstrText; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+28h] [ebp-4h]

  if ( dword_1064C40 & 1 )
  {
    v3 = GetLongPathNameW_0;
  }
  else
  {
    dword_1064C40 |= 1u;
    v2 = LoadLibraryW(L"kernel32.dll");
    v3 = GetProcAddress(v2, "GetLongPathNameW");
    GetLongPathNameW_0 = v3;
  }
  if ( !v3 )
  {
    v4 = &gszNullString;
    if ( psz )
      v4 = psz;
    *a1 = _wcsdup(v4);
    return a1;
  }
  sub_F77AB0(&gKeyNameMap, &bstrText, psz);
  v22 = 0;
  if ( !byte_1063860 )
  {
    v6 = bstrText.m_Data;
    if ( bstrText.m_Data )
      v7 = bstrText.m_Data->m_wstr;
    else
      v7 = 0;
    v20.m_Data = GetLongPathNameW_0(v7, 0, 0);
    v8 = malloc(2u);
    *v8 = 0;
    LOBYTE(v22) = 1;
    if ( !byte_1063860 )
    {
      v8 = realloc(v8, 2 * v20.m_Data + 2);
      v19 = v8;
      if ( v8 )
        memset(v8, 0, 2 * v20.m_Data + 2);
      v9 = v6 ? v6->m_wstr : 0;
      if ( GetLongPathNameW_0(v9, v8, v20.m_Data) )
      {
        if ( v6 )
          v10 = v6->m_wstr;
        else
          v10 = 0;
        v11 = wcscmp(v8, v10);
        if ( v11 )
          v11 = -(v11 < 0) | 1;
        if ( v11 )
        {
          if ( v6 )
            v12 = v6->m_wstr;
          else
            v12 = 0;
          v13 = wcscmp(psz, v12);
          if ( v13 )
            v13 = -(v13 < 0) | 1;
          if ( v13 )
          {
            v14 = *sub_F75DE0(&gKeyNameMap, &v20, v8);
            if ( v14 )
              v15 = *v14;
            else
              v15 = 0;
            sub_F72280(&v19, v15);
            _bstr_t::_Free(&v20);
            v8 = v19;
          }
          v16 = _wcsdup(v8);
        }
        else
        {
          v17 = &gszNullString;
          if ( psz )
            v17 = psz;
          v16 = _wcsdup(v17);
        }
        *a1 = v16;
        free(v8);
        _bstr_t::_Free(&bstrText);
        return a1;
      }
    }
    free(v8);
  }
  v18 = &gszNullString;
  if ( psz )
    v18 = psz;
  *a1 = _wcsdup(v18);
  _bstr_t::_Free(&bstrText);
  return a1;
}
// 1063860: using guessed type char byte_1063860;
// 1064C3C: using guessed type int (__stdcall *GetLongPathNameW_0)(_DWORD, _DWORD, _DWORD);
// 1064C40: using guessed type int dword_1064C40;

//----- (00F75520) --------------------------------------------------------
int __cdecl sub_F75520(int a1, wchar_t *psz, int a3)
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
  if ( !sub_F76090(v4) || (v5 = 1, v14 = 1, ((*(a3 + 8) - *(a3 + 4)) >> 2) <= 1) )
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
    if ( !sub_F75FD0(v8, v7) || _wcsicmp(*(v13 + *(a3 + 4)), L"start") )
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

//----- (00F756C0) --------------------------------------------------------
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
// 102CEA8: using guessed type wchar_t aSystem32[10];

//----- (00F75860) --------------------------------------------------------
char __cdecl sub_F75860(wchar_t **a1, __int16 a2, const wchar_t **a3, char a4)
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
  const wchar_t **v27; // eax
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
        v26 = sub_F81040(*a3);
        if ( v26 != -1 && !(v26 & 0x10)
          || (v27 = PE_CopyString(&ppv, a3, L".exe"),
              v28 = *a3,
              *a3 = _wcsdup(*v27),
              free(v28),
              free(ppv),
              v29 = sub_F81040(*a3),
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

//----- (00F75BB0) --------------------------------------------------------
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

//----- (00F75C70) --------------------------------------------------------
int __cdecl sub_F75C70(int a1, wchar_t *a2)
{
  wchar_t *v2; // eax
  wchar_t *v3; // esi
  unsigned int v4; // kr04_4
  wchar_t *v5; // esi
  const wchar_t **v6; // eax
  void *v7; // edi
  WCHAR *pszResult; // [esp+10h] [ebp-20h]
  WCHAR *ppv; // [esp+14h] [ebp-1Ch]
  HKEY__ hKey; // [esp+18h] [ebp-18h]
  int v12; // [esp+1Ch] [ebp-14h]
  int ImageBase; // [esp+20h] [ebp-10h]
  int v14; // [esp+2Ch] [ebp-4h]

  v14 = 1;
  *a1 = _wcsdup(a2);
  v2 = a2;
  v12 = 1;
  if ( *a2 && Wow64DisableWow64FsRedirection )
  {
    v3 = _wcsdup(L"\\");
    hKey.unused = v3;
    PE_CopyString2(&pszResult, gszProgramW6432EnvValue, &hKey);
    LOBYTE(v14) = 2;
    free(v3);
    Wow64DisableWow64FsRedirection(&ImageBase);
    if ( !ImageBase && !_wcsnicmp(a2, &gSystemDirInfo, wcslen(&gSystemDirInfo)) )
    {
      v4 = wcslen(&gSystemDirInfo);
      v5 = _wcsdup(gSystemDirInfo.szSystemWow64Directory);
      hKey.unused = v5;
      v6 = PE_CopyString(&ppv, &hKey, &a2[v4]);
      v7 = *a1;
      *a1 = _wcsdup(*v6);
      free(v7);
      free(ppv);
      free(v5);
    }
    Wow64RevertWow64FsRedirection(ImageBase);
    free(pszResult);
    v2 = a2;
  }
  free(v2);
  return a1;
}

//----- (00F75DE0) --------------------------------------------------------
int __thiscall sub_F75DE0(int **this, int a2, OLECHAR *psz)
{
  OLECHAR *v3; // ebx
  int v4; // esi
  OLECHAR **v5; // eax
  OLECHAR *v6; // eax
  UINT v7; // edi
  _DWORD *v8; // eax
  const wchar_t *v9; // eax
  int v10; // eax
  int v11; // eax
  int j; // eax
  int i; // eax
  BSTR *v14; // eax
  BSTR *v15; // esi
  BSTR v16; // eax
  OLECHAR *v17; // eax
  OLECHAR *v18; // esi
  int result; // eax
  int **v20; // [esp+14h] [ebp-10h]

  v20 = this;
  v3 = psz;
  v4 = **this;
  if ( **this == *this )
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
        _com_issue_error(-2147024882);
    }
    else
    {
      v15 = 0;
    }
    result = a2;
    *a2 = v15;
    if ( !v15 )
      _com_issue_error(-2147024882);
    return result;
  }
  while ( 1 )
  {
    if ( *(v4 + 24) )
      goto LABEL_13;
    v5 = *(v4 + 28);
    if ( !v5 )
      break;
    v6 = *v5;
    if ( !v6 )
      break;
    v7 = SysStringLen(v6);
    if ( !v7 )
      goto LABEL_28;
    v8 = *(v4 + 28);
    v9 = (v8 ? *v8 : 0);
    if ( !_wcsnicmp(v3, v9, v7) )
    {
      v10 = v3[v7];
      if ( !v10 || v10 == 92 )
        goto LABEL_28;
    }
    this = v20;
LABEL_13:
    if ( !*(v4 + 13) )
    {
      v11 = *(v4 + 8);
      if ( *(v11 + 13) )
      {
        for ( i = *(v4 + 4); !*(i + 13); i = *(i + 4) )
        {
          if ( v4 != *(i + 8) )
            break;
          v4 = i;
        }
        v4 = i;
      }
      else
      {
        v4 = *(v4 + 8);
        for ( j = *v11; !*(j + 13); j = *j )
          v4 = j;
      }
    }
    if ( v4 == *this )
      goto LABEL_23;
  }
  v7 = 0;
LABEL_28:
  sub_F785A0(&psz, v3, v7, (v4 + 20));
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

//----- (00F75FD0) --------------------------------------------------------
char __cdecl sub_F75FD0(wchar_t *a1, wchar_t *a2)
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

//----- (00F76090) --------------------------------------------------------
char __cdecl sub_F76090(wchar_t *psz)
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
  if ( !sub_F75FD0(v2, v1) )
  {
    v3 = _wcsdup(L"RUNDLL");
    v4 = _wcsdup(psz);
    if ( !sub_F75FD0(v4, v3) )
    {
      v5 = _wcsdup(L"CSCRIPT");
      v6 = _wcsdup(psz);
      if ( !sub_F75FD0(v6, v5) )
      {
        v7 = _wcsdup(L"WSCRIPT");
        v8 = _wcsdup(psz);
        if ( !sub_F75FD0(v8, v7) )
        {
          v9 = _wcsdup(L"REGSVR32");
          v10 = _wcsdup(psz);
          if ( !sub_F75FD0(v10, v9) )
          {
            v11 = _wcsdup(L"POWERSHELL");
            v12 = _wcsdup(psz);
            if ( !sub_F75FD0(v12, v11) )
            {
              v13 = _wcsdup(L"CMD");
              v14 = _wcsdup(psz);
              if ( !sub_F75FD0(v14, v13) )
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
  v22 = sub_F91290(v21, &v33);
  if ( v22 == 2 )
  {
    v34 = sub_F76700(psz, 0, 0, &v35, &v31, 0);
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
    v22 = sub_F911B0(v28, v27, v26);
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

//----- (00F763B0) --------------------------------------------------------
char __cdecl sub_F763B0(wchar_t *a1)
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

//----- (00F76440) --------------------------------------------------------
int __thiscall std::map<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>>::_Try_emplace<wchar_t const * const &,>(std__tree *this, tagKeyName **a2, tagKeyName *bstrValue, HKEY hRootKey, OLECHAR *lpszKey)
{
  OLECHAR *KeyId; // ebx
  std__Tree_node *pNode; // esi
  OLECHAR **v7; // eax
  OLECHAR *v8; // eax
  UINT v9; // edi
  std__Tree_node *v10; // eax
  const wchar_t *v11; // eax
  int v12; // eax
  std__Tree_node_For__bstr_t *v13; // eax
  std__Tree_node *j; // eax
  std__Tree_node *i; // eax
  tagKeyName *v16; // eax
  tagKeyName *v17; // esi
  Data_t_bstr_t *v18; // eax
  Data_t_bstr_t *v19; // eax
  tagKeyName *v20; // esi
  tagKeyName *result; // eax
  std__tree *pThis; // [esp+14h] [ebp-10h]

  pThis = this;
  KeyId = lpszKey;
  pNode = this->_Mypair._Myval2._Myhead->_Left;
  if ( this->_Mypair._Myval2._Myhead->_Left == this->_Mypair._Myval2._Myhead )
  {
LABEL_23:
    bstrValue->bstrText1.m_Data = hRootKey;
    v16 = operator new(0xCu);
    v17 = v16;
    bstrValue = v16;
    if ( v16 )
    {
      v16->bstrText2.m_Data = 0;
      v16->dwValue = 1;
      v18 = SysAllocString(KeyId);
      v17->bstrText1.m_Data = v18;
      if ( !v18 && KeyId )
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
      v17 = 0;
    }
    result = a2;
    *a2 = v17;
    if ( !v17 )
      _com_issue_error(E_OUTOFMEMORY);
    return result;
  }
  while ( 1 )
  {
    if ( pNode[1]._Left != hRootKey )
      goto LABEL_13;
    v7 = pNode[1]._Parent;
    if ( !v7 )
      break;
    v8 = *v7;
    if ( !v8 )
      break;
    v9 = SysStringLen(v8);
    if ( !v9 )
      goto LABEL_28;
    v10 = pNode[1]._Parent;
    v11 = (v10 ? v10->_Left : 0);
    if ( !_wcsnicmp(KeyId, v11, v9) )
    {
      v12 = KeyId[v9];
      if ( !v12 || v12 == '\\' )
        goto LABEL_28;
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
  v9 = 0;
LABEL_28:
  bstrValue->bstrText1.m_Data = pNode[1]._Right;
  sub_F785A0(&bstrValue, KeyId, v9, &pNode[1]._Color);
  v19 = bstrValue;
  *a2 = bstrValue;
  if ( v19 )
  {
    InterlockedIncrement(&v19->m_RefCount);
    v20 = bstrValue;
    if ( bstrValue )
    {
      if ( !InterlockedDecrement(&bstrValue->dwValue) && v20 )
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
  return a2;
}

//----- (00F76640) --------------------------------------------------------
HANDLE __stdcall sub_F76640(OLECHAR *lpszKeyName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
  tagKeyName *KeyName; // esi
  tagKeyName *v8; // ebx
  HANDLE v9; // edi

  sub_F77AB0(&gKeyNameMap, &lpszKeyName, lpszKeyName);
  KeyName = lpszKeyName;
  if ( lpszKeyName )
    v8 = *lpszKeyName;
  else
    v8 = 0;
  v9 = CreateFileW(
         v8,
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
           v8,
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

//----- (00F76700) --------------------------------------------------------
LONG __cdecl sub_F76700(OLECHAR *psz, int a2, int a3, int a4, int a5, int a6)
{
  Data_t_bstr_t *v6; // esi
  const WCHAR *v7; // eax
  LONG v8; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_F77AB0(&gKeyNameMap, &bstrText, psz);
  v6 = bstrText.m_Data;
  if ( bstrText.m_Data )
    v7 = bstrText.m_Data->m_wstr;
  else
    v7 = 0;
  v8 = sub_F99BB0(v7, a2, 0, 0, a3, a5, a4, 0, 0, 0, 0, a6, -1);
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
  return v8;
}

//----- (00F767A0) --------------------------------------------------------
int __cdecl PE_OpenKey(HKEY hRootKey, tagKeyName *lpszKeyName, LONG CreateOptions, DWORD DesiredAccess, PHKEY KeyHandle)
{
  Data_t_bstr_t *v5; // esi
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
  _bstr_t bstrUserName; // [esp+34h] [ebp-20h]
  _bstr_t bstrKeyName; // [esp+38h] [ebp-1Ch]
  _bstr_t v30; // [esp+3Ch] [ebp-18h]
  _bstr_t v31; // [esp+40h] [ebp-14h]
  _bstr_t v32; // [esp+44h] [ebp-10h]
  tagKeyName KeyName; // [esp+48h] [ebp-Ch]

  v5 = 0;
  v32.m_Data = 0;
  KeyName.dwValue = 0;
  std::map<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>>::_Try_emplace<wchar_t const * const &,>(
    &gKeyNameMap,
    &lpszKeyName,
    &hRootKey,
    hRootKey,
    lpszKeyName);
  RootDirectory = hRootKey;
  v7 = lpszKeyName;
  LOBYTE(KeyName.dwValue) = 1;
  if ( hRootKey != HKEY_LOCAL_MACHINE )
  {
    if ( hRootKey == HKEY_CURRENT_USER )
    {
      _bstr_t::_bstr_t(&hRootKey, L"\\");
      LOBYTE(KeyName.dwValue) = 2;
      v10 = _bstr_t::_bstr_t(&bstrUserName, gpAccountInfo->szUserName);
      LOBYTE(KeyName.dwValue) = 3;
      v11 = _bstr_t::operator+(&bstrKeyName, L"\\Registry\\User\\", v10);
      LOBYTE(KeyName.dwValue) = 4;
      v12 = _bstr_t::operator+(&v11->m_Data, &v30, &hRootKey);
      LOBYTE(KeyName.dwValue) = 5;
      v13 = _bstr_t::operator+(&v12->m_Data, &v31, &lpszKeyName);
      if ( &v32 != v13 )
      {
        _bstr_t::_Free(&v32);
        v5 = v13->m_Data;
        v32.m_Data = v5;
        if ( v5 )
          InterlockedIncrement(&v5->m_RefCount);
      }
      _bstr_t::_Free(&v31);
      _bstr_t::_Free(&v30);
      _bstr_t::_Free(&bstrKeyName);
      _bstr_t::_Free(&bstrUserName);
      LOBYTE(KeyName.dwValue) = 1;
      _bstr_t::_Free(&hRootKey);
      RootDirectory = 0;
      if ( v5 )
      {
        pszObjectName = v5->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( hRootKey == HKEY_CLASSES_ROOT )
    {
      v14 = _bstr_t::operator+(&hRootKey, L"\\Registry\\Machine\\Software\\Classes\\", &lpszKeyName);
      if ( &v32 != v14 )
      {
        _bstr_t::_Free(&v32);
        v5 = v14->m_Data;
        v32.m_Data = v5;
        if ( v5 )
          InterlockedIncrement(&v5->m_RefCount);
      }
      _bstr_t::_Free(&hRootKey);
      RootDirectory = 0;
      if ( v5 )
      {
        pszObjectName = v5->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( hRootKey == HKEY_USERS )
    {
      v15 = _bstr_t::operator+(&hRootKey, L"\\Registry\\User\\", &lpszKeyName);
      if ( &v32 != v15 )
      {
        _bstr_t::_Free(&v32);
        v5 = v15->m_Data;
        v32.m_Data = v5;
        if ( v5 )
          InterlockedIncrement(&v5->m_RefCount);
      }
      _bstr_t::_Free(&hRootKey);
      RootDirectory = 0;
      if ( v5 )
      {
        pszObjectName = v5->m_wstr;
        goto LABEL_28;
      }
    }
    else if ( lpszKeyName )
    {
      pszObjectName = lpszKeyName->bstrText1.m_Data;
      goto LABEL_28;
    }
LABEL_27:
    pszObjectName = 0;
    goto LABEL_28;
  }
  v8 = _bstr_t::operator+(&hRootKey, L"\\Registry\\Machine\\", &lpszKeyName);
  if ( &v32 != v8 )
  {
    _bstr_t::_Free(&v32);
    v5 = v8->m_Data;
    v32.m_Data = v5;
    if ( v5 )
      InterlockedIncrement(&v5->m_RefCount);
  }
  _bstr_t::_Free(&hRootKey);
  RootDirectory = 0;
  if ( !v5 )
    goto LABEL_27;
  pszObjectName = v5->m_wstr;
LABEL_28:
  v16 = pszObjectName;
  hRootKey = (pszObjectName + 1);
  do
  {
    v17 = *v16;
    v16 += 2;
  }
  while ( v17 );
  nLength = (v16 - hRootKey) >> 1;
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
  if ( v5 && !v23(&v5->m_RefCount) )
  {
    if ( v5->m_wstr )
    {
      SysFreeString(v5->m_wstr);
      v5->m_wstr = 0;
    }
    if ( v5->m_str )
    {
      j_j__free(v5->m_str);
      v5->m_str = 0;
    }
    j__free(v5);
  }
  return dwError;
}

//----- (00F76B30) --------------------------------------------------------
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

//----- (00F76CC0) --------------------------------------------------------
char __cdecl sub_F76CC0(std__List *a1, int a2)
{
  const wchar_t ***v2; // ebx
  void *v3; // esi
  int v4; // ecx
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
  sub_F76DD0(a1, 0, &v8, 0);
  v2 = v8;
  v3 = *a2;
  if ( (a2a - v8) & 0xFFFFFFF0 )
  {
    *a2 = _wcsdup(*v8);
    free(v3);
    sub_F738F0((a2 + 4), v2 + 1);
    result = 1;
  }
  else
  {
    *a2 = _wcsdup(&gszNullString);
    free(v3);
    v4 = a2;
    v5 = *(a2 + 8);
    v6 = *(a2 + 4);
    if ( v6 != v5 )
    {
      do
      {
        free(*v6);
        ++v6;
      }
      while ( v6 != v5 );
      v4 = a2;
    }
    *(v4 + 8) = *(v4 + 4);
    result = 0;
  }
  v11 = result;
  if ( v2 )
  {
    sub_F72BF0(v2, a2a);
    j__free(v2);
    result = v11;
  }
  return result;
}

//----- (00F76DD0) --------------------------------------------------------
void __cdecl sub_F76DD0(wchar_t *a1, int a2, int a3, int a4)
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
  void *v20; // [esp+10h] [ebp-34h]
  std__vector v21; // [esp+14h] [ebp-30h]
  wchar_t *v22; // [esp+20h] [ebp-24h]
  wchar_t *v23; // [esp+24h] [ebp-20h]
  int v24; // [esp+28h] [ebp-1Ch]
  wchar_t *v25; // [esp+2Ch] [ebp-18h]
  wchar_t *v26; // [esp+30h] [ebp-14h]
  char v27; // [esp+37h] [ebp-Dh]
  int v28; // [esp+40h] [ebp-4h]

  sub_F72BF0(*a3, *(a3 + 4));
  *(a3 + 4) = *a3;
  v25 = a1;
  v20 = malloc(2u);
  v4 = 0;
  v21.baseclass_0._Mypair._Myval2._Myend = 0;
  v21.baseclass_0._Mypair._Myval2._Myfirst = 0;
  v5 = 0;
  *v20 = 0;
  v21.baseclass_0._Mypair._Myval2._Mylast = 0;
  v6 = a4;
  v28 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = malloc(2u);
      v26 = v7;
      *v7 = 0;
      LOBYTE(v28) = 1;
      LOBYTE(v24) = ((v5 - v4) & 0xFFFFFFFC) == 0;
      v8 = sub_F75860(&v25, a2, &v26, v24);
      v27 = v8;
      if ( v6 )
      {
        v23 = malloc(2u);
        *v23 = 0;
        v9 = v25;
        LOBYTE(v28) = 2;
        v22 = v25;
        v10 = sub_F75860(&v22, a4, &v23, v24);
        v11 = v23;
        if ( v10 )
        {
          if ( v27 )
          {
            if ( v22 < v9 )
            {
              v25 = v22;
              v12 = v26;
              v26 = _wcsdup(v23);
              free(v12);
            }
          }
          else
          {
            v27 = 1;
          }
        }
        LOBYTE(v28) = 1;
        free(v11);
        v4 = v21.baseclass_0._Mypair._Myval2._Myfirst;
        v8 = v27;
      }
      if ( !v8 )
      {
        v15 = v25;
        break;
      }
      if ( &v26 >= v5 || v4 > &v26 )
      {
        if ( v5 == v21.baseclass_0._Mypair._Myval2._Myend )
        {
          std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(&v21, 1u);
          v5 = v21.baseclass_0._Mypair._Myval2._Mylast;
        }
        if ( v5 )
        {
          v14 = _wcsdup(v26);
          goto LABEL_20;
        }
      }
      else
      {
        v13 = &v26 - v4;
        if ( v5 == v21.baseclass_0._Mypair._Myval2._Myend )
        {
          std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(&v21, 1u);
          v5 = v21.baseclass_0._Mypair._Myval2._Mylast;
          v4 = v21.baseclass_0._Mypair._Myval2._Myfirst;
        }
        if ( v5 )
        {
          v14 = _wcsdup(v4[v13]);
LABEL_20:
          *v5 = v14;
          goto LABEL_21;
        }
      }
LABEL_21:
      v15 = v25;
      v5 += 4;
      v21.baseclass_0._Mypair._Myval2._Mylast = v5;
      if ( *v25 == a2 )
        break;
      v6 = a4;
      if ( *v25 == a4 )
        break;
      v4 = v21.baseclass_0._Mypair._Myval2._Myfirst;
      free(v26);
    }
    v16 = v21.baseclass_0._Mypair._Myval2._Myfirst;
    if ( (v5 - v21.baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC )
    {
      v17 = v20;
      v18 = _wcsdup(a1);
      v20 = v18;
      free(v17);
      v15 = v25;
      v18[v25 - a1] = 0;
      sub_F80460(a3, &v20);
      v5 = v21.baseclass_0._Mypair._Myval2._Mylast;
      v16 = v21.baseclass_0._Mypair._Myval2._Myfirst;
    }
    if ( !*v15 )
      break;
    v25 = v15 + 1;
    for ( i = v16; i != v5; ++i )
      free(*i);
    v4 = v21.baseclass_0._Mypair._Myval2._Myfirst;
    v5 = v21.baseclass_0._Mypair._Myval2._Myfirst;
    a1 = v25;
    v6 = a4;
    v21.baseclass_0._Mypair._Myval2._Mylast = v21.baseclass_0._Mypair._Myval2._Myfirst;
    free(v26);
  }
  free(v26);
  sub_F721F0(&v20);
}

//----- (00F77040) --------------------------------------------------------
void __cdecl sub_F77040(wchar_t *a1, int a2)
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
  sub_F7F8D0(&a2a, a1);
  v6 = 0;
  v4 = *a2;
  *a2 = _wcsdup(a1);
  free(v4);
  sub_F80530((a2 + 4), &a2a);
  free(a2a);
}

//----- (00F770E0) --------------------------------------------------------
wchar_t **__cdecl sub_F770E0(wchar_t **a1, int a2, int a3, void *a4)
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
  wchar_t *v17; // edx
  unsigned int v18; // eax
  OLECHAR *v19; // esi
  LSTATUS v20; // eax
  wchar_t *v21; // eax
  wchar_t *v22; // ecx
  WCHAR *v23; // esi
  DWORD v24; // eax
  WCHAR *v25; // eax
  const wchar_t *v26; // eax
  const wchar_t **v27; // eax
  wchar_t *v28; // eax
  const wchar_t **v29; // eax
  const wchar_t **v30; // eax
  const wchar_t *v31; // eax
  LPCWSTR i; // ecx
  WCHAR *v33; // edi
  wchar_t *v34; // edi
  wchar_t *v35; // eax
  wchar_t *v36; // ecx
  wchar_t v37; // ax
  wchar_t *v38; // eax
  const wchar_t **v39; // eax
  wchar_t *v40; // esi
  wchar_t **v41; // eax
  void *v42; // esi
  wchar_t *v43; // eax
  void *v44; // ST24_4
  wchar_t *v45; // eax
  void *v46; // ST24_4
  WCHAR **v47; // [esp-8h] [ebp-8Ch]
  wchar_t *v48; // [esp-4h] [ebp-88h]
  int v49; // [esp+10h] [ebp-74h]
  _WORD *v50; // [esp+14h] [ebp-70h]
  std__vector v51; // [esp+18h] [ebp-6Ch]
  void *v52; // [esp+24h] [ebp-60h]
  wchar_t *v53; // [esp+28h] [ebp-5Ch]
  void *v54; // [esp+2Ch] [ebp-58h]
  wchar_t *a2a; // [esp+30h] [ebp-54h]
  HKEY hKey; // [esp+34h] [ebp-50h]
  int a1a; // [esp+38h] [ebp-4Ch]
  void *v58; // [esp+3Ch] [ebp-48h]
  void *v59; // [esp+40h] [ebp-44h]
  WCHAR *lpszText; // [esp+44h] [ebp-40h]
  WCHAR *pszResult; // [esp+48h] [ebp-3Ch]
  wchar_t *v62; // [esp+4Ch] [ebp-38h]
  int v63; // [esp+50h] [ebp-34h]
  WCHAR **v64; // [esp+54h] [ebp-30h]
  wchar_t **v65; // [esp+58h] [ebp-2Ch]
  OLECHAR *psz; // [esp+5Ch] [ebp-28h]
  wchar_t *ppv; // [esp+60h] [ebp-24h]
  DWORD nBufferLength; // [esp+64h] [ebp-20h]
  LPCWSTR lpFileName; // [esp+68h] [ebp-1Ch]
  size_t v70; // [esp+6Ch] [ebp-18h]
  int v71; // [esp+80h] [ebp-4h]

  a1a = a2;
  v4 = *(a3 + 8) - *(a3 + 4);
  v65 = a1;
  v63 = a3;
  pszResult = a4;
  LOBYTE(v54) = a4;
  v49 = 0;
  if ( !(v4 & 0xFFFFFFFC) )
  {
    *a1 = _wcsdup(L"<bad command>");
    return a1;
  }
  v58 = _wcsdup(**(a3 + 4));
  v71 = 0;
  lpFileName = malloc(2u);
  *lpFileName = 0;
  v6 = malloc(2u);
  v64 = v6;
  *v6 = 0;
  v7 = malloc(2u);
  v59 = v7;
  *v7 = 0;
  v8 = _wcsdup(**(a3 + 4));
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
  CopyStringToString(&lpFileName, L"\\", 0x7FFFFFFFu, 0);
  CopyStringToString(&lpFileName, v8 + 12, 0x7FFFFFFFu, 0);
  v10 = _wcsdup(lpFileName);
  v47 = v64;
LABEL_9:
  v11 = v10;
  v53 = v10;
  free(v47);
  v12 = _wcsdup(v11);
  v52 = v12;
  LOBYTE(v71) = 6;
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
  v64 = lpFileName;
  lpFileName = _wcsdup(*v16);
  free(v64);
  free(psz);
  v17 = malloc(2u);
  v70 = v17;
  v62 = v17;
  *v17 = 0;
  LOBYTE(v71) = 7;
  if ( !*lpFileName )
    goto LABEL_64;
  psz = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\");
  LOBYTE(v71) = 8;
  CopyStringToString(&psz, lpszText, 0x7FFFFFFFu, 0);
  v18 = TlsGetValue(gdwTlsIndex);
  v19 = psz;
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, v18 | 0x20019, &hKey) )
  {
    v20 = sub_F815A0(hKey, 0, &lpFileName);
    v48 = hKey;
    if ( !v20 )
    {
      RegCloseKey(v48);
      v21 = _wcsdup(lpFileName);
      *v65 = v21;
      free(v19);
      free(v70);
      free(v12);
      free(ppv);
      free(lpszText);
      free(v59);
      free(v11);
      free(lpFileName);
      free(v58);
      return v65;
    }
    RegCloseKey(v48);
  }
  v64 = _wcsdup(lpFileName);
  v62 = v64;
  free(v70);
  if ( pszResult || byte_1063860 )
  {
LABEL_36:
    v26 = lpFileName;
    if ( *lpFileName == 92 && lpFileName[1] != 92 )
    {
      wcsncpy_s(&v70, 3u, gszWindowsDirectory, 2u);
      v27 = PE_CopyString2(&pszResult, &v70, &lpFileName);
      nBufferLength = lpFileName;
      lpFileName = _wcsdup(*v27);
      free(nBufferLength);
      free(pszResult);
      v26 = lpFileName;
    }
    v48 = v22;
    nBufferLength = &v48;
    v28 = _wcsdup(v26);
    *nBufferLength = v28;
    v29 = sub_F75C70(&pszResult, v48);
    nBufferLength = lpFileName;
    lpFileName = _wcsdup(*v29);
    free(nBufferLength);
    free(pszResult);
    v48 = lpFileName;
    if ( byte_1063860 )
    {
      v70 = _wcsdup(v48);
      v62 = v70;
      free(v64);
    }
    else
    {
      v30 = sub_F752B0(&nBufferLength, v48);
      v70 = _wcsdup(*v30);
      v62 = v70;
      free(v64);
      free(nBufferLength);
    }
    _wcslwr(v70);
    LOBYTE(v71) = 7;
    free(v19);
    v7 = v59;
    v17 = v70;
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
      v48 = v63;
      v38 = _wcsdup(v17);
      v39 = sub_F75520(&nBufferLength, v38, v48);
      v40 = _wcsdup(*v39);
      a2a = v40;
      free(lpszText);
      free(nBufferLength);
      if ( wcslen(v40) )
      {
        v50 = malloc(2u);
        *v50 = 0;
        v51.baseclass_0._Mypair._Myval2._Myfirst = 0;
        v51.baseclass_0._Mypair._Myval2._Mylast = 0;
        v51.baseclass_0._Mypair._Myval2._Myend = 0;
        LOBYTE(v71) = 10;
        sub_F80530(&v51, &a2a);
        v41 = sub_F770E0(&v54, a1a, &v50, v54);
        v42 = v70;
        v70 = _wcsdup(*v41);
        free(v42);
        free(v54);
        sub_F721F0(&v50);
        v40 = a2a;
      }
      v43 = _wcsdup(v70);
      v44 = v70;
      *v65 = v43;
      free(v44);
      free(v12);
      free(ppv);
      free(v40);
      free(v59);
    }
    else
    {
      v45 = _wcsdup(&gszNullString);
      v46 = v70;
      *v65 = v45;
      free(v46);
      free(v12);
      free(ppv);
      free(lpszText);
      free(v7);
    }
    free(v11);
    free(lpFileName);
    free(v58);
    return v65;
  }
  while ( 1 )
  {
    v23 = _wcsdup(lpFileName);
    pszResult = v23;
    LOBYTE(v71) = 9;
    if ( wcsstr(lpFileName, L"..") )
    {
      v24 = GetFullPathNameW(lpFileName, 0, 0, 0);
      nBufferLength = v24;
      if ( v24 )
      {
        v70 = 2 * v24 + 2;
        v25 = realloc(v23, v70);
        v23 = v25;
        pszResult = v25;
        if ( v25 )
          memset(v25, 0, v70);
        GetFullPathNameW(lpFileName, nBufferLength, v23, 0);
      }
    }
    if ( !byte_1063860 )
    {
      if ( sub_F81150(a1a, gpszSystemPathInfo, v23, &ppv) )
      {
        if ( !byte_1063860 && !(sub_F81040(ppv) & 0x10) )
        {
          nBufferLength = lpFileName;
          lpFileName = _wcsdup(ppv);
          free(nBufferLength);
          LOBYTE(v71) = 8;
          free(v23);
          goto LABEL_35;
        }
      }
      else if ( !wcschr(v23, 0x2Fu) && wcslen(v23) > 3 && v23[wcslen(v23) - 4] != 46 )
      {
        nBufferLength = ppv;
        ppv = _wcsdup(v23);
        free(nBufferLength);
        CopyStringToString(&ppv, L".exe", 0x7FFFFFFFu, 0);
        if ( byte_1063860
          || sub_F81150(a1a, gpszSystemPathInfo, ppv, &lpFileName)
          || (nBufferLength = ppv,
              ppv = _wcsdup(v23),
              free(nBufferLength),
              CopyStringToString(&ppv, L".dll", 0x7FFFFFFFu, 0),
              !byte_1063860)
          && sub_F81150(a1a, gpszSystemPathInfo, ppv, &lpFileName) )
        {
          LOBYTE(v71) = 8;
          free(v23);
LABEL_35:
          v19 = psz;
          goto LABEL_36;
        }
      }
    }
    v31 = lpFileName;
    for ( i = lpFileName; *i == 32; ++i )
      ;
    if ( !byte_1063860 )
      break;
LABEL_48:
    if ( wcsrchr(v31, 0x20u) )
      *wcsrchr(lpFileName, 0x20u) = 0;
    LOBYTE(v71) = 8;
    free(v23);
    if ( byte_1063860 )
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
  CopyStringToString(&lpFileName, v64, 0x7FFFFFFFu, 0);
  v34 = _wcsdup(lpFileName);
  v62 = v34;
  free(v64);
  if ( sub_F81040(**(v63 + 4)) != -1 && sub_F81040(**(v63 + 4)) & 0x10 )
  {
    sub_F72250(&v62, *(v63 + 4));
    v34 = v62;
  }
  else if ( !byte_1063860 && !wcsncmp(**(v63 + 4), L"||", 2u) )
  {
    if ( sub_F81040((**(v63 + 4) + 4)) == -1 )
    {
      nBufferLength = lpFileName;
      lpFileName = _wcsdup(L"File not found: ");
      free(nBufferLength);
      CopyStringToString(&lpFileName, (**(v63 + 4) + 4), 0x7FFFFFFFu, 0);
      nBufferLength = v34;
      v34 = _wcsdup(lpFileName);
      free(nBufferLength);
    }
    else
    {
      sub_F72280(&v62, (**(v63 + 4) + 4));
      v34 = v62;
    }
  }
  v35 = _wcsdup(v34);
  *v65 = v35;
  free(v23);
  free(psz);
  free(v34);
  free(v52);
  free(ppv);
  free(lpszText);
  free(v59);
  free(v11);
  free(lpFileName);
  free(v58);
  return v65;
}
// 1063860: using guessed type char byte_1063860;

//----- (00F77AB0) --------------------------------------------------------
int __thiscall sub_F77AB0(std__tree *this, tagKeyName *KeyName, LPCWSTR lpszKey)
{
  std::map<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>>::_Try_emplace<wchar_t const * const &,>(
    this,
    KeyName,
    &lpszKey,
    0,
    lpszKey);
  return KeyName;
}

//----- (00F77AE0) --------------------------------------------------------
int __cdecl sub_F77AE0(DWORD dwMessageId)
{
  int result; // eax
  DWORD v2; // ebx
  FILE *v3; // edi
  const wchar_t *v4; // esi
  wchar_t v5; // cx
  HLOCAL v6; // ST04_4
  HANDLE v7; // eax
  FILE *v8; // edi
  const wchar_t *v9; // esi
  wchar_t v10; // ax
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-8h]
  CHAR Buffer[4]; // [esp+8h] [ebp-4h]

  result = FormatMessageA(0x1300u, 0, dwMessageId, 0x400u, Buffer, 0, 0);
  v2 = result;
  if ( result )
  {
    if ( byte_10631C9 )
    {
      v3 = (sub_1007B15() + 8);
      _fputwc_nolock(0x3Cu, v3);
      v4 = L"error";
      v5 = 101;
      do
      {
        _fputwc_nolock(v5, v3);
        v5 = v4[1];
        ++v4;
      }
      while ( v5 );
      _fputwc_nolock(0x3Eu, v3);
    }
    v6 = *Buffer;
    v7 = GetStdHandle(0xFFFFFFF4);
    WriteFile(v7, v6, v2, &NumberOfBytesWritten, 0);
    if ( byte_10631C9 )
    {
      v8 = (sub_1007B15() + 8);
      _fputwc_nolock(0x3Cu, v8);
      _fputwc_nolock(0x2Fu, v8);
      v9 = L"error";
      v10 = 101;
      do
      {
        _fputwc_nolock(v10, v8);
        v10 = v9[1];
        ++v9;
      }
      while ( v10 );
      _fputwc_nolock(0x3Eu, v8);
    }
    result = LocalFree(*Buffer);
  }
  return result;
}
// 102D008: using guessed type wchar_t aError[6];
// 10631C9: using guessed type char byte_10631C9;

//----- (00F77BE0) --------------------------------------------------------
unsigned __int16 **__cdecl sub_F77BE0(std__vector *ppszArg, HKEY hKey, LPCWSTR *lpszArg3, LPCWSTR *lpszArg4)
{
  _WORD *v4; // eax
  WCHAR **v5; // ebx
  const wchar_t *lpszKeyRoot; // eax
  std__vector *v7; // esi
  LPCWSTR *v8; // eax
  unsigned __int16 **v9; // eax
  WCHAR *v10; // edi
  WCHAR **v11; // eax
  WCHAR *ppv; // [esp+8h] [ebp-4h]

  v4 = malloc(2u);
  v5 = ppszArg;
  ppszArg->baseclass_0._Mypair._Myval2._Myfirst = v4;
  *v4 = 0;
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
  v7 = _wcsdup(lpszKeyRoot);
  ppszArg = v7;
  v8 = PE_CopyString(&ppv, &ppszArg, L"\\");
  v9 = PE_CopyStringEx(&hKey, v8, lpszArg3);
  v10 = *v5;
  *v5 = _wcsdup(*v9);
  free(v10);
  free(hKey);
  free(ppv);
  free(v7);
  if ( **lpszArg4 )
  {
    v11 = PE_CopyString2(&ppszArg, L"\\", lpszArg4);
    CopyStringToString(v5, *v11, 0x7FFFFFFFu, 0);
    free(ppszArg);
  }
  return v5;
}
// 102D5F4: using guessed type wchar_t asc_102D5F4[2];

//----- (00F77CC0) --------------------------------------------------------
void __cdecl sub_F77CC0(HWND a1, HWND a2)
{
  HWND v2; // edi
  WCHAR *v3; // ebx
  OLECHAR *v4; // esi
  wchar_t *v5; // eax
  wchar_t *v6; // esi
  const wchar_t **v7; // eax
  wchar_t *v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  wchar_t *v11; // eax
  wchar_t *v12; // esi
  const wchar_t **v13; // eax
  wchar_t *v14; // eax
  wchar_t *v15; // eax
  wchar_t *v16; // esi
  const wchar_t **v17; // eax
  wchar_t *v18; // eax
  HWND v19; // edi
  wchar_t *v20; // eax
  wchar_t *v21; // esi
  const wchar_t **v22; // eax
  wchar_t *v23; // eax
  wchar_t *v24; // esi
  const wchar_t **v25; // eax
  HWND v26; // ecx
  WCHAR *v27; // esi
  wchar_t *v28; // eax
  const wchar_t **v29; // eax
  HWND v30; // eax
  HANDLE v31; // eax
  HWND v32; // esi
  HWND v33; // esi
  signed int v34; // ebx
  bool v35; // zf
  HWND v36; // eax
  HWND v37; // esi
  int v38; // eax
  int v39; // eax
  wchar_t v40; // ax
  wchar_t *v41; // esi
  HWND v42; // ebx
  int v43; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+10h] [ebp-164h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+54h] [ebp-120h]
  wchar_t *v46; // [esp+64h] [ebp-110h]
  WCHAR *v47; // [esp+68h] [ebp-10Ch]
  HWND hWnd; // [esp+6Ch] [ebp-108h]
  HKEY phkResult; // [esp+70h] [ebp-104h]
  DWORD v50; // [esp+74h] [ebp-100h]
  WCHAR *ppstr; // [esp+78h] [ebp-FCh]
  HWND hWndParent; // [esp+7Ch] [ebp-F8h]
  DWORD dwProcessId; // [esp+80h] [ebp-F4h]
  HWND v54; // [esp+84h] [ebp-F0h]
  DEVMODEW DevMode; // [esp+88h] [ebp-ECh]
  int v56; // [esp+170h] [ebp-4h]

  hWnd = a1;
  hWndParent = a2;
  v46 = 0;
  v2 = malloc(2u);
  v54 = v2;
  *v2 = 0;
  v56 = 0;
  v3 = malloc(2u);
  v47 = v3;
  *v3 = 0;
  v4 = malloc(2u);
  v50 = v4;
  *v4 = 0;
  LOBYTE(v56) = 2;
  DevMode.dmSize = 220;
  EnumDisplaySettingsW(0, 0xFFFFFFFF, &DevMode);
  if ( *hWndParent == 48 )
  {
    MessageBoxW(hWnd, L"The full name of the selected key or value is not available.", L"Process Explorer", 0x30u);
    goto LABEL_47;
  }
  if ( !wcsncmp(hWndParent, L"HKLM", 4u) )
  {
    v5 = _wcsdup(L"\\HKEY_LOCAL_MACHINE");
    v6 = v5;
    v54 = v5;
    v7 = PE_CopyString(&dwProcessId, &v54, hWndParent + 4);
    ppstr = v2;
    v8 = _wcsdup(*v7);
    v2 = v8;
    v54 = v8;
    free(ppstr);
    free(dwProcessId);
    free(v6);
    v9 = TlsGetValue(gdwTlsIndex);
    v10 = PE_OpenKey(ghLocalMachineKey, (hWndParent + 10), 0, v9 | 0x20019, &phkResult);
  }
  else if ( !wcsncmp(hWndParent, L"HKCU", 4u) )
  {
    v11 = _wcsdup(L"\\HKEY_CURRENT_USER");
    v12 = v11;
    dwProcessId = v11;
    v13 = PE_CopyString(&ppstr, &dwProcessId, hWndParent + 4);
    dwProcessId = v2;
    v14 = _wcsdup(*v13);
    v2 = v14;
    v54 = v14;
    free(dwProcessId);
    free(ppstr);
    free(v12);
    v10 = RegOpenKeyW(ghCurrentUserKey, hWndParent + 5, &phkResult);
  }
  else if ( !wcsncmp(hWndParent, L"HKCC", 4u) )
  {
    v15 = _wcsdup(L"\\HKEY_CURRENT_CONFIG");
    v16 = v15;
    dwProcessId = v15;
    v17 = PE_CopyString(&ppstr, &dwProcessId, hWndParent + 4);
    dwProcessId = v2;
    v18 = _wcsdup(*v17);
    v2 = v18;
    v54 = v18;
    free(dwProcessId);
    free(ppstr);
    free(v16);
    v10 = RegOpenKeyW(HKEY_CURRENT_CONFIG, hWndParent + 5, &phkResult);
  }
  else
  {
    v19 = hWndParent;
    if ( !wcsncmp(hWndParent, L"HKCR", 4u) )
    {
      v20 = _wcsdup(L"\\HKEY_CLASSES_ROOT");
      v21 = v20;
      dwProcessId = v20;
      v22 = PE_CopyString(&ppstr, &dwProcessId, hWndParent + 4);
      sub_F72250(&v54, v22);
      free(ppstr);
      free(v21);
      v10 = RegOpenKeyW(HKEY_CLASSES_ROOT, v19 + 5, &phkResult);
    }
    else
    {
      if ( wcsncmp(hWndParent, L"HKU", 3u) )
      {
        sub_F72280(&v54, hWndParent);
        goto LABEL_17;
      }
      v23 = _wcsdup(L"\\HKEY_USERS");
      v24 = v23;
      dwProcessId = v23;
      v25 = PE_CopyString(&ppstr, &dwProcessId, hWndParent + 3);
      sub_F72250(&v54, v25);
      free(ppstr);
      free(v24);
      v10 = RegOpenKeyW(HKEY_USERS, v19 + 4, &phkResult);
    }
    v2 = v54;
  }
  if ( !v10 )
  {
LABEL_17:
    RegCloseKey(phkResult);
    CopyStringToString(&v54, L"\\", 0x7FFFFFFFu, 0);
    v2 = v54;
    goto LABEL_18;
  }
  v46 = wcsrchr(v2, 0x5Cu) + 1;
  *wcsrchr(v2, 0x5Cu) = 0;
LABEL_18:
  v26 = FindWindowW(L"RegEdit_RegEdit", 0);
  hWndParent = v26;
  if ( v26 )
  {
    GetWindowThreadProcessId(v26, &dwProcessId);
    v31 = OpenProcess(0, 0, dwProcessId);
    v4 = v50;
    ProcessInformation.hProcess = v31;
    v30 = hWndParent;
  }
  else
  {
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    memset(&StartupInfo, 0, 0x44u);
    StartupInfo.cb = 68;
    StartupInfo.dwFlags = 1;
    StartupInfo.wShowWindow = 1;
    v27 = v3;
    if ( (GetVersion() & 0x80000000) == 0 )
      v28 = _wcsdup(L"%systemroot%\\regedit.exe");
    else
      v28 = _wcsdup(L"%windir%\\regedit.exe");
    v3 = v28;
    v47 = v28;
    free(v27);
    v29 = RequerySystemEnvironmentString(&ppstr, v3);
    dwProcessId = v50;
    v4 = _wcsdup(*v29);
    v50 = v4;
    free(dwProcessId);
    free(ppstr);
    sub_F81040(v4);
    if ( CreateProcessW(v4, v4, 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation) )
    {
      WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
      CloseHandle(ProcessInformation.hThread);
    }
    GetLastError();
    v30 = FindWindowW(L"RegEdit_RegEdit", 0);
    hWndParent = v30;
  }
  if ( v30 )
  {
    ShowWindow(v30, 5);
    v32 = hWndParent;
    SetForegroundWindow(hWndParent);
    hWnd = FindWindowExW(v32, 0, L"SysTreeView32", 0);
    SetForegroundWindow(hWnd);
    v33 = hWnd;
    SetFocus(hWnd);
    WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
    SendMessageW(hWndParent, 0x111u, 0x10288u, 0);
    WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
    v34 = 30;
    do
    {
      SendMessageW(v33, 0x100u, 0x25u, 0);
      WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
      --v34;
    }
    while ( v34 );
    v35 = *v2 == 0;
    v36 = v2;
    v3 = v47;
    v4 = v50;
    v54 = v2;
    if ( !v35 )
    {
      v37 = hWnd;
      do
      {
        v38 = *v36;
        if ( v38 == 92 )
        {
          SendMessageW(v37, 0x100u, 0x27u, 0);
        }
        else
        {
          v39 = toupper(v38);
          SendMessageW(v37, 0x102u, v39, 0);
        }
        WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
        v36 = (v54 + 2);
        v54 = v36;
      }
      while ( *v36 );
      v4 = v50;
    }
    WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
    if ( v46 )
    {
      v54 = FindWindowExW(hWndParent, 0, L"SysListView32", 0);
      SetForegroundWindow(v54);
      SetFocus(v54);
      if ( DevMode.dmBitsPerPel > 8 )
        Sleep(0x2EEu);
      SendMessageW(v54, 0x100u, 0x24u, 0);
      v40 = *v46;
      if ( *v46 )
      {
        v41 = v46;
        v42 = v54;
        do
        {
          v43 = toupper(v40);
          SendMessageW(v42, 0x102u, v43, 0);
          WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
          v40 = v41[1];
          ++v41;
        }
        while ( v40 );
        v3 = v47;
        v4 = v50;
      }
    }
    SetForegroundWindow(hWndParent);
    SetFocus(hWndParent);
    CloseHandle(ProcessInformation.hProcess);
  }
  else
  {
    MessageBoxW(
      hWnd,
      L"Error launching Regedit. Make sure you are running with Administrative rights.",
      L"Process Explorer",
      0x30u);
  }
LABEL_47:
  free(v4);
  free(v3);
  free(v2);
}
// 102D418: using guessed type wchar_t aWindirRegeditE[21];

//----- (00F784A0) --------------------------------------------------------
int __cdecl sub_F784A0(int a1, wchar_t *a2)
{
  _WORD *v2; // eax
  char v3; // bl
  unsigned int v4; // edi
  _WORD *v5; // esi
  _WORD *v6; // esi
  unsigned int i; // edx
  int v8; // eax

  v2 = malloc(2u);
  v3 = 0;
  *a1 = v2;
  v4 = 2;
  *v2 = 0;
  v5 = *a1;
  *a1 = _wcsdup(a2);
  free(v5);
  v6 = *a1;
  if ( !wcsncmp(a2, L"File not found: ", 0x10u) )
    v4 = 18;
  for ( i = v4; v4 < wcslen(a2); ++v4 )
  {
    v8 = a2[v4];
    if ( v8 == 92 )
    {
      if ( !v3 )
        v6[i++] = 92;
      v3 = 1;
    }
    else
    {
      v3 = 0;
      v6[i++] = v8;
    }
  }
  v6[i] = a2[v4];
  free(a2);
  return a1;
}

//----- (00F785A0) --------------------------------------------------------
_bstr_t *__cdecl sub_F785A0(_bstr_t *ret, OLECHAR *psz, int nPos, _bstr_t *str)
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
  strIn = str;
  v15 = 0;
  v14 = 1;
  if ( str->m_Data && str->m_Data->m_wstr )
    nLength = SysStringLen(str->m_Data->m_wstr);
  else
    nLength = 0;
  v6 = psz;
  fLengthIsZero = nLength != 0;
  nFlags = (*psz != 0) - fLengthIsZero;
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
  if ( (*psz != 0) != fLengthIsZero )
  {
    if ( nFlags == 1 )
    {
      if ( nPos )
        v6 = &psz[nPos + 1];
      _bstr_t::operator=(ret, v6);
      return ret;
    }
    return ret;
  }
  _bstr_t::_bstr_t(&str, &psz[nPos]);
  v15 = 1;
  v10 = _bstr_t::operator+(&strIn->m_Data, &bstr1, &str);
  if ( ret != v10 )
  {
    _bstr_t::_Free(ret);
    v11 = v10->m_Data;
    ret->m_Data = v10->m_Data;
    if ( v11 )
      InterlockedIncrement(&v11->m_RefCount);
  }
  _bstr_t::_Free(&bstr1);
  _bstr_t::_Free(&str);
  return ret;
}

//----- (00F786F0) --------------------------------------------------------
void __cdecl sub_F786F0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F787A0(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F787A0(a1, a2, v7, v5);
  free(v7);
}

//----- (00F787A0) --------------------------------------------------------
void *__cdecl sub_F787A0(int a1, void *a2, wchar_t *psz, void *a4)
{
  _WORD *v4; // ebx
  tagKeyName *v5; // esi
  const wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *v8; // ebx
  WCHAR *v9; // eax
  WCHAR *v10; // edi
  const wchar_t *v11; // eax
  wchar_t *v12; // esi
  unsigned __int16 **v13; // eax
  unsigned int v14; // eax
  _WORD *v15; // edi
  _WORD *v16; // esi
  WCHAR *v17; // eax
  const wchar_t **v18; // eax
  WCHAR *v19; // esi
  const wchar_t **v20; // eax
  void *v21; // esi
  tagKeyName *v22; // esi
  unsigned int v23; // eax
  const wchar_t **v24; // eax
  WCHAR *v25; // esi
  unsigned __int16 **v26; // eax
  WCHAR *v27; // edi
  WCHAR *v28; // edi
  tagKeyName *v29; // esi
  unsigned int v30; // eax
  const wchar_t *v31; // eax
  WCHAR *v32; // eax
  WCHAR *v33; // ebx
  wchar_t *v34; // eax
  wchar_t *v35; // edi
  const wchar_t *v36; // eax
  wchar_t *v37; // esi
  unsigned __int16 **v38; // eax
  const wchar_t *v39; // eax
  wchar_t *v40; // eax
  wchar_t *v41; // ebx
  wchar_t *v42; // eax
  wchar_t *v43; // edi
  const wchar_t *v44; // eax
  wchar_t *v45; // esi
  unsigned __int16 **v46; // eax
  wchar_t *v47; // eax
  wchar_t *v48; // edi
  const wchar_t *v49; // eax
  wchar_t *v50; // esi
  unsigned __int16 **v51; // eax
  WCHAR *ppv1; // [esp+10h] [ebp-A0h]
  WCHAR v54[2]; // [esp+14h] [ebp-9Ch]
  WCHAR v55[2]; // [esp+18h] [ebp-98h]
  int a4a; // [esp+1Ch] [ebp-94h]
  int v57; // [esp+20h] [ebp-90h]
  WCHAR *v58; // [esp+24h] [ebp-8Ch]
  WCHAR v59[2]; // [esp+28h] [ebp-88h]
  WCHAR v60[2]; // [esp+2Ch] [ebp-84h]
  WCHAR v61[2]; // [esp+30h] [ebp-80h]
  void *v62; // [esp+34h] [ebp-7Ch]
  WCHAR *pszResult; // [esp+38h] [ebp-78h]
  void *v64; // [esp+3Ch] [ebp-74h]
  int v65; // [esp+40h] [ebp-70h]
  int v66; // [esp+44h] [ebp-6Ch]
  int v67; // [esp+48h] [ebp-68h]
  int v68; // [esp+4Ch] [ebp-64h]
  void *v69; // [esp+50h] [ebp-60h]
  int a3; // [esp+54h] [ebp-5Ch]
  void *v71; // [esp+58h] [ebp-58h]
  void *a1a; // [esp+5Ch] [ebp-54h]
  HKEY KeyHandle; // [esp+60h] [ebp-50h]
  LPCWSTR v74; // [esp+64h] [ebp-4Ch]
  _WORD *v75; // [esp+68h] [ebp-48h]
  void *v76; // [esp+6Ch] [ebp-44h]
  WCHAR *v77; // [esp+70h] [ebp-40h]
  LPCWSTR szArg4; // [esp+74h] [ebp-3Ch]
  void *v79; // [esp+78h] [ebp-38h]
  DWORD dwIndex; // [esp+7Ch] [ebp-34h]
  LPCWSTR v81; // [esp+80h] [ebp-30h]
  WCHAR szArg[2]; // [esp+84h] [ebp-2Ch]
  LPCWSTR szArg3; // [esp+88h] [ebp-28h]
  char v84; // [esp+8Fh] [ebp-21h]
  WCHAR *ppv2; // [esp+90h] [ebp-20h]
  void *v86; // [esp+94h] [ebp-1Ch]
  HKEY hKey; // [esp+98h] [ebp-18h]
  wchar_t *ppv3; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v90; // [esp+ACh] [ebp-4h]

  v79 = malloc(2u);
  v77 = v79;
  *v79 = 0;
  v90 = 0;
  v69 = malloc(2u);
  *v69 = 0;
  v64 = malloc(2u);
  *v64 = 0;
  v71 = malloc(2u);
  *v71 = 0;
  v4 = malloc(2u);
  v75 = v4;
  *v4 = 0;
  v5 = psz;
  LOBYTE(v90) = 4;
  if ( a4 == -1 )
  {
    szArg4 = _wcsdup(&gszNullString);
    v76 = _wcsdup(&gszNullString);
    lpszKeyName = _wcsdup(&gszNullString);
    ppv3 = _wcsdup(&gszNullString);
    hKey = _wcsdup(&gszNullString);
    v86 = _wcsdup(&gszNullString);
    dwIndex = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    v7 = _wcsdup(v6);
    v8 = v7;
    a4 = v7;
    v9 = _wcsdup(&gszNullString);
    v10 = v9;
    ppv2 = v9;
    v11 = &gszNullString;
    if ( psz )
      v11 = psz;
    v12 = _wcsdup(v11);
    szArg3 = v12;
    v81 = sub_F77BE0(&a1a, a2, &a4, &dwIndex);
    v13 = sub_F77BE0(szArg, a2, &szArg3, &ppv2);
    LOBYTE(v90) = 16;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v13, v81, &v86);
    free(*szArg);
    free(a1a);
    free(v12);
    free(v10);
    free(v8);
    free(dwIndex);
    free(v86);
    free(hKey);
    free(ppv3);
    free(lpszKeyName);
    free(v76);
    LOBYTE(v90) = 4;
    free(szArg4);
    v4 = v75;
    v5 = psz;
  }
  v14 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, v5, 0, v14 | 0x20019, &KeyHandle) )
  {
    dwIndex = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    ppv3 = malloc(2u);
    *ppv3 = 0;
    v15 = malloc(2u);
    v86 = v15;
    *v15 = 0;
    v16 = malloc(2u);
    v65 = v16;
    v66 = 0;
    v67 = 0;
    *v16 = 0;
    v68 = 0;
    LOBYTE(v90) = 20;
    if ( !PE_LoadKey(KeyHandle, 0, &ppv3) )
    {
      do
      {
        v17 = PE_CopyString2(&pszResult, L"CLSID\\", &ppv3);
        v18 = PE_CopyString(&a1a, v17, L"\\InprocServer32");
        v19 = lpszKeyName;
        lpszKeyName = _wcsdup(*v18);
        free(v19);
        free(a1a);
        free(pszResult);
        v20 = PE_CopyString2(&v58, L"HKCR\\CLSID\\", &ppv3);
        v21 = v4;
        v4 = _wcsdup(*v20);
        v75 = v4;
        free(v21);
        free(v58);
        v22 = lpszKeyName;
        v23 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v22, 0, v23 | 0x20019, &hKey) )
        {
          if ( !sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName) )
          {
            sub_F77040(lpszKeyName, &v65);
            v24 = sub_F74EE0(&v62, a1, &v65, 0);
            v86 = _wcsdup(*v24);
            free(v15);
            free(v62);
            RegCloseKey(hKey);
            v25 = _wcsdup(L"CLSID\\");
            ppv2 = v25;
            v26 = PE_CopyStringEx(&ppv1, &ppv2, &ppv3);
            v27 = lpszKeyName;
            lpszKeyName = _wcsdup(*v26);
            free(v27);
            free(ppv1);
            free(v25);
            v28 = _wcsdup(ppv3);
            v77 = v28;
            free(v79);
            v29 = lpszKeyName;
            v30 = TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v29, 0, v30 | 0x20019, &hKey) )
            {
              if ( !sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName) && wcslen(lpszKeyName) )
              {
                v77 = _wcsdup(lpszKeyName);
                free(v28);
              }
              RegCloseKey(hKey);
            }
            v31 = &gszNullString;
            if ( psz )
              v31 = psz;
            v32 = _wcsdup(v31);
            v33 = v32;
            ppv2 = v32;
            v34 = _wcsdup(&gszNullString);
            v35 = v34;
            szArg3 = v34;
            v36 = &gszNullString;
            if ( psz )
              v36 = psz;
            v37 = _wcsdup(v36);
            v81 = v37;
            *szArg = sub_F77BE0(v60, a2, &ppv2, &ppv3);
            v38 = sub_F77BE0(v54, a2, &v81, &szArg3);
            LOBYTE(v90) = 25;
            v84 = sub_F73D40(a1, &v77, v38, *szArg, &v86, &v69, &v71, &v57);
            free(*v54);
            free(*v60);
            free(v37);
            free(v35);
            free(v33);
            if ( v84 )
            {
              if ( a4 == -1 )
              {
                ppv2 = _wcsdup(&gszNullString);
                szArg3 = _wcsdup(&gszNullString);
                v81 = _wcsdup(&gszNullString);
                *szArg = _wcsdup(&gszNullString);
                v79 = _wcsdup(&gszNullString);
                v76 = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                v39 = &gszNullString;
                if ( psz )
                  v39 = psz;
                v40 = _wcsdup(v39);
                v41 = v40;
                a4 = v40;
                v42 = _wcsdup(&gszNullString);
                v43 = v42;
                a4a = v42;
                v44 = &gszNullString;
                if ( psz )
                  v44 = psz;
                v45 = _wcsdup(v44);
                a3 = v45;
                v74 = sub_F77BE0(v59, a2, &a4, &szArg4);
                v46 = sub_F77BE0(v61, a2, &a3, &a4a);
                LOBYTE(v90) = 37;
                a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v46, v74, &v76);
                free(*v61);
                free(*v59);
                free(v45);
                free(v43);
                free(v41);
                free(szArg4);
                free(v76);
                free(v79);
                free(*szArg);
                free(v81);
                free(szArg3);
                free(ppv2);
              }
              v47 = _wcsdup(&gszNullString);
              v48 = v47;
              a3 = v47;
              v49 = &gszNullString;
              if ( psz )
                v49 = psz;
              v50 = _wcsdup(v49);
              v74 = v50;
              v51 = sub_F77BE0(v55, a2, &v74, &ppv3);
              LOBYTE(v90) = 40;
              sub_F73FF0(a1, -1, a4, 3, &v77, v51, &v86);
              free(*v55);
              free(v50);
              free(v48);
            }
            sub_F721F0(&v65);
            free(v86);
            free(ppv3);
            free(lpszKeyName);
            v4 = v75;
            v79 = v77;
            goto LABEL_33;
          }
          RegCloseKey(hKey);
        }
        sub_F721F0(&v65);
        free(v15);
        free(ppv3);
        free(lpszKeyName);
LABEL_33:
        ++dwIndex;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        ppv3 = malloc(2u);
        *ppv3 = 0;
        v15 = malloc(2u);
        v86 = v15;
        *v15 = 0;
        v16 = malloc(2u);
        v65 = v16;
        v66 = 0;
        v67 = 0;
        *v16 = 0;
        v68 = 0;
        LOBYTE(v90) = 20;
      }
      while ( !PE_LoadKey(KeyHandle, dwIndex, &ppv3) );
    }
    free(v16);
    free(v15);
    free(ppv3);
    free(lpszKeyName);
    RegCloseKey(KeyHandle);
  }
  free(v4);
  free(v71);
  free(v64);
  free(v69);
  free(v79);
  return a4;
}

//----- (00F79030) --------------------------------------------------------
void __cdecl sub_F79030(void *a1, int a2, void *a3, wchar_t *a4)
{
  _WORD *v4; // eax
  void *v5; // ebx
  const wchar_t *v6; // eax
  WCHAR *v7; // esi
  WCHAR *v8; // eax
  const wchar_t **v9; // eax
  WCHAR *v10; // edi
  const wchar_t *v11; // ecx
  wchar_t *v12; // esi
  WCHAR *v13; // eax
  const wchar_t **v14; // eax
  WCHAR *v15; // ebx
  WCHAR *pszResult; // [esp+10h] [ebp-18h]
  WCHAR *ppv; // [esp+14h] [ebp-14h]
  WCHAR *ppszText2; // [esp+18h] [ebp-10h]
  int v19; // [esp+24h] [ebp-4h]

  v4 = malloc(2u);
  v5 = v4;
  *v4 = 0;
  v19 = 0;
  v6 = &gszNullString;
  if ( a4 )
    v6 = a4;
  v7 = _wcsdup(v6);
  ppszText2 = v7;
  v8 = PE_CopyString2(&pszResult, L"Software\\Classes\\CLSID\\", &ppszText2);
  v9 = PE_CopyString(&ppv, v8, L"\\Instance");
  v10 = _wcsdup(*v9);
  ppszText2 = v10;
  free(v5);
  free(ppv);
  free(pszResult);
  free(v7);
  sub_F786F0(a2, a3, &ppszText2);
  if ( a1 )
  {
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    v11 = &gszNullString;
    if ( a4 )
      v11 = a4;
    v12 = _wcsdup(v11);
    a4 = v12;
    v13 = PE_CopyString2(&pszResult, L"Software\\Wow6432Node\\Classes\\CLSID\\", &a4);
    v14 = PE_CopyString(&a1, v13, L"\\Instance");
    v15 = v10;
    v10 = _wcsdup(*v14);
    ppszText2 = v10;
    free(v15);
    free(a1);
    free(pszResult);
    free(v12);
    sub_F786F0(a2, a3, &ppszText2);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  free(v10);
}

//----- (00F791C0) --------------------------------------------------------
void __cdecl sub_F791C0(int a1, int a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F79270(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F79270(a1, a2, v7, v5);
  free(v7);
}

//----- (00F79270) --------------------------------------------------------
void *__cdecl sub_F79270(int a1, int a2, wchar_t *psz, void *a4)
{
  int v4; // edi
  tagKeyName *v5; // esi
  const wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *v8; // ebx
  wchar_t *v9; // eax
  wchar_t *v10; // edi
  const wchar_t *v11; // eax
  wchar_t *v12; // esi
  unsigned __int16 **v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  const wchar_t **v16; // eax
  const WCHAR **v17; // eax
  wchar_t *v18; // eax
  wchar_t *v19; // ebx
  wchar_t *v20; // eax
  wchar_t *v21; // edi
  const WCHAR **v22; // eax
  wchar_t *v23; // eax
  wchar_t *v24; // esi
  const wchar_t *v25; // eax
  unsigned __int16 **v26; // eax
  wchar_t *v27; // esi
  const wchar_t *v28; // eax
  wchar_t *v29; // eax
  wchar_t *v30; // ebx
  wchar_t *v31; // eax
  wchar_t *v32; // edi
  const WCHAR **v33; // eax
  wchar_t *v34; // esi
  unsigned __int16 **v35; // eax
  wchar_t *v36; // eax
  wchar_t *v37; // ebx
  const wchar_t *v38; // esi
  const wchar_t *v39; // eax
  wchar_t *v40; // edi
  wchar_t *v41; // esi
  unsigned __int16 **v42; // eax
  int a2a; // [esp+10h] [ebp-3A4h]
  wchar_t **v45; // [esp+14h] [ebp-3A0h]
  int v46; // [esp+18h] [ebp-39Ch]
  int v47; // [esp+1Ch] [ebp-398h]
  int v48; // [esp+20h] [ebp-394h]
  void *v49; // [esp+24h] [ebp-390h]
  HKEY hKey; // [esp+28h] [ebp-38Ch]
  DWORD cbData; // [esp+2Ch] [ebp-388h]
  WCHAR v52[2]; // [esp+30h] [ebp-384h]
  wchar_t *v53; // [esp+34h] [ebp-380h]
  void *v54; // [esp+38h] [ebp-37Ch]
  void *v55; // [esp+3Ch] [ebp-378h]
  void *v56; // [esp+40h] [ebp-374h]
  wchar_t *pszText; // [esp+44h] [ebp-370h]
  void *v58; // [esp+48h] [ebp-36Ch]
  void *v59; // [esp+4Ch] [ebp-368h]
  int a3; // [esp+50h] [ebp-364h]
  LPCWSTR szArg4; // [esp+54h] [ebp-360h]
  WCHAR v62[2]; // [esp+58h] [ebp-35Ch]
  void *v63; // [esp+5Ch] [ebp-358h]
  int v64; // [esp+60h] [ebp-354h]
  WCHAR v65[2]; // [esp+64h] [ebp-350h]
  LPCWSTR szArg; // [esp+68h] [ebp-34Ch]
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
  hRootKey = a2;
  v53 = psz;
  v56 = malloc(2u);
  *v56 = 0;
  v74 = 0;
  v55 = malloc(2u);
  *v55 = 0;
  v49 = malloc(2u);
  *v49 = 0;
  v54 = malloc(2u);
  *v54 = 0;
  LOBYTE(v74) = 3;
  if ( a4 == -1 )
  {
    v72 = _wcsdup(&gszNullString);
    v71 = _wcsdup(&gszNullString);
    *v68 = _wcsdup(&gszNullString);
    v63 = _wcsdup(&gszNullString);
    v59 = _wcsdup(&gszNullString);
    v58 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    v7 = _wcsdup(v6);
    v8 = v7;
    pszText = v7;
    v9 = _wcsdup(L"(Default)");
    v10 = v9;
    *v62 = v9;
    v11 = &gszNullString;
    if ( psz )
      v11 = psz;
    v12 = _wcsdup(v11);
    a3 = v12;
    *v65 = sub_F77BE0(&a1a, hRootKey, &pszText, &szArg4);
    v13 = sub_F77BE0(&szArg, hRootKey, &a3, v62);
    LOBYTE(v74) = 15;
    a4 = sub_F73FF0(v64, 0, 0xFFFFFFFF, 0, v13, *v65, &v58);
    free(szArg);
    free(a1a);
    free(v12);
    free(v10);
    free(v8);
    free(szArg4);
    free(v58);
    free(v59);
    free(v63);
    free(*v68);
    free(v71);
    LOBYTE(v74) = 3;
    free(v72);
    v5 = v53;
    v4 = v64;
  }
  v14 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hRootKey, v5, 0, v14 | 0x20019, &hKey) )
  {
    cbData = 800;
    if ( !RegQueryValueExW(hKey, &gszNullString, 0, 0, Data, &cbData) && cbData )
    {
      a2a = malloc(2u);
      v45 = 0;
      v46 = 0;
      *a2a = 0;
      v47 = 0;
      LOBYTE(v74) = 16;
      if ( sub_F76CC0(Data, &a2a) )
      {
        pszText = *v45;
        v15 = wcscmp(pszText, L"%1");
        if ( v15 )
          v15 = -(v15 < 0) | 1;
        if ( v15 )
        {
          v16 = sub_F74EE0(&a1a, v4, &a2a, 0);
          sub_F72250(&v56, v16);
          free(a1a);
          v71 = _wcsdup(L"(Default)");
          v17 = &gszNullString;
          if ( v5 )
            v17 = v5;
          v18 = _wcsdup(v17);
          v19 = v18;
          a1a = v18;
          v20 = _wcsdup(&gszNullString);
          v21 = v20;
          szArg = v20;
          v22 = &gszNullString;
          if ( v5 )
            v22 = v5;
          v23 = _wcsdup(v22);
          v24 = v23;
          *v65 = v23;
          v25 = &gszNullString;
          if ( pszText )
            v25 = pszText;
          v72 = _wcsdup(v25);
          a3 = sub_F77BE0(v68, hRootKey, &a1a, &v71);
          v26 = sub_F77BE0(v62, hRootKey, v65, &szArg);
          LOBYTE(v74) = 23;
          v67 = sub_F73D40(v64, &v72, v26, a3, &v56, &v55, &v54, &v48);
          free(*v62);
          free(*v68);
          free(v72);
          free(v24);
          free(v21);
          free(v19);
          LOBYTE(v74) = 16;
          free(v71);
          if ( v67 )
          {
            if ( a4 == -1 )
            {
              szArg4 = _wcsdup(&gszNullString);
              v58 = _wcsdup(&gszNullString);
              v59 = _wcsdup(&gszNullString);
              v63 = _wcsdup(&gszNullString);
              *v68 = _wcsdup(&gszNullString);
              v71 = _wcsdup(&gszNullString);
              v72 = _wcsdup(&gszNullString);
              v27 = v53;
              v28 = &gszNullString;
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
                v33 = v27;
              v34 = _wcsdup(v33);
              *v65 = v34;
              a3 = sub_F77BE0(v52, hRootKey, &a1a, &v72);
              v35 = sub_F77BE0(v62, hRootKey, v65, &szArg);
              LOBYTE(v74) = 35;
              a4 = sub_F73FF0(v64, 0, 0xFFFFFFFF, 0, v35, a3, &v71);
              free(*v62);
              free(*v52);
              free(v34);
              free(v32);
              free(v30);
              free(v72);
              free(v71);
              free(*v68);
              free(v63);
              free(v59);
              free(v58);
              free(szArg4);
            }
            v71 = _wcsdup(&gszNullString);
            v72 = _wcsdup(&gszNullString);
            v36 = _wcsdup(L"(Default)");
            v37 = v36;
            *v52 = v36;
            v38 = &gszNullString;
            v39 = &gszNullString;
            if ( v53 )
              v39 = v53;
            v40 = _wcsdup(v39);
            a1a = v40;
            if ( pszText )
              v38 = pszText;
            v41 = _wcsdup(v38);
            szArg = v41;
            v42 = sub_F77BE0(v65, hRootKey, &a1a, v52);
            LOBYTE(v74) = 41;
            sub_F73FF0(v64, -1, a4, 12, &szArg, v42, &v56);
            free(*v65);
            free(v41);
            free(v40);
            free(v37);
            free(v72);
            free(v71);
          }
        }
      }
      sub_F721F0(&a2a);
    }
    RegCloseKey(hKey);
  }
  free(v54);
  free(v49);
  free(v55);
  free(v56);
  return a4;
}

//----- (00F79AB0) --------------------------------------------------------
void __cdecl sub_F79AB0(int a1, void *a2, void *a3, char a4, char a5)
{
  _WORD *v5; // ST68_4
  WCHAR *v6; // esi
  void *v7; // edi
  const wchar_t **v8; // eax
  wchar_t *v9; // ST6C_4

  v5 = malloc(2u);
  *v5 = 0;
  v6 = a3;
  v7 = sub_F79B70(a1, a2, *a3, a4, a5, 0xFFFFFFFF, 1, 1);
  v8 = PE_CopyString(&a3, v6, L"\\AutorunsDisabled");
  v9 = _wcsdup(*v8);
  free(v5);
  free(a3);
  sub_F79B70(a1, a2, v9, a4, a5, v7, 0, 1);
  free(v9);
}

//----- (00F79B70) --------------------------------------------------------
void *__cdecl sub_F79B70(int a1, void *a2, wchar_t *psz, char a4, char a5, void *a6, char a7, char a8)
{
  wchar_t *v8; // edi
  tagKeyName *v9; // esi
  const wchar_t *v10; // eax
  wchar_t *v11; // eax
  wchar_t *v12; // ebx
  wchar_t *v13; // eax
  wchar_t *v14; // edi
  const wchar_t *v15; // eax
  wchar_t *v16; // esi
  unsigned __int16 **v17; // eax
  unsigned int v18; // eax
  WCHAR *v19; // ebx
  _WORD *v20; // esi
  const wchar_t *v21; // edx
  __int16 *v22; // ecx
  __int16 v23; // ax
  wchar_t *v24; // esi
  WCHAR *v25; // eax
  const wchar_t **v26; // eax
  WCHAR *v27; // esi
  const wchar_t **v28; // eax
  wchar_t *v29; // esi
  tagKeyName *v30; // edi
  unsigned int v31; // eax
  WCHAR *v32; // esi
  void (__stdcall *v33)(HKEY); // edi
  WCHAR *v34; // eax
  const wchar_t **v35; // eax
  WCHAR *v36; // edi
  const wchar_t **v37; // eax
  tagKeyName *v38; // esi
  unsigned int v39; // eax
  int v40; // eax
  WCHAR *v41; // esi
  tagKeyName *v42; // esi
  unsigned int v43; // eax
  int v44; // eax
  void *v45; // esi
  WCHAR *v46; // ebx
  const wchar_t **v47; // eax
  WCHAR *v48; // esi
  const wchar_t **v49; // eax
  wchar_t *v50; // esi
  WCHAR *v51; // eax
  const wchar_t **v52; // eax
  WCHAR *v53; // esi
  const wchar_t **v54; // eax
  wchar_t *v55; // esi
  tagKeyName *v56; // esi
  unsigned int v57; // eax
  const wchar_t **v58; // eax
  LPCWSTR *v59; // eax
  unsigned __int16 **v60; // eax
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
  unsigned __int16 **v74; // eax
  const wchar_t *v75; // eax
  wchar_t *v76; // eax
  wchar_t *v77; // ebx
  wchar_t *v78; // eax
  wchar_t *v79; // edi
  const wchar_t *v80; // eax
  wchar_t *v81; // esi
  unsigned __int16 **v82; // eax
  const wchar_t *v83; // eax
  wchar_t *v84; // esi
  unsigned __int16 **v85; // eax
  int v87; // [esp+10h] [ebp-108h]
  int v88; // [esp+14h] [ebp-104h]
  int v89; // [esp+18h] [ebp-100h]
  int v90; // [esp+1Ch] [ebp-FCh]
  void *v91; // [esp+20h] [ebp-F8h]
  int a2a; // [esp+24h] [ebp-F4h]
  int v93; // [esp+28h] [ebp-F0h]
  int v94; // [esp+2Ch] [ebp-ECh]
  int v95; // [esp+30h] [ebp-E8h]
  WCHAR *v96; // [esp+34h] [ebp-E4h]
  WCHAR *ppv; // [esp+38h] [ebp-E0h]
  void *v98; // [esp+3Ch] [ebp-DCh]
  WCHAR v99[2]; // [esp+40h] [ebp-D8h]
  WCHAR *v100; // [esp+44h] [ebp-D4h]
  int v101; // [esp+48h] [ebp-D0h]
  WCHAR *v102; // [esp+4Ch] [ebp-CCh]
  WCHAR v103[2]; // [esp+50h] [ebp-C8h]
  WCHAR *v104; // [esp+54h] [ebp-C4h]
  WCHAR v105[2]; // [esp+58h] [ebp-C0h]
  void *v106; // [esp+5Ch] [ebp-BCh]
  WCHAR *pszResult; // [esp+60h] [ebp-B8h]
  WCHAR *ppv1; // [esp+64h] [ebp-B4h]
  int a3; // [esp+68h] [ebp-B0h]
  WCHAR *v110; // [esp+6Ch] [ebp-ACh]
  int a4a; // [esp+70h] [ebp-A8h]
  WCHAR *v112; // [esp+74h] [ebp-A4h]
  WCHAR v113[2]; // [esp+78h] [ebp-A0h]
  void *v114; // [esp+7Ch] [ebp-9Ch]
  WCHAR v115[2]; // [esp+80h] [ebp-98h]
  WCHAR *v116; // [esp+84h] [ebp-94h]
  void *v117; // [esp+88h] [ebp-90h]
  WCHAR *v118; // [esp+8Ch] [ebp-8Ch]
  void *v119; // [esp+90h] [ebp-88h]
  WCHAR *v120; // [esp+94h] [ebp-84h]
  int v121; // [esp+98h] [ebp-80h]
  int v122; // [esp+9Ch] [ebp-7Ch]
  int v123; // [esp+A0h] [ebp-78h]
  int v124; // [esp+A4h] [ebp-74h]
  void *v125; // [esp+A8h] [ebp-70h]
  void *v126; // [esp+ACh] [ebp-6Ch]
  void *v127; // [esp+B0h] [ebp-68h]
  void *v128; // [esp+B4h] [ebp-64h]
  HKEY KeyHandle; // [esp+B8h] [ebp-60h]
  DWORD Type; // [esp+BCh] [ebp-5Ch]
  unsigned int v131; // [esp+C0h] [ebp-58h]
  void *a1a; // [esp+C4h] [ebp-54h]
  DWORD dwIndex; // [esp+C8h] [ebp-50h]
  WCHAR szArg[2]; // [esp+CCh] [ebp-4Ch]
  LPCWSTR v135; // [esp+D0h] [ebp-48h]
  WCHAR *ppv3; // [esp+D4h] [ebp-44h]
  LPCWSTR szArg4; // [esp+D8h] [ebp-40h]
  wchar_t *v138; // [esp+DCh] [ebp-3Ch]
  LPCWSTR szArg3; // [esp+E0h] [ebp-38h]
  void *v140; // [esp+E4h] [ebp-34h]
  LPCWSTR v141; // [esp+E8h] [ebp-30h]
  HKEY hKey; // [esp+ECh] [ebp-2Ch]
  WCHAR *v143; // [esp+F0h] [ebp-28h]
  void *v144; // [esp+F4h] [ebp-24h]
  void *v145; // [esp+F8h] [ebp-20h]
  char v146; // [esp+FFh] [ebp-19h]
  wchar_t *ppszText2; // [esp+100h] [ebp-18h]
  HKEY__ v148; // [esp+104h] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+108h] [ebp-10h]
  int v150; // [esp+114h] [ebp-4h]

  v131 = 0;
  szArg3 = 0;
  v126 = malloc(2u);
  *v126 = 0;
  v150 = 0;
  v128 = malloc(2u);
  *v128 = 0;
  v125 = malloc(2u);
  *v125 = 0;
  v127 = malloc(2u);
  *v127 = 0;
  v8 = malloc(2u);
  v138 = v8;
  *v8 = 0;
  v9 = psz;
  LOBYTE(v150) = 4;
  if ( a6 == -1 )
  {
    v145 = _wcsdup(&gszNullString);
    v143 = _wcsdup(&gszNullString);
    v144 = _wcsdup(&gszNullString);
    v140 = _wcsdup(&gszNullString);
    v141 = _wcsdup(&gszNullString);
    ppv3 = _wcsdup(&gszNullString);
    dwIndex = _wcsdup(&gszNullString);
    v10 = &gszNullString;
    if ( psz )
      v10 = psz;
    v11 = _wcsdup(v10);
    v12 = v11;
    a6 = v11;
    v13 = _wcsdup(&gszNullString);
    v14 = v13;
    Type = v13;
    v15 = &gszNullString;
    if ( psz )
      v15 = psz;
    v16 = _wcsdup(v15);
    szArg3 = v16;
    szArg4 = sub_F77BE0(&a1a, a2, &a6, &dwIndex);
    v17 = sub_F77BE0(szArg, a2, &szArg3, &Type);
    LOBYTE(v150) = 16;
    a6 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v17, szArg4, &ppv3);
    free(*szArg);
    free(a1a);
    free(v16);
    free(v14);
    free(v12);
    free(dwIndex);
    free(ppv3);
    free(v141);
    free(v140);
    free(v144);
    free(v143);
    LOBYTE(v150) = 4;
    free(v145);
    v8 = v138;
    v9 = psz;
  }
  v18 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, v9, 0, v18 | 0x20019, &KeyHandle) )
  {
    dwIndex = 0;
    v148.unused = malloc(2u);
    *v148.unused = 0;
    v141 = malloc(2u);
    v143 = v141;
    *v141 = 0;
    ppszText2 = malloc(2u);
    *ppszText2 = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    v19 = malloc(2u);
    ppv3 = v19;
    *v19 = 0;
    v20 = malloc(2u);
    v145 = v20;
    v140 = v20;
    *v20 = 0;
    LOBYTE(v150) = 22;
    if ( !sub_F81450(KeyHandle, 0, &v148, 0, &Type, &ppszText2) )
    {
      while ( Type == 1 || Type == 2 || Type == 7 || Type == 3 )
      {
        v21 = v148.unused;
        v22 = v148.unused;
        szArg4 = v148.unused;
        szArg3 = (v148.unused + 2);
        do
        {
          v23 = *v22;
          ++v22;
        }
        while ( v23 );
        if ( !((v22 - szArg3) >> 1) )
        {
          if ( !a8 )
            break;
          v148.unused = _wcsdup(L"(Default)");
          free(szArg4);
          v21 = v148.unused;
        }
        v24 = _wcsdup(v21);
        v144 = v24;
        v143 = v24;
        free(v141);
        if ( a5 )
        {
          v25 = PE_CopyString2(&pszResult, L"CLSID\\", &v148);
          v26 = PE_CopyString(&ppv, v25, L"\\InprocServer32");
          v27 = lpszKeyName;
          lpszKeyName = _wcsdup(*v26);
          free(v27);
          free(ppv);
          free(pszResult);
          v28 = PE_CopyString2(&v120, L"HKCR\\CLSID\\", &v148);
          v29 = _wcsdup(*v28);
          v138 = v29;
          free(v8);
          free(v120);
          v30 = lpszKeyName;
          v31 = TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v30, 0, v31 | 0x20019, &hKey) )
          {
            v34 = PE_CopyString2(&v96, L"CLSID\\", &v148);
            v35 = PE_CopyString(&v118, v34, L"\\Shell\\Open\\Command");
            v36 = lpszKeyName;
            lpszKeyName = _wcsdup(*v35);
            free(v36);
            free(v118);
            free(v96);
            v37 = PE_CopyString2(&v116, L"HKCR\\CLSID\\", &v148);
            v138 = _wcsdup(*v37);
            free(v29);
            free(v116);
            v38 = lpszKeyName;
            v39 = TlsGetValue(gdwTlsIndex);
            v40 = PE_OpenKey(HKEY_CLASSES_ROOT, v38, 0, v39 | 0x20019, &hKey);
            v41 = lpszKeyName;
            if ( v40 )
            {
              lpszKeyName = _wcsdup(&gszNullString);
              free(v41);
              v33 = RegCloseKey;
            }
            else
            {
              lpszKeyName = _wcsdup(&gszNullString);
              free(v41);
              sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName);
              v33 = RegCloseKey;
              RegCloseKey(hKey);
            }
          }
          else
          {
            v32 = lpszKeyName;
            lpszKeyName = _wcsdup(&gszNullString);
            free(v32);
            sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName);
            v33 = RegCloseKey;
            RegCloseKey(hKey);
          }
          if ( wcslen(ppszText2)
            || (v42 = *PE_CopyString2(&v104, L"CLSID\\", &v148),
                LOBYTE(v150) = 23,
                v131 |= 1u,
                szArg3 = v131,
                v43 = TlsGetValue(gdwTlsIndex),
                v44 = PE_OpenKey(HKEY_CLASSES_ROOT, v42, 0, v43 | 0x20019, &hKey),
                v146 = 1,
                v44) )
          {
            v146 = 0;
          }
          v150 = 22;
          if ( v131 & 1 )
          {
            v131 &= 0xFFFFFFFE;
            free(v104);
          }
          if ( v146 )
          {
            sub_F81520(hKey, &gszNullString, 0, 0, &ppszText2);
            v33(hKey);
          }
          a2a = malloc(2u);
          v93 = 0;
          v94 = 0;
          *a2a = 0;
          v95 = 0;
          LOBYTE(v150) = 24;
          if ( sub_F76CC0(lpszKeyName, &a2a) )
          {
            v45 = v144;
            v46 = _wcsdup(ppszText2);
            v143 = v46;
            free(v45);
            v47 = sub_F74890(&v114, lpszKeyName);
            v48 = lpszKeyName;
            lpszKeyName = _wcsdup(*v47);
            free(v48);
            free(v114);
            v49 = sub_F74EE0(&v98, a1, &a2a, 0);
            v50 = _wcsdup(*v49);
            v140 = v50;
            free(v145);
            free(v98);
            sub_F721F0(&a2a);
            goto LABEL_46;
          }
          sub_F721F0(&a2a);
          free(v145);
          free(v19);
          free(lpszKeyName);
          free(ppszText2);
          free(v144);
LABEL_66:
          free(v148.unused);
          v8 = v138;
          goto LABEL_67;
        }
        if ( a4 )
        {
          v87 = malloc(2u);
          v88 = 0;
          v89 = 0;
          *v87 = 0;
          v90 = 0;
          LOBYTE(v150) = 26;
          if ( sub_F76CC0(ppszText2, &v87) )
          {
            v138 = _wcsdup(ppszText2);
            free(v8);
            v63 = sub_F74890(&v119, ppszText2);
            v64 = v126;
            v126 = _wcsdup(*v63);
            free(v64);
            free(v119);
            v65 = sub_F74EE0(&v117, a1, &v87, 0);
            v50 = _wcsdup(*v65);
            v140 = v50;
            free(v145);
            free(v117);
            sub_F721F0(&v87);
LABEL_45:
            v46 = v144;
LABEL_46:
            if ( !wcslen(v46) && wcslen(v50) )
            {
              if ( wcsrchr(v50, 0x5Cu) )
              {
                v66 = wcsrchr(v50, 0x5Cu);
                v143 = _wcsdup(v66 + 1);
                free(v46);
              }
              else
              {
                v143 = _wcsdup(v50);
                free(v46);
              }
            }
            v67 = &gszNullString;
            if ( psz )
              v67 = psz;
            v68 = _wcsdup(v67);
            v69 = v68;
            szArg3 = v68;
            v70 = _wcsdup(&gszNullString);
            v71 = v70;
            szArg4 = v70;
            v72 = &gszNullString;
            if ( psz )
              v72 = psz;
            v73 = _wcsdup(v72);
            *szArg = v73;
            a1a = sub_F77BE0(v113, a2, &szArg3, &v148);
            v74 = sub_F77BE0(v115, a2, szArg, &szArg4);
            LOBYTE(v150) = 31;
            v146 = sub_F73D40(a1, &v143, v74, a1a, &v140, &v128, &v127, &v101);
            free(*v115);
            free(*v113);
            free(v73);
            free(v71);
            free(v69);
            if ( v146 )
            {
              if ( a6 == -1 )
              {
                szArg3 = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                *szArg = _wcsdup(&gszNullString);
                a1a = _wcsdup(&gszNullString);
                v145 = _wcsdup(&gszNullString);
                v144 = _wcsdup(&gszNullString);
                v141 = _wcsdup(&gszNullString);
                v75 = &gszNullString;
                if ( psz )
                  v75 = psz;
                v76 = _wcsdup(v75);
                v77 = v76;
                a6 = v76;
                v78 = _wcsdup(&gszNullString);
                v79 = v78;
                a4a = v78;
                v80 = &gszNullString;
                if ( psz )
                  v80 = psz;
                v81 = _wcsdup(v80);
                a3 = v81;
                v135 = sub_F77BE0(v103, a2, &a6, &v141);
                v82 = sub_F77BE0(v105, a2, &a3, &a4a);
                LOBYTE(v150) = 43;
                a6 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v82, v135, &v144);
                free(*v105);
                free(*v103);
                free(v81);
                free(v79);
                free(v77);
                free(v141);
                free(v144);
                free(v145);
                free(a1a);
                free(*szArg);
                free(szArg4);
                free(szArg3);
              }
              v83 = &gszNullString;
              if ( psz )
                v83 = psz;
              v84 = _wcsdup(v83);
              v135 = v84;
              v85 = sub_F77BE0(v99, a2, &v135, &v148);
              LOBYTE(v150) = 45;
              sub_F73FF0(a1, -1, a6, 1, &v143, v85, &v140);
              free(*v99);
              free(v84);
            }
            free(v140);
            free(ppv3);
            free(lpszKeyName);
            free(ppszText2);
            free(v143);
            goto LABEL_66;
          }
          sub_F721F0(&v87);
          free(v145);
          free(v19);
          free(lpszKeyName);
          free(ppszText2);
          free(v24);
          free(v148.unused);
        }
        else
        {
          v51 = PE_CopyString2(&v102, L"CLSID\\", &ppszText2);
          v52 = PE_CopyString(&v112, v51, L"\\InprocServer32");
          v53 = lpszKeyName;
          lpszKeyName = _wcsdup(*v52);
          free(v53);
          free(v112);
          free(v102);
          v54 = PE_CopyString2(&v110, L"HKCR\\CLSID\\", &ppszText2);
          v55 = v8;
          v8 = _wcsdup(*v54);
          v138 = v8;
          free(v55);
          free(v110);
          v56 = lpszKeyName;
          v57 = TlsGetValue(gdwTlsIndex);
          if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v56, 0, v57 | 0x20019, &hKey)
            && !sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName) )
          {
            v121 = malloc(2u);
            v122 = 0;
            v123 = 0;
            *v121 = 0;
            v124 = 0;
            LOBYTE(v150) = 25;
            if ( sub_F76CC0(lpszKeyName, &v121) )
            {
              v58 = sub_F74EE0(&v91, a1, &v121, 0);
              ppv3 = _wcsdup(*v58);
              free(v19);
              free(v91);
              v59 = PE_CopyString(&v100, &v148, L" -> ");
              v60 = PE_CopyStringEx(&ppv1, v59, &ppv3);
              v61 = ppszText2;
              ppszText2 = _wcsdup(*v60);
              free(v61);
              free(ppv1);
              free(v100);
              v62 = sub_F74EE0(&v106, a1, &v121, 0);
              v50 = _wcsdup(*v62);
              v140 = v50;
              free(v145);
              free(v106);
              sub_F721F0(&v121);
              RegCloseKey(hKey);
              goto LABEL_45;
            }
            sub_F721F0(&v121);
          }
          free(v145);
          free(v19);
          free(lpszKeyName);
          free(ppszText2);
          free(v144);
          free(v148.unused);
        }
LABEL_67:
        ++dwIndex;
        v148.unused = malloc(2u);
        *v148.unused = 0;
        v141 = malloc(2u);
        v143 = v141;
        *v141 = 0;
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        v19 = malloc(2u);
        ppv3 = v19;
        *v19 = 0;
        v20 = malloc(2u);
        v145 = v20;
        v140 = v20;
        *v20 = 0;
        LOBYTE(v150) = 22;
        if ( sub_F81450(KeyHandle, dwIndex, &v148, 0, &Type, &ppszText2) )
          goto LABEL_68;
      }
      free(v20);
      free(v19);
      free(lpszKeyName);
      free(ppszText2);
      free(v141);
      free(v148.unused);
      goto LABEL_67;
    }
LABEL_68:
    free(v20);
    free(v19);
    free(lpszKeyName);
    free(ppszText2);
    free(v141);
    free(v148.unused);
    RegCloseKey(KeyHandle);
  }
  free(v8);
  free(v127);
  free(v125);
  free(v128);
  free(v126);
  return a6;
}

//----- (00F7AA30) --------------------------------------------------------
void __cdecl sub_F7AA30(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5)
{
  wchar_t *v5; // esi
  void *v6; // eax
  const WCHAR **v7; // ecx
  void *v8; // ebx
  wchar_t *v9; // edi
  const wchar_t **v10; // eax
  wchar_t *v11; // esi
  WCHAR *ppv; // [esp+10h] [ebp-18h]
  void *v13; // [esp+14h] [ebp-14h]
  void *v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v13 = malloc(2u);
  v14 = v13;
  *v13 = 0;
  v5 = psz;
  v15 = 0;
  v6 = sub_F7AB10(a1, a2, psz, lpValueName, a5, 0xFFFFFFFF);
  v7 = &gszNullString;
  v8 = v6;
  if ( v5 )
    v7 = v5;
  v9 = _wcsdup(v7);
  psz = v9;
  v10 = PE_CopyString(&ppv, &psz, L"\\AutorunsDisabled");
  v11 = _wcsdup(*v10);
  v14 = v11;
  free(v13);
  free(ppv);
  free(v9);
  sub_F7AB10(a1, a2, v11, lpValueName, a5, v8);
  free(v11);
}

//----- (00F7AB10) --------------------------------------------------------
void *__cdecl sub_F7AB10(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5, void *a6)
{
  _WORD *v6; // edi
  const WCHAR *v7; // esi
  tagKeyName *v8; // ebx
  const wchar_t *v9; // eax
  wchar_t *v10; // eax
  wchar_t *v11; // ebx
  const wchar_t *v12; // eax
  wchar_t *v13; // eax
  wchar_t *v14; // edi
  const wchar_t *v15; // eax
  wchar_t *v16; // esi
  unsigned __int16 **v17; // eax
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
  unsigned __int16 **v36; // eax
  const wchar_t *v37; // eax
  wchar_t *v38; // eax
  wchar_t *v39; // ebx
  const wchar_t *v40; // eax
  wchar_t *v41; // eax
  wchar_t *v42; // edi
  const wchar_t *v43; // eax
  wchar_t *v44; // esi
  unsigned __int16 **v45; // eax
  const wchar_t *v46; // eax
  wchar_t *v47; // eax
  wchar_t *v48; // ebx
  const wchar_t *v49; // eax
  wchar_t *v50; // eax
  wchar_t *v51; // edi
  const wchar_t *v52; // eax
  wchar_t *v53; // esi
  unsigned __int16 **v54; // eax
  bool v55; // zf
  int a2a; // [esp+10h] [ebp-94h]
  int v58; // [esp+14h] [ebp-90h]
  int v59; // [esp+18h] [ebp-8Ch]
  int v60; // [esp+1Ch] [ebp-88h]
  int v61; // [esp+20h] [ebp-84h]
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
  void *v73; // [esp+50h] [ebp-54h]
  int a4; // [esp+54h] [ebp-50h]
  int a3; // [esp+58h] [ebp-4Ch]
  void *v76; // [esp+5Ch] [ebp-48h]
  void *a1a; // [esp+60h] [ebp-44h]
  int a7; // [esp+64h] [ebp-40h]
  void *v79; // [esp+68h] [ebp-3Ch]
  void *v80; // [esp+6Ch] [ebp-38h]
  void *v81; // [esp+70h] [ebp-34h]
  WCHAR *ppv3; // [esp+74h] [ebp-30h]
  void *v83; // [esp+78h] [ebp-2Ch]
  LPCWSTR szArg4; // [esp+7Ch] [ebp-28h]
  LPCWSTR v85; // [esp+80h] [ebp-24h]
  LPCWSTR szArg3; // [esp+84h] [ebp-20h]
  WCHAR szArg[2]; // [esp+88h] [ebp-1Ch]
  void *v88; // [esp+8Ch] [ebp-18h]
  LPCWSTR v89; // [esp+90h] [ebp-14h]
  char v90; // [esp+97h] [ebp-Dh]
  int v91; // [esp+A0h] [ebp-4h]

  v83 = malloc(2u);
  a7 = v83;
  *v83 = 0;
  v91 = 0;
  v6 = malloc(2u);
  v81 = v6;
  ppv3 = v6;
  *v6 = 0;
  v72 = malloc(2u);
  *v72 = 0;
  v71 = malloc(2u);
  *v71 = 0;
  v73 = malloc(2u);
  *v73 = 0;
  v7 = lpValueName;
  v8 = psz;
  LOBYTE(v91) = 4;
  if ( a6 == -1 )
  {
    v89 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v88 = _wcsdup(&gszNullString);
    v79 = _wcsdup(&gszNullString);
    v80 = _wcsdup(&gszNullString);
    v76 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v9 = &gszNullString;
    if ( psz )
      v9 = psz;
    v10 = _wcsdup(v9);
    v11 = v10;
    a6 = v10;
    v12 = &gszNullString;
    if ( lpValueName )
      v12 = lpValueName;
    v13 = _wcsdup(v12);
    v14 = v13;
    a4 = v13;
    v15 = &gszNullString;
    if ( psz )
      v15 = psz;
    v16 = _wcsdup(v15);
    a3 = v16;
    v85 = sub_F77BE0(&a1a, a2, &a6, &szArg4);
    v17 = sub_F77BE0(szArg, a2, &a3, &a4);
    LOBYTE(v91) = 16;
    a6 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v17, v85, &v76);
    free(*szArg);
    free(a1a);
    free(v16);
    free(v14);
    free(v11);
    free(szArg4);
    free(v76);
    free(v80);
    free(v79);
    free(v88);
    free(szArg3);
    LOBYTE(v91) = 4;
    free(v89);
    v7 = lpValueName;
    v8 = psz;
    v6 = v81;
  }
  v18 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, v8, 0, v18 | 0x20019, &hKey) )
  {
    szArg4 = malloc(2u);
    *szArg4 = 0;
    LOBYTE(v91) = 17;
    if ( !sub_F81520(hKey, v7, 0, 0, &szArg4) )
    {
      v19 = szArg4;
      a1a = (szArg4 + 1);
      do
      {
        v20 = *v19;
        ++v19;
      }
      while ( v20 );
      if ( (v19 - a1a) >> 1 )
      {
        v67 = 0;
        v68 = 0;
        v69 = 0;
        LOBYTE(v91) = 18;
        sub_F76DD0(szArg4, a5, &v67, 0);
        v21 = v68;
        v22 = v67;
        a4 = (v68 - v67) >> 4;
        if ( a4 )
        {
          v23 = (v67 + 4);
          a3 = v67 + 4;
          while ( 1 )
          {
            ppv3 = _wcsdup(**v23);
            free(v81);
            v24 = malloc(2u);
            a2a = v24;
            v58 = 0;
            v59 = 0;
            *v24 = 0;
            v60 = 0;
            v25 = *v23;
            LOBYTE(v91) = 19;
            sub_F76CC0(*v25, &a2a);
            v26 = sub_F74EE0(&a1a, a1, &a2a, 0);
            a7 = _wcsdup(*v26);
            free(v83);
            free(a1a);
            v27 = &gszNullString;
            if ( v7 )
              v27 = v7;
            v89 = _wcsdup(v27);
            v28 = &gszNullString;
            if ( v8 )
              v28 = v8;
            v29 = _wcsdup(v28);
            v30 = v29;
            *szArg = v29;
            v31 = &gszNullString;
            if ( v7 )
              v31 = v7;
            v32 = _wcsdup(v31);
            v33 = v32;
            v85 = v32;
            v34 = &gszNullString;
            if ( psz )
              v34 = psz;
            v35 = _wcsdup(v34);
            szArg3 = v35;
            v88 = sub_F77BE0(v65, a2, szArg, &v89);
            v36 = sub_F77BE0(v64, a2, &szArg3, &v85);
            LOBYTE(v91) = 25;
            v90 = sub_F73D40(a1, v36, v88, &ppv3, &a7, &v72, &v73, &v61);
            free(*v64);
            free(*v65);
            free(v35);
            free(v33);
            free(v30);
            free(v89);
            if ( v90 )
            {
              if ( a6 == -1 )
              {
                v81 = _wcsdup(&gszNullString);
                v76 = _wcsdup(&gszNullString);
                v80 = _wcsdup(&gszNullString);
                v79 = _wcsdup(&gszNullString);
                v88 = _wcsdup(&gszNullString);
                szArg3 = _wcsdup(&gszNullString);
                v89 = _wcsdup(&gszNullString);
                v37 = &gszNullString;
                if ( psz )
                  v37 = psz;
                v38 = _wcsdup(v37);
                v39 = v38;
                a6 = v38;
                v40 = &gszNullString;
                if ( lpValueName )
                  v40 = lpValueName;
                v41 = _wcsdup(v40);
                v42 = v41;
                *szArg = v41;
                v43 = &gszNullString;
                if ( psz )
                  v43 = psz;
                v44 = _wcsdup(v43);
                v85 = v44;
                v83 = sub_F77BE0(v63, a2, &a6, &v89);
                v45 = sub_F77BE0(v62, a2, &v85, szArg);
                LOBYTE(v91) = 37;
                a6 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v45, v83, &szArg3);
                free(*v62);
                free(*v63);
                free(v44);
                free(v42);
                free(v39);
                free(v89);
                free(szArg3);
                free(v88);
                free(v79);
                free(v80);
                free(v76);
                free(v81);
              }
              v46 = &gszNullString;
              if ( lpValueName )
                v46 = lpValueName;
              v47 = _wcsdup(v46);
              v48 = v47;
              v89 = v47;
              v49 = &gszNullString;
              if ( lpValueName )
                v49 = lpValueName;
              v50 = _wcsdup(v49);
              v51 = v50;
              *szArg = v50;
              v52 = &gszNullString;
              if ( psz )
                v52 = psz;
              v53 = _wcsdup(v52);
              v85 = v53;
              v54 = sub_F77BE0(v66, a2, &v85, szArg);
              LOBYTE(v91) = 41;
              sub_F73FF0(a1, -1, a6, 1, &ppv3, v54, &a7);
              free(*v66);
              free(v53);
              free(v51);
              free(v48);
            }
            LOBYTE(v91) = 18;
            sub_F721F0(&a2a);
            v23 = (a3 + 16);
            v55 = a4-- == 1;
            a3 += 16;
            v83 = a7;
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
          sub_F72BF0(v22, v21);
          j__free(v67);
        }
      }
    }
    RegCloseKey(hKey);
    free(szArg4);
  }
  free(v73);
  free(v71);
  free(v72);
  free(v6);
  free(v83);
  return a6;
}
