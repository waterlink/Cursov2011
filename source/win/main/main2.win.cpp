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
		printf("everything is ok!\n");
	#endif
	#ifdef LINUX_target
		printf("WTF???");
	#endif

	MessageBox (NULL, TEXT ("Hello, Windowman!"), TEXT ("HelloMsg"), 0);

	return 0;

}

//#end
