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

#include "../utilcore/logger.all.hpp"

propertymanager::propertymanager(properties * props){

	this->props = props;

}
propertymanager::~propertymanager(){}
void propertymanager::notification(mapmanager * sender){

	chosen = sender->getchosenmarker();
	new logger(10, "markercore--propertymanager::notification::debug: chosen marker\n");
	props->clearproperty();
	props->addproperty("beep", /*"true"*/ chosen->getoption("beep"), "bool");
	props->addproperty("light", /*"true"*/ chosen->getoption("light"), "bool");
	if (chosen->gettype() != "startpoint") 
		props->addproperty("optimal", /*"true"*/ chosen->getoption("optimal"), "bool");

}
void propertymanager::updatenotification(mapmanager * sender){

	chosen = sender->getchosenmarker();
	chosen->setoption("beep", props->getproperty("beep"));
	chosen->setoption("light", props->getproperty("light"));
	if (chosen->gettype() != "startpoint") 
		chosen->setoption("optimal", props->getproperty("optimal"));

}

//#end
