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
//	class propertymanager
//	interface
//	class for managing properties of marker and its property window
//

#ifndef propertymanager_hpp
#define propertymanager_hpp

class propertymanager;

#include "../guicore/properties.all.hpp"
#include "../mapcore/mapmanager.all.hpp"

class
propertymanager{

public:

	propertymanager(properties * props);
	virtual ~propertymanager();
	virtual void notification(mapmanager * sender);

protected:

	

private:

	properties * props;
	marker * chosen;

};

#endif

//#end
