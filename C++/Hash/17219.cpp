#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string, string> um;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string site, name;
        cin >> site >> name;
        um[site] = name;
    }
    for(int i=0; i<m; i++){
        string tmp;
        cin >> tmp;
        cout << um[tmp] << "\n";
    }
    
}
