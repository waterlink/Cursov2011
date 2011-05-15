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
//	class directionoffset
//	interface
//	class for managing current direction of robot
//

#ifndef directionoffset_hpp
#define directionoffset_hpp

#include "marker.all.hpp"

#include <map>
#include <string>

using namespace std;

class
directionoffset: public marker{

public:

	directionoffset();
	~directionoffset();
	void setposition(int x, int y);
	pair < int, int > getposition();
	string getoption(string param);
	int getoption(string param, int);
	void setoption(string param, string value);
	void setoption(string param, int value);
	string gettype();

protected:

	

private:

	pair < int, int > position;
	map < string, string > options;

};

#endif

//#end
