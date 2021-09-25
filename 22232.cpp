#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(pair<string, int>a, pair<string, int> b)   //compare 함수 선언, pair를 사용하였으므로 pair를 매개변수로 전달.
{

    size_t pos = a.first.find('.');    // string의 rfind 함수를 이용하여 마지막으로 나타나는 문자의 위치를 반환한다.
    size_t pos1 = b.first.find('.');   // string의 rfind 함수를 이용하여 마지막 문자의 위치를 반환한다.

    if (a.first.substr(0, pos) == b.first.substr(0, pos1)) // string의 substr(0~pos-1)까지를 잘라내서, 파일명이 같다면
    {
        if (a.second == b.second)   // OS에 확장자에 존재 여부가 같다면
        {
            return a.first.substr(pos + 1) < b.first.substr(pos + 1);   //파일 확장자를 오름차순으로 정렬
        }
        else if (a.second < b.second)   // (0 1) 
            return b.second > a.second; // set 함수에 존재하는 확장자가 내림차순으로 정렬
        else if (a.second > b.second)
            return a.second > b.second; 
    }
    else
    {
        return a.first < b.first;   // 두 파일명이 같지 않다면, 파일명을 오름차순으로 정렬
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<string> check;  // set 컨테이너를 이용하여 확장자를 저장한다.

    vector<pair<string, int>> k;    // (파일, OS에 확장자에 존재 여부)를 저장할 vector 선언
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        k.push_back(make_pair(t, 0));   // vector에 (파일, OS에 확장자 존재 여부) 저장

    }
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        check.insert(t);    // set 컨테이너에 string(확장자) 저장
    }

    for (int i = 0; i < n; i++)
    {
        size_t pos = k[i].first.find('.'); // 벡터 k[i]의 first 값(파일)에 string의 rfind 함수를 이용하여 마지막으로 나타나는 문자의 위치 반환
        string a = k[i].first.substr(pos + 1);  //string의 substr을 이용하여 pos+1 ~ 마지막 문자까지 string을 자른다.

        auto iter = check.find(a);  // set 컨테이너의 find 함수를 이용하여 확장자가 set 컨테이너에 존재 여부를 확인한다.
        if (iter != check.end())    // set.find()함수는 원소 a를 가리키는 반복자를 반환하고, a가 없다면 s.end()를 반환한다.
            k[i].second = 1;    //vector 두번째 변수(os에 확장자 존재 여부에 존재를 표시한다)
    }
    sort(k.begin(), k.end(), compare);  //sort 함수 사용
    for (int i = 0; i < n; i++)
    {
        cout << k[i].first << "\n";
    }
}