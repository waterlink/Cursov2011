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
//	class command
//	interface
//	class command for robot
//

#ifndef command_hpp
#define command_hpp

#include "../robocore/izprog.all.hpp"
#include "../robocore/ibtexec.all.hpp"

#include <string>

using namespace std;

class
command{

public:

	command(izprog * zprog, ibtexec * btexec);
	virtual ~command(){}

	virtual void setup(string com);
	virtual string getsetup();
	virtual void execute();

protected:

	

private:

	izprog * zprog;
	ibtexec * btexec;

	string com;

};

#endif

//#end
