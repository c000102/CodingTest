/*
첫 줄에 N이 주어진다.N은 주어지는 명령의 수이다.(1≤N≤10, 000)
둘째 줄부터 N + 1줄까지 N개의 명령이 주어지는데, 한 줄에 하나씩 주어진다.

각 명령에 대한 출력 값을 한 줄에 하나씩 출력한다. 출력내용이 하나도 없는 경우는 주어지지 않는다.
input :
7
1 7
1 5
2
0
0
0
2

output:
2
5
7
E
0
*/
#include <iostream>
    using namespace std;

#define MAXN ((int)1e4)
int N; //명령개수
int cmd[MAXN + 10];
int a[MAXN + 10];

int stk[MAXN + 10];
int sp;
void push(int d)
{
    stk[sp++] = d;
}
void pop()
{
    sp = --sp;
}
int top()
{
    return stk[sp - 1];
}
bool empty()
{
    return (sp == 0) ? 1 : 0;
}
int size()
{
    return sp;
}
void Solve()
{
    sp = 0; //초기화
    for (int i = 0; i < N; i++)
    {
        switch (cmd[i])
        {
        case 0: //읽고 제거
            if (empty())
            {
                cout << "E"
                     << "\n";
            }
            else
            {
                cout << top() << "\n";
                pop();
            }
            break;
        case 1: //저장
            push(a[i]);
            break;
        default: // 2 : 저장 개수
            cout << size() << "\n";
        }
    }
}
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd[i];
        if (cmd[i] == 1)
        {
            cin >> a[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();
    Solve();
    return 0;
}