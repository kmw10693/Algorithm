#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int m,n;
ll arr[1000005];
ll tmp[1000005];

bool check(ll x){
   bool p = true;
   ll sum = 0;
   for(int i=0; i<n; i++){
       sum += (arr[i] / x);
       tmp[i] = arr[i] % x;
   }
   for(int i=0; i<m-n; i++){
       if(upper_bound(tmp, tmp+n, x)) p = true;
       else p = false;
   }
   if(p == false) return false;
   
   return sum>=m;
   
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    ll st = 0;
    ll en = 1000000005LL;
    
    while(st < en){
        ll mid = (st+en+1)/2;
        if(check(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
    
}
