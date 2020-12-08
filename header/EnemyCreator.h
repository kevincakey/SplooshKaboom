#ifndef ENEMY_CREATOR_CLASS
#define ENEMY_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Enemy.h"

class EnemyCreator : public TileCreator
{
private:
	int xLoc;
	int yLoc;
	Squid* squid;
public:
	EnemyCreator(int xL, int yL, Squid* sq) { xLoc = xL; yLoc = yL; squid = sq; };
	Tile* createTile() { return new Enemy(xLoc, yLoc, squid); };
};

#endif