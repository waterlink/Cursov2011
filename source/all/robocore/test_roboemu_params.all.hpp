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
//	class test_roboemu_params
//	interface
//	robot emulator, contains parameters, and full map
//

#ifndef test_roboemu_params_hpp
#define test_roboemu_params_hpp

#include <string>

using namespace std;

class
test_roboemu_params{

public:

	int
	x, y, lx, ly;

	double
	rd0, rd1;

	bool
	**map;

	int
	xmapsize,
	ymapsize;

	void
	loadmap(string path);

protected:

	

private:

	

};

#endif

//#end
