#include <iostream>
using namespace std;

class Complex {
	int Re;
	int Im;
public:
	Complex(int a, int b){
		Re = a;
		Im = b;  
	}
	~Complex() {
		delete& Re;
		delete& Im;
	}
	Complex(const Complex& Q) {
        
		Re = Q.Re;
		Im = Q.Im;
	}
	Complex operator = (const Complex& Q) {
		if (Re) {
			delete& Re;
		}
		if (Im) {
			delete& Im;
		}
		Re = Q.Re;
		Im = Q.Im;
		return *this;
	}
	friend Complex operator + (const Complex& Q1, const Complex& Q2) {
		Complex A(Q1.Re + Q2.Re, Q1.Im + Q2.Im);
		return A;
	}
	friend Complex operator * (const Complex& Q1, const Complex& Q2) {
		Complex A(Q1.Re * Q2.Re - Q1.Im * Q2.Im, Q1.Re * Q2.Im + Q1.Im * Q2.Re);
		return A;
	}
	friend ostream& operator << (ostream& A, Complex B) {
		return A << B.Re << "+" << B.Im << "i";
	}
	friend istream& operator >> (istream& A, Complex B) {
		return A >> B.Re >> B.Im;
	}
};

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Complex  A(a, b);
	Complex B(c, d);
	Complex C = A;
	cout << C;
    cout << a;
	cout << B;
	cout << A + B;
	cout << B * C;
	system("PAUSE");
	return 0;
}