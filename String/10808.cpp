#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    char a[101];
    cin >> a;
    int al[26] = {0};
    for(int i=0; i<strlen(a); i++)
    {
        for(int k=97; k<=122; k++)
        {
            if(a[i] == k){
                al[k-97]++;
                break;
            }
                
        }
    }
    for(int i=0; i<26; i++)
    {
        cout << al[i] << ' ';
    }
}
