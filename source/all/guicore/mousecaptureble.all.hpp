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
//	class mousecaptureble
//	interface
//	interface for objects that captures a mouse move & click
//

#ifndef mousecaptureble_hpp
#define mousecaptureble_hpp

#include "messager.all.hpp"

class
mousecaptureble{

public:

	virtual
	~mousecaptureble() = 0;	

	virtual void
	setmousedown(messager * onmousedown) = 0;

	virtual void
	setmouseup(messager * onmouseup) = 0;

	virtual void
	setmousemove(messager * onmousemove) = 0;

protected:

	

private:

	

};

#endif

//#end
