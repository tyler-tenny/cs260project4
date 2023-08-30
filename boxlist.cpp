#include "boxlist.h"
#include "box.h"

BoxList::BoxList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

BoxList::BoxList(const BoxList& other) {
	head = other.head;
	tail = other.head;
	Node* cur = other.head;

	while (cur) {
		append(cur->data);
		cur = cur->next;
	}
}

BoxList& BoxList::operator=(const BoxList& other) {
	if (this != &other) {
		Node* cur{ head };
		while (cur) {
			Node* temp = cur;
			cur = temp->next;
			delete temp;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;

		cur = other.head;
		while (cur) {
			append(cur->data);
			cur = cur->next;
		}
	}
	return *this;
}

BoxList::~BoxList() {
	if (head) {
		Node* cur{ head };
		while (cur) {
			Node* temp = cur;
			cur = temp->next;
			delete temp;
		}
	}
	head = nullptr;
	tail = nullptr;
	mCurrent = nullptr;
	size = 0;
}

void BoxList::append(Box& newBox) {

	Node* newNode = new Node{ newBox };

	if (!tail) {
		head = newNode;
		tail = newNode;
	}

	else {
		tail->next = newNode;
		tail = newNode;
	}
	++size;
}

void BoxList::startIterating() {
	mCurrent = head;
}

const Box& BoxList::getNextBox() {
	Node* temp = mCurrent;
	mCurrent = mCurrent->next;
	return temp->data;
}

bool BoxList::hasNextBox() {
	bool result{ false };
	if (mCurrent) {
		result = true;
	}
	return result;
}