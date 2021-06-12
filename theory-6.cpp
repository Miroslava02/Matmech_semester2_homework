#include <iostream>
#include <vector>
#include <math.h>
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
	int height(Node* ptr) {
		if ((ptr->left != 0) && (ptr->right != 0)) {
			return (1 + max(height(ptr->left), height(ptr->right)));
		}
		else if (ptr->left != 0) {
			return (1 + height(ptr->left));
		}
		else if (ptr->right != 0) {
			return (1 + height(ptr->right));
		}
		else return 1;
	}
	int balance(Node* ptr) {
		return (height(ptr->right) - height(ptr->left));

	}
	void big_left(Node* ptr) {
		Node* P = ptr;
		Node* Q = P->left;
		Node* R = Q->right;
		Q->right = R->left;
		P->left = R->right;
		R->left = Q;
		R->right = P;
		ptr = R;
	}
	void big_right(Node* ptr) {
		Node* P = ptr;
		Node* Q = P->right;
		Node* R = Q->left;
		Q->left = R->right;
		P->right = R->left;
		R->right = Q;
		R->left = P;
		ptr = R;
	}
	void left_m(Node* ptr) {
		Node* P = ptr;
		Node* Q = P->left;
		P->left = Q->right;
		Q->right = P;
		ptr = Q;
	}
	void right_m(Node* ptr) {
		Node* P = ptr;
		Node* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		ptr = Q;
	}
	void add(int x) {
		vector <Node*> A;
		Node* new_el;
		new_el->data = x;
		Node* ptr = root;
		A.push_back(ptr);
		int k=0;
		while (k != 1) {
			if (x < ptr->data) {
				if (ptr->left != NULL) {
					ptr=ptr->left;
					A.push_back(ptr);
				}
				else {
					ptr->left = new_el;
					k = 1;
				}
			}
			else {
				if (ptr->right != NULL) {
					ptr = ptr->right;
					A.push_back(ptr);
				}
				else {
					ptr->right = new_el;
				}
			}

		}
		int i = 0;
		while ((balance(A[i]) == 1 or balance(A[i]) == 0 or balance(A[i]) == -1) && i < A.size()) {
			i++;
		}
		if (abs(balance(A[i])) > 1) {
			if (A[i + 1] == A[i]->left) {
				if (A[i + 2] == A[i + 1]->left) {
					left_m(A[i]);
				}
				else {
					big_left(A[i]);
				}
			}
			else {
				if (A[i + 2] == A[i + 1]->right) {
					right_m(A[i]);
				}
				else {
					big_right(A[i]);
				}
			}
		}
		A.clear();
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
				if (A[i]->left->data) {
					cout << A[i]->left->data
				}
				if (A[i]->right->data) {
					cout << A[i]->right->data;
				}
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