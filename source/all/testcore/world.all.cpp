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

world::world(pather * decoder){ m = new test_simplemap(decoder); }
world::~world(){ delete m; }
int world::get(int x, int y){ m->getvalue(x, y); }
void world::set(int x, int y, int v){ m->setvalue(x, y, v); }

//#end
