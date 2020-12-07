#ifndef NEUTRAL_CLASS
#define NEUTRAL_CLASS

#include "Squid.h"

class Neutral : public Tile
{
private:
	int xLoc;
	int yLoc;
	Squid* squid;
public:
	Neutral(int x, int y, Squid* s)
	{
		xLoc = x;
		yLoc = y;
		squid = s;
	}
	bool checkSquid()
	{
		return squid->isSquid(xLoc, yLoc);
	}
	bool isHit()
	{
		return true;
	}
	string msg() { return "Neutral Tile"; };
};

#endif