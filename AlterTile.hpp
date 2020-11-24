#ifndef __ALTERTILE_HPP__
#define __ALTERTILE_HPP__

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
