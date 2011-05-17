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
//	class client
//	interface
//	main gui class, represents an application at all
//

#ifndef client_hpp
#define client_hpp

#include "component.all.hpp"
#include "form.all.hpp"

class
client: public component{

public:

	virtual
	~client() = 0;

	virtual int
	mainloop() = 0;

	virtual void
	newform(form * container, bool show) = 0;

	virtual void
	newmainform(form * container) = 0;

	virtual void update() = 0;

protected:

	

private:

	

};

#endif

//#end
