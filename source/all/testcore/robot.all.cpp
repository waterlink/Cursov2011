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
//	robot emulator
//

#include "robot.all.hpp"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "../utilcore/logger.all.hpp"
#include "../utilcore/mather.all.hpp"

#define eps 1e-9
#define maxspeed 1.5
#define sizex 1.0
#define sizey 1.0

/*
		lxy
	-------------------  1.0 - sizex
		 ^
|	 |-------|-------|
|	 |	 |	 |
|	r|0	 |	1|r
|<-	r|0	 *	1|r	->
|	r|0	 xy	1|r
|	 |		 |
|	 |---------------|

1.0 - sizey

*/

robot::robot(world * w){ this->w = w; }
robot::~robot(){}
double robot::grd0(){ return rd0; }
double robot::grd1(){ return rd1; }
void robot::srd(double v0, double v1){ rd0 = v0, rd1 = v1; }
bool robot::gtouch(){

	// TODO: code this function, it must interact with world object somehow

}
double robot::gsight(){

	// TODO: code this function, it must interact with world object somehow

}
void robot::slight(bool f){

	if (f) new logger(1, "testcore--robot::slight::test: light enabled\n");
	else new logger(1, "testcore--robot::slight::test: light disabled\n");

}
void robot::beep(){

	new logger(1, "testcore--robot::beep::test: beep\n");

}
void robot::update(){

	double pi = acos(-1.0);

	double nt = 1.0 * clock() / CLOCKS_PER_SEC;
	double dt = nt - t;

	if (fabs(rd0 - rd1) > eps && fabs(rd0) > eps && fabs(rd1) > eps){

		new logger(1, "testcore--robot::update::test: breaked\n");
		return;

	}

	double rd = max(rd0, rd1) * maxspeed / 100.0;

	if (rd0 > rd1){

		double l = rd * dt;
		double a = sizex / sizex;
		
		// get normale to lxy and fit it to rd1 coords, they are spin center now
		pair < double, double > lxyN = mather::rotateex(make_pair(lx, ly), -pi / 2.0, make_pair(x, y));
		double r1x = (lxyN.first - x) / mather::distex(lxyN, make_pair(x, y)) * sizex / 2.0 + x;
		double r1y = (lxyN.second - y) / mather::distex(lxyN, make_pair(x, y)) * sizex / 2.0 + y;

		pair < double, double > xy = mather::rotateex(make_pair(x, y), -a, make_pair(r1x, r1y));
		pair < double, double > lxy = mather::rotateex(make_pair(lx, ly), -a, make_pair(r1x, r1y));

		x = xy.first, y = xy.second;
		lx = lxy.first, ly = lxy.second;

	}
	else if (rd1 > rd0){

		double l = rd * dt;
		double a = sizex / sizex;
		
		// get normale to lxy and fit it to rd1 coords, they are spin center now
		pair < double, double > lxyN = mather::rotateex(make_pair(lx, ly), pi / 2.0, make_pair(x, y));
		double r0x = (lxyN.first - x) / mather::distex(lxyN, make_pair(x, y)) * sizex / 2.0 + x;
		double r0y = (lxyN.second - y) / mather::distex(lxyN, make_pair(x, y)) * sizex / 2.0 + y;

		pair < double, double > xy = mather::rotateex(make_pair(x, y), a, make_pair(r0x, r0y));
		pair < double, double > lxy = mather::rotateex(make_pair(lx, ly), a, make_pair(r0x, r0y));

		x = xy.first, y = xy.second;
		lx = lxy.first, ly = lxy.second;

	}
	else {

		double s = rd * dt;
		pair < double, double > xylxy = make_pair(lx - x, ly - y);

		x = x + xylxy.first / mather::dist(xylxy) * s;
		y = y + xylxy.second / mather::dist(xylxy) * s;

		lx = lx + xylxy.first / mather::dist(xylxy) * s;
		ly = ly + xylxy.second / mather::dist(xylxy) * s;

	}

}

//#end
