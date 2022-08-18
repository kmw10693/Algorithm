#include <iostream>
using namespace std;

int main() {
    int k;
    int sum =0;
    cin >> k;
    int array[k];
    for(int i=0; i<k; i++)
    {
        cin >> array[i];
        int *tmp = (int*)malloc(sizeof(int)*(array[i]+1));
        tmp[0] = tmp[1] = 0;
        for(int j=2; j<=array[i]; j++)
        {
            tmp[j] =1;

        }
        for(int j=2; j*j<=array[i]; j++)
        {
            for(int k=j+j; k<=array[i]; k+=j)
            {
                tmp[k] =0;
            }
        }
        if(tmp[array[i]] == 1)
            sum++;
        free(tmp);
    }
    cout << sum;
}
