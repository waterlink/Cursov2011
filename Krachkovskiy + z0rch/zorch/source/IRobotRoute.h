#pragma once
#include <list>

namespace Robot
{
    struct Point
    {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y) {}
    };

    //-------------------------------------------------------------------------------
    //          Интерфейс маршрута для движения LEGO-робота    
    //
    // Методы:
    //    Итератор первой путевой точки.                  (Begin)
    //    Итератор путевой точки, следующей за последней. (End)
    //    Начальное положение робота.                     (GetStartPos)
    //    Начальное направление робота.                   (GetOffset)
    //   
    // Особенности:
    //    Маршрут задается в виде списка. (std::list<Point>)
    //    Необходимо указывать начальное положение робота и его текущее направление.
    //    Возможно масштабирование карты. (scale = meter / coordinate)
    //
    //                                                 Copyright © Базь Максим, 2011
    //                                                        ...also known as z0rch
    //------------------------------------------------------------------------------
    class IRobotRoute
    {
    public:
        IRobotRoute(double scale = 0.1) : scale(scale) {}
        virtual ~IRobotRoute(void) {}
        virtual double GetScale(void) { return scale; }
        
        typedef std::list<Point>::iterator RouteIterator;

        virtual RouteIterator Begin(void) = 0;
        virtual RouteIterator End(void)   = 0;
        virtual Point GetStartPos(void)   = 0;
        virtual Point GetOffset(void)     = 0;
    private:
        double scale;
    };
}
