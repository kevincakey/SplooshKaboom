#ifndef EASY_H
#define EASY_H
#include "difficulty.h"

class Easy : public Difficulty {
public:
	Easy() {};
	void makeSquids(Squid* toCreate);
};
#endif