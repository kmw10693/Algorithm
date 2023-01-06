#include <bits/stdc++.h>
using namespace std;

class tmp{
    public:
      bool operator() (int a, int b){
          if(abs(a) != abs(b)) return abs(a) > abs(b);
          return a > 0 && b < 0;
      }
};

int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    priority_queue<int, vector<int>, tmp> q;
    while(n--){
        int x; cin >> x;
        if(x == 0){
            if(q.empty()) cout << "0\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else q.push(x);
    }
}
