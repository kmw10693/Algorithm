#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n,m;
pair<int,int> red, blue;
string board[11];

int dist[11][11][11][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs() {
    queue<tuple<int,int,int,int>> q;
    q.push({red.X, red.Y, blue.X, blue.Y});
    dist[red.X][red.Y][blue.X][blue.Y] = 0;
    
    while(!q.empty()) {
        int rx, ry, bx, by;
        tie(rx, ry, bx, by) = q.front();
        q.pop();
        int cnt = dist[rx][ry][bx][by];
        
        if(cnt >= 10)
            return -1;
        
        for(int i=0; i<4; i++) {
            int nRx = rx, nRy = ry, nBx = bx, nBy = by;
            
            while(board[nBx + dx[i]][nBy + dy[i]] == '.'){
                nBx += dx[i];
                nBy += dy[i];
            }
            
            if(board[nBx + dx[i]][nBy + dy[i]] == 'O') continue;
            
            while(board[nRx + dx[i]][nRy + dy[i]] == '.'){
                nRx += dx[i];
                nRy += dy[i];
            }
            
            if(board[nRx + dx[i]][nRy + dy[i]] == 'O') return cnt+1;
            
            if ((nRx == nBx) && (nRy == nBy)) {
                if(i == 0) // 아래
                    rx < bx ? nRx-- : nBx--;
                else if(i == 1) // 오른쪽
                    ry < by ? nRy-- : nBy--;
                else if(i == 2) //  위
                    rx < bx ? nBx++ : nRx++;
                else if(i == 3) // 왼쪽
                    ry < by ? nBy++ : nRy++;
            }
            
            if(dist[nRx][nRy][nBx][nBy] != -1) continue;
            dist[nRx][nRy][nBx][nBy] = cnt + 1;
            q.push({nRx, nRy, nBx, nBy});
         }
    }
    return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  
    // 거리 배열 초기화
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      for(int k = 0; k < 10; k++)
        fill(dist[i][j][k], dist[i][j][k]+10, -1);
        
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {      
      if (board[i][j] == 'B'){
        blue = {i, j};
        board[i][j] = '.';
      }
      else if (board[i][j] == 'R'){
        red = {i, j};
        board[i][j] = '.';
      }
    }
  }
  
  cout << bfs();
}
