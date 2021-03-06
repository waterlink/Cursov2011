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
//	class startpoint - realization of marker
//

#include "startpoint.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

void startpoint::setposition(int x, int y){

	position = make_pair(x, y);

}
pair < int, int > startpoint::getposition(){

	return position;

}

//	#refactor

string startpoint::getoption(string param){

	tokenizer * token = new stringtokenizer(&(options[param]));
	string res = token->getparam(param);
	delete token;
	return res;

}
int startpoint::getoption(string param, int){

	tokenizer * token = new stringtokenizer(&(options[param]));
	int res = token->getparam(param, 0);
	delete token;
	return res;

}
void startpoint::setoption(string param, string value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);
	delete token;

}
void startpoint::setoption(string param, int value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);
	delete token;

}

//	#refactorend

void startpoint::detect(){

	// TODO: make this 

}

string startpoint::gettype(){ return "startpoint"; }

//#end
