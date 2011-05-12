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

#include "../guicore/messager.all.hpp"
#include "../markercore/markerdrawer.all.hpp"
#include "../markercore/edgedrawer.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

class viewconnection: public messager{ public: viewconnection(){} ~viewconnection(){}

	void setup(mapmanager * manager){

		this->manager = manager;

	}

	void operator ()(component * sender, string message){

		tokenizer * token = new stringtokenizer(&message);

			if (token->getparam("message") == "mousedown"){

				// code this up
				manager->redraweverything();

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
void mapmanager::addmarker(marker * mar){}
void mapmanager::delmarker(marker * mar){}
void mapmanager::addedge(edge * edg){}
void mapmanager::deledge(edge * edg){}
pair < int, int > mapmanager::decodeposition(marker * mar){

	// stub
	return mar->getposition();

}
pair < int, int > mapmanager::decodeposition(pair < int, int > pos){

	// stub
	return pos;

}

//#end
