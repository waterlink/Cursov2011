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
//	class selectable
//	interface
//	interface for components that could be selected
//

#ifndef selectable_hpp
#define selectable_hpp

#include "messager.all.hpp"

class
selectable{

public:

	virtual
	~selectable() = 0;

	virtual void
	setselect(messager * onselect) = 0;

protected:

	

private:

	

};

#endif

//#end
