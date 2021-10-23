#include <bits/stdc++.h>

using namespace std;

int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};
int nz[2] = {1,-1};
#define X first
#define Y second 

int board[102][102][102];

int main(void)
{
    int dist[102][102][102];
    queue <tuple<int, int, int>> q;
    
    int m,n,h;
    cin >> m >> n >> h;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<n; j++)
            fill(dist[i][j], dist[i][j]+m, -1);
    }
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){
                    dist[i][j][k] = 0;
                    q.push({i,j,k});
                }
                if(board[i][j][k] == -1){
                    dist[i][j][k] = 0;
                }
            }
        }
    }
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int x = get<2>(t) + nx[i];
            int y = get<1>(t) + ny[i];
            int z = get<0>(t);
            
            if(x < 0 || x >= m || y <0 || y>=n || z < 0 || z>=h) continue;
            if(dist[z][y][x] >= 0 || board[z][y][x] == -1) continue;
            
            dist[z][y][x] = dist[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
            q.push({z,y,x});
        }
        for(int i=0; i<2; i++)
        {
            int x = get<2>(t);
            int y = get<1>(t);
            int z = get<0>(t) + nz[i];
            
            if(x < 0 || x >= m || y <0 || y>=n || z < 0 || z>=h) continue;
            if(dist[z][y][x] >= 0 || board[z][y][x] == -1) continue;
            
            dist[z][y][x] = dist[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
            q.push({z,y,x});
            
        }
    }
    int result = 0;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                result = max(dist[i][j][k], result);
                if(dist[i][j][k] == -1)
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << result;
}
