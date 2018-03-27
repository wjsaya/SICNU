#include<stdio.h>
int main(void)
{
    int i=0, j;
    int line;
    for(line = 1; line <=6; line+=2)
    {
        for(j=line;j<=5;j++)
        {
            i = i+j;
            printf("%d ", i);
        }
        i = 0;
        printf("\n");
    }



    return 0;
}
