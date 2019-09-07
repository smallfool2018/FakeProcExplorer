#ifndef __DRIVER_H__
#define __DRIVER_H__

#pragma once

#define CTRLCODE_OPEN_PROCESS					0x83350004
#define CTRLCODE_LOAD_DRIVER_VERSION			0x83350008
//0x83350020
#define CTRLCODE_QUERY_PROCESS_HANDLE			0x8335003C		
//0x83350048
//0x210012


//////////////////////////////////////////////////////////////////////////
class CDriver
{
public:
	CDriver();
	~CDriver();

	BOOL Load();
	BOOL Close();
	BOOL Control(DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize, LPVOID lpOutBuffer, DWORD nOutBufferSize);
public:
	HANDLE m_hDriver;
private:
	static BOOL Open(LPCTSTR lpszFileName,PHANDLE DriverHandle);
	static BOOL SaveDriverFromResource(LPCTSTR lpszFileName, LPCTSTR lpszPathName);
	static BOOL OpenEx(LPCTSTR lpszDriverName, LPCTSTR lpszPathName, PHANDLE DriverHandle);

};

typedef LONG NTSTATUS;
#define STATUS_SUCCESS 0
#define STATUS_IMAGE_ALREADY_LOADED	0xC000010E

extern CDriver theDriver;
extern HANDLE PE_OpenProcess(DWORD dwDesiredAccess, DWORD dwReserved, DWORD dwProcessId);
extern BOOL PE_IsProcessInJob(HANDLE ProcessHandle, DWORD ProcessId, void* pBuffer, DWORD dwRet);



//typedef struct _UNICODE_STRING
//{
//	USHORT Length;
//	USHORT MaximumLength;
//	PWSTR  Buffer;
//}UNICODE_STRING,*PUNICODE_STRING;

//class CWin32HeapEx : public ATL::CWin32Heap
//{
//public:
//};
//
//class CAtlStringMgrEx : public ATL::CAtlStringMgr
//{
//public:
//};


#endif //