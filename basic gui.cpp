//#include "header/Squid.h"
//
//#include "header/difficulty.h"
//
//#include "header/easy.h"
//
//#include "header/medium.h"
//
//#include <iostream>
//#include <vector>
//#include <time.h>
//#include <cstdlib>
//#include <stdlib.h>
//using namespace std;
//
//int main() {
//	srand(time(0));
//	int row = 1;
//	int guessX = -1;
//	int guessY = -1;
//	cout << "  |1|2|3|4|5|6|7|8|" << endl;
//	for (int i = 0; i < 8; i++) {
//		cout << row << " |~|~|~|~|~|~|~|~|" << endl;
//		row = row + 1;
//	}
//
//	Squid* mainSquid = new Squid();
//
//	Easy* easy = new Easy();
//	mainSquid->setDifficulty(easy);
//
//	mainSquid->createSquid();
//
//	Squid* secondSquid = new Squid();
//	Medium* medium = new Medium();
//	secondSquid->setDifficulty(medium);
//
//	secondSquid->createSquid();
//
//	Squid* thirdSquid = new Squid();
//	thirdSquid->setDifficulty(medium);
//
//	thirdSquid->createSquid();
//
//	vector<int> xPos = mainSquid->getXPos();
//	vector<int> yPos = mainSquid->getYPos();
//
//	for (int i = 0; i < xPos.size(); i++) {
//		cout << xPos.at(i) << " ";
//		cout << yPos.at(i) << " ";
//		cout << endl;
//	}
//	//for (int i = 0; i < 10; i++) {
//		cout << "guess x is: ";
//		cin >> guessX;
//		cout << "guessY is: ";
//		cin >> guessY;
//
//		if (mainSquid->isSquid(guessX, guessY)) {
//			cout << "is a hit!" << endl;
//		}
//		else {
//			cout << "was not a hit :(" << endl;
//		}
//	//}
//
//	xPos = secondSquid->getXPos();
//	yPos = secondSquid->getYPos();
//	for (int i = 0; i < xPos.size(); i++) {
//		cout << xPos.at(i) << " ";
//		cout << yPos.at(i) << " ";
//		cout << endl;
//	}
//	//for (int i = 0; i < 10; i++) {
//		cout << "guess x is: ";
//		cin >> guessX;
//		cout << "guessY is: ";
//		cin >> guessY;
//
//		if (secondSquid->isSquid(guessX, guessY)) {
//			cout << "is a hit!" << endl;
//		}
//		else {
//			cout << "was not a hit :(" << endl;
//		}
//	//}
//
//
//	xPos = thirdSquid->getXPos();
//	yPos = thirdSquid->getYPos();
//	for (int i = 0; i < xPos.size(); i++) {
//		cout << xPos.at(i) << " ";
//		cout << yPos.at(i) << " ";
//		cout << endl;
//	}
//
//	cout << "guess x is: ";
//	cin >> guessX;
//	cout << "guessY is: ";
//	cin >> guessY;
//
//	if (thirdSquid->isSquid(guessX, guessY)) {
//		cout << "is a hit!" << endl;
//	}
//	else {
//		cout << "was not a hit :(" << endl;
//	}
//
//	return 0;
//}