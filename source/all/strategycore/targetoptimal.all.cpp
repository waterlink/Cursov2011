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

#include <cstdio>

targetoptimal::targetoptimal(){}
targetoptimal::~targetoptimal(){}
void targetoptimal::setupmarkersource(markermap * markersource){ this->markersource = markersource; }
bool targetoptimal::go(){

	// TODO: code up a properties here
	zprog->passstartcoords(markers[start]->getposition().first, markers[start]->getposition().second,
				offset->getposition().first, offset->getposition().second);

		int j = 0;
		for (int i = 1; i <= way.size(); ++i){

			if (i < way.size()) 
				zprog->moverel(way[i].first - way[i - 1].first, way[i].second - way[i - 1].second);

			if (j < marks.size()) if (way[i - 1] == marks[j]->getposition()){

				if (marks[j]->getoption("beep") == "true")
					zprog->beep();
				zprog->setlight(marks[j]->getoption("light") == "true");
				++j;

			}

		}

	zprog->run();

	return true;

}
void targetoptimal::setupmprog(improg * mprog){ this->mprog = mprog; }
void targetoptimal::setupmap(string mapname){ this->mapname = mapname; }
void targetoptimal::setupzprog(izprog * zprog){ this->zprog = zprog; }
bool targetoptimal::status(){

	bool res = true;
	start = -1;
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
	edge * V[markers.size()];
	for (int i = 0; i < markers.size(); ++i) E[i] = -1, V[i] = 0;

	edge * edg;
	for (markersource->catedge(); (edg = markersource->catnextedge()) != markersource->catlastedge(); ){

		if (edg->getB()->gettype() == "target")
			E[mark[edg->getA()]] = mark[edg->getB()],
			V[mark[edg->getA()]] = edg;

	}

	for (int i = 0; i < markers.size(); ++i) printf("%d: %d\n", i, E[i]);
	//return false;

	int curr = start;
	marks.push_back(markers[start]);
	for (; curr >= 0; ){

		printf("curr: %d\n", curr);

		int next = E[curr];
		if (next < 0) break;
		marks.push_back(markers[next]);
		vector < pair < int, int > > eway = mprog->getway(markers[curr]->getposition(), markers[next]->getposition(), mapname);
		if (eway.size() == 0){

			V[curr]->setcolor(1);
			res = false;

		}
		else V[curr]->setcolor(3);
		for (int i = 0; i < eway.size(); ++i)
			way.push_back(eway[i]);
		curr = next;

	}

	return res;

}

//#end
