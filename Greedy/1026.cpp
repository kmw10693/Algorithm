#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int b[105];

bool compare(int i, int j) {
    return i > j;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    
    // 역정렬
    sort(a, a+n, compare);
    // 순정렬
    sort(b, b+n);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += (a[i] * b[i]);   
    }
    cout << sum;
}
