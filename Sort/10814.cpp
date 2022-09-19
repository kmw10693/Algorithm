#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> a,
pair<int,string> b) {
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int,string>> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        string s;
        cin >> t >> s;
        v.push_back({t,s});
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}
// Stable sort
