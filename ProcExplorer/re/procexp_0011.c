
//----- (00F7B220) --------------------------------------------------------
void __cdecl sub_F7B220(DWORD dwType, DWORD dwFlags)
{
  DWORD v2; // edi
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
  int v69; // [esp+28h] [ebp-4h]

  v2 = dwFlags;
  gbFlagsInSub_40B220 = dwFlags;
  SetErrorMode(1u);
  if ( Wow64EnableWow64FsRedirection )
  {
    Wow64EnableWow64FsRedirection(0);
    TlsSetValue(gdwTlsIndex, 0x100);
  }
  v3 = GetVersion;
  if ( dwType & KEY_WOW64_64KEY )
  {
    gdwFlags = KEY_WOW64_64KEY;
    if ( v2 == 2 || v2 == 1 )
      sub_F805A0(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"BootExecute");
    if ( v2 == 2 || v2 == 1 )
      sub_F805A0(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"SetupExecute");
    if ( v2 == 2 || v2 == 1 )
      sub_F805A0(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"Execute");
    if ( v2 == 2 || v2 == 1 )
      sub_F805A0(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"S0InitialCommand");
    if ( GetVersion() >= 6u )
    {
      v4 = GetVersion();
      if ( BYTE1(v4) >= 1u && (v2 == 2 || v2 == 1) )
        sub_F7AA30(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control", L"ServiceControlManagerExtension", 32);
    }
  }
  v5 = dwType;
  if ( dwType & 0x40000 )
  {
    gdwFlags = 0x40000;
    sub_F8D790(0);
    v5 = dwType;
  }
  if ( v5 & 0x80000 )
  {
    gdwFlags = 0x80000;
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Outlook\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Outlook\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Outlook\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Outlook\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Excel\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Excel\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Excel\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Excel\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\PowerPoint\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\PowerPoint\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\PowerPoint\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\PowerPoint\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Word\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Word\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Word\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Word\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Access\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Access\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Access\\Addins");
      sub_F87FE0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( v2 == 2 || !v2 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Access\\Addins");
      sub_F87FE0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    LOWORD(v5) = dwType;
  }
  if ( v5 & 0x200 )
  {
    gdwFlags = 512;
    if ( v2 == 2 || v2 == 1 )
      sub_F84E10(0, ghLocalMachineKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F84E10(
        0,
        ghLocalMachineKey,
        L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"Software\\Microsoft\\Command Processor", L"Autorun", 44);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"Software\\Wow6432Node\\Microsoft\\Command Processor", L"Autorun", 44);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
      sub_F7AA30(0, ghCurrentUserKey, L"Software\\Microsoft\\Command Processor", L"Autorun", 44);
    if ( v2 == 2 || !v2 )
    {
      v6 = _wcsdup(L"SOFTWARE\\Classes\\Exefile\\Shell\\Open\\Command");
      dwFlags = v6;
      sub_F791C0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(v6);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v7 = _wcsdup(L"SOFTWARE\\Classes\\Exefile\\Shell\\Open\\Command");
      dwFlags = v7;
      sub_F791C0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(v7);
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F85E10(0, ghLocalMachineKey, L"Software\\Classes\\.exe");
    if ( v2 == 2 || !v2 )
      sub_F85E10(0, ghCurrentUserKey, L"Software\\Classes\\.exe");
    if ( v2 == 2 || v2 == 1 )
      sub_F85E10(0, ghLocalMachineKey, L"Software\\Classes\\.cmd");
    if ( v2 == 2 || !v2 )
      sub_F85E10(0, ghCurrentUserKey, L"Software\\Classes\\.cmd");
    if ( v2 == 2 || !v2 )
    {
      v8 = _wcsdup(L"SOFTWARE\\Classes\\Htmlfile\\Shell\\Open\\Command");
      dwFlags = v8;
      sub_F791C0(0, ghCurrentUserKey, &dwFlags);
      v69 = -1;
      free(v8);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v9 = _wcsdup(L"SOFTWARE\\Classes\\Htmlfile\\Shell\\Open\\Command");
      dwFlags = v9;
      sub_F791C0(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(v9);
    }
    LOWORD(v5) = dwType;
    v3 = GetVersion;
  }
  cbData = v5 & 0x1000;
  if ( v5 & 0x1000 )
  {
    gdwFlags = 4096;
    if ( v3() < 6u )
    {
      if ( v2 == 2 || v2 == 1 )
        sub_F7AA30(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"ServiceControllerStart",
          32);
      if ( v2 == 2 || v2 == 1 )
        sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"LsaStart", 32);
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"SYSTEM\\Setup", L"CmdLine", 44);
  }
  v10 = dwType;
  if ( dwType & 0x20000 )
  {
    gdwFlags = 0x20000;
    if ( v2 == 2 || v2 == 1 )
    {
      sub_F95D10(0);
      v10 = dwType;
    }
  }
  if ( v10 & 0x20 )
  {
    gdwFlags = 32;
    if ( v2 == 2 || v2 == 1 )
    {
      sub_F89580(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Services");
      v10 = dwType;
    }
  }
  if ( v10 & 0x40 )
  {
    gdwFlags = 64;
    if ( v2 == 2 || v2 == 1 )
      sub_F81610(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Services");
    if ( v2 == 2 || v2 == 1 )
    {
      v11 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Font Drivers");
      dwFlags = v11;
      sub_F79AB0(0, ghLocalMachineKey, &dwFlags, 1, 0);
      v69 = -1;
      free(v11);
    }
  }
  if ( cbData )
  {
    gdwFlags = 4096;
    if ( GetVersion() < 6u )
    {
      if ( v2 == 2 || v2 == 1 )
        sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"GinaDLL", 44);
      if ( v2 == 2 || v2 == 1 )
        sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"UIHost", 44);
      if ( v2 == 2 || v2 == 1 )
        sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"System", 44);
      if ( v2 == 2 || v2 == 1 )
      {
        dwFlags = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\Notify");
        sub_F92060(0, ghLocalMachineKey, &dwFlags);
        v69 = -1;
        free(dwFlags);
      }
      if ( v2 == 2 || v2 == 1 )
        sub_F7AA30(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"SaveDumpStart",
          32);
    }
    else
    {
      if ( v2 == 2 || v2 == 1 )
      {
        v12 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\Credential Providers");
        dwFlags = v12;
        sub_F786F0(0, ghLocalMachineKey, &dwFlags);
        v69 = -1;
        free(v12);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v13 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\Credential Provider Filters");
        dwFlags = v13;
        sub_F786F0(0, ghLocalMachineKey, &dwFlags);
        v69 = -1;
        free(v13);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v14 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\PLAP Providers");
        dwFlags = v14;
        sub_F786F0(0, ghLocalMachineKey, &dwFlags);
        v69 = -1;
        free(v14);
      }
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"Taskman", 32);
    if ( v2 == 2 || !v2 )
      sub_F7AA30(
        0,
        ghCurrentUserKey,
        L"SOFTWARE\\Policies\\Microsoft\\Windows\\Control Panel\\Desktop",
        L"Scrnsave.exe",
        44);
    if ( v2 == 2 || !v2 )
      sub_F7AA30(0, ghCurrentUserKey, L"Control Panel\\Desktop", L"Scrnsave.exe", 44);
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\BootVerificationProgram", L"ImagePath", 44);
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\GpExtensions");
      sub_F92060(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
  }
  v15 = dwType;
  if ( dwType & 0x4000 )
  {
    gdwFlags = 0x4000;
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"SYSTEM\\CurrentControlSet\\Control\\Print\\Monitors");
      sub_F88A90(0, ghLocalMachineKey, &dwFlags, 1);
      v69 = -1;
      free(dwFlags);
    }
  }
  if ( v15 & 0x8000 )
  {
    gdwFlags = 0x8000;
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(
        0,
        ghLocalMachineKey,
        L"SYSTEM\\CurrentControlSet\\Control\\SecurityProviders",
        L"SecurityProviders",
        44);
    if ( v2 == 2 || v2 == 1 )
      sub_F86E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Authentication Packages");
    if ( v2 == 2 || v2 == 1 )
      sub_F86E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Notification Packages");
    if ( v2 == 2 || v2 == 1 )
      sub_F86E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Security Packages");
    if ( v2 == 2 || v2 == 1 )
      sub_F86E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa\\OSConfig", L"Security Packages");
  }
  if ( v15 & 0x10000 )
  {
    gdwFlags = 0x10000;
    if ( v2 == 2 || v2 == 1 )
    {
      dwFlags = _wcsdup(L"SYSTEM\\CurrentControlSet\\Control\\NetworkProvider\\Order");
      sub_F87710(0, ghLocalMachineKey, &dwFlags);
      v69 = -1;
      free(dwFlags);
    }
  }
  if ( v15 & 0x2000 )
  {
    gdwFlags = 0x10000;
    if ( v2 == 2 || v2 == 1 )
    {
      v16 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\Protocol_Catalog9\\Catalog_Entries");
      sub_F93190(0, v16);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v17 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\NameSpace_Catalog5\\Catalog_Entries");
      sub_F927D0(0, v17);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v18 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\Protocol_Catalog9\\Catalog_Entries64");
      sub_F93190(0, v18);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v19 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\NameSpace_Catalog5\\Catalog_Entries64");
      sub_F927D0(0, v19);
    }
    LOBYTE(v15) = dwType;
  }
  v20 = (v15 & 2);
  dwFlags = v20;
  if ( v20 && IsWinServer(TlsSetValue, v20) )
  {
    gdwFlags = 2;
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(
        0,
        ghLocalMachineKey,
        L"System\\CurrentControlSet\\Control\\Terminal Server\\Wds\\rdpwd",
        L"StartupPrograms",
        44);
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"AppSetup", 44);
  }
  if ( v20 )
  {
    gdwFlags = 2;
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Startup");
      v69 = 32;
      sub_F82060(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || !v2 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logon");
      v69 = 33;
      sub_F82060(0, ghCurrentUserKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logon");
      v69 = 34;
      sub_F82060(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"Userinit", 44);
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"VmApplet", 0);
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Shutdown");
      v69 = 35;
      sub_F82060(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || !v2 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      v69 = 36;
      sub_F82060(0, ghCurrentUserKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      v69 = 37;
      sub_F82060(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Group Policy\\Scripts\\Startup");
      v69 = 38;
      sub_F82060(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Group Policy\\Scripts\\Shutdown");
      v69 = 39;
      sub_F82060(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
  }
  if ( dwType & 0x400 )
  {
    gdwFlags = 1024;
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Windows");
      v69 = 40;
      sub_F72CB0(0, ghLocalMachineKey, &Type, L"Appinit_Dlls");
      v69 = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Windows");
      v69 = 41;
      sub_F72CB0(0, ghLocalMachineKey, &Type, L"Appinit_Dlls");
      v69 = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v21 = _wcsdup(L"System\\CurrentControlSet\\Control\\Session Manager\\AppCertDlls");
      cbData = v21;
      v69 = 42;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v21);
      v20 = dwFlags;
    }
  }
  if ( v20 )
  {
    gdwFlags = 2;
    if ( (GetVersion() & 0x80000000) != 0 )
    {
      if ( v2 == 2 || v2 == 1 )
      {
        v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunServices");
        cbData = v20;
        v69 = 43;
        sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
        v69 = -1;
        free(v20);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunServicesOnce");
        cbData = v20;
        v69 = 44;
        sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
        v69 = -1;
        free(v20);
      }
      if ( v2 == 2 || !v2 )
      {
        v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\RunServices");
        cbData = v20;
        v69 = 45;
        sub_F79AB0(0, ghCurrentUserKey, &cbData, 1, 0);
        v69 = -1;
        free(v20);
      }
      if ( v2 == 2 || !v2 )
      {
        v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\RunServicesOnce");
        cbData = v20;
        v69 = 46;
        sub_F79AB0(0, ghCurrentUserKey, &cbData, 1, 0);
        v69 = -1;
        free(v20);
      }
    }
    if ( v2 == 2 || !v2 )
      sub_F7AA30(0, ghCurrentUserKey, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", L"Shell", 44);
    if ( v2 == 2 || !v2 )
      sub_F7AA30(0, ghCurrentUserKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"Shell", 44);
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", L"Shell", 44);
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"Shell", 44);
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(0, ghLocalMachineKey, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"Taskman", 32);
    if ( !PE_OpenKey(ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\SafeBoot\\Option", 0, 0x20019u, &hKey) )
    {
      cbData = 4;
      Type = 4;
      if ( !RegQueryValueExW(hKey, L"UseAlternateShell", 0, &Type, Data, &cbData) && (v2 == 2 || v2 == 1) )
        sub_F7AA30(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\SafeBoot", L"AlternateShell", 44);
      RegCloseKey(hKey);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\AlternateShells\\AvailableShells");
      cbData = v20;
      v69 = 47;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v20);
    }
    if ( IsWinServer(TlsSetValue, v20) )
    {
      if ( v2 == 2 || v2 == 1 )
      {
        v22 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Runonce");
        cbData = v22;
        v69 = 48;
        sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
        v69 = -1;
        free(v22);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v23 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\RunonceEx");
        cbData = v23;
        v69 = 49;
        sub_F7F2D0(0, ghLocalMachineKey, &cbData, 1, 0);
        v69 = -1;
        free(v23);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v24 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Run");
        cbData = v24;
        v69 = 50;
        sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
        v69 = -1;
        free(v24);
      }
      if ( v2 == 2 || v2 == 1 )
        sub_F7AA30(
          0,
          ghLocalMachineKey,
          L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp",
          L"InitialProgram",
          44);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v25 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v25;
      v69 = 51;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v25);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v26 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v26;
      v69 = 52;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v26);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      v27 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v27;
      v69 = 53;
      sub_F79AB0(0, ghCurrentUserKey, &cbData, 1, 0);
      v69 = -1;
      free(v27);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || !v2 )
    {
      v28 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v28;
      v69 = 54;
      sub_F79AB0(0, ghCurrentUserKey, &cbData, 1, 0);
      v69 = -1;
      free(v28);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v29 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v29;
      v69 = 55;
      sub_F7F2D0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v29);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v30 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v30;
      v69 = 56;
      sub_F7F2D0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v30);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      v31 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v31;
      v69 = 57;
      sub_F7F2D0(0, ghCurrentUserKey, &cbData, 1, 0);
      v69 = -1;
      free(v31);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || !v2 )
    {
      v32 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v32;
      v69 = 58;
      sub_F7F2D0(0, ghCurrentUserKey, &cbData, 1, 0);
      v69 = -1;
      free(v32);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v33 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v33;
      v69 = 59;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v33);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v34 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v34;
      v69 = 60;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 1, 0);
      v69 = -1;
      free(v34);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      v35 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v35;
      v69 = 61;
      sub_F79AB0(0, ghCurrentUserKey, &cbData, 1, 0);
      v69 = -1;
      free(v35);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || !v2 )
    {
      v36 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v36;
      v69 = 62;
      sub_F79AB0(0, ghCurrentUserKey, &cbData, 1, 0);
      v69 = -1;
      free(v36);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    v20 = dwFlags;
  }
  cbData = dwType & 4;
  if ( dwType & 4 )
  {
    gdwFlags = 4;
    if ( v2 == 2 || !v2 )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Filter");
      v69 = 63;
      sub_F830B0(0, ghCurrentUserKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Filter");
      v69 = 64;
      sub_F830B0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || !v2 )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Handler");
      v69 = 65;
      sub_F830B0(0, ghCurrentUserKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Handler");
      v69 = 66;
      sub_F830B0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( v2 == 2 || !v2 )
    {
      Type = _wcsdup(L"SOFTWARE\\Microsoft\\Internet Explorer\\Desktop\\Components");
      v69 = 67;
      sub_F839D0(0, ghCurrentUserKey, &Type);
      v69 = -1;
      free(Type);
    }
  }
  if ( v20 )
  {
    gdwFlags = 2;
    if ( v2 == 2 || !v2 )
      sub_F8EFA0(
        0,
        ghCurrentUserKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"AltStartup");
    if ( v2 == 2 || v2 == 1 )
      sub_F8EFA0(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Common AltStartup");
    if ( v2 == 2 || v2 == 1 )
      sub_F8EFA0(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Common Startup");
    if ( v2 == 2 || !v2 )
      sub_F8EFA0(
        0,
        ghCurrentUserKey,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Startup");
    if ( v2 == 2 || !v2 )
      sub_F7AA30(0, ghCurrentUserKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows", L"Load", 32);
    if ( v2 == 2 || !v2 )
      sub_F7AA30(0, ghCurrentUserKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows", L"Run", 32);
    if ( (GetVersion() & 0x80000000) != 0 )
      sub_F91840(0);
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = v20;
      v69 = 68;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 1, 0);
      v69 = -1;
      free(v20);
    }
    if ( v2 == 2 || !v2 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = v20;
      v69 = 69;
      sub_F79AB0(0, ghCurrentUserKey, &Type, 1, 0);
      v69 = -1;
      free(v20);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Microsoft\\Active Setup\\Installed Components");
      v69 = 70;
      sub_F723D0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Active Setup\\Installed Components");
      v69 = 71;
      sub_F723D0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
      sub_F7AA30(
        0,
        ghLocalMachineKey,
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows",
        L"IconServiceLib",
        44);
  }
  if ( cbData )
  {
    gdwFlags = 4;
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\SharedTaskScheduler");
      Type = v20;
      v69 = 72;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 0, 1);
      v69 = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\SharedTaskScheduler");
      Type = v20;
      v69 = 73;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 0, 1);
      v69 = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = v20;
      v69 = 74;
      sub_F786F0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = v20;
      v69 = 75;
      sub_F786F0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = v20;
      v69 = 76;
      sub_F786F0(0, ghCurrentUserKey, &Type);
      v69 = -1;
      free(v20);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = v20;
      v69 = 77;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 0, 0);
      v69 = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = v20;
      v69 = 78;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 0, 0);
      v69 = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = v20;
      v69 = 79;
      sub_F79AB0(0, ghCurrentUserKey, &Type, 0, 0);
      v69 = -1;
      free(v20);
    }
  }
  if ( dwFlags )
  {
    gdwFlags = 2;
    if ( v2 == 2 || !v2 )
    {
      v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = v20;
      v69 = 80;
      sub_F79AB0(0, ghCurrentUserKey, &Type, 1, 0);
      v69 = -1;
      free(v20);
    }
    if ( IsWinServer(TlsSetValue, v20) )
    {
      if ( v2 == 2 || !v2 )
      {
        v37 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Runonce");
        Type = v37;
        v69 = 81;
        sub_F79AB0(0, ghCurrentUserKey, &Type, 1, 0);
        v69 = -1;
        free(v37);
      }
      if ( v2 == 2 || !v2 )
      {
        v38 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\RunonceEx");
        Type = v38;
        v69 = 82;
        sub_F7F2D0(0, ghCurrentUserKey, &Type, 1, 0);
        v69 = -1;
        free(v38);
      }
      if ( v2 == 2 || !v2 )
      {
        v39 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Run");
        Type = v39;
        v69 = 83;
        sub_F79AB0(0, ghCurrentUserKey, &Type, 1, 0);
        v69 = -1;
        free(v39);
      }
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v40 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows CE Services\\AutoStartOnConnect");
      Type = v40;
      v69 = 84;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 1, 0);
      v69 = -1;
      free(v40);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v41 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows CE Services\\AutoStartOnConnect");
      Type = v41;
      v69 = 85;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 1, 0);
      v69 = -1;
      free(v41);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v42 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows CE Services\\AutoStartOnDisconnect");
      Type = v42;
      v69 = 86;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 1, 0);
      v69 = -1;
      free(v42);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v43 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows CE Services\\AutoStartOnDisconnect");
      Type = v43;
      v69 = 87;
      sub_F79AB0(0, ghLocalMachineKey, &Type, 1, 0);
      v69 = -1;
      free(v43);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  v44 = dwType;
  if ( dwType & 0x10 )
  {
    gdwFlags = 16;
    if ( v2 == 2 || v2 == 1 )
    {
      sub_F90760(0);
      v44 = dwType;
    }
  }
  *Data = v44 & 8;
  if ( v44 & 8 )
  {
    gdwFlags = 8;
    if ( v2 == 2 || v2 == 1 )
    {
      v45 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects");
      Type = v45;
      v69 = 88;
      sub_F786F0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(v45);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v46 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects");
      Type = v46;
      v69 = 89;
      sub_F786F0(0, ghLocalMachineKey, &Type);
      v69 = -1;
      free(v46);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  if ( cbData )
  {
    gdwFlags = 4;
    if ( v2 == 2 || v2 == 1 )
    {
      v47 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellExecuteHooks");
      cbData = v47;
      v69 = 90;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 0, 1);
      v69 = -1;
      free(v47);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v48 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellExecuteHooks");
      cbData = v48;
      v69 = 91;
      sub_F79AB0(0, ghLocalMachineKey, &cbData, 0, 1);
      v69 = -1;
      free(v48);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      v69 = 92;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      v69 = 93;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      v69 = 94;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      v69 = 95;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      v69 = 96;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      v69 = 97;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      v69 = 98;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      v69 = 99;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      v69 = 100;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      v69 = 101;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      v69 = 102;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      v69 = 103;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      v69 = 104;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      v69 = 105;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      v69 = 106;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      v69 = 107;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      v69 = 108;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      v69 = 109;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      v69 = 110;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      v69 = 111;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      v69 = 112;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\DragDropHandlers");
      v69 = 113;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\DragDropHandlers");
      v69 = 114;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\DragDropHandlers");
      v69 = 115;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      v69 = 116;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      v69 = 117;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      v69 = 118;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      v69 = 119;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      v69 = 120;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      v69 = 121;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      v69 = 122;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      v69 = 123;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      v69 = 124;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      v49 = _wcsdup(L"Software\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = v49;
      v69 = 125;
      sub_F786F0(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(v49);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v50 = _wcsdup(L"Software\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = v50;
      v69 = 126;
      sub_F786F0(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(v50);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v51 = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = v51;
      v69 = 127;
      sub_F786F0(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(v51);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      v69 = 128;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      v69 = 129;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      v69 = 130;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      v69 = 131;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      v69 = 132;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      v69 = 133;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      v69 = 134;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      v69 = 135;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      v69 = 136;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      v69 = 137;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      v69 = 138;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      v69 = 139;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      v69 = 140;
      sub_F8A070(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      v69 = 141;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      v69 = 142;
      sub_F8A070(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
      sub_F7AA30(
        0,
        ghCurrentUserKey,
        L"Software\\Classes\\Clsid\\{AB8902B4-09CA-4bb6-B78D-A8F59079A8D5}",
        L"Inprocserver32",
        32);
    if ( v2 == 2 || !v2 )
    {
      v52 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = v52;
      v69 = 143;
      sub_F786F0(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(v52);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v53 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = v53;
      v69 = 144;
      sub_F786F0(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(v53);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v54 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = v54;
      v69 = 145;
      sub_F786F0(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(v54);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  if ( *Data )
  {
    gdwFlags = 8;
    if ( v2 == 2 || !v2 )
    {
      v55 = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\UrlSearchHooks");
      *Data = v55;
      v69 = 146;
      sub_F79AB0(0, ghCurrentUserKey, Data, 0, 1);
      v69 = -1;
      free(v55);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v56 = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Toolbar");
      *Data = v56;
      v69 = 147;
      sub_F79AB0(0, ghLocalMachineKey, Data, 0, 1);
      v69 = -1;
      free(v56);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      v57 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Toolbar");
      *Data = v57;
      v69 = 148;
      sub_F79AB0(0, ghLocalMachineKey, Data, 0, 1);
      v69 = -1;
      free(v57);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Explorer Bars");
      v69 = 149;
      sub_F84150(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Explorer Bars");
      v69 = 150;
      sub_F84150(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Explorer Bars");
      v69 = 151;
      sub_F84150(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Explorer Bars");
      v69 = 152;
      sub_F84150(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Extensions");
      v69 = 153;
      sub_F84150(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Extensions");
      v69 = 154;
      sub_F84150(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( v2 == 2 || !v2 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Extensions");
      v69 = 155;
      sub_F84150(0, ghCurrentUserKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Extensions");
      v69 = 156;
      sub_F84150(0, ghLocalMachineKey, &cbData);
      v69 = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  if ( (dwType & 0x80u) != 0 )
  {
    gdwFlags = 128;
    if ( PE_OpenKey(ghLocalMachineKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32", 0, 0x20019u, Data) )
    {
      if ( dword_1063628[0] && (v2 == 2 || v2 == 1) )
        wprintf(L"\nNo entry to display for codecs. Codecs are not supported on Nano Server.\n");
    }
    else
    {
      if ( v2 == 2 || !v2 )
      {
        v58 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v58;
        v69 = 157;
        sub_F79AB0(0, ghCurrentUserKey, &dwType, 1, 0);
        v69 = -1;
        free(v58);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v59 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v59;
        v69 = 158;
        sub_F79AB0(0, ghLocalMachineKey, &dwType, 1, 0);
        v69 = -1;
        free(v59);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, 0x200);
      }
      if ( v2 == 2 || !v2 )
      {
        v60 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v60;
        v69 = 159;
        sub_F79AB0(0, ghCurrentUserKey, &dwType, 1, 0);
        v69 = -1;
        free(v60);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v61 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v61;
        v69 = 160;
        sub_F79AB0(0, ghLocalMachineKey, &dwType, 1, 0);
        v69 = -1;
        free(v61);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, 0x100);
      }
      if ( v2 == 2 || !v2 )
      {
        v62 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = v62;
        v69 = 161;
        sub_F786F0(0, ghCurrentUserKey, &dwType);
        v69 = -1;
        free(v62);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v63 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = v63;
        v69 = 162;
        sub_F786F0(0, ghLocalMachineKey, &dwType);
        v69 = -1;
        free(v63);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, 0x200);
      }
      if ( v2 == 2 || v2 == 1 )
      {
        v64 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = v64;
        v69 = 163;
        sub_F786F0(0, ghLocalMachineKey, &dwType);
        v69 = -1;
        free(v64);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, 0x100);
      }
      if ( v2 == 2 || !v2 )
        sub_F79030(1, 0, ghCurrentUserKey, L"{083863F1-70DE-11d0-BD40-00A0C911CE86}");
      if ( v2 == 2 || !v2 )
        sub_F79030(1, 0, ghCurrentUserKey, L"{AC757296-3522-4E11-9862-C17BE5A1767E}");
      if ( v2 == 2 || !v2 )
        sub_F79030(1, 0, ghCurrentUserKey, L"{7ED96837-96F0-4812-B211-F13C24117ED3}");
      if ( v2 == 2 || !v2 )
        sub_F79030(1, 0, ghCurrentUserKey, L"{ABE3B9A4-257D-4B97-BD1A-294AF496222E}");
      if ( v2 == 2 || v2 == 1 )
        sub_F79030(1, 0, ghLocalMachineKey, L"{083863F1-70DE-11d0-BD40-00A0C911CE86}");
      if ( v2 == 2 || v2 == 1 )
        sub_F79030(1, 0, ghLocalMachineKey, L"{AC757296-3522-4E11-9862-C17BE5A1767E}");
      if ( v2 == 2 || v2 == 1 )
        sub_F79030(1, 0, ghLocalMachineKey, L"{7ED96837-96F0-4812-B211-F13C24117ED3}");
      if ( v2 == 2 || v2 == 1 )
        sub_F79030(1, 0, ghLocalMachineKey, L"{ABE3B9A4-257D-4B97-BD1A-294AF496222E}");
    }
  }
  if ( dwFlags )
  {
    gdwFlags = 2;
    if ( v2 == 2 || !v2 )
    {
      dwType = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      v69 = 164;
      sub_F82060(0, ghCurrentUserKey, &dwType);
      v69 = -1;
      free(dwType);
    }
    if ( v2 == 2 || v2 == 1 )
    {
      dwType = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Shutdown");
      v69 = 165;
      sub_F82060(0, ghLocalMachineKey, &dwType);
      free(dwType);
    }
  }
}
// 10631C0: using guessed type int gbFlagsInSub_40B220;
// 1063628: using guessed type int dword_1063628[140];
// 10648D8: using guessed type int gdwFlags;

//----- (00F7F2D0) --------------------------------------------------------
void __cdecl sub_F7F2D0(int a1, void *a2, int a3, char a4, char a5)
{
  WCHAR *v5; // edi
  tagKeyName *v6; // esi
  unsigned int v7; // eax
  _WORD *v8; // esi
  _WORD *v9; // ebx
  LPCWSTR *v10; // eax
  unsigned __int16 **v11; // eax
  wchar_t *v12; // edi
  void *v13; // ebx
  const wchar_t **v14; // eax
  wchar_t *v15; // esi
  void *v16; // edi
  LSTATUS v17; // eax
  WCHAR *v18; // ebx
  wchar_t *v19; // edi
  WCHAR *v20; // esi
  unsigned __int16 **v21; // eax
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
  v5 = a3;
  v35 = 0;
  v6 = *a3;
  v7 = TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(a2, v6, 0, v7 | 0x20019, &hKey) )
  {
    ppv3 = _wcsdup(&gszNullString);
    v33.unused = _wcsdup(&gszNullString);
    v31 = _wcsdup(&gszNullString);
    v30 = _wcsdup(&gszNullString);
    v29 = _wcsdup(&gszNullString);
    v18 = _wcsdup(&gszNullString);
    ppv1 = v18;
    v19 = _wcsdup(&gszNullString);
    szArg4 = v19;
    v20 = _wcsdup(&gszNullString);
    ppv = v20;
    a6 = sub_F77BE0(&a1a, a2, a3, &szArg4);
    v21 = sub_F77BE0(szArg, a2, a3, &ppv);
    LOBYTE(v35) = 13;
    sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v21, a6, &ppv1);
    free(*szArg);
    free(a1a);
    free(v20);
    free(v19);
    free(v18);
    free(v29);
    free(v30);
    free(v31);
    free(v33.unused);
    free(ppv3);
  }
  else
  {
    v31 = 0;
    v8 = malloc(2u);
    v33.unused = v8;
    *v8 = 0;
    v9 = malloc(2u);
    v30 = v9;
    v29 = v9;
    *v9 = 0;
    ppv3 = malloc(2u);
    *ppv3 = 0;
    LOBYTE(v35) = 3;
    if ( !PE_LoadKey(hKey, 0, &ppv3) )
    {
      do
      {
        v10 = PE_CopyString(&ppv, v5, L"\\");
        v11 = PE_CopyStringEx(&ppv1, v10, &ppv3);
        v12 = _wcsdup(*v11);
        v33.unused = v12;
        free(v8);
        free(ppv1);
        free(ppv);
        v13 = sub_F79B70(a1, a2, v12, a4, a5, 0xFFFFFFFF, 1, 0);
        v14 = PE_CopyString(&szArg4, &v33, L"\\AutorunsDisabled");
        v15 = _wcsdup(*v14);
        v29 = v15;
        free(v30);
        free(szArg4);
        sub_F79B70(a1, a2, v15, a4, a5, v13, 0, 0);
        free(ppv3);
        free(v15);
        free(v12);
        v31 = v31 + 1;
        v16 = v31;
        v8 = malloc(2u);
        v33.unused = v8;
        *v8 = 0;
        v9 = malloc(2u);
        v30 = v9;
        v29 = v9;
        *v9 = 0;
        ppv3 = malloc(2u);
        *ppv3 = 0;
        LOBYTE(v35) = 3;
        v17 = PE_LoadKey(hKey, v16, &ppv3);
        v5 = a3;
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

//----- (00F7F610) --------------------------------------------------------
char __cdecl sub_F7F610(HWND hWnd, tagAccountInfo *pInfo, DWORD dwMenuId)
{
  WCHAR *v3; // edi
  WCHAR *lpszFile; // ebx
  _WORD *v5; // eax
  int index; // ecx
  tagAccountInfo **v7; // esi
  unsigned int nCount; // edx
  tagAccountInfo *v9; // eax
  tagAccountInfo *pInfoTemp; // esi
  bool bNotSystemUser; // zf
  int v12; // eax
  const WCHAR **v13; // ecx
  wchar_t *v14; // esi
  const wchar_t **v15; // eax
  const wchar_t **v16; // eax
  WCHAR *v17; // esi
  tagKeyName *v18; // esi
  int v19; // eax
  wchar_t *v20; // esi
  const wchar_t **v21; // eax
  WCHAR *v22; // ST48_4
  FILE *v23; // eax
  UINT v24; // ST2C_4
  HMENU v25; // eax
  UINT v26; // ST2C_4
  HMENU v27; // eax
  void *v29; // [esp+10h] [ebp-30h]
  const WCHAR *lpszKeyName; // [esp+14h] [ebp-2Ch]
  HKEY__ v31; // [esp+18h] [ebp-28h]
  WCHAR *ppstr; // [esp+1Ch] [ebp-24h]
  DWORD dwMessageId; // [esp+20h] [ebp-20h]
  HKEY__ hKey; // [esp+24h] [ebp-1Ch]
  HKEY KeyHandle; // [esp+28h] [ebp-18h]
  tagAccountInfo *pInfoTemp_1; // [esp+2Ch] [ebp-14h]
  char ret; // [esp+33h] [ebp-Dh]
  int v38; // [esp+3Ch] [ebp-4h]

  v3 = malloc(2u);
  hKey.unused = v3;
  *v3 = 0;
  v38 = 0;
  lpszFile = malloc(2u);
  v31.unused = lpszFile;
  *lpszFile = 0;
  ret = 0;
  v5 = malloc(2u);
  index = 0;
  v29 = v5;
  *v5 = 0;
  v7 = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
  nCount = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  LOBYTE(v38) = 2;
  if ( nCount )
  {
    while ( 1 )
    {
      v9 = v7[index];
      v7 = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
      if ( v9->nMenuID == dwMenuId )
        break;
      if ( ++index >= nCount )
        goto LABEL_4;
    }
    pInfoTemp = *(garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst + index);
  }
  else
  {
LABEL_4:
    pInfoTemp = KeyHandle;
  }
  bNotSystemUser = LOBYTE(pInfoTemp->bIsSystemUser) == 0;
  pInfoTemp_1 = pInfoTemp;
  if ( !bNotSystemUser )
  {
    KeyHandle = HKEY_CURRENT_USER;
LABEL_20:
    ret = 1;
    if ( hWnd )
    {
      v24 = pInfo->nMenuID;
      v25 = GetMenu(hWnd);
      CheckMenuItem(v25, v24, 0);
      v26 = pInfoTemp_1->nMenuID;
      v27 = GetMenu(hWnd);
      CheckMenuItem(v27, v26, MF_CHECKED);
    }
    if ( pInfo && !LOBYTE(pInfo->bIsSystemUser) )
    {
      RegCloseKey(ghCurrentUserKey);
      RegUnLoadKeyW(HKEY_USERS, pInfo->szUserName);
    }
    gpAccountInfo = pInfoTemp_1;
    ghCurrentUserKey = KeyHandle;
    goto LABEL_26;
  }
  lpszKeyName = pInfoTemp->szReferenceName;
  v12 = wcscmp(pInfoTemp->szReferenceName, L"NT AUTHORITY\\SYSTEM");
  if ( v12 )
    v12 = -(v12 < 0) | 1;
  if ( v12 )
  {
    v13 = &gszNullString;
    if ( pInfoTemp != -1048 )
      v13 = pInfoTemp->szProfileImgPath;
    v14 = _wcsdup(v13);
    hKey.unused = v14;
    v15 = PE_CopyString(&ppstr, &hKey, L"\\ntuser.dat");
    dwMessageId = v3;
    v3 = _wcsdup(*v15);
    hKey.unused = v3;
    free(dwMessageId);
    free(ppstr);
    free(v14);
    v16 = RequerySystemEnvironmentString(&ppstr, v3);
    v17 = lpszFile;
    lpszFile = _wcsdup(*v16);
    v31.unused = lpszFile;
    free(v17);
    free(ppstr);
    v18 = pInfoTemp_1->szUserName;
    dwMessageId = RegLoadKeyW(HKEY_USERS, pInfoTemp_1->szUserName, lpszFile);
    if ( dwMessageId )
    {
      v20 = _wcsdup(L"Error loading profile for ");
      v31.unused = v20;
      v21 = PE_CopyString(&ppstr, &v31, lpszKeyName);
      v22 = v3;
      v3 = _wcsdup(*v21);
      free(v22);
      free(ppstr);
      free(v20);
      v23 = sub_1007B15();
      fputws(v3, v23 + 2);
      sub_F77AE0(dwMessageId);
      goto LABEL_26;
    }
    v19 = PE_OpenKey(HKEY_USERS, v18, 0, 0x2001Fu, &KeyHandle);
  }
  else
  {
    v19 = PE_OpenKey(HKEY_USERS, pInfoTemp->szUserName, 0, 0x2001Fu, &KeyHandle);
  }
  if ( !v19 )
    goto LABEL_20;
LABEL_26:
  free(v29);
  free(lpszFile);
  free(v3);
  return ret;
}
// 102D238: using guessed type wchar_t aNtAuthoritySys[20];

//----- (00F7F8D0) --------------------------------------------------------
int __cdecl sub_F7F8D0(int a1, wchar_t *a2)
{
  const wchar_t *v2; // ecx
  wchar_t *v3; // eax
  wchar_t *v4; // ecx
  wchar_t *v5; // edx
  wchar_t i; // ax

  v2 = &gszNullString;
  if ( a2 )
    v2 = a2;
  v3 = _wcsdup(v2);
  v4 = v3;
  v5 = v3;
  *a1 = v3;
  for ( i = *v3; i; ++v4 )
  {
    if ( i != '"' )
    {
      *v5 = i;
      ++v5;
    }
    i = v4[1];
  }
  *v5 = 0;
  return a1;
}

//----- (00F7F930) --------------------------------------------------------
char __thiscall sub_F7F930(_DWORD *this, unsigned int a2)
{
  _DWORD *v2; // esi
  char *v4; // eax

  v2 = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  if ( !a2 )
    return 0;
  if ( a2 > 0x3FFFFFFF )
    std::_Xlength_error("vector<T> too long");
  v4 = operator new(4 * a2);
  if ( !v4 )
    std::_Xbad_alloc();
  *v2 = v4;
  v2[1] = v4;
  v2[2] = &v4[4 * a2];
  return 1;
}

//----- (00F7F9A0) --------------------------------------------------------
_DWORD *std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode()
{
  _DWORD *result; // eax

  result = operator new(0x20u);
  JUMPOUT(result, 0, std::_Xbad_alloc);
  *result = result;
  if ( result != -4 )
    result[1] = result;
  if ( result != -8 )
    result[2] = result;
  *(result + 6) = 257;
  return result;
}

//----- (00F7F9D0) --------------------------------------------------------
int __thiscall sub_F7F9D0(int *this, unsigned int a2, int a3)
{
  int *v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // eax
  void *v8; // ecx
  int *v9; // edx
  int v10; // eax
  int result; // eax
  int v12; // [esp+0h] [ebp-28h]
  int *v13; // [esp+10h] [ebp-18h]
  int v14; // [esp+14h] [ebp-14h]
  int *v15; // [esp+18h] [ebp-10h]
  int v16; // [esp+24h] [ebp-4h]

  v15 = &v12;
  v3 = this;
  v13 = this;
  v4 = a2 | 7;
  if ( (a2 | 7) <= 0x7FFFFFFE )
  {
    v5 = this[5];
    v6 = this[5] >> 1;
    if ( v6 > v4 / 3 )
    {
      v4 = v6 + v5;
      if ( v5 > 2147483646 - v6 )
        v4 = 2147483646;
    }
  }
  else
  {
    v4 = a2;
  }
  v7 = v4 + 1;
  v16 = 0;
  v8 = 0;
  v14 = 0;
  if ( v4 != -1 )
  {
    if ( v7 > 0x7FFFFFFF || (v8 = operator new(2 * v7), (v14 = v8) == 0) )
      std::_Xbad_alloc();
  }
  if ( a3 )
  {
    v9 = v3[5] < 8 ? v3 : *v3;
    if ( a3 )
      memmove_0(v8, v9, 2 * a3);
  }
  if ( v3[5] >= 8 )
    j__free(*v3);
  v10 = v14;
  *v3 = v14;
  v3[5] = v4;
  v3[4] = a3;
  if ( v4 >= 8 )
    v3 = v10;
  result = 0;
  *(v3 + a3) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F7FB40) --------------------------------------------------------
void __stdcall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(std__Tree_node *a1)
{
  std__Tree_node_For__bstr_t *v1; // edi
  std__Tree_node_For__bstr_t *v2; // ebx
  Data_t_bstr_t *v3; // esi
  Data_t_bstr_t *v4; // esi

  v1 = a1;
  v2 = a1;
  if ( !a1->_IsNil )
  {
    do
    {
      std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(v2->_Right);
      v3 = v1->_bstrText2.m_Data;
      v2 = v2->_Left;
      if ( v3 )
      {
        if ( !InterlockedDecrement(&v3->m_RefCount) && v3 )
        {
          if ( v3->m_wstr )
          {
            SysFreeString(v3->m_wstr);
            v3->m_wstr = 0;
          }
          if ( v3->m_str )
          {
            j_j__free(v3->m_str);
            v3->m_str = 0;
          }
          j__free(v3);
        }
        v1->_bstrText2.m_Data = 0;
      }
      v4 = v1->_bstrText1.m_Data;
      if ( v4 )
      {
        if ( !InterlockedDecrement(&v4->m_RefCount) && v4 )
        {
          if ( v4->m_wstr )
          {
            SysFreeString(v4->m_wstr);
            v4->m_wstr = 0;
          }
          if ( v4->m_str )
          {
            j_j__free(v4->m_str);
            v4->m_str = 0;
          }
          j__free(v4);
        }
        v1->_bstrText1.m_Data = 0;
      }
      j__free(v1);
      v1 = v2;
    }
    while ( !v2->_IsNil );
  }
}

//----- (00F7FC40) --------------------------------------------------------
BOOL __thiscall sub_F7FC40(void *this, int a2, int a3)
{
  int *v3; // esi
  unsigned int v4; // eax
  BOOL result; // eax
  unsigned int v6; // ebx
  int *v7; // ecx
  int v8; // [esp+14h] [ebp+Ch]

  v3 = this;
  if ( a2 > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v4 = *(this + 5);
  if ( v4 >= a2 )
  {
    if ( a3 && a2 < 8 )
    {
      v6 = *(this + 4);
      if ( a2 < v6 )
        v6 = a2;
      if ( v4 >= 8 )
      {
        v7 = *this;
        v8 = *v3;
        if ( v6 )
        {
          memmove_0(v3, v7, 2 * v6);
          v7 = v8;
        }
        j__free(v7);
      }
      v3[4] = v6;
      v3[5] = 7;
      *(v3 + v6) = 0;
      result = a2 > 0;
    }
    else
    {
      if ( !a2 )
      {
        *(this + 4) = 0;
        if ( v4 >= 8 )
          v3 = *this;
        *v3 = 0;
      }
      result = a2 > 0;
    }
  }
  else
  {
    sub_F7F9D0(this, a2, *(this + 4));
    result = a2 > 0;
  }
  return result;
}

//----- (00F7FD00) --------------------------------------------------------
int *__thiscall sub_F7FD00(int *this, unsigned int a2)
{
  int *v2; // ebx
  unsigned int v3; // esi
  char *v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int *result; // eax
  int v9; // [esp+0h] [ebp-28h]
  void *v10; // [esp+10h] [ebp-18h]
  int *v11; // [esp+14h] [ebp-14h]
  int *v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+24h] [ebp-4h]

  v12 = &v9;
  v2 = this;
  v11 = this;
  v3 = a2;
  v4 = 0;
  v10 = 0;
  if ( a2 )
  {
    if ( a2 > 0xFFFFFFF || (v4 = operator new(16 * a2), (v10 = v4) == 0) )
      std::_Xbad_alloc();
  }
  v13 = 0;
  sub_F73440(*v2, v2[1], v4);
  v5 = *v2;
  v6 = v2[1];
  v7 = v2[1] - *v2;
  if ( v5 )
  {
    sub_F72BF0(v5, v6);
    j__free(*v11);
  }
  result = v11;
  v11[2] = &v4[16 * v3];
  result[1] = &v4[v7 & 0xFFFFFFF0];
  *result = v4;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F7FDF0) --------------------------------------------------------
const wchar_t **__thiscall sub_F7FDF0(std__vector *this, unsigned int a2)
{
  std__vector *v2; // ebx
  char *v3; // edi
  std__vector *v4; // eax
  std__vector *v5; // esi
  int v6; // ecx
  int v7; // ecx
  const wchar_t **result; // eax
  int v9; // [esp+0h] [ebp-2Ch]
  int v10; // [esp+10h] [ebp-1Ch]
  void *v11; // [esp+14h] [ebp-18h]
  int *v12; // [esp+1Ch] [ebp-10h]
  int v13; // [esp+28h] [ebp-4h]

  v12 = &v9;
  v2 = this;
  v3 = 0;
  v11 = 0;
  if ( a2 )
  {
    if ( a2 > 0x3FFFFFFF || (v3 = operator new(4 * a2), (v11 = v3) == 0) )
      std::_Xbad_alloc();
  }
  v13 = 0;
  sub_F734F0(v2->baseclass_0._Mypair._Myval2._Myfirst, v2->baseclass_0._Mypair._Myval2._Mylast, v3);
  v4 = v2->baseclass_0._Mypair._Myval2._Mylast;
  v5 = v2->baseclass_0._Mypair._Myval2._Myfirst;
  v6 = v2->baseclass_0._Mypair._Myval2._Mylast - v2->baseclass_0._Mypair._Myval2._Myfirst;
  v11 = v2->baseclass_0._Mypair._Myval2._Mylast;
  v7 = v6 >> 2;
  v10 = v7;
  if ( v5 )
  {
    if ( v5 != v4 )
    {
      do
      {
        free(v5->baseclass_0._Mypair._Myval2._Myfirst);
        v5 = (v5 + 4);
      }
      while ( v5 != v11 );
    }
    j__free(v2->baseclass_0._Mypair._Myval2._Myfirst);
    v7 = v10;
  }
  v2->baseclass_0._Mypair._Myval2._Myfirst = v3;
  v2->baseclass_0._Mypair._Myval2._Myend = &v3[4 * a2];
  result = &v3[4 * v7];
  v2->baseclass_0._Mypair._Myval2._Mylast = result;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F7FEE0) --------------------------------------------------------
int *__thiscall sub_F7FEE0(int *this, unsigned int a2)
{
  int v2; // esi
  int *result; // eax
  int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = this[1];
  result = ((this[2] - v2) >> 4);
  if ( result < a2 )
  {
    v4 = (v2 - *this) >> 4;
    if ( 0xFFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = a2 + v4;
    v6 = (this[2] - *this) >> 4;
    if ( 0xFFFFFFF - (v6 >> 1) >= v6 )
    {
      v8 = (v6 >> 1) + v6;
      if ( v8 < v5 )
        v8 = v5;
      result = sub_F7FD00(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = sub_F7FD00(this, v7);
    }
  }
  return result;
}

//----- (00F7FF60) --------------------------------------------------------
unsigned int __thiscall std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(std__vector *this, unsigned int a2)
{
  void *v2; // esi
  unsigned int result; // eax
  signed int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = this->baseclass_0._Mypair._Myval2._Mylast;
  result = (this->baseclass_0._Mypair._Myval2._Myend - v2) >> 2;
  if ( result < a2 )
  {
    v4 = (v2 - this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( 0x3FFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = a2 + v4;
    v6 = (this->baseclass_0._Mypair._Myval2._Myend - this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( 0x3FFFFFFF - (v6 >> 1) >= v6 )
    {
      v8 = (v6 >> 1) + v6;
      if ( v8 < v5 )
        v8 = v5;
      result = sub_F7FDF0(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = sub_F7FDF0(this, v7);
    }
  }
  return result;
}

//----- (00F7FFE0) --------------------------------------------------------
void *__stdcall sub_F7FFE0(unsigned int a1)
{
  void *v1; // ecx

  v1 = 0;
  if ( a1 )
  {
    if ( a1 > 0x7FFFFFFF || (v1 = operator new(2 * a1)) == 0 )
      std::_Xbad_alloc();
  }
  return v1;
}

//----- (00F80010) --------------------------------------------------------
int __thiscall sub_F80010(int *this)
{
  int *v1; // edi
  int v2; // ebx
  void **v3; // esi
  int result; // eax

  v1 = this;
  v2 = this[1];
  v3 = *this;
  if ( *this == v2 )
  {
    result = *this;
    this[1] = v3;
  }
  else
  {
    do
    {
      free(*v3);
      ++v3;
    }
    while ( v3 != v2 );
    result = *v1;
    v1[1] = *v1;
  }
  return result;
}

//----- (00F80050) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(std__tree *this, std__Tree_node **a2, std__Tree_node *a3, std__Tree_node *Node)
{
  std__Tree_node *v4; // eax
  std__tree *v5; // esi
  std__Tree_node *_Myhead; // ecx
  std__Tree_node **v7; // eax
  std__Tree_node *v8; // ecx
  int result; // eax
  std__Tree_node *v10; // ecx
  std__Tree_node *i; // edx
  std__Tree_node *v12; // eax
  int v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  _Myhead = this->_Mypair._Myval2._Myhead;
  if ( a3 != _Myhead->_Left || Node != _Myhead )
  {
    for ( ; a3 != Node; v4 = a3 )
    {
      v10 = v4;
      if ( !v4->_IsNil )
      {
        i = v4->_Right;
        if ( i->_IsNil )
        {
          for ( i = v4->_Parent; !i->_IsNil; i = i->_Parent )
          {
            if ( v4 != i->_Right )
              break;
            v4 = i;
          }
        }
        else
        {
          v12 = i->_Left;
          if ( !i->_Left->_IsNil )
          {
            do
            {
              i = v12;
              v12 = v12->_Left;
            }
            while ( !v12->_IsNil );
          }
        }
        a3 = i;
      }
      std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(
        v5,
        &v13,
        v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(_Myhead->_Parent);
    v5->_Mypair._Myval2._Myhead->_Parent = v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Myhead->_Left = v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Myhead->_Right = v5->_Mypair._Myval2._Myhead;
    v7 = &v5->_Mypair._Myval2._Myhead->_Left;
    v5->_Mypair._Myval2._Mysize = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00F80110) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(std__tree *this, int a2, std__Tree_node *a3)
{
  std__Tree_node_For__bstr_t *v3; // ebx
  std__Tree_node *v4; // edi
  std__Tree_node *v5; // ecx
  std__Tree_node *v6; // esi
  std__tree *pThis; // edx
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std__Tree_node *v11; // eax
  std__Tree_node *i; // ecx
  std__Tree_node *v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  std__Tree_node *v16; // ST00_4
  std__Tree_node *v17; // esi
  std__Tree_node *v18; // ST00_4
  Data_t_bstr_t *v19; // edi
  LONG (__stdcall *v20)(volatile LONG *); // ecx
  Data_t_bstr_t *v21; // edi
  std__Tree_node *v22; // eax
  std__Tree_node *v23; // ecx
  int result; // eax
  std__Tree_node *v25; // [esp+Ch] [ebp-8h]
  std__tree *This; // [esp+10h] [ebp-4h]

  v3 = a3;
  This = this;
  sub_F94CE0(&a3);
  if ( v3->_Left->_IsNil )
  {
    v4 = v3->_Right;
LABEL_6:
    v6 = v3->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = v6;
    pThis = This;
    if ( This->_Mypair._Myval2._Myhead->_Parent == v3 )
    {
      This->_Mypair._Myval2._Myhead->_Parent = v4;
    }
    else if ( v6->_Left == v3 )
    {
      v6->_Left = v4;
    }
    else
    {
      v6->_Right = v4;
    }
    v8 = This->_Mypair._Myval2._Myhead;
    if ( This->_Mypair._Myval2._Myhead->_Left == v3 )
    {
      if ( v4->_IsNil )
      {
        v9 = v6;
      }
      else
      {
        v10 = v4->_Left;
        v9 = v4;
        if ( !v4->_Left->_IsNil )
        {
          do
          {
            v9 = v10;
            v10 = v10->_Left;
          }
          while ( !v10->_IsNil );
        }
        v8 = This->_Mypair._Myval2._Myhead;
      }
      v8->_Left = v9;
    }
    if ( This->_Mypair._Myval2._Myhead->_Right == v3 )
    {
      if ( v4->_IsNil )
      {
        This->_Mypair._Myval2._Myhead->_Right = v6;
      }
      else
      {
        v11 = v4->_Right;
        for ( i = v4; !v11->_IsNil; v11 = v11->_Right )
          i = v11;
        This->_Mypair._Myval2._Myhead->_Right = i;
      }
    }
    goto LABEL_37;
  }
  if ( v3->_Right->_IsNil )
  {
    v4 = v3->_Left;
    goto LABEL_6;
  }
  v5 = a3;
  v25 = a3;
  v4 = a3->_Right;
  if ( a3 == v3 )
    goto LABEL_6;
  v3->_Left->_Parent = a3;
  v5->_Left = v3->_Left;
  if ( v5 == v3->_Right )
  {
    v6 = v5;
  }
  else
  {
    v6 = v5->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = v6;
    v6->_Left = v4;
    v5->_Right = v3->_Right;
    v3->_Right->_Parent = v5;
  }
  if ( This->_Mypair._Myval2._Myhead->_Parent == v3 )
  {
    This->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else
  {
    v13 = v3->_Parent;
    if ( v13->_Left == v3 )
      v13->_Left = v5;
    else
      v13->_Right = v5;
  }
  v5->_Parent = v3->_Parent;
  v14 = v5->_Color;
  v25->_Color = v3->_Color;
  pThis = This;
  v3->_Color = v14;
LABEL_37:
  if ( v3->_Color == 1 )
  {
    for ( ; v4 != pThis->_Mypair._Myval2._Myhead->_Parent; v6 = v6->_Parent )
    {
      if ( v4->_Color != 1 )
        break;
      v15 = v6->_Left;
      if ( v4 == v6->_Left )
      {
        v15 = v6->_Right;
        if ( !v15->_Color )
        {
          v15->_Color = 1;
          v6->_Color = 0;
          sub_FF54B0(pThis, v6);
          v15 = v6->_Right;
          pThis = This;
        }
        if ( v15->_IsNil )
          goto LABEL_55;
        if ( v15->_Left->_Color != 1 || v15->_Right->_Color != 1 )
        {
          if ( v15->_Right->_Color == 1 )
          {
            v15->_Left->_Color = 1;
            v15->_Color = 0;
            sub_1002BB0(pThis, v15);
            v15 = v6->_Right;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v16 = v6;
          v17 = This;
          v15->_Right->_Color = 1;
          sub_FF54B0(This, v16);
          v4->_Color = 1;
          goto LABEL_61;
        }
      }
      else
      {
        if ( !v15->_Color )
        {
          v15->_Color = 1;
          v6->_Color = 0;
          sub_1002BB0(pThis, v6);
          v15 = v6->_Left;
          pThis = This;
        }
        if ( v15->_IsNil )
          goto LABEL_55;
        if ( v15->_Right->_Color != 1 || v15->_Left->_Color != 1 )
        {
          if ( v15->_Left->_Color == 1 )
          {
            v15->_Right->_Color = 1;
            v15->_Color = 0;
            sub_FF54B0(pThis, v15);
            v15 = v6->_Left;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v18 = v6;
          v17 = This;
          v15->_Left->_Color = 1;
          sub_1002BB0(This, v18);
          v4->_Color = 1;
          goto LABEL_61;
        }
      }
      v15->_Color = 0;
LABEL_55:
      v4 = v6;
    }
    v17 = This;
    v4->_Color = 1;
  }
  else
  {
    v17 = This;
  }
LABEL_61:
  v19 = v3->_bstrText2.m_Data;
  // void __thiscall tagKeyName___tagKeyName(tagKeyName *this)
  v20 = InterlockedDecrement;
  if ( v19 )
  {
    if ( !InterlockedDecrement(&v19->m_RefCount) && v19 )
    {
      if ( v19->m_wstr )
      {
        SysFreeString(v19->m_wstr);
        v19->m_wstr = 0;
      }
      if ( v19->m_str )
      {
        j_j__free(v19->m_str);
        v19->m_str = 0;
      }
      j__free(v19);
    }
    v20 = InterlockedDecrement;
    v3->_bstrText2.m_Data = 0;
  }
  v21 = v3->_bstrText1.m_Data;
  if ( v21 )
  {
    if ( !v20(&v21->m_RefCount) && v21 )
    {
      if ( v21->m_wstr )
      {
        SysFreeString(v21->m_wstr);
        v21->m_wstr = 0;
      }
      if ( v21->m_str )
      {
        j_j__free(v21->m_str);
        v21->m_str = 0;
      }
      j__free(v21);
    }
    v3->_bstrText1.m_Data = 0;
  }
  j__free(v3);
  v22 = v17->_Parent;
  v23 = a3;
  if ( v22 )
    v17->_Parent = (v22 - 1);
  result = a2;
  *a2 = v23;
  return result;
}

//----- (00F80440) --------------------------------------------------------
UINT __thiscall sub_F80440(BSTR **this)
{
  UINT result; // eax

  if ( *this && **this )
    result = SysStringLen(**this);
  else
    result = 0;
  return result;
}

//----- (00F80460) --------------------------------------------------------
const wchar_t **__thiscall sub_F80460(int *this, const wchar_t **a2)
{
  int *v2; // esi
  const wchar_t **result; // eax
  const wchar_t **v4; // edi
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // ebx

  v2 = this;
  result = this[1];
  v4 = a2;
  if ( a2 >= result || (v5 = *this, *v2 > a2) )
  {
    if ( result == v2[2] )
      result = sub_F7FEE0(v2, 1u);
    v7 = v2[1];
    if ( v7 )
    {
      *v7 = _wcsdup(*a2);
      goto LABEL_11;
    }
  }
  else
  {
    v6 = a2 - v5;
    if ( result == v2[2] )
      result = sub_F7FEE0(v2, 1u);
    v7 = v2[1];
    v4 = (*v2 + (v6 & 0xFFFFFFF0));
    if ( v7 )
    {
      *v7 = _wcsdup(*v4);
LABEL_11:
      result = sub_F735A0((v7 + 4), v4 + 1);
      goto LABEL_12;
    }
  }
LABEL_12:
  v2[1] += 16;
  return result;
}

//----- (00F80530) --------------------------------------------------------
const wchar_t **__thiscall sub_F80530(std__vector *this, const wchar_t **a2)
{
  std__vector *v2; // esi
  const wchar_t **result; // eax
  _BYTE *v4; // ecx
  int v5; // edi
  _DWORD *v6; // ebx

  v2 = this;
  result = this->baseclass_0._Mypair._Myval2._Mylast;
  if ( a2 >= result || (v4 = this->baseclass_0._Mypair._Myval2._Myfirst, v2->baseclass_0._Mypair._Myval2._Myfirst > a2) )
  {
    if ( result == v2->baseclass_0._Mypair._Myval2._Myend )
      result = std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(v2, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = _wcsdup(*a2);
      goto LABEL_11;
    }
  }
  else
  {
    v5 = (a2 - v4) >> 2;
    if ( result == v2->baseclass_0._Mypair._Myval2._Myend )
      result = std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(v2, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = _wcsdup(*(v2->baseclass_0._Mypair._Myval2._Myfirst + v5));
LABEL_11:
      *v6 = result;
      goto LABEL_12;
    }
  }
LABEL_12:
  v2->baseclass_0._Mypair._Myval2._Mylast = v2->baseclass_0._Mypair._Myval2._Mylast + 4;
  return result;
}

//----- (00F805A0) --------------------------------------------------------
void *__cdecl sub_F805A0(int a1, HKEY hKey, LPCWSTR lpszKeyName, LPCWSTR lpValueName)
{
  _bstr_t *v4; // eax
  _bstr_t *v5; // eax
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  Data_t_bstr_t *v8; // esi
  void *v9; // eax
  const WCHAR *v10; // ecx
  void *v11; // eax
  Data_t_bstr_t *v12; // esi
  void *v13; // edi
  _bstr_t v15; // [esp+10h] [ebp-1Ch]
  _bstr_t v16; // [esp+14h] [ebp-18h]
  _bstr_t v17; // [esp+18h] [ebp-14h]
  _bstr_t v18; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&v16, L"AutorunsDisabled");
  v19 = 0;
  v4 = _bstr_t::_bstr_t(&v17, L"\\");
  LOBYTE(v19) = 1;
  v5 = _bstr_t::operator+(&v18, lpszKeyName, v4);
  LOBYTE(v19) = 2;
  _bstr_t::operator+(&v5->m_Data, &v15, &v16);
  v6 = v18.m_Data;
  if ( v18.m_Data )
  {
    if ( !InterlockedDecrement(&v18.m_Data->m_RefCount) && v6 )
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
    v18.m_Data = 0;
  }
  v7 = v17.m_Data;
  if ( v17.m_Data )
  {
    if ( !InterlockedDecrement(&v17.m_Data->m_RefCount) && v7 )
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
    v17.m_Data = 0;
  }
  v8 = v16.m_Data;
  LOBYTE(v19) = 6;
  if ( v16.m_Data && !InterlockedDecrement(&v16.m_Data->m_RefCount) )
  {
    if ( v8->m_wstr )
    {
      SysFreeString(v8->m_wstr);
      v8->m_wstr = 0;
    }
    if ( v8->m_str )
    {
      j_j__free(v8->m_str);
      v8->m_str = 0;
    }
    j__free(v8);
  }
  v9 = sub_F80790(a1, hKey, lpszKeyName, lpValueName, 0xFFFFFFFF);
  if ( v15.m_Data )
    v10 = v15.m_Data->m_wstr;
  else
    v10 = 0;
  v11 = sub_F80790(a1, hKey, v10, lpValueName, v9);
  v12 = v15.m_Data;
  v13 = v11;
  if ( v15.m_Data && !InterlockedDecrement(&v15.m_Data->m_RefCount) && v12 )
  {
    if ( v12->m_wstr )
    {
      SysFreeString(v12->m_wstr);
      v12->m_wstr = 0;
    }
    if ( v12->m_str )
    {
      j_j__free(v12->m_str);
      v12->m_str = 0;
    }
    j__free(v12);
  }
  return v13;
}

//----- (00F80790) --------------------------------------------------------
void *__cdecl sub_F80790(int a1, HKEY hKey, LPCWSTR lpszKeyName, LPCWSTR lpszValueName, HANDLE Handle)
{
  HANDLE v5; // edi
  const WCHAR *v6; // esi
  int v7; // ebx
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  const wchar_t *v10; // eax
  const wchar_t *v11; // eax
  unsigned __int16 **v12; // esi
  unsigned __int16 **v13; // eax
  WCHAR *v15; // eax
  wchar_t *v16; // edi
  DWORD v17; // eax
  _WORD *v18; // eax
  WCHAR *v19; // esi
  wchar_t *v20; // eax
  wchar_t *v21; // esi
  const wchar_t **v22; // eax
  wchar_t *v23; // ebx
  const wchar_t *v24; // ecx
  const wchar_t *v25; // eax
  const wchar_t *v26; // eax
  const wchar_t *v27; // eax
  unsigned __int16 **v28; // esi
  unsigned __int16 **v29; // eax
  char v30; // bl
  LPCWSTR v31; // ebx
  const wchar_t *v32; // eax
  const wchar_t *v33; // eax
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  unsigned __int16 **v36; // esi
  unsigned __int16 **v37; // eax
  int v38; // ST34_4
  int v39; // esi
  const WCHAR **v40; // eax
  const wchar_t *v41; // eax
  unsigned __int16 **v42; // eax
  WCHAR v43[2]; // [esp+10h] [ebp-A4h]
  WCHAR v44[2]; // [esp+14h] [ebp-A0h]
  WCHAR v45[2]; // [esp+18h] [ebp-9Ch]
  WCHAR v46[2]; // [esp+1Ch] [ebp-98h]
  WCHAR v47[2]; // [esp+20h] [ebp-94h]
  int v48; // [esp+24h] [ebp-90h]
  void *v49; // [esp+28h] [ebp-8Ch]
  int a2; // [esp+2Ch] [ebp-88h]
  int v51; // [esp+30h] [ebp-84h]
  int v52; // [esp+34h] [ebp-80h]
  int v53; // [esp+38h] [ebp-7Ch]
  int v54; // [esp+3Ch] [ebp-78h]
  void *v55; // [esp+40h] [ebp-74h]
  void *v56; // [esp+44h] [ebp-70h]
  LPCWSTR v57; // [esp+48h] [ebp-6Ch]
  void *v58; // [esp+4Ch] [ebp-68h]
  LPCWSTR v59; // [esp+50h] [ebp-64h]
  void *v60; // [esp+54h] [ebp-60h]
  LPCWSTR v61; // [esp+58h] [ebp-5Ch]
  WCHAR *ppv3; // [esp+5Ch] [ebp-58h]
  void *v63; // [esp+60h] [ebp-54h]
  LPCWSTR v64; // [esp+64h] [ebp-50h]
  LPCWSTR v65; // [esp+68h] [ebp-4Ch]
  void *v66; // [esp+6Ch] [ebp-48h]
  void *a1a; // [esp+70h] [ebp-44h]
  HKEY hKeya; // [esp+74h] [ebp-40h]
  WCHAR szArg[2]; // [esp+78h] [ebp-3Ch]
  LPCWSTR v70; // [esp+7Ch] [ebp-38h]
  LPCWSTR v71; // [esp+80h] [ebp-34h]
  void *v72; // [esp+84h] [ebp-30h]
  LPCWSTR v73; // [esp+88h] [ebp-2Ch]
  LPCWSTR v74; // [esp+8Ch] [ebp-28h]
  LPCWSTR v75; // [esp+90h] [ebp-24h]
  DWORD cbData; // [esp+94h] [ebp-20h]
  LPCWSTR szArg3; // [esp+98h] [ebp-1Ch]
  WCHAR *pszText; // [esp+9Ch] [ebp-18h]
  LPCWSTR szArg4; // [esp+A0h] [ebp-14h]
  wchar_t *v80; // [esp+A4h] [ebp-10h]
  int v81; // [esp+B0h] [ebp-4h]

  v5 = Handle;
  v6 = lpszValueName;
  v7 = a1;
  if ( Handle == -1 )
  {
    v71 = _wcsdup(&gszNullString);
    v81 = 0;
    v73 = _wcsdup(&gszNullString);
    v70 = _wcsdup(&gszNullString);
    v74 = _wcsdup(&gszNullString);
    v72 = _wcsdup(&gszNullString);
    v80 = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( lpszValueName )
      v8 = lpszValueName;
    szArg4 = _wcsdup(v8);
    v9 = &gszNullString;
    if ( lpszKeyName )
      v9 = lpszKeyName;
    pszText = _wcsdup(v9);
    v10 = &gszNullString;
    if ( lpszValueName )
      v10 = lpszValueName;
    v75 = _wcsdup(v10);
    v11 = &gszNullString;
    if ( lpszKeyName )
      v11 = lpszKeyName;
    szArg3 = _wcsdup(v11);
    LOBYTE(v81) = 9;
    v12 = sub_F77BE0(&a1a, hKey, &pszText, &szArg4);
    LOBYTE(v81) = 10;
    v13 = sub_F77BE0(szArg, hKey, &szArg3, &v75);
    LOBYTE(v81) = 11;
    v5 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v13, v12, &v80);
    Handle = v5;
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v75);
    free(pszText);
    free(szArg4);
    free(v80);
    free(v72);
    free(v74);
    free(v70);
    free(v73);
    v81 = -1;
    free(v71);
    v6 = lpszValueName;
  }
  hKeya = 0;
  PE_OpenKey(hKey, lpszKeyName, 0, KEY_READ, &hKeya);
  if ( !hKeya )
    return v5;
  cbData = 0;
  if ( !RegQueryValueExW(hKeya, v6, 0, 0, 0, &cbData) )
  {
    v15 = malloc(2u);
    pszText = v15;
    *v15 = 0;
    v81 = 12;
    v16 = operator new[](2 * ((cbData >> 1) + 2));
    RegQueryValueExW(hKeya, v6, 0, 0, v16, &cbData);
    v17 = cbData >> 1;
    cbData = v17;
    if ( v17 > 2 )
    {
      v16[v17 - 1] = 0;
      for ( v16[cbData] = 0; *v16; v16 = wcschr(v16 + 1, 0) + 1 )
      {
        v18 = malloc(2u);
        a2 = v18;
        *v18 = 0;
        v51 = 0;
        v52 = 0;
        v53 = 0;
        LOBYTE(v81) = 13;
        sub_F76CC0(v16, &a2);
        v19 = pszText;
        pszText = _wcsdup(v16);
        free(v19);
        sub_F74EE0(&v80, v7, &a2, 0);
        v20 = v80;
        if ( v80 )
        {
          if ( !_wcsnicmp(v80, L"File not found: ", 0x10u) && !_wcsnicmp(v16, L"autocheck ", 0xAu) )
          {
            v21 = _wcsdup(v16);
            v54 = v21;
            LOBYTE(v81) = 15;
            sub_F76CC0((v16 + 10), &a2);
            v22 = sub_F74EE0(&v49, v7, &a2, 0);
            v23 = v80;
            v80 = _wcsdup(*v22);
            free(v23);
            free(v49);
            free(v21);
            v7 = a1;
          }
          v20 = v80;
        }
        if ( *v20 )
        {
          szArg4 = malloc(2u);
          *szArg4 = 0;
          szArg3 = malloc(2u);
          *szArg3 = 0;
          v75 = malloc(2u);
          *v75 = 0;
          LOBYTE(v81) = 18;
          v54 = sub_F74ED0();
          v72 = _wcsdup(v16);
          v24 = &gszNullString;
          if ( lpszValueName )
            v24 = lpszValueName;
          v74 = _wcsdup(v24);
          v25 = &gszNullString;
          if ( lpszKeyName )
            v25 = lpszKeyName;
          v70 = _wcsdup(v25);
          v26 = &gszNullString;
          if ( lpszValueName )
            v26 = lpszValueName;
          v73 = _wcsdup(v26);
          v27 = &gszNullString;
          if ( lpszKeyName )
            v27 = lpszKeyName;
          v71 = _wcsdup(v27);
          LOBYTE(v81) = 23;
          v28 = sub_F77BE0(v43, hKey, &v70, &v74);
          LOBYTE(v81) = 24;
          v29 = sub_F77BE0(v47, hKey, &v71, &v73);
          LOBYTE(v81) = 25;
          v30 = sub_F73D40(v7, v29, v28, &v72, &v80, &szArg4, &v75, &v48);
          free(*v47);
          free(*v43);
          free(v71);
          free(v73);
          free(v70);
          free(v74);
          free(v72);
          if ( v30 )
          {
            if ( Handle == -1 )
            {
              v58 = _wcsdup(&gszNullString);
              v56 = _wcsdup(&gszNullString);
              v60 = _wcsdup(&gszNullString);
              v55 = _wcsdup(&gszNullString);
              v66 = _wcsdup(&gszNullString);
              v63 = _wcsdup(&gszNullString);
              v31 = lpszValueName;
              v32 = &gszNullString;
              if ( lpszValueName )
                v32 = lpszValueName;
              v59 = _wcsdup(v32);
              v33 = &gszNullString;
              if ( lpszKeyName )
                v33 = lpszKeyName;
              v64 = _wcsdup(v33);
              v34 = &gszNullString;
              if ( lpszValueName )
                v34 = lpszValueName;
              v65 = _wcsdup(v34);
              v35 = &gszNullString;
              if ( lpszKeyName )
                v35 = lpszKeyName;
              v57 = _wcsdup(v35);
              LOBYTE(v81) = 35;
              v36 = sub_F77BE0(v46, hKey, &v64, &v59);
              LOBYTE(v81) = 36;
              v37 = sub_F77BE0(v44, hKey, &v57, &v65);
              LOBYTE(v81) = 37;
              v38 = v36;
              v39 = a1;
              Handle = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v37, v38, &v63);
              free(*v44);
              free(*v46);
              free(v57);
              free(v65);
              free(v64);
              free(v59);
              free(v63);
              free(v66);
              free(v55);
              free(v60);
              free(v56);
              free(v58);
            }
            else
            {
              v39 = a1;
              v31 = lpszValueName;
            }
            *szArg = _wcsdup(&gszNullString);
            v40 = &gszNullString;
            if ( v31 )
              v40 = v31;
            a1a = _wcsdup(v40);
            v41 = &gszNullString;
            if ( lpszKeyName )
              v41 = lpszKeyName;
            v61 = _wcsdup(v41);
            ppv3 = _wcsdup(v16);
            LOBYTE(v81) = 41;
            v42 = sub_F77BE0(v45, hKey, &v61, &a1a);
            LOBYTE(v81) = 42;
            sub_F73FF0(v39, v54, Handle, 5, &ppv3, v42, &v80);
            free(*v45);
            free(ppv3);
            free(v61);
            free(a1a);
            free(*szArg);
          }
          free(v75);
          free(szArg3);
          free(szArg4);
          v20 = v80;
        }
        free(v20);
        LOBYTE(v81) = 12;
        sub_F721F0(&a2);
        v7 = a1;
      }
    }
    free(pszText);
  }
  RegCloseKey(hKeya);
  return Handle;
}

//----- (00F80F50) --------------------------------------------------------
int __cdecl RequerySystemEnvironmentString(WCHAR **ppstr, LPCWSTR lpszName)
{
  DWORD nLength; // eax
  DWORD v3; // edi
  WCHAR *pBuffer; // eax
  size_t v5; // edi
  WCHAR *v6; // eax
  DWORD nSize; // [esp+Ch] [ebp-4h]

  nLength = ExpandEnvironmentStringsW(lpszName, 0, 0);
  v3 = nLength;
  nSize = nLength;
  pBuffer = malloc(2u);
  v5 = 2 * v3 + 2;
  *ppstr = pBuffer;
  *pBuffer = 0;
  v6 = realloc(*ppstr, v5);
  *ppstr = v6;
  if ( v6 )
    memset(v6, 0, v5);
  ExpandEnvironmentStringsW(lpszName, *ppstr, nSize);
  return ppstr;
}

//----- (00F80FC0) --------------------------------------------------------
HANDLE __cdecl sub_F80FC0(OLECHAR *psz, LPWIN32_FIND_DATAW lpFindFileData)
{
  Data_t_bstr_t *v2; // esi
  const WCHAR *v3; // eax
  HANDLE v4; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_F77AB0(&gKeyNameMap, &bstrText, psz);
  v2 = bstrText.m_Data;
  if ( bstrText.m_Data )
    v3 = bstrText.m_Data->m_wstr;
  else
    v3 = 0;
  v4 = FindFirstFileW(v3, lpFindFileData);
  if ( v2 && !InterlockedDecrement(&v2->m_RefCount) )
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
  return v4;
}

//----- (00F81040) --------------------------------------------------------
DWORD __cdecl sub_F81040(OLECHAR *psz)
{
  Data_t_bstr_t *v1; // esi
  const WCHAR *v2; // eax
  DWORD v3; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_F77AB0(&gKeyNameMap, &bstrText, psz);
  v1 = bstrText.m_Data;
  if ( bstrText.m_Data )
    v2 = bstrText.m_Data->m_wstr;
  else
    v2 = 0;
  v3 = GetFileAttributesW(v2);
  if ( v1 && !InterlockedDecrement(&v1->m_RefCount) )
  {
    if ( v1->m_wstr )
    {
      SysFreeString(v1->m_wstr);
      v1->m_wstr = 0;
    }
    if ( v1->m_str )
    {
      j_j__free(v1->m_str);
      v1->m_str = 0;
    }
    j__free(v1);
  }
  return v3;
}

//----- (00F810C0) --------------------------------------------------------
DWORD_PTR __cdecl sub_F810C0(OLECHAR *psz, DWORD dwFileAttributes, SHFILEINFOW *psfi, UINT cbFileInfo, UINT uFlags)
{
  Data_t_bstr_t *v5; // esi
  const WCHAR *v6; // eax
  DWORD_PTR v7; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_F77AB0(&gKeyNameMap, &bstrText, psz);
  v5 = bstrText.m_Data;
  if ( bstrText.m_Data )
    v6 = bstrText.m_Data->m_wstr;
  else
    v6 = 0;
  v7 = SHGetFileInfoW(v6, dwFileAttributes, psfi, cbFileInfo, uFlags);
  if ( v5 && !InterlockedDecrement(&v5->m_RefCount) )
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
  return v7;
}

//----- (00F81150) --------------------------------------------------------
bool __cdecl sub_F81150(int a1, wchar_t *a2, WCHAR *psz, int a4)
{
  int v4; // eax
  Data_t_bstr_t *bstrFileName; // esi
  const WCHAR *v6; // eax
  void *v7; // ebx
  bool v8; // bl
  const wchar_t *v9; // ecx
  wchar_t *v10; // edi
  bool v11; // zf
  const wchar_t *v12; // esi
  wchar_t *v13; // ebx
  unsigned int v14; // ecx
  WCHAR *v15; // edx
  WCHAR v16; // ax
  size_t v17; // esi
  const WCHAR **v18; // ecx
  WCHAR *v19; // ebx
  Data_t_bstr_t *v20; // esi
  const WCHAR *v21; // eax
  DWORD v22; // eax
  void *v24; // ebx
  int dwFileAttributes; // [esp+14h] [ebp-18h]
  LPCWSTR lpszKey; // [esp+18h] [ebp-14h]
  const wchar_t *v27; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+28h] [ebp-4h]

  v4 = *psz;
  if ( v4 && psz[1] == ':' || v4 == '\\' )
  {
    sub_F77AB0(&gKeyNameMap, &dwFileAttributes, psz);
    bstrFileName = dwFileAttributes;
    if ( dwFileAttributes )
      v6 = *dwFileAttributes;
    else
      v6 = 0;
    dwFileAttributes = GetFileAttributesW(v6);
    v7 = *a4;
    *a4 = _wcsdup(psz);
    free(v7);
    v8 = dwFileAttributes != -1 && !(dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    if ( bstrFileName && !InterlockedDecrement(&bstrFileName->m_RefCount) )
    {
      if ( bstrFileName->m_wstr )
      {
        SysFreeString(bstrFileName->m_wstr);
        bstrFileName->m_wstr = 0;
      }
      if ( bstrFileName->m_str )
      {
        j_j__free(bstrFileName->m_str);
        bstrFileName->m_str = 0;
      }
      j__free(bstrFileName);
    }
  }
  else
  {
    v9 = &gszNullString;
    if ( a2 )
      v9 = a2;
    v10 = _wcsdup(v9);
    v11 = *v10 == 0;
    v12 = v10;
    v28 = 0;
    v27 = v10;
    if ( v11 )
    {
LABEL_42:
      v8 = 0;
    }
    else
    {
      while ( 1 )
      {
        v13 = wcschr(v12, ';');
        if ( v13 )
          *v13 = 0;
        v14 = wcslen(v12);
        v15 = psz;
        do
        {
          v16 = *v15;
          ++v15;
        }
        while ( v16 );
        v17 = v15 - (psz + 1) + v14 + 2;
        lpszKey = malloc(2 * v17);
        swprintf_s(lpszKey, v17, L"%s\\%s", v27, psz);
        if ( v13 )
        {
          v18 = (v13 + 1);
          *v13 = 59;
        }
        else
        {
          v18 = &gszNullString;
        }
        v19 = lpszKey;
        v27 = v18;
        sub_F77AB0(&gKeyNameMap, &dwFileAttributes, lpszKey);
        v20 = dwFileAttributes;
        v21 = (dwFileAttributes ? *dwFileAttributes : 0);
        v22 = GetFileAttributesW(v21);
        if ( v22 != -1 && !(v22 & 0x10) )
          break;
        free(v19);
        if ( v20 )
        {
          if ( !InterlockedDecrement(&v20->m_RefCount) )
          {
            if ( v20->m_wstr )
            {
              SysFreeString(v20->m_wstr);
              v20->m_wstr = 0;
            }
            if ( v20->m_str )
            {
              j_j__free(v20->m_str);
              v20->m_str = 0;
            }
            j__free(v20);
          }
          dwFileAttributes = 0;
        }
        v12 = v27;
        if ( !*v27 )
          goto LABEL_42;
      }
      v24 = *a4;
      *a4 = _wcsdup(lpszKey);
      free(v24);
      free(lpszKey);
      _bstr_t::_Free(&dwFileAttributes);
      v8 = 1;
    }
    free(v10);
  }
  return v8;
}

//----- (00F813D0) --------------------------------------------------------
LSTATUS __cdecl PE_LoadKey(HKEY hKey, DWORD dwIndex, WCHAR **ppszKey)
{
  LSTATUS result; // eax
  DWORD v4; // eax
  size_t v5; // ebx
  WCHAR *v6; // eax
  DWORD cbMaxSubKeyLen; // [esp+0h] [ebp-4h]

  cbMaxSubKeyLen = 0;
  result = RegQueryInfoKeyW(hKey, 0, 0, 0, 0, &cbMaxSubKeyLen, 0, 0, 0, 0, 0, 0);
  if ( !result )
  {
    v4 = cbMaxSubKeyLen + 1;
    cbMaxSubKeyLen = v4;
    v5 = 2 * v4 + 2;
    v6 = realloc(*ppszKey, v5);
    *ppszKey = v6;
    if ( v6 )
      memset(v6, 0, v5);
    result = RegEnumKeyW(hKey, dwIndex, *ppszKey, cbMaxSubKeyLen);
  }
  return result;
}

//----- (00F81450) --------------------------------------------------------
LSTATUS __cdecl sub_F81450(HKEY hKey, DWORD dwIndex, int a3, LPDWORD lpReserved, LPDWORD lpType, int a6)
{
  LSTATUS result; // eax
  size_t v7; // esi
  void *v8; // eax
  size_t v9; // esi
  void *v10; // eax
  DWORD cbMaxValueLen; // [esp+0h] [ebp-8h]
  DWORD cbMaxValueNameLen; // [esp+4h] [ebp-4h]

  cbMaxValueNameLen = 0;
  cbMaxValueLen = 0;
  result = RegQueryInfoKeyW(hKey, 0, 0, 0, 0, 0, 0, 0, &cbMaxValueNameLen, &cbMaxValueLen, 0, 0);
  if ( !result )
  {
    v7 = 2 * (cbMaxValueNameLen++ + 1) + 2;
    v8 = realloc(*a3, v7);
    *a3 = v8;
    if ( v8 )
      memset(v8, 0, v7);
    v9 = 2 * (((cbMaxValueLen + 1) >> 1) + 1);
    v10 = realloc(*a6, 2 * (((cbMaxValueLen + 1) >> 1) + 1));
    *a6 = v10;
    if ( v10 )
      memset(v10, 0, v9);
    result = RegEnumValueW(hKey, dwIndex, *a3, &cbMaxValueNameLen, lpReserved, lpType, *a6, &cbMaxValueLen);
  }
  return result;
}

//----- (00F81520) --------------------------------------------------------
LSTATUS __cdecl sub_F81520(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, int a5)
{
  LSTATUS result; // eax
  void *v6; // eax
  DWORD v7; // [esp+0h] [ebp-8h]
  DWORD cbData; // [esp+4h] [ebp-4h]

  cbData = 0;
  result = RegQueryValueExW(hKey, lpValueName, lpReserved, 0, 0, &cbData);
  if ( !result )
  {
    v7 = 2 * (((cbData + 1) >> 1) + 1);
    v6 = realloc(*a5, 2 * (((cbData + 1) >> 1) + 1));
    *a5 = v6;
    if ( v6 )
      memset(v6, 0, v7);
    result = RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, *a5, &cbData);
  }
  return result;
}

//----- (00F815A0) --------------------------------------------------------
LSTATUS __cdecl sub_F815A0(HKEY hKey, LPCWSTR lpSubKey, int a3)
{
  LSTATUS result; // eax
  void *v4; // eax
  unsigned int v5; // [esp+0h] [ebp-8h]
  LONG cbData; // [esp+4h] [ebp-4h]

  cbData = 0;
  result = RegQueryValueW(hKey, lpSubKey, 0, &cbData);
  if ( !result )
  {
    v5 = 2 * (((cbData + 1) >> 1) + 1);
    v4 = realloc(*a3, 2 * (((cbData + 1) >> 1) + 1));
    *a3 = v4;
    if ( v4 )
      memset(v4, 0, v5);
    result = RegQueryValueW(hKey, lpSubKey, *a3, &cbData);
  }
  return result;
}

//----- (00F81610) --------------------------------------------------------
void *__cdecl sub_F81610(int a1, void *a2, wchar_t *psz)
{
  DWORD v3; // ebx
  wchar_t *v4; // eax
  wchar_t *v5; // eax
  WCHAR *v6; // eax
  _WORD *v7; // eax
  _WORD *v8; // eax
  _WORD *v9; // eax
  _WORD *v10; // eax
  _WORD *v11; // eax
  const wchar_t *v12; // eax
  const wchar_t *v13; // eax
  unsigned __int16 **v14; // esi
  unsigned __int16 **v15; // eax
  void *v16; // esi
  LSTATUS (__stdcall *v17)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // esi
  LSTATUS v18; // eax
  void *v19; // esi
  WCHAR *v20; // eax
  const wchar_t **v21; // eax
  wchar_t *v22; // esi
  const wchar_t **v23; // eax
  void *v24; // esi
  HMODULE v25; // eax
  FARPROC v26; // eax
  size_t v27; // esi
  void *v28; // eax
  WCHAR *v29; // esi
  const wchar_t *v30; // eax
  const wchar_t *v31; // eax
  unsigned __int16 **v32; // esi
  unsigned __int16 **v33; // eax
  char v34; // bl
  const wchar_t *v35; // eax
  const wchar_t *v36; // eax
  unsigned __int16 **v37; // esi
  unsigned __int16 **v38; // eax
  const wchar_t *v39; // eax
  unsigned __int16 **v40; // eax
  BYTE v42; // [esp+10h] [ebp-2C4h]
  void *v43; // [esp+14h] [ebp-2C0h]
  BYTE v44[4]; // [esp+18h] [ebp-2BCh]
  BYTE Data[4]; // [esp+1Ch] [ebp-2B8h]
  WCHAR v46[2]; // [esp+20h] [ebp-2B4h]
  WCHAR *ppv; // [esp+24h] [ebp-2B0h]
  int a2a; // [esp+28h] [ebp-2ACh]
  WCHAR v49[2]; // [esp+2Ch] [ebp-2A8h]
  int v50; // [esp+30h] [ebp-2A4h]
  WCHAR *pszResult; // [esp+34h] [ebp-2A0h]
  WCHAR v52[2]; // [esp+38h] [ebp-29Ch]
  WCHAR v53[2]; // [esp+3Ch] [ebp-298h]
  WCHAR v54[2]; // [esp+40h] [ebp-294h]
  void *v55; // [esp+44h] [ebp-290h]
  void *v56; // [esp+48h] [ebp-28Ch]
  void *v57; // [esp+4Ch] [ebp-288h]
  void *v58; // [esp+50h] [ebp-284h]
  void *a1a; // [esp+54h] [ebp-280h]
  void *v60; // [esp+58h] [ebp-27Ch]
  void *ppv1; // [esp+5Ch] [ebp-278h]
  WCHAR szArg[2]; // [esp+60h] [ebp-274h]
  HKEY hRootKey; // [esp+64h] [ebp-270h]
  DWORD v64; // [esp+68h] [ebp-26Ch]
  LPCWSTR v65; // [esp+6Ch] [ebp-268h]
  WCHAR *pszText; // [esp+70h] [ebp-264h]
  LPCWSTR v67; // [esp+74h] [ebp-260h]
  LPCWSTR szArg3; // [esp+78h] [ebp-25Ch]
  WCHAR *ppv3; // [esp+7Ch] [ebp-258h]
  LPCWSTR v70; // [esp+80h] [ebp-254h]
  LPCWSTR v71; // [esp+84h] [ebp-250h]
  LPCWSTR v72; // [esp+88h] [ebp-24Ch]
  LPCWSTR szArg4; // [esp+8Ch] [ebp-248h]
  LPCWSTR v74; // [esp+90h] [ebp-244h]
  LPCWSTR v75; // [esp+94h] [ebp-240h]
  int v76; // [esp+98h] [ebp-23Ch]
  void *v77; // [esp+9Ch] [ebp-238h]
  wchar_t *v78; // [esp+A0h] [ebp-234h]
  void *v79; // [esp+A4h] [ebp-230h]
  HKEY v80; // [esp+A8h] [ebp-22Ch]
  DWORD cbData; // [esp+ACh] [ebp-228h]
  void *v82; // [esp+B0h] [ebp-224h]
  HKEY hKey; // [esp+B4h] [ebp-220h]
  wchar_t *ppszText2; // [esp+B8h] [ebp-21Ch]
  wchar_t Src; // [esp+BCh] [ebp-218h]
  int v86; // [esp+2D0h] [ebp-4h]

  v3 = 0;
  v76 = a1;
  v80 = a2;
  v64 = 0;
  v4 = malloc(2u);
  v78 = v4;
  *v4 = 0;
  v86 = 0;
  v5 = malloc(2u);
  ppszText2 = v5;
  *v5 = 0;
  v6 = malloc(2u);
  ppv3 = v6;
  *v6 = 0;
  v7 = malloc(2u);
  v79 = v7;
  *v7 = 0;
  v8 = malloc(2u);
  v60 = v8;
  *v8 = 0;
  v9 = malloc(2u);
  v82 = v9;
  *v9 = 0;
  v10 = malloc(2u);
  v58 = v10;
  *v10 = 0;
  v11 = malloc(2u);
  v77 = v11;
  *v11 = 0;
  v72 = _wcsdup(&gszNullString);
  v65 = _wcsdup(&gszNullString);
  v67 = _wcsdup(&gszNullString);
  v75 = _wcsdup(&gszNullString);
  v71 = _wcsdup(&gszNullString);
  v74 = _wcsdup(&gszNullString);
  szArg4 = _wcsdup(&gszNullString);
  v12 = &gszNullString;
  if ( psz )
    v12 = psz;
  pszText = _wcsdup(v12);
  v70 = _wcsdup(&gszNullString);
  v13 = &gszNullString;
  if ( psz )
    v13 = psz;
  szArg3 = _wcsdup(v13);
  LOBYTE(v86) = 17;
  v14 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
  LOBYTE(v86) = 18;
  v15 = sub_F77BE0(szArg, v80, &szArg3, &v70);
  LOBYTE(v86) = 19;
  v16 = sub_F73FF0(v76, 0, 0xFFFFFFFF, 0, v15, v14, &v74);
  ppv1 = v16;
  free(*szArg);
  free(a1a);
  free(szArg3);
  free(v70);
  free(pszText);
  free(szArg4);
  free(v74);
  free(v71);
  free(v75);
  free(v67);
  free(v65);
  LOBYTE(v86) = 7;
  free(v72);
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hRootKey) )
  {
    if ( !PE_LoadKey(hRootKey, 0, &ppszText2) )
    {
      v17 = RegQueryValueExW;
      do
      {
        if ( !PE_OpenKey(hRootKey, ppszText2, 0, 0x20019u, &hKey) )
        {
          cbData = 4;
          if ( !v17(hKey, L"Type", 0, 0, Data, &cbData) && *Data <= 2u )
          {
            cbData = 4;
            if ( !v17(hKey, L"Start", 0, 0, v44, &cbData) )
            {
              cbData = 4;
              if ( *v44 != 4 || !v17(hKey, L"AutorunsDisabled", 0, 0, &v42, &cbData) )
              {
                v18 = sub_F81520(hKey, L"ImagePath", 0, 0, &v78);
                v19 = v77;
                if ( v18 )
                {
                  v77 = _wcsdup(ppszText2);
                  free(v19);
                  v20 = PE_CopyString2(&pszResult, L"\\SystemRoot\\System32\\Drivers\\", &ppszText2);
                  v21 = PE_CopyString(&ppv, v20, L".sys");
                  v22 = v78;
                  v78 = _wcsdup(*v21);
                  free(v22);
                  free(ppv);
                  free(pszResult);
                }
                else
                {
                  v77 = _wcsdup(v78);
                  free(v19);
                }
                v23 = sub_F74F20(&v43, v76, v78);
                v24 = v79;
                v79 = _wcsdup(*v23);
                free(v24);
                free(v43);
                a2a = sub_F74ED0();
                sub_F81520(hKey, L"Description", 0, 0, &v82);
                if ( *v82 == 64 )
                {
                  v25 = LoadLibraryW(L"Advapi32.dll");
                  v26 = GetProcAddress(v25, "RegLoadMUIStringW");
                  dword_1064C4C = v26;
                  if ( v26 )
                  {
                    if ( !(v26)(hKey, L"Description", &Src, 260, &cbData, 0, 0) )
                    {
                      v27 = 2 * cbData + 4;
                      v28 = realloc(v82, v27);
                      v82 = v28;
                      if ( v28 )
                      {
                        memset(v28, 0, v27);
                        v28 = v82;
                      }
                      sub_F747C0(&Src, v28, cbData + 1);
                    }
                  }
                }
                v29 = ppv3;
                ppv3 = _wcsdup(ppszText2);
                free(v29);
                v30 = &gszNullString;
                if ( psz )
                  v30 = psz;
                v67 = _wcsdup(v30);
                v65 = _wcsdup(&gszNullString);
                v31 = &gszNullString;
                if ( psz )
                  v31 = psz;
                v72 = _wcsdup(v31);
                LOBYTE(v86) = 22;
                v32 = sub_F77BE0(v54, v80, &v67, &ppszText2);
                LOBYTE(v86) = 23;
                v33 = sub_F77BE0(v49, v80, &v72, &v65);
                LOBYTE(v86) = 24;
                v34 = sub_F73D40(v76, v33, v32, &ppv3, &v79, &v60, &v58, &v50);
                free(*v49);
                free(*v54);
                free(v72);
                free(v65);
                LOBYTE(v86) = 7;
                free(v67);
                if ( v34 )
                {
                  if ( ppv1 == -1 )
                  {
                    v57 = _wcsdup(&gszNullString);
                    v56 = _wcsdup(&gszNullString);
                    v55 = _wcsdup(&gszNullString);
                    szArg3 = _wcsdup(&gszNullString);
                    v70 = _wcsdup(&gszNullString);
                    pszText = _wcsdup(&gszNullString);
                    szArg4 = _wcsdup(&gszNullString);
                    v35 = &gszNullString;
                    if ( psz )
                      v35 = psz;
                    v74 = _wcsdup(v35);
                    v71 = _wcsdup(&gszNullString);
                    v36 = &gszNullString;
                    if ( psz )
                      v36 = psz;
                    v75 = _wcsdup(v36);
                    LOBYTE(v86) = 34;
                    v37 = sub_F77BE0(v52, v80, &v74, &szArg4);
                    LOBYTE(v86) = 35;
                    v38 = sub_F77BE0(v53, v80, &v75, &v71);
                    LOBYTE(v86) = 36;
                    ppv1 = sub_F73FF0(v76, 0, 0xFFFFFFFF, 0, v38, v37, &pszText);
                    free(*v53);
                    free(*v52);
                    free(v75);
                    free(v71);
                    free(v74);
                    free(szArg4);
                    free(pszText);
                    free(v70);
                    free(szArg3);
                    free(v55);
                    free(v56);
                    free(v57);
                  }
                  *szArg = _wcsdup(&gszNullString);
                  v39 = &gszNullString;
                  if ( psz )
                    v39 = psz;
                  a1a = _wcsdup(v39);
                  LOBYTE(v86) = 38;
                  v40 = sub_F77BE0(v46, v80, &a1a, &ppszText2);
                  LOBYTE(v86) = 39;
                  sub_F73FF0(v76, a2a, ppv1, 13, &ppv3, v40, &v79);
                  free(*v46);
                  free(a1a);
                  LOBYTE(v86) = 7;
                  free(*szArg);
                }
                v17 = RegQueryValueExW;
                v3 = v64;
              }
            }
          }
          RegCloseKey(hKey);
        }
        v64 = ++v3;
      }
      while ( !PE_LoadKey(hRootKey, v3, &ppszText2) );
      v16 = ppv1;
    }
    RegCloseKey(hRootKey);
  }
  free(v77);
  free(v58);
  free(v82);
  free(v60);
  free(v79);
  free(ppv3);
  free(ppszText2);
  free(v78);
  return v16;
}
// 1064C4C: using guessed type int dword_1064C4C;

//----- (00F82060) --------------------------------------------------------
void *__cdecl sub_F82060(int a1, int a2, int *a3)
{
  void *v3; // eax

  v3 = sub_F82090(a1, a2, *a3, 0xFFFFFFFF, 1);
  return sub_F82090(a1, a2, *a3, v3, 0);
}

//----- (00F82090) --------------------------------------------------------
void *__cdecl sub_F82090(int a1, int a2, int a3, void *a4, char a5)
{
  wchar_t *v5; // edi
  const wchar_t *v6; // ecx
  const WCHAR **v7; // eax
  wchar_t *v8; // esi
  WCHAR *v9; // eax
  const wchar_t **v10; // eax
  void *v11; // ebx
  WCHAR *v12; // ebx
  unsigned int v13; // eax
  void (__stdcall *v14)(HKEY); // esi
  WCHAR *v15; // ebx
  _WORD *v16; // eax
  WCHAR *v17; // eax
  WCHAR *v18; // esi
  _WORD *v19; // eax
  WCHAR *v20; // eax
  WCHAR *v21; // edi
  WCHAR *v22; // ebx
  LPCWSTR *v23; // eax
  unsigned __int16 **v24; // eax
  LPCWSTR *v25; // eax
  unsigned __int16 **v26; // eax
  WCHAR *v27; // ebx
  int v28; // ebx
  LPCWSTR *v29; // eax
  int v30; // ebx
  void **v31; // ebx
  void **v32; // esi
  unsigned int v33; // eax
  LSTATUS v34; // eax
  tagKeyName *v35; // esi
  unsigned int v36; // eax
  void *v37; // esi
  wchar_t *v38; // eax
  void *v39; // esi
  WCHAR *v40; // esi
  unsigned int v41; // eax
  LSTATUS v42; // eax
  int v43; // ebx
  tagKeyName *v44; // esi
  unsigned int v45; // eax
  WCHAR *v46; // eax
  LPCWSTR *v47; // eax
  unsigned __int16 **v48; // eax
  LPCWSTR *v49; // eax
  unsigned __int16 **v50; // eax
  wchar_t *v51; // esi
  const wchar_t **v52; // eax
  WCHAR *v53; // esi
  void **v54; // ecx
  const wchar_t **v55; // eax
  WCHAR *v56; // esi
  LPCWSTR *v57; // eax
  unsigned __int16 **v58; // eax
  LPCWSTR *v59; // eax
  unsigned __int16 **v60; // eax
  void *v61; // esi
  int v63; // [esp+10h] [ebp-118h]
  int a2a; // [esp+20h] [ebp-108h]
  HKEY v65; // [esp+24h] [ebp-104h]
  wchar_t *v66; // [esp+28h] [ebp-100h]
  WCHAR *v67; // [esp+2Ch] [ebp-FCh]
  int v68; // [esp+30h] [ebp-F8h]
  WCHAR *v69; // [esp+34h] [ebp-F4h]
  WCHAR *ppv1; // [esp+38h] [ebp-F0h]
  HKEY KeyHandle; // [esp+3Ch] [ebp-ECh]
  WCHAR *v72; // [esp+40h] [ebp-E8h]
  WCHAR *v73; // [esp+44h] [ebp-E4h]
  wchar_t *psz; // [esp+48h] [ebp-E0h]
  void *v75; // [esp+4Ch] [ebp-DCh]
  void *v76; // [esp+50h] [ebp-D8h]
  void **v77; // [esp+54h] [ebp-D4h]
  int v78; // [esp+58h] [ebp-D0h]
  WCHAR szText2[2]; // [esp+5Ch] [ebp-CCh]
  HKEY v80; // [esp+60h] [ebp-C8h]
  WCHAR *v81; // [esp+64h] [ebp-C4h]
  WCHAR *ppv3; // [esp+68h] [ebp-C0h]
  void *v83; // [esp+6Ch] [ebp-BCh]
  void *v84; // [esp+70h] [ebp-B8h]
  void *v85; // [esp+74h] [ebp-B4h]
  WCHAR v86[2]; // [esp+78h] [ebp-B0h]
  void *v87; // [esp+7Ch] [ebp-ACh]
  void *v88; // [esp+80h] [ebp-A8h]
  int a1a; // [esp+84h] [ebp-A4h]
  void *v90; // [esp+88h] [ebp-A0h]
  HKEY hRootKey; // [esp+8Ch] [ebp-9Ch]
  void *v92; // [esp+90h] [ebp-98h]
  HKEY__ v93; // [esp+94h] [ebp-94h]
  WCHAR *ppv; // [esp+98h] [ebp-90h]
  WCHAR *v95; // [esp+9Ch] [ebp-8Ch]
  WCHAR *v96; // [esp+A0h] [ebp-88h]
  WCHAR *v97; // [esp+A4h] [ebp-84h]
  void *v98; // [esp+A8h] [ebp-80h]
  WCHAR *v99; // [esp+ACh] [ebp-7Ch]
  HKEY__ v100; // [esp+B0h] [ebp-78h]
  WCHAR *v101; // [esp+B4h] [ebp-74h]
  WCHAR *v102; // [esp+B8h] [ebp-70h]
  WCHAR *v103; // [esp+BCh] [ebp-6Ch]
  HKEY__ v104; // [esp+C0h] [ebp-68h]
  HKEY hKey; // [esp+C4h] [ebp-64h]
  LPCWSTR lpAppName; // [esp+C8h] [ebp-60h]
  HKEY__ v107; // [esp+CCh] [ebp-5Ch]
  LPCWSTR v108; // [esp+D0h] [ebp-58h]
  WCHAR *v109; // [esp+D4h] [ebp-54h]
  LPCWSTR lpFileName; // [esp+D8h] [ebp-50h]
  WCHAR KeyName; // [esp+DCh] [ebp-4Ch]
  int v112; // [esp+124h] [ebp-4h]

  a1a = a1;
  hRootKey = a2;
  psz = a3;
  hKey = 0;
  v108 = malloc(2u);
  *v108 = 0;
  v112 = 0;
  v5 = malloc(2u);
  v66 = v5;
  *v5 = 0;
  v107.unused = malloc(2u);
  *v107.unused = 0;
  lpAppName = malloc(2u);
  *lpAppName = 0;
  *v86 = malloc(2u);
  **v86 = 0;
  *szText2 = malloc(2u);
  **szText2 = 0;
  v104.unused = malloc(2u);
  *v104.unused = 0;
  v93.unused = malloc(2u);
  *v93.unused = 0;
  v98 = malloc(2u);
  *v98 = 0;
  v88 = malloc(2u);
  *v88 = 0;
  v96 = malloc(2u);
  v103 = v96;
  *v96 = 0;
  v90 = malloc(2u);
  *v90 = 0;
  v6 = L"HKCU";
  LOBYTE(v112) = 11;
  if ( a2 != ghCurrentUserKey )
    v6 = L"HKLM";
  v7 = &gszNullString;
  if ( v6 )
    v7 = v6;
  v8 = _wcsdup(v7);
  v100.unused = v8;
  v9 = PE_CopyString(&ppv, &v100, L"\\");
  v10 = PE_CopyString(&v97, v9, psz);
  v11 = v107.unused;
  v107.unused = _wcsdup(*v10);
  free(v11);
  free(v97);
  free(ppv);
  free(v8);
  if ( a4 == -1 )
  {
    v102 = _wcsdup(&gszNullString);
    v101 = _wcsdup(&gszNullString);
    v95 = _wcsdup(&gszNullString);
    v99 = _wcsdup(&gszNullString);
    lpFileName = _wcsdup(&gszNullString);
    v109 = _wcsdup(&gszNullString);
    LOBYTE(v112) = 17;
    a4 = sub_F73FF0(a1a, 0, 0xFFFFFFFF, 0, &v107, &v107, &v109);
    free(v109);
    free(lpFileName);
    free(v99);
    free(v95);
    free(v101);
    LOBYTE(v112) = 11;
    free(v102);
  }
  v12 = _wcsdup(psz);
  v103 = v12;
  free(v96);
  if ( !a5 )
  {
    CopyStringToString(&v103, L"\\AutorunsDisabled", 0x7FFFFFFFu, 0);
    v12 = v103;
  }
  v13 = TlsGetValue(gdwTlsIndex);
  v14 = RegCloseKey;
  if ( !PE_OpenKey(hRootKey, v12, 0, v13 | 0x20019, &hKey) )
  {
    v100.unused = 0;
    if ( !sub_F81450(hKey, 0, &lpAppName, 0, 0, &v104) )
    {
      do
      {
        PE_CopyString(&lpFileName, &v104, L"\\Scripts.Ini");
        if ( GetFileAttributesW(lpFileName) == -1 )
        {
          LOBYTE(v112) = 11;
          free(lpFileName);
        }
        else
        {
          v15 = 0;
          while ( 1 )
          {
            v97 = v15;
            _swprintf(&KeyName, L"%dCmdLine", v15);
            v16 = malloc(2u);
            *v16 = 0;
            v17 = realloc(v16, 0x412u);
            v18 = v17;
            ppv = v17;
            if ( v17 )
              memset(v17, 0, 0x412u);
            v84 = GetPrivateProfileStringW(lpAppName, &KeyName, &gszNullString, v18, 0x208u, lpFileName);
            if ( !v84 )
              break;
            _swprintf(&KeyName, L"%dParameters", v15);
            v19 = malloc(2u);
            *v19 = 0;
            v20 = realloc(v19, 0x412u);
            v21 = v20;
            ppv3 = v20;
            if ( v20 )
              memset(v20, 0, 0x412u);
            GetPrivateProfileStringW(lpAppName, &KeyName, &gszNullString, v21, 0x208u, lpFileName);
            if ( v84 > 2 && (!wcsncmp(v18, L"\\\\", 2u) || v18[1] == 58) )
            {
              v22 = v108;
              v108 = _wcsdup(v18);
              free(v22);
            }
            else
            {
              v23 = PE_CopyString(&v72, &v104, L"\\");
              v24 = PE_CopyStringEx(&ppv1, v23, &lpAppName);
              v25 = PE_CopyString(&v73, v24, L"\\");
              v26 = PE_CopyStringEx(&v67, v25, &ppv);
              v27 = v108;
              v108 = _wcsdup(*v26);
              free(v27);
              free(v67);
              free(v73);
              free(ppv1);
              free(v72);
            }
            if ( GetFileAttributesW(v108) == -1 )
            {
              free(v21);
              free(v18);
              v15 = (v97 + 1);
            }
            else
            {
              v75 = malloc(2u);
              *v75 = 0;
              v76 = 0;
              v77 = 0;
              v78 = 0;
              LOBYTE(v112) = 21;
              sub_F77040(v108, &v75);
              v28 = a1a;
              sub_F74EE0(&v109, a1a, &v75, 0);
              LOBYTE(v112) = 22;
              v84 = sub_F74ED0();
              v29 = PE_CopyString(&v69, &v108, L" ");
              PE_CopyStringEx(&v96, v29, &ppv3);
              free(v69);
              v102 = _wcsdup(&KeyName);
              LOBYTE(v112) = 24;
              LOBYTE(v28) = sub_F73D40(v28, &v107, &v102, &v96, &v109, &v98, &v90, &v68);
              free(v102);
              if ( v28 )
              {
                if ( a4 == -1 )
                {
                  v85 = _wcsdup(&gszNullString);
                  v83 = _wcsdup(&gszNullString);
                  v87 = _wcsdup(&gszNullString);
                  v99 = _wcsdup(&gszNullString);
                  v95 = _wcsdup(&gszNullString);
                  v101 = _wcsdup(&gszNullString);
                  v30 = a1a;
                  LOBYTE(v112) = 30;
                  a4 = sub_F73FF0(a1a, 0, 0xFFFFFFFF, 0, &v107, &v107, &v101);
                  free(v101);
                  free(v95);
                  free(v99);
                  free(v87);
                  free(v83);
                  free(v85);
                }
                else
                {
                  v30 = a1a;
                }
                v92 = _wcsdup(&gszNullString);
                v81 = _wcsdup(&KeyName);
                LOBYTE(v112) = 32;
                sub_F73FF0(v30, v84, a4, 10, &v81, &v108, &v109);
                free(v81);
                free(v92);
              }
              free(v96);
              free(v109);
              v31 = v76;
              if ( v76 )
              {
                if ( v76 != v77 )
                {
                  v32 = v77;
                  do
                  {
                    free(*v31);
                    ++v31;
                  }
                  while ( v31 != v32 );
                  v31 = v76;
                  v18 = ppv;
                }
                j__free(v31);
                v76 = 0;
                v77 = 0;
                v78 = 0;
              }
              free(v75);
              free(v21);
              free(v18);
              v15 = (v97 + 1);
            }
          }
          free(v18);
          LOBYTE(v112) = 11;
          free(lpFileName);
        }
        ++v100.unused;
      }
      while ( !sub_F81450(hKey, v100.unused, &lpAppName, 0, 0, &v104) );
      v12 = v103;
      v5 = v66;
      v14 = RegCloseKey;
    }
    v14(hKey);
  }
  v33 = TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(hRootKey, psz, 0, v33 | 0x20019, &hKey) )
    goto LABEL_74;
  v87 = 0;
  v34 = PE_LoadKey(hKey, 0, &lpAppName);
  if ( v34 == 259 )
    goto LABEL_73;
  while ( !v34 )
  {
    v35 = lpAppName;
    v36 = TlsGetValue(gdwTlsIndex);
    if ( !PE_OpenKey(hKey, v35, 0, v36 | 0x20019, &KeyHandle) )
    {
      v109 = malloc(2u);
      *v109 = 0;
      LOBYTE(v112) = 33;
      if ( sub_F81520(KeyHandle, L"DisplayName", 0, 0, &v109) )
        goto LABEL_69;
      v37 = v93.unused;
      v93.unused = _wcsdup(&gszNullString);
      free(v37);
      sub_F81520(KeyHandle, L"FileSysPath", 0, 0, &v93);
      v38 = wcsrchr(psz, 0x5Cu);
      v39 = *szText2;
      *szText2 = _wcsdup(v38);
      free(v39);
      v40 = v12;
      v12 = _wcsdup(lpAppName);
      v103 = v12;
      free(v40);
      if ( !a5 )
      {
        CopyStringToString(&v103, L"\\AutorunsDisabled", 0x7FFFFFFFu, 0);
        v12 = v103;
      }
      v41 = TlsGetValue(gdwTlsIndex);
      if ( !PE_OpenKey(hKey, v12, 0, v41 | 0x20019, &v80) )
      {
        v83 = 0;
        v42 = PE_LoadKey(v80, 0, v86);
        if ( v42 != 259 )
        {
          v43 = a1a;
          do
          {
            if ( v42 )
              break;
            v44 = *v86;
            v45 = TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(v80, v44, 0, v45 | 0x20019, &v65) )
            {
              if ( !sub_F81520(v65, L"Script", 0, 0, &v108) )
              {
                lpFileName = malloc(2u);
                *lpFileName = 0;
                if ( *v93.unused && *v108 != 92 && v108[1] != 58 )
                {
                  v46 = PE_CopyString(&v73, &v93, L"\\");
                  v47 = PE_CopyString(&ppv1, v46, L"Scripts");
                  v48 = PE_CopyStringEx(&v72, v47, szText2);
                  v49 = PE_CopyString(&ppv3, v48, L"\\");
                  v50 = PE_CopyStringEx(&v69, v49, &v108);
                  v51 = v5;
                  v5 = _wcsdup(*v50);
                  v66 = v5;
                  free(v51);
                  free(v69);
                  free(ppv3);
                  free(v72);
                  free(ppv1);
                  free(v73);
                  sub_F72170(&v63);
                  LOBYTE(v112) = 35;
                  sub_F77040(v5, &v63);
                  v52 = sub_F74EE0(&v67, v43, &v63, 0);
                  v53 = lpFileName;
                  lpFileName = _wcsdup(*v52);
                  free(v53);
                  free(v67);
                  v54 = &v63;
                }
                else
                {
                  v75 = malloc(2u);
                  *v75 = 0;
                  v76 = 0;
                  v77 = 0;
                  v78 = 0;
                  LOBYTE(v112) = 36;
                  sub_F77040(v108, &v75);
                  v55 = sub_F74EE0(&v84, v43, &v75, 0);
                  v56 = lpFileName;
                  lpFileName = _wcsdup(*v55);
                  free(v56);
                  free(v84);
                  v54 = &v75;
                }
                LOBYTE(v112) = 34;
                sub_F721F0(v54);
                a2a = sub_F74ED0();
                v57 = PE_CopyString(&v99, &v107, L"\\");
                v58 = PE_CopyStringEx(&v95, v57, &lpAppName);
                v59 = PE_CopyString(&v101, v58, L"\\");
                v60 = PE_CopyStringEx(&v102, v59, v86);
                v61 = v104.unused;
                v104.unused = _wcsdup(*v60);
                free(v61);
                free(v102);
                free(v101);
                free(v95);
                free(v99);
                if ( sub_F73D40(v43, &v107, &v104, &v109, &lpFileName, &v98, &v90, &v68) )
                {
                  if ( a4 == -1 )
                  {
                    v92 = _wcsdup(&gszNullString);
                    v96 = _wcsdup(&gszNullString);
                    ppv = _wcsdup(&gszNullString);
                    v97 = _wcsdup(&gszNullString);
                    v100.unused = _wcsdup(&gszNullString);
                    hRootKey = _wcsdup(&gszNullString);
                    LOBYTE(v112) = 42;
                    a4 = sub_F73FF0(v43, 0, 0xFFFFFFFF, 0, &v107, &v107, &hRootKey);
                    free(hRootKey);
                    free(v100.unused);
                    free(v97);
                    free(ppv);
                    free(v96);
                    free(v92);
                  }
                  v85 = _wcsdup(&gszNullString);
                  v81 = _wcsdup(&gszNullString);
                  LOBYTE(v112) = 44;
                  sub_F73FF0(v43, a2a, a4, 3, &v109, &v104, &lpFileName);
                  free(v81);
                  free(v85);
                }
                LOBYTE(v112) = 33;
                free(lpFileName);
              }
              RegCloseKey(v65);
            }
            v83 = v83 + 1;
            v42 = PE_LoadKey(v80, v83, v86);
          }
          while ( v42 != 259 );
          v12 = v103;
        }
        RegCloseKey(v80);
LABEL_69:
        RegCloseKey(KeyHandle);
      }
      LOBYTE(v112) = 11;
      free(v109);
    }
    v87 = v87 + 1;
    v34 = PE_LoadKey(hKey, v87, &lpAppName);
    if ( v34 == 259 )
      break;
  }
  v14 = RegCloseKey;
LABEL_73:
  v14(hKey);
LABEL_74:
  free(v90);
  free(v12);
  free(v88);
  free(v98);
  free(v93.unused);
  free(v104.unused);
  free(*szText2);
  free(*v86);
  free(lpAppName);
  free(v107.unused);
  free(v5);
  free(v108);
  return a4;
}

//----- (00F83070) --------------------------------------------------------
unsigned __int16 **__cdecl PE_CopyStringEx(WCHAR **ppv, LPCWSTR *lpszText1, LPCWSTR *lpszText2)
{
  *ppv = _wcsdup(*lpszText1);
  CopyStringToString(ppv, *lpszText2, -0x80000001, 0);
  return ppv;
}

//----- (00F830B0) --------------------------------------------------------
void __cdecl sub_F830B0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F83160(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F83160(a1, a2, v7, v5);
  free(v7);
}

//----- (00F83160) --------------------------------------------------------
void *__cdecl sub_F83160(int a1, void *a2, wchar_t *psz, void *a4)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  unsigned __int16 **v6; // esi
  unsigned __int16 **v7; // eax
  unsigned int v8; // eax
  void (__stdcall *v9)(HKEY); // ebx
  tagKeyName *v10; // esi
  unsigned int v11; // eax
  WCHAR *v12; // eax
  const wchar_t **v13; // eax
  WCHAR *v14; // esi
  const wchar_t **v15; // eax
  WCHAR *v16; // esi
  tagKeyName *v17; // esi
  unsigned int v18; // eax
  WCHAR *v19; // esi
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  const wchar_t *v22; // ecx
  const wchar_t *v23; // eax
  unsigned __int16 **v24; // esi
  unsigned __int16 **v25; // eax
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  HKEY v29; // ebx
  unsigned __int16 **v30; // esi
  unsigned __int16 **v31; // eax
  const wchar_t *v32; // eax
  unsigned __int16 **v33; // eax
  DWORD v34; // esi
  int v36; // [esp+10h] [ebp-B0h]
  int v37; // [esp+14h] [ebp-ACh]
  int v38; // [esp+18h] [ebp-A8h]
  int v39; // [esp+1Ch] [ebp-A4h]
  WCHAR *v40; // [esp+20h] [ebp-A0h]
  WCHAR v41[2]; // [esp+24h] [ebp-9Ch]
  WCHAR v42[2]; // [esp+28h] [ebp-98h]
  WCHAR *ppv; // [esp+2Ch] [ebp-94h]
  WCHAR v44[2]; // [esp+30h] [ebp-90h]
  int v45; // [esp+34h] [ebp-8Ch]
  void *v46; // [esp+38h] [ebp-88h]
  WCHAR v47[2]; // [esp+3Ch] [ebp-84h]
  WCHAR v48[2]; // [esp+40h] [ebp-80h]
  WCHAR *pszResult; // [esp+44h] [ebp-7Ch]
  void *v50; // [esp+48h] [ebp-78h]
  int a2a; // [esp+4Ch] [ebp-74h]
  LPCWSTR v52; // [esp+50h] [ebp-70h]
  void *v53; // [esp+54h] [ebp-6Ch]
  LPCWSTR v54; // [esp+58h] [ebp-68h]
  void *v55; // [esp+5Ch] [ebp-64h]
  LPCWSTR v56; // [esp+60h] [ebp-60h]
  LPCWSTR v57; // [esp+64h] [ebp-5Ch]
  void *v58; // [esp+68h] [ebp-58h]
  void *v59; // [esp+6Ch] [ebp-54h]
  void *v60; // [esp+70h] [ebp-50h]
  void *v61; // [esp+74h] [ebp-4Ch]
  void *v62; // [esp+78h] [ebp-48h]
  HKEY KeyHandle; // [esp+7Ch] [ebp-44h]
  void *a1a; // [esp+80h] [ebp-40h]
  WCHAR szArg[2]; // [esp+84h] [ebp-3Ch]
  void *v66; // [esp+88h] [ebp-38h]
  LPCWSTR v67; // [esp+8Ch] [ebp-34h]
  LPCWSTR szArg3; // [esp+90h] [ebp-30h]
  LPCWSTR v69; // [esp+94h] [ebp-2Ch]
  LPCWSTR v70; // [esp+98h] [ebp-28h]
  HKEY hKey; // [esp+9Ch] [ebp-24h]
  WCHAR *pszText; // [esp+A0h] [ebp-20h]
  WCHAR *ppszText2; // [esp+A4h] [ebp-1Ch]
  LPCWSTR szArg4; // [esp+A8h] [ebp-18h]
  LPCWSTR lpszKeyName; // [esp+ACh] [ebp-14h]
  LPCWSTR v76; // [esp+B0h] [ebp-10h]
  int v77; // [esp+BCh] [ebp-4h]

  v66 = malloc(2u);
  *v66 = 0;
  v77 = 0;
  v62 = malloc(2u);
  *v62 = 0;
  v61 = malloc(2u);
  *v61 = 0;
  LOBYTE(v77) = 2;
  if ( a4 == -1 )
  {
    v67 = _wcsdup(&gszNullString);
    v69 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v70 = _wcsdup(&gszNullString);
    v76 = _wcsdup(&gszNullString);
    lpszKeyName = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v4 = &gszNullString;
    if ( psz )
      v4 = psz;
    pszText = _wcsdup(v4);
    ppszText2 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( psz )
      v5 = psz;
    hKey = _wcsdup(v5);
    LOBYTE(v77) = 12;
    v6 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v77) = 13;
    v7 = sub_F77BE0(szArg, a2, &hKey, &ppszText2);
    LOBYTE(v77) = 14;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v7, v6, &lpszKeyName);
    free(*szArg);
    free(a1a);
    free(hKey);
    free(ppszText2);
    free(pszText);
    free(szArg4);
    free(lpszKeyName);
    free(v76);
    free(v70);
    free(szArg3);
    free(v69);
    LOBYTE(v77) = 2;
    free(v67);
  }
  v8 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, psz, 0, v8 | 0x20019, &KeyHandle) )
  {
    *szArg = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    ppszText2 = malloc(2u);
    *ppszText2 = 0;
    v76 = malloc(2u);
    *v76 = 0;
    szArg4 = malloc(2u);
    *szArg4 = 0;
    pszText = malloc(2u);
    *pszText = 0;
    LOBYTE(v77) = 19;
    v9 = RegCloseKey;
    if ( !PE_LoadKey(KeyHandle, 0, &lpszKeyName) )
    {
      do
      {
        v10 = lpszKeyName;
        v11 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v10, 0, v11 | 0x20019, &hKey) )
        {
          if ( sub_F81520(hKey, L"CLSID", 0, 0, &ppszText2) )
          {
            v9(hKey);
          }
          else
          {
            v9(hKey);
            v12 = PE_CopyString2(&pszResult, L"CLSID\\", &ppszText2);
            v13 = PE_CopyString(&ppv, v12, L"\\InprocServer32");
            v14 = v76;
            v76 = _wcsdup(*v13);
            free(v14);
            free(ppv);
            free(pszResult);
            v15 = PE_CopyString2(&v40, L"HKCR\\CLSID\\", &ppszText2);
            v16 = pszText;
            pszText = _wcsdup(*v15);
            free(v16);
            free(v40);
            v17 = v76;
            v18 = TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v17, 0, v18 | KEY_READ, &hKey) )
            {
              v19 = v76;
              v76 = _wcsdup(&gszNullString);
              free(v19);
              sub_F81520(hKey, &gszNullString, 0, 0, &v76);
              v9(hKey);
              if ( wcslen(v76) )
              {
                v36 = malloc(2u);
                *v36 = 0;
                v37 = 0;
                v38 = 0;
                v39 = 0;
                LOBYTE(v77) = 20;
                sub_F77040(v76, &v36);
                v20 = sub_F74EE0(&v46, a1, &v36, 0);
                v21 = szArg4;
                szArg4 = _wcsdup(*v20);
                free(v21);
                free(v46);
                a2a = sub_F74ED0();
                v22 = &gszNullString;
                if ( psz )
                  v22 = psz;
                szArg3 = _wcsdup(v22);
                v69 = _wcsdup(&gszNullString);
                v23 = &gszNullString;
                if ( psz )
                  v23 = psz;
                v67 = _wcsdup(v23);
                LOBYTE(v77) = 23;
                v24 = sub_F77BE0(v44, a2, &szArg3, &lpszKeyName);
                LOBYTE(v77) = 24;
                v25 = sub_F77BE0(v42, a2, &v67, &v69);
                LOBYTE(v77) = 25;
                v26 = sub_F73D40(a1, &lpszKeyName, v25, v24, &szArg4, &v66, &v61, &v45);
                free(*v42);
                free(*v44);
                free(v67);
                free(v69);
                free(szArg3);
                if ( v26 )
                {
                  if ( a4 == -1 )
                  {
                    v58 = _wcsdup(&gszNullString);
                    v59 = _wcsdup(&gszNullString);
                    v55 = _wcsdup(&gszNullString);
                    v53 = _wcsdup(&gszNullString);
                    v60 = _wcsdup(&gszNullString);
                    v50 = _wcsdup(&gszNullString);
                    v52 = _wcsdup(&gszNullString);
                    v27 = &gszNullString;
                    if ( psz )
                      v27 = psz;
                    v54 = _wcsdup(v27);
                    v57 = _wcsdup(&gszNullString);
                    v28 = &gszNullString;
                    if ( psz )
                      v28 = psz;
                    v70 = _wcsdup(v28);
                    v29 = a2;
                    LOBYTE(v77) = 35;
                    v30 = sub_F77BE0(v47, a2, &v54, &v52);
                    LOBYTE(v77) = 36;
                    v31 = sub_F77BE0(v48, a2, &v70, &v57);
                    LOBYTE(v77) = 37;
                    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v31, v30, &v50);
                    free(*v48);
                    free(*v47);
                    free(v70);
                    free(v57);
                    free(v54);
                    free(v52);
                    free(v50);
                    free(v60);
                    free(v53);
                    free(v55);
                    free(v59);
                    free(v58);
                  }
                  else
                  {
                    v29 = a2;
                  }
                  a1a = _wcsdup(&gszNullString);
                  v32 = &gszNullString;
                  if ( psz )
                    v32 = psz;
                  v56 = _wcsdup(v32);
                  LOBYTE(v77) = 39;
                  v33 = sub_F77BE0(v41, v29, &v56, &lpszKeyName);
                  LOBYTE(v77) = 40;
                  sub_F73FF0(a1, a2a, a4, 3, &lpszKeyName, v33, &szArg4);
                  free(*v41);
                  free(v56);
                  free(a1a);
                }
                sub_F721F0(&v36);
                free(pszText);
                free(szArg4);
                free(v76);
                free(ppszText2);
                free(lpszKeyName);
                v9 = RegCloseKey;
                goto LABEL_31;
              }
            }
          }
        }
        free(pszText);
        free(szArg4);
        free(v76);
        free(ppszText2);
        free(lpszKeyName);
LABEL_31:
        v34 = ++*szArg;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        v76 = malloc(2u);
        *v76 = 0;
        szArg4 = malloc(2u);
        *szArg4 = 0;
        pszText = malloc(2u);
        *pszText = 0;
        LOBYTE(v77) = 19;
      }
      while ( !PE_LoadKey(KeyHandle, v34, &lpszKeyName) );
    }
    free(pszText);
    free(szArg4);
    free(v76);
    free(ppszText2);
    free(lpszKeyName);
    v9(KeyHandle);
  }
  free(v61);
  free(v62);
  free(v66);
  return a4;
}

//----- (00F839D0) --------------------------------------------------------
void __cdecl sub_F839D0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F83A80(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F83A80(a1, a2, v7, v5);
  free(v7);
}

//----- (00F83A80) --------------------------------------------------------
void *__cdecl sub_F83A80(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  _WORD *v5; // esi
  tagKeyName *v6; // edi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  unsigned __int16 **v9; // edi
  unsigned __int16 **v10; // eax
  unsigned int v11; // eax
  void *v12; // esi
  tagKeyName *v13; // edi
  unsigned int v14; // eax
  const wchar_t **v15; // eax
  void *v16; // edi
  int v17; // eax
  const wchar_t *v18; // ecx
  const wchar_t *v19; // eax
  unsigned __int16 **v20; // edi
  unsigned __int16 **v21; // eax
  char v22; // bl
  wchar_t *v23; // ebx
  const wchar_t *v24; // eax
  const wchar_t *v25; // eax
  unsigned __int16 **v26; // edi
  unsigned __int16 **v27; // eax
  const WCHAR **v28; // eax
  unsigned __int16 **v29; // eax
  int a2a; // [esp+10h] [ebp-A0h]
  int v32; // [esp+14h] [ebp-9Ch]
  int v33; // [esp+18h] [ebp-98h]
  int v34; // [esp+1Ch] [ebp-94h]
  WCHAR v35[2]; // [esp+20h] [ebp-90h]
  _WORD *v36; // [esp+24h] [ebp-8Ch]
  WCHAR v37[2]; // [esp+28h] [ebp-88h]
  WCHAR v38[2]; // [esp+2Ch] [ebp-84h]
  void *v39; // [esp+30h] [ebp-80h]
  int v40; // [esp+34h] [ebp-7Ch]
  WCHAR v41[2]; // [esp+38h] [ebp-78h]
  int v42; // [esp+3Ch] [ebp-74h]
  WCHAR v43[2]; // [esp+40h] [ebp-70h]
  HKEY hKey; // [esp+44h] [ebp-6Ch]
  void *v45; // [esp+48h] [ebp-68h]
  LPCWSTR v46; // [esp+4Ch] [ebp-64h]
  void *v47; // [esp+50h] [ebp-60h]
  std__List *v48; // [esp+54h] [ebp-5Ch]
  void *v49; // [esp+58h] [ebp-58h]
  DWORD v50; // [esp+5Ch] [ebp-54h]
  void *v51; // [esp+60h] [ebp-50h]
  void *v52; // [esp+64h] [ebp-4Ch]
  void *a1a; // [esp+68h] [ebp-48h]
  HKEY KeyHandle; // [esp+6Ch] [ebp-44h]
  WCHAR szArg[2]; // [esp+70h] [ebp-40h]
  LPCWSTR v56; // [esp+74h] [ebp-3Ch]
  LPCWSTR v57; // [esp+78h] [ebp-38h]
  LPCWSTR v58; // [esp+7Ch] [ebp-34h]
  LPCWSTR v59; // [esp+80h] [ebp-30h]
  LPCWSTR v60; // [esp+84h] [ebp-2Ch]
  LPCWSTR szArg3; // [esp+88h] [ebp-28h]
  LPCWSTR v62; // [esp+8Ch] [ebp-24h]
  WCHAR *pszText; // [esp+90h] [ebp-20h]
  LPCWSTR szArg4; // [esp+94h] [ebp-1Ch]
  LPCWSTR v65; // [esp+98h] [ebp-18h]
  void *v66; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v68; // [esp+ACh] [ebp-4h]

  v4 = 0;
  v50 = 0;
  v48 = malloc(2u);
  LOWORD(v48->_Mypair._Myval2._Myhead) = 0;
  v68 = 0;
  lpszKeyName = malloc(2u);
  *lpszKeyName = 0;
  v5 = malloc(2u);
  v36 = v5;
  *v5 = 0;
  v66 = malloc(2u);
  *v66 = 0;
  v52 = malloc(2u);
  *v52 = 0;
  v51 = malloc(2u);
  *v51 = 0;
  v49 = malloc(2u);
  *v49 = 0;
  v6 = psz;
  LOBYTE(v68) = 6;
  if ( a4 == -1 )
  {
    v59 = _wcsdup(&gszNullString);
    v65 = _wcsdup(&gszNullString);
    v56 = _wcsdup(&gszNullString);
    v58 = _wcsdup(&gszNullString);
    v60 = _wcsdup(&gszNullString);
    v62 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v57 = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( psz )
      v8 = psz;
    szArg3 = _wcsdup(v8);
    LOBYTE(v68) = 16;
    v9 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v68) = 17;
    v10 = sub_F77BE0(szArg, a2, &szArg3, &v57);
    LOBYTE(v68) = 18;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v10, v9, &v62);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v57);
    free(pszText);
    free(szArg4);
    free(v62);
    free(v60);
    free(v58);
    free(v56);
    free(v65);
    LOBYTE(v68) = 6;
    free(v59);
    v6 = psz;
  }
  v11 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, v6, 0, v11 | 0x20019, &KeyHandle) )
  {
    if ( !PE_LoadKey(KeyHandle, 0, &lpszKeyName) )
    {
      v12 = a4;
      do
      {
        v13 = lpszKeyName;
        v14 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v13, 0, v14 | 0x20019, &hKey) )
        {
          if ( !sub_F81520(hKey, L"Source", 0, 0, &v48) )
          {
            a2a = malloc(2u);
            *a2a = 0;
            v32 = 0;
            v33 = 0;
            v34 = 0;
            LOBYTE(v68) = 19;
            if ( sub_F76CC0(v48, &a2a) )
            {
              v15 = sub_F74EE0(&v39, a1, &a2a, 0);
              v16 = v66;
              v66 = _wcsdup(*v15);
              free(v16);
              free(v39);
              v17 = sub_F74ED0();
              v18 = &gszNullString;
              v40 = v17;
              if ( psz )
                v18 = psz;
              v65 = _wcsdup(v18);
              v59 = _wcsdup(&gszNullString);
              v19 = &gszNullString;
              if ( psz )
                v19 = psz;
              a4 = _wcsdup(v19);
              LOBYTE(v68) = 22;
              v20 = sub_F77BE0(v37, a2, &v65, &lpszKeyName);
              LOBYTE(v68) = 23;
              v21 = sub_F77BE0(v41, a2, &a4, &v59);
              LOBYTE(v68) = 24;
              v22 = sub_F73D40(a1, &lpszKeyName, v21, v20, &v66, &v52, &v49, &v42);
              free(*v41);
              free(*v37);
              free(a4);
              free(v59);
              free(v65);
              if ( v22 )
              {
                if ( v12 == -1 )
                {
                  v45 = _wcsdup(&gszNullString);
                  v47 = _wcsdup(&gszNullString);
                  szArg3 = _wcsdup(&gszNullString);
                  v57 = _wcsdup(&gszNullString);
                  pszText = _wcsdup(&gszNullString);
                  szArg4 = _wcsdup(&gszNullString);
                  v62 = _wcsdup(&gszNullString);
                  v23 = psz;
                  v24 = &gszNullString;
                  if ( psz )
                    v24 = psz;
                  v60 = _wcsdup(v24);
                  v58 = _wcsdup(&gszNullString);
                  v25 = &gszNullString;
                  if ( psz )
                    v25 = psz;
                  v56 = _wcsdup(v25);
                  LOBYTE(v68) = 34;
                  v26 = sub_F77BE0(v35, a2, &v60, &v62);
                  LOBYTE(v68) = 35;
                  v27 = sub_F77BE0(v43, a2, &v56, &v58);
                  LOBYTE(v68) = 36;
                  v12 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v27, v26, &szArg4);
                  free(*v43);
                  free(*v35);
                  free(v56);
                  free(v58);
                  free(v60);
                  free(v62);
                  free(szArg4);
                  free(pszText);
                  free(v57);
                  free(szArg3);
                  free(v47);
                  free(v45);
                }
                else
                {
                  v23 = psz;
                }
                *szArg = _wcsdup(&gszNullString);
                a1a = _wcsdup(&gszNullString);
                v28 = &gszNullString;
                if ( v23 )
                  v28 = v23;
                v46 = _wcsdup(v28);
                LOBYTE(v68) = 39;
                v29 = sub_F77BE0(v38, a2, &v46, &lpszKeyName);
                LOBYTE(v68) = 40;
                sub_F73FF0(a1, v40, v12, 3, &lpszKeyName, v29, &v66);
                free(*v38);
                free(v46);
                free(a1a);
                free(*szArg);
              }
              v4 = v50;
            }
            LOBYTE(v68) = 6;
            sub_F721F0(&a2a);
          }
          RegCloseKey(hKey);
        }
        v50 = ++v4;
      }
      while ( !PE_LoadKey(KeyHandle, v4, &lpszKeyName) );
      a4 = v12;
      v5 = v36;
    }
    RegCloseKey(KeyHandle);
  }
  free(v49);
  free(v51);
  free(v52);
  free(v66);
  free(v5);
  free(lpszKeyName);
  free(v48);
  return a4;
}

//----- (00F84150) --------------------------------------------------------
void __cdecl sub_F84150(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F84200(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F84200(a1, a2, v7, v5);
  free(v7);
}

//----- (00F84200) --------------------------------------------------------
void *__cdecl sub_F84200(int a1, void *a2, wchar_t *psz, void *a4)
{
  wchar_t *v4; // edi
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  unsigned __int16 **v7; // esi
  unsigned __int16 **v8; // eax
  unsigned int v9; // eax
  void (__stdcall *v10)(HKEY); // ebx
  tagKeyName *v11; // esi
  unsigned int v12; // eax
  wchar_t *v13; // ebx
  UINT v14; // edi
  wchar_t *v15; // eax
  const wchar_t **v16; // eax
  wchar_t *v17; // esi
  HMODULE v18; // ebx
  wchar_t *v19; // edi
  LSTATUS v20; // eax
  WCHAR *v21; // eax
  const wchar_t **v22; // eax
  WCHAR *v23; // esi
  tagKeyName *v24; // esi
  unsigned int v25; // eax
  DWORD v26; // esi
  WCHAR *v28; // esi
  const wchar_t *v29; // eax
  void *v30; // esi
  const wchar_t **v31; // eax
  WCHAR *v32; // esi
  const WCHAR **v33; // ecx
  const WCHAR **v34; // eax
  HKEY v35; // ebx
  unsigned __int16 **v36; // esi
  unsigned __int16 **v37; // eax
  const WCHAR **v38; // eax
  const WCHAR **v39; // eax
  HKEY v40; // ebx
  unsigned __int16 **v41; // esi
  unsigned __int16 **v42; // eax
  const WCHAR **v43; // eax
  unsigned __int16 **v44; // eax
  HKEY v45; // [esp-4h] [ebp-2E0h]
  int v46; // [esp+10h] [ebp-2CCh]
  int v47; // [esp+14h] [ebp-2C8h]
  int v48; // [esp+18h] [ebp-2C4h]
  int v49; // [esp+1Ch] [ebp-2C0h]
  void *v50; // [esp+20h] [ebp-2BCh]
  WCHAR *ppv; // [esp+24h] [ebp-2B8h]
  WCHAR v52[2]; // [esp+28h] [ebp-2B4h]
  WCHAR v53[2]; // [esp+2Ch] [ebp-2B0h]
  WCHAR v54[2]; // [esp+30h] [ebp-2ACh]
  wchar_t *v55; // [esp+34h] [ebp-2A8h]
  WCHAR v56[2]; // [esp+38h] [ebp-2A4h]
  int v57; // [esp+3Ch] [ebp-2A0h]
  WCHAR *ppstr; // [esp+40h] [ebp-29Ch]
  WCHAR v59[2]; // [esp+44h] [ebp-298h]
  WCHAR *pszResult; // [esp+48h] [ebp-294h]
  int a2a; // [esp+4Ch] [ebp-290h]
  void *v62; // [esp+50h] [ebp-28Ch]
  void *v63; // [esp+54h] [ebp-288h]
  void *v64; // [esp+58h] [ebp-284h]
  void *v65; // [esp+5Ch] [ebp-280h]
  void *v66; // [esp+60h] [ebp-27Ch]
  LPCWSTR v67; // [esp+64h] [ebp-278h]
  LPCWSTR v68; // [esp+68h] [ebp-274h]
  LPCWSTR v69; // [esp+6Ch] [ebp-270h]
  void *v70; // [esp+70h] [ebp-26Ch]
  void *v71; // [esp+74h] [ebp-268h]
  void *v72; // [esp+78h] [ebp-264h]
  HKEY v73; // [esp+7Ch] [ebp-260h]
  void *a1a; // [esp+80h] [ebp-25Ch]
  WCHAR szArg[2]; // [esp+84h] [ebp-258h]
  HKEY KeyHandle; // [esp+88h] [ebp-254h]
  void *v77; // [esp+8Ch] [ebp-250h]
  void *v78; // [esp+90h] [ebp-24Ch]
  LPCWSTR v79; // [esp+94h] [ebp-248h]
  LPCWSTR v80; // [esp+98h] [ebp-244h]
  LPCWSTR v81; // [esp+9Ch] [ebp-240h]
  LPCWSTR v82; // [esp+A0h] [ebp-23Ch]
  LPCWSTR szArg3; // [esp+A4h] [ebp-238h]
  int v84; // [esp+A8h] [ebp-234h]
  wchar_t *ppv3; // [esp+ACh] [ebp-230h]
  WCHAR *ppszText2; // [esp+B0h] [ebp-22Ch]
  HKEY hKey; // [esp+B4h] [ebp-228h]
  OLECHAR *pszText; // [esp+B8h] [ebp-224h]
  LPCWSTR szArg4; // [esp+BCh] [ebp-220h]
  LPCWSTR lpszKeyName; // [esp+C0h] [ebp-21Ch]
  WCHAR Buffer; // [esp+C4h] [ebp-218h]
  int v92; // [esp+2D8h] [ebp-4h]

  v4 = psz;
  v84 = a1;
  v73 = a2;
  v55 = psz;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  v92 = 0;
  v77 = malloc(2u);
  *v77 = 0;
  v71 = malloc(2u);
  *v71 = 0;
  v72 = malloc(2u);
  *v72 = 0;
  v78 = malloc(2u);
  *v78 = 0;
  LOBYTE(v92) = 4;
  if ( a4 == -1 )
  {
    v79 = _wcsdup(&gszNullString);
    v81 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v80 = _wcsdup(&gszNullString);
    v82 = _wcsdup(&gszNullString);
    lpszKeyName = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    hKey = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    ppszText2 = _wcsdup(v6);
    LOBYTE(v92) = 14;
    v7 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v92) = 15;
    v8 = sub_F77BE0(szArg, a2, &ppszText2, &hKey);
    LOBYTE(v92) = 16;
    a4 = sub_F73FF0(v84, 0, 0xFFFFFFFF, 0, v8, v7, &lpszKeyName);
    free(*szArg);
    free(a1a);
    free(ppszText2);
    free(hKey);
    free(pszText);
    free(szArg4);
    free(lpszKeyName);
    free(v82);
    free(v80);
    free(szArg3);
    free(v81);
    LOBYTE(v92) = 4;
    free(v79);
  }
  v9 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, psz, 0, v9 | 0x20019, &KeyHandle) )
  {
    *szArg = 0;
    pszText = malloc(2u);
    *pszText = 0;
    ppszText2 = malloc(2u);
    *ppszText2 = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    szArg4 = malloc(2u);
    *szArg4 = 0;
    LOBYTE(v92) = 20;
    v10 = RegCloseKey;
    if ( !PE_LoadKey(KeyHandle, 0, &pszText) )
    {
      while ( 1 )
      {
        v11 = pszText;
        v12 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v11, 0, v12 | 0x20019, &hKey) )
        {
          if ( sub_F81520(hKey, L"MenuText", 0, 0, &ppv3) && sub_F81520(hKey, L"ButtonText", 0, 0, &ppv3) )
            goto LABEL_25;
          if ( *ppv3 == 64 )
          {
            v13 = _wcsdup(ppv3);
            a2a = v13;
            LOBYTE(v92) = 21;
            v14 = 0;
            if ( wcschr(v13, 0x2Cu) )
            {
              v15 = wcschr(v13, 0x2Cu);
              *v15 = 0;
              v14 = abs(_wtoi(v15 + 1));
            }
            v16 = RequerySystemEnvironmentString(&ppstr, v13 + 1);
            v17 = _wcsdup(*v16);
            free(v13);
            free(ppstr);
            v18 = LoadLibraryExW(v17, 0, 2u);
            if ( v18 )
            {
              if ( LoadStringW(v18, v14, &Buffer, 260) )
              {
                v19 = ppv3;
                ppv3 = _wcsdup(&Buffer);
                free(v19);
              }
              FreeLibrary(v18);
            }
            LOBYTE(v92) = 20;
            free(v17);
            v10 = RegCloseKey;
            v4 = v55;
          }
          if ( !sub_F81520(hKey, L"Exec", 0, 0, &lpszKeyName) )
            goto LABEL_36;
          if ( !sub_F81520(hKey, L"Script", 0, 0, &lpszKeyName) )
          {
            if ( !_wcsnicmp(lpszKeyName, L"res://", 6u) )
            {
              v28 = lpszKeyName;
              v29 = lpszKeyName + 6;
              goto LABEL_35;
            }
            if ( !_wcsnicmp(lpszKeyName, L"file://", 7u) )
            {
              v28 = lpszKeyName;
              v29 = lpszKeyName + 7;
LABEL_35:
              lpszKeyName = _wcsdup(v29);
              free(v28);
            }
LABEL_36:
            v10(hKey);
            v46 = malloc(2u);
            *v46 = 0;
            v47 = 0;
            v48 = 0;
            v49 = 0;
            LOBYTE(v92) = 22;
            sub_F77040(lpszKeyName, &v46);
            v30 = v78;
            v78 = _wcsdup(lpszKeyName);
            free(v30);
            v31 = sub_F74EE0(&v50, v84, &v46, 0);
            v32 = szArg4;
            szArg4 = _wcsdup(*v31);
            free(v32);
            free(v50);
            a2a = sub_F74ED0();
            v33 = &gszNullString;
            if ( v4 )
              v33 = v4;
            szArg3 = _wcsdup(v33);
            v81 = _wcsdup(&gszNullString);
            v34 = &gszNullString;
            if ( v4 )
              v34 = v4;
            v79 = _wcsdup(v34);
            v35 = v73;
            LOBYTE(v92) = 25;
            v36 = sub_F77BE0(v52, v73, &szArg3, &pszText);
            LOBYTE(v92) = 26;
            v37 = sub_F77BE0(v56, v35, &v79, &v81);
            LOBYTE(v92) = 27;
            LOBYTE(v35) = sub_F73D40(v84, &ppv3, v37, v36, &szArg4, &v77, &v72, &v57);
            free(*v56);
            free(*v52);
            free(v79);
            free(v81);
            free(szArg3);
            if ( v35 )
            {
              if ( a4 == -1 )
              {
                v62 = _wcsdup(&gszNullString);
                v66 = _wcsdup(&gszNullString);
                v64 = _wcsdup(&gszNullString);
                v63 = _wcsdup(&gszNullString);
                v70 = _wcsdup(&gszNullString);
                v65 = _wcsdup(&gszNullString);
                v67 = _wcsdup(&gszNullString);
                v38 = &gszNullString;
                if ( v4 )
                  v38 = v4;
                v68 = _wcsdup(v38);
                v82 = _wcsdup(&gszNullString);
                v39 = &gszNullString;
                if ( v4 )
                  v39 = v4;
                v80 = _wcsdup(v39);
                v40 = v73;
                LOBYTE(v92) = 37;
                v41 = sub_F77BE0(v59, v73, &v68, &v67);
                LOBYTE(v92) = 38;
                v42 = sub_F77BE0(v54, v40, &v80, &v82);
                LOBYTE(v92) = 39;
                a4 = sub_F73FF0(v84, 0, 0xFFFFFFFF, 0, v42, v41, &v65);
                free(*v54);
                free(*v59);
                free(v80);
                free(v82);
                free(v68);
                free(v67);
                free(v65);
                free(v70);
                free(v63);
                free(v64);
                free(v66);
                free(v62);
              }
              else
              {
                v40 = v73;
              }
              a1a = _wcsdup(&gszNullString);
              v43 = &gszNullString;
              if ( v4 )
                v43 = v4;
              v69 = _wcsdup(v43);
              LOBYTE(v92) = 41;
              v44 = sub_F77BE0(v53, v40, &v69, &pszText);
              LOBYTE(v92) = 42;
              sub_F73FF0(v84, a2a, a4, 3, &ppv3, v44, &szArg4);
              free(*v53);
              free(v69);
              free(a1a);
            }
            sub_F721F0(&v46);
            free(szArg4);
            free(lpszKeyName);
            free(ppszText2);
            free(pszText);
            v10 = RegCloseKey;
            goto LABEL_28;
          }
          v20 = sub_F81520(hKey, L"ClsidExtension", 0, 0, &ppszText2);
          v45 = hKey;
          if ( v20 )
            goto LABEL_26;
          v10(hKey);
          v21 = PE_CopyString2(&pszResult, L"CLSID\\", &ppszText2);
          v22 = PE_CopyString(&ppv, v21, L"\\InprocServer32");
          v23 = lpszKeyName;
          lpszKeyName = _wcsdup(*v22);
          free(v23);
          free(ppv);
          free(pszResult);
          v24 = lpszKeyName;
          v25 = TlsGetValue(gdwTlsIndex);
          if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v24, 0, v25 | 0x20019, &hKey) )
            break;
        }
LABEL_27:
        free(szArg4);
        free(lpszKeyName);
        free(ppszText2);
        free(pszText);
LABEL_28:
        v26 = ++*szArg;
        pszText = malloc(2u);
        *pszText = 0;
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        szArg4 = malloc(2u);
        *szArg4 = 0;
        LOBYTE(v92) = 20;
        if ( PE_LoadKey(KeyHandle, v26, &pszText) )
          goto LABEL_29;
      }
      if ( !sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName) )
        goto LABEL_36;
LABEL_25:
      v45 = hKey;
LABEL_26:
      v10(v45);
      goto LABEL_27;
    }
LABEL_29:
    free(szArg4);
    free(lpszKeyName);
    free(ppszText2);
    free(pszText);
    v10(KeyHandle);
  }
  free(v78);
  free(v72);
  free(v71);
  free(v77);
  free(ppv3);
  return a4;
}

//----- (00F84E10) --------------------------------------------------------
void *__cdecl sub_F84E10(int a1, void *a2, OLECHAR *psz)
{
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  void *v8; // eax
  void *v9; // eax
  void *v10; // esi
  void *v11; // edi
  void *v13; // [esp+10h] [ebp-1Ch]
  _bstr_t v14; // [esp+14h] [ebp-18h]
  _bstr_t v15; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&v14, L"AutorunsDisabled");
  v17 = 0;
  v3 = _bstr_t::_bstr_t(&v15, L"\\");
  LOBYTE(v17) = 1;
  v4 = _bstr_t::operator+(&a1a, psz, v3);
  LOBYTE(v17) = 2;
  _bstr_t::operator+(&v4->m_Data, &v13, &v14);
  v5 = a1a.m_Data;
  if ( a1a.m_Data )
  {
    if ( !InterlockedDecrement(&a1a.m_Data->m_RefCount) && v5 )
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
    a1a.m_Data = 0;
  }
  v6 = v15.m_Data;
  if ( v15.m_Data )
  {
    if ( !InterlockedDecrement(&v15.m_Data->m_RefCount) && v6 )
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
    v15.m_Data = 0;
  }
  v7 = v14.m_Data;
  LOBYTE(v17) = 6;
  if ( v14.m_Data && !InterlockedDecrement(&v14.m_Data->m_RefCount) )
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
  v8 = sub_F84FF0(a1, a2, psz, 0xFFFFFFFF, 1);
  v9 = sub_F84FF0(a1, a2, psz, v8, 0);
  v10 = v13;
  v11 = v9;
  if ( v13 && !InterlockedDecrement(v13 + 2) && v10 )
  {
    if ( *v10 )
    {
      SysFreeString(*v10);
      *v10 = 0;
    }
    if ( *(v10 + 1) )
    {
      j_j__free(*(v10 + 1));
      *(v10 + 1) = 0;
    }
    j__free(v10);
  }
  return v11;
}

//----- (00F84FF0) --------------------------------------------------------
void *__cdecl sub_F84FF0(int a1, void *a2, wchar_t *psz, void *a4, char a5)
{
  void *v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  unsigned __int16 **v8; // esi
  unsigned __int16 **v9; // eax
  unsigned int v10; // eax
  WCHAR *v12; // ebx
  WCHAR *v13; // edi
  int v14; // esi
  const WCHAR *v15; // eax
  wchar_t *v16; // eax
  wchar_t *v17; // esi
  unsigned int v18; // eax
  int v19; // eax
  wchar_t *v20; // esi
  const wchar_t *v21; // ecx
  const WCHAR **v22; // eax
  wchar_t *v23; // esi
  LPCWSTR *v24; // eax
  unsigned __int16 **v25; // edi
  unsigned __int16 **v26; // eax
  wchar_t *v27; // edi
  const wchar_t *v28; // eax
  const WCHAR **v29; // eax
  unsigned __int16 **v30; // esi
  unsigned __int16 **v31; // eax
  const WCHAR **v32; // eax
  wchar_t *v33; // esi
  LPCWSTR *v34; // eax
  unsigned __int16 **v35; // eax
  unsigned int v36; // eax
  wchar_t *v37; // esi
  const wchar_t *v38; // eax
  const WCHAR **v39; // eax
  HKEY v40; // edi
  unsigned __int16 **v41; // esi
  unsigned __int16 **v42; // eax
  const WCHAR **v43; // eax
  const WCHAR *v44; // eax
  wchar_t *v45; // eax
  wchar_t *v46; // edi
  const wchar_t *v47; // eax
  wchar_t *v48; // eax
  wchar_t *v49; // esi
  LPCWSTR *v50; // eax
  unsigned __int16 **v51; // eax
  int v52; // eax
  wchar_t *v53; // esi
  int v54; // [esp+10h] [ebp-528h]
  int v55; // [esp+14h] [ebp-524h]
  int v56; // [esp+18h] [ebp-520h]
  int v57; // [esp+1Ch] [ebp-51Ch]
  WCHAR v58[2]; // [esp+20h] [ebp-518h]
  WCHAR v59[2]; // [esp+24h] [ebp-514h]
  int v60; // [esp+28h] [ebp-510h]
  BYTE v61[4]; // [esp+2Ch] [ebp-50Ch]
  WCHAR v62[2]; // [esp+30h] [ebp-508h]
  wchar_t *v63; // [esp+34h] [ebp-504h]
  WCHAR v64[2]; // [esp+38h] [ebp-500h]
  WCHAR *v65; // [esp+3Ch] [ebp-4FCh]
  WCHAR *v66; // [esp+40h] [ebp-4F8h]
  WCHAR *v67; // [esp+44h] [ebp-4F4h]
  WCHAR *pszResult; // [esp+48h] [ebp-4F0h]
  WCHAR *ppv1; // [esp+4Ch] [ebp-4ECh]
  WCHAR v70[2]; // [esp+50h] [ebp-4E8h]
  WCHAR v71[2]; // [esp+54h] [ebp-4E4h]
  WCHAR *v72; // [esp+58h] [ebp-4E0h]
  WCHAR v73[2]; // [esp+5Ch] [ebp-4DCh]
  WCHAR *ppv; // [esp+60h] [ebp-4D8h]
  LPCWSTR v75; // [esp+64h] [ebp-4D4h]
  WCHAR *ppv3; // [esp+68h] [ebp-4D0h]
  LPCWSTR v77; // [esp+6Ch] [ebp-4CCh]
  LPCWSTR v78; // [esp+70h] [ebp-4C8h]
  void *v79; // [esp+74h] [ebp-4C4h]
  void *v80; // [esp+78h] [ebp-4C0h]
  LPCWSTR v81; // [esp+7Ch] [ebp-4BCh]
  void *v82; // [esp+80h] [ebp-4B8h]
  LPCWSTR v83; // [esp+84h] [ebp-4B4h]
  void *v84; // [esp+88h] [ebp-4B0h]
  void *v85; // [esp+8Ch] [ebp-4ACh]
  LPCWSTR v86; // [esp+90h] [ebp-4A8h]
  void *v87; // [esp+94h] [ebp-4A4h]
  void *v88; // [esp+98h] [ebp-4A0h]
  void *v89; // [esp+9Ch] [ebp-49Ch]
  LPCWSTR v90; // [esp+A0h] [ebp-498h]
  void *v91; // [esp+A4h] [ebp-494h]
  void *v92; // [esp+A8h] [ebp-490h]
  void *v93; // [esp+ACh] [ebp-48Ch]
  void *v94; // [esp+B0h] [ebp-488h]
  LPCWSTR v95; // [esp+B4h] [ebp-484h]
  void *v96; // [esp+B8h] [ebp-480h]
  LPCWSTR v97; // [esp+BCh] [ebp-47Ch]
  void *v98; // [esp+C0h] [ebp-478h]
  DWORD cbData; // [esp+C4h] [ebp-474h]
  HKEY__ v100; // [esp+C8h] [ebp-470h]
  WCHAR szArg[2]; // [esp+CCh] [ebp-46Ch]
  void *a1a; // [esp+D0h] [ebp-468h]
  LPCWSTR v103; // [esp+D4h] [ebp-464h]
  wchar_t *v104; // [esp+D8h] [ebp-460h]
  WCHAR *ppszText2; // [esp+DCh] [ebp-45Ch]
  LPCWSTR szArg3; // [esp+E0h] [ebp-458h]
  LPCWSTR v107; // [esp+E4h] [ebp-454h]
  int v108; // [esp+E8h] [ebp-450h]
  HKEY hKey; // [esp+ECh] [ebp-44Ch]
  LPCWSTR v110; // [esp+F0h] [ebp-448h]
  HKEY v111; // [esp+F4h] [ebp-444h]
  int v112; // [esp+F8h] [ebp-440h]
  LPCWSTR szArg4; // [esp+FCh] [ebp-43Ch]
  WCHAR *pszText; // [esp+100h] [ebp-438h]
  HKEY KeyHandle; // [esp+104h] [ebp-434h]
  HKEY__ v116; // [esp+108h] [ebp-430h]
  int v117; // [esp+10Ch] [ebp-42Ch]
  char v118; // [esp+113h] [ebp-425h]
  LPCWSTR lpszKeyName; // [esp+114h] [ebp-424h]
  wchar_t Data[260]; // [esp+118h] [ebp-420h]
  WCHAR Name; // [esp+320h] [ebp-218h]
  int v122; // [esp+534h] [ebp-4h]

  v5 = a4;
  v112 = a1;
  v111 = a2;
  v104 = psz;
  v117 = 0;
  v108 = 0;
  if ( a4 == -1 )
  {
    ppszText2 = _wcsdup(&gszNullString);
    v122 = 0;
    lpszKeyName = _wcsdup(&gszNullString);
    v103 = _wcsdup(&gszNullString);
    v107 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    KeyHandle = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    pszText = _wcsdup(v6);
    v110 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    v116.unused = _wcsdup(v7);
    LOBYTE(v122) = 9;
    v8 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v122) = 10;
    v9 = sub_F77BE0(szArg, a2, &v116, &v110);
    LOBYTE(v122) = 11;
    v5 = sub_F73FF0(v112, 0, 0xFFFFFFFF, 0, v9, v8, &KeyHandle);
    a4 = v5;
    free(*szArg);
    free(a1a);
    free(v116.unused);
    free(v110);
    free(pszText);
    free(szArg4);
    free(KeyHandle);
    free(szArg3);
    free(v107);
    free(v103);
    free(lpszKeyName);
    v122 = -1;
    free(ppszText2);
  }
  hKey = 0;
  v10 = TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(a2, psz, 0, v10 | 0x20019, &hKey) )
    return v5;
  *szArg = 0;
  if ( !RegEnumKeyW(hKey, 0, &Name, 0x104u) )
  {
    v12 = lpszKeyName;
    do
    {
      KeyHandle = 0;
      if ( a5 )
      {
        v13 = ppszText2;
        lpszKeyName = &gszNullString;
      }
      else
      {
        v13 = _wcsdup(L"AutorunsDisabled");
        ppszText2 = v13;
        v14 = v117 | 1;
        v15 = *PE_CopyString2(&pszResult, L"\\", &ppszText2);
        v117 = v14 | 2;
        v108 = v14 | 2;
        lpszKeyName = v15;
      }
      v16 = _wcsdup(&Name);
      v17 = v16;
      v116.unused = v16;
      v122 = 14;
      lpszKeyName = *PE_CopyString(&ppv, &v116, lpszKeyName);
      LOBYTE(v122) = 15;
      v18 = TlsGetValue(gdwTlsIndex);
      v118 = PE_OpenKey(hKey, lpszKeyName, 0, v18 | 0x20019, &KeyHandle) == 0;
      free(ppv);
      free(v17);
      v19 = v117;
      if ( v117 & 2 )
      {
        v117 &= 0xFFFFFFFD;
        v108 = v117;
        free(pszResult);
        v19 = v117;
      }
      v122 = -1;
      if ( v19 & 1 )
      {
        v117 = v19 & 0xFFFFFFFE;
        v108 = v19 & 0xFFFFFFFE;
        free(v13);
      }
      if ( v118 )
      {
        cbData = 520;
        if ( !RegQueryValueExW(KeyHandle, L"Debugger", 0, 0, Data, &cbData) )
        {
          pszText = malloc(2u);
          *pszText = 0;
          v122 = 16;
          v116.unused = malloc(2u);
          *v116.unused = 0;
          v110 = malloc(2u);
          *v110 = 0;
          v54 = malloc(2u);
          *v54 = 0;
          v55 = 0;
          v56 = 0;
          v57 = 0;
          LOBYTE(v122) = 19;
          sub_F77040(Data, &v54);
          sub_F74EE0(&szArg4, v112, &v54, 0);
          LOBYTE(v122) = 20;
          v100.unused = sub_F74ED0();
          v88 = _wcsdup(&Name);
          v20 = v104;
          v21 = &gszNullString;
          if ( v104 )
            v21 = v104;
          szArg3 = _wcsdup(v21);
          v107 = _wcsdup(&gszNullString);
          v22 = &gszNullString;
          if ( v20 )
            v22 = v20;
          v103 = _wcsdup(v22);
          v23 = _wcsdup(&Name);
          lpszKeyName = v23;
          v24 = PE_CopyString(&v72, &lpszKeyName, L"\\Debugger");
          LOBYTE(v122) = 26;
          v25 = sub_F77BE0(v59, v111, &szArg3, v24);
          LOBYTE(v122) = 27;
          v26 = sub_F77BE0(v58, v111, &v103, &v107);
          LOBYTE(v122) = 28;
          v118 = sub_F73D40(v112, v26, v25, &v88, &szArg4, &pszText, &v110, &v60);
          free(*v58);
          free(*v59);
          free(v72);
          free(v23);
          free(v103);
          free(v107);
          free(szArg3);
          free(v88);
          if ( v118 )
          {
            if ( a4 == -1 )
            {
              v92 = _wcsdup(&gszNullString);
              v84 = _wcsdup(&gszNullString);
              v94 = _wcsdup(&gszNullString);
              v80 = _wcsdup(&gszNullString);
              v79 = _wcsdup(&gszNullString);
              v96 = _wcsdup(&gszNullString);
              v75 = _wcsdup(&gszNullString);
              v27 = v104;
              v28 = &gszNullString;
              if ( v104 )
                v28 = v104;
              v77 = _wcsdup(v28);
              v81 = _wcsdup(&gszNullString);
              v29 = &gszNullString;
              if ( v27 )
                v29 = v27;
              v83 = _wcsdup(v29);
              LOBYTE(v122) = 38;
              v30 = sub_F77BE0(v70, v111, &v77, &v75);
              LOBYTE(v122) = 39;
              v31 = sub_F77BE0(v64, v111, &v83, &v81);
              LOBYTE(v122) = 40;
              a4 = sub_F73FF0(v112, 0, 0xFFFFFFFF, 0, v31, v30, &v96);
              free(*v64);
              free(*v70);
              free(v83);
              free(v81);
              free(v77);
              free(v75);
              free(v96);
              free(v79);
              free(v80);
              free(v94);
              free(v84);
              free(v92);
            }
            else
            {
              v27 = v104;
            }
            v98 = _wcsdup(&gszNullString);
            v82 = _wcsdup(Data);
            v32 = &gszNullString;
            if ( v27 )
              v32 = v27;
            v90 = _wcsdup(v32);
            ppv3 = _wcsdup(&Name);
            v33 = _wcsdup(&Name);
            lpszKeyName = v33;
            v34 = PE_CopyString(&v66, &lpszKeyName, L"\\Debugger");
            LOBYTE(v122) = 46;
            v35 = sub_F77BE0(v62, v111, &v90, v34);
            LOBYTE(v122) = 47;
            sub_F73FF0(v112, v100.unused, a4, 1, &ppv3, v35, &szArg4);
            free(*v62);
            free(v66);
            free(v33);
            free(ppv3);
            free(v90);
            free(v82);
            free(v98);
          }
          free(szArg4);
          sub_F721F0(&v54);
          free(v110);
          free(v116.unused);
          v122 = -1;
          free(pszText);
        }
        RegCloseKey(KeyHandle);
      }
      v36 = TlsGetValue(gdwTlsIndex);
      if ( !PE_OpenKey(hKey, &Name, 0, v36 | 0x20019, &KeyHandle) )
      {
        cbData = 4;
        if ( !RegQueryValueExW(KeyHandle, L"GlobalFlag", 0, 0, v61, &cbData) && *v61 & 0x100 )
        {
          if ( a4 == -1 )
          {
            a1a = _wcsdup(&gszNullString);
            v122 = 48;
            v85 = _wcsdup(&gszNullString);
            v87 = _wcsdup(&gszNullString);
            v89 = _wcsdup(&gszNullString);
            v91 = _wcsdup(&gszNullString);
            v93 = _wcsdup(&gszNullString);
            v95 = _wcsdup(&gszNullString);
            v37 = v104;
            v38 = &gszNullString;
            if ( v104 )
              v38 = v104;
            v97 = _wcsdup(v38);
            v86 = _wcsdup(&gszNullString);
            v39 = &gszNullString;
            if ( v37 )
              v39 = v37;
            v78 = _wcsdup(v39);
            v40 = v111;
            LOBYTE(v122) = 57;
            v41 = sub_F77BE0(v71, v111, &v97, &v95);
            LOBYTE(v122) = 58;
            v42 = sub_F77BE0(v73, v40, &v78, &v86);
            LOBYTE(v122) = 59;
            a4 = sub_F73FF0(v112, 0, 0xFFFFFFFF, 0, v42, v41, &v93);
            free(*v73);
            free(*v71);
            free(v78);
            free(v86);
            free(v97);
            free(v95);
            free(v93);
            free(v91);
            free(v89);
            free(v87);
            free(v85);
            free(a1a);
          }
          if ( a5 )
          {
            lpszKeyName = &gszNullString;
          }
          else
          {
            v12 = _wcsdup(L"AutorunsDisabled");
            lpszKeyName = v12;
            v43 = PE_CopyString2(&v65, L"\\", &lpszKeyName);
            v117 |= 0xCu;
            v44 = *v43;
            v108 = v117;
            lpszKeyName = v44;
          }
          v45 = _wcsdup(&Name);
          v46 = v45;
          v116.unused = v45;
          v47 = &gszNullString;
          if ( v104 )
            v47 = v104;
          v48 = _wcsdup(v47);
          v49 = v48;
          v100.unused = v48;
          v50 = PE_CopyString(&v67, &v100, L"\\");
          v51 = PE_CopyStringEx(&ppv1, v50, &v116);
          PE_CopyString(&v63, v51, lpszKeyName);
          v122 = 60;
          free(ppv1);
          free(v67);
          free(v49);
          free(v46);
          v52 = v117;
          if ( v117 & 8 )
          {
            v117 &= 0xFFFFFFF7;
            v108 = v117;
            free(v65);
            v52 = v117;
          }
          if ( v52 & 4 )
          {
            v117 = v52 & 0xFFFFFFFB;
            v108 = v52 & 0xFFFFFFFB;
            free(v12);
          }
          v53 = v63;
          sub_F86A10(v112, v111, v63, L"VerifierDlls", &Name, 32, a4);
          v122 = -1;
          free(v53);
        }
        RegCloseKey(KeyHandle);
      }
      ++*szArg;
    }
    while ( !RegEnumKeyW(hKey, *szArg, &Name, 0x104u) );
  }
  RegCloseKey(hKey);
  return a4;
}

//----- (00F85E10) --------------------------------------------------------
void *__cdecl sub_F85E10(int a1, void *a2, OLECHAR *psz)
{
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  void *v8; // eax
  void *v9; // eax
  void *v10; // esi
  void *v11; // edi
  void *v13; // [esp+10h] [ebp-1Ch]
  _bstr_t v14; // [esp+14h] [ebp-18h]
  _bstr_t v15; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&v14, L"AutorunsDisabled");
  v17 = 0;
  v3 = _bstr_t::_bstr_t(&v15, L"\\");
  LOBYTE(v17) = 1;
  v4 = _bstr_t::operator+(&a1a, psz, v3);
  LOBYTE(v17) = 2;
  _bstr_t::operator+(&v4->m_Data, &v13, &v14);
  v5 = a1a.m_Data;
  if ( a1a.m_Data )
  {
    if ( !InterlockedDecrement(&a1a.m_Data->m_RefCount) && v5 )
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
    a1a.m_Data = 0;
  }
  v6 = v15.m_Data;
  if ( v15.m_Data )
  {
    if ( !InterlockedDecrement(&v15.m_Data->m_RefCount) && v6 )
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
    v15.m_Data = 0;
  }
  v7 = v14.m_Data;
  LOBYTE(v17) = 6;
  if ( v14.m_Data && !InterlockedDecrement(&v14.m_Data->m_RefCount) )
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
  v8 = sub_F85FF0(a1, a2, psz, 0xFFFFFFFF, 1);
  v9 = sub_F85FF0(a1, a2, psz, v8, 0);
  v10 = v13;
  v11 = v9;
  if ( v13 && !InterlockedDecrement(v13 + 2) && v10 )
  {
    if ( *v10 )
    {
      SysFreeString(*v10);
      *v10 = 0;
    }
    if ( *(v10 + 1) )
    {
      j_j__free(*(v10 + 1));
      *(v10 + 1) = 0;
    }
    j__free(v10);
  }
  return v11;
}

//----- (00F85FF0) --------------------------------------------------------
void *__cdecl sub_F85FF0(int a1, void *a2, wchar_t *a3, void *a4, char a5)
{
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  unsigned __int16 **v7; // esi
  unsigned __int16 **v8; // eax
  wchar_t *v9; // eax
  wchar_t *v10; // eax
  int v11; // ecx
  tagKeyName *v12; // ebx
  const WCHAR **v13; // eax
  WCHAR *v14; // eax
  WCHAR *v15; // ebx
  wchar_t *v16; // eax
  wchar_t *v17; // edi
  const wchar_t *v18; // eax
  wchar_t *v19; // esi
  LPCWSTR *v20; // eax
  unsigned __int16 **v21; // eax
  LPCWSTR *v22; // eax
  unsigned __int16 **v23; // eax
  unsigned int v24; // eax
  wchar_t *v25; // esi
  WCHAR *v26; // eax
  tagKeyName *v27; // edi
  unsigned int v28; // eax
  int v29; // eax
  const WCHAR **v30; // edi
  const WCHAR **v31; // ecx
  const WCHAR **v32; // eax
  const WCHAR **v33; // eax
  unsigned __int16 **v34; // esi
  unsigned __int16 **v35; // eax
  const WCHAR **v36; // esi
  const WCHAR **v37; // eax
  const WCHAR **v38; // eax
  unsigned __int16 **v39; // eax
  const WCHAR **v40; // eax
  unsigned __int16 **v41; // eax
  int v43; // [esp+10h] [ebp-494h]
  int v44; // [esp+20h] [ebp-484h]
  int a2a; // [esp+24h] [ebp-480h]
  DWORD cbData; // [esp+28h] [ebp-47Ch]
  HKEY KeyHandle; // [esp+2Ch] [ebp-478h]
  HKEY hKey; // [esp+30h] [ebp-474h]
  WCHAR v49[2]; // [esp+34h] [ebp-470h]
  WCHAR szArg[2]; // [esp+38h] [ebp-46Ch]
  int v51; // [esp+3Ch] [ebp-468h]
  void *v52; // [esp+40h] [ebp-464h]
  LPCWSTR szArg3; // [esp+44h] [ebp-460h]
  WCHAR *pszText; // [esp+48h] [ebp-45Ch]
  LPCWSTR v55; // [esp+4Ch] [ebp-458h]
  HKEY hRootKey; // [esp+50h] [ebp-454h]
  LPCWSTR szArg4; // [esp+54h] [ebp-450h]
  void *v58; // [esp+58h] [ebp-44Ch]
  WCHAR *v59; // [esp+5Ch] [ebp-448h]
  LPCWSTR v60; // [esp+60h] [ebp-444h]
  WCHAR *ppv3; // [esp+64h] [ebp-440h]
  LPCWSTR v62; // [esp+68h] [ebp-43Ch]
  WCHAR *ppv; // [esp+6Ch] [ebp-438h]
  WCHAR *ppv1; // [esp+70h] [ebp-434h]
  LPCWSTR v65; // [esp+74h] [ebp-430h]
  HKEY__ v66; // [esp+78h] [ebp-42Ch]
  void *a1a; // [esp+7Ch] [ebp-428h]
  char v68; // [esp+83h] [ebp-421h]
  wchar_t Data[260]; // [esp+84h] [ebp-420h]
  wchar_t v70[260]; // [esp+28Ch] [ebp-218h]
  int v71; // [esp+4A0h] [ebp-4h]

  v51 = a1;
  hRootKey = a2;
  *szArg = a3;
  if ( a4 == -1 )
  {
    v65 = _wcsdup(&gszNullString);
    v71 = 0;
    v52 = _wcsdup(&gszNullString);
    ppv1 = _wcsdup(&gszNullString);
    ppv = _wcsdup(&gszNullString);
    v60 = _wcsdup(&gszNullString);
    v58 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( a3 )
      v5 = a3;
    pszText = _wcsdup(v5);
    v55 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( a3 )
      v6 = a3;
    szArg3 = _wcsdup(v6);
    LOBYTE(v71) = 9;
    v7 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v71) = 10;
    v8 = sub_F77BE0(&v66, a2, &szArg3, &v55);
    LOBYTE(v71) = 11;
    a4 = sub_F73FF0(v51, 0, 0xFFFFFFFF, 0, v8, v7, &v58);
    free(v66.unused);
    free(a1a);
    free(szArg3);
    free(v55);
    free(pszText);
    free(szArg4);
    free(v58);
    free(v60);
    free(ppv);
    free(ppv1);
    free(v52);
    free(v65);
  }
  v65 = malloc(2u);
  *v65 = 0;
  v71 = 12;
  hKey = 0;
  v9 = _wcsdup(a3);
  szArg3 = v9;
  v10 = wcsrchr(v9, 0x5Cu);
  *v10 = 0;
  v11 = (v10 + 1);
  *v49 = v10 + 1;
  if ( a5 )
  {
    v12 = _wcsdup(a3);
    v52 = v12;
    free(v65);
  }
  else
  {
    v13 = &gszNullString;
    if ( v11 )
      v13 = v11;
    v14 = _wcsdup(v13);
    v15 = v14;
    ppv3 = v14;
    v16 = _wcsdup(L"AutorunsDisabled");
    v17 = v16;
    a1a = v16;
    v18 = &gszNullString;
    if ( szArg3 )
      v18 = szArg3;
    v19 = _wcsdup(v18);
    v66.unused = v19;
    v20 = PE_CopyString(&ppv, &v66, L"\\");
    v21 = PE_CopyStringEx(&ppv1, v20, &a1a);
    v22 = PE_CopyString(&v62, v21, L"\\");
    v23 = PE_CopyStringEx(&v59, v22, &ppv3);
    v52 = _wcsdup(*v23);
    free(v65);
    free(v59);
    free(v62);
    free(ppv1);
    free(ppv);
    free(v19);
    free(v17);
    free(v15);
    v12 = v52;
  }
  v24 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hRootKey, v12, 0, v24 | 0x20019, &hKey) )
  {
    KeyHandle = 0;
    cbData = 520;
    if ( !RegQueryValueExW(hKey, 0, 0, 0, Data, &cbData) )
    {
      v25 = _wcsdup(Data);
      v66.unused = v25;
      v26 = PE_CopyString2(&ppv3, L"Software\\Classes\\", &v66);
      v27 = *PE_CopyString(&a1a, v26, L"\\shell\\open\\command");
      LOBYTE(v71) = 15;
      v28 = TlsGetValue(gdwTlsIndex);
      v68 = PE_OpenKey(hRootKey, v27, 0, v28 | 0x20019, &KeyHandle) == 0;
      free(a1a);
      free(ppv3);
      LOBYTE(v71) = 12;
      free(v25);
      if ( v68 )
      {
        cbData = 520;
        if ( !RegQueryValueExW(KeyHandle, 0, 0, 0, v70, &cbData) )
        {
          v29 = wcscmp(v70, L"\"%1\" %*");
          if ( v29 )
            v29 = -(v29 < 0) | 1;
          if ( v29 )
          {
            szArg4 = malloc(2u);
            *szArg4 = 0;
            v55 = malloc(2u);
            *v55 = 0;
            pszText = malloc(2u);
            *pszText = 0;
            sub_F72170(&v43);
            LOBYTE(v71) = 19;
            sub_F77040(v70, &v43);
            sub_F74EE0(&v58, v51, &v43, 0);
            LOBYTE(v71) = 20;
            a2a = sub_F74ED0();
            v62 = _wcsdup(&gszNullString);
            v30 = *szArg;
            v31 = &gszNullString;
            if ( *szArg )
              v31 = *szArg;
            v60 = _wcsdup(v31);
            ppv = _wcsdup(&gszNullString);
            v32 = &gszNullString;
            if ( v30 )
              v32 = v30;
            ppv1 = _wcsdup(v32);
            v33 = &gszNullString;
            if ( v30 )
              v33 = v30;
            v65 = _wcsdup(v33);
            LOBYTE(v71) = 25;
            v34 = sub_F77BE0(&a1a, hRootKey, &v60, &v62);
            LOBYTE(v71) = 26;
            v35 = sub_F77BE0(&v66, hRootKey, &ppv1, &ppv);
            LOBYTE(v71) = 27;
            v68 = sub_F73D40(v51, &v65, v35, v34, &v58, &szArg4, &pszText, &v44);
            free(v66.unused);
            free(a1a);
            free(v65);
            free(ppv1);
            free(ppv);
            free(v60);
            LOBYTE(v71) = 20;
            free(v62);
            if ( v68 )
            {
              if ( a4 == -1 )
              {
                v66.unused = _wcsdup(&gszNullString);
                a1a = _wcsdup(&gszNullString);
                ppv3 = _wcsdup(&gszNullString);
                v59 = _wcsdup(&gszNullString);
                v60 = _wcsdup(&gszNullString);
                ppv = _wcsdup(&gszNullString);
                ppv1 = _wcsdup(&gszNullString);
                v36 = &gszNullString;
                v37 = &gszNullString;
                if ( v30 )
                  v37 = v30;
                v65 = _wcsdup(v37);
                v38 = &gszNullString;
                if ( *v49 )
                  v38 = *v49;
                v62 = _wcsdup(v38);
                LOBYTE(v71) = 36;
                v39 = sub_F77BE0(szArg, hRootKey, &v65, &ppv1);
                LOBYTE(v71) = 37;
                a4 = sub_F73FF0(v51, 0, 0xFFFFFFFF, 0, &v62, v39, &ppv);
                free(*szArg);
                free(v62);
                free(v65);
                free(ppv1);
                free(ppv);
                free(v60);
                free(v59);
                free(ppv3);
                free(a1a);
                free(v66.unused);
              }
              else
              {
                v36 = &gszNullString;
              }
              v62 = _wcsdup(&gszNullString);
              v59 = _wcsdup(v70);
              ppv3 = _wcsdup(&gszNullString);
              v40 = &gszNullString;
              if ( v30 )
                v40 = v30;
              a1a = _wcsdup(v40);
              if ( v30 )
                v36 = v30;
              v66.unused = _wcsdup(v36);
              LOBYTE(v71) = 42;
              v41 = sub_F77BE0(v49, hRootKey, &a1a, &ppv3);
              LOBYTE(v71) = 43;
              sub_F73FF0(v51, a2a, a4, 3, &v66, v41, &v58);
              free(*v49);
              free(v66.unused);
              free(a1a);
              free(ppv3);
              free(v59);
              free(v62);
            }
            free(v58);
            sub_F721F0(&v43);
            free(pszText);
            free(v55);
            free(szArg4);
          }
        }
        RegCloseKey(KeyHandle);
      }
    }
    RegCloseKey(hKey);
  }
  free(szArg3);
  free(v12);
  return a4;
}
// 103244C: using guessed type wchar_t a1_0[8];

//----- (00F86A10) --------------------------------------------------------
void *__cdecl sub_F86A10(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, wchar_t *a5, int a6, void *a7)
{
  unsigned int v7; // eax
  int v8; // esi
  char *v9; // ecx
  int v10; // ebx
  OLECHAR **v11; // edi
  void *v12; // esi
  const wchar_t **v13; // eax
  void *v14; // esi
  const wchar_t *v15; // ecx
  const wchar_t *v16; // eax
  const wchar_t *v17; // eax
  unsigned __int16 **v18; // esi
  unsigned __int16 **v19; // eax
  char v20; // bl
  const wchar_t *v21; // eax
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  const wchar_t *v24; // eax
  unsigned __int16 **v25; // eax
  void *v27; // [esp+10h] [ebp-78h]
  int v28; // [esp+14h] [ebp-74h]
  int v29; // [esp+18h] [ebp-70h]
  WCHAR v30[2]; // [esp+1Ch] [ebp-6Ch]
  int a2a; // [esp+20h] [ebp-68h]
  int v32; // [esp+24h] [ebp-64h]
  void *a1a; // [esp+28h] [ebp-60h]
  WCHAR szArg[2]; // [esp+2Ch] [ebp-5Ch]
  void *v35; // [esp+30h] [ebp-58h]
  HKEY hKey; // [esp+34h] [ebp-54h]
  int v37; // [esp+38h] [ebp-50h]
  unsigned int v38; // [esp+3Ch] [ebp-4Ch]
  void *v39; // [esp+40h] [ebp-48h]
  LPCWSTR v40; // [esp+44h] [ebp-44h]
  LPCWSTR v41; // [esp+48h] [ebp-40h]
  WCHAR *ppv3; // [esp+4Ch] [ebp-3Ch]
  LPCWSTR szArg4; // [esp+50h] [ebp-38h]
  WCHAR *pszText; // [esp+54h] [ebp-34h]
  LPCWSTR v45; // [esp+58h] [ebp-30h]
  LPCWSTR szArg3; // [esp+5Ch] [ebp-2Ch]
  void *v47; // [esp+60h] [ebp-28h]
  void *v48; // [esp+64h] [ebp-24h]
  wchar_t *v49; // [esp+68h] [ebp-20h]
  void *v50; // [esp+6Ch] [ebp-1Ch]
  void *v51; // [esp+70h] [ebp-18h]
  void *v52; // [esp+74h] [ebp-14h]
  int v53; // [esp+84h] [ebp-4h]

  v52 = malloc(2u);
  *v52 = 0;
  v53 = 0;
  v50 = malloc(2u);
  *v50 = 0;
  v47 = malloc(2u);
  *v47 = 0;
  v48 = malloc(2u);
  *v48 = 0;
  v51 = malloc(2u);
  *v51 = 0;
  LOBYTE(v53) = 4;
  v7 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, psz, 0, v7 | 0x20019, &hKey) )
  {
    v49 = malloc(2u);
    *v49 = 0;
    LOBYTE(v53) = 5;
    if ( !sub_F81520(hKey, lpValueName, 0, 0, &v49) && wcslen(v49) )
    {
      v27 = 0;
      v28 = 0;
      v29 = 0;
      LOBYTE(v53) = 6;
      sub_F76DD0(v49, 44, &v27, 0);
      v8 = v28;
      v9 = v27;
      v38 = 0;
      if ( (v28 - v27) >> 4 )
      {
        v10 = 0;
        v37 = 0;
        do
        {
          v11 = &v9[v10];
          v12 = v51;
          v51 = _wcsdup(**&v9[v10 + 4]);
          free(v12);
          v13 = sub_F74EE0(&v35, a1, v11, 0);
          v14 = v52;
          v52 = _wcsdup(*v13);
          free(v14);
          free(v35);
          a2a = sub_F74ED0();
          v15 = &gszNullString;
          if ( lpValueName )
            v15 = lpValueName;
          szArg4 = _wcsdup(v15);
          v16 = &gszNullString;
          if ( psz )
            v16 = psz;
          pszText = _wcsdup(v16);
          v45 = _wcsdup(&gszNullString);
          v17 = &gszNullString;
          if ( psz )
            v17 = psz;
          szArg3 = _wcsdup(v17);
          LOBYTE(v53) = 10;
          v18 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
          LOBYTE(v53) = 11;
          v19 = sub_F77BE0(szArg, a2, &szArg3, &v45);
          LOBYTE(v53) = 12;
          v20 = sub_F73D40(a1, v19, v18, v11, &v52, &v50, &v48, &v32);
          free(*szArg);
          free(a1a);
          free(szArg3);
          free(v45);
          free(pszText);
          LOBYTE(v53) = 6;
          free(szArg4);
          if ( v20 )
          {
            v21 = &gszNullString;
            if ( lpValueName )
              v21 = lpValueName;
            v39 = _wcsdup(v21);
            v22 = &gszNullString;
            if ( lpValueName )
              v22 = lpValueName;
            v40 = _wcsdup(v22);
            v23 = &gszNullString;
            if ( psz )
              v23 = psz;
            v41 = _wcsdup(v23);
            v24 = &gszNullString;
            if ( a5 )
              v24 = a5;
            ppv3 = _wcsdup(v24);
            LOBYTE(v53) = 16;
            v25 = sub_F77BE0(v30, a2, &v41, &v40);
            LOBYTE(v53) = 17;
            sub_F73FF0(a1, a2a, a7, 1, &ppv3, v25, &v52);
            free(*v30);
            free(ppv3);
            free(v41);
            free(v40);
            LOBYTE(v53) = 6;
            free(v39);
          }
          v8 = v28;
          v9 = v27;
          v10 = v37 + 16;
          ++v38;
          v37 += 16;
        }
        while ( v38 < (v28 - v27) >> 4 );
      }
      if ( v9 )
      {
        sub_F72BF0(v9, v8);
        j__free(v27);
      }
    }
    RegCloseKey(hKey);
    free(v49);
  }
  free(v51);
  free(v48);
  free(v47);
  free(v50);
  free(v52);
  return a7;
}

//----- (00F86E10) --------------------------------------------------------
void *__cdecl sub_F86E10(int a1, void *a2, OLECHAR *psz, LPCWSTR lpValueName)
{
  _bstr_t *v4; // eax
  _bstr_t *v5; // eax
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  Data_t_bstr_t *v8; // esi
  void *v9; // eax
  wchar_t *v10; // ecx
  void *v11; // eax
  void *v12; // esi
  void *v13; // edi
  void *v15; // [esp+10h] [ebp-1Ch]
  _bstr_t v16; // [esp+14h] [ebp-18h]
  _bstr_t v17; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&v16, L"AutorunsDisabled");
  v19 = 0;
  v4 = _bstr_t::_bstr_t(&v17, L"\\");
  LOBYTE(v19) = 1;
  v5 = _bstr_t::operator+(&a1a, psz, v4);
  LOBYTE(v19) = 2;
  _bstr_t::operator+(&v5->m_Data, &v15, &v16);
  v6 = a1a.m_Data;
  if ( a1a.m_Data )
  {
    if ( !InterlockedDecrement(&a1a.m_Data->m_RefCount) && v6 )
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
    a1a.m_Data = 0;
  }
  v7 = v17.m_Data;
  if ( v17.m_Data )
  {
    if ( !InterlockedDecrement(&v17.m_Data->m_RefCount) && v7 )
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
    v17.m_Data = 0;
  }
  v8 = v16.m_Data;
  LOBYTE(v19) = 6;
  if ( v16.m_Data && !InterlockedDecrement(&v16.m_Data->m_RefCount) )
  {
    if ( v8->m_wstr )
    {
      SysFreeString(v8->m_wstr);
      v8->m_wstr = 0;
    }
    if ( v8->m_str )
    {
      j_j__free(v8->m_str);
      v8->m_str = 0;
    }
    j__free(v8);
  }
  v9 = sub_F87000(a1, a2, psz, lpValueName, -1);
  if ( v15 )
    v10 = *v15;
  else
    v10 = 0;
  v11 = sub_F87000(a1, a2, v10, lpValueName, v9);
  v12 = v15;
  v13 = v11;
  if ( v15 && !InterlockedDecrement(v15 + 2) && v12 )
  {
    if ( *v12 )
    {
      SysFreeString(*v12);
      *v12 = 0;
    }
    if ( *(v12 + 1) )
    {
      j_j__free(*(v12 + 1));
      *(v12 + 1) = 0;
    }
    j__free(v12);
  }
  return v13;
}

//----- (00F87000) --------------------------------------------------------
void *__cdecl sub_F87000(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5)
{
  void *v5; // ebx
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  unsigned __int16 **v10; // esi
  unsigned __int16 **v11; // eax
  LPCWSTR v13; // ebx
  wchar_t *v14; // esi
  DWORD v15; // eax
  int v16; // edi
  _WORD *v17; // eax
  WCHAR *v18; // eax
  const WCHAR **v19; // ecx
  const wchar_t *v20; // eax
  const WCHAR **v21; // eax
  const wchar_t *v22; // eax
  unsigned __int16 **v23; // edi
  unsigned __int16 **v24; // eax
  OLECHAR **v25; // ST40_4
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  const wchar_t *v29; // eax
  const wchar_t *v30; // eax
  unsigned __int16 **v31; // edi
  unsigned __int16 **v32; // eax
  const WCHAR **v33; // eax
  const wchar_t *v34; // eax
  unsigned __int16 **v35; // eax
  int a2a; // [esp+10h] [ebp-A4h]
  int v37; // [esp+14h] [ebp-A0h]
  int v38; // [esp+18h] [ebp-9Ch]
  int v39; // [esp+1Ch] [ebp-98h]
  WCHAR v40[2]; // [esp+20h] [ebp-94h]
  WCHAR v41[2]; // [esp+24h] [ebp-90h]
  WCHAR v42[2]; // [esp+28h] [ebp-8Ch]
  int v43; // [esp+2Ch] [ebp-88h]
  WCHAR v44[2]; // [esp+30h] [ebp-84h]
  int v45; // [esp+34h] [ebp-80h]
  WCHAR v46[2]; // [esp+38h] [ebp-7Ch]
  void *v47; // [esp+3Ch] [ebp-78h]
  void *v48; // [esp+40h] [ebp-74h]
  LPCWSTR v49; // [esp+44h] [ebp-70h]
  WCHAR *ppv3; // [esp+48h] [ebp-6Ch]
  LPCWSTR v51; // [esp+4Ch] [ebp-68h]
  void *v52; // [esp+50h] [ebp-64h]
  LPCWSTR v53; // [esp+54h] [ebp-60h]
  void *v54; // [esp+58h] [ebp-5Ch]
  LPCWSTR v55; // [esp+5Ch] [ebp-58h]
  void *v56; // [esp+60h] [ebp-54h]
  LPCWSTR v57; // [esp+64h] [ebp-50h]
  void *v58; // [esp+68h] [ebp-4Ch]
  void *a1a; // [esp+6Ch] [ebp-48h]
  HKEY hKey; // [esp+70h] [ebp-44h]
  WCHAR szArg[2]; // [esp+74h] [ebp-40h]
  LPCWSTR v62; // [esp+78h] [ebp-3Ch]
  void *v63; // [esp+7Ch] [ebp-38h]
  LPCWSTR v64; // [esp+80h] [ebp-34h]
  LPCWSTR v65; // [esp+84h] [ebp-30h]
  LPCWSTR v66; // [esp+88h] [ebp-2Ch]
  LPCWSTR v67; // [esp+8Ch] [ebp-28h]
  LPCWSTR szArg3; // [esp+90h] [ebp-24h]
  DWORD cbData; // [esp+94h] [ebp-20h]
  LPCWSTR v70; // [esp+98h] [ebp-1Ch]
  void *ppv1; // [esp+9Ch] [ebp-18h]
  WCHAR *pszText; // [esp+A0h] [ebp-14h]
  LPCWSTR szArg4; // [esp+A4h] [ebp-10h]
  int v74; // [esp+B0h] [ebp-4h]

  v5 = a5;
  ppv1 = a5;
  if ( dword_10631D8 && a5 == -1 )
  {
    v63 = _wcsdup(&gszNullString);
    v74 = 0;
    v65 = _wcsdup(&gszNullString);
    v66 = _wcsdup(&gszNullString);
    v62 = _wcsdup(&gszNullString);
    v64 = _wcsdup(&gszNullString);
    v67 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( lpValueName )
      v6 = lpValueName;
    szArg4 = _wcsdup(v6);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v8 = &gszNullString;
    if ( lpValueName )
      v8 = lpValueName;
    v70 = _wcsdup(v8);
    v9 = &gszNullString;
    if ( psz )
      v9 = psz;
    szArg3 = _wcsdup(v9);
    LOBYTE(v74) = 9;
    v10 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v74) = 10;
    v11 = sub_F77BE0(szArg, a2, &szArg3, &v70);
    LOBYTE(v74) = 11;
    v5 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v11, v10, &v67);
    ppv1 = v5;
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v70);
    free(pszText);
    free(szArg4);
    free(v67);
    free(v64);
    free(v62);
    free(v66);
    free(v65);
    v74 = -1;
    free(v63);
  }
  hKey = 0;
  PE_OpenKey(a2, psz, 0, 0x20019u, &hKey);
  if ( !hKey )
    return v5;
  v13 = lpValueName;
  cbData = 0;
  RegQueryValueExW(hKey, lpValueName, 0, 0, 0, &cbData);
  v14 = operator new[](2 * ((cbData >> 1) + 2));
  RegQueryValueExW(hKey, lpValueName, 0, 0, v14, &cbData);
  v15 = cbData >> 1;
  cbData = v15;
  if ( v15 > 2 )
  {
    v14[v15 - 1] = 0;
    v14[cbData] = 0;
    if ( *v14 )
    {
      v16 = a1;
      do
      {
        v17 = malloc(2u);
        a2a = v17;
        *v17 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v74 = 12;
        sub_F76CC0(v14, &a2a);
        *szArg = _wcsdup(v14);
        LOBYTE(v74) = 13;
        sub_F74EE0(&szArg4, v16, &a2a, 0);
        v18 = szArg4;
        if ( *szArg4 )
        {
          pszText = malloc(2u);
          *pszText = 0;
          szArg3 = malloc(2u);
          *szArg3 = 0;
          v70 = malloc(2u);
          *v70 = 0;
          LOBYTE(v74) = 17;
          v43 = sub_F74ED0();
          v19 = &gszNullString;
          if ( v13 )
            v19 = v13;
          v64 = _wcsdup(v19);
          v20 = &gszNullString;
          if ( psz )
            v20 = psz;
          v62 = _wcsdup(v20);
          v21 = &gszNullString;
          if ( v13 )
            v21 = v13;
          v66 = _wcsdup(v21);
          v22 = &gszNullString;
          if ( psz )
            v22 = psz;
          v65 = _wcsdup(v22);
          v63 = _wcsdup(v14);
          LOBYTE(v74) = 22;
          v23 = sub_F77BE0(v44, a2, &v62, &v64);
          LOBYTE(v74) = 23;
          v24 = sub_F77BE0(v46, a2, &v65, &v66);
          LOBYTE(v74) = 24;
          v25 = v23;
          v16 = a1;
          v26 = sub_F73D40(a1, &v63, v24, v25, &szArg4, &pszText, &v70, &v45);
          free(*v46);
          free(*v44);
          free(v63);
          free(v65);
          free(v66);
          free(v62);
          free(v64);
          if ( v26 )
          {
            if ( ppv1 == -1 )
            {
              v48 = _wcsdup(&gszNullString);
              v52 = _wcsdup(&gszNullString);
              v47 = _wcsdup(&gszNullString);
              v54 = _wcsdup(&gszNullString);
              v58 = _wcsdup(&gszNullString);
              v56 = _wcsdup(&gszNullString);
              v13 = lpValueName;
              v27 = &gszNullString;
              if ( lpValueName )
                v27 = lpValueName;
              v55 = _wcsdup(v27);
              v28 = &gszNullString;
              if ( psz )
                v28 = psz;
              v57 = _wcsdup(v28);
              v29 = &gszNullString;
              if ( lpValueName )
                v29 = lpValueName;
              v49 = _wcsdup(v29);
              v30 = &gszNullString;
              if ( psz )
                v30 = psz;
              v67 = _wcsdup(v30);
              LOBYTE(v74) = 34;
              v31 = sub_F77BE0(v42, a2, &v57, &v55);
              LOBYTE(v74) = 35;
              v32 = sub_F77BE0(v40, a2, &v67, &v49);
              LOBYTE(v74) = 36;
              ppv1 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v32, v31, &v56);
              free(*v40);
              free(*v42);
              free(v67);
              free(v49);
              free(v57);
              free(v55);
              free(v56);
              free(v58);
              free(v54);
              free(v47);
              free(v52);
              free(v48);
            }
            else
            {
              v13 = lpValueName;
            }
            a1a = _wcsdup(&gszNullString);
            v33 = &gszNullString;
            if ( v13 )
              v33 = v13;
            v51 = _wcsdup(v33);
            v34 = &gszNullString;
            if ( psz )
              v34 = psz;
            v53 = _wcsdup(v34);
            ppv3 = _wcsdup(v14);
            LOBYTE(v74) = 40;
            v35 = sub_F77BE0(v41, a2, &v53, &v51);
            v16 = a1;
            LOBYTE(v74) = 41;
            sub_F73FF0(a1, v43, ppv1, 5, &ppv3, v35, &szArg4);
            free(*v41);
            free(ppv3);
            free(v53);
            free(v51);
            free(a1a);
          }
          else
          {
            v13 = lpValueName;
          }
          free(v70);
          free(szArg3);
          free(pszText);
          v18 = szArg4;
        }
        free(v18);
        free(*szArg);
        v74 = -1;
        sub_F721F0(&a2a);
        v14 = wcschr(v14 + 1, 0) + 1;
      }
      while ( *v14 );
    }
  }
  RegCloseKey(hKey);
  return ppv1;
}
// 10631D8: using guessed type int dword_10631D8;

//----- (00F87710) --------------------------------------------------------
void __cdecl sub_F87710(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F877C0(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F877C0(a1, a2, v7, v5);
  free(v7);
}

//----- (00F877C0) --------------------------------------------------------
void *__cdecl sub_F877C0(int a1, void *a2, wchar_t *psz, void *a4)
{
  WCHAR *v4; // edi
  _WORD *v5; // ebx
  tagKeyName *v6; // esi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  unsigned __int16 **v9; // esi
  unsigned __int16 **v10; // eax
  LPCWSTR *v11; // ebx
  WCHAR *v12; // eax
  _WORD *v13; // edx
  WCHAR v14; // cx
  WCHAR *v15; // esi
  unsigned __int16 **v16; // eax
  WCHAR *v17; // esi
  unsigned __int16 **v18; // eax
  _WORD *v19; // eax
  const wchar_t **v20; // eax
  void *v21; // esi
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  unsigned __int16 **v24; // esi
  unsigned __int16 **v25; // eax
  const wchar_t *v26; // eax
  const wchar_t *v27; // eax
  unsigned __int16 **v28; // esi
  unsigned __int16 **v29; // eax
  const wchar_t *v30; // eax
  unsigned __int16 **v31; // eax
  WCHAR v32; // cx
  int v34; // [esp+10h] [ebp-BCh]
  int v35; // [esp+14h] [ebp-B8h]
  int v36; // [esp+18h] [ebp-B4h]
  int v37; // [esp+1Ch] [ebp-B0h]
  WCHAR *ppv1; // [esp+20h] [ebp-ACh]
  _WORD *v39; // [esp+24h] [ebp-A8h]
  WCHAR v40[2]; // [esp+28h] [ebp-A4h]
  WCHAR v41[2]; // [esp+2Ch] [ebp-A0h]
  WCHAR v42[2]; // [esp+30h] [ebp-9Ch]
  int v43; // [esp+34h] [ebp-98h]
  void *v44; // [esp+38h] [ebp-94h]
  WCHAR v45[2]; // [esp+3Ch] [ebp-90h]
  WCHAR v46[2]; // [esp+40h] [ebp-8Ch]
  WCHAR *ppv; // [esp+44h] [ebp-88h]
  void *v48; // [esp+48h] [ebp-84h]
  LPCWSTR v49; // [esp+4Ch] [ebp-80h]
  HKEY KeyHandle; // [esp+50h] [ebp-7Ch]
  LPCWSTR v51; // [esp+54h] [ebp-78h]
  void *v52; // [esp+58h] [ebp-74h]
  void *v53; // [esp+5Ch] [ebp-70h]
  void *v54; // [esp+60h] [ebp-6Ch]
  void *v55; // [esp+64h] [ebp-68h]
  void *v56; // [esp+68h] [ebp-64h]
  HKEY hKey; // [esp+6Ch] [ebp-60h]
  void *a1a; // [esp+70h] [ebp-5Ch]
  WCHAR szArg[2]; // [esp+74h] [ebp-58h]
  void *v60; // [esp+78h] [ebp-54h]
  void *v61; // [esp+7Ch] [ebp-50h]
  WCHAR *ppv2; // [esp+80h] [ebp-4Ch]
  wchar_t *v63; // [esp+84h] [ebp-48h]
  wchar_t *v64; // [esp+88h] [ebp-44h]
  LPCWSTR v65; // [esp+8Ch] [ebp-40h]
  LPCWSTR v66; // [esp+90h] [ebp-3Ch]
  LPCWSTR v67; // [esp+94h] [ebp-38h]
  WCHAR *ppv3; // [esp+98h] [ebp-34h]
  LPCWSTR v69; // [esp+9Ch] [ebp-30h]
  LPCWSTR v70; // [esp+A0h] [ebp-2Ch]
  LPCWSTR szArg4; // [esp+A4h] [ebp-28h]
  LPCWSTR v72; // [esp+A8h] [ebp-24h]
  LPCWSTR v73; // [esp+ACh] [ebp-20h]
  WCHAR *pszText; // [esp+B0h] [ebp-1Ch]
  LPCWSTR szArg3; // [esp+B4h] [ebp-18h]
  void *v76; // [esp+B8h] [ebp-14h]
  char v77; // [esp+BFh] [ebp-Dh]
  int v78; // [esp+C8h] [ebp-4h]

  v64 = malloc(2u);
  *v64 = 0;
  v78 = 0;
  v4 = malloc(2u);
  ppv2 = v4;
  *v4 = 0;
  v63 = malloc(2u);
  *v63 = 0;
  v5 = malloc(2u);
  v39 = v5;
  *v5 = 0;
  v76 = malloc(2u);
  *v76 = 0;
  v60 = malloc(2u);
  *v60 = 0;
  v61 = malloc(2u);
  *v61 = 0;
  v56 = malloc(2u);
  *v56 = 0;
  v6 = psz;
  LOBYTE(v78) = 7;
  if ( a4 == -1 )
  {
    v70 = _wcsdup(&gszNullString);
    v65 = _wcsdup(&gszNullString);
    v67 = _wcsdup(&gszNullString);
    v69 = _wcsdup(&gszNullString);
    v72 = _wcsdup(&gszNullString);
    v73 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v66 = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( psz )
      v8 = psz;
    szArg3 = _wcsdup(v8);
    LOBYTE(v78) = 17;
    v9 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v78) = 18;
    v10 = sub_F77BE0(szArg, a2, &szArg3, &v66);
    LOBYTE(v78) = 19;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v10, v9, &v73);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v66);
    free(pszText);
    free(szArg4);
    free(v73);
    free(v72);
    free(v69);
    free(v67);
    free(v65);
    LOBYTE(v78) = 7;
    free(v70);
    v6 = psz;
  }
  if ( !PE_OpenKey(ghLocalMachineKey, v6, 0, 1u, &KeyHandle) )
  {
    if ( !sub_F81520(KeyHandle, L"ProviderOrder", 0, 0, &v64) )
    {
      v11 = operator new(4u);
      if ( v11 )
        *v11 = _wcsdup(v64);
      else
        v11 = 0;
      v12 = v64;
      szArg3 = v64;
      do
      {
        v13 = *v11;
        **v11 = 0;
        v14 = *v12;
        if ( *v12 )
        {
          do
          {
            if ( v14 == 44 )
              break;
            if ( v14 == 32 )
              break;
            ++v12;
            *v13 = v14;
            ++v13;
            v14 = *v12;
          }
          while ( *v12 );
          szArg3 = v12;
        }
        *v13 = 0;
        v15 = _wcsdup(L"System\\CurrentControlSet\\Services\\");
        ppv2 = v15;
        v16 = PE_CopyStringEx(&ppv1, &ppv2, v11);
        ppv3 = v4;
        v4 = _wcsdup(*v16);
        ppv2 = v4;
        free(ppv3);
        free(ppv1);
        free(v15);
        v17 = _wcsdup(L"\\NetworkProvider");
        ppv3 = v17;
        v18 = PE_CopyStringEx(&ppv, &ppv2, &ppv3);
        LOBYTE(v78) = 21;
        v77 = PE_OpenKey(a2, *v18, 0, 1u, &hKey) == 0;
        free(ppv);
        LOBYTE(v78) = 7;
        free(v17);
        if ( v77 )
        {
          if ( !sub_F81520(hKey, L"ProviderPath", 0, 0, &v63) )
          {
            v19 = malloc(2u);
            v34 = v19;
            *v19 = 0;
            v35 = 0;
            v36 = 0;
            v37 = 0;
            LOBYTE(v78) = 22;
            sub_F77040(v63, &v34);
            *szArg = _wcsdup(v63);
            LOBYTE(v78) = 23;
            v20 = sub_F74EE0(&v44, a1, &v34, 0);
            v21 = v76;
            v76 = _wcsdup(*v20);
            free(v21);
            free(v44);
            ppv3 = sub_F74ED0();
            sub_F81520(hKey, L"Name", 0, 0, &v61);
            v69 = _wcsdup(L"ProviderOrder");
            v22 = &gszNullString;
            if ( psz )
              v22 = psz;
            v67 = _wcsdup(v22);
            v65 = _wcsdup(&gszNullString);
            v23 = &gszNullString;
            if ( psz )
              v23 = psz;
            v70 = _wcsdup(v23);
            LOBYTE(v78) = 27;
            v24 = sub_F77BE0(v42, a2, &v67, &v69);
            LOBYTE(v78) = 28;
            v25 = sub_F77BE0(v40, a2, &v70, &v65);
            LOBYTE(v78) = 29;
            v77 = sub_F73D40(a1, v11, v25, v24, &v76, &v60, &v56, &v43);
            free(*v40);
            free(*v42);
            free(v70);
            free(v65);
            free(v67);
            free(v69);
            if ( v77 )
            {
              if ( a4 == -1 )
              {
                v53 = _wcsdup(&gszNullString);
                v48 = _wcsdup(&gszNullString);
                v52 = _wcsdup(&gszNullString);
                v55 = _wcsdup(&gszNullString);
                v54 = _wcsdup(&gszNullString);
                v66 = _wcsdup(&gszNullString);
                pszText = _wcsdup(&gszNullString);
                v26 = &gszNullString;
                if ( psz )
                  v26 = psz;
                szArg4 = _wcsdup(v26);
                v73 = _wcsdup(&gszNullString);
                v27 = &gszNullString;
                if ( psz )
                  v27 = psz;
                v72 = _wcsdup(v27);
                LOBYTE(v78) = 39;
                v28 = sub_F77BE0(v45, a2, &szArg4, &pszText);
                LOBYTE(v78) = 40;
                v29 = sub_F77BE0(v46, a2, &v72, &v73);
                LOBYTE(v78) = 41;
                a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v29, v28, &v66);
                free(*v46);
                free(*v45);
                free(v72);
                free(v73);
                free(szArg4);
                free(pszText);
                free(v66);
                free(v54);
                free(v55);
                free(v52);
                free(v48);
                free(v53);
              }
              a1a = _wcsdup(&gszNullString);
              v51 = _wcsdup(L"ProviderOrder");
              v30 = &gszNullString;
              if ( psz )
                v30 = psz;
              v49 = _wcsdup(v30);
              LOBYTE(v78) = 44;
              v31 = sub_F77BE0(v41, a2, &v49, &v51);
              LOBYTE(v78) = 45;
              sub_F73FF0(a1, ppv3, a4, 5, v11, v31, &v76);
              free(*v41);
              free(v49);
              free(v51);
              free(a1a);
            }
            free(*szArg);
            LOBYTE(v78) = 7;
            sub_F721F0(&v34);
          }
          RegCloseKey(hKey);
        }
        v12 = szArg3;
        v32 = *szArg3;
        if ( !*szArg3 )
          break;
        while ( v32 == 44 || v32 == 32 )
        {
          v32 = v12[1];
          ++v12;
          szArg3 = v12;
          if ( !v32 )
            goto LABEL_42;
        }
      }
      while ( *v12 );
LABEL_42:
      v5 = v39;
    }
    RegCloseKey(KeyHandle);
  }
  free(v56);
  free(v61);
  free(v60);
  free(v76);
  free(v5);
  free(v63);
  free(v4);
  free(v64);
  return a4;
}

//----- (00F87FE0) --------------------------------------------------------
void __cdecl sub_F87FE0(int a1, HKEY hKey, WCHAR **ppszKeyName)
{
  WCHAR *v3; // ST20_4

  v3 = malloc(2u);
  *v3 = 0;
  sub_F88050(a1, hKey, *ppszKeyName, 0xFFFFFFFF);
  free(v3);
}
