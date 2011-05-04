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
//	class for managing hwnd's
//

#include "hwndmaster.win.hpp"

map < HWND, Wform * > hwndmaster::handle_form;
map < Wform *, HWND > hwndmaster::form_handle;

Wform * hwndmaster::byhandle(HWND hwnd){

	return handle_form[hwnd];

}
HWND hwndmaster::byform(Wform * frm){

	return form_handle[frm];

}
void hwndmaster::newform(HWND hwnd, Wform * frm){

	handle_form[hwnd] = frm;
	form_handle[frm] = hwnd;

}

//#end
