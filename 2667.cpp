#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second 

int arr[101][101];
int check[101][101];

int main() {
  ios :: sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  string arr2[101];
  
  cin >> n;
  
  for(int i=0; i<n; i++)
  {
      cin >> arr2[i];
  }
   for(int i=0; i<n; i++)
  {
      for(int j=0; j<n; j++)
      {
          if(arr2[i][j] == '0')
            arr[i][j] = 0;
          else if(arr2[i][j] == '1')
            arr[i][j] = 1;
      }
  }
  queue <pair<int,int>> q;
  vector <int> v;
  int ans = 0;

  for(int i=0; i<n; i++)
  {
      for(int j=0; j<n; j++)
      {
          int vv = 0;
          int checka = 0;
          if(arr[i][j] == 1 && check[i][j] == 0){
            q.push({i,j});
            ans++;
            checka = 1;
          }
          while(!q.empty())
          {
             auto t = q.front(); q.pop();
             for(int qw =0; qw<4; qw++)
             {
                 int x = t.X + dx[qw];
                 int y = t.Y + dy[qw];
                 
                 if(x < 0 || x>=n || y< 0 || y>=n)
                    continue;
                 if(arr[x][y] < 1 || check[x][y] > 0)
                    continue;
                check[x][y] =1;
                q.push({x,y});
                vv++;
    
             }
          }
          if(vv == 0 && checka == 1)
            v.push_back(vv+1);
          else if(vv != 0)
            v.push_back(vv);
            
      }
  }
  cout << ans << "\n";
  sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++)
    cout << v[i] << "\n";
        
 
  
}
