
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int sum(int a, int b){
    return a+b;
}


int main(){
    cout<<"hello world";
    int a, b, a1, b1;
    int line;
    vector <int> A, B;
    ifstream in("C:\\Users\\Мирослава\\OneDrive\\Документы\\input.txt");
    if (in.is_open())
    {
        cout<<"hello world";
        while (in>>a>>b)
        {
           A.push_back(a);
           cout<<a;
           B.push_back(b);
           cout<<b;
           
        }
    }
    in.close(); 
    for (int i=0; i<3; i++){
        cout<<sum(A[i], B[i]);
    }
    system("PAUSE");  
    return 0;
}
