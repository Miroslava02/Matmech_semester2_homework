#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int sum(int a, int b){
    return a+b;
}


int main(){
    
    int a, b, a1, b1;
    int line;
    vector <int> A, B;
    ifstream in("C:\\ssss\\input.txt");
    if (in.is_open())
    {
        
        while (in>>a>>b)
        {
           A.push_back(a);
           cout<<a;
           B.push_back(b);
           cout<<b;
           
        }
    }
    in.close(); 
    ofstream out;          
    out.open("C:\\ssss\\output.txt"); 
    if (out.is_open())
    {
        for (int i=0; i<3; i++){
        out<<sum(A[i], B[i])<<endl;
        }
        out<<"hello world";
    }
    
    
    system("PAUSE");  
    return 0;
}
