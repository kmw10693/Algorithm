#include <bits/stdc++.h>
using namespace std;

char t[60] = "";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for(int i=0; i<s.length(); i++){
        t[i+1] = s[i];
    }
    t[s.size()+1] = 'e';

    bool b = false;
    for(int i=1; i<s.size()+2; i++){
        
        // -를 처음 만난경우 판단한다.
        if(t[i] == '-') {
            b = true;
        }
        // +를 만나고 b가 true일 경우에 -로 변환한다.
        if(t[i] == '+' && b == true) {
            t[i] = '-';
        }
    }

    int sum = 0;
    int p[5] = {1,10,100,1000,10000};
    char ba = '+';
    
    for(int i=1; i<s.size()+2; i++){
        int a = -1;
        int k = i;
        while(t[k] != '-' && t[k] != '+' && t[k] != 'e'){
            a++;
            k++;
        }
        
        while(t[i] != '-' && t[i] != '+' && t[i] != 'e') {
            if(ba == '+') sum += ((t[i] - '0') * p[a--]);
            else sum -= ((t[i] - '0') * p[a--]);
            i++;
        }
        ba = t[i];

    }
    cout << sum;
}
