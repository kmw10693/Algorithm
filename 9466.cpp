#include <bits/stdc++.h>

using namespace std;


int arr[100005];
int checkArr[100005];

const int CYCLE_IN = -1;
const int NOT_VISITED = 0;

void run(int x)
{
    int cur = x;
    while(true)
    {
        checkArr[cur] = x;
        cur = arr[cur];
        
        if(checkArr[cur] == x)
        {
            while(checkArr[cur] != CYCLE_IN)
            {
                checkArr[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        else if(checkArr[cur] != 0) return;
    }
}

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
   
    while(t--)
    {
        int n;
        cin >> n; 
        fill(checkArr+1, checkArr+n+1, 0);
        for(int i=1; i<=n; i++)
            cin >> arr[i];
            
        int ans = 0; 
        for(int i=1; i<=n; i++)
        {
            if(checkArr[i] == NOT_VISITED)  run(i);
        }
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(checkArr[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << "\n";
    }
}
