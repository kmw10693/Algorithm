 #include <bits/stdc++.h>
using namespace std;

string s,e,q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> e >> q;
    
    int sh, sm;
    int eh, em;
    int qh, qm;
    
    sh = stoi(s.substr(0,2));
    sm = stoi(s.substr(3,5));
    
    eh = stoi(e.substr(0,2));
    em = stoi(e.substr(3,5));
    
    qh = stoi(q.substr(0,2));
    qm = stoi(q.substr(3,5));
    
    unordered_map<string, int> um;
    
    int ans = 0;
    while(1) {
        string tmpt;
        string nick;
        
        cin >> tmpt >> nick;
        if(cin.eof() == true) break;
        
        int h,m;
        h = stoi(tmpt.substr(0,2));
        m = stoi(tmpt.substr(3,5));
        
        if(um.find(nick) == um.end() && (h < sh || (h == sh && m <= sm))) {
            um.insert({nick, 1});
        }
        
        if(um[nick] >= 1 && (h> eh || (h==eh && m >= em)) && (h < qh || (h == qh && m<= qm))) {
            um[nick]++;
        }

    
        
        
    }
    for(auto t : um) {
        if(t.second >=2) ans++;
    }
    cout << ans;
    
    
    
    
}
