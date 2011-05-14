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
//	class markermanager
//	interface
//	class for managing markers, eg current selected marker type
//

#ifndef markermanager_hpp
#define markermanager_hpp

#include <string>

using namespace std;

class
markermanager{

public:

	markermanager();
	virtual ~markermanager();

	// select mode
	// startpoint mode
	// target mode
	// multitarget mode
	// free mode
	virtual string getcurrentmarkertype();
	virtual void setcurrentmarkertype(string type);

protected:

	

private:

	string markertype;

};

#endif

//#end
