#include "boxtree.h"
#include "boxlist.h"

Node::Node(Box b) : data{ b }, left{ nullptr }, right{ nullptr } {}

BoxTree::BoxTree() {
	root = nullptr;
}

void BoxTree::insert(Box& newBox) {
	insert(root, newBox);
}

void BoxTree::insert(Node *& r, Box & newBox) {
	if (!r) {
		r= new Node(newBox);
	}

	else if (r->data.ID == newBox.ID) {
		r->data = newBox;
	}

	else if (r->data.ID > newBox.ID) {
		insert(r->left, newBox);
	}

	else {
		insert(r->right, newBox);
	}
}

void BoxTree::deleteNode(Node*& n) {
	
	Node* temp;

	//leaf state
	if (!n->left && !n->right) {
		delete n;
		n = nullptr;
	}

	//no left child state
	else if (!n->left) {
		temp = n;
		n = n->right;
		temp->right = nullptr;
		delete temp;
	}
	
	//no right child state
	else if (!n->right) {
		temp = n;
		n = n->left;
		temp->left = nullptr;
		delete temp;
	}

	//two children
	else {
		//inorder successor
		Node* prev = nullptr;
		Node* cur = n->right;
		while (cur->left) {
			prev = cur;
			cur = cur->left;
		}
		//copy data at cur to n
		n->data = cur->data;
		//disconnect cur from tree
		if (!prev) {
			n->right = cur->right;
		}
		else {
			prev->left = cur->right;
		}

		cur->right = nullptr;
		delete cur;
	}
}

void BoxTree::remove(Box & removeBox) {
	remove(root, removeBox);
}

void BoxTree::remove(Node*& r, Box & removeBox) {
	if (r) {
		if (removeBox.ID == r->data.ID) {
			deleteNode(r);
		}
		else if (removeBox.ID < r->data.ID) {
			remove(r->left, removeBox);
		}
		else {
			remove(r->right, removeBox);
		}
	}
}

BoxList BoxTree::getRange(const int start, const int stop) {
	BoxList bl;
	createRangeList(bl, start, stop, root);
	return bl;
}

void BoxTree::createRangeList(BoxList& bl, const int& start, const int& stop, Node*& r) {
	//traverse to start of range
	//if ID is less than start, go left. If ID is greater than start, go right.
	//if ID is equal, go to next step.
	if (r) {
		if (r->data.ID < start) {
			createRangeList(bl, start, stop, r->left);
		}
		else if (r->data.ID > start) {
			createRangeList(bl, start, stop, r->right);
		}
		else if (r->data.ID == start) {
			while (r && r->data.ID != stop) {
				bl.append(r->data);
				r = r->right;
			}
		}
	}
}

void BoxTree::removeAll(Node*& r) {
	if (r) {
		removeAll(r->left);
		removeAll(r->right);
		delete r;
		r = nullptr;
	}
}

BoxTree::~BoxTree() {
	if (root) {
		removeAll(root);
	}
	delete root;
	root = nullptr;
}