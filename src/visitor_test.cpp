#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "TileCreator.h"
#include "EnemyCreator.h"
#include "NeutralCreator.h"
#include "Visitor.h"

using namespace std;

void testTilesHit(TileCreator&, Visitor*);
void testTilesNotHit(TileCreator&, Visitor*);

int main()
{
	Visitor* vis = new Visitor();

	TileCreator* enemy = new EnemyCreator();
	TileCreator* neutral = new NeutralCreator();

	testTilesHit(*enemy, vis);
	cout << endl;
	testTilesHit(*neutral, vis);

	cout << endl;

	testTilesNotHit(*enemy, vis);
	cout << endl;
	testTilesNotHit(*neutral, vis);

	delete enemy;
	delete neutral;

	return 0;
}

void testTilesHit(TileCreator& t, Visitor* vis)
{
	Tile* tile = t.createTile();
	vis->countSquids(tile);

	cout << "Squids detected: " << vis->squidsLeft();
	cout << endl;

	cout << "message: " << tile->msg() << endl;
	if (tile->checkSquid())
	{
		cout << "Tile is a squid" << endl;
	}
	else
	{
		cout << "Tile is not a squid" << endl;
	}

	vis->checkHit(tile);
	if (tile->isHit())
	{
		cout << "Tile is hit" << endl;
	}
	else
	{
		cout << "Tile isnt hit" << endl;
	}

	cout << "message: " << tile->msg() << endl;
}

void testTilesNotHit(TileCreator& t, Visitor* vis)
{
	Tile* tile = t.createTile();
	vis->countSquids(tile);

	cout << "Squids detected: " << vis->squidsLeft();
	cout << endl;

	cout << "message: " << tile->msg() << endl;
	if (tile->checkSquid())
	{
		cout << "Tile is a squid" << endl;
	}
	else
	{
		cout << "Tile is not a squid" << endl;
	}

	//vis->checkHit(tile);
	if (tile->isHit())
	{
		cout << "Tile is hit" << endl;
	}
	else
	{
		cout << "Tile isnt hit" << endl;
	}

	cout << "message: " << tile->msg() << endl;
}
