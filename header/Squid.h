#pragma once
#ifndef SQUID_H
#define SQUID_H
#include <vector>
using namespace std;
class Squid {
private:
	vector<int> xLoc;
	vector<int> yLoc;

public:
	Squid(int, int, int, int);
	bool isSquid(int, int);
	vector<int> getXPos();
	vector<int> getYPos();
};

#endif