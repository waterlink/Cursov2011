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
//	class, creates primitive for edges
//

#include "edgedrawer.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

string edgedrawer::draw(edge * edg, pair < int, int > Adecodedcoords, pair < int, int > Bdecodedcoords){

#define ret \
		delete token; \
		return res;

	string res = "";
	tokenizer * token = new stringtokenizer(&res);

	token->setparam("primitive", "line");
	token->setparam("x", Adecodedcoords.first);
	token->setparam("y", Adecodedcoords.second);
	token->setparam("w", Bdecodedcoords.first - Adecodedcoords.first);
	token->setparam("h", Bdecodedcoords.second - Adecodedcoords.second);
	token->setparam("thickness", 2);

	if (edg->determine() == 0){

		token->setparam("rcolor", 100);
		token->setparam("gcolor", 100);
		token->setparam("bcolor", 100);

	}
	else if (edg->determine() == 1){

		token->setparam("rcolor", 255);
		token->setparam("gcolor", 0);
		token->setparam("bcolor", 0);

	}
	else if (edg->determine() == 2){

		token->setparam("rcolor", 0);
		token->setparam("gcolor", 255);
		token->setparam("bcolor", 255);

	}
	else if (edg->determine() == 3){

		token->setparam("rcolor", 0);
		token->setparam("gcolor", 255);
		token->setparam("bcolor", 0);

	}

	ret;

#undef ret

}

//#end
