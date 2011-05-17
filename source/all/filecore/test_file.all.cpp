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
//	class for testing file functionality
//

#include "test_file.all.hpp"

test_file::test_file(file * myfile){ this->myfile = myfile; }
test_file::~test_file(){}
void test_file::cat(){

	for (;;) printf("%c", myfile->catchar());

}

//#end
