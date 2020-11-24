#ifndef ENEMY_CLASS
#define ENEMY_CLASS

//#include "Tile.h"

class Enemy : public Tile
{
private:
	int status;
public:
	string msg() { return "Enemy Tile"; };
};

#endif