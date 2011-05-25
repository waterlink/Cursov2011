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
//	class logic
//	interface
//	class controlling main processes in program
//

#ifndef logic_hpp
#define logic_hpp

#include "../guicore/guicore.all.hpp"
#include "../mapcore/mapmanager.all.hpp"
#include "../filecore/pather.all.hpp"
#include "../markercore/markermanager.all.hpp"
#include "../mapcore/mapcore.all.hpp"

class
logic{

public:

	logic();
	logic(
		client * app,
		form * form1,
		button * btn1,
		view * view1,
		toolbox * toolbox1,
		button * btn2,
		button * btn3,
		status * stat1,
		properties * prop1,
		menu * mmain,
		menu * mfile,
		menu * mq,
		menu * mfile_exit,
		menu * mq_about,

		pather * decoder,

		button * selectmode,
		button * startpointmode,
		button * targetmode,
		button * multitargetmode,
		button * freemode,

		menu * mtest,
		menu * mtestrun
	);

	int run();

	void changetoolboxmode(component * pressed);

	markermap * getmarkers();
	mapcore * getmap();
	pather * getdecoder();
	mapmanager * getmanager();

protected:

	

private:

	//dependent:

	client * app;
	form * form1;
	button * btn1;
	view * view1;
	toolbox * toolbox1;
	button * btn2;
	button * btn3;
	status * stat1;
	properties * prop1;
	menu * mmain;
	menu * mfile;
	menu * mq;
	menu * mfile_exit;
	menu * mq_about;

	pather * decoder;

	button * selectmode;
	button * startpointmode;
	button * targetmode;
	button * multitargetmode;
	button * freemode;

	menu * mtest;
	menu * mtestrun;

	//independent:

	mapcore * M;
	markermap * markers;
	mapmanager * manager;
	markermanager * chosenmarkertype;

} * mainlogic;

#endif

//#end
