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
void printBoard(vector<vector<Tile*>>);
vector<vector<Tile*>> createBoard(Squid*, Visitor*);
Difficulty* chooseDifficulty();
void showSquid(Squid*, Visitor*);
void showNumSquids(Squid*, Visitor*);
vector<vector<Tile*>> makeNullBoard();
void fire(vector<vector<Tile*>> board, Visitor* visitor);
void hitAll(vector<vector<Tile*>> board);

int main()
{
	srand(time(0));
	Squid* mainSquid = new Squid();

	Visitor* visitor = new Visitor();

	Difficulty* difficulty = chooseDifficulty();
	mainSquid->setDifficulty(difficulty);

	mainSquid->createSquid();
	//showSquid(mainSquid, visitor);

	vector<vector<Tile*>> board = createBoard(mainSquid, visitor);

	printBoard(board);

	int numTries = 15;

	//start of firing/game
	while (visitor->squidsLeft() > 0 && numTries > 0)
	{
		cout << numTries << " tries left!" << endl;
		cout << "SQUIDS DETECTED: " << visitor->squidsLeft() << endl;
		fire(board, visitor);
		printBoard(board);
		numTries--;
	}

	if (visitor->squidsLeft() > 0)
	{
		cout << "Defeat... T.T" << endl;
		hitAll(board);
	}
	else
	{
		cout << "Victory!!!! POG" << endl;
	}

	return 0;
}
void printBoard(vector<vector<Tile*>> brd) {
	//cout << "printing out board" << endl;
	int row = 1;
	cout << "  |1|2|3|4|5|6|7|8|" << endl;
	for (int i = 0; i < brd.size(); i++) {
		cout << row << " |";
		//cout << "brd.ati.size" << brd.at(i).size() << endl;
		for (int j = 0; j < brd.at(i).size(); j++)
		{
			cout << brd.at(j).at(i)->msg() << "|";
		}
		cout << endl;
		row = row + 1;
	}
}

vector<vector<Tile*>> createBoard(Squid* squid, Visitor* visitor)
{
	vector<vector<Tile*>> board = makeNullBoard();
	vector<int> xPos = squid->getXPos();
	vector<int> yPos = squid->getYPos();
	//cout << "making board with tiles" << endl;
	//make board of Tiles here

	//cout << "starting filling the vector" << endl;

	TileCreator* newEnemy = new EnemyCreator();

	//cout << "xPos.size(): " << xPos.size();
	//cout << "yPos.size(): " << yPos.size();

	for (int i = 0; i < xPos.size(); i++)
	{
		//cout << "i: " << i << endl;
		Tile* enemyTile = newEnemy->createTile();
		//cout << "xPos.at(i): " << xPos.at(i) << endl;
		//cout << "yPos.at(i): " << yPos.at(i) << endl;
		board.at(xPos.at(i) - 1).at(yPos.at(i) - 1) = enemyTile;
		//cout << "past board" << endl;
		visitor->countSquids(board.at(xPos.at(i) - 1).at(yPos.at(i) - 1));
	}
	//cout << "done making enemies" << endl;

	return board;
}

vector<vector<Tile*>> makeNullBoard()
{
	//cout << "Making null Board" << endl;
	vector<vector<Tile*>> board;
	for (int j = 0; j < 8; j++)
	{
		vector<Tile*> initialFill;
		for (int i = 0; i < 8; i++)
		{
			TileCreator* newNeutral = new NeutralCreator();
			Tile* neutralTile = newNeutral->createTile();
			initialFill.push_back(neutralTile);
			//cout << "Initial fill size" << initialFill.size() << endl;
			if (i == 7)
			{
				board.push_back(initialFill);
			}
		}
	}
	//printBoard(board);
	//cout << "v size" << board.size() << endl;
	return board;
}

Difficulty* chooseDifficulty() {
	return new Easy();

	//while (true) {
	//	cout << "Please choose your difficulty:" << endl;
	//	cout << "1 for easy" << endl << "2 for medium" << endl << "3 for hard" << endl << "4 exit game" << endl;
	//	int hardness;
	//	cin >> hardness;
	//	if (hardness == 1) {
	//		return new Easy();
	//	}
	//	else if (hardness == 2) {
	//		return new Medium();
	//	}
	//	/*else if(hardness == 3){
	//		return new Hard();
	//	}*/
	//	else if (hardness == 4) {
	//		exit(1);
	//	}
	//	else {
	//		cout << "please select a valid input!" << endl;
	//	}
	//}
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
	cout << "Squids Detected: " << squids + 1 << endl;
}

void showNumSquids(Squid* squid, Visitor* visitor) {
	vector<int> xPos = squid->getXPos();
	vector<int> yPos = squid->getYPos();
	int squids = visitor->squidsLeft();

	for (int i = 0; i < xPos.size(); i++) {
		squids = i;
	}

	squids = squids - 1;
	cout << "Squids Detected: " << squids + 1 << endl;
}

void fire(vector<vector<Tile*>> board, Visitor* visitor)
{
	int guessX = -1;
	int guessY = -1;

	cout << "guess x is: ";
	cin >> guessX;
	cout << "guessY is: ";
	cin >> guessY;

	guessX--;
	guessY--;

	while (board.at(guessX).at(guessY)->isHit() == true)
	{
		cout << "Please choose a tile that hasn't been selected yet!" << endl;
		cout << "guess x is: ";
		cin >> guessX;
		cout << "guessY is: ";
		cin >> guessY;

		guessX--;
		guessY--;
	}

	if (board.at(guessX).at(guessY)->checkSquid()) {
		cout << "KABOOM! :o" << endl;
	}
	else {
		cout << "sploosh :(" << endl;
	}
	visitor->checkHit(board.at(guessX).at(guessY));
}

void hitAll(vector<vector<Tile*>> board)
{
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.at(i).size(); j++)
		{
			board.at(i).at(j)->setHit();
		}
	}
	printBoard(board);
}