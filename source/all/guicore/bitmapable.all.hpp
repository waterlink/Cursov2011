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
//	class bitmapable
//	interface
//	interface for components with bitmaps
//

#ifndef bitmapable_hpp
#define bitmapable_hpp

#include <string>

using namespace std;

class
bitmapable{

public:

	virtual
	~bitmapable() = 0;

	virtual bool
	loadbitmap(string path) = 0;

	virtual void
	setbitsize(int w, int h) = 0;

protected:

	

private:

	

};

#endif

//#end
