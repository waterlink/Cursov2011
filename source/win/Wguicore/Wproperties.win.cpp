//	
//	Author: Fedorov Alexey
//	Type: Open-Source Project
//	Platform: Linux and Windows
//	Codename: Project Santiago
//	
//	Designer of the robot behavior
//	
//	sharp-end must not to be deleted
//	

//
//	source file
//	gui class properties for winapi
//

#include "Wproperties.win.hpp"

#include "../main/mainclass.win.hpp"
#include "Wclient.win.hpp"
#include "idmaster.win.hpp"
#include "hwndmaster.win.hpp"
#include "../../all/utilcore/stringtokenizer.all.hpp"

#include <winuser.h>
#include <commctrl.h>
#include <windowsx.h>

#include <cstring>

Wproperties::Wproperties(string name, Wform * parent){

// TODO: code this up to work with vertical scrolling

	maxnum = 0;

	myWform = new Wform();

	this->name = name;

	HWND hWnd; 
	WNDCLASS WndClass; 
	HINSTANCE hInst = mainclass::getInst();

	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	WndClass.lpfnWndProc = (WNDPROC)wndproc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInst;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = /*(HBRUSH)GetStockObject(WHITE_BRUSH)*/ (HBRUSH)(COLOR_BTNFACE + 1);
	WndClass.lpszMenuName = "";
	WndClass.lpszClassName = name.c_str();

	if(!RegisterClass(&WndClass)){

		MessageBox(NULL,"Cannot register class","Error",MB_OK);
		return;

	}

	hWnd = CreateWindowEx(0, name.c_str(), name.c_str(),
				WS_OVERLAPPEDWINDOW | WS_CHILD | WS_VISIBLE, 
				0, 0,
				0, 0,
				parent->gethandle(),
				(HMENU)idmaster::gen(this),
				hInst,
				NULL
			);

	if(!hWnd){

		MessageBox(NULL, "Cannot create property window", "Error", MB_OK);
		return;

	}

	RECT RclParent;

	int iHThumb = GetSystemMetrics(SM_CXHTHUMB);
	int iVThumb = GetSystemMetrics(SM_CYVTHUMB);

	/*hWndVertScroll = CreateWindow(
					"scrollbar",
					0,
					WS_CHILD | WS_VISIBLE | SBS_VERT | SBS_RIGHTALIGN,
					0, 0, 0, 0,
					hWnd,
					NULL,
					hInst,
					NULL
				);

	SetScrollRange(hWndVertScroll, SB_CTL, 0, 10, FALSE);
	currpos = 0;*/

	sethandle(hWnd);
	hwndmaster::newform(hwnd, (Wform *)this);

}
Wproperties::Wproperties(){ maxnum = 0; }
Wproperties::~Wproperties(){}

bool Wproperties::addproperty(string name, string value, string type){

	if (type == "bool"){

		int num = maxnum++;

		props[name] = make_pair(type, value);
		nums[name] = num;

		handles[name] = CreateWindow(
				"button",
				name.c_str(),
				WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
				5, 25 * num,
				getsize().first - 10, 22,
				hwnd,
				NULL,
				mainclass::getInst(),
				NULL
			);

		SetWindowText(handles[name], name.c_str());
		if (value == "true")
			Button_SetCheck(handles[name], BST_CHECKED);
		else Button_SetCheck(handles[name], BST_UNCHECKED);

		return true;

	}
	else if (type == "string" || type == "int"){

		fprintf(stderr, "Wguicore--Wproperties::addproperty::debug: here!\n");

		int num = maxnum++;

		props[name] = make_pair(type, value);
		nums[name] = num;
		
		handles[name + "___value"] = CreateWindow(
							"edit", 0,
							WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
							50, 25 * num, getsize().first - 55, 22,
							hwnd, 0,
							mainclass::getInst(), 0
						);
		handles[name + "___caption"] = CreateWindow(
							"static", name.c_str(),
							WS_CHILD | WS_VISIBLE,
							5, 25 * num, 48, 22,
							hwnd, 0,
							mainclass::getInst(), 0
						);
		fprintf(stderr, "Wguicore--Wproperties::addproperty::debug: handle: %d\n", handles[name + "___value"]);
		char buf[100];
		strcpy(buf, value.c_str());
		//SendMessage(handles[name + "___value"], WM_SETTEXT, 0, (LPARAM)buf);
		//SetWindowText(handles[name + "___value"], value.c_str());

		fprintf(stderr, "Wguicore--Wproperties::addproperty::debug: here!\n");
		return true;

	}

	return false;

}
string Wproperties::getproperty(string name){

	string type = props[name].first;
	char buf[110];
	if (type == "bool"){

		GetWindowText(handles[name], buf, 100);

	}
	else if (type == "string" || type == "int"){

		GetWindowText(handles[name + "___value"], buf, 100);

	}
	else return "";

	string res = buf;
	return res;

}
bool Wproperties::delproperty(string name){

	// TODO: code this up (when it'll really need, it will be soon)s

}

// form methods
void Wproperties::show(){ myWform->show(); }
void Wproperties::close(){ myWform->close(); }
void Wproperties::add(component * control){ myWform->add(control); }
void Wproperties::del(string name){ myWform->del(name); }
component * Wproperties::getcomponent(string name){ return myWform->getcomponent(name); }

// component methods
int Wproperties::dispatch(string message){

#define clean \
		delete token; \
		return 0;

// TODO: here again

	tokenizer * token = new stringtokenizer(&message);

	if (token->getparam("message") == "vertscroll"){

		/*int pos = token->getparam("position", 0);
		int dpos = pos - currpos;
		ScrollWindow(hwnd, 0, dpos * getsize().second / 2, 0, 0);
		SetScrollPos(hwnd, SB_HORZ, pos, true);
		UpdateWindow(hwnd);*/

	}

	clean;

#undef clean

}
void Wproperties::setparent(component * parent){ myWform->setparent(parent); }
component * Wproperties::getparent(){ return myWform->getparent(); }
string Wproperties::getname(){ return name; }

// sizeble methods
pair < int, int > Wproperties::getsize(){ return myWform->getsize(); }
pair < int, int > Wproperties::getposition(){ return myWform->getposition(); }
void Wproperties::setsize(int w, int h){ 

// and possibly TODO here

	myWform->setsize(w, h);
	//int iVThumb = GetSystemMetrics(SM_CYVTHUMB);
	//MoveWindow(hWndVertScroll, w - iVThumb, 0, w, h, true);

}
void Wproperties::setposition(int x, int y){ myWform->setposition(x, y); }

// winapi-sensitive
HWND Wproperties::gethandle(){ return hwnd; }
void Wproperties::sethandle(HWND handle){ hwnd = handle; myWform->sethandle(hwnd); }

//#end
