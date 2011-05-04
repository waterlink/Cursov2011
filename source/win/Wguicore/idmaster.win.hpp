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
//	class idmaster
//	interface
//	class for managing ID* for our components
//

#ifndef idmaster_hpp
#define idmaster_hpp

#include "../../all/guicore/component.all.hpp"

#include <map>

using namespace std;

class
idmaster{

public:

	static int gen(component * control);
	static map < int, component * > * getmap();

protected:

	

private:

	static map < int, component * > ids;

};

#endif

//#end
