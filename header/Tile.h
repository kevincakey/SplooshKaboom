#ifndef TILE_CLASS
#define TiLE_CLASS

#include "Squid.h"

using namespace std;

class Tile
{
private:
	int xLoc;
	int yLoc;
	Squid* squid;
public:
	virtual string msg() = 0;
	virtual bool checkSquid() = 0;
	virtual bool isHit() = 0;
};

#endif