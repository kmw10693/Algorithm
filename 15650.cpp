#include <bits/stdc++.h>

using namespace std;

int n,m;    // 4, 2
int arr[10];
int arrcheck[10];
int check2 = -1;

void start(int k)
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
        if(!arrcheck[i])
        {
            arrcheck[i] = 1;
            if(k > 0) check2 = arr[k-1];
            else check2 = -1;
            arr[k] = i;
            if(check2 < arr[k])
                start(k+1); 
            
            arrcheck[i] = 0;
           
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    start(0);
}


