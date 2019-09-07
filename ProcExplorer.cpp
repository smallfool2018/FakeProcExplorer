// ProcExplorer.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "ProcExplorer.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


LPFN_GetVersion gpfnGetVersion = NULL;
LPFN_SHAutoComplete gpfnSHAutoComplete = NULL;

typedef 
WINBASEAPI
VOID (WINAPI *LPFN_GetNativeSystemInfo)(
	_Out_ LPSYSTEM_INFO lpSystemInfo
);


HINSTANCE		ghMainInstance = NULL;
WCHAR*			gszNullString = NULL;

static inline uint16_t byteswap_ushort(uint16_t number)
{
#if defined(_MSC_VER) && _MSC_VER > 1310
	return _byteswap_ushort(number);
#elif defined(__GNUC__)
	return __builtin_bswap16(number);
#else
	return (number >> 8) | (number << 8);
#endif
}

//#include "utfconvert.h"

//#include <stdint.h>
//#ifdef __GNUC__
//#include <endian.h>
//#endif // __GNUC__

//static inline uint16_t byteswap_ushort(uint16_t number)
//{
//#if defined(_MSC_VER) && _MSC_VER > 1310
//	return _byteswap_ushort(number);
//#elif defined(__GNUC__)
//	return __builtin_bswap16(number);
//#else
//	return (number >> 8) | (number << 8);
//#endif
//}


////////////////////////////////////////
//     以下转换都是在小端序下进行     //
////////////////////////////////////////



// 从UTF16 LE编码的字符串创建
std::string utf16le_to_utf8(const std::u16string& u16str)
{
	if (u16str.empty()) { return std::string(); }
	const char16_t* p = u16str.data();
	std::u16string::size_type len = u16str.length();
	if (p[0] == 0xFEFF) {
		p += 1; //带有bom标记，后移
		len -= 1;
	}

	// 开始转换
	std::string u8str;
	u8str.reserve(len * 3);

	char16_t u16char;
	for (std::u16string::size_type i = 0; i < len; ++i) {
		// 这里假设是在小端序下(大端序不适用)
		u16char = p[i];

		// 1字节表示部分
		if (u16char < 0x0080) {
			// u16char <= 0x007f
			// U- 0000 0000 ~ 0000 07ff : 0xxx xxxx
			u8str.push_back((char)(u16char & 0x00FF));  // 取低8bit
			continue;
		}
		// 2 字节能表示部分
		if (u16char >= 0x0080 && u16char <= 0x07FF) {
			// * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
			u8str.push_back((char)(((u16char >> 6) & 0x1F) | 0xC0));
			u8str.push_back((char)((u16char & 0x3F) | 0x80));
			continue;
		}
		// 代理项对部分(4字节表示)
		if (u16char >= 0xD800 && u16char <= 0xDBFF) {
			// * U-00010000 - U-001FFFFF: 1111 0xxx 10xxxxxx 10xxxxxx 10xxxxxx
			uint32_t highSur = u16char;
			uint32_t lowSur = p[++i];
			// 从代理项对到UNICODE代码点转换
			// 1、从高代理项减去0xD800，获取有效10bit
			// 2、从低代理项减去0xDC00，获取有效10bit
			// 3、加上0x10000，获取UNICODE代码点值
			uint32_t codePoint = highSur - 0xD800;
			codePoint <<= 10;
			codePoint |= lowSur - 0xDC00;
			codePoint += 0x10000;
			// 转为4字节UTF8编码表示
			u8str.push_back((char)((codePoint >> 18) | 0xF0));
			u8str.push_back((char)(((codePoint >> 12) & 0x3F) | 0x80));
			u8str.push_back((char)(((codePoint >> 06) & 0x3F) | 0x80));
			u8str.push_back((char)((codePoint & 0x3F) | 0x80));
			continue;
		}
		// 3 字节表示部分
		{
			// * U-0000E000 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx
			u8str.push_back((char)(((u16char >> 12) & 0x0F) | 0xE0));
			u8str.push_back((char)(((u16char >> 6) & 0x3F) | 0x80));
			u8str.push_back((char)((u16char & 0x3F) | 0x80));
			continue;
		}
	}

	return u8str;
}


// 从UTF16BE编码字符串创建
std::string utf16be_to_utf8(const std::u16string& u16str)
{
	if (u16str.empty()) { return std::string(); }
	const char16_t* p = u16str.data();
	std::u16string::size_type len = u16str.length();
	if (p[0] == 0xFEFF) {
		p += 1; //带有bom标记，后移
		len -= 1;
	}


	// 开始转换
	std::string u8str;
	u8str.reserve(len * 2);
	char16_t u16char;   //u16le 低字节存低位，高字节存高位
	for (std::u16string::size_type i = 0; i < len; ++i) {
		// 这里假设是在小端序下(大端序不适用)
		u16char = p[i];
		// 将大端序转为小端序
		u16char = byteswap_ushort(u16char);

		// 1字节表示部分
		if (u16char < 0x0080) {
			// u16char <= 0x007f
			// U- 0000 0000 ~ 0000 07ff : 0xxx xxxx
			u8str.push_back((char)(u16char & 0x00FF));
			continue;
		}
		// 2 字节能表示部分
		if (u16char >= 0x0080 && u16char <= 0x07FF) {
			// * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
			u8str.push_back((char)(((u16char >> 6) & 0x1F) | 0xC0));
			u8str.push_back((char)((u16char & 0x3F) | 0x80));
			continue;
		}
		// 代理项对部分(4字节表示)
		if (u16char >= 0xD800 && u16char <= 0xDBFF) {
			// * U-00010000 - U-001FFFFF: 1111 0xxx 10xxxxxx 10xxxxxx 10xxxxxx
			uint32_t highSur = u16char;
			uint32_t lowSur = byteswap_ushort(p[++i]);
			// 从代理项对到UNICODE代码点转换
			// 1、从高代理项减去0xD800，获取有效10bit
			// 2、从低代理项减去0xDC00，获取有效10bit
			// 3、加上0x10000，获取UNICODE代码点值
			uint32_t codePoint = highSur - 0xD800;
			codePoint <<= 10;
			codePoint |= lowSur - 0xDC00;
			codePoint += 0x10000;
			// 转为4字节UTF8编码表示
			u8str.push_back((char)((codePoint >> 18) | 0xF0));
			u8str.push_back((char)(((codePoint >> 12) & 0x3F) | 0x80));
			u8str.push_back((char)(((codePoint >> 06) & 0x3F) | 0x80));
			u8str.push_back((char)((codePoint & 0x3F) | 0x80));
			continue;
		}
		// 3 字节表示部分
		{
			// * U-0000E000 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx
			u8str.push_back((char)(((u16char >> 12) & 0x0F) | 0xE0));
			u8str.push_back((char)(((u16char >> 6) & 0x3F) | 0x80));
			u8str.push_back((char)((u16char & 0x3F) | 0x80));
			continue;
		}
	}
	return u8str;
}






// 获取转换为UTF-16 LE编码的字符串
std::u16string utf8_to_utf16le(const std::string& u8str, bool addbom, bool* ok)
{
	std::u16string u16str;
	u16str.reserve(u8str.size());
	if (addbom) {
		u16str.push_back(0xFEFF);   //bom (字节表示为 FF FE)
	}
	std::string::size_type len = u8str.length();

	const unsigned char* p = (unsigned char*)(u8str.data());
	// 判断是否具有BOM(判断长度小于3字节的情况)
	if (len > 3 && p[0] == 0xEF && p[1] == 0xBB && p[2] == 0xBF) {
		p += 3;
		len -= 3;
	}

	bool is_ok = true;
	// 开始转换
	for (std::string::size_type i = 0; i < len; ++i) {
		uint32_t ch = p[i]; // 取出UTF8序列首字节
		if ((ch & 0x80) == 0) {
			// 最高位为0，只有1字节表示UNICODE代码点
			u16str.push_back((char16_t)ch);
			continue;
		}
		switch (ch & 0xF0)
		{
		case 0xF0: // 4 字节字符, 0x10000 到 0x10FFFF
		{
			uint32_t c2 = p[++i];
			uint32_t c3 = p[++i];
			uint32_t c4 = p[++i];
			// 计算UNICODE代码点值(第一个字节取低3bit，其余取6bit)
			uint32_t codePoint = ((ch & 0x07U) << 18) | ((c2 & 0x3FU) << 12) | ((c3 & 0x3FU) << 6) | (c4 & 0x3FU);
			if (codePoint >= 0x10000)
			{
				// 在UTF-16中 U+10000 到 U+10FFFF 用两个16bit单元表示, 代理项对.
				// 1、将代码点减去0x10000(得到长度为20bit的值)
				// 2、high 代理项 是将那20bit中的高10bit加上0xD800(110110 00 00000000)
				// 3、low  代理项 是将那20bit中的低10bit加上0xDC00(110111 00 00000000)
				codePoint -= 0x10000;
				u16str.push_back((char16_t)((codePoint >> 10) | 0xD800U));
				u16str.push_back((char16_t)((codePoint & 0x03FFU) | 0xDC00U));
			}
			else
			{
				// 在UTF-16中 U+0000 到 U+D7FF 以及 U+E000 到 U+FFFF 与Unicode代码点值相同.
				// U+D800 到 U+DFFF 是无效字符, 为了简单起见，这里假设它不存在(如果有则不编码)
				u16str.push_back((char16_t)codePoint);
			}
		}
		break;
		case 0xE0: // 3 字节字符, 0x800 到 0xFFFF
		{
			uint32_t c2 = p[++i];
			uint32_t c3 = p[++i];
			// 计算UNICODE代码点值(第一个字节取低4bit，其余取6bit)
			uint32_t codePoint = ((ch & 0x0FU) << 12) | ((c2 & 0x3FU) << 6) | (c3 & 0x3FU);
			u16str.push_back((char16_t)codePoint);
		}
		break;
		case 0xD0: // 2 字节字符, 0x80 到 0x7FF
		case 0xC0:
		{
			uint32_t c2 = p[++i];
			// 计算UNICODE代码点值(第一个字节取低5bit，其余取6bit)
			uint32_t codePoint = ((ch & 0x1FU) << 12) | ((c2 & 0x3FU) << 6);
			u16str.push_back((char16_t)codePoint);
		}
		break;
		default:    // 单字节部分(前面已经处理，所以不应该进来)
			is_ok = false;
			break;
		}
	}
	if (ok != NULL) { *ok = is_ok; }

	return u16str;
}


// 获取转换为UTF-16 BE的字符串
std::u16string utf8_to_utf16be(const std::string& u8str, bool addbom, bool* ok)
{
	// 先获取utf16le编码字符串
	std::u16string u16str = utf8_to_utf16le(u8str, addbom, ok);
	// 将小端序转换为大端序
	for (size_t i = 0; i < u16str.size(); ++i) {
		u16str[i] = byteswap_ushort(u16str[i]);
	}
	return u16str;
}

// 从UTF16编码字符串构建，需要带BOM标记
std::string utf16_to_utf8(const std::u16string& u16str)
{
	if (u16str.empty()) { return std::string(); }
	//Byte Order Mark
	char16_t bom = u16str[0];
	switch (bom) {
	case 0xFEFF:    //Little Endian
		return utf16le_to_utf8(u16str);
		break;
	case 0xFFFE:    //Big Endian
		return utf16be_to_utf8(u16str);
		break;
	default:
		return std::string();
	}
}

// 从UTF16编码字符串构建，需要带BOM标记
////std::string utf16_to_utf8(const std::u16string& u16str)
////{
////	if (u16str.empty()) { return std::string(); }
////	//Byte Order Mark
////	char16_t bom = u16str[0];
////	switch (bom) {
////	case 0xFEFF:    //Little Endian
////		return utf16le_to_utf8(u16str);
////		break;
////	case 0xFFFE:    //Big Endian
////		return utf16be_to_utf8(u16str);
////		break;
////	default:
////		return std::string();
////	}
////}



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	//QueryTagInformation(NULL, NULL, NULL, NULL);

	//DWORD dwValue111 = 0x200001;
	//WORD w = LOWORD(dwValue111);///0x0001
	//WORD h = HIWORD(dwValue111);///0x0020

	InitSystemPath();

	extern void LoadSystemAccountInfo(HWND hWnd);
	LoadSystemAccountInfo(NULL);

	BITMAPINFO bi = { sizeof(bi) };

	*(DWORD*)&bi.bmiHeader.biPlanes = 0x200001;

	static int gIntArray[] = { 1,2,3,4 };
	int arrIDs[96] = { 0 };
	int nIndex = 0;

	////{
	////	static int gIntArray[] = { 1,2,3,4 };
	////	int arrIDs[96] = { 0 };
	////	int nIndex = 0;
	////	//if (pUserData >= 8)
	////	{
	////		__m128i v36 = _mm_load_si128((__m128i*)&gIntArray);
	////		__m128i* v37 = (__m128i*)&arrIDs[4];
	////		do
	////		{
	////			int v38 = nIndex + 4;
	////			v37 += 8;
	////			__m128i v39 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(nIndex), 0), v36);
	////			nIndex += 8;
	////			_mm_storeu_si128(v37 - 3, v39);
	////			_mm_storeu_si128(v37 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v38), 0), v36));
	////		} while (nIndex < 96);
	////	}
	////	//for (; nIndex < pUserData; ++nIndex)
	////	//	arrIDs[nIndex] = nIndex;
	////}
	CString str ( "I am smallfool" );

	//DWORD dwSize = sizeof(DLGTEMPLATE);
	PMIB_TCPTABLE pTcpTable;
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;
	pTcpTable = (MIB_TCPTABLE *)malloc(sizeof(MIB_TCPTABLE));
	if (pTcpTable == NULL) {
		return 1;
	}

	dwSize = sizeof(MIB_TCPTABLE);
	// Make an initial call to GetTcpTable to
	// get the necessary size into the dwSize variable
	if ((dwRetVal = GetTcpTable(pTcpTable, &dwSize, TRUE)) ==
		ERROR_INSUFFICIENT_BUFFER) {
		free(pTcpTable);
		pTcpTable = (MIB_TCPTABLE *)malloc(dwSize);
		if (pTcpTable == NULL) {
			printf("Error allocating memory\n");
			return 1;
		}
	}
	// Mak


	/*DWORD dwValue[2] = { 0x450050 , 0x460052 };
	WCHAR* psz = (WCHAR*)dwValue;*/
	//DWORD
	//	AllocateAndGetTcpExTableFromStack(
	//		PVOID *ppTcpTable,BOOL bOrder,HANDLE hHeap,DWORD dwFlags,DWORD dwFamily
	//	);

	_bstr_t strName("test");
	_bstr_t strIsOK("OK");

	_bstr_t strKKK = strName;
	strKKK += strIsOK;

	_bstr_t strURL(L"http://www.baidu.com");

	_bstr_t str2 = strKKK + strURL;

	///AllocateAndGetTcpExTable2FromStack();
	///AllocateAndGetTcpExTable2FromStack

    // TODO: 在此放置代码。
	/*DRIVER_ACTION_VERIFY;*/

	//TOKEN_PRIVILEGES* pTokenPrivileges = (TOKEN_PRIVILEGES*)malloc(1000);
	//pTokenPrivileges->PrivilegeCount = 0;
	//__asm
	//{
	//	mov		edi, pTokenPrivileges
	//	mov		ecx, [edi]
	//	lea		eax, [ecx+ecx*2]
	//	lea     edx, [edi + eax * 4]
	//	lea     eax, [ecx + 1]
	//	mov     ecx, [ebp + pTokenPivileges]
	//	mov		[edi], eax
	//}
	////HANDLE TokenHandle = NULL;
	////OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &TokenHandle);

	////HANDLE hToken = GetUserToken(TokenHandle);
	////CloseHandle(TokenHandle);

	////SaveCmdLineToMRUList(L"d:\\smallfool\\test.exe");

	///CHAR by[] = { 0x48, 0x89, 0x5c , 0x24 , 0x08 , 0x48 , 0x89 , 0x74 , 0x24 , 0x10 , 0x57 , 0x48 , 0x83 , 0xec , 0x20 , 0x48 , 0x63 , 0xd9 , 0x83 , 0xfb , 0x15 , 0x0f , 0x87 , 0xf0 , 0xd4 , 0x01 , 0x00 };
	////WCHAR* pszText = (WCHAR*)by;

	////WCHAR szBuffer[260] = { 0 };
	////MultiByteToWideChar(CP_ACP, 0, (CHAR*)by, sizeof(by), szBuffer, 260);

	extern WCHAR** sub_404FB0(WCHAR **ppszArgs, HWND hWndIn, LPCWSTR lpszFileName);

	WCHAR* pTest = NULL;
	sub_404FB0(&pTest, NULL, L"d:\\msdia80.dll");

	HMODULE hModuleKernel32 = LoadLibrary(TEXT("Kernel32.dll"));
	LPFN_GetNativeSystemInfo pfnGetNativeSystemInfo =(LPFN_GetNativeSystemInfo) GetProcAddress(hModuleKernel32, "GetNativeSystemInfo");
	if (pfnGetNativeSystemInfo)
		pfnGetNativeSystemInfo(&gSystemInfo);
	else
		GetSystemInfo(&gSystemInfo);
#ifdef _M_IX64
	if (FakeIsWow64Process())
	{
		_beginthread((_beginthread_proc_type)LoadSharedMemory, 0, (void*)hInstance);
		if (LaunchProcExplorer64(TRUE, nCmdShow))
			return 0;

		MessageBox(NULL, _TEXT("Unable to extract 64-bit image. Run Process Explorer from a writeable directory."), _TEXT("Process Explorer"), MB_ICONERROR);
		return TRUE;
	}
#endif 

	gpfnGetVersion = (LPFN_GetVersion)::GetProcAddress(hModuleKernel32, "GetVersion");
	ATLASSERT(gpfnGetVersion != NULL);

	DWORD dwVersion = gpfnGetVersion();
	if (dwVersion >= 5)
	{
		gdwVersion = 0;
		if (dwVersion < 10)
		{
			if (dwVersion >= 6)
			{
				//操作系统平台
				DWORD dwPlatform = HIBYTE(dwVersion);
				if (dwPlatform)
				{
					if (dwPlatform == VER_NT_WORKSTATION)
						gdwVersion = 2;
					else
						gdwVersion = 3;
				}
				else
				{
					gdwVersion = 1;
				}
			}
		}
		else
		{
			gdwVersion = 4;
		}
	}

	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

	gszCmdLine = lpCmdLine;
	int nArg = 0;
	WCHAR* strText;
	int nCmd = 0;
	WCHAR* strCmdInfo[32] = { 0 };

	WCHAR* strNewCmd = NULL;
	strCmdInfo[0] = lpCmdLine;

	if (*lpCmdLine)
	{
		do 
		{
			WCHAR* strCmd = strCmdInfo[nCmd];
			int nIndex = 0;
			if (*strCmd)
			{
				int nChar = 0;
				do 
				{
					if (strCmd[nChar] == ' ')
						break;
					nChar = ++nIndex;
				} while (strCmd[nIndex]);

				if (nIndex)
					nArg = ++nCmd;
			}

			int nOffset = sizeof(WCHAR)*nIndex;
			WCHAR* strArgs = (&strText)[nCmd];
			if (!strArgs[nOffset])
				break;
			strArgs[nOffset] = 0;
			nCmd = nArg;
			strNewCmd = &(&strText)[nArg][nOffset + 1];
			strCmdInfo[nArg] = strNewCmd;

			if (nCmd == 32)
				break;

		} while (*strNewCmd);
	}
	
	//if (!ParseArguments(IDS_PROCEXPOLER, &nArg, (WCHAR**)&strCmdInfo))
	//{
	//	return TRUE;
	//}


	if (nArg <= 0)
	{
		MSG msg;
		if (!InitMainWnd(hInst, nCmdShow))
			return FALSE;

		/// 加入快捷键
		HACCEL hAccel = LoadAccelerators(hInst, MAKEINTRESOURCEW(IDC_PROCEXPLORER));// L"PROCEXPLORER");
		if (!GetMessageW(&msg, 0, 0, 0))
			return 0;

		HWND hWndThreadStack = NULL;
		///进入消息循环
		while (1)
		{
			if (ghWndThreadStack != NULL)
			{
				if (TranslateAccelerator(ghWndThreadStack, hAccel, &msg))
				{
					if (!GetMessage(&msg, 0, 0, 0))
						return	FALSE;
				}
				hWndThreadStack = ghWndThreadStack;
			}

			/// 
			if (!ghFindDlg || !IsDialogMessage(ghFindDlg, &msg))
			{
				hWndThreadStack = ghWndThreadStack;

				if ((!hWndThreadStack || !IsDialogMessage(hWndThreadStack, &msg))
					&& !TranslateAccelerator(ghMainWnd, hAccel, &msg))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			if (!GetMessage(&msg, 0, 0, 0))
				return	FALSE;
		}
	}

	return 0;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROCEXPLORER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROCEXPLORER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
