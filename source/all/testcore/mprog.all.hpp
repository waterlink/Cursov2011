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
//	class mprog
//	interface
//	emulator class for makelov's module
//

#ifndef mprog_hpp
#define mprog_hpp

#include "../robocore/improg.all.hpp"
#include "../mapcore/mapcore.all.hpp"

class
mprog: public improg{

public:

	mprog(mapcore * mc);
	~mprog();

	vector < pair < int, int > > getway(pair < int, int > A, pair < int, int > B, string mapname);

protected:

	

private:

	mapcore * mc;

};

#endif

//#end
