#include<stdio.h>

int sum(int a,int b){

    return a+b;
}

int sum(int a,int b, int c){

    return a+b+c;
}

/*void sum(int a,int b){

}*/  // Ambiguous

//inline void incr(double n) { n++ ;} //Ambiguous

inline void incr(double& n){ n++ ;}
double sum(double a,double b){
    return double (a+b) ;
}


int main(){

    double d = sum(10.77,345.5) ;
    incr(d) ;

    printf("%.2lf\n", d) ;
    printf("%d\n",sum(2,3));
    printf("%d",sum(2,3,4));


    return 0;
}
