#include <iostream>
using namespace std;
class Temp
{
    int a, b;
public :
    Temp (int n= 0, int m = 0) { a = n; b = m; } //Automatic Inlining
    int get_a () { return a; } //Automatic Inlining
    int get_b () { return b; } //Automatic Inlining
};
int main ()
{
    Temp ob[4][2] = { Temp (1, 2) , Temp (3, 4) ,
                 Temp (5, 6) , Temp (7, 8) ,
                 Temp (9, 10) , Temp (11 , 12) ,
                 Temp (13 , 14) , Temp (15 , 16)
    };
    for (int i=0; i <4; i++){
        cout << ob[i][0]. get_a () << ' ';
        cout << ob[i][0]. get_b () << "\n";
        cout << ob[i][1]. get_a () << ' ';
        cout << ob[i][1]. get_b () << "\n";
    }
    Temp ob2[3] = {1,2,3} ;
    cout<<ob2[0].get_a()<<" "<<ob2[1].get_a()<<" "<<ob2[2].get_a()<<endl;
    
    Temp* ob3 = ob2 ;
    cout<<ob3[0].get_a()+1<<" "<<ob3[1].get_a()+1<<" "<<ob3[2].get_a()+1<<endl;

    Temp* ob4 = new Temp(99) ;//new Temp(1), new Temp(1,2) all valid
    //ob4 = new Temp[3] ;
    cout<<ob4->get_a()<<" "<<ob4->get_b()<<endl;
    Temp a,b,c,d(121,11) ;
    Temp tarray[] = {a,b,c,Temp(),Temp(1,2),Temp(1),69,96,{69,45},d} ;
    for(int i = 0 ;i< 10 ;i++){
        cout<<tarray[i].get_a()<<" "<<tarray[i].get_b()<<endl;
    }
    delete ob4 ;

    return 0;
}
