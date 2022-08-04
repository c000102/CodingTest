/*
사칙연산 수식을 입력 받아 그 수식의 결과를 출력하는 프로그램을 작성하시오.
수식은 수와 +, -, *, /의 연산자로 구성되어 있으며 각 수는 10 이하의 양의 정수이다.
나눗셈의 처리결과는 몫만을 취하도록 한다.

첫 줄에 정수의 개수 N이 입력으로 주어진다.
둘째 줄에는 N개의 정수 M과 연산자로 구성 된 수식이 주어진다. 정수와 연산자 사이에는 공백이 하나 주어진다. (1≤ N ≤20, 1≤ M ≤10 , 연산자 - +, -, *, / )

수식의 연산결과를 출력한다.

input :
4
1 - 4 * 9 + 10

output:
-25
*/

#include <stdio.h>
#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];

//Stack
int sk[MAX+10];
int sp;

void push(int d)
{
    sk[sp++] = d;
}

void pop(void)
{
    --sp;
}

int top()
{
    return sk[sp-1];
}

int empty()
{
    return sp == 0;
}

int Slove()
{
    int sol = 0,d;
    push(M[0]);

    for(int i=1; i<N; i++)
    {
        switch (op[i])
        {
        case '+':
            push(M[i]);
            break;
        case '-':
            push(-M[i]);
            break;
        case '*':
            d = top() * M[i];
            pop();
            push(d);
            break;
        case '/':
            d = top() / M[i];
            pop();
            push(d);
            break;
        }
    }

    while(!empty())
    {
        sol += top();
        pop();
    }
    
    return sol;
}

void InputData(void)
{
    scanf("%d", &N);
    scanf("%d", &M[0]);
    for (int i = 1; i < N; i++)
    {
        scanf(" %c %d", &op[i], &M[i]);
    }
}

int main(void)
{
    int ans = -1;
    InputData(); //입력

    ans = Slove();

    printf("%d\n", ans);

    return 0;
}