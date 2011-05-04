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
//	class hwndmaster
//	interface
//	class for managing hwnd's
//

#ifndef hwndmaster_hpp
#define hwndmaster_hpp

#include <map>

#include "Wform.win.hpp"

using namespace std;

class
hwndmaster{

public:

	static Wform * byhandle(HWND hwnd);
	static HWND byform(Wform * frm);
	static void newform(HWND hwnd, Wform * frm);

protected:

	

private:

	static map < HWND, Wform * > handle_form;
	static map < Wform *, HWND > form_handle;

};

#endif

//#end
