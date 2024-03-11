#include <bits/stdc++.h>
using namespace std;

int n;
int friendk[55][55];
const int INF = 0x3f3f3f3f;
int minscore[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++)
        fill(friendk[i], friendk[i]+1+n, INF);
    
    for(int i=1; i<=n; i++) friendk[i][i] = 0;
    
    while(1){
        int x,y;
        cin >> x >> y;
        if(x == -1 && y == -1) break;
        friendk[x][y] = friendk[y][x] = 1;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                friendk[i][j] = min(friendk[i][j], friendk[i][k] + friendk[k][j]);
            }
        }
    }
    
    int mm = INF;
    for(int i=1; i<=n; i++){
        int m = 0;
        for(int j=1; j<=n; j++){
            m = max(m, friendk[i][j]);
        }
        minscore[i] = m;
        mm = min(mm, minscore[i]);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(minscore[i] == mm){
            cnt++;
        }
    }
    cout << mm << ' ' << cnt << '\n';
    for(int i=1; i<=n; i++){
        if(minscore[i] == mm){
            cout << i << ' ';
        }
    }
}
// 플루이드 와샬 알고리즘을 통한 문제풀이
