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

Wproperties::Wproperties(string name, Wform * parent){

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
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = "";
	WndClass.lpszClassName = name.c_str();

	if(!RegisterClass(&WndClass)){

		MessageBox(NULL,"Cannot register class","Error",MB_OK);
		return;

	}

	hWnd = CreateWindow(name.c_str(), name.c_str(),
				WS_OVERLAPPEDWINDOW | WS_CHILD | WS_VISIBLE | WS_VSCROLL, 
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

	sethandle(hWnd);
	hwndmaster::newform(hwnd, (Wform *)this);

}
Wproperties::Wproperties(){}
Wproperties::~Wproperties(){}

bool Wproperties::addproperty(string name, string value, string type){}
string Wproperties::getproperty(string name){}
bool Wproperties::delproperty(string name){}

// form methods
void Wproperties::show(){ myWform->show(); }
void Wproperties::close(){ myWform->close(); }
void Wproperties::add(component * control){ myWform->add(control); }
void Wproperties::del(string name){ myWform->del(name); }
component * Wproperties::getcomponent(string name){ return myWform->getcomponent(name); }

// component methods
int Wproperties::dispatch(string message){}
void Wproperties::setparent(component * parent){ myWform->setparent(parent); }
component * Wproperties::getparent(){ return myWform->getparent(); }
string Wproperties::getname(){ return name; }

// sizeble methods
pair < int, int > Wproperties::getsize(){ return myWform->getsize(); }
pair < int, int > Wproperties::getposition(){ return myWform->getposition(); }
void Wproperties::setsize(int w, int h){ myWform->setsize(w, h); }
void Wproperties::setposition(int x, int y){ myWform->setposition(x, y); }

// winapi-sensitive
HWND Wproperties::gethandle(){ return hwnd; }
void Wproperties::sethandle(HWND handle){ hwnd = handle; myWform->sethandle(hwnd); }

//#end
