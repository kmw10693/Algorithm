#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int check[130][130];    // R G B 구분
int check2[130][130];   // 영역 구분
int main(void)
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string arr[130];
    
    queue <pair<int,int>>q;
    
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    // 정상인 경우 R = 0, G = 1, B = 2
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == 'R')
                check[i][j] = 0;
            else if(arr[i][j] == 'G')
                check[i][j] = 1;
            else
                check[i][j] = 2;
        }
        
    }
    int ans1 = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(check2[i][j] == 0){
                q.push({i,j});
                ans1++;
            }
            while(!q.empty())
            {
                auto t = q.front(); q.pop();
                for(int as = 0; as<4; as++)
                {
                    int x = t.X + dx[as];
                    int y = t.Y + dy[as];
                    
                    if(x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    if(check2[x][y] > 0 || check[x][y] != check[t.X][t.Y])
                        continue;
                    check2[x][y] = 1;
                    q.push({x,y});
                    
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            check2[i][j] = 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == 'R')
                check[i][j] = 0;
            else if(arr[i][j] == 'G')
                check[i][j] = 0;
            else
                check[i][j] = 1;
        }
    }
    int ans2 = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(check2[i][j] == 0){
                q.push({i,j});
                ans2++;
            }
            while(!q.empty())
            {
                auto t = q.front(); q.pop();
                for(int as = 0; as<4; as++)
                {
                    int x = t.X + dx[as];
                    int y = t.Y + dy[as];
                    
                    if(x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    if(check2[x][y] > 0 || check[x][y] != check[t.X][t.Y])
                        continue;
                    check2[x][y] = 1;
                    q.push({x,y});
                    
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    
 
}