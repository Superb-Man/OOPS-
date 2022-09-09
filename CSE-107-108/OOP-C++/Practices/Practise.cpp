#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class strtype{
    char *p;
    int len ;
public :
    strtype ( char *ptr ){
        len = strlen (ptr );
        p = ( char *) malloc (len +1);
        if (!p){
            cout << " Allocation error \n";
            exit (1) ;
        }
        strcpy (p, ptr );
    }
    ~ strtype (){
        cout << " Freeing p\n";
        free (p);
    }
    void show (){
        cout << p << " - lengthj : " << len ;
        cout << '\n';
    }
};
int main (){
    strtype s1(" This is a test ."), s2("I like C++. ");
    s1. show ();
    s2. show ();
    return 0;
}