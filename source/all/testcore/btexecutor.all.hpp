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
//	header file
//	class btexecutor
//	interface
//	emulator class for btexecutor
//

#ifndef btexecutor_hpp
#define btexecutor_hpp

#include "../robocore/ibtexec.all.hpp"
#include "robot.all.hpp"

class
btexecutor: public ibtexec{

public:

	btexecutor(robot * robo);
	~btexecutor();

	double getRD0power();
	double getRD1power();
	bool setRD0power(double power);
	bool setRD1power(double power);

	bool getTouchSensorState();
	double getUltrasoundDistance();

	double getLight();
	double getVoltage();

protected:

	

private:

	robot * robo;

	double savedpower;
	int ispowersaved;

};

#endif

//#end
