#ifndef ENEMY_CREATOR_CLASS
#define ENEMY_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Enemy.h"

class EnemyCreator : public TileCreator
{
public:
	EnemyCreator() {};
	Tile* createTile() { return new Enemy(); };
};

#endif