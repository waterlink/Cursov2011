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
//	main file
//

#include "main.linux.hpp"

int
main(int argc, char ** argv){

	#ifdef LINUX_target
		printf("Hello, linuxoid!!!\n");
	#endif
	printf("Hello, world!\n");

	mainclass
	*MC = new mainclass(argc, argv);
	int
	errcode = MC->run();
	delete MC;
	
	return errcode;

}

//#end
