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
//	win version of main class, contains initialization, run method and finalization
//

#include "mainclass.win.hpp"

mainclass::mainclass(){}

void
mainclass::init(
			HINSTANCE Inst,
			LPSTR CmdParam,
			int CmdShow
		){

	this->Inst = Inst;
	this->CmdParam = CmdParam;
	this->CmdShow = CmdShow;

}

mainclass::~mainclass(){}

int
mainclass::run(){

	MessageBox (NULL, TEXT ("mainclass: Hello, Windowman!"), TEXT ("HelloMsg"), 0);

	return 0;

}

//#end
