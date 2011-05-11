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
//	class for independent coordinating for child forms
//

#include "metrics.all.hpp"

void metrics::set(int x, int y){

	settings::set("metrics.x", x);
	settings::set("metrics.y", y);

}
pair < int, int > metrics::get(){

	int x = settings::get("metrics.x", 0);
	int y = settings::get("metrics.y", 0);
	return make_pair(x, y);

}

//#end
