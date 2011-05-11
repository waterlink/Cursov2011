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
//	class sizeble
//	interface
//	interface for components with adjustable size'n'position
//

#ifndef sizeble_hpp
#define sizeble_hpp

#include <map>
#include <cstring>

#include "messager.all.hpp"

using namespace std;

class
sizeble{

public:

	sizeble(){ sizeble_markup = new char[8]; strcpy(sizeble_markup, "sizeble"); }

	virtual
	~sizeble() = 0;

	virtual pair < int, int >
	getsize() = 0;

	virtual pair < int, int >
	getposition() = 0;

	virtual void
	setsize(int w, int h) = 0;

	virtual void
	setposition(int x, int y) = 0;

	virtual void setresize(messager * onresize) = 0;
	virtual void setparentresize(messager * onparentresize) = 0;

	char * sizeble_markup;

protected:

	

private:

	

};

#endif

//#end
