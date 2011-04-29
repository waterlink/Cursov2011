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
//	class stringtokenizer
//	interface
//	tokenizer realization for strings
//

#ifndef stringtokenizer_hpp
#define stringtokenizer_hpp

#include "tokenizer.all.hpp"

class
stringtokenizer: public tokenizer{

public:

	stringtokenizer(string * data);
	~stringtokenizer();
	void setparam(string param, string value);
	string getparam(string param);
	int getparam(string param, int);	// int added just for distinguishing

protected:

	

private:

	string * data;

};

#endif

//#end
