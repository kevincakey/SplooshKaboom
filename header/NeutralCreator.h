#ifndef NEUTRAL_CREATOR_CLASS
#define NEUTRAL_CREATOR_CLASS

//#include "Tile.h"
#include "TileCreator.h"
#include "Neutral.h"

class NeutralCreator : public TileCreator
{
public:
	Tile* createTile() { return new Neutral(); };
};

#endif