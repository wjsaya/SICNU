#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree();

void InorderTraversal( BinTree BT )
//中序LVR
{
    if(BT)
    {
        InorderTraversal( BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal( BT->Right);
    }
}

void PreorderTraversal( BinTree BT )
//先序VLR
{
    if(BT)
    {
        printf(" %c", BT->Data);
        PreorderTraversal( BT->Left);
        PreorderTraversal( BT->Right);
    }
}
void PostorderTraversal( BinTree BT )
//后序LRV
{
    if(BT)
    {
        PostorderTraversal( BT->Left);
        PostorderTraversal( BT->Right);
        printf(" %c", BT->Data);
    }
}


void LevelorderTraversal( BinTree BT )
//层序
{
    if (BT == NULL) return;
    BinTree q[100];
    q[0] = BT;

    int front = 0;
    int rear = 1;

    while (front < rear)
    {
        int last = rear;
        while (front < last)
        {
            printf(" %c", q[front]->Data);

            if (q[front]->Left)
                q[rear++] = q[front]->Left;

            if (q[front]->Right)
                q[rear++] = q[front]->Right;

            ++front;
        }
    }
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */

