#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
} students[10];

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
    struct st1* student = (struct st1*) malloc( 2*sizeof (struct st1) );
    strcpy((student+0)->name,"Toriqe") ;        strcpy((student+0)->state,"Bangladesh") ;
    strcpy((student+0)->street,"Dhanmondi 2") ; strcpy((student+0)->city,"Dhaka") ;
    printf("info : %s %s %s %s\n" ,(student+0)->name,(student+0)->state,(student+0)->street,(student+0)->city) ;

    strcpy((student+1)->name,"Tuhine") ;        strcpy((student+1)->state,"Bangladesh") ;
    strcpy((student+1)->street,"Dhanmondi 2") ; strcpy((student+1)->city,"Dhaka") ;
    printf("info : %s %s %s %s\n" ,(student+1)->name,(student+1)->state,(student+1)->street,(student+1)->city) ;

    /*******************Using the second method*********************/

    char *ch [] = {"a","b","c","d","e","f","g","h","i","j"} ; int i = 0 ;
    while(++i <= 10){
        strcpy(students[i-1].name,ch[i-1]) ;        strcpy(students[i-1].state,"Bangladesh") ;
        strcpy(students[i-1].street,"Dhanmondi 2") ; strcpy(students[i-1].city,"Dhaka") ;
        printf("info : %s %s %s %s\n" ,students[i-1].name,students[i-1].state,students[i-1].street,students[i-1].city) ;
    }

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

    St* stt = (St*) malloc( 2*sizeof(St) ) ;
    strcpy((stt+0)->myname,"Kazi Istiak Uddin Toriqe") ; strcpy((stt+1)->myname,"Eqirot Niddu Kaitsi") ;
    printf("info : %s\ninfo : %s",(stt+0)->myname, (stt+1)->myname) ;
     


     free(student) ;
     free(stt) ;
    
}
//./Structure/Part1/DynamicAllocation.exe