#include <bits/stdc++.h>

using namespace std;

int n,m;

int arr[20];

int arr2[20];

bool vis[20000];

void ans(int t, int k){

    if(t == m) {

        for(int i=0; i<m; i++){

            cout << arr2[i] << ' ';

        }

        cout << '\n';

        return;

    }

    for(auto a : arr){

        if(!vis[a] && k < a) {

            vis[a] = 1;

            arr2[t] = a;

            ans(t+1, a);

            vis[a] = 0;

        }

    }

}

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    

    cin >> n >> m;

    for(int i=0; i<n; i++)

        cin >> arr[i];

    sort(arr, arr+n);

    ans(0,0);

}
