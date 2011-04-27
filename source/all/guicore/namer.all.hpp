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
//	class namer
//	interface
//	class for managing component names
//

#ifndef namer_hpp
#define namer_hpp

#include <string>

#include "component.all.hpp"

using namespace std;

class
namer{

public:

	virtual
	~namer() = 0;

	virtual bool
	isavailable(string name) = 0;

	virtual component *
	byname(string name) = 0;

protected:

	

private:

	

};

#endif

//#end
