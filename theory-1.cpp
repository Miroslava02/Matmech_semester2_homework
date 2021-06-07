#include <iostream>
using namespace std;


struct cArray {
	int* data;
	size_t size;
	cArray(size_t N) {
		size = N;
		data = new int[size];
	}
	~cArray() {
		delete[] data;
	}
	cArray(const cArray& A) {
		if (data) {
			delete[] data;
		}
		size = A.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = A.data[i];
		}
	}
	cArray operator=(const cArray& A) {
		if (data) {
			delete[] data;
		}
		size = A.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = A.data[i];
		}
		return *this;
	}
	int operator[](size_t i) const{
		return data[i % size];
	}
	int& operator[](size_t i){
		return data[i % size];
	}
};

int main() {
	int N;
	cin >> N;
	cArray A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 3 * N; i++) {
		cout << A[i]<<" ";
	}
	system("PAUSE");
	return 0;
}
