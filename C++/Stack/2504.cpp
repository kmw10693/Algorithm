#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    stack <char> s;
    
    string t;
    cin >> t;
    
    long long sum = 0;
    long long tmp = 1;
    
    for(int i=0; i<t.length(); i++)
    {
        if(t[i] == '(')
        {
            tmp *=2;
            s.push(t[i]);
        }
        else if(t[i] == '[')
        {
            tmp *=3;
            s.push(t[i]);
        }
        else if(t[i] == ')')
        {
            if(!s.empty() && s.top() == '(')
            {
                if(t[i-1] == '(')
                {
                       sum+=tmp;
                }
                s.pop();
                tmp/=2;
                
            }
            else
            {
                cout << "0" << "\n";
                return 0;
            }
        }
        else if(t[i] == ']')
        {
            if(!s.empty() && s.top() == '[')
            {
                if(t[i-1] == '[')
                {
                    sum+=tmp;
                }
                s.pop();
                tmp/=3;
            }
            else
            {
                cout << "0" << "\n";
                return 0;
            }
        }
    }
    if(!s.empty())
    {
        cout << "0" << "\n";
        return 0;
    }
    cout << sum << "\n";
}
