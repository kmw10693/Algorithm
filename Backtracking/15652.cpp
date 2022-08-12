#include <bits/stdc++.h>

using namespace std;

int n,m;

int arr[20];
bool vis[20];

void cur(int t, int k){
    if(t == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(k <= i){
            arr[t] = i;
            vis[i] = 1;
            cur(t+1, i);
            vis[i] = 0;
        }
    }
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cur(0,0);
}
