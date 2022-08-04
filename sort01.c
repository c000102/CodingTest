/*
input :
8
2 4 7 8 8 9 4 3

output:
2 3 4 4
*/

#include <stdio.h>
#define MAXN ((int)3e4)
int N;
int A[MAXN + 10];

void simpleSort(int s, int e)
{
    for (int i = s; i < 4; i++)
    {
        for (int j = i + 1; j <= e; j++)
        {
            if(A[i]>A[j])
            {
                int tmpN = A[i];
                A[i] = A[j];
                A[j] = tmpN;
            }
        }
    }
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}

void OutputData(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void)
{
    InputData(); //입력 받는 부분

    simpleSort(0, N-1);

    OutputData(); //출력 하는 부분
    return 0;
}