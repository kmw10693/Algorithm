#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int t[2000005] = {0};
    int n;
    cin >> n;
    int *tmp = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> tmp[i];
    }
    int x;
    cin >> x;
    int check =0;
    for(int i=0; i<n; i++)
    {
       if(tmp[i] < x)
       {
           if(t[x-tmp[i]])
            check++;
       }
       t[tmp[i]]++;
    }
    cout << check;
    delete []tmp;
    
}
