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
#include "../../all/guicore/messager.all.hpp"

HINSTANCE mainclass::Inst = 0;

HINSTANCE mainclass::getInst(){ return Inst; }

class btn1_onclick: public messager{ public: btn1_onclick(){} ~btn1_onclick(){}
	void operator ()(component * sender, string message){

		fprintf(stderr, "main--btn1click::fixme: stub, catched!!\n");

	}
} * btn1click = new btn1_onclick();

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

	Wclient * app = new Wclient("app");
	Wform * form1 = new Wform("form1");
	Wbutton * btn1 = new Wbutton("btn1");

	btn1->setposition(100, 100);
	btn1->setsize(50, 15);
	btn1->setactivate(btn1click);
	form1->add(btn1);
	form1->setposition(150, 100);
	form1->setsize(400, 300);
	app->newmainform(form1);
	app->mainloop();

	return 0;

}

//#end
