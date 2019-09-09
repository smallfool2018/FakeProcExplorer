int __stdcall Proxy_ProcThreadListCtrlWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	HWND hWnd; // ebx
	LPARAM lParam; // edi
	int result; // eax
	HCURSOR v7; // eax
	LRESULT nItemCount_1; // eax
	HBRUSH hBrush; // eax
	HBRUSH hBrush_1; // eax
	LRESULT nTopIndex; // eax
	HBRUSH hBrush_2; // eax
	int code; // eax
	signed int v14; // edi
	int v15; // ST18_4
	int v16; // ST14_4
	HWND v17; // eax
	int v18; // ST18_4
	int v19; // ST14_4
	HWND v20; // eax
	int nRet; // edi
	HDC v22; // esi
	int v23; // eax
	bool v24; // zf
	bool v25; // sf
	unsigned __int8 v26; // of
	LPARAM v27; // eax
	void *v28; // ST24_4
	LPARAM v29; // eax
	HWND hWndTooltips; // eax
	HANDLE v31; // eax
	HWND hWndTooltips_1; // eax
	HCURSOR hCursor; // eax
	unsigned int pUserData; // esi
	unsigned int nIndex; // ecx
	__m128i v36; // xmm1
	LPARAM *v37; // edx
	unsigned int v38; // eax
	__m128i v39; // xmm0
	HGLOBAL hGlobal; // edi
	int nLength; // ebx
	wchar_t *pBuffer; // esi
	LRESULT nItem_1; // ecx
	unsigned int nIdIndex; // eax
	HDC wParam_3; // ST20_4
	HWND hWndParent; // eax
	HWND hWndList; // edi
	int nItem; // eax
	int nID; // esi
	LRESULT nCount; // eax
	LRESULT lParam1; // eax
	LVITEMW Item; // [esp+Ch] [ebp-6254h]
	LVITEMW item; // [esp+40h] [ebp-6220h]
	unsigned int lParam4; // [esp+74h] [ebp-61ECh]
	HWND hWnd; // [esp+78h] [ebp-61E8h]
	unsigned __int32 nItemCount; // [esp+7Ch] [ebp-61E4h]
	LPARAM lParam; // [esp+80h] [ebp-61E0h]
	HDC wParam; // [esp+84h] [ebp-61DCh]
	struct tagPOINT Point; // [esp+88h] [ebp-61D8h]
	char v60; // [esp+90h] [ebp-61D0h]
	WPARAM uMsg; // [esp+94h] [ebp-61CCh]
	WPARAM wParam_1; // [esp+98h] [ebp-61C8h]
	RECT lParam_1; // [esp+9Ch] [ebp-61C4h]
	RECT rcItem; // [esp+ACh] [ebp-61B4h]
	struct tagRECT Rect; // [esp+BCh] [ebp-61A4h]
	RECT rc; // [esp+CCh] [ebp-6194h]
	LPARAM arrIDs[96]; // [esp+DCh] [ebp-6184h]
	WCHAR szText[8192]; // [esp+25Ch] [ebp-6004h]
	WCHAR chText[4096]; // [esp+425Ch] [ebp-2004h]

	static int gIntArray[] = { 1,2,3,4 };


	item.mask = 0;
	memset(&item.iItem, 0, 0x30u);
	if (Msg > WM_NOTIFY)
	{
		if (Msg == WM_KEYDOWN)
		{
			switch (wParam)
			{
			case VK_TAB:
				hWndList = ghWndTreeListView;
				if (hWnd == ghWndTreeListView)
				{
					hWndList = ghWndHandlesListCtrl;
					if (gConfig.bShowDllView)
						hWndList = ghWndDllsListCtrl;
				}
				item.iItem = 0;
				item.iSubItem = 0;
				item.stateMask = LVIS_SELECTED;
				item.mask = LVIF_PARAM |LVIF_STATE;
				nItem = SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
				if (nItem == -1)
					nItem = 0;
				item.iItem = nItem;
				SetFocus(hWndList);
				Item.stateMask = LVIS_FOCUSED|LVIS_SELECTED;
				Item.state = LVIS_FOCUSED | LVIS_SELECTED;
				SendMessageW(hWndList, LVM_SETITEMSTATE, item.iItem, &Item);
				return 0;
			case VK_RETURN:
				if (hWnd == ghWndTreeListView)
				{
					nID = IDC_TREEVIEW_LIST;
				}
				else
				{
					nItemCount = 2 * (hWnd == ghWndDllsListCtrl) + IDC_LISTCTRL_HANDLES;
					nID = 2 * (hWnd == ghWndDllsListCtrl) + IDC_LISTCTRL_HANDLES;
				}
				item.iItem = SendMessageW(hWnd, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
				if (item.iItem != -1)
					FillList(nID);
				return 0;
			case VK_END:
				Item.stateMask = LVIS_FOCUSED | LVIS_SELECTED;
				Item.state = LVIS_FOCUSED | LVIS_SELECTED;
				nCount = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
				SendMessageW(hWnd, LVM_SETITEMSTATE, nCount - 1, &Item);
				lParam1 = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
				SendMessageW(hWnd, LVM_ENSUREVISIBLE, lParam1 - 1, 0);
				return 0;
			case VK_HOME:
				Item.stateMask = LVIS_FOCUSED | LVIS_SELECTED;
				Item.state = LVIS_FOCUSED | LVIS_SELECTED;
				SendMessageW(hWnd, LVM_SETITEMSTATE, 0, &Item);
				SendMessageW(hWnd, LVM_ENSUREVISIBLE, 0, 0);
				return 0;
			case  'C':///0x43, 67
				if (hWnd != ghWndTreeListView && GetKeyState(VK_LCONTROL))
				{
					pUserData = GetWindowLongW(hWnd, GWLP_USERDATA);
					nItemCount = pUserData;
					if (!SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, pUserData, arrIDs))
					{
						nIndex = 0;
						if (pUserData)
						{
							if (pUserData >= 8)
							{
								v36 = _mm_load_si128(&gIntArray);
								v37 = &arrIDs[4];
								do
								{
									v38 = nIndex + 4;
									v37 += 8;
									v39 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(nIndex), 0), v36);
									nIndex += 8;
									_mm_storeu_si128(v37 - 3, v39);
									_mm_storeu_si128(v37 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v38), 0), v36));
								} while (nIndex < pUserData - (pUserData & 7));
							}
							for (; nIndex < pUserData; ++nIndex)
								arrIDs[nIndex] = nIndex;
						}
					}
					hGlobal = 0;
					item.iItem = -1;
					nLength = 0;
					pBuffer = 0;
					nItem_1 = SendMessageW(hWnd, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
					for (item.iItem = nItem_1; nItem_1 != -1; item.iItem = nItem_1)
					{
						nIdIndex = 0;
						lParam4 = 0;
						if (nItemCount)
						{
							while (1)
							{
								Item.iSubItem = arrIDs[nIdIndex];
								Item.pszText = szText;
								Item.cchTextMax = 8192;
								SendMessageW(hWnd, LVM_GETITEMTEXTW, nItem_1, &Item);
								nLength += wcslen(szText) + 2;
								if (pBuffer)
								{
									GlobalUnlock(hGlobal);
									hGlobal = GlobalReAlloc(hGlobal, 2 * nLength + 2, 0);
									pBuffer = GlobalLock(hGlobal);
								}
								else
								{
									hGlobal = GlobalAlloc(0x2002u, 2 * nLength + 2);
									pBuffer = GlobalLock(hGlobal);
									*pBuffer = 0;
								}
								wcscat_s(pBuffer, nLength + 1, szText);
								if (++lParam4 >= nItemCount)
									break;
								wcscat_s(pBuffer, nLength + 1, L"\t");
								nIdIndex = lParam4;
								if (lParam4 >= nItemCount)
									break;
								nItem_1 = item.iItem;
							}
						}
						wcscat_s(pBuffer, nLength + 1, L"\r\n");
						GlobalUnlock(hGlobal);
						nItem_1 = SendMessageW(hWnd, LVM_GETNEXTITEM, item.iItem, 2);
					}
					hWnd = hWnd;
					SetFocus(hWnd);
					if (hGlobal && OpenClipboard(hWnd))
					{
						EmptyClipboard();
						SetClipboardData(CF_UNICODETEXT, hGlobal);
						CloseClipboard();
					}
					lParam = lParam;
				}
				goto LABEL_70;
			default:
			LABEL_70:
				wParam_3 = wParam;
				hWndParent = GetParent(hWnd);
				SendMessageW(hWndParent, WM_KEYDOWN, wParam_3, lParam);
				break;
			}
		}
		else if (Msg == WM_MOUSEMOVE)
		{
			if (gdwVersion < 1)
			{
				hWndTooltips = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
				if (!IsWindowVisible(hWndTooltips)
					|| (Point.x = lParam, Point.y = SHIWORD(lParam), SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point) >= 0)
					&& (v31 = GetPropW(hWnd, L"hitrow"), wParam_1 != v31))
				{
					hWndTooltips_1 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
					SendMessageW(hWndTooltips_1, TTM_POP, 0, 0);
				}
			}
			if (hWnd == ghWndDllsListCtrl)
			{
				GetCursorPos(&Point);
				ScreenToClient(hWnd, &Point);
				if (SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point) >= 0
					&& gConfig.dwDllColumnMap[wParam_1] == IDS_VIRUSTOTAL)
				{
					item.iItem = uMsg;
					item.mask = LVIF_PARAM;
					SendMessageW(hWnd, LVM_GETITEMW, 0, &item);
					if (sub_491820(item.lParam[4].field_1C))
					{
						hCursor = LoadCursorW(ghInstance, L"HAND");
						SetCursor(hCursor);
					}
				}
			}
		}
		return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
	}
	if (Msg != WM_NOTIFY)
	{
		RECT rcClient;
		switch (Msg)
		{
		case WM_SETFOCUS:
		case WM_KILLFOCUS:
			if (hWnd == ghWndTreeListView && (HWND)wParam != ghWndTreeListView)
				sub_451D40();
			return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
		case WM_ERASEBKGND:
			if (!SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0))
				return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
			GetClientRect(hWnd, &rcClient);
			rcItem.left = 0;
			nItemCount = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
			SendMessageW(hWnd, LVM_GETITEMRECT, nItemCount - 1, &rcItem);
			rc.left = rcItem.right;
			hBrush = GetSysColorBrush(COLOR_WINDOW);
			FillRect(wParam, &rc, hBrush);
			rc = rcClient;
			rc.right = rcClient.right;
			rc.top = rcItem.bottom;
			rc.bottom = rcClient.bottom;
			FillRect(wParam, &rc, hBrush);
			rcItem.left = 0;
			nTopIndex = SendMessageW(hWnd, LVM_GETTOPINDEX, 0, 0);
			SendMessageW(hWnd, LVM_GETITEMRECT, nTopIndex, &rcItem);
			rc.right = rcClient.right;
			rc.left = 0;
			rc.top = 0;
			rc.bottom = rcItem.top;
			FillRect(wParam, &rc, hBrush);
			return 1;
		case WM_SETCURSOR:
			if (hWnd == ghWndHandlesListCtrl)
			{
				SetCursor(ghCursorArrow);
				return 1;
			}
			else
			{
				SetCursor(gnRefCount? LoadCursorW(NULL, IDC_APPSTARTING): LoadCursorW(NULL, IDC_ARROW));
				return 1;
			}
		default:
			return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
		}
		return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
	}
	// WM_NOTIFY
	NMHDR* pNMHDR = (NMHDR*)lParam;

	if (*lParam != SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0))
		return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
	
	code = pNMHDR->code;
	if (code != TTN_GETDISPINFOW)
	{
		if (code == TTN_SHOW)
		{
			v14 = -1;
			if (gdwVersion >= 1)
				v14 = -4;
			GetCursorPos(&Point);
			ScreenToClient(hWnd, &Point);
			item.iItem = SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point);
			if (item.iItem != -1 && wParam_1 != -1)
			{
				sub_44A880(hWnd, uMsg, wParam_1, &lParam_1);
				Point.x = lParam_1.left;
				Point.y = lParam_1.top;
				ClientToScreen(hWnd, &Point);
				v15 = Point.y - 1;
				v16 = v14 + Point.x;
				v17 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
				SetWindowPos(v17, 0, v16, v15, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE);
				return 1;
			}
			v18 = Point.y - 1;
			v19 = v14 + Point.x;
			v20 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
			SetWindowPos(v20, 0, v19, v18, 0, 0, SWP_NOACTIVATE);
			lParam = lParam;
		}
		return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
	}

	///TTN_GETDISPINFOW
	{
		if (gdwVersion >= 1)
			return CallWindowProcW(gOldListWndProc, hWnd, Msg, wParam, lParam);
		nRet = CallWindowProcW(gOldListWndProc, hWnd, WM_NOTIFY, wParam, lParam);
		GetCursorPos(&Point);
		ScreenToClient(hWnd, &Point);
		if (SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point) < 0 || !(v60 & 0xE) || (wParam_1 & 0x80000000) != 0)
			return nRet;
		item.iSubItem = wParam_1;
		item.iItem = uMsg;
		item.mask = 1;
		item.pszText = chText;
		item.cchTextMax = 4096;
		SendMessageW(hWnd, LVM_GETITEMW, 0, &item);
		if (!chText[0])
		{
			v29 = lParam;
			*(lParam + 12) = 0;
			*(v29 + 16) = 0;
			return nRet;
		}
		Item.pszText = 2;
		SendMessageW(hWnd, LVM_GETCOLUMNW, wParam_1, &Item.pszText);
		_mm_storeu_si128(&lParam_1, 0i64);
		v22 = GetDC(hWnd);
		SelectObject(v22, ghConfigFont);
		DrawTextW(v22, chText, -1, &lParam_1, 0xD00u);
		v23 = lParam_1.right - lParam_1.left + 6;
		v26 = __OFSUB__(v23, Item.iImage);
		v24 = v23 == Item.iImage;
		v25 = v23 - Item.iImage < 0;
		v27 = lParam;
		if ((v25 ^ v26) | v24)
		{
			*(lParam + 12) = 0;
			*(v27 + 16) = 0;
		}
		else
		{
			v28 = wParam_1;
			*(lParam + 12) = chText;
			SetPropW(hWnd, L"hitrow", v28);
		}
		ReleaseDC(hWnd, v22);
	}
	return nRet;
}