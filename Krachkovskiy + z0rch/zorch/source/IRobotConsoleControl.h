#pragma once
#include "headers.h"
#include "IRobotRoute.h"

namespace Robot
{
    __interface IRobotConsoleControl
    {
        void OpenConnection(void);
        void CloseConnection(void);
        bool IsConnected(void);

        void PassRoute(IRobotRoute &route);
        wstring GetBattery(void);
    };
}