#include <iostream>
#include <stack>
#include <string>
using namespace std;


int pol(stack <char> S) {
	if (S.top() == '+') {
		S.pop();
		return (S.top() + pol(S));
	}
	else if (S.top() == '*') {
		S.pop();
		return (S.top() * pol(S));
	}
	else if (S.top() == '-') {
		S.pop();
		return (S.top() - pol(S));
	}
	else  {
		return (S.top() / pol(S));
	}
}

int main() {
	stack <char> Stack;
	char a;
	while (a!='=') {
		cin >> a;
		Stack.push(a);
		cout << a;
	}
	Stack.pop();
	cout << pol(Stack);
    system("PAUSE");
	return 0;
}