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
//	class robot
//	interface
//	robot emulator
//

#ifndef robot_hpp
#define robot_hpp

#include "world.all.hpp"

class
robot{

public:

	robot(world * w);
	virtual ~robot();
	virtual double grd0();
	virtual double grd1();
	virtual void srd(double v0, double v1);
	virtual bool gtouch();
	virtual double gsight();
	virtual void slight(bool f);
	virtual void beep();
	virtual void update();
	virtual bool test();

	virtual double getmaxspeed();
	virtual pair < double, double > getsize();

	virtual void setupcorrds(pair < int, int > pos);
	virtual void setuplook(pair < int, int > look);

protected:

	

private:

	double rd0, rd1;
	bool light;
	bool touch;

	world * w;

	double x, y;
	double lx, ly;

	double t;

};

#endif

//#end
