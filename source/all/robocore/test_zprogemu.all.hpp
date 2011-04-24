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
//	class test_zprogemu
//	interface
//	console emulator of external module z0rch's program
//

#ifndef test_zprogemu_hpp
#define test_zprogemu_hpp

#include <string>
#include <vector>
#include <cstdio>

#include "izprog.all.hpp"
#include "test_roboemu_params.all.hpp"

using namespace std;

/*	#doc class robocore--test_zprogemu
		test class

		emulates robot and z0rch's program
		using console for logging
*/
class
test_zprogemu: public izprog{

public:

/*	#doc robocore--test_zprogemu::test_zprogemu
		test_zprogemu(
					test_roboemu_params * sample
				);

		links this emulator to specific robot params
*/
	test_zprogemu(test_roboemu_params * sample);
//	#docend robocore--test_zprogemu::test_zprogemu

	~test_zprogemu();

	void
	passstartcoords(int sx, int sy, int lx, int ly);

	void
	moverel(int dx, int dy);

	void
	beep();

	void
	setlight(bool fLight);

	void
	run();

protected:

	

private:

	test_roboemu_params 
	*sample;

	int
	sx, sy, lx, ly;

	vector < pair < char, pair < int, int > > >
	comm;
	

};
//	#docend class robocore--test_zprogemu

#endif

//#end
