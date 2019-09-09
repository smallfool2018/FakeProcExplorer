#include "stdafx.h"
#include "..\include\GraphWnd.h"




void SystemProcessInfo_GetSystemProcessName(DWORD dwProcessId, LARGE_INTEGER* FileTime, WCHAR* pszText, DWORD dwSize)
{
	PSYSTEM_PROCESS_INFORMATION i = NULL;
	if (dwProcessId == -10)
	{
		wcscpy_s(pszText, dwSize, L"Hardware Interrupts and DPCs");
		return;
	}

	for (i = gpSystemProcessInfo;
		dwProcessId != HandleToUlong(i->UniqueProcessId)
		|| FileTime && (*(ULONGLONG*)&i->CreateTime > *(ULONGLONG*)FileTime);
		i = (i + i->NextEntryOffset))
	{
		if (!i->NextEntryOffset)
		{
			wcscpy_s(pszText, dwSize, L"<Non-existent Process>");
			return;
		}
	}
	if (i->ImageName.Length)
		wcsncpy_s(pszText, dwSize, i->ImageName.Buffer, i->ImageName.Length >> 1);
	else
		wcscpy_s(pszText, dwSize, L"System Idle Process");
}

void QueryProcessCommandLineArgs(HANDLE hProcess,
	PVOID PebAddress,
	WCHAR **ppszCommandLine,
	WCHAR **ppszCurrentDirectory,
	WCHAR **ppszEnvBlock
);

void PE_GetFullPathName(WCHAR** ppszPathName);


void QueryProcessArguments(HANDLE hProcess, 
	DWORD dwProcessId, 
	WCHAR **ppszCommandLine, 
	WCHAR **ppszCurrentDirectory,
	WCHAR **ppszEnvBlock, 
	PDWORD pbFlagsInExtendedProcessBasicInfo)
{	
	PROCESS_EXTENDED_BASIC_INFORMATION ProcessInformation = { sizeof(ProcessInformation) };

	ULONG cbRet = 0;
	if(ppszCommandLine)
		*ppszCommandLine = NULL;
	if (ppszCurrentDirectory)
		*ppszCurrentDirectory = NULL;
	if (ppszEnvBlock)
		*ppszEnvBlock = NULL;

	if (hProcess)
	{
		if (!gpfn_NtQueryInformationProcess(hProcess,
			ProcessBasicInformation,
			(PVOID)&ProcessInformation,
			sizeof(PROCESS_EXTENDED_BASIC_INFORMATION),
			&cbRet)
			||	!gpfn_NtQueryInformationProcess(hProcess,
				ProcessBasicInformation,
				(PVOID)&ProcessInformation.BasicInfo,
				sizeof(PROCESS_BASIC_INFORMATION),
				&cbRet))
		{
			if (pbFlagsInExtendedProcessBasicInfo)
				*pbFlagsInExtendedProcessBasicInfo = ProcessInformation.Flags & 1;

			if (ProcessInformation.BasicInfo.PebBaseAddress)
			{
				QueryProcessCommandLineArgs(hProcess,
					ProcessInformation.BasicInfo.PebBaseAddress,
					ppszCommandLine,
					ppszCurrentDirectory,
					ppszEnvBlock);

				if (*ppszCurrentDirectory)
				{
					PE_GetFullPathName(ppszCurrentDirectory);
				}
				else
				{
					*ppszCurrentDirectory = _wcsdup(L"");
				}
				if (!*ppszEnvBlock)
				{
					*ppszEnvBlock = _wcsdup(L"");
				}
			}
		}
	}
}


void QueryProcessCommandLineArgs(HANDLE hProcess,
	PVOID PebAddress,
	WCHAR **ppszCommandLine,
	WCHAR **ppszCurrentDirectory,
	WCHAR **ppszEnvBlock
)
{


}

void PE_GetFullPathName(WCHAR** ppszPathName)
{

}

DWORD Fake_GetProcessMitigationPolicy(HANDLE hProcess)
{
	///BOOL GetProcessMitigationPolicy(HANDLE hProcess, _PROCESS_MITIGATION_POLICY MitigationPolicy, PVOID lpBuffer, SIZE_T dwLength);
	PROCESS_MITIGATION_DEP_POLICY Policy = { 0 };

	return 0;
}

BOOL Fake_GetProcessDEPPolicy(HANDLE hProcess, LPDWORD lpFlags, PBOOL lpPermanent)
{
	///BOOL GetProcessDEPPolicy(HANDLE hProcess,LPDWORD lpFlags,PBOOL lpPermanent);
	return GetProcessDEPPolicy(hProcess, lpFlags, lpPermanent);
}

#if DEBUG_sub_FDA500

int __cdecl sub_FDA500(SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo)
{
	SYSTEM_PROCESS_INFORMATION *pNext; // eax
	ULONG NumberOfThreads; // ecx
	signed int v3; // edx
	PUCHAR pKernelTime; // eax
	unsigned int v5; // esi
	int v6; // kr00_4
	int result; // eax

	////if (GetVersion() <= 4u)
	////	pNext = (pSystemProcessInfo + 0x88);
	////else
		pNext = pSystemProcessInfo + 1;
	NumberOfThreads = pSystemProcessInfo->NumberOfThreads;
	if (!NumberOfThreads)
		goto __quit;

	v3 = 0;
	pKernelTime = (PUCHAR)&pNext->KernelTime;
	v5 = 0;
	do
	{
		v6 = *pKernelTime + v5;
		////v3 = (*pKernelTime + __PAIR__(v3, v5)) >> 32;
		v5 += *pKernelTime;
		pKernelTime += 0x40;
		--NumberOfThreads;
	} while (NumberOfThreads);
	if (v3 >= 0 && (v3 > 0 || v6))
		result = v6;
	else
__quit:
	result = 0;
	return result;
}

#endif 
///sub_FDA500

ULONGLONG SystemProcessInfo_CalculateKernelTime(PSYSTEM_PROCESS_INFORMATION pSystemProcessInfo)
{
	//if (gdwVersion <= WINDOWS_XP)
	//{

	//}
	PSYSTEM_PROCESS_INFORMATION pInfo = pSystemProcessInfo;
	pInfo++;
	if (!pSystemProcessInfo->NumberOfThreads)
		return 0i64;


	return 0i64;

}