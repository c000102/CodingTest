/*
input :
5
3
1
10
7
4

output:
4
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e3)
int N;            //연잎수
int A[MAXN + 10]; //연잎좌표

int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int SolveN3()
{
    int cnt = 0;

    qsort(A, N, sizeof(A[0]), comp);

    for(int a=0; a<N-2; a++)
    {
        for(int b=a+1; b<N-1; b++)
        {
            int fist = A[b] - A[a];
            for(int c=b+1; c<N; c++)
            {
                int second = A[c] - A[b];
                //if ((fist <= second) && (second <= 2*fist)) cnt++;
                if(second < fist) continue;
                if(second >= 2*fist) break;
                cnt++;
            }
        }
    }
    return cnt;
}

int bslow(int s, int e, int d)
{
    int sol = -1;
    while (s<= e)
    {
        int m=(s+e)/2;
        if(A[m] >= d)
        {
            sol = m;
            e=m-1;
        }
        else
        {
            s=m+1;
        }
    }
    return sol;
}

int bsup(int s, int e, int d)
{
    int sol = -1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (A[m] <= d)
        {
            sol = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return sol;
}

int Solve()
{
    int cnt = 0;

    qsort(A, N, sizeof(A[0]), comp);

    for (int a = 0; a < N - 2; a++)
    {
        for (int b = a + 1; b < N - 1; b++)
        {
            int first = A[b] - A[a];
            int low = bslow(0, N-1, A[b]+first);
            if (low < 0) break;
            cnt += bsup(0, N-1, A[b]+2*first) - low + 1;
        }
    }
    return cnt;
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}
int main(void)
{
    int ans = -1;
    InputData(); //입력받는부분

   // ans = SolveN3();
    ans = Solve();

    printf("%d\n", ans); //출력하는부분
    return 0;
}
