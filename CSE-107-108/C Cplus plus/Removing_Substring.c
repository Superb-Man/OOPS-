#include<stdio.h>
#include<string.h>
void newstr(char *p,char *q)
{
    int change,i=0,j=0;
    char *y;
    char *x=p;
    while(*x)
    {
        y=q;
        change=0;
        if(*x==*y)
        {
            change=1;
            while(*y)
            {
                if(*x!=*y)
                {
                    change=0;
                    break;
                }
                else
                {
                    x++;
                    y++;
                }

            }
        }
        if(change==1)
        {
            int a=y-q;
            int l=i;
            x=p+l;
            while(*(p+a+l))
            {
                *(p+l)=*(p+l+a);
                l++;
            }
            *(p+l)='\0';
        }
        else
        {
            int a=y-q;
            x=x-a+1;
            i++;
        }
    }
    *(p+i)='\0';

}
int main()
{
    char str[100],s[10];
    gets(str);
    gets(s);
    newstr(str,s);
    printf("%s", str);

}
