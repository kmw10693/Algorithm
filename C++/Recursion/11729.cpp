#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int to, int bypass) // start = 1, to = 3, bypass =2
{
    if(n == 1)
    {
        printf("%d %d\n", start, to);
    }
    else
    {
        hanoi(n-1, start, bypass, to);
        printf("%d %d\n",start, to);
        hanoi(n-1, bypass, to, start);
    }
}

int main()
{
    int k;
    cin >> k;
    cout << (1<<k) -1<<"\n";
    hanoi(k, 1,3,2);
}
