#ifndef SQUID_CPP
#define SQUID_CPP
#include "Squid.h"
#include <iostream>


Squid::Squid(int startX, int startY, int endX, int endY) {
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
bool Squid::isSquid(int x, int y) {
	for (int i = 0; i < this->xLoc.size(); i++) {
		if (this->xLoc.at(i) == x && this->yLoc.at(i) == y) {
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
#endif