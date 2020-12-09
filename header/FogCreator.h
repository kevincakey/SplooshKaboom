#ifndef FOG_CREATOR_CLASS
#define FOG_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Fog.h"

class FogCreator : public TileCreator
{
private:
	int xLoc;
	int yLoc;
	Squid* squid;
public:
	FogCreator(int xL, int yL, Squid* sq) { xLoc = xL; yLoc = yL; squid = sq; };
	Tile* createTile() { return new Fog(xLoc, yLoc, squid); };
};

#endif