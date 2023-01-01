#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> um;
string name[100005];

int n,m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> name[i];
        um[name[i]] = i;
    }
    
    for(int i=0; i<m; i++){
        string query;
        cin >> query;
        if(isdigit(query[0])) cout << name[stoi(query)];
        else cout << um[query];
        cout << "\n";
    }
}
// 나는야 포켓몬 마스터 이다솜
