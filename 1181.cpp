#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b)
{
    if(a.length() == b.length())
        return a<b;
    return a.length() < b.length();
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector <string> v;
    for(int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        if(find(v.begin(), v.end(), s) == v.end())
            v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++)
        cout << v[i]<<"\n";
        
}
    
    
