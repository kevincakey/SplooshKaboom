#include "../header/medium.h"
#include <iostream>

using namespace std;

void Medium::makeSquids(Squid* toCreate) {
	int begX = 0;
	int endX = 0;
	int begY = 0;
	int endY = 0;

	begX = rand() % 8;
	begY = rand() % 8;

	bool sameX = rand() % 2;//if 1, then same x, if 0 then same y

	if (sameX) {
		endX = begX;

		endY = rand() % 8;
		if (begY > endY) {
			swap(begY, endY);
		}
		//cout << "endY is: " << endY << " and begY is: " << begY << endl;
		while ((endY - begY > 4) || (endY - begY == 0)) {
			//cout << "endY is: " << endY << " and begY is: " << begY << endl;
			endY = rand() % 8;
			if (begY > endY) {
				swap(begY, endY);
			}
		}
		//begY++;//changing begY so that it can't be 0 to make it more clear that the hit position should be tile x,1
	}
	else {
		endY = begY;

		endX = rand() % 8;
		if (begX > endX) {
			swap(begX, endX);
		}
		//cout << "endx is: " << endX << " and begX is: " << begX << endl;
		while ((endX - begX > 4) || (endX - begX == 0)) {
			//cout << "endx is: " << endX << " and begX is: " << begX << endl;
			endX = rand() % 8;
			if (begX > endX) {
				swap(begX, endX);
			}
		}
		//begX++;//making it so x can't be 0
	}
	begX++;
	endX++;

	begY++;
	endY++;
	if (begX != endX) {
		for (int i = begX; i <= endX; i++) {
			toCreate->setXLoc(i);
			toCreate->setYLoc(begY);
		}
	}
	else if(begY != endY) {
		for (int i = begY; i <= endY; i++) {
			toCreate->setXLoc(begX);
			toCreate->setYLoc(i);
		}
	}
	else {
		cout << "error: squid creation failed" << endl;
		exit(1);
	}
}