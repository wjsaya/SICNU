/*
给定两个均不超过9的正整数a和n，要求编写程序求a+aa+aaa++?+aa?a（n个a）之和。
输入格式：
输入在一行中给出不超过9的正整数a和n。
输出格式：
在一行中按照“s = 对应的和”的格式输出。
*/
#include<stdio.h>
long long get_each(long long time)
{

	long long i, sum=1;
	for(i=0;i<time;i++)
		sum *= 10;
	sum = sum/10;
	return sum;
}

int main(void)
{
	long long a, i, n, sum=0, each, sum_a=0;
	scanf("%lld %lld", &a, &n);
	
	for(i=1;i<=n;i++)
	{
		each = get_each(i);
		sum += each*a;
		sum_a += sum;
	}
	printf("%lld\n",sum_a);
	return 0;
}
