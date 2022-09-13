#include <bits/stdc++.h>
using namespace std;

int n,l;
int board[102][102];

bool ans(vector <int>& line){
    int cnt = 1;
    int idx = 0;
    while(idx < n-1){
        if(abs(line[idx+1] - line[idx]) > 1) return 0;
        if(line[idx] == line[idx + 1]) {
            cnt++;
            idx++;
        }
        
        else if(line[idx] < line[idx+1]) {
            if(cnt < l) return 0;
            cnt = 1;
            idx++;
        }
        else {
            if(idx + l >= n) return 0;
            for(int i= idx+1; i< idx+l; i++){
                if(line[i] != line[i+1]) return 0;
            }
            idx = idx + l;
            cnt = 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    }
    int ans2 = 0;
    // 가로
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<n; j++){
            v.push_back(board[i][j]);
        }
        ans2 += ans(v);
    }
    
    // 세로
    for(int i=0; i<n; i++){
        vector<int> t;
        for(int j=0; j<n; j++){
            t.push_back(board[j][i]);
        }
        ans2 += ans(t);
    }
    cout << ans2;
    
}