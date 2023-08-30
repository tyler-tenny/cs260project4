#pragma once
#include "box.h"
#include "boxlist.h"

struct Node {
	Node(Box b);
	Box data;
	Node* left;
	Node* right;
};

class BoxTree {
public:
	BoxTree();
	BoxTree(const BoxTree&) = delete;
	BoxTree& operator=(const BoxTree) = delete;

	void insert(Node*& r, Box & newBox);
	void insert(Box& newBox);
	void deleteNode(Node*& n);
	void remove(Box & removeBox);
	void remove(Node*& r, Box& removeBox);
	BoxList getRange(int start, int stop);
	void createRangeList(BoxList& bl, const int& start, const int& stop, Node*& r);
	void removeAll(Node*& r);

	~BoxTree();

private:
	Node* root;
};

