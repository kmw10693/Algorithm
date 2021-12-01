#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        stack <char> t;
        cin >> s;
        
        int check = 0;
        for(auto k : s)
        {
            if(k == '(')
                t.push(k);
            else if(k == ')')
            {
                if(!t.empty())
                {
                    if(t.top() == '(')
                    {
                        t.pop();
                    }
                    else
                    {
                        check = 1;
                        break;
                    }
                }
                else
                {
                    check = 1;
                    break;
                }
            }
                
        }
        if(!t.empty())
            check =1;
            
        if(check == 1)
            cout << "NO"<<"\n";
        else
            cout <<"YES" << "\n";
    }
}
