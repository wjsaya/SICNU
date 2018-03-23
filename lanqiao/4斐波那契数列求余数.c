#include<stdio.h>
int main() {
    /*
  Fn=Fn-1+Fn-2，其中F1=F2=1。


  



  1
  1
  2
  3
  5
  8
  13
  21
  34
  55
 
 ( f(n-1) + f(n-2)) / mod;
  */
long i, n;
long last;
long a=1,b=1,c;
scanf("%d", &n);
if(n<3)
    printf("%d\n",n);
else
{
    for(i=2;i<n;++i)
    {
        c = (a+b)% 10007;
        a = b;
        b = c;
    }
    printf("%d\n", c);
}
return 0;
}

