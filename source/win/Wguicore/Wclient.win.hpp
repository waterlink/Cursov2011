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
//	class Wclient
//	interface
//	gui class client for winapi
//

#ifndef Wclient_hpp
#define Wclient_hpp

#include "../../all/guicore/client.all.hpp"

#include <windows.h>

long WINAPI wndproc(HWND,UINT,UINT,LONG);

class
Wclient: public client{

public:

	// client methods
	Wclient(string name);
	~Wclient();
	int mainloop();
	void newform(form * container, bool show);
	void newmainform(form * container);

	// component methods
	int dispatch(string message);
	void setparent(component * parent);
	component * getparent();
	string getname();

	void update();

protected:

	

private:

	map < string, component * > forms;
	string mainform;

	string name;

};

#endif

//#end
