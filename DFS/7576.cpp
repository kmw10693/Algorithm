#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

queue <pair<int,int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void)
{
   ios :: sync_with_stdio(0);
   cin.tie(0);
   
   int board[1002][1002];
   int dist[1002][1002] = {0};
   int M, N; // m은 가로, n은 세로
   cin >> M >> N;
   
   for(int i=0; i<N; i++)
   {
       for(int j=0; j<M; j++)
       {
           cin >> board[i][j];
           if(board[i][j] == 1)
           {
                q.push({i,j});   
           }
           else if(board[i][j] == 0)
             dist[i][j] = -1;
       }
   }
   
   while(!q.empty())
   {
       auto t = q.front(); q.pop();
       for(int i=0; i<4; i++)
       {
           int nx = t.X + dx[i]; // 
           int ny = t.Y + dy[i];
           
           if(nx < 0 || nx >=N|| ny <0 || ny >= M) continue;
           if(dist[nx][ny] >=0 || board[nx][ny] != 0 ) continue;
           
           dist[nx][ny] = dist[t.X][t.Y]+1;
           q.push({nx, ny});
       }
   }
   int result = 0;
   for(int i=0; i<N; i++)
   {
       for(int j=0; j<M; j++)
       {
           if(dist[i][j] == -1)
           {
               cout << "-1" << "\n";
               return 0;
               
           }
           result = max(result, dist[i][j]);
       }
      
       
   }
   cout << result << "\n";
   
   
 
}
