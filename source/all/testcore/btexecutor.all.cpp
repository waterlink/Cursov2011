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
//	emulator class for btexecutor
//

#include "btexecutor.all.hpp"

#include <cmath>

#include "../utilcore/mather.all.hpp"

btexecutor::btexecutor(robot * robo){

	this->robo = robo;
	ispowersaved = -1;

}
btexecutor::~btexecutor(){}

double btexecutor::getRD0power(){ return robo->grd0(); }
double btexecutor::getRD1power(){ return robo->grd1(); }
bool btexecutor::setRD0power(double power){

	if (ispowersaved == 1){

		robo->srd(power, savedpower);
		ispowersaved = -1;

	}
	else {

		savedpower = power;
		ispowersaved = 0;

	}

}
bool btexecutor::setRD1power(double power){

	if (ispowersaved == 0){

		robo->srd(savedpower, power);
		ispowersaved = -1;

	}
	else {

		savedpower = power;
		ispowersaved = 1;

	}

}

bool btexecutor::getTouchSensorState(){ return robo->gtouch(); }
double btexecutor::getUltrasoundDistance(){ return robo->gsight(); }

double btexecutor::getLight(){ 

	// TODO: fixme: stub
	return false; 

}
double btexecutor::getVoltage(){

	// emulator has 100% voltage all the time
	return 1.0;

}

//#end
