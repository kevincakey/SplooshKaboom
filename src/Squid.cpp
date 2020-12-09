#ifndef SQUID_CPP
#define SQUID_CPP
#include "../header/Squid.h"
#include <iostream>


Squid::Squid(int startX, int startY, int endX, int endY) {//should only be called by the difficulty stategy pattern
	if (startX > endX) {
		swap(startX, endX);
	}
	if (startY > endY) {
		swap(startY, endY);
	}
	if (startX < 1 || endX < 1 || startY < 1 || endY < 1) {
		cout << "invalid entries. \n exiting program" << endl;
		exit;
	}
	int numTiles = 0;
	if (startX == endX) {
		numTiles = endY - startY + 1;
		for (int i = 0; i < numTiles; i++) {
			this->xLoc.push_back(startX);
			this->yLoc.push_back(startY);
			startY++;
		}
	}
	else if (startY = endY) {
		numTiles = endX - startX + 1;
		for (int i = 0; i < numTiles; i++) {
			this->xLoc.at(i) = startX;
			this->yLoc.at(i) = startY;
			startX++;
		}
	}
	else {
		//int x = startX;
		//int y = startY;
		int numXTiles = endX - startX + 1;
		int numYTiles = endY - startY + 1;
		for (int i = 0; i < numXTiles; i++) {
			this->xLoc.at(i) = startX;
			startX++;
		}
		for (int i = 0; i < numYTiles; i++) {
			this->yLoc.at(i) = startY;
			startY++;
		}
	}

}

void Squid::createSquid() {
	howHard->makeSquids(this);
}
bool Squid::isSquid(int x, int y) {

	for (int i = 0; i < xLoc.size(); i++) {
		if (x == xLoc.at(i) && y == yLoc.at(i)) {
			return true;
		}
	}
	return false;
}
vector<int> Squid::getXPos() {
	return this->xLoc;
}
vector<int> Squid::getYPos() {
	return this->yLoc;
}

void Squid::setDifficulty(Difficulty* difficulty) {
	this->howHard = difficulty;
}
void Squid::setXLoc(int x) {
	this->xLoc.push_back(x);
}
void Squid::setYLoc(int y) {
	this->yLoc.push_back(y);
}
#endif