#include <iostream>
using namespace std;

int main(void) {
    while(1)
    {
        int a[3];
        for(int i=0; i<3; i++)
        {
            scanf("%d",&a[i]);
        }
        if(a[0] == 0 && a[1] == 0 && a[2] == 0)
            break;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<2; j++)
            {
                if(a[j] > a[j+1])
                {
                    int tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tmp;
                    
                }
            }
        }
        if(a[2]*a[2] == a[1]*a[1] + a[0]*a[0])
            printf("right\n");
        else
            printf("wrong\n");
            
    }
}
