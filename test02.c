/*
input :
6
3
2
6
1
1
2

output:
3
3
0
6
6
0
*/

#include <stdio.h>
#define MAXN ((int)1e5)
int N;              //빌딩수
int H[MAXN + 10];   //빌딩높이
int sol[MAXN + 10]; //각 빌딩에서 보이는 빌딩 번호

// Stack
int sk[MAXN + 10];
int sp;

void push(int d)
{
    sk[sp++] = d;
}

void pop(void)
{
    --sp;
}

int top()
{
    return sk[sp - 1];
}

int empty()
{
    return sp == 0;
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &H[i]);
    }
}
void OutputData(void)
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", sol[i]);
    }
}

void SolveN2()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            if(H[i]<H[j])
            {
                sol[i] = j;
                break;
            }
        }
    }
}

void Solve()
{
    sp=0;
    for(int i=1; i<=N; i++)
    {
        while (!empty() &&(H[top()] < H[i]))
        {
            sol[top()] = i;
            pop();
        }
        push(i);
    }
}

int main(void)
{
    InputData(); //입력받는 부분

    //SolveN2();
    Solve();

    printf("\n");
    OutputData(); //출력하는 부분
    return 0;
}