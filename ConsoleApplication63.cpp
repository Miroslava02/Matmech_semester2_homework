#include <iostream>
#include <chrono>
using namespace std;


const int N = 10000;
const int M = 7;

void add(int* a, int* b, int* c)
{

	for (int i = 0; i < N; i++) {
		c[i] = a[i] + b[i];
	}

}

int main() {

	auto t1 = std::chrono::high_resolution_clock::now();
	int**a;
	int**b;
	int**c;
	a = new int* [M];
	b = new int* [M];
	c = new int* [M];
	for (int i = 0; i < M; i++) {
		a[i] = new int[N];
		b[i] = new int[N];
		c[i] = new int[N];

		for (int j = 0; j < N; j++) {
			a[i][j] = 23;
			b[i][j] = 23;
		}
		add(a[i], b[i], c[i]);
	}
	
	//for (int i = 0; i < N; i++) {


	   //cout << a[i] << " " << b[i] << " " << c[i] << endl;
		//}
	for (int i = 0; i < M; i++) {
		delete[] a[i];
		a[i] = NULL;
		delete[] b[i];
		b[i] = NULL;
		delete[] c[i];
		c[i] = NULL;
	}
	delete[] a;
	a = NULL;
	delete[]b;
	b = NULL;
	delete[]c;
	c = NULL;
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	cout << N << endl << M << endl;
	std::cout << duration;
	return 0;
}