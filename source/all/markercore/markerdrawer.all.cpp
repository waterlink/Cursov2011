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
//	class, makes primitive for desired marker
//

#include "markerdrawer.all.hpp"

#include "../utilcore/stringtokenizer.all.hpp"

string markerdrawer::draw(marker * mar, pair < int, int > decodedcoords){

#define ret \
		delete token; \
		return res;

	string res = "";
	tokenizer * token = new stringtokenizer(&res);

	if (mar->gettype() == "startpoint"){

		token->setparam("primitive", "rectangle");
		token->setparam("x", decodedcoords.first);
		token->setparam("y", decodedcoords.second);
		token->setparam("w", 10);
		token->setparam("h", 10);
		token->setparam("rcolor", 0);
		token->setparam("gcolor", 0);
		token->setparam("bcolor", 150);

	}
	else if (mar->gettype() == "target"){

		token->setparam("primitive", "rectangle");
		token->setparam("x", decodedcoords.first);
		token->setparam("y", decodedcoords.second);
		token->setparam("w", 10);
		token->setparam("h", 10);
		token->setparam("rcolor", 0);
		token->setparam("gcolor", 150);
		token->setparam("bcolor", 0);

	}
	else if (mar->gettype() == "multitarget"){

		token->setparam("primitive", "rectangle");
		token->setparam("x", decodedcoords.first);
		token->setparam("y", decodedcoords.second);
		token->setparam("w", 10);
		token->setparam("h", 10);
		token->setparam("rcolor", 150);
		token->setparam("gcolor", 0);
		token->setparam("bcolor", 0);

	}

	ret;

#undef ret

}

//#end
