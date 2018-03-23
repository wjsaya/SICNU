#include<stdio.h>
int main(void) 
{
  int list[100000];
  int i, n, last;
  list[0] = 1;
  list[1] = 1;
  
  scanf("%d", &n);
  if(n<3)
    printf("%d\n",n);
   
else    {
  for(i=2; i<n; i++)
          list[i] = (list[i-1] + list[i-2]) % 10007;
  
    printf("%d\n", list[n]);
}
   return 0;
}
