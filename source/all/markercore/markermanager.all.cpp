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
//	class for managing markers, eg current selected marker type
//

#include "markermanager.all.hpp"

markermanager::markermanager(){ markertype = "selectmode"; }
markermanager::~markermanager(){}

string markermanager::getcurrentmarkertype(){ return markertype; }
void markermanager::setcurrentmarkertype(string type){ markertype = type; }

//#end
