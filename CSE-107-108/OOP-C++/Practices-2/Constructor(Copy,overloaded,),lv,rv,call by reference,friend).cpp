#include<iostream>
using namespace std;
class Rectangle;
class Square;
class Rectangle {
	int *width, *height;
public:
    Rectangle()
    {
        cout<<"Main Rect"<<endl;
    }
    Rectangle(const Rectangle &rect);

    Rectangle(int, int);

    ~Rectangle();
    int area () {return (*width * *height);}
    void sett(int width,int height)
    {
	  this->width=new int;
	  this->height=new int;
	  *this->width=width;
	  *this->height=height;
    }
    int area_compare(Square sq);

};
class Square{
    int length;
    public:
        Square()
        {
            cout<<"Main Sq called"<<endl;
        }
        Square(int);
        ~Square()
        {
            cout<<"Destroy sq"<<endl;
        }
        int area() {return length*length;}
        void sett(int length)
        {
            this->length=length;
        }
        Square(const Square &sq);
        friend int Rectangle::area_compare(Square sq);

};
int *func(int *a)
{
    //return *a;
    int &n=*a;
    return (&n);
}
int &fun(int &a)
{
    //return &a;
    int *n=&a;
    return *n;
}

Rectangle::Rectangle (int width, int height) {
    cout<<"Overloaded Rect"<<endl;
    this->width= new int;
    this->height = new int;
    *this->width=width;
    *this->height=height;
}
Rectangle:: ~Rectangle () {
    delete width;
    delete height;
    cout<<"Destroy Rect"<<endl;
}
Rectangle:: Rectangle(const Rectangle &rect)
{
    cout<<"COPY Rect"<<endl;
    //*this=rect;
    this->width=new int;
    this->height=new int;
    *width=*rect.width;
    *height=*rect.height;
}

Square::Square(int length)
{
    cout<<"Overloaded Sq called"<<endl;
    this->length=length;
}
Square::Square(const Square &sq)
{
    cout<<"Sq copy"<<endl;
    length=sq.length;
}
int Rectangle::area_compare(Square sq)
{
    return (area()-sq.area());
}
Rectangle *larger(Rectangle *a, Rectangle *b){ //return by reference: *---&
    if(a->area()>b->area())
    {

        return a;
    }
    else return b;
}

Rectangle *AREA(Rectangle *A)
{
    return A;
}


int main () {
    int x=10;
    int *p=func(&x);
    int &f=fun(x);
    cout<<*p<<" "<<p<<endl;
    cout<<f;
    ++f;
    cout<<" "<<x<<endl<<endl<<endl;
    //const int &x=7;
    //int x=16,y=15;
//    int *p=&x;
//    int &q=x;
//    q=min(x,y);
//    cout<<x<<" "<<y<<endl;


    Rectangle *recta,*rectb;
    recta=new Rectangle(3,4);
    rectb=new Rectangle(5,6);
    Rectangle rectc(7,8);
    Rectangle rectd(9,10);
    Rectangle *rect_larger=larger(recta,rectb);
    //Rectangle recte=larger(recta,rectb);
    Rectangle rectf=rectc;
    rectf.sett(14,20);


    cout << "recta area: " << recta->area() << endl;//if not pointer (->)---->(.)
    cout << "rectb area: " << rectb->area() << endl;//if not pointer (->)---->(.)
    cout << "rectc area: " << rectc.area() << endl;
    cout << "rectd area: " << rectd.area() << endl;
	//cout << "recte area: " << recte.area();
    cout << "rectf area: " << rectf.area() << endl;
    cout << "rect_larger area: " << rect_larger->area() << endl;//if not pointer (->)---->(.)
    cout<<endl<<endl<<endl;
    Square s1(5),s2;
    s2.sett(4);
    Square s3=s2;
    cout<<"s1 area "<<s1.area()<<endl;
    cout<<"s2 area "<<s2.area()<<endl;
    cout<<"s3 area "<<s3.area()<<endl;

    cout<<"difference between recta and s1 "<<recta->area_compare(s1)<<endl;

    delete recta;
    delete rectb;

//
//    Rectangle a(3,5),b(4,6);
//    Rectangle R[2][4]={Rectangle(3,4),Rectangle(4,5),a,b};
//    cout<<R[1][1].area()<<" "<<R[1][2].area()<<endl;

     return 0;
}
