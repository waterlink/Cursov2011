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
//	class edge simple realization
//

#include "simpleedge.all.hpp"

#include "../utilcore/logger.all.hpp"

#include <cstdlib>

simpleedge::simpleedge(){}
simpleedge::~simpleedge(){}
marker * simpleedge::getA(){ return A; }
marker * simpleedge::getB(){ return B; }
void simpleedge::setA(marker * A){ this->A = A; }
void simpleedge::setB(marker * B){ this->B = B; }

// 0 - gray (unknown)
// 1 - red (forbidden)
// 2 - yellow (non-optimal way)
// 3 - green (optimal way)
int simpleedge::determine(){

	new logger(1, "markercore--simpleedge::fixme: stub, rand\n");
	return 0;

}

//#end
