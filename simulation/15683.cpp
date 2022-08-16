#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int board[10][10];
int board2[10][10];

bool re(int x, int y){
    if(x <0 || x>=n || y < 0 || y>=m) {
        return true;
    }
    return false;
}

void check(int x, int y, int dir){
    int t = dir%4;
    int a = x+dx[t]; int b = y+dy[t];
    
    if(re(a,b)) return;
    if(board2[a][b] == 6) return;
    if(board2[a][b] == 0) board2[a][b] = 7;
    check(a, b, t);
        
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    cin >> n >> m;
    vector<pair<int,int>> v;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] > 0 && board[i][j] != 6)
                v.push_back({i,j});
            if(board[i][j] == 0) ans++;
        }
    }
    
    for(int i=0; i<(1 << 2*v.size()); i++){
        int brute = i;
        int tn = 0;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                board2[i][j] = board[i][j];
            }
        }
        for(int i=0; i<v.size(); i++){
            int tmp = brute%4;
            brute /= 4;
            int x = v[i].X; int y =v[i].Y;
            if(board[x][y] == 1){
                check(x,y,tmp);
            }
            else if(board[x][y] == 2){
                check(x,y,tmp);
                check(x,y,tmp+2);
            }
            else if(board[x][y] == 3){
                check(x,y,tmp);
                check(x,y,tmp+1);
            }
            else if(board[x][y] == 4){
                check(x,y,tmp);
                check(x,y,tmp+1);
                check(x,y,tmp+2);
            }
            else {
                check(x,y,tmp);
                check(x,y,tmp+1);
                check(x,y,tmp+2);
                check(x,y,tmp+3);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board2[i][j] == 0) tn++;
            }
        }
        ans = min(ans, tn);
    }
    cout << ans;
    
}
