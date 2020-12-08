#ifndef NEUTRAL_CREATOR_CLASS
#define NEUTRAL_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Neutral.h"

class NeutralCreator : public TileCreator
{
private:
	int xLoc;
	int yLoc;
	Squid* squid;
public:
	NeutralCreator(int xL, int yL, Squid* sq) { xLoc = xL; yLoc = yL; squid = sq; };
	Tile* createTile() { return new Neutral(xLoc, yLoc, squid); };
};

#endif