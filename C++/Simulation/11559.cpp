#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char arr[15][15];
bool carr[15][8];
bool carr2[15][8];

int ans = 0;
int t;

void search(int x, int y){
    carr[x][y] = true;
    if(x < 0 || x>=12 || y<0 || y>=6) return;
    for(int i=0; i<4; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X < 0 || X>=12 || Y<0 || Y>=6) continue;
        if(!carr[X][Y] && arr[x][y] == arr[X][Y]) {
            carr[X][Y] = true;
            search(X,Y);
        }
    }
    t++;
}

void del(int x, int y, char c){
    arr[x][y] = '.';
    carr2[x][y] = true;
    if(x < 0 || x>=12 || y<0 || y>=6) return;
    for(int i=0; i<4; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X < 0 || X>=12 || Y<0 || Y>=6) continue;
        if(!carr2[X][Y] && arr[X][Y] == c) {
            carr2[X][Y] = true;
            arr[X][Y] = '.';
            del(X,Y,c);
        }
    }
    
}

void mova(int x, int y, int c) {
    int X = x + 1;
    if(X <0 || X>=12) return;
    if(arr[X][y] == '.'){ 
        arr[X][y] = c;
        arr[x][y] = '.';
        mova(X, y, c);
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin >> arr[i][j];
        }
    }

    while(1){
        bool tns = false;
        queue<pair<int,int>> q;
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(arr[i][j] != '.') q.push({i,j});
            }
        }
        if(q.empty()) break;
        memset(carr, 0, sizeof(carr));
        memset(carr2, 0, sizeof(carr2));
        
        while(!q.empty()){
            auto qt = q.front(); q.pop();
            t = 0;
            int x = qt.X;
            int y = qt.Y;
            search(x,y);
            if(t >= 4){
               tns = true;
        
                del(x,y,arr[x][y]);
            }
            
        }
        for(int i=11; i>=0; i--){
                    for(int j=5; j>=0; j--){
                        if(arr[i][j] != '.') mova(i,j,arr[i][j]);
                    }
                }

        if(tns == false) break;
        if(tns == true) ans++;
        
    }

    cout << ans;
}
   
