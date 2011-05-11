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
//	class Wform
//	interface
//	gui class form for winapi
//

#ifndef Wform_hpp
#define Wform_hpp

#include "../../all/guicore/form.all.hpp"

#include <map>
#include <string>

#include <windows.h>

using namespace std;

class
ihandled{

public:

	virtual ~ihandled(){}
	virtual HWND gethandle() = 0;
	virtual void sethandle(HWND handle) = 0;

};

class
Wform: public form, public ihandled{

public:

	Wform(string name);
	Wform();
	~Wform();

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

	map < string, component * > controls;
	bool visible;

	component * parent;
	string name;

	pair < int, int > position;
	pair < int, int > size;

	// winapi header
	HWND hwnd;

};

#endif

//#end
