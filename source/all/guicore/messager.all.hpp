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
//	class messager
//	interface
//	delegate-method class for messaging
//

#ifndef messager_hpp
#define messager_hpp

#include <string>

#include "component.all.hpp"

using namespace std;

class
messager{

public:

	virtual
	~messager() = 0;

	virtual void
	operator ()(component * sender, string message) = 0;

protected:

	

private:

	

};

#define EHandler(name, x) \
	\
	class on##name: public messager{ public: on##name(){} ~on##name(){} \
	void operator ()(component * sender, string message) x \
} * name = new on##name();

#endif

//#end
