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
//	class filesystem
//	interface
//	class for managing filesystem
//

#ifndef filesystem_hpp
#define filesystem_hpp

#include "pather.all.hpp"
#include "file.all.hpp"

class
filesystem{

public:

	filesystem();
	virtual ~filesystem();

	virtual void cd(string path);
	virtual string pwd();
	virtual void pathsetup(pather * decoder);
	virtual file * getfile(string name);

protected:

	

private:

	string path;
	pather * decoder;

};

#endif

//#end
