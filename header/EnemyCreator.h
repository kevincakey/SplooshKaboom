#ifndef ENEMY_CREATOR_CLASS
#define ENEMY_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Enemy.h"

class EnemyCreator : public TileCreator
{
public:
	Tile* createTile(int x, int y, Squid* s) { return new Enemy(x, y, s); };
};

#endif