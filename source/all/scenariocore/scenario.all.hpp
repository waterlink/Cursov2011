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
//	class scenario
//	interface
//	class for managing commands
//

#ifndef scenario_hpp
#define scenario_hpp

#include "command.all.hpp"
#include "../filecore/filesystem.all.hpp"
#include "../filecore/file.all.hpp"
#include "../filecore/pather.all.hpp"

#include <vector>
#include <string>

using namespace std;

class
scenario{

public:

	scenario(pather * decoder, izprog * zprog, ibtexec * btexec);
	virtual ~scenario();

	virtual void addcommand(command * com);
	virtual void delcommand(command * com);
	virtual void run();
	virtual void clear();
	virtual void save();
	virtual void save(string path);
	virtual void load();
	virtual void load(string path);
	virtual bool issaved();
	virtual void prepare();

protected:

	

private:

	vector < command * > commands;

	filesystem * fs;
	file * scenariofile;

	izprog * zprog;
	ibtexec * btexec;

	bool saved;

};

#endif

//#end
