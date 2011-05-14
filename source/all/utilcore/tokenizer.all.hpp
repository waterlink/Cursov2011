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
//	class tokenizer
//	interface
//	this class allows to work with strings, as they are datastructures with unknown signature (param:value param:value ...)
//

#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <string>
#include <climits>

using namespace std;

class
tokenizer{

public:

	virtual ~tokenizer() = 0;
	virtual void setparam(string param, string value) = 0;
	virtual void setparam(string param, int value) = 0;
	virtual string getparam(string param) = 0;
	virtual int getparam(string param, int) = 0;	// int added just for distinguishing

	static int unknowint;

protected:

	

private:

	

};

#endif

//#end
