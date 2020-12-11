#pragma once
#ifndef VISITOR_H
#define VISITOR_H

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
//#include "Tile.h"

using namespace std;

class Visitor {

private:


	int NumSquids;

public:
	Visitor() { NumSquids = 0;}
	void countSquids(Tile* tile){
		if (tile->checkSquid()){
			NumSquids++;
		}
	}
	void hitSquid(){
		NumSquids--;
	}
	void checkHit(Tile* tile){
		if(tile->checkSquid()){
			this->hitSquid();
		}
		tile->setHit();
	}
	int squidsLeft(){
		return NumSquids;
	}
};
#endif // !VISITOR_H
