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
//	class textable
//	interface
//	interface for objects with text
//

#ifndef textable_hpp
#define textable_hpp

#include <string>

using namespace std;

class
textable{

public:

	virtual
	~textable() = 0;

	virtual void
	settext(string text) = 0;

	virtual string
	gettext() = 0;

protected:

	

private:

	

};

#endif

//#end
