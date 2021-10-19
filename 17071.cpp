#include <bits/stdc++.h>

using namespace std;

int n,k;
int visit2[2][500001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second

int sum(int n)
{
    return n * (n+1)/2;
}
int main(void)
{
    cin >> n >> k;
    queue<pair<int,int>> q;
    q.push({n,0});
    visit2[0][n] = 0;
    memset(visit2, -1, sizeof(visit2));
    
    while(!q.empty())
    {
        auto a = q.front(); q.pop();
        int cur = a.X;
        int t = a.Y;
        
        if(cur > 500000 || cur < 0) continue;
        if(visit2[t%2][cur] != -1 ) continue;
        
        visit2[t%2][cur] = t;
        q.push({cur-1, t+1});
        q.push({cur+1, t+1});
        q.push({2*cur, t+1});
        
    }
    for(int i=0; i< 500000; i++)    //동생 도착 시간
    {
        int nk = k + sum(i);
        if(nk > 500000) break;
        
        if(visit2[i%2][nk] != -1 && visit2[i%2][nk] <= i  )
        {
            cout << i << "\n";
            return 0;
        }//누나 도착 시간 <= 동생 도착 시간
    }
    cout << "-1" << "\n";
}
