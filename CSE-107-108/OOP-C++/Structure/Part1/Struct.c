#include<stdio.h>
#include<string.h>

/***********Process1*********/

struct st1{
    char name[30];
    char street[40];
    char city[20];
    char state[3];
    unsigned long int zip;
};
/*Now st1 is a type
In C :    struct st1 x ;
In C++ :   x ;*/

/*************Process 2***********/

struct st2 {
    char name[30];
    char street[40];
    char city[20];
    char state[3];
    unsigned long int zip;
} _aa,_bb,_cc;

//Now declares variable in definition ;

/******************Process 3*****************/
struct{
    char name[30];
    char street[40];
    char city[20];
    char state[3];
    unsigned long int zip;
} st3;

//This is for only one structure variable .


/****************Process 4 *************/
typedef struct{
    char myname[120] ;
} St ; 

int main(){

    //*****************Using the first method****************//
    struct st1 student1,student2 ;
    strcpy(student1.name,"Toriqe") ;        strcpy(student1.state,"Bangladesh") ;
    strcpy(student1.street,"Dhanmondi 2") ; strcpy(student1.city,"Dhaka") ;
    printf("info : %s %s %s %s\n" ,student1.name,student1.state,student1.street,student1.city) ;

    strcpy(student2.name,"Tuhine") ;        strcpy(student2.state,"Bangladesh") ;
    strcpy(student2.street,"Dhanmondi 2") ; strcpy(student2.city,"Dhaka") ;
    printf("info : %s %s %s %s\n" ,student2.name,student2.state,student2.street,student2.city) ;

    /*******************Using the second method*********************/

    strcpy(_aa.name,"Lamiya") ;        strcpy(_aa.state,"Bangladesh") ;
    strcpy(_aa.street,"Dhanmondi 2") ; strcpy(_aa.city,"Dhaka") ;
    printf("info : %s %s %s %s\n" ,_aa.name,_aa.state,_aa.street,_aa.city) ;

    /*
    struct st2 dsf ;
    def.zip = 100 ;
    Error because st2 variables are already declared with definition
    */

   /**********************Using the third method******************/

    strcpy(st3.name,"Deep Purple") ;        strcpy(st3.state,"England") ;
    strcpy(st3.street,"123_x") ; strcpy(st3.city,"Cambridge") ;
    printf("info : %s %s %s %s\n" ,st3.name,st3.state,st3.street,st3.city) ;

    /************************Using method 4**********************/

    St stt , sttt;
    strcpy(stt.myname,"Kazi Istiak Uddin Toriqe") ; strcpy(sttt.myname,"Eqirot Niddu Kaitsi") ;
    printf("info : %s\ninfo : %s",stt.myname, sttt.myname) ;
     
    
}
//./Structure/Part1/Struct.exe