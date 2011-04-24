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
//	class izprog
//	interface
//	interface for z0rch's program
//

#ifndef izprog_hpp
#define izprog_hpp

/*	#doc class robocore--izprog
		interface for external module (z0rch's program)
		used for movement, light and beep

		allows to build scenario for robot and
		use external module to run it
*/
class
izprog{

public:

	virtual
	~izprog() = 0;

/* 	#doc robocore--izprog::passstartcoords
		void
		passstartcoords(
					int sx, int sy,
					int lx, int ly
				);

		this method passes to external module
		current robot coordinates (sx; sy) 
		and offset of his look (lx; ly) 
*/
	virtual void
	passstartcoords(int sx, int sy, int lx, int ly) = 0;
//	#docend robocore--izprog::passstartcoords

/*	#doc robocore--izprog::moverel
		void
		moverel( int dx, int dy );

		this method passes next target 
		with offset from current position (dx; dy)
		to external module
*/
	virtual void
	moverel(int dx, int dy) = 0;
//	#docend robocore--izprog::moverel

/*	#doc robocore--izprog::beep
		void
		beep();

		this method passes command for robot
		to beep through external module
*/
	virtual void
	beep() = 0;
//	#docend robocore--izprog::beep

/*	#doc robocore--izprog::setlight
		void
		setlight(bool fLight);

		this method passes command for robot
		to enable/disable light through
		external module
*/
	virtual void
	setlight(bool fLight) = 0;
//	#docend robocore--izprog::setlight

/*	#doc robocore--izprog::run
		void
		run();

		this method passes command to external
		module to run builded scenario for robot
*/
	virtual void
	run() = 0;
//	#docend robocore--izprog::run

protected:

	

private:

	

};
// 	#docend class robocore--izprog

#endif

//#end
