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
//	class edgedrawer
//	interface
//	class, creates primitive for edges
//

#ifndef edgedrawer_hpp
#define edgedrawer_hpp

#include "edge.all.hpp"

#include <string>

using namespace std;

class
edgedrawer{

public:

	static string draw(edge * edg, pair < int, int > Bdecodedcoords, pair < int, int > Adecodedcoords);

protected:

	

private:

	

};

#endif

//#end
