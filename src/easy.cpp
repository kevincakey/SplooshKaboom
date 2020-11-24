#include "../Header/easy.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;


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
		while (endY - begY < 3){
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
		while (endX - begX < 3) {
			endX = rand() % 8;
			if (begX > endX) {
				swap(begX, endX);
			}
		}
	}
	toCreate->setXLoc(begX, endX);
	toCreate->setYLoc(begY, endY);
}