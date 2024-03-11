#include <bits/stdc++.h>

using namespace std;

int map1[100][100];
int visited[100][100];
int visited2[100][100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map1[i][j];
        }
    }
    
    queue <pair<int,int>> q;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map1[i][j] == 1 && visited[i][j] == 0)
            {
                count++;
                q.push({i,j});
                visited[i][j] = count;
            }
            while(!q.empty())
            {
                auto t=q.front(); q.pop();
                for(int at=0; at<4; at++)
                {
                    int x = t.X + dx[at];
                    int y = t.Y + dy[at];
                    
                    if(x<0 || x>=n || y<0 || y>=n)  continue;
                    if(visited[x][y] || map1[x][y] < 1)   continue;

                    visited[x][y] = count;
                    q.push({x,y});
                    
                }
            }
        }
    }
    int mina = 100000;
    int tmp = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(visited[i][j] > 0 && !visited2[i][j] && tmp != visited[i][j])
            {
                
                visited2[i][j] = 1;
                tmp = visited[i][j];
                q.push({i,j});
            }
            while(!q.empty())
            {
                auto t= q.front(); q.pop();
                for(int at=0; at<4; at++)
                {
                    int x = t.X + dx[at];
                    int y = t.Y + dy[at];
                    
                    if(x<0 || x>=n || y<0 || y>=n) continue;
                    if(visited2[x][y]) continue;
                    
                    if(visited[x][y] == 0)
                    {
                        visited2[x][y] = 1;
                        map1[x][y] = map1[t.X][t.Y] +1;
                        q.push({x,y});
                        
                    }
                    if(visited[x][y] != tmp && visited[x][y] > 0)
                    {
                        visited2[x][y] =1;
                        mina = min(mina, map1[t.X][t.Y]);
                    }

                }
            }
            memset(map1, 0, sizeof(map1));
            memset(visited2, 0, sizeof(visited2));
        }
    }
    cout <<mina;
    
   
    

    
}