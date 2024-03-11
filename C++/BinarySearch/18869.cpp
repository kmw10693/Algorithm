#include <bits/stdc++.h>
using namespace std;

int m,n;
int arr[105][10005];

void compress(int a[]){
    vector <int> v(a, a+n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0; i<n; i++){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
   
}

bool compare2(int a[], int b[]) {
    for(int i=0; i<n; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
        compress(arr[i]);
    }
    
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            ans += compare2(arr[i], arr[j]);
        }
    }
    
    cout << ans;
}
