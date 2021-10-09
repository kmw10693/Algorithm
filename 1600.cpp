#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dx2[8] = {1,1,2,2,-1,-1,-2,-2};
int dy2[8] = {2,-2,1,-1,2,-2,1,-1};

int arr[210][210];
int count2[32][210][210];

int main(void)
{
    int k,w,h;
    cin >> k >> w >> h;
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cin >> arr[i][j];
        }

    }
    
    queue <tuple<int,int,int>> q;
    count2[0][0][0]= 1;
    q.push({0,0,0});
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        int kz,x,y;
        tie(kz,x,y) = t;
        
        if(kz < k)
        {
            for(int i=0; i<8; i++)
            {
                int nx = x + dx2[i];
                int ny = y + dy2[i];
                
                if(nx < 0 || nx >= h || ny < 0 || ny>=w) continue;
                if(arr[nx][ny]) continue;
                if(count2[kz+1][nx][ny]) continue;
                count2[kz+1][nx][ny] = count2[kz][x][y] + 1;
                q.push({kz+1,nx,ny});
            }
        }
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <0 || nx>=h || ny <0 || ny>=w) continue;
            if(arr[nx][ny]) continue;
            if(count2[kz][nx][ny]) continue;
            count2[kz][nx][ny] = count2[kz][x][y] + 1;
            q.push({kz,nx,ny});
        }
    }
    int ans = 10000009;
    for(int i=0; i< k+1; i++)
    {
        if(count2[i][h-1][w-1]) ans = min(ans, count2[i][h-1][w-1]);
    }
    if(ans == 10000009)
        cout << -1;
    else
        cout << ans-1;
    
}
