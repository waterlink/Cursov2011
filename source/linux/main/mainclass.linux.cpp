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
//	main class, contains initializer for parameters and method run, to run application
//

#include "mainclass.linux.hpp"
#include <cstdio>

mainclass::mainclass(int argc, char ** argv){

	this->argc = argc;
	this->argv = argv;

}

mainclass::~mainclass(){}

int
mainclass::run(){

	printf("program is working!!!");
	return 0;

}

//#end
