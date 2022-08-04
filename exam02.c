/*
승훈이는 심심한 시간에 스타크래프트(Starcraft) 게임을 하며 놀고 있었다.
스타크래프트유닛중 하나인 저글링을 한 곳에 몰아세운 뒤, 방사능 오염 공격으로 없애보려고 했다.
그런데 좀 더 재미있게 게임을 하기 위해서 게임을 개조하여 방사능 오염 공격을 가하면 방사능은 1초마다 이웃한 저글링에 오염된다.
그리고 방사능에 오염된 저글링은 3초 후에 죽게 된다.
예를 들어 아래 왼쪽그림과 같이 모여 있는 저글링 중에 빨간 동그라미 표시를 한 저글링에게 방사능 오염공격을 가하면,
총 9초 후에 저글링들이 죽게 된다. 아래 오른쪽에 있는 그림의 숫자들은 각 저글링들이 죽는 시간이다.
input:
7 8
0010000
0011000
0001100
1011111
1111011
0011100
0011100
0001000
3 5
==
첫째 줄은 지도의 가로 세로 크기가 주어진다. 지도는 격자 구조로 이루어져 있으며 크기는 100×100칸을 넘지 않는다.
둘째 줄부터는 지도상에 저글링들이 놓여있는 상황이 주어진다. 1은 저글링이 있는 곳의 표시이고 0은 없는 곳이다.
마지막 줄에는 방사능오염을 가하는 위치가 가로 세로 위치로 주어진다.
주의 사항으로, 좌표는 좌측상단이 가장 작은 위치이며 이 위치의 좌표는 (1,1)이다.
==
죽을 수 있는 저글링들이 모두 죽을 때까지 몇 초가 걸리는지 첫 번째 줄에 출력하고 둘째 줄에는 죽지 않고 남아 있게 되는 저글링의 수를 출력하시오.
output:
9
0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN (100)
int W, H;                       //지도의 가로 세로 크기
char map[MAXN + 10][MAXN + 10]; //지도 정보('1':저글링, '0':빈곳)
int sw, sh;                     //시작위치 가로 세로 좌표
int soltime, solzergling;

char visit[MAXN + 10][MAXN + 10];
int sol[MAXN * MAXN + 10];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int rp = 0, wp = 0;
struct QUE
{
    int y;
    int x;
    int second;
};

struct QUE que[MAXN * MAXN + 10];
void push(int y, int x, int second)
{
    visit[y][x] = '2';
    que[wp].x = x;
    que[wp].y = y;
    que[wp].second = second;
    wp++;
}

void pop(void) { rp++; }
struct QUE front() { return que[rp]; }
int empty(void) { return wp == rp; }
int size(void) { return wp - rp; }

void InputData(void)
{
    scanf("%d %d", &W, &H);
    for (int i = 1; i <= H; i++)
    {
        scanf("%s", &map[i][1]);
    }
    scanf("%d %d", &sw, &sh);
}

int BSF()
{
    struct QUE curr = {};
    while (!empty())
    {
        curr = front();
        pop();
        soltime = curr.second;
        for (int i = 0; i < 4; i++)
        {
            int ndy = curr.y + dy[i];
            int ndx = curr.x + dx[i];
            if (visit[ndy][ndx] == '2' || visit[ndy][ndx] == '0' || map[ndy][ndx] == '0' ||
                ndy <= 0 || ndx <= 0 || ndy > H || ndx > W)
                continue;
            push(ndy, ndx, curr.second + 1);
        }
    }
    return curr.second;
}
void Solve(void)
{
    wp = rp = 0;
    solzergling = 0, soltime = 0;
    memcpy(visit, map, sizeof(map));

    push(sh, sw, 3);

    soltime = BSF();

    for (int y = 1; y <= H; y++)
    {
        for (int x = 1; x <= W; x++)
        {
            if (visit[y][x] == '2' || visit[y][x] == '0' || map[y][x] == '0')
                continue;
            solzergling++;
        }
    }
}

int main(void)
{
    InputData(); //입력 받는 부분
                 
    Solve(); //여기서부터 작성

    printf("%d\n%d\n", soltime, solzergling);
    return 0;
}
