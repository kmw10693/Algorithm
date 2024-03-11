#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<string> v;
    
    for(int i=s.size()-1; i>=0; i--){
        string t;
        for(int j=i; j<=s.size()-1; j++){
            t.push_back(s[j]);
        }
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << "\n";
    }
}
    
