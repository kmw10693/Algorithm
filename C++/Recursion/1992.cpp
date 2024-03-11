#include <bits/stdc++.h>

using namespace std;

char arr[100][100];
vector<char> v;

bool test(int x, int y, int N)
{
    for(int i=x; i<x+N; i++)
    {
        for(int j=y; j<y+N; j++)
        {
            if(arr[x][y] != arr[i][j])
                return false;
        }
    }
    return true;
}

void check(int x, int y, int N)
{
    if(test(x,y,N) == true)
    {
        if(arr[x][y] == '1') {
            v.push_back('1');
        }
        else if(arr[x][y] == '0'){
            v.push_back('0');
        }
        return;

    }
    for(int i=x; i<x+N; i+=N/2)
    {
        for(int j=y; j<y+N; j+=N/2)
        {
            v.push_back('(');
            check(i,j,N/2);
           
        }
    }
    v.push_back(')');
}   

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    bool first = false;
    check(0,0,N);
    for(int i=0; i<v.size(); i++)
    {
        if((v[i] == '0' || v[i] == '1') && first == false){
            first = true;
            continue;
        }
        if(v[i] == '0' || v[i] == '1')
        {
            if(i != 0 && first == true)
            {
                v.erase(v.begin()+i-1);
            }
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i];
    }
    
}

