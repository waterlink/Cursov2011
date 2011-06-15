#pragma once
#include "headers.h"
#include "IRobotRoute.h"

namespace Robot
{
    /*__interface*/ class IRobotConsoleControl
    {
    	public:
    	virtual ~IRobotConsoleControl(){}
    
        virtual void OpenConnection(void) = 0;
        virtual void CloseConnection(void) = 0;
        virtual bool IsConnected(void) = 0;

        virtual void PassRoute(IRobotRoute &route) = 0;
        virtual wstring GetBattery(void) = 0;
    };
}
