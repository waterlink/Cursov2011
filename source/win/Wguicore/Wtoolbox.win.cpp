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
//	gui class toolbox for winapi
//

#include "Wtoolbox.win.hpp"

#include "../main/mainclass.win.hpp"
#include "Wclient.win.hpp"
#include "idmaster.win.hpp"
#include "hwndmaster.win.hpp"
#include "../../all/utilcore/stringtokenizer.all.hpp"

Wtoolbox::Wtoolbox(){}
Wtoolbox::Wtoolbox(string name, Wform * parent){

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
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.lpszMenuName = "";
	WndClass.lpszClassName = name.c_str();

	if(!RegisterClass(&WndClass)){

		MessageBox(NULL,"Cannot register class","Error",MB_OK);
		return;

	}

	hWnd = CreateWindow(name.c_str(), name.c_str(),
				WS_CHILD | WS_VISIBLE, 
				0, 0,
				0, 0,
				parent->gethandle(),
				(HMENU)idmaster::gen(this),
				hInst,
				NULL
			);

	if(!hWnd){

		MessageBox(NULL,"Cannot create toolbox","Error",MB_OK);
		return;

	}

	sethandle(hWnd);
	hwndmaster::newform(hwnd, (Wform *)this);

}
Wtoolbox::~Wtoolbox(){}

component * Wtoolbox::getactivecontrol(){ return activecontrol; }
void Wtoolbox::setactivecontrol(component * control){ activecontrol = control; }

// form methods
void Wtoolbox::show(){ myWform->show(); }
void Wtoolbox::close(){ myWform->close(); }
void Wtoolbox::add(component * control){ myWform->add(control); }
void Wtoolbox::del(string name){ myWform->del(name); }
component * Wtoolbox::getcomponent(string name){ return myWform->getcomponent(name); }

// component methods
int Wtoolbox::dispatch(string message){ 

	// TODO: code here outfit selected control

#define clean \
		delete token; \
		return myWform->dispatch(message);

	tokenizer * token = new stringtokenizer(&message);

	if (token->getparam("message") == "paint")
		if (activecontrol){

		sizeble * control = dynamic_cast < sizeble * >(activecontrol);

		RECT rect;
		rect.left = control->getposition().first;
		rect.top = control->getposition().second;
		rect.right = rect.left + control->getsize().first;
		rect.bottom = rect.top + control->getsize().second;
		InvalidateRect(hwnd, &rect, true);
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		HBRUSH hbrush;
		HPEN hpen;
		LOGBRUSH brush;

			brush.lbStyle = BS_SOLID;
			brush.lbColor = RGB(0, 255, 0);
			hbrush = CreateBrushIndirect(&brush);
			SelectObject(hdc, hbrush);
			hpen = CreatePen(PS_NULL, 4, RGB(0, 255, 0));
			SelectObject(hdc, hpen);

			Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

		EndPaint(hwnd, &ps);

	}

	clean;

#undef clean

}
void Wtoolbox::setparent(component * parent){ myWform->setparent(parent); }
component * Wtoolbox::getparent(){ return myWform->getparent(); }
string Wtoolbox::getname(){ return name; }

// sizeble methods
pair < int, int > Wtoolbox::getsize(){ return myWform->getsize(); }
pair < int, int > Wtoolbox::getposition(){ return myWform->getposition(); }
void Wtoolbox::setsize(int w, int h){ myWform->setsize(w, h); }
void Wtoolbox::setposition(int x, int y){ myWform->setposition(x, y); }

// winapi-sensitive
HWND Wtoolbox::gethandle(){ return hwnd; }
void Wtoolbox::sethandle(HWND handle){ hwnd = handle; myWform->sethandle(hwnd); }

//#end
