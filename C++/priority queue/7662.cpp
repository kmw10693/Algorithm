#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; 
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        multiset <int> ms;
        while(k--){
            char a;
            int b;
            cin >> a >> b;
            if(a == 'D') {
                if(ms.empty()) continue;
                else {
                    if (b == -1) ms.erase(ms.begin());
                    else ms.erase(prev(ms.end()));
                }
            }
            else {
                ms.insert(b);
            }
        }
        if(ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << "\n";
    }
}
// 이진 검색 트리를 활용한 구현 
