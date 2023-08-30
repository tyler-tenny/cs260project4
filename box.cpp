#include "box.h"
#include <cstring>

Box::Box(int ID, char* plantName) : ID { ID } {
	plant = new char[strlen(plantName) + 1];
	strcpy(plant, plantName);
}

Box::Box() : ID { 0 } {
	plant = new char[6];
	strcpy(plant, "empty");
}

Box::Box(const Box& other) : ID{other.ID} {
	plant = new char[strlen(other.plant) + 1];
	strcpy(plant, other.plant);
}

Box& Box::operator=(const Box& other) {
	//check for self assignment
	if (this != &other) {
		ID = other.ID;
		delete[] plant;
		plant = new char[strlen(other.plant) + 1];
		strcpy(plant, other.plant);
	}
	return *this;
}

Box::~Box() {
	ID = 0;
	delete[] plant;
}