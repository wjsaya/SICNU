#include<stdio.h>
#include <stdlib.h>
// 大数乘法
// https://blog.csdn.net/u010983881/article/details/77503519

int ascii2int(char in) {
    return in - 48;
}

/*
        9  8
×       2  1
-------------
       (9)(8)  <---- 第1趟: 98×1的每一位结果 
  (18)(16)     <---- 第2趟: 98×2的每一位结果 
-------------
  (18)(25)(8)  <---- 这里就是相对位的和，还没有累加进位 
*/
int main(void) {
    char in1[] = {"789652"};
    char in2[] = {"3211"};
    int i;

    for(i=0; i<6; i++)
        printf("%d |", ascii2int(in1[i]));
}
