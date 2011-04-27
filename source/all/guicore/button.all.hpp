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
//	class button
//	interface
//	gui button class
//

#ifndef button_hpp
#define button_hpp

#include "component.all.hpp"
#include "textable.all.hpp"
#include "activateble.all.hpp"
#include "enableble.all.hpp"
#include "sizeble.all.hpp"

class
button: 
	public component, 
	public textable, 
	public activateble,
	public enableble,
	public sizeble{

public:

	virtual
	~button() = 0;

protected:

	

private:

	

};

#endif

//#end
