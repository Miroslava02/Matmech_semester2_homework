#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node* right;
	Node* left;
};


class search_tree {
	Node* root;
public:
	search_tree(int x) {
		root->data = x;
	}
	void add(int x) {
		Node* new_el;
		new_el->data = x;
		Node* ptr = root;
		int k=0;
		while (k != 1) {
			if (x < ptr->data) {
				if (ptr->left != NULL) {
					ptr=ptr->left;
				}
				else {
					ptr->left = new_el;
					k = 1;
				}
			}
			else {
				if (ptr->right != NULL) {
					ptr = ptr->right;
				}
				else {
					ptr->right = new_el;
				}
			}

		}
	}
	
    void delete_tree(Node * ptr) {
		delete& ptr->data;
		if (ptr->left != NULL) {
			delete_tree(ptr->left);
		}
		if (ptr->right != NULL) {
			delete_tree(ptr->right);
		}
		delete ptr;

	}
	~search_tree() {
		delete_tree(root);
	}
	bool search(int x) {
		Node* ptr = root;
		while (1==1) {
			if (x == ptr->data) {
				return 1;
			}
			else if (x < ptr->data) {
				if (ptr->left != NULL) {
					ptr = ptr->left;
				}
				else {
					return 0;
				}
	
			}
			else {
				if (ptr->right != NULL) {
					ptr = ptr->right;
				}
				else {
					return 0;
				}
				
			}

		}
	}
	void write(Node* ptr) {
		if (ptr->left != NULL) {
			write(ptr->left);
		}
		cout << ptr->data;
		if (ptr->right != NULL) {
			write(ptr->right);
		}
	}
	void write_sorted() {
		write(root);
	}
	void write_raw() {
		vector <Node*> A;
		vector <Node*> temp;
		int p;
		A.push_back(root);
		while (A.size() != 0) {
			p = A.size();
			for (int i = 0; i < p; i++) {
				cout << A[i]->left->data << A[i]->right->data;
				temp.push_back(A[i]->left);
				temp.push_back(A[i]->right);
			}
			A.clear();
			A = temp;
			temp.clear();
		}
		vector <Node*>tmp = A;
		A.swap(tmp);
		vector <Node*> tmp1 = temp;
		temp.swap(tmp1);
	}
};