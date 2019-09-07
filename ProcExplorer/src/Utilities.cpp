#include "stdafx.h"
#include "../ProcExplorer.h"
#include "../include/RegSettings.h"
#include <shellapi.h>
#include <devguid.h>
#include <Dbghelp.h>
#pragma comment(lib,"Dbghelp.lib")
#pragma comment(lib,"Shell32.lib")

typedef list<_bstr_t> cbstrList;


LPFN_CreateRestrictedToken gpfnCreateRestrictedToken = NULL;
LPFN_WinVerifyTrust    gpfnWinVerifyTrust = NULL;
LPFN_WTHelperGetProvSignerFromChain    gpfnWTHelperGetProvSignerFromChain = NULL;
LPFN_WTHelperProvDataFromStateData    gpfnWTHelperProvDataFromStateData = NULL;
LPFN_CryptCATAdminReleaseContext    gpfnCryptCATAdminReleaseContext = NULL;
LPFN_CryptCATAdminReleaseCatalogContext    gpfnCryptCATAdminReleaseCatalogContext = NULL;
LPFN_CryptCATCatalogInfoFromContext    gpfnCryptCATCatalogInfoFromContext = NULL;
LPFN_CryptCATAdminEnumCatalogFromHash    gpfnCryptCATAdminEnumCatalogFromHash = NULL;
LPFN_CryptCATAdminCalcHashFromFileHandle    gpfnCryptCATAdminCalcHashFromFileHandle = NULL;
LPFN_CryptCATAdminAcquireContext    gpfnCryptCATAdminAcquireContext = NULL;
LPFN_CertNameToStrW    gpfnCertNameToStrW = NULL;
LPFN_CryptCATAdminAddCatalog    gpfnCryptCATAdminAddCatalog = NULL;
LPFN_CryptCATAdminRemoveCatalog    gpfnCryptCATAdminRemoveCatalog = NULL;
LPFN_IsCatalogFile    gpfnIsCatalogFile = NULL;

LPFN_NtQueryInformationProcess gpfnNtQueryInformationProcess = NULL;
LPFN_NtQueryInformationThread gpfnNtQueryInformationThread = NULL;
LPFN_NtQuerySystemInformation gpfnNtQuerySystemInformation = NULL;

LPFN_RtlInitUnicodeString gpfnRtlInitUnicodeString = NULL;
LPFN_RtlNtStatusToDosError gpfnRtlNtStatusToDosError = NULL;
//INIT_LOAD(RtlInitUnicodeString);
//INIT_LOAD(RtlNtStatusToDosError);

INIT_LOAD(NtOpenThread);
INIT_LOAD(NtQueryInformationThread);


INIT_LOAD(NtOpenSymbolicLinkObject);
INIT_LOAD(NtQuerySymbolicLinkObject);
INIT_LOAD(NtQueryInformationProcess);
LPFN_EnableTraceEx gpfn_EnableTraceEx = (LPFN_EnableTraceEx)::GetProcAddress(LoadLibraryW(L"Advapi32.dll"), "EnableTraceEx");

LPFN_ZwOpenKey gpfn_NtOpenKey = (LPFN_ZwOpenKey)::GetProcAddress(LoadLibraryW(L"NTDLL.DLL"), "NtOpenKey");
LPFN_ZwCreateKey gpfn_NtCreateKey = (LPFN_ZwCreateKey)::GetProcAddress(LoadLibraryW(L"NTDLL.DLL"), "NtCreateKey");

SYSTEM_INFO			gSystemInfo = { 0 };


int					gnNumArgs = 0;

WCHAR				gszLocaleInfo[16] = { L'.' };

tagProcessComment*	gpProcessComments = NULL;
WCHAR**				gpHiddenProcesses = NULL;

HFONT				ghConfigFont = NULL;
HFONT				ghConfigUnderlineFont = NULL;
HFONT				ghDefaultUnderlineFontHandle = NULL;


bool				gbWintrustInited = false;
UINT				gShellIconMsg = 0;

int					gcyScreen = GetSystemMetrics(SM_CYSCREEN);
int					gcxScreen = GetSystemMetrics(SM_CXSCREEN);
int					gcxFullScreen = GetSystemMetrics(SM_CXVIRTUALSCREEN);
int					gcyFullScreen = GetSystemMetrics(SM_CYVIRTUALSCREEN);

///For the MM_TEXT mapping mode, you can use the following formula 
/// to specify a height for a font with a specified point size :

tagLogPixelSize		gLogPixelSize;

/// 系统帐户HASH表
CAccountInfoMap		gAccoutInfoMap;
CAccountInfoArray	garrAccountInfo;
tagAccountInfo*		gpAccountInfo = NULL;
CKeyNameMap			gKeyNameMap;
cbstrList			gBstrList;
CLock				gBstrListLock;
HKEY				ghLocalMachineKey = HKEY_LOCAL_MACHINE;
HKEY				ghCurrentUserKey = HKEY_CURRENT_USER;
bool				gbRestorePrivilegeFailed = false;
SystemDirInfo		gSystemDirInfo;
WCHAR				gszWindowsDirectory[_MAX_PATH] = { 0 };
WCHAR				gszProgramW6432EnvValue[_MAX_PATH] = { 0 };
WCHAR				gszProgameFilesX86EnvValueValue[_MAX_PATH] = { 0 };
DWORD				gdwTlsIndex = 0;
CLock				gBackendThreadLock;
WCHAR*				gpszSystemPathInfo = NULL;
HANDLE				ghAppToken = NULL;



BOOL LoadDbgHelp();

#define PROCESS_DUMPFILE	0x10000000

typedef struct tagDUMPFILEINFO
{
	DWORD	dwPid;
	BOOL	fFullMemory;
	DWORD	dwError;
	WCHAR	szFileName[_MAX_PATH];
}DUMPFILEINFO,*PDUMPFILEINFO,*LPDUMPFILEINFO;


BOOL DumpFileProcess(HANDLE FileHandle, HANDLE ProcessHandle, BOOL fFullMemory);


//////////////////////////////////////////////////////////////////////////
//
//	检测是否为WOW32Process模式
//	
//////////////////////////////////////////////////////////////////////////
BOOL FakeIsWow64Process(VOID)
{
	BOOL ret = FALSE;
	HMODULE hModuleKernel32 = GetModuleHandleW(L"kernel32.dll");
	LPFN_IsWow64Process pfnIsWow64Process = (LPFN_IsWow64Process)GetProcAddress(hModuleKernel32, "IsWow64Process");
	if (pfnIsWow64Process)
	{
		pfnIsWow64Process(GetCurrentProcess(), &ret);
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////
//
//	加载共享内存
//	
//////////////////////////////////////////////////////////////////////////
DWORD WINAPI LoadSharedMemory(VOID* p)
{
	LoadDbgHelp();
	HANDLE hServerEvent = CreateEventW(0, 0, 0, L"Procexp32bitServerEvent");
	HANDLE hClientEvent = CreateEventW(0, 0, 0, L"Procexp32bitClientEvent");
	if (hClientEvent)
	{
		PAGE_READONLY;
		if (hServerEvent)
		{
			HANDLE hMapping = CreateFileMappingW(
				(HANDLE)INVALID_HANDLE_VALUE,
				0,
				PAGE_REVERT_TO_FILE_MAP | PAGE_READWRITE,
				0,
				gSystemInfo.dwPageSize,
				L"Procexp32bitSection");
			tagDUMPFILEINFO* pFileInfo = (tagDUMPFILEINFO *)MapViewOfFile(hMapping, 6u, 0, 0, gSystemInfo.dwPageSize);
			DWORD dwRet = WaitForSingleObject(hServerEvent, INFINITE);
			if (!dwRet)
			{
				const WCHAR* pszFileName = (const WCHAR *)&pFileInfo->szFileName;
				do
				{
					//待DUMP的文件
					HANDLE hFileHandle = CreateFileW(pszFileName, GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE| FILE_SHARE_DELETE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
					if (hFileHandle == INVALID_HANDLE_VALUE)
					{
						pFileInfo->dwError = GetLastError();
					}
					else
					{
						///打开指定的进程
						HANDLE hProcess = OpenProcess(PROCESS_DUMPFILE, FALSE, pFileInfo->dwPid);
						if (hProcess)
						{
							//DUMP操作
							if (!DumpFileProcess(hFileHandle, hProcess, pFileInfo->fFullMemory))
								pFileInfo->dwError = GetLastError();
							CloseHandle(hProcess);
						}
						else
						{
							pFileInfo->dwError = GetLastError();
						}
						CloseHandle(hFileHandle);
					}
					SetEvent(hClientEvent);
					dwRet = WaitForSingleObject(hServerEvent, INFINITE);
					pszFileName = (const WCHAR *)&pFileInfo->szFileName;
				} while (!dwRet);
			}
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//	加载DBGHLP.DLL
//	
//////////////////////////////////////////////////////////////////////////
BOOL LoadDbgHelp()
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	Dump进程
//	FileHandle:		待写入的文件句柄
//	ProcessHandle:	待DUMP的进程句柄
//	fFullMemory:	是否包括全内存
//	
//	返回值:			
//	
//////////////////////////////////////////////////////////////////////////
BOOL DumpFileProcess(HANDLE FileHandle, HANDLE ProcessHandle, BOOL fFullMemory)
{
	HMODULE hModuleDbgHlp = LoadLibrary(TEXT("DBGHELP.DLL"));
	MINIDUMP_TYPE DumpType = MINIDUMP_TYPE(MiniDumpWithThreadInfo | MiniDumpWithProcessThreadData | MiniDumpWithDataSegs | MiniDumpWithHandleData);

	if (hModuleDbgHlp&&GetProcAddress(hModuleDbgHlp, "EnumDirTreeW"))
	{
		if (fFullMemory)
			DumpType = MINIDUMP_TYPE(DumpType | MiniDumpWithFullMemoryInfo | MiniDumpWithFullMemory);
	}
	else
	{
		DumpType = MINIDUMP_TYPE(MiniDumpWithProcessThreadData | MiniDumpWithDataSegs | MiniDumpWithHandleData);
		if (fFullMemory)
			DumpType = MINIDUMP_TYPE(DumpType | MiniDumpWithFullMemory);
	}
	return MiniDumpWriteDump(ProcessHandle, GetProcessId(ProcessHandle), FileHandle, DumpType, NULL, NULL, NULL);
}

//////////////////////////////////////////////////////////////////////////
//
//	SaveDriverFromResource 将指定的二进制资源保存到指定的文件名中
//	lpszResID:		待保存的资源ID号
//	lpszFileName:	待写入的文件名称
//	
//	返回值:			
//	
//////////////////////////////////////////////////////////////////////////
BOOL SaveDriverFromResource(LPCWSTR lpszResID, LPCWSTR lpszFileName)
{
	HRSRC hRes = FindResourceW(NULL, lpszResID, L"BINRES");
	if (!hRes)
		return 0;
	HGLOBAL hGlobal = LoadResource(NULL, hRes);
	DWORD dwSize = SizeofResource(NULL, hRes);
	VOID* pBuffer = LockResource(hGlobal);
	FILE *pFile = NULL;
	if (_wfopen_s(&pFile, lpszFileName, L"wb"))
		return 0;
	fwrite(pBuffer, sizeof(CHAR), dwSize, pFile);
	fclose(pFile);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	SaveDriverFromResource 将指定的二进制资源保存到指定的文件名中
//	lpszResID:		待保存的资源ID号
//	lpszFileName:	待写入的文件名称
//	
//	返回值:			
//	
//////////////////////////////////////////////////////////////////////////
BOOL LaunchProcExplorer64(BOOL fDeleteFile, int nCmdShow)
{
	STARTUPINFOW StartupInfo = { sizeof(StartupInfo) };
	PROCESS_INFORMATION ProcessInformation = { 0 };
	WCHAR	szFileName[_MAX_PATH] = { 0 };
	WCHAR	szPathName[_MAX_PATH] = { 0 };
	HKEY	hMainKey = NULL;
	UINT	nResID;

	ZeroMemory(&StartupInfo.lpDesktop, sizeof(StartupInfo) - 8);
	///	获取当前可执行模块的全路径名称
	DWORD dwRet = GetModuleFileNameW(NULL, szFileName, _MAX_PATH - 1);
	if (dwRet)
	{
		///	保存到注册表中
		if (!RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hMainKey))
		{
			/// 注册表中产生一个原始路径的字符串字段名称
			RegSetValueExW(hMainKey, L"OriginalPath", 0, REG_SZ, (BYTE*)szFileName, (DWORD)(wcslen(szFileName) * sizeof(WCHAR)));
			RegCloseKey(hMainKey);
		}

		///删除末尾后缀
		*wcsrchr(szFileName, L'.') = 0;
		///添加64.exe后缀
		wcscat_s(szFileName, _MAX_PATH, L"64.exe");
		/// 检测当前系统是否为IA64位 
		if (gSystemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
		{
			nResID = IDS_DRIVER_64;
		}
		else
		{
			/// 不支持的系统架构，则报错
			if (gSystemInfo.wProcessorArchitecture != PROCESSOR_ARCHITECTURE_AMD64)
			{
				wsprintfW(szFileName, L"Unsupported processor type: %d\n", gSystemInfo.wProcessorArchitecture);
				MessageBoxW(NULL, szFileName, IDS_PROCEXPOLER, MB_ICONERROR);
				return 0;
			}
			nResID = IDS_DRIVER_32;
		}
		/// 扩展为TEMP全路径
		ExpandEnvironmentStringsW(L"%TEMP%", szPathName, MAX_PATH);
		WCHAR* psz = wcsrchr(szFileName, L'\\');
		wcscat_s(szPathName, MAX_PATH, psz);
		wcscpy_s(szFileName, MAX_PATH, szPathName);
		/// 将资源内的驱动文件释放到TEMP路径下
		if (!SaveDriverFromResource(MAKEINTRESOURCEW(nResID), szFileName)
			&& GetFileAttributesW(szFileName) == INVALID_FILE_ATTRIBUTES)
		{
			return 0;
		}
		/// 保存到注册表中
		if (!RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hMainKey))
		{
			RegSetValueExW(hMainKey, L"Path", 0, REG_SZ, (const BYTE *)szFileName, (DWORD)(2 * wcslen(szFileName)));
			RegCloseKey(hMainKey);
		}

		/// 准备启动64位进程
		StartupInfo.wShowWindow = nCmdShow;
		StartupInfo.dwFlags = STARTF_USESHOWWINDOW;

		if (!CreateProcessW(szFileName, GetCommandLineW(), NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcessInformation))
			return FALSE;
		if (fDeleteFile)
		{
			WaitForSingleObject(ProcessInformation.hProcess, INFINITE);
			DeleteFileW(szFileName);
		}
		CloseHandle(ProcessInformation.hProcess);
		CloseHandle(ProcessInformation.hThread);
		dwRet = TRUE;
	}

	//DLGTEMPLATEEX* lpDialogTemplate = (LPCDLGTEMPLATEW)::LocalAlloc(LMEM_ZEROINIT, sizeof(DLGTEMPLATE));

	//DialogBoxIndirectParamW(NULL, lpDialogTemplate, NULL, DialogFunc, InitParam);
	return dwRet;
}


//////////////////////////////////////////////////////////////////////////
//
//	加载DBGHLP.DLL
//	
//////////////////////////////////////////////////////////////////////////
BOOL IsNanoServer()
{
	HKEY hKey = NULL;
	BOOL ret = FALSE;
	DWORD Data = 0;
	DWORD cbData = sizeof(DWORD);
	DWORD Type = 0;
	if (!RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Server\\ServerLevels", &hKey))
	{
		if (!RegQueryValueExW(hKey, L"NanoServer", FALSE, &Type, (BYTE*)&Data, &cbData)
			&& Type == REG_DWORD
			&& Data == 1)
			ret = TRUE;
		RegCloseKey(hKey);
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////
//
//	DlgLicense	授权许可对话框回调函数 
//	hDlg:		待保存的资源ID号
//	msg:		待写入的文件名称
//	wParam:		
//	lParam:		
//	
//	返回值:			
//	
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgLicense(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
			EndDialog(hDlg, 1);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		case 501:
			break;
		default:
			return 0;
		}
	case WM_CTLCOLORSTATIC:
		//if (lParam == (LPARAM)GetDlgItem(hDlg, 500))
		//	return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);
		break;
	}

	return 1;
}

//////////////////////////////////////////////////////////////////////////
//
//	ExitWithLicenseInfo	在输出CONSOLE窗口中输出授权许可后，退出 
//	
//////////////////////////////////////////////////////////////////////////
VOID ExitWithLicenseInfo()
{
	exit(0);
}

//IDOK		"&Agree"
//IDCANCEL	"&Decline"
//501		"&Print"
//500		RichEditCtrl
//502		Static
//////////////////////////////////////////////////////////////////////////
//
//	ShowLicenseView	显示授权许可对话框 
//	lpszTitle:			
//	pszArguments:	
//	lpszTitle:		
//	
//	返回值:			
//	
//////////////////////////////////////////////////////////////////////////
BOOL ShowLicenseView(LPCWSTR lpszTitle)
{
	typedef LPWSTR * (WINAPI* LPFN_CommandLineToArgvW)(_In_ LPCWSTR lpCmdLine, _Out_ int* pNumArgs);
	//LPFN_CommandLineToArgvW pfnCommandLineToArgw = (LPFN_CommandLineToArgvW)GetProcAddress(LoadLibrary(TEXT("SHELL32.DLL")), "CommandLineToArgvW");

	//int nNumArgs = gnNumArgs;
	//LPWSTR* ppstrCmdLine = pfnCommandLineToArgw(GetCommandLineW(), &gnNumArgs);


	//if (IsNanoServer()
	//	|| GetFileType(GetStdHandle(STD_OUTPUT_HANDLE)) == FILE_TYPE_PIPE))
	//{
	//	ExitWithLicenseInfo();
	//}
	//0x
	//typedef struct {
	//	DWORD style;			//0
	//	DWORD dwExtendedStyle;	//0x04
	//	WORD cdit;				//0x08
	//	short x;				//0x0A
	//	
	//	short y;				//0x0C
	//	short cx;				//0x0E
	//	
	//	short cy;				//0x10

	//	DWORD	dwValue1;		//0x12

	//	WCHAR	szTitle[36];		//0x16
	//	WORD	wValue2;			//0x3A
	//	WCHAR	szDlgType[];	//0x3C

	//} DLGTEMPLATE;

	HMODULE hModule = LoadLibrary(TEXT("RICHED32.DLL"));

	LPCDLGTEMPLATEW pTemplate = (LPCDLGTEMPLATEW)::LocalAlloc(LMEM_ZEROINIT, 1000);
	DLGTEMPLATE* pDlgTemplate = (DLGTEMPLATE*)pTemplate;

	DWORD dwSize = sizeof(DLGTEMPLATE);

	pDlgTemplate->style = WS_POPUP | WS_BORDER | WS_DLGFRAME | WS_SYSMENU | DS_CENTER| DS_SYSMODAL|DS_LOCALEDIT|DS_SETFONT;
	//pDlgTemplate->x = 0;
	//pDlgTemplate->cx = 11796792;
	//pDlgTemplate->cdit = 0;
	//pDlgTemplate->dwExtendedStyle = 0;

	DLGITEMTEMPLATE* pItemStatic = (DLGITEMTEMPLATE*)(pDlgTemplate + 1);

	//pItemStatic->cx = 196615;
	//pItemStatic->cy = 917802;
	pItemStatic->id = IDD_LICENSE_STATIC;
	pItemStatic->style = WS_CHILD | WS_VISIBLE;
	pItemStatic->dwExtendedStyle = 0;

	WS_EX_CONTROLPARENT| WS_EX_STATICEDGE|WS_EX_APPWINDOW;

	pDlgTemplate->cdit++;

	DLGITEMTEMPLATE* pItemAgree = (DLGITEMTEMPLATE*)(pItemStatic + 1);
	ZeroMemory(pItemAgree, sizeof(DLGITEMTEMPLATE));
	pItemAgree->style = WS_VISIBLE | WS_CHILD | WS_TABSTOP;

	DLGITEMTEMPLATE* pItemDecline = (DLGITEMTEMPLATE*)(pItemAgree + 1);
	ZeroMemory(pItemDecline, sizeof(DLGITEMTEMPLATE));

	DLGITEMTEMPLATE* pItemPrint = (DLGITEMTEMPLATE*)(pItemDecline + 1);
	ZeroMemory(pItemPrint, sizeof(DLGITEMTEMPLATE));

	DLGITEMTEMPLATE* pItemRichEdit = (DLGITEMTEMPLATE*)(pItemPrint + 1);
	ZeroMemory(pItemRichEdit, sizeof(DLGITEMTEMPLATE));


	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	ParseArguments	解析命令行 
//	pnArg:			
//	pszArguments:	
//	lpszTitle:		
//	
//	返回值:			
//	
//////////////////////////////////////////////////////////////////////////
BOOL ParseArguments(LPCWSTR lpszTitle, int* pnArg, WCHAR* pszArguments)
{
	if (!pnArg || !pszArguments)
		return ShowLicenseView(lpszTitle);

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	ProductIsIOTOAP
//	Return Value:
//
//////////////////////////////////////////////////////////////////////////
BOOL ProductIsIOTOAP()
{
	WCHAR szProductName[_MAX_PATH] = { 0 };

	HKEY hKey = 0;
	BOOL ret = FALSE;
	DWORD cbData = _MAX_PATH * sizeof(WCHAR);
	DWORD dwType = 0;
	if (!RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\windows nt\\currentversion", &hKey))
	{
		if (!RegQueryValueExW(hKey, L"ProductName", 0, &dwType, (BYTE*)szProductName, &cbData)
			&& !_wcsicmp(L"iotuap", szProductName))
		{
			ret = TRUE;
		}
		RegCloseKey(hKey);
	}
	return ret;
}


//////////////////////////////////////////////////////////////////////////
//	TmAdjustPrivilege	提权操作
//	LPCTSTR lpszName:
//
//	Return Value:		
//
//
//////////////////////////////////////////////////////////////////////////
BOOL TmAdjustPrivilege(LPCTSTR lpszName)
{
	HANDLE TokenHandle = NULL;
	LUID luid = { 0 };

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY, &TokenHandle))
		return FALSE;
	if (!LookupPrivilegeValue(NULL, lpszName, &luid))
	{
		CloseHandle(TokenHandle);
		return FALSE;
	}

	TOKEN_PRIVILEGES TokenPriv = { 0 };
	TokenPriv.Privileges[0].Luid = luid;
	TokenPriv.PrivilegeCount = 1;
	TokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	BOOL ret = AdjustTokenPrivileges(TokenHandle, FALSE, &TokenPriv, sizeof(TOKEN_PRIVILEGES), NULL, NULL);
	if (ret)
	{
		if (GetLastError())
			ret = FALSE;
	}
	CloseHandle(TokenHandle);
	return ret;
}

//////////////////////////////////////////////////////////////////////////
CRegSettings::CRegSettings()
{
	ZeroMemory(this, sizeof(*this));
}

CRegSettings gConfig;


//////////////////////////////////////////////////////////////////////////
//
//	AddTrayIcon
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL TrayIcon_Add(HWND hWnd, UINT nID, CGraphData* pGraphData, LPCWSTR lpszTipText)
{
	CHAR Buffer[sizeof(NOTIFYICONDATA) + 800] = { 0 };

	NOTIFYICONDATA *nid = (NOTIFYICONDATA*)Buffer;
	nid->uID = nID;
	nid->hWnd = hWnd;
	nid->cbSize = sizeof(Buffer);

	nid->uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	nid->uCallbackMessage = WM_NOTIFY_TRAYICON;
	////nid.hIcon = 

	BOOL ret = Shell_NotifyIcon(NIM_ADD, nid);

	///*DestroyIcon(nid.hIcon);*/

	return ret;
}

//////////////////////////////////////////////////////////////////////////
///
///	BitmapItem_Create: 创建一块指定高度宽度的内存图片
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL BitmapItem_Create(LPBITMAPITEM pItem, int nWidth, int nHeight)
{
	BITMAPINFO bi = { sizeof(bi) };
	bi.bmiHeader.biClrImportant = 0;
	bi.bmiHeader.biSize = offsetof(BITMAPINFO, bmiColors);
	bi.bmiHeader.biHeight = -nHeight;
	bi.bmiHeader.biWidth = nWidth;
	////*(DWORD*)&bi.bmiHeader.biPlanes = 0x200001;
	bi.bmiHeader.biBitCount = 32;
	bi.bmiHeader.biPlanes = 1;

	bi.bmiHeader.biClrUsed = 0;
	bi.bmiHeader.biCompression = 0;
	bi.bmiHeader.biSizeImage = 0;

	HDC hDC = GetDC(NULL);

	pItem->hBitmapHandle = CreateDIBSection(hDC, &bi, 0, &pItem->pBits, NULL, 0);
	pItem->nWidth = nWidth;
	pItem->nHeight = nHeight;
	pItem->hCompatibleDC = CreateCompatibleDC(hDC);
	SelectObject(pItem->hCompatibleDC, pItem->hBitmapHandle);
	ReleaseDC(NULL, hDC);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
///
///	BitmapItem_SetRectColor:将图片指定矩形区域设置为指定的颜色
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL BitmapItem_SetRectColor(LPBITMAPITEM pItem, RECT* lprc, COLORREF color)
{
	int left = 0;

	if (lprc->left > 0)
		left = lprc->left;
	

	int nWidth = pItem->nWidth;

	if (lprc->right < nWidth)
		nWidth = lprc->right;

	int y = 0;
	if (lprc->top > 0)
		y = lprc->top;

	int nHeight = pItem->nHeight;
	if (lprc->bottom < nHeight)
		nHeight = lprc->bottom;

	for (; y < nHeight; ++y)
	{
		int x = left;
		if (left < nWidth)
		{
			do
			{
				int nBit = x++ + y * pItem->nWidth;
				((COLORREF*)pItem->pBits)[nBit] = (color & 0xFF00) | (color << 16) | (color >> 16) & 0xFF;
			} while (x < nWidth);
		}
	}

	return TRUE;
}


//////////////////////////////////////////////////////////////////////////
BOOL TrayIcon_Delete(HWND hWnd, UINT nID)
{
	CHAR Buffer[sizeof(NOTIFYICONDATA) + 800] = { 0 };

	NOTIFYICONDATA *nid = (NOTIFYICONDATA*)Buffer;
	nid->uID = nID;
	nid->hWnd = hWnd;
	nid->cbSize = sizeof(Buffer);

	return Shell_NotifyIcon(NIM_DELETE, nid);
}

void RegVar_ReadWrite(BOOL fSave, DWORD dwCount, CRegVar* pVariable)
{
	tagConfigItem ConfigItems[20] = { 0 };
	
	WCHAR szBuffer[256] = { 0 };
	
	*(double*)&ConfigItems[1].dwValue1 = 200.0;
	*(double*)&ConfigItems[3].dwValue1 = 200.0;
	ConfigItems[1].Address = &pVariable->ProcessImageColumnWidth;
	ConfigItems[2].Address = pVariable->ProcessColumns;
	ConfigItems[3].Address = &pVariable->PrcessColumnCount;
	*&ConfigItems[4].Address = pVariable->ProcessColumnMap;
	ConfigItems[5].Address = &pVariable->DllColumnCount;
	ConfigItems[6].Address = pVariable->DllColumns;
	ConfigItems[7].Address = pVariable->DllColumnMap;
	*(double*)&ConfigItems[5].dwValue1 = 4.0;
	ConfigItems[8].Address = &pVariable->HandleColumnCount;
	ConfigItems[9].Address = pVariable->HandleColumnMap;
	*(double*)&ConfigItems[8].dwValue1 = 2.0;
	ConfigItems[10].Address = pVariable->HandleColumns;
	ConfigItems[0].Name = L"ColumnSetName";
	ConfigItems[0].RegType = 4;
	ConfigItems[0].StructSize = 520;	//130*4;
	ConfigItems[0].Address = pVariable;
	ConfigItems[1].Name = L"ProcessImageColumnWidth";
	ConfigItems[1].RegType = 3;
	ConfigItems[1].StructSize = 2;
	ConfigItems[2].Name = L"ProcessColumns";
	ConfigItems[2].RegType = 6;
	ConfigItems[2].StructSize = 192;	//96*2
	ConfigItems[3].Name = L"PrcessColumnCount";
	ConfigItems[3].StructSize = 0;
	ConfigItems[4].Name = L"ProcessColumnMap";
	ConfigItems[4].RegType = 5;
	ConfigItems[4].StructSize = 384;	//96*4
	ConfigItems[5].Name = L"DllColumnCount";
	ConfigItems[6].Name = L"DllColumns";
	ConfigItems[6].RegType = 6;
	ConfigItems[6].StructSize = 64;		//32*2
	ConfigItems[7].Name = L"DllColumnMap";
	ConfigItems[7].RegType = 5;
	ConfigItems[7].StructSize = 128;	//32*4
	ConfigItems[8].Name = L"HandleColumnCount";
	ConfigItems[9].Name = L"HandleColumnMap";
	ConfigItems[9].RegType = 5;
	ConfigItems[9].StructSize = 128;	//32*4
	ConfigItems[10].Name = L"HandleColumns";
	ConfigItems[10].StructSize = 64;
	ConfigItems[11].Name = L"HandleSortColumn";
	ConfigItems[11].Address = &pVariable->HandleSortColumn;
	ConfigItems[12].Name = L"HandleSortDirection";
	ConfigItems[12].Address = &pVariable->HandleSortDirection;
	ConfigItems[13].Address = &pVariable->DllSortColumn;
	ConfigItems[14].Address = &pVariable->DllSortDirection;
	ConfigItems[15].Address = &pVariable->ProcessSortColumn;
	ConfigItems[16].Address = &pVariable->ProcessSortDirection;
	ConfigItems[17].Address = &pVariable->ShowProcessTree;
	ConfigItems[18].Address = &pVariable->StatusBarColumns;
	*(LONGLONG*)&ConfigItems[15].dwValue1 = 0x41EFFFFFFFE00000i64;///dbl_4CEA40;
	ConfigItems[12].RegType = 1;
	*(double*)&ConfigItems[12].dwValue1 = 1.0;
	ConfigItems[13].Name = L"DllSortColumn";
	*(LONGLONG*)&ConfigItems[13].dwValue1 = 0i64;
	ConfigItems[14].Name = L"DllSortDirection";
	ConfigItems[14].RegType = 1;
	*(double*)&ConfigItems[14].dwValue1 = 1.0;
	ConfigItems[15].Name = L"ProcessSortColumn";
	ConfigItems[16].Name = L"ProcessSortDirection";
	ConfigItems[16].RegType = 1;
	*(double*)&ConfigItems[16].dwValue1 = 1.0;
	ConfigItems[17].Name = L"ShowProcessTree";
	ConfigItems[17].RegType = 1;
	*(double*)&ConfigItems[17].dwValue1 = 1.0;
	ConfigItems[18].Name = L"StatusBarColumns";
	*(double*)&ConfigItems[18].dwValue1 = 21.0;
	ConfigItems[19].Name = 0;
	ConfigItems[19].RegType = 0;
	ConfigItems[19].StructSize = 0;
	ConfigItems[19].Address = 0;
	*(LONGLONG*)&ConfigItems[19].dwValue1 = 0i64;
	
	wsprintfW(szBuffer, L"Software\\Sysinternals\\Process Explorer\\ColumnSet%d", dwCount);
	tagRegKeyInfo regKeyInfo;
	regKeyInfo.szKeyName = _wcsdup(szBuffer);

	if (fSave)
	{
		SaveConfigItemToRegistry(&regKeyInfo, ConfigItems);
	}
	else
	{
		LoadConfigItemFromRegistry(&regKeyInfo, ConfigItems);
	}
}


//////////////////////////////////////////////////////////////////////////
//
//	PEStrFromString
//
//
//
//
//////////////////////////////////////////////////////////////////////////
//////tagPESTR* PEStrFromString(LPCOLESTR pstr)
//////{
//////	tagPESTR* str = new tagPESTR();
//////	if (str)
//////	{
//////		str->pBuffer = NULL;
//////		str->nRefCount = 1;
//////		str->bstr = SysAllocString(pstr);
//////		if (!str->bstr)
//////			ErrorReport(E_OUTOFMEMORY);
//////		return str;
//////	}
//////	else
//////	{
//////		ErrorReport(E_OUTOFMEMORY);
//////	}
//////	return NULL;
//////}
//////
//////tagPESTR* PEStringAppend(tagPESTR& str1, tagPESTR& str2)
//////{
//////	return &str1;
//////}
//////
//////void PEStrRelease(tagPESTR* str)
//////{
//////	if (str->bstr)
//////	{
//////		if (!InterlockedDecrement(&str->nRefCount))
//////		{
//////			SysFreeString(str->bstr);
//////			str->bstr = NULL;
//////		}
//////		if (str->pBuffer)
//////		{
//////			free(str->pBuffer);
//////			str->pBuffer = NULL;
//////		}
//////		str->bstr = NULL;
//////	}
//////}

//////////////////////////////////////////////////////////////////////////
//
//	ErrorReport
//
//
//
//
//////////////////////////////////////////////////////////////////////////
void ErrorReport(DWORD dwError)
{

}

void ReportMsg(LPCTSTR lpszMsg, HWND hWnd)
{
	TCHAR* pszBuffer = NULL;
	TCHAR szText[256] = { 0 };
	DWORD dwError = GetLastError();
	if (dwError)
	{
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwError, LOCALE_USER_DEFAULT, (LPTSTR)&pszBuffer, 0, NULL);
		_stprintf_s(szText, TEXT("%s: %s"), lpszMsg, pszBuffer);
		LocalFree(pszBuffer);
	}
	else
	{
		_stprintf_s(szText, TEXT("%s."), lpszMsg);
	}
	MessageBox(hWnd, szText, TEXT("Process Explorer"), MB_ICONSTOP);
}

HICON ghStockIcon = NULL;
//////////////////////////////////////////////////////////////////////////
//
//	SetMenuIcon
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL SetMenuIcon(HMENU hMenu, UINT nItem)
{
	HICON hIcon = ghStockIcon;
	if (!ghStockIcon)
	{
		SHSTOCKICONINFO StockIconInfo = { sizeof(StockIconInfo) };
		SHGetStockIconInfo(SIID_DEVICECAMERA, SHGSI_ICON | SHGSI_SMALLICON, &StockIconInfo);
		hIcon = ghStockIcon = StockIconInfo.hIcon;
	}
	MENUITEMINFO mii = { sizeof(mii) };
	mii.fMask = MIIM_DATA|MIIM_BITMAP;
	mii.hbmpItem = (HBITMAP)-1;
	mii.dwItemData = (DWORD)hIcon;
	return SetMenuItemInfo(hMenu, nItem, FALSE, &mii);
}


#include "../include/d3dkmt.h"
CAdapterList gAdapterList;
ULONG gdwGraphCount = 0;

//////////////////////////////////////////////////////////////////////////
//
//	InitAdapterList
//
///////////////////////////////////////////////////////////////////////////
BOOL InitAdapterList(__int64* pMinSegments, __int64* pNbSegments)
{
	BOOL ret = FALSE;
	GUID CLSID_GUID_DISPLAY_DEVICE_ARRIVAL = { 0x1ca05180,0xa699,0x450a, 0x9a,0x0c,0xde,0x4f,0xbe,0x3d,0xdd,0x89 };
	SP_DEVINFO_DATA DeviceInfoData = { 0 };
	
	*pMinSegments = 0;
	*pNbSegments = 0;
	
	///GUID WceusbshGUID = { 0x25dbce51, 0x6c8f, 0x4a72, 0x8a,0x6d,0xb5,0x4c,0x2b,0x4f,0xc8,0x35 }
	HDEVINFO  DeviceInfoSet = SetupDiGetClassDevs(&CLSID_GUID_DISPLAY_DEVICE_ARRIVAL, NULL, NULL, DIGCF_DEVICEINTERFACE | DIGCF_PRESENT);
	if (DeviceInfoSet == INVALID_HANDLE_VALUE)
		return FALSE;

	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD DeviceIndex = 0;
	DWORD PropType = 0L;
	VOID* DevGuid = NULL;
	DWORD Size = 0L;
	SP_DEVICE_INTERFACE_DATA DeviceInterfaceData = { 0 };
	DWORD RequiredSize = 0;
	HMODULE hModule = LoadLibraryW(L"GDI32.DLL");
	if (!hModule)
		return FALSE;
	PFND3DKMT_OPENADAPTERFROMDEVICENAME pfnD3DKMTOpenAdapterFromDeviceName = (PFND3DKMT_OPENADAPTERFROMDEVICENAME)::GetProcAddress(hModule, "D3DKMTOpenAdapterFromDeviceName");
	if (pfnD3DKMTOpenAdapterFromDeviceName == NULL)
		return FALSE;
	PFND3DKMT_CLOSEADAPTER pfnD3DKMTCloseAdapter = (PFND3DKMT_CLOSEADAPTER)::GetProcAddress(hModule, "D3DKMTCloseAdapter");
	PFND3DKMT_QUERYSTATISTICS pfnD3DKMTQueryStatistics = (PFND3DKMT_QUERYSTATISTICS)::GetProcAddress(hModule, "D3DKMTQueryStatistics");


	if (!SetupDiEnumDeviceInterfaces(DeviceInfoSet, NULL, &CLSID_GUID_DISPLAY_DEVICE_ARRIVAL, 0, &DeviceInterfaceData))
	{
		DWORD dwError = GetLastError();
		goto __Exit;
	}


	int Index = 0;
	ULONG nNbSegments = 0L;
	while (1)
	{
		if (SetupDiGetDeviceInterfaceDetail(DeviceInfoSet, &DeviceInterfaceData, NULL, Index, &RequiredSize, NULL)
			|| GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
			SP_DEVICE_INTERFACE_DETAIL_DATA* pData = (SP_DEVICE_INTERFACE_DETAIL_DATA*)new char[RequiredSize];

			memset(pData, 0, RequiredSize);
			pData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA) + 2;
			SetupDiGetDeviceInterfaceDetail(DeviceInfoSet, &DeviceInterfaceData, pData, RequiredSize, NULL, NULL);

			D3DKMT_OPENADAPTERFROMDEVICENAME DeviceName = { 0 };
			DeviceName.pDeviceName = pData->DevicePath;
			(*pfnD3DKMTOpenAdapterFromDeviceName)(&DeviceName);

			D3DKMT_QUERYSTATISTICS StatisticsAdapter;
			ZeroMemory(&StatisticsAdapter, sizeof(D3DKMT_QUERYSTATISTICS));
			StatisticsAdapter.AdapterLuid = DeviceName.AdapterLuid;
			StatisticsAdapter.Type = D3DKMT_QUERYSTATISTICS_ADAPTER;

			if (!pfnD3DKMTQueryStatistics(&StatisticsAdapter))
			{
				gdwGraphCount = StatisticsAdapter.QueryResult.AdapterInformation.NodeCount;
			}
			gAdapterList.push_back(DeviceName.AdapterLuid);
			if (StatisticsAdapter.QueryResult.AdapterInformation.NbSegments)
			{
				UINT nSegmentID = 0;
				do
				{
					D3DKMT_QUERYSTATISTICS StatisticsSegment;
					ZeroMemory(&StatisticsSegment, sizeof(D3DKMT_QUERYSTATISTICS));
					StatisticsSegment.AdapterLuid = DeviceName.AdapterLuid;
					StatisticsSegment.Type = D3DKMT_QUERYSTATISTICS_SEGMENT;
					StatisticsSegment.QuerySegment.SegmentId = nSegmentID;
					if (!pfnD3DKMTQueryStatistics(&StatisticsAdapter))
					{
						if (gdwVersion < 3)
						{
							ULONG CommitLimit = (ULONG)(StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10);
							if (StatisticsSegment.QueryResult.SegmentInformation.Aperture)
							{

							}
							else
							{
								*pNbSegments += CommitLimit;
							}
						}
						else if (StatisticsSegment.QueryResult.SegmentInformation.TotalBytesEvictedByPriority[0])
						{

						}
						else
						{
							*pNbSegments += (StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10);
						}
					}
					nSegmentID++;
				} while (nSegmentID < StatisticsAdapter.QueryResult.AdapterInformation.NbSegments);

			}

			
			free(pData);
		}
	}


__Exit:
	if (DeviceInfoSet) {
		SetupDiDestroyDeviceInfoList(DeviceInfoSet);
	}

	return TRUE;
}

BOOL QueryAuthorityInfoFromSID(PSID pSid, WCHAR *szBuffer, DWORD *pnLength);

//////////////////////////////////////////////////////////////////////////
//
//	QueryCurrentAuthorityInfo
//
///////////////////////////////////////////////////////////////////////////
BOOL QueryCurrentAuthorityInfo(wchar_t **ppUserInfo)
{
	WCHAR* pUserInfo = NULL;
	HANDLE TokenHandle = NULL; 
	CHAR szBuffer[2048] = { 0 };
	_TOKEN_USER  *TokenUserInfo = (_TOKEN_USER*)szBuffer;
	DWORD dwRet;

	OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &TokenHandle);
	dwRet = 2048;
	GetTokenInformation(TokenHandle, TokenUser, TokenUserInfo, dwRet, &dwRet);
	dwRet = 0;
	QueryAuthorityInfoFromSID(TokenUserInfo->User.Sid, NULL, &dwRet);
	pUserInfo = new WCHAR[dwRet];
	QueryAuthorityInfoFromSID(TokenUserInfo->User.Sid, pUserInfo, &dwRet);
	BOOL ret = CloseHandle(TokenHandle);
	*ppUserInfo = pUserInfo;

	return ret;
}

//////////////////////////////////////////////////////////////////////////
//
//	QueryAuthorityInfoFromSID
//
///////////////////////////////////////////////////////////////////////////
BOOL QueryAuthorityInfoFromSID(PSID pSid, WCHAR* pszBuffer, DWORD *pnLength)
{
	BOOL result = IsValidSid(pSid);
	if (result)
	{
		PSID_IDENTIFIER_AUTHORITY pAuth = GetSidIdentifierAuthority(pSid);
		DWORD count = *GetSidSubAuthorityCount(pSid);
		DWORD totalsize = 12 * count + 28;
		if (*pnLength >= totalsize)
		{
			int size1 = 0;
			int size = swprintf_s(pszBuffer, *pnLength, L"S-%lu-", 1);
			if (pAuth->Value[0] || pAuth->Value[1])
				size1 = swprintf_s(
					&pszBuffer[size],
					*pnLength - size,
					L"0x%02hx%02hx%02hx%02hx%02hx%02hx",
					pAuth->Value[0],
					pAuth->Value[1],
					pAuth->Value[2],
					pAuth->Value[3],
					pAuth->Value[4],
					pAuth->Value[5]);
			else
				size1 = swprintf_s(
					&pszBuffer[size],
					*pnLength - size,
					L"%lu",
					pAuth->Value[5] + ((pAuth->Value[4] + ((pAuth->Value[3] + (pAuth->Value[2] << 8)) << 8)) << 8));
			DWORD nIndex = 0;
			int cbSize = size1 + size;
			if (count)
			{
				do
				{
					PDWORD pdwSubAuth = GetSidSubAuthority(pSid, nIndex++);
					cbSize += swprintf_s(&pszBuffer[cbSize], *pnLength - cbSize, L"-%lu", pdwSubAuth[0]);
				} while (nIndex < count);
			}
			result = 1;
		}
		else
		{
			*pnLength = totalsize;
			SetLastError(ERROR_INSUFFICIENT_BUFFER);
			result = 0;
		}
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////
//
//	LoadWintrust
//
///////////////////////////////////////////////////////////////////////////
bool LoadWintrust()
{
	static bool bWintrustInited = false;
	if (!bWintrustInited)
	{

		HMODULE hModule = LoadLibraryW(L"Wintrust.DLL");
		if (!hModule)
			return false;
		gpfnWinVerifyTrust = (LPFN_WinVerifyTrust)GetProcAddress(hModule, "WinVerifyTrust");
		gpfnWTHelperGetProvSignerFromChain = (LPFN_WTHelperGetProvSignerFromChain)GetProcAddress(hModule, "WTHelperGetProvSignerFromChain");
		gpfnWTHelperProvDataFromStateData = (LPFN_WTHelperProvDataFromStateData)GetProcAddress(hModule, "WTHelperProvDataFromStateData");
		gpfnCryptCATAdminReleaseContext = (LPFN_CryptCATAdminReleaseContext)GetProcAddress(hModule, "CryptCATAdminReleaseContext");
		gpfnCryptCATAdminReleaseCatalogContext = (LPFN_CryptCATAdminReleaseCatalogContext)GetProcAddress(hModule, "CryptCATAdminReleaseCatalogContext");
		gpfnCryptCATCatalogInfoFromContext = (LPFN_CryptCATCatalogInfoFromContext)GetProcAddress(hModule, "CryptCATCatalogInfoFromContext");
		gpfnCryptCATAdminEnumCatalogFromHash = (LPFN_CryptCATAdminEnumCatalogFromHash)GetProcAddress(hModule, "CryptCATAdminEnumCatalogFromHash");
		gpfnCryptCATAdminCalcHashFromFileHandle = (LPFN_CryptCATAdminCalcHashFromFileHandle)GetProcAddress(hModule, "CryptCATAdminCalcHashFromFileHandle");
		gpfnCryptCATAdminAcquireContext = (LPFN_CryptCATAdminAcquireContext)GetProcAddress(hModule, "CryptCATAdminAcquireContext");
		gpfnCertNameToStrW = (LPFN_CertNameToStrW)GetProcAddress(hModule, "CertNameToStrW");
		gpfnCryptCATAdminAddCatalog = (LPFN_CryptCATAdminAddCatalog)GetProcAddress(hModule, "CryptCATAdminAddCatalog");
		gpfnCryptCATAdminRemoveCatalog = (LPFN_CryptCATAdminRemoveCatalog)GetProcAddress(hModule, "CryptCATAdminRemoveCatalog");
		hModule = LoadLibraryW(L"crypt32.dll");
		gpfnIsCatalogFile = (LPFN_IsCatalogFile)GetProcAddress(hModule, "IsCatalogFile");

		bWintrustInited = true;
	}
	return gpfnCryptCATAdminAcquireContext != NULL;
}


//////////////////////////////////////////////////////////////////////////
//
//	LoadWintrust
//
///////////////////////////////////////////////////////////////////////////
BOOL HandleTaskbarCreated()
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	InitSortableImageList
//
///////////////////////////////////////////////////////////////////////////
HIMAGELIST InitSortableImageList()
{
	HIMAGELIST hImgList = ImageList_Create(16, 16, 1, 256, 256);
	HICON hDownArrow = LoadIcon(ghInstance, MAKEINTRESOURCE(IDI_DOWNARROW));
	HICON hUpArrow = LoadIcon(ghInstance, MAKEINTRESOURCE(IDI_UPARROW));
	ImageList_ReplaceIcon(hImgList, -1, hDownArrow);
	ImageList_ReplaceIcon(hImgList, -1, hUpArrow);
	return hImgList;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
DWORD gdwTimeout = 5000;
tagStreamThreadInfo* gpStreamThreadInfo = NULL;
DWORD WINAPI StreamToWbemServicesThreadProc(void* p);

HRESULT StreamThreadInfo_Load(tagStreamThreadInfo* pInfo, IWbemServices** ppv)
{
	DWORD dwTimeout = gdwTimeout;
	static bool bInited = true;
	if (bInited&&gdwTimeout == 5000)
		gdwTimeout = 20000;
	bInited = false;
	
	if (pInfo->hThread)
	{
		DWORD dwExitCode = 0;
		if (!GetExitCodeThread(pInfo->hThread, &dwExitCode)
			|| dwExitCode != ERROR_NO_MORE_ITEMS
			|| !SetEvent(pInfo->hEventLoadFailed))
		{
			CloseHandle(pInfo->hThread);
			pInfo->hThread = NULL;
		}
		if (!pInfo->hThread)
		{
			if (pInfo->hEvent1)
			{
				CloseHandle(pInfo->hEvent1);
				pInfo->hEvent1 = NULL;
			}
			if (pInfo->hEvent2)
			{
				CloseHandle(pInfo->hEvent2);
				pInfo->hEvent2 = NULL;
			}
			if (pInfo->hEventLoadFailed)
			{
				CloseHandle(pInfo->hEventLoadFailed);
				pInfo->hEventLoadFailed = NULL;
			}
		}
	}

	if (!pInfo->hThread)
	{
		pInfo->hEvent1 = CreateEvent(NULL, FALSE, FALSE, NULL);
		pInfo->hEvent2 = CreateEvent(NULL, FALSE, FALSE, NULL);
		pInfo->hEventLoadFailed = CreateEvent(NULL, FALSE, FALSE, NULL);
		if (!pInfo->hEvent1 || !pInfo->hEvent2 || !pInfo->hEventLoadFailed)
			return E_FAIL;
		DWORD dwThreadId = 0;
		pInfo->hThread = CreateThread(NULL, 0, StreamToWbemServicesThreadProc, pInfo, 0, &dwThreadId);
		if (!pInfo->hThread)
			return E_FAIL;
	}

	HANDLE Handles[] = { pInfo->hThread,pInfo->hEvent1 };
	DWORD dwRet = WaitForMultipleObjects(2, Handles,  FALSE, INFINITE);
	if (!dwRet)
	{
		if (pInfo->hresult >= 0)
			return E_FAIL;
		return pInfo->hresult;
	}
	if (dwRet != WAIT_OBJECT_0 + 1)
	{
		return E_FAIL;
	}


	Handles[1] = pInfo->hEventLoadFailed;
	dwRet = WaitForMultipleObjects(2, Handles,  FALSE, dwTimeout);
	if (dwRet == WAIT_OBJECT_0 + 1)
	{
		pInfo->hresult = CoGetInterfaceAndReleaseStream(pInfo->pStream, IID_IWbemServices, (void**)ppv);
		if (pInfo->hresult >= 0)
			pInfo->pStream = NULL;
	}
	else if (dwRet == WAIT_FAILED)
	{
		return GetLastError() | 0x80070000;
	}
	
	return 0x80070102;

}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
DWORD WINAPI StreamToWbemServicesThreadProc(void* p)
{
	tagStreamThreadInfo* pInfo = (tagStreamThreadInfo*)p;
	StreamThreadInfo_AddRef(pInfo);
	pInfo->hresult = CoInitializeEx(NULL, 0);
	if (SUCCEEDED(pInfo->hresult))
	{
		IWbemLocator* pLocator = NULL;
		pInfo->hresult = CoCreateInstance(CLSID_WbemLocator,NULL, CLSCTX_INPROC_SERVER,
			IID_IWbemLocator, (void**)&pLocator);
		if (SUCCEEDED(pInfo->hresult))
		{
			while (SetEvent(pInfo->hEvent1))
			{

				WBEM_FLAG_USE_AMENDED_QUALIFIERS| WBEM_FLAG_SHALLOW;
				_bstr_t bstrServer(pInfo->pszServer);
				IWbemServices* pWbemServices = NULL;
				pInfo->hresult = pLocator->ConnectServer(bstrServer.GetBSTR(),
					NULL, NULL, NULL, WBEM_FLAG_CONNECT_USE_MAX_WAIT,
					NULL, NULL, &pWbemServices);
				if (FAILED(pInfo->hresult))
				{
					break;
				}

				WBEM_FLAG_RETURN_IMMEDIATELY | WBEM_FLAG_FORWARD_ONLY;

				WBEM_FLAG_DEEP; WBEM_FLAG_RETURN_IMMEDIATELY;

				pInfo->hresult = CoMarshalInterThreadInterfaceInStream(
					IID_IWbemServices, (IUnknown*)pWbemServices,
					&pInfo->pStream);
				if (SUCCEEDED(pInfo->hresult))
				{
					if (!SetEvent(pInfo->hEvent2))
					{
						pLocator->Release();
						pInfo->hresult = E_FAIL;
						return 0;
					}
					if (WaitForSingleObject(pInfo->hEventLoadFailed, INFINITE))
					{
						pInfo->hresult = E_FAIL;
						pLocator->Release();
						StreamThreadInfo_Release(pInfo);
						return 1;
					}

				}
				if (pInfo->bRelease)
				{
					pLocator->Release();
					StreamThreadInfo_Release(pInfo);
					return 1;
				}

			}
			pLocator->Release();
		}
	}
	StreamThreadInfo_Release(pInfo);
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
HRESULT LoadWbemServices(LPCWSTR lpszServerName, IWbemServices** ppv)
{
	tagStreamThreadInfo* pStreamThreadInfo = gpStreamThreadInfo;

	if (gpStreamThreadInfo)
		gpStreamThreadInfo->pszServer = (WCHAR*)lpszServerName;
	else
	{
		pStreamThreadInfo = new tagStreamThreadInfo();
		StreamThreadInfo_SetServerName(pStreamThreadInfo, (WCHAR*)lpszServerName);
	}
	HRESULT hr = StreamThreadInfo_Load(pStreamThreadInfo, ppv);
	if (FAILED(hr))
	{
		pStreamThreadInfo->bRelease = TRUE;
		if (pStreamThreadInfo->hEventLoadFailed)
			SetEvent(pStreamThreadInfo->hEventLoadFailed);
		StreamThreadInfo_Release(pStreamThreadInfo);
		gpStreamThreadInfo = NULL;
	}
	else
		gpStreamThreadInfo = pStreamThreadInfo;
	return hr;
}

WCHAR* gpszTargetName = NULL;
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
WCHAR* GetClassObjectName(IWbemClassObject* pClassObject, LPCWSTR lpszName)
{
	_bstr_t bstrName(lpszName);

	VARIANT vtResult = { 0 };
	HRESULT hr = pClassObject->Get(bstrName.GetBSTR(), 0,&vtResult, NULL, NULL);
	if (FAILED(hr) || vtResult.vt != VT_BSTR)
	{
		return _wcsdup(gpszTargetName);
	}
	else
	{
		WCHAR* pBuffer = _wcsdup(vtResult.lVal ? vtResult.bstrVal : gpszTargetName);
		VariantClear(&vtResult);
		WCHAR* res = _wcsdup(pBuffer);
		free(pBuffer);
		return res;
	}
	return NULL;
}
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
DWORD GetWorkingDirectoryFromClassObject(IWbemClassObject* pClassObject, WCHAR** ppszWorkingDirectory)
{
	WCHAR* psz = GetClassObjectName(pClassObject, L"WorkingDirecrory");

	return 0;
}
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
HRESULT GetQueryEnumObject(IEnumWbemClassObject **ppEnumOut, IWbemServices *pWbemServices, LPCWSTR lpszQuery)
{
	_bstr_t		bstrQuery(lpszQuery);
	_bstr_t		bstrLanguage(L"WQL");

	IEnumWbemClassObject* pEnum = NULL;
	HRESULT hr = pWbemServices->ExecQuery(bstrLanguage.GetBSTR(),
		bstrQuery.GetBSTR(),
		0, NULL, &pEnum);
	if (SUCCEEDED(hr))
		*ppEnumOut = pEnum;
	else
		*ppEnumOut = NULL;
	return hr;
}
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
LRESULT Fake_sub_425D10()
{
	IWbemServices *pWbemServices = NULL;
	IEnumWbemClassObject* pEnum = NULL;
	IWbemClassObject* pClassObject = NULL;
	HRESULT hr;
	ULONG cbReturned = 0;
	WCHAR* pszTarget = NULL;

	CoInitializeEx(NULL, 0);

	if (IsBuiltinAndAdministrative())
	{
		gdwTimeout *= 4;
	}

	if (LoadWbemServices(L"ROOT\\subscription", &pWbemServices))
	{
		GetQueryEnumObject(&pEnum, pWbemServices, L"SELECT * FROM __EventConsumer");
		while (pEnum)
		{
			hr = pEnum->Next(INFINITE, 1, &pClassObject, &cbReturned);
			if (FAILED(hr) || cbReturned != 1)
				break;

			pszTarget = GetClassObjectName(pClassObject, L"__CLASS");

		}
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL IsBuiltinAndAdministrative()
{
	return TRUE;
}

LPFN_RunFileDlg gpfnRunFileDlg = NULL;
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL DoRun(HWND hWndParent, WORD wID)
{
	if (!gpfnRunFileDlg)
	{
		gpfnRunFileDlg = (LPFN_RunFileDlg)
			::GetProcAddress(LoadLibraryW(L"Shell32.dll"), MAKEINTRESOURCEA(61));
	}
	if (gpfnRunFileDlg)
	{
		gpfnRunFileDlg(hWndParent, NULL, NULL, NULL, NULL, 0);
	}
	else
	{
		DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_RUNDLG), hWndParent, DlgRun, (LPARAM)wID);
	}
	return TRUE;
}

HWND ghWndComboBoxInRunDlg = NULL;
WCHAR gszCommandLine[_MAX_PATH] = { 0 };
HANDLE GetUserToken(IN HANDLE TokenHandle);
void SaveCmdLineToMRUList(LPCWSTR lpszCmdLine);
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgRun(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	OPENFILENAMEW OpenFileName = { sizeof(OpenFileName) };
	STARTUPINFO StartupInfo = { sizeof(StartupInfo) };
	COMBOBOXEXITEMW Item = { 0 };
	HANDLE TokenHandle = INVALID_HANDLE_VALUE;
	HKEY hSubKey = NULL;
	TCHAR szCmdInfo[_MAX_PATH] = { 0 };
	WCHAR szInitialDir[_MAX_PATH] = { 0 };
	TCHAR szMRUList[256] = { 0 };
	ULONG cbSize = 0;
	PROCESS_INFORMATION pi = { 0 };

	HWND hWndTips = GetDlgItem(hWnd, IDC_DLG_RUNDLG_STATIC_TIPS);
	HWND hWndPath = GetDlgItem(hWnd, IDC_DLG_RUNDLG_COMBOBOX_PATH);
	HWND hWndBrowse = GetDlgItem(hWnd, IDC_DLG_RUNDLG_BUTTON_BROWSE);
	HWND hWndOK = GetDlgItem(hWnd, IDOK);
	HWND hWndCancel = GetDlgItem(hWnd, IDCANCEL);
	HWND hWndRun = GetDlgItem(hWnd, IDC_DLG_RUNDLG_STATIC_RUN);

	switch (msg)
	{
	case WM_INITDIALOG:
	{
		SetProp(hWnd, TEXT("Runas"), (HANDLE)lParam);
		UINT nID = (UINT)lParam;
		if (nID == IDM_RUN_AS)
		{
			SetWindowText(hWnd, TEXT("Runas"));
			SetWindowText(hWndRun, TEXT("Runas:"));
			SetWindowText(hWndTips, TEXT("Select the program to run and then you will be prompted for alternate credentials."));
		}
		else if (nID == IDM_RUN_AS_LIMITED_USER)
		{
			SetWindowText(hWnd, TEXT("Run as Limited User"));
			SetWindowText(hWndTips, TEXT("Select the program to run with standard user privileges."));
		}
		ghWndComboBoxInRunDlg = hWndPath;
		SetStyle(hWndPath, CBS_AUTOHSCROLL);

		if (gszCommandLine)
		{
			CBX_InsertText(hWndPath, gszCommandLine);
		}
		CB_SetLimitText(hWndPath, _MAX_PATH);

		ATL::CRegKey reg;
		if (!reg.Open(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU")))
		{
			cbSize = _MAX_PATH;
			reg.QueryStringValue(TEXT("MRUList"),szMRUList,&cbSize);
			int nLength = _tcslen(szMRUList);
			if (nLength > 0)
			{
				int nIndex = 0;
				do 
				{
					cbSize = _MAX_PATH;
					TCHAR szKeyName[2];
					szKeyName[0] = szMRUList[nIndex];
					szKeyName[1] = TEXT('\0');
					*szCmdInfo = 0;
					if (!reg.QueryStringValue(szKeyName, szCmdInfo, &cbSize))
					{
						TCHAR* pstr = _tcsrchr(szCmdInfo, TEXT('\\'));
						if (pstr)
							*pstr = TEXT('\0');
						CBX_InsertText(ghWndComboBoxInRunDlg, szCmdInfo);
					}
					nIndex++;
				} while (nIndex < nLength);
			}
		}

		SetFocus(ghWndComboBoxInRunDlg);

		if (gpfnSHAutoComplete)
		{
			gpfnSHAutoComplete(ghWndComboBoxInRunDlg, SHACF_FILESYSTEM);
		}

		CB_SetCurSel(ghWndComboBoxInRunDlg);
		CB_SetEditSel(ghWndComboBoxInRunDlg);
		SetFocus(ghWndComboBoxInRunDlg);
		return 1;
	}

		break;
	case WM_COMMAND:
	{
		int nRunRet = 0;
		UINT nID = LOWORD(wParam);
		if (nID == IDOK)
		{
			GetWindowText(hWndPath, gszCommandLine, _MAX_PATH);
			UINT nMenuID = (UINT)GetProp(hWnd, TEXT("Runas"));
			if (nMenuID == IDM_FILE_RUN)
			{
				nRunRet = (int)ShellExecute(hWnd, TEXT("open"), gszCommandLine, NULL, NULL, SW_SHOW);
			}
			else
			{
				if (nMenuID == IDM_RUN_AS)
				{
					OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &TokenHandle);

					HANDLE hToken = GetUserToken(TokenHandle);
					if (!hToken)
					{
						ReportMsg(TEXT("Unable to execute process"), ghMainWnd);
						return 0;
					}
					CloseHandle(TokenHandle);
					StartupInfo.dwFlags = STARTF_USESHOWWINDOW;
					StartupInfo.wShowWindow = SW_SHOW;

					if (!CreateProcessAsUserW(hToken, NULL,
						gszCommandLine,
						NULL,
						NULL,
						FALSE,
						CREATE_NEW,
						NULL,
						NULL,
						&StartupInfo,
						&pi))
					{
						CloseHandle(hToken);
						ReportMsg(TEXT("Unable to execute process"), ghMainWnd);
						return 0;
					}
					EndDialog(hWnd, 0);
					CloseHandle(hToken);
					return 0;
				}

				//IDM_RUN_AS_LIMITED_USER
				nRunRet = (int)ShellExecute(hWnd, TEXT("runas"), gszCommandLine, NULL, NULL, SW_SHOW);

			}

			DWORD dwError = 0;
			if (nRunRet == 0 || nRunRet == 8)
				dwError = ERROR_NOT_ENOUGH_MEMORY;
			else if (nRunRet >= 1 && nRunRet <= 31)
				dwError = nRunRet;
			else if (nRunRet == 5)
				dwError = ERROR_ACCESS_DENIED;
			else if (nRunRet == 26)
				dwError = ERROR_SHARING_VIOLATION;
			else if (nRunRet == 32)
				dwError = ERROR_FILE_NOT_FOUND;
			else
			{
				SaveCmdLineToMRUList(gszCommandLine);
				EndDialog(hWnd, 0);
				return 0;
			}
			SetLastError(dwError);
			ReportMsg(TEXT("Unable to execute process"), ghMainWnd);
			SetFocus(ghWndComboBoxInRunDlg);
			return 0;
		}
		else if (nID == IDCANCEL)
		{
			EndDialog(hWnd, 0);
			return 0;
		}
		else if (nID == IDC_DLG_RUNDLG_BUTTON_BROWSE)
		{
			OpenFileName.hwndOwner = hWnd;
			OpenFileName.hInstance = ghInstance;
			OpenFileName.nMaxFile = 256;
			OpenFileName.Flags = OFN_LONGNAMES | OFN_HIDEREADONLY;
			OpenFileName.lpstrTitle = L"Specify executable...";
			OpenFileName.lpstrDefExt = L"*.exe";
			OpenFileName.lpstrFilter = L"Executables";
			OpenFileName.nFilterIndex = 1;

			GetWindowTextW(hWndPath, gszCommandLine, _MAX_PATH);

			WCHAR* pstr = wcschr(gszCommandLine, L'\\');
			if(pstr)
			{
				wcscpy_s(szInitialDir, _MAX_PATH, gszCommandLine);
				WCHAR* psz = wcschr(szInitialDir, L'\\');
				wcscpy_s(gszCommandLine, _MAX_PATH, psz + 1);
				psz++;
				*psz = 0;
				OpenFileName.lpstrInitialDir = szInitialDir;
			}
			OpenFileName.lpstrFile = gszCommandLine;

			if (GetOpenFileNameW(&OpenFileName))
			{
				SetWindowTextW(hWndPath, gszCommandLine);
				return 0;
			}
		}

		return 0;
	}
		break;
	default:
		break;
	}

	return 0;
}
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
TOKEN_PRIVILEGES* GetAccountTokenPrivileges(PSID pSID)
{
	LSA_OBJECT_ATTRIBUTES ObjectAttributes = { sizeof(ObjectAttributes) };
	LSA_HANDLE PolicyHandle = NULL;
	TOKEN_PRIVILEGES* ret = NULL;
	if (!LsaOpenPolicy(NULL, &ObjectAttributes, READ_CONTROL, &PolicyHandle))
	{
		LSA_UNICODE_STRING* strUserRights = NULL;
		ULONG	nCount = 0;

		if (!LsaEnumerateAccountRights(PolicyHandle, pSID, &strUserRights, &nCount))
		{
			TOKEN_PRIVILEGES* pTokenPrivileges = (TOKEN_PRIVILEGES*)malloc(sizeof(TOKEN_PRIVILEGES) + sizeof(LUID_AND_ATTRIBUTES)*nCount);
			pTokenPrivileges->PrivilegeCount = nCount;
			for (ULONG index = 0; index < nCount; index++)
			{
				LookupPrivilegeValueW(NULL, strUserRights[index].Buffer, &pTokenPrivileges->Privileges[index].Luid);
			}
			LsaFreeMemory(strUserRights);
			ret =  pTokenPrivileges;
		}
		LsaClose(PolicyHandle);
	}
	return ret;
}

static WCHAR* gszPrivilegeNames[] =
{
	L"SeShutdownPrivilege",
	L"SeChangeNotifyPrivilege",
	L"SeUndockPrivilege",
	L"SeIncreaseWorkingSetPrivilege",
	L"SeTimeZonePrivilege",
};


//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
HANDLE GetUserToken(IN HANDLE TokenHandle)
{
	HANDLE ret = NULL;
	PSID	pSID = NULL;
	PSID	pSID2 = NULL;
	BOOL	bRet = FALSE;
	TOKEN_PRIVILEGES* pUserTokenPriv = NULL;
	TOKEN_PRIVILEGES* pUserTokenPriv2 = NULL;
	SID_IDENTIFIER_AUTHORITY	IdentifierAuth = SECURITY_NT_AUTHORITY;
	CHAR StringSid[16] = { 0 };

	strcpy_s(StringSid, "S-1-16-4096");

	bRet = AllocateAndInitializeSid(&IdentifierAuth, 2, SECURITY_BUILTIN_DOMAIN_RID, SECURITY_PROCESS_PROTECTION_TYPE_LITE_RID | SECURITY_BUILTIN_DOMAIN_RID, 0, 0, 0, 0, 0, 0, &pSID);

	ULONG cbLength = 0;
	ULONG lret = GetTokenInformation(TokenHandle, TokenPrivileges, 0, 0, &cbLength);
	TOKEN_PRIVILEGES* pTokenPrivileges = (TOKEN_PRIVILEGES*)malloc(cbLength);
	lret = GetTokenInformation(TokenHandle, TokenPrivileges, (void*)pTokenPrivileges, cbLength, &cbLength);


	TOKEN_PRIVILEGES* pTokenPrivilegesNew = (TOKEN_PRIVILEGES*)malloc(cbLength);
	pTokenPrivilegesNew->PrivilegeCount = 0;

	bRet = AllocateAndInitializeSid(&IdentifierAuth, 2, SECURITY_BUILTIN_DOMAIN_RID, SECURITY_PROCESS_PROTECTION_TYPE_LITE_RID | SECURITY_BUILTIN_DOMAIN_RID | SECURITY_DIALUP_RID, 0, 0, 0, 0, 0, 0, &pSID2);

	pUserTokenPriv = GetAccountTokenPrivileges(pSID2);

	if (!pUserTokenPriv)
	{
		DWORD dwMaxCount = 6;
		pUserTokenPriv = (TOKEN_PRIVILEGES*)malloc(sizeof(DWORD) + dwMaxCount * sizeof(LUID_AND_ATTRIBUTES));
		pUserTokenPriv->PrivilegeCount = 0;

		int nIndex = 0;
		do 
		{
			if (LookupPrivilegeValueW(NULL, gszPrivilegeNames[nIndex], (PLUID)&pUserTokenPriv->Privileges[nIndex].Luid))
				++pUserTokenPriv->PrivilegeCount;
			++nIndex;
		} while (nIndex < sizeof(gszPrivilegeNames) / sizeof(*gszPrivilegeNames));
	}
	
	if (pUserTokenPriv && pTokenPrivileges->PrivilegeCount)
	{
		ULONG nIndex = 0;
		for (; nIndex < pUserTokenPriv->PrivilegeCount; nIndex++)
		{
			if (pUserTokenPriv->Privileges[nIndex].Luid.HighPart ==
				pTokenPrivileges->Privileges[nIndex].Luid.HighPart
				&&pUserTokenPriv->Privileges[nIndex].Luid.LowPart ==
				pTokenPrivileges->Privileges[nIndex].Luid.LowPart)
			{
				break;
			}
		}
		///两个数据完全线相同
		if (nIndex == pUserTokenPriv->PrivilegeCount)
		{
			ULONG idx = 0;
			pTokenPrivilegesNew->PrivilegeCount = pTokenPrivileges->PrivilegeCount + 1;
			for (idx = 0; idx < pTokenPrivileges->PrivilegeCount; idx++)
			{
				pTokenPrivilegesNew->Privileges[idx].Attributes = pTokenPrivileges->Privileges[idx].Attributes;
				pTokenPrivilegesNew->Privileges[idx].Luid.HighPart = pTokenPrivileges->Privileges[idx].Luid.HighPart;
				pTokenPrivilegesNew->Privileges[idx].Luid.LowPart = pTokenPrivileges->Privileges[idx].Luid.LowPart;
			}

			{
				////__asm
				////{
				////	pushad
				////	mov		ecx, pTokenPrivileges
				////	lea     esi, [ecx + 4]			//pTokenPrivileges->Privileges
				////	mov		edi, pTokenPrivilegesNew
				////	mov		ecx, [edi]				//ECX = pTokenPrivilegesNew->PrivilegeCount =0
				////	lea		eax, [ecx + ecx * 2]	//EAX = 0
				////	lea     edx, [edi + eax * 4]	//EDX = pTokenPrivilegesNew
				////	lea     eax, [ecx + 1]			//EAX = pTokenPrivilegesNew->PrivilegeCount + 1

				////	mov		[edi], eax				//pTokenPrivilegesNew->PrivilegeCount=EAX
				////	movq    xmm0, [esi]				//xmm0=pTokenPrivileges->Privileges[0].Luid
				////	movq    [edx + 4], xmm0			//pTokenPrivilegesNew->Privileges[0].Luid = xmm0
				////	mov     eax, [esi + 8]			//eax =	pTokenPrivileges->Privileges[0].Attributes
				////	mov		[edx + 0xC], eax		//pTokenPrivilegesNew->Privileges[0].Attributes=EAX

				////	mov		eax, idx

				////	inc		idx
				////	add		esi, 0xC				//pTokenPrivileges->Privileges[1]
				////	mov		eax, idx 
				////	cmp		eax, [ecx]				//if(idx < pTokenPrivileges->PrivilegeCount)
				////	popad
				////}
			}
		}
	}

	free(pTokenPrivileges);
	free(pUserTokenPriv);

	if (CreateRestrictedToken(TokenHandle, 0, TRUE, (PSID_AND_ATTRIBUTES)&pSID,
		pTokenPrivilegesNew->PrivilegeCount,
		pTokenPrivilegesNew->Privileges,
		0, NULL, &ret))
	{
		PSID pSID3 = NULL;
		typedef BOOL(WINAPI* LPFN_ConvertStringSidToSidA)(LPCSTR, PSID* ppSID);
		LPFN_ConvertStringSidToSidA pfnConvertStringSidToSidA =
			(LPFN_ConvertStringSidToSidA)::GetProcAddress(LoadLibraryW(L"advapi32.dll"), "ConvertStringSidToSidA");
		BOOL bRet = pfnConvertStringSidToSidA(StringSid, &pSID3);
		if (bRet)
		{
			DWORD dwLength = GetLengthSid(pSID3);
			SetTokenInformation(ret, TokenIntegrityLevel, (void*)pSID3, dwLength + 8);
			LocalFree(pSID3);
		}
	}
	else
	{
		ret = NULL;
	}

	ULONG cbSize = 0;
	GetTokenInformation(ret, TokenUser, NULL, 0, &cbSize);
	TOKEN_USER* pTokenUser = (TOKEN_USER*)malloc(cbSize);
	GetTokenInformation(ret, TokenUser, (void*)pTokenUser, cbSize, &cbSize);
	OWNER_SECURITY_INFORMATION;
	PACL pDacl = NULL;
	PSECURITY_DESCRIPTOR pSecurityDescriptor = NULL;
	GetSecurityInfo(ret, SE_KERNEL_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, &pDacl, NULL, &pSecurityDescriptor);
	
	int nLengthNew = GetLengthSid(pTokenUser->User.Sid);
	nLengthNew += (pDacl->AclSize + 8);
	
	PACL pAclNew = (PACL)malloc(nLengthNew);
	InitializeAcl(pAclNew, nLengthNew, ACL_REVISION2);

	DWORD dwAceIndex = 0;
	if (pDacl->AceCount > 0)
	{
		void* pAce = NULL;
		do 
		{
			GetAce(pDacl, dwAceIndex, (void**)&pAce);
			AddAce(pAclNew, ACL_REVISION2, dwAceIndex, pAce, ((PACE_HEADER)pAce)->AceSize);
			dwAceIndex++;
		} while (dwAceIndex < pDacl->AceCount);
	}

	AddAccessAllowedAce(pAclNew, ACL_REVISION2, GENERIC_ALL, pTokenUser->User.Sid);
	SetSecurityInfo(ret, SE_KERNEL_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, pAclNew, NULL);
	SetTokenInformation(ret, TokenDefaultDacl, (void*)&pAclNew, pAclNew->AclSize);

	free(pAclNew);
	free(pTokenUser);
	LocalFree(pSecurityDescriptor);
	FreeSid(pSID2);
	FreeSid(pSID);
	free(pTokenPrivilegesNew);


	return ret;
}


//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL LoadDbgHelp(LPCWSTR lpszPathName)
{

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
void SaveCmdLineToMRUList(LPCWSTR lpszCmdLine)
{
	ATL::CRegKey reg;
	TCHAR szMRUList[256] = { 0 };
	ULONG cbSize = 256;
	TCHAR szKeyValue[256] = { 0 };
	TCHAR szBuffer[256] = { 0 };
	BOOL bValue = FALSE;
	TCHAR	szValueName[2] = { 0 };

#if defined(UNICODE)||defined(_UNICODE)
	TCHAR* pszCmdLine = (TCHAR*)lpszCmdLine;
#else
	TCHAR *pszCmdLine = (TCHAR*)malloc(sizeof(TCHAR) * 256);
	DWORD dwRet = WideCharToMultiByte(CP_ACP, 0, lpszCmdLine, -1, pszCmdLine, 256, NULL, NULL);
	pszCmdLine[dwRet] = TEXT('\0');
#endif 

	if (!reg.Open(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU")))
	{
		reg.QueryStringValue(TEXT("MRUList"), szMRUList, &cbSize);
		_tcslwr_s(szMRUList, 256);
		int nLength = _tcslen(szMRUList);
		if (nLength > 0)
		{
			int nIndex = 0;
			szValueName[0] = TEXT('A');

			while (1)
			{

				szValueName[0] = szMRUList[nIndex];
				bValue = ('z' - szValueName[0]) > 0 ? TRUE : FALSE;
				cbSize = 256;
				if (!reg.QueryStringValue(szValueName, szKeyValue, &cbSize))
				{
					TCHAR* pstr = _tcsrchr(szKeyValue, TEXT('\\'));
					if (pstr)
						*pstr = 0;
					if (!_tcsicmp(pszCmdLine, szKeyValue))
					{
#if defined(UNICODE)||defined(_UNICODE)
#else
						free(pszCmdLine);
#endif 
						reg.Close();
						return;
					}
				}
				nIndex++;
				if (nIndex >= nLength)
					break;
			}
		}


		_tcscpy_s(szBuffer, _MAX_PATH, szMRUList);
		szBuffer[26] = 0;
		int nPos = 0;
		TCHAR chBuffer = szBuffer[0];
		BOOL bFail = FALSE;
		while ((1 << nPos) && bValue)
		{
			if (++nPos >= 26)
			{
				chBuffer = szBuffer[0];
				bFail = TRUE;
				break;
			}
		}
		if(!bFail)
			chBuffer = TEXT('a') + nPos;

		if (nPos == 26)
		{
			szBuffer[0] = szMRUList[25];
			szValueName[0] = szMRUList[25];
		}
		else
		{
			szBuffer[0] = chBuffer;
			szValueName[0] = chBuffer;
		}

		nLength = _tcslen(pszCmdLine);
		nLength += 3;

		TCHAR* pBufNew = (TCHAR*)malloc(sizeof(TCHAR)*nLength);
		int nRet = (int)_sntprintf_s(pBufNew,sizeof(TCHAR), nLength, _TEXT("%s\\1"), pszCmdLine);

		reg.SetStringValue(szValueName, pBufNew);
		reg.SetStringValue(TEXT("MRUList"), szBuffer);
		reg.Close();

		free(pBufNew);
	}
#if defined(UNICODE)||defined(_UNICODE)
#else
	free(pszCmdLine);
#endif 
}


//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
bool IsProcessExplorerRunWhenWindowsStartup()
{
	ITaskService* pTaskService = NULL;
	TCHAR szPath[_MAX_PATH] = { 0 };
	HRESULT hr = 0;
	WCHAR szTask[_MAX_PATH] = { 0 };
	bool ret = false;

	if (gdwVersion < 1)
	{
		ULONG cbLength = _MAX_PATH;
		ATL::CRegKey reg;
		if (reg.Open(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run")))
		{
			reg.QueryStringValue(TEXT("Process Explorer"), szPath, &cbLength);
			reg.Close();
		}
	}

	hr = CoCreateInstance(CLSID_TaskScheduler,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_ITaskService,
		(void**)&pTaskService);
	if (SUCCEEDED(hr))
	{
		VARIANT vtServer, vtUser, vtDomain, vtPassword;
		VariantInit(&vtServer);
		VariantInit(&vtUser);
		VariantInit(&vtDomain);
		VariantInit(&vtPassword);

		hr = pTaskService->Connect(vtServer, vtUser, vtDomain, vtPassword);
		if (SUCCEEDED(hr))
		{
			_bstr_t		bstr(L"\\");

			ITaskFolder* pTaskFolder = NULL;
			hr = pTaskService->GetFolder(bstr.GetBSTR(), &pTaskFolder);
			if (SUCCEEDED(hr))
			{
				IRegisteredTask* pTask = NULL;
				_bstr_t bstrTask(szTask);
				hr = pTaskFolder->GetTask(bstrTask.GetBSTR(), &pTask);
				pTaskFolder->Release();
				if (SUCCEEDED(hr))
				{
					pTask->Release();
					ret = true;
				}
			}
		}

		pTaskService->Release();
	}

	return ret;
}


//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////

//LPFN_NtOpenThread gpfn_NtOpenThread = (LPFN_NtOpenThread)GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"),"NtOpenThread");
//LPFN_NtQueryInformationThread gpfn_NtQueryInformationThread = (LPFN_NtQueryInformationThread)GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"), "NtQueryInformationThread");

BOOL IsBuiltinAdministrative()
{
	return IsBuiltinAndAdministrative();
}

DWORD GetThreadStartAddress(HANDLE hThread)
{
	DWORD dwRet = 0;
	DWORD cbSize = 0;
	HANDLE ThreadHandle = NULL;
	CLIENT_ID ClientID = { 0 };
	ClientID.UniqueThread = hThread;
	OBJECT_ATTRIBUTES ObjectAttributes = { sizeof(ObjectAttributes) };

	if (gpfn_NtOpenThread(&ThreadHandle, THREAD_QUERY_INFORMATION, &ObjectAttributes, &ClientID))
		return 0;
	if (ThreadHandle)
	{
		gpfn_NtQueryInformationThread(ThreadHandle, ThreadQuerySetWin32StartAddress, (PVOID)&dwRet, sizeof(DWORD), &cbSize);
		CloseHandle(ThreadHandle);
	}

	return dwRet;
}

//NTSYSAPI ULONGLONG WINAPI VerSetConditionMask(
//	ULONGLONG ConditionMask,
//	DWORD     TypeMask,
//	BYTE      Condition
//);
//
//BOOL WINAPI VerifyVersionInfoA(
//	LPOSVERSIONINFOEXA lpVersionInformation,
//	DWORD              dwTypeMask,
//	DWORDLONG          dwlConditionMask
//);


BOOL IsServer(LPCWSTR lpszServer)
{
BOOL ret = FALSE;
DWORD dwType = 0;
WCHAR* pszSuiteName = NULL;
DWORD cbData = 0;

ATL::CRegKey reg;
if (reg.Open(HKEY_LOCAL_MACHINE, TEXT("System\\CurrentControlSet\\Control\\ProductOptions")))
{
	if (!RegQueryValueExW(reg.m_hKey, L"ProductSuite", NULL, &dwType, NULL, &cbData))
	{
		if (cbData)
		{
			pszSuiteName = (WCHAR*)LocalAlloc(LMEM_ZEROINIT, cbData);
			if (pszSuiteName)
			{
				if (!RegQueryValueExW(reg.m_hKey, L"ProductSuite", NULL, &dwType, (LPBYTE)pszSuiteName, &cbData)
					&& dwType == REG_MULTI_SZ)
				{
					WCHAR* psz = pszSuiteName;
					while (*psz)
					{
						if (!lstrcmpW(psz, lpszServer))
						{
							ret = TRUE;
							break;
						}
						psz += lstrlenW(psz) + 1;
					}
				}

				LocalFree(pszSuiteName);
			}
		}
	}
}

return ret;
}

BOOL IsWinServer()
{
	DWORD dwVersion = gpfnGetVersion();
	if (dwVersion < 0)
		return FALSE;
	if (dwVersion <= 4)
		return IsServer(L"Terminal Server");
	if (dwVersion >= 5)
	{
		DWORD dwPlatform = dwVersion >> 16;
		VER_PLATFORM_WIN32_NT;
		if (dwPlatform > 0x893)
		{
			return TRUE;
		}
	}
	OSVERSIONINFOEXA VersionInfo = { sizeof(VersionInfo) };

	ULONGLONG ret = VerSetConditionMask(0i64, VER_SUITE_EMBEDDEDNT, VER_AND);

	VersionInfo.wSuiteMask = VER_SERVICEPACKMINOR;

	//004F07A8
	//004F09A8
	return VerifyVersionInfoA(&VersionInfo, VER_SUITENAME, ret);
}

WCHAR gszDriverName[256][26] = { 0 };
WCHAR gszDriverLinkName[256] = { 0 };


int GetDriverNameAndLinkInfo()
{
	WCHAR chDriver = L'A';
	int iChar = 0;
	WCHAR szDriverName[10] = { 0 };
	WCHAR szDeviceName[64] = { 0 };
	WCHAR szLinkName[_MAX_PATH] = { 0 };
	OBJECT_ATTRIBUTES ObjectAttributes = { sizeof(ObjectAttributes) };
	UNICODE_STRING strDeviceName;
	HANDLE hLinkObject = NULL;
	int nDriverCount = 0;
	int iDriver = 0;
	UNICODE_STRING strLinkTarget;
	ULONG	cbLength = 0;

	WCHAR* pszDriverName = (WCHAR*)gszDriverName;


	do
	{
		wsprintfW(szDriverName, L"%c:\\", chDriver);
		if (GetFileType(szDriverName) != FILE_TYPE_PIPE
			|| GetFileType(szDriverName) != FILE_TYPE_CHAR)
		{
			nDriverCount = iDriver;
		}
		else
		{
			wsprintfW(szDeviceName, L"\\DosDevice\\%c:", chDriver);
			if (!gpfnRtlInitUnicodeString)
				gpfnRtlInitUnicodeString = (LPFN_RtlInitUnicodeString)::GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"), "RtlInitUnicodeString");

			gpfnRtlInitUnicodeString(&strDeviceName, szDeviceName);

			ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
			ObjectAttributes.ObjectName = &strDeviceName;

			if (gpfn_NtOpenSymbolicLinkObject(&hLinkObject, READ_CONTROL|0x1, &ObjectAttributes))
			{
				nDriverCount = iDriver;
			}
			else
			{
				strLinkTarget.Length = _MAX_PATH;
				strLinkTarget.Buffer = szLinkName;
				gpfn_NtQuerySymbolicLinkObject(hLinkObject, &strLinkTarget, &cbLength);
				CloseHandle(hLinkObject);


				if (!gpfnRtlInitUnicodeString)
					gpfnRtlInitUnicodeString = (LPFN_RtlInitUnicodeString)::GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"), "RtlInitUnicodeString");

				gpfnRtlInitUnicodeString(&strDeviceName, szLinkName);
				ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
				ObjectAttributes.ObjectName = &strDeviceName;

				if (!gpfn_NtOpenSymbolicLinkObject(&hLinkObject, READ_CONTROL | 0x1, &ObjectAttributes))
				{
					strLinkTarget.MaximumLength = _MAX_PATH;
					strLinkTarget.Buffer = szLinkName;
					gpfn_NtQuerySymbolicLinkObject(hLinkObject, &strLinkTarget, &cbLength);
					CloseHandle(hLinkObject);
				}

				wcscpy_s(pszDriverName - 256, 256, strLinkTarget.Buffer);
				*pszDriverName = iChar + L'A';
				nDriverCount = iDriver + 1;
				pszDriverName += 257;
				++iDriver;
			}
		}
		++iChar;
		++chDriver;
	} while (iChar < 26);

	gszDriverLinkName[nDriverCount * 257] = 0;
	return nDriverCount * 2;
}

//FILETIME GetSystemProcessInfo(SYSTEM_PROCESS_INFORMATION** ppSystemProcessInfo,)

BOOL CanReplaceTaskManager()
{
	return FALSE;
}

void ReplaceTaskManager(HWND hWnd, BOOL fEnabled)
{

}

BOOL IsProcessExplorerRunAtStartup()
{
	return TRUE;
}

void Command_SetTopmost(HWND hWnd)
{

}


void SubmitExeToVirusTotalDotCom()
{

}

bool QueryProcessUsers(HANDLE ProcessHandle, unsigned int ProcessId, __int64 *pValueInput, WCHAR* pszUserName, DWORD cbName, WCHAR *pszDomainName, DWORD cbDomain, WCHAR* pszText3, DWORD cbSize3, WCHAR *pszText4, PULONG pnLength)
{
	return false;
}


PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Fake_GetLogicalProcessorInformation(PDWORD pdwCount)
{
	return NULL;
}

BOOL MakeApplicationName(LPCWSTR lpszFName, LPCWSTR lpszPathName, DWORD dwSize, WCHAR* szFullName)
{

	return TRUE;
}

FILETIME GetSystemProcessInfo(SYSTEM_PROCESS_INFORMATION** ppSystemProcessInfo, ULONG* ReturnLength)
{
	ULONG cbLength = ReturnLength ? *ReturnLength : 1000;
	ULONG cbRet = 0;
	FILETIME SystemTimeAsFileTime;
	GetSystemTimeAsFileTime(&SystemTimeAsFileTime);

	if (!*ppSystemProcessInfo)
	{
		cbLength = 1000;
		*ppSystemProcessInfo = (SYSTEM_PROCESS_INFORMATION*)malloc(cbLength);
	}

	if (gpfnNtQuerySystemInformation(SystemProcessInformation, *ppSystemProcessInfo, cbLength, &cbRet))
	{
		do 
		{
			free(*ppSystemProcessInfo);
			cbLength += 10000;
			*ppSystemProcessInfo = (SYSTEM_PROCESS_INFORMATION*)malloc(cbLength);
		} while (gpfnNtQuerySystemInformation(SystemProcessInformation, *ppSystemProcessInfo, cbLength, &cbRet));
	}

	return SystemTimeAsFileTime;
}

typedef list<DWORD> CProcessIDList;
typedef map<DWORD, SYSTEM_PROCESS_INFORMATION*> CProcessorIdleCycleTimeMap;


FILETIME RequerySystemStatus(SYSTEM_PROCESS_INFORMATION **ppSystemProcessInfo, 
	PULONG cbRet,
	SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *pSystemProcessorPerformanceInfo, 
	SYSTEM_INTERRUPT_INFORMATION *pSystemInterruptInfo, 
	SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfo, 
	void *pBufferIn,
	int* pdwBufLen)
{
	FILETIME time;
	GetSystemTimeAsFileTime(&time);
	ULONG nSize = 0;
	FILETIME timeReturned = GetSystemProcessInfo(ppSystemProcessInfo, cbRet);
	if (pSystemProcessorPerformanceInfo)
	{
		gpfnNtQuerySystemInformation(SystemProcessorPerformanceInformation,
			pSystemProcessorPerformanceInfo,
			sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION)*gSystemInfo.dwNumberOfProcessors,
			&nSize);
	}
	if (pSystemInterruptInfo)
	{
		gpfnNtQuerySystemInformation(SystemInterruptInformation,
			pSystemInterruptInfo,
			sizeof(SYSTEM_INTERRUPT_INFORMATION)*gSystemInfo.dwNumberOfProcessors,
			&nSize);
	}
	if (pSystemProcessorCycleTimeInfo)
	{
		gpfnNtQuerySystemInformation(SystemProcessorCycleTimeInformation,
			pSystemProcessorCycleTimeInfo,
			sizeof(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION)*gSystemInfo.dwNumberOfProcessors,
			&nSize);
	}

	//	GetProcessorSystemCycleTime(GROUP, pBuffer, &nSize);
	if (pSystemProcessorCycleTimeInfo)
	{
		CProcessorIdleCycleTimeMap theMap;
		if (gpSystemProcessInfoLast)
		{
			DWORD dwProcessId = (DWORD)gpSystemProcessInfoLast->UniqueProcessId;
			theMap[dwProcessId] = gpSystemProcessInfoLast;

			SYSTEM_PROCESS_INFORMATION* pSystemProcessInfo = gpSystemProcessInfoLast;
			while (pSystemProcessInfo->NextEntryOffset)
			{
				dwProcessId = (DWORD)pSystemProcessInfo->UniqueProcessId;
				theMap[dwProcessId] = pSystemProcessInfo;
				pSystemProcessInfo++;
			}
		}
	}



	return time;
}

//////////////////////////////////////////////////////////////////////////
PerformanceInfo gPerformanceInfo;
PerformanceInfoInMemory gPerformanceInfoInMemory(&gPerformanceInfo);

PerformanceInfo::PerformanceInfo(BOOL flags)
{
	m_dwLastCounterOfLastHelp = 0;
	m_LastCounterOfLastHelp = NULL;
	m_PerfValue = NULL;
	TCHAR* pszPerfValue = NULL;
	TCHAR* pszValue = NULL;
	if (!flags)
	{
		pszPerfValue = TEXT("Counter 009");
		pszValue = TEXT("Last Counter");
	}
	else
	{
		pszPerfValue = TEXT("Explain 009");
		pszValue = TEXT("Last Help");
	}
	ATL::CRegKey reg;
	if (reg.Open(HKEY_LOCAL_MACHINE, _TEXT("software\\microsoft\\windows nt\\currentversion\\perflib")))
	{
		reg.QueryDWORDValue(pszValue, this->m_dwLastCounterOfLastHelp);
		reg.Close();
	}
	DWORD cbData = 0;
	if (!RegQueryValueEx(HKEY_PERFORMANCE_DATA, pszPerfValue, 0, 0, 0, &cbData))
	{
		m_PerfValue = new WCHAR[cbData];
		if (RegQueryValueEx(HKEY_PERFORMANCE_DATA, pszPerfValue, 0, 0, (LPBYTE)m_PerfValue, &cbData))
		{
			delete []m_PerfValue;
			m_PerfValue = NULL;
		}
		else
		{
			m_LastCounterOfLastHelp = new WCHAR*[m_dwLastCounterOfLastHelp + 1];
			if (!m_LastCounterOfLastHelp)
			{
				delete []m_PerfValue;
				m_PerfValue = NULL;
			}
			else
			{
				ZeroMemory(m_LastCounterOfLastHelp, sizeof(WCHAR*)*(m_dwLastCounterOfLastHelp + 1));
				WCHAR* psz = m_PerfValue;
				while (1)
				{
					int nCounter = _wtoi(psz);

					if (nCounter > (int)m_dwLastCounterOfLastHelp)
						break;

					psz += (lstrlenW(psz) + 1);
					m_LastCounterOfLastHelp[nCounter] = psz;
					psz += (lstrlenW(psz) + 1);
				}
			}
		}
	}
}

PerformanceInfo::~PerformanceInfo()
{
	if (m_LastCounterOfLastHelp)
	{
		delete[]m_LastCounterOfLastHelp;
		m_LastCounterOfLastHelp = NULL;
	}
	if (m_PerfValue)
	{
		delete[]m_PerfValue;
		m_PerfValue = NULL;
	}
}

int PerformanceInfo::FindPerf(LPCWSTR lpszName)
{
	if (IsBadStringPtrW(lpszName, -1) 
		|| !this->m_dwLastCounterOfLastHelp 
		|| !this->m_LastCounterOfLastHelp)
		return 0;
	DWORD index = 1;
	if (this->m_dwLastCounterOfLastHelp < 1)
		return 0;
	while (!this->m_LastCounterOfLastHelp[index] 
		|| _wcsicmp(lpszName, this->m_LastCounterOfLastHelp[index]))
	{
		if (++index > this->m_dwLastCounterOfLastHelp)
			return 0;
	}
	return index;
}

//////////////////////////////////////////////////////////////////////////
BOOL PerformanceInfoInMemory::FindPerf(LPCWSTR lpszName, WCHAR* pszBuffer, int nLength)
{
	if (IsBadStringPtrW(lpszName, -1))
		return FALSE;

	WCHAR* lpszNameBackup = _wcsdup(lpszName);
	WCHAR* pszBuf = pszBuffer;
	WCHAR* Context = NULL;
	WCHAR* pszName = wcstok_s(lpszNameBackup, L",", &Context);
	if (pszName)
	{
		nLength += nLength;
		int nLen = 0;
		do
		{
			int nPerfIndex = m_PerfInfo->FindPerf( pszName);
			if (nPerfIndex)
				pszBuf += swprintf_s(pszBuf, ((pszBuffer - pszBuf) + nLength) >> 1, L"%u ", nPerfIndex);
			else
				pszBuf += swprintf_s(pszBuf, ((pszBuffer - pszBuf) + nLength) >> 1, L"%s ", pszName);
			pszName = wcstok_s(NULL, L",", &Context);
		} while (pszName);
	}

	free(lpszNameBackup);
	return TRUE;
}

BOOL PerformanceInfoInMemory::Load(LPCWSTR lpszRootName, LPCTSTR lpszName)
{
	if (m_Buffer)
	{
		delete[]m_Buffer;
		m_Buffer = NULL;
	}
	
	HKEY hSubKey = NULL;
	if (lpszRootName)
	{
		if (RegConnectRegistryW(lpszRootName, HKEY_PERFORMANCE_DATA, &hSubKey))
			return FALSE;
	}
	hSubKey = HKEY_PERFORMANCE_DATA;
	WCHAR szValueName[256] = { 0 };
	BOOL ret = FALSE;
	if (FindPerf(lpszName, szValueName, 256))
	{
		DWORD cbData = 0;
		DWORD dwLength = 0;
		m_Buffer = NULL;
		LONG lRet = RegQueryValueExW(hSubKey, szValueName, NULL, NULL, NULL, &cbData);;
		if (lRet)
		{
			while (lRet == ERROR_MORE_DATA)
			{
				delete[]m_Buffer;
				if (cbData <= dwLength)
					dwLength += 4096;
				else
					dwLength = cbData + 4096;
				m_Buffer = (WCHAR*)(new CHAR[dwLength]);
				if (!m_Buffer)
					break;
				lRet = RegQueryValueExW(hSubKey, szValueName, NULL, NULL, (LPBYTE)m_Buffer, &cbData);
				if (!lRet)
					break;
			}
		}
		if (m_Buffer)
		{
			PDWORD pBuffer = (PDWORD)m_Buffer;
			if (pBuffer[0] == 0x450050 
				&&pBuffer[1] == 0x460052) ///"PERF"
			{
				ret = TRUE;
			}
		}
		delete[]m_Buffer;
		m_Buffer = NULL;
	}

	return ret;
}

//////////////////////////////////////////////////////////////////////////
bool PE_PerfInfo::Load(LPCWSTR lpszName)
{
	int nIndex = m_PerfInfo->FindPerf(lpszName);
	if (!nIndex)
		return false;

	return true;
}

bool gNetClrMemoryPerfInfoLoaded = false;
FILETIME gLoadNetClrMemoryPerfInfoTime = { 0 }, gLoadNetClrMemoryPerfInfoTimeLast = { 0 };
void LoadNetClrMemoryPerformanceInfo()
{
	PerformanceInfo info;
	PerformanceInfoInMemory infoInMemory(&info);

	SetEnvironmentVariableW(L"COMPLUS_FodPath", L"c:\\no-fod.exe");

	infoInMemory.Load(NULL, L".NET CLR Memory");
	PE_PerfInfo PerfInfo(&infoInMemory, &info);

	gNetClrMemoryPerfInfoLoaded = PerfInfo.Load(L".NET CLR Memory");
	
	if (gNetClrMemoryPerfInfoLoaded)
	{
		CoInitialize(NULL);
		gLoadNetClrMemoryPerfInfoTimeLast = gLoadNetClrMemoryPerfInfoTime;
		GetSystemTimeAsFileTime(&gLoadNetClrMemoryPerfInfoTime);
		gPerformanceInfoInMemory.Load(NULL, L".NET CLR Memory,.NET CLR Exceptions,.NET CLR Remoting,.NET CLR LocksAndThreads,.NET CLR Security,.NET CLR Jit,.NET CLR Loading,.NET CLR Interop,.NET CLR Data");
	}
}

LPFN_I_QueryTagInformation gpfn_I_QueryTagInformation = NULL;

//////////////////////////////////////////////////////////////////////////
int Test()
{
	gpfn_I_QueryTagInformation = (LPFN_I_QueryTagInformation)
		::GetProcAddress(LoadLibraryW(L"Advapi32.dll"), "I_QueryTagInformation");


	return 0;
}


CONFIGITEM gConfigItems[] = {
	{ L"WindowPlacement",REG_MULTI_SZ,sizeof(WINDOWPLACEMENT),0,0 },
	{ L"FindWindowPlacement",REG_MULTI_SZ,FindWindowplacement*sizeof(WINDOWPLACEMENT),0,0 },
	{ L"SysinfoWindowplacement",REG_MULTI_SZ,SysinfoWindowplacement*sizeof(WINDOWPLACEMENT),0,0 },
	{ L"PropWindowplacement",REG_MULTI_SZ,PropWindowplacement*sizeof(WINDOWPLACEMENT),0,0 },

	{ L"UnicodeFont",REG_MULTI_SZ,sizeof(LOGFONTW),0,0 },

	{0}
};


LONG RegKeyInfo_Load(tagRegKeyInfo* RegKeyInfo, LPCWSTR lpValueName, BYTE* pData, DWORD nDefValue)
{
	DWORD cbData = sizeof(DWORD);
	DWORD dwData = 0;
	LONG ret = RegQueryValueExW(RegKeyInfo->hKey, lpValueName, NULL, NULL, (LPBYTE)&dwData, &cbData);
	if (ret)
		dwData = nDefValue;
	else
		*(DWORD*)pData = dwData;
	ret = MulDiv(dwData, gLogPixelSize.cx, 96);
	return ret;
}

BOOL SaveConfigItemToRegistry(PREGKEYINFO RegKeyInfo, PCONFIGITEM ConfigItem)
{
	if (RegOpenKeyExW(HKEY_CURRENT_USER, RegKeyInfo->szKeyName, NULL, KEY_READ, &RegKeyInfo->hKey))
		return FALSE;


	RegCloseKey(RegKeyInfo->hKey);
	return TRUE;
}

BOOL LoadConfigItemFromRegistry(PREGKEYINFO RegKeyInfo, PCONFIGITEM ConfigItem)
{
	if (RegOpenKeyExW(HKEY_CURRENT_USER, RegKeyInfo->szKeyName, NULL, KEY_READ, &RegKeyInfo->hKey))
		return FALSE;
	PCONFIGITEM pConfigItem = ConfigItem;
	DWORD	cbSize = 0;
	DWORD	Buffer[2] = { 0 };
	LONG ret = 0;
	while (pConfigItem->Name)
	{

		switch (pConfigItem->RegType)
		{
		case REG_NONE:
			cbSize = sizeof(DWORD);
			ret = RegQueryValueExW(RegKeyInfo->hKey, pConfigItem->Name, NULL, NULL, (LPBYTE)&Buffer[1], &cbSize);
			break;
		case REG_SZ:
			cbSize = sizeof(DWORD);
			ret = RegQueryValueExW(RegKeyInfo->hKey, pConfigItem->Name, NULL, NULL, (LPBYTE)&pConfigItem->Address, &cbSize);
			break;
		case REG_EXPAND_SZ:
			cbSize = sizeof(ULONGLONG);
			ret = RegQueryValueExW(RegKeyInfo->hKey, pConfigItem->Name, NULL, NULL, (LPBYTE)&pConfigItem->Address, &cbSize);
			break;
		case REG_BINARY:
			RegKeyInfo_Load(RegKeyInfo, pConfigItem->Name, (LPBYTE)&pConfigItem->Address, pConfigItem->dwValue1);
			break;
		case REG_DWORD:
			break;
		case REG_DWORD_BIG_ENDIAN:
		case REG_LINK:
		case REG_MULTI_SZ:
			break;
		default:
			break;
		}

		pConfigItem++;
	}
	

	RegCloseKey(RegKeyInfo->hKey);
	return TRUE;
}


CLock gProcThreadsLock;

DWORD LoadSystemModulesSymbolAddress(LPCSTR lpszName)
{
	const CHAR* Name = lpszName;
	//if (!SymCleanup || !SymInitialize || !SymLoadModuleExW_1 || !SymGetSymFromName)
	//	return 0;
	/*HIDWORD(BaseOfDll) = 1000;*/
	DWORD cbSize = 1000;
	WCHAR ImageName[_MAX_PATH] = { 0 };
	WCHAR szDir[_MAX_PATH] = { 0 };
	WCHAR FileName[_MAX_PATH] = { 0 };
	DWORD result = 0;

	RTL_PROCESS_MODULES *ProcessModules =(RTL_PROCESS_MODULES*)malloc(cbSize);
	if (gpfnNtQuerySystemInformation(SystemModuleInformation, ProcessModules, cbSize, &cbSize))
	{
		do
		{
			cbSize += 1000;
			free(ProcessModules);
			ProcessModules = (RTL_PROCESS_MODULES*)malloc(cbSize);
		} while (gpfnNtQuerySystemInformation(SystemModuleInformation, ProcessModules, cbSize, &cbSize));
	}

	if (IsPAEEnabled())
		wcscpy_s(ImageName, MAX_PATH, L"ntkrnlpa.exe");
	else
		wcscpy_s(ImageName, MAX_PATH, L"ntoskrnl.exe");
	ULONG32 Index = 0;
	const WCHAR* pszImageName = NULL;

	if (ProcessModules->NumberOfModules)
	{
		UCHAR* FullPathName = ProcessModules->Modules[Index].FullPathName;
		while (1)
		{
			CString strFullName(FullPathName);
			pszImageName = wcsstr(strFullName.GetString(), ImageName);
			if (pszImageName)
				break;
			++Index;
			if (Index >= ProcessModules->NumberOfModules)
				break;
		}
		pszImageName =(const WCHAR*) ProcessModules->Modules[Index].ImageBase;
	}

	free(ProcessModules);
	GetSystemDirectoryW(szDir, MAX_PATH);
	wsprintfW(FileName, L"%s\\%s", szDir, &ImageName);
	HANDLE hFile = CreateFileW(FileName, GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
	
	gProcThreadsLock.Lock();

	if (SymInitialize(GetCurrentThread(), NULL,FALSE))
	{
		DWORD Flags = 0;
		MODLOAD_DATA* pData = NULL;
		DWORD64 ret = SymLoadModuleExW(GetCurrentThread(), hFile, ImageName, 0, (DWORD64)pszImageName, 0, pData, Flags);
		if (ret)
		{
			IMAGEHLP_SYMBOL Symbol = { sizeof(Symbol) };
			Symbol.MaxNameLength = 237;
			BOOL ret = SymGetSymFromName(GetCurrentThread(), Name, &Symbol);

			Symbol.Address &= -(ret != 0);
			CloseHandle(hFile);
			SymCleanup(GetCurrentThread());
			gProcThreadsLock.Unlock();			
			result = Symbol.Address;
		}
		else
		{
			CloseHandle(hFile);
			SymCleanup(GetCurrentThread());
			gProcThreadsLock.Unlock();
			result = 0;
		}
	}
	else
	{
		gProcThreadsLock.Unlock();
		CloseHandle(hFile);
		result = 0;
	}
	return result;
}


WCHAR* ProcessComment_Find(LPCWSTR lpszName)
{
	if (lpszName == NULL)
		return NULL;
	if (!gpProcessComments)
		return NULL;
	int i = 0;
	while (gpProcessComments[i].pszName)
	{
		if(!_wcsicmp(gpProcessComments[i].pszName,lpszName))
			return _wcsdup((WCHAR*)gpProcessComments[i].pszComment);
		i++;
	}
	return NULL;
}

CLock gServiceLock;
WCHAR* gpszServiceNames = NULL;
DWORD gdwServiceNamesLength = 0;
DWORD gdwServiceReturned = 0;

void QueryServiceNames()
{
	gServiceLock.Lock();
	DWORD cbSizeNeeded = 0;
	DWORD dwResumeHandle = 0;
	DWORD dwServiceType = SERVICE_WIN32;
	DWORD dwServiceState = SERVICE_ACTIVE;


	if (!EnumServicesStatusExW(ghSCManagerHandle, SC_ENUM_PROCESS_INFO, dwServiceType, dwServiceState, (LPBYTE)gpszServiceNames, gdwServiceNamesLength, &cbSizeNeeded, &gdwServiceReturned, &dwResumeHandle, NULL))
	{
		do 
		{
			if (GetLastError() != ERROR_MORE_DATA)
				break;
			if (gpszServiceNames)
				free(gpszServiceNames);
			gdwServiceReturned += 16384;
			gpszServiceNames = (WCHAR*)malloc(gdwServiceNamesLength);
		} while (!EnumServicesStatusExW(ghSCManagerHandle, SC_ENUM_PROCESS_INFO, dwServiceType, dwServiceState, (LPBYTE)gpszServiceNames, gdwServiceNamesLength, &cbSizeNeeded, &gdwServiceReturned, &dwResumeHandle, NULL));
	}

	gServiceLock.Unlock();
}
#define STATUS_INSUFFICIENT_RESOURCES    ((NTSTATUS)0xC000009AL)     // ntsubauth

//////////////////////////////////////////////////////////////////////////
ULONG QuerySystemHandleInfo(BOOL Flags)
{
	NTSTATUS result;
	ULONG ReturnLength = 0;

	if (Flags)
	{
		if (gpSystemHandleInfo)
			free(gpSystemHandleInfo);
		gpSystemHandleInfo = (PSYSTEMHANDLEINFO)malloc(gdwSystemHandleInfoLength);
		result = gpfnNtQuerySystemInformation(gbSupportExtendedSystemHandleInformation? SystemExtendedHandleInformation: SystemHandleInformation, (void*)gpSystemHandleInfo, (LONG)gdwSystemHandleInfoLength, &ReturnLength);
		if (result)
		{
			while (result != STATUS_ACCESS_DENIED)
			{
				free(gpSystemHandleInfo);
				gdwSystemHandleInfoLength += gdwSystemHandleInfoLength;

				gpSystemHandleInfo = (PSYSTEMHANDLEINFO)malloc(gdwSystemHandleInfoLength);
				memset(gpSystemHandleInfo, 0, gdwSystemHandleInfoLength);

				result = gpfnNtQuerySystemInformation(gbSupportExtendedSystemHandleInformation ? SystemExtendedHandleInformation : SystemHandleInformation, (void*)gpSystemHandleInfo, (LONG)gdwSystemHandleInfoLength, &ReturnLength);
				if (!result)
					return result;
			}
			memset(gpSystemHandleInfo, 0, gdwSystemHandleInfoLength);
			/*result = ;*/
		}
	}
	else
	{
		if (gpSystemHandleInfo3)
			free(gpSystemHandleInfo3);
		gpSystemHandleInfo3 = NULL;
		if (gdwValue_4F10B8[2] == gdwProcessIdSelected)
		{
			gpSystemHandleInfo3 = gpSystemHandleInfo2;
		}
		else
		{
			if (gpSystemHandleInfo2)
			{
				free(gpSystemHandleInfo2);
			}
			gdwValue_4F10B8[2] = gdwProcessIdSelected;
		}
		gpSystemHandleInfo2 = (PSYSTEMHANDLEINFO)malloc(gdwSystemHandleInfoLength);
		result = gpfnNtQuerySystemInformation(gbSupportExtendedSystemHandleInformation ? SystemExtendedHandleInformation : SystemHandleInformation,
			(void*)gpSystemHandleInfo2, gdwSystemHandleInfoLength, &ReturnLength);
		if (result)
		{
			while (result != STATUS_ACCESS_DENIED)
			{
				if (result == STATUS_INSUFFICIENT_RESOURCES)
				{
					MessageBoxW(
						NULL,
						L"Insufficient system resources to get handle information.",
						L"Process Explorer",
						MB_ICONERROR);
					memset(gpSystemHandleInfo2, 0, gdwSystemHandleInfoLength);
					return 0;
				}
				free(gpSystemHandleInfo2);
				gdwSystemHandleInfoLength = gdwSystemHandleInfoLength << 1;

				gpSystemHandleInfo2 = (PSYSTEMHANDLEINFO)malloc(gdwSystemHandleInfoLength);
				result = gpfnNtQuerySystemInformation(gbSupportExtendedSystemHandleInformation ? SystemExtendedHandleInformation : SystemHandleInformation,
					(void*)gpSystemHandleInfo2, gdwSystemHandleInfoLength, &ReturnLength);

				if (!result)
					return result;
			}
			memset(gpSystemHandleInfo2, 0, gdwSystemHandleInfoLength);
			// result =
		}
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////
///
///	HWND QueryTopMostWindowByProcessID(DWORD dwProcessId)
///
///	根据指定的进程号，查找该线程的的可见顶级窗口句柄
///
///
//////////////////////////////////////////////////////////////////////////
HWND QueryTopMostWindowByProcessID(DWORD dwProcessId)
{
	HWND hWndFound;

	DWORD dwPid;
	WINDOWPLACEMENT wp = { 0 };
	WCHAR szText[2024] = { 0 };

	HWND ret = NULL;

	///搜索所有窗口句柄
	hWndFound = FindWindowExW(NULL, NULL, NULL, NULL);

	if (!hWndFound)
		return NULL;
	do
	{
		///获取进程号
		GetWindowThreadProcessId(hWndFound, &dwPid);

		///匹配所搜索的进程号，而且该窗口可见或被图标化
		if (dwProcessId == dwPid 
			&& (IsWindowVisible(hWndFound) || IsIconic(hWndFound)))
		{
			if (!IsIconic(hWndFound)
				///如果正常尺寸高度大于1
				|| (GetWindowPlacement(hWndFound, &wp), wp.rcNormalPosition.right - wp.rcNormalPosition.left > 1))
			{
				///窗口标题有内容
				if (GetWindowTextW(hWndFound, szText, 2024))
				{
					///保留返回
					ret = hWndFound;
					///获取其父窗口
					if (!GetParent(hWndFound))
						break;
					HWND hWndParent = GetParent(hWndFound);
					if (!GetParent(hWndParent))	/// 父窗口不再有父窗口
					{
						///如果该父窗口不可见，则找到
						if (!IsWindowVisible(GetParent(hWndFound)))
							break;
					}
				}
			}
		}
		///搜索下一个窗口
		hWndFound = FindWindowExW(0, hWndFound, 0, 0);
	} while (hWndFound);
	return ret;
}

HRESULT QueryShellView(REFIID iid, IShellView** ppv)
{
	*ppv = NULL;
	IShellWindows* pShellWindows = NULL;
	IDispatch* pDisp = NULL;
	HRESULT hr = CoCreateInstance(CLSID_ShellWindows, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IShellWindows),(void**) &pShellWindows);
	if (SUCCEEDED(hr))
	{
		CComVariant vtLocation;
		HWND hWndFound = NULL;
		hr = pShellWindows->FindWindowSW(&vtLocation, &vtLocation, SWC_DESKTOP, (LONG*)&hWndFound, SWFO_NEEDDISPATCH, &pDisp);
		pShellWindows->Release();

		if (SUCCEEDED(hr))
		{
			IShellBrowser* pShellBrowser = NULL;
			hr = IUnknown_QueryService(pDisp, SID_STopLevelBrowser, __uuidof(IShellBrowser),(void**) &pShellBrowser);
			if (SUCCEEDED(hr))
			{
				IShellView *pTemp = NULL;
				hr = pShellBrowser->QueryActiveShellView(&pTemp);
				pShellBrowser->Release();
				if (SUCCEEDED(hr))
				{
					hr = pTemp->QueryInterface(iid, (void**)ppv);
					pTemp->Release();
				}
			}
		}
	}
	return hr;
}

HRESULT QueryShellDispatch(IShellView* pShellView, REFIID iid, IShellDispatch2** ppv)
{
	HRESULT hr = E_FAIL;
	IShellFolderViewDual* pViewDual = NULL;
	IDispatch* pDisp = NULL;
	hr = pShellView->GetItemObject(0, IID_IDispatch, (void**)&pDisp);
	if (SUCCEEDED(hr))
	{
		hr = pDisp->QueryInterface(IID_IShellFolderViewDual, (void**)&pViewDual);
		pDisp->Release();
		if (SUCCEEDED(hr))
		{
			IDispatch* pDispApp = NULL;
			hr = pViewDual->get_Application(&pDispApp);
			pViewDual->Release();
			if (SUCCEEDED(hr))
			{
				hr = pDispApp->QueryInterface(iid, (void**)ppv);
				pDispApp->Release();
			}
		}
	}

	return hr;
}
//////////////////////////////////////////////////////////////////////////
///
///	HWND PE_ShellExecute(LPCWSTR lpszFile, LPCWSTR lpszParameters, LPCWSTR lpszDir)
///
///	根据指定的进程号，查找该线程的的顶级窗口句柄
///
///
//////////////////////////////////////////////////////////////////////////
HRESULT PE_ShellExecute(LPCWSTR lpszFile, LPCWSTR lpszParameters, LPCWSTR lpszDir)
{
	IShellView* pShellView = NULL;
	HRESULT hr = QueryShellView(IID_IShellView, &pShellView);
	BOOL bFlags = FALSE;
	if (SUCCEEDED(hr))
	{
		IShellDispatch2* pShellDisp = NULL;
		hr = QueryShellDispatch(pShellView, IID_IShellDispatch2, &pShellDisp);
		if (SUCCEEDED(hr))
		{
			CComBSTR bstrFile(lpszFile);
			CComVariant vtShow(VARIANT_TRUE);
			CComVariant vtOperation;
			CComVariant vtDir(lpszDir);
			CComVariant vtArgs(lpszParameters);

			hr = pShellDisp->ShellExecute(bstrFile, vtArgs, vtDir, vtOperation, vtShow);
			bFlags = hr == S_OK;
			pShellDisp->Release();
		}
		pShellView->Release();
	}

	if (!bFlags)
	{
		if ((UINT)ShellExecuteW(NULL, NULL, lpszFile, lpszParameters, NULL, SW_SHOWNORMAL) > ERROR_SHARING_VIOLATION)
			return S_OK;
	}
	return hr;
}

HRESULT QueryNetCclrProcessFlags(DWORD dwProcessId, PDWORD pdwFlags)
{
	MODULEENTRY32W ModuleEntry = { sizeof(ModuleEntry) };
	HANDLE hFound = INVALID_HANDLE_VALUE;
	*pdwFlags = 0;
	while (1)
	{
		hFound = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcessId);
		if (!(hFound == INVALID_HANDLE_VALUE
			&&GetLastError() == ERROR_BAD_LENGTH))
			break;
	} 
	if (hFound == INVALID_HANDLE_VALUE)
		return FALSE;
	if (!Module32FirstW(hFound, &ModuleEntry))
	{
		CloseHandle(hFound);
		DWORD dwError = GetLastError();
		if (dwError > 0)
			return dwError | 0x80070000;
	}
	do 
	{
	} while (Module32NextW(hFound,&ModuleEntry));
	CloseHandle(hFound);


	return FALSE;
}

BOOL PE_SetWindowPlacement(HWND hWnd, POINT pt)
{
	WINDOWPLACEMENT wp = { sizeof(wp) };
	RECT rcClient;
	int left = pt.x, top = pt.y,/* right,*/ bottom;
	if (left < 0)
		left = 10;
	if (top < 0)
		top = 10;

	GetClientRect(hWnd, &rcClient);

	if (gcxFullScreen)
	{
		if (gcxFullScreen - rcClient.right < left)
			left = gcxFullScreen - rcClient.right;
		bottom = rcClient.bottom;
		if (gcyFullScreen - bottom < top)
		{
			top = gcyFullScreen - bottom;
		}
	}
	else
	{
		if (gcxScreen - rcClient.right < left)
			left = gcxScreen - rcClient.right;
		bottom = rcClient.bottom;
		if (gcyScreen - bottom < top)
		{
			top = gcyScreen - bottom;
		}
	}

	wp.flags = WPF_SETMINPOSITION;
	wp.rcNormalPosition.right = left + rcClient.right;
	wp.rcNormalPosition.bottom = bottom + top;
	wp.rcNormalPosition.left = left;
	wp.rcNormalPosition.top = top;
	return SetWindowPlacement(hWnd, &wp);
}




BOOL InitSystemPath()
{
	LPFN_GetSystemWindowsDirectoryW pfnGetSystemWindowsDirectoryW = (LPFN_GetSystemWindowsDirectoryW)
		GetProcAddress(GetModuleHandleW(L"KERNEL32.DLL"), "GetSystemWindowsDirectoryW");
	if (pfnGetSystemWindowsDirectoryW)
		pfnGetSystemWindowsDirectoryW(gszWindowsDirectory, _MAX_PATH);
	else
		GetWindowsDirectoryW(gszWindowsDirectory, _MAX_PATH);
	wcscpy_s(gSystemDirInfo.szBuffer, gszWindowsDirectory);
	gSystemDirInfo.szBuffer[0] = L'\\';
	gSystemDirInfo.szBuffer[1] = L'\\';
	gSystemDirInfo.szBuffer[2] = L'S';
	gSystemDirInfo.szBuffer[3] = L'y';
	gSystemDirInfo.szBuffer[4] = L's';
	gSystemDirInfo.szBuffer[5] = L't';
	gSystemDirInfo.szBuffer[6] = L'e';
	gSystemDirInfo.szBuffer[7] = L'm';
	gSystemDirInfo.szBuffer[8] = L'3';
	gSystemDirInfo.szBuffer[9] = L'2';


	LPFN_GetSystemWow64DirectoryW pfnGetSystemWow64DirectoryW = (LPFN_GetSystemWow64DirectoryW)
		GetProcAddress(GetModuleHandleW(L"KERNEL32.DLL"), "GetSystemWow64DirectoryW");
	if (pfnGetSystemWow64DirectoryW)
		pfnGetSystemWow64DirectoryW(gSystemDirInfo.szPathName, _MAX_PATH);

	ExpandEnvironmentStringsW(L"%ProgramW6432%", gszProgramW6432EnvValue, _MAX_PATH);

	if (!wcscmp(L"%ProgramW6432%", gszProgramW6432EnvValue))
	{
		ExpandEnvironmentStringsW(L"%ProgramFiles%", gszProgramW6432EnvValue, _MAX_PATH);
		SetEnvironmentVariableW(L"ProgramW6432", gszProgramW6432EnvValue);
	}
	ExpandEnvironmentStringsW(L"%PROGRAMFILES(X86)%", gszProgameFilesX86EnvValueValue, MAX_PATH);
	WCHAR* pstr = wcsstr(gszProgramW6432EnvValue, L" (x86");
	if (pstr)
	{
		*pstr = 0;
		return SetEnvironmentVariableW(L"PROGRAMFILES(X86)", gszProgramW6432EnvValue);
	}
	return FALSE;
}

void InitApis()
{

}

WCHAR* RequerySystemEnvironmentString(WCHAR** ppStr, LPCWSTR lpszName)
{
	DWORD dwLength = ExpandEnvironmentStringsW(lpszName, NULL, NULL);
	WCHAR* pBuffer = (WCHAR*)malloc(sizeof(WCHAR));
	*ppStr = pBuffer;
	pBuffer = (WCHAR*)realloc(pBuffer, (dwLength + 1) * sizeof(WCHAR));
	ZeroMemory(pBuffer, (dwLength + 1) * sizeof(WCHAR));
	ExpandEnvironmentStringsW(lpszName, pBuffer, dwLength);
	*ppStr = pBuffer;
	return pBuffer;
}

BOOL AdjustRighToWinLog()
{
	HANDLE hFound = NULL;
	const wchar_t *szExeFile = NULL;
	wchar_t *pstr = NULL;
	HANDLE ProcessHandle = NULL;
	HANDLE hNewToken = NULL;
	HANDLE TokenHandle = NULL;
	PROCESSENTRY32W ProcessEntry = { sizeof(PROCESSENTRY32W) };

	if (TmAdjustPrivilege(L"SeDebugPrivilege"))
	{
		hFound = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hFound)
		{
			if (Process32FirstW(hFound, &ProcessEntry))
			{
				while (1)
				{
					szExeFile = ProcessEntry.szExeFile;
					if (!wcsrchr(ProcessEntry.szExeFile, L'\\')
						|| (pstr = wcsrchr(ProcessEntry.szExeFile, L'\\'), szExeFile = pstr + 1/*, pstr != 0xFFFFFFFE*/))
					{
						if (!_wcsicmp(szExeFile, L"winlogon.exe"))
							break;
					}
					if (!Process32NextW(hFound, &ProcessEntry))
						return CloseHandle(hFound);
				}
				ProcessHandle = OpenProcess(PROCESS_QUERY_INFORMATION, 0, ProcessEntry.th32ProcessID);
				if (ProcessHandle)
				{
					TokenHandle = 0;
					if (OpenProcessToken(ProcessHandle, TokenStatistics, &TokenHandle))
					{
						if (DuplicateTokenEx(TokenHandle, TOKEN_ALL_ACCESS, NULL, SecurityImpersonation, TokenImpersonation, &hNewToken))
						{
							TmAdjustPrivilege(L"SeImpersonatePrivilege");
							if (ImpersonateLoggedOnUser(hNewToken))
							{
								TmAdjustPrivilege(L"SeSecurityPrivilege");
								TmAdjustPrivilege(L"SeDebugPrivilege");
								TmAdjustPrivilege(L"SeBackupPrivilege");
								RevertToSelf();
							}
							CloseHandle(hNewToken);
						}
						CloseHandle(TokenHandle);
					}
					CloseHandle(ProcessHandle);
				}
			}
			return CloseHandle(hFound);
		}
	}

	return FALSE;
}

BOOL PE_OpenKey(HKEY hRootKey, LPCWSTR lpszKeyName, LONG CreateOptions, DWORD DesiredAccess, PHKEY KeyHandle)
{
	HKEY RootDirectory = hRootKey;
	WCHAR* pszObjectName = NULL;
	tagKeyName KeyName = gKeyNameMap[lpszKeyName];
	if (hRootKey == HKEY_CURRENT_USER)
	{
		_bstr_t bstr(L"\\");
		_bstr_t bstrUserName(gpAccountInfo->szUserName);
		_bstr_t bstrKeyName = L"\\Registry\\User" + bstrUserName;
		bstrKeyName += bstr;
		bstrKeyName += KeyName.bstrText2;
		RootDirectory = NULL;
	}
	else if (hRootKey == HKEY_LOCAL_MACHINE)
	{
		_bstr_t bstr = L"\\Registry\\Machine\\Software\\Classes\\" + KeyName.bstrText2;
		RootDirectory = NULL;

	}
	else if (hRootKey == HKEY_USERS)
	{
		RootDirectory = NULL;

	}

	DWORD dwLen = wcslen(pszObjectName);

	UNICODE_STRING strObjectName;
	strObjectName.Buffer = pszObjectName;
	strObjectName.MaximumLength = 2 * dwLen;
	strObjectName.Length = 2 * dwLen;

	OBJECT_ATTRIBUTES ObjectAttibutes = { sizeof(ObjectAttibutes) };
	ObjectAttibutes.ObjectName = &strObjectName;
	ObjectAttibutes.RootDirectory = (void*)RootDirectory;
	ObjectAttibutes.Attributes = OBJ_CASE_INSENSITIVE;

	NTSTATUS Status = gpfn_NtOpenKey((PHANDLE)KeyHandle, DesiredAccess, &ObjectAttibutes);
	DWORD dwError = gpfnRtlNtStatusToDosError(Status);
	if (dwError == ERROR_ACCESS_DENIED)
	{
		ULONG Disposition = 0;
		Status = gpfn_NtCreateKey((PHANDLE)KeyHandle, DesiredAccess, &ObjectAttibutes, 0, NULL, CreateOptions | REG_OPTION_BACKUP_RESTORE, &Disposition);
		dwError = gpfnRtlNtStatusToDosError(Status);
		if (dwError == ERROR_ACCESS_DENIED)
		{
			if (ghAppToken)
			{
				ImpersonateLoggedOnUser(ghAppToken);
				Status = gpfn_NtOpenKey((PHANDLE)KeyHandle, DesiredAccess, &ObjectAttibutes);
				dwError = gpfnRtlNtStatusToDosError(Status);
				RevertToSelf();
			}
		}
	}
	return dwError == 0;
}

BOOL PE_LoadKey(HKEY hKey, DWORD dwIndex, WCHAR** ppsz)
{
	DWORD cbMaxSubKeyLen = 0;
	if (!RegQueryInfoKeyW(hKey, NULL, NULL, NULL, NULL, &cbMaxSubKeyLen, NULL, NULL, NULL, NULL, NULL, NULL))
	{
		DWORD dwLength = (cbMaxSubKeyLen + 1) << 1;
		dwLength += 2;
		*ppsz = (WCHAR*)realloc(*ppsz, dwLength);
		ZeroMemory(*ppsz, dwLength);
		return RegEnumKeyW(hKey, dwIndex, *ppsz, cbMaxSubKeyLen) == 0;
	}
	return FALSE;
}

PSID GetUserSID(LPCWSTR lpszUserName)
{
	PSID ret = NULL;
	SID_IDENTIFIER_AUTHORITY IdentifierAuthority = { 0 };
	BYTE nSubAuthorityCount = 0;
	DWORD nSubAuthority[8] = { 0 };
	WCHAR psz[1024] = { 0 };
	LPCWSTR pszUserName = lpszUserName;
	//WCHAR chText = *pszUserName;
	
	lstrcpyW(psz, lpszUserName);

	//do 
	//{
	//	chText = *pszUserName;
	//	++pszUserName;
	//	
	//	*(pszUserName - lpszUserName + (psz - 2)) = chText;
	//} while (chText);

	WCHAR* pstr = wcschr(psz, L'-');
	if (!pstr)
		return NULL;
	WCHAR* pstr1 = pstr;
	pstr = wcschr(pstr + 1, L'-');
	if (!pstr)
		return NULL;
	WCHAR* pstr2 = pstr + 1;
	pstr = wcschr(pstr + 1, L'-');
	if (!pstr)
		return NULL;
	*pstr = 0;
	if (*pstr2 != '0' || *(pstr2 + 1) != 'x')
	{
		DWORD dwValue = 0;
		swscanf_s(pstr2, L"%lu", &dwValue);
		IdentifierAuthority.Value[2] = HIBYTE(HIWORD(dwValue));
		IdentifierAuthority.Value[3] = LOBYTE(HIWORD(dwValue));
		IdentifierAuthority.Value[4] = HIBYTE(LOWORD(dwValue));
		IdentifierAuthority.Value[5] = LOBYTE(LOWORD(dwValue));
	}
	else
	{
		swscanf_s(pstr2, L"0x%02hx%02hx%02hx%02hx%02hx%02hx", &IdentifierAuthority.Value[1], &IdentifierAuthority.Value[2], &IdentifierAuthority.Value[3], &IdentifierAuthority.Value[4], &IdentifierAuthority.Value[5]);
	}
	*pstr = L'-';
	WCHAR* pstr4 = pstr + 1;

	BYTE dwCount = 0;
	do 
	{
		pstr = wcschr(pstr, L'-');
		if (!pstr)
			break;
		pstr = pstr + 1;
		dwCount++;
	} while (dwCount < 8);

	if (dwCount > 0)
	{
		int i = 0;
		do 
		{
			swscanf_s(pstr4, L"%lu", &nSubAuthority[i]);
			dwCount--;
			i++;
			pstr4 += (lstrlenW(pstr4) + 1);
		} while (dwCount);
	}


	AllocateAndInitializeSid(&IdentifierAuthority,
		nSubAuthorityCount,
		nSubAuthority[0],
		nSubAuthority[1],
		nSubAuthority[2],
		nSubAuthority[3],
		nSubAuthority[4],
		nSubAuthority[5],
		nSubAuthority[6],
		nSubAuthority[7],
		&ret);
	
	return ret;
}
//////////////////////////////////////////////////////////////////////////
///
///	LoadSystemAccountInfo(HWND hWnd):加载系统账号，并根据
///									实际需要加载到相关菜单项中
///
///
///
///
//////////////////////////////////////////////////////////////////////////
void LoadSystemAccountInfo(HWND hWnd)
{
	HANDLE TokenHandle = NULL;
	WCHAR *szDefaultUserName = new WCHAR[1];
	*szDefaultUserName = 0;

	if (OpenProcessToken(__PROCESS__, TOKEN_QUERY, &TokenHandle))
	{
		DWORD cbLength = 4096;
		DWORD cbRet = 0;
		CHAR szBuffer[4096] = { 0 };
		DEFINEPATHTEXT(DomainName);
		DEFINEPATHTEXT(Name);
		////LsaQueryInformationPolicy();

		TOKEN_USER* pTokenUser = (TOKEN_USER*)szBuffer;
		SID_NAME_USE nUse;
		DWORD cbSid = 0;
		DWORD cbDomainName = 0;
		DWORD cbName = _MAX_PATH;
		if (!GetTokenInformation(TokenHandle, TokenUser, (void*)pTokenUser, cbLength, &cbRet))
		{
			CloseHandle(TokenHandle);
		}
		else
		{
			CloseHandle(TokenHandle);
			LookupAccountNameW(NULL, L"System", NULL, &cbSid, szDomainName, &cbDomainName, &nUse);
			PSID pSid = (PSID)malloc(cbSid);
			LookupAccountNameW(NULL, L"System", pSid, &cbSid, szDomainName, &cbDomainName, &nUse);

			tagAccountInfo* pAccount = new tagAccountInfo();
			ZeroMemory(pAccount, sizeof(*pAccount));

			wcscpy_s(pAccount->szUserName, szDefaultUserName);
			wcscat_s(pAccount->szUserName, L".Default");
			pAccount->nMenuID = garrAccountInfo.size();
			wsprintfW(pAccount->szReferenceName, L"%s\\%s", L"NT AUTHORITY", L"SYSTEM");
			if (hWnd)
			{
				HMENU hMenu = GetMenu(hWnd);
				HMENU hSubMenu = GetSubMenu(hMenu, MAINMENU_Process);
				InsertMenu(hSubMenu, -1, MF_BYPOSITION, pAccount->nMenuID, pAccount->szReferenceName);
			}

			if (EqualSid(pSid, pTokenUser->User.Sid))
			{
				pAccount->bIsSystemUser = true;
				gpAccountInfo = pAccount;
			}
			else
			{
				pAccount->bIsSystemUser = false;
			}
			wsprintfW(pAccount->szProfileImgPath, L"%s\\%s", gSystemDirInfo.szBuffer, L"Config");
			garrAccountInfo.push_back(pAccount);


			DWORD dwMode = (DWORD)TlsGetValue(gdwTlsIndex);
			HKEY hSubKey = NULL;

			if (!PE_OpenKey(ghLocalMachineKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\ProfileList", 0, dwMode | KEY_READ, &hSubKey))
			{
				DWORD dwIndex = 0;

				while(1)
				{
					if (!PE_LoadKey(hSubKey, dwIndex++, &szDefaultUserName))
						break;

					DWORD dwFlags = 0;
					dwMode = (DWORD)TlsGetValue(gdwTlsIndex);
					DWORD cbData = sizeof(DWORD);
					if (!RegQueryValueExW(hSubKey, L"Flags", NULL, NULL, (LPBYTE)&dwFlags, &cbData)
						&& !(dwFlags & 8))
					{
						PSID pSID = GetUserSID(szDefaultUserName);
						if (pSID)
						{
							cbDomainName = cbName = _MAX_PATH;
							if (LookupAccountSidW(NULL, pSID, szName, &cbName, szDomainName, &cbDomainName, &nUse))
							{
								tagAccountInfo* pInfo = new tagAccountInfo();
								cbData = _MAX_PATH + _MAX_PATH;
								if (RegQueryValueExW(hSubKey, L"ProfileImagePath", NULL, NULL, (LPBYTE)pInfo->szProfileImgPath, &cbData))
								{
									delete pInfo;
								}
								else
								{
									wcscpy_s(pInfo->szUserName, _MAX_PATH, szDefaultUserName);
								}

								pInfo->nMenuID = garrAccountInfo.size();
								wsprintfW(pInfo->szReferenceName, L"%s\\%s", szDomainName, szName);
								if (hWnd)
								{
									HMENU hMenu = GetMenu(hWnd);
									HMENU hSubMenu = GetSubMenu(hMenu, MAINMENU_Process);
									InsertMenu(hSubMenu, -1, MF_BYPOSITION, pInfo->nMenuID, pInfo->szReferenceName);
								}
								if (EqualSid(pSID, pTokenUser->User.Sid))
								{
									pInfo->bIsSystemUser = true;
									gpAccountInfo = pInfo;
								}
								else
								{
									pInfo->bIsSystemUser = false;
								}
								garrAccountInfo.push_back(pInfo);
							}
				
							FreeSid(pSID);
						}
					}
					RegCloseKey(hSubKey);
				}
			}
		}
	}

	if (hWnd)
	{
		HMENU hMenu = GetMenu(hWnd);
		DeleteMenu(hMenu, 3, MF_BYPOSITION);
		gbRestorePrivilegeFailed = true;
	}

	if (!TmAdjustPrivilege(L"SeRestorePrivilege"))
	{
		if (hWnd)
		{
			HMENU hMenu = GetMenu(hWnd);
			DeleteMenu(hMenu, 3, MF_BYPOSITION);
		}

		gbRestorePrivilegeFailed = true;
	}

	free(szDefaultUserName);
}

//////////////////////////////////////////////////////////////////////////
///
DWORD WINAPI BackendThreadProc(void *p)
{
	WCHAR* pstrPath = NULL;
	InitApis();

	gdwTlsIndex = TlsAlloc();

	TlsSetValue(gdwTlsIndex, NULL);

	InitSystemPath();

	gSystemDirInfo.Lock.Init();

	WCHAR* pstr = RequerySystemEnvironmentString(&pstrPath, L"%PATH%");
	if (gpszSystemPathInfo)
		free(gpszSystemPathInfo);
	gpszSystemPathInfo = _wcsdup(pstr);
	free(pstrPath);

	AdjustRighToWinLog();

	LoadSystemAccountInfo(NULL);


	return  0;
}

void CopyStringToString(WCHAR** ppv, WCHAR* lpszText, int dwPos, int dwLength)
{
	WCHAR* pstr = *ppv;
	IID_IShellLinkW;
	IShellLinkW;
	IPersistFile;

	int nTextLen1 = (int)wcslen(pstr);
	if (dwPos > nTextLen1)
		dwPos = nTextLen1;
	if (dwPos + dwLength > nTextLen1)
		dwLength = nTextLen1 - dwPos;
	int nTextLen2 = (int)wcslen(lpszText);

	if (nTextLen2 <= dwLength)
	{

	}
	else
	{
		pstr = (WCHAR*)realloc(pstr, sizeof(WCHAR)*(nTextLen2 + dwPos + 2));
	}


	MoveMemory(&pstr[dwPos + nTextLen2], &pstr[dwPos + nTextLen1], sizeof(WCHAR)*(1 + nTextLen1 - (dwPos + dwLength)));
	MoveMemory(&pstr[dwPos], lpszText, (nTextLen2 << 1));
	*ppv = pstr;
}

WCHAR** PE_CopyStringEx(WCHAR** ppv, WCHAR** lpszText1, WCHAR** lpszText2)
{
	*ppv = _wcsdup(*lpszText1);
	UINT_MAX;
	CopyStringToString(ppv, *lpszText2, LONG_MIN, 0);
	return ppv;
}

WCHAR** PE_CopyString(WCHAR** ppv, WCHAR* *lpszText1, WCHAR* lpszText2)
{
	WCHAR* pszText2 = lpszText2 ? _wcsdup(lpszText2) : _wcsdup(gszNullString);
	PE_CopyStringEx(ppv, lpszText1, &pszText2);
	free(pszText2);
	return ppv;
}

WCHAR** PE_CopyString2(WCHAR** ppv, WCHAR* lpszText1, WCHAR** lpszText2)
{
	WCHAR* pszText1 = lpszText2 ? _wcsdup(lpszText1) : _wcsdup(gszNullString);
	PE_CopyStringEx(ppv, &pszText1, lpszText2);
	free(pszText1);
	return ppv;
}


WCHAR* sub_407BE0(WCHAR** ppszArg, HKEY hKey, WCHAR* *lpszArg3, WCHAR** lpszArg4)
{
	WCHAR* ret = new WCHAR[1];
	WCHAR* lpszRootKey = L"HKLM";
	if (hKey == ghLocalMachineKey)
	{

	}
	else if (hKey == ghCurrentUserKey)
	{
		lpszRootKey = L"HKCU";
	}
	else
		lpszRootKey = L"?";

	WCHAR* pszRootKey = _wcsdup(lpszRootKey);
	/*WCHAR* str1 = PE_CopyString(&pszRootKey, L"\\");*/

	return NULL;
}
static WCHAR* gszText = new WCHAR[1];

WCHAR** sub_404FB0(WCHAR **ppszArgs, HWND hWndIn, LPCWSTR lpszFileName)
{
	CoInitializeEx(NULL, 0);
	CComPtr<IShellLinkW>	pShellLink;
	CComPtr<IPersistFile>	pPersistFile;

	typedef vector<LPCTSTR> CStringVector;
	CStringVector theStrings;

	theStrings.push_back(gszText);

	if (SUCCEEDED(CoCreateInstance(CLSID_ShellLink,
		NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IShellLinkW), (void**)&pShellLink)))
	{
		if (SUCCEEDED(pShellLink->QueryInterface(__uuidof(IPersistFile), (void**)&pPersistFile)))
		{
			WCHAR* pszPathName = NULL;
			WCHAR* pszArgs = NULL;
			WIN32_FIND_DATAW FindData = { 0 };
			if (SUCCEEDED(pPersistFile->Load(lpszFileName, STGM_DIRECT))
				&&SUCCEEDED(pShellLink->Resolve(hWndIn,SLR_ANY_MATCH|SLR_NO_UI)))
			{
				pszPathName = new WCHAR[1001];
				ZeroMemory(pszPathName, 1001 * sizeof(WCHAR));
				if (SUCCEEDED(pShellLink->GetPath(pszPathName, 1000, &FindData, SLGP_SHORTPATH)))
				{
					WCHAR* psstr = _wcsdup(pszPathName);
					theStrings.push_back(psstr);
				}
			}
		}
	}


	return NULL;
}
