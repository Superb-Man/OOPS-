#include<iostream>
#include<cstring>
#include<typeinfo>

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
        virtual ~ Rect()
        {
            delete w;
            delete l;
        }
        virtual int area()
        {
            return *w * *l;
        }
        Rect& operator++();
        Rect& operator=(const Rect& r);

};
class Box: public Rect{
    protected:
        int *h;
        char *a;
    public:
        Box()
        {
            h=new int;*h=0;
        }
        Box(int l,int w,int h):Rect(l,w)
        {
            this->h=new int;
            *this->h=h;
        }
        Box(const Box& b):Rect(b)
        {
            cout<<"COPY"<<endl;
            this->h=new int;
            *this->h=*b.h;
        }
       ~ Box()
        {
            delete h;
        }
        char* getlin(){ return a;}
        void print()
        {
            cout<<"NAME OF THE BOX   "<< getlin()<<endl;
        }
        int area()
        {
            return (*l * *l)+(*w * *w)+(*h * *h);
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
    Rect ra(5,6),*rb,rc;
    Box ba(10,10,9),*bb,bc;
    rb = &ba;
    cout<<typeid(*rb).name()<<endl;
    //++ba;
    cout<<rb->area()<<endl;
    //++(*rb);
    cout<<"Box area is "<<rb->area()<<endl;
    bb=dynamic_cast<Box*> (&ra);
    cout<<typeid(*bb).name()<<endl;
    cout<<bb->volume()<<endl;

}








