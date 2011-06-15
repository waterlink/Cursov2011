#pragma once
#include "headers.h"

namespace Robot
{
    class /*__interface*/ IRobotHasLight
    {
    	public:
    	virtual ~IRobotHasLight(){}
    
        virtual void LightOn(void) = 0;
        virtual void LightOff(void) = 0;
    };
}
