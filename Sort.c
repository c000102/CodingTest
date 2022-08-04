/*
input :
10
8 24 27 18 20 6 17 19 30 11

output:
6 8 11 17 18 19 20 24 27 30 -- 오름차순
30 27 24 20 19 18 17 11 8 6 -- 내림차순
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)5e3)
int N;
int A[MAXN + 10];

void simpleSort(int s, int e)
{
    for(int i=s; i<e; i++)
    {
        for(int j=i+1; j<=e; j++)
        {
#if 0
            if(A[i]>A[j]) // 오름차순
            {
                int tmpN = A[i];
                A[i] = A[j];
                A[j] = tmpN;
            }
#else
            if (A[i] < A[j]) // 내림차순
            {
                int tmpN = A[i];
                A[i] = A[j];
                A[j] = tmpN;
            }
#endif
        }
    }
}

int comp(const void *a, const void *b)
{
#if 0    
    return *(int *)a - *(int *)b; // 오름차순
#else
    return *(int *)b - *(int *)a; // 내림차순
#endif
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
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void)
{
    InputData(); //입력 받는 부분

    //simpleSort(0, N-1);
    qsort(A, N, sizeof(A[0]), comp);

    OutputData(); //출력 하는 부분
    return 0;
}