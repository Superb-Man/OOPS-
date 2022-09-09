/*
Find a recurrence relation for the number of strictly
increasing sequences of positive integers that have 1
as their first term and n as their last term, where n is
a positive integer. That is, sequences a1, a2, . . . , ak,
where a1 = 1, a[k] = n, and a[j] < a[j+1] for j =
1, 2, . . . , k − 1.


Sol->{
    supoose our string always starts with 1 and now,
    if it ends with n-1 having length n-1, we can just add n at last or
    if it it ends with n-1 having length n , we can just replace n-1 by n;
}
*/
#include<stdio.h>
int f(int  n){
    if(n==1) return 1; //1
    if(n==2) return 1; //1,2
    return 2*f(n-1) ;
}

int main(){
    int n ;
    while(scanf("%d", &n)){
        printf("%d\n", f(n)) ;
    }
}