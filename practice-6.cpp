#include <iostream>
#include <typeinfo>
using namespace std;




   template <typename U, typename T>
   class Pair{
       U first;
       T second;

   public:
      
       Pair(U a, T b) {
           first = a;
           second = b;
       }
       ~Pair() {
           delete& first;
           delete& second;
       }
       Pair(const Pair& A) {
           first = A.first;
           second = A.second;
       }
       Pair operator = (const Pair& A) {
           if (first) {
               delete first;
           }
           first = A.first;
           if (second) {
               delete second;
           }
           second = A.second;
           return *this;
       }
       Pair operator+=( Pair& A) {
           first += A.first;
           second += A.second;
           return *this;
       }
       Pair operator * ( Pair& A) {
           first *= A.first;
           first *= A.second;
           return *this;
       }
       friend ostream& operator << (ostream& A, Pair B){
           return A << B.first << " " << B.second;
       }
       friend istream& operator >> (istream& A,Pair B){
           return A >> B.first >> " " >> B.second;
       }
   };

   int main() {
       Pair <int, float> A(5, 9.0);
       Pair <int, float> B(7, 6.3);
       A +=B;
       cout << A << B;
       return 0;
   }
