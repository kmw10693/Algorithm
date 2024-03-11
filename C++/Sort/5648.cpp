#include <bits/stdc++.h>
using namespace std;

int n;

string rever(string s) {
    string t = "";
    bool c = 0;
    for(int i=s.length()-1; i>=0; i--){
        if(c == 0 && s[i] - '0' == 0) continue;
        else {
            if(s[i] != '0') c = 1;
            t.push_back(s[i]);
            
        }
    }
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<long long> v;
    while(n--) {
        string s;
        cin >> s;
        v.push_back(stoll(rever(s)));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    
}
