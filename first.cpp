#include <iostream>
using namespace std;



class AoA {
public:
	size_t m;
	int** A;
	int* data;
public:
	AoA(int* Array_k, size_t m) : m(m), A(new int* [m]) {
		size_t size = 0;
		for (int i = 0; i < m; i++) {
			size += Array_k[i];
		}
		data = new int[size];
		int temp = 0;
		for (int i = 0; i < m; i++) {
			A[i] = data + temp;
			temp += Array_k[i];
		}
	}
	int get(size_t i, size_t j) {
		if (i >= m) throw "Out of m";
		if (j >= (size_t)(A[i] - A[i + 1])) throw "Out of k[i]";
		return A[i][j];
	}
};



int main() {
	int* B = new int[5];
	B[0] = 5;
	B[1] = 8;
	B[2] = 1;
	B[3] = 7;
	B[4] = 3;
	AoA mat(B, 5);
	for (int i = 0; i < mat.m; i++) {
		for (int j = 0; j < B[i]; j++) {
			mat.A[i][j] = i * i + j * j;
		}
	}
	cout << mat.A[1][7];
	return 0;
}
