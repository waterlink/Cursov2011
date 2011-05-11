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
//	class that identifies a file
//

#include "file.all.hpp"

file::file(string path){ this->path = path; }
file::~file(){}

bool file::wopen(){

	if (isopened())
		freopen(path.c_str(), "w", id);
	else id = fopen(path.c_str(), "w");
	return opened = id != 0;

}
bool file::ropen(){

	if (isopened())
		freopen(path.c_str(), "r", id);
	else id = fopen(path.c_str(), "r");
	return opened = id != 0;

}
bool file::aopen(){

	if (isopened())
		freopen(path.c_str(), "a", id);
	else id = fopen(path.c_str(), "a");
	return opened = id != 0;

}
void file::flush(){

	if (isopened())
		fflush(id);

}
void file::close(){

	if (isopened())
		fclose(id);
	opened = false;

}
bool file::isopened(){

	return opened;

}

//#end
