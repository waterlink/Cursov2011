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

Wform::Wform(string name){

	this->name = name;

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
	fprintf(stderr, "Wguicore--Wform::show::fixme: stub\n");
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

	// TODO: make this work with winapi
	// TODO: use tokenizer here
	fprintf(stderr, "Wguicore--Wform::dispatch::fixme: stub\nMessage is: %s\n", message.c_str());

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

}
void Wform::setposition(int x, int y){

	position.first = x;
	position.second = y;

}

//#end
