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
//	class for drawing pixels of map
//

#include "pixeldrawer.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

int pixeldrawer::draw(int type){

	// unknown - gray
	if (type == 0) return 150 + (150 << 8) + (150 << 16);
	// free - white
	if (type == 1) return 255 + (255 << 8) + (255 << 16);
	// obstacle - black
	if (type == 2) return 0;

}

string pixeldrawer::drawall(int x, int w, int h){

	string res;
	tokenizer * token = new stringtokenizer(&res);

		token->setparam("primitive", "bits");
		token->setparam("x", x);
		token->setparam("w", w);
		token->setparam("h", h);

	delete token;
	return res;

}

//#end
