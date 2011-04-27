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
//	class paintable
//	interface
//	interface for components that could freely paint on themselves
//

#ifndef paintable_hpp
#define paintable_hpp

#include "messager.all.hpp"

class
paintable{

public:

	virtual
	~paintable() = 0;	

	virtual void
	setpaint(messager * onpaint) = 0;

protected:

	

private:

	

};

#endif

//#end
