#ifndef ENEMY_CLASS
#define ENEMY_CLASS

#include "Squid.h"

class Enemy : public Tile
{
private:
	int xLoc;
	int yLoc;
	Squid* squid;
public:
	Enemy(int x, int y, Squid* s)
	{
		xLoc = x;
		yLoc = y;
		squid = s;
	}
	bool checkSquid()
	{
		return squid->isSquid(xLoc, yLoc);
	}
	bool isHit()
	{
		return true;
	}
	string msg() { return "Enemy Tile"; };
};

#endif