/*
input :
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1

output:
1
2
5
*/

#include <stdio.h>
#define MAXN (100)
int N, M;         //문서수, 궁금한 문서 번호
int P[MAXN + 10]; //문서 우선순위

struct QUE
{
    int n, p;
};
struct QUE que[MAXN*MAXN];

int wp, rp;

void push(int n, int p)
{
    que[wp].n=n;
    que[wp].p=p;
    wp++;
}

void pop(void)
{
    rp++;
}

struct QUE front(void)3
{
    return que[rp];
}

int empty(void)
{
    return (rp == wp);
}

int Solve(void)
{
    int seq = 0;
    //0. 초기화
    int priocnt[10] = {0}; //우선순위 별 개수
    wp = rp = 0;

    //1. 우선순위 별 개수 파악, 큐에 저장
    for(int i=0; i<N; i++)
    {
        priocnt[P[i]]++;
        push(i, P[i]);
    }

    //2. 시뮬레이션
    for(int p=9; p>=1; p--)
    {
        while (priocnt[p])
        {
            struct QUE cur = front();
            pop();
            if(cur.p == p)// 인쇄
            {
                seq++;
                if (cur.n == M) return seq; // 궁금한 문서임, 성공
                priocnt[p]--;// 인쇄 했으므로 감소
            }
            else// 가장 높은 우선순위 아니므로 큐에 다시 저장
            {
                push(cur.n, cur.p);
            }
            
        }
    }
    return -1;
}

void InputData(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }
}

int main(void)
{
    int ans = -1;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        InputData(); //입력받는 부분

        ans = Solve();

        printf("%d\n", ans); //출력하는 부분
    }
    return 0;
}