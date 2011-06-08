#pragma once
#include "headers.h"

namespace Robot
{
    class /*__interface*/ IRobotHasSound
    {
    	public:
    	virtual ~IRobotHasSound(){}
    
        virtual void SoundOn(void) = 0;
        virtual void SoundOff(void) = 0;
    };
}
