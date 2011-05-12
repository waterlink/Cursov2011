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
//	class test_simplemap
//	interface
//	class map, realization, for test purposes
//

#ifndef test_simplemap_hpp
#define test_simplemap_hpp

#include "mapcore.all.hpp"
#include "../filecore/filesystem.all.hpp"
#include "../filecore/file.all.hpp"
#include "../filecore/pather.all.hpp"

#include <map>

using namespace std;

class
test_simplemap: public mapcore{

public:

	test_simplemap(pather * decoder);
	~test_simplemap(){}
	void choose(string name);
	void load();
	void save();
	int getvalue(int i, int j);
	void setvalue(int i, int j, int v);

protected:

	

private:

	// 0 - unknown
	// 1 - free
	// -1 - obstacle
	map < pair < int, int >, int > M;

	filesystem * fs;
	file * mapfile;

};

#endif

//#end
