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
//	tokenizer realization for strings
//

#include "stringtokenizer.all.hpp"

#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>

using namespace std;

stringtokenizer::stringtokenizer(string * data){ this->data = data; }
stringtokenizer::~stringtokenizer(){}
void stringtokenizer::setparam(string param, string value){

	string & data = *(this->data);

	string v = getparam(param);
	if (v == ""){

		data = data + param + ":" + value + " ";
		return;

	}
	string pv = param + ":" + v;
	string npv = param + ":" + value;
	int found = data.find(pv);
	data.replace(found, pv.size(), npv);

}
string stringtokenizer::getparam(string param){

	string & data = *(this->data);

	string p = param + ":";
	int found = data.find(p);
	if (found == string::npos) return "";
	int found2 = data.find(" ", found + 1);
	found += p.size();
	return data.substr(found, found2 - found);

}
int stringtokenizer::getparam(string param, int){

	string S = getparam(param);
	char * buff = new char[S.size() + 10];
	strcpy(buff, S.c_str());
	int x = LONG_MAX;
	sscanf(buff, "%d", &x);
	return x;

}

//#end
