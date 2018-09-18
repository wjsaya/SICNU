#include<stdio.h>
#include<math.h>
#define MAXLEN 20

void pr(int **in, int ii) {
        int i, j;
         
        printf("******************************************\n");
        for (i=0; i<ii; i++) {
                for(j=0; j<ii; j++) {
                        printf("%d\t",  *((int*)in + ii*i + j));
                }
                printf("\n");
        }
        printf("******************************************\n");
}


void matrix(int *a, int **b, int lena, int lenb) {
        int i, j;
        printf("\nlena = %d, lenb = %d\n", lena, lenb);
        
        if ((lena <= 2) || (lenb <= 2)) {
                pr(a, lena);
                pr(b, lenb);
        }
        
        else {
                int newi=0, newj=0;
                int newlen = lena / 2;
                int A1[MAXLEN][MAXLEN];
                int B1[MAXLEN][MAXLEN];
                int C1[MAXLEN][MAXLEN];
                int D1[MAXLEN][MAXLEN];
                int A2[MAXLEN][MAXLEN];
                int B2[MAXLEN][MAXLEN];
                int C2[MAXLEN][MAXLEN];
                int D2[MAXLEN][MAXLEN];
                
                /*
                for(i=0; i<lena; i++) {
                        for(j=0; j<lena; j++) {
                                if ((i <= newlen) && (j <= newlen))
                                        A1[i][j] = *((int*)a + lena*i + j);

                                else if ((i <= newlen) && (j > newlen))
                                        B1[i][j] = *((int*)a + lena*i + j);

                                else if ((i >= newlen) && (j <= newlen))
                                        C1[i][j] = *((int*)a + lena*i + j);

                                else
                                        D1[i][j] = *((int*)a + lena*i + j);
                        }
                }*/
                
                
                /*
                for(i=0; i<lena; i++) {
                        for(j=0; j<lena; j++) {
                                if ((i <= newlen) && (j <= newlen))
                                        A1[newi][newj] = *((int*)a + lena*i + j);

                                else if ((i <= newlen) && (j > newlen))
                                        B1[newi][newj] = *((int*)a + lena*i + j);

                                else if ((i >= newlen) && (j <= newlen))
                                        C1[newi][newj] = *((int*)a + lena*i + j);

                                else
                                        D1[newi][newj] = *((int*)a + lena*i + j);
                        }
                }*/
                
                for(i=0; i<lena; i++, newi++) {
                        for(j=0; j<lena; j++, newj++) {
                                if (i <= newlen) {
                                        if(j <= newlen)
                                                A1[newi][newj] = *((int*)a + lena*i + j);
                                        
                                        if(j > newlen)
                                                B1[newi][newj] = *((int*)a + lena*i + j);
                                        newj++;
                                }
                        newi++;
                        }
                }
                
                
                pr(A1, newlen);
                pr(B1, newlen);

                pr(C1, newlen);
                pr(D1, newlen);
                pr(a, lena);

                /*
                for(i=0; i<lena; i++) {
                        for(j=0; j<lena; j++) {
                                printf(" %d", A1[i][j]);
                        }
                                printf("\n");
                }*/





        }

}

int main(void)
{
        /*
        int a[2][2] = {
                                        {1, 2},
                                        {3, 4}
                                        };
        int b[2][2] = {
                                        {5, 6},
                                        {7, 8}
                                        };
        */
        
        int a[4][4] = {
                                        {1, 2, 3, 4},
                                        {3, 4, 5, 6},
                                        {5, 6, 7, 8},
                                        {8, 9, 10, 11}
                                        };
        int b[4][4] = {
                                        {8, 9, 10, 11},
                                        {5, 6, 7, 8},
                                        {3, 4, 5, 6},
                                        {1, 2, 3, 4}
                                        };
        
//      pr(a, 2, 2);

        matrix(a, b, sqrt(sizeof(a) / sizeof(int)), sqrt(sizeof(b) / sizeof(int)));


        return 0;
}



