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
//	header file
//	class world
//	interface
//	world emulator
//

#ifndef world_hpp
#define world_hpp

#include <map>

using namespace std;

#include "../filecore/filesystem.all.hpp"
#include "../mapcore/test_simplemap.all.hpp"
#include "../filecore/pather.all.hpp"

class
world{

public:

	world(pather * decoder);
	virtual ~world();
	virtual int get(int x, int y);
	virtual void set(int x, int y, int v);

protected:

	

private:

	mapcore * m;

};

#endif

//#end
