#pragma once
#include "IRobotRoute.h"
using namespace Robot;

class DummyRoute : public IRobotRoute
{
public:
    DummyRoute(double scale = 0.1) : IRobotRoute(scale) 
    {
        /*** HARD ROUTE
        srand(500);

        start[0] = Point(rand() % 10 - rand() % 10, rand() % 10 - rand() % 10);
        start[1] = Point(rand() % 10 - rand() % 10, rand() % 10 - rand() % 10);

        for(int i=0; i<10; i++)
            route.push_back(Point(rand() % 10 - rand() % 10, rand() % 10 - rand() % 10));
        */

        /**** 8 ***/
        start[0] = Point(2,0);
        start[1] = Point(3,1);
        route.push_back(Point(2,   1));
        route.push_back(Point(0,   2));
        route.push_back(Point(-2,  4));
        route.push_back(Point(-2,  6));
        route.push_back(Point(0,   7));
        route.push_back(Point(2,   6));
        route.push_back(Point(2,   4));
        route.push_back(Point(0,   2));
        route.push_back(Point(-2,  1));
        route.push_back(Point(-2, -1));
        route.push_back(Point(0,  -2));
        route.push_back(Point(2,  -1));
        route.push_back(Point(2,   0));

    }
    ~DummyRoute(void) {}
    
    RouteIterator Begin(void) { return route.begin(); }
    RouteIterator End(void)   { return route.end();   }
    Point GetStartPos(void)   { return start[0]; }
    Point GetOffset(void)     { return start[1]; }
private:
    std::list<Point> route;
    Point start[2];
};