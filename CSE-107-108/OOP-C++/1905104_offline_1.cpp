#include<iostream>
#include<cmath>
using namespace std;
class Point
{
        // x and y coordinate
        int x, y;
    public:
        //Add necessary constructor(s) to initialize x and y
        //Add your set and get functions for x and y
        Point()
        {

        }
        Point(int a,int b)
        {
            x=a;
            y=b;
        }
        void set_values(int a,int b)
        {
            x=a;
            y=b;
        }
        int get1()
        {
            return x;
        }
        int get2()
        {
            return y;
        }
        /*void get(int *a,int *b)
        {
            *a=x;
            *b=y;
        }*/
        void print()
        {
            cout << "Coordinate: "<< x <<", " <<y <<endl;
        }
};
class Circle
{
        Point p;
        int radius;
    public:
        // Add necessary constructor(s) to initialize p and radius
        // Overload “upload” functions
        Circle(int a,int b,int c)
        {
            radius=c;
            p.set_values(a,b);
        }
        void update(int a,int b)
        {
            int x=p.get1()+a;
            int y=p.get2()+b;
            p.set_values(x,y);
        }
        void update(int a)
        {
            radius+=a;
        }
        void update(int a,int b,int c)
        {
            int x=p.get1()+a;
            int y=p.get2()+b;
            radius+=c;
            p.set_values(x,y);
        }
        void print()
        {
            cout << "Center ";
            p.print();
            cout << "Radius: " << radius << endl;
        }
};
class Line{
        Point p1,p2;
    public:
        Line(int a1,int b1,int a2,int b2)
        {
            p1.set_values(a1,b1);
            p2.set_values(a2,b2);
        }

        void print()
        {
            p1.print();
            p2.print();
        }
        void length()
        {
            int x1,x2,y1,y2;
            cout<<"Length of Line ";
            double x=(p1.get1()-p2.get1())*(p1.get1()-p2.get1());
            double y=(p1.get2()-p2.get2())*(p1.get2()-p2.get2());
            cout<<sqrt(x+y)<<endl;
        }

};
int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    cout << endl << "Point Display" <<endl;
    p.print();
    cout << endl << "Circle Display" <<endl;
    c.print();
    cout << endl;


    //First update
    cout << "First Update" << endl;

    // call “update” function of Circle class to increase the center’s x coordinate by 5 and y coordinate by 5;
    c.update(5,5);

    c.print();
    cout <<endl;

    //Second update
    cout << "Second Update" << endl;


    // call “update” function of Circle class to increase the radius by 6;
    c.update(6);

    c.print();
    cout << endl;

    //Third update
    cout << "Third Update" << endl;

    c.update(2,2,2);
    c.print();

    cout << endl;
    Line l(1,2,3,4);

    l.length();

    return 0;
}
