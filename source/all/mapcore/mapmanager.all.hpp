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
//	class mapmanager
//	interface
//	class to manage map, markermap and view it all
//

#ifndef mapmanager_hpp
#define mapmanager_hpp

#include "mapcore.all.hpp"
#include "../markercore/markermap.all.hpp"
#include "../guicore/view.all.hpp"

class
mapmanager{

public:

	mapmanager(mapcore * mapsource, markermap * markersource, view * viewdestination);
	virtual ~mapmanager();

	virtual void connecttoview();
	virtual void redraweverything();
	virtual void addmarker(marker * mar);
	virtual void delmarker(marker * mar);
	virtual void addedge(edge * edg);
	virtual void deledge(edge * edg);

	virtual pair < int, int > decodeposition(marker * mar);
	virtual pair < int, int > decodeposition(pair < int, int > pos);

protected:

	

private:

	mapcore * mapsource;
	markermap * markersource;
	view * viewdestination;

	marker * chosenmarker;
	edge * chosenedge;

};

#endif

//#end
