#include <bits/stdc++.h>
using namespace std;

int N,M,H;
int ans = 4;

void dfs(int now, int n, bool ladder[31][11]){
    if(n >= ans) return;
    
    bool chk = false;
    for(int i=1; i<=n; i++){
       int now = i;
       for(int j=1; j<=H; j++){
           if(ladder[j][now-1]) now--;
           else if(ladder[j][now]) now++;
       }
       
       if(now != i) {
           chk = true;
           break;
       }
    }
    if(!chk) {
        ans = min(ans, n);
        return;
    }
    
    if(n == 3) return;
    for(int j=now; j<N; j++){
        for(int i=1; i<=H; i++){
            if(!ladder[i][j] && !ladder[i][j-1] && !ladder[i][j+1]){
                ladder[i][j] = true;
                dfs(j, n+1, ladder);
                ladder[i][j] = false;
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool ladder[31][11];
    memset(ladder, 0, sizeof(ladder));
    
    cin >> N >> M >> H;
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        ladder[a][b] = true;
    }
    dfs(1,0,ladder);
    if(ans == 4) cout << -1;
    else cout << ans;
    
}
