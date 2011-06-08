#pragma once

// Disable CRT secure warnings
#define _CRT_SECURE_NO_WARNINGS
#pragma once 

#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#include "ExceptionHeaders.h"
