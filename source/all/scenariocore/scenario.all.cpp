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
//	source file
//	class for managing commands
//

#include "scenario.all.hpp"

scenario::scenario(pather * decoder, izprog * zprog, ibtexec * btexec){

	fs = new filesystem;
	fs->pathsetup(decoder);
	fs->cd("/scenaries");

	this->zprog = zprog;
	this->btexec = btexec;

}
scenario::~scenario(){

	scenariofile->close();
	delete scenariofile;
	delete fs;

}

void scenario::addcommand(command * com){

	commands.push_back(com);
	saved = false;

}
void scenario::delcommand(command * com){

	int i, j;
	for (i = 0, j = 0; i < commands.size(); ++i, ++j)
		if (commands[i] == com){ 

			--j;
			delete com;

		}
		else commands[j] = commands[i];

	commands.resize(j);
	saved = false;

}
void scenario::run(){

	// TODO::MAYBE: maybe code it in just send 1 command to robot (after preparation)

	int i, j;
	for (i = 0, j = 0; i < commands.size(); ++i, ++j)
		commands[i]->execute();

}
void scenario::clear(){

	for (int i = 0; i < commands.size(); ++i)
		delete commands[i];

	commands.clear();
	saved = false;

}
void scenario::save(){

	if (!scenariofile) return;
	scenariofile->wopen();

	scenariofile->nextint(commands.size());
	scenariofile->nextline("");

	int i, j;
	for (i = 0, j = 0; i < commands.size(); ++i, ++j)
		scenariofile->nextline(commands[i]->getsetup());

	saved = true;

}
void scenario::save(string path){

	scenariofile = fs->getfile(path);
	scenariofile->wopen();

	scenariofile->nextint(commands.size());
	scenariofile->nextline("");

	int i, j;
	for (i = 0, j = 0; i < commands.size(); ++i, ++j)
		scenariofile->nextline(commands[i]->getsetup());

	saved = true;

}
void scenario::load(){

	if (!scenariofile) return;
	scenariofile->ropen();

	commands.resize(scenariofile->nextint());

	int i, j;
	for (i = 0, j = 0; i < commands.size(); ++i, ++j){

		string scom = scenariofile->nextline();
		command * com = new command(zprog, btexec);
		com->setup(scom);
		commands[i] = com;

	}

	saved = true;

}
void scenario::load(string path){

	scenariofile = fs->getfile(path);
	scenariofile->ropen();

	commands.resize(scenariofile->nextint());

	int i, j;
	for (i = 0, j = 0; i < commands.size(); ++i, ++j){

		string scom = scenariofile->nextline();
		command * com = new command(zprog, btexec);
		com->setup(scom);
		commands[i] = com;

	}

	saved = true;

}
bool scenario::issaved(){ return saved; }
void scenario::prepare(){

	// TODO: code this up

}

//#end
