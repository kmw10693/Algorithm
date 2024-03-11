#include <iostream>
#include <vector>

using namespace std;

vector <int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j=0;
    for(int i=1; i< patternSize; i++)
    {
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
        
    }
    return table;
}
vector<int> KMP(string parent, string pattern)
{
    vector <int> ans;
    vector <int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j=0;
    for(int i=0; i<parentSize; i++)
    {
        while(j>0 && parent[i] != pattern[j])
        {
            j = table[j-1];
        }
        if(parent[i] == pattern[j])
        {
            if(j == patternSize-1)
            {
                    ans.push_back(i-patternSize+2);
                    j = table[j];    
            }
            else
                j++;
            
        }
    }
    return ans;
}
int main()
{
    string s, p;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);
    getline(cin, p);
    vector<int> result = KMP(s, p);
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
    
