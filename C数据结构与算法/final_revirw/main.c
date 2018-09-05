#include<stdio.h>
#include<stdlib.h>

typedef struct linkNode *PtrToNode;
typedef PtrToNode linkList;
struct linkNode 
{
    int Data;
    linkList Next;
};

int get_len(linkList L)
{
        int count=0;
        if(L == NULL) 
                return 0;

        while(L)
        {
                printf("%d\n", L->Data);
                L = L->Next;
                count++;
        }
        return count;
}


PtrToNode create(linkList L, int a, int b)
{
        PtrToNode re = L;
        int i;
        for(i=a; i<b; i++)
        {
                printf("开始插入%d\n", i);
                PtrToNode temp = NULL;
                temp = ( PtrToNode )malloc(sizeof(PtrToNode));
                temp->Data = i;
                temp->Next = NULL;
                L->Next = temp;
                L = L->Next;
        }
//      return re;
}

int main(void)
{
        int a;
        PtrToNode p = NULL;
        p->Data = 0;
        p->Next = NULL;
        create(p, 1, 5);
//      a = get_len(p);
//      printf("length=%d\n\n", a);

        system("pause");
    return 0;
}
