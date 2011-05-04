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
//	gui class button version for winapi
//

#include "Wbutton.win.hpp"
#include "idmaster.win.hpp"
#include "../main/mainclass.win.hpp"

#include "../../all/utilcore/stringtokenizer.all.hpp"

// component
Wbutton::Wbutton(string name, Wform * parent){ 

	this->name = name;
	hwnd = CreateWindow(
				"button",
				name.c_str(),
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				0, 0,
				0, 0,
				parent->gethandle(),
				(HMENU) idmaster::gen(this),
				mainclass::getInst(),
				NULL
			);
	//parent->add(this);

}
Wbutton::~Wbutton(){}
int Wbutton::dispatch(string message){

	// TODO: here is winapi dispatching
	// TODO: use of tokenizer

#define clean \
		delete token; \
		return 0;

	fprintf(stderr, "Wguicore--Wbutton::dispatch::fixme: stub, message: %s\n", message.c_str());
	tokenizer * token = new stringtokenizer(&message);
	if (token->getparam("message") == "activate"){

		(*onactivate)(this, message);

	}
	clean;

#undef clean

}
void Wbutton::setparent(component * parent){ this->parent = parent; }
component * Wbutton::getparent(){ return parent; }
string Wbutton::getname(){ return name; }

// textable
void Wbutton::settext(string text){ 

	this->text = text; 
	SetWindowText(hwnd, text.c_str());

}
string Wbutton::gettext(){ 

	return text; 

}

// activateble
void Wbutton::setactivate(messager * onactivate){ this->onactivate = onactivate; }

// enableble
void Wbutton::enable(){ 

	enabled = true; 
	EnableWindow(hwnd, true);

}
void Wbutton::disable(){ 

	enabled = false; 
	EnableWindow(hwnd, false);

}
bool Wbutton::isenable(){ return enabled; }

// sizeble
pair < int, int > Wbutton::getsize(){ return size; }
pair < int, int > Wbutton::getposition(){ return position; }
void Wbutton::setsize(int w, int h){ 

	size = make_pair(w, h); 
	MoveWindow(hwnd, position.first, position.second, w, h, true);

}
void Wbutton::setposition(int x, int y){ 

	position = make_pair(x, y); 
	MoveWindow(hwnd, x, y, size.first, size.second, true);

}

//#end
