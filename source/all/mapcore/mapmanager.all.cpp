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
#include <cmath>

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

#include "../maincore/datamanager.all.hpp"

#include "pixeldrawer.all.hpp"

//	#refactor

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
					new logger(0, "mapcore--viewconnection::handler::fixme: selectmode, stub\n");

					int x = token->getparam("x", 0);
					int y = token->getparam("y", 0);
					manager->setchosenmarker(manager->findnearest(make_pair(x, y)));
					manager->redraweverything();

				}

			}
			else if (token->getparam("message") == "mousedown" 
				&& token->getparam("button") == "right"){

				if (manager->extractmarkermanager()->getcurrentmarkertype() == "startpointmode"){

					// TODO: here must be a dialog asking, is user really wants do that

					new logger(10, "mapcore--viewconnection::handler::debug: changing offset marker\n");

					manager->clearoffset();
					manager->choosestartpoint();

					new logger(10, "mapcore--viewconnection::handler::debug: chosen a start point\n");

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

						new logger(10, "mapcore--viewconnection::handler::debug: redraw is done\n");

					}

					new logger(10, "mapcore--viewconnection::handler::debug: offset added succesfully\n");

				}

			}

		delete token;

	}

private: 

	mapmanager * manager;

};

//	#refactorend

mapmanager::mapmanager(mapcore * mapsource, markermap * markersource, view * viewdestination){

	this->mapsource = mapsource;
	this->markersource = markersource;
	this->viewdestination = viewdestination;

	chosenmarker = NULL;
	chosenedge = NULL;

	bitsync = new mapsync(mapsource, datamanager::getbyid(0));

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

	pair < int, int > size = mapsource->getsize();
	string bits = pixeldrawer::drawall(0, size.first, size.second);
	viewdestination->undraw(bits);
	bitsync->bsync();
	viewdestination->draw(bits);

	if (chosenmarker){

		// code this up
		string prim = markerdrawer::drawchosen(decodeposition(chosenmarker));
		viewdestination->undraw(prim);
		viewdestination->draw(prim);

	}
	else if (chosenedge){

		// code this up in future

	}

	edge * edg;
	for (markersource->catedge(); (edg = markersource->catnextedge()) != markersource->catlastedge(); ){

		string prim = edgedrawer::draw(edg, decodeposition(edg->getA()), decodeposition(edg->getB()));
		viewdestination->undraw(prim);
		viewdestination->draw(prim);

	}

	new logger(10, "mapcore--mapmanager::redraweverything::debug: edges deleted\n");

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		string prim = markerdrawer::draw(mar, decodeposition(mar));
		viewdestination->undraw(prim);
		viewdestination->draw(prim);

	}

	new logger(10, "mapcore--mapmanager::redraweverything::debug: markers deleted\n");

}
void mapmanager::addmarker(marker * mar){ markersource->addmarker(mar); }
void mapmanager::delmarker(marker * mar){ 

	string prim = markerdrawer::draw(mar, decodeposition(mar));
	viewdestination->undraw(prim);
	markersource->delmarker(mar); 

}
void mapmanager::addedge(edge * edg){ markersource->addedge(edg); }
void mapmanager::deledge(edge * edg){ 

	string prim = edgedrawer::draw(edg, decodeposition(edg->getA()), decodeposition(edg->getB()));
	viewdestination->undraw(prim);
	markersource->deledge(edg); 

}
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


	edge * edg;
	for (markersource->catedge(); (edg = markersource->catnextedge()) != markersource->catlastedge(); )
		if (edg->determine() == 4)
			break;

	if (edg != markersource->catlastedge())
		deledge(edg);

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		if (mar->gettype() == "directionoffset"){

			new logger(10, "mapcore--mapmanager::clearoffset::debug: deleting marker...");

			delmarker(mar);

			new logger(10, "done\n");

			break;

		}

	}

}

void mapmanager::setchosenmarker(marker * mar){ 

	if (chosenmarker){

		string prim = markerdrawer::drawchosen(decodeposition(chosenmarker));
		viewdestination->undraw(prim);

	}
	chosenmarker = mar;

}
marker * mapmanager::getchosenmarker(){ 

	// for future
	if (chosenedge){

		//string prim = edgedrawer::drawchosen(decodeposition(mar));
		//viewdestination->undraw(prim);

	}
	return chosenmarker; 

}

// for future purposes
void mapmanager::setchosenedge(edge * edg){ chosenedge = edg; }
edge * mapmanager::getchosenedge(){ return chosenedge; }

marker * mapmanager::findnearest(pair < int, int > pos){

	// TODO: code this up
	pair < int, int > decodedpos = decodeposition(pos);

	double bestdistance = 1e9;
	marker * found = NULL;

	marker * mar;
	for (markersource->catmarker(); (mar = markersource->catnextmarker()) != markersource->catlastmarker(); ){

		double x1 = decodedpos.first;
		double y1 = decodedpos.second;
		double x2 = mar->getposition().first - x1;
		double y2 = mar->getposition().second - y1;

		double dist = sqrt(x2 * x2 + y2 * y2);
		if (dist < bestdistance){

			bestdistance = dist;
			found = mar;

		}

	}

	return found;

}
void mapmanager::setuppropertymanager(propertymanager * propertydestination){

	this->propertydestination = propertydestination;

}
void mapmanager::propertynotify(){

	if (propertydestination) propertydestination->notification(this);

}

//#end
