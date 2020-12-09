#include <iostream>
#include "TileCreator.h"
#include "EnemyCreator.h"
#include "NeutralCreator.h"
#include "FogCreator.h"
#include "Squid.h"

using namespace std;

void ClientCode(TileCreator& t)
{
	//cout << "Client: " << t.operation() << endl;
	cout << "Client: ";// << t.createTile() << endl;
	Squid* s = new Squid(1, 1, 9, 9);
	s->createSquid();
	Tile* tile = t.createTile(3, 3, s);
	cout << "Created with " << tile->msg() << endl;
}

int main()
{
	Squid* s = new Squid(1, 1, 9, 9);
	TileCreator * e = new EnemyCreator(3, 3, s);
	ClientCode(*e);
	TileCreator* n = new NeutralCreator(3, 3, s);
	ClientCode(*n);
	TileCreator* f = new FogCreator(3, 3, s);
	ClientCode(*f);

	delete e;
	delete n;
	delete f;

	return 0;
}