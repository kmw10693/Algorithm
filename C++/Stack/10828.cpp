#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    stack <int> t;
    while(n--)
    {
        cin >> s;
        if(s == "push")
        {
            int k;
            cin >> k; 
            t.push(k);
        }
        else if(s == "top")
        {
           if(t.empty())
                cout << "-1" << "\n";
           else
                cout << t.top() << "\n"; 
          
        }
        else if(s == "size")
        {
            cout << t.size() << "\n";
        }
        else if(s == "empty")
        {
            if(t.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }
        else if(s == "pop")
        {
            if(t.empty())
                cout << "-1" << "\n";
            else
            {
                cout << t.top() << "\n";
                t.pop();
            }
        }
    }
}
