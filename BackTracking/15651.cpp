#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];
int arrcheck[10][10];


void check(int k, int t)
{
    if(k == m)
    {
        for(int i=0; i<m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        
        return;
    }
    
    for(int i=1; i<=n; i++)
    {
        if(!arrcheck[k][i])
        {
            arrcheck[k][i] = 1;
            arr[k] =i;
            check(k+1, i);
            arrcheck[k][i] = 0;
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    check(0,1);
    
}


