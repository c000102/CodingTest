/*
input :
8
70 30 70 40 60 50 90 80

output:
7 8 1
*/

#include <stdio.h>
#define MAXN ((int)3e4)
int N; //자료 개수
struct ST
{
    int id, score; //아이디, 점수
};
struct ST A[MAXN + 10]; //자료

void simpleSort(int s, int e)
{
    for (int i = s; i < s+3; i++)
    {
        for (int j = i + 1; j <= e; j++)
        {
            if ((A[i].score < A[j].score) || ((A[i].score == A[j].score) && (A[i].id > A[j].id)))
            {
                struct ST tmpN = A[i];
                A[i] = A[j];
                A[j] = tmpN;
            }
        }
    }
}

int comd(const void *a, const void *b)
{
    struct ST *x = (sturct ST *)a;
    struct ST *y = (sturct ST *)b;

    if (x->score == y->score) return x->id - y->id;
    return y->id - x->id;
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i].score);
        A[i].id = i + 1;
    }
}

void OutputData(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", A[i].id);
    }
    printf("\n");
}

int main(void)
{
    InputData(); //입력
    simpleSort(0, N-1);
    //qsrt(A, N, sizeof(A[0]));
    OutputData();
    return 0;
}