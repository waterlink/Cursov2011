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
//	class vectored
//	interface
//	class array realization
//

#ifndef vectored_hpp
#define vectored_hpp

#include "datamanager.all.hpp"

#include <vector>

using namespace std;

class
vectored: public array{

public:

	vectored(){}
	~vectored(){}

	int get(int index);
	void set(int index, int value);

protected:

	

private:

	vector < int > V;

};

#endif

//#end
