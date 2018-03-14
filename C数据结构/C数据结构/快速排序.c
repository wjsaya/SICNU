#include <stdio.h>
#define MAXN 10

void sort(int a[], int n) {
   int i,j,min,temp;

   for (i=0; i<n; i++)   {
        min = i;  //取出起始下标
        for (j=min; j<n ;j++)
            if (a[j] <= a[min])
                min = j;
    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
   }
}

int main()
{
    int i, n;
    int a[MAXN];

    scanf("%d", &n);
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);

    sort(a, n);

    printf("After sorted the a is:");
    for( i = 0; i < n; i++ )
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
