#include <bits/stdc++.h>

using namespace std;

int N;
int paper[2200][2200];
int cnt[3];

bool check(int x, int y, int N)
{
    for(int i=x; i<x+N; i++)
    {
        for(int j=y; j<y+N; j++)
        {
            if(paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
    
}
void solve(int x, int y, int N)
{
    if(check(x,y,N) == true)
    {
        cnt[paper[x][y]+1]++;
        return; // base condition;
    }
    int t = N/3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            solve(x+i*t, y+j*t, t);
        
    
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> paper[i][j];
    solve(0, 0, N);
    cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];
        
    
}
