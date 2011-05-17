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
//	class strategycore
//	interface
//	interface for all algos
//

#ifndef strategycore_hpp
#define strategycore_hpp

#include "../markercore/markermap.all.hpp"

class
strategycore{

public:

	virtual ~strategycore(){}
	virtual void setupmarkersource(markermap * markersource) = 0;
	virtual bool go() = 0;

protected:

	

private:

	

};

#endif

//#end
