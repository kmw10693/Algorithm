#include <bits/stdc++.h>

using namespace std;

string arr[5];

int k,ans;

void rotate(int dir, int t){

    char start = arr[t][0];

    char end = arr[t][7];

    string tmp;

    tmp = arr[t];

    

    if(dir == 1){

        for(int i=0; i<7; i++){

            arr[t][i+1] = tmp[i];

        }

        arr[t][0] = end;

    }

    else{

        for(int i=1; i<8; i++){

            arr[t][i-1] = tmp[i];

        }

        arr[t][7] = start;

    }

}

void check(int num, int dir, int t, int s){

    if(num == 4 || num == -1) return;

    if(s == 0){

        check(num+1, dir, num, 1);

        check(num-1, dir, num, 1);

        return;

    }

    int dir2 = -1 * dir;

    if(num > t) {

        if(arr[t][2] != arr[num][6]){

          check(num+1, dir2, num, 1);

          rotate(dir2, num);

          

        }

    }

    else if(num < t){

        if(arr[t][6] != arr[num][2]) {

          check(num-1, dir2, num, 1);

          rotate(dir2, num);

        }

    }

    

}

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    

    for(int i=0; i<4; i++){

         cin >> arr[i];

    }

    cin >> k;

    while(k--){

        int num,dir;

        cin >> num >> dir;

        check(num-1, dir, 0, 0);

        rotate(dir,num-1);

    }

    

    for(int i=0; i<4; i++){

        if(arr[i][0] == '1') ans += (1 << i);

    }

    cout << ans;

    

}
