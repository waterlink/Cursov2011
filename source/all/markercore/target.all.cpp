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

//	#refactor

string target::getoption(string param){

	tokenizer * token = new stringtokenizer(&(options[param]));
	string res = token->getparam(param);
	delete token;
	return res;

}
int target::getoption(string param, int){

	tokenizer * token = new stringtokenizer(&(options[param]));
	int res = token->getparam(param, 0);
	delete token;
	return res;

}
void target::setoption(string param, string value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);
	delete token;

}
void target::setoption(string param, int value){

	tokenizer * token = new stringtokenizer(&(options[param]));
	token->setparam(param, value);
	delete token;

}

//	#refactorend

string target::gettype(){ return "target"; }

//#end
