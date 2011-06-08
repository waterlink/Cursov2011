#pragma once

// Disable CRT secure warnings
//#define _CRT_SECURE_NO_WARNINGS
#pragma once 

/* (WINVER >= 0x0500 || _WIN32_WINDOWS >= 0x0410) */
#define WINVER 0x0501
#define _WIN32_WINDOWS 0x0411

#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#pragma comment(lib, "ws2_32.lib")

#include <commctrl.h>
//#pragma comment(lib,"comctl32.lib")
//#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define __ANSI
#ifdef __ANSI
#define wstring string
#define L(x) x
#define wchar_t char
#define wcscpy strcpy
#define wcscat strcat
#define mbstowcs(ws, cs, sz) strlen(strcpy(ws, cs))
#else
//#define wstring wstring
#define L(x) L##x
//#define wchar_t wchar_t
#endif

#include "ExceptionHeaders.h"

