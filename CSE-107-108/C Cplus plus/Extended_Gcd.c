#include<stdio.h>
int exte_gcd(int a,int b,int *x,int *y)
{
    if(b==0)
    {
        *x=1; 
        *y=0;
        return a;  
    }
    int x1,y1;
    int d=exte_gcd(b,a%b,&x1,&y1);
    *x=y1;                 
    *y=x1-y1*(a/b);
    return d;
}
int main()
{
    int p,q,x,y;
    scanf("%d%d", &p,&q);
    printf("%d\n", exte_gcd(p,q,&x,&y));
    printf("%d %d", x,y);
}
