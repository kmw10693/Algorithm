#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int check[31][31][31];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dz[2] = {1,-1};

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    while(1)
    {
    
        int l,r,c;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0)
            break;
        
        char map1[31][31][31];
        string s[31][31];
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++){
                cin >> s[i][j];
            }
        }
        int ax=0, ay=0, az=0;
        queue <pair<pair<int,int>,int>> q;
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                for(int k=0; k<c; k++)
                {
                    map1[i][j][k] = s[i][j][k];
                    if(map1[i][j][k] ==  'S'){
                        q.push({{i,j},k});
                        check[i][j][k] = 1;
                    }
                    if(map1[i][j][k] == 'E')
                    {
                        ax = i, ay = j, az=k;
                    }
                    
                }
               
            }
        }
        while(!q.empty())
        {
            auto t = q.front(); q.pop();
            for(int at=0; at<4; at++)
            {
                int x = t.X.Y + dx[at];
                int y = t.Y + dy[at];
                int z = t.X.X;
                
                if(x<0 || x>=r || y<0 || y>=c)  continue;
                if(check[z][x][y] > 0 || map1[z][x][y] == '#') continue;
                check[z][x][y] = check[t.X.X][t.X.Y][t.Y] + 1;
                q.push({{z,x},y});
            }
            for(int at=0; at<2; at++)
            {
                int x = t.X.Y;
                int y = t.Y;
                int z = t.X.X + dz[at];
                
                if(z<0 || z>=l) continue;
                if(check[z][x][y] > 0 || map1[z][x][y] == '#') continue;
                check[z][x][y] = check[t.X.X][t.X.Y][t.Y] + 1;
                q.push({{z,x},y});

            }
        }
        if(check[ax][ay][az] == 0)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << check[ax][ay][az]-1 << " minute(s).\n";
        memset(check, 0, sizeof(check));

        
    }
}