#include <bits/stdc++.h>

using namespace std;

int map1[310][310];
int visited[310][310];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map1[i][j];
        }
    }
    int ice = 0;
    int ans = 0;
    queue <pair<int,int>> q;
    
    while(1)
    {
        ice = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map1[i][j] > 0 && visited[i][j] < 1)
                {
                     ice++;
                     q.push({i,j});
                     visited[i][j] = 1;
                }
                while(!q.empty())
                {
                    auto t= q.front(); q.pop();
                    for(int at=0; at<4; at++)
                    {
                        int x = t.X + dx[at];
                        int y = t.Y + dy[at];
                        
                        if(x<0 || x>=n || y<0 || y>=m)  continue;
                        if(visited[x][y] > 0) continue;
                        
                        if(map1[x][y] == 0 )
                        {
                            map1[t.X][t.Y] = (map1[t.X][t.Y] <= 0) ? 0 : map1[t.X][t.Y] -1;
                        }
                        else
                        {
                            visited[x][y] = 1;
                            q.push({x,y});
                        }
                    }
                }
                
            }
        }

        if(ice >= 2)
        {
            cout << ans;
            return 0;
        }
        else if(ice <= 0)
        {
            cout << 0;
            return 0;
        }
        ans++;
        memset(visited, 0, sizeof(visited));
    }
}