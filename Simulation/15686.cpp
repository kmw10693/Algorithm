#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[51][51];

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int,int>> chicken;
    vector<pair<int,int>> home;
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) home.push_back({i,j});
            else if(arr[i][j] == 2) chicken.push_back({i,j});
        }
    }
    
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() -m, 0);
    int ans3 = 99999999;
    do{
        int ans2 = 0;
        for(int j=0; j<home.size(); j++){
         int x = home[j].first;
         int y = home[j].second;
     
         int ans = 99999999;
         for(int i=0; i<chicken.size(); i++){
                if(brute[i] == 0) continue;
                int tmpX = chicken[i].first;
                int tmpY = chicken[i].second;
                
                int tmpA = abs(x - tmpX) + abs(y - tmpY);
                ans = min(ans, tmpA);
            }
            ans2 += ans;
        }
        ans3 = min(ans3, ans2);
        
    }while(next_permutation(brute.begin(), brute.end()));
    
    cout << ans3;
    
}