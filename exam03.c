/*
입력 파일의 첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다.
세로와 가로의 길이는 최대 100이다. 판의 각 가로줄의 모양이 윗줄부터 차례로 입력 파일의 둘째 줄부터 마지막 줄까지 주어진다.
치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어 지며 각 숫자 사이에는 빈칸이 하나씩 있다.
input:
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0

첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출력하고,
둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다
output:
3
5
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXN (100)
int W, H;           //블록의 가로, 세로 길이
int N;              //상점 수
int Dir[MAXN + 10]; //상점및 동근이 위치한 방향(1:북, 2:남, 3:서, 4:동)
int Len[MAXN + 10]; //북남: 왼쪽에서 거리, 서동:위쪽에 거리
void InputData(void)
{
    scanf("%d %d", &W, &H);
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
    {
        scanf("%d %d", &Dir[i], &Len[i]);
    }
}
enum eDIR
{
    NORTH = 1,
    SOUTH = 2,
    WEST = 3,
    EAST = 4
};

int DistFromSouthTo(int i)
{
    int dist = 0;
    int s_dir = Dir[N];
    int s_len = Len[N];
    int e_dir = Dir[i];
    int e_len = Len[i];
    int distLeft = 0;
    int distRight = 0;

    switch (e_dir)
    {
    case NORTH:
        distLeft = H + s_len + e_len;
        distRight = H + (2 * W) - (s_len + e_len);
        dist = (distLeft < distRight) ? distLeft : distRight;
        break;
    case SOUTH:
        dist = abs(e_len - s_len);
        break;
    case WEST:
        dist = (H - e_len) + s_len;
        break;
    case EAST:
        dist = (H - e_len) + (W - s_len);
        break;
    }
    return dist;
}

int DistFromNorthTo(int i)
{
    int dist = 0;
    int s_dir = Dir[N];
    int s_len = Len[N];
    int e_dir = Dir[i];
    int e_len = Len[i];
    int distLeft = 0;
    int distRight = 0;

    switch (e_dir)
    {
    case NORTH:
        dist = abs(e_len - s_len);
        break;
    case SOUTH:
        distLeft = H + s_len + e_len;
        distRight = H + (2 * W) - (s_len + e_len);
        dist = (distLeft < distRight) ? distLeft : distRight;
        break;
    case WEST:
        dist = s_len + e_len;
        break;
    case EAST:
        dist = (W - s_len) + e_len;
        break;
    }
    return dist;
};

int DistFromEastTo(int i)
{
    int dist = 0;
    int s_dir = Dir[N];
    int s_len = Len[N];
    int e_dir = Dir[i];
    int e_len = Len[i];
    int distTop = 0;
    int distBottom = 0;

    switch (e_dir)
    {
    case NORTH:
        dist = s_len + (W - e_len);
        break;
    case SOUTH:
        dist = (H - s_len) + (W - e_len);
        break;
    case WEST:
        distTop = W + e_len + s_len;
        distBottom = W + (2 * H) - (s_len + e_len);
        dist = (distTop < distBottom) ? distTop : distBottom;
        break;
    case EAST:
        dist = abs(s_len - e_len);
        break;
    }
    return dist;
}

int DistFromWestTo(int i)
{
    int dist = 0;
    int s_dir = Dir[N];
    int s_len = Len[N];
    int e_dir = Dir[i];
    int e_len = Len[i];
    int distTop = 0;
    int distBottom = 0;

    switch (e_dir)
    {
    case NORTH:
        dist = s_len + e_len;
        break;
    case SOUTH:
        dist = (H - s_len) + e_len;
        break;
    case WEST:
        dist = abs(s_len - e_len);
        break;
    case EAST:
        distTop = W + s_len + e_len;
        distBottom = W + (2 * H) - (s_len + e_len);
        dist = (distTop < distBottom) ? distTop : distBottom;
        break;
    }
    return dist;
}
int solve()
{
    int dist = 0;
    int s_dir = Dir[N];
    for (int i = 0; i < N; i++)
    {
        switch (s_dir)
        {
        case NORTH:
            dist += DistFromNorthTo(i);
            break;
        case SOUTH:
            dist += DistFromSouthTo(i);
            break;
        case WEST:
            dist += DistFromWestTo(i);
            break;
        case EAST:
            dist += DistFromEastTo(i);
            break;
        }
    }
    return dist;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    ans = solve(); // 여기서부터 작성

    printf("%d\n", ans); // 출력하는 부분
    // system("pause");
    return 0;
}
