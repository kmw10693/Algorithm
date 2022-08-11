#include <bits/stdc++.h>

using namespace std;

char board[10000][10000];

void printx(int x, int y){

    board[x][y+2] = '*';

    

    board[x+1][y+1] = '*';

    board[x+1][y+3] = '*';

    

    board[x+2][y] = '*';

    board[x+2][y+1] = '*';

    board[x+2][y+2] = '*';

    board[x+2][y+3] = '*';

    board[x+2][y+4] ='*';

}

void star(int n, int x, int y){

    if(n == 3) {

        printx(x,y);

        return;

    }

    star(n/2, x, y+n/2);

    star(n/2, x+n/2, y);

    star(n/2, x+n/2, y+n);

}

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    

    int n;

    cin >> n;

    memset(board, ' ', sizeof(board));

    star(n, 0,0);

    for(int i=0; i<n; i++){

        for(int j=0; j<2*n; j++){

            cout << board[i][j];

        }

        cout << '\n';

    }

    

}
