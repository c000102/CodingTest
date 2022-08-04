/*
당신은 H행, W열의 크기를 가진 행렬을 가지고 있고, 행렬은 1과 0의 세포로 이루어져 있다. 여기서 수직이든 수평이든 대각선 방향이든 인접한 두 개의 세포를 연결되어 있다고 표현하는데, 세포가 1인 것들은 서로 연결되어 하나의 구역을 이룬다.
행렬에는 몇 개의 구역이 있는데, 행렬에서 크기가 가장 큰 구역을 이루는 세포 1의 개수는 얼마인가?

가장 첫 줄에는 행의 크기인 H(0<H<10)을 입력 받고, 두 번째 줄에는 열 크기인 W(0<W<10)을 입력 받는다. 다음으로는 실제 행렬을 입력 받는데, 행렬은 숫자들로 이루어져 있다.

가장 큰 구역의 세포 1의 개수를 출력하라.

input:
4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0

output:
5

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN (10)
int H, W; //행, 열 크기
int map[MAXN + 10][MAXN + 10];
int sol[MAXN * MAXN + 10];

int dy[] = {-1, -1, -1,
            0, 0, 0,
            1, 1, 1};
int dx[] = {-1, 0, 1,
            -1, 0, 1,
            -1, 0, 1};

int rp = 0, wp = 0;
struct QUE
{
    int y;
    int x;
};
struct QUE que[MAXN * MAXN + 10];
void push(int y, int x)
{
    map[y][x] = -1;
    que[wp].x = x;
    que[wp].y = y;
    wp++;
}

void pop(void) 
{ 
    rp++;
}

struct QUE front()
{ 
    return que[rp];
}

int empty(void)
{
    return wp == rp;
}

void InputData(void)
{
    scanf("%d", &H);
    scanf("%d", &W);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

int FloodFill(int y, int x)
{
    int homeSz = 0;
    wp = rp = 0;
    push(y, x);
    homeSz++;
    while (!empty())
    {
        struct QUE curr = front();
        pop();

        for (int i = 0; i < 9; i++)
        {
            int ndy = curr.y + dy[i];
            int ndx = curr.x + dx[i];
            if (map[ndy][ndx] != 1) continue;
            push(ndy, ndx);
            homeSz++;
        }
    }
    return homeSz;
}

int comp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int Solve(void)
{
    int homeID = 0;
    int homeSz = 0;

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (map[y][x] != 1)
                continue;
            sol[homeID] = FloodFill(y, x);
            homeID++;
        }
    }
    qsort((void *)sol, homeID, sizeof(sol[0]), comp);
    return sol[0];
}

int main(void)
{
    int ans = -1;
    InputData(); // 입력받는 부분

    ans = Solve(); // 여기서부터 작성

    printf("\n");
    printf("%d\n", ans); // 출력하는 부분
    return 0;
}
