#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long ans = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack <char> stick;
    
    string k;
    cin >> k;
    for(int i=0; i<k.length(); i++)
    {
        if(k[i] == '(')
        {
            stick.push(k[i]);
        }
        else
        {
            if(k[i-1] == '(')
            {
                stick.pop();
                ans+=stick.size();
            }
            else
            {
                stick.pop();
                ans++;
            }
        }

        
    }
    cout << ans << "\n";
}
