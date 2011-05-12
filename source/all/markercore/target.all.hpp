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
//	class target
//	interface
//	class target - realization of marker
//

#ifndef target_hpp
#define target_hpp

#include "marker.all.hpp"

class
target: public marker{

public:

	target(){}
	~target(){}

	void setposition(int x, int y);
	pair < int, int > getposition();
	string getoption(string param);
	int getoption(string param, int);
	void setoption(string param, string value);
	void setoption(string param, int value);

protected:

	

private:

	pair < int, int > position;
	map < string, string > options;

};

#endif

//#end
