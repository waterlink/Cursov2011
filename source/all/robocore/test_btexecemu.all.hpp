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
//	class test_btexecemu
//	interface
//	test class for kbtexec (Krachkovskiy's BTExecutor external module), emulates direct control of robot
//

#ifndef test_btexecemu_hpp
#define test_btexecemu_hpp

#include "ibtexec.all.hpp"
#include "test_roboemu_params.all.hpp"

/*	#doc class robocore--test_btexecemu
		test class

		emulates kbtexec, logging to console,
		use of loaded map in sample
*/
class
test_btexecemu: public ibtexec{

public:

/*	#doc robocore--test_btexecemu::test_btexecemu
		test_btexecemu(
					test_roboemu_params * sample
				);

		links this emulator to specific robot params
*/
	test_btexecemu(test_roboemu_params * sample);
//	#enddoc robocore--test_btexecemu::test_btexecemu

	~test_btexecemu();

	double
	getRD0power();

	double
	getRD1power();

	bool
	getTouchSensorState();

	double
	getUltrasoundDistance();

	double
	getLight();

	double
	getVoltage();

	bool
	setRD0power(double power);

	bool
	setRD1power(double power);

protected:

	

private:

	test_roboemu_params 
	*sample;

};
//	#docend class robocore--test_btexecemu

#endif

//#end
