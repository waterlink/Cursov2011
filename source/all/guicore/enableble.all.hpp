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
//	class enableble
//	interface
//	interface for components that could be enabled or disabled
//

#ifndef enableble_hpp
#define enableble_hpp

class
enableble{

public:

	virtual
	~enableble() = 0;

	virtual void
	enable() = 0;

	virtual void
	disable() = 0;

protected:

	

private:

	

};

#endif

//#end
