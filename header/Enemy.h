#ifndef ENEMY_CLASS
#define ENEMY_CLASS

#include "Squid.h"

class Enemy : public Tile
{
private:
	string secretValue = "x";
	bool hit = false;
public:
	bool checkSquid()
	{
		return true;
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