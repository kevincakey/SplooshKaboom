#ifndef FOG_CLASS
#define FOG_CLASS

#include "Squid.h"

class Fog : public Tile
{
private:
	int xLoc;
	int yLoc;
	Squid* squid;
public:
	Fog(int x, int y, Squid* s)
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
		return false;
	}
	string msg() { return "Fog Tile"; };
};

#endif