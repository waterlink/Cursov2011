#pragma once
#include <list>
using namespace std;

namespace Robot
{
    struct Point
    {
        int x, y;
        Point(int x = 0, int y = 0)
        {
            this -> x = x;
            this -> y = y;
        }
    };

    typedef list<Point>::iterator PointIterator;

    class IRobotCoordinates
    {
    public:
        PointIterator begin(void) { return coord.begin(); }
        PointIterator end(void)   { return coord.end();   }
    
    protected:
        Point firstDirection;
        list<Point> coord;
    };
}