#include <bits/stdc++.h>

using namespace std;

int board[5][6][6][6];
int maze[6][6][6];

int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

int ans(){
    int dist[5][5][5] = {0,};
    if(maze[0][0][0] == 0 or maze[4][4][4] == 0) return 9999;
    
    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 1;
    q.push({0,0,0});
    
    while(!q.empty()){
        tuple<int,int,int> cur = q.front(); q.pop();
        for(int i=0; i<6; i++){
            int x,y,z;
            tie(x,y,z) = cur;
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if(nx < 0 || nx>= 5 || ny< 0 || ny>=5 || nz<0 || nz>=5) continue;
            if(maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0) continue;
            
            
            if(nx == 4 && ny == 4 && nz == 4) return dist[x][y][z];
            
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx,ny,nz});
        }
    }
    return 9999;
    
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 미로 설계하기
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                cin >> board[0][i][j][k];
            }
            
        }
        
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                board[1][i][j][k] = board[0][i][4-k][j];
            }
        }
        
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                board[2][i][j][k] = board[1][i][4-k][j];
            }
        }
        
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                board[3][i][j][k] = board[2][i][4-k][j];
            }
        }
    }
    
    // 블록 쌓기
    int dum[5] = {0,1,2,3,4};
    int answer = 9999;
    
    do {
        for(int i=0; i<1024; i++){
            int tmp = i;
            for(int j=0; j<5; j++){
                int k = tmp % 4;
                tmp /= 4;

                for(int a=0; a<5; a++){
                    for(int b=0; b<5; b++) {
                        maze[j][a][b] = board[k][dum[j]][a][b];
                    }
                }
            }
            answer = min(answer, ans());
            
        }
        
    } while(next_permutation(dum, dum+5));
    
    if(answer == 9999) {
        cout << -1;
    }
    else cout << answer;
    
}
