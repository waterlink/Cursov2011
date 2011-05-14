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
//	source file
//	class for managing markers
//

#include "markermap.all.hpp"

markermap::markermap(){}
markermap::~markermap(){}

void markermap::addmarker(marker * mar){ markers.insert(mar); }
void markermap::addedge(edge * edg){ edges.insert(edg); }

void markermap::delmarker(marker * mar){

	set < marker * >::iterator it = markers.lower_bound(mar);
	if (it != markers.end())
		if (*it == mar){

			delete *it;
			markers.erase(it);

		}

}
void markermap::deledge(edge * edg){

	set < edge * >::iterator it = edges.lower_bound(edg);
	if (it != edges.end())
		if (*it == edg){

			delete *it;
			edges.erase(it);

		}

}

void markermap::catmarker(){ markeriter = markers.begin(); }
marker * markermap::catnextmarker(){ 

	if (markeriter == markers.end())
		return catlastmarker();
	marker * res = *markeriter;
	++markeriter;
	return res;

}
marker * markermap::catlastmarker(){ return 0; }

void markermap::catedge(){ edgeiter = edges.begin(); }
edge * markermap::catnextedge(){ 

	if (edgeiter == edges.end())
		return catlastedge();
	edge * res = *edgeiter;
	++edgeiter;
	return res;

}
edge * markermap::catlastedge(){ return 0; }

void markermap::clear(){

	for (set < marker * >::iterator it = markers.begin(); it != markers.end(); ++it)
		delete *it;
	markers.clear();

	for (set < edge * >::iterator it = edges.begin(); it != edges.end(); ++it)
		delete *it;
	edges.clear();

}

//#end
