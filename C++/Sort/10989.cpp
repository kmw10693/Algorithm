#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[10002] ={0,};
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        arr[t]++;
    }
    
    for(int i=0; i<10001; i++){
        while(arr[i]--) cout << i << '\n';
    }
}
// counting sort
