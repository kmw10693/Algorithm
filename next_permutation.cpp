#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[3] = {1,2,3};
    do{
        for(int i=0; i<3; i++)
            cout << a[i];
        cout << "\n";
        
    }while(next_permutation(a,a+3));
    
    int ab[4] = {0, 0, 1, 1};
    do{
        for(int i=0; i<4; i++){
            if(ab[i] == 0)
                cout << i+1;
        }
        cout << "\n";
    }while(next_permutation(ab, ab+4));
}
