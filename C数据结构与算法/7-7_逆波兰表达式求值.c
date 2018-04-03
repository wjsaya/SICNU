#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int MAXSIZE = 1000;
int t;                      //栈顶指针
int S[1000];

void pushin(int x)
//入栈
{
    S[++t] = x;
}

int get()
{
    return S[t--];
}

int pop()

int isEmpty()
{
    return t == 0;
}


int main(void)
{
    int a1, a2;
    t = 0;
    char input[100];
    scanf("%s", input);
    while(t != 0)
    {
        if(input[0] == '+')
        {
            a1 = get();
            a2 = get();
            pushin(a1+a2);
        }
        else if(input[0] == '+')
        {
            a1 = get();
            a2 = get();
            pushin(a1+a2);
        }
        else if(input[0] == '+')
        {
            a1 = get();
            a2 = get();
            pushin(a1+a2);
        }
        
        else
            pushin(atoi(input));
    }

    printf("%d",get());
    return 0;
}
