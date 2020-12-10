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
void printBoard(vector<vector<Tile*>>);
vector<vector<Tile*>> createBoard(Squid*);
Difficulty* chooseDifficulty();
void showSquid(Squid*);
vector<vector<Tile*>> makeNullBoard();

int main()
{
	srand(time(0));
	int row = 1;
	int guessX = -1;
	int guessY = -1;


	Squid* mainSquid = new Squid();

	Difficulty* difficulty = chooseDifficulty();
	mainSquid->setDifficulty(difficulty);

	mainSquid->createSquid();
	showSquid(mainSquid);
	
	vector<vector<Tile*>> board = createBoard(mainSquid);

	printBoard(board);

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

	printBoard(board);
}
void printBoard(vector<vector<Tile*>> brd) {
	cout << "printing out board" << endl;
	int row = 1;
	cout << "  |1|2|3|4|5|6|7|8|" << endl;
	for (int i = 0; i < 8; i++) {
		cout << row << " |";
		for (int j = 0; j < 8; j++)
		{
			cout << brd.at(i).at(j)->msg() << "|";
		}
		cout << endl;
		row = row + 1;
	}
}

vector<vector<Tile*>> createBoard(Squid* squid)
{
	vector<vector<Tile*>> board = makeNullBoard();
	vector<int> xPos = squid->getXPos();
	vector<int> yPos = squid->getYPos();
	cout << "making board with tiles" << endl;
	//make board of Tiles here

	cout << "starting filling the vector" << endl;
	for (int i = 0; i < 8; i++)
	{
		//cout << "first forloop" << endl;
		for (int j = 0; j < 8;j++)
		{
			//cout << "second forloop" << endl;
			for (int I = 0; I < xPos.size();I++) 
			{
				for (int J = 0; J < yPos.size();J++) 
				{
					if (i == xPos.at(I) && j == yPos.at(J))
					{
						//cout << "squid here" << endl;
						TileCreator* newEnemy = new EnemyCreator();
						Tile* enemyTile = newEnemy->createTile();
						board.at(i).at(j) = enemyTile;
					}
					else
					{
						//cout << "empty here" << endl;
						TileCreator* newNeutral = new NeutralCreator();
						//cout << "tile creator" << endl;
						Tile* neutralTile = newNeutral->createTile();
						//cout << "tile" << endl;
						//cout << "i: " << i << " j: " << j << endl;
						board.at(i).at(j) = neutralTile;//push back puts into pos 9
						//cout << "equals" << endl;
					}
				}
			}
		}
	}
	return board;
}

vector<vector<Tile*>> makeNullBoard()
{
	vector<Tile*> initialFill;
	for (int i = 0; i < 8; i++)
	{
		initialFill.push_back(nullptr);
	}
	cout << "Initial fill size" << initialFill.size() << endl;
	vector<vector<Tile*>> board;
	for (int j = 0; j < 8;j++)
	{
		board.push_back(initialFill);
	}
	cout << "v size" << board.size() << endl;
	return board;
}

Difficulty* chooseDifficulty(){
	while (true) {
		cout << "Please choose your difficulty:" << endl;
		cout << "1 for easy" << endl << "2 for medium" << endl << "3 for hard" << endl << "4 exit game" << endl;
		int hardness;
		cin >> hardness;
		if (hardness == 1) {
			return new Easy();
		}
		else if (hardness == 2) {
			return new Medium();
		}
		/*else if(hardness == 3){
			return new Hard();
		}*/
		else if (hardness == 4) {
			exit(1);
		}
		else{
			cout << "please select a valid input!" << endl;
		}
	}
} 

void showSquid(Squid* squid)
{
	vector<int> xPos = squid->getXPos();
	vector<int> yPos = squid->getYPos();

	for (int i = 0; i < xPos.size(); i++) {
		cout << xPos.at(i) << " ";
		cout << yPos.at(i) << " ";
		cout << endl;
	}
}

//void fire(Squid* squid)
//{
//
//}