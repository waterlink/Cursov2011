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
array{

public:

	virtual ~array(){}
	virtual int get(int index) = 0;
	virtual void set(int index, int value) = 0;

};

class
datamanager{

public:

	static array * getbyid(int id);
	static int getbydata(array * data);
	static void add(int id, array * data);

protected:

	

private:

	static map < int, array * > byid;
	static map < array *, int > bydata;

};

#endif

//#end
