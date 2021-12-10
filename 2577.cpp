#include <iostream>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int a,b,c;
    cin >> a >> b>> c;
   
    int gop = a*b*c;
    int k[10] = {0};
    while(gop> 0)
    {
        k[gop%10]++;
        gop /=10;
    }
    for(int i=0; i<10; i++)
    {
        cout << k[i] << "\n";
    }
    
}
