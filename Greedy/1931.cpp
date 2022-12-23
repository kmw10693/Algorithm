#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> v[100005];

int main() {
    cin >> n;
    // 입력
    for(int i=0; i<n; i++) {
        // 우선 끝나는 시간부터 정렬
        cin >> v[i].second >> v[i].first;
    }
    sort(v, v+n); // 정렬
    
    int t = 0, ans = 0; // 시간과 정답
    for(int i=0; i<n; i++) {
        // 만약 시간이 넘어서면 오답
        if(t > v[i].second) continue;
        ans++;
        t = v[i].first;
    }
    cout << ans;
}
