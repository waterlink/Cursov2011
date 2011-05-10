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
//	class Wstatus
//	interface
//	gui class status for winapi
//

#ifndef Wstatus_hpp
#define Wstatus_hpp

#include "../../all/guicore/status.all.hpp"
#include "Wform.win.hpp"
#include <windows.h>

class
Wstatus: public status{

public:

	Wstatus();
	Wstatus(string name, Wform * parent);
	~Wstatus();

	// component
	int dispatch(string message);
	void setparent(component * parent);
	component * getparent();
	string getname();

	// textable
	void settext(string text);
	string gettext();

protected:

	

private:

	string name;
	component * parent;

	string text;

	UINT wId;

	HWND hSW;

};

#endif

//#end
