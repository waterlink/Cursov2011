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
//	class Wmenu
//	interface
//	gui class menu for winapi
//

#ifndef Wmenu_hpp
#define Wmenu_hpp

#include <string>
#include <vector>

using namespace std;

#include "../../all/guicore/menu.all.hpp"
#include "Wform.win.hpp"

#include <windows.h>

class
Wmenu: public menu, public ihandled{

public:

	// menu methods
	Wmenu(string name, bool popup);
	Wmenu(string name);
	Wmenu();
	Wmenu(string name, Wform * parent);
	Wmenu(string name, Wmenu * parent, bool popup);
	~Wmenu();
	bool ispopup();
	void add(menu * submenu);

	// component methods
	int dispatch(string message);
	void setparent(component * parent);
	component * getparent();
	string getname();

	//textable methods
	void settext(string text);
	string gettext();

	// activateble methods
	void setactivate(messager * onactivate);

	// selectable methods
	void setselect(messager * onselect);

	// enableble methods
	void enable();
	void disable();
	bool isenable();

	// winapi-sensitive
	HWND gethandle();
	void sethandle(HWND handle);

protected:

	

private:

	bool popup;
	vector < menu * > submenus;

	component * parent;
	string name;

	string text;

	messager * onactivate;
	messager * onselect;

	bool enabled;

	HMENU hm;

};

#endif

//#end
