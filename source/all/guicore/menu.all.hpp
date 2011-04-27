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
//	class menu
//	interface
//	gui menu component
//

#ifndef menu_hpp
#define menu_hpp

#include "component.all.hpp"
#include "messager.all.hpp"
#include "textable.all.hpp"
#include "activateble.all.hpp"
#include "selectable.all.hpp"
#include "enableble.all.hpp"

class
menu: 
	public component, 
	public textable, 
	public activateble, 
	public selectable, 
	public enableble{

public:

	virtual
	~menu() = 0;

	virtual bool
	ispopup() = 0;

	virtual void
	add(menu * submenu) = 0;

protected:

	

private:

	

};

#endif

//#end
