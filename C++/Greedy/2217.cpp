#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // 정렬
    sort(arr, arr+n);
    int ans = 0;
    // 첫째 줄 부터 비교
    for(int i=0; i<n; i++){
        ans = max(arr[i] * (n-i), ans);
    }
    cout << ans;
}
