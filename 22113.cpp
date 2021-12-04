#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector <int> k;
    for(int i=0; i<m; i++)
    {
        int t;
        cin >> t;
        k.push_back(t);
    }
  
    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for(int i=0; i<m; i++)
    {
        if(i == m-1)
            break;
        int x = k[i];
        int y = k[i+1];
        sum += arr[x-1][y-1];
    }
    cout << sum;
}
