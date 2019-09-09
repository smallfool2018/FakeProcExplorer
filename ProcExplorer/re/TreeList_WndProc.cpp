HWND  CTreeList::TreeWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if (Msg - LVM_FIRST <= 0xFF)
		return this->HandleListViewMsg(hWnd, Msg, wParam, lParam);

	if (Msg == WM_LBUTTONDOWN)
	{
		if (LOBYTE(this->field_BC))
		{
			POINT ho = lParam;
			if (abs(lParam - this->m_nBottomScrollBarWidthOrHeight) <= 8)
			{
				SetCapture(hWnd);
				SetCursor(this->m_hCursor);
				this->m_ptDownLast.x = ho;
			LABEL_9:
				SetFocus(hWnd);
				Rect.bottom = 0;
				pChild = 0;
				dwStyle = CTreeList::Query(this, lParam, SHIWORD(lParam), &Rect.bottom, 0, &pChild);
				Rect.bottom = dwStyle;
				if (dwStyle & (TVIF_INTEGRAL | TVIF_CHILDREN | TVIF_SELECTEDIMAGE))
				{
					CTreeList::SendNotify(this, this->m_hWnd, -2, 0, pChild, 0, 0);
					LOWORD(dwStyle) = Rect.bottom;
				}
				if (dwStyle & TVIF_CHILDREN)
				{
					sub_42BF00(this, pChild, ~(pChild->m_dwStyle >> 4) & 1);
				}
				else if (dwStyle & (TVIF_STATEEX | TVIF_INTEGRAL | TVIF_CHILDREN | TVIF_SELECTEDIMAGE))
				{
					sub_42F090(this, pChild);
				}
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			}
			goto LABEL_40;
		}
	LABEL_32:
		hWnd = hWnd;
		goto LABEL_33;
	}
	if (Msg == WM_MOUSEMOVE)
	{
		if (this->field_BC)
		{
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			if (GetCapture() == hWnd && wParam & MK_LBUTTON)
			{
				int dx = pt.x - this->m_ptDownLast.x;
				if (pt.x != this->m_ptDownLast.x)
				{

					if (m_nBottomScrollBarWidthOrHeight + dx < this->field_94)
						dx = this->field_94 - m_nBottomScrollBarWidthOrHeight;
					this->m_ptDownLast.x += dx;

					CTreeList::MoveHeaders(this, m_nBottomScrollBarWidthOrHeight + dx);
					Paint.rcPaint.bottom = 1;
					hWndHeaderLeft = this->m_hWndHeaderLeft;
					Paint.fRestore = v14;
					SendMessageW(m_hWndHeaderLeft, HDM_SETITEMW, 0, &Paint.rcPaint.bottom);
					sub_42EF00(this);
					lParam = lParam;
				}
				SetCursor(this->m_hCursor);
				Msg = WM_MOUSEMOVE;
				goto LABEL_209;
			}
			if (abs(pChild - this->m_nBottomScrollBarWidthOrHeight) <= 8)
			{
				SetCursor(this->m_hCursor);
				Msg = WM_MOUSEMOVE;
				goto LABEL_209;
			}
			v16 = GetClassLongW(this->m_hWnd, GWLP_ID);
			v17 = this->m_pfnD8 == 0;
			v18 = v16;
			ho = v16;
			if (!v17)
			{
				pItem = 0;
				lpchText.m_Data = 0;
				pChildItem = 0;
				CTreeList::Query(this, pChild, SHIWORD(lParam), &pItem, &lpchText, &pChildItem);
				if (pChildItem)
				{
					// typedef LRESULT(*LPFN_CALLBACK_D8)(tagTreeViewChildItem* pItem, _bstr_t str);
					v19 = (this->m_pfnD8)(pChildItem, lpchText.m_Data);
					v18 = ho;
					if (v19)
						v18 = v19;
				}
				else
				{
					v18 = ho;
				}
			}
			SetCursor(v18);
			goto LABEL_31;
		}
		goto LABEL_32;
	}
	if (Msg != WM_LBUTTONUP || !LOBYTE(this->field_BC))
		goto LABEL_32;
	v21 = GetCapture();
	hWnd = hWnd;
	if (v21 == hWnd)
	{
		ReleaseCapture();
	LABEL_40:
		v22 = GetClassLongW(this->m_hWnd, GCL_HCURSOR);
		SetCursor(v22);
	LABEL_31:
		Msg = Msg;
		goto LABEL_32;
	}
	Msg = WM_LBUTTONUP;
LABEL_33:
	if (Msg > WM_KEYFIRST)
	{
		if (Msg > WM_MOUSELAST)
		{
			switch (Msg)
			{
			case TREELIST_MSG_2000:
				sub_42F160(wParam, lParam != 0);
				return 0;
			case TREELIST_MSG_2001:
				return sub_42BF00(this, wParam, lParam != 0);
			case TREELIST_MSG_2002:
				return *(wParam + 28);
			case TREELIST_MSG_2003:
				sub_42EAD0(this, wParam);
				return 0;
			case TREELIST_MSG_2004:
				return sub_42E5E0(*lParam, *(lParam + 4), *(lParam + 8));
			case TREELIST_MSG_2005:
				return CTreeList::FindChild(this, wParam);
			default:
				goto LABEL_82;
			}
			goto LABEL_82;
		}
		if (Msg == WM_MOUSELAST)
		{
			Rect.bottom = this->field_8C + SHIWORD(wParam);
			v84 = Rect.bottom;
			this->field_8C = Rect.bottom;
			if (abs(v84) >= 40)
			{
				this->field_8C = Rect.bottom - 40 * (v84 / 40);
				CTreeList::UpdateVScrollBars(this, Rect.bottom / -40);
			}
			return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
		}
		if (Msg <= WM_VSCROLL)
		{
			if (Msg == WM_VSCROLL)
			{
				*&Paint.rgbReserved[4] = 28;
				v82 = this->m_hWndScrollBarRightRight;
				*&Paint.rgbReserved[28] = 0;
				_mm_storeu_si128(&Paint.rgbReserved[12], 0i64);
				*&Paint.rgbReserved[8] = 7;
				GetScrollInfo(v82, 2, &Paint.rgbReserved[4]);
				switch (wParam)
				{
				case SB_HORZ:
					CTreeList::SetVScrollPos(--*&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_VERT:
					CTreeList::SetVScrollPos(++*&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_CTL:
					*&Paint.rgbReserved[24] -= *&Paint.rgbReserved[20];
					CTreeList::SetVScrollPos(*&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_BOTH:
					*&Paint.rgbReserved[24] += *&Paint.rgbReserved[20];
					CTreeList::SetVScrollPos(*&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_THUMBPOSITION:
				case SB_THUMBTRACK:
					*&Paint.rgbReserved[24] = wParam >> 16;
					CTreeList::SetVScrollPos(wParam >> 16);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_TOP:
					*&Paint.rgbReserved[24] = 0;
					CTreeList::SetVScrollPos(0);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_BOTTOM:
					*&Paint.rgbReserved[24] = *&Paint.rgbReserved[16];
					CTreeList::SetVScrollPos(*&Paint.rgbReserved[16]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_ENDSCROLL:
					return 1;
				default:
					return 0;
				}
				return 0;
			}
			v73 = Msg - WM_CHAR;
			if (!v73)
			{
				if (this->m_nChildCount)
				{
					pItem = GetTickCount();
					if (pItem - this->m_dwTickCountLast > 0x2EE)
						sub_42A320(byte_4C4260);
					if (!this->m_ChildLast
						|| ((v75 = _bstr_t::_bstr_t(&v88, byte_4C4260), v93 = sub_42A3E0(v75), _bstr_t::_Free(&v88), !v93) ? (v76 = this->m_ChildLast) : (v76 = sub_42E650(this->m_ChildLast)),
						(pChildItem = v76) == 0))
					{
						pChildItem = this->m_Child;
					}
					this->m_dwTickCountLast = pItem;
					ho = wParam;
					_bstr_t::_bstr_t(&lpchText, &ho);
					v106 = 0;
					_bstr_t::operator+=(&this->field_D0, &lpchText);
					v106 = -1;
					_bstr_t::_Free(&lpchText);
					v77 = pChildItem;
					pChild = pChildItem;
					while (1)
					{
						Rect.bottom = 260;
						v78 = (*(v77[1]->m_TreeList + 8))(v77, 0, v105, &Rect.bottom);
						lParam = lParam;
						pItem = v78;
						v79 = this->field_D0;
						lpchText.m_Data = (v79 ? *v79 : 0);
						v80 = sub_410440(&this->field_D0);
						if (!_wcsnicmp(pItem, lpchText.m_Data, v80))
							break;
						v77 = sub_42E650(pChild);
						pChild = v77;
						if (!v77)
						{
							v77 = this->m_Child;
							pChild = this->m_Child;
						}
						if (v77 == pChildItem)
							return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
					}
					sub_42F090(this, pChild);
					v81 = CTreeList::FindChild(this, pChild);
					sub_42BE30(this, v81);
				}
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			}
			v74 = v73 - 17;
			if (!v74)
			{
				if (wParam == 100)
				{
					GetCursorPos(&Rect.right);
					MapWindowPoints(0, hWnd, &Rect.right, 1u);
					CTreeList::PopTooltip(this, this->m_hWndTooltipOfTreeList, &Rect.right);
				}
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			}
			if (v74 == 1)
			{
				if (!lParam)
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				*&Paint.rgbReserved[4] = 28;
				*&Paint.rgbReserved[28] = 0;
				_mm_storeu_si128(&Paint.rgbReserved[12], 0i64);
				*&Paint.rgbReserved[8] = 7;
				GetScrollInfo(lParam, 2, &Paint.rgbReserved[4]);
				switch (wParam)
				{
				case SB_HORZ:
					--*&Paint.rgbReserved[24];
					CTreeList::SetHScrollPos(lParam, *&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_VERT:
					++*&Paint.rgbReserved[24];
					CTreeList::SetHScrollPos(lParam, *&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_CTL:
					*&Paint.rgbReserved[24] -= *&Paint.rgbReserved[20];
					CTreeList::SetHScrollPos(lParam, *&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_BOTH:
					*&Paint.rgbReserved[24] += *&Paint.rgbReserved[20];
					CTreeList::SetHScrollPos(lParam, *&Paint.rgbReserved[24]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_THUMBPOSITION:
				case SB_THUMBTRACK:
					*&Paint.rgbReserved[24] = wParam >> 16;
					CTreeList::SetHScrollPos(lParam, wParam >> 16);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_TOP:
					*&Paint.rgbReserved[24] = 0;
					CTreeList::SetHScrollPos(lParam, 0);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_BOTTOM:
					*&Paint.rgbReserved[24] = *&Paint.rgbReserved[16];
					CTreeList::SetHScrollPos(lParam, *&Paint.rgbReserved[16]);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				case SB_ENDSCROLL:
					return 1;
				default:
					return 0;
				}
				return 0;
			}
		LABEL_82:
			if (Msg == WM_THEMECHANGED)
			{
				if (this->baseclass.m_hThemeHandle)
					gpfnCloseThemeData(this->baseclass.m_hThemeHandle);
				this->baseclass.m_hThemeHandle = 0;
				if (gpfnIsThemeActive && gpfnIsThemeActive())
				{
					v47 = (this->GetName)(this);
					this->baseclass.m_hThemeHandle = gpfnOpenThemeData(hWnd, v47);
				}
			}
		LABEL_88:
			lParam = lParam;
			return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
		}
		if (Msg == WM_LBUTTONDOWN)
			goto LABEL_9;
	LABEL_209:
		if (Msg - 515 <= 1)
		{
			Rect.bottom = 0;
			lpchText.m_Data = 0;
			ho = 0;
			if (CTreeList::Query(this, lParam, SHIWORD(lParam), &Rect.bottom, &lpchText, &ho) & (TVIF_INTEGRAL | TVIF_CHILDREN | TVIF_SELECTEDIMAGE))
			{
				v83 = ho;
				sub_42F090(this, ho);
				v87 = v83;
				v86 = lpchText.m_Data;
				v85 = 2 * (Msg == WM_LBUTTONDBLCLK) - 5;
			LABEL_81:
				CTreeList::SendNotify(this, this->m_hWnd, v85, v86, v87, 0, 0);
			}
		}
		goto LABEL_82;
	}
	if (Msg == WM_KEYDOWN)
	{
		v17 = LOBYTE(this->m_ptDownLast.y) == 0;
		v54 = 2007;
		*&Paint.rgbReserved[12] = hWnd;
		if (!v17)
			v54 = -155;
		*&Paint.rgbReserved[20] = v54;
		v55 = GetWindowLongW(hWnd, -12);
		*&Paint.rgbReserved[24] = wParam;
		v56 = v55;
		*&Paint.rgbReserved[16] = v55;
		*&Paint.rgbReserved[26] = 0;
		v57 = GetParent(hWnd);
		SendMessageW(v57, 0x4Eu, v56, &Paint.rgbReserved[12]);
		switch (wParam)
		{
		case VK_PRIOR:
		case VK_NEXT:
			pChildItem = this->m_ChildLast;
			if (!pChildItem)
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			*&Paint.rgbReserved[4] = 28;
			v63 = this->m_hWndScrollBarRightRight;
			*&Paint.rgbReserved[28] = 0;
			_mm_storeu_si128(&Paint.rgbReserved[12], 0i64);
			*&Paint.rgbReserved[8] = 2;
			GetScrollInfo(v63, 2, &Paint.rgbReserved[4]);
			ho = 0;
			if (!*&Paint.rgbReserved[20])
				goto LABEL_149;
			v64 = pChildItem;
			break;
		case VK_LEFT:
		case VK_RIGHT:
			v68 = this->m_ChildLast;
			if (!v68)
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			v69 = v68->m_dwStyle;
			v70 = v68->m_dwStyle;
			if (wParam == 39)
			{
				if (!((v70 >> 6) & 1))
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				if (!((v69 >> 4) & 1))
				{
					sub_42BF00(this, v68, 1);
					return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
				}
				return CTreeList::TreeWndProc(this, hWnd, 0x100u, 0x28u, 0);
			}
			if ((v70 >> 4) & 1 && (v69 >> 6) & 1)
			{
				sub_42BF00(this, v68, 0);
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			}
			v71 = v68->m_Current;
			pItem = v71;
			if (v71 && v71 != &this->field_40)
			{
				v72 = CTreeList::FindChild(this, v68);
				sub_42F090(this, pItem);
				sub_42BE30(this, v72);
				goto LABEL_88;
			}
			return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
		case VK_UP:
		case VK_DOWN:
			v60 = this->m_ChildLast;
			if (!v60)
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			v61 = (wParam == 40 ? sub_42E650(v60) : sub_42E9D0(v60));
			ho = v61;
			if (!v61)
				return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
			v62 = CTreeList::FindChild(this, v61);
			sub_42F090(this, ho);
			sub_42BE30(this, v62);
			goto LABEL_88;
		case VK_ADD:
			if (GetKeyState(VK_LCONTROL))
			{
				if (SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1 > 0)
				{
					v58 = 0;
					do
					{
						if (v58 || !this->field_9C)
							v59 = CTreeList::GetChildWidth(this, v58);
						else
							v59 = this->field_98;
						sub_42F110(v58++, v59);
					} while (v58 < SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1);
					lParam = lParam;
				}
				sub_42EF00(this);
			}
			return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
		default:
			return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
		}
		do
		{
			if (wParam == VK_NEXT)
			{
				v65 = sub_42E650(v64);
				if (!v65)
					break;
				v64 = v65;
				pChildItem = v65;
			}
			else
			{
				v66 = sub_42E9D0(v64);
				if (!v66)
					break;
				v64 = v66;
				pChildItem = v66;
			}
			ho = ho + 1;
		} while (ho < *&Paint.rgbReserved[20]);
		lParam = lParam;
	LABEL_149:
		if (!pChildItem)
			return (this->HandleMessage)(this, hWnd, Msg, wParam, lParam);
		v67 = CTreeList::FindChild(this, pChildItem);
		sub_42F090(this, pChildItem);
		sub_42BE30(this, v67);
		goto LABEL_88;
	}
	switch (Msg)
	{
	case WM_DESTROY:
		sub_42A620(this);
		goto LABEL_82;
	case WM_SIZE:
		sub_42EF00(this);
		sub_42EFD0();
		sub_42EC50();
		v31 = this->m_hWnd;
		Paint.rcPaint.right = 48;
		_mm_storeu_si128(&Paint.fRestore, 0i64);
		Paint.rcPaint.bottom = 0;
		_mm_storeu_si128(&Paint.rgbReserved[8], 0i64);
		Paint.fRestore = v31;
		*&Paint.rgbReserved[24] = 0i64;
		GetClientRect(v31, Paint.rgbReserved);
		SendMessageW(this->m_hWndTooltipOfTreeList, 0x434u, 0, &Paint.rcPaint.right);
		goto LABEL_82;
	case WM_SETCURSOR:
	case WM_KILLFOCUS:
		if (this->m_ChildLast)
			sub_42EAD0(this, this->m_ChildLast);
		goto LABEL_82;
	case WM_SETREDRAW:
		if (wParam)
		{
			v23 = DefWindowProcW(hWnd, Msg, wParam, lParam);
			this->m_bSkipTimerForTooltip = 0;
			v24 = v23;
			sub_42EA10(this);
			result = v24;
		}
		else
		{
			this->m_bSkipTimerForTooltip = 1;
			result = DefWindowProcW(hWnd, Msg, 0, lParam);
		}
		return result;
	case WM_PAINT:
		v29 = CreateRectRgn(0, 0, 0, 0);
		v30 = hWnd;
		ho = v29;
		if (GetUpdateRgn(hWnd, v29, 0) != 1)
		{
			BeginPaint(v30, &Paint);
			sub_42AEC0(this, &Paint.hdc, ho);
			EndPaint(v30, &Paint);
		}
		DeleteObject(ho);
		return 0;
	case WM_ERASEBKGND:
		return 1;
	case WM_SETCURSOR:
		if (wParam != hWnd)
			goto LABEL_82;
		return 1;
	case WM_SETFONT:
		v25 = wParam;
		this->m_Font = wParam;
		v26 = lParam != 0;
		v27 = this->m_hWndHeaderLeft;
		v93 = lParam != 0;
		SendMessageW(v27, 0x30u, v25, v26);
		SendMessageW(this->m_hWndHeaderRight, 0x30u, this->m_Font, v26);
		SendMessageW(this->m_hWndTooltipOfTreeList, 0x30u, this->m_Font, v26);
		SendMessageW(this->m_hWndTooltipOfLeftHeader, 0x30u, this->m_Font, v26);
		SendMessageW(this->m_hWndTooltipOfRightHeader, 0x30u, this->m_Font, v26);
		GetClientRect(this->m_hWnd, &Paint.rgbReserved[16]);
		v100 = 0;
		v89 = &Paint.rgbReserved[16];
		*cy = 0i64;
		pItem = &v100;
		v28 = this->m_hWndHeaderLeft;
		_mm_storeu_si128(hWndInsertAfter, 0i64);
		SendMessageW(v28, 0x1205u, 0, &v89);
		SetWindowPos(
			this->m_hWndHeaderLeft,
			hWndInsertAfter[0],
			0,
			0,
			this->m_nBottomScrollBarWidthOrHeight,
			cy[0],
			cy[1] | 0x40);
		SetWindowPos(
			this->m_hWndHeaderRight,
			this->m_hWndHeaderLeft,
			this->m_nBottomScrollBarWidthOrHeight,
			0,
			hWndInsertAfter[3] - this->m_nBottomScrollBarWidthOrHeight,
			cy[0],
			cy[1] | 0x40);
		if (!v93)
			return 0;
		sub_42EA10(this);
		return 0;
	case WM_NOTIFY:
		if (*lParam != this->m_hWndTooltipOfTreeList)
			goto LABEL_69;
		v32 = *(lParam + 8);
		if (v32 == TTN_GETDISPINFOW)
		{
			if (this->m_point.y)
			{
				pChildItem = (lParam + 12);
				*(lParam + 12) = lParam + 16;
				v33 = this->m_point.y;
				ho = (lParam + 16);
				if (CTreeList::SendNotify(this, this->m_hWnd, 2004, this->m_nHeaderItemCount, v33, 0, lParam + 12))
					return 0;
				v34 = this->m_point.y;
				pItem = 80;
				lpchText.m_Data = (*(**(v34 + 4) + 8))(v34, this->m_nHeaderItemCount, ho, &pItem);
				hWndInsertAfter[2] = 0;
				hWndInsertAfter[3] = 0;
				cy[0] = GetSystemMetrics(78);
				cy[1] = CTreeList::GetLineHeight(this);
				sub_42C210(this->m_point.x, this->m_nHeaderItemCount, 1, 1, this->m_point.y, &prcScroll);
				*&Paint.rgbReserved[4] = 28;
				v35 = this->m_hWndScrollBarRightBottom;
				*&Paint.rgbReserved[28] = 0;
				_mm_storeu_si128(&Paint.rgbReserved[12], 0i64);
				*&Paint.rgbReserved[8] = 4;
				GetScrollInfo(v35, 2, &Paint.rgbReserved[4]);
				if (prcScroll.left == this->m_nBottomScrollBarWidthOrHeight)
				{
					if (*&Paint.rgbReserved[24])
						return 0;
				}
				v36 = this->m_hWnd;
				pChild = (this->m_Format & 0xFFFB3FFF | 0x400);
				v37 = GetDC(v36);
				v38 = this->m_Font;
				ho = v37;
				v39 = SelectObject(v37, v38);
				DrawTextW(ho, lpchText.m_Data, -1, &hWndInsertAfter[2], pChild);
				v40 = v39;
				v41 = ho;
				SelectObject(ho, v40);
				ReleaseDC(this->m_hWnd, v41);
				v42 = &gszNullString;
				lParam = lParam;
				if ((cy[0] - hWndInsertAfter[2]) > prcScroll.right - prcScroll.left)
					v42 = lpchText.m_Data;
				*pChildItem = v42;
			}
			else
			{
				*(lParam + 12) = &gszNullString;
			}
		}
		else if (v32 == TTN_SHOW)
		{
			sub_42C210(this->m_point.x, this->m_nHeaderItemCount, 0, 1, this->m_point.y, &hWndInsertAfter[2]);
			SendMessageW(this->m_hWndTooltipOfTreeList, 0x41Fu, 1u, &hWndInsertAfter[2]);
			MapWindowPoints(this->m_hWnd, 0, &hWndInsertAfter[2], 2u);
			SetWindowPos(this->m_hWndTooltipOfTreeList, 0, hWndInsertAfter[2], hWndInsertAfter[3], 0, 0, 0x15u);
			SendMessageW(this->m_hWndTooltipOfTreeList, 0x30u, this->m_Font, 0);
			CTreeList::SendNotify(
				this,
				this->m_hWndTooltipOfTreeList,
				2005,
				this->m_nHeaderItemCount,
				this->m_point.y,
				0,
				0);
			return 1;
		}
	LABEL_69:
		v43 = *lParam;
		v44 = this->m_hWndHeaderLeft;
		if (*lParam != v44 && v43 != this->m_hWndHeaderRight)
			goto LABEL_82;
		v45 = lParam[2];
		if (v45 > 0xFFFFFEC0)
		{
			if (v45 == -311)
			{
				InvalidateRect(this->m_hWnd, 0, 0);
				return 0;
			}
			if (v45 == -5)
				CTreeList::SendNotify(this, v43, -5, 0, 0, 0, 0);
			goto LABEL_82;
		}
		if (v45 != -320)
		{
			switch (v45)
			{
			case 0xFFFFFEBB:
				v48 = v43 == this->m_hWndHeaderRight;
				v17 = (lParam[3] + v48) == 0;
				v49 = lParam[3] + v48;
				ho = v49;
				if (v17 && this->field_9C)
				{
					v50 = this->field_98;
				}
				else
				{
					v50 = CTreeList::GetChildWidth(this, v49);
					v49 = ho;
				}
				sub_42F110(v49, v50);
				if (!ho)
					CTreeList::MoveHeaders(this, v50);
				sub_42EF00(this);
				break;
			case 0xFFFFFEBE:
				if (v43 == v44)
					v46 = 0;
				else
					v46 = lParam[3] + 1;
				v87 = 0;
				v86 = v46;
				v85 = 2003;
				goto LABEL_81;
			case 0xFFFFFEBF:
				sub_42EF00(this);
				break;
			}
			goto LABEL_82;
		}
		v51 = lParam[5];
		if (!(*v51 & 1))
			goto LABEL_82;
		v52 = lParam[3];
		if (!v52 && *(v51 + 1) < this->field_94)
			return 1;
		pItem = (v52 + (v43 == this->m_hWndHeaderRight));
		CTreeList::MapToHeader(this, pItem, &hWndInsertAfter[2]);
		GetClientRect(this->m_hWnd, &Paint.rgbReserved[16]);
		ho = hWndInsertAfter[2] + *(lParam[5] + 1) - cy[0];
		if (!ho)
			return 0;
		v53 = pItem;
		prcScroll.top = cy[1];
		prcScroll.right = *&Paint.rgbReserved[24];
		prcScroll.left = cy[0];
		prcScroll.bottom = *&Paint.rgbReserved[28];
		if (!pItem)
			prcScroll.left = cy[0] - 1;
		if ((GetWindowLongW(this->m_hWndScrollBarRightRight, -16) >> 28) & 1)
			prcScroll.right -= GetSystemMetrics(2);
		ScrollWindowEx(this->m_hWnd, ho, 0, &prcScroll, 0, 0, 0, 2u);
		if ((v53 || !this->field_9C)
			&& (Rect.left = hWndInsertAfter[2],
				Rect.top = cy[1],
				Rect.right = cy[0],
				Rect.bottom = *&Paint.rgbReserved[28],
				InvalidateRect(this->m_hWnd, &Rect, 0),
				v53))
		{
			sub_42EF00(this);
			UpdateWindow(this->m_hWndScrollBarRightBottom);
			result = 0;
		}
		else
		{
			CTreeList::MoveHeaders(this, ho + cy[0]);
			sub_42EF00(this);
			sub_42EFD0();
			UpdateWindow(this->m_hWndHeaderRight);
			UpdateWindow(this->m_hWndScrollBarLeftBottom);
			UpdateWindow(this->m_hWndScrollBarRightBottom);
			result = 0;
		}
		break;
	case WM_NCDESTROY:
		if (this->m_ImageList && !LOBYTE(this->m_NotMyImageList))
			ImageList_Destroy(this->m_ImageList);
		SetPropW(hWnd, MAKE, 0);
		delete this;
		return DefWindowProcW(hWnd, Msg, wParam, lParam);
	case WM_GETDLGCODE:
		return (DefWindowProcW(hWnd, Msg, wParam, lParam) | 1);
	default:
		goto LABEL_82;
	}
	return result;
}


