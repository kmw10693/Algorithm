#include <bits/stdc++.h>

using namespace std;

int N;

void _bar(const char* str, int stk)
{
    for(int i=0; i<stk; i++)
    {
        cout << "____";
    }
    cout << str << "\n";
}
void solve(int cnt)
{
    _bar("\"����Լ��� ������?\"", cnt);
    if(cnt == N)
    {
        _bar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"", cnt);
    }
    else
    {
        _bar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.", cnt);
        _bar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.", cnt);
        _bar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"", cnt);
        solve(cnt+1);
    }
    _bar("��� �亯�Ͽ���.", cnt);
}
    
int main()
{
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    solve(0);
    
}
    

