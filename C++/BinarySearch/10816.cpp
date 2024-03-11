#include <bits/stdc++.h>
using namespace std;

int arr[500005];
int n,m;

int lower_search(int target){
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(arr[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int higher_search(int target){
    int st = 0;
    int en = n;
    while(st < en){
        int mid = (st+en)/2;
        if(arr[mid] > target) en = mid;
        else st = mid+1;
    }
    return st;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cin >> m;
    for(int i=0; i<m; i++){
        int t; cin >> t;
        cout << higher_search(t) - lower_search(t) << " ";
    }
}
