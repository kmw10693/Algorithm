#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(void)
{
    
    stack<int> s;
    int k;
    cin >> k;
    while(k--)
    {
        int a;
        cin >> a;
        if(a == 0)
        {
            s.pop();
        }
        else
            s.push(a);
    }
    int sum =0;
    while(s.size())
    {
        sum+= s.top();
        s.pop();
    }
    cout << sum;
}
