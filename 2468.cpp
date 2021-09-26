#include <bits/stdc++.h>
using namespace std;

int arr[105][105];

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int maxt = 0;
    vector <int> v;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
            maxt = max(arr[i][j], maxt);
        }
    }
    for(int i=0; i<=maxt; i++)
    {
        int check[105][105] = {0};
        
        for(int j=0; j<n; j++)
        {
            for(int t=0; t<n; t++)
            {
                if(arr[j][t] <= i)
                    check[j][t] = 1;
            }
        }

        queue <pair<int,int>>q;
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            for(int t=0; t<n; t++)
            {
                if(check[j][t] < 1)
                {
                    q.push({j,t});
                    sum++;
                }
                while(!q.empty())
                {
                    auto t = q.front(); q.pop();
                    for(int at=0; at<4; at++)
                    {
                        int x = t.X + dx[at];
                        int y = t.Y + dy[at];
                        
                        if(x<0 || x>=n || y<0 || y>=n)
                            continue;
                        if(check[x][y] > 0)
                            continue;
                        check[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
            
        }
        v.push_back(sum);
    }
    int maxa = 0;
    for(int i=0; i<v.size(); i++)
    {
        maxa = max(v[i], maxa);
    }
    cout << maxa;
    
   
}