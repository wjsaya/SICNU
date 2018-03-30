/*
给定两个均不超过9的正整数a和n，要求编写程序求a+aa+aaa++?+aa?a（n个a）之和。
输入格式：
输入在一行中给出不超过9的正整数a和n。
输出格式：
在一行中按照“s = 对应的和”的格式输出。
*/
#include<stdio.h>
int get_each(int time,int value)
{
	int i,sum=1;
	//printf("time=%d,value=%d\n",time,value);
	for(i=0;i<time;i++)
		sum *= 10;
	sum = sum/10;
	//printf("\n");
	return sum;
}
int main(void)
{
	int a, n, i, sum=0, each,sum_a=0;
	scanf("%d %d", &a, &n);
	
	for(i=1;i<=n;i++)
	{
		each = get_each(i, a);
		sum += each*a;
		sum_a += sum;
	}
	printf("s = %d\n",sum_a);
	return 0;
}
