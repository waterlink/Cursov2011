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
//	guicore view class for winapi
//

#include "Wview.win.hpp"

#include "../../all/utilcore/stringtokenizer.all.hpp"
#include "Wform.win.hpp"
#include <windows.h>

Wview::Wview(string name, form * parent){

	this->name = name;
	this->parent = parent;

}
Wview::~Wview(){}

// component:
int Wview::dispatch(string message){

	// TODO: code this up

#define clean \
		delete token; \
		return 0;

	tokenizer * token = new stringtokenizer(&message);
	if (token->getparam("message") == "paint"){

		if (onpaint) (*onpaint)(this, message);
		// just an example
		/*Wform * parent = dynamic_cast < Wform * >(this->parent);
		if (parent){

			HWND hwnd = parent->gethandle();
			RECT rect;
			rect.left = position.first;
			rect.top = position.second;
			rect.right = rect.left + size.first;
			rect.bottom = rect.top + size.second;
			InvalidateRect(hwnd, &rect, true);
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			
				HBRUSH hbrush;
				HPEN hpen;
				LOGBRUSH brush;
				brush.lbStyle = BS_SOLID;
				brush.lbColor = RGB(0, 0, 255);
				hbrush = CreateBrushIndirect(&brush);
				SelectObject(hdc, hbrush);
				hpen = CreatePen(PS_NULL, 2, RGB(0, 0, 255));
				SelectObject(hdc, hpen);
				Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

			EndPaint(hwnd, &ps);

		}*/

	}	

	clean;

#undef clean 

}
void Wview::setparent(component * parent){

	this->parent = parent;

}
component * Wview::getparent(){

	return parent;

}
string Wview::getname(){

	return name;

}

// sizeble:
pair < int, int > Wview::getsize(){ 

	return size;

}
pair < int, int > Wview::getposition(){

	return position;

}
void Wview::setsize(int w, int h){

	size = make_pair(w, h);

}
void Wview::setposition(int x, int y){

	position = make_pair(x, y);

}

// mousecaptureble:
void Wview::setmousedown(messager * onmousedown){

	this->onmousedown = onmousedown;

}
void Wview::setmouseup(messager * onmouseup){

	this->onmouseup = onmouseup;

}
void Wview::setmousemove(messager * onmousemove){

	this->onmousemove = onmousemove;

}

// paintable:
void Wview::setpaint(messager * onpaint){

	this->onpaint = onpaint;

}

//#end
