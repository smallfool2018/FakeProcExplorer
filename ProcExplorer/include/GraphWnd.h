#ifndef __GRAPHWND_H__
#define __GRAPHWND_H__
#pragma once
class CGraphWnd
{
public:
	CGraphWnd();
	~CGraphWnd();

	static LRESULT CALLBACK GraphWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK ChartWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

};

#endif //__GRAPHWND_H__

