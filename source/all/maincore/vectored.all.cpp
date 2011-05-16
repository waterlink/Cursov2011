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
//	class array realization
//

#include "vectored.all.hpp"

int vectored::get(int index){

	if (index >= V.size())
		V.resize(2 * (index + 1));

	return V[index];

}
void vectored::set(int index, int value){

	if (index >= V.size())
		V.resize(2 * (index + 1));

	V[index] = value;

}

//#end
