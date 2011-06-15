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
//	z0rch module adapter, win specification
//

#include "Wzprog.win.hpp"

using namespace Robot;

#include "../../../Wzprog/IRobotRoute.h"
#include "../../all/utilcore/logger.all.hpp"

class Wzprog::FileRoute : public IRobotRoute
    {
    public:
        FileRoute(double scale, Point startPos, Point offset)
            :IRobotRoute(scale), start(startPos), offset(offset)
        {}

        RouteIterator Begin(void) { return route.begin(); }
        RouteIterator End(void)   { return route.end();   }
        Point GetStartPos(void)   { return start;         }
        Point GetOffset(void)     { return offset;        }

        void Push(Point p)        { route.push_back(p);   }
    private:
        list<Point> route;
        Point start, offset;

    };

Wzprog::Wzprog(){

	fileRoute = 0;

}
Wzprog::~Wzprog(){

	if (fileRoute)
		delete fileRoute;

}

void Wzprog::passstartcoords(int sx, int sy, int lx, int ly){

	fileRoute = new FileRoute(0.1, Point(sx, sy), Point(lx, ly));
	this->sx = sx;
	this->sy = sy;
	this->lx = lx;
	this->ly = ly;

}
void Wzprog::moverel(int dx, int dy){

	Point topush;
	IRobotRoute::RouteIterator iter = fileRoute->End();
	if (fileRoute->Begin() == fileRoute->End())
		topush = Point(sx + dx, sy + dy);
	else{
	
		iter--;
		topush = Point(iter->x + dx, iter->y + dy);
	
	}
	fileRoute->Push(topush);

}
void Wzprog::beep(){

	// this functionallity in zprog doesn't exists for now

}
void Wzprog::setlight(bool fLight){

	// this functionallity in zprog doesn't exists for now

}
void Wzprog::run(){

	static bool openedconnection = false;
	if (!openedconnection) try{
		RobotControl::InitInstance()->OpenConnection();
		openedconnection = true;
	} catch (...){
		new logger(-1, "failed to open connection\n");
	}
	try{
		RobotControl::InitInstance()->PassRoute(*fileRoute);
	} catch (...){
		new logger(-1, "failed to pass route\n");
	}
	/*try{
		RobotControl::InitInstance()->CloseConnection();
	} catch (...){
		new logger(-1, "failed to close connection\n");
	}*/

}

//#end
