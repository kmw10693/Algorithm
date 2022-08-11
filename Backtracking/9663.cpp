#include <bits/stdc++.h>

using namespace std;

bool isused1[100];

bool isused2[100];

bool isused3[100];

int cnt = 0;

int n;

void recur(int cur){

    if(cur == n){

        cnt++;

        return;

    }

    

    for(int i=0; i<n; i++){

        if(isused1[i] || isused2[cur+i] || isused3[cur-i+n-1])

          continue;

        isused1[i] = 1;

        isused2[cur+i] = 1;

        isused3[cur-i+n-1] = 1;

        recur(cur+1);

        isused1[i] =0;

        isused2[cur+i] = 0;

        isused3[cur-i+n-1] = 0;

    }

}

int main(){

   ios::sync_with_stdio(0);

   cin.tie(0);

   

   cin >> n;

   recur(0);

   

   cout << cnt;

}
