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
//	class simpleedge
//	interface
//	class edge simple realization
//

#ifndef simpleedge_hpp
#define simpleedge_hpp

#include "edge.all.hpp"

class
simpleedge: public edge{

public:

	simpleedge();
	~simpleedge();
	marker * getA();
	marker * getB();
	void setA(marker * A);
	void setB(marker * B);

	// 0 - gray (unknown)
	// 1 - red (forbidden)
	// 2 - yellow (non-optimal way)
	// 3 - green (optimal way)
	// 4 - blue (robot offset)
	int determine();
	void setcolor(int color);

protected:

	

private:

	marker * A, * B;
	int color;

};

#endif

//#end
