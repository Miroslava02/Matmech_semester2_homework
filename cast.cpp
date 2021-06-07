#include <iostream>
using namespace std;

int main() {
	const int m = 5;
	int n;
	void* p;
	int* q;
	char a;
	int b;

	class A {
		int a;
		int b;
	public:
		A(int x, int y) {
			a = x;
			b = y;
		}
		virtual void sum() {
			a + b;
		}
	};
	class B {
		unsigned int a;
		unsigned int b;
	public:
		B(unsigned int x, unsigned int y) {
			a = x;
			b = y;
		}
		virtual void sum() {}
	};

	class Bx : B {
	};
	class Ax : A {
		int k;
	};

	n = const_cast<int&>(m);
	cout << n * 2;
	a = '2';
	b = static_cast<int>(a);
	cout << b;

	p = new int[10];
	q = reinterpret_cast<int*>(p);

	A* M;
	B N(7, 8);
	p = dynamic_cast<void*>(M);
	return 0;
}
