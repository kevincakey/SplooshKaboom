#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include "Squid.h"
#include "difficulty.h"
#include "easy.h"
#include "medium.h"
#include "TileCreator.h"
#include "EnemyCreator.h"
#include "NeutralCreator.h"
#include "Visitor.h"

using namespace std;

vector<vector<Tile*>> createBoard(Squid*, Visitor*);
Difficulty* chooseDifficulty();
void showSquid(Squid*, Visitor*);
vector<vector<Tile*>> makeNullBoard();
void fire(vector<vector<Tile*>> board, Visitor* visitor);

int main()
{
	srand(time(0));
	Squid* mainSquid = new Squid();
	Visitor* visitor = new Visitor();
	Difficulty* difficulty = chooseDifficulty();
	mainSquid->setDifficulty(difficulty);
	mainSquid->createSquid();
	showSquid(mainSquid, visitor);
	vector<vector<Tile*>> board = createBoard(mainSquid, visitor);

	int numTries = 15;

	while (visitor->squidsLeft() > 0 && numTries > 0)
	{
		cout << numTries << " tries left!" << endl;
		cout << "SQUIDS DETECTED: " << visitor->squidsLeft() << endl;
		fire(board, visitor);
		numTries--;
	}
	if (visitor->squidsLeft() > 0)
	{
		cout << "Squids survived, they took over the Earth!" << endl;
	}
	else
	{
		cout << "Squids are now extinct" << endl;
	}
	return 0;
}

vector<vector<Tile*>> createBoard(Squid* squid, Visitor* visitor)
{
	vector<vector<Tile*>> board = makeNullBoard();
	vector<int> xPos = squid->getXPos();
	vector<int> yPos = squid->getYPos();

	TileCreator* newEnemy = new EnemyCreator();

	for (int i = 0; i < xPos.size(); i++)
	{
		Tile* enemyTile = newEnemy->createTile();
		board.at(xPos.at(i) - 1).at(yPos.at(i) - 1) = enemyTile;
		visitor->countSquids(board.at(xPos.at(i) - 1).at(yPos.at(i) - 1));
	}
	return board;
}

vector<vector<Tile*>> makeNullBoard()
{
	vector<vector<Tile*>> board;
	/*vector<Tile*> initialFill;*/
	for (int i = 0; i < 8; i++)
	{
		vector<Tile*> initialFill;
		for (int j = 0; j < 8; j++)
		{
			TileCreator* newNeutral = new NeutralCreator();
			Tile* neutralTile = newNeutral->createTile();
			initialFill.push_back(neutralTile);
			if (j == 7)
			{
				board.push_back(initialFill);
			}
		}
	}
	return board;
}

Difficulty* chooseDifficulty() {
	return new Easy();
}

void showSquid(Squid* squid, Visitor* visitor)
{
	vector<int> xPos = squid->getXPos();
	vector<int> yPos = squid->getYPos();

	int squids = visitor->squidsLeft();

	cout << "Squids at: \n";

	for (int i = 0; i < xPos.size(); i++) {
		squids = i;
		cout << xPos.at(i) << " ";
		cout << yPos.at(i) << " ";
		cout << endl;
	}
	cout << endl;
	cout << squids + 1 << " Squids Created: " << endl;
	cout << endl;
}

void fire(vector<vector<Tile*>> board, Visitor* visitor)
{
	int guessX = -1;
	int guessY = -1;

	cout << "\nguess x is: ";
	cin >> guessX;
	cout << "guessY is: ";
	cin >> guessY;

	guessX--;
	guessY--;

	while (board.at(guessX).at(guessY)->isHit() == true)
	{
		cout << "Choose Coordinates " << endl;
		cout << "guess x is: ";
		cin >> guessX;
		cout << "guessY is: ";
		cin >> guessY;

		guessX--;
		guessY--;
	}

	if (board.at(guessX).at(guessY)->checkSquid()) {
		cout << "\nTile has a squid" << endl;
	}
	else {
		cout << "\nTile does not have a squid" << endl;
	}
	visitor->checkHit(board.at(guessX).at(guessY));
}