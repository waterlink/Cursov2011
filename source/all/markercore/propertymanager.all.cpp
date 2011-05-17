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
//	class for managing properties of marker and its property window
//

#include "propertymanager.all.hpp"

propertymanager::propertymanager(properties * props){

	this->props = props;

}
propertymanager::~propertymanager(){}
void propertymanager::notification(mapmanager * sender){

	chosen = sender->getchosenmarker();

}

//#end
