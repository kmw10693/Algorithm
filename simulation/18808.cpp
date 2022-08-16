#include <bits/stdc++.h>
using namespace std;

int note[45][45];
int board[20][20];

int n,m,k;
int r,c;

void rotate(){
    int tmp[20][20];
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            tmp[i][j] = board[i][j];
        }
    }
    memset(board, 0, sizeof(board));
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            board[i][j] = tmp[r-1-j][i];
        }
    }
    swap(r,c);
}

bool pos(int x, int y){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(note[x+i][y+j] && board[i][j])
              return false;
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j]) {
                note[x+i][y+j] = 1;
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >>m >> k;
    
    while(k--){
        cin >> r >> c;
        for(int i=0; i<r;i++){
            for(int j=0; j<c; j++)
              cin >> board[i][j];
        }
        
        for(int i=0; i<4; i++){
            bool rot = false;
            for(int a=0; a<=n-r; a++){
                if(rot) break;
                for(int b=0; b<=m-c; b++){
                    if(pos(a,b)) {
                        rot = true;
                        break;
                    }
                }
            }
            if(rot) break;
            rotate();
        }
        
    }
    int ans =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(note[i][j]) ans++;
        }
    }
    cout << ans;
}
