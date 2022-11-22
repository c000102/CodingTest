/*
다음 명령을 처리하기 위한 큐 함수를 구현하시오.
주어진 명령은 다음의 3가지 이다.
1. "1 a"는 a라는 수를 큐에 넣는다. 이때, a는 10,000 이하의 자연수이다.
2. "0"는 큐에서 데이터를 빼고, 그 데이터를 출력한다. 만약 큐가 비어있으면, "E"를 출력한다.
3. "2"는 큐에 쌓여있는 데이터의 수를 출력한다.
C++의 queue class member functions과 유사한 기능을 하는 아래 함수를 구현하시오

int empyt(void) - 1:empty, non-empty:0
int size(void) - 저장 개수
int front(void) - 제일 먼저 저장되 값, 삭제하지 않음
void push(int d) - 저장
void pop(void) - front를 삭제
문제: 큐를 구현하시오

첫 줄에 N이 주어진다. N은 주어지는 명령의 수이다. (1≤N≤10,000)
둘째 줄부터 N+1줄까지 N개의 명령이 주어지는데, 한 줄에 하나씩 주어진다.
input :
7
1 7
1 5
2
0
0
0
2

각 명령에 대한 출력 값을 한 줄에 하나씩 출력한다. 출력내용이 하나도 없는 경우는 주어지지 않는다.
output:
2
7
5
E
0
*/

#include <stdio.h>
#define MAXN ((int)1e4)
int N; //명령개수
int cmd[MAXN + 10];
int a[MAXN + 10];

int que[MAXN + 10];
int wp, rp;

void push(int d)
{
    a[wp++] = d;
}
void pop(void)
{
    rp++;
}
int front(void)
{
    return a[rp];
}
int empty(void)
{
    return (rp == wp);
}
int size(void)
{
    return wp - rp;
}
void Solve(void)
{
    wp = rp = 0; //초기화
    for (int i = 0; i < N; i++)
    {
        switch (cmd[i])
        {
        case 0: //읽고 제거
            if (empty())
            {
                printf("E\n");
            }
            else
            {
                printf("%d\n", front());
                pop();
            }
            break;
        case 1: //저장
            push(a[i]);
            break;
        default: // 2 : 저장 개수
            printf("%d\n", size());
        }
    }
}
void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &cmd[i]);
        if (cmd[i] == 1)
        {
            scanf("%d", &a[i]);
        }
    }
}
int main(void)
{
    InputData();

    printf("\n");
    Solve();
    return 0;
}