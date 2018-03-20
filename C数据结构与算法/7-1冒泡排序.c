#include<stdio.h>

void sort(int n, int times, int l[])   {
    int i, j, temp;
    int time = 0;
    for (i=0; i<n; i++) 
    {
        if(time >= times)
            break;
        for(j=0;j<n-i;j++)  
        {
            if(l[j] > l[j+1])   
            {
                temp = l[j];
                l[j] = l[j+1];
                l[j+1] = temp;
            }
        }
        time++;
    }
    for (i=0; i<n; i++)
        printf("%d ",l[i]);
    printf("\n");
}

int main(void)  {
    int i, n, times;
    int lis[20];
    scanf("%d", &n);
    scanf("%d", &times);
    for(i=0; i<n; i++)  {
        scanf("%d", &lis[i]);
    }
    for (i=0; i<n; i++)
        printf("%d ",lis[i]);
    printf("\n---------------------------------------\n");

    sort(n, times, lis);
}
