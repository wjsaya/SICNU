#include<stdio.h>
#define MAXSIZE 30
int main()
{
    int i;
    char sh[MAXSIZE], sz[MAXSIZE];
    char in;
    scanf("%c", &in);
    for(i = 0; ; i++)
    {
        if(in == ' ')
            break;
        sh[i] = in;
        scanf("%c", &in);
    }

    for(i=0; ;i++)
    {
        if(in == '\n')
            break;
        sz[i] = in;
        scanf("%c", &in);
    }

    for(i = 0;; i++)
    {
        if(sh[i] == ' ')
            break;
        printf("|%c", sh[i]);
    }
    return 0;
}
