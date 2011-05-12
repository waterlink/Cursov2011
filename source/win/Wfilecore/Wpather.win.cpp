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
//	filecore path class for windows
//

#include "Wpather.win.hpp"

Wpather::Wpather(){}
Wpather::~Wpather(){}

string Wpather::decode(string path){

	string res = "";
	for (unsigned int i = 0; i < res.size(); i += 1)
		if (path[i] == '/')
			res.push_back('\\');
		else res.push_back(path[i]);
	if (res[0] == '\\')
		res[0] = '.';

	return res;

}

//#end
