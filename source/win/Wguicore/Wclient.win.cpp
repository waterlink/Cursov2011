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
//	gui class client for winapi
//

#include "Wclient.win.hpp"

#include <cstdio>
#include <cstdlib>

#include "Wform.win.hpp"

#include <windows.h>

int processmessage(
			Wclient *, 
			form *, 
			map < int, component * > *, 
			HACCEL,
			int & rescode 
		);
long WINAPI wndproc(HWND hWnd, UINT Message, UINT wParam, LONG lParam){

	// TODO: code this up!

	switch (Message){

		case WM_DESTROY: 
			PostQuitMessage(0);
			return 0;

	}

	return DefWindowProc(hWnd,Message,wParam,lParam);

}
int processmessage(
			Wclient * pcl, 
			Wform * pfrm, 
			map < int, component * > * pIC, 
			HACCEL hAcc,
			int & rescode 
		){

	MSG Msg;
	HWND hWnd = pfrm->gethandle();
	int flag = 1;
	fprintf(stderr, "Wguicore--processmessage::debug: here!\n");
	int val = GetMessage(&Msg, NULL, 0, 0);
	fprintf(stderr, "Wguicore--processmessage::debug: here!\n");
	if (val == -1){

		// error handling
		flag = 0;

	}
	else if (val == 0) flag = 0;
	else {

		if (hAcc != NULL){
			if(!TranslateAccelerator(hWnd,hAcc,&Msg)){

				TranslateMessage(&Msg);
				// in our wndproc function will be 
				DispatchMessage(&Msg);

			}
		}
		else {

			TranslateMessage(&Msg);
			// in our wndproc function will be 
			DispatchMessage(&Msg);

		}

	}

	rescode = Msg.wParam;

	return flag;

}

// client methods
Wclient::Wclient(string name){

	this->name = name;

}
Wclient::~Wclient(){

	for (map < string, component * >::iterator iter = forms.begin(); iter != forms.end(); ++iter)
		delete iter->second;
	forms.clear();

}
int Wclient::mainloop(){

	// TODO: code here mainloop with message dispatching for winapi
	/*

		// so, i need method, that could read all hwnds of my windows,
		// has all accel tables handles, parsing this all mess with message to
		// wndproc, there must be somewhere map < hwnd, form * >, and maybe
		// reverted, wndproc must parse message and compose string and return somehow
		// it to this class, i think it must call dispatch. Additional wndproc needs
		// map < control id, component * >

		// here must be something like:

		bool flag = true;
		int val;
		while (flag){

			// first one, i need here to extract message and compose it to string
			val = GetMessage(&Msg,NULL,0,0));
			if (val == -1){

				// error handling
				flag = 0;

			}
			else if (val == 0) flag = 0;
			else {

				// if some of them translated succesfully, i don't need do nothing, so i need some
				// way to return special nothing-to-do flag
				//
				// here iterating for all our forms and checking if Accelerator passed
				// if not, then:
				{

					TranslateMessage(&Msg);
					// in our wndproc function will be 
					DispatchMessage(&Msg);

				}

			}

		}
		return Msg.wParam;

	*/
	int rescode = 0;
	while (processmessage(this, (Wform *)(forms[mainform]), NULL, NULL, rescode)){

		fprintf(stderr, "Wguicore--Wclient::mainloop::fixme: stub\n");
		dispatch("");

	}
	return rescode;

}
void Wclient::newform(form * container, bool show){

	// check if form exists
	string cname = container->getname();
	if (forms[cname] != NULL)
		return;

	// add our form
	forms[cname] = container;

	// show form
	if (show)
		container->show();

}
void Wclient::newmainform(form * container){

	// setup our main form
	string cname = container->getname();
	mainform = cname;

	// check if exists
	if (forms[cname] != NULL)
		return;

	// add our main form
	forms[cname] = container;

	// show main form
	container->show();

}

// component methods
int Wclient::dispatch(string message){

	// TODO: make this work with winapi
	// TODO: use tokenizer here
	fprintf(stderr, "Wguicore--Wclient::dispatch::fixme: stub\nMessage is: %s\n", message.c_str());

}
void Wclient::setparent(component * parent){

	fprintf(stderr, "Wguicore--Wclient::setparent::warning can't change parent of application, ignoring\n");

}
component * Wclient::getparent(){

	fprintf(stderr, "Wguicore--Wclient::getparent::warning can't get parent of application, returning NULL\n");
	return NULL;

}
string Wclient::getname(){

	return name;

}

//#end
