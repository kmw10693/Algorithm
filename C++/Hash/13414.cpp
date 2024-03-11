#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> um;
#define X first
#define Y second
bool compare(pair<string, int> p1, pair<string, int> p2){
    return p1.Y < p2.Y;
}
int min(int a, int b){
    if(a >= b) return b;
    return a;
}
int n,m;
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        string name;
        cin >> name;
        
        if(um.find(name) != um.end()){
            um.erase(name);
            um[name] = i;
        }
        else um[name] = i;
    }
    vector<pair<string, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), compare);
    
    int t = min(n, v.size());
    for(int i=0; i<t; i++) {
        cout << v[i].X << "\n";
    }  
}
// 수강신청
