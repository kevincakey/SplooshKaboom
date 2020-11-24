#ifndef ENEMY_CREATOR_CLASS
#define ENEMY_CREATOR_CLASS

//#include "Tile.h"
#include "TileCreator.h"
#include "Enemy.h"

class EnemyCreator : public TileCreator
{
public:
	Tile* createTile() { return new Enemy(); };
};

#endif