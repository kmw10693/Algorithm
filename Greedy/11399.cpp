#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin >> n;
   for(int i=0; i<n; i++){
       cin >> arr[i];
   }
   sort(arr, arr+n);
   
   int sum = 0;
   for(int i=0; i<n; i++){
       for(int j=0; j<=i; j++){
           sum += arr[j];
       }
   }
   cout << sum;
   
}
