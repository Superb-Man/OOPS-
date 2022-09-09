#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *x,char *y)
{
    char temp=*x;
    *x=*y;
    *y=temp;
}
int tot;
void permute(char str[],int l,int r,int *y)
{
    if(!(r-l))
    {
        tot++;
        printf("%s\n", str);
        *y=tot;
    }
    for(int i=l;i<=r;i++)
    {
        swap(&str[l],&str[i]);
        permute(str,l+1,r,y);
        swap(&str[i],&str[l]);
    }
}
int main()
{
    char s[100];
    gets(s);
    permute(s,0,strlen(s)-1,&tot);
    printf("%d", tot);
}
