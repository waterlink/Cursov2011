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
//	world emulator
//

#include "world.all.hpp"

world::world(pather * decoder){ 

	m = new test_simplemap(decoder); 
	m->choose("testmap");
	m->load();

}
world::~world(){ delete m; }
int world::get(int x, int y){

	pair < int, int > size = m->getsize();
	if (x < 0 || x >= size.first ||
	    y < 0 || y >= size.second)
		return 0;
	int X = m->getvalue(x, y);
	if (X == -1) return 0;
	return 1;

}
void world::set(int x, int y, int v){ 

	int X = 0;
	if (v == 1) X = -1;
	else X = 1;
	m->setvalue(x, y, X);

}

//#end
