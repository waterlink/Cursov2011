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
//	class mapsync
//	interface
//	class to sync bits and map
//

#ifndef mapsync_hpp
#define mapsync_hpp

#include "mapcore.all.hpp"
#include "../maincore/datamanager.all.hpp"

class
mapsync{

public:

	mapsync(mapcore * mapsource, array * bitsource);
	virtual ~mapsync();
	// from array to map
	virtual void msync();
	// from map to array
	virtual void bsync();

protected:

	

private:

	mapcore * mapsource;
	array * bitsource;

};

#endif

//#end
