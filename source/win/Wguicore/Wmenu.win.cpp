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

	if (!popup) hm = (HMENU)idmaster::gen(this);
	else hm = CreatePopupMenu();

}
Wmenu::Wmenu(string name){

	this->name = name;
	this->popup = false;
	hm = CreateMenu();

}
Wmenu::Wmenu(){}
Wmenu::Wmenu(string name, Wform * parent){

	popup = false;
	this->name = name;
	hm = CreateMenu();
	parent->add(this);
	this->parent = parent;

}
Wmenu::Wmenu(string name, Wmenu * parent, bool popup){

	this->name = name;
	this->popup = popup;
	if (popup) hm = CreatePopupMenu();
	else hm = (HMENU)(idmaster::gen(this));
	parent->add(this);	

}
Wmenu::~Wmenu(){}
bool Wmenu::ispopup(){

	return popup;

}
void Wmenu::add(menu * submenu){

	// there will not be any checks, 'cause it possible to add the same menu 2 times
	submenus.push_back(submenu);
	submenu->setparent(this);
	Wmenu * sm = dynamic_cast < Wmenu * >(submenu);
	if (sm) AppendMenu(hm, MF_STRING, (UINT_PTR)(sm->gethandle()), sm->gettext().c_str());

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
	Wform * par = dynamic_cast < Wform * >(parent);
	if (par){

		SetMenu(par->gethandle(), hm);

	}

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
	if (!parent) return;
	ihandled * par = dynamic_cast < ihandled * >(parent);
	if (par){

		HMENU hanc = (HMENU)(par->gethandle());
		ModifyMenu(hanc, (UINT)hm, MF_BYCOMMAND | MF_STRING, (UINT)hm, text.c_str());

	}

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
