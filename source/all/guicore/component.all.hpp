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
//	class component
//	interface
//	this is just an abstract component class
//

#ifndef component_hpp
#define component_hpp

#include <string>

using namespace std;

class
component{

public:

	virtual
	~component() = 0;

	virtual int
	dispatch(string message) = 0;

	virtual void
	setparent(component * parent) = 0;

	virtual component *
	getparent() = 0;

	virtual string
	getname() = 0;

protected:

	

private:

	

};

#endif

//#end
