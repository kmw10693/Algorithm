#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int arr[300000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int sum = 0;
    int en= 0;
    int ans = 0;
    sum = arr[0];
    for(int i=0; i<n; i++){
        while(en < n && sum < m){
            en++;
            sum += arr[en];
        }
        if(en == n) break;
        if(sum == m) ans++;
        sum -= arr[i];
    }
    cout << ans;
}
