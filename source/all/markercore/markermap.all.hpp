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
//	class markermap
//	interface
//	class for managing markers
//

#ifndef markermap_hpp
#define markermap_hpp

#include "marker.all.hpp"
#include "edge.all.hpp"

#include <set>

using namespace std;

class
markermap{

public:

	markermap();
	virtual ~markermap();

	virtual void addmarker(marker * mar);
	virtual void addedge(edge * edg);
	virtual void delmarker(marker * mar);
	virtual void deledge(edge * edg);

	virtual void catmarker();
	virtual marker * catnextmarker();
	virtual marker * catlastmarker();

	virtual void catedge();
	virtual edge * catnextedge();
	virtual edge * catlastedge();

protected:

	

private:

	set < marker * > markers;
	set < edge * > edges;

	set < marker * >::iterator markeriter;
	set < edge * >::iterator edgeiter;

};

#endif

//#end
