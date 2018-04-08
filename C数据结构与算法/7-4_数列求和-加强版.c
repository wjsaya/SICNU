/*
给定两个均不超过9的正整数a和n，要求编写程序求a+aa+aaa++?+aa?a（n个a）之和。
输入格式：
输入在一行中给出不超过9的正整数a和n。
输出格式：
在一行中按照“s = 对应的和”的格式输出。
*/

#include<stdio.h> 
int main()
{
    int i,a,x;
    int b[100005];
    long long d = 0;
	scanf("%d %d", &a, &x);
	
	
    for(i=0;i<x;i++)
    {
        d += (x-i)*a;
        b[i]=d%10;
        d/=10;
    }
    if(d)
		printf("%d", d);
	//cout<<d;
    for(i=x-1;i>=0;i--)
		printf("%d", b[i]);
	
    if(x==0)
		printf("0");
}
