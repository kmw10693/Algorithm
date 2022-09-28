#include <bits/stdc++.h>

using namespace std;

int n,c;

map<int,int> order;

bool cmp(pair<int,int>& a, pair<int, int> & b){
    if(a.second == b.second) return order[a.first] < order[b.first];
    
    return a.second > b.second;
        
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int,int> a; // 1,1 2,2 
    
    cin >> n >> c;
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        a[k]++;
        
        if(order[k] == 0) order[k] = i+1;
    }
    
    vector<pair<int,int>> v(a.begin(), a.end());
    sort(v.begin(), v.end(), cmp);
    
    for (auto x : v)
	{
		for (int i = 0; i < x.second; i++)
		{
			cout << x.first << " ";
		}
	}
    
}
