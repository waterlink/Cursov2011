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
//	class mather
//	interface
//	class for managing mathematics
//

#ifndef mather_hpp
#define mather_hpp

#include <map>

using namespace std;

class
mather{

public:

	static pair < double, double > rotate(pair < double, double > X, double a);
	static pair < double, double > rotateex(pair < double, double > X, double a, pair < double, double > X0);
	static double dist(pair < double, double > X);
	static double distex(pair < double, double > X, pair < double, double > Y);
	static pair < double, double > normalize(pair < double, double > X, double D);
	static pair < double, double > normalizeex(pair < double, double > X, double D, pair < double, double > X0);
	static double epsilon();
	static double pi();

protected:

	

private:

	

};

#endif

//#end
