#ifndef MEDIUM_H
#define MEDIUM_H
#include "difficulty.h"

class Medium : public Difficulty {
public:
	Medium() {};
	void makeSquids(Squid* toCreate);
};


#endif
