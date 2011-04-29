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

// component
Wbutton::Wbutton(string name){ this->name = name; }
Wbutton::~Wbutton(){}
int Wbutton::dispatch(string message){

	// TODO: here is winapi dispatching
	// TODO: use of tokenizer
	fprintf(stderr, "Wguicore--Wbutton::dispatch::fixme: stub, message: %s\n", message.c_str());
	return 0;

}
void Wbutton::setparent(component * parent){ this->parent = parent; }
component * Wbutton::getparent(){ return parent; }
string Wbutton::getname(){ return name; }

// textable
void Wbutton::settext(string text){ this->text = text; }
string Wbutton::gettext(){ return text; }

// activateble
void Wbutton::setactivate(messager * onactivate){ this->onactivate = onactivate; }

// enableble
void Wbutton::enable(){ enabled = true; }
void Wbutton::disable(){ enabled = false; }
bool Wbutton::isenable(){ return enabled; }

// sizeble
pair < int, int > Wbutton::getsize(){ return size; }
pair < int, int > Wbutton::getposition(){ return position; }
void Wbutton::setsize(int w, int h){ size = make_pair(w, h); }
void Wbutton::setposition(int x, int y){ position = make_pair(x, y); }

//#end
