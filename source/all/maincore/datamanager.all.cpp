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

map < int, array * > datamanager::byid;
map < array *, int > datamanager::bydata;

array * datamanager::getbyid(int id){

	return byid[id];

}
int datamanager::getbydata(array * data){

	return bydata[data];

}
void datamanager::add(int id, array * data){

	byid[id] = data;
	bydata[data] = id;

}

//#end
