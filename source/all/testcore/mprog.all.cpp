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
//	emulator class for makelov's module
//

#include "mprog.all.hpp"

#include <algorithm>

#include "../utilcore/logger.all.hpp"

#define maxn 500

class
mprog_data{

public:

	int M[maxn][maxn];
	int A[maxn][maxn];
	pair < int, int > C[maxn * maxn + 2];

};

mprog::mprog(mapcore * mc){

	this->mc = mc;

}
mprog::~mprog(){}

vector < pair < int, int > > mprog::getway(pair < int, int > A, pair < int, int > B, string mapname){

	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	int dc = 4;

	vector < pair < int, int > > R;
	R.clear();

	mc->choose(mapname);
	mc->load();
	if (mc->getvalue(B.first + 1, B.second + 1) == -1)
		return R;
	int w = mc->getsize().first;
	int h = mc->getsize().second;
	mprog_data * dt = new mprog_data;
	mprog_data & data = *dt;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			// -1 - 1 - obstacle; 0,1 - 0 - free;
			data.M[i + 1][j + 1] = ((mc->getvalue(i, j) == -1)?1:0);

	for (int i = 0; i < h + 2; ++i)
		data.M[i][0] = data.M[i][w + 1] = 1;
	for (int i = 0; i < w + 2; ++i)
		data.M[0][i] = data.M[h + 1][i] = 1;

	for (int i = 0; i < h + 2; ++i)
		for (int j = 0; j < w + 2; ++j)
			data.A[i][j] = 0;

	int sx = A.first + 1, sy = A.second + 1;
	int tx = B.first + 1, ty = B.second + 1;

	int p, d = 1;
	data.C[0] = make_pair(sx, sy);
	data.A[sx][sy] = 1;

	for (p = 0; p < d && data.A[tx][ty] == 0; ++p){

		pair < int, int > u = data.C[p];
		for (int i = 0; i < dc; ++i){

			pair < int, int > v = u;
			v.first += dx[i];
			v.second += dy[i];

			if (	data.A[v.first][v.second] == 0 &&
				data.M[v.first][v.second] == 0){

				data.C[d++] = v;
				data.A[v.first][v.second] = data.A[u.first][u.second] + 1;

			}

		}

	}

	if (data.A[tx][ty] == 0){

		return R;
		delete dt;

	}

	new logger(0, "testcore--mprog::getway::debug: bfs done. calcing a way\n");

	pair < int, int > u = make_pair(tx, ty);
	R.push_back(u);
	for (; u != make_pair(sx, sy); ){

		for (int i = 0; i < dc; ++i){

			pair < int, int > v = u;
			v.first += dx[i];
			v.second += dy[i];

			if (data.A[v.first][v.second] == data.A[u.first][u.second] - 1){

				u = v;
				R.push_back(u);
				break;

			}

		}

	}

	new logger(0, "testcore--mprog::getway::debug: calcing a way done\n");

	for (int i = 0; i < R.size() / 2; ++i)
		swap(R[i], R[R.size() - 1 - i]);

	delete dt;
	return R;

}

//#end
