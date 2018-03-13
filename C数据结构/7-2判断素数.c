#include<stdio.h>

void issu(n) {
int i;
for (i=1; i<n; i++) {
    if (n%i == 0) 
        printf("No\n");
    } 
   //# else
   //#     printf("Yes\n");

}

int main(void)  {
int i, N;  //正整数个数,<=10
int num[10];

scanf("%d", &N);
for (i=0; i<N; i++)    {
    scanf("%d", &num[i]);
}

for (i=0; i<N; i++) {
    //printf("%d\n", num[i]);
    issu(num[i]);
    }

}
