#ifndef NEUTRAL_CLASS
#define NEUTRAL_CLASS

//#include "Tile.h"

class Neutral : public Tile
{
private:
	int status;
public:
	string msg() { return "Neutral Tile"; };
};

#endif