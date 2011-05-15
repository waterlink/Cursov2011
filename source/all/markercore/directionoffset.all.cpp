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
//	class for managing current direction of robot
//

#include "directionoffset.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

directionoffset::directionoffset(){}
directionoffset::~directionoffset(){}

void directionoffset::setposition(int x, int y){ position = make_pair(x, y); }
pair < int, int > directionoffset::getposition(){ return position; }

string directionoffset::getoption(string param){

	tokenizer * token = new stringtokenizer(&(options[param]));
	string res = token->getparam(param);
	delete token;
	return res;

}
int directionoffset::getoption(string param, int){

	tokenizer * token = new stringtokenizer(&(options[param]));
	int res = token->getparam(param, 0);
	delete token;
	return res;

}
void directionoffset::setoption(string param, string value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);
	delete token;

}
void directionoffset::setoption(string param, int value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);
	delete token;

}

string directionoffset::gettype(){ return "directionoffset"; }

//#end
