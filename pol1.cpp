#include <iostream>
#include <stack>
#include <string>
using namespace std;




int main() {
	stack <int> Stack;
	char a;
    int p;
    int n;
    int m;
	while (a!='=') {
		cin >> a;
        if ((a!='+')&&(a!='-')&&(a!='*')&&(a!='/')){
            p=static_cast<int>(a);
		   Stack.push(p);
           cout<<Stack.top()<<" ";
        }
        else{
           if (a=='+'){
              m = Stack.top();
              Stack.pop();
              n = Stack.top();
              Stack.pop();
              Stack.push(n+m);
           }
           if (a=='-'){
              m = Stack.top();
              Stack.pop();
              n = Stack.top();
              Stack.pop();
              Stack.push(n-m);
           }
           if (a=='*'){
              m = Stack.top();
              Stack.pop();
              n = Stack.top();
              Stack.pop();
              Stack.push(n*m);
           }
           if (a=='/'){
              m = Stack.top();
              Stack.pop();
              n = Stack.top();
              Stack.pop();
              Stack.push(n/m);
           }
        }
	}
	cout<<Stack.top();
    system("PAUSE");
	return 0;
}