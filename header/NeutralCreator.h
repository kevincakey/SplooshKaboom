#ifndef NEUTRAL_CREATOR_CLASS
#define NEUTRAL_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Neutral.h"

class NeutralCreator : public TileCreator
{
public:
	NeutralCreator() {};
	Tile* createTile() { return new Neutral(); };
};

#endif