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
//	class target - realization of marker
//

#include "target.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

void target::setposition(int x, int y){

	position = make_pair(x, y);

}
pair < int, int > target::getposition(){

	return position;

}
string target::getoption(string param){

	tokenizer * token = new stringtokenizer(&(options[param]));
	return token->getparam(param);

}
int target::getoption(string param, int){

	tokenizer * token = new stringtokenizer(&(options[param]));
	return token->getparam(param, 0);

}
void target::setoption(string param, string value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);

}
void target::setoption(string param, int value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);

}

string target::gettype(){ return "target"; }

//#end
