#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXLEN 64

void pr(int in[MAXLEN][MAXLEN], int len)
{
//	输出方阵内容 
    int x, y;
        printf("\n{\n");
    for(x=0; x<len; x++)
    {
        for(y=0; y<len; y++)
        {
//        printf("\n(%d, %d) \t%d\t|\t%d", x, y, in[x][y], *((int*)in + len*x + y));
            printf("%5d,", in[x][y]);
        }
        printf("\n");
    }
        printf("}");
}


void split(int a[MAXLEN][MAXLEN], int A11[MAXLEN][MAXLEN], int A12[MAXLEN][MAXLEN], int A21[MAXLEN][MAXLEN], int A22[MAXLEN][MAXLEN], int lena) {
//	大方阵分割为四部分 
		int newlen = lena / 2;
		int i, j;
                for(i=0; i<newlen; i++) {
                        for(j=0; j<newlen; j++) {
                                    if((i <= newlen) && (j <= newlen)) 
                                            A11[i][j] = a[i][j];
                                    }
                        }
                
                
                for(i=0; i<newlen; i++) {
                        for(j=newlen; j<lena; j++) {
//                        	printf("i=%d, j=%d\n", i, j);
                                            A12[i][j-newlen] = a[i][j];
                                    }
                        }
                        
                for(i=newlen; i<lena; i++) {
                        for(j=0; j<newlen; j++) {
//                        	printf("i=%d, j=%d\n", i, j);
                                            A21[i-newlen][j] = a[i][j];
                                    }
                        }
                
                for(i=newlen; i<lena; i++) {
                        for(j=newlen; j<lena; j++) {
//                        	printf("i=%d, j=%d\n", i, j);
                                            A22[i-newlen][j-newlen] = a[i][j];
                                    }
                        }
}


void multiply(int re[MAXLEN][MAXLEN], int A[MAXLEN][MAXLEN], int B[MAXLEN][MAXLEN]) {
/*
2阶方阵求乘积 
a[00] b[01]			e[00] f[01]
c[10] d[11]			g[10] h[11]

ae+bg[00]			af+bh[01]
ce+dg[10]			cf+dh[11]
*/
	re[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	re[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	re[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	re[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}


void add(int re[MAXLEN][MAXLEN], int A[MAXLEN][MAXLEN], int B[MAXLEN][MAXLEN], int len) {
/*
两个2阶方阵求和 
a[00] b[01]			e[00] f[01]
c[10] d[11]			g[10] h[11]

a+e[00]			b+f[01]
c+g[10]			d+h[11]
*/
	int i, j;
	for(i=0; i<len; i++) {
		for(j=0; j<len; j++) {
			re[i][j] = A[i][j] + B[i][j]; 
		}
	}
	/*
	re[0][0] = A[0][0] + B[0][0];
	re[0][1] = A[0][1] + B[0][1];
	re[1][0] = A[1][0] + B[1][0];
	re[1][1] = A[1][1] + B[1][1];
	*/	
}


void stubid(int c[MAXLEN][MAXLEN], int A[MAXLEN][MAXLEN], int B[MAXLEN][MAXLEN], int len) {
//	手算 
    int x, y, z;
        for(x=0; x<len; x++)
        {
            for(z=0; z<len; z++)
            {
                c[x][z]=0;
                for(y=0; y<len; y++)
                {
                    c[x][z] += A[x][y] * B[y][z];
                }
            }
        }
}
			
	

void merge(int re[MAXLEN][MAXLEN], int C11[MAXLEN][MAXLEN], int C12[MAXLEN][MAXLEN], int C21[MAXLEN][MAXLEN], int C22[MAXLEN][MAXLEN], int len) {
/*
合并C11, C12, C21, C22到c 
a[00] b[01]
c[10] d[11]

ad - bc
*/

		int newlen = len / 2;
		int i, j;
                for(i=0; i<newlen; i++) {
                        for(j=0; j<newlen; j++) {
                                    if((i <= newlen) && (j <= newlen)) 
                                            re[i][j] = C11[i][j];
                                    }
                        }
                
                
                for(i=0; i<newlen; i++) {
                        for(j=newlen; j<len; j++) {
//                        	printf("i=%d, j=%d\n", i, j);
                                            re[i][j] = C12[i][j-newlen];
                                    }
                        }
                        
                for(i=newlen; i<len; i++) {
                        for(j=0; j<newlen; j++) {
//                        	printf("i=%d, j=%d\n", i, j);
                                            re[i][j] = C21[i-newlen][j];
                                    }
                        }
                
                for(i=newlen; i<len; i++) {
                        for(j=newlen; j<len; j++) {
//                        	printf("i=%d, j=%d\n", i, j);
                                            re[i][j] = C22[i-newlen][j-newlen];
                                    }
                        }
}
					
								
void matrix(int c[MAXLEN][MAXLEN], int a[MAXLEN][MAXLEN], int b[MAXLEN][MAXLEN], int lena) {
//	C = A * B
        int i, j;
//        printf("\nlena = %d, lena = %d\n", lena, lena);
        
        if ((lena <= 2) || (lena <= 2)) {
//        	小于等于2时，直接把两个矩阵相乘即可 
//                pr(a, lena);
//                pr(b, lena);
				multiply(c, a, b);
        }
        
        else {
//        	长度大于2， 分割AB，递归求乘积 
                int newi=0, newj=0;
                int newlen = lena / 2;
                int A11[MAXLEN][MAXLEN];
                int A12[MAXLEN][MAXLEN];
                int A21[MAXLEN][MAXLEN];
                int A22[MAXLEN][MAXLEN];
                
                int B11[MAXLEN][MAXLEN];
                int B12[MAXLEN][MAXLEN];
                int B21[MAXLEN][MAXLEN];
                int B22[MAXLEN][MAXLEN];
                
                int C11[MAXLEN][MAXLEN];
                int C12[MAXLEN][MAXLEN];
                int C21[MAXLEN][MAXLEN];
                int C22[MAXLEN][MAXLEN];
                
                split(a, A11, A12, A21, A22, lena);
                split(b, B11, B12, B21, B22, lena);
                
                int SUM_TEMP1[MAXLEN][MAXLEN];
                int SUM_TEMP2[MAXLEN][MAXLEN];
                    
                matrix(SUM_TEMP1, A11, B11, newlen);
                matrix(SUM_TEMP2, A12, B21, newlen);
                add(C11, SUM_TEMP1, SUM_TEMP2, newlen);
                        
                            
//				memset(SUM_TEMP1, 0, sizeof(SUM_TEMP1));
//				memset(SUM_TEMP2, 0, sizeof(SUM_TEMP2));
//				现在矩阵不一定小于2，不能直接加？？？ 
                            
                    matrix(SUM_TEMP1, A11, B12, newlen);
                    matrix(SUM_TEMP2, A12, B22, newlen);
                    add(C12, SUM_TEMP1, SUM_TEMP2, newlen);
                            
                    matrix(SUM_TEMP1, A21, B11, newlen);
                    matrix(SUM_TEMP2, A22, B21, newlen);
                    add(C21, SUM_TEMP1, SUM_TEMP2, newlen);
                            
                    matrix(SUM_TEMP1, A21, B12, newlen);
                    matrix(SUM_TEMP2, A22, B22, newlen);
                    add(C22, SUM_TEMP1, SUM_TEMP2, newlen);		
//
//				printf("C11 = ");
//				pr(C11, newlen);
//				printf("C12 = ");
//				pr(C12, newlen);
//				printf("C21 = ");
//				pr(C21, newlen);
//				printf("C22 = ");
//				pr(C22, newlen);	

				merge(c, C11, C12, C21, C22, lena);
//				pr(c, lena);
        }

}

int main(void)
{
    int i, j;
    int a[MAXLEN][MAXLEN];
    int b[MAXLEN][MAXLEN];
    int c[MAXLEN][MAXLEN];
    int len;
    printf("输入矩阵尺寸：");
    scanf("%d", &len);
    for(i=0; i<len; i++) {
    	for(j=0; j<len; j++) {
    		a[i][j] = rand() % 10;
    		b[i][j] = rand() % 10;
		}
	}
        matrix(c, a, b, len);
//        pr(a, len);
//        pr(b, len);
        pr(c, len);
        
        stubid(c, a, b, len);
        pr(c, len);
    
        return 0;
}



