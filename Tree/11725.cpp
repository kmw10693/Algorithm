#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
int h[100005];

void dfs(int cur){
    for(int nxt : adj[cur]){
        if(h[cur] == nxt) continue;
        h[nxt] = cur;
        dfs(nxt);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n;
    m = n;
    n--;
    while(n--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    for(int i=2; i<=m; i++){
        cout << h[i] << '\n';
    }
    
}
