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
//	class map, realization, for test purposes
//

#include "test_simplemap.all.hpp"

#include "../utilcore/logger.all.hpp"

test_simplemap::test_simplemap(pather * decoder){

	fs = new filesystem;
	fs->pathsetup(decoder);
	fs->cd("/map");

}
test_simplemap::~test_simplemap(){

	mapfile->close();
	delete mapfile;
	delete fs;

}
void test_simplemap::choose(string name){

	mapfile = fs->getfile(name);

}
void test_simplemap::load(){

	mapfile->ropen();
	if (mapfile->isopened() == false)
		new logger(0, "mapcore--test_simplemap::load::warning: file is not opened\n");
	int w = mapfile->nextint();
	int h = mapfile->nextint();
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; ++j)
			M[make_pair(i, j)] = mapfile->nextint();

	char logbuf[200];
	sprintf(logbuf, "mapcore--test_simplemap::load::debug: map size = %d, w = %d, h = %d\n", M.size(), w, h);
	new logger(0, logbuf);

}
void test_simplemap::save(){

	int w = 0, h = 0;
	for (map < pair < int, int >, int >::iterator iter = M.begin(); iter != M.end(); ++iter){

		if (iter->first.first > h) h = iter->first.first;
		if (iter->first.second > w) w = iter->first.second;

	}
	++h, ++w;

	mapfile->nextint(w);
	mapfile->nextint(h);
	mapfile->nextline("");
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; ++j)
			mapfile->nextint(M[make_pair(i, j)]);

}
int test_simplemap::getvalue(int i, int j){

	return M[make_pair(i, j)];

}
void test_simplemap::setvalue(int i, int j, int v){

	M[make_pair(i, j)] = v;

}
pair < int, int > test_simplemap::getsize(){

	int w = 0, h = 0;
	for (map < pair < int, int >, int >::iterator iter = M.begin(); iter != M.end(); ++iter){

		if (iter->first.first > h) h = iter->first.first;
		if (iter->first.second > w) w = iter->first.second;

	}
	++h, ++w;

	return make_pair(w, h);

}
file * test_simplemap::getfile(){ return mapfile; }

//#end
