/*
input :
10
1 1 1 6 9 11 13 17 19 20
2
1 9

output:
3 1
*/

#include <stdio.h>
#define MAX ((int)2e5)
int N;
int A[MAX + 10];
int M;
int B[MAX + 10];

int BinarySerchLower(int s, int e, int d)
{
    int sol = -1;
    while (s <= e)
    {
        int m = (s+e)/2;
       
        if(A[m] == d)
        {
            sol = m;
            e = m -1;
        }
        else if(A[m] > d)
        {
            e = m -1;
        }
        else
        {
            s = m+1;
        }
 
    }
   return sol; 
}

int BinarySerchUpper(int s, int e, int d)
{
    int sol = -1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (A[m] == d)
        {
            sol = m;
            s = m + 1;
        }
        else if (A[m] > d)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return sol;
}

void Solve(void)
{
    for(int i=0; i<M; i++)
    {
        int lower = BinarySerchLower(0, N-1, B[i]);
        if(lower != -1)
        {
            int upper = BinarySerchUpper(0, N-1, B[i]);
            B[i] = upper - lower + 1;
        }
        else
        {
            B[i] = 0;
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
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }
}

void OutputData(void)
{
    for (int i = 0; i < M; i++)
    {
        printf("%d ", B[i]);
    }
}

int main(void)
{
    // 입력받는 부분
    InputData();

    Solve();
    
    // 출력하는 부분
    OutputData();
    return 0;
}