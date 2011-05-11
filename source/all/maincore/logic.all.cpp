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

#include "../guicore/metrics.all.hpp"

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

	metrics::set(1000, 750);

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

	mfile->settext("&File");
	mq->settext("&Help");
	mfile_exit->settext("&Exit");
	mq_about->settext("&About");

	mmain->add(mfile);
	mmain->add(mq);
	mfile->add(mfile_exit);
	mq->add(mq_about);

	mmain->setparent(form1);

	//mfile_exit->setactivate(exitactivate);
	//mq_about->setactivate(aboutactivate);

	/**/
	app->newmainform(form1);
	form1->setposition(150, 100);
	form1->setsize(500, 500);
	btn1->setposition(100, 100);
	btn1->setsize(200, 200);
	btn1->settext("BGA!!!");
	//btn1->setactivate(btn1click);
	form1->add(btn1);
	view1->setposition(50, 50);
	view1->setsize(300, 40);
	//view1->setmousemove(view1mousemove);
	form1->add(view1);
	btn2->setposition(50, 50);
	btn2->setsize(50, 16);
	btn2->settext("BGA!!!");
	//btn2->setactivate(btn2_3click);
	btn3->setposition(50, 30);
	btn3->setsize(50, 16);
	btn3->settext("BGA!!! v2.0");
	//btn3->setactivate(btn2_3click);
	toolbox1->add(btn2);
	toolbox1->add(btn3);
	toolbox1->setactivecontrol(btn2);
	toolbox1->setposition(350, 350);
	toolbox1->setsize(100, 100);
	form1->add(toolbox1);
	stat1->settext("Hello world");
	form1->add(stat1);
	prop1->setposition(150, 350);
	prop1->setsize(100, 100);
	prop1->addproperty("Beep", "false", "bool");
	prop1->addproperty("Sound", "true", "bool");
	prop1->addproperty("Laser", "true", "bool");
	prop1->addproperty("BeepEx", "true", "bool");
	prop1->addproperty("SoundEx", "false", "bool");
	prop1->addproperty("LaserEx", "true", "bool");
	prop1->addproperty("Title", "Hello world!!", "string");
	form1->add(prop1);/**/

	// form1 setup
//	form1->setposition(50, 50);
//	form1->setsize(900, 700);

	btn1->setactivate(click_btn1);

}

int logic::run(){

	return app->mainloop();

}

//#end
