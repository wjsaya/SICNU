#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */


List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()  
{  
  int len = 0;
  int num = 0;
  PtrToNode list = NULL;
  PtrToNode last = NULL;

  scanf( "%d",&len );
  if(  len == 0  )
    return NULL;

  scanf( "%d",&num );
  list = ( PtrToNode )malloc( sizeof( struct Node ) );
  list->Data = num;
  list->Next = NULL;
  last = list;
  len--;
  while(  len ){
    scanf( "%d",&num );
    PtrToNode node = ( PtrToNode )malloc( sizeof( struct Node ) );
    node->Data = num;
    node->Next = NULL;
    last->Next = node;
    last = node;
    len--;
  }
  return list;
}  
void Print( List L )  
{  
    if(L==NULL)  
    return ;  
    while(L!=NULL){  
        printf("%d ",L->Data);  
        L=L->Next;  
    }  
    putchar('\n');  
}  


/* 你的代码将被嵌在这里 */
List Reverse( List L )  
{  
    if(L == NULL)  
        return NULL;  

    PtrToNode temp = NULL, new = NULL;
    while(L != NULL)  
    {  
        temp = L->Next;  
        L->Next = new;  
        new = L;  
        L = temp;  
    }  
    return new;  
}  
