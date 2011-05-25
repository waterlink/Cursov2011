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

#define maxspeed 1.5
#define sizex 1.0
#define sizey 1.0

/*
		lxy
	-------------------  1.0 - sizex
	X0	 ^	 3X
|	 |-------|-------|
|	 |	 |	 |
|	r|0	 |	1|r
|<-	r|0	 *	1|r	->
|	r|0	 xy	1|r
|	 |		 |
|	 |---------------|
	X1		 2X
1.0 - sizey

*/

robot::robot(world * w){ 

	this->w = w; 
	rd0 = rd1 = 0.0;
	t = 1.0 * clock() / CLOCKS_PER_SEC;

}
robot::~robot(){}
double robot::grd0(){ 

	return rd0; 

}
double robot::grd1(){ 

	return rd1; 

}
void robot::srd(double v0, double v1){ 

	update();
	rd0 = v0, rd1 = v1; 

}
bool robot::gtouch(){

	// TODO: code this function, it must interact with world object somehow
	update();
	return touch;

}
double robot::gsight(){

	// TODO: code this function, it must interact with world object somehow
	update();
	double dx = lx - x;
	double dy = ly - y;

	int xflag = 1;
	if (dy > dx) xflag = 0;

	for (int i = 0; ; ++i){

		double ddx = dx * i;
		double ddy = dy * i;
		if (xflag)
			ddx = i, ddy /= dx;
		else
			ddx /= dy, ddy = i;

		int nx = (int)(x + ddx);
		int ny = (int)(y + ddy);

		if (w->get(nx, ny)){

			return mather::distex(make_pair(x, y), make_pair(1.0 * nx, 1.0 * ny));	// return dist here
			break;	// and break

		}

	}

}
void robot::slight(bool f){

	update();
	if (f) new logger(0, "testcore--robot::slight::test: message:light_enabled \n");
	else new logger(0, "testcore--robot::slight::test: message:light_disabled \n");

}
void robot::beep(){

	update();
	new logger(0, "testcore--robot::beep::test: message:beep \n");

}
void robot::update(){

	double pi = acos(-1.0);

	double nt = 1.0 * clock() / CLOCKS_PER_SEC;
	double dt = nt - t;

	t = nt;

	double oldx = x, oldy = y; 
	double oldlx = lx, oldly = ly;

	if (fabs(rd0 - rd1) > mather::epsilon() && fabs(rd0) > mather::epsilon() && fabs(rd1) > mather::epsilon()){

		new logger(0, "testcore--robot::update::test: message:breaked \n");
		return;

	}

	double rd = max(rd0, rd1) * maxspeed / 100.0;

	if (fabs(rd0 - rd1) < mather::epsilon()) {

		double s = 2.0 * rd * dt;
		pair < double, double > xylxy = make_pair(lx - x, ly - y);

		x = x + xylxy.first / mather::dist(xylxy) * s;
		y = y + xylxy.second / mather::dist(xylxy) * s;

		lx = lx + xylxy.first / mather::dist(xylxy) * s;
		ly = ly + xylxy.second / mather::dist(xylxy) * s;

	}
	else if (rd0 > rd1){

		double l = rd * dt;

		double R = sizex;
		double a = l / R;
		
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

		double R = sizex;
		double a = l / R;
		
		// get normale to lxy and fit it to rd1 coords, they are spin center now
		pair < double, double > lxyN = mather::rotateex(make_pair(lx, ly), pi / 2.0, make_pair(x, y));
		double r0x = (lxyN.first - x) / mather::distex(lxyN, make_pair(x, y)) * sizex / 2.0 + x;
		double r0y = (lxyN.second - y) / mather::distex(lxyN, make_pair(x, y)) * sizex / 2.0 + y;

		pair < double, double > xy = mather::rotateex(make_pair(x, y), a, make_pair(r0x, r0y));
		pair < double, double > lxy = mather::rotateex(make_pair(lx, ly), a, make_pair(r0x, r0y));

		x = xy.first, y = xy.second;
		lx = lxy.first, ly = lxy.second;

	}

	char logbuf[50];
	sprintf(
		logbuf, 
		"testcore--robot::update::test: message:moved x:%d y:%d lx:%d ly:%d t:%d \n", 
		(int)x, (int)y, (int)lx, (int)ly, (int)t
	);
	new logger(0, logbuf);

	if (!test()){

		x = oldx, y = oldy;
		lx = oldlx, ly = oldly;
		rd0 = rd1 = 0.0;
		touch = true;
		new logger(0, "testcore--robot::update::test: message:touched \n");

	}
	else { 

		touch = false;

	}

}

bool robot::test(){

	double pi = acos(-1.0);
	// get lxy rotated by 45 grads X0..3
	pair < double, double > X0 = mather::normalizeex(
		mather::rotateex(make_pair(lx, ly), 1.0 * pi / 4.0, make_pair(x, y)),
		mather::dist(make_pair(sizex / 2.0, sizey / 2.0)),
		make_pair(x, y)
	);
	pair < double, double > X1 = mather::normalizeex(
		mather::rotateex(make_pair(lx, ly), 3.0 * pi / 4.0, make_pair(x, y)),
		mather::dist(make_pair(sizex / 2.0, sizey / 2.0)),
		make_pair(x, y)
	);
	pair < double, double > X2 = mather::normalizeex(
		mather::rotateex(make_pair(lx, ly), 5.0 * pi / 4.0, make_pair(x, y)),
		mather::dist(make_pair(sizex / 2.0, sizey / 2.0)),
		make_pair(x, y)
	);
	pair < double, double > X3 = mather::normalizeex(
		mather::rotateex(make_pair(lx, ly), 7.0 * pi / 4.0, make_pair(x, y)),
		mather::dist(make_pair(sizex / 2.0, sizey / 2.0)),
		make_pair(x, y)
	);

	double 	xmin = min(X0.first, X1.first);
		xmin = min(xmin, X2.first);
		xmin = min(xmin, X3.first);

	double 	ymin = min(X0.second, X1.second);
		ymin = min(ymin, X2.second);
		ymin = min(ymin, X3.second);

	double 	xmax = max(X0.first, X1.first);
		xmax = max(xmax, X2.first);
		xmax = max(xmax, X3.first);

	double 	ymax = max(X0.second, X1.second);
		ymax = max(ymax, X2.second);
		ymax = max(ymax, X3.second);

	int x1 = (int)xmin;
	int y1 = (int)ymin;
	int x2 = (int)(xmax - mather::epsilon() + 1.0);
	int y2 = (int)(ymax - mather::epsilon() + 1.0);

	bool res = true;

	for (int i = x1; i <= x2; ++i)
		for (int j = y1; j <= y2; ++j)
			if (w->get(i, j))
				res = false;

	return res;

}
double robot::getmaxspeed(){

	return maxspeed;

}

pair < double, double > robot::getsize(){

	return make_pair(sizex, sizey);

}

void robot::setupcorrds(pair < int, int > pos){

	x = 1.0 * pos.first;
	y = 1.0 * pos.second;

}
void robot::setuplook(pair < int, int > look){

	lx = 1.0 * look.first;
	ly = 1.0 * look.second;

}

//#end
