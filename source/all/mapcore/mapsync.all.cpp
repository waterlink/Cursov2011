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
//	class to sync bits and map
//

#include "mapsync.all.hpp"

mapsync::mapsync(mapcore * mapsource, array * bitsource){

	this->mapsource = mapsource;
	this->bitsource = bitsource;

}
mapsync::~mapsync(){}
void mapsync::msync(){

	pair < int, int > size = mapsource->getsize();
	int w = size.first;
	int h = size.second;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; ++j)
			mapsource->setvalue(i, j, bitsource->get(i * w + j));

}
void mapsync::bsync(){

	pair < int, int > size = mapsource->getsize();
	int w = size.first;
	int h = size.second;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; ++j)
			//mapsource->setvalue(i, j, bitsource->get(i * w + j));
			bitsource->set(i * w + j, mapsource->getvalue(i, j));

}

//#end
