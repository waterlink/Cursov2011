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
