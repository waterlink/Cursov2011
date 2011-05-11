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
//	gui class form for winapi
//

#include "Wform.win.hpp"

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Wclient.win.hpp"
#include "../main/mainclass.win.hpp"
#include "../../all/utilcore/stringtokenizer.all.hpp"
#include "hwndmaster.win.hpp"

using namespace std;

Wform::Wform(){}
Wform::Wform(string name){

	this->name = name;

	HWND hWnd; 
	WNDCLASS WndClass; 
	HINSTANCE hInst = mainclass::getInst();

	fprintf(stderr, "Wguicore--Wform::Wform::debug: Inst = %d\n", hInst);

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

	hWnd = CreateWindow(name.c_str(), name.c_str(),
				WS_OVERLAPPEDWINDOW, 
				CW_USEDEFAULT,CW_USEDEFAULT,
				CW_USEDEFAULT,CW_USEDEFAULT,
				NULL,NULL,
				hInst,NULL);

	if(!hWnd){

		MessageBox(NULL,"Cannot create window","Error",MB_OK);
		return;

	}

	hwnd = hWnd;
	hwndmaster::newform(hwnd, this);

}
Wform::~Wform(){

	for (map < string, component * >::iterator iter = controls.begin(); iter != controls.end(); ++iter)
		delete iter->second;
	controls.clear();
	((form *)getparent())->del(getname());

}

// Wform methods
void Wform::show(){

	// TODO: make this work with winapi
	/*fprintf(stderr, "Wguicore--Wform::show::fixme: stub\n");*/
	ShowWindow(hwnd, 10);
	UpdateWindow(hwnd);
	visible = true;

}
void Wform::close(){

	// TODO: make this work with winapi
	fprintf(stderr, "Wguicore--Wform::close::fixme: stub\n");
	visible = false;

}
void Wform::add(component * control){

	// check if exists already
	string cname = control->getname();
	if (getcomponent(cname) != NULL)
		return;
	
	// add to our control map this component
	controls[cname] = control;

}
void Wform::del(string name){

	map < string, component * >::iterator iter = controls.lower_bound(name);
	if (iter != controls.end())
		if (iter->first == name)
			controls.erase(iter);

}
component * Wform::getcomponent(string name){

	return controls[name];

}

// component methods
int Wform::dispatch(string message){

#define clean \
		delete token;\
		delete token2; \
		return 0;

	// TODO: make this work with winapi
	// TODO: use tokenizer here
	fprintf(stderr, "Wguicore--Wform::dispatch::fixme: stub\nMessage is: %s\n", message.c_str());

	// here we have a paint, mousecapture
	string msg = message;
	tokenizer * token = new stringtokenizer(&message);
	tokenizer * token2 = new stringtokenizer(&msg);
	fprintf(stderr, "Wguicore--Wform::dispatch::debug: created tokenizers\n");
	if (token->getparam("message") == "paint"){

		for (map < string, component * >::iterator iter = controls.begin(); iter != controls.end(); ++iter)
			iter->second->dispatch(message);

	}
	if (	token->getparam("message") == "mousedown" ||
		token->getparam("message") == "mouseup" ||
		token->getparam("message") == "mousemove"){

		fprintf(stderr, "Wguicore--Wform::dispatch::debug: entered into mousecapture dispatching\n");

		for (map < string, component * >::iterator iter = controls.begin(); iter != controls.end(); ++iter){

			sizeble * control = dynamic_cast < sizeble * >(iter->second);
			fprintf(stderr, "Wguicore--Wform::dispatch::debug control is: %d\n", control);
			if (control == NULL) continue;
			fprintf(stderr, "Wguicore--Wform::dispatch::debug: control->sizeble_markup: %d\n", (int)(control->sizeble_markup));
			if (1){

				fprintf(stderr, "Wguicore--Wform::dispatch::debug: found sizeble control: %s\n", iter->second->getname().c_str());
				pair < int, int > size = control->getsize();
				pair < int, int > pos = control->getposition();
				int x = token->getparam("x", 0);
				int y = token->getparam("y", 0);
				if (	x >= pos.first && x <= pos.first + size.first &&
					y >= pos.second && y <= pos.second + size.second){

					token2->setparam("x", x - pos.first);
					token2->setparam("y", y - pos.second);
					cerr << "Wguicore--Wform::dispatch::debug: msg is " << msg << endl;
					iter->second->dispatch(msg);

				}

			}

		}

	}
	if (token->getparam("message") == "resize"){

		token2->setparam("oldwidth", size.first);
		token2->setparam("oldheight", size.second);
		size.first = token->getparam("width", 0);
		size.second = token->getparam("height", 0);
		token2->setparam("message", "parentresize");
		for (map < string, component * >::iterator iter = controls.begin(); iter != controls.end(); ++iter)
			iter->second->dispatch(msg);

	}

	clean;

#undef clean

}
void Wform::setparent(component * parent){

	this->parent = parent;

}
component * Wform::getparent(){

	return parent;

}
string Wform::getname(){

	return name;

}

// sizeble methods
pair < int, int > Wform::getsize(){

	return size;

}
pair < int, int > Wform::getposition(){

	return position;

}
void Wform::setsize(int w, int h){

	size.first = w;
	size.second = h;
	MoveWindow(hwnd, position.first, position.second, w, h, true);

}
void Wform::setposition(int x, int y){

	position.first = x;
	position.second = y;
	MoveWindow(hwnd, x, y, size.first, size.second, true);

}

// winapi sensitive
HWND Wform::gethandle(){

	return hwnd;

}

void Wform::sethandle(HWND handle){

	hwnd = handle;

}
void Wform::setresize(messager * onresize){ this->onresize = onresize; }
void Wform::setparentresize(messager * onparentresize){ this->onparentresize = onparentresize; }

//#end
