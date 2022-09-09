#include<stdio.h>
#include<string.h>
int pallindrome(int n,int temp)
{
    if(n==0) return temp;
    temp=temp*10+(n%10);
    return pallindrome(n/10,temp);
}
int main()
{
    int m;
    scanf("%d", &m);
    if(pallindrome(m,0)==m) printf("YES");
    else printf("NO");
}
