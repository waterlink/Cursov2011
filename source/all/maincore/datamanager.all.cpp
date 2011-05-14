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
//	class for managing huge datastructures
//

#include "datamanager.all.hpp"

map < int, void * > datamanager::byid;
map < void *, int > datamanager::bydata;

void * datamanager::getbyid(int id){

	return byid[id];

}
int datamanager::getbydata(void * data){

	return bydata[data];

}
void datamanager::add(int id, void * data){

	byid[id] = data;
	bydata[data] = id;

}

//#end
