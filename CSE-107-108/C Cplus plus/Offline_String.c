//In this problem, you will be given three strings s1, s2, s3. You need to replace all the occurrence of string s2 in string s1 with s3. Finally you need to output the string s1 (modified new string). You cannot use any other character arrays except the arrays used for taking inputs. • Maximum initial length of s1 will be 100 • Minimum length of s2 will be 2 • Maximum length of s3 will be 10
#include<stdio.h>
#include<string.h>
char s1[501],s2[101],s3[11];
int main()
{
    int i,j=0,k,l,x,y,z,change=1,diff;
    gets(s1);
    gets(s2);
    gets(s3);
    x=strlen(s1);
    y=strlen(s2);
    z=strlen(s3);
    for(i=0;i<x;i++)
    {
        change=1;
        if(s2[0]!=s1[i]) change=0;
        if(s2[0]==s1[i])
        {
            j=i;
            for(k=0;k<y;k++)
            {
                if(s2[k]!=s1[j])
                {
                    change=0;
                    break;
                }
                j++;
            }
        }
        if(change==1)
        {
            x+=z-y;
            diff=z-y;
            if(z>y){
                for(k=x-1;k>=i+z;k--)
                {
                    s1[k]=s1[k-diff];
                }
            }
            else if(z<y)
            {
                for(k=i+z;k<x;k++)
                {
                    s1[k]=s1[k-diff];
                }
            }
            j=i;
            for(k=0;k<z;k++)
            {
                s1[j]=s3[k];
                j++;
            }
            i=j;
        }
    }
    s1[x]='\0';
    printf("%s",s1);

}
