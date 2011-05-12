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
//	class edge
//	interface
//	class edge, abstract, connects two markers, oriented
//

#ifndef edge_hpp
#define edge_hpp

#include "marker.all.hpp"

class
edge{

public:

	virtual ~edge(){}
	virtual marker * getA() = 0;
	virtual marker * getB() = 0;
	virtual void setA(marker * A) = 0;
	virtual void setB(marker * B) = 0;

	// 0 - gray (unknown)
	// 1 - red (forbidden)
	// 2 - yellow (non-optimal way)
	// 3 - green (optimal way)
	virtual int determine() = 0;

protected:

	

private:

	

};

#endif

//#end
