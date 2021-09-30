#include <bits/stdc++.h>

using namespace std;

int map1[100005];
int prepos[100005];

int main() {
    fill(map1, map1+100005, -1);
    int n,k;
    cin >> n >> k;
    
    queue<int> q;
    map1[n] = 0;
    prepos[n] = n;
    q.push(n); // 1 16
    
    while(map1[k] == -1)
    {
        auto t = q.front(); q.pop();

        for(int nxt : {2*t, t-1, t+1}) // 2 0 9
        {

            if(nxt < 0 || nxt > 100000) continue;
            if(map1[nxt] > -1) continue; 
            
            map1[nxt] = map1[t] + 1;
            prepos[nxt] = t;
            q.push(nxt);
        }

    }
    cout << map1[k] << "\n";
    deque<int> track = {k};
    while(track.front() != n)
    {
        track.push_front(prepos[track.front()]);
    }
    for(int p : track)  cout << p << ' ';
    
}