#include<stdio.h>
int N;
int i=0;
int count=0;
int arrH[30], arrZ[30], arrC[30];

int getlen(int *p)
{
    int len=0;
    int i=0;
    while(p[i++]!='\0')
        len++;
    return len;
}

void sort(int *pH, int *pZ)
{
//传入后序和中序的排列，取出当前根。分两部分递归
//后序直接去尾
//中序稍微麻烦点
    int arrH[30], arrZ[30];
    arrC[count++] = pH[getlen(pH)-1];    //层序结果
    printf("root=%d\n", arrC[count-1]);

    for(i=0; i<N; i++) {
        if(arrC[count-1] == pZ[i])
        {
            break;
        }
        arrZ[i] = pZ[i];
    }
    for(; i<getlen(pH)-1; i++)
        arrZ[i] = pZ[i+1];

    for(i=0; i<getlen(pH)-1; i++)
        arrH[i] = pH[i];
    
    sort(arrH, arrZ);
/*
 * for(i=0; i<N; i++)
        printf("len(pH)=%d\tZ=%d\tH=%d\n",getlen(pH)-1, arrZ[i], arrH[i]);
        */
}

int main(void)
{
    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d", &arrH[i]);

    for(i=0; i<N; i++)
        scanf("%d", &arrZ[i]);

    sort(arrH, arrZ);
//    getlen(arrH);
    return 0;

/*
    for(i=0; i<N; i++)
    {
        if(arrZ[i] == arrC[0])
            break;
        printf("%d ", arrZ[i]);
    }
    printf("\n");
    for(;i<N; i++)
        printf("%d ", arrZ[i]);
*/
}

