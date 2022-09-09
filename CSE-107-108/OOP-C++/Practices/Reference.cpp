#include<iostream>
using namespace std ;

int *func(int *a)
{
    //return *a;
    int &n=*a;
    return (&n);
}
int &fun(int &a)
{
    //return &a;
    int *n=&a;
    return *n;
}
int main () {
    int x ;
    fun(x) = 10 ;
    int *p=func(&x);
    int &f=fun(x);
    //
    cout<<++(*p)<<" "<<++f<<" "<<"address : "<<p<<" "<<endl;   //11,12,..
    cout<<++x<<endl<<endl<<endl;//13
    cout<<++(*p)<<" "<<++f<<" "<<"address : "<<p<<" "<<endl<<endl<<endl;//14,15,...
    ++p;
    cout<<++(*p)<<" "<<++f<<" "<<"address : "<<p<<" "<<endl;//Garbage,16,...
    //
    const int &a=7;
    int b=16,c=15;
    int *d=&b;
    cout<<a<<" "<<++b<< " "<<*d<<" "<<endl;//7,17,17
}
