#include<iostream>
#include<typeinfo>
using namespace std ;

class Villain ; //Forward Declaration 

class Hero {
    int energy ;
public:
    Hero(int energy){
        this->energy = energy ;
    }

    friend void WhoGetsTheSword(Hero h, Villain v ) ;

    void WhoGetsMorePunch (Villain v) ;

};

class Villain{
    int energy ;
public:
    Villain(int energy){
        this-> energy = energy ;
    }

    friend void WhoGetsTheSword(Hero h, Villain v ) ;

    friend void Hero::WhoGetsMorePunch(Villain v) ;
};

void Hero::WhoGetsMorePunch(Villain v){
    if(energy > v.energy){
        cout << typeid(Hero).name() <<" Beats "<<typeid(Villain).name()<<endl;
    }
    else if(energy == v.energy) {
        cout<<"They marry each other"<<endl;
    }
    else {
        cout << typeid(Villain).name() <<" Beats "<<typeid(Hero).name()<<endl;
    }
}
int main(){
    Hero hero(45) ;
    Villain vill(90) ;
    hero.WhoGetsMorePunch(vill) ;
    WhoGetsTheSword(hero,vill) ;
}
void WhoGetsTheSword(Hero h, Villain v){
    if(h.energy > v.energy){
        cout << typeid(Hero).name() <<" gets The Sword "<<endl;
    }
    else if(h.energy == v.energy) {
        cout<<"They marry each other"<<endl;
    }
    else {
        cout << typeid(Villain).name() <<" gets The Sword "<<endl;
    }
}