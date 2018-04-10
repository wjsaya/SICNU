#include<stdio.h>

int size(int *p) {
    int i=0, len=0;
    while(p[i] != '\0') {
        if(p[i] != -233)
            len++;
        i++;
        }
    return len;
}

int push(int *p, int X) {
    int last;
    last = size(p);
    p[last++] = X;
}

int isEmpty(int *p) {
    if(size(p) == 0)
        return 0;
    else
        return 1;
}

int pop(int *p) {
    int re;
    int i=0;
    while(p[i] != '\0') {
        if(p[i] != -233)
            break;
        i++;
    }
    re = p[i];
    p[i] = -233;
    return(re);
}

int main(void)
{
    int A[1000];
    int B[1000];

    int N;
    int temp;
    int i=0;
    scanf("%d", &N);

    while(i<N)
    {
        scanf("%d", &temp);
        if (temp % 2 == 0)
            push(B, temp);
        else
            push(A, temp);
       i++;
    }

    i=1;
    while(size(A)!=0 && size(B)!=0) {
        if(i == N-2)
            printf("%d", pop(A));
        else
            printf("%d ", pop(A));
        if(i % 2 == 0)
            if(i == N-2)
                printf("%d", pop(B));
            else
                printf("%d ", pop(B));
        i++;
    }
    while(size(A)!=0) {
        if(i == N-2)
            printf("%d", pop(A));
        else
            printf("%d ", pop(A));
        i++;
        }

    while(size(B)!=0) {
        if(i == N-2)
            printf("%d", pop(B));
        else
            printf("%d ", pop(B));

        i++;
        }

   return 0;
}
