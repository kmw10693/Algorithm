#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
ll arr[10000001];
ll tmp[10000001];

bool check(ll x){
    ll sum = 0;
    for(ll i=0; i<n; i++){
        tmp[i] = arr[i];
        if(tmp[i] - x > 0) sum += (tmp[i] - x);
    }
    return sum >= m;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(ll i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    ll st=0;
    ll en = 2000000001;
    
    while(st < en){
        ll mid = (st+en+1)/2;
        if(check(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}
