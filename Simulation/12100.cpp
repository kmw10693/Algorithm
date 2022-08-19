#include <bits/stdc++.h>
using namespace std;

int board1[21][21];
int board2[21][21];
    
int n, mx;
int tmp2[21][21];
    
void rotate() {
    int tmp[21][21];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = board2[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board2[i][j] = tmp[n-1-j][i];
        }
    }
}

void move(int t){
    while(t--) rotate();
 
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(board2[i][j] == 0) continue;
            if(tmp2[i][cnt] == 0) tmp2[i][cnt] = board2[i][j];
            else if(board2[i][j] == tmp2[i][cnt]) tmp2[i][cnt++] *=2;
            else tmp2[i][++cnt] = board2[i][j];
        }
        
        for(int j=0; j<n; j++){
            board2[i][j] = tmp2[i][j];
        }
        memset(tmp2, 0, sizeof(tmp2));
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board1[i][j];
        }
    }
    for(int a=0; a<1024; a++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board2[i][j] = board1[i][j];
            }
        }
        int brute = a;
        for(int j=0; j<5; j++){
            int tmp = brute % 4;
            brute /= 4;
            move(tmp);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               mx = max(mx, board2[i][j]);
            }
        }
    }
    cout << mx;
    
}





