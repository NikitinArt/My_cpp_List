#pragma once
class MyList
{
private:
	struct Node {
		int value;
		Node* pnext;
		Node* pprevious;

		Node(const int value);
	};

	Node* first = nullptr;

	Node* last = nullptr;

public:

	void push_back(const int value);

	void push_up(const int value);

	void show();

	void remove(const int value);

	Node* find(const int value);
};

