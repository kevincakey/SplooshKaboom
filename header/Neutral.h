#ifndef NEUTRAL_CLASS
#define NEUTRAL_CLASS

#include "Squid.h"

class Neutral : public Tile
{
private:
	string secretValue = "o";
	bool hit = false;
public:
	bool checkSquid()
	{
		return false;
	}
	bool isHit()
	{
		return hit;
	}
	string msg()
	{
		if (isHit())
		{
			return secretValue;
		}
		else
		{
			return "~";
		}
	}
	void setHit()
	{
		hit = true;
	}
};

#endif