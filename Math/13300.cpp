#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int arr[2][7][1] ={0};
    int room = 0;
    for(int i=0; i<n; i++)
    {
        int s,y;
        cin >> s >> y;
        arr[s][y][0]++;
        if(arr[s][y][0] >= k)
        {
            room++;
            arr[s][y][0] = arr[s][y][0] - k;
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<7; j++)
        {
            if(arr[i][j][0] > 0)
                room++;
        }
    }
    cout << room;
    
}
