#ifndef TILE_CREATOR_CLASS
#define TILE_CREATOR_CLASS

#include <iostream>
#include "Tile.h"
#include "Squid.h"

using namespace std;

enum TileType
{
	EnemyTile, NeutralTile, FogTile
};

class TileCreator
{
public:
	virtual Tile* createTile(int x, int y, Squid* s) = 0;
	string operation()
	{
		Tile* t = this->createTile();
		string result = "Created with " + t->msg();
		return result;
	}
};

#endif