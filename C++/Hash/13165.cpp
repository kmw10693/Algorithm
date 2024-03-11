#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    multimap<string, string> um;
    unordered_map<string, string> um2;
    
    for(int i=0; i<n; i++){
        string s;
        int t;
        cin >> s >> t;
        for(int j=0; j<t; j++){
            string name;
            cin >> name; 
            um.insert({s, name});
            um2.insert({name,s});
        }
    }
    
    
    for(int i=0; i<m; i++){
        string s;
        int t;
        cin >> s >> t;
        if(t == 0) {
            vector <string> v;
            for(auto it = um.lower_bound(s); it != um.upper_bound(s); it++){
                v.push_back(it->second);
            }
            sort(v.begin(), v.end());
            for(int i=0; i<v.size(); i++){
                cout << v[i] << "\n";
            }
        }
        else {
            cout << um2[s] << "\n";
        }
    }
    
}

// 걸그룹, 이름을 구별한 해시맵을 2개 생성하여 값을 구해준다.
