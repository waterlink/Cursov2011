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
//	class command for robot
//

#include "command.all.hpp"

command::command(izprog * zprog, ibtexec * btexec){

	this->zprog = zprog;
	this->btexec = btexec;

}

void command::setup(string com){

	// TODO: code this up
	this->com = com;

}
string command::getsetup(){

	return com;

}
void command::execute(){

	// TODO: code this up

}

//#end
