#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[8] = {2,2,1,1,-1,-1,-2,-2}; // 1 0 -1 0 
int dy[8] = {1,-1,2,-2,2,-2,1,-1}; // 0 1 0 -1

int main(void)
{
    int n;
    cin >> n;

    
    while(n--)
    {
        int check[310][310] = {0};
        int a;
        cin >> a;
        int x1, y1, x2, y2;
        cin >> x1 >> y1; 
        cin >> x2 >> y2;
        queue <pair<int,int>> q;
        
        q.push({x1,y1}); // 0 0
        
        while(!q.empty())
        {
            auto b = q.front(); q.pop();
            for(int i=0; i<8; i++)
            {
                int x = b.X + dx[i];
                int y = b.Y + dy[i];
                
                if(x<0 || x>=a || y<0 || y>=a)
                    continue;
                if(check[x][y] > 0)
                    continue;
                check[x][y] = check[b.X][b.Y] + 1;
                q.push({x,y});
            }
        }
        if(x1 == x2 && y1 == y2)
            cout << "0" << "\n";
        else
            cout << check[x2][y2] << "\n";
    }
    
}