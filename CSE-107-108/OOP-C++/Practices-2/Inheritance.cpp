#include<iostream>
#include<cstring>

using namespace std;

class Rect{
    protected:
        int *l,*w;
    public:
        Rect()
        {
            l=new int;w=new int;
            *l=0;*w=0;
        }
        Rect(int l,int w)
        {
            this->l=new int;this->w=new int;
            *this->l=l;*this->w=w;
        }
        Rect(const Rect& r)
        {
            this->l=new int;
            this->w=new int;
            *this->l=*r.l;
            *this->w=*r.w;
        }
        ~ Rect()
        {
            delete w;
            delete l;
        }
        int area()
        {
            return *w * *l;
        }
        Rect& operator++();
        Rect& operator=(const Rect& r);

};
class Box: public Rect{
    protected:
        int *h,stl;
        char *a;
    public:
        Box()
        {
            a=new char[100];
            strcpy(a,"Default box");
            h=new int;*h=0;
            stl=strlen(a)+1;
        }
        Box(char *x,int l,int w,int h):Rect(l,w)
        {
            stl=strlen(x)+1;
            this->a=new char[stl];
            strcpy(this->a,x);
            this->h=new int;
            *this->h=h;
        }
        Box(const Box& b):Rect(b)
        {
            cout<<"COPY"<<endl;
            this->stl=strlen(b.a)+1;
            this->a=new char[stl];
            strcpy(this->a,b.a);
            this->h=new int;
            *this->h=*b.h;
        }
       ~ Box()
        {
            delete h;
            delete [] a;
        }
        char* getlin(){ return a;}
        void print()
        {
            cout<<"NAME OF THE BOX   "<< getlin()<<endl;
        }
        int volume()
        {
            return area()*(*h);
        }
        Box& operator++();
        Box& operator=(const Box& b);
};

Rect& Rect::operator++()
{
    (*w)++;
    (*l)++;
    return *this;
}

Rect& Rect::operator=(const Rect& r)
{
    *w=*r.w;
    *l=*r.l;

    return *this;
}

Box& Box::operator++()
{
    Rect::operator++();
    (*h)++;

    return *this;
}

Box& Box::operator=(const Box& b)
{
    Rect::operator=(b);
    *h=*b.h;
    cout<<"assign"<<endl;

    return *this;
}

int main()
{
    Rect ra(3,7);
    Rect rb=ra;
    cout<<rb.area()<<" "<<ra.area()<<endl;
    Box B1("RED BOX MAGA",5,7,8),B3;
    Box B2=++B1;
    B3=++B2;
    cout<<B1.area()<<" "<<B1.volume()<<endl;
    B2.print();
    cout<<B2.area()<<" "<<B2.volume()<<endl;
    cout<<B3.area()<<" "<<B3.volume()<<endl;
}



