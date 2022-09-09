/*
count-number-binary-strings-without-consecutive-1s
Sol ->{
    putting 1 at the last position assumming string having length of n-1 doesn't contain consecutive 1 then -> f(n-1)
    putting 10 at the last position assumming n-2 n-1 doesn't contain consecutive 1 then -> f(n-2)
}
*/

#include<stdio.h>
int f(int  n){
    if(n==1) return 2;
    if(n==2) return 3;
    return f(n-1)+f(n-2) ;
}

int main(){
    int n ;
    while(scanf("%d", &n) && n!=0){
        printf("%d", f(n)) ;
    }
}