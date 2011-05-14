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
//	class datamanager
//	interface
//	class for managing huge datastructures
//

#ifndef datamanager_hpp
#define datamanager_hpp

#include <map>

using namespace std;

class
datamanager{

public:

	static void * getbyid(int id);
	static int getbydata(void * data);
	static void add(int id, void * data);

protected:

	

private:

	static map < int, void * > byid;
	static map < void *, int > bydata;

};

#endif

//#end
