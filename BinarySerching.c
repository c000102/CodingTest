/*
input :
7
2 4 9 10 14 23 32
3
6 23 9

output:
0
6
3
*/

#include <stdio.h>
#define MAXN ((int)5e4)
#define MAXT ((int)1e4)
int N;
int A[MAXN + 10];
int T;
int B[MAXT + 10];

int BinarySearch(int s, int e, int d)
{
    while (s<=e)
    {
        int m=(s+e)/2;
        if(A[m]==d) { return m; }
        else if(A[m] > d) { e = m-1; }
        else { s = m+1; }
    }
    
    return 0;
}

void Solve(void)
{
    for(int i=0; i<T; i++)
    {
        B[i] = BinarySearch(1, N, B[i]);
    }
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &B[i]);
    }
}
void OutputData(void)
{
    for (int i = 0; i < T; i++)
    {
        printf("%d\n", B[i]);
    }
}
int main(void)
{
    InputData(); // 입력받는 부분

    Solve();
    printf("\n");
    OutputData(); // 출력하는 부분
    return 0;
}