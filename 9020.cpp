#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int *arr = new int[T];
    for(int k=0; k<T; k++)
    {
        cin >> arr[k];
        bool *p = new bool[arr[k]+1];
        p[0] = p[1] = false;
        for(int i=2; i<=arr[k]; i++)
        {
            p[i] = true;
        }
        for(int i=2; i*i<=arr[k]; i++)
        {
            for(int j=i+i; j<=arr[k]; j+=i)
            {
                p[j] = false;
            }
        }
        int tmp1, tmp2;
        tmp1 = tmp2 = arr[k]/2;
        
        while(1)
        {
            if(tmp1 + tmp2 == arr[k] && p[tmp1] && p[tmp2])
            {
                cout << tmp1 << " " <<tmp2<<endl;
                break;
            }
            tmp1--;
            tmp2++;
        }
       
    }
}
