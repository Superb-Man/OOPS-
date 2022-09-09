#include <iostream>
#include<cstring>

using namespace std ;
class A{
    public:
    
    int a ;
    A(int a = 0){
        this->a = a ;
    }
    A operator=(const A &a){
        this->a = a.a ;
        
        return *this ;
    }
    A operator+=(const A& a){
        this->a+= a.a ;
        
        return *this ;
    }
};
class B{
    public:
    
    int b ;
    B(int b = 0){
        this->b = b ;
    }
    B& operator=(const B &b){
        this->b = b.b ;
        
        return *this ;
    }
    B& operator+=(const B& b){
        this->b+= b.b ;
        
        return *this ;
    }
};
class C{
    public:
    
    char *c ;
    C(){
        this->c = new char[100] ;
    }
    C(char *c){
        this->c = new char[100] ;
        strcpy(this->c,c) ;
    }
    ~ C ()
    {
        delete [] c;
    }
    const C& operator=(const C &c){
        strcpy(this->c,c.c) ;
        
        return *this ;
    }
    
    const C& operator^=(const C& c){ 
        char *p = new char[100];
        char *q = c.c ;
        int i = 0; 
        while( *this->c){
            if((*this->c != *q) && *q){
                *(p+i) = *q ;
                i++ ;
            }
            else if(*q=='\0'){
                *(p+i)=*this->c;
                i++ ;
            }
            
            this->c++ ;
            if(*q!='\0') q++ ;
        }
        *(p+i) = '\0' ;
        this->c = new char[100] ;
        strcpy(this->c,p) ;
        delete [] p ;
        
        return *this ;
    }
};

int main(){
    A aa(1),aaa,a4(4) ;
    aa=aaa ;
    cout<<&aa<<" "<<&aaa<<" "<<&a4<<"HEHE"<<endl ;//address not same.Working like copy as we overloaded assignment operator
    (aa=aaa)=a4 ;//Not working 
    cout<<aa.a<<" "<<aaa.a<<" "<<a4.a<<endl; //0 0 4
    (aa+=aaa) += a4 ; //Not working
    cout<<aa.a<<" "<<aaa.a<<" "<<a4.a<<endl; //0 0 4
    (aa=(aaa=aa)+=aaa)+=a4 ;//Not working
    cout<<aa.a<<" "<<aaa.a<<" "<<a4.a<<endl;//0 0 4
    cout<<&aa<<" "<<&aaa<<" "<<&a4<<"  HEHE"<<endl<<endl ;
    
    
    B bb(2),bbb,b4(5) ;
    bb=bbb ;
    cout<<&bb<<" "<<&bbb<<" "<<&b4<<"  HEHE"<<endl ;//address not same.Working like copy as we overloaded assignment operator
    (bb=bbb)=b4 ;//working
    cout<<bb.b<<" "<<bbb.b<<" "<<b4.b<<endl; //5 0 5
    (bb+=bbb) += b4 ;//Working
    cout<<bb.b<<" "<<bbb.b<<" "<<b4.b<<endl;//10 0 5
    (bb=(bbb=bb)+=bbb)+=b4 ;//working 
    cout<<bb.b<<" "<<bbb.b<<" "<<b4.b<<endl<<endl;//25 20 5
    
    
    C cc("helloWorld"),ccc("hello"),c4("helloWorld_DIE_S") ;
    cc=c4;
    cout<<&cc<<" "<<&ccc<<" "<<&c4<<"    HEHE"<<endl ;//address not same.Working like copy as we overloaded assignment operator
    cout<<cc.c<<" "<<ccc.c<<" "<<c4.c<<endl ;
    cc^=ccc ;
    cout<<cc.c<<" "<<ccc.c<<" "<<c4.c<<endl<<endl;
}