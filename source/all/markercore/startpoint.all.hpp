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
//	class startpoint
//	interface
//	class startpoint - realization of marker
//

#ifndef startpoint_hpp
#define startpoint_hpp

#include "marker.all.hpp"

class
startpoint: public marker{

public:

	startpoint(){}
	~startpoint(){}

	void setposition(int x, int y);
	pair < int, int > getposition();
	string getoption(string param);
	int getoption(string param, int);
	void setoption(string param, string value);
	void setoption(string param, int value);

	string gettype();

	virtual void detect();

protected:

	

private:

	pair < int, int > position;
	map < string, string > options;

};

#endif

//#end
