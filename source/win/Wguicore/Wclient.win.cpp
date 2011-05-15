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
//	gui class client for winapi
//

#include "Wclient.win.hpp"

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Wform.win.hpp"
#include "idmaster.win.hpp"
#include "../../all/utilcore/stringtokenizer.all.hpp"
#include "hwndmaster.win.hpp"
#include "Wmenu.win.hpp"
#include "../main/mainclass.win.hpp"

#include "../../all/utilcore/logger.all.hpp"

#include <windows.h>

map < int, component * > test_pIC;
map < int, component * > * controlhandles;
Wform * currform;

int processmessage(
			Wclient *, 
			Wform *, 
			map < int, component * > *, 
			HACCEL,
			int & rescode 
		);
long WINAPI wndproc(HWND hWnd, UINT Message, UINT wParam, LONG lParam){

	// TODO: code this up!

#define clean \
		delete msgtoken; \
		return 0;

	string msg;
	char buff[30];
	tokenizer * msgtoken = new stringtokenizer(&msg);
	int x, y;

	currform = hwndmaster::byhandle(hWnd);
	if (currform == NULL) return DefWindowProc(hWnd, Message, wParam, lParam);

	switch (Message){

		case WM_VSCROLL:
			msgtoken->setparam("message", "vertscroll");
			msgtoken->setparam("position", HIWORD(wParam));
			currform->dispatch(msg);
			clean;

		case WM_SIZE:
			SendMessage(hWnd, WM_PAINT, NULL, NULL);
			msgtoken->setparam("message", "resize");
			msgtoken->setparam("width", LOWORD(lParam));
			msgtoken->setparam("height", HIWORD(lParam));
			currform->dispatch(msg);
			clean;

		case WM_COMMAND:
			if ((*controlhandles)[LOWORD(wParam)]){

				msgtoken->setparam("message", "activate");
				(*controlhandles)[LOWORD(wParam)]->dispatch(msg);

			}
			clean;

		case WM_PAINT:
			msgtoken->setparam("message", "paint");
			currform->dispatch(msg);
			clean;

		// mouse downs
		case WM_LBUTTONDOWN: msgtoken->setparam("button", "left"); goto dispdown;
		case WM_MBUTTONDOWN: msgtoken->setparam("button", "middle"); goto dispdown;
		case WM_RBUTTONDOWN: msgtoken->setparam("button", "right");
		dispdown: msgtoken->setparam("message", "mousedown"); goto disp;

		// mouse ups
		case WM_LBUTTONUP: msgtoken->setparam("button", "left"); goto dispup;
		case WM_MBUTTONUP: msgtoken->setparam("button", "middle"); goto dispup;
		case WM_RBUTTONUP: msgtoken->setparam("button", "right");
		dispup: msgtoken->setparam("message", "mouseup"); goto disp;

		// mouse dblcliks
		case WM_LBUTTONDBLCLK: msgtoken->setparam("button", "left"); goto dispdbl;
		case WM_MBUTTONDBLCLK: msgtoken->setparam("button", "middle"); goto dispdbl;
		case WM_RBUTTONDBLCLK: msgtoken->setparam("button", "right");
		dispdbl: msgtoken->setparam("message", "mousedown");
			 msgtoken->setparam("doubleclick", "true");

		disp:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			sprintf(buff, "%d", x);
			msgtoken->setparam("x", buff);
			sprintf(buff, "%d", y);
			msgtoken->setparam("y", buff);
			if (wParam & MK_SHIFT)
				msgtoken->setparam("shift", "true");
			else msgtoken->setparam("shift", "false");
			if (wParam & MK_CONTROL)
				msgtoken->setparam("control", "true");
			else msgtoken->setparam("control", "false");
			currform->dispatch(msg);
			clean;

		case WM_MOUSEMOVE:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			msgtoken->setparam("message", "mousemove");
			sprintf(buff, "%d", x);
			msgtoken->setparam("x", buff);
			sprintf(buff, "%d", y);
			msgtoken->setparam("y", buff);
			if (wParam & MK_SHIFT)
				msgtoken->setparam("shift", "true");
			else msgtoken->setparam("shift", "false");
			if (wParam & MK_CONTROL)
				msgtoken->setparam("control", "true");
			else msgtoken->setparam("control", "false");
			if (wParam & MK_LBUTTON)
				msgtoken->setparam("left", "true");
			else msgtoken->setparam("left", "false");
			if (wParam & MK_MBUTTON)
				msgtoken->setparam("middle", "true");
			else msgtoken->setparam("middle", "false");
			if (wParam & MK_RBUTTON)
				msgtoken->setparam("right", "true");
			else msgtoken->setparam("right", "false");
			currform->dispatch(msg);
			clean;

		case WM_MENUSELECT:
			msgtoken->setparam("message", "select");
			if ((*controlhandles)[LOWORD(wParam)])
				(*controlhandles)[LOWORD(wParam)]->dispatch(msg);
			clean;

		case WM_DESTROY: 
			PostQuitMessage(0);
			clean;

		default:
			delete msgtoken;
			return DefWindowProc(hWnd, Message, wParam, lParam);

	}

	delete msgtoken;
	return DefWindowProc(hWnd, Message, wParam, lParam);

#undef clean

}
int processmessage(
			Wclient * pcl, 
			Wform * pfrm, 
			map < int, component * > * pIC, 
			HACCEL hAcc,
			int & rescode 
		){

	MSG Msg;
	HWND hWnd = pfrm->gethandle();
	currform = pfrm;
	int flag = 1;
	int val = GetMessage(&Msg, NULL, 0, 0);
	controlhandles = pIC;
	if (val == -1){

		// error handling
		flag = 0;

	}
	else if (val == 0) flag = 0;
	else {

		if (hAcc != NULL){
			if(!TranslateAccelerator(hWnd,hAcc,&Msg)){

				TranslateMessage(&Msg);
				// in our wndproc function will be 
				DispatchMessage(&Msg);

			}
		}
		else {

			TranslateMessage(&Msg);
			// in our wndproc function will be 
			DispatchMessage(&Msg);

		}

	}

	rescode = Msg.wParam;

	return flag;

}

// client methods
Wclient::Wclient(string name){

	this->name = name;

}
Wclient::~Wclient(){

	for (map < string, component * >::iterator iter = forms.begin(); iter != forms.end(); ++iter)
		delete iter->second;
	forms.clear();

}
int Wclient::mainloop(){

	// TODO: code here mainloop with message dispatching for winapi
	/*

		// so, i need method, that could read all hwnds of my windows,
		// has all accel tables handles, parsing this all mess with message to
		// wndproc, there must be somewhere map < hwnd, form * >, and maybe
		// reverted, wndproc must parse message and compose string and return somehow
		// it to this class, i think it must call dispatch. Additional wndproc needs
		// map < control id, component * >

		// here must be something like:

		bool flag = true;
		int val;
		while (flag){

			// first one, i need here to extract message and compose it to string
			val = GetMessage(&Msg,NULL,0,0));
			if (val == -1){

				// error handling
				flag = 0;

			}
			else if (val == 0) flag = 0;
			else {

				// if some of them translated succesfully, i don't need do nothing, so i need some
				// way to return special nothing-to-do flag
				//
				// here iterating for all our forms and checking if Accelerator passed
				// if not, then:
				{

					TranslateMessage(&Msg);
					// in our wndproc function will be 
					DispatchMessage(&Msg);

				}

			}

		}
		return Msg.wParam;

	*/
	int rescode = 0;
	while (processmessage(this, (Wform *)(forms[mainform]), idmaster::getmap(), NULL, rescode)){

	}
	return rescode;

}
void Wclient::newform(form * container, bool show){

	// check if form exists
	string cname = container->getname();
	if (forms[cname] != NULL)
		return;

	// add our form
	forms[cname] = container;

	// show form
	if (show)
		container->show();

}
void Wclient::newmainform(form * container){

	// setup our main form
	string cname = container->getname();
	mainform = cname;

	// check if exists
	if (forms[mainform] != NULL)
		return;

	// add our main form
	forms[mainform] = container;

	// show main form
	container->show();

}

// component methods
int Wclient::dispatch(string message){

	// TODO: maybe it must be not empty :)

}
void Wclient::setparent(component * parent){

	//fprintf(stderr, "Wguicore--Wclient::setparent::warning can't change parent of application, ignoring\n");
	new logger(5, "Wguicore--Wclient::setparent::warning can't change parent of application, ignoring\n");

}
component * Wclient::getparent(){

	//fprintf(stderr, "Wguicore--Wclient::getparent::warning can't get parent of application, returning NULL\n");
	new logger(5, "Wguicore--Wclient::getparent::warning can't get parent of application, returning NULL\n");
	return NULL;

}
string Wclient::getname(){

	return name;

}

//#end
