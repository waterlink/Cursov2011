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
//	class for managing mathematics
//

#include "mather.all.hpp"

#include <cmath>

#define eps 1e-9

pair < double, double > mather::rotate(pair < double, double > X, double a){

	double x = X.first;
	double y = X.second;
	double rx = x * cos(a) + y * sin(a);
	double ry = x * sin(a) - y * cos(a);
	return make_pair(rx, ry);

}
pair < double, double > mather::rotateex(pair < double, double > X, double a, pair < double, double > X0){

	pair < double, double > Y = mather::rotate(make_pair(X.first - X0.first, X.second - X0.second), a);
	Y.first += X0.first;
	Y.second += X0.second;
	return Y;

}
double mather::dist(pair < double, double > X){ return sqrt(X.first * X.first + X.second * X.second); }
double mather::distex(pair < double, double > X, pair < double, double > Y){ 

	return mather::dist(make_pair(X.first - Y.first, X.second - Y.second));

}
pair < double, double > mather::normalize(pair < double, double > X, double D){

	pair < double, double > res;
	res.first = X.first * D / mather::dist(X);
	res.second = X.second * D / mather::dist(X);
	return res;

}
pair < double, double > mather::normalizeex(pair < double, double > X, double D, pair < double, double > X0){

	pair < double, double > Y = mather::normalize(make_pair(X.first - X0.first, X.second - X0.second), D);
	Y.first += X0.first;
	Y.second += X0.second;
	return Y;

}
double mather::epsilon(){ return eps; }

//#end
