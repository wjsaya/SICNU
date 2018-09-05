#include<stdio.h>

void print(int arr[], int num)
{
    int i;
    for(i=0;i<num;i++)
        printf("%d\t", arr[i]);
    printf("\n");
}


void select_sort(int arr[], int num)
{
    int i, j, tag, temp;
    for(i=0; i<num; i++)
    {
        tag = i;
        for(j=i; j<num; j++)
        {
            if(arr[j] <= arr[tag])
                tag = j;
        }
        temp = arr[tag];
        arr[tag] = arr[i];
        arr[i] = temp;
    }
}

void quick_sort(int arr[], int left, int right)
{
    int i = left, j = right;
    int temp, tag = arr[left];
    if(left >= right)
        return;
    
    while(i < j)
    {
        while(i < j && arr[j] >= tag)
            j--;
        while(i < j && arr[i] <= tag)
            i++;
        if( i < j )
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[i];
    arr[i] = tag;

    quick_sort(arr, left, i-1);
    quick_sort(arr, i+1, right);
}

int main(void)
{
    int i, N;
    int arr[10] = {9, 6, -5, 0, 1, 2, 3, -5, 9, 8};
    printf("输入数字个数: ");
    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d", &arr[i]);

    printf("before sort\n");
    print(arr, N);


    select_sort(arr, N);
    //quick_sort(arr, 0, N);
    
    
    printf("\n\nafter sort\n");
    print(arr, N);
    
    return 0;
}
