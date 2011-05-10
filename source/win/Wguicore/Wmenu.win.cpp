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
//	gui class menu for winapi
//

#include "Wmenu.win.hpp"

#include <cstdio>

#include "../../all/utilcore/stringtokenizer.all.hpp"
#include "idmaster.win.hpp"

// menu methods
Wmenu::Wmenu(string name, bool popup){

	this->name = name;
	this->popup = popup;

}
Wmenu::Wmenu(){}
Wmenu::Wmenu(string name, Wform * parent){}
Wmenu::Wmenu(string name, Wmenu * parent, int){}
Wmenu::~Wmenu(){}
bool Wmenu::ispopup(){

	return popup;

}
void Wmenu::add(menu * submenu){

	// there will not be any checks, 'cause it possible to add the same menu 2 times
	submenus.push_back(submenu);
	submenu->setparent(this);

}

// component methods
int Wmenu::dispatch(string message){

	// TODO: here is winapi dispatching
	// TODO: use of tokenizer
	fprintf(stderr, "Wguicore--Wmenu::dispatch::fixme: stub, message: %s\n", message.c_str());

#define clean \
		delete token; \
		return 0;

	tokenizer * token = new stringtokenizer(&message);

	if (token->getparam("message") == "select"){
		if (onselect)
			(*onselect)(this, message);
	} else if (token->getparam("message") == "activate"){
		if (onactivate)
			(*onactivate)(this, message);
	}

	clean;

#undef clean

}
void Wmenu::setparent(component * parent){

	this->parent = parent;

}
component * Wmenu::getparent(){

	return parent;

}
string Wmenu::getname(){

	return name;

}

//textable methods
void Wmenu::settext(string text){

	this->text = text;

}
string Wmenu::gettext(){

	return text;

}

// activateble methods
void Wmenu::setactivate(messager * onactivate){

	this->onactivate = onactivate;

}

// selectable methods
void Wmenu::setselect(messager * onselect){

	this->onselect = onselect;

}

// enableble methods
void Wmenu::enable(){

	enabled = true;

}
void Wmenu::disable(){

	enabled = false;

}
bool Wmenu::isenable(){

	return enabled;

}

HWND Wmenu::gethandle(){

	return (HWND)hm;

}
void Wmenu::sethandle(HWND handle){

	hm = (HMENU)handle;

}

//#end
