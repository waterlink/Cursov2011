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

filesystem::filesystem(){

       path = ".";

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
       string OSpath = decoder->decode(path);

       return new file(OSpath);

}

//#end
