#include <bits/stdc++.h>
using namespace std;

int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};

#define X first
#define Y second

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    string arr[n];
    
    int arr2[601][601];
    
    for(int i=0; i<n; i++)
    {
        fill(arr2[i], arr2[i]+m, -1);
    }
    
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
            
    queue <pair<int, int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] == 'I'){
                arr2[i][j] = 0;
                q.push({i,j});
            }
            if(arr[i][j] == 'X')
                arr2[i][j] = 0;
            
        }
    }
    int sum = 0;
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int x = t.X + nx[i];
            int y = t.Y + ny[i];
            
            if(x < 0 || x>=n || y<0 || y>=m)
                continue;
            if(arr2[x][y] >= 0 || arr[x][y] == 'X')
                continue;
            
            if(arr2[x][y] < 0 && arr[x][y] == 'P')
                sum++;
            
            arr2[x][y] = 1;
            q.push({x,y});
        }
    }
    if(sum > 0)
        cout << sum << "\n";
    else
        cout << "TT" << "\n";
    
    
        
    
}
