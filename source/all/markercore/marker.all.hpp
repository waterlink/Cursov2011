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
//	class marker
//	interface
//	class marker, abstract
//

#ifndef marker_hpp
#define marker_hpp

#include <map>
#include <string>

using namespace std;

class
marker{

public:

	virtual ~marker(){}
	virtual void setposition(int x, int y) = 0;
	virtual pair < int, int > getposition() = 0;
	virtual string getoption(string param) = 0;
	virtual int getoption(string param, int) = 0;
	virtual void setoption(string param, string value) = 0;
	virtual void setoption(string param, int value) = 0;

protected:

	

private:

	

};

#endif

//#end
