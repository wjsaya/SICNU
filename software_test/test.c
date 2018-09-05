#include<stdio.h>
int main(void)  {
char ch[] = "145678";
int i;

for(i=0; i<6; i++) {
int n = ch[i] - 48;
printf("%d, %d\n", n, ch);
}

}
