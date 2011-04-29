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
//	class Wbutton
//	interface
//	gui class button version for winapi
//

#ifndef Wbutton_hpp
#define Wbutton_hpp

#include "../../all/guicore/button.all.hpp"

class
Wbutton: public button{

public:

	// component
	Wbutton(string name);
	~Wbutton();
	int dispatch(string message);
	void setparent(component * parent);
	component * getparent();
	string getname();

	// textable
	void settext(string text);
	string gettext();

	// activateble
	void setactivate(messager * onactivate);

	// enableble
	void enable();
	void disable();
	bool isenable();

	// sizeble
	pair < int, int > getsize();
	pair < int, int > getposition();
	void setsize(int w, int h);
	void setposition(int x, int y);

protected:

	

private:

	string name;
	component * parent;

	string text;

	messager * onactivate;

	bool enabled;

	pair < int, int > size;
	pair < int, int > position;

};

#endif

//#end
