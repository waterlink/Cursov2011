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
	ofid.open(path.c_str());
	mode = "out";
	return opened = id != 0;

}
bool file::ropen(){

	if (isopened())
		freopen(path.c_str(), "r", id);
	else id = fopen(path.c_str(), "r");
	ifid.open(path.c_str());
	mode = "in";
	return opened = id != 0;

}
bool file::aopen(){

	if (isopened())
		freopen(path.c_str(), "a", id);
	else id = fopen(path.c_str(), "a");
	ofid.open(path.c_str(), ostream::app);
	mode = "out";
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
int file::nextint(){

	int x = 0;
	if (mode == "in")
		fscanf(id, "%d", &x);
	return x;

}
void file::nextint(int x){

	if (mode == "out")
		fprintf(id, " %d ", x);

}
double file::nextdouble(){

	double x = 0;
	if (mode == "in")
		fscanf(id, "%lf", &x);
	return x;

}
void file::nextdouble(double x){

	if (mode == "out")
		fprintf(id, " %lf ", x);

}

string file::nextline(){

	string res = "";
	if (mode == "in")
		getline(ifid, res);
	return res;

}
string file::nextword(){

	string res = "";
	if (mode == "out")
		ifid >> res;
	return res;

}
void file::nextline(string s){

	if (mode == "out")
		ofid << s << endl;

}
void file::nextword(string s){

	if (mode == "out")
		ofid << " " << s << " ";

}

//#end
