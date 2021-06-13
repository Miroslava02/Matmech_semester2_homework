#include <iostream>
using namespace std;

template<class T>
void swap(T* a, int i, int j) {
    T s = a[i];
    a[i] = a[j];
    a[j] = s;
}
template <class T>
void sink(T* a, int k, int n) {  
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && (a[j] < a[j + 1])) {
            j++;
        }
        if (a[k] >= a[j]) break;
        swap(a, k, j);
        k = j;
    }
}

template <class T>
void heapsort(T* a, int size) {
    int n = size;
    for (int k = n / 2; k >= 0; k--)
        sink(a, k, n);
    while (n > 0) {
        swap(a, 0, n--);
        sink(a, 0, n);

    }

}
int main() {

    int*  a = new int[8];
    a[0] = 1;
    a[1] = 3;
    a[2] = 20;
    a[3] = 30;
    a[4] = 17;
    a[5] = 65;
    a[6] = 0;
    a[7] = 4;
    int n = 8;
    heapsort(a, 8);

    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    delete[] a;
    system("PAUSE");
    return 0;
}