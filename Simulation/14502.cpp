#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10][10];
int tmp[10][10];

int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};

int cnt;

#define X first
#define Y second

vector<pair<int,int>> v;

int dfs(){
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
          if(tmp[i][j] == 2) q.push({i,j});
      }
    }
    
    while(!q.empty()){
        auto t = q.front(); q.pop();
        int x = t.X; int y = t.Y;
        
        for(int i=0; i<4; i++){
            int dx = x + nx[i];
            int dy = y + ny[i];
            
            if(dx < 0 || dx >=n || dy < 0 || dy >= m) continue;
            if(tmp[dx][dy] != 0) continue;
            
            tmp[dx][dy] = 2;
            q.push({dx,dy});
        }
    }
    
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 0) sum++;
        }
    }
    return sum;
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int me = -1;
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];

        if(arr[i][j] == 0){
            v.push_back({i,j});
            cnt++;
        }
        }
    }
    
    vector<int> v2;
    for(int i=0; i<3; i++){
        v2.push_back(1);
    }
    for(int i=0; i<cnt-3; i++){
        v2.push_back(0);
    }
    
    sort(v2.begin(), v2.end());
    do{
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
               tmp[i][j] = arr[i][j];
        }
        
        for(int i=0; i<v2.size(); i++){
            if(v2[i] == 1){
                tmp[v[i].X][v[i].Y] = 1;
            }
        }
        me = max(me, dfs());
    }while(next_permutation(v2.begin(), v2.end()));
    cout << me;
}
