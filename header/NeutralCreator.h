#ifndef NEUTRAL_CREATOR_CLASS
#define NEUTRAL_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Neutral.h"

class NeutralCreator : public TileCreator
{
public:
	Tile* createTile(int x, int y, Squid* s) { return new Neutral(x, y, s); };
};

#endif