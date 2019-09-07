#include "stdafx.h"

//CComBSTR gstr(lpszText);
#include <comutil.h>

class CComBSTRX :public CComBSTR
{
public:
};

class _bstr_t_x : public _bstr_t
{
public:

};

////typedef struct tagStringItem
////{
////	_bstr_t bstrName;
////	int		nValue1;
////	int		nValue2;
////}STRINGITEM,*PSTRINGITEM,*LPSTRINGITEM;
////
////typedef map<WCHAR*, tagStringItem> CStringItemMap;
////
////CStringItemMap gMap7;

#include <system_error>
class _System_error_category_Ex : public std::_System_error_category
{
public:
	_System_error_category_Ex() {}
	virtual ~_System_error_category_Ex() {}
};

////class _bstr_t_data : public _bstr_t::Data_t
////{
////public:
////
////};

BSTR Fake_Sub_494390(LPCSTR lpszText)
{
	int nLength = lstrlenA(lpszText);
	WCHAR* pString = NULL;
	WCHAR szBuffer[8] = { 0 };
	BSTR bstr = NULL;
	//try
	//{
		int ret = MultiByteToWideChar(CP_ACP, 0, lpszText, nLength + 1, NULL, NULL);
		if (ret)
		{
			int cbRet = ret;
			ret = ret << 1;

			if (ret >= 4096)
			{
				pString = new WCHAR[cbRet];
			}
			else
			{
				pString = szBuffer;
			}
			if (MultiByteToWideChar(CP_ACP, 0, lpszText, nLength + 1, pString, cbRet) > 0)
			{
				bstr = SysAllocString(pString);
			}
			if (ret >= 4096)
				delete[]pString;
		}
	//}
	//catch (_com_error(GetLastError()| 0x80070000))
	//{

	//}


	return bstr;
	
}

tagGraphInfo gIOGraphInfo("I/O",2);
tagGraphInfo gNetworkGraphInfo("Network",9);
tagGraphInfo gDiskGraphInfo("Disk",8);

void CGraphData_Update(CGraphData& gd, FILETIME time,
	double dbMemorySize,
	double dbValue, 
	LPCWSTR lpszName)
{
	if (gd.m_nItemID)
	{
		if (dbMemorySize > gd.m_dbMemorySize)
			gd.m_dbMemorySize = dbMemorySize*1.2;
		else if (dbMemorySize <= gd.m_dbMemorySize)
		{
			if (dbMemorySize < 0.0)
				dbMemorySize = 0.0;
		}
		else
		{
			dbMemorySize = gd.m_dbMemorySize;
		}
	}

	if (dbValue < gd.m_Item[0].dbMemorySize)
	{
		if (dbValue < 0.0)
			dbValue = 0.0;
	}
	else
	{
		dbValue = 100.0;
	}

	WCHAR* psz = _wcsdup(lpszName);
	gd.m_Lock.Lock();


	gd.m_Lock.Unlock();

}


void GraphInfo_Refresh(tagGraphInfo* pGrahInfo)
{
	pGrahInfo->pGraphData->m_dbMemorySize = 1.0;
	DWORD nIndex = 0;
	for (; nIndex < gdwVirtualScreenWidth; ++nIndex)
	{
		//double v5 = *(pGrahInfo->pGraphData->m_Item[0].dwValue[0] + 8 * nIndex);
		//if (v5 > pGrahInfo->pGraphData->m_dbMemorySize)
		//{
		//	pGrahInfo->pGraphData->m_dbMemorySize = v5 * 1.2;
		//}
	}
	int nChild = 1;
}