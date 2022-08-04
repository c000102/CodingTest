/*
input :
3
2 2 5

4000
18 1 3 31 71 77 74 84 7 47 22 83 40 10 8 48 95 65 96 19 1 32 36 69 33 71 10 88 52 86 63 56 2 29

output:
13

2413410
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)5e3)
int N;
int A[MAXN + 10];

int comp(const void *a, const void *b)
{
    if (*(int *)a < *(int*)b) return -1;
    if (*(int *)a == *(int*)b) return 0;
    if (*(int *)a > *(int*)b) return 1;

    return 0;
}

void simpleSort(int s, int e)
{
    for (int i = s; i < s + 2; i++)
    {
        for (int j = i + 1; j <= e; j++)
        {
            if (A[i] > A[j])
            {
                int  tmpN = A[i];
                A[i] = A[j];
                A[j] = tmpN;
            }
        }
    }
}

int Solve(void)
{
    int sum=0;
    for (int i=0; i<N-1; i++)
    {
        //qsort(A+i, N-i, sizeof(A[0]), comp);
        simpleSort(i, N-1);
        A[i + 1] += A[i];
        sum += A[i+1];
    }
    return sum;
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}

int main()
{
    int ans = -1;
    InputData(); //입력

    ans = Solve();

    printf("%d\n", ans); //출력
    return 0;
}