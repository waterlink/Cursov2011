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
//	class test_file
//	interface
//	class for testing file functionality
//

#ifndef test_file_hpp
#define test_file_hpp

#include "file.all.hpp"

class
test_file{

public:

	test_file(file * myfile);
	virtual ~test_file();
	virtual void cat();

protected:

	

private:

	file * myfile;

};

#endif

//#end
