/*
input :
4

output:
3 1 2 4
*/

#include <stdio.h>
#define MAXN (100)
int N;
int sol[MAXN + 10];

int wp, rp;
int que[MAXN * MAXN + 10];

void push(int d){
    que[wp++] = d;
}

void pop(void){
    rp++;
}

int front(void){
    return que[rp];
}

int back(void){
    return que[wp-1];
}

int empty(void){
    return (rp == wp);
}

int size(void){
    return wp - rp;
}

void Solve(void)
{
    int k=0;
    wp = rp = 0;
    for(int i=1; i<=N; i++)
    {
        push(i);
    }

    for(int i=0; i<N-1; i++)
    {
        int cnt = back() / 2;
        for(int j=0; j<cnt; j++)
        {
            int r=front();
            pop();
            push(r);
        }
        sol[k++] = front();
        pop();
    }
    sol[k++] = front();
    pop();
}

void InputData(void)
{
    scanf("%d", &N);
}
void OutputData(void)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", sol[i]);
    }
}
int main(void)
{
    InputData(); //입력

    Solve();
    
    OutputData(); //출력
    return 0;
}