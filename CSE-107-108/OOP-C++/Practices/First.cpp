#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class strtype
{
    char *p;
public :
    strtype ( char *s);
    ~ strtype () { cout<<"DES"<<endl;
    delete [] p;
    }
    char *get () {
        return p;
    }
};
strtype :: strtype ( char *s)
{
    int l=strlen(s);
    this->p=new char[l];
    strcpy(p,s);
    //cout<<p<<endl;
}
void show ( strtype &x)
{
   cout << x.get() << "\n";
}
class haha{
    int *p;
    int size;
    int y;
public:
    haha(int size)
    {
        p=new int[this->size];
    }
    haha (){
        int x=0;
    }
    void set_(int i,int x){
        p[i]=x;
    }

    void set_(int x){
        y=x;
    }
    int &sett(int i){
        return p[i];
    }

    int &sett(){
        return y ;
    }
    int get(int i){
        return p[i];
    }

    int get(){
        return y ;
    }
};

class fac{
    char  *p;
    int length;
public:
    fac(){
        this->length=255;
        this->p=new char[length+1];
        strcpy(this->p,"");
    }
    fac(char *p,int length){
        this->length=length;
        this->p=new char[length+1];
        strcpy(this->p,p);
    }
    char *getlin(){
         return p;
    }
    int getlength(){ 
        return length;
    }
};
int main ()
{
    haha hehe(10);
    hehe.set_(2,10);
    hehe.sett(7)=18;
    hehe.sett() = 18 ;
    for(int i=0;i<10;i++) cout<<hehe.get(i)<<endl;
    cout<<hehe.get() <<endl;
    fac st;
    fac str2("THIS IS NOT YOU", 100);
    cout<<st.getlength()<<endl;
    cout<<str2.getlin()<<" "<<str2.getlength()<<endl;

}
