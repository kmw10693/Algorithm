#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define X first
#define Y second

int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};


int m, n, t, k;

int main(void)
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    
    while(t--)
    {
        queue<pair<int,int>> q;
        
        int count = 0;
        
        int board[52][52] = {0};
        int dist[52][52] = {0};
        
        cin >> m >> n >> k;
        for(int i=0; i<k; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == 1 && dist[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 1;
                    count++;
                }
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dst=0; dst<4; dst++)
                    {
                        int x = cur.X + nx[dst];
                        int y = cur.Y + ny[dst];
                        
                        if(x < 0 || x >= n || y < 0 || y >=m) continue;
                        if(dist[x][y] !=0 || board[x][y] !=1) continue;
                        
                        dist[x][y] = 1;
                        q.push({x,y});
                        
                    }
                }
            }
        }
        cout << count << "\n";
        
        
    }
}

