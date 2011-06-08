#pragma once
#include "headers.h"

namespace Robot
{
    __interface IRobotHasLight
    {
        void LightOn(void);
        void LightOff(void);
    };
}