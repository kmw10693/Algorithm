#include <iostream>

int main(void) {
    int a[4] = {0,};
    for(int i=0; i<4; i++)
    {
        scanf("%d",&a[i]);
    }
    a[2] = a[2]-a[0];
    a[3] = a[3]-a[1];
    int tmp=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[j] > a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                
            }
        }
    }
    printf("%d", a[0]);

    
}
