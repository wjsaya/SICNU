#include <stdio.h>
#define MAXN 10
int get_max_1(int n, int l[]) {
//穷举法，复杂度为N^3(3个for)
    int i,j,k;
    int this_sum = 0, max_sum = 0;
    for(i=0 ; i<n; i++)    
    {
        for(j=0; j<n; j++) 
        {
            this_sum = 0;
            for(k=i; k<j; k++)
                this_sum += l[k];
            if (this_sum > max_sum)
                max_sum = this_sum;
        }
    }
    return max_sum;
}

int get_max_2(int n, int l[]) {
//穷举法升级版，复杂度为N^2(2个for)
    int i,j,k;
    int this_sum = 0, max_sum = 0;
    for(i=0 ; i<n; i++)    
    {
        this_sum = 0;
        for(j=i; j<n; j++) 
        {
            this_sum += l[j];
            if (this_sum > max_sum)
                max_sum = this_sum;
        }
    }
    return max_sum;
}

int get_max_3(int n, int l[])   {
    int i;
    int this_sum = 0, max_sum = 0;
    for(i=0; i<n; i++)
    {
        this_sum += l[i];
        if (this_sum > max_sum)
            max_sum = this_sum;
        else if (this_sum < 0)
            this_sum = 0;
    }
    return(max_sum);
}

int main()
{
    int i, n;
    int l[MAXN];
    
    scanf("%d", &n);
    if(n >= MAXN)
        return 0;
    for( i=0; i<n; i++ )
        scanf("%d", &l[i]);
    printf("%d\n",get_max_3(n, l));

    return 0;
}
