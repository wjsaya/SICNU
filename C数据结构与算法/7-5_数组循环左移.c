#include<stdio.h>
void print(int li[], int end)
{
//    printf("print:%p,%d##\n",&li,end);
    int i;
    for(i=0;i<end-1;i++)
        printf("%d ",li[i]);
    printf("%d",li[i]);
}
void left(int list[],  int end, int times)
{
    int i,temp;
    int time_i;
    while(times > 0)
    {
    temp = list[0];
    for(i=0;i<end;i++)
    {
        list[i] = list[i+1];
    }
    list[i-1] = temp;
     //   print(&list[0], end);
    times--;
    }
}

int main(void)
{
    int i, n, times;
    int in[9999];
    int *p = in;
    scanf("%d %d", &n, &times);
    for(i=0;i<n;i++)
   //     in[i] = i+1;
      scanf("%d", &in[i]);
   
   left(p, n, times);
      print(&in[0], n);
    return 0;
}
