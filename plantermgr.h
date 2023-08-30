#pragma once
#include "boxtree.h"

class PlanterMgr {
public:
	void plant(int boxID, char* plantName);

	void harvest(char* plantName, int start, int stop);

	void prune(int boxID);
private:
	BoxTree bt;
};

