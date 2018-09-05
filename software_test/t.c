#include "stdio.h"
#include <math.h>


void main() {
    int m, n, temp, gcd;
    int count[]={0,0,0,0,0,0,0,0,0,0,0,0};
    scanf("%d %d", & n, & m);
    printf("%d和%d的最大公约数是：", n, m);
    count[0]++;
    if (m == 0) gcd = n,count[1]++;
    if (n == 0) gcd = m,count[2]++;
    if (m != 0 && n != 0) {
        count[3]++;
        if (m > n) {
            count[4]++;
            temp = n;
            n = m;
            m = temp;
        }
        while (m != 0) {
            count[5]++;
            temp = n % m;
            n = m;
            m = temp;
        }
        gcd = n;
    }
    printf("%d\n",gcd);
    int i;
    for(i=0;i<=5;i++)
    {
        printf("第%d个计数器的统计值为：%d\n", i, count[i]);
    }
}

