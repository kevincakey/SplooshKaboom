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
	}
	toCreate->setXLoc(begX, endX);
	toCreate->setYLoc(begY, endY);
}