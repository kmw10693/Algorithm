#include <bits/stdc++.h>

using namespace std;

int extend[1001][1001];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int step[10];
int area[10];
queue<tuple<int,int,int>> q[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,p;
    cin >> n >> m >> p;
    for(int i=1; i<=p; i++)
        cin >> step[i];
    char ch;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ch;
            if(ch == '.') extend[i][j] = 1;
            else if(ch == '#') extend[i][j] = 0;
            else
            {
                extend[i][j] = 0;
                q[ch -'0'].push({i,j,0});
                area[ch-'0'] += 1;
            }
        }
    }
    while(1)
    {
        bool extend2 = 0;
        for(int i=1; i<=p; i++)
        {
            queue<tuple<int,int,int>> nextq;
            while(!q[i].empty())
            {
                int curx, cury, curstep;
                tie(curx, cury, curstep) = q[i].front();
                q[i].pop();
                if(curstep >= step[i]) {
                    nextq.push({curx,cury, 0});
                    continue;
                }
                for(int dir=0; dir<4; dir++)
                {
                    int x = curx+dx[dir]; 
                    int y = cury+dy[dir];
                    if(x<0 || x>=n || y<0 || y>=m) continue;
                    if(!extend[x][y]) continue;
                    q[i].push({x,y,curstep+1});
                    extend[x][y] = 0;
                    area[i]++;
                    extend2 =1;
                }
                
            }
            q[i] = nextq;
        }
        if(!extend2) break;
    }
    for(int i=1; i<=p; i++)
        cout << area[i] << " ";
}
