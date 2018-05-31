#include<stdio.h>
void quicksort(int a[], int left, int right) 
{ 
    int i, j, t, temp; 
    if(left > right) 
       return; 
    temp=a[left]; //temp中存的就是基准数 
    i = left; 
    j = right; 
    while(i != j) 
    {
        while(a[j] >= temp && i<j)             //右向左找第一个小于基准数的下标，且i<j
            j--; 
        while(a[i] <= temp && i<j)             //左向右找第一个大于基准数的下标，且i<j
            i++; 
        if(i <= j)                              //i,j相遇，交换对应值
        { 
            t = a[i]; 
            a[i] = a[j]; 
            a[j] = t; 
        } 
    } 
    a[left] = a[i];                                        //基准数重置
    a[i] = temp; 
    quicksort(a, left, i-1);//继续处理左边的，这里是一个递归的过程 
    quicksort(a, i+1, right);//继续处理右边的 ，这里是一个递归的过程 
} 

void p(int q[], int a,int e)
{
    int i;
    for(i=1;i<=e-a;i++)
        printf("%d ",q[i]);
    printf("%d", q[i]);
    printf("\n");
}

int main(void)
{
    int arr[100000];
    int i, N;
    scanf("%d", &N);
    for(i=1;i<=N;i++)
        scanf("%d", &arr[i]); 

    quicksort(arr, 1, N); //快速排序调用 
    p(arr, 1, N);

}






