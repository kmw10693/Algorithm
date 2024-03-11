#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    

    int T;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        string P;
        cin >> P;
        int n;
        cin >> n;
        string a;
        cin >> a;
        string tmp;
        int m = 0;
        
        deque <int> q;
        for(int j=1; j<a.length(); j++)
        {
            if(a[j] == ',' || a[j] == ']')
            {
            
                tmp[m] =a[j];
                if(m!=0)
                    q.push_back(stoi(tmp));
                m=0;
                
            }
            else
            {
                tmp[m++] = a[j];
            }
        }
        int rev = 0;// rev 나머지가 1이면 뒤집고, 0이면 뒤집 x
        int checkErr = 0;
        for(int j=0; j<P.length(); j++)
        {
            if(P[j] == 'R')
            {
               rev++;
            }
            else if(P[j] == 'D')
            {
                if(q.empty())
                {
                    cout << "error";
                    checkErr =1;
                    break;
                }
                else
                {
                    if(rev % 2 == 1)
                    {
                        q.pop_back();
                    }
                    
                    else if(rev % 2 == 0)
                    {
                        q.pop_front();
                    }
                }
            }
            
            
        }
        if(rev%2 == 1 && checkErr == 0)
        {
            cout<<"[";
            for(int i=q.size()-1; i>=0; i--)
            {
                if(i == 0)
                {
                    cout << q[i];
                    break;
                }
                cout << q[i] << ",";
            }
            cout << "]";
        }
        else if(rev %2 == 0 && checkErr == 0)
        {
            cout << "[";
            for(int i=0; i<q.size(); i++)
            {
                if(i == q.size()-1)
                {
                    cout << q[i];
                    break;
                }
                cout << q[i] << ",";
            }
            cout << "]";
        }
        cout << "\n";
    
    }
}
