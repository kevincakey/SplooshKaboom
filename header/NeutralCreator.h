#ifndef NEUTRAL_CREATOR_CLASS
#define NEUTRAL_CREATOR_CLASS

#include "Squid.h"
#include "TileCreator.h"
#include "Neutral.h"

class NeutralCreator : public TileCreator
{
public:
	Tile* createTile(int, int, Squid*) { return new Neutral(int, int, Squid*); };
};

#endif