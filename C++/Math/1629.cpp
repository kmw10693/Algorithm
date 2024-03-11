#include <bits/stdc++.h>

using namespace std;

long long k(long long a, long long b, long long c)
{
    if(b == 1)
        return a%c;    
        
    long long val = k(a, b/2, c);
    val = (val * val) % c;
    
    if(b%2 == 0)
        return val;
    else
        return (val * (a%c)) % c;
    
    
    
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b, c;
    cin >> a >> b >> c;
    
    cout << k(a,b,c);
}
