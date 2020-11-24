#ifndef __ALTERTILE_H__
#define __ALTERTILE_H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class AlterTile {
private:
	vector<int> xLoc;
	vector<int> yLoc;
	bool hit;
public:
	AlterTile();
	AlterTile(vector<int>,vector<int>);
	bool checkHit(int, int);
	void displayChange(int, int, string);
};

#endif
