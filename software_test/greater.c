// asdasd.cpp : 定义控制台应用程序的入口点。

#include "stdio.h"
#include <math.h>

void get(int n, int m) {
    int c[6];

    c[0]++;
    printf("%d和%d的最大公约数是：",n,m);
    int i;
    int temp,gcd;
    if(m==0 ) gcd=n;
        c[1]++;
        
    if(n==0) gcd=m;
        c[2]++;

    if(m!=0&&n!=0){
        c[3]++;
            if(m>n){
            c[4]++;
                temp=n;
                n=m;
                m=temp;
            }
            while(m!=0){
            c[5]++;
                temp=n%m;
                n=m;
                m=temp;
            }
            gcd=n;
    }
    printf("\t\t%d\t",gcd);
    for(i=0; i<6; i++)
        printf("%d\t", c[i]);
    printf("\n");
}

int main(void){
        int i;
        int a[6] = {729, 15, 3501, 4, 5, 0};
        int b[6] = {99, 21, 225, 6, 0, 3};
        //scanf("%d %d",&n,&m);
        for(i=0; i<6; i++)
                get(a[i], b[i]);
}

