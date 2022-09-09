#include<iostream>
#include<cstring>
using namespace std ;
class Student{
    char*         name ;
    int           age ;
        
public :

    Student(char* name, int age = 0){
        this->name = new char[strlen(name)+2] ;
        strcpy(this->name, name) ;
        this->age = age ;
    }
    void print(){
        cout<<"Name : "<<name<<" ,Age : "<<age<<endl;
    }
    operator int() { return age ;}
    operator char*(){ return name ; }

};

int main(){
    Student st("Toriqe",20) ;
    Student st2("Kazi", 200) ;
    int i = st2 ;
    char* p = st ; 
    cout<<p<<" "<<i<<endl;

}