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

#include "../../all/utilcore/logger.all.hpp"

Wview::Wview(string name, form * parent){

	this->name = name;
	this->parent = parent;

}
Wview::~Wview(){}

void Wview::draw(string primitive){

	drawqueue.push_back(primitive);

}
void Wview::undraw(string primitive){

	list < string >::iterator iter;
	for (iter = drawqueue.begin(); iter != drawqueue.end(); ++iter)
		if (*iter == primitive)
			break;
	if (iter != drawqueue.end())
		drawqueue.erase(iter);

}

// component:
int Wview::dispatch(string message){

#define clean \
		delete token; \
		return 0;

	tokenizer * token = new stringtokenizer(&message);
	if (token->getparam("message") == "paint"){

		if (onpaint) (*onpaint)(this, message);
		Wform * parent = dynamic_cast < Wform * >(this->parent);
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
			for (list < string >::iterator iter = drawqueue.begin(); iter != drawqueue.end(); ++iter){

				string next = *iter;
				tokenizer * primitive = new stringtokenizer(&next);

				string ptype = primitive->getparam("primitive");
				int x = primitive->getparam("x", 0);
				int y = primitive->getparam("y", 0);
				int w = primitive->getparam("w", 0);
				int h = primitive->getparam("h", 0);
				int r = primitive->getparam("r", 0);
				int cr = primitive->getparam("rcolor", 0);
				int cg = primitive->getparam("gcolor", 0);
				int cb = primitive->getparam("bcolor", 0);
				int th = primitive->getparam("thickness", 0);
				if (th == tokenizer::unknowint)
					th = 0;

				brush.lbStyle = BS_SOLID;
				brush.lbColor = RGB(cr, cg, cb);
				hbrush = CreateBrushIndirect(&brush);
				SelectObject(hdc, hbrush);
				hpen = CreatePen(PS_SOLID, th, RGB(cr, cg, cb));
				SelectObject(hdc, hpen);

				if (ptype == "rectangle")
					Rectangle(hdc, x, y, x + w, y + h);
				if (ptype == "point")
					SetPixel(hdc, x, y, RGB(cr, cg, cb));
				if (ptype == "ellipse")
					Ellipse(hdc, x, y, x + w, y + h);
				if (ptype == "circle")
					Ellipse(hdc, x - r / 2, y - r / 2, x + r / 2, y + r / 2);
				if (ptype == "line"){

					new logger(0, "trying to paint line\n");
					MoveToEx(hdc, x, y, NULL);
					LineTo(hdc, x + w, y + h);

				}
				
				delete primitive;
				
			}

			EndPaint(hwnd, &ps);

		}		

	}
	else if (token->getparam("message") == "mousedown"){
		if (onmousedown)
			(*onmousedown)(this, message);
	}
	else if (token->getparam("message") == "mouseup"){
		if (onmouseup)
			(*onmouseup)(this, message);
	}
	else if (token->getparam("message") == "mousemove")
		if (onmousemove)
			(*onmousemove)(this, message);

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
