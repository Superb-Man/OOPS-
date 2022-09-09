#include<iostream>
#include<cstring>
using namespace std ;
class Teacher{
    char*      name ;
    int        age ;
    double     cgpa ;
    static int count ; 
public:

    
    Teacher(){
        
    }
    
    Teacher(char* name , int age = 0 ,double cgpa = 0){
        this->name = new char[100] ;
        strcpy(this->name,name) ;
        this->age    = age ;
        this->cgpa   = cgpa ;
    }
    void set(char* name, int age,double cgpa){
        if(this->name == NULL){
            this->name = new char[100] ;
        }
        strcpy(this->name,name) ;
        this->age    = age ;
        this->cgpa   = cgpa ;
    }
    Teacher (const Teacher& obj) ;
    void print () ;
    static int __count(){
        return ++count ;
    }

} ;

Teacher:: Teacher(const Teacher& obj){
    strcpy(this->name,name) ;
    cout<<"Copy Clled"<<endl;
    this->age   = age ;
    this->cgpa  = cgpa ;
}

int Teacher::count ;
void Teacher::print(){
    cout<<"Teacher's Name : "<<name<<" ,Age : "<<age<<" CGPA: "<<cgpa<<endl;
}

namespace stdu{
    
    double countCgpa(pair<double,double>p[] , int n) ;

    class Student{
        char*         name ;
        int           age ;
        int           id ;
        double        cgpa ;
        
    public :
    
        Student(){
            
        }
        Student(char* name,int age = 0  ,int id = 0){
            this->name = new char[100] ;
            strcpy(this->name, name) ;
            this->id    = id ;
            this->age   = age ;
            cgpa        = 0.0 ;
        }

        void set(char* name,int age,int id){
           if(this->name == NULL){
                this->name = new char[100] ;
            }
            strcpy(this->name, name) ;
            this->id    = id ;
            this->age   = age ;
            cgpa        = 0.0 ;
        }
        //friend double countCgpa(pair<double,double>p[], int n) ;
        
        char* getName(){
            return name ;
        }
        int getAge(){ return age ;}
        double getCgpa(){ return cgpa ;}
        void setCgpa(pair<double,double>p[] ,int n){
            this->cgpa = countCgpa(p,n) ;
        }
        void print(){
            cout<<"Name : "<<name<<" ,ID : "<<id<<" ,Age : "<<age<<" ,CGPA: "<<cgpa<<endl;
        }
        operator Teacher(){
            return Teacher(this->name,this->age,this->cgpa) ;
        }

    };

    double countCgpa(pair<double,double>p [] , int  n){
        double cgpa = 0 , credits = 0;
        for(int i = 0 ; i< n ;i++){
            cgpa+=(p[i].first*p[i].second) ;
            credits+=p[i].first ;
        }
        return (double) (cgpa*1.0)/credits ;
    }
}

using stdu :: Student ;

int main(){
    int n ;/*How many students?*/ cin>>n ;
    Student *students = new Student[n] ;
    for(int i = 0 ;i<n;i++){
        string s ; int age ,id ;
        cin>> s >> age >> id ;
        char *p;
        p = new char[s.size()+1] ;
        strcpy(p,s.c_str()) ;
        students[i].set(p,age,id) ;
    }
    for(int i = 0 ;i < n; i++){
        int m ; //Subjects 
        cin>> m ;
        pair<double,double> p[m] ;
        for(int j = 0 ;j< m ;j++){
            cin >> p[j].first >> p[j].second ;
        }
        students[i].setCgpa(p,m) ;    
    }
    for(int i = 0 ;i< n ;i++){
        students[i].print() ;
    }
    //Teacher::count++ ;

    Teacher *teachers = new Teacher[n] ;
    for(int i = 0 ;i< n ;i++){
        if(students[i].getCgpa()>3.90){
            teachers[Teacher::__count() -1] =  students[i] ;
        }
    }
    int cnt = Teacher::__count() - 1 ;
    cout<<cnt<<endl;
    for(int i = 0 ;i< cnt ;i++){
        teachers[i].print() ;
    }
    
    delete []students ;  
    delete []teachers ;
    
    return 0 ;
}
