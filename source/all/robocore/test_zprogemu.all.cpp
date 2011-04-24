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
//	console emulator of external module z0rch's program
//

#include "test_zprogemu.all.hpp"

test_zprogemu::test_zprogemu(test_roboemu_params * sample){

	this->sample = sample;
	comm.clear();

}

test_zprogemu::~test_zprogemu(){ comm.clear(); }

void
test_zprogemu::passstartcoords(int sx, int sy, int lx, int ly){

	this->sx = sx;
	this->sy = sy;
	this->lx = lx;
	this->ly = ly;

}

void
test_zprogemu::moverel(int dx, int dy){

	comm.push_back(make_pair('m', make_pair(dx, dy)));

}

void
test_zprogemu::beep(){

	comm.push_back(make_pair('b', make_pair(0, 0)));

}

void
test_zprogemu::setlight(bool fLight){

	comm.push_back(make_pair('l', make_pair(fLight, 0)));

}

void
test_zprogemu::run(){

	for (int i = 0; i < comm.size(); ++i){

		printf(
			"%c %d %d\n", 
			comm[i].first, 
			comm[i].second.first, 
			comm[i].second.second
		);

	}

}

//#end
