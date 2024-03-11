#include <bits/stdc++.h>
using namespace std;

long long a,b;
vector <int> v, q;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;

    for(int i=0; i<a; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    for(int i=0; i<b; i++){
        int t;
        cin >> t;
        q.push_back(t);
    }
    
    sort(v.begin(), v.end());
    sort(q.begin(), q.end());

    bool check = false;
    for(int i=0; i<a; i++){
        if(binary_search(q.begin(), q.end(), v[i])) {
            v[i] = -1;
            check = true;
            ans++;
        }
    }
    if(a- ans == 0) {
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end());
    cout << a-ans << "\n";
    for(int i=0; i<a; i++) {
        if(v[i] >= 0) cout << v[i] << " ";
    }
    
    
}
