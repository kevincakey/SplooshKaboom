#include "AlterTile.h"

using namespace std;


AlterTile::AlterTile() {};

AlterTile::AlterTile(vector <int> x, vector <int> y) {
	this->xLoc = x;
	this->yLoc = y;
}

bool AlterTile::checkHit(int x, int y) {
	for (int i = 0; i < this->xLoc.size(); i++) {
		if (this->xLoc.at(i) == x && this->yLoc.at(i) == y) {
			return true;
		}
	}
	return false;
}

void AlterTile::displayChange (int x ,int y, string tile) {
	
	// delete wave '~'
	// print hit 'x'
	// print miss 'o'
	// on board

	if (checkHit(x, y) == true) {
		cout << "hit!\n\n";
		replace(tile.begin(), tile.end(), '~', 'x');

	}
	else if (checkHit(x, y) == false) {
		cout << "miss!\n\n";
		replace(tile.begin(), tile.end(), '~', 'o');
	}
}
	
