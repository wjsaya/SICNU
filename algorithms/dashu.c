#include<stdio.h>
#include <stdlib.h>
// 大数乘法
// https://blog.csdn.net/u010983881/article/details/77503519

int a2i(char in) {
    // convert ascii to integer.
    return in - 48;
}

int getlen(char in[]) {
// get length of char list.
    int count=0;
    while(in[count] != '\0')
        count++;
    return count;
}

void a2ilist(char in[], int out[]) {
// convert char list(in) to int list(out)
    int i;
    int temp;
    int lenin = getlen(in);
    for(i=0; i<lenin; i++)
        out[lenin - i - 1] =  a2i(in[i]);
}

void multiplication(int intmult[], int intfac[],  int lenmult, int lenfac, int re[])
{

    int temp[99][99];

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
}

int main(void) {
    char multiplier[] = {"56345"};  // 被乘数
    char factor[] = {"123"};        // 乘数
    int intmult[99];
    int intfac[99];
    int re[99];

    int lenmult = getlen(multiplier);
    int lenfac = getlen(factor);

    a2ilist(multiplier, intmult);
    a2ilist(factor, intfac);

    multiplication(intmult, intfac, lenmult, lenfac, re);

    for(i=(lenmult + lenfac); i>=0; i--) // from low to high
    {
            printf("%d", re[i]);
    }
}




