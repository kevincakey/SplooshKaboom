#ifndef FOG_CREATOR_CLASS
#define FOG_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Fog.h"

class FogCreator : public TileCreator
{
public:
	Tile* createTile(int x, int y, Squid* s) { return new Fog(x, y, s); };
};

#endif