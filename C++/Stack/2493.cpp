#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    stack <pair<int,int>> s;
    int n;
    cin >> n;

    int tmpI = 1;
    vector <int> ans;
    
    while(n--)
    {
        int t;
        cin >> t;
        while(!s.empty())
        {
            if(s.top().second > t)
            {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        if(s.empty())
        {
            cout << "0" << " ";
        }
        
        s.push(make_pair(tmpI, t));
        tmpI++;
    }
    
   
    
}
