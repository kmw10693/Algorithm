#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector <pair<int, int>>v;
    vector <int>ans(1000001);
    
    for(int i=0; i<N; i++)
    {
        int t;
        cin >> t;
        v.push_back(pair<int, int>(t, i));
    }
    sort(v.begin(), v.end());
    
    int p = v[0].first;
    int cnt = 0;
    ans[v[0].second] = 0;
    
    for(int i=1; i<N; i++)
    {
        if(v[i].first == p)
        {
            ans[v[i].second] = cnt;
        }
        else
        {
            ans[v[i].second] = ++cnt;
            p = v[i].first;
        }
    }
    for(int i=0; i<N; i++)
    {
        cout << ans[i] << " ";
    }
}
    
    
    
    
