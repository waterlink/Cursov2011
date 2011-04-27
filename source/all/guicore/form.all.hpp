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
//	class form
//	interface
//	the form class, it's like a window class, abstract
//

#ifndef form_hpp
#define form_hpp

#include "component.all.hpp"
#include "sizeble.all.hpp"

class
form: 
	public component,
	public sizeble{

public:

	virtual
	~form() = 0;

	virtual void
	show() = 0;

	virtual void
	close() = 0;

	virtual void
	add(component * control) = 0;

	virtual void
	del(string name) = 0;

	virtual component *
	getcomponent(string name) = 0;

protected:

	

private:

	

};

#endif

//#end
