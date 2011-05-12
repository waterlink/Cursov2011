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
//	class markerdrawer
//	interface
//	class, makes primitive for desired marker
//

#ifndef markerdrawer_hpp
#define markerdrawer_hpp

#include "marker.all.hpp"

#include <string>

using namespace std;

class
markerdrawer{

public:

	static string draw(marker * mar, pair < int, int > decodedcoords);

protected:

	

private:

	

};

#endif

//#end
