#include "stdafx.h"
#include "..\include\Driver.h"


CDriver theDriver;

//////////////////////////////////////////////////////////////////////////
//
CDriver::CDriver()
	:m_hDriver(INVALID_HANDLE_VALUE)
{
	////CString str;
	////str.LoadString(IDS_ADDRESS);

	////CString str2;
	////str2.SetString(_TEXT("This is a test"));

	////CString str3 = str2 + str;

	////str2.Empty();
}


CDriver::~CDriver()
{
	this->Close();
}

//////////////////////////////////////////////////////////////////////////
//
//CDriver::Load: 加载内嵌在EXE资源中的驱动程序
//
//返回值：
//
//////////////////////////////////////////////////////////////////////////
BOOL CDriver::Load()
{
	TCHAR szPathName[_MAX_PATH] = { 0 };
	TCHAR szFullPath[_MAX_PATH] = { 0 };
	if (!Open(TEXT("PROCEXP152"), &m_hDriver))
	{
		GetSystemDirectory(szPathName, _MAX_PATH);
		_stprintf_s(szFullPath, _MAX_PATH, TEXT("%s\\Driver\\%s"), szPathName, TEXT("PROCEXP152.SYS"));
		if (!SaveDriverFromResource(MAKEINTRESOURCE(IDR_DRIVER_150), szFullPath))
		{
			_stprintf_s(szPathName, _MAX_PATH, TEXT("%%TEMP%%\\%s"), TEXT("PROCEXP152.SYS"));
			ExpandEnvironmentStrings(szPathName, szFullPath, _MAX_PATH);
			if (!SaveDriverFromResource(MAKEINTRESOURCE(IDR_DRIVER_150), szFullPath))
			{
				GetCurrentDirectory(_MAX_PATH, szPathName);
				_stprintf_s(szFullPath, _MAX_PATH, TEXT("%s\\%s"), szPathName, TEXT("PROCEXP152.SYS"));
				if (!SaveDriverFromResource(MAKEINTRESOURCE(IDR_DRIVER_150), szFullPath))
					return FALSE;
			}
		}
		if (!OpenEx(TEXT("PROCEXP152"), szFullPath, &m_hDriver))
		{
			DeleteFile(szFullPath);
			return TRUE;
		}
		DeleteFile(szFullPath);
	}
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//CDriver::Close: 关闭驱动程序
//
//返回值：
//
//////////////////////////////////////////////////////////////////////////
BOOL CDriver::Close()
{
	if (m_hDriver != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hDriver);
		m_hDriver = INVALID_HANDLE_VALUE;
	}
	return TRUE;
}


//////////////////////////////////////////////////////////////////////////
//
//CDriver::Control: 读写控制驱动程序
//
//返回值：
//
//////////////////////////////////////////////////////////////////////////
BOOL CDriver::Control(DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize, LPVOID lpOutBuffer, DWORD nOutBufferSize)
{
	DWORD dwRet = 0L;
	if (m_hDriver == INVALID_HANDLE_VALUE)
		return FALSE;
	return DeviceIoControl(m_hDriver, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, &dwRet, NULL) != 0;
}

//////////////////////////////////////////////////////////////////////////
//
//CDriver::Open: 将指定名称的驱动程序加载到指定的句柄中
//
//返回值：
//
//////////////////////////////////////////////////////////////////////////
BOOL CDriver::Open(LPCTSTR lpszFileName, PHANDLE DriverHandle)
{
	TCHAR szFileName[_MAX_PATH] = { 0 };	
	_stprintf_s(szFileName, _MAX_PATH, TEXT("\\\\.\\%s"), lpszFileName);
	HANDLE hFile = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_stprintf_s(szFileName, _MAX_PATH, TEXT("\\\\.\\Globals\\%s"), lpszFileName);
		hFile = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	}
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;
	*DriverHandle = hFile;
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//CDriver::SaveDriverFromResource: 将指定资源ID的资源信息保存到指定名称的文件中
//
//lpszResID:
//lpszPathName:
//
//返回值：
//
//////////////////////////////////////////////////////////////////////////
BOOL CDriver::SaveDriverFromResource(LPCTSTR lpszResID, LPCTSTR lpszPathName)
{
	FILE* pFile = NULL;
	if (_tfopen_s(&pFile, lpszPathName, TEXT("wb")))
		return FALSE;

	HRSRC hRsrc = FindResource(NULL, lpszResID, TEXT("BINRES"));
	if (!hRsrc)
	{
		fclose(pFile);
		return FALSE;
	}
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);
	DWORD dwSize = SizeofResource(NULL, hRsrc);
	PVOID pBuffer = LockResource(hGlobal);
	fwrite(pBuffer, sizeof(CHAR), dwSize, pFile);
	fclose(pFile);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//CDriver::OpenEx:	自动打开指定的驱动文件
//lpszDriverName:	待打开的驱动名称
//lpszPathName:		驱动文件路径信息
//DriverHandle:		打开成功返回的驱动句柄
//
//返回值：
//
//////////////////////////////////////////////////////////////////////////
BOOL CDriver::OpenEx(LPCTSTR lpszDriverName, LPCTSTR lpszPathName, PHANDLE DriverHandle)
{
#define KEYFORMAT TEXT("System\\CurrentControlSet\\Services\\%s")
	TCHAR szKeyName[_MAX_PATH] = { 0 };
	TCHAR szBuffer[_MAX_PATH] = { 0 };

	HKEY hKey = NULL;
	LONG lRet = 0;
	DWORD dwValue = 1;
	UNICODE_STRING strDriverName;
	HANDLE hFile = INVALID_HANDLE_VALUE;

	/// 提权
	TmAdjustPrivilege(TEXT("SeLoadDriverPrivilege"));

	/// 写入注册表一些控制信息
	_stprintf_s(szKeyName, _MAX_PATH, KEYFORMAT, lpszDriverName);
	if (!RegCreateKey(HKEY_LOCAL_MACHINE, szKeyName, &hKey))
		return FALSE;
	dwValue = SERVICE_KERNEL_DRIVER;
	///服务类型
	RegSetValueEx(hKey, TEXT("Type"), 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));
	///错误处理
	dwValue = SERVICE_ERROR_NORMAL;
	RegSetValueEx(hKey, TEXT("ErrorControl"), 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));
	///启动风格
	dwValue = SERVICE_DEMAND_START;	
	RegSetValueEx(hKey, TEXT("Start"), 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));
	///路径信息
	_stprintf_s(szBuffer, _MAX_PATH, TEXT("\\??\\%s"), lpszPathName);
	RegSetValueEx(hKey, TEXT("ImagePath"), 0, REG_SZ, (BYTE*)szBuffer, sizeof(TCHAR)*_tcslen(szBuffer));
	RegCloseKey(hKey);

	///加载驱动
	LPFN_NtLoadDriver pfnNtLoadDriver = (LPFN_NtLoadDriver)::GetProcAddress(GetModuleHandle(TEXT("NTDLL.DLL")), "NtLoadDriver");
	_stprintf_s(szBuffer, _MAX_PATH, TEXT("\\Registry\\Machine\\System\\CurrentControlSet\\Services\\%s"), lpszPathName);

	if (gpfnRtlInitUnicodeString == NULL)
		gpfnRtlInitUnicodeString = (LPFN_RtlInitUnicodeString)::GetProcAddress(GetModuleHandle(TEXT("NTDLL.DLL")), "RtlInitUnicodeString");

	gpfnRtlInitUnicodeString(&strDriverName, szBuffer);
	NTSTATUS Status = pfnNtLoadDriver(&strDriverName);


	///删除一些键值
	_stprintf_s(szBuffer, _MAX_PATH, TEXT("%s\\Enum"), szKeyName);
	RegDeleteKey(HKEY_LOCAL_MACHINE, szBuffer);
	_stprintf_s(szBuffer, _MAX_PATH, TEXT("%s\\Security"), szKeyName);
	RegDeleteKey(HKEY_LOCAL_MACHINE, szBuffer);
	RegDeleteKey(HKEY_LOCAL_MACHINE, szKeyName);

	if (Status&&Status != STATUS_IMAGE_ALREADY_LOADED)
	{
		if (gpfnRtlNtStatusToDosError == NULL)
			gpfnRtlNtStatusToDosError = (LPFN_RtlNtStatusToDosError)::GetProcAddress(GetModuleHandle(TEXT("NTDLL.DLL")), "RtlNtStatusToDosError");

		///启动失败
		SetLastError(gpfnRtlNtStatusToDosError(Status));
		return FALSE;
	}
	else
	{
		///启动成功，打开驱动进行读写
		_stprintf_s(szBuffer, _MAX_PATH, TEXT("\\\\.\\%s"), lpszDriverName);
		hFile = CreateFile(szBuffer, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			_stprintf_s(szBuffer, _MAX_PATH, TEXT("\\\\.\\Global\\%s"), lpszDriverName);
			hFile = CreateFile(szBuffer, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		}
		if (hFile == INVALID_HANDLE_VALUE)
			return FALSE;
		*DriverHandle = hFile;
	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
///
///
///lpszDriverName:	待打开的驱动名称
///lpszPathName:		驱动文件路径信息
///DriverHandle:		打开成功返回的驱动句柄
///
///返回值：
///
//////////////////////////////////////////////////////////////////////////
HANDLE PE_OpenProcess(DWORD dwDesiredAccess, DWORD dwReserved, DWORD dwProcessId)
{
	HANDLE ret = OpenProcess(dwDesiredAccess, FALSE, dwProcessId);
	if (!ret)
	{
		if (GetLastError() == ERROR_ACCESS_DENIED)
		{
			DWORD cbRet = 0;
			DWORD OutBuffer = 0;
			theDriver.Control(CTRLCODE_QUERY_PROCESS_HANDLE, &dwProcessId, sizeof(DWORD), (PVOID)(&OutBuffer), sizeof(HANDLE));
			ret = (HANDLE)OutBuffer;
		}
	}
	return ret;
}

BOOL PE_IsProcessInJob(HANDLE ProcessHandle, DWORD ProcessId, void* pBuffer, DWORD dwRet)
{
	BOOL bRet = FALSE;
	if (!ProcessHandle)
		return FALSE;

	if (IsProcessInJob(ProcessHandle, NULL, &bRet) && bRet)
		return TRUE;

	if (gbSupportExtendedSystemHandleInformation)
	{

	}

	return FALSE;
}
