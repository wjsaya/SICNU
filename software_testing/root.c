// asdasd.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include "stdio.h"
#include <math.h>
#include "stdio.h"
#include "math.h"

void get(float a, float b, float c) {
        double delta,x1=0.0,x2=0.0;
//      scanf("%.2f%.2f%.2f",&a,&b,&c);
        printf("%.2f,%.2f,%.2f\t",a,b,c);
        if(a==0.0 && b==0.0){
                        printf("本方程没有实根！\n");
                }
        if(a==0.0 && b!=0.0){
                        x1=c/b*(-1);
                        printf("方程只有一个实根：%.2f\n",x1);
                }
        delta=b*b - 4*a*c;
        //printf("%.2f",delta);
        if(a!=0){
                if(delta>0.0){
                        x1=(b*(-1)+sqrt(delta))/(2.0*a);
                        x2=(b*(-1)-sqrt(delta))/(2.0*a);
                        printf("方程有两个不同实根，分别是：%.2f,%.2f\n",x1,x2);
                }
                if(delta==0.0){
                        x1=(b*(-1)+sqrt(delta))/(2.0*a);
                        printf("方程只有一个实根：%.2f\n",x1);
                }
                if(delta<0.0){
                        printf("本方程没有实根！\n");
                }
        }
}

int  main(void){
        float a[6] = {1, 1, 1, 1, 0, 0};
        float b[6] = {-4, -3, 0, 15, 0, 2};
        float c[6] = {4, 2, 1, 54, 4, -10};
        int i;
        for(i=0; i<6; i++)      {
                get(a[i], b[i], c[i]);
        }
}

