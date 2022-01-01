#include <bits/stdc++.h>

using namespace std;

char map2[10000][10000];

void draw(int x, int y, int N)
{
    for(int i=x; i<x+N; i++)
    {
        for(int j=y; j<y+N; j++)
        {
            if(i%3 == 1 && j%3 == 1) map2[i][j] = ' ';
            
            else map2[i][j] = '*';
        }
        
    }
}

void start(int x, int y, int N)
{
    if(N == 3)
    {
        draw(x,y,N);
        return;
    }
    for(int i=x; i<x+N; i+=N/3)
    {
        for(int j=y; j<y+N; j+=N/3)
        {
            if(N>3){
                if(i%N/(N/3) != 1 || j%N/(N/3) != 1) start(i,j,N/3);
            }
                
        }
    }

    
}

int main()
{
    int N;
    cin >> N;
    memset(map2, ' ', sizeof(map2));
    start(0,0,N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << map2[i][j];
        }
        cout<< "\n";
    }
}
