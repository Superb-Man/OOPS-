//
// Author: Saifur Rahman
// Last modified: 12 DEC 2020
//

#include <stdio.h>
#include <stdarg.h>

void myPrintf(const char *fmt, ...)
{
    va_list ap;
    const char *p;
    int ival;
    float fval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch(*++p)
        {
            case 'y':
            {
                va_arg(ap, int);
                printf("%d", ival);
                break;
            }
            case 'z':
            {   fval = va_arg(ap, double);
                printf("%lf", fval);
                break;
            }

            default:
            {
                putchar(*p);
                break;
            }
        }
    }

    va_end(ap);
}

int main(int argc, char *argv[])
{
    int x;
    float f;

    while (EOF != scanf("%d%f", &x, &f))
        myPrintf("The input integer is: %y %z\n", x, f);

    return 0;
}
