#include <bits/stdc++.h>
using namespace std;

int t; 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int ans = 1;
        unordered_map<string, int> um;
        for(int i=0; i<n; i++){
            string a,b;
            cin >> a >> b;
            um[b]++;
        }
        
        for(auto t : um){
            ans *= (t.second + 1);
        }
        cout << ans -1 << "\n";
    }
}

// 중복을 제거하기 위해서 값을 +1 을 해준 값을 곱하고, 결과 값에 -1을 해주면 된다. (해시)
