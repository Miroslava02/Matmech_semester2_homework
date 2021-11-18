#include <iostream>
#include <chrono>
using namespace std;


const int N = 110000;

 void add(int* a, int* b, int* c)
{
	 
	 for (int i = 0; i < N; i++) {
		 c[i] = a[i] + b[i];
	 }

}

 int main() {

	 auto t1 = std::chrono::high_resolution_clock::now();
	 int* a;
	 int* b;
	 int* c;
	 a = new int[N];
	 b = new int[N];
	 c = new int[N];
	 for (int i = 0; i < N; i++) {
		 a[i] = 23;
		 b[i] = 23;
	 }
	 add(a, b, c);
	 //for (int i = 0; i < N; i++) {


		//cout << a[i] << " " << b[i] << " " << c[i] << endl;
		 //}
	 delete[] a;
	 a = NULL;
	 delete[]b;
	 b = NULL;
	 delete[]c;
	 c = NULL;
	 auto t2 = std::chrono::high_resolution_clock::now();
	 auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	 cout << N << endl;
	 std::cout << duration;
	 return 0;
 }