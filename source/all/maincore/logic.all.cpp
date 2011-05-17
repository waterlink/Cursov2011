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
//	class controlling main processes in program
//

#include "logic.all.hpp"

#include <cstdio>

#include "../utilcore/stringtokenizer.all.hpp"
#include "../utilcore/settings.all.hpp"
#include "../mapcore/mapcore.all.hpp"
#include "../mapcore/test_simplemap.all.hpp"
#include "../markercore/markermap.all.hpp"
#include "datamanager.all.hpp"
#include "vectored.all.hpp"
#include "../filecore/test_file.all.hpp"

EHandler(click_btn1, {

	printf("ehandler catched an event\n");

})

EHandler(modeactivate, {

	//printf("modeactivate\n");
	mainlogic->changetoolboxmode(sender);

})

logic::logic(){}
logic::logic(
		client * app,
		form * form1,
		button * btn1,
		view * view1,
		toolbox * toolbox1,
		button * btn2,
		button * btn3,
		status * stat1,
		properties * prop1,
		menu * mmain,
		menu * mfile,
		menu * mq,
		menu * mfile_exit,
		menu * mq_about,

		pather * decoder,

		button * selectmode,
		button * startpointmode,
		button * targetmode,
		button * multitargetmode,
		button * freemode
){

#define clean \
		delete token; \
		return;

	settings::set("loglevel", 0);

	datamanager::add(0, new vectored);

	mainlogic = this;

	string message;
	tokenizer * token = new stringtokenizer(&message);

	this->app = app, 
	this->form1 = form1,
	this->btn1 = btn1,
	this->view1 = view1,
	this->toolbox1 = toolbox1,
	this->btn2 = btn2,
	this->btn3 = btn3,
	this->stat1 = stat1,
	this->prop1 = prop1,
	this->mmain = mmain,
	this->mfile = mfile,
	this->mq = mq,
	this->mfile_exit = mfile_exit,
	this->mq_about = mq_about;

	this->decoder = decoder;

	form1->setposition(50, 50);
	form1->setsize(900, 650);

	view1->setposition(0, 0);
	view1->setsize(form1->getsize().first - 200, form1->getsize().second);
	token->setparam("primitive", "rectangle");
	token->setparam("x", 0);
	token->setparam("y", 0);
	token->setparam("w", view1->getsize().first);
	token->setparam("h", view1->getsize().second);
	token->setparam("rcolor", 255);
	token->setparam("gcolor", 255);
	token->setparam("bcolor", 255);
	token->setparam("thickness", 2);
	view1->draw(message);

	toolbox1->setposition(form1->getsize().first - 150, 0);
	toolbox1->setsize(150, form1->getsize().second - 400);

	prop1->setposition(form1->getsize().first - 150, form1->getsize().second - 350);
	prop1->setsize(150, 350);
	prop1->clearproperty();

	btn1->setsize(0, 0);
	btn2->setsize(0, 0);
	btn3->setsize(0, 0);

	btn1->setactivate(click_btn1);

	mapcore * M = new test_simplemap(decoder);
	M->choose("testmap");
	M->load();
	markermap * markers = new markermap();
	manager = new mapmanager(M, markers, view1);
	manager->connecttoview();
	chosenmarkertype = new markermanager;
	manager->connecttomarkermanager(chosenmarkertype);

	/*button * selectmode
	button * startpointmode
	button * targetmode
	button * multitargetmode
	button * freemode*/

	toolbox1->add(selectmode);
	toolbox1->add(startpointmode);
	toolbox1->add(targetmode);
	toolbox1->add(multitargetmode);
	toolbox1->add(freemode);

	toolbox1->setactivecontrol(selectmode);

	selectmode->setsize(20, 20);
	selectmode->setposition(65, 10);
	selectmode->setactivate(modeactivate);
	selectmode->settext("");

	startpointmode->setsize(20, 20);
	startpointmode->setposition(65, 40);
	startpointmode->setactivate(modeactivate);
	startpointmode->settext("S");

	targetmode->setsize(20, 20);
	targetmode->setposition(65, 70);
	targetmode->setactivate(modeactivate);
	targetmode->settext("T");

	multitargetmode->setsize(20, 20);
	multitargetmode->setposition(65, 100);
	multitargetmode->setactivate(modeactivate);
	multitargetmode->settext("M");

	freemode->setsize(20, 20);
	freemode->setposition(65, 130);
	freemode->setactivate(modeactivate);
	freemode->settext("F");

	clean;

#undef clean

}

int logic::run(){

	return app->mainloop();

}

void logic::changetoolboxmode(component * pressed){

	chosenmarkertype->setcurrentmarkertype(pressed->getname());
	toolbox1->setactivecontrol(pressed);

}

//#end
