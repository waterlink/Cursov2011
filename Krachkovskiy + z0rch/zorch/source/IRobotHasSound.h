#pragma once
#include "headers.h"

namespace Robot
{
    __interface IRobotHasSound
    {
        void SoundOn(void);
        void SoundOff(void);
    };
}