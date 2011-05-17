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
//	optimal strategy for targets
//

#include "targetoptimal.all.hpp"

targetoptimal::targetoptimal(){}
targetoptimal::~targetoptimal(){}
void targetoptimal::setupmarkersource(markermap * markersource){ this->markersource = markersource; }
bool targetoptimal::go(){

	vector < pair < int, int > > way;
	vector < marker * > markers;
	map < marker *, int > mark;
	vector < edge * > edges;
	marker * offset;
	int start = -1;

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		if (mar->gettype() == "startpoint" || mar->gettype() == "target")
			markers.push_back(mar), mark[mar] = markers.size() - 1;
		if (mar->gettype() == "startpoint")
			start = markers.size() - 1;
		if (mar->gettype() == "directionoffset")
			offset = mar;

	}

	int E[markers.size()];
	for (int i = 0; i < markers.size(); ++i) E[i] = -1;

	edge * edg;
	for (markersource->catedge(); (edg = markersource->catnextedge()) != markersource->catlastedge(); ){

		if (edg->getB()->gettype() == "target")
			E[mark[edg->getA()]] = mark[edg->getB()];

	}

	int curr = start;
	for (; curr >= 0; ){

		int next = E[curr];
		vector < pair < int, int > > eway = mprog->getway(markers[curr]->getposition(), markers[next]->getposition(), mapname);
		if (eway.size() == 0)
			return false;
		for (int i = 0; i < eway.size(); ++i)
			way.push_back(eway[i]);

	}

	// TODO: code up a properties here
	zprog->passstartcoords(markers[start]->getposition().first, markers[start]->getposition().second,
				offset->getposition().first, offset->getposition().second);

		for (int i = 1; i < way.size(); ++i)
			zprog->moverel(way[i].first - way[i - 1].first, way[i].second - way[i - 1].second);

	zprog->run();

	return true;

}
void targetoptimal::setupmprog(improg * mprog){ this->mprog = mprog; }
void targetoptimal::setupmap(string mapname){ this->mapname = mapname; }
void targetoptimal::setupzprog(izprog * zprog){ this->zprog = zprog; }

//#end
