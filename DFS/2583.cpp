#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

#define X first
#define Y second 

int arr[101][101];
int check[101][101];

int main() {
  int m,n,k;
  cin >> m >> n >> k;
  
  
  while(k--)
  {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      
      for(int i=y1; i<y2; i++)
      {
          for(int j=x1; j<x2; j++)
          {
              arr[i][j] = 1;
          }
      }
  }
  int ans = 0;
  vector <int> a;
  
  queue <pair<int,int>> q;
  for(int i=0; i<m; i++)
  {
      for(int j=0; j<n; j++)
      {
          int dd = 0;
          int checkA = 0;
          if(arr[i][j] == 0 && check[i][j] == 0){
            q.push({i,j});
            ans++;
            checkA = 1;
          }
          while(!q.empty())
          {
             auto t = q.front(); q.pop();
             for(int qw =0; qw<4; qw++)
             {
                 int x = t.X + dx[qw];
                 int y = t.Y + dy[qw];
                 
                 if(x < 0 || x>=m || y< 0 || y>=n)
                    continue;
                 if(arr[x][y] > 0 || check[x][y] > 0)
                    continue;
                check[x][y] =1;
                dd++;
                q.push({x,y});
    
             }
          }
          if(checkA == 1 && dd == 0)
            a.push_back(dd+1);
          else if(dd != 0)
            a.push_back(dd);
      }
  }
  cout << ans << "\n";
  sort(a.begin(), a.end());
  for(int i=0; i<a.size(); i++)
    cout << a[i] << " ";
  
}
