#include<stdio.h>
#include <stdlib.h>
// 大数乘法
// https://blog.csdn.net/u010983881/article/details/77503519

int a2i(char in) {
    return in - 48;
}

int getlen(char in[]) {
    int count=0;
    while(in[count] != '\0')
        count++;
    return count;
}

int a2ilist(char in[], int out[]) {
// convert char list(in) to int list(out)
    int i;
    int temp;
    int lenin = getlen(in);
    for(i=0; i<lenin; i++)
        out[lenin - i - 1] =  a2i(in[i]);
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
    char multiplier[] = {"12345"};
    char factor[] = {"123"};
    int intmult[99];
    int intfac[99];
    int temp[99][99];
    int re[99];
    int i, j;
    int lenmult = getlen(multiplier);
    int lenfac = getlen(factor);

    a2ilist(multiplier, intmult);
    a2ilist(factor, intfac);

    for(i=lenfac-1; i>=0; i--)  { // loop on factor
        for(j=0; j<lenmult; j++)  { // loop on multiplier
            temp[i][j] = intmult[j]*intfac[i]; // get result
          //  printf("[%d, %d]\t", i, j);
          //  printf("%d*%d=%d\n", intmult[j], intfac[i], temp[i][j]);
        }
    }

    for(i=lenfac-1; i>=0; i--)
        for(j=lenmult-1; j>=0; j--)
            re[i+j] = 0; // init re list

    for(i=lenfac-1; i>=0; i--) {
        for(j=lenmult-1; j>=0; j--) {
            re[i+j] += temp[i][j]; 
            //printf("[%d, %d]\t%d\n", i, j, re[i+j]);
        }
    }

    for(i=0; i<9;i++) {
        if(re[i] >=10) {
            re[i+1] += re[i]/10;
            re[i] = re[i]%10;
            }
    }

    
    
    i=(lenmult+lenfac);
    while(1)
    {
        if(re[i] != 0)
            break;
        i--;
    }

    for(; i>=0; i--) // from low to high
    {
            printf("%d", re[i]);
    }
}





