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
//	class targetoptimal
//	interface
//	optimal strategy for targets
//

#ifndef targetoptimal_hpp
#define targetoptimal_hpp

#include "strategycore.all.hpp"
#include "../robocore/improg.all.hpp"
#include "../robocore/izprog.all.hpp"

class
targetoptimal: public strategycore{

public:

	targetoptimal();
	~targetoptimal();
	void setupmarkersource(markermap * markersource);
	bool go();

	virtual void setupmprog(improg * mprog);
	virtual void setupmap(string mapname);
	virtual void setupzprog(izprog * zprog);

protected:

	

private:

	markermap * markersource;
	improg * mprog;
	string mapname;
	izprog * zprog;

};

#endif

//#end
