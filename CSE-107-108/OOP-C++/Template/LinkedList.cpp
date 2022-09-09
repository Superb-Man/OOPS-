// A simple generic linked list .
#include<iostream>
using namespace std;

template <class T >
class list {
    T data ;
    list * next ;
public :
    list ( T d);
    void add ( list * node ) { 
        node -> next = this ; next = 0; 
    }
    list * getnext () { return next ; }
    T getdata () { return data ; }
};
template <class T > list < T >:: list ( T data)  {
    this->data = data;
    next = 0;
}
int main ()
{
    list <char> start ('a');
    list <char> *p, * last ;
    int i;
    // build a list
    last = & start ;
    for (i=1; i <26; i++)
    {
        p = new list <char>( 'a' + i);
        p->add(last);
        last = p;
    }
    // follow the list
    p = & start ;
    while (p)
    {
        cout << p-> getdata ();
        p = p-> getnext ();
    }
    
    
    return 0;
}