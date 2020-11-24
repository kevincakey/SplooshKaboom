#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include "Squid.h"
#include <iostream>
using namespace std;

class Squid;

class Difficulty {
public:
	Difficulty() { };
	virtual void makeSquids(Squid*) = 0;
};
#endif
