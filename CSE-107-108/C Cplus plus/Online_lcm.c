#include<stdio.h>
int main()
{
    int lcm,gcd,y,k;
    scanf("%d", &y);
    gcd=y;
    lcm=y;
    printf("LCM of all numbers up to now is %d\n", lcm);
    gcd=lcm;
    while(lcm<=10000)
    {
        //int y;
        scanf("%d", &y);
        int x=y;
        while(gcd%y)
        {
            k=gcd;
            gcd=y;
            y=k%y;
        }
        lcm=(lcm*x)/y;
        printf("LCM of all numbers up to now is %d\n", lcm);
        gcd=lcm;
    }
    return 0;
}
