#include <iostream>
#include "math.h"
#include <fstream>
using namespace std;



int sum(int** Matrix, int a, int b) {
    if (a >= b) {
        return Matrix[a - 1][b - 1];
    }
    else {
        return Matrix[b - 1][a - 1];
    }
}

int dna(int a, int b, int c, int** Matrix, int N) {
    int d = -1;
    int a1, b1, c1;
    while ((a != b or b != c) and d != pow(N, 3)) {
        a1 = sum(Matrix, sum(Matrix, b, c), a);
        b1 = sum(Matrix, sum(Matrix, a, c), b);
        c1 = sum(Matrix, sum(Matrix, a, b), c);
        a = a1;
        b = b1;
        c = c1;
        d += 1;
    }
    return d;
}

int main()
{
    int N;
    cin >> N;
    int** M = new int* [N];
    for (int i = 0; i < N; i++) {
        M[i] = new int[i + 1];
    }
    ifstream in("C:\\ffff\\Matrix.txt");
    if (in.is_open())
    {
        for (int i = 0; i < N; i++) {
           for (int j = 0; j <= i; j++) {
            in >> M[i][j];
           }
       }
    }
    in.close(); 
    int S = 0;
    int I, J, K;
    I = 1;
    J = 1;
    K = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            for (int k = j; k <= N; k++) {
                cout << i << " " << j << " " << k << " " << dna(i, j, k, M, N)<<endl;
                if (dna(i, j, k, M, N) >= S) {
                    S = dna(i, j, k, M, N);
                    I = i;
                    J = j;
                    K = k;
                }
            }
        }
    }
    cout << S;
    cout << I;
    cout << J;
    cout << K;
    system("PAUSE");
    return 0;
}