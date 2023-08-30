#include "plantermgr.h"
#include "box.h"
#include "boxlist.h"
#include <iostream>

void PlanterMgr::plant(int boxID, char* plantName) {
	/* Now that you have insert working, update PersonMgr::plant() to print the
        correct message, create a Box object for the plant, and insert the new Box
        into the tree.*/

    std::cout << "Planting " << plantName << " in box " << boxID << "\n";

    Box* b = new Box{ boxID, plantName };
    bt.insert(*b);
    delete b;
    b = nullptr;
}

void PlanterMgr::harvest(char* plantName, int start, int stop) {
    BoxList bl;
    std::cout << "Harvesting " << plantName << " plants from boxes " << start << " to " << stop << ".\n";
    bl = bt.getRange(start, stop);
    std::cout << "The following boxes will be harvested: ";
    bl.startIterating();
    while (bl.hasNextBox()) {
        const Box& box = bl.getNextBox();
        if (strcmp(box.plant, plantName) == 0) {
            std::cout << box.ID << " ";
        }
    }
    std::cout << "\n";
}

void PlanterMgr::prune(int boxID) {
    std::cout << "Pruning box number " << boxID << "\n";
    Box b;
    b.ID = boxID;
    bt.remove(b);
}