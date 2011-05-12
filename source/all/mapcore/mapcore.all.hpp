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
//	class mapcore
//	interface
//	class mapcore, contains a map, loads and saves it, abstract
//

#ifndef map_hpp
#define map_hpp

#include <string>

using namespace std;

class
mapcore{

public:

	virtual ~mapcore(){}
	virtual void choose(string name) = 0;
	virtual void load() = 0;
	virtual void save() = 0;
	virtual int getvalue(int i, int j) = 0;
	virtual void setvalue(int i, int j, int v) = 0;

protected:

	

private:

	

};

#endif

//#end
