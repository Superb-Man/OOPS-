#include <iostream>
using namespace std;

int a = 1;
int f(int a) { return a; }
int g(int x = f(a)) { return x; }

int h() {
  a=2;
  {
    int a = 3;
    return g(a);
  }
}
int k(){
    int a = 7 ;
    return g() ;
}

int main() {
  cout << h() << endl;
  cout<< k() <<endl;
}