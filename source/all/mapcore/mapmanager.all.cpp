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
//	class to manage map, markermap and view it all
//

#include "mapmanager.all.hpp"

#include <cstdio>

#include "../guicore/messager.all.hpp"
#include "../markercore/markerdrawer.all.hpp"
#include "../markercore/edgedrawer.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

#include "../markercore/target.all.hpp"
#include "../markercore/startpoint.all.hpp"
#include "../markercore/multitarget.all.hpp"
#include "../markercore/directionoffset.all.hpp"

#include "../markercore/simpleedge.all.hpp"

#include "../utilcore/logger.all.hpp"

class viewconnection: public messager{ public: viewconnection(){} ~viewconnection(){}

	void setup(mapmanager * manager){

		this->manager = manager;

	}

	void operator ()(component * sender, string message){

		tokenizer * token = new stringtokenizer(&message);

			if (token->getparam("message") == "mousedown" 
				&& token->getparam("button") == "left"){

				// code this up
				if (manager->extractmarkermanager()->getcurrentmarkertype() == "targetmode"){

					manager->gotolasttarget();
					if (manager->getcurrenttarget() == 0)
						manager->choosestartpoint();
					if (manager->getcurrenttarget()){

						int x = token->getparam("x", 0);
						int y = token->getparam("y", 0);
						marker * mar = new target;
						mar->setposition(x, y);
						manager->addmarker(mar);
						edge * edg = new simpleedge;
						edg->setA(manager->getcurrenttarget());
						edg->setB(mar);
						manager->addedge(edg);
						manager->redraweverything();

					}

				}
				else if (manager->extractmarkermanager()->getcurrentmarkertype() == "startpointmode"){

					// TODO: here must be a dialog asking, is user really wants do that
					manager->clear();
					int x = token->getparam("x", 0);
					int y = token->getparam("y", 0);
					marker * mar = new startpoint;
					mar->setposition(x, y);
					manager->addmarker(mar);
					manager->redraweverything();

				}
				else if (manager->extractmarkermanager()->getcurrentmarkertype() == "multitargetmode"){

					manager->choosestartpoint();
					if (manager->getcurrenttarget()){

						int x = token->getparam("x", 0);
						int y = token->getparam("y", 0);
						marker * mar = new multitarget;
						mar->setposition(x, y);
						manager->addmarker(mar);
						edge * edg = new simpleedge;
						edg->setA(manager->getcurrenttarget());
						edg->setB(mar);
						manager->addedge(edg);
						manager->redraweverything();

					}

				}
				else if (manager->extractmarkermanager()->getcurrentmarkertype() == "freemode"){

					//fprintf(stderr, "mapcore--viewconnection::handler::fixme: freemode, stub\n");
					new logger(4, "mapcore--viewconnection::handler::fixme: freemode, stub\n");

				}
				else if (manager->extractmarkermanager()->getcurrentmarkertype() == "selectmode"){

					//fprintf(stderr, "mapcore--viewconnection::handler::fixme: selectmode, stub\n");
					new logger(4, "mapcore--viewconnection::handler::fixme: selectmode, stub\n");

				}

			}
			else if (token->getparam("message") == "mousedown" 
				&& token->getparam("button") == "right"){

				if (manager->extractmarkermanager()->getcurrentmarkertype() == "startpointmode"){

					// TODO: here must be a dialog asking, is user really wants do that
					manager->clearoffset();
					manager->choosestartpoint();
					if (manager->getcurrenttarget()){
					
						int x = token->getparam("x", 0);
						int y = token->getparam("y", 0);
						marker * mar = new directionoffset;
						mar->setposition(x, y);
						manager->addmarker(mar);
						edge * edg = new simpleedge;
						edg->setA(manager->getcurrenttarget());
						edg->setB(mar);
						manager->addedge(edg);
						manager->redraweverything();

					}

				}

			}

		delete token;

	}

private: mapmanager * manager;
};

/*EHandler(viewconnection, {

	// sender'n'message
	tokenizer * token = new stringtokenizer(&message);

		if (token->getparam("message") == "mousedown"){

			// code this up
			redraweverything();

		}

	delete token;

})*/

mapmanager::mapmanager(mapcore * mapsource, markermap * markersource, view * viewdestination){

	this->mapsource = mapsource;
	this->markersource = markersource;
	this->viewdestination = viewdestination;

}
mapmanager::~mapmanager(){}

void mapmanager::connecttoview(){

	viewconnection * onviewconnection = new viewconnection;
	onviewconnection->setup(this);

	viewdestination->setmousedown(onviewconnection);
	viewdestination->setmouseup(onviewconnection);
	viewdestination->setmousemove(onviewconnection);

}
void mapmanager::redraweverything(){

	edge * edg;
	for (markersource->catedge(); (edg = markersource->catnextedge()) != markersource->catlastedge(); ){

		string prim = edgedrawer::draw(edg, decodeposition(edg->getA()), decodeposition(edg->getB()));
		viewdestination->undraw(prim);
		viewdestination->draw(prim);

	}

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		string prim = markerdrawer::draw(mar, decodeposition(mar));
		viewdestination->undraw(prim);
		viewdestination->draw(prim);

	}

	if (chosenmarker){

		// code this up

	}
	else if (chosenedge){

		// code this up

	}

}
void mapmanager::addmarker(marker * mar){ markersource->addmarker(mar); }
void mapmanager::delmarker(marker * mar){ markersource->delmarker(mar); }
void mapmanager::addedge(edge * edg){ markersource->addedge(edg); }
void mapmanager::deledge(edge * edg){ markersource->deledge(edg); }
pair < int, int > mapmanager::decodeposition(marker * mar){

	// stub
	return mar->getposition();

}
pair < int, int > mapmanager::decodeposition(pair < int, int > pos){

	// stub
	return pos;

}
void mapmanager::connecttomarkermanager(markermanager * chosentype){

	this->chosentype = chosentype;

}
markermanager * mapmanager::extractmarkermanager(){

	return chosentype;

}

int mapmanager::getmapvalue(int i, int j){

	return mapsource->getvalue(i, j);

}
void mapmanager::setmapvalue(int i, int j, int v){

	mapsource->setvalue(i, j, v);

}
void mapmanager::gotolasttarget(){

	marker * mar, * lmar = 0;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		if (mar->gettype() == "target")
			lmar = mar;

	}

	currenttarget = lmar;

}

void mapmanager::clearstartpoint(){

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		if (mar->gettype() == "startpoint"){

			delmarker(mar);
			break;

		}

	}

}

void mapmanager::choosestartpoint(){

	marker * mar, * lmar = 0;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		if (mar->gettype() == "startpoint"){

			lmar = mar;
			break;

		}

	}

	currenttarget = lmar;

}

marker * mapmanager::getcurrenttarget(){ return currenttarget; }

void mapmanager::clear(){ 

	edge * edg;
	for (markersource->catedge(); (edg = markersource->catnextedge()) != markersource->catlastedge(); ){

		string prim = edgedrawer::draw(edg, decodeposition(edg->getA()), decodeposition(edg->getB()));
		viewdestination->undraw(prim);
		//viewdestination->draw(prim);

	}

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		string prim = markerdrawer::draw(mar, decodeposition(mar));
		viewdestination->undraw(prim);
		//viewdestination->draw(prim);

	}

	if (chosenmarker){

		// code this up

	}
	else if (chosenedge){

		// code this up

	}

	markersource->clear(); 

}

void mapmanager::clearoffset(){

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		if (mar->gettype() == "directionoffset"){

			delmarker(mar);
			break;

		}

	}

}

//#end
