#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );


void print(List L) {
    while(L->Next) {
    //    printf("%d=%d | ", L->Next, L->Next->Data);
        printf("%d| ", L->Next->Data);
        L = L->Next;
    }
    puts("");
}



int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
    flag = Insert(L, X, NULL);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);     
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */

List MakeEmpty() 
        {
        List newin;
        newin = (List)malloc(sizeof(List));
        newin->Data = 0;
        newin->Next = NULL;
        return newin;
        }


bool Insert( List L, ElementType X, Position P ) 
        {
        List in;
        in = (List)malloc(sizeof(List));
        in->Next = NULL;
        
                while(L) 
                {
                        if (L->Next == P)
                        {
                                in->Data = X;
                                in->Next = P;
                                L->Next = in;
                                return true;
                        }
                        L = L->Next;
                }
     
       if (L!= P)
                {
          printf("Wrong Position for Insertion\n");
          return false;
                }
        }


Position Find( List L, ElementType X ) 
        {
        while(L) 
                {
            if (L->Data == X)
                                return L;
            else
                                L = L->Next;
        }
           return ERROR;
        }



bool Delete( List L, Position P ) 
        {
        while(L) 
                {
                if (L->Next == P) 
                                {
                    L->Next = L->Next->Next;
                    return true;
                }
                L = L->Next;
        }
        printf("Wrong Position for Deletion\n");
        return false;
                
        }

