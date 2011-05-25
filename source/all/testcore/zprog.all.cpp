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
//	emulator class for z0rch's module
//

#include "zprog.all.hpp"

#include <cmath>
#include <ctime>

#include "../utilcore/mather.all.hpp"

zprog::zprog(btexecutor * btexec, robot * robo){

	this->btexec = btexec;
	this->robo = robo;

}
zprog::~zprog(){}

void zprog::passstartcoords(int sx, int sy, int lx, int ly){

	pos = make_pair(1.0 * sx, 1.0 * sy);
	look = make_pair(1.0 * lx, 1.0 * ly);

}
void zprog::moverel(int dx, int dy){

	moverelcommands.push_back(make_pair(dx, dy));

}

void zprog::beep(){

	withbeep.push_back(moverelcommands.size() - 1);

}
void zprog::setlight(bool fLight){

	if (fLight)
		withlighton.push_back(moverelcommands.size() - 1);
	else withlightoff.push_back(moverelcommands.size() - 1);

}

void zprog::run(){

	// TODO: code this up
	int withbeepPos = 0;
	int withlightonPos = 0;
	int withlightoffPos = 0;
	int commandsPos = -1;

	do {

		if (commandsPos > 0){

			realrelmove(moverelcommands[commandsPos].first, moverelcommands[commandsPos].first);
			if (btexec->getTouchSensorState())
				break;

		}

		if (withbeep.size() > 0)
			if (withbeep[withbeepPos] == commandsPos)
				robo->beep();

		if (withlighton.size() > 0)
			if (withlighton[withlightonPos] == commandsPos)
				robo->slight(true);

		if (withlightoff.size() > 0)
			if (withlightoff[withlightoffPos] == commandsPos)
				robo->slight(false);		

	} while (++commandsPos < moverelcommands.size());

}
/*

P0:
_______________________________________________

	   look
	   /			targ
	  /	    R-dist	*
	 /			b-angle
	*  a-angle					-> x
	sp

_______________________________________________

P1:
_______________________________________________


				look,targ
		    R	--------*
     a=b      ----------
	*-----
	sp
_______________________________________________

P2:

_______________________________________________

				targ  -------- look
				*-----
				sp
_______________________________________________

*/
void zprog::realrelmove(int dx, int dy){

	double mullifier = 100.0;
	double rotspeed = 0.3;
	double gospeed = 0.5;
	double maxspeed = robo->getmaxspeed();

	double rspeed = maxspeed * rotspeed;
	double gspeed = 2.0 * maxspeed * gospeed;
	double sizex = robo->getsize().first;

	pair < double, double > xylxy = make_pair(look.first - pos.first, look.second - pos.second);
	xylxy = mather::normalize(xylxy, 1.0);
	double a = acos(xylxy.first);
	if (xylxy.second < 0.0)
		a = 2.0 * mather::pi() - a;

	pair < double, double > xyt = make_pair(1.0 * dx, 1.0 * dy);
	xyt = mather::normalize(xyt, 1.0);
	double b = acos(xyt.first);
	if (xyt.second < 0.0)
		b = 2.0 * mather::pi() - b;

	a -= b;
	//a = -a;

	printf("a-angle: %.3lf\n", a);

	double R = sizex;
	double l = R * fabs(a);
	double ndt = l / rspeed;

	int counter = 0;

	double t = 1.0 * clock() / CLOCKS_PER_SEC;
	double dt = 0.0;

	if (a < -mather::epsilon()){

		btexec->setRD0power(rotspeed * mullifier);
		btexec->setRD1power(0.0);

	}
	else if (a > mather::epsilon()){

		btexec->setRD1power(rotspeed * mullifier);
		btexec->setRD0power(0.0);

	}

	if (a < 0.0) a = -a;

	if (a > mather::epsilon()){

		while (1){

			if (counter == 100){

				dt = 1.0 * clock() / CLOCKS_PER_SEC - t;
				if (dt >= ndt){

					btexec->setRD0power(0.0);
					btexec->setRD1power(0.0);
					break;

				}
				counter = 0;

			}

			++counter;

		}

	}

	l = mather::dist(make_pair(1.0 * dx, 1.0 * dy));
	ndt = l / gspeed;

	counter = 0;

	t = 1.0 * clock() / CLOCKS_PER_SEC;

	btexec->setRD0power(gospeed * mullifier);
	btexec->setRD1power(gospeed * mullifier);

	while (1){

		if (counter == 100){

			dt = 1.0 * clock() / CLOCKS_PER_SEC - t;
			if (dt >= ndt){

				btexec->setRD0power(0.0);
				btexec->setRD1power(0.0);
				break;

			}
			counter = 0;

		}

		++counter;

	}

	pos.first += 1.0 * dx;
	pos.second += 1.0 * dy;

	look.first = pos.first + 1.0 * dx;
	look.second = pos.second + 1.0 * dy;

}

//#end
