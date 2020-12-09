#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include "Squid.cpp"
#include "../header/difficulty.h"
#include "easy.cpp"
#include "medium.cpp"
#include "../header/TileCreator.h"
#include "../header/EnemyCreator.h"
#include "../header/NeutralCreator.h"

using namespace std;

int main()
{
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

	vector<int> xPos = mainSquid->getXPos();
	vector<int> yPos = mainSquid->getYPos();

	for (int i = 0; i < xPos.size(); i++) {
		cout << xPos.at(i) << " ";
		cout << yPos.at(i) << " ";
		cout << endl;
	}

	//cout << 
	//make board of Tiles here
	vector<vector<Tile*>> v;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8;j++)
		{
			if (i == xPos.at(i) && j == yPos.at(j))
			{
				TileCreator* e = new EnemyCreator();
				Tile* et = e->createTile();
				v.at(i).at(j) = et;
			}
			else
			{
				TileCreator* n = new NeutralCreator();
				Tile* nt = n->createTile();
				v.at(i).at(j) = nt;
			}
		}
	}

	//print board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8;j++)
		{
			v.at(i).at(j);
		}
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
}