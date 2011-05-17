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

class mapmanager;

#include "mapcore.all.hpp"
#include "../markercore/markermap.all.hpp"
#include "../guicore/view.all.hpp"
#include "../markercore/markermap.all.hpp"
#include "../markercore/markermanager.all.hpp"
#include "mapsync.all.hpp"
#include "../markercore/propertymanager.all.hpp"

//	#refactor

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

	virtual void connecttomarkermanager(markermanager * chosentype);
	virtual markermanager * extractmarkermanager();

	virtual int getmapvalue(int i, int j);
	virtual void setmapvalue(int i, int j, int v);

	virtual marker * getcurrenttarget();
	virtual void gotolasttarget();
	virtual void clearstartpoint();
	virtual void choosestartpoint();
	virtual void clearoffset();

	virtual void clear();

	virtual void setchosenmarker(marker * mar);
	virtual marker * getchosenmarker();

	// for future purposes
	virtual void setchosenedge(edge * edg);
	virtual edge * getchosenedge();

	virtual marker * findnearest(pair < int, int > pos);

	virtual void setuppropertymanager(propertymanager * propertydestination);
	virtual void propertynotify();

protected:

	

private:

	mapcore * mapsource;
	markermap * markersource;
	view * viewdestination;

	marker * chosenmarker;
	edge * chosenedge;		// for future purposes

	markermanager * chosentype;

	marker * currenttarget;

	mapsync * bitsync;

	propertymanager * propertydestination;

};

//	#refactorend

#endif

//#end
