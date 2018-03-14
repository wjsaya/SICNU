#include <stdio.h>
#include <math.h>


int issu(n) {
int i;
int checked=1;

if (n == 1)
    return(0);
for (i=2; i<=sqrt(n); i++) {
    if (n%i == 0)
        checked = 0;
}
    return(checked);
}

int main(void)  {
int i, N;  //正整数个数,<=10
int num[10];

scanf("%d", &N);
for (i=0; i<N; i++)    {
    scanf("%d", &num[i]);
}

for (i=0; i<N; i++) {
    if (issu(num[i]) == 0)
        printf("No\n");
    else
        printf("Yes\n");
    }

}
