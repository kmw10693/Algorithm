#include <bits/stdc++.h>


using namespace std;

string board[1002];

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int vis1[1002][1002]; // บา
int vis2[1002][1002];   // ม๖ศฦ


int main(void) {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >>m;
    
    for(int i=0; i<n; i++)
    {
        fill(vis1[i], vis1[i]+m, -1);
        fill(vis2[i], vis2[i]+m, -1);
    }
    
    for(int i=0; i<n; i++)
    {
        cin >> board[i];
        
    }
    queue <pair<int, int>> q1;  // บา
    queue <pair<int, int>> q2; // ม๖ศฦ
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == 'F'){
                q1.push({i,j});
                vis1[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                q2.push({i,j});
                vis2[i][j] = 0;
            }
        }
    }
    while(!q1.empty())
    {
        auto cur = q1.front(); q1.pop();
        for(int i=0; i<4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >=n || ny < 0 || ny>=m)
                continue;
            if(vis1[nx][ny]>=0 || board[nx][ny] == '#')
                continue;
            
            vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
            q1.push({nx,ny});
            
        }
    }
    while(!q2.empty())
    {
        auto cur = q2.front(); q2.pop();
        for(int i=0; i<4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >=n || ny < 0 || ny>=m)
            {
                cout << vis2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(vis2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if(vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y]+1)
                continue;
                
            vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
            q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
}
