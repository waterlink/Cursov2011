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
//	class Wzprog
//	interface
//	z0rch module adapter, win specification
//

#ifndef Wzprog_hpp
#define Wzprog_hpp

#include <string>
#include <vector>
#include <cstdio>

#include "../../all/robocore/izprog.all.hpp"
#include "../../../Wzprog/RobotControl.h"

using namespace std;

class
Wzprog: public izprog{

public:

	Wzprog();
	~Wzprog();
	
	void passstartcoords(int sx, int sy, int lx, int ly);
	void moverel(int dx, int dy);
	void beep();
	void setlight(bool fLight);
	void run();

protected:

	

private:

    class FileRoute;
    FileRoute * fileRoute;
    int sx, sy, lx, ly;

};

#endif

//#end
