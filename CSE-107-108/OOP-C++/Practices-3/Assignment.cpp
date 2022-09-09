// Online C++ compiler to run C++ program online
#include <iostream>

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
    
    int c ;
    C(int c= 0){
        this->c = c ;
    }
    const C& operator=(const C &c){
        this->c = c.c ;
        
        return *this ;
    }
    
    const C& operator-=(const C& c){
        this->c-=c.c ;
        
        return *this ;
    }
};

int main(){
    A aa(1),aaa,a4(4) ;
    (aa=aaa)=a4 ;//Not working 
    cout<<aa.a<<" "<<aaa.a<<" "<<a4.a<<endl; //0 0 4
    (aa+=aaa) += a4 ; //Not working
    cout<<aa.a<<" "<<aaa.a<<" "<<a4.a<<endl; //0 0 4
    (aa=(aaa=aa)+=aaa)+=a4 ;//Not working
    cout<<aa.a<<" "<<aaa.a<<" "<<a4.a<<endl<<endl;//0 0 4
    
    
    B bb(2),bbb,b4(5) ;
    (bb=bbb)=b4 ;//working
    cout<<bb.b<<" "<<bbb.b<<" "<<b4.b<<endl; //5 0 5
    (bb+=bbb) += b4 ;//Working
    cout<<bb.b<<" "<<bbb.b<<" "<<b4.b<<endl;//10 0 5
    (bb=(bbb=bb)+=bbb)+=b4 ;//working 
    cout<<bb.b<<" "<<bbb.b<<" "<<b4.b<<endl<<endl;//25 20 5
    
    
    C cc(3),ccc,c4(6) ;
    cc=c4;
    cout<<cc.c<<" "<<ccc.c<<" "<<c4.c<<endl ;
    cc-=ccc ;
    ++cc.c ;
    cout<<cc.c<<" "<<ccc.c<<" "<<c4.c<<endl<<endl;
}