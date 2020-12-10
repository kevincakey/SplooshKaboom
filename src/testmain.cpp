#include <iostream>
#include "../header/TileCreator.h"
#include "../header/EnemyCreator.h"
#include "../header/NeutralCreator.h"
#include "Squid.cpp"

using namespace std;

void ClientCode(TileCreator& t)
{
	//cout << "Client: " << t.operation() << endl;
	Tile* tile = t.createTile();
	cout << "message: " << tile->msg() << endl;
	if (tile->checkSquid())
	{
		cout << "is a squid" << endl;
	}
	else
	{
	cout << "isnt a squid" << endl;
	}

	if (tile->isHit())
	{
		cout << "is hit" << endl;
	}
	else
	{
		cout << "isnt hit" << endl;
	}
	tile->setHit();
	cout << "hit tile" << endl;
	if (tile->isHit())
	{
		cout << "is hit" << endl;
	}
	else
	{
		cout << "isnt hit" << endl;
	}
	cout << "message: " << tile->msg() << endl;
}

int main()
{
	TileCreator* e = new EnemyCreator();
	ClientCode(*e);
	TileCreator* n = new NeutralCreator();
	ClientCode(*n);

	delete e;
	delete n;

	return 0;
}