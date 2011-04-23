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
//	main class, contains initializer for parameters and method run, to run application
//

#ifndef mainclass_hpp
#define mainclass_hpp

class
mainclass{

public:

	mainclass(int argc, char ** argv);
	~mainclass();

	int
	run();

protected:

	

private:

	int
	argc;

	char
	**argv;

};

#endif

//#end
