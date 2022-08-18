#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
    queue <pair<int,int>> q;
    
int main(void)
{
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int board[n][m];
    bool vis[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            vis[i][j] = 0;
        }
    }
    
    int pic = 0;
    int max = 0;
    int width = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!vis[i][j] && board[i][j])
            {
                q.push({i,j});
                pic++;
                while(!q.empty())
                {
                    pair<int, int>cur = q.front(); 
                    q.pop();
                    ++width;
                     for(int dir=0; dir <4; dir++)
                     {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx <0 || nx>=n || ny<0 || ny>=m)
                        continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) 
                        continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                if(max < width)
                    max = width;
                width = 0;
            }
            
        }
        
    }
    if(max == 1 || pic == 0)
    {
        cout << pic << "\n" << max;
    }
    else
    {
        cout << pic << "\n" << max-1;
    }

    
}
