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
//	class for managing ID* for our components
//

#include "idmaster.win.hpp"

#include <cstdlib>

#define max_id 10000
#define min_id 100

map < int, component * > idmaster::ids;

int idmaster::gen(component * control){

	int x;

	do{

		x = rand() % (max_id - min_id) + min_id;

	} while ( ids[x] != NULL );

	ids[x] = control;
	return x;

}

map < int, component * > * idmaster::getmap(){ return &ids; }

//#end
