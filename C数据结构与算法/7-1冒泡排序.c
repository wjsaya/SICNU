#include<stdio.h>

void sort(int n, int times, int l[])   {
    int i, j, temp;
    int time = 0;
    
    
    for (i=0; i<n; i++) 
    {
        if(time >= times)
        //满足给定次数,退
        	break;            
        for(j=0;j<n-1;j++)
        {//对比值 
            if(l[j] > l[j+1])   
            {
                temp = l[j];
                l[j] = l[j+1];
                l[j+1] = temp;
            }
        }
        time++;
    }
    
    

    
}

int main(void)  {
    int i, n, times;
    int lis[20];
    scanf("%d", &n);
    scanf("%d", &times);
    for(i=0; i<n; i++)  {
        scanf("%d", &lis[i]);
    }

    sort(n, times, lis);
	for (i=0; i<n-1; i++)
       	printf("%d#",lis[i]);
    printf("%d",lis[i]);
}
