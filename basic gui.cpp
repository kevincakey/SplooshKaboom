#include "header/Squid.h"

#include "header/difficulty.h"

#include "header/easy.h"

#include "header/medium.h"

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int main() {
	srand(time(0));
	int row = 1;
	int guessX = -1;
	int guessY = -1;
	cout << "  |1|2|3|4|5|6|7|8|" << endl;
	for (int i = 0; i < 8; i++) {
		cout << row << " |~|~|~|~|~|~|~|~|" << endl;
		row = row + 1;
	}

	Squid* mainSquid = new Squid();
	Easy* easy = new Easy();
	mainSquid->setDifficulty(easy);

	mainSquid->createSquid();

	Squid* secondSquid = new Squid();
	Medium* medium = new Medium();
	secondSquid->setDifficulty(medium);

	secondSquid->createSquid();

	Squid* thirdSquid = new Squid();
	thirdSquid->setDifficulty(medium);

	thirdSquid->createSquid();

	vector<int> rowPos = mainSquid->getXPos();
	vector<int> colPos = mainSquid->getYPos();

	for (int i = 0; i < rowPos.size(); i++) {
		cout << rowPos.at(i) << " ";
		cout << colPos.at(i) << " ";
		cout << endl;
	}

	cout << "guess x is: ";
	cin >> guessX;
	cout << "guessY is: ";
	cin >> guessY;

	if (mainSquid->isSquid(guessX, guessY)) {
		cout << "is a hit!" << endl;
	}
	else {
		cout << "was not a hit :(" << endl;
	}


	rowPos = secondSquid->getXPos();
	colPos = secondSquid->getYPos();
	for (int i = 0; i < rowPos.size(); i++) {
		cout << rowPos.at(i) << " ";
		cout << colPos.at(i) << " ";
		cout << endl;
	}

	cout << "guess x is: ";
	cin >> guessX;
	cout << "guessY is: ";
	cin >> guessY;

	if (secondSquid->isSquid(guessX, guessY)) {
		cout << "is a hit!" << endl;
	}
	else {
		cout << "was not a hit :(" << endl;
	}



	rowPos = thirdSquid->getXPos();
	colPos = thirdSquid->getYPos();
	for (int i = 0; i < rowPos.size(); i++) {
		cout << rowPos.at(i) << " ";
		cout << colPos.at(i) << " ";
		cout << endl;
	}

	cout << "guess x is: ";
	cin >> guessX;
	cout << "guessY is: ";
	cin >> guessY;

	if (thirdSquid->isSquid(guessX, guessY)) {
		cout << "is a hit!" << endl;
	}
	else {
		cout << "was not a hit :(" << endl;
	}

	return 0;
}