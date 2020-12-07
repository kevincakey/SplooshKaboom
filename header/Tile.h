#ifndef TILE_CLASS
#define TiLE_CLASS

using namespace std;

class Tile
{
private:
	int status;
public:
	virtual string msg() = 0;
	virtual bool checkSquid() = 0;
	virtual bool isHit() = 0;
};

#endif