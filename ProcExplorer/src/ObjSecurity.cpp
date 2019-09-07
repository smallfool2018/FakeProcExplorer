#include "stdafx.h"
#include "..\include\ObjSecurity.h"

// {5872FBBF-7068-4737-99A0-626884D17240}
static const GUID CLSID_ObjectSecurity =
{ 0x965FC360, 0x16FF, 0x11D0,{ 0x91, 0xCB, 0, 0xAA, 0, 0xBB, 0xB7, 0x23 } };


SI_ACCESS gAccess[]=
{
	{ &GUID_NULL,1,L"List",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,2,L"Add Entry",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,GENERIC_READ,L"Read",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,GENERIC_WRITE,L"Write",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,DELETE,L"Delete",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,GENERIC_EXECUTE,L"Execute",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,READ_CONTROL,L"Read Control",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,WRITE_DAC,L"Change Permissions",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,WRITE_OWNER,L"Change Owner",SI_ACCESS_SPECIFIC },
};

SI_ACCESS gAccess2[] =
{
	{ &GUID_NULL,READ_CONTROL,L"Read",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,2,L"Write",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,DELETE,L"Delete",SI_ACCESS_SPECIFIC | SI_ACCESS_GENERAL },
	{ &GUID_NULL,WRITE_DAC,L"Change Permissions",SI_ACCESS_SPECIFIC },
	{ &GUID_NULL,WRITE_OWNER,L"Change Owner",SI_ACCESS_SPECIFIC },
};

HRESULT ProcExpSetSecurity(SERVERINFO* ServerInfo, SECURITY_INFORMATION SecurirtyInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, PSECURITY_DESCRIPTOR pSecurityDescriptor2, int nFlags);


//////////////////////////////////////////////////////////////////////////
CObjSecurity::CObjSecurity()
	:m_nRefCount(0)
{
}


CObjSecurity::~CObjSecurity()
{
}

HRESULT WINAPI CObjSecurity::QueryInterface(REFIID iid, void** ppv)
{
	if (iid == IID_IUnknown)
	{
		*ppv = this;
		return S_OK;
	}

	if (iid == CLSID_ObjectSecurity)
	{
		*ppv = this;
		return S_OK;
	}

	return E_NOINTERFACE;
}

ULONG WINAPI CObjSecurity::AddRef()
{
	ULONG ret = m_nRefCount;
	m_nRefCount++;
	return ret;
}

ULONG WINAPI CObjSecurity::Release()
{
	m_nRefCount--;
	ULONG ret = m_nRefCount;
	if (!m_nRefCount)
	{
		delete this;
		return 0;
	}
	return ret;
}

HRESULT WINAPI CObjSecurity::GetObjectInformation(PSI_OBJECT_INFO pObjectInfo)
{
	pObjectInfo->dwFlags = m_dwFlags;
	pObjectInfo->hInstance = ghMainInstance;
	pObjectInfo->pszObjectName = m_pszObjectName;
	pObjectInfo->pszServerName = m_pszServerName;

	return S_OK;
}

HRESULT WINAPI CObjSecurity::GetSecurity( SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR *ppSecurityDescriptor, BOOL fDefault)
{
	if (!(fDefault == 0))
		return E_NOTIMPL;
	DWORD dwError = 0;
	if (m_nRightType == 4)
	{
		DWORD cbNeeded = 0;
		QueryServiceObjectSecurity(m_ServerInfo->m_SCHandle, RequestedInformation, ppSecurityDescriptor, 0, &cbNeeded);
		if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
			PVOID pBuffer = LocalAlloc(0, cbNeeded);
			*ppSecurityDescriptor = (PSECURITY_DESCRIPTOR) pBuffer;
			if (QueryServiceObjectSecurity(m_ServerInfo->m_SCHandle, RequestedInformation, ppSecurityDescriptor, cbNeeded, &cbNeeded))
				return S_OK;
		}
		dwError = GetLastError();
	}

	return S_OK;

}

HRESULT WINAPI CObjSecurity::SetSecurity (SECURITY_INFORMATION SecurityInformation,
	PSECURITY_DESCRIPTOR pSecurityDescriptor)
{
	DWORD dwError = 0;
	if (m_nRightType == 4)
	{
		if (SetServiceObjectSecurity(m_ServerInfo->m_SCHandle, SecurityInformation, pSecurityDescriptor))
			return S_OK;
		dwError = GetLastError();
	}
	else
	{
		dwError = ProcExpSetSecurity(m_ServerInfo, SecurityInformation, pSecurityDescriptor, 0, 0);
	}
	return dwError|0x80070000;

}

HRESULT WINAPI CObjSecurity::GetAccessRights ( const GUID* pguidObjectType,
	DWORD dwFlags, // SI_EDIT_AUDITS, SI_EDIT_PROPERTIES
	PSI_ACCESS *ppAccess,
	ULONG *pcAccesses,
	ULONG *piDefaultAccess)
{
	return E_NOTIMPL;

}

GENERIC_MAPPING gMask1 = { 0x21410,0x203EB,0x120000,0x1F0FFF };
GENERIC_MAPPING gMask2 = { 0x21410,0x203EB,0x120000,0x1F0FFF };
GENERIC_MAPPING gMask3 = { 0x21410,0x203EB,0x120000,0x1F0FFF };
GENERIC_MAPPING gMask4 = { 0x120089,0x120116,0x1200A0,0x1F01FF };

HRESULT WINAPI CObjSecurity::MapGeneric ( const GUID *pguidObjectType,
	UCHAR *pAceFlags,
	ACCESS_MASK *pMask)
{
	if(m_nRightType==3)
		MapGenericMask(pMask, &gMask1);
	if (m_nRightType == 4)
		MapGenericMask(pMask, &gMask2);
	if (m_nRightType == 5)
		MapGenericMask(pMask, &gMask3);
	else
		MapGenericMask(pMask, &gMask4);
	return S_OK;

}
HRESULT WINAPI CObjSecurity::GetInheritTypes ( PSI_INHERIT_TYPE *ppInheritTypes,
	ULONG *pcInheritTypes)
{
	static SI_INHERIT_TYPE InheritType = { &GUID_NULL,0,L"Inherit None" };
	*ppInheritTypes = &InheritType;
	*pcInheritTypes = 1;
	return S_OK;

}
HRESULT WINAPI CObjSecurity::PropertySheetPageCallback( HWND hwnd, UINT uMsg, SI_PAGE_TYPE uPage)
{
	return S_OK;

}

HRESULT CObjSecurity::Create(LISTITEM* pListItem, LPCTSTR lpszText, CObjSecurity** ppv, int nType, BOOL fObjSecurity)
{
	CObjSecurity *pThis = new CObjSecurity();
	pThis->m_nRefCount = 1;
	HRESULT hr = pThis->Init(531, (tagHANDLELISTITEMPARAM*)pListItem, lpszText, TEXT(""), nType, fObjSecurity);
	if (FAILED(hr))
	{
		delete pThis;
	}
	return hr;
}

HRESULT CopyServerName(WCHAR** ppszServerName, LPCWSTR lpszServerName)
{
	if (!ppszServerName || !lpszServerName)
		return E_INVALIDARG;
	WCHAR* pszText = (WCHAR*)LocalAlloc(LMEM_ZEROINIT, sizeof(WCHAR)*(wcslen(lpszServerName) + 1));
	if (!pszText)
		return E_OUTOFMEMORY;
	wcscpy_s(pszText, wcslen(lpszServerName) + 1, lpszServerName);
	*ppszServerName = pszText;
	return S_OK;
}

HRESULT CObjSecurity::Init(UINT dwFlags, tagHANDLELISTITEMPARAM* pListItem, LPCWSTR lpszObjectName, LPCWSTR lpszServerName, int nType, BOOL fObjSecurity)
{
	m_dwFlags = dwFlags;
	if (fObjSecurity)
		m_dwFlags = dwFlags | 4;
	m_nRightType = nType;
	m_pszObjectName = (WCHAR*)lpszObjectName;
	m_ServerInfo = (SERVERINFO*)pListItem;
	CopyServerName(&m_pszServerName, lpszServerName);

	/*NtCreateKey();*/
	//Wow64RevertWow64FsRedirection()
	return S_OK;
}


HRESULT ProcExpSetSecurity(SERVERINFO* ServerInfo, SECURITY_INFORMATION SecurirtyInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, PSECURITY_DESCRIPTOR pSecurityDescriptor2, int nFlags)
{
	return S_OK;
}