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

#define EHandler(name, x) \
	\
	class on##name: public messager{ public: on##name(){} ~on##name(){} \
	void operator ()(component * sender, string message) x \
} * name = new on##name();

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

	btn1->setactivate(click_btn1);

}

int logic::run(){

	return app->mainloop();

}

//#end
