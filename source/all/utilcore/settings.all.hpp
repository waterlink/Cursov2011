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
//	class settings
//	interface
//	class for managing current settings of an application
//

#ifndef settings_hpp
#define settings_hpp

#include "stringtokenizer.all.hpp"

#include <string>

using namespace std;

class
setgettable{

public:

	setgettable(string s = ""){ data = s; }
	~setgettable(){}

	operator string(){ return data; }

private:

	string data;

};

class
settings{

public:

	static string get(string param);
	static int get(string param, int);
	static void set(string param, string value);
	static void set(string param, int value);

	settings();
	~settings();

	setgettable operator [](string param);

protected:

	

private:

	static string sgs;

};

#endif

//#end
