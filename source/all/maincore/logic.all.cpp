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

EHandler(click_btn1, {

	printf("ehandler catched an event\n");

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
		menu * mq_about
){

#define clean \
		delete token; \
		return;

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
	token->setparam("gcolor", 0);
	token->setparam("bcolor", 0);
	token->setparam("thickness", 2);
	view1->draw(message);

	toolbox1->setposition(form1->getsize().first - 150, 0);
	toolbox1->setsize(150, form1->getsize().second - 400);

	prop1->setposition(form1->getsize().first - 150, form1->getsize().second - 350);
	prop1->setsize(150, 350);

	btn1->setsize(0, 0);

	btn1->setactivate(click_btn1);

	clean;

#undef clean

}

int logic::run(){

	return app->mainloop();

}

//#end
