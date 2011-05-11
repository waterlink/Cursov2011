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
//	class pather
//	interface
//	class for managing paths
//

#ifndef pather_hpp
#define pather_hpp

class
pather{

public:

	virtual ~pather(){}

	virtual string decode(string path) = 0;

protected:

	

private:

	

};

#endif

//#end
