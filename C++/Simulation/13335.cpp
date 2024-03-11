#include <bits/stdc++.h>
using namespace std;

int n, w, l, a[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue <int> q;
    int sum = 0;
    int ans = 0;
    
    cin >> n >> w >> l;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        while(1){
            if(q.size() == w){
                sum -= q.front();
                q.pop();
            }
            if(sum + a[i] <= l) break;
            q.push(0);
            ans++;
        }
        q.push(a[i]);
        sum += a[i];
        ans++;
    }
    cout << ans + w;
    
}