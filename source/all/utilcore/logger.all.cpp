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
//	source file
//	class used to do logging into stderr
//

#include "logger.all.hpp"

#include <cstdio>

logger::logger(int level, string message){

	int maxlevel = settings::get("loglevel", 0);
	if (level == 0 && !(maxlevel >= level))
		fprintf(stderr, "utilcore--logger::logger::log_fatal: level: %d, maxlevel: %d, message: %s\n", 
				level, maxlevel, message.c_str());
	if (maxlevel >= level){

		fprintf(stderr, message.c_str());

	}
	delete this;

}
logger::~logger(){}

//#end
