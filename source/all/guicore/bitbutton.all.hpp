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
//	class bitbutton
//	interface
//	gui class button with bitmap on it
//

#ifndef bitbutton_hpp
#define bitbutton_hpp

#include "component.all.hpp"
#include "textable.all.hpp"
#include "activateble.all.hpp"
#include "enableble.all.hpp"
#include "bitmapable.all.hpp"
#include "sizeble.all.hpp"

class
bitbutton:
	public component,
	public textable,
	public activateble,
	public enableble,
	public bitmapable,
	public sizeble{

public:

	virtual
	~bitbutton() = 0;

protected:

	

private:

	

};

#endif

//#end
