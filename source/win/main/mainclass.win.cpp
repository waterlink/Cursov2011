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
//	win version of main class, contains initialization, run method and finalization
//

#include "mainclass.win.hpp"

#include "../Wguicore/Wclient.win.hpp"
#include "../Wguicore/Wform.win.hpp"
#include "../Wguicore/Wbutton.win.hpp"
#include "../Wguicore/Wview.win.hpp"
#include "../Wguicore/Wtoolbox.win.hpp"
#include "../Wguicore/Wstatus.win.hpp"
#include "../Wguicore/Wproperties.win.hpp"
#include "../Wguicore/Wmenu.win.hpp"

#include "../../all/guicore/messager.all.hpp"
#include "../../all/utilcore/stringtokenizer.all.hpp"

class
data{

public:

	Wclient * app;
	Wform * form1;
	Wbutton * btn1;
	Wview * view1;
	Wtoolbox * toolbox1;
	Wbutton * btn2;
	Wbutton * btn3;
	Wstatus * stat1;
	Wproperties * prop1;
	Wmenu * mmain;
	Wmenu * mfile;
	Wmenu * mq;
	Wmenu * mfile_exit;
	Wmenu * mq_about;

} * glbl_data = new data;

HINSTANCE mainclass::Inst = 0;

HINSTANCE mainclass::getInst(){ return Inst; }

class btn1_onclick: public messager{ public: btn1_onclick(){} ~btn1_onclick(){}
	void operator ()(component * sender, string message){

		fprintf(stdout, "main--btn1click::fixme: stub, catched!!\n");

	}
} * btn1click = new btn1_onclick();

class btn2_3_onclick: public messager{ public: btn2_3_onclick(){} ~btn2_3_onclick(){}
	void operator ()(component * sender, string message){

		fprintf(stdout, "main--btn1click::fixme: stub, catched!!\n");

		glbl_data->toolbox1->setactivecontrol(sender);

	}
} * btn2_3click = new btn2_3_onclick();

class view1_onmousemove: public messager{ public: view1_onmousemove(){} ~view1_onmousemove(){}
	void operator ()(component * sender, string message){

		fprintf(stdout, "main--view1mousemove::fixme: stub, catched!!\n");
		glbl_data->stat1->settext("this is a main view");

	}
} * view1mousemove = new view1_onmousemove();

mainclass::mainclass(){}

void
mainclass::init(
			HINSTANCE Inst,
			LPSTR CmdParam,
			int CmdShow
		){

	fprintf(stderr, "main--mainclass::init::debug: Inst = %d, CmdShow = %d\n", Inst, CmdShow);

	this->Inst = Inst;
	this->CmdParam = CmdParam;
	this->CmdShow = CmdShow;

}

mainclass::~mainclass(){}

int
mainclass::run(){

	MessageBox (NULL, TEXT ("mainclass: Hello, Windowman!"), TEXT ("HelloMsg"), 0);

	glbl_data->app = new Wclient("app");
	glbl_data->form1 = new Wform("form1");
	glbl_data->btn1 = new Wbutton("btn1", glbl_data->form1);
	glbl_data->view1 = new Wview("view1", glbl_data->form1);
	glbl_data->toolbox1 = new Wtoolbox("toolbox1", glbl_data->form1);
	glbl_data->btn2 = new Wbutton("btn2", /*dynamic_cast < ihandled * >*/(glbl_data->toolbox1));
	glbl_data->btn3 = new Wbutton("btn3", glbl_data->toolbox1);
	glbl_data->stat1 = new Wstatus("stat1", glbl_data->form1);
	glbl_data->prop1 = new Wproperties("prop1", glbl_data->form1);

	glbl_data->mmain = new Wmenu("mmain");
	glbl_data->mfile = new Wmenu("mfile", true);
	glbl_data->mq = new Wmenu("mq", true);
	glbl_data->mfile_exit = new Wmenu("mfile_exit", false);
	glbl_data->mq_about = new Wmenu("mq_about", false);

	glbl_data->mfile->settext("&File");
	glbl_data->mq->settext("&Help");
	glbl_data->mfile_exit->settext("&Exit");
	glbl_data->mq_about->settext("&About");

	glbl_data->mmain->add(glbl_data->mfile);
	glbl_data->mmain->add(glbl_data->mq);
	glbl_data->mfile->add(glbl_data->mfile_exit);
	glbl_data->mq->add(glbl_data->mq_about);

	glbl_data->mmain->setparent(glbl_data->form1);

	glbl_data->btn1->setposition(100, 100);
	glbl_data->btn1->setsize(200, 200);
	glbl_data->btn1->settext("BGA!!!");
	glbl_data->btn1->setactivate(btn1click);
	glbl_data->form1->add(glbl_data->btn1);
	glbl_data->view1->setposition(50, 50);
	glbl_data->view1->setsize(300, 40);
	glbl_data->view1->setmousemove(view1mousemove);
	glbl_data->form1->add(glbl_data->view1);
	glbl_data->btn2->setposition(50, 50);
	glbl_data->btn2->setsize(50, 16);
	glbl_data->btn2->settext("BGA!!!");
	glbl_data->btn2->setactivate(btn2_3click);
	glbl_data->btn3->setposition(50, 30);
	glbl_data->btn3->setsize(50, 16);
	glbl_data->btn3->settext("BGA!!! v2.0");
	glbl_data->btn3->setactivate(btn2_3click);
	glbl_data->toolbox1->add(glbl_data->btn2);
	glbl_data->toolbox1->add(glbl_data->btn3);
	glbl_data->toolbox1->setactivecontrol(glbl_data->btn2);
	glbl_data->toolbox1->setposition(350, 350);
	glbl_data->toolbox1->setsize(100, 100);
	glbl_data->form1->add(glbl_data->toolbox1);
	glbl_data->stat1->settext("Hello world");
	glbl_data->form1->add(glbl_data->stat1);
	glbl_data->prop1->setposition(150, 350);
	glbl_data->prop1->setsize(100, 100);
	glbl_data->prop1->addproperty("Beep", "false", "bool");
	glbl_data->prop1->addproperty("Sound", "true", "bool");
	glbl_data->prop1->addproperty("Laser", "true", "bool");
	glbl_data->prop1->addproperty("BeepEx", "true", "bool");
	glbl_data->prop1->addproperty("SoundEx", "false", "bool");
	glbl_data->prop1->addproperty("LaserEx", "true", "bool");
	glbl_data->prop1->addproperty("Title", "Hello world!!", "string");
	glbl_data->form1->add(glbl_data->prop1);
	glbl_data->form1->setposition(150, 100);
	glbl_data->form1->setsize(500, 500);
	glbl_data->app->newmainform(glbl_data->form1);
	return glbl_data->app->mainloop();

}

//#end
