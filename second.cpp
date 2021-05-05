#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next = NULL;
	Node* prev = NULL;
};


class CircleList {
public:
	Node* head;
public:
	CircleList() {
	}
	~CircleList() {
		if (!head) return;
		Node* p = head->next;
		while (p != head) {
			Node* temp = p;
			p = p->next;
			delete temp;
		}
		delete head;
	}

	int get_max() {
		int max = head->data;
		Node* p = head->next;
		while (p != head) {
			if (p->data > max) max = p->data;
			p = p->next;
		}
		return max;
	}
	void push_back(int x) {
		Node* temp = head;
		head->data = x;
		head->next = temp;
		temp->prev = head;
		Node* p = temp->next;
		while ((p->next != temp)&&(p!=NULL)) {
			p = p->next;
		}
		p->next = head;
		head->prev = p;
		delete temp;
	}
};

int main() {
	CircleList L;
	L.push_back(6);
	L.push_back(10);
	L.push_back(7);
	cout << L.get_max();
	return 0;
}
