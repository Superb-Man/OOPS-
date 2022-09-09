#include<iostream>
using namespace std;

class Rect{
    int *w,*h;
    public:
    Rect()
    {
        w=new int ;
        h=new int ;
        cout<<"CALLED MAIN"<<endl;
        *w=0;*h=0;
    }
    Rect(int w,int h)
    {
        cout<<"Overloaded called"<<endl;
        this->w=new int;
        this->h=new int;
        *this->w=w;
        *this->h=h;
    }

    Rect(const Rect& r){
        this->h=new int;
        this->w=new int;
        *this->h=*r.h;
        *this->w=*r.w;
    }

    ~Rect()
    {
        cout<<"Destructor called"<<endl;
        delete w;
        delete h;
    }

    Rect operator+(Rect &r)
    {
        cout<<"+ OPERATOR"<<endl;
        Rect rr;
        *rr.w=*w+*r.w;
        *rr.h=*h+*r.h;
        cout<<"BLAH BLAH"<<endl;
        //cout<<*rr.w<<" "<<*rr.h<<endl;
        //return *this;
        return rr;
    }
    Rect &operator=(const Rect &r)
    {
        cout<<" hahahahahahah"<<endl;
        *w=*r.w;
        *h=*r.h;

        return *this;
    }
    Rect &operator++()
    {
        cout<<"Prefix"<<endl;
        //cout<<*w<<" "<<*h<<endl;
        (*w)++;
        (*h)++;
        //cout<<*w<<" "<<*h<<endl<<endl;
        return *this;
    }
    Rect &operator-()
    {
        *w=-*w;
        *h=-*h;

        return *this;
    }
    Rect operator++(int)
    {
        cout<<"Postfix"<<endl;
        Rect t;
        //cout<<*r.w<<" "<<*r.h<<endl;
        *t.w=(*w)++;
        *t.h=(*h)++;
        //cout<<*t.w<<" "<<*t.h<<endl<<endl;

        return t;
    }
    int operator==(Rect &r)
    {
        cout<<"Chking"<<endl;
        return *w==*r.w && *h==*r.h;
    }
    int area()
    {
        return *w  * *h;
    }

};

int main()
{
    Rect a(5,6),b(5,6);
    Rect c=a+b;
    Rect d;
    d=a.operator+(b);//d=a+b;
    Rect e,f;
    e=d;
    f=++d;
    cout<<f.area()<<endl;
    cout<<d.area()<<endl;
    e=f++;
    -f;

    if(a==b) cout<<"same xd"<<endl;
    else cout<<"NO"<<endl;

    if(a==d) cout<<"same"<<endl;
    else cout<<"NO"<<endl;
    cout<<f.area()<<" "<<d.area()<<" "<<e.area()<<" "<<a.area()<<" "<<c.area()<<endl;

    /*to call implicitly obj+ob,ob*ob,ob++,++ob;
    to call explicitly obj.operator+(ob),obj.operator*(ob),ob.operator++(0),
    ob.operator++();*/
}
