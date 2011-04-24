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
//	test class for kbtexec (Krachkovskiy's BTExecutor external module), emulates direct control of robot
//

#include "test_btexecemu.all.hpp"

#include <cstdio>

test_btexecemu::test_btexecemu(test_roboemu_params * sample){

	this->sample = sample;

}

test_btexecemu::~test_btexecemu(){}

double
test_btexecemu::getRD0power(){

	return sample->rd0;

}

double
test_btexecemu::getRD1power(){

	return sample->rd1;

}

bool
test_btexecemu::getTouchSensorState(){

	// TODO: here must be checking, if there is an obstacle in front of robot
	printf("test_btexecemu::getTouchSensorState::fixme: stub\n");
	return false;

}

double
test_btexecemu::getUltrasoundDistance(){

	// TODO: here must be calculating how distant obstacle in front it is
	printf("test_btexecemu::getUltrasoundDistance::fixme: stub\n");
	return 10000.0;

}

double
test_btexecemu::getLight(){

	return sample->light;

}

double
test_btexecemu::getVoltage(){

	return sample->voltage;

}

bool
test_btexecemu::setRD0power(double power){

	sample->rd0 = power;
	return true;

}

bool
test_btexecemu::setRD1power(double power){

	sample->rd1 = power;
	return true;

}

//#end
