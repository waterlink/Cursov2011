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
//	class for managing current settings of an application
//

#include "settings.all.hpp"

map < string, string > settings::sgs;

string settings::get(string param){

	tokenizer * token = new stringtokenizer(&(sgs[param]));
	string res = token->getparam(param);
	delete token;
	return res;

}
int settings::get(string param, int){

	tokenizer * token = new stringtokenizer(&(sgs[param]));
	int res = token->getparam(param, 0);
	delete token;
	return res;

}
void settings::set(string param, string value){

	tokenizer * token = new stringtokenizer(&(sgs[param]));
	token->setparam(param, value);
	delete token;

}
void settings::set(string param, int value){

	tokenizer * token = new stringtokenizer(&(sgs[param]));
	token->setparam(param, value);
	delete token;

}
settings::settings(){}
settings::~settings(){}

setgettable settings::operator [](string param){

	return get(param);

}

//#end
