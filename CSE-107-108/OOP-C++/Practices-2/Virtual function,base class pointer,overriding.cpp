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
        virtual ~ Rect()
        {
            delete w;
            delete l;
        }
        virtual int area()
        {
            return *w * *l;
        }
        virtual Rect& operator++();
        virtual Rect& operator=(const Rect& r);

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
    Rect *R,r(5,6);
    Box B1("BOX MAGA",10,10,9);
    R = &B1;
    ++B1;
    ++(*R);
    cout<<"Box area is "<<R->area()<<endl;
    R = &r;
    cout<<"Rect area is "<<R->area()<<endl;

}



