#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000005];
bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N, compare);
    
    for(int i=0; i<N; i++){
        cout << arr[i] << '\n';
    }
}
