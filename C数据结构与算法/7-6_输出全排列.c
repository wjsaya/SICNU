#include<stdio.h>

void pp(int *p, int end)
//输出当前数组的顺序，end为属于长度
{
    int i;
        for(i=0;i<end;i++)
             printf("%d",p[i]);
      printf("\n");
}

void swap(int *a, int *b)
//交换a,b
{  
    int temp;  
  
    temp = *a;  
    *a = *b;  
    *b = temp;
}

void print(int *li, int start, int end)
//递归调用，输出全排列
{
    int i, j;
    int lis[end];
    for(i=0;i<end;i++)
        lis[i] = li[i];
    if(start >= end)
         pp(lis, end);
   
    else
    {
        i = start;
        for(j=start;j<end;j++)
        {
            sort(&lis, j, end);
            swap(&lis[i], &lis[j]);
            print(&lis, start+1, end);
            swap(&lis[j], &lis[i]);
        }
    }
}


void sort(int a[], int s, int n) {
    //指定a中，s-n之间的数据进行快速排序，从小到大
   int i,j,min,temp;
   for (i=s; i<n; i++)   {
        min = i;  //取出起始下标
        for (j=min; j<n ;j++)
            if (a[j] <= a[min])
                min = j;
    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
   }
}


int main(void)
{
    int list[9];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        list[i] = i+1;
        print(&list, 0, n);
    return 0;
}
