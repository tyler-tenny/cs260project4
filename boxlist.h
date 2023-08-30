#pragma once
#include "box.h"

class BoxList {
public:
	struct Node {
		Box data;
		Node* next{};
	};

	BoxList();

	BoxList(const BoxList& other);

	BoxList& operator=(const BoxList& other);

	~BoxList();

	void append(Box& newBox);

	void startIterating();

	const Box& getNextBox();

	bool hasNextBox();

private:
	Node* head;
	Node* tail;
	Node* mCurrent{};

	int size;
};

