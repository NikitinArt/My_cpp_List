#include "MyList.h"
#include <iostream>

MyList::Node::Node(const int value) {
	this->pnext = nullptr;

	this->pprevious = nullptr;

	this->value = value;
}

void MyList::push_back(const int value) {
	Node* new_node = new Node(value);

	if (first == nullptr) {

		first = last = new_node;

		return;
	}

	last->pnext = new_node;

	new_node->pprevious = last;

	last = new_node;

}

void MyList::push_up(const int value) {
	Node* new_node = new Node(value);

	if (first == nullptr) {

		first = last = new_node;

		return;
	}

	first->pprevious = new_node;

	new_node->pnext = first;

	first = new_node;
}

void MyList::show() {
	if (first == nullptr) return;

	Node* iter_node = first;

	while (iter_node != nullptr) {
		std::cout << iter_node->value << "\n";

		iter_node = iter_node->pnext;
	}
}

void MyList::remove(const int value) {
	if (first == nullptr) return;

	if (first->value == value) {
		Node* p = first;

		first = first->pnext;

		first->pprevious = nullptr;

		delete p;
	}
	else if (last->value == value) {
		Node* p = last;

		last = last->pprevious;

		last->pnext = nullptr;

		delete p;
	}
	else {
		Node* p;

		p = this->find(value);

		if (p == nullptr) return;

		Node* pprevious = p->pprevious;
		Node* pnext = p->pnext;

		delete p;

		pnext->pprevious = pprevious;

		pprevious->pnext = pnext;
	}
}

MyList::Node* MyList::find(const int value) {
	Node* p = first;

	while (p && p->value != value) p = p->pnext;

	return (p && p->value == value) ? p : nullptr;
}
