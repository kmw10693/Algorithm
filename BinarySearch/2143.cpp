#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr1[1005];
ll arr2[1005];

ll dp1[1005];
ll dp2[1005];

vector <ll> v1;
vector <ll> v2;
int main() {
    
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T,m,n;
    cin >> T;
    
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr1[i];
        dp1[i] = dp1[i-1] + arr1[i];
    }
    
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> arr2[i];
        dp2[i] = dp2[i-1] + arr2[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            v1.push_back(dp1[i] - dp1[j]);
        }
    }
    
    for(int i=1; i<=m; i++){
        for(int j=0; j<i; j++){
            v2.push_back(dp2[i] - dp2[j]);
        }
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    ll ans = 0;
    for(int i=0; i<v1.size(); i++){
        int need = T - v1[i];
        ans += upper_bound(v2.begin(), v2.end(),need) - lower_bound(v2.begin(), v2.end(),need);
        
        
    }
    cout << ans;
    
}
