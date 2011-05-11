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
//	class Wview
//	interface
//	guicore view class for winapi
//

#ifndef Wview_hpp
#define Wview_hpp

#include <list>

#include "../../all/guicore/view.all.hpp"
#include "../../all/guicore/form.all.hpp"

using namespace std;

class
Wview: public view{

public:

	Wview(string name, form * parent);
	~Wview();

	void draw(string primitive);
	void undraw(string primitive);

	// component:
	int dispatch(string message);
	void setparent(component * parent);
	component * getparent();
	string getname();

	// sizeble:
	pair < int, int > getsize();
	pair < int, int > getposition();
	void setsize(int w, int h);
	void setposition(int x, int y);
	void setresize(messager * onresize);
	void setparentresize(messager * onparentresize);

	// mousecaptureble:
	void setmousedown(messager * onmousedown);
	void setmouseup(messager * onmouseup);
	void setmousemove(messager * onmousemove);

	// paintable:
	void setpaint(messager * onpaint);

protected:

	

private:

	string name;
	component * parent;

	list < string > drawqueue;

	pair < int, int > position;
	pair < int, int > size;

	pair < int, int > psize;
	pair < int, int > cposition;
	pair < int, int > csize;

	messager * onmousedown;
	messager * onmouseup;
	messager * onmousemove;

	messager * onpaint;

	messager * onresize;
	messager * onparentresize;

};

#endif

//#end
