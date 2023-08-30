#pragma once
class Box {
public:
	
	Box(int ID, char* plantName);
	Box();

	Box(const Box& other);
	Box& operator=(const Box& other);

	int ID;
	char* plant;

	~Box();
};

