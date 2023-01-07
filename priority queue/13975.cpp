#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    
    while(n--){
        int t;
        cin >> t;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        while(t--){
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
    
    ll ans = 0;
    while(q.size() > 1){
        ll a = q.top(); q.pop();
        ll b = q.top(); q.pop();
        ans += (a+b);
        q.push(a+b);
    }
    cout << ans << "\n";
        }
}
