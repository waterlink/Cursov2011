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
//	class Wtoolbox
//	interface
//	gui class toolbox for winapi
//

#ifndef Wtoolbox_hpp
#define Wtoolbox_hpp

#include <string>

#include "../../all/guicore/toolbox.all.hpp"
#include "Wform.win.hpp"

using namespace std;

class
Wtoolbox: public toolbox, public ihandled{

public:

	Wtoolbox();
	Wtoolbox(string name, Wform * parent);
	~Wtoolbox();

	component * getactivecontrol();
	void setactivecontrol(component * control);

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
	void setresize(messager * onresize);
	void setparentresize(messager * onparentresize);

	// winapi-sensitive
	HWND gethandle();
	void sethandle(HWND handle);

protected:

	

private:

	Wform * myWform;
	HWND hwnd;
	component * activecontrol;
	string name;

};

#endif

//#end
