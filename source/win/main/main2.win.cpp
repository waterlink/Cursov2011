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
//	main file, runs mainclass
//

#include "main2.win.hpp"

int __stdcall
WinMain(
		HINSTANCE Inst,
		HINSTANCE,
		LPSTR CmdParam,
		int CmdShow
	){

	#ifdef WIN_target
		fprintf(stderr, "everything is ok!\n");
	#endif
	#ifdef LINUX_target
		fprintf(stderr, "WTF???");
	#endif

	mainclass
	*MC = new mainclass;
	MC->init(
			Inst, 
			CmdParam, 
			CmdShow
		);

	int
	errcode = MC->run();

	delete MC;

	return errcode;

}

//#end
