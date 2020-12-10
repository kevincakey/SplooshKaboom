#ifndef TILE_CLASS
#define TiLE_CLASS

#include "Squid.h"
//#include "visitor.hpp"
using namespace std;

//class Visitor;

class Tile
{
public:
	virtual string msg() = 0;
	virtual bool checkSquid() = 0;
	virtual bool isHit() = 0;
	virtual void setHit() = 0;

	//void accept(Visitor* vis){
	//	//vis->checkHit(this);
	//}
};

#endif