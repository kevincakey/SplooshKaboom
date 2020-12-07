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
	string operation(int x, int y, Squid* s)
	{
		Tile* t = this->createTile(x, y, s);
		string result = "Created with " + t->msg();
		return result;
	}
};

#endif