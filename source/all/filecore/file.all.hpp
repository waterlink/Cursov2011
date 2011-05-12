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
//	class file
//	interface
//	class that identifies a file
//

#ifndef file_hpp
#define file_hpp

#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

class
file{

public:

	file(string path);
	virtual ~file();

	virtual bool wopen();
	virtual bool ropen();
	virtual bool aopen();
	virtual void flush();
	virtual void close();
	virtual bool isopened();

	virtual int nextint();
	virtual void nextint(int x);

	virtual double nextdouble();
	virtual void nextdouble(double x);

	virtual string nextline();
	virtual string nextword();
	virtual void nextline(string s);
	virtual void nextword(string s);


protected:

	

private:

	FILE * id;
	ifstream ifid;
	ofstream ofid;
	bool opened;
	string path;
	string mode;

};

#endif

//#end
