#ifndef TILE_CLASS
#define TiLE_CLASS

#include "Squid.h"

using namespace std;

class Tile
{
public:
	virtual string msg() = 0;
	virtual bool checkSquid() = 0;
	virtual bool isHit() = 0;
	virtual void setHit() = 0;
};

#endif