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
//	class zprog
//	interface
//	emulator class for z0rch's module
//

#ifndef zprog_hpp
#define zprog_hpp

#include "../robocore/izprog.all.hpp"
#include "robot.all.hpp"
#include "btexecutor.all.hpp"

#include <vector>

using namespace std;

class
zprog: public izprog{

public:

	zprog(btexecutor * btexec, robot * robo);
	~zprog();

	void passstartcoords(int sx, int sy, int lx, int ly);
	void moverel(int dx, int dy);

	void beep();
	void setlight(bool fLight);

	void run();

protected:

	void realrelmove(int dx, int dy);

private:

	btexecutor * btexec;
	robot * robo;

	pair < double, double > pos;
	pair < double, double > look;
	vector < pair < int, int > > moverelcommands;

	vector < int > withbeep;
	vector < int > withlighton;
	vector < int > withlightoff;

};

#endif

//#end
