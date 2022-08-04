/*
input :
4
120 110 140 150
485

output:
127
*/

#include <stdio.h>
#define MAXN ((int)1e4)
int N, M;
int A[MAXN + 10];
void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
}

int isPossible(int m)
{
    int sum=M;
    for(int i=0; i<N; i++)
    {
        if(A[i]>m) sum -=m;
        else sum -= A[i];
        if( sum < 0) return 0;
    }
    return 1;
}

int Solve(void)
{
    int s =0, e=0, sol=0;
    for(int  i=0; i<N; i++)
    {
        if(e<A[i]) e = A[i];
    }

    while (s <= e)
    {
        int m = (s+e)/2;
        if(isPossible(m) == 1)
        {
            sol = m; s=m+1;
        }
        else
        {
            e=m-1;
        }
        
    }
    return sol;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}