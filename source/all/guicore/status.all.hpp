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
//	class status
//	interface
//	gui status bar class
//

#ifndef status_hpp
#define status_hpp

#include "component.all.hpp"
#include "textable.all.hpp"

class
status: 
	public component,
	public textable{

public:

	virtual
	~status() = 0;

protected:

	

private:

	

};

#endif

//#end
