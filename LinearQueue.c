/*
문제: 큐를 구현하시오


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