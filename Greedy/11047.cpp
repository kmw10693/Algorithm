#include <bits/stdc++.h>
using namespace std;

int n,k,ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    vector<int> v;
    
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        
        v.push_back(t);
    }
    for(int i=n-1; i>=0; i--){
        if(k <= 0) break;
        if(k / v[i] > 0) {
            ans += (k / v[i]);
        }
        k = k % v[i];
        
    }
    cout << ans;
}
