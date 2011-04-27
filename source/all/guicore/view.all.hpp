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
//	class view
//	interface
//	gui view class
//

#ifndef view_hpp
#define view_hpp

#include "component.all.hpp"
#include "sizeble.all.hpp"
#include "mousecaptureble.all.hpp"
#include "paintable.all.hpp"

class
view:
	public component,
	public sizeble,
	public mousecaptureble,
	public paintable{

public:

	virtual
	~view() = 0;

protected:

	

private:

	

};

#endif

//#end
