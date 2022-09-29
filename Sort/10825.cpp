#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    
    vector<tuple<int,int,int,string>> v;
    
    while(n--){
        string s;
        int a,b,c; // a는 국어 b는 영어 c는 수학
        cin >> s >> a >> b >> c;
        v.push_back({-a, b, -c, s});
    }
    sort(v.begin(), v.end());
    for(auto s : v) {
        cout << get<3>(s) << "\n";
    }
}
