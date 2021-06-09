#include <iostream>
using namespace std;

template <class T, int a, int b>
class Matrix {
public:
    int width_m = a;
	int height_n = b;
	T** A;
public:
	Matrix(int m, int n) {
		width_m=m;
		height_n=n;
		A = new T * [width_m];
		for (int i = 0; i < m; i++) {
			A[i] = new T[height_n];
		}
	}
	~Matrix() {
		for (int i = 0; i < width_m; i++) {
			delete[] A[i];
		}
		delete[] A;
		delete A;
		delete& width_m;
		delete& height_n;
	}
	Matrix(Matrix& M) {
		width_m = M.width_m;
		height_n = M.height_n;
		A = new T * [width_m];
		for (int i = 0; i < width_m; i++) {
			A[i] = new T[height_n];
		}
		for (int i = 0; i < width_m; i++) {
			for (int j = 0; j < height_n; j++) {
				if (M.A[i][j]) {
					A[i][j] = M.A[i][j];
				}
			}
		}
	}
	Matrix operator =(Matrix& M) {
		width_m = M.width_m;
		height_n = M.height_n;
		
		A = new T * [width_m];
		
		for (int i = 0; i < width_m; i++) {
			A[i] = new T[height_n];
		}
		
		for (int i = 0; i < width_m; i++) {
			for (int j = 0; j < height_n; j++) {
				if (M.A[i][j]) {
					A[i][j] = M.A[i][j];
				}
			}
		}
		return *this;
	}
	friend Matrix sum (Matrix& M, Matrix& N) {
		if (M.width_m != N.width_m or M.height_n != N.height_n) {
			throw invalid_argument("matrixes are of different size");
		}
		Matrix C(M.width_m, M.height_n);
		for (int i = 0; i < M.width_m; i++) {
			for (int j = 0; j < M.height_n; j++) {
				C.A[i][j] = M.A[i][j] + N.A[i][j];
			}
		}
		return C;
	}
	friend Matrix minus(Matrix& M, Matrix& N) {
		if (M.width_m != N.width_m or M.height_n != N.height_n) {
			throw invalid_argument("matrixes are of different size");
		}
		Matrix C(M.width_m, M.height_n);
		for (int i = 0; i < M.width_m; i++) {
			for (int j = 0; j < M.height_n; j++) {
				C.A[i][j] = M.A[i][j] - N.A[i][j];
			}
		}
		return C;
	}
	friend Matrix compose (Matrix& M, Matrix& N) {
		if (M.width_m != N.height_n) {
			throw invalid_argument("matrixes are impossible to compose");
		}
		Matrix C(M.height_n, N.width_m);
		int x;
		for (int i = 0; i < M.height_n; i++) {
			for (int j; j < N.width_m; j++) {
				for (int k = 0; k < N.height_n; k++) {
					x += (M.A[i][k] * N.A[k][j]);
					C.A[i][j] = x;
				}
			}
		}
		return C;
	}
    friend void operator << (ostream& A, Matrix&M){
           for (int i =0; i<M.width_m; i++){
               for (int j=0; j<M.height_n; j++){
                   cout<<M.A[i][j]<<" ";
               }
           }
       }
    friend void operator >> (ostream& A, Matrix&M){
           for (int i =0; i<M.width_m; i++){
               for (int j=0; j<M.height_n; j++){
                   cin>>M.A[i][j]>>" ";
               }
           }
       }
	
};
template<class T, int a>
void transpose(Matrix<T, a, 1> &M) {
		
	}

template<class T, int a, int b>
void transpose(Matrix<T, a, b> &M) {
		int m1 = M.height_n;
		int n1 = M.width_m;
		T** B = new T * [m1];
		for (int i = 0; i < m1; i++) {
			B[i] = new T[n1];
		}
		for (int i = 0; i < m1; i++) {
			for (int j; j < n1; j++) {
				if (M[j][i]) {
					B[i][j] = M.A[j][i];
				}
			}
		}
		M.width_m = m1;
		M.height_n = n1;
		M.A = B;
		for (int i = 0; i < m1; i++) {
			delete[]B[i];
		}
		delete[]B;
		delete B;
		delete& m1;
		delete& n1;
	}


int main() {

	Matrix<int, 2, 2> S(2, 2);
	Matrix<int, 2, 2> P(2, 2);
	S.A[0][0] = 5;
	S.A[0][1] = 6;
	S.A[1][0] = 2;
	S.A[1][1] = 0;
	P.A[0][0] = 8;
	P.A[0][1] = 1;
	P.A[1][0] = 3;
	P.A[1][1] = 4;
	
	cout << 1;
	cout << S.A[0][0];
	
	cout<<S;
	
	cout << sum(S,P).A[0][1];
    cout<<compose(S, P).A[0][1];
    cout<<S.A[0][1];
	return 0;
}
