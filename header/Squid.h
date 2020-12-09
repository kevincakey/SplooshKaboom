#pragma once
#ifndef SQUID_H
#define SQUID_H
#include "difficulty.h"
#include <iostream>
#include <vector>
using namespace std;

class Difficulty;

class Squid {
private:
	vector<int> xLoc;
	vector<int> yLoc;
	Difficulty* howHard;

public:
	Squid() { howHard = nullptr; };
	Squid(int, int, int, int);
	void createSquid();
	bool isSquid(int, int);
	vector<int> getXPos();
	vector<int> getYPos();
	void setXLoc(int, int);
	void setYLoc(int, int);
	void setDifficulty(Difficulty* difficulty);
};

#endif