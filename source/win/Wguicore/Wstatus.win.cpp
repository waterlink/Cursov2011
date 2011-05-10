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
//	gui class status for winapi
//

#include "Wstatus.win.hpp"

#include "../main/mainclass.win.hpp"
#include "../../all/utilcore/stringtokenizer.all.hpp"

#include <commctrl.h>

#include <cstring>

Wstatus::Wstatus(){}
Wstatus::Wstatus(string name, Wform * parent){

	this->name = name;
	HWND hWnd = parent->gethandle();
	hSW = CreateStatusWindow(WS_CHILD | WS_VISIBLE, NULL, hWnd, wId);
	setparent(parent);

}
Wstatus::~Wstatus(){}

// component
int Wstatus::dispatch(string message){

#define clean \
		delete token; \
		return 0;

	tokenizer * token = new stringtokenizer(&message);

	if (token->getparam("message") == "resize"){

		int width = token->getparam("width", 0);
		int height = token->getparam("height", 0);
		SendMessage(hSW, WM_SIZE, SIZE_RESTORED, width + (height << 16));

	}

	clean;

#undef clean

}
void Wstatus::setparent(component * parent){

	this->parent = parent;

}
component * Wstatus::getparent(){

	return parent;

}
string Wstatus::getname(){

	return name;

}

// textable
void Wstatus::settext(string text){

	this->text = text;
	char buf[100];
	strcpy(buf, text.c_str());
	SendMessage(hSW, SB_SETTEXT, 0, (LPARAM)buf);

}
string Wstatus::gettext(){

	return text;

}

//#end
