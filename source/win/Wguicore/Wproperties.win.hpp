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
//	class Wproperties
//	interface
//	gui class properties for winapi
//

#ifndef Wproperties_hpp
#define Wproperties_hpp

#include "../../all/guicore/properties.all.hpp"
#include "Wform.win.hpp"

#include <windows.h>

class
Wproperties: public properties, public ihandled{

public:

	Wproperties(string name, Wform * parent);
	Wproperties();
	~Wproperties();

	bool addproperty(string name, string value, string type);
	string getproperty(string name);
	bool delproperty(string name);

	// form methods
	void show();
	void close();
	void add(component * control);
	void del(string name);
	component * getcomponent(string name);

	// component methods
	int dispatch(string message);
	void setparent(component * parent);
	component * getparent();
	string getname();

	// sizeble methods
	pair < int, int > getsize();
	pair < int, int > getposition();
	void setsize(int w, int h);
	void setposition(int x, int y);

	// winapi-sensitive
	HWND gethandle();
	void sethandle(HWND handle);

protected:

	

private:

	Wform * myWform;
	HWND hwnd;
	string name;

	// name: < type, value >
	map < string, pair < string, string > > props;

};

#endif

//#end
