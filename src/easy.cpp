#include "../Header/easy.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

//bigger squids means easier to find
void Easy::makeSquids(Squid* toCreate) {
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
		while (endY - begY < 5) {
			endY = rand() % 8;
			if (begY > endY) {
				swap(begY, endY);
			}
		}
	}
	else {//if y is to be the same
		endY = begY;

		endX = rand() % 8;
		if (begX > endX) {
			swap(begX, endX);
		}
		while (endX - begX < 5) {//squids can't be smaller than 5 units
			endX = rand() % 8;
			if (begX > endX) {
				swap(begX, endX);
			}
		}
	}
	begX++;
	begY++;

	endX++;
	endY++;

	if (begX != endX) {
		for (int i = begX; i <= endX; i++) {
			toCreate->setXLoc(i);
			toCreate->setYLoc(begY);
		}
	}
	else if (begY != endY) {
		for (int i = begY; i <= endY; i++) {
			toCreate->setXLoc(begX);
			toCreate->setYLoc(i);
		}
	}
	else {
		cout << "error: squid creation failed" << endl;
		exit;
	}
}