#include<iostream>
using namespace std ;
int f(int a) { return 10*a; }
int f(double a) { return 2.0*a; }
void space( int a ) {
    cout<<"LOLLL " << a << endl;
}
void space( int a, char *c ) {
    cout<<"CSE 107 " << a <<" " << c << endl;
}
bool larger(int a,int b){
    return a>b;
}
bool smaller(int a,int b){ 
    return a<b;
}
bool equal(int a,int b){
    return a == b ;
}
 
int main()
{
    int (*pf1)(double) = f;
    int (&pf2)(int) = f; 
    void (*fp1)(int) = space ; 
    void (&fp2)(int, char*) = space ; 
    bool (*compare[])(int ,int)={smaller,larger,equal};
    cout << pf1(12) <<" "<< pf2(12) << endl; 
    space(11) ;
    space(11,"Function Pointer") ;
    for(int i =0 ;i < 3 ;i++) cout << (compare[i])(1,3) <<endl;
}