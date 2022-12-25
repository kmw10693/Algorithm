#include <bits/stdc++.h>
using namespace std;

int t;
int ans2[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int k;
            cin >> k;
            ans2[i] = k;
        }
        int max_val = ans2[n-1];
        
        long long ans = 0;
        for(int i=n-2; i>=0; i--){
            if(ans2[i] > max_val) max_val = ans2[i];
            ans += (max_val - ans2[i]);
        }
        
        cout << ans << "\n";
    }
}
