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
//	class ibtexec
//	interface
//	interface for BTExecutor external module
//

#ifndef ibtexec_hpp
#define ibtexec_hpp

/*	#doc class robocore--ibtexec
		interface for external module (Krachkovskiy's BTExecutor)
		used for movement, light, touchsense and ultrasoundsense

		allows to manipulate with robot in online mode
*/
class
ibtexec{

public:

	virtual
	~ibtexec() = 0;

/*	#doc robocore--ibtexec::getRD0power
		double
		getRD0power();

		allows to get power of motor A
*/
	virtual double
	getRD0power() = 0;
//	#docend robocore--ibtexec::getRD0power

/*	#doc robocore--ibtexec::getRD1power
		double
		getRD1power();

		allows to get power of motor C
*/
	virtual double
	getRD1power() = 0;
//	#docend robocore--ibtexec::getRD1power

/*	#doc robocore--ibtexec::getTouchSensorState
		bool
		getTouchSensorState();

		allows to get if the obstacle is touched
		with touch sensor
*/
	virtual bool
	getTouchSensorState() = 0;
//	#docend robocore--ibtexec::getTouchSensorState

/*	#doc robocore--ibtexec::getUltrasoundDistance
		double
		getUltrasoundDistance();

		allows to get distance to nearest obstacle
		in front of robot
*/
	virtual double
	getUltrasoundDistance() = 0;
//	#docend robocore--ibtexec::getUltrasoundDistance

/*	#doc robocore--ibtexec::getLight
		double
		getLight();

		allows to get current intensivity
		of light
*/
	virtual double
	getLight() = 0;
//	#docend robocore--ibtexec::getLight

/*	#doc robocore--ibtexec::getVoltage
		double
		getVoltage();

		allows to get current battery power
*/
	virtual double
	getVoltage() = 0;
//	#docend robocore--ibtexec::getVoltage

/*	#doc robocore--ibtexec::setRD0power
		bool
		setRD0power( double power );

		allows to change motor A power
		returns true, if operation was succesful
*/
	virtual bool
	setRD0power(double power) = 0;
//	#docend robocore--ibtexec::setRD0power

/*	#doc robocore--ibtexec::setRD1power
		bool
		setRD1power( double power );

		allows to change motor C power
		returns true, if operation was succesful
*/
	virtual bool
	setRD1power(double power) = 0;
//	#docend robocore--ibtexec::setRD1power

protected:

	

private:

	

};
//	#docend class robocore--ibtexec

#endif

//#end
