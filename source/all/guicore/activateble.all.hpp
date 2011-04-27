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
//	header file
//	class activateble
//	interface
//	interface for objects, that could be activated
//

#ifndef activateble_hpp
#define activateble_hpp

#include "messager.all.hpp"

class
activateble{

public:

	virtual
	~activateble() = 0;

	virtual void
	setactivate(messager * onactivate) = 0;

protected:

	

private:

	

};

#endif

//#end
