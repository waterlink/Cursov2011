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
//	gui class client for winapi
//

#include "Wclient.win.hpp"

#include <cstdio>
#include <cstdlib>

// client methods
Wclient::Wclient(string name){

	this->name = name;

}
Wclient::~Wclient(){

	for (map < string, component * >::iterator iter = forms.begin(); iter != forms.end(); ++iter)
		delete iter->second;
	forms.clear();

}
int Wclient::mainloop(){

	// TODO: code here mainloop with message dispatching for winapi
	while (1){

		fprintf(stderr, "Wguicore--Wclient::mainloop::fixme: stub\n");
		dispatch("");

	}

}
void Wclient::newform(form * container, bool show){

	// check if form exists
	string cname = container->getname();
	if (forms[cname] != NULL)
		return;

	// add our form
	forms[cname] = container;

	// show form
	if (show)
		container->show();

}
void Wclient::newmainform(form * container){

	// setup our main form
	string cname = container->getname();
	mainform = cname;

	// check if exists
	if (forms[cname] != NULL)
		return;

	// add our main form
	forms[cname] = container;

	// show main form
	container->show();

}

// component methods
int Wclient::dispatch(string message){

	// TODO: make this work with winapi
	// TODO: use tokenizer here
	fprintf(stderr, "Wguicore--Wclient::dispatch::fixme: stub\nMessage is: %s\n", message.c_str());

}
void Wclient::setparent(component * parent){

	fprintf(stderr, "Wguicore--Wclient::setparent::warning can't change parent of application, ignoring\n");

}
component * Wclient::getparent(){

	fprintf(stderr, "Wguicore--Wclient::getparent::warning can't get parent of application, returning NULL\n");
	return NULL;

}
string Wclient::getname(){

	return name;

}

//#end
