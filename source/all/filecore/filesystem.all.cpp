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
//	class for managing filesystem
//

#include "filesystem.all.hpp"

#include "../utilcore/logger.all.hpp"

filesystem::filesystem(){

       path = "/";

}
filesystem::~filesystem(){}

void filesystem::cd(string path){

       while (1){

               if (path.size() == 0) break;
               if (path[path.size() - 1] != '/') break;
               path.erase(path.size() - 1, 1);

       }

       if (path == "")
               this->path = "/";
       else if (path[0] == '/')
               this->path = path;
       else this->path = this->path + path;

	new logger(0, "filecore--filesystem::cd::debug: resulting path is " + this->path + "\n");

}
string filesystem::pwd(){

       return path;

}
void filesystem::pathsetup(pather * decoder){

       this->decoder = decoder;

}
file * filesystem::getfile(string name){

       if (!decoder) return 0;

       string path = this->path + "/" + name;
	new logger(0, "filecore--filesystem::getfile::debug: passing path " + path + "\n");
       string OSpath = decoder->decode(path);
	new logger(0, "filecore--filesystem::getfile::debug: OS path " + OSpath + "\n");

       return new file(OSpath);

}

//#end
