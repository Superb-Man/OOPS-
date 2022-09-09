#include<iostream>
using namespace std ;

class Outer {
  int x;
//public:
  class Inner{ };

  class Inner2 {

    // The compiler cannot allow the following
    // declaration because Outer::Inner is private:
    Inner _inner;

    int y;
    void f(Outer* _outer, int i) {

    // The compiler cannot allow the following
    // statement because Outer::x is private:
    //   _outer->x = i;

    }
  };
  void g(Inner2* _inner2) {

    // The compiler cannot allow the following
    // statement because Inner2::y is private:
    //   int z = _inner2->y;
  }
};
  



class Outeranother {
    int _outervariable  ;
/*
   class Inner { };
   Inner _inner;

   class Inner2 : public Inner { //    Inherits 
   private:
      Inner _inner;
//      Outeranother::Inner _inner; //  private 
      Innner2 _inner2;
//      Outeranother::Inner2 _inner2; // private
   };
*/
public:

    Outeranother(int _outervariable = 1){
        this-> _outervariable = _outervariable ;
    }

   class Inner {
    protected:
      int _innervariable ;
    public:
      Inner(int _innervariable = 11){
          this->_innervariable = _innervariable ;
      }
      void add(Outeranother& outer){ 
        /*
        *Inner Class can not access non static outerClass variables
        */
        _innervariable += outer._outervariable ;
      }

      int get(){
          return _innervariable ;
      }
   };


   Inner _inner;

   class Inner2 : public Inner { //    Inherits 
   private:
//      Inner _inner;
      Outeranother::Inner _inner;

    public:
      Inner2(Inner _inner, int _innervariable = 111) : Inner(_innervariable){
          this->_inner = _inner ;
      }
   };
   
   int get(){
       return _outervariable ;
   }
};

int main() { 
//    Outer::Inner2 obj ;
    Outeranother obj2 ;
    Outeranother::Inner obj3 ;
    Outeranother::Inner2 obj4(obj3,122) ;
    cout<<obj2.get()<<" "<<obj3.get()<<" "<<obj4.get()<<endl;
    obj3.add(obj2) ;
    obj4.add(obj2) ;
    cout<<obj2.get()<<" "<<obj3.get()<<" "<<obj4.get()<<endl;
    Outeranother objX(100) ;
    
    obj3.add(objX) ;
    obj4.add(objX) ;
    cout<<objX.get()<<" "<<obj3.get()<<" "<<obj4.get()<<endl;
    cout<<"ALL WORKS WELL" ;
}
/*
*1 11 122
*1 12 123
*100 112 223
*ALL WORKS WELL
*/