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
#include "../../all/robocore/test_roboemu_params.all.hpp"
#include "../../all/robocore/test_btexecemu.all.hpp"

mainclass::mainclass(int argc, char ** argv){

	this->argc = argc;
	this->argv = argv;

}

mainclass::~mainclass(){}

int
mainclass::run(){

	printf("program is working!!!\n");

	test_roboemu_params
	*sample = new test_roboemu_params;

	test_zprogemu
	*tzpe = new test_zprogemu(sample);

	test_btexecemu
	*btee = new test_btexecemu(sample);
	
		tzpe->passstartcoords(30, 30, 35, 30);
		tzpe->moverel(10, 5);
		tzpe->beep();
		tzpe->moverel(-40, 55);
		tzpe->setlight(true);
		tzpe->moverel(30, -60);
		tzpe->setlight(false);

		tzpe->run();

		printf("rd0: %lf\n", btee->getRD0power());
		printf("rd1: %lf\n", btee->getRD1power());
		printf("touchsensor: %d\n", btee->getTouchSensorState());
		printf("ultrasensor: %lf\n", btee->getUltrasoundDistance());
		printf("light %d\n", btee->getLight());
		btee->setRD0power(55.4);
		btee->setRD1power(40.25);
		printf("rd0: %lf\n", btee->getRD0power());
		printf("rd1: %lf\n", btee->getRD1power());
		printf("touchsensor: %d\n", btee->getTouchSensorState());
		printf("ultrasensor: %lf\n", btee->getUltrasoundDistance());
		printf("light %d\n", btee->getLight());

	delete tzpe;

	return 0;

}

//#end
