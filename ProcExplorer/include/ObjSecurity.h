#ifndef __OBJECTSECURITY_H__
#define __OBJECTSECURITY_H__
#pragma once

#include <aclui.h>

#include "../ProcExplorer.h"

//////////////////////////////////////////////////////////////////////////
//0x1C = 28
class CObjSecurity :public ISecurityInformation
{
public:
	CObjSecurity();
	virtual ~CObjSecurity();

	STDMETHOD(QueryInterface)(THIS_ _In_ REFIID riid, _Outptr_ void **ppvObj) ;
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	// *** ISecurityInformation methods ***
	STDMETHOD(GetObjectInformation) (THIS_ PSI_OBJECT_INFO pObjectInfo) ;
	STDMETHOD(GetSecurity) (THIS_ SECURITY_INFORMATION RequestedInformation,
		PSECURITY_DESCRIPTOR *ppSecurityDescriptor,
		BOOL fDefault);
	STDMETHOD(SetSecurity) (THIS_ SECURITY_INFORMATION SecurityInformation,
		PSECURITY_DESCRIPTOR pSecurityDescriptor) ;
	STDMETHOD(GetAccessRights) (THIS_ const GUID* pguidObjectType,
		DWORD dwFlags, // SI_EDIT_AUDITS, SI_EDIT_PROPERTIES
		PSI_ACCESS *ppAccess,
		ULONG *pcAccesses,
		ULONG *piDefaultAccess);
	STDMETHOD(MapGeneric) (THIS_ const GUID *pguidObjectType,
		UCHAR *pAceFlags,
		ACCESS_MASK *pMask);
	STDMETHOD(GetInheritTypes) (THIS_ PSI_INHERIT_TYPE *ppInheritTypes,
		ULONG *pcInheritTypes);
	STDMETHOD(PropertySheetPageCallback)(THIS_ HWND hwnd, UINT uMsg, SI_PAGE_TYPE uPage) ;

	static HRESULT Create(LISTITEM* pListItem, LPCTSTR lpszText, CObjSecurity** ppv, int nType, BOOL fObjSecurity);

	virtual HRESULT Init(UINT nID, tagHANDLELISTITEMPARAM* pListItem, LPCWSTR lpszText, LPCWSTR lpszName, int nType, BOOL fObjSecurity);

public:
	LONG	m_nRefCount;

	DWORD	m_dwFlags;
	WCHAR*	m_pszServerName;
	WCHAR*	m_pszObjectName;

	UINT	m_nRightType;

	SERVERINFO *m_ServerInfo;

};


#endif //__OBJECTSECURITY_H__
