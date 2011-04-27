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
//	class properties
//	interface
//	gui property table class
//

#ifndef properties_hpp
#define properties_hpp

#include <string>

using namespace std;

#include "form.all.hpp"

class
properties: 
	public form{

public:

	virtual
	~properties() = 0;

	virtual bool
	addproperty(string name, string value, string type) = 0;

	virtual string
	getproperty(string name) = 0;

	virtual bool
	delproperty(string name) = 0;

protected:

	

private:

	

};

#endif

//#end
