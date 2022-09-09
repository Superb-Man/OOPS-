#include<stdio.h>
#include<string.h>
void add(char *p,char *q)
{
    while(*p)
    {
        p++;
    }
    while(*q)
    {
        *p=*q;
        q++;
        p++;
    }
    *p='\0';
}
int main()
{
    char str[30],s[30];
    gets(str);
    gets(s);
    add(str,s);
    printf("%s", str);

}
