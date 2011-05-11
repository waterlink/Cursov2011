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
//	class logger
//	interface
//	class used to do logging into stderr
//

#ifndef logger_hpp
#define logger_hpp

#include "settings.all.hpp"

#include <string>

using namespace std;

class
logger{

public:

	logger(int level, string message);
	~logger();

protected:

	

private:

	

};

#endif

//#end
