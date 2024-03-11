#include <bits/stdc++.h>
using namespace std;
int n;
string arr[100];

bool compare(string a, string b){
    
    if(a.size() != b.size()) return a.length() < b.length();
    else if(a.size() == b.size()){
        int suma = 0, sumb =0;
        for(int i=0; i<a.size(); i++){
            if(isdigit(a[i])) suma += (a[i] - '0');
        }
        for(int i=0; i<b.size(); i++){
            if(isdigit(b[i])) sumb += (b[i] - '0');
        }
        if(suma != sumb) return suma < sumb;
    }
    return a < b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n, compare);
    for(int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }
}
