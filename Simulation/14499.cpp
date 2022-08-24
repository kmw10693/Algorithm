#include <bits/stdc++.h>

using namespace std;

int n,m,k,x,y;

int arr[22][22];

int dice[5][5];

// 0 2 0 0

// 4 1 3 6

// 0 5 0 0 

// 0 6 0 0 

void move(int t){

    int tmp[4][4];

    for(int i=0; i<4; i++){

        for(int j=0; j<4; j++){

            tmp[i][j] = dice[i][j];

        }

    }

    if(t == 1){

        for(int i=0; i<3; i++){

            dice[1][i+1] = tmp[1][i];

        }

        dice[1][0] = tmp[1][3];

        dice[3][1] = dice[1][3];

    }

    else if(t == 2){

        for(int i=1; i<4; i++){

            dice[1][i-1] = tmp[1][i];

        }

        dice[1][3] = tmp[1][0];

        dice[3][1] = dice[1][3];

    }

    else if(t == 3){

        for(int i=1; i<4; i++){

            dice[i-1][1] = tmp[i][1];

        }

        dice[3][1] = tmp[0][1];

        dice[1][3] = dice[3][1];

    }

    else{

        for(int i=0; i<3; i++){

            dice[i+1][1] = tmp[i][1];

        }

        dice[0][1] = tmp[3][1];

        dice[1][3] = dice[3][1];

    }

}

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    

    cin >> n >> m >> x >> y >> k;

    

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> arr[i][j];

        }

    }

    while(k--){

        int t;

        cin >> t;

        if(t == 1){

           if(y+1 >= m) continue;

           y +=1;

        }

        else if(t == 2){

           if(y-1 < 0 ) continue;

           y-=1;

        }

        else if(t == 3){

            if(x-1 < 0 ) continue;

            x -=1;

        }

        else {

            if(x+1 >= n) continue;

            x+=1;

        }

       move(t);

        cout << dice[1][1] << '\n';

        if(arr[x][y] != 0){

            dice[1][3] = arr[x][y];

            dice[3][1] = arr[x][y];

            arr[x][y] = 0;

        }

        else{

            arr[x][y] = dice[3][1];

        }

        

    }

    

}
