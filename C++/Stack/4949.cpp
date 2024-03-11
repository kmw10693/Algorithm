#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string t;
        getline(cin, t);
        if (t == ".")
            break;

        stack <char> s;
        int check = 1; // check가 1이면 yes 0이면 no

        for (auto i : t)
        {
            if (i == '[' || i == '(')
                s.push(i);
            if (i == ']')
            {
                if (!s.empty())
                {
                    if(s.top() == '[')
                        s.pop();
                    else
                    {
                        check = 0;
                        break;
                    }
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            else if (i == ')')
            {
                if (!s.empty())
                {
                    if(s.top() == '(')
                        s.pop();
                    else
                    {
                        check =0;
                        break;
                    }
                }
                else
                {
                    check = 0;
                    break;
                }

            }
        }
        if(!s.empty())
            check =0;
            
        if (check == 1)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";


    }


}

