//Given a positive integer n (n<=30), generate all distinct ways to write n as the sum of positive integers using recursion. For example, with n = 4, the options are 4, 3 + 1, 2 + 2, 2 + 1 + 1, and 1 + 1 + 1 + 1. • Each combination of sum will be considered as a distinct way. For example, 2 + 1 + 1, 1+2+1 and 1+1+2 represent the same way. You need to print the combination so that higher number are placed before the lower numbers. • You need to print the outputs in an increasing order of integers that are present in the representation. For example, 3 + 1 should be printed before 2 + 1 + 1 • If two representations have same number of integers, the one with the highest number should be printed before. For example, 3+1 should be printed before 2+2

#include<stdio.h>
#include<stdlib.h>
int ar[30],ind,tot;
void permute(int prev,int n,int *y)
{
    int i,j;
    if(n==0)
    {
        for(i=0;i<ind;i++)
        {
            printf("%d ", ar[i]);
        }
        tot++;
        *y=tot;
        printf("\n");
      return ;
    }
    for(i=n;i>=1;i--)
    {
        if(i>prev) continue;
        ar[ind]=i;
        ind++;
        permute(i,n-i,y);
        ind--;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    permute(n,n,&tot);
    printf("TOTAL WAYS: %d", tot);
}
