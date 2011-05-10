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
//	header file
//	class mainclass
//	interface
//	win version of main class, contains initialization, run method and finalization
//

#ifndef mainclass_hpp
#define mainclass_hpp

#include <windows.h>
#include <cstdlib>

#include "../Wguicore/Wclient.win.hpp"
#include "../Wguicore/Wform.win.hpp"
#include "../Wguicore/Wbutton.win.hpp"
#include "../Wguicore/Wview.win.hpp"
#include "../Wguicore/Wtoolbox.win.hpp"
#include "../Wguicore/Wstatus.win.hpp"
#include "../Wguicore/Wproperties.win.hpp"
#include "../Wguicore/Wmenu.win.hpp"

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

class
mainclass{

public:

	static HINSTANCE getInst();

	mainclass();

	void
	init(
			HINSTANCE Inst,
			LPSTR CmdParam,
			int CmdShow
		);

	~mainclass();

	int
	run();

protected:

	

private:

	static HINSTANCE
	Inst;
	
	LPSTR
	CmdParam;

	int
	CmdShow;

};

#endif

//#end
