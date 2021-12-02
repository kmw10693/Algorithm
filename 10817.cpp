#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a, &b, &c);
    if(a>b)
    {
        if(a>c)
        {
            if(b>c)
                printf("%d", b);
            else
                printf("%d", c);
        }
        else
            printf("%d", a);
    }
    else // a<b b<c
    {
        if(b>c)
        {
            if(c>a)
                printf("%d", c);
            else
                printf("%d", a);
        }
        else
            printf("%d", b);    
    }
       
}
