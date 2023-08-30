#include "plantermgr.h"
#include "box.h"
#include <iostream>

void PlanterMgr::plant(int boxID, char* plantName) {
	/* Now that you have insert working, update PersonMgr::plant() to print the
        correct message, create a Box object for the plant, and insert the new Box
        into the tree.*/

    std::cout << "Planting " << plantName << " in box " << boxID << "\n";

    Box* b = new Box{ boxID, plantName };
    bt.insert(*b);
}

void PlanterMgr::harvest(char* plantName, int start, int stop) {

}

void PlanterMgr::prune(int boxID) {
    std::cout << "Pruning box number " << boxID << "\n";
    Box b;
    b.ID = boxID;
    bt.remove(b);
}