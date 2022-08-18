#include <bits/stdc++.h>

using namespace std;

int m,n;
int arr[10];
int arrcheck[10];
int checkt;

void check(int x)
{
    if(x == n)
    {
        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout <<"\n";
        return;
    }
    for(int i=1; i<=m; i++)
    {
        
        arrcheck[i] = 1;
        arr[x] = i;
        if(checkt <= arr[x]){
          checkt = arr[x];
          check(x+1);
          checkt = arr[x];
        } 
    
        arrcheck[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    check(0);
}
