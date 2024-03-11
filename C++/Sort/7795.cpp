#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        vector<int> a;
        vector<int> b;
        int ans = 0;
        int n,m;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            int k;
            cin >> k;
            a.push_back(k);
        }
        for(int i=0; i<m; i++){
            int k;
            cin >> k;
            b.push_back(k);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<b.size(); j++){
                if(a[i] <= b[j]) break;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
