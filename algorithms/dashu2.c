#include<stdio.h>
#define toint(X)  (X - '0')
// ´óÊý³Ë·¨
// https://blog.csdn.net/u010983881/article/details/77503519
// http://www.cnblogs.com/king-ding/p/bigIntegerMul.html

int getlen(char in[]) {
    int count=0;
    while(in[count] != '\0')
        count++;
    return count;
}

void muti(char *mult, char *fact) {
//	printf("%c, %c", mult[0], fact[0]);
	int lenMult = getlen(mult);
	int lenFact = getlen(fact);
	char *a;
	int asd=0;
	
	memcpy(a, mult, lenMult/2);
	
    	printf("%d|", toint(a[asd]));
    
}

int main(void) {
    char multiplier[] = {"12345678"};
    char factor[] = {"12345678"};
    muti(multiplier, factor);
    
}





