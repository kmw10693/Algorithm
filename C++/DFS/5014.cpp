#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[1000001];

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    queue <int> q;
    fill(board, board+1000001, -1);
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    
    board[s] = 0;
    q.push(s);
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int nxt : {cur+u, cur-d})
        {
            if(nxt < 1 || nxt > f)
                continue;
            if(board[nxt] >=0)
                continue;
            if(nxt == cur)
                continue;
            board[nxt] = board[cur] + 1;
            q.push({nxt});
        }
    
    }
    if(board[g] == -1)
        cout << "use the stairs";
    else
        cout << board[g];
    
    
}