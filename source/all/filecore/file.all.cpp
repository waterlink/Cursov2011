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

#include "../utilcore/logger.all.hpp"

file::file(string path){ 

	this->path = path; 
	opened = false;

	new logger(0, "filecore--file::file::debug: path is " + path + "\n");

}
file::~file(){}

bool file::wopen(){

	if (isopened())
		freopen(path.c_str(), "w", id), ofid.close(), ofid.open(path.c_str());
	else id = fopen(path.c_str(), "w"), ofid.open(path.c_str());
	mode = "out";
	return opened = id != 0;

}
bool file::ropen(){

	if (isopened())
		freopen(path.c_str(), "r", id);//, ifid.close(), ifid.open(path.c_str());
	else id = fopen(path.c_str(), "r");//, ifid.open(path.c_str());
	mode = "in";
	char logbuf[200]; 
	sprintf(logbuf, "filecore--file::ropen::debug: id = %d\n", id);
	new logger(0, logbuf);
	return opened = id != 0;

}
bool file::aopen(){

	if (isopened())
		freopen(path.c_str(), "a", id), ofid.close(), ofid.open(path.c_str(), ostream::app);
	else id = fopen(path.c_str(), "a"), ofid.open(path.c_str(), ostream::app);
	mode = "out";
	return opened = id != 0;

}
void file::flush(){

	if (isopened()){
		fflush(id);
		// TODO: code this flush up
		//if (mode == "in") ifid.flush();
		//if (mode == "out") ofid.flush();
	}

}
void file::close(){

	if (isopened()){
		fclose(id);
		if (mode == "in") ifid.close();
		if (mode == "out") ofid.close();
	}
	opened = false;

}
bool file::isopened(){

	return opened;

}
int file::nextint(){

	int x = 0;
	if (mode == "in"){

		new logger(0, "filecore--file::nextint::debug: trying to scan\n");
		fscanf(id, "%d", &x);

	}
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
char file::catchar(){

	char ch;
	if (mode == "in")
		fscanf(id, "%c", &ch);
	return ch;

}

//#end
