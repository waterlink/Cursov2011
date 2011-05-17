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
//	class improg
//	interface
//	interface for connecting with Markelov's module
//

#ifndef improg_hpp
#define improg_hpp

#include <vector>
#include <string>

using namespace std;

class
improg{

public:

	virtual ~improg(){}
	virtual vector < pair < int, int > > getway(pair < int, int > A, pair < int, int > B, string mapname) = 0;

protected:

	

private:

	

};

#endif

//#end
