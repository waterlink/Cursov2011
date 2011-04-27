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
//	class toolbox
//	interface
//	gui toolbox class
//

#ifndef toolbox_hpp
#define toolbox_hpp

#include "form.all.hpp"

class
toolbox: public form{

public:

	virtual
	~toolbox() = 0;

	virtual component *
	getactivecontrol() = 0;

	virtual void
	setactivecontrol(component * control) = 0;

protected:

	

private:

	

};

#endif

//#end
