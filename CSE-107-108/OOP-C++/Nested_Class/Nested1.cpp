#include<iostream>
using namespace std;
class A {
    int a ;
    static int b ; 
public:
    A(int a = 0){
        this-> a = a ;
    }
    class B {
    private:
        int num;
        public:
        void putdata(int n) {
            /*num = n+a ; can't access a*/
            //a = 10 ;
            num = n + b ; 
        }
        void putdata(A& outer){
            num+=outer.a ;
        }
        void getdata() {
            cout<<"The number is "<<num;
        }
    };
};
int A::b = 10 ;
int main() {
   cout<<"Nested classes in C++"<< endl;
   A :: B obj;
   A obj2(100) ;
   obj.putdata(9);
   obj.putdata(obj2) ;
   obj.getdata();
   return 0;
}