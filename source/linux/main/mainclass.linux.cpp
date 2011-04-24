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
#include <cstdlib>

#include "../../all/robocore/test_zprogemu.all.hpp"

mainclass::mainclass(int argc, char ** argv){

	this->argc = argc;
	this->argv = argv;

}

mainclass::~mainclass(){}

int
mainclass::run(){

	printf("program is working!!!\n");

	test_zprogemu
	*tzpe = new test_zprogemu(NULL);
	
		tzpe->passstartcoords(30, 30, 35, 30);
		tzpe->moverel(10, 5);
		tzpe->beep();
		tzpe->moverel(-40, 55);
		tzpe->setlight(true);
		tzpe->moverel(30, -60);
		tzpe->setlight(false);

		tzpe->run();

	delete tzpe;

	return 0;

}

//#end
