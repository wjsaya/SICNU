#include<stdio.h>

void sort(int n, int *list)
{
	int i, j, k, temp, max=0, max_x;
	//i从0-n,j从0-n取最小 
	for(i=0;i<n;i++)
	{
	//	printf("\n");
	//	printf("i=%d->%d\t\t\t",i,list[i]);
	//	for(k=0;k<n;k++)
	//		printf("%d ", list[k]);

		max = list[i];
		
		for(j=i;j<n;j++)
		{
			if(max <= list[j])
			{
				max = list[j];
				max_x = j;
			}
		}
	//	printf("\t\tmax=%d",list[max_x]);
		temp = list[i];
		list[i] = list[max_x];
		list[max_x] = temp;
	}
	
}

int main(void)
{
	int n, i;
	int in[10];
	
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &in[i]);
	
	
	sort(n, in);
	
	for (i=0; i<n-1; i++)
       	printf("%d ",in[i]);
    printf("%d",in[i]);
	
	
	return 0;
} 
