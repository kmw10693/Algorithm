#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];
vector <int> v;

int ans() {
    int start = 0, link = 0;
    vector <int> a;
    vector <int> b;
    for(int i=0; i<n; i++){
        if(v[i] == 1) a.push_back(i);
        else b.push_back(i);
    }
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            start += board[a[i]][a[j]];
            link += board[b[i]][b[j]];
        }
    }
    return abs(start-link);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    int mint = 999999999;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<n/2; i++)
        v.push_back(1);
    
    for(int i=0; i<n/2; i++)
        v.push_back(0);
    
    sort(v.begin(), v.end());
    
    do{
        mint = min(ans(), mint);
    }while(next_permutation(v.begin(), v.end()));
    cout << mint;
        
}