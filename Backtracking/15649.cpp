#include <bits/stdc++.h>

using namespace std;

int n,m; // 3, 1인 경우
int arr[10];
bool isused[10];
void func(int k) // 3 1 인 경우 
{
    if(k == m)
    {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}


