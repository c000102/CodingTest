/*
input:
8 7
1 2 7 5
11111111
00000111
10110011
10111001
10111101
10000001
11111111

output:
9

ex)
8 10
1 1 7 9
00000101
11001000
10000010
01101010
00000110
01010000
01110110
10000100
10011101
01000001
--> 16

5 5
1 1 5 5
00000
01101
00100
01110
00000
--> 8

*/

#include <stdio.h>
#include <string.h>
#define MAXN (100)
int W, H;                       //가로, 세로 크기
int sw, sh, ew, eh;             //출발 가로세로, 도착 가로세로 좌표
char map[MAXN + 10][MAXN + 10]; //지도정보

int visited[MAXN+10][MAXN+10];
struct QUE
{
    int h, w, t;
};

struct QUE que[MAXN*MAXN+10];
int wp, rp;

void push(int h, int w, int t)
{
    if(map[h][w] != '0') return;
    if(visited[h][w]) return;
    visited[h][w]=1;
    que[wp].h=h; que[wp].w=w; que[wp].t=t; wp++;
}

void pop(void)
{
    rp++;
}

struct QUE front(void)
{
    return que[rp];
};

int empty(void)
{
    return wp == rp;
}

int BFS(void)
{
    int dh[] = {-1, 1, 0, 0};
    int dw[] = {0, 0, 1, -1};
    //.0 초기화
    memset(visited, 0, sizeof(visited));
    wp=rp=0;
    //1. 시작위치 큐 저장
    push(sh, sw, 0);
    //2. 반복문
    while (!empty())
    {
        struct QUE cur = front(); pop();
        if((cur.h==eh)&&(cur.w==ew))return cur.t;
        for(int i=0; i<4; i++)
        {
            push(cur.h+dh[i], cur.w+dw[i], cur.t+1);
        }
        
    }
    
    //3. 실패
    return -1;
}

void InputData(void)
{
    scanf("%d %d", &W, &H);
    scanf("%d %d %d %d", &sw, &sh, &ew, &eh);
    for (int i = 1; i <= H; i++)
    {
        scanf("%s", &map[i][1]);
    }
}

int main(void)
{
    int ans = -1;
    InputData(); //입력

   ans = BFS();

    printf("%d\n", ans); //출력
    return 0;
}
